// func_001b3a00 (0x001b3a00-0x001b3f00, 1280B) — guarded floor @259fndiff/1272B (8B under; frame/saves agree).
// Wins: tb-recompute (killed s4, frame match); DN-goto 0x80-gate (-7); st==2 retsw-skip (correctness);
// beq st-dispatch; u16 counters; div; full call coverage (9 new decls); GPREL relocs.
// Walls: GPREL-vs-immediate phantoms (~15); c1/c2 swap neutral; return-switch bne-vs-beq;
// DN-goto scaffolding (+2); list-loop rotation; st==1 id-check at-temp.
// Unattempted before (no prior note). Production stays ASM.
s32 func_001b3a00(void)
{
    u16 st;
    s64 *pp;
    u16 fl;
    u8 *lst;
    u32 c1;
    u32 c2;
    u16 id;
    u8 *u;

    if ((*(s32 *)((u8 *)iGpffffb3ac +  12) & 0x80) != 0) {
        func_001b1830();
        goto body;
    } else {
        return 0;
    }
body:
    func_00213b80(*(u8 **)((u8 *)iGpffffb3ac +  3540));
    func_00212240(*(u8 **)((u8 *)iGpffffb3ac +  3540), 0);
    st = *(u16 *)((u8 *)iGpffffb3ac +  28);
    if (st == 2) {
        goto retsw;
    } else if (st == 3) {
        func_0043f9c8((u8 *)iGpffffb3ac +  3244, 0, 88);
        *(s32 *)((u8 *)iGpffffb3ac +  12) = *(s32 *)((u8 *)iGpffffb3ac +  12) & 0xDFFFFFFF;
    } else if (st == 1) {
        id = *(u16 *)((u8 *)iGpffffb3ac +  3172);
        if ((s32)id < 3) {
            u32 present = *(u32 *)((u8 *)iGpffffb3ac +  (id & 0xFFFF) * 4 + 3204);
            if (present != 0) {
                *(s32 *)((u8 *)iGpffffb3ac +  12) = *(s32 *)((u8 *)iGpffffb3ac +  12) | 0x20000000;
                return 11;
            }
        }
        *(s32 *)((u8 *)iGpffffb3ac +  12) = *(s32 *)((u8 *)iGpffffb3ac +  12) & 0xDFFFFFFF;
    } else {
        return 0;
    }
st2:
    pp = (s64 *)func_001b1510();
    {
        s32 has = 0;
        if (pp != NULL) {
            fl = *(u16 *)((u8 *)pp + 110);
            if (fl == 0x102 || fl == 0x101 || fl == 0x100) {
                *(u16 *)((u8 *)iGpffffb3ac +  3244) = *(u16 *)((u8 *)iGpffffb3ac +  3244) | 2;
                has = 1;
            }
        }
        c1 = 0;
        c2 = 0;
        lst = *(u8 **)((u8 *)iGpffffb3ac +  380);
        while (lst != NULL) {
            if (func_002428f0(*(s32 *)(lst + 2660), 0) != 0) {
                c1 = (c1 + 1) & 0xFFFF;
            } else {
                *(u16 *)((u8 *)iGpffffb3ac +  (c2 & 0xFFFF) * 2 + 3262) = *(u16 *)(*(s32 *)(lst + 2660) + 2);
                c2 = (c2 + 1) & 0xFFFF;
                c1 = (c1 + 1) & 0xFFFF;
            }
            lst = *(u8 **)(lst + 2664);
        }
        *(s32 *)((u8 *)iGpffffb3ac +  3276) = c1 & 0xFFFF;
        *(s32 *)((u8 *)iGpffffb3ac +  3272) = c2 & 0xFFFF;
        {
            u16 dv = *(u16 *)((u8 *)iGpffffb3ac +  3162);
            *(s32 *)((u8 *)iGpffffb3ac +  3304) = dv;
            if ((s32)*(u16 *)((u8 *)iGpffffb3ac +  3162) > 0) {
                *(s32 *)((u8 *)iGpffffb3ac +  3300) = *(s32 *)((u8 *)iGpffffb3ac +  3300) / (s32)*(u16 *)((u8 *)iGpffffb3ac +  3162);
            }
        }
        if (*(u16 *)((u8 *)iGpffffb3ac +  28) != 3 && func_001ef7e0((u8 *)pp) != 0) {
            if (func_0036ee60((u8 *)iGpffffb3ac +  3316, *(s16 *)((u8 *)iGpffffb3ac +  3300), has) != 0) {
                *(u16 *)((u8 *)iGpffffb3ac +  3244) = *(u16 *)((u8 *)iGpffffb3ac +  3244) | 1;
            }
        }
        if (func_0022bd20() != 0) {
            *(u16 *)((u8 *)iGpffffb3ac +  3244) = *(u16 *)((u8 *)iGpffffb3ac +  3244) | 8;
        }
        *(s32 *)((u8 *)iGpffffb3ac +  3256) = func_001ef9a0();
        {
            s32 ix = func_001ef9a0();
            if ((*(u8 *)(*(s32 *)(iGpffffb3ac + -0x4BEC) + ix * 24) & 0x20) != 0) {
                s16 d = *(s16 *)((u8 *)iGpffffb3ac +  3296) - (s16)func_00231e20(*(s32 *)(*(u8 **)(*(u8 **)((u8 *)iGpffffb3ac +  368) + 48) + 2660));
                if (d < 0) {
                    d = 0;
                } else if (d >= 6) {
                    d = 5;
                }
                *(s16 *)((u8 *)iGpffffb3ac +  3260) = *(u8 *)(*(s32 *)(iGpffffb3ac + -0x4BF0) + d);
            }
        }
        lst = *(u8 **)((u8 *)iGpffffb3ac +  380);
        while (lst != NULL) {
            {
                u16 *q = *(u16 **)(lst + 2660);
                if (q != NULL) {
                    s32 f = func_002326e0((s32)q);
                    func_002326f0((s32)q, 0xFFF7FFFF);
                    if ((f & 0x100000) == 0) {
                        func_00198dd0(lst, 6);
                    }
                }
            }
            lst = *(u8 **)(lst + 2664);
        }
        if ((*(u16 *)((u8 *)iGpffffb3ac +  3244) & 1) != 0 && (*(s32 *)((u8 *)iGpffffb3ac +  12) & 0x20000000) == 0) {
            func_002138a0(*(u8 **)((u8 *)iGpffffb3ac +  3540));
        }
        *(s32 *)((u8 *)iGpffffb3ac +  3536) = func_0021d980(*(s32 *)((u8 *)iGpffffb3ac +  3528), (u8 *)iGpffffb3ac + 3244);
        func_0021dab0(*(s32 *)((u8 *)iGpffffb3ac +  3536));
retsw:
        st = *(u16 *)((u8 *)iGpffffb3ac +  28);
        if (st == 1) {
            if ((*(s32 *)((u8 *)iGpffffb3ac +  16) & 2) != 0) {
                return 12;
            }
            return 11;
        } else if (st == 2) {
            if ((*(s32 *)((u8 *)iGpffffb3ac +  16) & 0x20000000) != 0) {
                return 12;
            }
            if (func_00193260((u8 *)iGpffffb3ac) != 0) {
                return 9;
            }
            return 13;
        }
        return 14;
    }
}
