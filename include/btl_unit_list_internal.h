#ifndef BTL_UNIT_LIST_INTERNAL_H
#define BTL_UNIT_LIST_INTERNAL_H

#include "btl_effect_internal.h"

/* Update one genus-list endpoint: endpoint zero is the head, one the tail. */
static inline void btlUnitStoreListEndpoint(u8 *value, u8 *base, u32 index, u32 endpoint)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    /* measured: plain address addition changes btlUnitUnlinkAndFree by 20 normalized bytes;
     * the existing comma expression retains retail's addu operand order (MATCH). */
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    ((BtlBattleState *)address)->unitLists[endpoint] = stored;
}

#endif
