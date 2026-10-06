typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];

void func_002ba080(u8 *arg0, s16 arg1, s16 arg2, FclVec2 arg3, FclDrawColor arg4, s32 arg5, s32 arg6, s32 arg7, f32 fparg0, s8 arg_sp0)
{

    FclBoundsPacket src;
    FclBoundsBytes copy1, copy2;
    FclVec2 pos1, pos2, tmpA, tmpB, tmpC;
    u8 *object;
    FclDrawColor tmpCol1;
    FclDrawColor tmpCol2;
    s16 value;
    s16 pair_index;
    s16 next_index;
    s8 ones;
    s8 tens;
    s8 flag;
    object = arg0;
    src = func_002b29e0(22.0f, 17.0f);
    pos1 = func_002b2970(arg3.x + 284.0f, arg3.y + 6.0f);
    value = (s16)arg2;
    if ((value == -1) || fclDigitIsZero(&value)) { ones = 10; tens = 10; }
    else { ones = (s8)(value % 10); tens = (s8)(value / 10); }
    pair_index = (s16)((s16)arg1 * 2);
    next_index = (s16)((s16)arg1 * 2 + 1);
    flag = arg_sp0;
    if (flag == 0) {
        u8 *digit; u8 *slot; s32 offset;
        f32 glyphHeight, glyphWidth, glyphY, glyphX;
        digit = D_0063F1F0 + ((s32)ones * 0x10);
        glyphHeight = *(f32 *)(digit + 12);
        glyphWidth = *(f32 *)(digit + 8);
        glyphY = *(f32 *)(digit + 4);
        slot = *(u8 **)(object + 0x38);
        offset = (s32)pair_index * 0x220;
        glyphX = *(f32 *)digit;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F4) = glyphX;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F8) = glyphY;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1FC) = glyphWidth;
        *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x200) = glyphHeight;
        copy1 = src.representation;
        slot = *(u8 **)(object + 0x38);
        tmpCol1 = arg4;
        slot += offset;
        *(FclVec2 *)(slot + 0x12C) = pos1;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        *(u8 *)(slot + 0x162) = ((u8 *)&tmpCol1)[3];
        *(FclDrawColor *)(slot + 0x179) = arg4;
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = fparg0;
        *(s16 *)(slot + 0x104) = (s16)(*(s16 *)(slot + 0x104) | 1);
        ((FclBoundsPacket *)(slot + 0x204))->representation = copy1;
        *(s16 *)(slot + 0x100) = arg7;
        slot = *(u8 **)(object + 0x38) + offset;
        func_002b83e0(slot + 0x104, pos1, arg4, arg4, 0, ((u8 *)&arg4)[3], (f32)src.dimensions.height, fparg0, arg5, arg6, arg_sp0, 0);
    } else {
        u8 *slot;
        s32 offset;
        offset = (s32)pair_index * 0x220;
        slot = *(u8 **)(object + 0x38) + offset;
        if ((*(s16 *)(slot + 0x104) & 1) == 1) {
            u8 *a0 = slot + 0x104;
            {
                FclDigitColorStorage endpoint;
                endpoint.word = ((const FclDigitStoredWord *)(a0 + 0x75))->word;
                func_002b83e0(a0, *(FclVec2 *)(a0 + 0x28), endpoint.channels, endpoint.channels, *(u8 *)(a0 + 0x5E), 0, (f32)src.dimensions.height, fparg0, arg5, arg6, arg_sp0, 0);
            }
        }
    }
    if (flag == 0) {
        if ((value >= 10) || (value == 0)) {
            u8 *digit; u8 *slot; s32 offset;
            f32 glyphHeight, glyphWidth, glyphY, glyphX;
            digit = D_0063F1F0 + ((s32)tens * 0x10);
            glyphHeight = *(f32 *)(digit + 12);
            glyphWidth = *(f32 *)(digit + 8);
            glyphY = *(f32 *)(digit + 4);
            slot = *(u8 **)(object + 0x38);
            offset = (s32)next_index * 0x220;
            glyphX = *(f32 *)digit;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F4) = glyphX;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1F8) = glyphY;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x1FC) = glyphWidth;
            *(f32 *)((u8 *)((u32)offset + (u32)slot) + 0x200) = glyphHeight;
            pos2 = func_002b2970(pos1.x - 18.0f, pos1.y);
            tmpA = pos2;
            copy2 = src.representation;
            slot = *(u8 **)(object + 0x38);
            tmpCol2 = arg4;
            slot += offset;
            *(FclVec2 *)(slot + 0x12C) = tmpA;
            *(f32 *)(slot + 0x1A0) = 1.0f;
            *(f32 *)(slot + 0x194) = 1.0f;
            *(u8 *)(slot + 0x162) = ((u8 *)&tmpCol2)[3];
            *(FclDrawColor *)(slot + 0x179) = arg4;
            *(s32 *)(slot + 0x1C4) = 0;
            *(f32 *)(slot + 0x108) = fparg0;
            *(s16 *)(slot + 0x104) = (s16)(*(s16 *)(slot + 0x104) | 1);
            ((FclBoundsPacket *)(slot + 0x204))->representation = copy2;
            *(s16 *)(slot + 0x100) = arg7;
            slot = *(u8 **)(object + 0x38) + offset;
            tmpB = func_002b2970(pos1.x - 18.0f, pos1.y);
            func_002b83e0(slot + 0x104, tmpB, arg4, arg4, 0, ((u8 *)&arg4)[3], (f32)src.dimensions.height, fparg0, arg5, arg6, arg_sp0, 0);
        }
    } else {
        u8 *slot;
        s32 offset;
        offset = (s32)next_index * 0x220;
        slot = *(u8 **)(object + 0x38) + offset;
        if ((*(s16 *)(slot + 0x104) & 1) == 1) {
            u8 *a0 = slot + 0x104;
            tmpC = func_002b2970(pos1.x - 18.0f, *(f32 *)(a0 + 0x2C));
            {
                FclDigitColorStorage endpoint;
                endpoint.word = ((const FclDigitStoredWord *)(a0 + 0x75))->word;
                func_002b83e0(a0, tmpC, endpoint.channels, endpoint.channels, *(u8 *)(a0 + 0x5E), 0, (f32)src.dimensions.height, fparg0, arg5, arg6, arg_sp0, 0);
            }
        }
    }
}
