
#include "config.h"

#include "Permission.hpp"

#if defined(HAVE_WINBASE_H)
#include <winbase.h>
#endif //defined  HAVE_WINBASE_H
 




namespace Fuma
{
        namespace FileSystem
        {
                namespace Permission
                {
                     struct windows_permission_trait
                     {
                        typedef DWORD value_type;

                        static int compare(const value_type & lhs, const value_type & rhs) {
                                return (lhs - rhs);
                        }

                        static bool is_directory(const value_type & value) {
                                return (value & FILE_ATTRIBUTE_DIRECTORY);
                        }

                        static bool is_file() {
                                return !(value & FILE_ATTRIBUTE_DIRECTORY); 
                        }

                        static bool exists(const value_type & rhs) {
                                return  (rhs != INVALID_FILE_ATTRIBUTES);
                        }

                     };
                     
                     typedef PermissionType< windows_permission_trait > PermissionTrait;
                 
                     struct PermissionValue
                     {
                         PermissionTrait value;
                         PermissionValue(const Permission & val) : value(val) {}
                     };

                     bool is_directory(const PermissionValue & rhs) { 
                         return rhs.value.is_directory();
                     }

                     bool is_file(const PermissionValue & rhs) {
                         return rhs.value.is_file();
                     }

                     bool exists(const PermissionValue & rhs) { 
                         return rhs.value.exists();
                     }
                }
          }
 }
