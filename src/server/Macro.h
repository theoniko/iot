#ifndef MACRO_H
#define MACRO_H

#ifdef TESTING
        #define VIRTUAL_ON_UT virtual
    #else
        #define VIRTUAL_ON_UT
#endif

#endif // MACRO_H