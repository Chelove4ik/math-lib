#ifndef MATH_LIB_LIBRARY_H
#define MATH_LIB_LIBRARY_H

#ifdef __WIN32__
    #ifdef BUILD_LIB
        #define LIB_CLASS __declspec(dllexport)
    #else
        #define LIB_CLASS __declspec(dllimport)
    #endif
#else
    #define LIB_CLASS       // Linux & other Unices : leave it blank !
#endif

#ifdef __cplusplus
extern "C" {
#endif

LIB_CLASS void hello();

#ifdef __cplusplus
}
#endif

#endif //MATH_LIB_LIBRARY_H
