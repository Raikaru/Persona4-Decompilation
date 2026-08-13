/* Source unit: src/Kosaka/k_clump/k_clump_004578b0.c (1 function markers) */
#include "include_asm.h"
#include "Kosaka/k_clump_internal.h"

typedef struct KClumpResourceList
{
    u8 reserved[0x20];
    void** materials;
    u32 count;
} KClumpResourceList;

typedef struct KClumpUserDataContext
{
    char name[0x40];
    u32 count;
} KClumpUserDataContext;

typedef struct
{
    f32 x;
    f32 y;
} RwV2d;

extern void memset(void* destination, s32 value, u32 size);

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
} RwSphere;

extern void* func_003bfae0(void* object);
extern s32 RwCameraFrustumTestSphere(void* camera, void* sphere);
extern void* D_008872E0[];
extern u32 D_00764068;
extern f32 D_00764b80;
extern void primSphereLine3D(void* center, f32 radius, void* color, u32 saveAndRestoreRenderState);

extern s32 func_003b83f0(void* object);
extern s32 func_003b85b0(void* object);
extern void func_003b8520(void* object, u32 mode);
extern void func_003b83d0(void* object, void* data);
extern f32 func_003bd090(RpUserDataArray* userData, s32 index);

extern void func_00397390(void* data);
extern u8* func_003ef650(s32, s32);
extern s32 func_003ef6d0(void);
extern void func_003ef3a0(void*);
extern void func_003ef5b0(s32, s32);
extern void func_00440b68();
extern void func_0044ea90(void*, s32);
extern u8* (*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_00712620[];
extern u8 D_00712640[];
extern u8 D_00712650[];
extern void (*jtbl_008873EC[])(void*);



// FUN_004578B0
s32 K_Clump_MatUsrDataGetInt(const RpMaterial* material, const char* name)
{
    s32 i;
    s32 value;
    RpUserDataArray* userData;

    value = 0;
    for (i = 0; i < func_003bcfb0(material); i++)
    {
        userData = func_003bd000(material, i);
        if (strcmp(func_003bd040(userData), name) == 0 &&
            func_003bd050(userData) == rpINTUSERDATA)
        {
            value = func_003bd070(userData, 0);
            break;
        }
    }
    return value;
}



// FUN_004579A0
f32 func_004579a0(const RpMaterial* material, const char* name)
{
    s32 i;
    f32 value;
    RpUserDataArray* userData;

    value = 1.0f;
    for (i = 0; i < func_003bcfb0(material); i++)
    {
        userData = func_003bd000(material, i);
        if (strcmp(func_003bd040(userData), name) == 0 &&
            func_003bd050(userData) == rpREALUSERDATA)
        {
            value = func_003bd090(userData, 0);
            break;
        }
    }
    return value;
}
// FUN_00457A90
u32 K_Clump_MatUsrDataHasData(const RpMaterial* material, const char* name)
{
    s32 i;
    u32 result;
    RpUserDataArray* userData;

    result = 0;
    for (i = 0; i < func_003bcfb0(material); i++)
    {
        userData = func_003bd000(material, i);
        /* The retail function performs the accessor twice. */
        func_003bd040(userData);
        if (strcmp(func_003bd040(userData), name) == 0)
        {
            result = 1;
            break;
        }
    }
    return result;
}



// FUN_00457B60
void* func_00457b60(void* geometry, void* data)
{
    KClumpResourceList* resourceList;
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 found;
    RpUserDataArray* userData;

    resourceList = *(KClumpResourceList**)((u8*)geometry + 0x18);
    for (resourceIndex = 0; resourceIndex < (s32)resourceList->count; resourceIndex++)
    {
        material = resourceList->materials[resourceIndex];
        found = 0;
        for (materialIndex = 0; materialIndex < func_003bcfb0((RpMaterial*)material); materialIndex++)
        {
            userData = func_003bd000((RpMaterial*)material, materialIndex);
            func_003bd040(userData);
            if (strcmp(func_003bd040(userData), (const char*)((const char**)data + 1)) == 0)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            *(u32*)data = 1;
            return NULL;
        }
    }
    return geometry;
}



// FUN_00457C90
u32 func_00457c90(void* clump, const char* name)
{
    struct
    {
        u32 found;
        char copiedName[72];
    } context;

    context.found = 0;
    strcpy(context.copiedName, name);
    func_003bff30(clump, (KClumpCallback)func_00457b60, &context);
    return context.found;
}



// FUN_00457CE0
u32 func_00457ce0(void* geometry, const char* name)
{
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 result;
    RpUserDataArray* userData;

    for (resourceIndex = 0; resourceIndex < (s32)*(u32*)((u8*)geometry + 0x14); resourceIndex++)
    {
        material = *(void**)(*(u32*)((u8*)geometry + 0x10) + resourceIndex * 4);
        result = 0;
        for (materialIndex = 0; materialIndex < func_003bcfb0((RpMaterial*)material); materialIndex++)
        {
            userData = func_003bd000((RpMaterial*)material, materialIndex);
            func_003bd040(userData);
            if (strcmp(func_003bd040(userData), name) == 0)
            {
                result = 1;
                break;
            }
        }
        if (result == 1)
        {
            return 1;
        }
    }
    return 0;
}



// FUN_00457E00
void* func_00457e00(void* object, u32* context)
{
    s32 resourceIndex;
    s32 materialIndex;
    s32 elementIndex;
    void* material;
    RpUserDataArray* userData;

    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                userData = (RpUserDataArray*)material;
                if (func_003bd050(userData) == rpINTUSERDATA &&
                    func_003bd070(userData, elementIndex) == (s32)context[0x11])
                {
                    context[0x10] = (u32)object;
                    return NULL;
                }
            }
        }
    }
    func_003e9af0(object, (KClumpCallback)func_00457e00, context);
    return object;
}



// FUN_00457F40
void* func_00457f40(void* object, const char* name, s32 value)
{
    struct
    {
        char nameCopy[0x40];
        void* result;
        s32 inputValue;
    } context;
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
    void* material;

    geometry = *(void**)((u8*)object + 4);
    strcpy(context.nameCopy, name);
    context.result = NULL;
    context.inputValue = value;
    for (resourceIndex = 0; resourceIndex < func_003bcf10(geometry); resourceIndex++)
    {
        material = func_003bcf60(geometry, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), context.nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA &&
                    func_003bd070((RpUserDataArray*)material, elementIndex) == context.inputValue)
                {
                    context.result = geometry;
                    return context.result;
                }
            }
        }
    }
    func_003e9af0(geometry, (KClumpCallback)func_00457e00, context.nameCopy);
    return context.result;
}



// FUN_00458090
void* func_00458090(void* object, u32* context)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context[0x10]++;
                }
            }
        }
    }
    func_003e9af0(object, (KClumpCallback)func_00458090, context);
    return object;
}



// FUN_004581A0
s32 func_004581a0(void* object, const char* name)
{
    KClumpUserDataContext context;
    s32 resourceIndex;
    s32 elementIndex;
    void* clump;
    void* material;

    clump = *(void**)((u8*)object + 4);
    strcpy(context.name, name);
    context.count = 0;
    for (resourceIndex = 0; resourceIndex < func_003bcf10(clump); resourceIndex++)
    {
        material = func_003bcf60(clump, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), context.name) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context.count++;
                }
            }
        }
    }
    func_003e9af0(clump, (KClumpCallback)func_00458090, &context);
    return (s32)context.count;
}



// FUN_004582C0
void* func_004582c0(void* object, u32* context)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    if (context[0x12] == 1)
    {
        return NULL;
    }
    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context[0x10] == context[0x11])
                    {
                        context[0x13] = func_003bd070((RpUserDataArray*)material, elementIndex);
                        context[0x14] = (u32)object;
                        context[0x12] = 1;
                        return NULL;
                    }
                    context[0x11]++;
                }
            }
        }
    }
    func_003e9af0(object, (KClumpCallback)func_004582c0, context);
    return object;
}



// FUN_00458430
void func_00458430(f32* result, void* object, const char* name, s32 index)
{
    struct
    {
        char nameCopy[0x40];
        s32 targetIndex;
        s32 currentIndex;
        s32 unused0;
        s32 resultValue;
        void* resultMaterial;
    } context;
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
    void* material;

    geometry = *(void**)((u8*)object + 4);
    memset(&context, 0, 0x54);
    strcpy(context.nameCopy, name);
    context.targetIndex = index;
    for (resourceIndex = 0; resourceIndex < func_003bcf10(geometry); resourceIndex++)
    {
        material = func_003bcf60(geometry, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), context.nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context.targetIndex == context.currentIndex)
                    {
                        context.resultValue = func_003bd070((RpUserDataArray*)material, elementIndex);
                        context.resultMaterial = geometry;
                        *(RwV2d*)result = *(RwV2d*)&context.resultValue;
                        return;
                    }
                    context.currentIndex++;
                }
            }
        }
    }
    func_003e9af0(geometry, (KClumpCallback)func_004582c0, &context);
    *(RwV2d*)result = *(RwV2d*)&context.resultValue;
}



// FUN_00462170
void* func_00462170(void* item)
{
    RwSphere* sphere;

    if ((*(u8*)((u8*)item + 2) & 4) != 0)
    {
        goto process;
    }
    return item;
process:
    if (*(u32*)((u8*)item + 0x18) != 0)
    {
        sphere = func_003bfae0(item);
        if (RwCameraFrustumTestSphere(*(void**)D_008872E0, sphere) != 0)
        {
            (*(void (**)(void*))((u8*)item + 0x48))(item);
            if (D_00764068 == 1)
            {
                f32 debugValue;
                RwSphere* sphere2;

                debugValue = D_00764b80;
                sphere2 = func_003bfae0(item);
                primSphereLine3D(sphere2, sphere2->radius, &debugValue, 0);
            }
        }
    }
    return item;
}



// FUN_00462E80
u32 func_00462e80(const u32* state)
{
    if (state == NULL)
    {
        return 0;
    }
    return state[8] != 0;
}



/* measured: opt_propagation off preserves the delimiter preheader instruction order; this bracket was verified at object 592B/window 592B with normalized_diff 0. */
#pragma opt_propagation off
// FUN_00462EB0
void func_00462eb0(s8* arg0)
{
    extern u8* func_00455f70(void*, u32*);
    extern void func_00442428();
    extern s32 func_003e2f60(s32, s32, void*);
    extern s32 func_003df3c0(s32, s32*);
    extern void func_003e2ce0(s32, u32);
    extern void func_003e2e40(s32, s32);
    extern u8 iGpffffaf80;
    extern u8 D_00712580[];
    extern u8 D_007125A0[];
    extern u8 D_007125E0[];
    extern void func_00440b68();
    typedef struct
    {
        s32 code;
        u32 value;
        u8 padding[0x18];
        char buffer[0x10c];
        u32 output;
    } ParseWork;
    ParseWork work;
    s32 temp_2;
    s32 var_20;
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 var_21;
    s32 var_4;
    s8* var_16;
    s32 var_22;
    s32 var_23;
    s32 delimiter;

    var_20 = 0;
    var_19 = 0;
    var_18 = 0;
    var_17 = 0;
    var_21 = 0;
    var_22 = 0;
    var_23 = 0;
    var_16 = arg0;
    func_00455f70(arg0, &work.output);
    func_00442830(work.buffer, (const char*)&iGpffffaf80);
    var_4 = 0;
    delimiter = 0x3A;
    goto scan_cond;
scan:
    if (*var_16 == delimiter)
    {
        goto scan_colon;
    }
    var_16++;
    goto scan_inc;
scan_colon:
    var_16++;
    goto scan_found;
scan_inc:
    var_4++;
scan_cond:
    if (var_4 < 0x100)
    {
        goto scan;
    }
scan_found:
    func_00442428(work.buffer, (const char*)var_16);
    temp_2 = func_003e2f60(2, 1, arg0);
    if (temp_2 != 0)
    {
        while (func_003df3c0(temp_2, &work.code) != 0)
        {
            switch (work.code)
            {
            case 11:
                var_20++;
                break;
            case 16:
                var_19++;
                break;
            case 27:
                var_18++;
                break;
            case 35:
                var_17++;
                break;
            case 22:
                var_21++;
                break;
            case 43:
                var_22++;
                break;
            case 12:
                var_23++;
                break;
            }
            func_003e2ce0(temp_2, work.value);
        }
        func_003e2e40(temp_2, 0);
    }
    func_00440b68(D_00712580, work.buffer);
    func_00440b68(D_007125A0, var_20, var_19, var_18, var_22, var_17, var_21, var_23);
    func_00440b68(D_007125E0);
}
/* measured: opt_propagation on closes the target-only bracket. */
#pragma opt_propagation on
/* measured: object 324B/window 336B, normalized_diff 24; differing word offsets 36,40,112,116,208,212. Best body archived at build/FKCL_00463100_body.c. The named first-argument locals plus inline second-argument expressions retain the three addiu/move swaps. Corrected-callee check: func_003ef650 retail reads $a0 first (lw 8($a0)), confirming the owner/name parameter order; signed, unsigned, pointer, old-style and variadic prototype variants all regressed or retained the residual. First-argument locals, liveness/reuse, destination locals, direct nested calls, explicit argument locals, pointer/address temporaries, struct-field forms, declaration permutations, and compiler-knob probes were exhausted. */
// FUN_00463100 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/k_clump", func_00463100);
// FUN_00463250
void func_00463250(u32* arg0)
{
    u32* next;
    u32* current;
    u8* resource;

    current = arg0;
    while (current != NULL)
    {
        next = (u32*)current[0x40 / 4];
        resource = func_003ef650(func_003ef6d0(), (s32)current);
        func_00440b68(D_00712650, current, *(s32*)(resource + 0x54));
        func_003ef3a0(resource);
        jtbl_008873EC[0](current);
        current = next;
    }
}
// FUN_004632F0
void* func_004632f0(void* object, void* data)
{
    s32 state;

    if (func_003b83f0(*(void**)((u8*)object + 0x18)) == 0)
    {
        goto fail;
    }
    state = func_003b85b0(object);
    if (state == 0)
    {
        goto normal;
    }
    if (state == 3)
    {
        goto normal;
    }
    switch (state)
    {
    case 1:
        goto normal;
    case 2:
        goto state2;
    default:
        goto default_state;
    }
state2:
    func_003b8520(object, 2);
    goto normal;
default_state:
    func_003b8520(object, 2);
    goto normal;
normal:
    func_003b83d0(object, data);
    goto done;
fail:
    func_00397390(data);
done:
    return object;
}
