#ifndef ALLEGRO_PLUGIN_H
#define ALLEGRO_PLUGIN_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#include <allegro5/allegro_video.h>

#if defined ALLEGRO_PLUGIN_DLL_ACTIVATED

#ifdef ALLEGRO_PLUGIN_DLL
#define extern ALLEGRO_PLUGIN_CALL __declspec(dllexport)
#else
#define extern ALLEGRO_PLUGIN_CALL __declspec(dllimport)
#endif
#define ALLEGRO_PLUGIN_TYPE __cdecl
#else

#define ALLEGRO_PLUGIN_CALL
#define ALLEGRO_PLUGIN_TYPE

#endif // ALLEGRO_PLUGIN_DLL_ACTIVATED's end

#elif defined __linux__

#define ALLEGRO_PLUGIN_CALL
#define ALLEGRO_PLUGIN_TYPE

#endif // SYSTEM's end

#include <place/machine.h>

typedef struct{
	ALLEGRO_DISPLAY		*window;
	ALLEGRO_EVENT_QUEUE	*event_row;
	ALLEGRO_EVENT_SOURCE event_fake;
}allegro_plugin_t;

extern ALLEGRO_PLUGIN_CALL allegro_plugin_t *ALLEGRO_PLUGIN_TYPE	allegro_plugin_push(void);
extern ALLEGRO_PLUGIN_CALL status_t	ALLEGRO_PLUGIN_TYPE allegro_start(machine_t *gear);
extern ALLEGRO_PLUGIN_CALL void ALLEGRO_PLUGIN_TYPE	allegro_search_res(vf2d *size, B32 *pos);
extern ALLEGRO_PLUGIN_CALL status_t ALLEGRO_PLUGIN_TYPE	allegro_prev_res(vf2d *size, B32 *pos);
extern ALLEGRO_PLUGIN_CALL status_t ALLEGRO_PLUGIN_TYPE	allegro_next_res(vf2d *size, B32 *pos);
extern ALLEGRO_PLUGIN_CALL status_t ALLEGRO_PLUGIN_TYPE	allegro_plugin_event(machine_t *gear, vf2d offset);
extern ALLEGRO_PLUGIN_CALL void ALLEGRO_PLUGIN_TYPE	allegro_plugin_pop(allegro_plugin_t *plugin);

#if defined __cplusplus
}
#endif

#endif /* ALLEGRO_PLUGIN_H_ */
