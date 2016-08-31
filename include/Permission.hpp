#if !defined(FUMA_FILESYSTEM_PERMISSION_HPP)
#define FUMA_FILESYSTEM_PERMISSION_HPP

namespace Fuma
{
    namespace FileSystem
    {
        namespace Permission
        {
            // forward declaration for value type
            struct PermissionValue;

            // free functions for manipulating value type
            bool exists(const PermissionValue & value);
            bool is_directory(const PermissionValue & value);
            bool is_file(const PermissionValue & value);

            template <typename T>
            struct permission_trait
            {
                typedef typename T::value_type value_type;
                typedef typename T::value_type pointer_type;

                static int compare(const value_type & lhs, const value_type & rhs)
                {
                        return T::compare(lhs,rhs);
                }
                static bool is_directory(const value_type & value)
                {
                        return T::is_directory(value);
                }

                static bool is_file(const value_type & value)
                {
                        return T::is_file(value);
                }
                static bool exists(const value_type & value)
                {
                        return T::exists(value);
                }
                static pointer_type address_of(const value_type & value)
                {
                        return T::address_of(value);
                }
            };

            template <typename Trait>
            class PermissionType
            {
                public:
                    typedef typename Trait::value_type value_type;
                    typedef typename Trait::pointer_type pointer_type;

                    PermissionType() {}
                    ~PermissionType() {}

                    // copy construct
                    PermissionType(const PermissionType<Trait> & val)
                        : m_value(val.m_value) {}

                    // copy assign
                    PermissionType & operator=(const PermissionType<Trait> & val){
                        if(&val != this)
                        {
                            m_value = val.m_value;
                        }
                        return *this;
                    }
                    
                    // assignment api    
                    pointer_type address_of() const {
                        return Trait::address_of(m_value);
                    }

                    int compare(const PermissionType<Trait> & rhs) const{
                        return Trait::compare(m_value,rhs.m_value); 
                    }

                    bool exists() const {
                        return Trait::exists(m_value);
                    }

                    bool is_directory() const {
                        return Trait::is_directory(m_value);
                    }

                    bool is_file() const {
                        return Trait::is_file(m_value);
                    }

                private:
                    value_type m_value;
            };

            template <typename Trait>
            bool operator>(const PermissionType<Trait> & lhs, const PermissionType<Trait> & rhs) {
                return lhs.compare(rhs) > 0;
            }

            template <typename Trait>
            bool operator<(const PermissionType<Trait> & lhs, const PermissionType<Trait> & rhs) {
                return lhs.compare(rhs) < 0;
            }

            template <typename Trait>
            bool operator==(const PermissionType<Trait> & lhs, const PermissionType<Trait> & rhs) {
                return lhs.compare(rhs) == 0;
            }

        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma

#endif /* !defined(FUMA_FILESYSTEM_PERMISSION_HPP) */
