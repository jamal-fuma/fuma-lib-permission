#if !defined(FUMA_FILESYSTEM_PERMISSION_WINDOWS_HPP)
#define FUMA_FILESYSTEM_PERMISSION_WINDOWS_HPP

namespace Fuma
{
    namespace FileSystem
    {
        namespace Permission
        {
            namespace Windows
            {
                // forward declartion of platform value_type
                struct value_type;

                struct permission_trait
                {
                    static int compare(const value_type & lhs, const value_type & rhs) ;
                    static bool is_directory(const value_type & value);
                    static bool is_file(const value_type & value);
                    static bool exists(const value_type & rhs);
                };   
            } // Fuma::FileSystem::Permission::Windows
        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma
#endif // #defined(FUMA_FILESYSTEM_PERMISSION_WINDOWS_HPP)
