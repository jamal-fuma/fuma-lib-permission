#include "config.h"

#include "Permission.hpp"

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
                     struct unix_permission_trait
                     {
                        typedef mode_t value_type;

                        static int compare(const value_type & lhs, const value_type & rhs) ;

                        static bool is_directory(const value_type & value);

                        static bool is_file();

                        static bool exists(const value_type & rhs);
                     };   
                }
          }
}
  
int Fuma::FileSystem::Permission::unix_permission_trait::compare(const value_type & lhs, const value_type & rhs) {
        return (lhs - rhs);
}

bool Fuma::FileSystem::Permission::unix_permission_trait::is_directory(const value_type & value) {
        return S_ISDIR(value);
}

bool Fuma::FileSystem::Permission::unix_permission_trait::is_file() {
        return S_ISREG(value);
}

bool Fuma::FileSystem::Permission::unix_permission_trait::exists(const value_type & rhs) {
        return (S_ISREG(value) || S_ISDIR(value));
}
