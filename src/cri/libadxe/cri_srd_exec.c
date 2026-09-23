/* Persona 4 SRD/PS2EE 2.22 server dispatcher, independently derived from
 * retail code at 0x004E4190. The older CRI 2.18a source at
 * https://github.com/crowded-street/3s-decomp/blob/main/src/anniversary/cri/libadxe/cri_srd.c
 * corroborates the API name, not this body; no external code was copied. */
#include "type.h"

extern s8 D_00731C00[]; /* srd_obj; devtype is byte +1 */
extern s32 D_00731C3C;
extern volatile s32 D_00731C40, D_00731C44; /* asynchronous lock flags */
extern s32 func_004f1278(s32 *);
extern void func_004f0668(void), func_004f06e0(void);
extern void func_004e3dc8(s8 *), func_004e3fb0(s8 *);

/* SRD_ExecServer. */
// FUN_004E4190
void func_004e4190(void) {
    s8 *srd = D_00731C00;
    if (func_004f1278(&D_00731C3C) == 0) return;
    if (srd[1] == 1) {
        if (D_00731C40 == 1) func_004f0668();
        func_004e3dc8(srd);
        if (D_00731C40 == 1) func_004f06e0();
    }
    if (srd[1] == 2) {
        if (D_00731C44 == 1) func_004f0668();
        func_004e3fb0(srd);
        if (D_00731C44 == 1) func_004f06e0();
    }
    D_00731C3C = 0;
}
