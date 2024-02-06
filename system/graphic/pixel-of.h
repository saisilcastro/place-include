#ifndef PIXEL_OF_H_
#define PIXEL_OF_H_

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#include <conio.h>

#if defined PIXEL_DLL_ACTIVATED

#ifdef PIXEL_DLL
#define extern PIXEL_OF_CALL __declspec(dllexport)
#else
#define extern PIXEL_OF_CALL __declspec(dllimport)
#endif
#define PIXEL_OF_TYPE __cdecl
#else

#define PIXEL_OF_CALL
#define PIXEL_OF_TYPE

#endif // PIXEL_DLL_ACTIVATED's end

#elif defined __linux__

#define PIXEL_OF_CALL
#define PIXEL_OF_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>

typedef struct{
	B8U r;
	B8U g;
	B8U b;
	B8U a;
}pixel_t;

extern PIXEL_OF_CALL pixel_t	PIXEL_OF_TYPE pixel_start(void);
extern PIXEL_OF_CALL pixel_t	*PIXEL_OF_TYPE pixel_set(B8U r, B8U g, B8U b, B8U a);
extern PIXEL_OF_CALL pixel_t PIXEL_OF_TYPE pixel_rgb_start(B8U r, B8U g, B8U b);
extern PIXEL_OF_CALL pixel_t PIXEL_OF_TYPE pixel_rgba_start(B8U r, B8U g, B8U b, B8U a);
extern PIXEL_OF_CALL void PIXEL_OF_TYPE pixel_rgb_set(pixel_t * p, B8U r, B8U g, B8U b);
extern PIXEL_OF_CALL void PIXEL_OF_TYPE pixel_rgba_set(pixel_t * p, B8U r, B8U g, B8U b, B8U a);
extern PIXEL_OF_CALL void PIXEL_OF_TYPE pixel_of_show_console(pixel_t * p);
extern PIXEL_OF_CALL void PIXEL_OF_TYPE pixel_destroy(pixel_t * p);

#if defined __cplusplus
}
#endif

#endif /* PIXEL_OF_H_ */
