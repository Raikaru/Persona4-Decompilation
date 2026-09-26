#ifndef K_MODEL_INTERNAL_H
#define K_MODEL_INTERNAL_H

#include "type.h"

/* The model loader as the Kosaka field code (k_fldFBN, k_fldUnit, the field
 * party cache in code1_0016, k_command) was compiled against it: a u16 model
 * type. mdlManager.c defines it with an int-width type, and that is also
 * retail: the definition forwards `type` unmasked to the same helpers as
 * func_0047ac90, which forwards its own type unmasked to func_00477c40, whose
 * first parameter mdlSE's func_0047df40 fills with an unmasked int. Field
 * callers pass u16 values unmasked (func_00162680, func_0015e960) and do
 * not match with the definition's type. Evidence:
 * docs/probe_archive/Prototype_mismatch_00477c40_00478140_20260926.md
 * lint: allow H011 -- retail-proven stale field prototype: u16 type here, int type in mdlManager */
extern void *func_00478140(u16 type, u16 id, u32 flags);

#endif
