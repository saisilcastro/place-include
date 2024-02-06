#ifndef FONT_OF_H
#define FONT_OF_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#include <conio.h>

#if defined FONT_DLL_ACTIVATED

#ifdef FONT_DLL
#define extern FONT_OF_CALL __declspec(dllexport)
#else
#define extern FONT_OF_CALL __declspec(dllimport)
#endif
#define FONT_OF_TYPE __cdecl
#else

#define FONT_OF_CALL
#define FONT_OF_TYPE

#endif // FONT_DLL_ACTIVATED's end

#elif defined __linux__

#define FONT_OF_CALL
#define FONT_OF_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>
#include <place/system/math-of.h>
#include <place/system/graphic/pixel-of.h>

typedef struct font_s font_t;
struct font_s {
	B32     id;
	B32     size;
	pixel_t	color[1];
	void    *data;
};

extern FONT_OF_CALL font_t *FONT_OF_TYPE	font_load(B32 id, B32 size, B8 *path, pixel_t *color, system_t *up);
extern FONT_OF_CALL void FONT_OF_TYPE		font_draw(font_t *font, vf2d pos, char *str, system_t *up);
extern FONT_OF_CALL vf2d FONT_OF_TYPE		font_size(font_t *font, char *buffer, system_t *up);
extern FONT_OF_CALL void FONT_OF_TYPE		font_pop(void *data, system_t *up);

#if defined __cplusplus
}
#endif

#endif /* FONT_OF_H_ */
