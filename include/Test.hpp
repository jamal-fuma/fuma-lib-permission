#ifndef FUMA_TEST_HPP
#define FUMA_TEST_HPP

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro helpers 
#define STRINGIZE(s) #s

#define CONCAT(s) CONCAT_0(s)
#define CONCAT_0(s) CONCAT_1(s)
#define CONCAT_1(s) s

// TEST HELPERS
#define assert_string_equal(a,b) \
do {                                                    \
        int result = strcmp((a),(b)) ;                  \
        if(result)                                      \
        {                                               \
                printf("%s:%d Assertion Failed\n\t"     \
                        "Expected: >> \n|%s|\n\t"       \
                        "Actual  : >> \n|%s|\n",        \
                        __FILE__,                       \
                        __LINE__,                       \
                        (a),                            \
                        (b)                             \
                );                                      \
        }                                               \
        assert( !result && "Assertion Failed");                        \
}while(0)

#define assert_integer_equal(a,b,m) \
do {                                                    \
        int result = ((a)-(b)) ;                        \
        if(result)                                      \
        {                                               \
                printf("%s:%d Assertion Failed\n\t"     \
                        "Expected: >> \n%ld\n\t"        \
                        "Actual  : >> \n%ld\n",         \
                        __FILE__,                       \
                        __LINE__,                       \
                        (a)+0L,                         \
                        (b)+0L                          \
                );                                      \
        }                                               \
        assert( !result && (m));                        \
}while(0)


#define assert_condition(operation,message)             \
do {                                                    \
        if(!(operation))                                     \
        { \
                printf("Fail >> %s:%d: %s\n", __FILE__, __LINE__, (message)); \
                exit(EXIT_FAILURE); \
        } \
}while(0)


#define assert_null(a) assert_condition( \
                ( (a) == NULL ), \
                (CONCAT(STRINGIZE(Expected )  " " STRINGIZE(a)  " " STRINGIZE( would be null ) )) \
        )

#define assert_not_null(a) assert_condition( \
                ( (a) != NULL ), \
                (CONCAT(STRINGIZE(Expected )  " " STRINGIZE(a)  " " STRINGIZE( would be non null ) )) \
        )
#define assert_less(a,b) assert_condition( \
                ( (a) < (b) ), \
                (CONCAT(STRINGIZE(Expected ) STRINGIZE(a) " " STRINGIZE( would be < )  " " STRINGIZE(b)   )) \
        )
#define assert_less_equal(a,b) assert_condition( \
                ( (a) <= (b) ), \
                (CONCAT(STRINGIZE(Expected ) STRINGIZE(a) " " STRINGIZE( would be <= )  " " STRINGIZE(b)   )) \
        )
#define assert_equal(a,b) assert_condition( \
                ( (a) == (b) ), \
                (CONCAT(STRINGIZE(Expected ) " " STRINGIZE(a) " " STRINGIZE( would  == )  " " STRINGIZE(b)   )) \
        )
#define assert_not_equal(a,b) assert_condition( \
                ( (a) != (b) ), \
                (CONCAT(STRINGIZE(Expected ) STRINGIZE(a) " " STRINGIZE( would  != )  " " STRINGIZE(b)   )) \

#define assert_greater(a,b) assert_condition( \
                ( (a) > (b) ), \
                (CONCAT(STRINGIZE(Expected )  " " STRINGIZE(a) " " STRINGIZE( would be > )  " " STRINGIZE(b)   )) \

#define assert_greater_equal(a,b) assert_condition( \
                ( (a) >= (b) ), \
                (CONCAT(STRINGIZE(Expected )  " " STRINGIZE(a) " " STRINGIZE( would be >= )  " " STRINGIZE(b)   )) \

#endif // ndef FUMA_TEST_HPP

