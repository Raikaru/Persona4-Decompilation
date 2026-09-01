/* object_size=584; window=576; normalized_diff=398; differing_offsets=[0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,276,280,284,288,292,296,300,304,308,312,316,320,324,328,332,336,340,344,348,352,356,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,452,456,460,464,468,472,476,480,484,488,492,496,500,504,508,512,516,520,524,528,532,536,540,544,548,552,556,560,564,568,572]; classification=OBJECT_LARGER_THAN_WINDOW+LARGE_RESIDUAL; ruled_out=retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; corrected callees func_0045a890(s16)->s32, func_0045af90(s16)->s32, func_0047e0f0(u8*,s16,s16,u16); candidate frame/signature was frame=0x50, sq s0-s3, mixed prototype (u8*,s16,u16), but residual remained 398 and object exceeded window, so archived immediately. */

void func_0047eb20(u8 *arg0, s16 arg1, u16 arg2)
{
    s16 status;
    s32 temp_4_2;
    u16 type;
    u8 *node;

    if ((*(u16 *)(arg0 + 0x10) & 0x10) == 0) {
        return;
    }
    node = *(u8 **)arg0;
    if (node == NULL || (*(u16 *)(node + 0x12) & 1) == 0) {
        return;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        type = *(u16 *)(node + 0xC);
        if (type == 1) {
            status = 2;
        } else {
            status = 3;
        }
        if ((type == 1 &&
             (arg1 != 0xE || *(s16 *)(arg0 + 4) != arg1 ||
              func_0045af90(status) == 0)) ||
            (*(u16 *)(node + 0xC) == 2 &&
             (arg1 != 2 || *(s16 *)(arg0 + 4) != arg1 ||
              func_0045af90(status) != 0))) {
            if (func_0047e0f0(arg0, 0, arg1, arg2) != 0) {
                *(s16 *)(arg0 + 8) = 0;
                *(s16 *)(arg0 + 4) = arg1;
                *(u16 *)(arg0 + 6) = arg2;
                return;
            }
            *(s16 *)(arg0 + 8) = -1;
            return;
        }
        *(s16 *)(arg0 + 8) = -1;
        return;
    }
    if (*(u16 *)(node + 0x10) != 2 ||
        (arg1 != 4 && arg1 != 5) ||
        func_0045a890(*(s16 *)(node + 4)) == 0) {
        return;
    }
    *(s16 *)(arg0 + 0x1C) = *(s16 *)(node + 4);
    *(s16 *)(arg0 + 0x24) = arg2;
    *(s16 *)(arg0 + 0x20) = 0;
    *(s16 *)(arg0 + 0x22) = arg1 - 4;
    temp_4_2 = *(s32 *)(node + 4);
    switch (temp_4_2) {
    case 3:
        *(s16 *)(arg0 + 0x1E) = 1;
        break;
    case 4:
        *(s16 *)(arg0 + 0x1E) = 2;
        break;
    case 5:
        *(s16 *)(arg0 + 0x1E) = 3;
        break;
    }
    *(s16 *)(arg0 + 4) = arg1;
}
