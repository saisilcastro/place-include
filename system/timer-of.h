#ifndef TIMER_OF_H
#define TIMER_OF_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined TIMER_OF_DLL_ACTIVATED

#ifdef TIMER_OF_DLL
#define extern TIMER_OF_CALL __declspec(dllexport)
#else
#define extern TIMER_OF_CALL __declspec(dllimport)
#endif
#define TIMER_OF_TYPE __cdecl
#else

#define TIMER_OF_CALL
#define TIMER_OF_TYPE

#endif // TIMER_OF_DLL_ACTIVATED's end

#elif defined __linux__

#define TIMER_OF_CALL
#define TIMER_OF_TYPE

#endif // SYSTEM's end

#include <sys/time.h>

extern TIMER_OF_CALL long TIMER_OF_TYPE time_now(void);

#if defined __cplusplus
}
#endif

#endif /* TIMER_OF_H_ */
