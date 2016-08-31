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
                struct type_trait
                {
                    typedef mode_t value_type;

                    typedef mode_t* pointer_type;
                    typedef const mode_t* const_pointer_type;

                    typedef mode_t & reference_type;
                    typedef const mode_t & const_reference_type;

                    static int compare(const value_type & lhs, const value_type & rhs)
                    {
                        return (lhs - rhs);
                    }

                    static is_directory(const value_type & lhs)
                    {
                        return S_ISDIR(lhs);
                    }

                    static is_file(const value_type & lhs)
                    {
                        return S_ISREG(lhs);
                    }

                    static exists(const value_type & lhs)
                    {
                        return (S_ISREG(lhs) || S_ISDIR(lhs));
                    }

                    static pointer_type address_of(const value_type & lhs)
                    {
                        return ( &lhs);
                    }
                };

           } // Fuma::FileSystem::Permission::Unix
        } // Fuma::FileSystem::Permission
    } // Fuma::FileSystem
} // Fuma


