/*
 * ostypes.h - RenderWare base types for the PlayStation 2 build.
 *
 * The RenderWare 3.7.0.2 source this project reconstructs the code1_0039..
 * code1_003e block from ships only the Windows ostypes.h (core/os/win); the
 * sky2 one is not in that tree. This is the same header with the MWCCPS2
 * answers filled in: 64-bit integers are native `long long`, the machine is
 * little-endian, and RwReal is a 32-bit float.
 */
#ifndef PS2_OSTYPES_H
#define PS2_OSTYPES_H

#define rwLITTLEENDIAN          /* This is a little endian machine */

typedef long RwFixed;
typedef int RwInt32;
typedef unsigned int RwUInt32;
typedef short RwInt16;
typedef unsigned short RwUInt16;
typedef unsigned char RwUInt8;
typedef signed char RwInt8;

#ifdef RWUNICODE
typedef wchar_t RwChar;
#else /* RWUNICODE */
typedef char RwChar;
#endif /* RWUNICODE */

typedef float RwReal;
typedef RwInt32 RwBool;

typedef long long RwInt64;
typedef unsigned long long RwUInt64;
#define RWZERO64 ((RwUInt64)0)

/* Structure alignment: matrices and vectors are quadword aligned on the
 * EE so the VU macros can lq/sq them; the public rwplcore.h for other
 * targets declares these as sizeof(RwUInt32). */
#define RWALIGN(type, x)   type __attribute__((aligned(x)))
#define rwMATRIXALIGNMENT  16
#define rwFRAMEALIGNMENT   16
#define rwV4DALIGNMENT     16
#define rwMALLOCALIGNMENT  16

/* The PlayStation 2 library keeps the engine instance in a static array
 * (`ourGlobals`, retail 0x008872E0) rather than behind a pointer: balibtyp.h
 * turns RwEngineInstance into that array when RWGLOBALSIZE is defined. The
 * size only sizes the array declaration; the plugin globals appended by the
 * toolkit registry are what actually fill it at run time. */
#define RWGLOBALSIZE 0x400

#endif /* PS2_OSTYPES_H */
