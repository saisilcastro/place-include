#ifndef IMAGE_OF_H_
#define IMAGE_OF_H_

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#include <conio.h>

#if defined IMAGE_DLL_ACTIVATED

#ifdef IMAGE_DLL
#define extern IMAGE_OF_CALL __declspec(dllexport)
#else
#define extern IMAGE_OF_CALL __declspec(dllimport)
#endif
#define IMAGE_OF_TYPE __cdecl
#else

#define IMAGE_OF_CALL
#define IMAGE_OF_TYPE

#endif // IMAGE_DLL_ACTIVATED's end

#elif defined __linux__

#define IMAGE_OF_CALL
#define IMAGE_OF_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>
#include <place/system/graphic/pixel-of.h>
#include <place/system/math-of.h>

typedef enum {
	IMAGE_MODE_NORMAL
} image_mode_t;

typedef enum {
	IMAGE_FLIP_NONE,
	IMAGE_FLIP_HORIZONTAL,
	IMAGE_FLIP_VERTICAL
} image_flip_t;

typedef struct{
	B32				id;
	void			*data;
	image_flip_t	flip;
}image_t;

extern IMAGE_OF_CALL image_t *IMAGE_OF_TYPE	image_push(B32 id, image_flip_t flip, void *data);
extern IMAGE_OF_CALL image_t *IMAGE_OF_TYPE	image_create(B32 id, vf2d size, system_t *up);
extern IMAGE_OF_CALL image_t *IMAGE_OF_TYPE	image_load(char * path, B32 id, image_flip_t flip, system_t *up);
extern IMAGE_OF_CALL image_t *IMAGE_OF_TYPE image_clone(image_t *set, system_t *up);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE	image_target_self(image_t *image, system_t *up);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE	image_target_window(void * plugin, system_t *up);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE	image_draw(image_t *set, pixel_t *color, vf2d center, vf2d pos, vf2d zoom, float angle, system_t *up);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE	image_put_pixel(pixel_t *color, vf2d pos, system_t *up);
extern IMAGE_OF_CALL vf2d IMAGE_OF_TYPE	image_size(image_t *set, system_t *up);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE image_remove(image_t *set);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE	image_pointer_pop(void **set, system_t *up);
extern IMAGE_OF_CALL void IMAGE_OF_TYPE	image_pop(void *data, system_t *up);

#if defined __cplusplus
}
#endif

#endif /* IMAGE_OF_H_ */
