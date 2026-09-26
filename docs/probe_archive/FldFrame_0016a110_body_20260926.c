// FUN_0016A110
#pragma push
#pragma opt_loop_invariants on
s32 func_0016a110(s32 collisionWorld, f32 *origin, f32 *vector, f32 fraction, s32 fieldId)
{
    extern void *mdlGetClump(void *model);
    extern f32 RwV3dLength(f32 *vec);
    extern u8 D_007E8020[];
    extern f32 fGpffff82b8;
    extern u32 func_0016b480(void *cw, const RwV3d *line, RwV3d *hit);
    typedef struct FldFrameWork6A110
    {
        RwV3d points[64];
        RwV3d normals[64];
        f32 fracs[64];
        RwV3d extra[64];
        s32 flags[64];
        s32 mode;
        s32 count;
        s32 hitCount;
        RwV3d normDir;
        u8 scratch[0x20];
        u8 zero[0x18];
        f32 input[4];
        union
        {
            u_long128 bits;
            f32 f[4];
        } copy;
        u8 tail[8];
        s32 type;
    } FldFrameWork6A110;
    f32 qy;
    f32 neg;
    RwV3d hit;
    s32 k;
    u8 *entry;
    s32 allHit;
    s32 i;
    f32 scale;
    RwV3d delta;
    FldFrameWork6A110 work;
    s32 result;
    RwV3d scaled;
    u8 *list10;
    u8 *list3;
    RwV3d line[2];
    s32 m;
    f32 qz;
    f32 qfrac;
    f32 dot;
    s32 n;
    s32 j;
    result = 0;
    list10 = func_001452b0(10);
    list3 = func_001452b0(3);
    func_001452b0(1);
    work.input[0] = origin[0] + vector[0];
    work.input[1] = origin[1] + vector[1];
    work.input[2] = origin[2] + vector[2];
    work.input[3] = fraction;
    work.type = 3;
    work.copy.bits = *(u_long128 *)work.input;
    for (i = 0; i < 64; i++)
    {
        memset(&work.points[i], 0, 12);
        memset(&work.normals[i], 0, 12);
        work.fracs[i] = fGpffff82b4;
        work.flags[i] = 0;
    }
    work.hitCount = 0;
    work.count = 0;
    {
        s32 *src = (s32 *)&work.copy;
        s32 *dst = (s32 *)work.scratch;
        s32 cnt = 7;
        do
        {
            s32 v = *src;
            src++;
            cnt--;
            *dst = v;
            dst++;
        } while (cnt > 0);
    }
    RwV3dNormalize((f32 *)&work.normDir, (const f32 *)vector);
    memset(work.zero, 0, 12);
    if (collisionWorld == 0)
    {
        return 0;
    }
    work.mode = 1;
    func_003bff30((void *)collisionWorld, func_0016a0c0, work.points);
    while (list10 != NULL)
    {
        if (((*(s32 *)(list10 + 0x28) & 2) != 0) && (*(s32 *)(list10 + 0x150) == 1))
        {
            void *target = mdlGetClump(*(void **)(list10 + 0x144));
            func_003bff30(target, func_0016a0c0, work.points);
            line[1].x = origin[0];
            line[1].y = origin[1];
            line[1].z = origin[2];
            line[0] = line[1];
            line[0].y += 400.0f;
            line[1].y -= 600.0f;
            target = mdlGetClump(*(void **)(list10 + 0x144));
            if (func_0016b480(target, line, &hit) == 1)
            {
                vector[1] = -((origin[1] - fraction) - hit.y);
            }
        }
        list10 = *(u8 **)(list10 + 0x138);
    }
    work.mode = 0;
    func_0014a200();
    func_0014a200();
    {
        u16 low = (u16)fieldId;
        if ((low & 0x3ff) == 0)
        {
        for (j = 0; ; j++)
        {
            u8 *entry = *(u8 **)(D_007E8020 + j * 4);
            if (entry == NULL)
            {
                break;
            }
            {
                s32 present = *(s32 *)(entry + 0x48) != 0;
                if (present != 0)
                {
                    present = *(s32 *)(entry + 0x54) != 0;
                }
                if (present != 0)
                {
                    u8 *other = *(u8 **)(entry + 0x54);
                    if (((*(s32 *)(other + 0x28) & 2) != 0) && ((*(s32 *)(entry + 0x40) & 2) == 0))
                    {
                        void *id = *(void **)(other + 0x228);
                        if (id != 0)
                        {
                            void *target = mdlGetClump(id);
                            func_003bff30(target, func_0016a0c0, work.points);
                        }
                    }
                }
            }
        }
        }
    }
    while (list3 != NULL)
    {
        if (((*(s32 *)(list3 + 0x28) & 2) != 0) && (*(s32 *)(list3 + 0x22c) != 0))
        {
            void *target = mdlGetClump(*(void **)(list3 + 0x22c));
            func_003bff30(target, func_0016a0c0, work.points);
        }
        list3 = *(u8 **)(list3 + 0x138);
    }
    for (k = 0; (entry = *(u8 **)(D_007E8020 + k * 4 + 0x20)) != NULL; k++)
    {
        if (*(s32 *)entry != 0)
        {
            void *id = *(void **)(entry + 0x164);
            if (id != 0)
            {
                void *target = mdlGetClump(id);
                func_003bff30(target, func_0016a0c0, work.points);
            }
        }
    }
    n = 0;
    allHit = 1;
    while (n < work.count)
    {
        if (work.flags[n] == 0)
        {
            allHit = 0;
            break;
        }
        n++;
    }
    i = 0;
    qy = work.copy.f[1];
    qz = work.copy.f[2];
    qfrac = work.copy.f[3];
    for (; i < work.count; i++)
    {
        if (work.fracs[i] < fGpffff82b4)
        {
            delta.x = work.copy.f[0] - work.points[i].x;
            delta.y = qy - work.points[i].y;
            delta.z = qz - work.points[i].z;
            RwV3dNormalize((f32 *)&delta, (const f32 *)&delta);
            scale = qfrac - work.fracs[i];
            scaled.x = delta.x * scale;
            scaled.y = delta.y * scale;
            scaled.z = delta.z * scale;
            if (work.flags[i] == 1)
            {
                work.extra[i] = scaled;
            }
            else
            {
                for (m = 0; m < work.count; m++)
                {
                    if (work.flags[m] == 1)
                    {
                        f32 d = scaled.y * work.extra[m].y + scaled.x * work.extra[m].x + scaled.z * work.extra[m].z;
                        if (d < 0.0f)
                        {
                            scaled.x += work.extra[m].x;
                            scaled.y += work.extra[m].y;
                            scaled.z += work.extra[m].z;
                        }
                    }
                }
            }
            neg = -1.0f;
            if (allHit == 1)
            {
                neg = vector[1] * work.normals[i].y + vector[0] * work.normals[i].x + vector[2] * work.normals[i].z;
            }
            dot = vector[1] * delta.y + vector[0] * delta.x + vector[2] * delta.z;
            if ((dot < 0.0f || work.flags[i] == 1) && neg < 0.0f)
            {
                vector[0] += scaled.x;
                vector[1] += scaled.y;
                vector[2] += scaled.z;
                result = 1;
            }
            if (vector[0] == 0.0f && vector[1] == 0.0f && vector[2] == 0.0f)
            {
                vector[0] += scaled.x;
                vector[1] += scaled.y;
                vector[2] += scaled.z;
                result = 1;
            }
        }
    }
    if (allHit == 0 && work.count >= 2)
    {
        RwV3dLength((f32 *)vector);
        for (n = 0; n < work.count - 1; n++)
        {
            for (m = n + 1; m < work.count; m++)
            {
                f32 d = work.normals[n].y * work.normals[m].y + work.normals[n].x * work.normals[m].x + work.normals[n].z * work.normals[m].z;
                if (d < fGpffff82b8)
                {
                    vector[0] = 0.0f;
                    vector[1] = 0.0f;
                    vector[2] = 0.0f;
                    return result;
                }
            }
        }
    }
    return result;
}
#pragma pop
