/* IDA recovery: 93 differing words through the normal probe CLI; not installed. */
/* IDA btlFormation.c:402-440; complete retail 001d2e20 window.
 * The placement classifier's live definition returns only 0, 1, 2, or 3. */
typedef struct BtlFormationPlacementWork {
    u8* actor;
    u8* subject;
    u8* partner;
    s16 action;
} BtlFormationPlacementWork;

extern s32 func_00199d00(s32 unused, u8* subject, s64 action, s32 paired);
extern s32 func_001f1210(u8* actor, s64 action, s32 paired);
extern void func_001951f0(u8* actor, u8* subject, u8* partner, s32 placement,
                         f32* position, f32* rotation, s32 mode);

// FUN_001D2E20
u32 func_001d2e20(u8* raw)
{
    f32 rotation[4];
    f32 position[3];
    BtlFormationPlacementWork* work = (BtlFormationPlacementWork*)raw;
    u8* actor = work->actor;
    u8* subject = *(u8**)(work->subject + 0x30);
    s32 paired = work->partner != NULL;
    s32 action = work->action;
    s32 placement = (s16)func_00199d00((s32)actor, subject, action, paired);

    if (func_001f1210(actor, action, paired) == 0) {
        s32 kind = (s16)func_00199d00((s32)actor, subject, action, paired);
        if (kind == 3 || kind == 1) {
            func_001951f0(actor, subject, NULL, placement, position, rotation, 1);
        } else if (kind == 2 || kind == 0) {
            func_001951f0(actor, subject, NULL, placement, position, rotation, 0);
        }
        func_00194f10(actor, rotation);
        func_00194ee0(actor, position);
    } else {
        func_001951f0(actor, subject, *(u8**)(work->partner + 0x30),
                     placement, position, rotation, 2);
        func_00194f10(actor, rotation);
        func_00194ee0(actor, position);
    }
    return 1;
}
