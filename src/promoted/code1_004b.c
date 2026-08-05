#include "include_asm.h"
#include "type.h"
extern s32 iGpffffbb9c;
extern void func_00484bb0();
extern void func_00485b20();
extern void func_00485fe0();
extern void func_00485630();
extern void func_00485c80();
extern void func_00486400();
extern void func_00486060();
extern void func_004860f0();
extern void func_00486180();


extern void func_004b0ce0();


// FUN_004B0F70
void func_004b0f70(void *object) {
    func_004b0ce0(object, 0);
}


extern void func_004b0ce0();


// FUN_004B0FA0
void func_004b0fa0(void *object) {
    func_004b0ce0(object, 1);
}


extern void func_004865c0();


// FUN_004B0FD0
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b0fd0);

// FUN_004B1030
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b1030);

// FUN_004B10F0
void func_004b10f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x4) = arg1;
}

// FUN_004B1130
void func_004b1130(void)
{
    func_00484bb0();
}

// FUN_004B1150
void func_004b1150(void)
{
    func_00485b20();
}

// FUN_004B1170
void func_004b1170(void)
{
    func_00485fe0();
}

// FUN_004B1190
void func_004b1190(void)
{
    func_00485630();
}

// FUN_004B11B0
void func_004b11b0(void)
{
    func_00485c80();
}

// FUN_004B1290
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b1290);

// FUN_004B13D0
void func_004b13d0(void)
{
    func_00486400();
}

// FUN_004B13F0
void func_004b13f0(void *object, s32 *arg1) {
    func_004865c0(object, *arg1);
}


extern u32 func_00486700(void *object);


// FUN_004B1420
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b1420);

// FUN_004B1470
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b1470);

// FUN_004B14F0
void func_004b14f0(void *object, s32 *arg1) {
    *arg1 = func_00486700(object);
}


typedef signed __int128 s128;


// FUN_004B1520
void func_004b1520(void)
{
    func_00486060();
}

// FUN_004B1540
void func_004b1540(void)
{
    func_004860f0();
}

// FUN_004B1560
void func_004b1560(void)
{
    func_00486180();
}

// FUN_004B1600
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b1600);

// FUN_004B18E0
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b18e0);

// FUN_004B1AA0
void func_004b1aa0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x8) = 0;
}

// FUN_004B3250
void func_004b3250(s32 arg0)
{
    iGpffffbb9c = arg0;
}

// FUN_004B4EA0
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b4ea0);

// FUN_004B4F40
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b4f40);

// FUN_004B4F90
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b4f90);

// FUN_004B4FF0
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b4ff0);

// FUN_004B50D0
s128 func_004b50d0(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


typedef signed __int128 s128;


// FUN_004B50E0
void func_004b50e0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x10) = arg1;
}

// FUN_004B5340
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b5340);

// FUN_004B5530
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b5530);

// FUN_004B55A0
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b55a0);

// FUN_004B5620
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004b5620);

// FUN_004B5750
s128 func_004b5750(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


typedef signed __int128 s128;


// FUN_004B5760
s128 func_004b5760(u8 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *(s128 *)(arg0 + 0x10) = temp;
    return temp;
}


extern u8 *func_004b6030();
extern u8 *func_004b6900();
extern void func_004b6bb0();
extern void func_004b6da0();


// FUN_004B5770
void func_004b5770(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004B57A0
u8 *func_004b57a0(void *object, s32 arg1) {
    u8 *temp_2;
    u8 *temp_2_2;

    temp_2_2 = func_004b6030(object);
    *(s32 *)(temp_2_2 + 0x20) = arg1;
    temp_2 = func_004b6900(temp_2_2);
    func_004b6da0(temp_2);
    func_004b6bb0(temp_2);
    return temp_2;
}


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the load (nd 8 -> 0). */

// FUN_004BD6B8
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd6b8);

// FUN_004BD750
#pragma schedule on
s32 func_004bd750(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}
#pragma schedule off
