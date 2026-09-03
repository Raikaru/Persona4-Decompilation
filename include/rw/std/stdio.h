#ifndef RW_SHIM_STDIO_H
#define RW_SHIM_STDIO_H
#include <stddef.h>
#include <stdarg.h>
typedef struct FILE FILE;
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define EOF (-1)
extern int sprintf(char *buffer, const char *format, ...);
extern int vsprintf(char *buffer, const char *format, va_list ap);
extern int printf(const char *format, ...);
extern int sscanf(const char *buffer, const char *format, ...);
#endif
