#ifndef AUDIO_OF_H
#define AUDIO_OF_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined AUDIO_DLL_ACTIVATED

#ifdef AUDIO_DLL
#define extern AUDIO_CALL __declspec(dllexport)
#else
#define extern AUDIO_CALL __declspec(dllimport)
#endif
#define AUDIO_TYPE __cdecl
#else

#define AUDIO_CALL
#define AUDIO_TYPE

#endif // AUDIO_DLL_ACTIVATED's end

#elif defined __linux__

#define AUDIO_CALL
#define AUDIO_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>

typedef struct audio_s audio_t;
struct audio_s {
	B32	frequency;
	B32	format;
	B32	channel;
	B32	chunk_size;
};

extern AUDIO_CALL void AUDIO_TYPE audio_set(audio_t *set, B32 frequency, B32 format, B32 channel, B32 chunk_size);

#if defined __cplusplus
}
#endif

#endif /* AUDIO_OF_H */
