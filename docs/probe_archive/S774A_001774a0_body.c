s32 func_001774a0(void)
{
    s32 v = func_0029cc00(0);
    s32 id = func_0029cc00(1);
    u8* s2 = func_001452b0(14);
    s64 cfg = D_005F1868[0];
    f32 cfgf = D_005F1870[0];
    if (s2 == 0)
        func_0046d730(D_005F1858, 707);
    while (s2 != 0 && (*(u16*)s2 & 0x3ff) != id)
        s2 = *(u8**)(s2 + 312);
    switch ((v & 0xffc00) >> 10)
    {
    case 1:
    {
        u8* p = func_00145270(v & 0xffff);
        if (p != 0) {
            s32 obj = *(s32*)(p + 356);
            u8* q = func_0047a2f0(obj);
            f32 a[3] = {*(f32*)(q+48), *(f32*)(q+52), *(f32*)(q+56)};
            f32 neg[3] = {-a[0], -a[1], -a[2]};
            func_0047a180(obj, (u8*)neg, 2);
            func_0047a1a0(obj, (u8*)&cfg, 0, *(f32*)(s2+332));
            func_0047a180(obj, (u8*)a, 2);
            q = func_0047a2f0(obj);
            *(f32*)(q+48)=*(f32*)(s2+320); *(f32*)(q+52)=*(f32*)(s2+324); *(f32*)(q+56)=*(f32*)(s2+328);
            { f32 m[16]; func_003e0380(m); func_003e03e0(func_0047a2f0(obj), m); func_003e05d0(func_0047a2f0(obj)); }
            func_00168c00(*(s32*)(p+544)); func_0015bae0();
            for (s32 i=0;i<3;i++) { s32 x=0; u8* r=D_007EF9B0 + i*1872; if (*(s32*)(r+1944)!=0 && *(s32*)(r+1956)!=0) x=1; if (x && *(s32*)(r+2304)!=0) func_0017e9b0(*(s32*)(r+2304)); }
            u8* t=func_00155280(); if (*(s32*)(t+4)!=0) func_0016ec90(*(s32*)(func_00155280()+4));
        }
        break;
    }
    case 2: break;
    case 3:
    {
        u8* p=func_00145270(v&0xffff); if(p!=0){s32 obj=*(s32*)(p+356);u8*q=func_0047a2f0(obj);f32 a[3]={*(f32*)(q+48),*(f32*)(q+52),*(f32*)(q+56)};f32 neg[3]={-a[0],-a[1],-a[2]};func_0047a180(obj,(u8*)neg,2);func_0047a1a0(obj,(u8*)&cfg,2,*(f32*)(s2+332));func_0047a180(obj,(u8*)a,2);q=func_0047a2f0(obj);*(f32*)(q+48)=*(f32*)(s2+320);*(f32*)(q+52)=*(f32*)(s2+324);*(f32*)(q+56)=*(f32*)(s2+328);{f32 m[16];func_003e0380(m);func_003e03e0(func_0047a2f0(obj),m);func_003e05d0(func_0047a2f0(obj));} if(*(s32*)(p+556)){f32 z=func_00168770(*(s32*)(p+552));f32 zz[3]={z,z,z};func_0047a1a0(*(s32*)(p+556),(u8*)&cfg,2,*(f32*)(s2+332));func_0047a1e0(*(s32*)(p+556),zz,2);func_0047a180(*(s32*)(p+556),s2+320,2);func_00478e70(*(s32*)(p+556));}}
        break;
    }
    case 4: case 5: case 6: case 7: case 8: case 9: break;
    case 10:
    {
        u8* p=func_00145270(v&0xffff); if(p!=0){s32 obj=*(s32*)(p+324);u8*q=func_0047a2f0(obj);f32 a[3]={*(f32*)(q+48),*(f32*)(q+52),*(f32*)(q+56)};f32 neg[3]={-a[0],-a[1],-a[2]};func_0047a180(obj,(u8*)neg,2);func_0047a1a0(obj,(u8*)&cfg,0,*(f32*)(s2+332));func_0047a180(obj,(u8*)a,2);q=func_0047a2f0(obj);*(f32*)(q+48)=*(f32*)(s2+320);*(f32*)(q+52)=*(f32*)(s2+324);*(f32*)(q+56)=*(f32*)(s2+328);{f32 m[16];func_003e0380(m);func_003e03e0(func_0047a2f0(obj),m);func_003e05d0(func_0047a2f0(obj));}}
        break;
    }
    default: func_0046d730(D_005F1858,823); break;
    }
    return 1;
}
