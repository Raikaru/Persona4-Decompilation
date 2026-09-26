/* func_004b6030 round-2 draft: 93 reloc-masked differing words.
 * Needs `extern void* memcpy(void* dst, const void* src, u32 size);` in eff_afpack.c. */
#pragma opt_loop_invariants on
// FUN_004B6030
u8* func_004b6030(u8* arg0)
{
    u8* aTmp[16];
    u8* cTmp1[16];
    u8* cTmp2[16];
    u8* bTmp1[16];
    u8* bTmp2[16];
    u8* node;
    u8* base;
    u8* dst;
    u8* src;
    u8* col;
    u8* s;
    u8* d;
    s32 size;
    s32 i;
    s32 j;
    s32 k;
    u16 id;
    s32 key;
    s32 i0;
    s32 i1;
    s32 i2;
    s32 i3;
    s32 i4;
    s32 i5;
    u8* hdr;

    hdr = arg0;
    arg0 += 0x10;
    for (i0 = 0; i0 < *(u16*)(hdr + 0xA); i0++) {
        aTmp[i0] = arg0;
        arg0 += 0x38;
    }
    for (i1 = 0; i1 < *(u16*)(hdr + 0xC); i1++) {
        cTmp1[i1] = arg0;
        arg0 += 8;
        switch (*(u16*)(cTmp1[i1] + 4)) {
        case 0:
            arg0 += 4;
            break;
        default:
            func_0046d730(D_007146B0, 0x1AE);
            break;
        }
        cTmp2[i1] = arg0;
        switch (*(u16*)(cTmp1[i1] + 6)) {
        case 0:
            arg0 += 0x10;
            break;
        default:
            func_0046d730(D_007146B0, 0x1BA);
            break;
        }
    }
    for (i2 = 0; i2 < *(u16*)(hdr + 8); i2++) {
        bTmp1[i2] = arg0;
        switch (*(s32*)hdr) {
        case 0x64:
            arg0 += 0x18;
            break;
        case 0x65:
            arg0 += 0x20;
            break;
        default:
            func_0046d730(D_007146B0, 0x1C8);
            break;
        }
        bTmp2[i2] = arg0;
        switch (*(s32*)hdr) {
        case 0x64:
            arg0 += *(s32*)(bTmp1[i2] + 0x14);
            break;
        case 0x65:
            arg0 += *(s32*)(bTmp1[i2] + 0x1C);
            break;
        }
    }
    size = 0;
    size += 0x24;
    size += *(u16*)(hdr + 8) * 0x18;
    size += *(u16*)(hdr + 0xA) * 0x34;
    size += *(u16*)(hdr + 0xC) * 0x18;
    size += *(u16*)(hdr + 8) * 4;
    for (i3 = 0; i3 < *(u16*)(hdr + 8); i3++) {
        switch (*(s32*)hdr) {
        case 0x64:
            size += *(s32*)(bTmp1[i3] + 0x14);
            break;
        case 0x65:
            size += *(s32*)(bTmp1[i3] + 0x1C);
            break;
        }
    }
    size += *(u16*)(hdr + 8) * 8;
    func_0044ea90(D_007146B0, 0x1E4);
    node = (u8*)(*jtbl_008873E8)(size, 0x40000);
    base = node + 0x24;
    *(u8**)(node + 0xC) = base;
    base += *(u16*)(hdr + 8) * 0x18;
    *(u8**)(node + 0x10) = base;
    base += *(u16*)(hdr + 0xA) * 0x34;
    *(u8**)(node + 0x14) = base;
    base += *(u16*)(hdr + 0xC) * 0x18;
    *(u8**)(node + 0x1C) = base;
    base += *(u16*)(hdr + 8) * 4;
    for (i4 = 0; i4 < *(u16*)(hdr + 8); i4++) {
        ((u8**)*(u8**)(node + 0x1C))[i4] = base;
        switch (*(s32*)hdr) {
        case 0x64:
            base += *(s32*)(bTmp1[i4] + 0x14);
            break;
        case 0x65:
            base += *(s32*)(bTmp1[i4] + 0x1C);
            break;
        }
    }
    *(u8**)(node + 0x18) = base;
    *(s32*)(node + 0) = *(s32*)(hdr + 4);
    *(u16*)(node + 4) = *(u16*)(hdr + 8);
    *(u16*)(node + 6) = *(u16*)(hdr + 0xA);
    *(u16*)(node + 8) = *(u16*)(hdr + 0xC);
    for (i5 = 0; i5 < *(u16*)(hdr + 0xA); i5++) {
        dst = *(u8**)(node + 0x10) + i5 * 0x34;
        src = aTmp[i5];
        *(f32*)(dst + 0) = *(f32*)(src + 4);
        *(f32*)(dst + 4) = *(f32*)(src + 8);
        *(f32*)(dst + 8) = *(f32*)(src + 0xC);
        *(f32*)(dst + 0xC) = *(f32*)(src + 0x10);
        *(f32*)(dst + 0x10) = *(f32*)(src + 0x14);
        *(f32*)(dst + 0x14) = *(f32*)(src + 0x18);
        *(f32*)(dst + 0x18) = *(f32*)(src + 0x1C);
        *(f32*)(dst + 0x1C) = *(f32*)(src + 0x20);
        *(f32*)(dst + 0x24) = *(f32*)(src + 0x24);
        *(f32*)(dst + 0x20) = *(f32*)(src + 0x28);
        *(f32*)(dst + 0x28) = *(f32*)(src + 0x2C);
        *(f32*)(dst + 0x2C) = *(f32*)(src + 0x30);
        *(f32*)(dst + 0x30) = *(f32*)(src + 0x34);
    }
    for (i = 0; i < *(u16*)(hdr + 0xC); i++) {
        dst = *(u8**)(node + 0x14) + i * 0x18;
        src = cTmp1[i];
        col = cTmp2[i];
        id = *(u16*)(src + 2);
        *(s32*)(dst + 0) = id;
        if (id & 1) {
            *(s32*)(dst + 4) = D_00764CA8;
        } else {
            *(s32*)(dst + 4) = 0;
        }
        switch (*(u16*)(src + 6)) {
        case 0:
            for (k = 0; k < 4; k++) {
                s = col + k * 4;
                d = dst + (k >> 1) * 8 + (k & 1) * 4;
                d[8] = s[0];
                d[9] = s[1];
                d[10] = s[2];
                d[11] = s[3];
            }
            break;
        default:
            func_0046d730(D_007146B0, 0x22E);
            break;
        }
    }
    for (i = 0; i < *(u16*)(hdr + 8); i++) {
        dst = *(u8**)(node + 0xC) + i * 0x18;
        src = bTmp1[i];
        switch (*(s32*)hdr) {
        case 0x64:
            key = *(u16*)(src + 2);
            break;
        case 0x65:
            key = *(u16*)(src + 2);
            break;
        }
        for (j = 0; j < *(u16*)(hdr + 0xA); j++) {
            if (key == *(u16*)aTmp[j]) {
                break;
            }
        }
        *(u8**)(dst + 0) = *(u8**)(node + 0x10) + j * 0x34;
        switch (*(s32*)hdr) {
        case 0x64:
            key = *(u16*)(src + 4);
            break;
        case 0x65:
            key = *(u16*)(src + 4);
            break;
        }
        for (j = 0; j < *(u16*)(hdr + 0xC); j++) {
            if (key == *(u16*)cTmp1[j]) {
                break;
            }
        }
        *(u8**)(dst + 4) = *(u8**)(node + 0x14) + j * 0x18;
        switch (*(s32*)hdr) {
        case 0x64:
            *(s32*)(dst + 8) = *(u16*)(src + 0x10);
            break;
        case 0x65:
            *(s32*)(dst + 8) = *(u16*)(src + 0x10);
            break;
        }
        switch (*(s32*)hdr) {
        case 0x64:
            *(s32*)(dst + 0xC) = *(u16*)(src + 0x12);
            break;
        case 0x65:
            *(s32*)(dst + 0xC) = *(u16*)(src + 0x12);
            break;
        }
        switch (*(s32*)hdr) {
        case 0x64:
            *(s32*)(dst + 0x10) = 0;
            break;
        case 0x65:
            *(s32*)(dst + 0x10) = *(u16*)(src + 0x14);
            break;
        }
        switch (*(s32*)hdr) {
        case 0x64:
            *(f32*)(dst + 0x14) = 10.0f;
            break;
        case 0x65:
            *(f32*)(dst + 0x14) = *(f32*)(src + 0x18);
            break;
        }
        switch (*(s32*)hdr) {
        case 0x64:
            *(s32*)(*(u8**)(node + 0x18) + i * 8) = *(s32*)(src + 8);
            *(s32*)(*(u8**)(node + 0x18) + i * 8 + 4) = *(s32*)(src + 0xC);
            break;
        case 0x65:
            *(s32*)(*(u8**)(node + 0x18) + i * 8) = *(s32*)(src + 8);
            *(s32*)(*(u8**)(node + 0x18) + i * 8 + 4) = *(s32*)(src + 0xC);
            break;
        }
        switch (*(s32*)hdr) {
        case 0x64:
            memcpy(((u8**)*(u8**)(node + 0x1C))[i], bTmp2[i], *(s32*)(src + 0x14));
            break;
        case 0x65:
            memcpy(((u8**)*(u8**)(node + 0x1C))[i], bTmp2[i], *(s32*)(src + 0x1C));
            break;
        }
    }
    return node;
}
#pragma opt_loop_invariants off
