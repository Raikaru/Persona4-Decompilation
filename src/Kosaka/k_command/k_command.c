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



// FUN_00176C20
u32 func_00176c20()
{
    s32 resourceId;

    resourceId = func_0029cc00(0);
    func_0014a0f0((u16)resourceId, func_0029cc00(1));
    return true;
}





// FUN_00176C70
INCLUDE_ASM("asm/nonmatchings/k_command", func_00176c70);



// FUN_00176EF0
INCLUDE_ASM("asm/nonmatchings/k_command", func_00176ef0);



// FUN_00176FF0
INCLUDE_ASM("asm/nonmatchings/k_command", func_00176ff0);



// FUN_00177120
INCLUDE_ASM("asm/nonmatchings/k_command", func_00177120);



// FUN_00177280
INCLUDE_ASM("asm/nonmatchings/k_command", func_00177280);



// FUN_001773D0
INCLUDE_ASM("asm/nonmatchings/k_command", func_001773d0);



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
INCLUDE_ASM("asm/nonmatchings/k_command", func_00177b30);

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
INCLUDE_ASM("asm/nonmatchings/k_command", func_00177db0);

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
INCLUDE_ASM("asm/nonmatchings/k_command", func_00177e80);



// FUN_00177F50
INCLUDE_ASM("asm/nonmatchings/k_command", func_00177f50);



// FUN_00178070
INCLUDE_ASM("asm/nonmatchings/k_command", func_00178070);



// FUN_001780D0
INCLUDE_ASM("asm/nonmatchings/k_command", func_001780d0);



// FUN_00178130
INCLUDE_ASM("asm/nonmatchings/k_command", func_00178130);



// FUN_00178360
INCLUDE_ASM("asm/nonmatchings/k_command", func_00178360);

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
INCLUDE_ASM("asm/nonmatchings/k_command", func_00178420);

// FUN_00178470
s32 func_00178470(void)
{
    D_00764B5C = func_0029cd50(0);
    return 1;
}





// FUN_001784A0
INCLUDE_ASM("asm/nonmatchings/k_command", func_001784a0);



// FUN_00178500
INCLUDE_ASM("asm/nonmatchings/k_command", func_00178500);

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
