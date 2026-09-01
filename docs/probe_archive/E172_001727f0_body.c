/* measured: object_size=944 bytes, retail_window=944 bytes, normalized_diff=577, first differing offsets=0,4,8,10,12,14,16,18,20,22,24,26,27,28,30,31; declarations corrected in candidate: func_001452b0(s32) -> u8 *, func_00452490(void *), func_0018e030(u8 *, s32), func_0029db50(s32,s32,s32,s32), func_00182310(s32), func_001560a0(u8 *,s16,s16,s16), func_0047a0e0(u8 *,s32,f32); body retained for future reconstruction. */
/* func_001727F0 candidate declarations */
typedef s32 P4_UNK;
typedef s8 P4_UNK8;
typedef s16 P4_UNK16;
typedef s32 P4_UNK32;
typedef s64 P4_UNK64;
#define P4_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define P4_BITWISE(type, expr) ((type)(expr))
#define P4_LWL(expr) (expr)
#define P4_FIRST3BYTES(expr) (expr)
#define P4_UNALIGNED32(expr) (expr)
#define P4_CARRY 0
#define P4_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define P4_55280() ((u8 *)(u32)func_00155280())

void func_002bd3c0(void);
void func_002bd410(void);

// FUN_001727F0
s32 func_001727f0(u8 *arg0) {
    u8 *func_001452b0(s32);
    void func_001560a0(u8 *, s16, s16, s16);
    void func_00182310(s32);
    void func_0018e030(u8 *, s32);
    s32 func_0029db50(s32, s32, s32, s32);
    s32 func_00452490(void *);
    void func_0047a0e0(u8 *, s32, f32);
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    s32 *temp_18;
    s32 *temp_19;
    s32 temp_17_2;
    s32 temp_3;
    u16 temp_17;
    u8 *temp_16;
    u8 *temp_17_3;
    u8 *temp_18_2;
    u8 *var_18;

    temp_16 = (u8 *)(P4_FIELD(arg0, u8 **, 0x38));
    temp_3 = (s32)(P4_FIELD(temp_16, s32 *, 4));
    switch (temp_3) {                               /* irregular */
    case 0:
        temp_4 = (u8 *)(P4_FIELD(P4_55280(), u8 **, 0x18DC));
        if (P4_FIELD((((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + temp_4), u16 *, 0x10) == 0xFFFF) {
            P4_FIELD(temp_16, u8 **, 0x1C) = NULL;
            if (P4_FIELD((((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + P4_FIELD(P4_55280(), s32 *, 0x18DC)), u16 *, 0x18) != 0) {
                P4_FIELD(temp_16, u8 **, 0x1C) = (u8 *)(func_001452b0(0xA));
loop_11:
                var_18 = (u8 *)(P4_FIELD(temp_16, u8 **, 0x1C));
                if (var_18 != NULL) {
                    var_18 = (u8 *)(P4_FIELD(temp_16, u8 **, 0x1C));
                    temp_17 = (u16)(P4_FIELD(var_18, u16 *, 0));
                    if (temp_17 != P4_FIELD((P4_FIELD(P4_55280(), s32 *, 0x18DC) + ((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C)), u16 *, 0x18)) {
                        P4_FIELD(temp_16, u8 **, 0x1C) = (u8 *) P4_FIELD(var_18, u8 **, 0x138);
                        goto loop_11;
                    }
                }
                if (var_18 != NULL) {
                    func_0047a0e0(P4_FIELD(var_18, u8 **, 0x144), 0, 0x3F800000);
                    func_00479940(P4_FIELD(P4_FIELD(temp_16, u8 **, 0x1C), s32 *, 0x144), 0, P4_FIELD((((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + P4_FIELD(P4_55280(), s32 *, 0x18DC)), s16 *, 0x1A), 0U, 0);
                }
            } else {
                P4_FIELD(temp_16, u8 **, 0x1C) = NULL;
            }
            P4_FIELD(temp_16, s32 *, 4) = 1;
        } else {
            func_002bd410();
            func_002bd3c0();
            func_0018e030(P4_FIELD(P4_55280(), u8 **, 0x1C), 1);
            temp_18 = (s32 *)P4_55280();
            temp_17_2 = P4_FIELD(P4_55280(), s32 *, 0x1858);
            P4_FIELD(temp_16, s32 *, 0x10) = func_0029db50(0xF, P4_FIELD(temp_18, s32 *, 0x1854), temp_17_2, (s32) P4_FIELD((((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + P4_FIELD(P4_55280(), s32 *, 0x18DC)), u16 *, 0x10));
            P4_FIELD(temp_16, s32 *, 4) = 3;
        }
        func_00182310(1);
block_22:
    default:
        return 1;
    case 1:
        temp_19 = (s32 *)P4_55280();
        temp_4_2 = (u8 *)(P4_FIELD(P4_55280(), u8 **, 0x18DC));
        temp_18_2 = (u8 *)(((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + temp_4_2);
        temp_4_3 = (u8 *)(P4_FIELD(P4_55280(), u8 **, 0x18DC));
        temp_17_3 = (u8 *)(((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + temp_4_3);
        func_001560a0((u8 *)(u32)*temp_19, P4_FIELD(temp_18_2, u16 *, 0x12), P4_FIELD(temp_17_3, u16 *, 0x14), P4_FIELD((((P4_FIELD(temp_16, u16 *, 0x2C) & 0x3FF) * 0x2C) + P4_FIELD(P4_55280(), s32 *, 0x18DC)), u16 *, 0x16));
        P4_FIELD(temp_16, s32 *, 0x10) = 0;
        P4_FIELD(temp_16, s32 *, 4) = 2;
        goto block_22;
    case 3:
        if (func_00452490((void *)(u32)P4_FIELD(temp_16, s32 *, 0x10)) != 1) {
            func_0018e030(P4_FIELD(P4_55280(), u8 **, 0x1C), 0);
            func_00182310(0);
            P4_FIELD(temp_16, s32 *, 0x10) = 0;
            P4_FIELD(temp_16, s32 *, 4) = 4;
        case 4:
            return 0;
        }
        goto block_22;
    }
}
#undef P4_55280
#undef P4_BITWISE
#undef P4_LWL
#undef P4_FIRST3BYTES
#undef P4_UNALIGNED32
#undef P4_CARRY
#undef P4_OVERFLOW
#undef MULT_HI
#undef MULTU_HI
#undef CLZ
