/* Closest C reconstruction attempt for 0016abc0; not an exact match. */

s32 func_0016abc0(s32 collisionWorld, f32* point,
                  f32* normal, f32* vector, f32 fraction)
{
    typedef struct FldFrameQueryWork
    {
        u8 records[0xb00];
        s32 mode;
        s32 count;
        s32 hitCount;
        u8 gap[0xc];
        u8 scratch[0x20];
        u8 zero[0x18];
        f32 input[4];
        u_long128 inputCopy;
        u8 inputTail[8];
        s32 intersectionType;
    } FldFrameQueryWork;
    FldFrameQueryWork work;
    s32 result;
    u8* list;
    u8* node;
    void* target;
    void* table;
    f32* dimensions;
    f32* entry;
    s32* src;
    s32* dst;
    s32 i;
    s32 j;
    s32 x;
    s32 z;
    s32 foundCount;
    u16 id;
    f32 threshold;
    f32 pointY;
    f32 pointZ;

    result = 0;
    list = func_001452b0(10);
    func_001452b0(3);
    func_001452b0(1);
    pointY = point[1];
    pointZ = point[2];
    work.input[0] = point[0];
    work.input[1] = pointY;
    work.input[2] = pointZ;
    work.input[3] = fraction;
    work.intersectionType = 3;
    work.inputCopy = *(u_long128*)work.input;

    i = 0;
    while (i < 64)
    {
        entry = (f32*)(work.records + 12 * i);
        func_0043f9c8(entry, 0, 12);
        func_0043f9c8((u8*)entry + 0x300, 0, 12);
        *(f32*)((u8*)entry + 0x600) = fGpffff82b4;
        *(s32*)((u8*)entry + 0xa00) = 0;
        i++;
    }

    work.hitCount = 0;
    work.count = 0;
    src = (s32*)&work.inputCopy;
    dst = (s32*)work.scratch;
    i = 7;
    do
    {
        *dst++ = *src++;
        i--;
    } while (i > 0);
    func_0043f9c8(work.zero, 0, 12);

    if (collisionWorld != 0)
    {
        work.mode = 1;
        func_003bff30((void*)collisionWorld, func_0016a0c0,
                      work.records);
        if (func_0014a200() == 1 || func_0014a270() == 1)
        {
            dimensions = (f32*)func_003e9700(
                *(s32*)((u8*)func_00457120() + 4));
            x = (s32)((dimensions[12] + 600.0f) / 1200.0f);
            z = (s32)((dimensions[14] + 600.0f) / 1200.0f);
            for (j = 0; j < 4; j++)
            {
                s32* offsets = &D_005F1650[2 * j];
                table = func_00155280();
                if (*(u8*)((u8*)table +
                           ((z + offsets[1]) << 8) +
                           16 * (x + offsets[0]) + 84) == 1)
                {
                    table = func_00155280();
                    id = *(u16*)((u8*)table +
                                 ((z + offsets[1]) << 8) +
                                 16 * (x + offsets[0]) + 86);
                    target = 0;
                    node = func_001452b0(12);
                    while (node != 0)
                    {
                        if (*(u16*)node == id)
                        {
                            target = *(void**)(*(u8**)(node + 0x1a0) + 8);
                            break;
                        }
                        node = *(u8**)(node + 0x138);
                    }
                    if (target != 0)
                        func_003bff30(target, func_0016a0c0,
                                      work.records);
                }
            }
            while (list != 0)
            {
                if ((*(s32*)(list + 0x28) & 2) != 0 &&
                    *(s32*)(list + 0x150) == 1)
                {
                    target = func_0047a310(*(s32*)(list + 0x144));
                    func_003bff30(target, func_0016a0c0,
                                  work.records);
                }
                list = *(u8**)(list + 0x138);
            }
        }

        *(u32*)normal = 0;
        *(u32*)(normal + 1) = 0;
        *(u32*)(normal + 2) = 0;
        *(u32*)vector = 0;
        *(u32*)(vector + 1) = 0;
        *(u32*)(vector + 2) = 0;
        foundCount = 0;
        threshold = fGpffff82b4;
        i = 0;
        while (i < work.count)
        {
            entry = (f32*)(work.records + 12 * i);
            if (*(f32*)(work.records + 0x600 + 4 * i) < threshold)
            {
                normal[0] += entry[192];
                normal[1] += entry[193];
                normal[2] += entry[194];
                vector[0] += entry[0];
                vector[1] += entry[1];
                vector[2] += entry[2];
                foundCount++;
                result = 1;
            }
            i++;
        }
        if (result == 1)
        {
            func_003e40b0(normal, normal);
            threshold = (f32)foundCount;
            vector[0] /= threshold;
            vector[1] /= threshold;
            vector[2] /= threshold;
        }
        return result;
    }
    return 0;
}
