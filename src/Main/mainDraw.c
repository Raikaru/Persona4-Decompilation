/* Consolidated Persona 4 source units. */
/* Original translation unit mainDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern void (*D_00887300[])(u32, u32);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00481430(void *arg0);
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern void func_003e82a0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00457120(void);
extern s32 func_00457130(void);
extern void func_0044f6b0(void);
extern void func_00460a80(void *arg0, s32 arg1);
extern void func_00460ac0(void *arg0, void *arg1);
extern void func_004623a0(s32 arg0);
extern void func_0044ea90(void *file, s32 line);
extern void func_0046d730(void *file, s32 line);
extern s32 func_00451de0();
extern u8 D_00793E80[];
extern u8 D_00793EB0[];
extern u8 D_00794900[];
extern u8 D_005DCAE8[];
extern u8 D_005DCAF8[];
extern u8 D_005DCB10[];
extern u8 D_001013A0[];
extern void (*D_00793FA8[])(void);
extern s32 D_00793FB0[];
extern u16 D_00793FBA[];
extern void (*D_00793FD8[])(void);
extern s32 D_00793FE0[];
extern u16 D_00793FEA[];
extern void (*D_00794008[])(void);
extern s32 D_00794010[];
extern u16 D_0079401A[];
extern void (*D_00794038[])(void);
extern s32 D_00794040[];
extern u16 D_0079404A[];
extern void (*D_00794068[])(void);
extern s32 D_00794070[];
extern u16 D_0079407A[];
extern void (*D_00794098[])(void);
extern s32 D_007940A0[];
extern u16 D_007940AA[];
extern void (*D_007940C8[])(void);
extern s32 D_007940D0[];
extern u16 D_007940DA[];
extern void (*D_00794188[])(void);
extern s32 D_00794190[];
extern u16 D_0079419A[];
extern void (*D_007941B8[])(void);
extern s32 D_007941C0[];
extern u16 D_007941CA[];
extern void (*D_007941E8[])(void);
extern s32 D_007941F0[];
extern u16 D_007941FA[];
extern void (*D_00794218[])(void);
extern s32 D_00794220[];
extern u16 D_0079422A[];
extern void (*D_00794248[])(void);
extern s32 D_00794250[];
extern u16 D_0079425A[];
extern void (*D_00794278[])(void);
extern s32 D_00794280[];
extern u16 D_0079428A[];
extern void (*D_007942A8[])(void);
extern s32 D_007942B0[];
extern u16 D_007942BA[];
extern void (*D_00794458[])(void);
extern s32 D_00794460[];
extern u16 D_0079446A[];
extern void (*D_00794488[])(void);
extern s32 D_00794490[];
extern u16 D_0079449A[];
extern void (*D_007944B8[])(void);
extern s32 D_007944C0[];
extern u16 D_007944CA[];
extern void (*D_007944E8[])(void);
extern s32 D_007944F0[];
extern u16 D_007944FA[];
extern void (*D_00794518[])(void);
extern s32 D_00794520[];
extern u16 D_0079452A[];
extern void (*D_00794548[])(void);
extern s32 D_00794550[];
extern u16 D_0079455A[];
extern void (*D_00794578[])(void);
extern s32 D_00794580[];
extern u16 D_0079458A[];
extern void (*D_00794698[])(void);
extern s32 D_007946A0[];
extern u16 D_007946AA[];
extern void (*D_007946C8[])(void);
extern s32 D_007946D0[];
extern u16 D_007946DA[];
extern void (*D_007946F8[])(void);
extern s32 D_00794700[];
extern u16 D_0079470A[];
extern void (*D_00794728[])(void);
extern s32 D_00794730[];
extern u16 D_0079473A[];
extern void (*D_00794758[])(void);
extern s32 D_00794760[];
extern u16 D_0079476A[];
extern void (*D_00794788[])(void);
extern s32 D_00794790[];
extern u16 D_0079479A[];
extern void (*D_007947B8[])(void);
extern s32 D_007947C0[];
extern u16 D_007947CA[];
extern void (*D_00794AE8[])(void);
extern s32 D_00794AF0[];
extern u16 D_00794AFA[];
extern void (*D_00794B18[])(void);
extern s32 D_00794B20[];
extern u16 D_00794B2A[];
extern void (*D_00794B48[])(void);
extern s32 D_00794B50[];
extern u16 D_00794B5A[];
extern void (*D_00794B78[])(void);
extern s32 D_00794B80[];
extern u16 D_00794B8A[];
extern void (*D_00794BA8[])(void);
extern s32 D_00794BB0[];
extern u16 D_00794BBA[];
extern void (*D_00794BD8[])(void);
extern s32 D_00794BE0[];
extern u16 D_00794BEA[];
extern void (*D_00794C08[])(void);
extern s32 D_00794C10[];
extern u16 D_00794C1A[];
extern void (*D_00795058[])(void);
extern s32 D_00795060[];
extern u16 D_0079506A[];
extern void (*D_00795CE8[])(void);
extern s32 D_00795CF0[];
extern u16 D_00795CFA[];
extern void (*D_00795D18[])(void);
extern s32 D_00795D20[];
extern u16 D_00795D2A[];
extern void (*D_00795D48[])(void);
extern s32 D_00795D50[];
extern u16 D_00795D5A[];
extern void (*D_00795D78[])(void);
extern s32 D_00795D80[];
extern u16 D_00795D8A[];
extern void (*D_00795DA8[])(void);
extern s32 D_00795DB0[];
extern u16 D_00795DBA[];
extern void (*D_00795DD8[])(void);
extern s32 D_00795DE0[];
extern u16 D_00795DEA[];
extern void (*D_00795E08[])(void);
extern s32 D_00795E10[];
extern u16 D_00795E1A[];
extern void (*D_00796078[])(void);
extern s32 D_00796080[];
extern u16 D_0079608A[];
extern void (*D_007960A8[])(void);
extern s32 D_007960B0[];
extern u16 D_007960BA[];
extern void (*D_007960D8[])(void);
extern s32 D_007960E0[];
extern u16 D_007960EA[];
extern void (*D_00796108[])(void);
extern s32 D_00796110[];
extern u16 D_0079611A[];
extern void (*D_00796138[])(void);
extern s32 D_00796140[];
extern u16 D_0079614A[];
extern void (*D_00796168[])(void);
extern s32 D_00796170[];
extern u16 D_0079617A[];
extern void (*D_00796198[])(void);
extern s32 D_007961A0[];
extern u16 D_007961AA[];
extern void (*D_00796528[])(void);
extern s32 D_00796530[];
extern u16 D_0079653A[];
extern void (*D_00796558[])(void);
extern s32 D_00796560[];
extern u16 D_0079656A[];
extern void (*D_00796588[])(void);
extern s32 D_00796590[];
extern u16 D_0079659A[];
extern void (*D_007965B8[])(void);
extern s32 D_007965C0[];
extern u16 D_007965CA[];
extern void (*D_007965E8[])(void);
extern s32 D_007965F0[];
extern u16 D_007965FA[];
extern void (*D_00796618[])(void);
extern s32 D_00796620[];
extern u16 D_0079662A[];
extern void (*D_00796648[])(void);
extern s32 D_00796650[];
extern u16 D_0079665A[];
extern void func_001015c0(void);
extern void func_001016f0(void);
extern void func_00101820(void);
extern void func_00101950(void);
extern void func_00101a80(void);
extern void func_001014b0(void);
extern s32 func_00101bb0(u8 *arg0);
extern s32 func_00102550(void);
extern void func_001025e0(void *arg0);


/* measured: retail hoists the D_00887300 vtable base into $s0 once
   (lui/addiu) and reloads `lw $v0, 0($s0)` per call; mwcc b210 folds the
   address into each call (`lui $v0; lw $v0, 0($v0)`) even when the base is
   named in a local `void (**tbl)(u32,u32) = D_00887300;` (local gets folded
   back into the constant). Tried both the direct D_00887300[0](...) spelling
   and the local-pointer spelling: identical nd 67 (6 differing words at the
   3 call sites + downstream branch-target shifts). Same vtable-hoist floor
   as func_001015c0/16f0/1820/1950/1a80. */
// FUN_001014B0
INCLUDE_ASM("asm/nonmatchings/mainDraw", func_001014b0);

// FUN_001015C0
#pragma opt_propagation off
void func_001015c0(void) {
    void (**base)(u32, u32);

    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    func_00481430(func_001015c0);
}
#pragma opt_propagation on

// FUN_001016F0
#pragma opt_propagation off
void func_001016f0(void) {
    void (**base)(u32, u32);

    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x44);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    func_00481430(func_001016f0);
}
#pragma opt_propagation on

// FUN_00101820
#pragma opt_propagation off
void func_00101820(void) {
    void (**base)(u32, u32);

    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    func_00481430(func_00101820);
}
#pragma opt_propagation on

// FUN_00101950
#pragma opt_propagation off
void func_00101950(void) {
    void (**base)(u32, u32);

    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x42);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    func_00481430(func_00101950);
}
#pragma opt_propagation on

// FUN_00101A80
#pragma opt_propagation off
void func_00101a80(void) {
    void (**base)(u32, u32);

    func_003f6440(3, 0x71801);
    func_003f6440(2, 6);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](0x14, 1);
    base[0](9, 2);
    base[0](6, 1);
    base[0](8, 0);
    base[0](3, 1);
    base[0](4, 1);
    base[0](1, 0);
    func_00481430(func_00101a80);
}
#pragma opt_propagation on

// FUN_00101BB0
s32 func_00101bb0(u8 *arg0) {
    u8 *temp_17;
    s32 temp_16;

    temp_17 = *(u8 **)(arg0 + 0x38);
    func_0044f6b0();
    temp_16 = func_00457120();
    func_003e82a0(temp_16, func_00457130(), 3);
    func_00460a80(&D_00793E80, 0xD8);
    *(s32 *)temp_17 = 0;
    *(s32 *)(temp_17 + 4) = 0;
    *(s32 *)(temp_17 + 0x30) = 0;
    *(s32 *)(temp_17 + 0x34) = 0;
    func_00460ac0(&D_00793EB0, temp_17);
    func_00460ac0(&D_00794900, temp_17 + 0x30);
    D_00793FA8[0] = func_001015c0;
    D_00793FB0[0] = 0;
    D_00793FD8[0] = func_001016f0;
    D_00793FE0[0] = 0;
    D_00794008[0] = func_00101950;
    D_00794010[0] = 0;
    D_00794038[0] = func_00101a80;
    D_00794040[0] = 0;
    D_00794068[0] = func_00101820;
    D_00794070[0] = 0;
    D_00794098[0] = func_00101a80;
    D_007940A0[0] = 0;
    D_007940C8[0] = func_00101950;
    D_007940D0[0] = 0;
    D_00793FBA[0] |= 1;
    D_00793FEA[0] |= 1;
    D_0079401A[0] |= 1;
    D_0079404A[0] |= 1;
    D_0079407A[0] |= 1;
    D_007940AA[0] |= 1;
    D_007940DA[0] |= 1;
    D_00794188[0] = func_001015c0;
    D_00794190[0] = 0;
    D_007941B8[0] = func_001016f0;
    D_007941C0[0] = 0;
    D_007941E8[0] = func_00101950;
    D_007941F0[0] = 0;
    D_00794218[0] = func_00101a80;
    D_00794220[0] = 0;
    D_00794248[0] = func_00101820;
    D_00794250[0] = 0;
    D_00794278[0] = func_00101a80;
    D_00794280[0] = 0;
    D_007942A8[0] = func_00101950;
    D_007942B0[0] = 0;
    D_0079419A[0] |= 1;
    D_007941CA[0] |= 1;
    D_007941FA[0] |= 1;
    D_0079422A[0] |= 1;
    D_0079425A[0] |= 1;
    D_0079428A[0] |= 1;
    D_007942BA[0] |= 1;
    D_00794458[0] = func_001015c0;
    D_00794460[0] = 0;
    D_00794488[0] = func_001016f0;
    D_00794490[0] = 0;
    D_007944B8[0] = func_00101950;
    D_007944C0[0] = 0;
    D_007944E8[0] = func_00101a80;
    D_007944F0[0] = 0;
    D_00794518[0] = func_00101820;
    D_00794520[0] = 0;
    D_00794548[0] = func_00101a80;
    D_00794550[0] = 0;
    D_00794578[0] = func_00101950;
    D_00794580[0] = 0;
    D_0079446A[0] |= 1;
    D_0079449A[0] |= 1;
    D_007944CA[0] |= 1;
    D_007944FA[0] |= 1;
    D_0079452A[0] |= 1;
    D_0079455A[0] |= 1;
    D_0079458A[0] |= 1;
    D_00794AE8[0] = func_001015c0;
    D_00794AF0[0] = 0;
    D_00794B18[0] = func_001016f0;
    D_00794B20[0] = 0;
    D_00794B48[0] = func_00101950;
    D_00794B50[0] = 0;
    D_00794B78[0] = func_00101a80;
    D_00794B80[0] = 0;
    D_00794BA8[0] = func_00101820;
    D_00794BB0[0] = 0;
    D_00794BD8[0] = func_00101a80;
    D_00794BE0[0] = 0;
    D_00794C08[0] = func_00101950;
    D_00794C10[0] = 0;
    D_00794AFA[0] |= 1;
    D_00794B2A[0] |= 1;
    D_00794B5A[0] |= 1;
    D_00794B8A[0] |= 1;
    D_00794BBA[0] |= 1;
    D_00794BEA[0] |= 1;
    D_00794C1A[0] |= 1;
    D_00795CE8[0] = func_001015c0;
    D_00795CF0[0] = 0;
    D_00795D18[0] = func_001016f0;
    D_00795D20[0] = 0;
    D_00795D48[0] = func_00101950;
    D_00795D50[0] = 0;
    D_00795D78[0] = func_00101a80;
    D_00795D80[0] = 0;
    D_00795DA8[0] = func_00101820;
    D_00795DB0[0] = 0;
    D_00795DD8[0] = func_00101a80;
    D_00795DE0[0] = 0;
    D_00795E08[0] = func_00101950;
    D_00795E10[0] = 0;
    D_00795CFA[0] |= 1;
    D_00795D2A[0] |= 1;
    D_00795D5A[0] |= 1;
    D_00795D8A[0] |= 1;
    D_00795DBA[0] |= 1;
    D_00795DEA[0] |= 1;
    D_00795E1A[0] |= 1;
    D_00796528[0] = func_001015c0;
    D_00796530[0] = 0;
    D_00796558[0] = func_001016f0;
    D_00796560[0] = 0;
    D_00796588[0] = func_00101950;
    D_00796590[0] = 0;
    D_007965B8[0] = func_00101a80;
    D_007965C0[0] = 0;
    D_007965E8[0] = func_00101820;
    D_007965F0[0] = 0;
    D_00796618[0] = func_00101a80;
    D_00796620[0] = 0;
    D_00796648[0] = func_00101950;
    D_00796650[0] = 0;
    D_0079653A[0] |= 1;
    D_0079656A[0] |= 1;
    D_0079659A[0] |= 1;
    D_007965CA[0] |= 1;
    D_007965FA[0] |= 1;
    D_0079662A[0] |= 1;
    D_0079665A[0] |= 1;
    D_00796078[0] = func_001015c0;
    D_00796080[0] = 0;
    D_007960A8[0] = func_001016f0;
    D_007960B0[0] = 0;
    D_007960D8[0] = func_00101950;
    D_007960E0[0] = 0;
    D_00796108[0] = func_00101a80;
    D_00796110[0] = 0;
    D_00796138[0] = func_00101820;
    D_00796140[0] = 0;
    D_00796168[0] = func_00101a80;
    D_00796170[0] = 0;
    D_00796198[0] = func_00101950;
    D_007961A0[0] = 0;
    D_0079608A[0] |= 1;
    D_007960BA[0] |= 1;
    D_007960EA[0] |= 1;
    D_0079611A[0] |= 1;
    D_0079614A[0] |= 1;
    D_0079617A[0] |= 1;
    D_007961AA[0] |= 1;
    D_00794698[0] = func_001015c0;
    D_007946A0[0] = 0;
    D_007946C8[0] = func_001016f0;
    D_007946D0[0] = 0;
    D_007946F8[0] = func_00101950;
    D_00794700[0] = 0;
    D_00794728[0] = func_00101a80;
    D_00794730[0] = 0;
    D_00794758[0] = func_00101820;
    D_00794760[0] = 0;
    D_00794788[0] = func_00101a80;
    D_00794790[0] = 0;
    D_007947B8[0] = func_00101950;
    D_007947C0[0] = 0;
    D_007946AA[0] |= 1;
    D_007946DA[0] |= 1;
    D_0079470A[0] |= 1;
    D_0079473A[0] |= 1;
    D_0079476A[0] |= 1;
    D_0079479A[0] |= 1;
    D_007947CA[0] |= 1;
    D_00795058[0] = func_001015c0;
    D_00795060[0] = 0;
    D_0079506A[0] |= 1;
    return 0;
}

// FUN_00102490
void func_00102490(void) {
    u8 *temp_2;
    s32 temp_2_2;

    func_0044ea90(&D_005DCAE8, 0x13B);
    temp_2 = D_008873F4[0](1, 0x60, 0x40000);
    temp_2_2 = func_00451de0(&D_005DCAF8, 0xA, 0, 0, func_00101bb0, NULL, temp_2);
    *(void **)(temp_2 + 8) = &D_001013A0;
    *(s32 *)(temp_2 + 0x10) = 0;
    *(void (**)(void))(temp_2 + 0x38) = func_001014b0;
    *(s32 *)(temp_2 + 0x40) = 0;
    if (temp_2_2 == 0) {
        func_0046d730(&D_005DCAE8, 0x14F);
    }
}

// FUN_00102550
s32 func_00102550(void) {
    u32 var_16;

    if (func_003e8120(func_00457120()) != 0) {
        var_16 = 0;
        while (var_16 < 0xD8U) {
            s32 off = var_16 * 0x30;
            func_004623a0((s32)&D_00793E80 + off);
            var_16 += 1;
        }
    }
    func_003e8110(func_00457120());
    return 0;
}

// FUN_001025E0
void func_001025e0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_00102610
void func_00102610(void) {
    func_0044ea90(&D_005DCAE8, 0x1FD);
    if (func_00451de0(&D_005DCB10, 0xC8, 0, 0, func_00102550, func_001025e0,
                      D_008873F4[0](1, 4, 0x40000)) == 0) {
        func_0046d730(&D_005DCAE8, 0x208);
    }
}
