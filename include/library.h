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

#endif //MATH_LIB_LIBRARY_H
