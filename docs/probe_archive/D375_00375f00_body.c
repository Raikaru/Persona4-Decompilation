/* IDA-backed retained floor: 156B / 160B, eight fndiff words including one zero-tail word.
 * IDA: docs/ida_headstart/src/Battle/btlShuffleDraw.c:383-393; retail confirms
 * motion helper -> state 5 -> rotation helper -> state 3, with no final flag OR.
 * Typed 0xE8 records preserve the real 0x60 motion and 0x6C rotation subobjects.
 * Native parent smoke: 576 cases, using helper hooks for ordering and adjacent bytes.
 * Retail retains idx and parent but reuses their combined base for the stores;
 * this candidate still recomputes that base. Production remains ASM.
 */
// FUN_00375F00
#pragma optimization_level 1
void func_00375f00(u8 *arg0, s32 arg1) {
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
typedef char RecordSizeCheck[sizeof(ShuffleRecord)==0xe8 ? 1 : -1];
 s32 idx=arg1*sizeof(ShuffleRecord);
 ShuffleContext *p=(ShuffleContext *)((u32)arg0+(u32)idx);
 func_00370410((u8 *)&p->records[0].motion);
 p->records[0].motionState=5;
 func_00370a80((u8 *)&((ShuffleContext *)((u8 *)idx+(u32)arg0))->records[0].rotation);
 ((ShuffleContext *)((u8 *)idx+(u32)arg0))->records[0].rotationState=3;
}

#pragma optimization_level 2
