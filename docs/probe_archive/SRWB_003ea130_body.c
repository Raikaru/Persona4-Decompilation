object 388B / window 400B / normalized_diff 29 (callback-2-arg macro-state probe, measured before later schedule-off probe); differing offsets: 168,172,180-216,240-260,252-260 (17 differing words reloc-masked); instruction deficit 3 instructions / tail size short 12B; classification UNDERSIZED / loop address-register and callback materialization mismatch; ruled out: generated M2C body wholesale, direct absolute-array state expressions, typed State pointer (oversized 368B? frame 0x40), macro State fields (frame exact 0x30), callback 3-argument and callback 2-argument forms, explicit next temporary (compiler optimized same), no_branch_likely on. Retail prologue frame 0x30, saves s0/s1 (2), one arg a0 (s1); declarations corrected at block scope for func_003e12f0 old-style and iGpffffb7cc; State fields 0x210/0x214/0x218/0x21c and callback table local. Schedule-off follow-up was not measured because a sibling live body func_0040a500 caused compile syntax errors at line 1789.

Candidate body:
s32 func_003ea130(s32 arg0)
{
    typedef struct { u8 pad[0x210]; s32 field_210; s32 field_214; s32 field_218; s32 field_21c; } State;
    extern void func_003e12f0();
    extern s32 iGpffffb7cc;
    s32 *node;
    s32 *next;
    void (**callbacks)(s32 arg0, void *arg1);
#define STATE ((State *)((u8 *)D_008872E0 + iGpffffb7c8))
    if (STATE->field_210 != 0) {
        jtbl_008873EC[0]((void *)STATE->field_210);
        STATE->field_210 = 0;
        STATE->field_214 = 0;
    }
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 4) != 0) {
        jtbl_008873EC[0](*(void **)((u8 *)D_008872E0 + iGpffffb7c8 + 4));
        *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 4) = 0;
        *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 8) = 0;
    }
    node = (s32 *)STATE->field_21c;
    if (node != NULL) {
        callbacks = (void (**)(s32, void *))(void *)jtbl_008873FC;
        do {
            next = *(s32 **)((u8 *)node + 0x30);
            STATE->field_21c = (s32)next;
            callbacks[0](STATE->field_218, (void *)node);
            node = (s32 *)STATE->field_21c;
        } while (node != NULL);
    }
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218) != 0) {
        func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218));
        *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8 + 0x218) = 0;
    }
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) != 0) {
        func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb7c8));
        *(s32 *)((u8 *)D_008872E0 + iGpffffb7c8) = 0;
    }
    iGpffffb7cc -= 1;
    return arg0;
}
