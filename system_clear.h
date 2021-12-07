#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

#ifdef _WIN32
    #include <Windows.h>
    const float ESPERA = 1000;
#else
    #include <unistd.h>
    const float ESPERA = 3000000;
#endif