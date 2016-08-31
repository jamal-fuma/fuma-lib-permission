#include "config.h"
#include "Permission.hpp"

namespace Permission = Fuma::FileSystem::Permission;

#if defined(ENABLE_UNIX_BUILD)
        #include "Unix.hpp"
        namespace Platform = Fuma::FileSystem::Permission::Unix;
        typedef Permission::PermissionType< Platform::permission_trait > PermissionTrait;

#elif defined(ENABLE_WINDOWS_BUILD)
        #include "Windows.hpp"
        namespace Platform = Fuma::FileSystem::Permission::Windows;
        typedef Permission::PermissionType< Platform::permission_trait > PermissionTrait;
#else
        #error "Unsupported Platform"
#endif

namespace Fuma
{
    namespace FileSystem
    {
        namespace Permission
        {
            struct PermissionValue
            {
                PermissionTrait value;
            };
        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma
#
bool
Fuma::FileSystem::Permission::exists(const PermissionValue & rhs)
{
     return rhs.value.exists();
}

bool
Fuma::FileSystem::Permission::is_directory(const PermissionValue & rhs)
{
     return rhs.value.is_directory();
}

bool
Fuma::FileSystem::Permission::is_file(const PermissionValue & rhs)
{
     return rhs.value.is_file();
}
