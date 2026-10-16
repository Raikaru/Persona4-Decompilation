#ifndef BTL_BATTLE_INTERNAL_H
#define BTL_BATTLE_INTERNAL_H

/* Battle flag word at iGpffffb3ac+0xC (also reached as D_0076449C+0xC).
 * Set by the battle sequence start; battle teardown frees the battle-owned
 * unit slot tables (+0xC74, +0xC84, +0xC94) only while it is set. */
#define BTL_FLAG_FREE_UNITS (1 << 14) /* 0x4000 */

#endif
