// Best body for func_0029e040 @0x0029e040 window 1296B
// probe clean_v1: obj 1216/1296 nd 865 MISMATCH (honest ScrTaskData/state switch 0..4, lb s8, 30.0f/8.0f/2.0f/1.0f/45.0f/12.0f via lui, lq D_0063E5E0 + cvt.w.s pair, s64 ldr/ldl, no pragma)
// Status: ASM retained; archived per nd>25 gate (nd 865 >> 25, obj -80B). Do NOT touch other funcs in scrScriptProcess.c.
// Notes: obj -80B short; frame 0x50 vs retail 0x60 (-16B); D_008C0256/0252/024E via GPREL lhu vs retail lui+lhu (each -4B, ~6 loads); switch dispatch order 4/3/2/1/0 matches but early func_004680f0 check polarity beq vs retail bne; float clamp blocks c.lt.s+bc1t/bc1f match (>= for sub, < for add); index search while+break matches but regs $t0/$t1 vs $8/$3; vector block single flt store vs retail dual swc1 0x54/0x58; first diffs word [0,4,8,10,12,14,15,16,18,19,20,22,23,28,29,30], differing words 289 reloc-masked. Prior file note nd891/obj1300 retained in source.
// Retail shape covered: case0 lb 0x10 + 00442948/00442830/00440b68(&iGpffffa7d0)/00454a60; case1 004553c0/00455f70 + 30.0f/8.0f; case2 0256x4 + 0252 inc/dec + 024E 0x40->3 /0x20->ret2 + entry+0x20 stride-0x10 search + 0x218 clamp + 0029df30 + s64 ldr/ldl 0x21C + 00450050(&iGpffffa7d8) + lq D_0063E5E0 + 12.0f mul + cvt.w.s + 0045d6e0(&flt,&v1,0.0f,1); case3 0029d660; case4 0029cb00 single-arg switch (2->clear+ret1, 1->ret0, 0->log+clear+ret1).
s32 func_0029e040(u8 *arg0)
{
    ScrTaskData *task;
    u8 *entry;
    u8 *found;
    u8 *ptr;
    s32 count;
    s32 i;
    f32 f;
    ScrE040Vec4 v0;
    ScrE040Vec4 v1;
    f32 flt;
    s32 out;

    task = *(ScrTaskData **)(arg0 + 0x38);
    if (func_004680f0(task->unk_04, task->text) != 1) {
        return 0;
    }
    switch (task->state) {
    case 0:
        if (*(s8 *)task->text == 0) {
            return 1;
        }
        func_00442830(task->text + 0x100, task->text + func_00442948(D_0063E5F0));
        func_00440b68(&iGpffffa7d0, D_0063E3D0, 0x417);
        task->unk_210 = func_00454a60(task->text + 0x100, 0);
        task->state = 1;
        break;
    case 1:
        if (func_004553c0(task->unk_210) != 0) {
            task->unk_224 = (s32)func_00455f70(task->text + 0x100, &out);
            task->state = 2;
            task->unk_218 = 0;
            task->unk_21C = 30.0f;
            task->unk_220 = 8.0f;
        }
        break;
    case 2:
        if (D_008C0256 & 0x1000) {
            f = task->unk_220;
            if (f >= 2.0f) {
                task->unk_220 = f - 1.0f;
            }
        }
        if (D_008C0256 & 0x4000) {
            f = task->unk_220;
            if (f < 30.0f) {
                task->unk_220 = f + 1.0f;
            }
        }
        if (D_008C0256 & 0x8000) {
            f = task->unk_21C;
            if (f >= 2.0f) {
                task->unk_21C = f - 1.0f;
            }
        }
        if (D_008C0256 & 0x2000) {
            f = task->unk_21C;
            if (f < 45.0f) {
                task->unk_21C = f + 1.0f;
            }
        }
        if (D_008C0252 & 0x4000) {
            task->unk_218++;
        } else if (D_008C0252 & 0x1000) {
            task->unk_218--;
        }
        if (D_008C024E & 0x40) {
            task->state = 3;
        } else if (D_008C024E & 0x20) {
            return 2;
        }
        entry = (u8 *)task->unk_224;
        found = NULL;
        count = 0;
        if (entry != NULL) {
            u8 *q;
            s32 n;

            q = entry + 0x20;
            n = *(s32 *)(entry + 0x10);
            i = 0;
            while (i < n) {
                u8 *e;

                e = q + i * 16;
                if (*(s32 *)e == 0) {
                    found = entry + *(s32 *)(e + 0xC);
                    break;
                }
                i++;
            }
            if (found != NULL) {
                count = *(s32 *)(q + i * 16 + 8);
            }
        }
        if (task->unk_218 < 0) {
            task->unk_218 = 0;
        } else if (task->unk_218 >= count) {
            task->unk_218 = count - 1;
        }
        ptr = func_0029df30(entry, task->unk_218);
        func_00450050(*(s64 *)&task->unk_21C, &iGpffffa7d8, task->unk_218, ptr);
        flt = iGpffffa7cc;
        v0 = D_0063E5E0;
        v0.a = (s32)(12.0f * task->unk_21C);
        v0.b = (s32)(12.0f * task->unk_220);
        v1 = v0;
        func_0045d6e0(&flt, &v1, 0.0f, 1);
        break;
    case 3:
        task->unk_214 = (s32)func_0029d660((ScrHeader *)task->unk_224, task->unk_218);
        if (task->unk_214 == 0) {
            func_0046d730(D_0063E3D0, 0x44C);
        }
        task->state = 4;
        task->flags |= 1;
        break;
    case 4:
        {
            s32 ret;

            ret = func_0029cb00((void *)task->unk_214);
            if (ret == 2) {
                task->flags &= ~1;
                return 1;
            }
            if (ret == 1) {
                break;
            }
            if (ret == 0) {
                func_0046d740(D_0063E520, D_0063E3D0, 0x457);
                task->flags &= ~1;
                return 1;
            }
        }
        break;
    }
    return 0;
}
