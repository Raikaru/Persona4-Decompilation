/* func_003bcc80 archive: best current-TU candidate, object 208B/window 208B,
   normalized_diff 8 (2 differing words). The only residual is the second loop
   entry guard: the compiler emits `blez $v0, ...` while retail uses
   `slt $at, $zero, $v0; beqz $at, ...` with the loop counter init in the delay
   slot. This is the documented slt $at-guard floor for this function.
*/
#include "include_asm.h"
#include "type.h"

extern void func_003bc740(u8 *arg0);
extern void func_003bbf80(u8 *arg0, u8 *arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);

s32 func_003bcc80(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_2;
    s32 var_19;
    s32 var_18;
    u8 *temp_17;
    u8 *temp_16;

    temp_17 = (u8 *)(arg0 + arg2);
    temp_16 = (u8 *)(arg1 + arg2);
    func_003bc740(temp_17);
    *(s32 *)(temp_17 + 0) = *(s32 *)(temp_16 + 0);
    temp_2 = *(s32 *)(temp_17 + 0);
    if (temp_2 > 0) {
        *(u8 **)(temp_17 + 4) = jtbl_008873E8[0](temp_2 * 0x10, 0x3011F);
        if (*(s32 *)(temp_17 + 0) > 0) {
            var_19 = 0;
            var_18 = 0;
            do {
                func_003bbf80(*(u8 **)(temp_17 + 4) + var_18,
                              *(u8 **)(temp_16 + 4) + var_18);
                var_19 += 1;
                var_18 += 0x10;
            } while (var_19 < *(s32 *)(temp_17 + 0));
        }
    }
    return arg0;
}
