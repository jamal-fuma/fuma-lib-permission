#include "config.h"
#include "Permission.hpp"

#if defined(UNIX)
        //namespace Platform = Fuma::FileSystem::Permission::Unix;

#elif defined(WINDOWS)
    //    namespace Platform = Fuma::FileSystem::Permission::Windows;
#else
        #error "Unsupported Platform"
#endif

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
