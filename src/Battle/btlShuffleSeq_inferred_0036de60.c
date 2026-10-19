/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Battle/btlShuffleSeq.c); members 0036de60-0036de60 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
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
