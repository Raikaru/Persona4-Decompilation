#ifndef K_CLUMP_INTERNAL_H
#define K_CLUMP_INTERNAL_H

#include "type.h"

typedef struct RpMaterial RpMaterial;

typedef enum RpUserDataFormat
{
    rpNAUSERDATAFORMAT = 0,
    rpINTUSERDATA,
    rpREALUSERDATA,
    rpSTRINGUSERDATA,
} RpUserDataFormat;

typedef struct RpUserDataArray
{
    char* name;
    RpUserDataFormat format;
    s32 numElements;
    void* data;
} RpUserDataArray;

typedef void* (*KClumpCallback)(void* object, void* data);

extern s32 func_003bcf10(void* object);
extern void* func_003bcf60(void* object, s32 index);
extern s32 func_003bcfb0(const RpMaterial* material);
extern RpUserDataArray* func_003bd000(const RpMaterial* material, s32 index);
extern char* func_003bd040(RpUserDataArray* userData);
extern RpUserDataFormat func_003bd050(RpUserDataArray* userData);
extern s32 func_003bd060(void* object);
extern s32 func_003bd070(RpUserDataArray* userData, s32 index);
extern void* func_003bff30(void* object, KClumpCallback callback, void* data);
extern void* func_003e9af0(void* object, KClumpCallback callback, void* data);
extern s32 func_004426e8(const char* left, const char* right);
extern char* func_00442830(char* destination, const char* source);

extern void* func_00457b60(void* object, void* data);
extern void* func_00457e00(void* object, u32* context);
extern void* func_00458090(void* object, u32* context);
extern void* func_004582c0(void* object, u32* context);

#endif
