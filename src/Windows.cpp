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
                    DWORD value;
                };
           } // Fuma::FileSystem::Permission::Windows
        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma

using Fuma::FileSystem::Permission::Windows::value_type;

int Fuma::FileSystem::Permission::Windows::permission_trait::compare(const value_type & lhs, const value_type & rhs) {
        return (lhs.value - rhs.value);
}

bool Fuma::FileSystem::Permission::Windows::permission_trait::is_directory(const value_type & lhs) {
        return (lhs.value & FILE_ATTRIBUTE_DIRECTORY);
}

bool Fuma::FileSystem::Permission::Windows_permission_trait::is_file(const value_type & lhs) {
        return !(lhs.value & FILE_ATTRIBUTE_DIRECTORY);
}

bool Fuma::FileSystem::Permission::windows_permission_trait::exists(const value_type & lhs) {
        return  (lhs.value != INVALID_FILE_ATTRIBUTES);
}
