#include "config.h"
#include "Permission.hpp"

#if defined(ENABLE_UNIX_BUILD)
        namespace Platform = Fuma::FileSystem::Permission::Unix;
        #include "Unix.hpp"

#elif defined(ENABLE_WINDOWS_BUILD)
        namespace Platform = Fuma::FileSystem::Permission::Windows;
        #include "Windows.hpp"
#else
        #error "Unsupported Platform"
#endif

typedef PermissionType< Platform::permission_trait, Platform::value_type > PermissionTrait;

struct PermissionValue
{
    PermissionTrait value;
    PermissionValue(const Permission & val) : value(val) {}
};

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
