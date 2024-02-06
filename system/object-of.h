#ifndef OBJECT_OF_H
#define OBJECT_OF_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined OBJECT_OF_DLL_ACTIVATED

#ifdef OBJECT_OF_DLL
#define extern OBJECT_OF_CALL __declspec(dllexport)
#else
#define extern OBJECT_OF_CALL __declspec(dllimport)
#endif
#define OBJECT_OF_TYPE __cdecl
#else

#define OBJECT_OF_CALL
#define OBJECT_OF_TYPE

#endif // OBJECT_OF_DLL_ACTIVATED's end

#elif defined __linux__

#define OBJECT_OF_CALL
#define OBJECT_OF_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>
#include <place/system/graphic/image-of.h>
#include <place/system/math-of.h>

typedef struct{
	B32		id;
	B8		*name;
	vf2d	pos[1];
	vf2d	route[1];
	vf2d	vel[1];
	vf2d	size[1];
	vf2d	zoom[1];
	vf2d	axis[1];
	float	angle;
	pixel_t	color[1];
	image_t	*image;
}object_t;

extern OBJECT_OF_CALL object_t *OBJECT_OF_TYPE object_push(B32 id, char *name, vf2d pos, vf2d vel, vf2d zoom, image_t *image, pixel_t color, system_t *up);
extern OBJECT_OF_CALL void OBJECT_OF_TYPE	object_set(object_t *set, B32 id, char *name, vf2d pos, vf2d vel, vf2d size, vf2d zoom, image_t *image, pixel_t color, system_t *up);
extern OBJECT_OF_CALL status_t OBJECT_OF_TYPE	object_move(object_t *set, long time);
extern OBJECT_OF_CALL void		OBJECT_OF_TYPE object_pop(void *data, system_t *up);

#if defined __cplusplus
}
#endif

#endif /* OBJECT_OF_H_ */
