#ifndef SYSTEM_OF_H
#define SYSTEM_OF_H

#include <stdio.h>

#if (defined(WIN32) || defined(WINDOWS_XP))

#define MAX_FILE_NAME (_MAX_PATH + _MAX_FNAME)

#include <unistd.h>
#include <conio.h>
#define _getch getch
#define _kbhit kbhit

#endif

#define ARRAY_SIZE(a)(sizeof(a) / sizeof(a[0]))

#if defined(UNICODE) || defined(_UNICODE)
#define STR(s) L##s
#else
#define STR(s) s
#endif

#define NEXT(a)(a = a->next)

#define get_dir getcwd

typedef void B0;
typedef char B8;
typedef unsigned char B8U;
typedef short B16;
typedef unsigned short B16U;
typedef int B32;
typedef unsigned int B32U;
typedef long long int B64;
typedef long long int unsigned B64U;
typedef float BP32;
typedef double BP64;

typedef enum {
    SYSTEM_MAIN_NONE,
    SYSTEM_CONSOLE,
    SYSTEM_PRIMARY,
    SYSTEM_SDL,
    SYSTEM_ALLEGRO
} SYSTEM_MAIN;

typedef enum {
    GRAPHIC_CONSOLE,
    GRAPHIC_PRIMARY,
    GRAPHIC_OPENGL,
    GRAPHIC_DIRECTX
} SYSTEM_GRAPHIC;

typedef enum {
    SYSTEM_AUDIO_NONE,
    SYSTEM_AUDIO_PRIMARY,
    SYSTEM_AUDIO_ALLEGRO,
    SYSTEM_AUDIO_SDL
} SYSTEM_AUDIO;

typedef enum {
    SYSTEM_NETWORK_NONE,
    SYSTEM_NETWORK_PRIMARY,
    SYSTEM_NETWORK_SDL
} SYSTEM_NETWORK;

typedef struct {
    SYSTEM_MAIN system;
    SYSTEM_GRAPHIC driver;
    SYSTEM_AUDIO audio;
    SYSTEM_NETWORK network;
} system_t;

typedef enum {
    Off,
    On
} status_t;

#define BIT_ON_(var,bit)   ((var)=((var) | (bit)))
#define BIT_OFF_(var,bit) ((var)=((var) & (~bit)))
#define BIT_IS_ON_(var,bit) (var & bit)

#define BIT_ON(var, bit) (var |= (1 << bit))
#define BIT_OFF(var, bit) (var &= ~(1 << bit))
#define BIT_TOGGLE(var, bit)(var ^= (1 << bit))
#define BIT_IS_ON(var, bit) (var & (1 << bit) ? 1 : 0)

typedef struct {
    unsigned b16 :16;
} B16Set;

#define B16_ON(var,bit) ((var.b16)=(var.b16) | (bit))
#define B16_OFF(var,bit) ((var.b16)=((var.b16) & (~bit)))
#define B16_IS_ON(var,bit) (var.b16 & bit)

typedef enum {
    WINDOW_LEFT_CENTER,
    WINDOW_TOP_CENTER,
    WINDOW_WIDTH = 640,
    WINDOW_HEIGHT = 480
} WINDOW_STANDARD;

typedef enum {
    MACHINE_RUNNING,
    MACHINE_FULLSCREEN,
    MACHINE_FOCUS_ON,
    MACHINE_MOUSE_IN,
    MACHINE_PRESSED,
    MACHINE_CAMERA_MOUSE,
    MACHINE_CAMERA_OBJECT,
    MACHINE_VIDEO_PLAYING,
    MACHINE_VSYNC,
    MACHINE_DRAW
} MACHINE_EVENT;

typedef enum {
    MACHINE_MOUSE_LEFT,
    MACHINE_MOUSE_MIDDLE,
    MACHINE_MOUSE_RIGHT,
    MACHINE_MOUSE_MAX
} MACHINE_MOUSE_BUTTON;

typedef enum {
    MACHINE_WHEEL_UP,
    MACHINE_WHEEL_DOWN,
    MACHINE_WHEEL_MAX
} MACHINE_MOUSE_WHEEL;

typedef enum {
    MACHINE_FINGER_PRESS
} MACHINE_TOUCH;

typedef enum {
    MACHINE_JOY_LEFT,
    MACHINE_JOY_UP,
    MACHINE_JOY_RIGHT,
    MACHINE_JOY_DOWN
} MACHINE_JOYSTICK;

#endif
