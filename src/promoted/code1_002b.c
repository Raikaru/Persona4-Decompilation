#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void func_002bb9e0(u8 *arg0, s32 arg1);

extern s32 func_002bc0e0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_002bcc60(u8 *arg0);
extern u8 *D_0072466C;

extern s32 clndGetMoonPhase(void);

extern u32 func_00106a90(s16 arg0);
extern u8 *D_00882F40[];
extern void func_00278450(s32 arg0);
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern s8 D_007488F8[];
extern s8 iGpffffb578;
extern s32 *func_002bbf70(void);
extern s32 func_002bb0e0(void);
extern void func_002791f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_00279350(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);



// FUN_002B2940
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2940);
// FUN_002B2950
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2950);
// FUN_002B2960
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2960);
// FUN_002B2970
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2970);
// FUN_002B29A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b29a0);
// FUN_002B29E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b29e0);
// FUN_002B2A30
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2a30);
// FUN_002B2A60
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2a60);
// FUN_002B2AA0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2aa0);
// FUN_002B2BD0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2bd0);
// FUN_002B2CB0
s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 + arg1;
    }
    {
        s32 var = arg0 + arg1;
        s32 bound;
        if (arg2 < var) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D00
s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 - arg1;
    }
    {
        s32 var = arg0 - arg1;
        s32 bound;
        if (var < arg2) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D50
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2d50);
// FUN_002B2E70
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2e70);
// FUN_002B2F90
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2f90);
// FUN_002B3050
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3050);
// FUN_002B3110
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3110);
// FUN_002B3140
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3140);
// FUN_002B3170
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3170);
// FUN_002B31A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b31a0);
// FUN_002B3230
s32 func_002b3230(s16 *arg0, s16 *arg1) {
    s16 b;
    u32 x;
    u32 y;

    b = *arg1;
    x = func_00106a90(*arg0);
    y = func_00106a90(b);
    if (x < y) {
        return 1;
    }
    return -(s32)(y < x);
}

// FUN_002B32A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b32a0);
// FUN_002B32D0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b32d0);
// FUN_002B3520
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3520);
// FUN_002B3720
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3720);
// FUN_002B3960
void func_002b3960(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B5100
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b5100);
// FUN_002B5120
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b5120);
// FUN_002B52A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b52a0);
// FUN_002B5C60
void func_002b5c60(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002BA080
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba080);
// FUN_002BA5D0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba5d0);
// FUN_002BA970
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba970);
// FUN_002BAA20
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002baa20);
// FUN_002BAA50
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002baa50);
// FUN_002BAB80
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bab80);
// FUN_002BACB0
s8 func_002bacb0(void) {
    s32 i = 0;
    u8 **t = D_00882F40;

    while (i < 5) {
        if (t[i] == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002BAD10
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bad10);
// FUN_002BADC0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002badc0);
// FUN_002BAE80
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bae80);
// FUN_002BAF40
s32 func_002baf40(s32 arg0) {
    s32 *p;

    p = func_002bbf70();
    if (p == NULL) {
        return 0;
    }
    if (*p < 0) {
        return 0;
    }
    p[2] = arg0;
    *((s8 *)p + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}

// FUN_002BAFC0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bafc0);
// FUN_002BB180
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb180);
// FUN_002BB420
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb420);
// FUN_002BB4E0
s32 func_002bb4e0(void) {
    s32 *temp_2;
    s32 temp_4;

    temp_2 = (s32 *)(func_002bbf70());
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = (s32)(*(s32 *)((u8 *)(temp_2) + 0));
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)((u8 *)(temp_2) + 0) = -1;
        *(s8 *)((u8 *)(temp_2) + 4) = 0;
        *(s8 *)((u8 *)(temp_2) + 5) = 0;
    }
    func_002e0dd0();
    return 1;
}

// FUN_002BB550
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb550);
// FUN_002BB680
s32 func_002bb680(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return 0;
    }
    if (*(s32 *)p < 0) {
        return 0;
    }
    if (*(s8 *)(p + 5) != 0) {
        if (*(s8 *)(p + 4) == 2) {
            return 0;
        }
    }
    return *(s8 *)(p + 4);
}

// FUN_002BB7C0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb7c0);
// FUN_002BB9E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bb9e0);
// FUN_002BBCC0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bbcc0);
// FUN_002BBCF0
void func_002bbcf0(u8 *arg0) {
    func_002bb9e0(arg0, 1);
}



// FUN_002BBD80
void func_002bbd80(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p != NULL) {
        func_00278450(*(s32 *)p);
    }
}

// FUN_002BC0B0
void func_002bc0b0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    func_002bc0e0(arg0, arg1, arg2, 1, arg3, arg4);
}



// FUN_002BC0E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc0e0);
// FUN_002BC4B0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc4b0);
// FUN_002BC7A0
void func_002bc7a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_002791f0(arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0);
}

// FUN_002BC7F0
void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_00279350(arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0, &D_00793E80[arg5 * 0x30]);
}

// FUN_002BC860
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc860);
// FUN_002BC890
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc890);
// FUN_002BC9E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc9e0);
// FUN_002BCBC0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bcbc0);
// FUN_002BD280
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd280);
// FUN_002BD3E0
void func_002bd3e0(void) {
    func_002bcc60(D_0072466C);
}



// FUN_002BD410
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd410);
// FUN_002BD7B0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd7b0);
// FUN_002BD840
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd840);
// FUN_002BD8E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bd8e0);
// FUN_002BDB10
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bdb10);
// FUN_002BDFF0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bdff0);
// FUN_002BE100
s32 func_002be100(s32 arg0) {
    s32 i = 0;
    s32 key = arg0 & 0xFF;
    s8 *t = D_007488F8;

    while ((i & 0xFF) < 0xC) {
        if (key == t[i & 0xFF]) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
    return 0;
}

// FUN_002BE160
s32 func_002be160(u8 *arg0, s32 arg1) {
    s32 n = arg1 & 0xFFFF;
    if (n == 0) {
        return 1;
    }
    return (clndGetMoonPhase() & 0xFF) >= n;
}

// FUN_002BE1B0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002be1b0);
// FUN_002BE1E0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002be1e0);
// FUN_002BE3C0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002be3c0);
// FUN_002BE4A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002be4a0);