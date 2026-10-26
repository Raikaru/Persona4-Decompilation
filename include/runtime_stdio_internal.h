#ifndef RUNTIME_STDIO_INTERNAL_H
#define RUNTIME_STDIO_INTERNAL_H

/* The EE argument list points into its eight-byte register-save slots. */
int vsprintf(char *buffer, const char *format, void *arguments);

#endif
