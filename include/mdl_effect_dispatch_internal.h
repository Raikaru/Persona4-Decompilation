#ifndef MDL_EFFECT_DISPATCH_INTERNAL_H
#define MDL_EFFECT_DISPATCH_INTERNAL_H

#include "type.h"

/* D_00713480 has 0x40-byte entries selected by primitive kind. Only the
 * constructor, clone and destructor slots used by tree ownership are typed. */
typedef struct MdlEffectPrimitiveHandlers {
    void *(*create)(void *source);
    u8 pad4[0xC];
    union { s32 value; void (*callback)(s32 instance); } destroy;
    void *(*clone)(void *source);
    u8 pad18[0x28];
} MdlEffectPrimitiveHandlers;

/* Kind-specific record dispatch uses 0x1C-byte entries. The constructor word
 * at +0xC is tested before choosing the direct-parameter constructor. */
typedef struct MdlEffectKindHandlers {
    u8 pad0[0xC];
    union { s32 value; s32 (*callback)(u8 *source); } fromRecord;
    u8 pad10[0xC];
} MdlEffectKindHandlers;

/* D_0071401C is an interior alias for the record constructor column of the
 * same 0x1C-byte table; this describes the subobject beginning at that alias. */
typedef struct MdlEffectRecordConstructor {
    union { s32 value; s32 (*callback)(u8 *source); } constructor;
    u8 pad4[0x18];
} MdlEffectRecordConstructor;

#endif
