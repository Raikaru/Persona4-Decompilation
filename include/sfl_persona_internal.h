#ifndef SFL_PERSONA_INTERNAL_H
#define SFL_PERSONA_INTERNAL_H

#include "type.h"

/* Same layout as the provider's SflPersonaState in sfl_data_inferred.c:
 * reset clears 0x18 bytes at +4; load writes the five category ranks at +6. */
typedef struct SflPersonaDetails {
    s16 partyId;
    s16 ranks[5];
    s32 value;
    u8 *row;
    u8 arcana;
    u8 level;
    u8 pad16[2];
} SflPersonaDetails;

typedef struct SflPersonaState {
    s16 kind;
    u8 pad02[2];
    SflPersonaDetails details;
} SflPersonaState;

#endif
