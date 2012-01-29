#include "config.h"

#include "Permission.hpp"
#include "Unix.hpp"

#if defined(HAVE_SYS_STAT_H)
#include <sys/stat.h>
#endif //defined  HAVE_SYS_STAT_H

#if defined(HAVE_SYS_TYPES_H)
#include <sys/types.h>
#endif //defined  HAVE_SYS_STAT_H

namespace Fuma
{
    namespace FileSystem
    {
        namespace Permission
        {
            namespace Unix
            {
                struct value_type;
                {
                    mode_t value;
                };
            } // Fuma::FileSystem::Permission::Unix
        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma

using Fuma::FileSystem::Permission::Unix::value_type;

int Fuma::FileSystem::Permission::Unix::permission_trait::compare(const value_type & lhs, const value_type & rhs) {
        return (lhs.value - rhs.value);
}

bool Fuma::FileSystem::Permission::Unix::permission_trait::is_directory(const value_type & lhs) {
        return S_ISDIR(lhs.value);
}

bool Fuma::FileSystem::Permission::Unix::permission_trait::is_file(const value_type & lhs) {
        return S_ISREG(lhs.value);
}

bool Fuma::FileSystem::Permission::Unix::permission_trait::exists(const value_type & lhs) {
        return (S_ISREG(lhs.value) || S_ISDIR(lhs.value));
}
