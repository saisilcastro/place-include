#ifndef MACHINE_H
#define MACHINE_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined MACHINE_DLL_ACTIVATED

#ifdef MACHINE_DLL
#define extern MACHINE_CALL __declspec(dllexport)
#else
#define extern MACHINE_CALL __declspec(dllimport)
#endif
#define MACHINE_TYPE __cdecl
#else

#define MACHINE_CALL
#define MACHINE_TYPE

#endif // MACHINE_DLL_ACTIVATED's end

#elif defined __linux__

#define MACHINE_CALL
#define MACHINE_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>
#include <place/system/math-of.h>
#include <place/system/chained-of.h>
#include <place/system/keyboard-of.h>
#include <place/system/mouse-of.h>
#include <place/system/audio-of.h>
#include <place/system/graphic/pixel-of.h>
#include <place/system/graphic/image-of.h>
#include <place/system/graphic/font-of.h>
#include <place/system/sound-of.h>
#include <place/system/object-of.h>
#include <place/system/timer-of.h>

extern MACHINE_CALL int MACHINE_TYPE vscprintf(const char *format, va_list pargs);
extern MACHINE_CALL int MACHINE_TYPE scprintf(const char *format, ...);

typedef struct machine_s	machine_t;
struct machine_s{
	B8				*title;
	system_t		up[1];
	vf2d			pos[1];
	vf2d			size[1];
	unsigned short	event: 10;
	status_t		key[KEYBOARD_MAX];
	mouse_t			mouse[1];
	audio_t			audio[1];
	object_t		map[1];
	chained_t		*img;
	chained_t		*obj;
	chained_t		*snd;
	chained_t		*font;
	void			*plugin;
	status_t		(*start)(machine_t *set);
	void			(*resize)(machine_t *set);
	void			(*search_res)(vf2d *size, B32 *pos, system_t *up);
	status_t		(*prev_res)(vf2d *size, B32 *pos, system_t *up);
	status_t		(*next_res)(vf2d *size, B32 *pos, system_t *up);
	status_t		(*running)(machine_t *set);
	void			(*show)(machine_t *set);
	void			(*pop)(machine_t *set);
};

extern MACHINE_CALL void MACHINE_TYPE	machine_set(machine_t *set, system_t up, char *title, vf2d size);

#if defined __cplusplus
}
#endif

#endif /* MACHINE_H_ */
