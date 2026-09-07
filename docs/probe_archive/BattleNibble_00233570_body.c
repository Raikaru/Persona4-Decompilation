/* Full-owner exact recovery: 784B / 784B, all fifteen relocations resolved.
 * No omitted tail or overflow. Requires datCalc.c declarations and its existing
 * pure-C PTDatCalcOffsetAdd helper. Keep the standalone signed-byte promotion
 * after the getter branch merge; it preserves retail register lifetimes. */
s64 func_00233570(u8 *arg0, s32 arg1, s64 arg2)
{
    s32 index;
    u8 byteIndex;
    s32 halfIndex;
    u16 offset;
    s32 odd;
    s32 value;
    s32 current;
    s16 result;
    s8 packed;
    s8 checked;
    u8 *ptr;

    index = arg1 & 0xff;
    if (index >= 24) {
        func_0046d730(D_00635938, 1142);
    }
    result = 0;
    if (index < 16) {
        if (index >= 24) {
            func_0046d730(D_00635938, 1039);
        }
        byteIndex = arg1;
        halfIndex = byteIndex >> 1;
        offset = halfIndex;
        odd = byteIndex & 1;
        if (odd) {
            value = (s8)(*(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 28) >> 4);
        } else {
            value = (s8)(*(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 28) & 15);
        }
        value = (s8)value;
        if (value > 7) {
            value = (s8)(value - 15);
        }
        current = (s8)value;
        if ((s8)arg2 == 0) {
            return (s8)current;
        }
        result = current + (s8)arg2;
        if (result > 1) {
            result = 1;
        } else if (result < -1) {
            result = -1;
        }
        packed = result;
        if (index >= 24) {
            func_0046d730(D_00635938, 1089);
        }
        checked = packed;
        if (checked > 7 || checked < -7) {
            func_0046d730(D_00635938, 1090);
        }
        offset = halfIndex;
        if (checked < 0) {
            packed = (s8)(checked + 15);
        }
        if (odd) {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[28] = (ptr[28] & 15) | ((packed & 15) << 4);
        } else {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[28] = (ptr[28] & 240) | (packed & 15);
        }
        if (result == 0) {
            *(s32 *)(arg0 + 20) &= ~(1 << index);
        } else {
            *(s32 *)(arg0 + 20) |= 1 << index;
        }
        if (index >= 24) {
            func_0046d730(D_00635938, 1118);
        }
        offset = halfIndex;
        if (odd) {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[36] &= 15;
        } else {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[36] &= 240;
        }
    } else {
        *(s32 *)(arg0 + 20) |= 1 << index;
    }
    return (s8)result;
}
