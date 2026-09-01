/* object 780 / window 784 / normalized_diff 252; differing offsets: 93, 109, 114, 118, 126, 150, 154, 166, 177, 182, 202, 230, 238, 246, 250, 282 */
/* Corrected callee signatures verified against MATCH definitions:
 * func_00487ba0(u8 *, s32 *);
 * func_00487860(u8 *, s32 *);
 * func_00487a30(u8 *, void *);
 * func_00487650(u8 *, s32, s32);
 * func_0046d730(void *, s32);
 * func_00484490(int).
 * Retail saved-register mapping: arg0=$s0; func_00484490 result=$s4;
 * count=$s3; allocator base=$s1; first allocation result=$s2;
 * second allocation result=$s1; func_004844d0 result=$s3.
 */
// FUN_00486B00
 typedef s32 EP_WORD;
 #define EP_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
 EP_WORD *func_00486b00(u8 *arg0)
 {
    u8 *arg0_p = arg0;
    u8 *temp_2_2;
    u32 base;
    s32 temp_3;
    u32 var_19;
    EP_WORD *temp_2;
    EP_WORD *temp_2_5;
    s32 *temp_2_3;
    temp_2_2 = (u8 *)func_00484490((int)arg0_p);
    if (NULL == temp_2_2) {
        func_0046d730(D_00713CD0, 0x55);
    }
    temp_3 = (s32)(EP_FIELD(temp_2_2, s32 *, 0x20));
    if (temp_3 == 0) {
        var_19 = (u32)(EP_FIELD(temp_2_2, s32 *, 0xB8) * EP_FIELD(temp_2_2, s32 *, 0x24));
    } else {
        var_19 = (u32)(temp_3 * EP_FIELD(temp_2_2, s32 *, 0x24));
    }
    if (var_19 >= 0x12DU) var_19 = 0x12C;
    func_0044ea90(D_00713CC0, 0x171);
    base = (u32)jtbl_008873E8;
    temp_2 = (EP_WORD *)(*(void *(*)(u32, u32))*(u32 *)base)(0x60, 0x40000);
    func_0043f9c8(temp_2, 0, 0x60);
    if (temp_2 == NULL) func_0046d730(D_00713CD0, 0x1F);
    EP_FIELD(temp_2, EP_WORD **, 0) = (EP_WORD *)var_19;
    EP_FIELD(temp_2, s32 *, 4) = -1;
    EP_FIELD(temp_2, s32 *, 8) = 0x3F800000;
    if (temp_2 == NULL) func_0046d730(D_00713CD0, 0x57);
    func_004875d0((u8 *)temp_2, EP_FIELD(arg0, u16 *, 0xC), temp_2_2);
    if (EP_FIELD(temp_2, EP_WORD **, 0) == NULL) return temp_2;
    temp_2_3 = (s32 *)func_004844d0((int)arg0_p);
    if (temp_2_3 != NULL) {
        switch ((u16)(EP_FIELD(arg0_p, u16 *, 0x1C))) {
        case 1:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 1);
            func_004877b0((u8 *)temp_2, (s32)temp_2_3); break;
        case 2:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 2);
            func_00487860((u8 *)temp_2, temp_2_3); break;
        case 4:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 4);
            func_00487710((u8 *)temp_2, *temp_2_3); break;
        case 5: func_004878c0((u8 *)temp_2, temp_2_3); break;
        case 6: func_00487a30((u8 *)temp_2, temp_2_3); break;
        case 7:
            func_00487650((u8 *)temp_2, EP_FIELD(EP_FIELD(temp_2, u8 **, 0x4C), s32 *, 8), 7);
            func_00487ba0((u8 *)temp_2, temp_2_3);
            func_0044ea90(D_00713CC0, 0x171);
            temp_2_5 = (EP_WORD *)(*(void *(*)(u32, u32))*(u32 *)base)(0x30, 0x40000);
            func_0043f9c8(temp_2_5, 0, 0x30);
            EP_FIELD(temp_2_5, s16 *, 0x18) = 0x19;
            EP_FIELD(temp_2, EP_WORD **, 0x5C) = (EP_WORD *)temp_2_5;
            EP_FIELD(EP_FIELD(temp_2, EP_WORD **, 0x5C), EP_WORD **, 0x1C) = (EP_WORD *)temp_2;
            break;
        default: func_0046d730(D_00713CD0, 0x7E); break;
        }
        EP_FIELD(temp_2, u16 *, 0xC) = (u16)EP_FIELD(arg0_p, u16 *, 0x1C);
    }
    return temp_2;
 }
