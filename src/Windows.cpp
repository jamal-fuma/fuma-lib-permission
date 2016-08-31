#include "config.h"

#if defined(HAVE_WINBASE_H)
#include <winbase.h>
#endif //defined  HAVE_WINBASE_H

#include "Permission.hpp"
#include "Windows.hpp"

namespace Fuma
{
    namespace FileSystem
    {
        namespace Permission
        {
            namespace Windows
            {
                struct value_type
                {
                    typedef DWORD value_type;
                };

                struct pointer_type
                {
                    typedef DWORD* pointer_type;
                };

           } // Fuma::FileSystem::Permission::Windows
        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma

using Fuma::FileSystem::Permission::Windows::value_type;
using Fuma::FileSystem::Permission::Windows::pointer_type;

int Fuma::FileSystem::Permission::Windows::permission_trait::compare(const value_type & lhs, const value_type & rhs) {
        return (lhs - rhs);
}

bool Fuma::FileSystem::Permission::Windows::permission_trait::is_directory(const value_type & lhs) {
        return (lhs & FILE_ATTRIBUTE_DIRECTORY);
}

bool Fuma::FileSystem::Permission::Windows_permission_trait::is_file(const value_type & lhs) {
        return !(lhs & FILE_ATTRIBUTE_DIRECTORY);
}

bool Fuma::FileSystem::Permission::Windows::permission_trait::exists(const value_type & lhs) {
        return  (lhs != INVALID_FILE_ATTRIBUTES);
}

bool Fuma::FileSystem::Permission::Windows::permission_trait::exists(const value_type & lhs) {
        return  (lhs != INVALID_FILE_ATTRIBUTES);
}

pointer_type Fuma::FileSystem::Permission::Windows::permission_trait::address_of(const value_type & lhs){
        return ( &lhs);
}
