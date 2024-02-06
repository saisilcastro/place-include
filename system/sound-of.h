#ifndef SOUND_H
#define SOUND_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined SOUND_DLL_ACTIVATED

#ifdef SOUND_DLL
#define extern SOUND_CALL __declspec(dllexport)
#else
#define extern SOUND_CALL __declspec(dllimport)
#endif
#define SOUND_TYPE __cdecl
#else

#define SOUND_CALL
#define SOUND_TYPE

#endif // SOUND_DLL_ACTIVATED's end

#elif defined __linux__

#define SOUND_CALL
#define SOUND_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>
#include <place/system/audio-of.h>

typedef enum{
	PLAY_EFFECT,
	PLAY_MUSIC
}play_type_t;

typedef enum{
	PLAY_ONCE,
	PLAY_LOOP
}play_mode_t;

typedef struct sound_s	sound_t;
struct sound_s{
	B32			id;
	struct{
		BP32		music;
		BP32		effect;
	}volume[1];
	BP32		balance;
	BP32		speed;
	play_mode_t	mode;
	play_type_t	type;
	void		*data;
};

extern SOUND_CALL sound_t *SOUND_TYPE	sound_push(B32 id, BP32 music, BP32 effect, BP32 balance, BP32 speed, play_mode_t mode, void *data);
extern SOUND_CALL sound_t *SOUND_TYPE	sound_load(char *path, B32 id, play_type_t type, play_mode_t mode, audio_t audio, system_t *up);
extern SOUND_CALL status_t SOUND_TYPE	sound_play(sound_t *sound, system_t *up);
extern SOUND_CALL void SOUND_TYPE		sound_pop(void *data, system_t *up);

#if defined __cplusplus
}
#endif

#endif /* SOUND_H_ */
