/* object 324B/window 336B, normalized_diff 179, differing offsets 24,28,32,36,64,68,72,76,84,88,92,96,100,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,236,240,244,248,252,256,260,264,268,280,284,288,292,296,300,304,308,312,316,320; deficit 3 instructions (object undersized); classification saved-register/parameter coloring plus loop-tail path; ruled out movz/movn, COP1 MAC, standalone MMI, framed tail-jump, EE-gcc sd/sq floor. Prologue retail saves s3/s2/s1/s0 frame -0x50; args are (u8*, s32, s32) with a3 unused. Candidate frame exact but colors arg0=$s0,arg1=$s2,arg2=$s1. */
// FUN_0027A150
u8 *func_0027a150(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 tag;
    s32 temp;
    u8 *head;
    u8 *link;

    if (arg0 == NULL)
        func_0046d730(D_0063BE10, 0xE3E);
    arg1 = arg2 - arg1 - 1;
    tag = *(s32 *)(arg0 + 8);
phase1_test:
    if (arg1 <= 0)
        goto phase2_start;
    temp = *(s32 *)(arg0 + 8);
    if (tag != temp) {
        arg1--;
        tag = temp;
        goto phase1_test;
    }
    link = *(u8 **)(arg0 + 0x24);
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
    *(u8 **)(arg0 + 0x2C) = arg0;
    func_00271b70((s32)arg0);
    arg0 = link;
    if (arg0 == NULL)
        return NULL;
    goto phase1_test;

phase2_start:
    head = arg0;
phase2_walk:
    link = arg0;
    arg0 = *(u8 **)(arg0 + 0x24);
    if (arg0 == NULL)
        goto phase2_free;
    if (tag == *(s32 *)(arg0 + 8))
        goto phase2_walk;
    goto phase2_free;

phase2_free:
    if (arg0 != NULL)
        goto phase2_free_body;
    *(s32 *)(head + 0x28) = 0;
    *(s32 *)(link + 0x24) = 0;
    arg0 = head;
phase2_link:
    if (arg0 == NULL)
        return head;
    *(u8 **)(arg0 + 0x2C) = link;
    arg0 = *(u8 **)(arg0 + 0x24);
    goto phase2_link;

phase2_free_body:
    tag = *(s32 *)(arg0 + 0x24);
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
    *(u8 **)(arg0 + 0x2C) = arg0;
    func_00271b70((s32)arg0);
    arg0 = (u8 *)tag;
    goto phase2_free;
}
