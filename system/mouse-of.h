#ifndef MOUSE_H
#define MOUSE_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined MOUSE_DLL_ACTIVATED

#ifdef MOUSE_DLL
#define extern MOUSE_CALL __declspec(dllexport)
#else
#define extern MOUSE_CALL __declspec(dllimport)
#endif
#define MOUSE_TYPE __cdecl
#else

#define MOUSE_CALL
#define MOUSE_TYPE

#endif // MOUSE_DLL_ACTIVATED's end

#elif defined __linux__

#define MOUSE_CALL
#define MOUSE_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>

typedef struct mouse_s	mouse_t;
struct mouse_s{
	B32 			x;
	B32 			y;
	unsigned char	button: 2;
	unsigned char	wheel: 3;
};

MOUSE_CALL void MOUSE_TYPE mouse_set(mouse_t *mouse);

#if defined __cplusplus
}
#endif

#endif /* MOUSE_H_ */
