/* P4M lane func_002ba970 best candidate, archived per abandon rule.
   Best of ~13 probed shapes: normalized_diff 71, object 148B / window 176B.
   Retail semantics (from recon_dis): writes RGBA arg2 (4-byte struct passed
   in $a2) to entries (s16)arg1*2 and +1 of *(arg0+0x38) at +0x179..0x17C,
   then alpha byte again at +0x162 of both entries. Retail reloads the base
   pointer 4x and re-extends (s16)dbl after the first sb block; b210 keeps
   the cached pointer and hoists the extension, so the load/store schedule
   never lines up. All probes MISMATCH >= nd 71; archived, not applied. */

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Rgba;

// FUN_002BA970
void func_002ba970(u8 *arg0, s64 arg1, Rgba arg2)
{
    s32 dbl;
    u8 *base;
    u8 *pA;
    u8 *pB;

    dbl = (s16)arg1 * 2;
    base = *(u8 **)(arg0 + 0x38);
    pA = base + dbl * 0x220;
    *(Rgba *)(pA + 0x179) = arg2;
    pB = base + (s16)(dbl + 1) * 0x220;
    *(Rgba *)(pB + 0x179) = arg2;
    pA[0x162] = arg2.a;
    pB[0x162] = arg2.a;
}
