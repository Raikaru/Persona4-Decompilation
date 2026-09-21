/*
 * stdarg.h - the variadic macros for the CRI sources under ee-gcc.
 *
 * include/rw/std/stdarg.h serves the RenderWare block and defines only
 * `va_list`; ee-gcc's headers additionally spell the type `__gnuc_va_list`,
 * and CRI's error formatters use it. See include/cri/ps2/libcdvd.h for how
 * these shims are validated.
 */
#ifndef CRI_SHIM_STDARG_H
#define CRI_SHIM_STDARG_H

typedef char *__gnuc_va_list;
typedef __gnuc_va_list va_list;

#define va_start(ap, last) ((ap) = (char *)&(last) + ((sizeof(last) + 3) & ~3))
#define va_arg(ap, type) \
    (*(type *)(((ap) += ((sizeof(type) + 3) & ~3)) - ((sizeof(type) + 3) & ~3)))
#define va_end(ap) ((void)0)

#endif /* CRI_SHIM_STDARG_H */
