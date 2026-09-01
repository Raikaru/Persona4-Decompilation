/* object_size=2444 window=2480 normalized_diff=1628 differing_offsets=0,1,4,8,10,12,14,16,18,20,22,24,26,28,30,31,... classification=large-structure-mismatch; ruled_out=retail prologue/frame observation, nine-state switch reconstruction, six real stack buffers plus 0x40/0x08 scratch aggregates, corrected block-scope missing callees; automatic archive because residual is in the hundreds and candidate frame is 0x8F0 vs retail 0x6F0, indicating a materially different allocation/structure; no floor instruction (movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or ee-gcc sd-$sN signature) observed */
// FUN_00190C10
s32 func_00190c10(u8 *arg0) {
    typedef struct Frame {
        u8 buf60[0x40];
        u8 bufA0[0x100];
        u8 buf1A0[0x100];
        u8 buf2A0[0x100];
        u8 buf3A0[0x100];
        u8 buf4A0[0x100];
        u8 buf5A0[0x100];
        u8 buf6A0[0x40];
        s32 value6E0;
        s32 value6E8;
    } Frame;
    extern void func_00427338(s32 fd, void *buf, s32 size);
    extern void func_004275A8(s32 fd, void *buf, s32 size);
    Frame frame;
    u8 *work;
    u8 *tex;
    u8 *ptr;
    u8 *ptr2;
    s8 *scan;
    s32 *word;
    s32 fd;
    s32 handle;
    s32 i;
    s32 j;
    s32 n;
    s32 state;
    s32 value;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        handle = func_00428550(D_005F61D0);
        *(s32 *)(work + 4) = handle;
        if (handle < 0) {
            return -1;
        }
        *(s32 *)(work + 0) = *(s32 *)(work + 0) + 1;
        break;
    case 1:
        if (func_00428780(*(s32 *)(work + 4), work + 8) > 0) {
            if (func_004426e8(work + 0x48, &D_00763138) != 0 &&
                func_004426e8(work + 0x48, &D_0076313C) != 0) {
                scan = (s8 *)(work + 0x48);
                while (*scan != 0x2E && *scan != 0) {
                    scan++;
                }
                if (func_004426e8(scan, &D_00763140) == 0) {
                    func_00442830(work + 0x14C, D_005F61F8);
                    func_00442428(work + 0x14C, work + 0x48);
                    *(u8 **)(work + 0x24C) =
                        func_00150970(work + 0x14C);
                    func_00440b68(D_005F6210, work + 0x14C);
                    *(s32 *)(work + 0) = 2;
                }
            }
        } else {
            *(s32 *)(work + 0) = 8;
        }
        break;
    case 2:
        tex = *(u8 **)(work + 0x24C);
        if (func_00150c80(tex) != 0) {
            func_00150ce0(tex);
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 3:
        tex = *(u8 **)(work + 0x24C);
        if (func_001510c0(tex) != 0) {
            *(s32 *)(work + 0x254) = 0;
            *(s32 *)(work + 0xA58) = 0;
            for (i = 0; (u32)i < *(u32 *)(tex + 0x18); i++) {
                n = func_004581a0(*(void **)(tex + i * 4 + 0x1C),
                                  D_005F6230);
                for (j = 0; j < n; j++) {
                    func_00458430(&frame.value6E8,
                                  tex + i * 4 + 0x1C, D_005F6230, j);
                    if (frame.value6E8 == 0) {
                        func_00458430(&frame.value6E0,
                                      tex + i * 4 + 0x1C, D_005F6250, j);
                        *(s32 *)(work + 0x258 +
                                 *(s32 *)(work + 0x254) * 4) =
                            frame.value6E0;
                        *(s32 *)(work + 0x254) += 1;
                    } else if (frame.value6E8 == 1) {
                        func_00458430(&frame.value6E0,
                                      tex + i * 4 + 0x1C, D_005F6250, j);
                        *(s32 *)(work + 0xA5C +
                                 *(s32 *)(work + 0xA58) * 4) =
                            frame.value6E0;
                        *(s32 *)(work + 0xA58) += 1;
                    }
                }
            }
            *(s32 *)(work + 0) = 4;
        }
        break;
    case 4:
        func_00442830(frame.buf5A0, D_005F6270);
        scan = (s8 *)(work + 0x14C);
        while (*scan != 0) {
            scan++;
        }
        while (*scan != 0x2F) {
            scan--;
        }
        func_00442428(frame.buf5A0, scan + 1);
        word = (s32 *)frame.buf5A0;
        while (*word != 0x2E) {
            word++;
        }
        func_00442830(word, &D_00763148);
        fd = func_00426cf0(frame.buf5A0, 0x603, 0x1FF);
        D_00764498 = fd;
        if (fd >= 0) {
            *(s32 *)(work + 0xE64) = 0;
            *(s32 *)(work + 0xE68) = 0;
            tex = *(u8 **)(work + 0x24C);
            func_00442088(frame.buf4A0, D_005F62A0,
                          *(s16 *)(tex + 4), *(s16 *)(tex + 6));
            sceWrite(fd, frame.buf4A0, func_00442948(frame.buf4A0));
            for (i = 0; (u32)i < *(u32 *)(work + 0x254); i++) {
                value = *(s32 *)(work + 0x258 + i * 4);
                if (value != 0) {
                    func_00442088(frame.buf4A0, D_005F62B0,
                                  *(s16 *)(tex + 4), value);
                    sceWrite(fd, frame.buf4A0,
                             func_00442948(frame.buf4A0));
                }
            }
            for (i = 0; (u32)i < *(u32 *)(work + 0xA58); i++) {
                value = *(s32 *)(work + 0xA5C + i * 4);
                func_00442088(frame.buf4A0, D_005F62C0,
                              *(s16 *)(tex + 4), value);
                sceWrite(fd, frame.buf4A0, func_00442948(frame.buf4A0));
                func_00442088(frame.buf5A0, D_005F62D0,
                              *(s16 *)(tex + 4), value);
                func_004288d8(frame.buf5A0, frame.buf6A0);
                func_00442088(frame.buf3A0, D_005F6310,
                              *(s16 *)(tex + 4), value);
                func_004288d8(frame.buf5A0, frame.buf60);
                func_0044ea90(D_005F6168, 0x166);
                n = *(s32 *)(frame.buf60 + 8);
                ptr = D_008873F4[0](1, n, 0x40000);
                if (ptr != NULL) {
                    value = func_00426cf0(frame.buf5A0, 1, 0x1FF);
                    if (value >= 0) {
                        sceRead(value, ptr, n);
                        func_00426f80(value);
                        func_00428f08(&D_00763130, 0);
                    }
                    value = func_00426cf0(frame.buf3A0, 0x603, 0x1FF);
                    if (value >= 0) {
                        sceWrite(value, ptr, n);
                        func_00426f80(value);
                        func_00428f08(&D_00763130, 0);
                    }
                    jtbl_008873EC[0](ptr);
                }
            }
            *(s32 *)(work + 0xE5C) = 0;
            *(s32 *)(work + 0) = 5;
        }
        break;
    case 5:
        i = *(s32 *)(work + 0xE5C);
        if ((u32)i < *(u32 *)(work + 0x254)) {
            value = *(s32 *)(work + 0x258 + i * 4);
            if (value != 0) {
                tex = *(u8 **)(work + 0x24C);
                func_00442088(frame.buf2A0, D_005F6350,
                              *(s16 *)(tex + 4), value);
                func_00440b68(&D_00763150, D_005F6168, 0x263);
                ptr = func_00454a60(frame.buf2A0, 0);
                *(u8 **)(work + 0xE60) = ptr;
                func_00456150(ptr);
                *(s32 *)(work + 0) = 6;
            } else {
                *(s32 *)(work + 0xE5C) = i + 1;
            }
        } else {
            tex = *(u8 **)(work + 0x24C);
            func_00151f80(tex);
            ptr2 = *(u8 **)(tex + 0xA44);
            func_00463250(*(void **)(ptr2 + 0x128));
            jtbl_008873EC[0](ptr2);
            *(u8 **)(tex + 0xA44) = NULL;
            *(u8 **)(work + 0x24C) = NULL;
            *(s32 *)(work + 0) = 7;
        }
        break;
    case 6:
        tex = *(u8 **)(work + 0x24C);
        i = *(s32 *)(work + 0xE5C);
        value = *(s32 *)(work + 0x258 + i * 4);
        func_00442088(frame.buf1A0, D_005F6370,
                      *(s16 *)(tex + 4), value);
        ptr = *(u8 **)(work + 0xE60);
        *(s32 *)(work + 0x658 + i * 4) =
            func_00190680(ptr, frame.buf1A0);
        func_00454bd0(ptr);
        *(u8 **)(work + 0xE60) = NULL;
        *(s32 *)(work + 0xE5C) = i + 1;
        *(s32 *)(work + 0) = 5;
        break;
    case 7:
        func_00440b68(&D_00763150, D_005F6168, 0x2A0);
        ptr = func_00454a60(work + 0x14C, 0);
        *(u8 **)(work + 0x250) = ptr;
        func_00456150(ptr);
        func_00442830(frame.bufA0, D_005F63B0);
        scan = (s8 *)(work + 0x14C);
        while (*scan != 0) {
            scan++;
        }
        while (*scan != 0x2F) {
            scan--;
        }
        func_00442428(frame.bufA0, scan + 1);
        func_001909f0(*(u8 **)(work + 0x250), frame.bufA0, work);
        func_00454bd0(*(u8 **)(work + 0x250));
        func_00442830(frame.bufA0, D_005F63B0);
        scan = (s8 *)(work + 0x14C);
        while (*scan != 0) {
            scan++;
        }
        while (*scan != 0x2F) {
            scan--;
        }
        func_00442428(frame.bufA0, scan + 1);
        func_004288d8(frame.bufA0, frame.buf6A0);
        *(s32 *)(work + 0xE68) += *(s32 *)(frame.buf6A0 + 8);
        for (i = 0; (u32)i < *(u32 *)(work + 0x254); i++) {
            word = (s32 *)(work + 0x658 + i * 4);
            if (*word != 0) {
                func_003ef1b0(*word);
                *word = 0;
            }
        }
        func_00426f80(D_00764498);
        *(s32 *)(work + 0) = 1;
        break;
    case 8:
        return -1;
    default:
        break;
    }
    return 0;
}
