/* Exact field raycast recovery, installed in k_fldFrame.c.
 * 560B/560B; zero fully relocated differing words; all 12 relocations resolved.
 * The complete owner preserves its other 15 emitted functions.
 * Uses the existing owner FldFrameRaycast and shared k_fldFrame_internal.h types.
 * Start X/Z selects the grid record; +0x1a0 reaches its resource. The non-grid
 * path reloads the root after the mode query. All paths use the input snapshot.
 * Signed multiplication preserves the retail shifts without shifting negatives.
 * Native proof: 1,249 raycast/iterator cases (64-bit sanitizers and 32-bit), plus
 * 196,728 cases executing all three actual field consumers on 32-bit records.
 * Inputs require two valid points, finite representable coordinate conversions
 * and a valid mapped-grid record for the selected cell. No guards were added.
 */
u32 func_0016b540(const RwV3d* line, RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy;
    u8* object;
    void* collisionWorld;

    lineCopy = *(const FldFrameLine*)line;
    object = *(u8**)(iGpffff9db0 + 0x28);
    if (object == NULL)
    {
        return 0;
    }
    if ((*(u32*)object & 1) != 0)
    {
        FldFrameIntersection intersection;
        FldFrameRaycast raycast;
        u32 result;
        collisionWorld = *(void**)(object + 0xc);
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = 0;
        intersection.type = 1;
        intersection.line = lineCopy;
        if (collisionWorld == NULL)
        {
            result = 0;
        }
        else
        {
            func_00394d70(collisionWorld, &intersection, func_0016b260, &raycast);
            result = raycast.didHit;
        }
        return result;
    }
    else
    {
        FldFrameIntersection intersection;
        FldFrameRaycast raycast;
        collisionWorld = NULL;
        if (func_0014a160() != 0)
        {
            u8* entry;
            u32 key;
            entry = func_001452b0(0xc);
            key = *(u16*)((u8*)func_00155280() +
                         (s32)((600.0f + lineCopy.point[0].z) / 1200.0f) * 0x100 +
                         (s32)((600.0f + lineCopy.point[0].x) / 1200.0f) * 0x10 + 0x56);
            while (entry != NULL)
            {
                if (*(u16*)entry == key)
                {
                    collisionWorld = *(void**)(*(u8**)(entry + 0x1a0) + 8);
                    break;
                }
                entry = *(u8**)(entry + 0x138);
            }
        }
        else
        {
            collisionWorld = *(void**)(*(u8**)(iGpffff9db0 + 0x28) + 8);
        }
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = 0;
        raycast.nearestFraction = fGpffff82b4;
        intersection.type = 1;
        intersection.line = lineCopy;
        *(FldFrameIntersection*)&raycast.line[0] = intersection;
        if (collisionWorld == NULL)
        {
            return 0;
        }
        func_003bff30(collisionWorld, func_0016b430, &raycast);
        return raycast.didHit;
    }
}

