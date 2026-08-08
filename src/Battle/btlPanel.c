#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
typedef struct BtlPanel BtlPanel;
struct BtlPanel
{
    u8* records;    // 0x00
    u8 pad4[0x30];
    s32 field34;    // 0x34
    u8 pad38[4];
    s16 state;      // 0x3C
    s16 index;      // 0x3E
};

void func_00440b68();
extern u8* func_00454a60(u8* param, s32 mode);
void func_00454bd0(u8* ptr);
s32 func_004553c0(u8* ptr);
s32 func_00106330(s32 id);
s32 func_0019ef90(s32 a, s32 b);
s32 func_0046b000(u32 param);
s32 func_0046a750(s32 param);
s32 func_0046a770(u32 param);
extern u8* func_00452560(s32 param);
extern char iGpffffa578;
extern s32 iGpffffa570;
extern char D_00626780[];
extern u8 D_00626790[];
extern u8 D_006267B0[];
extern u32 D_00626720[];
extern u8* func_00194470(u32 type, u32 workSize);
void func_0043f9c8(void* dst, s32 value, u32 size);
void func_00456150(u8* ptr);
s32 func_00481360(s32 param);
extern s32 iGpffffb470;
extern u8 D_006267D0[];



// Archived C body: build/WBHygiene_func_00202890_archive.txt; no current park body remains.
// FUN_00202890
INCLUDE_ASM("asm/nonmatchings/btlPanel", func_00202890);



// FUN_00202B60
s32 func_00202890(void* panel);

u8* func_00202b60(s32 param)
{
    u8* p = func_00194470(0x508, 0x40);
    u8* rec;

    p[0x47] &= 0xFE;
    *(u32*)(p + 0x6C) = (u32)func_00202890;
    rec = *(u8**)(p + 0x78);
    func_0043f9c8(rec, 0, 0x40);
    *(s32*)(rec + 0x34) = param;
    return p;
}



// FUN_00202BE0
void func_00202be0(void)
{
    u8* t;

    func_00440b68(&iGpffffa578, D_00626780, 0x5FB);
    t = func_00454a60(D_006267D0, 0);
    func_00456150(t);
    iGpffffb470 = func_00481360(*(s32*)(t + 0x110));
    func_00454bd0(t);
}
