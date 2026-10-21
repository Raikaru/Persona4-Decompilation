
#include "type.h"
#include "btl_shuffle_card_internal.h"
/* Canonical grouped function declarations. */
u32 btlShuffleCardGetKind(int work);
/* Return the model mode used by shuffle callers as the card-kind selector. */
// FUN_0036DE60
u32 btlShuffleCardGetKind(int work)
{
    return (u32)((BtlShuffleCard *)work)->model.mode;
}
