/* object 192B/window 160B/normalized_diff 147; differing offsets 16-20,22-24,26-...; classification OVERSIZED; frame is exact (-0x150) and no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed. Residual is branch/body layout and initial remaining-register use (candidate emits an extra branch and tests $a2 instead of retail's preloaded $s1); archived immediately before restoring. */
s32 func_003df1a0(s32 arg0, u8 *arg1, s32 arg2) {
    extern void func_0043f810(void *dst, const void *src, u32 size); extern s32 func_003e2ab0(s32,void*,s32);
    u8 buffer[256]; u8 *cursor; s32 remaining; s32 chunk;
    cursor=arg1; remaining=arg2; if(remaining!=0){ loop: if((u32)remaining<0x100U) chunk=remaining; else chunk=0x100; func_0043f810(buffer,cursor,chunk); if(func_003e2ab0(arg0,buffer,chunk)!=0){remaining-=chunk; if(remaining!=0){cursor+=chunk;goto loop;}} else return 0;} return arg0;
}
