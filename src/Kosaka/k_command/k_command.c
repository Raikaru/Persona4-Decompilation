/* Source unit: src/Kosaka/k_command/k_command_00176c20.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

extern char* strcpy(char* destination, const char* source);
extern s32 sprintf(char* destination, const char* format, ...);
extern char* strcat(char* destination, const char* source);
#include "type.h"
#include "include_asm.h"

extern s32 func_0029cc00(s32 arg0);
extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern f32 func_0029cd50(s32 arg0);
extern f32 D_00764B5C;

extern u8 D_00724B3C;
extern u8 D_00724B40;
extern u8 D_00724B44;
extern u8 D_00724B48;
extern char D_005F1858[];
extern s64 D_005F1868[];
extern f32 D_005F1870[];
extern s32 D_007EFA00[];
extern u8 D_007EF9B0[];
extern s32 D_00764364;
extern u8* D_00762EA0;

extern void func_0046d730(const char* file, s32 line);
extern s32 func_00457120(void);
extern void* func_00174c00(void);
extern void* func_00174c10(void);
extern u8* func_00145270(u16 arg0);
extern u8* func_001452b0(s32 arg0);
extern u16 func_00145780(s32 arg0, u16 arg1, s32 arg2);
extern void func_0016f130(s32 a, s32 b, s32 c);
extern void func_0016f3b0(s32 a, s32 b, s32 c);
extern s32 func_004782b0(void* arg0);
extern void* func_00478750(s32 arg0);
extern void func_004787e0(u32 arg0);
extern void func_00478e70(s32 arg0);
extern void func_00479940(s32 a, s32 b, s16 c, u16 d, s32 e);
extern void func_00479e60(s32 a, s32 b, f32 c);
extern void func_0047a1c0(s32 a, void* b, s32 c);
extern f32 func_0047a080(s32 arg0, s32 arg1);
extern void func_0047a0e0(s32 arg0, s32 arg1, f32 arg2);
extern void* func_0047a2f0(u32 arg0);
extern void func_0047a1a0(s32 arg0, void* arg1, f32 arg2, s32 arg3);
extern void func_0047a180(s32 arg0, u8* arg1, s32 arg2);
extern void func_0047a1e0(s32 arg0, void* arg1, s32 arg2);
extern f32 func_0014b660(u8* arg0);
extern f32 func_0014b5d0(u8* arg0);
extern f32 func_0014b6f0(u8* arg0);
extern void func_00146e60(s32 arg0, u8* arg1, f32* arg2);
extern s32 func_00151580(s32 a, s32 b, s32* c);
extern s32 func_003e9700(s32 arg0);
extern void func_003e40b0(f32* a, f32* b);
extern void func_003e0380(f32* a);
extern void func_003e03e0(void* a, f32* b);
extern s32 func_003e05d0(void* arg0);
extern s32 func_00168780(s32 arg0, f32 arg1);
extern f32 func_00168770(s32 arg0);
extern void func_00168c00(s32 arg0);
extern void func_0015bae0(void);
extern void func_0016ec90(s32 arg0);
extern void func_0017e9b0(s32 arg0);
extern void func_0017b9a0(s32 arg0, f32 arg1);
extern u8* func_00155280(void);

typedef struct
{
    f32 x, y, z;
} Vec3f;

typedef struct
{
    f32 m[16];
} Mat4;



// FUN_00176C20
u32 func_00176c20()
{
    s32 resourceId;

    resourceId = func_0029cc00(0);
    func_0014a0f0((u16)resourceId, func_0029cc00(1));
    return true;
}





// FUN_00176C70
s32 func_00176c70(void)
{
    s32 v = func_0029cc00(0);
    s32 w = func_0029cc00(1);
    s32 x = func_0029cc00(2);
    s32 iv = (s32)func_0029cd50(3);
    f32 g = func_0029cd50(4);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            if (x != 0)
            {
                func_00479940(*(s32*)(p + 0x164), 0, w, iv, 1);
            }
            else
            {
                func_00479940(*(s32*)(p + 0x164), 0, w, iv, 0);
            }
            func_0047a0e0(*(s32*)(p + 0x164), 0, g);
        }
        break;
    }
    case 3:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            if (x != 0)
            {
                func_00479940(*(s32*)(p + 0x164), 0, w, iv, 1);
            }
            else
            {
                func_00479940(*(s32*)(p + 0x164), 0, w, iv, 0);
            }
            func_0047a0e0(*(s32*)(p + 0x164), 0, g);
        }
        break;
    }
    case 10:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            if (x != 0)
            {
                func_00479940(*(s32*)(p + 0x144), 0, w, iv, 1);
            }
            else
            {
                func_00479940(*(s32*)(p + 0x144), 0, w, iv, 0);
            }
            func_0047a0e0(*(s32*)(p + 0x144), 0, g);
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x1E0);
        break;
    }
    return 1;
}



// FUN_00176EF0
s32 func_00176ef0(void)
{
    s32 v = func_0029cc00(0);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            return *(u8*)(*(s32*)(p + 0x164) + 0xEE) == 1;
        }
        break;
    }
    case 3:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            return *(u8*)(*(s32*)(p + 0x164) + 0xEE) == 1;
        }
        break;
    }
    case 10:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            return *(u8*)(*(s32*)(p + 0x144) + 0xEE) == 1;
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x212);
        break;
    }
    return 1;
}



// FUN_00176FF0
s32 func_00176ff0(void)
{
    s32 v = func_0029cc00(0);
    f32 f = func_0029cd50(1);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_00479e60(*(s32*)(p + 0x164), 0, f);
        }
        break;
    }
    case 3:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_00479e60(*(s32*)(p + 0x164), 0, f);
        }
        break;
    }
    case 10:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_00479e60(*(s32*)(p + 0x144), 0, f);
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x23C);
        break;
    }
    return 1;
}



// FUN_00177120
s32 func_00177120(void)
{
    s32 v = func_0029cc00(0);
    f32 threshold = 0.0f;
    f32 f = func_0029cd50(1);
    s32 k = (v & 0xFFC00) >> 10;
    u8* p;
    s32 result;
    switch (k)
    {
    case 1:
        p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            threshold = func_0047a080(*(s32*)(p + 0x164), 0);
        }
        break;
    case 3:
        if (func_00145270(v & 0xFFFF) != 0)
        {
            threshold = func_0047a080(*(s32*)(p + 0x164), 0);
        }
        break;
    case 10:
        if (func_00145270(v & 0xFFFF) != 0)
        {
            threshold = func_0047a080(*(s32*)(p + 0x164), 0);
        }
        break;
    default:
        func_0046d730(D_005F1858, 0x264);
        break;
    }
    return (f >= threshold) ^ 1;
}



// FUN_00177280
s32 func_00177280(void)
{
    s32 v = func_0029cc00(0);
    f32 pos[3];
    s32 k;
    pos[0] = func_0029cd50(1);
    pos[1] = func_0029cd50(1);
    pos[2] = func_0029cd50(1);
    k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_0047a1e0(*(s32*)(p + 0x164), pos, 2);
        }
        break;
    }
    case 3:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_0047a1e0(*(s32*)(p + 0x164), pos, 2);
        }
        break;
    }
    case 10:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_0047a1e0(*(s32*)(p + 0x144), pos, 2);
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x294);
        break;
    }
    return 1;
}



// FUN_001773D0
s32 func_001773d0(void)
{
    s32 v = func_0029cc00(0);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
        break;
    case 3:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0 && *(s32*)(p + 0x230) != 0)
        {
            f32 f = func_0029cd50(1);
            func_0017b9a0(*(s32*)(p + 0x230), f);
        }
        break;
    }
    case 10:
        break;
    default:
        func_0046d730(D_005F1858, 0x2B2);
        break;
    }
    return 1;
}



// FUN_001774A0
INCLUDE_ASM("asm/nonmatchings/k_command", func_001774a0);

// FUN_00177A10
u32 K_Cmd_CREATE_FLD_MDL()
{
    char path[64];
    char buff[64];
    s32 majorId;
    u32 minorId;
    Model* mdl;

    majorId = func_0029cc00(0);
    minorId = func_0029cc00(1);

    if (majorId > -1)
    {
        strcpy(path, "field/rmd/m");

        sprintf(buff, "%03d_", majorId);
        strcat(path, buff);

        sprintf(buff, "%03d.RMD", minorId);
        strcat(path, buff);
    }
    else
    {
        strcpy(path, "field/grmd/fobj");
        sprintf(buff, "%03d.RMD", minorId);
        strcat(path, buff);
    }

    mdl = func_00477e80(4, minorId, path, 0);
    func_0029cf50((s32)mdl);

    return true;
}





// FUN_00177B30
s32 func_00177b30(void)
{
    s32 v = func_0029cc00(0);
    s32 w = func_0029cc00(1);
    s32 flag = 0;
    s32 created = 0;
    u8* p2 = 0;
    s32 tmp;
    if (func_004782b0((void*)v) == 1)
    {
        u8* p = func_00145270((w & 0x3FF) | 0x2800);
        if (p != 0)
        {
            func_004787e0(v);
            func_0029cf50(0);
            return 1;
        }
        flag = func_00145ac0(w & 0xFFFF, (Model*)v) & 0xFFFF;
        while (*(s32*)(D_00762EA0 + 0x24) > 0)
        {
            p2 = (u8*)func_00151580(*(s32*)(D_00762EA0 + 0x28), w, &tmp);
            break;
        }
        if (p2 != 0)
        {
            f32 vec[3];
            p2 = (u8*)func_003e9700((s32)p2);
            vec[0] = func_0014b660(p2);
            vec[1] = func_0014b5d0(p2);
            vec[2] = func_0014b6f0(p2);
            func_00146e60(flag & 0xFFFF, (u8*)(p2 + 0x30), vec);
            func_0047a1c0(v, p2, 0);
            func_00479940(v, 0, 0, 8, 1);
        }
        if (tmp == 1)
        {
            u8* r = func_00145270(flag & 0xFFFF);
            *(s32*)(r + 0x150) = 1;
        }
        created = 1;
    }
    func_0029cf50(flag);
    return created;
}

// FUN_00177D10
u32 func_00177d10()
{
    Model* model;
    u32 resourceId;
    u32 created;

    model = (Model*)func_0029cc00(0);
    resourceId = 0;
    created = 0;
    if (func_004782b0(model) == true)
    {
        resourceId = (u16)func_00145ac0(func_0014b510(10), model);
        created = 1;
    }
    func_0029cf50(resourceId);

    return created;
}





// FUN_00177DB0
s32 func_00177db0(void)
{
    s32 a = func_0029cc00(0);
    s32 b = func_0029cc00(1);
    u8* p = func_00145270(a);
    if (p != 0)
    {
        *(s32*)(p + 0x150) = b;
    }
    return 1;
}

// FUN_00177E20
u32 K_Cmd_CREATE_MDL()
{
    s32 type;
    s32 id;
    Model* mdl;

    type = func_0029cc00(0);
    id = func_0029cc00(1);

    mdl = func_00478140(type, id, 0);

    func_0029cf50((s32)mdl);

    return true;
}





// FUN_00177E80
s32 func_00177e80(void)
{
    s32 type = func_0029cc00(0);
    s32 id = func_0029cc00(1);
    s32 res = 0;
    s32 created = 0;
    if (func_004782b0((void*)type) == 1)
    {
        u8* p;
        res = func_00145780(func_0014b510(3), id, type);
        p = func_00145270(res);
        *(s32*)(p + 0x22C) = (s32)func_00478750(D_00764364);
        created = 1;
    }
    func_0029cf50(res);
    return created;
}



// FUN_00177F50
s32 func_00177f50(void)
{
    s32 v = func_0029cc00(0);
    f32 f = func_0029cd50(1);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_00168780(*(s32*)(p + 0x220), f);
        }
        break;
    }
    case 3:
    {
        u8* p = func_00145270(v & 0xFFFF);
        if (p != 0)
        {
            func_00168780(*(s32*)(p + 0x228), f);
            if (*(s32*)(p + 0x22C) != 0)
            {
                f32 vec[3];
                vec[2] = f;
                vec[1] = f;
                vec[0] = f;
                func_0047a1e0(*(s32*)(p + 0x22C), vec, 2);
                func_00478e70(*(s32*)(p + 0x22C));
            }
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x404);
        break;
    }
    return 1;
}



// FUN_00178070
s32 func_00178070(void)
{
    s32 a = func_0029cc00(0);
    s32 b = func_0029cc00(1);
    func_0016f130(0, b, a);
    return 1;
}



// FUN_001780D0
s32 func_001780d0(void)
{
    s32 a = func_0029cc00(0);
    s32 b = func_0029cc00(1);
    func_0016f3b0(0, b, a);
    return 1;
}



// FUN_00178130
s32 func_00178130(void)
{
    s32 v = func_0029cc00(0);
    u8* p = func_00174c00();
    Vec3f diff;
    Vec3f v1;
    f32 v2x;
    f32 angle;
    f32 dot;
    if (p != 0)
    {
        v1 = *(Vec3f*)((u8*)func_0047a2f0(*(s32*)(p + 0x144)) + 0x20);
        v2x = ((Vec3f*)((u8*)func_0047a2f0(*(s32*)(p + 0x144)) + 0x30))->x;
        diff.x = v2x - ((Vec3f*)((u8*)func_0047a2f0(D_007EFA00[0]) + 0x30))->x;
        v2x = ((Vec3f*)((u8*)func_0047a2f0(*(s32*)(p + 0x144)) + 0x30))->y;
        diff.y = v2x - ((Vec3f*)((u8*)func_0047a2f0(D_007EFA00[0]) + 0x30))->y;
        v2x = ((Vec3f*)((u8*)func_0047a2f0(*(s32*)(p + 0x144)) + 0x30))->z;
        diff.z = v2x - ((Vec3f*)((u8*)func_0047a2f0(D_007EFA00[0]) + 0x30))->z;
        func_003e40b0(&diff.x, &diff.x);
        func_003e40b0(&v1.x, &v1.x);
        func_0014b5d0((u8*)func_003e9700(*(s32*)((u8*)func_00457120() + 4)));
        dot = diff.x * v1.x + diff.y * v1.y + diff.z * v1.z;
        if (dot < 0.0f)
        {
            v1.x = -v1.x;
            v1.y = -v1.y;
            v1.z = -v1.z;
        }
        if (v1.x > 0.5f)
        {
            angle = 90.0f;
        }
        else if (v1.x < -0.5f)
        {
            angle = 270.0f;
        }
        else if (v1.z > 0.5f)
        {
            angle = 0.0f;
        }
        else if (v1.z < -0.5f)
        {
            angle = 180.0f;
        }
        func_0016f3b0(0, v, (s32)angle);
    }
    return 1;
}



// FUN_00178360
s32 func_00178360(void)
{
    D_00724B3C = func_0029cc00(0);
    D_00724B40 = func_0029cc00(1);
    D_00724B44 = func_0029cc00(2);
    D_00724B48 = 0;
    return 1;
}

// FUN_001783B0
s32 func_001783b0(void)
{
    s32 temp_17;
    s32 temp_16;

    temp_17 = func_0029cc00(0) & 0xFF;
    temp_16 = func_0029cc00(1) & 0xFF;
    func_00457140(temp_17, temp_16, func_0029cc00(2) & 0xFF, 0);
    return 1;
}





// FUN_00178420
s32 func_00178420(void)
{
    f32 value = func_0029cd50(0);
    *(f32*)((u8*)func_00457120() + 0x88) = value;
    func_00457120();
    return 1;
}

// FUN_00178470
s32 func_00178470(void)
{
    D_00764B5C = func_0029cd50(0);
    return 1;
}





// FUN_001784A0
s32 func_001784a0(void)
{
    u16* p = func_00174c00();
    if (p != 0)
    {
        func_0029cf50(*p);
    }
    else
    {
        func_0046d730(D_005F1858, 0x462);
    }
    return 1;
}



// FUN_00178500
s32 func_00178500(void)
{
    u16* p = func_00174c10();
    if (p != 0)
    {
        func_0029cf50(*p);
    }
    else
    {
        func_0046d730(D_005F1858, 0x474);
    }
    return 1;
}

// FUN_00178970
u32 func_00178970()
{
    s32 resourceId;
    s32 value;

    resourceId = func_0029cc00(0);
    value = func_0029cc00(1);

    return func_002bd360(resourceId, value) == 0;
}



// FUN_0025D100
u32 func_0025d100()
{
    func_0029cf50(func_00106600(func_0029cc00(0)));

    return true;
}
