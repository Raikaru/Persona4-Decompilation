/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleCard.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_00368be0(void);
extern void func_0036c450(void);
extern void func_0036dba0(u8 *arg0);

extern void func_003dc740(void *dest, void *src, s32 mode, f32 fparg0);
extern void func_0036de20(u8 *arg0, void *arg1);

extern void func_0036b5e0(u8 *arg0, f32 *out);

// FUN_0036D990
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036d990);
// FUN_0036DA40
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036da40);
// FUN_0036DAA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036daa0);




// FUN_0036DB20
void func_0036db20(u8 *arg0)
{
    func_00368be0();
    func_0036c450();
    func_0036dba0(arg0);
}

// FUN_0036DB60
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036db60);
// FUN_0036DBA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036dba0);
// FUN_0036DC60
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036dc60);
// FUN_0036DD10
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036dd10);
// FUN_0036DDA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036dda0);
// FUN_0036DDC0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036ddc0);




// FUN_0036DDE0
void func_0036dde0(u8 *arg0, void *arg1, s32 arg2, f32 fparg0)
{
    f32 sp20[4];

    func_003dc740(sp20, arg1, arg2, fparg0);
    func_0036de20(arg0, sp20);
}

// FUN_0036DE20
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036de20);
// FUN_0036DE40
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036de40);




// FUN_0036DE70
f32 func_0036de70(u8 *arg0)
{
    f32 sp10[3];

    func_0036b5e0(arg0, sp10);
    return 6.0f * sp10[0];
}

// FUN_0036DEB0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036deb0);
// FUN_0036DEE0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036dee0);
// FUN_0036DF30
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036df30);
// FUN_0036DF90
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036df90);
// FUN_0036E000
INCLUDE_ASM("asm/nonmatchings/btlShuffleCard", func_0036e000);
