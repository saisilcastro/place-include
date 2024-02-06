#ifndef PLACE_H
#define PLACE_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined PLACE_DLL_ACTIVATED

#ifdef PLACE_DLL
#define extern PLACE_CALL __declspec(dllexport)
#else
#define extern PLACE_CALL __declspec(dllimport)
#endif
#define PLACE_TYPE __cdecl
#else

#define PLACE_CALL
#define PLACE_TYPE

#endif // PLACE_DLL_ACTIVATED's end

#elif defined __linux__

#include <stdio.h>
#include <string.h>

#define vscprintf _vscprintf

#define PLACE_CALL
#define PLACE_TYPE

#endif // SYSTEM's end

#include <place/machine.h>

typedef struct place_s	place_t;
struct place_s{
	machine_t	gear[1];
	long		time;
	void		(*search_res)(int *pos);
	status_t	(*prev_res)(vf2d *size, int *pos);
	status_t	(*next_res)(vf2d *size, int *pos);
	void		(*resize)(void);
	void		(*run)(void *data);
	void		(*map_set)(image_t *image);
	image_t		*(*image_load)(B8 *path, B32 id, image_flip_t flip);
	image_t		*(*image_text_create)(font_t *font, B32 id, const B8 *str, ...);
	image_t		*(*image_select)(B32 id);
	vf2d		(*image_size)(image_t *image);
	void		(*image_next_first)(image_t *image);
	void		(*image_next_last)(image_t *image);
	void		(*image_remove)(B32 id);
	void		(*image_pop)(void);
	font_t		*(*font_load)(B8 *path, B32 id, B32 size);
	font_t		*(*font_select)(B32 id);
	void		(*font_next_first)(font_t *font);
	void		(*font_next_last)(font_t *font);
	void		(*font_pop)(void);
	sound_t		*(*sound_load)(B8 *path, B32 id, play_type_t type, play_mode_t mode);
	sound_t		*(*sound_select)(B32 id);
	void		(*sound_next_first)(sound_t *sound);
	void		(*sound_next_last)(sound_t *sound);
	void		(*sound_pop)(void);
	status_t	(*sound_play)(sound_t *sound);
	object_t	*(*object_push)(B32 id, char *name, vf2d pos, vf2d vel, vf2d zoom, image_t *image, pixel_t color);
	object_t	*(*object_select)(B32 id);
	void		(*object_next_first)(object_t *object);
	void		(*object_next_last)(object_t *object);
	float		(*object_width)(object_t *object);
	float		(*object_height)(object_t *object);
	void		(*object_zoom_fit)(object_t *object, vf2d size);
	void		(*object_pop)(void);
	void		(*camera_object)(object_t *object);
	void		(*camera_mouse)(BP32 w_offset, BP32 h_offset);
	status_t	(*mouse_down)(MACHINE_MOUSE_BUTTON button);
	status_t	(*mouse_release)(MACHINE_MOUSE_BUTTON button);
	status_t	(*mouse_over)(object_t *object);
	status_t	(*key_down)(keyboard_map key);
	status_t	(*start)(void *data);
	void		(*create)(void *data);
	void		(*update)(void *data);
	void		(*draw)(void *data);
	void		(*stop)(void);
	void		(*destroy)(place_t *set);
};

extern PLACE_CALL place_t *PLACE_TYPE	place_get(void);

#if defined __cplusplus
}
#endif

#endif /* PLACE_H_ */
