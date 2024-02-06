#ifndef MATH_OF_H
#define MATH_OF_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined WIN32 || WIN64 || WINDOWS_XP

#if defined MATH_OF_DLL_ACTIVATED

#ifdef MATH_OF_DLL
#define extern MATH_OF_CALL __declspec(dllexport)
#else
#define extern MATH_OF_CALL __declspec(dllimport)
#endif
#define MATH_OF_TYPE __cdecl
#else

#define MATH_OF_CALL
#define MATH_OF_TYPE

#endif // MATH_OF_DLL_ACTIVATED's end

#elif defined __linux__

#define MATH_OF_CALL
#define MATH_OF_TYPE

#endif // SYSTEM's end

typedef struct {
    int x, y;
} vi2d;

extern MATH_OF_CALL vi2d MATH_OF_TYPE vi2d_start(int x, int y);
extern MATH_OF_CALL vi2d * MATH_OF_TYPE vi2d_set(int x, int y);

typedef struct {
    float x, y;
} vf2d;

extern MATH_OF_CALL vf2d MATH_OF_TYPE vf2d_start(float x, float y);
extern MATH_OF_CALL vf2d * MATH_OF_TYPE vf2d_set(float x, float y);
extern MATH_OF_CALL vf2d MATH_OF_TYPE vf2d_normalize(vf2d f, vf2d s, float x, float y);

#if defined __cplusplus
}
#endif

#endif /* MATH_OF_H */
