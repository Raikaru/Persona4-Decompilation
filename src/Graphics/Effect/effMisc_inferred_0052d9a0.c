#include "include_asm.h"
#include "type.h"

extern s32 D_00745AF8;

extern s32 D_00745ABC;

extern s32 D_007609B0[];

extern s32 D_00745C84;

extern s32 D_00745C6C;

extern s32 D_0074613C;

/* Open declaration question (2026-08-09): func_0052c890 candidates all emit
 * sq-style saves at frame 0x40 while retail uses sd saves at frame 0x20.
 * The scalar-only body removed aggregates, arrays, by-value structs, and
 * vector types; deleting either added callee prototype independently did not
 * change the result. The same unexplained inflation appears at
 * func_0050d088 (0x30 vs 0x20) and func_005249b0 (0x30 vs 0x20).
 * This is anomalous, not normal MWCCPS2 behavior: among retail functions
 * saving $ra, 3161 already-MATCHED and 4690 unmatched functions use sd, while
 * exactly one function in the image uses sq $ra. */

typedef void (*Code1B9Callback)(s32 arg0, s32 arg1, void *arg2);
typedef struct {
    Code1B9Callback callback;
    s32 arg1;
    s32 count;
} Code1B9Work;
/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */

/* Source unit: src/promoted/code1_0052.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0052.c; members 0052d9a0-0052d9a0 */

extern s32 *func_00528c30(void);
extern void func_0052c870(s32 arg0);
typedef struct {
    s64 total;
    s64 min;
    s64 max;
    s32 count;
} StatAccum52;
/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
/* measured: b210 O2 emits lui/addiu/jr/nop (unfilled return delay slot);
 * retail is lui $v0 / jr $ra / addiu $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill. */
/* measured: closes the schedule-on segment-return bracket through func_00528c30; explicit schedule off restores the following code's baseline state. */
/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
/* measured: b210 O2 emits lui/lw/jr/nop (v0 base, unfilled return delay
 * slot); retail is lui $v1 / jr $ra / lw $v0-in-delay-slot / nop. #pragma
 * schedule on is load-bearing for the delay-slot fill; load-address color
 * stays $v0 vs retail $v1 (nd 2, allocator floor). NONMATCHING */
/* measured: ee-gcc -O2 -G0 matches the 16-byte retail window. */
/* measured: closes the schedule-on segment-return bracket through func_0052c870; explicit schedule off restores the following code's baseline state. */
// FUN_0052D9A0
void func_0052d9a0(StatAccum52 *acc, s64 value)
{
    acc->total += value;
    acc->min = (value < acc->min) ? value : acc->min;
    acc->max = (acc->max < value) ? value : acc->max;
    acc->count++;
}

