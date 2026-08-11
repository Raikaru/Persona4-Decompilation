#include "include_asm.h"
#include "type.h"

extern s32 D_0075DDD8[];

extern s32 D_0075DE40[];

extern s32 D_0075E8B0[];

extern s32 D_007442A0[];
extern s32 D_0074428C;
extern s32 D_00745884;
extern s32 D_00745880;
extern s32 D_0074587C;
extern s32 D_00744164;
extern s32 D_00744168;

extern void func_0050cd00(s32 arg0);
extern void func_0043f810(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_0074586C[];

extern s32 D_00745878[];
extern void func_005179f8(void);
/* Census note: the 24-byte tier here is mostly a confirmed framed tail-jump
   floor, not a reusable template backlog. The floor members are:
   00503848, 005074A8, 005074F0, 00507508, 00507768, 005097E8,
   0050C008, 0050C128, 0050C218, 0050C360, 0050C910, 0050C928,
   0050CD80, 0050CD98, 0050CDB0, 00507520, 0050BEE8, 0050C8B0,
   0050C8C8, 0050C8E0, 0050C8F8, 0050CFE0, 0050CFF8.
   The first 15 use the plain framed tail shape; 00507520, 0050BEE8,
   0050C8B0, 0050C8C8, 0050C8E0, and 0050C8F8 add a pre-tail load;
   0050CFE0 and 0050CFF8 add a pre-tail addiu. The only real 24-byte
   members are 00507950 and 0050B3E0. Above this tier: 56-byte has one
   pair plus singletons, 40-byte has two triples plus singletons, 136-byte
   has one pair plus singletons, and 120-byte is seven singletons; this
   singleton-heavy shape is the actual file structure.
*/

/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

/* measured: 00503478 has a 16-byte window containing two jr $ra/nop pairs; the second pair is unreferenced and not registrable, so this boundary is unmatchable in C. */
// FUN_00503478
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503478);
// FUN_00503488
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503488);
// FUN_005034F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005034f0);
// FUN_005035A0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005035a0);
// FUN_00503638
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503638);
// FUN_005036B8
s32 *func_005036b8(void)
{
    return D_0075DDD8;
}
#pragma optimization_level 2


/* measured: -O2 emits both stores before jr $ra; retail schedules the second
   store into the jr delay slot (sw $a2, 4($a0); jr $ra; sw $a1, ($a0)). */
#pragma optimization_level 3

// FUN_005036C8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005036c8);
// FUN_00503740
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503740);
// FUN_005037D0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005037d0);
// FUN_00503848
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503848);
// FUN_00503870
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503870);
// FUN_005038C0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005038c0);
// FUN_005038F8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005038f8);
// FUN_00503990
void func_00503990(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)arg0 = arg1;
    *(s32 *)(arg0 + 4) = arg2;
}
#pragma optimization_level 2


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_005039A0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005039a0);
// FUN_00503A40
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503a40);
// FUN_00503A68
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503a68);
// FUN_00503AA0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503aa0);
// FUN_00503AF8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00503af8);
// FUN_00506B88
s32 *func_00506b88(void)
{
    return D_0075DE40;
}
#pragma optimization_level 2


/* measured: retail is lui $v0; jr; sw %lo(D_0074428C)($v0) -- the base is a
   live return value, which is why the store folds into an offset off $v0
   (same family as func_004d18d8/004d3148/004d3678/004d36a8). A void
   spelling colors the base $v1 (nd 2); returning the segment pointer (lo
   bits zero, so lui alone materializes it) gives nd 0. */
#pragma schedule on

// FUN_00506B98
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00506b98);
// FUN_00506C30
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00506c30);
// FUN_00506D08
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00506d08);
// FUN_00506D80
void func_00506d80(void)
{
}
// FUN_00507258
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507258);
// FUN_005072C0
void func_005072c0(void)
{
}
// FUN_005072C8
void func_005072c8(void)
{
}
// FUN_005072D8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005072d8);
// FUN_005073A0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005073a0);
// FUN_005073F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005073f0);
// FUN_00507480
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507480);
// FUN_005074A8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005074a8);
// FUN_005074C0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005074c0);
// FUN_005074F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005074f0);
// FUN_00507508
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507508);
// FUN_00507520
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507520);
// FUN_00507538
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507538);
// FUN_00507560
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507560);
// FUN_00507628
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507628);
// FUN_00507768
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507768);
// FUN_00507780
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507780);
// FUN_005077F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005077f0);
// FUN_005078A0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005078a0);
// FUN_00507948
s32 func_00507948(void)
{
    return 0;
}
// FUN_00507950
extern s32 D_00744164;
extern s32 D_00744168;
s32 func_00507950(s32 arg0, s32 arg1)
{
    D_00744164 = arg0;
    D_00744168 = arg1;
    return 0;
}
// FUN_00507968
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00507968);
// FUN_00509698
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00509698);
// FUN_00509720
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00509720);
// FUN_005097E8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_005097e8);
// FUN_00509800
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00509800);
// FUN_00509910
void func_00509910(s32 arg0)
{
    D_0074428C = arg0;
}
/* measured: closes the schedule-on segment-return bracket through func_00509910; explicit schedule off restores the following code's baseline state. */
#pragma schedule off


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_00509920
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00509920);
// FUN_00509A30
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_00509a30);
// FUN_0050B290
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b290);
// FUN_0050B300
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b300);
// FUN_0050B388
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b388);
// FUN_0050B3C0
s32 *func_0050b3c0(void)
{
    return D_0075E8B0;
}
#pragma optimization_level 2


/* measured: -O2 emits lui/addiu before jr $ra; retail schedules the final
   addiu into the jr delay slot (lui $v0; jr $ra; addiu $v0, $v0, %lo). */
#pragma optimization_level 3

// FUN_0050B3D0
s32 *func_0050b3d0(void)
{
    return D_007442A0;
}
#pragma optimization_level 2


/* retail: lui $v1; jr; lw $v0, %lo(D)($v1) (separate base $v1); mwcc b210
   merges the base into $v0 (lui $v0; jr; lw $v0, ($v0)), nd 2. Tried
   schedule on/off, opt_regalloc on/off, u32, pointer local (*p and p[0]),
   address-of, u8-cast; corroborated across 19 getters in code1_004c/004d/
   004e/004f/0050/0051/0052 with 16+ spellings. measured allocator floor
   ($v0/$v1 coalescing in tiny accessors; getters not reachable). */
#pragma optimization_level 3

#pragma optimization_level 2


/* retail: lui $v1; jr; lw $v0, %lo(D)($v1) (separate base $v1); mwcc b210
   merges the base into $v0 (lui $v0; jr; lw $v0, ($v0)), nd 2. Tried
   schedule on/off, opt_regalloc on/off, u32, pointer local (*p and p[0]),
   address-of, u8-cast; corroborated across 19 getters in code1_004c/004d/
   004e/004f/0050/0051/0052 with 16+ spellings. measured allocator floor
   ($v0/$v1 coalescing in tiny accessors; getters not reachable). */
#pragma optimization_level 3

#pragma optimization_level 2


/* measured: retail is lui $v0; jr; sw %lo(D_00745884)($v0) -- the base is a
   live return value, which is why the store folds into an offset off $v0
   (same family as func_004d18d8/004d3148/004d3678/004d36a8). A void
   spelling colors the base $v1 (nd 2); returning the segment pointer (lo
   bits zero, so lui alone materializes it) gives nd 0. */
#pragma schedule on

// FUN_0050B3E0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b3e0);
// FUN_0050B3F8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b3f8);
// FUN_0050B5B0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b5b0);
// FUN_0050B610
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b610);
// FUN_0050B6B8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b6b8);
// FUN_0050B6E0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b6e0);
// FUN_0050B700
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b700);
// FUN_0050B728
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b728);
// FUN_0050B748
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b748);
// FUN_0050B780
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b780);
// FUN_0050B7B0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b7b0);
// FUN_0050B8F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b8f0);
// FUN_0050B920
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b920);
// FUN_0050B940
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050b940);
// FUN_0050B9E8
s32 func_0050b9e8(void)
{
    func_005179f8();
    return 0;
}
// FUN_0050BA08
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ba08);
// FUN_0050BCB0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bcb0);
// FUN_0050BCD8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bcd8);
// FUN_0050BCF8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bcf8);
// FUN_0050BD48
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bd48);
// FUN_0050BD80
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bd80);
// FUN_0050BDC0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bdc0);
// FUN_0050BE00
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050be00);
// FUN_0050BE60
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050be60);
// FUN_0050BE90
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050be90);
// FUN_0050BEE8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bee8);
// FUN_0050BF00
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bf00);
// FUN_0050C008
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c008);
// FUN_0050C020
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c020);
// FUN_0050C0A8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c0a8);
// FUN_0050C128
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c128);
// FUN_0050C140
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c140);
// FUN_0050C218
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c218);
// FUN_0050C230
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c230);
// FUN_0050C2B8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c2b8);
// FUN_0050C360
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c360);
// FUN_0050C378
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c378);
// FUN_0050C3E0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c3e0);
// FUN_0050C508
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c508);
// FUN_0050C590
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c590);
// FUN_0050C5E8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c5e8);
// FUN_0050C640
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c640);
// FUN_0050C6B8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c6b8);
// FUN_0050C6D8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c6d8);
// FUN_0050C728
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c728);
// FUN_0050C7A0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c7a0);
// FUN_0050C7F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c7f0);
// FUN_0050C8B0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c8b0);
// FUN_0050C8C8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c8c8);
// FUN_0050C8E0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c8e0);
// FUN_0050C8F8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c8f8);
// FUN_0050C910
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c910);
// FUN_0050C928
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c928);
// FUN_0050C940
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c940);
// FUN_0050C9D0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050c9d0);
// FUN_0050CA58
void func_0050ca58(s32 arg0)
{
    if (arg0 == 0) {
        D_00745878[0] = 0;
        return;
    }
    D_00745878[0] = 1;
}
// FUN_0050CAA0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050caa0);
// FUN_0050CAE0
void func_0050cae0(void)
{
    D_00745878[0] = 1;
    D_0074587C = 0;
    D_00745880 = 0;
    D_00745884 = 0;
}
// FUN_0050CB08
void func_0050cb08(void)
{
    func_0050cd00(8);
    func_0050cd00(9);
}
// FUN_0050CB28
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cb28);
// FUN_0050CB68
s32 func_0050cb68(s32 arg0, s32 arg1, s32 arg2)
{
    func_0043f810(arg2, arg0 + 0x70000000, arg1);
    return 0;
}
// FUN_0050CBA0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cba0);
// FUN_0050CC08
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cc08);
// FUN_0050CC48
s32 func_0050cc48(s32 arg0, s32 arg1, s32 arg2)
{
    func_0043f810(arg2 + 0x70000000, arg0, arg1);
    return 0;
}
// FUN_0050CC78
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cc78);
// FUN_0050CCE0
void func_0050cce0(s32 arg0)
{
    D_00745884 = arg0;
}
/* measured: closes the schedule-on segment-return bracket through func_0050cce0; explicit schedule off restores the following code's baseline state. */
#pragma schedule off

// FUN_0050CCF0
s32 func_0050ccf0(void)
{
    return D_00745884;
}
// FUN_0050CD00
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cd00);
// FUN_0050CD48
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cd48);
// FUN_0050CD80
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cd80);
// FUN_0050CD98
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cd98);
// FUN_0050CDB0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cdb0);
/* measured: 0050CDC8 has a 16-byte window containing two jr $ra/nop pairs; the second pair is unreferenced and not registrable, so this boundary is unmatchable in C. */
// FUN_0050CDC8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cdc8);
// FUN_0050CDD8
void func_0050cdd8(void)
{
}
// FUN_0050CDE0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cde0);
// FUN_0050CE40
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ce40);
// FUN_0050CE60
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ce60);
// FUN_0050CEB0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ceb0);
// FUN_0050CF00
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cf00);
// FUN_0050CF68
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cf68);
// FUN_0050CFE0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cfe0);
// FUN_0050CFF8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050cff8);
// FUN_0050D010
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d010);
// FUN_0050D088
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d088);
// FUN_0050D110
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d110);
// FUN_0050D148
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d148);
// FUN_0050D1A0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d1a0);
// FUN_0050D228
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d228);
// FUN_0050D260
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d260);
// FUN_0050D2B8
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d2b8);
// FUN_0050D2F0
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d2f0);
// FUN_0050D320
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d320);
// FUN_0050D348
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050d348);
/* measured: schedule on places the field load in the jr $ra delay slot for this 8-byte accessor. */
#pragma schedule on
// FUN_0050D370
s32 func_0050d370(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x40);
}
/* measured: closes the schedule-on bracket for func_0050d370; explicit schedule off restores the file baseline. */
#pragma schedule off