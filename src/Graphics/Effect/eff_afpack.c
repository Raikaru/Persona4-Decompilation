/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "include_asm.h"

typedef struct RuntimeWork RuntimeWork;

typedef struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    u8 reserved[8];
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
} RuntimeListNode;

extern void* D_00764C98;
extern s32 D_00922DB0[];
extern s32 D_00922DB4[];
extern void func_00460ac0(void* arg0, s32* arg1);
extern void* D_00764C9C;
extern RuntimeListNode* D_00764CA0;
extern void func_004baea0(void* arg0, void* arg1);
extern void func_004baed0(void* arg0, void* arg1);
extern void func_00440b68(const void* msg, const void* file, s32 line);
extern u8* func_00454a60(u8* param, s32 mode);
extern void func_00456150(void* handle);
extern s32 func_003ef740(u8* param, s32 mode);
extern void func_00454bd0(u8* ptr);
extern s32 func_00451de0(void* data, s32 a, s32 b, s32 c, void* init, void* close, void* buf);
extern void func_0043f9c8(void* dst, s32 value, u32 size);
extern u8 D_00764210;
extern s32 D_00764CA4;
extern s32 D_00764CA8;
extern u8 D_007146B0[];
extern u8 D_007146C0[];
extern u8 D_007146D0[];
extern void* D_00922DB8[];
extern s32 D_00922DC0[];
extern void func_004b6e80(void);
extern s32 func_004b6e40(void);
extern void func_0046d730(const void* file, s32 line);
extern void func_003e9390(void* frame);
extern void func_003c02e0(void* arg);
extern void func_003c4220(void* arg);
extern void func_004b8f10(void* arg0);
extern void (*jtbl_008873EC[])(void* ptr);
extern void func_0044ea90(const void* file, s32 line);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void func_004b8df0(void* arg0, void* arg1);
extern s32 func_003c4140(void);
extern void func_003c42b0(void* a, void* b);
extern u8* func_004b8350(void* a, void* b, void* c);
extern s32 func_003c00e0(void);
extern void func_003c0210(void* a, void* b, s32 c);
extern s32 func_003e9320(void);
extern void func_003c1b90(void* a, void* b);
extern void func_003c2a80(void* a);
extern void func_004bccf0(void* a, void* b);
extern void func_003c22f0(void* a);

// FUN_004B6030
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6030);

/* measured: nd 501 with a full C body (object 684B against a 688B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_004B6900
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6900);

// FUN_004B6BB0
void func_004b6bb0(RuntimeListNode* node)
{
    s32 i;
    s32 sp3C;
    s32 off;
    u8* work;
    u8* out;

    i = 0;
    while (i < *(s16*)((u8*)node->work + 4))
    {
        work = (u8*)node->work;
        out = *(u8**)((u8*)node + 0x10) + i * 0x20;
        *(s32*)(out + 8) = *(s32*)(*(s32**)(work + 0x1C) + i);
        off = i * 0x3C;
        *(s32*)(out + 0x10) = (s32)((u8*)node->vertices + off);
        func_004baea0(out, work);
        i++;
    }
    node->flags |= 1;
    i = 0;
    while (i < *(s16*)((u8*)node->work + 4))
    {
        func_004baed0(*(u8**)((u8*)node + 0x10) + i * 0x20, &sp3C);
        i++;
    }
}

// FUN_004B6C90
void func_004b6c90(s32 arg0, s32 arg1)
{
    s32 temp_2;

    func_00440b68(&D_00764210, D_007146B0, 0x2DA);
    temp_2 = (s32)func_00454a60(D_007146C0, 0);
    func_00456150((void*)temp_2);
    D_00764CA8 = (s32)func_003ef740(D_007146C0, 0);
    func_00454bd0((u8*)temp_2);
    D_00764CA0 = NULL;
    D_00764C9C = NULL;
    D_00764CA4 = func_00451de0(D_007146D0, arg1, 0, 0, (void*)func_004b6e40, NULL, NULL);
    func_0043f9c8(D_00922DB0, 0, 0x30);
    D_00922DB8[0] = (void*)func_004b6e80;
    D_00922DC0[0] = 0;
    D_00764C98 = (void*)arg0;
}

// FUN_004B6DE0
s32 func_004b6de0(RuntimeListNode* node)
{
    RuntimeListNode* current;

    current = D_00764CA0;
    while (current != NULL)
    {
        if (current == node)
        {
            break;
        }
        current = *(RuntimeListNode**)((u8*)current + 0x1c);
    }
    if (current == NULL)
    {
        return 0;
    }
    return !(node->flags & 8);
}

// FUN_004B6DA0
void func_004b6da0(void* node)
{
    if (D_00764C9C == NULL)
    {
        *(void**)((u8*)node + 0x18) = NULL;
        *(void**)((u8*)node + 0x1c) = NULL;
        D_00764CA0 = (RuntimeListNode*)node;
        D_00764C9C = node;
        return;
    }
    else
    {
        *(void**)((u8*)node + 0x18) = D_00764C9C;
        *(void**)((u8*)node + 0x1c) = NULL;
        *(void**)((u8*)D_00764C9C + 0x1c) = node;
    }
    D_00764C9C = node;
}
// FUN_004B6E40
s32 func_004b6e40(void)
{
    D_00922DB0[0] = 0;
    D_00922DB4[0] = 0;
    func_00460ac0(D_00764C98, D_00922DB0);
    return 0;
}

// FUN_004B6E80
void func_004b6e80(void) {
    typedef int (*code)(...);
    extern code DAT_008873ec_abs[];
    void *(**table);
    extern void func_004b5950(void *arg0);
    extern void func_004b5c60(void *arg0);
    extern s32 func_004bce30(void *arg0);
    s32 flags;
    u8 *first;
    u8 *prev;
    u8 *next;
    s32 off;
    u8 *temp;
    s32 bits;
    u8 *work;
    s32 i;
    u8 *node;

    first = (u8 *)D_00764CA0;
    if (first != NULL) {
        while (first != NULL) {
            flags = *(s32 *)(first + 0);
            if (flags & 8) {
                func_004b5950(first);
            } else if (flags & 2) {
                func_004b5950(first);
                *(s32 *)(first + 0) = *(s32 *)(first + 0) & ~2;
            }
            first = *(u8 **)(first + 0x1C);
        }
        node = (u8 *)D_00764CA0;
        while (node != NULL) {
            temp = node;
            node = *(u8 **)(node + 0x1C);
            bits = 0;
            i = 0;
            while (i < *(s16 *)(*(u8 **)(temp + 4) + 4)) {
                bits |= func_004bce30(*(u8 **)(temp + 0x10) + (i << 5));
                i++;
            }
            if (bits == 0) {
                if (D_00764CA0 == NULL) {
                    func_0046d730(D_007146B0, 0x326);
                }
                if (D_00764C9C == NULL) {
                    func_0046d730(D_007146B0, 0x327);
                }
                next = *(u8 **)(temp + 0x1C);
                if (next != NULL) {
                    *(u8 **)(next + 0x18) = *(u8 **)(temp + 0x18);
                }
                prev = *(u8 **)(temp + 0x18);
                if (prev != NULL) {
                    *(u8 **)(prev + 0x1C) = *(u8 **)(temp + 0x1C);
                }
                if (temp == (u8 *)D_00764C9C) {
                    D_00764C9C = *(u8 **)(temp + 0x18);
                }
                if (temp == (u8 *)D_00764CA0) {
                    D_00764CA0 = (RuntimeListNode *)*(u8 **)(temp + 0x1C);
                }
                work = *(u8 **)(temp + 4);
                i = 0;
                while (i < *(s16 *)(*(u8 **)(temp + 4) + 4)) {
                    func_004b8f10(*(u8 **)(temp + 8) + i * 0x3C);
                    off = i * 8;
                    func_003e9390(*(u8 **)(*(u8 **)(*(u8 **)(temp + 0xC) + off) + 4));
                    func_003c02e0(*(u8 **)(*(u8 **)(temp + 0xC) + off));
                    func_003c4220(*(u8 **)(*(u8 **)(temp + 0xC) + off + 4));
                    i++;
                }
                table = (void *(**) )DAT_008873ec_abs;
                ((code)table[0])(temp);
                ((code)table[0])(work);
            }
        }
        first = (u8 *)D_00764CA0;
        while (first != NULL) {
            flags = *(s32 *)(first + 0);
            if (flags & 8) {
                func_004b5c60(first);
            } else if (flags & 4) {
                func_004b5c60(first);
                *(s32 *)(first + 0) = *(s32 *)(first + 0) & ~4;
            }
            first = *(u8 **)(first + 0x1C);
        }
    }
}

// FUN_004B7140
void func_004b7140(s32 arg0)
{
    s32 temp_16;
    u8* var_19;
    u8* temp_18;
    u8* temp_21;
    u8* temp_3;
    u8* temp_3_2;
    s32 var_17;
    u32 base;

    var_19 = (u8*)D_00764CA0;
    while (var_19 != NULL)
    {
        temp_18 = var_19;
        var_19 = *(u8**)(var_19 + 0x1C);
        if (*(s32*)(*(u8**)(temp_18 + 4) + 0x20) == arg0)
        {
            if (D_00764CA0 == NULL)
            {
                func_0046d730(D_007146B0, 0x326);
            }
            if (D_00764C9C == NULL)
            {
                func_0046d730(D_007146B0, 0x327);
            }
            temp_3 = *(u8**)(temp_18 + 0x1C);
            if (temp_3 != NULL)
            {
                *(u8**)(temp_3 + 0x18) = *(u8**)(temp_18 + 0x18);
            }
            temp_3_2 = *(u8**)(temp_18 + 0x18);
            if (temp_3_2 != NULL)
            {
                *(u8**)(temp_3_2 + 0x1C) = *(u8**)(temp_18 + 0x1C);
            }
            if (temp_18 == (u8*)D_00764C9C)
            {
                D_00764C9C = *(void**)(temp_18 + 0x18);
            }
            if (temp_18 == (u8*)D_00764CA0)
            {
                D_00764CA0 = *(RuntimeListNode**)(temp_18 + 0x1C);
            }
            temp_21 = *(u8**)(temp_18 + 4);
            var_17 = 0;
            while (var_17 < *(s16*)(*(u8**)(temp_18 + 4) + 4))
            {
                func_004b8f10(*(u8**)(temp_18 + 8) + var_17 * 0x3C);
                temp_16 = var_17 * 8;
                func_003e9390(*(void**)(*(u8**)(*(u8**)(temp_18 + 0xC) + temp_16) + 4));
                func_003c02e0(*(u8**)(*(u8**)(temp_18 + 0xC) + temp_16));
                func_003c4220(*(void**)(*(u8**)(temp_18 + 0xC) + temp_16 + 4));
                var_17++;
            }
            base = (u32)jtbl_008873EC;
            ((void (*)(void*))*(u32*)base)(temp_18);
            ((void (*)(void*))*(u32*)base)(temp_21);
        }
    }
}

