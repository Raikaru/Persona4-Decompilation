#ifndef RUNTIME_STDIO_INTERNAL_H
#define RUNTIME_STDIO_INTERNAL_H

/* The EE argument list points into its eight-byte register-save slots. */
int vsprintf(char *buffer, const char *format, void *arguments);

/* Retail printf and scePrintf preserve the supplied message as the format. */
int func_00440b68(const char *format, ...);
int func_004244c8(const char *format, ...);

#endif
