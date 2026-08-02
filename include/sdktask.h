#ifndef SDKTASK_H
#define SDKTASK_H

#include "type.h"

/* The object every registered task handler receives as its argument.
 *
 * `func_00451fc0(parent, name, prio, a3, a4, update, free, work)` shifts its
 * arguments down and calls `func_00451de0(name, prio, a3, a4, update, free,
 * work)` to build one of these, then attaches it to `parent`. Reading the
 * stores in `func_00451de0` (asm/nonmatchings/sdkTask/func_00451de0.s) gives
 * the offsets below directly:
 *
 *     sw  $2,  0x18($21)    a heap copy of the name string
 *     sw  $19, 0x20($21)
 *     sh  $18, 0x2C($21)
 *     sh  $17, 0x2E($21)
 *     sw  $16, 0x30($21)    first callback argument
 *     sw  $22, 0x34($21)    second callback argument
 *     sw  $23, 0x38($21)    the handler's own work allocation
 *
 * Only the fields with that direct evidence are named. Everything else stays in
 * a `reserved` array so the layout is exact and nobody has to guess: a named
 * field here is a claim, and an unnamed span is an honest admission. Field 0x38
 * alone accounts for roughly 286 raw `*(u8 **)(x + 0x38)` dereferences across
 * about fifty first-party files, which is why it is worth a type at all.
 *
 * These names are descriptive, not recovered Atlus identifiers. The retail
 * address stays the authority; see config/symbol_names.txt for anything whose
 * real name has actual evidence behind it.
 */
typedef struct SdkTask {
    /* 0x00 */ u8 reserved_00[0x18];
    /* 0x18 */ char *name;
    /* 0x1C */ u8 reserved_1c[0x14];
    /* 0x30 */ void *slot30;
    /* 0x34 */ void *slot34;
    /* 0x38 */ u8 *work;   /* u8 * so callers can do the byte-offset
                            * arithmetic the retail code does; void * would
                            * make `work + 0x534` illegal in C. */
} SdkTask;

/* Registers a child task under `parent` and returns it. The trailing `work`
 * pointer is what lands in SdkTask::work and is handed back to the callbacks. */
extern SdkTask *func_00451fc0();

#endif /* SDKTASK_H */
