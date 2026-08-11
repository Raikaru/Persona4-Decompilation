#include "include_asm.h"
#include "type.h"
/* Toolchain-blocked: retail saves callee-saved registers with sd; MWCCPS2 3.0.1 emits sq. See build/ORCH_sd_toolchain_blocked.txt. */

s32 func_00439598(void);

s32 func_00439770(void);

s32 func_00439970(void);

s32 func_00438e60(void);

extern s32 D_008AC780[];
extern s32 D_0070FC58[];
extern s32 D_0070FC5C[];
extern s32 D_0070FC60[];
extern s32 D_0070FC64[];
extern s32 D_0070FC40[];
extern s32 D_008BD9C0[];
extern s32 D_008BDAC0[];
extern s32 D_00754B00[];
extern s32 D_008BE280[];
s32 func_0043ae60(s32);
s32 func_0043a810(s32);
void func_004217f0(s32);
void func_0043a2d0(s32, s32, s32, s32);
void func_0043a500(s32, s32, s32, s32);
void func_00421810(s32);
extern s32 D_008AC840[];
void func_00421820(s32);
void func_00422218(s32 *, s32);
extern s32 D_009389E0[];
s32 func_00421f98(s32, s32);

typedef struct {
    u8 _pad[0x14];
    s32 field_14;
    u8 _pad2[0x1c - 0x18];
    s32 field_1c;
    s32 field_20;
} D_008AC788_entry;
extern D_008AC788_entry D_008AC788[];
s32 func_00439cc8(s32, s32, s32, s32, s32);

s32 func_00431408(void);

extern s32 *D_00710070[];
void func_0043ddf8(u8 *, s16, s16, s32);
s32 func_0043DFA0(s32 *);
s32 func_004258b0(s32 *, s32, s32, s32 *, s32, s32 *, s32, s32, s32);
s32 *func_0043eae8(s32 *);
extern s32 D_00754EF0[];
void func_0043c6d8(u8 *, s32, s32);
s64 func_00444210(s32, s32, s32);



// FUN_00430018
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430018);
// FUN_00430090
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430090);
// FUN_004300C8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004300c8);
// FUN_00430180
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430180);
// FUN_004301D8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004301d8);
// FUN_00430210
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430210);
// FUN_00430328
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430328);
// FUN_00430440
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430440);
// FUN_00430578
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430578);
// FUN_00430630
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430630);
// FUN_004306F8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004306f8);
// FUN_004307D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004307d0);
// FUN_00430880
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430880);
// FUN_00430930
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430930);
// FUN_004309B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004309b0);
// FUN_00430A08
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430a08);
// FUN_00430A60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430a60);
// FUN_00430B30
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430b30);
// FUN_00430B98
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430b98);
// FUN_00430C00
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430c00);
// FUN_00430C68
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430c68);
// FUN_00430CD0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430cd0);
// FUN_00430DF8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430df8);
// FUN_00430E28
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430e28);
// FUN_00430ED8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430ed8);
// FUN_00430F60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430f60);
// FUN_00430F80
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00430f80);
// FUN_00431308
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431308);
// FUN_00431408
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431408);
// FUN_00431540
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431540);
// FUN_004315B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004315b0);
// FUN_004316A8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004316a8);
// FUN_00431850
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431850);
// FUN_00431928
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431928);
// FUN_004319B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004319b8);
// FUN_00431A38
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431a38);
// FUN_00431AE8
/* measured: schedule on is required for the adjacent matched 56-byte helper. */
#pragma schedule on
/* measured: opt_propagation off preserves the retail call argument/global
   materialization order (nd 22 -> 0, object 56/56). */
#pragma opt_propagation off
s32 func_00431ae8(s32 arg0) { extern s32 D_008968E0[]; extern void func_00421670(s32,s32); s32 g; if(arg0<=0)return 0x81010016; { s32 x; g=D_008968E0[0]; x=arg0; func_00421670(g,x); } return 0; }
/* measured: closes the opt_propagation scope at the file baseline. */
#pragma opt_propagation on
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
// FUN_00431B20
/* measured: opt_propagation off preserves the retail call argument/global
   materialization order (nd 22 -> 0, object 56/56). */
#pragma opt_propagation off
/* measured: schedule on is required for the adjacent matched 56-byte helper. */
#pragma schedule on
s32 func_00431b20(s32 arg0) { extern s32 D_008968E0[]; extern void func_00421680(s32,s32); s32 g; if(arg0<=0)return 0x81010016; { s32 x; g=D_008968E0[0]; x=arg0; func_00421680(g,x); } return 0; }
/* measured: closes the opt_propagation scope at the file baseline. */
#pragma opt_propagation on
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
// FUN_00431B58
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431b58);
// FUN_00431C08
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431c08);
// FUN_00431CB8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431cb8);
// FUN_00431D78
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431d78);
// FUN_00431E78
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431e78);
// FUN_00431F28
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00431f28);
// FUN_00432048
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432048);
// FUN_00432168
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432168);
// FUN_00432288
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432288);
// FUN_004323A8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004323a8);
// FUN_004324A0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004324a0);
// FUN_00432588
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432588);
// FUN_004326B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004326b8);
// FUN_004327B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004327b0);
// FUN_004328B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004328b0);
// FUN_004329B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004329b0);
// FUN_00432AD0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432ad0);
// FUN_00432BB8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432bb8);
// FUN_00432E18
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432e18);
// FUN_00432EC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432ec0);
// FUN_00432EE8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432ee8);
// FUN_00432F10
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432f10);
// FUN_00432F50
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432f50);
// FUN_00432F90
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432f90);
// FUN_00432FD0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00432fd0);
// FUN_00433010
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433010);
// FUN_00433050
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433050);
// FUN_00433090
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433090);
// FUN_004330D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004330d0);
// FUN_00433110
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433110);
// FUN_00433150
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433150);
// FUN_00433190
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433190);
// FUN_004331D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004331d0);
// FUN_00433210
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433210);
// FUN_00433250
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433250);
// FUN_00433290
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433290);
// FUN_004332D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004332d0);
// FUN_00433310
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433310);
// FUN_00433370
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433370);
// FUN_004333E0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004333e0);
// FUN_00433438
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433438);
// FUN_004334F0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004334f0);
// FUN_00433670
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433670);
// FUN_00433790
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433790);
// FUN_004337D8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004337d8);
// FUN_00433960
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433960);
// FUN_004339C0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004339c0);
// FUN_00433A28
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433a28);
// FUN_00433B48
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433b48);
// FUN_00433BD8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433bd8);
// FUN_00433CF0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433cf0);
// FUN_00433D38
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433d38);
// FUN_00433DA0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433da0);
// FUN_00433ED0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00433ed0);
// FUN_00434000
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00434000);
// FUN_004340D8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004340d8);
// FUN_00434258
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00434258);
// FUN_004342E8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004342e8);
// FUN_00434340
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00434340);
// FUN_004346D8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004346d8);
// FUN_00435008
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00435008);
// FUN_00435108
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00435108);
// FUN_004351A8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004351a8);
// FUN_00435208
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00435208);
// FUN_00435480
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00435480);
// FUN_004358D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004358d0);
// FUN_00435A78
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00435a78);
// FUN_00435BA8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00435ba8);
// FUN_00436078
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00436078);
// FUN_004361A8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004361a8);
// FUN_00436298
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00436298);
// FUN_00436828
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00436828);
// FUN_00436A30
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00436a30);
// FUN_00436D80
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00436d80);
// FUN_00437360
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00437360);
// FUN_00437430
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00437430);
// FUN_00437AB8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00437ab8);
// FUN_00437CE8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00437ce8);
// FUN_00437E10
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00437e10);
// FUN_00438330
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438330);
// FUN_004384B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004384b8);
// FUN_00438638
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438638);
// FUN_00438700
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438700);
/* measured: removing this pragma takes func_00438740 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on
// FUN_00438740
void func_00438740(void) {
    func_00439598();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: removing this pragma takes func_00438760 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438760
void func_00438760(void) {
    func_00439770();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: removing this pragma takes func_00438780 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on

// FUN_00438780
void func_00438780(void) {
    func_00439970();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off



// FUN_004387A0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004387a0);
// FUN_004388B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004388b8);
// FUN_004389D8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004389d8);
// FUN_00438A18
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438a18);
// FUN_00438A58
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438a58);

// FUN_00438AC8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438ac8);
// FUN_00438E60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438e60);
/* measured: removing this pragma takes func_00438fa0 nd 0 -> nd 6: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10; baseline -O2 leaves it nop. */
#pragma schedule on
// FUN_00438FA0
void func_00438fa0(void) {
    func_00438e60();
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off


/* measured: the retail listing settles the proposed nonconstant-stride lever.
   funcs 00438fc0, 00439008, 004390c8, and 00439110 each materialize literal
   0x184 with `addiu $v1,$zero,0x184` before a real three-operand `mult`; no
   0x184 is loaded from memory or passed in. b210 strength-reduces the C
   constant, so this is the documented R5900-mult floor. The first two best
   probes are nd 68 -> 56 (obj 76/72); the latter two were archived above the
   nd 25 threshold. */
// FUN_00438FC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00438fc0);
/* measured: twin of func_00438fc0 (same R5900-mult floor, calls func_0043a500).
   schedule on fills the jr $ra delay slot (nd 68 -> 56, obj 76/72).
   Archived in build/W8Code1_0043_high_nd_park_archive.txt; source is
   intentionally bare because nd 56 exceeds the nd 25 park threshold. */
// FUN_00439008
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439008);

// FUN_00439050
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439050);


/* measured: floor. Retail keeps the R5900 3-op mult (addiu $v1,$zero,0x184;
   mult $a0,$a0,$v1) for arg0*0x184; b210 strength-reduces it. Best probe nd 76;
   the archived body measured nd 84, object 96/72, and is not retained because
   it exceeds the nd 25 park threshold. */
// FUN_004390C8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004390c8);

// FUN_00439110
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439110);

// FUN_00439158
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439158);
// FUN_004392D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004392d0);
// FUN_004393A0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004393a0);

// FUN_004393F8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004393f8);


// FUN_00439428
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439428);
// FUN_004394B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_004394b8);

// FUN_00439530
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439530);
// FUN_00439558
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439558);
// FUN_00439598
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439598);
// FUN_00439770
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439770);
// FUN_00439880
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439880);
// FUN_00439970
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439970);
// FUN_00439A60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439a60);
// FUN_00439BB0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439bb0);
// FUN_00439CC8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439cc8);
// FUN_00439E90
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439e90);



// FUN_00439EB0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_00439eb0);
// FUN_0043A048
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a048);
// FUN_0043A198
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a198);
// FUN_0043A2D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a2d0);
// FUN_0043A500
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a500);
// FUN_0043A680
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a680);
// FUN_0043A6B8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a6b8);
// FUN_0043A6F0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a6f0);
// FUN_0043A810
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a810);
// FUN_0043A840
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a840);

/* measured: obj 72 of a 72-byte window and the record stride/loop bounds are
   right, but retail lays the two exits out separately -- `jr $ra; move $v0,$v1`
   inline in the middle of the loop for the found case and `jr $ra; addiu
   $v0,-1` after the back-edge -- and reaches the advance block through a
   branch-likely PAIR (`beql` then `bnel`, both carrying the i++ in their delay
   slots). b210 merges the two returns into one shared epilogue and lowers the
   second test as `bne` + `b`. Measured identical at nd 41: do/while, while(1)
   with a trailing `i >= 2` / `i > 1` return, an explicit goto-loop, nested-if
   instead of &&, `e[0]` instead of `e[0] != 0`, and declaring the pointer
   before the counter. The top-tested for/while forms are worse (nd 54, obj 76
   overflows the window). Return-duplication/branch-likely-pair floor at nd 41;
   archived in
   build/W8Code1_0043_high_nd_park_archive.txt; source is intentionally bare
   because nd 41 exceeds the nd 25 park threshold. */
// FUN_0043A8A8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a8a8);

// FUN_0043A8F0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a8f0);
// FUN_0043A920
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a920);

/* measured: retail hoists the D_0070FC40 address once into $v1 and reuses the
   %lo displacement for both the flag load and the clear store; b210
   materialises the address twice. Those two extra words, plus b210 filling a
   branch-likely delay slot with the D_008BE280 lui where retail fills the
   bnez slot with the $ra save, plus scheduling the flag clear into the bltz
   delay slot where retail clears it before the load, leave the residual.
   Probed the < 0 and >= 0 orientations, a pointer local for the flag (worse),
   schedule on and off, O3, opt_common_subs on, and opt_rebuildconditionals off.
   The equal-zero-plus-goto shape was best at nd 29; archived in
   build/W8Code1_0043_high_nd_park_archive.txt; source intentionally bare
   because nd 29 exceeds the nd 25 park threshold. */

// FUN_0043A978
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043a978);
// FUN_0043AC18
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac18);

// FUN_0043AC60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ac60);

// FUN_0043ACC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043acc0);


/* measured: func_0043bc70 is not a 0x184 wrapper. Retail loads the
   multiplicand from D_0070FC64, materializes literal 0xC in $a2, then emits
   `mult $0,$a1,$a2`; the multiplier is still compile-time constant, so the
   same strength-reduction claim is inapplicable. */

// FUN_0043AD30
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ad30);

// FUN_0043AE60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ae60);

// FUN_0043AF20
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043af20);

// FUN_0043B090
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b090);

// FUN_0043B188
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b188);

// FUN_0043B238
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b238);

// FUN_0043B2E8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b2e8);

// FUN_0043B398
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b398);

// FUN_0043B458
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b458);

// FUN_0043B5E8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b5e8);

// FUN_0043B718
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b718);

// FUN_0043B8C8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043b8c8);

// FUN_0043BA20
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ba20);

// FUN_0043BB48
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bb48);

// FUN_0043BB70
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bb70);
// FUN_0043BC70
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bc70);

// FUN_0043BCB8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bcb8);
// FUN_0043BEC8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043bec8);
// FUN_0043C008
/* measured: schedule on preserves the matched 8-byte zero-return helper. */
#pragma schedule on
s32 func_0043c008(void) {
    return 0;
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
// FUN_0043C010
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c010);
// FUN_0043C098
/* measured: schedule on preserves the matched 8-byte zero-return helper. */
#pragma schedule on
s32 func_0043c098(void) {
    return 0;
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
/* measured: removing this pragma takes func_0043c0a0 nd 0 -> nd 18: retail fills
   the jr $ra delay slot with addiu $sp, $sp, 0x10 and materializes the return
   zero between ld $ra and the jump; baseline -O2 emits ld; move; addiu; jr; nop. */
#pragma schedule on
// FUN_0043C0A0
s32 func_0043c0a0(void) {
    func_00431408();
    return 0;
}
/* measured: closes the bracket noted above func_0043c0a0's opening pragma
   (removing it takes that function nd 0 -> nd 18). */
#pragma schedule off
// FUN_0043C0C0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c0c0);

// FUN_0043C180
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c180);

// FUN_0043C230
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c230);

// FUN_0043C308
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c308);

// FUN_0043C3B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c3b0);

// FUN_0043C470
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c470);

// FUN_0043C518
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c518);

// FUN_0043C5E8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c5e8);

/* measured: direct cast is byte-exact except return conversion and epilogue scheduling; Committed at nd 8 in-file (nd 2 measured in isolation). */
// FUN_0043C6B0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0043c6b0(s32 arg0) {
    return (s32)func_00444210(arg0, 0, 0xA);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c6b0);
#endif




/* measured: O3 is the best tested body for this byte loop (object 52/56,
   normalized_diff 9). Retail allocates the -1 sentinel in $t7 and puts the
   pointer increment in the branch-delay slot; plain C keeps the sentinel in
   $v1 and emits the increment before the branch. Postincrement, for-loop,
   O2, live third-argument, pointer-alias, and hoisted-zero probes were ruled
   out. Committed at nd 9. */

// FUN_0043C6D8 NONMATCHING
#ifdef NON_MATCHING
/* measured: optimization level 3 body */
#pragma optimization_level 3
void func_0043c6d8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 sentinel;
    arg1 -= 1;
    sentinel = -1;
    if (arg1 != sentinel) {
        do {
            *arg0 = 0;
            arg1 -= 1;
            arg0 += 1;
        } while (arg1 != sentinel);
    }
}
/* measured: closes the optimization-level 3 scope at the file baseline. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c6d8);
#endif



/* measured: raw field stores reproduce the exact 96-byte object except b210 uses $v1/$a1 for the two function/data addresses and leaves the final self-pointer store in the body instead of the jr $ra delay slot. In-function schedule off improves the baseline to normalized_diff 24 (object 92/96); address-local and struct-pointer spellings do not improve it. Committed at nd 24. */



// FUN_0043C710
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c710);
// FUN_0043C738
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c738);
// FUN_0043C7F0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c7f0);
// FUN_0043C840
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043c840);
// FUN_0043CA70
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ca70);
// FUN_0043DC60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dc60);
// FUN_0043DCE8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dce8);
/* measured: raw field stores reproduce the exact 96-byte object except b210 uses $v1/$a1 for the two function/data addresses and leaves the final self-pointer store in the body instead of the jr $ra delay slot. In-function schedule off improves the baseline to normalized_diff 24 (object 92/96); address-local and struct-pointer spellings do not improve it. Committed at nd 24. */
// FUN_0043DDF8 NONMATCHING
#ifdef NON_MATCHING
void func_0043ddf8(u8 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    extern void func_00442220();
    extern void func_00442300();
    extern u8 D_00442280[];
    extern u8 D_00442368[];
    typedef void (*Ddf8Func)(void);
    typedef struct {
        s32 f0; s32 f4; s32 f8; s16 fC; s16 fE;
        s32 f10; s32 f14; s32 f18; u8 *f1C;
        Ddf8Func f20; u8 *f24; Ddf8Func f28; u8 *f2C;
        s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44;
        s32 f48; s32 f4C; s32 f50; s32 f54;
    } Ddf8;
    Ddf8 *p;
    /* measured: schedule off gives the nearest tested 92-byte object. */
    #pragma schedule off
    p = (Ddf8 *)arg0;
    p->f54 = arg3;
    p->fC = arg1;
    p->fE = arg2;
    p->f20 = (Ddf8Func)func_00442220;
    p->f24 = D_00442280;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f28 = (Ddf8Func)func_00442300;
    p->f2C = D_00442368;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = arg0;
    /* measured: closes the schedule-off scope at the file baseline. */
    #pragma schedule on
  }
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ddf8);
#endif

// FUN_0043DE58
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043de58);


// FUN_0043DEC8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dec8);

/* measured: pointer-loaded absolute D_00710070 plus schedule-on gives the exact
   32-byte object at nd 13 (bare baseline was nd 7 with object 16/32). The
   remaining fndiff rows are off 4 (candidate lui $v0 vs retail lui $t7), off
   16 (candidate lw $a0 vs retail ld $ra), off 20 (candidate ld $ra vs retail
   j func_0043DFA0), off 24 (candidate jr vs retail addiu $sp,0x10), and off
   28 (candidate addiu $sp,0x10 vs retail nop). Direct array-address,
   scalar-GP, pointer-cast, void-return, and schedule-off spellings were
   ruled out; the scheduled pointer load is the best tested body.
   Committed at nd 13. */

// FUN_0043DFC0 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule-on indexed pointer-load body is load-bearing for this parked nd 13 body. */
#pragma schedule on
void func_0043dfc0(void) {
    func_0043DFA0(D_00710070[0x1C]);
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfc0);
#endif


// FUN_0043DFE0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043dfe0);

// FUN_0043E060
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e060);
// FUN_0043E170
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e170);
// FUN_0043E450
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e450);
// FUN_0043E5B0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e5b0);

// FUN_0043E608
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e608);

// FUN_0043E9D0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043e9d0);

// FUN_0043EA60
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ea60);

/* measured: schedule on orders the global-address addiu into the jr delay slot. */
#pragma schedule on
// FUN_0043EAE8
s32 *func_0043eae8(s32 *arg0) {
    return D_00754EF0;
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off

// FUN_0043EAF8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eaf8);

/* measured: schedule-on call wrapper is object 32/32 at normalized_diff 13.
   Retail uses an absolute D_00710070 load in $t7 followed by a framed tail jump;
   b210 emits the equivalent jal/epilogue with a $v0 absolute load. Direct
   tail-return without schedule was nd 25, object 40/32. Committed at nd 13. */

// FUN_0043EB20 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule-on tail-call body is load-bearing for this parked nd 13 body. */
#pragma schedule on
s32 *func_0043eb20(void) {
    return func_0043eae8(D_00710070[0]);
}
/* measured: closes the schedule-on scope at the file baseline. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb20);
#endif

// FUN_0043EB40
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb40);
// FUN_0043EB98
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043eb98);
// FUN_0043ECE8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ece8);
// FUN_0043ED08
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ed08);
// FUN_0043ED28
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ed28);
// FUN_0043EF80
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ef80);
// FUN_0043F668
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043f668);
// FUN_0043F698
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043f698);
// FUN_0043F778
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043f778);
// FUN_0043F810
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043f810);
// FUN_0043F8C0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043f8c0);
// FUN_0043F9C8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043f9c8);
// FUN_0043FA88
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fa88);
// FUN_0043FAE0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fae0);
// FUN_0043FB38
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fb38);
/* measured: pointer-slot reconstruction is semantically exact; b210 keeps
   the same 44-byte object but assigns temporaries to v-registers
   instead of retail's t-registers. Object 44/48, normalized_diff 14. */
// FUN_0043FBE0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fbe0);
// FUN_0043FC10
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fc10);
// FUN_0043FD18
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fd18);
// FUN_0043FE48
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fe48);
// FUN_0043FEC8
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043fec8);
// FUN_0043FF88
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ff88);
// FUN_0043FFC0
INCLUDE_ASM("asm/nonmatchings/code1_0043", func_0043ffc0);