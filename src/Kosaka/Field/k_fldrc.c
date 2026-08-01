/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00102E70)
/* Source unit: src/Kosaka/Field/k_fldrc.c */
#include "type.h"

extern void func_00192e90(void);
extern void func_00193730(void);

// FUN_00102E70
void func_00102e70(void)
{
    func_00192e90();
    func_00193730();
}
#endif /* P4_UNIT_00102E70 */

#if defined(P4_UNIT_00150890)
/* Source unit: src/Kosaka/Field/k_fldrc.c */
#include "type.h"

/*
 * Retail reaches the "%03d" / "_%03d" / ".rws" fragments of its field-path
 * format table through gp-relative addiu with the offset folded in as an
 * addend.  These dummy externs are anchored at the GP base (0x007690f0) so
 * the pointer-minus-offset expressions below materialize the string
 * addresses (0x00762ee8 / 0x00762ef0 / 0x00762ef8) exactly like the donor
 * P3 unit (gp0xffff9538 at the P3 GP base, minus 0x6ac8).
 */
extern u32 gp0xffff9df8;
extern u32 gp0xffff9e00;
extern u32 gp0xffff9e08;
extern s32 iGpffffb204;
extern char D_005efcc0[];
extern char D_005efcd0[];
extern u32 func_00442088();
extern u32 func_00442428();
extern u32 func_00442830();
extern void* func_00150970(char* path);

// FUN_00150890
void* func_00150890(s16 majorId, s16 minorId)
{
    char path[40];
    char token[8];

    if (iGpffffb204 == 0)
    {
        func_00442830(path, D_005efcc0);
    }
    else
    {
        func_00442830(path, D_005efcd0);
    }
    func_00442088(token, (const char*)&gp0xffff9df8 - 0x6208, majorId);
    func_00442428(path, token);
    func_00442088(token, (const char*)&gp0xffff9e00 - 0x6200, minorId);
    func_00442428(path, token);
    func_00442428(path, (const char*)&gp0xffff9e08 - 0x61f8);
    return func_00150970(path);
}
#endif /* P4_UNIT_00150890 */
