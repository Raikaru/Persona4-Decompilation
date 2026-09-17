// Best body for func_001774a0 @0x001774a0 window 1392B
// probe v1_switch: obj 1368/1392 nd 875 MISMATCH (switch 1/3/10/default, honest -1.0f via lui 0xBF80, u16 lhu walk, Vec3f block copies, bottom-test loops)
// Status: ASM retained; archived per nd>25 gate. Do NOT touch other funcs. Empty-case hypothesis retired per docs/matching.md wave-11/12 (nd75/348 with cases 2,4-9) — not retried.
// Notes: obj -24B (6 words) short; first diffs at word 74 (ld dest $v0 vs $v1) then scheduling/stack offsets (sd 0xa8 vs lui, swc1 offsets 0x98 vs 0xA0 etc.); dispatch order retail 10/3/1 descending vs mwcc ascending — switch keeps all-forward beq shape, if-chain (nd885/obj1360) worse. Lint: 1 warn H007 stkF dead store (alive via contiguous &stk64 12B buf for 0047a1a0).
s32 func_001774a0(void)
{
    s32 v0;
    s32 v1;
    u8* ent;
    s64 stk64;
    f32 stkF;
    Vec3f vCopy;
    Vec3f vNeg;
    Vec3f m1;
    Vec3f m3;
    Vec3f m10;
    Vec3f vS;
    s32 k;

    v0 = func_0029cc00(0);
    v1 = func_0029cc00(1);
    ent = func_001452b0(0xE);
    stk64 = D_005F1868[0];
    stkF = D_005F1870[0];
    if (ent == NULL) {
        func_0046d730(D_005F1858, 0x2C3);
    }
    while (ent != NULL) {
        if ((*(u16*)ent & 0x3FF) == v1) {
            break;
        }
        ent = *(u8**)(ent + 0x138);
    }
    k = (v0 & 0xFFC00) >> 10;
    switch (k) {
    case 1: {
        u8* p = func_00145270(v0 & 0xFFFF);
        if (p != NULL) {
            void* q = func_0047a2f0(*(s32*)(p + 0x164));
            vCopy = *(Vec3f*)((u8*)q + 0x30);
            vNeg.x = -1.0f * vCopy.x;
            vNeg.y = -1.0f * vCopy.y;
            vNeg.z = -1.0f * vCopy.z;
            func_0047a180(*(s32*)(p + 0x164), (u8*)&vNeg, 2);
            func_0047a1a0(*(s32*)(p + 0x164), &stk64, *(f32*)(ent + 0x14C), 0);
            func_0047a180(*(s32*)(p + 0x164), (u8*)&vCopy, 2);
            q = func_0047a2f0(*(s32*)(p + 0x164));
            *(Vec3f*)((u8*)q + 0x30) = *(Vec3f*)(ent + 0x140);
            func_003e0380(&m1.x);
            func_003e03e0(func_0047a2f0(*(s32*)(p + 0x164)), &m1.x);
            func_003e05d0(func_0047a2f0(*(s32*)(p + 0x164)));
            func_00168c00(*(s32*)(p + 0x220));
            func_0015bae0();
            {
                s32 i = 0;
                while (i < 3) {
                    s32 flag = 0;
                    u8* e = D_007EF9B0 + i * 0x750;
                    if ((*(s32*)(e + 0x798) != 0) && (*(s32*)(e + 0x7A4) != 0)) {
                        flag = 1;
                    }
                    if (flag != 0) {
                        s32 t = *(s32*)(e + 0x900);
                        if (t != 0) {
                            func_0017e9b0(t);
                        }
                    }
                    i++;
                }
            }
            if (*(s32*)(func_00155280() + 4) != 0) {
                func_0016ec90(*(s32*)(func_00155280() + 4));
            }
        }
        break;
    }
    case 3: {
        u8* p = func_00145270(v0 & 0xFFFF);
        if (p != NULL) {
            void* q = func_0047a2f0(*(s32*)(p + 0x164));
            vCopy = *(Vec3f*)((u8*)q + 0x30);
            vNeg.x = -1.0f * vCopy.x;
            vNeg.y = -1.0f * vCopy.y;
            vNeg.z = -1.0f * vCopy.z;
            func_0047a180(*(s32*)(p + 0x164), (u8*)&vNeg, 2);
            func_0047a1a0(*(s32*)(p + 0x164), &stk64, *(f32*)(ent + 0x14C), 2);
            func_0047a180(*(s32*)(p + 0x164), (u8*)&vCopy, 2);
            q = func_0047a2f0(*(s32*)(p + 0x164));
            *(Vec3f*)((u8*)q + 0x30) = *(Vec3f*)(ent + 0x140);
            func_003e0380(&m3.x);
            func_003e03e0(func_0047a2f0(*(s32*)(p + 0x164)), &m3.x);
            func_003e05d0(func_0047a2f0(*(s32*)(p + 0x164)));
            if (*(s32*)(p + 0x22C) != 0) {
                f32 f = func_00168770(*(s32*)(p + 0x228));
                vS.x = f;
                vS.y = f;
                vS.z = f;
                func_0047a1a0(*(s32*)(p + 0x22C), &stk64, *(f32*)(ent + 0x14C), 2);
                func_0047a1e0(*(s32*)(p + 0x22C), &vS, 2);
                func_0047a180(*(s32*)(p + 0x22C), ent + 0x140, 2);
                func_00478e70(*(s32*)(p + 0x22C));
            }
        }
        break;
    }
    case 10: {
        u8* p = func_00145270(v0 & 0xFFFF);
        if (p != NULL) {
            void* q = func_0047a2f0(*(s32*)(p + 0x144));
            vCopy = *(Vec3f*)((u8*)q + 0x30);
            vNeg.x = -1.0f * vCopy.x;
            vNeg.y = -1.0f * vCopy.y;
            vNeg.z = -1.0f * vCopy.z;
            func_0047a180(*(s32*)(p + 0x144), (u8*)&vNeg, 2);
            func_0047a1a0(*(s32*)(p + 0x144), &stk64, *(f32*)(ent + 0x14C), 0);
            func_0047a180(*(s32*)(p + 0x144), (u8*)&vCopy, 2);
            q = func_0047a2f0(*(s32*)(p + 0x144));
            *(Vec3f*)((u8*)q + 0x30) = *(Vec3f*)(ent + 0x140);
            func_003e0380(&m10.x);
            func_003e03e0(func_0047a2f0(*(s32*)(p + 0x144)), &m10.x);
            func_003e05d0(func_0047a2f0(*(s32*)(p + 0x144)));
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x337);
        break;
    }
    return 1;
}

