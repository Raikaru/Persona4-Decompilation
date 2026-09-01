s32 func_0029e040(u8 *arg0) {
    ScrTaskData *task = *(ScrTaskData **)(arg0 + 0x38);
    s32 i;
    s32 count;
    u8 *entry;
    u8 *found;
    f32 f;
    if (func_004680f0(*(s32 *)(task + 4), (u8 *)task + 0x10) != 1) return 0;
    switch (task->unk_0C) {
    case 0:
        if (*(s8 *)((u8 *)task + 0x10) == 0) return 1;
        func_00442830((u8 *)task + 0x110, (u8 *)task + 0x10 + func_00442948(D_0063E5F0));
        func_00440b68((char *)((u8 *)arg0 - 0x5830), D_0063E3D0, 0x417);
        task->unk_210 = func_00454a60((u8 *)task + 0x110, 0);
        task->unk_0C = 1;
        return 0;
    case 1:
        if (func_004553c0(task->unk_210)) {
            task->unk_224 = func_00455f70((u8 *)task + 0x110, &count);
            task->unk_0C = 2; task->unk_218 = 0; task->unk_21C = 30.0f; task->unk_220 = 8.0f;
        }
        return 0;
    case 2:
        if (D_008C0256 & 0x1000) { f=task->unk_220; if (!(f<2.0f)) task->unk_220=f-1.0f; }
        if (D_008C0256 & 0x4000) { f=task->unk_220; if (f<30.0f) task->unk_220=f+1.0f; }
        if (D_008C0256 & 0x8000) { f=task->unk_21C; if (!(f<2.0f)) task->unk_21C=f-1.0f; }
        if (D_008C0256 & 0x2000) { f=task->unk_21C; if (f<45.0f) task->unk_21C=f+1.0f; }
        if (D_008C0252 & 0x4000) task->unk_218++; else if (D_008C0252 & 0x1000) task->unk_218--;
        if (D_008C024E & 0x40) { task->unk_0C=3; goto select; }
        if (D_008C024E & 0x20) return 2;
select:
        entry=task->unk_224; found=0; count=0;
        if (entry) { u8 *q=entry+0x20; for(i=0;i<*(s32 *)(entry+0x10);i++,q+=0x10) if (*(s32 *)q==0) {found=entry+*(s32 *)(q+0xC); break;} if(found) count=*(s32 *)(q+8); }
        if (task->unk_218<0) task->unk_218=0; else if (task->unk_218>=count) task->unk_218=count-1;
        func_00450050((s64)task->unk_21C, D_0063E580, task->unk_218, func_0029df30(task->unk_224,task->unk_218,entry));
        func_0045d6e0(&task->unk_21C, &D_0063E5E0, 1, 0); return 0;
    case 3:
        task->unk_214=func_0029d660(task->unk_224,task->unk_218); if(!task->unk_214) func_0046d730(D_0063E3D0,0x44C); task->unk_0C=4; task->state|=1; return 0;
    case 4:
        if (func_0029cb00(task->unk_214,1)==1) { func_0046d740(D_0063E520,D_0063E3D0,0x457); task->state&=~1; return 1; }
        if (func_0029cb00(task->unk_214,1)==2) { task->state&=~1; return 1; }
    }
    return 0;
}
