#include "rw_object_internal.h"
#include "rw_texture_internal.h"
#include "rw_atomic_layout_internal.h"
/* Source unit: src/Kosaka/k_clump/k_clump_004578b0.c (1 function markers) */
#include "include_asm.h"
#include "Kosaka/k_clump_property_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "texture_callback_internal.h"

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

extern void memset(void* destination, s32 value, u32 size);

#include "rw_geometry_layout_internal.h"

extern void* func_003bfae0(void* object);
extern s32 RwCameraFrustumTestSphere(void* camera, void* sphere);
extern void* D_008872E0[];
extern u32 D_00764068;
extern f32 D_00764b80;
extern void primSphereLine3D(void* center, f32 radius, void* color, u32 preserveState);

extern s32 func_003b83f0(void* object);
extern s32 func_003b85b0(void* object);
extern void func_003b8520(void* object, u32 mode);
extern void func_003b83d0(void* object, void* data);
extern f32 func_003bd090(RpUserDataArray* userData, s32 index);

extern void func_00397390(void* data);
extern u8* func_003ef650(s32, ...);
extern s32 func_003ef6d0(void);
extern void func_003ef3a0(void*);
extern void func_003ef5b0(s32, s32);
extern void func_00440b68();
extern void chkmemAllocSiteTag(void*, s32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00712620[];
extern u8 D_00712640[];
extern u8 D_00712650[];
extern void (*jtbl_008873EC[])(void*);



/* Texture-name nodes are allocated as 0x44 bytes and chained at +0x40. */
typedef struct KClumpTextureName {
    char name[0x40];
    struct KClumpTextureName *next;
} KClumpTextureName;

/* RpWorld material list prefix, rw/world/baworld.h and bamatlst.h. */
struct RpWorld {
    RwObject object;
    u32 flags;
    s32 renderOrder;
    struct { struct RpMaterial **materials; s32 count, capacity; } matList;
};

/* Return the first named integer material property, defaulting to zero. */
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



/* Return the first named real material property, defaulting to one. */
// FUN_004579A0
f32 K_Clump_MatUsrDataGetFloat(const RpMaterial* material, const char* name)
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
void* K_Clump_AtomicMatUsrDataCb(void* geometry, void* data)
{
    KClumpResourceList* resourceList;
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 found;
    RpUserDataArray* userData;

    resourceList = (KClumpResourceList *)((struct RpAtomic *)geometry)->geometry;
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



/* Search every atomic for a material property matching a copied name. */
// FUN_00457C90
u32 K_Clump_ClumpHasMatUsrData(void* clump, const char* name)
{
    struct
    {
        u32 found;
        char copiedName[72];
    } context;

    context.found = 0;
    strcpy(context.copiedName, name);
    RpClumpForAllAtomics(clump, (KClumpCallback)K_Clump_AtomicMatUsrDataCb, &context);
    return context.found;
}



/* Search the world-format material list for any property with the requested name. */
// FUN_00457CE0
u32 K_Clump_GeometryHasMatUsrData(void* geometry, const char* name)
{
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 result;
    RpUserDataArray* userData;

    for (resourceIndex = 0; resourceIndex < (s32)(u32)((struct RpWorld *)geometry)->matList.count; resourceIndex++)
    {
        material = ((struct RpWorld *)geometry)->matList.materials[resourceIndex];
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



/* Search this frame and its descendants for the requested integer property value. */
// FUN_00457E00
void* K_Clump_FindIntUsrDataFrameCb(void* object, void* data)
{
    u32* context = data;
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
    func_003e9af0(object, K_Clump_FindIntUsrDataFrameCb, context);
    return object;
}



/* Search the root frame and descendants for a named integer property equal to value. */
// FUN_00457F40
void* K_Clump_FindIntUsrDataFrame(void* object, const char* name, s32 value)
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

    geometry = ((RwObject *)object)->parent;
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
    func_003e9af0(geometry, K_Clump_FindIntUsrDataFrameCb, context.nameCopy);
    return context.result;
}



/* Accumulate integer elements with the requested property name while traversing child frames. */
// FUN_00458090
void* K_Clump_CountIntUsrDataCb(void* object, void* data)
{
    u32* search = data;
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), (const char*)search) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    search[0x10]++;
                }
            }
        }
    }
    func_003e9af0(object, K_Clump_CountIntUsrDataCb, search);
    return object;
}



/* Count integer property elements over the complete frame hierarchy. */
// FUN_004581A0
s32 K_Clump_CountIntUsrData(void* object, const char* name)
{
    KClumpUserDataContext context;
    s32 resourceIndex;
    s32 elementIndex;
    void* clump;
    void* material;

    clump = ((RwObject *)object)->parent;
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
    func_003e9af0(clump, K_Clump_CountIntUsrDataCb, &context);
    return (s32)context.count;
}



/* The callback and lookup share the name, search counters, found flag,
   and complete integer/frame result. See KClump_property_result_20261005.md. */
typedef struct KClumpIntSearchContext
{
    char nameCopy[0x40];
    s32 targetIndex;
    s32 currentIndex;
    s32 found;
    KClumpIntPropertyResult result;
} KClumpIntSearchContext;

typedef char KClumpIntSearchContextSize[
    (sizeof(KClumpIntSearchContext) == 0x54) ? 1 : -1];

/* Stop at the requested integer-property ordinal and retain its value and owning frame. */
// FUN_004582C0
void* K_Clump_IntUsrDataAtCb(void* object, void* data)
{
    KClumpIntSearchContext* context = data;
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    if (context->found == 1)
    {
        return NULL;
    }
    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (strcmp(func_003bd040((RpUserDataArray*)material), context->nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context->targetIndex == context->currentIndex)
                    {
                        context->result.value = func_003bd070((RpUserDataArray*)material, elementIndex);
                        context->result.frame = object;
                        context->found = 1;
                        return NULL;
                    }
                    context->currentIndex++;
                }
            }
        }
    }
    func_003e9af0(object, K_Clump_IntUsrDataAtCb, context);
    return object;
}



/* Return the selected named integer property and frame, using a zeroed search context. */
// FUN_00458430
void K_Clump_GetIntUsrDataAt(KClumpIntPropertyResult* result, void* object, const char* name, s32 index)
{
    KClumpIntSearchContext context;
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
    void* material;

    geometry = ((RwObject *)object)->parent;
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
                        context.result.value = func_003bd070((RpUserDataArray*)material, elementIndex);
                        context.result.frame = geometry;
                        *result = context.result;
                        return;
                    }
                    context.currentIndex++;
                }
            }
        }
    }
    func_003e9af0(geometry, K_Clump_IntUsrDataAtCb, &context);
    *result = context.result;
}



/* Mark the caller output when a traversed material has fully opaque alpha. */
/* RpGeometryForAllMaterials supplies RpMaterial records; +7 is color.alpha. */
// FUN_00461530
s32 K_Clump_CheckSentinelFrameCb(u8 *frame, s32 *found)
{
    if (((RpMaterial *)frame)->color.alpha == 0xFF) {
        *found = 1;
    }
    return (s32)frame;
}
/* Render enabled atomics whose bounding spheres intersect the camera frustum; optionally draw debug bounds. */
// FUN_00462170
void* K_Clump_RenderAtomicIfVisibleCb(void* item, void* data)
{
    RwSphere* sphere;

    if ((((struct RpAtomic *)item)->flags & 4) != 0)
    {
        goto process;
    }
    return item;
process:
    if ((u32)((struct RpAtomic *)item)->geometry != 0)
    {
        sphere = func_003bfae0(item);
        if (RwCameraFrustumTestSphere(*(void**)D_008872E0, sphere) != 0)
        {
            ((struct RpAtomic *)item)->renderCallBack((struct RpAtomic *)item);
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



/* Treat a null state as disabled; otherwise test the ninth state word. */
// FUN_00462E80
u32 K_Clump_StateFlagIsSet(const u32* state)
{
    if (state == NULL)
    {
        return 0;
    }
    return state[8] != 0;
}



/* measured: opt_propagation off preserves the delimiter preheader instruction order; this bracket was verified at object 592B/window 592B with normalized_diff 0. */
#pragma opt_propagation off
/* Scan stream chunk headers and log counts without decoding their payloads. */
// FUN_00462EB0
void K_Clump_LogCodeCounts(s8* path)
{
    extern u8* H_Cdvd_LookupRequest(void*, u32*);
    extern void strcat();
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
    s32 stream;
    s32 worldCount;
    s32 clumpCount;
    s32 animationCount;
    s32 chunkCount;
    s32 dictionaryCount;
    s32 characterIndex;
    s8* pathCursor;
    s32 teamDictionaryCount;
    s32 lightCount;
    s32 delimiter;

    worldCount = 0;
    clumpCount = 0;
    animationCount = 0;
    chunkCount = 0;
    dictionaryCount = 0;
    teamDictionaryCount = 0;
    lightCount = 0;
    pathCursor = path;
    H_Cdvd_LookupRequest(path, &work.output);
    strcpy(work.buffer, (const char*)&iGpffffaf80);
    characterIndex = 0;
    delimiter = 0x3A;
    goto scan_cond;
scan:
    if (*pathCursor == delimiter)
    {
        goto scan_colon;
    }
    pathCursor++;
    goto scan_inc;
scan_colon:
    pathCursor++;
    goto scan_found;
scan_inc:
    characterIndex++;
scan_cond:
    if (characterIndex < 0x100)
    {
        goto scan;
    }
scan_found:
    strcat(work.buffer, (const char*)pathCursor);
    stream = func_003e2f60(2, 1, path);
    if (stream != 0)
    {
        while (func_003df3c0(stream, &work.code) != 0)
        {
            switch (work.code)
            {
            case 11:
                worldCount++;
                break;
            case 16:
                clumpCount++;
                break;
            case 27:
                animationCount++;
                break;
            case 35:
                chunkCount++;
                break;
            case 22:
                dictionaryCount++;
                break;
            case 43:
                teamDictionaryCount++;
                break;
            case 12:
                lightCount++;
                break;
            }
            func_003e2ce0(stream, work.value);
        }
        func_003e2e40(stream, 0);
    }
    func_00440b68(D_00712580, work.buffer);
    func_00440b68(D_007125A0, worldCount, clumpCount, animationCount, teamDictionaryCount, chunkCount, dictionaryCount, lightCount);
    func_00440b68(D_007125E0);
}
/* measured: opt_propagation on closes the target-only bracket. */
#pragma opt_propagation on
// FUN_00463100
struct RwTexture *K_Clump_AppendTextureName(struct RwTexture *texture, void *list)
{
    u8* textureBytes;
    u32** listHead;
    u8* resource;
    char* work;
    u8* current;
    u32** next;

    textureBytes = (u8*)texture;
    listHead = (u32**)list;

    resource = func_003ef650(func_003ef6d0(), textureBytes + 0x10);
    if (resource != NULL)
    {
        (((RwTexture *)resource)->refCount)++;
    }
    else
    {
        func_003ef5b0(func_003ef6d0(), (s32)textureBytes);
    }
    resource = func_003ef650(func_003ef6d0(), textureBytes + 0x10);
    func_00440b68(D_00712620, resource + 0x10, (u8)((RwTexture *)resource)->filterAddressing, ((RwTexture *)resource)->refCount);
    chkmemAllocSiteTag(D_00712640, 0x97);
    work = (char*)D_008873F4[0](1, 0x44, 0x40000);
    strcpy(work, (const char*)(textureBytes + 0x10));
    if (*listHead == NULL)
    {
        *listHead = (u32*)work;
    }
    else
    {
        current = (u8*)*listHead;
        next = (u32**)(current + 0x40);
        while (*next != NULL)
        {
            current = (u8*)*next;
            next = (u32**)(current + 0x40);
        }
        *next = (u32*)work;
    }
    return texture;
}
// FUN_00463250
void K_Clump_FreeTextureNameList(u32* listHead)
{
    u32* next;
    u32* current;
    u8* resource;

    current = listHead;
    while (current != NULL)
    {
        next = (u32 *)((KClumpTextureName *)current)->next;
        resource = func_003ef650(func_003ef6d0(), (s32)current);
        func_00440b68(D_00712650, current, ((RwTexture *)resource)->refCount);
        func_003ef3a0(resource);
        jtbl_008873EC[0](current);
        current = next;
    }
}
/* Update a ready object, normalizing its state when needed; otherwise release the supplied data. */
// FUN_004632F0
void* K_Clump_UpdateObjectCb(void* object, void* data)
{
    s32 state;

    if (func_003b83f0((void *)((struct RpAtomic *)object)->geometry) == 0)
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
