#include "include_asm.h"
#include "type.h"

extern void func_00106390(s32 arg0, s32 arg1);

extern s64 func_0029cc00(s32 arg0);
extern u8 *func_00105510(s16 arg0);
extern void func_00243ec0(u8 *arg0, s16 arg1);
extern s64 func_00243e90(u8 *arg0);
extern void func_0029cf50(s32 arg0);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;

extern f32 func_0047a080(s32 arg0, s32 arg1);
extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);
extern void func_00198920(u8 *arg0, s16 arg1, u16 arg2, f32 arg3, u16 arg4);
extern void func_00194670(u8 *arg0);
extern s32 func_0047a9d0(u8 *arg0);
extern void func_0047a9b0(u8 *arg0);
extern void func_0047a990(u8 *arg0);


extern void func_0019d990(u8 *arg0, s32 arg1);
extern void func_0014b0c0(s32 arg0, s32 arg1);

extern u8 *func_0019d210(s32 arg0);
extern void func_0019ea60(u8 *arg0, u16 arg1);



extern void func_0019be50(u8 *arg0);
extern void *func_00194470();

extern void func_0019e830(void);
extern void func_0019e850(void);
extern void func_0019e9d0(void);

// FUN_00192B20
void func_00192b20(void) {
    s32 i;

    for (i = 0x15C0; i <= 0x15FF; i++) {
        func_00106390(i, 0);
    }
    func_00106390(0x1435, 0);
    func_00106390(0x1438, 0);
}



// FUN_00193630
s32 func_00193630(void) {
    s64 temp_17;
    s64 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_00243ec0(func_00105510((s16)temp_17), (s16)temp_16);
    return 1;
}



// FUN_001936A0
s32 func_001936a0(void) {
    func_0029cf50((s16)func_00243e90(func_00105510((s16)func_0029cc00(0))));
    return 1;
}



// FUN_00193730
void func_00193730(void) {
    *(s32 *)(D_0076449C + 0xC) |= 0x4000;
}



// FUN_00193A80
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00193a80);

// FUN_00193B70
u8 *func_00193b70(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (uid == (*(u64 *)(packet + 0x58) & mask) &&
                (*(u8 *)(packet + 0x47) & 0x20) != 0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
        i++;
    }
    return NULL;
}

// FUN_00193BF0
/* Same packet-list walk as func_00193b70; this P4 packet stores the UID at
   offset 0x60 instead of 0x58. */
u8 *func_00193bf0(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (uid == (*(u64 *)(packet + 0x60) & mask) &&
                (*(u8 *)(packet + 0x47) & 0x20) != 0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
        i++;
    }
    return NULL;
}

// FUN_00193C70
u32 func_00193c70(void)
{
    u32 total;
    u32 i;
    u8 *btl;
    u8 *packet;

    total = 0;
    i = 0;
    btl = iGpffffb3ac;
    for (; i < 4; i++) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            total++;
            packet = *(u8 **)(packet + 0x7C);
        }
    }
    return total;
}
// FUN_00193CD0
u32 func_00193cd0(u32 id)
{
    u8 *packet;
    u8 *btl;
    u32 total;
    u32 i;

    total = 0;
    i = 0;
    btl = iGpffffb3ac;
    id = (u16)id;
    for (; i < 4; i++) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (*(u32 *)(packet + 0x40) == id) {
                total++;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
    }
    return total;
}
// FUN_00193D30
void func_00193d30(void)
{
    u8 *packet;
    u32 i;
    u32 flags;

    i = 0;
    for (; i < 4; i++) {
        packet = *(u8 **)(iGpffffb3ac + i * 8 + 0x19C);
        while (packet != NULL) {
            flags = *(u8 *)(packet + 0x47);
            if ((flags & 1) != 0) {
                *(u8 *)(packet + 0x47) = flags | 4;
            }
            packet = *(u8 **)(packet + 0x80);
        }
    }
}

// FUN_00194660
void func_00194660(void)
{
}

static inline u32 packetListOffset(u32 offset, u32 base)
{
    return offset + base;
}

#pragma opt_propagation off
// FUN_001949D0
void func_001949d0(s32 arg0)
{
    u8 *btl;
    u8 *temp_16;
    u8 *var_4;

    btl = iGpffffb3ac;
    var_4 = *(u8 **)((u8 *)packetListOffset((arg0 & 0xFF) * 8, (u32)btl) + 0x19C);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x7C);
        func_00194670(var_4);
        var_4 = temp_16;
    }
}
#pragma opt_propagation on

// FUN_00194B50
s32 func_00194b50(void)
{
    return 1;
}

// FUN_00195530
INCLUDE_ASM("asm/nonmatchings/code1_0019", func_00195530);

// FUN_00195610
void func_00195610(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}


// FUN_00195710
void func_00195710(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00196CE0
void func_00196ce0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_001973D0
void func_001973d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00197D50
void func_00197d50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00197F30
void func_00197f30(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00198840
/* Ported from P3FES btlUnit00282c60: the P4 genus/flag/value fields retain
   the donor layout at 0xA2/0x98/0x9DA, with the result comparing unk_9EC. */
u32 func_00198840(u8 *unit)
{
    s16 val;

    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
    case 1:
        if ((*(s32 *)(unit + 0x98) & 2) != 0) {
            val = *(s16 *)(unit + 0x9DA);
        } else {
            val = 0;
        }
        return *(s16 *)(unit + 0x9EC) == val;
    }

    return 0;
}

// FUN_001988B0
/* Ported from P3FES btlUnit00282cd0: the P4 genus/flag/value fields retain
   the donor layout at 0xA2/0x98/0x9DA, with the result testing val == 1. */
u32 func_001988b0(u8 *unit)
{
    s16 val;

    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
    case 1:
        if ((*(s32 *)(unit + 0x98) & 2) != 0) {
            val = *(s16 *)(unit + 0x9DA);
        } else {
            val = 0;
        }
        return val == 1;
    }

    return 0;
}

// FUN_00199830
s64 func_00199830(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x98) & 2) {
        return (s64)(s16)(s32)func_0047a080(*(s32 *)(arg0 + 0xA00), 0);
    }
    return 0;
}



// FUN_00199890
void func_00199890(u8 *arg0, s32 arg1)
{
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0)
        func_00479e60(*(u8 **)(arg0 + 0xA00), 0, (f32)arg1);
}

// FUN_00199E50
void func_00199e50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00199E70
s32 func_00199e70(u8 *arg0)
{
    s16 temp_5;

    temp_5 = *(s16 *)(arg0 + 4);
    if (temp_5 >= 0 && temp_5 < 0x1E)
        func_00198920(*(u8 **)(arg0 + 0), temp_5, *(u16 *)(arg0 + 6),
                      *(f32 *)(arg0 + 8), *(u16 *)(arg0 + 0xC));
    return 1;
}

// FUN_00199EC0
void func_00199ec0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A010
void func_0019a010(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A030
s32 func_0019a030(u8 *arg0)
{
    s16 temp_5;
    s16 var_2;
    u8 *temp_4;

    temp_4 = *(u8 **)arg0;
    if ((*(s32 *)(temp_4 + 0x98) & 2) != 0)
        var_2 = *(s16 *)(temp_4 + 0x9DA);
    else
        var_2 = 0;
    temp_5 = *(s16 *)(temp_4 + 0x9EC);
    if (temp_5 != var_2)
        func_00198920(temp_4, temp_5, *(u16 *)(arg0 + 4),
                      *(f32 *)(temp_4 + 0x9F0),
                      (u16)*(s8 *)(temp_4 + 0x9F4));
    return 1;
}

// FUN_0019A0A0
void func_0019a0a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A130
void func_0019a130(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A2C0
void func_0019a2c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A660
void func_0019a660(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A840
void func_0019a840(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A8D0
void func_0019a8d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019A8F0
/* Ported from P3FES btlUnitUpdate00284c90Packet: the packet's unit
   pointer is at offset 0 and its comparison field is at offset 0x9EC. */
u32 func_0019a8f0(void *work)
{
    u8 *unit;
    s16 current;

    unit = *(u8 **)work;
    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
    case 1:
        if ((*(s32 *)(unit + 0x98) & 2) != 0)
            current = *(s16 *)(unit + 0x9DA);
        else
            current = 0;
        return *(s16 *)(unit + 0x9EC) == current;
    }
    return 0;
}

// FUN_0019A960
void func_0019a960(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019A9E0
void func_0019a9e0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019AA00
s32 func_0019aa00(u8 *arg0)
{
    s16 frame;
    u8 *temp_3;

    frame = *(s16 *)(arg0 + 4);
    temp_3 = *(u8 **)arg0;
    if ((*(s32 *)(temp_3 + 0x98) & 2) != 0)
        func_00479e60(*(u8 **)(temp_3 + 0xA00), 0, (f32)frame);
    return 1;
}

// FUN_0019AA50
void func_0019aa50(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019AAE0
void func_0019aae0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019AC20
void func_0019ac20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B530
void func_0019b530(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B620
void func_0019b620(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019B680
void func_0019b680(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019B710
void func_0019b710(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BBC0
void func_0019bbc0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BC90
void func_0019bc90(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BCE0
void func_0019bce0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BD60
void func_0019bd60(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BDB0
void func_0019bdb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BE30
void func_0019be30(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_0019BE90
void func_0019be90(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019BEB0
u8 *func_0019beb0(u8 *arg0)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x11B, 4);
    *(void **)(packet + 0x68) = (void *)func_0019be30;
    *(void **)(packet + 0x6C) = (void *)func_0019be50;
    *(void **)(packet + 0x70) = (void *)func_0019be90;
    **(u8 ***)(packet + 0x78) = arg0;
    return packet;
}

// FUN_0019BF10
void func_0019bf10(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0));
    *(u16 *)(temp_5 + 0xA0) = (u16) (*(u16 *)(temp_5 + 0xA0) + 1);
    if (!(*(u16 *)(arg0 + 8) & 0x10)) {
        temp_4 = (u8 *)(*(u8 **)(temp_5 + 0xA00));
        if (*(s32 *)(temp_4 + 0x2D0) == 0) {
            func_0047d170(temp_4, temp_5);
        }
        *(s32 *)(arg0 + 0xC) = 1;
    }
}

// FUN_0019C010
void func_0019c010(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_0019D040
void func_0019d040(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) &= ~0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 1);
        *(s32 *)(arg0 + 0x9C) &= ~2;
        return;
    }
    *(s32 *)(arg0 + 0x9C) |= 2;
}



// FUN_0019D0C0
void func_0019d0c0(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) |= 0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 0);
    }
    *(s32 *)(arg0 + 0x9C) &= ~2;
}



// FUN_0019D4E0
void func_0019d4e0(u8 *arg0)
{
    u8 *node;
    s32 h;

    func_0019d3c0();
    node = *(u8 **)(arg0 + 0xA0C);
    if (node != NULL) {
        func_0019d550(node);
    }
    h = ((s32 *)arg0)[641];
    if (h != 0) {
        func_001d7040(h);
        *(s32 *)(arg0 + 0xA04) = 0;
    }
    h = ((s32 *)arg0)[642];
    if (h != 0) {
        func_001d6c10(h);
        *(s32 *)(arg0 + 0xA08) = 0;
    }
}

// FUN_0019DEA0
void func_0019dea0(u8 *arg0)
{
    if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
        if (func_0047a9d0(*(u8 **)(arg0 + 0xA00)) != 0) {
            func_0047a9b0(*(u8 **)(arg0 + 0xA00));
            func_0047a990(*(u8 **)(arg0 + 0xA00));
        }
    }
}

// FUN_0019E9F0
u8 *func_0019e9f0(u8 *unit, s16 value)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)func_00194470(0x11A, 8);
    *(void **)(packet + 0x68) = (void *)func_0019e830;
    *(void **)(packet + 0x6C) = (void *)func_0019e850;
    *(void **)(packet + 0x70) = (void *)func_0019e9d0;
    work = *(u8 **)(packet + 0x78);
    *(u8 **)work = unit;
    *(s16 *)(work + 4) = value;

    return packet;
}

// FUN_0019EF30
void func_0019ef30(u8 *arg0, u16 arg1) {
    if (*(u8 **)(arg0 + 0xA0C) == NULL) {
        *(u8 **)(arg0 + 0xA0C) = func_0019d210(2);
    }
    func_0019ea60(*(u8 **)(arg0 + 0xA0C), arg1);
}
