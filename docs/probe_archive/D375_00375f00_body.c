/* Current b210 owner floor: 156B/160B, four differing bytes in two emitted
 * words; four retail zero-tail bytes. Both call relocations fully resolved.
 * At +0x48/+0x70 retail copies the cached context from s2; the candidate
 * recomputes it from parent/index. Production remains ASM.
 * IDA: docs/ida_headstart/src/Battle/btlShuffleDraw.c:383-393.
 * Motion helper -> state 5 -> rotation helper -> state 3; no final flag OR.
 * Typed 0xE8 records preserve 0x60 motion and 0x6C rotation subobjects.
 * Both calls share the cached context; state stores derive their own views.
 * Native actual-provider smoke: 180 cases under Clang UB traps, covering
 * provider mutations, inter-call state, all twelve records and adjacent bytes.
 * All 44 existing owner C matches and their relocations remain intact.
 * Requires valid aligned backing storage and an allocated record index.
 *
 * Fresh 2026-09-09 compiler experiments preserve the same 156B/nd4 floor.
 * Eight equivalent integer/pointer/indexed state views do not close the
 * cached-base copies; the wide-index view grows to 172B. Explicit cached
 * state stores and a grouped base/offset/context local both collapse to
 * 128B/nd100, removing the retail parent/index register lifetimes. An inline
 * context-view helper reaches 156B/nd26 but still recomputes the two bases.
 * Typed-record cached-context construction grows to 176B/nd115. The b119
 * compiler emits the same 156B/nd4 candidate as b210; no compiler cutover.
 * Production remains unchanged. These are source-shape experiments, not
 * a proof that no matching ordinary-C spelling exists.
 */
// FUN_00375F00
#pragma optimization_level 1
typedef struct ShuffleMotion { u8 data[0x60]; } ShuffleMotion;
typedef struct ShuffleRotation { u8 data[0x6c]; } ShuffleRotation;
typedef struct ShuffleRecord {
    u16 flags; u16 unknown02;
    s32 motionState; s32 rotationState;
    ShuffleMotion motion;
    ShuffleRotation rotation;
    u8 trackD8[8]; u8 trackE0[8];
} ShuffleRecord;
typedef struct ShuffleContext { u8 preceding[0x1d6a0]; ShuffleRecord records[]; } ShuffleContext;
void func_00375f00(u8 *arg0, s32 arg1) {
    s32 idx = arg1 * sizeof(ShuffleRecord);
    ShuffleContext *p = (ShuffleContext *)(arg0 + idx);
    func_00370410((u8 *)&p->records[0].motion);
    ((ShuffleContext *)(arg0 + idx))->records[0].motionState = 5;
    func_00370a80((u8 *)&p->records[0].rotation);
    ((ShuffleContext *)(arg0 + idx))->records[0].rotationState = 3;
}

#pragma optimization_level 2
