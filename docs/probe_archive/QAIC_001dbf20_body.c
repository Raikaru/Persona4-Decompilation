/* Reconstructed selection/sort candidate; NOT a confirmed compiler floor.
 * MWCCPS2 b210: object 1152B / window 1120B / differing words 242.
 * The historical five-word note belonged to func_001dc9a0, not this target.
 * The previously named BtlAICommand_dbf20_v4.json could not be recovered;
 * the old archive held only a failed oversized-candidate comment.
 * Ascending case labels reproduce retail's descending compare chain.
 * Residuals include first-call setup/masking, copy-index allocation,
 * constant materialization, FP record addressing, sorting and weight-base
 * hoisting; the epilogue starts 36B late and the object is 32B oversized.
 * The current-HP helper uses its production u32(u32) declaration with an
 * explicit low16 mask; its defining-source ABI remains unconfirmed.
 * Count/object validity and nonzero maximum HP are retail preconditions,
 * not runtime-proven here. Do not promote this candidate on a low score.
 * Production keeps its two-argument signature and authoritative ASM.
 */
#include "type.h"
#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_common_subs off
// FUN_001DBF20
s32 func_001dbf20(u8 *arg0, u32 arg1) {
    struct DatUnit;
    extern u16 func_001d7f10(u8 *, u8 *, u16, u32);
    extern u32 func_00231d70(u32);
    extern u16 func_00231f80(struct DatUnit *);
    extern u32 func_00231ed0(u32);
    extern u8 *iGpffffb3b8;
    extern u8 D_006095F0[];
    typedef struct { u8 *unit; f32 ratio; } Choice;
    Choice choices[12];
    u16 count, copy_count;
    s32 i, random_select, scan, changed, sum, random, n;
    if (func_001d7f10(arg0,arg0+0x98,*(u16 *)(arg0+0x6e),0)) {
        i=0;
        while ((copy_count=*(u16 *)(arg0+0xd0)), (i&0xffff)<copy_count) {
            u8 *p=arg0+(i&0xffff)*4;
            *(u32 *)(p+0x38)=*(u32 *)(p+0x98);
            i=(i+1)&0xffff;
        }
        *(u16 *)(arg0+0x6a)=copy_count;
        return 1;
    }
    count=*(u16 *)(arg0+0xd0);
    random_select=1;
    if (count==1) {
        *(u32 *)(arg0+0x38)=*(u32 *)(arg0+0x98);
        *(u16 *)(arg0+0x6a)=1;
    } else {
        if ((*(u8 **)(arg0+0x30))[0xa2]==1) {
            scan=0;
            while ((scan&0xffff)<count) {
                if ((*(u8 **)((*(u8 **)(arg0+(scan&0xffff)*4+0x98))+0x30))[0xa2]!=0) break;
                scan=(scan+1)&0xffff;
            }
            if ((scan&0xffff)==count) random_select=0;
        }
        switch (iGpffffb3b8[*(u16 *)(arg0+0x6e)*40+0x11]) {
        case 1: case 3: case 4: case 8: case 10: case 12: case 13: case 14: case 16: break;
        default: random_select=1;
        }
        if (random_select || count>=5) {
            *(u32 *)(arg0+0x38)=*(u32 *)(arg0+(func_00231d70(count&0xffff)&0xffff)*4+0x98);
            *(u16 *)(arg0+0x6a)=1;
        } else {
            i=0;
            n=count&0xffff;
            while ((i&0xffff)<n) {
                s32 index=i&0xffff;
                u8 **slot=(u8 **)(arg0+index*4+0x98);
                u8 *unit=*slot;
                u32 max=func_00231f80(*(struct DatUnit **)(*(u8 **)(unit+0x30)+0xa64));
                u32 current=(func_00231ed0(*(u32 *)(*(u8 **)(unit+0x30)+0xa64))&0xffff);
                choices[index].unit=*slot;
                choices[index].ratio=(f32)current/(f32)max;
                i=(i+1)&0xffff;
            }
            do {
                changed=0;
                scan=0;
                while ((scan&0xffff)<n-1) {
                    Choice *p=&choices[scan&0xffff];
                    f32 ratio=p->ratio;
                    if (ratio<choices[(scan&0xffff)+1].ratio) {
                        u8 *unit=p->unit;
                        p->unit=p[1].unit;
                        p->ratio=p[1].ratio;
                        p[1].unit=unit;
                        p[1].ratio=ratio;
                        changed=1;
                    }
                    scan=(scan+1)&0xffff;
                }
            } while (changed);
            random=func_00231d70(100)&0xffff;
            sum=0;
            scan=0;
            while ((scan&0xffff)<(count&0xffff)) {
                sum=(sum+D_006095F0[(count&0xffff)*4+(scan&0xffff)-4])&0xffff;
                if (sum>=random) break;
                scan=(scan+1)&0xffff;
            }
            if (n!=(scan&0xffff)) {
                *(u8 **)(arg0+0x38)=choices[scan&0xffff].unit;
                *(u16 *)(arg0+0x6a)=1;
            } else {
                *(u8 **)(arg0+0x38)=choices[func_00231d70(count&0xffff)].unit;
                *(u16 *)(arg0+0x6a)=1;
            }
        }
    }
    return 1;
}

#pragma pop
