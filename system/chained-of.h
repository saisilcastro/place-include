#ifndef CHAINED_H
#define CHAINED_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined CHAINED_DLL_ACTIVATED

#ifdef CHAINED_DLL
#define extern CHAINED_CALL __declspec(dllexport)
#else
#define extern CHAINED_CALL __declspec(dllimport)
#endif
#define CHAINED_TYPE __cdecl
#else

#define CHAINED_CALL
#define CHAINED_TYPE

#endif // CHAINED_DLL_ACTIVATED's end

#elif defined __linux__

#define CHAINED_CALL
#define CHAINED_TYPE

#endif // SYSTEM's end

#include <place/system/system-of.h>

typedef struct chained_s chained_t;
struct chained_s {
	void		*data;
	chained_t	*prev;
	chained_t	*next;
};

extern CHAINED_CALL chained_t	*CHAINED_TYPE chained_push(void *data);
extern CHAINED_CALL status_t	CHAINED_TYPE chained_next_first(chained_t **head, chained_t *set);
extern CHAINED_CALL status_t	CHAINED_TYPE chained_next_last(chained_t **head, chained_t *set);
extern CHAINED_CALL void		CHAINED_TYPE chained_pop(chained_t **head, system_t *up, void (*delete)(void *data, system_t *up));

#if defined __cplusplus
}
#endif

#endif /* CHAINED_H */
