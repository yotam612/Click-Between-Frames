#pragma once

#include <Geode/Geode.hpp>
#include "linuxeventcodes.hpp"

#if defined(_MSC_VER)
    #define CBF_PACK_PUSH __pragma(pack(push, 1))
    #define CBF_PACK_POP  __pragma(pack(pop))
    #define CBF_PACKED
#else
    #define CBF_PACK_PUSH
    #define CBF_PACK_POP
    #define CBF_PACKED __attribute__((packed))
#endif

#ifndef CBF_WINE_LINUX_INPUT
    #define CBF_WINE_LINUX_INPUT 0
#endif

enum DeviceType : int8_t {
    MOUSE,
    TOUCHPAD,
    KEYBOARD,
    TOUCHSCREEN,
    CONTROLLER,
    UNKNOWN
};

CBF_PACK_PUSH
struct CBF_PACKED LinuxInputEvent {
    LARGE_INTEGER time;
    USHORT type;
    USHORT code;
    int value;
    DeviceType deviceType;
};
CBF_PACK_POP

extern HANDLE hSharedMem;
extern HANDLE hMutex;
extern LPVOID pBuf;

extern bool linuxNative;

inline LARGE_INTEGER largeFromTimestamp(TimestampType t) {
	LARGE_INTEGER res;
	res.QuadPart = t;
	return res;
}

inline TimestampType timestampFromLarge(LARGE_INTEGER l) {
	return l.QuadPart;
}

constexpr size_t BUFFER_SIZE = 20;

void windowsSetup();
void linuxCheckInputs();
void rawInputThread();
