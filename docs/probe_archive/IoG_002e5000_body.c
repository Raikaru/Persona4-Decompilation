// FUN_002E5000 archive (wave Io lane IoG cut off mid-work; body is the live state at cutoff, status MISMATCH-nd288).
extern s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2);
#pragma push
#pragma opt_propagation off
void func_002e5000(void) {
s16 i;
s16 j;
s32 outer_offset;
s32 inner_offset;
u8 *base;
u8 *active;
u8 *active2;
u8 *row;
u8 *slot;
u8 *outer;
u8 *inner;
u8 **nextp;

base = *(u8 **)(D_00882F70[0] + 0x38);
active = base;
for (i = 0; i < *(s32 *)(active + 8); i++) {
    j = 0;
    row = base + i * 0xC;
    outer_offset = i * 0x30;
    nextp = D_00882F70 + (s8)(i + 1);
    for (; (active = *(u8 **)(D_00882F70[0] + 0x38)), j < *(s32 *)(active + 8); j++) {
        *(u8 *)(row + j + 0x14) = 0;
        slot = *(u8 **)(*nextp + 0x38);
        switch (*(s32 *)(slot + 4)) {
        case 0:
        case 2:
        case 7:
        case 8:
            inner_offset = j * 0x30;
            inner = slot + inner_offset + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            inner_offset = j * 0x30;
            inner = slot + inner_offset + 0xA4;
            break;
        default:
            inner_offset = j * 0x30;
            inner = slot + inner_offset + 0x14;
            break;
        }
        active2 = *(u8 **)(D_00882F70[0] + 0x38);
        switch (*(s32 *)(active2 + 4)) {
        case 0:
        case 2:
        case 7:
        case 8:
            outer = active2 + outer_offset + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            outer = active2 + outer_offset + 0xA4;
            break;
        default:
            outer = active2 + outer_offset + 0x14;
            break;
        }
        switch (*(s32 *)(active2 + 4)) {
        case 0:
        case 2:
        case 7:
        case 8:
            slot = active2 + inner_offset + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            slot = active2 + inner_offset + 0xA4;
            break;
        default:
            slot = active2 + inner_offset + 0x14;
            break;
        }
        if (func_003129b0(inner, *(u16 *)(outer + 2), *(u16 *)(slot + 2)) == 1) {
            *(u8 *)(row + j + 0x14) = 1;
        }
    }
}
}
#pragma pop
