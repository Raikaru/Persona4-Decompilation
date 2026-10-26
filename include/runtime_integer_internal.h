#ifndef RUNTIME_INTEGER_INTERNAL_H
#define RUNTIME_INTEGER_INTERNAL_H

#include "type.h"

struct _reent;

/* EE long is 64 bits and char ** points to a four-byte PS2 pointer slot. */
s64 _strtol_r(struct _reent *context, const char *text, char **end, s32 base);
s64 strtol(const char *text, char **end, s32 base);
u64 _strtoul_r(struct _reent *context, const char *text, char **end, s32 base);
u64 strtoul(const char *text, char **end, s32 base);
s32 atoi(const char *text);

#endif
