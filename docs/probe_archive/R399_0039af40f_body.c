/* object 300 / window 320 / normalized_diff 167; differing offsets 0x48-0x13c; undersized 20 bytes: frame/saved-register prologue exact, but count guard stores/reloads and loop call/index scheduling differ; classification branch layout, call materialisation, magic-division scheduling; ruled out separate locals (object 192), aggregate without address locals (228), and schedule-off (332). */
s32 func_0039af40(s32 arg0, s32 unused, s32 arg2)
{
    struct Item { s32 value0; s32 value1; s32 value2; f32 value; s32 index; };
    s32 count, i, offset, temp, delta;
    u8 *base, *records;
    struct Item item;
    s32 *p_value1, *p_value2, *p_index;
    f32 *p_value;
    extern s32 func_003e2ab0();
    base = (u8 *)(arg2 + iGpffffb5f0);
    count = *(s32 *)base;
    count = func_003df240(arg0, &count, 4);
    if (count == 0) goto return_zero;
    if (count > 0) goto setup;
return_arg: return arg0;
return_zero: return 0;
setup:
    i = 0; offset = 0; p_value1=&item.value1; p_value2=&item.value2; p_value=&item.value; p_index=&item.index;
loop:
    records=*(u8 **)(base+8); item.value0=*(s32 *)(records+offset);
    *p_value1=(s32)*(s16 *)(records+offset+4); *p_value2=(s32)*(s16 *)(records+offset+6);
    *p_value=*(f32 *)(records+offset+8); temp=*(s32 *)(records+offset+0x10); delta=temp-(s32)records;
    *p_index=(delta/20)+((u32)delta>>31);
    if(func_003e2ab0(arg0,&item,0x14)==0) return 0;
    i+=1; offset+=0x14; if(i<count) goto loop; goto return_arg;
}
