#ifndef RW_SHIM_STDARG_H
#define RW_SHIM_STDARG_H
typedef char *va_list;
#define va_start(ap, last) ((ap) = (char *)&(last) + ((sizeof(last) + 3) & ~3))
#define va_arg(ap, type) (*(type *)(((ap) += ((sizeof(type) + 3) & ~3)) - ((sizeof(type) + 3) & ~3)))
#define va_end(ap) ((void)0)
#endif
