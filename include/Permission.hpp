#if !defined(FUMA_FILESYSTEM_PERMISSION_HPP)
#define FUMA_FILESYSTEM_PERMISSION_HPP

namespace Fuma
{
    namespace FileSystem
    {
        namespace Permission
        {
            // interface class
            class PermissionInterface
            {
                public:
                    PermissionInterface() {}
                    virtual ~PermissionInterface() = 0;

                    virtual bool exists() = 0;
                    virtual bool is_directory() = 0;
                    virtual bool is_file() = 0;
            };

            // forward declaration for value type
            struct PermissionValue;

            // free functions for manipulating value type
            bool exists(const PermissionValue & value);
            bool is_directory(const PermissionValue & value);
            bool is_file(const PermissionValue & value);

           // concrete implementation of the interface
            class PermissionImpl : public PermissionInterface
            {
            public:
                    PermissionImpl() {}

                    PermissionImpl(const PermissionImpl & rhs) :
                             m_value(rhs.m_value) {}

                    virtual ~PermissionImpl(){ }

                    virtual bool exists(){
                        return exists(m_value);
                    }

                    virtual bool is_directory(){
                        return is_directory(m_value);
                    }

                    virtual bool is_file(){
                        return is_file(m_value);
                    }

            private:
                    PermissionValue & m_value;
            };


            // public implementation
            class Permission
            {
                public:
                    Permission(const PermissionInterface & impl) :
                        m_impl(impl) {}

                    Permission(const Permission & rhs) :
                        m_impl(rhs.impl) {}

                    Permission & operator=(const Permission & rhs) {
                        if(this != &rhs)
                        {
                            m_impl = rhs.impl;
                        }
                        return *this;
                    }

          // member functions delegating to free function
                    bool exists(){
                        return m_impl.exists();
                    }

                    bool is_directory(){
                        return m_impl.is_directory();
                    }

                    bool is_file(){
                        return m_impl.is_file()
                    }

                private:
                    PermissionInterface & m_impl;
            };

            template <typename Trait>
            class PermissionType
            {
                public:
                    typedef typename Trait::value_type value_type;
                    PermissionType() : m_value(Trait()) {}
                    ~PermissionType() {}

                    // copy construct
                    PermissionType(const PermissionType & val) 
                        : m_value(val.m_value) {}

                    // copy assign
                    PermissionType & operator=(const PermissionType & val){
                        if(&val != this)
                        {
                            m_value = val;
                        }
                        return *this;
                    }
                    
                    // assignment api    
                    value_type* address_of(const value_type & val) const {
                        return & m_value;
                    }

                    int compare(const PermissionType & rhs) const{ 
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
                return lhs.compare(rhs) > 0
            }

            template <typename Trait>
            bool operator<(const PermissionType<Trait> & lhs, const PermissionType<Trait> & rhs) {
                return lhs.compare(rhs) < 0
            }

            template <typename Trait>
            bool operator==(const PermissionType<Trait> & lhs, const PermissionType<Trait> & rhs) {
                return lhs.compare(rhs) == 0
            }

        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma

#endif /* !defined(FUMA_FILESYSTEM_PERMISSION_HPP) */
