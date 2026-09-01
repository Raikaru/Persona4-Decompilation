/* LaneFldFrame candidate archive: semantic C reconstruction measured non-MATCH (frame/register layout); reverted to INCLUDE_ASM. */
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
    typedef struct FldFrameHitState
    {
        RwV3d* hitPointDst;
        u32 didHit;
    } FldFrameHitState;
    FldFrameLine lineCopy __attribute__((aligned(16)));
    FldFrameIntersection intersection __attribute__((aligned(16)));
    FldFrameHitState hitState;
    FldFrameRaycast raycast;
    u8* root;
    u8* collisionWorld;
    u8* entry;
    u16 id;
    u32 result;

    lineCopy = *(const FldFrameLine*)line;
    result = 0;
    root = *(u8**)(iGpffff9db0 + 0x28);
    if (root != NULL)
    {
        if ((*(u32*)root & 1) != 0)
        {
            hitState.hitPointDst = hitPointDst;
            hitState.didHit = 0;
            intersection.type = 1;
            intersection.line = lineCopy;
            collisionWorld = *(u8**)(root + 0xc);
            if (collisionWorld != NULL)
            {
                func_00394d70(collisionWorld, &intersection,
                              func_0016b260, &hitState);
                result = hitState.didHit;
            }
        }
        else
        {
            /* Probe retained an erroneous label while exploring branch layout. */
            collisionWorld = NULL;
            if (func_0014a160() != 0)
            {
                entry = func_001452b0(0xc);
                id = *(u16*)(func_00155280() +
                             (s32)((lineCopy.point[1].z + 600.0f) /
                                   1200.0f) * 0x100 +
                             (s32)((lineCopy.point[0].x + 600.0f) /
                                   1200.0f) * 0x10 + 0x56);
                while (entry != NULL)
                {
                    if (*(u16*)entry == id)
                    {
                        collisionWorld = *(u8**)(*(u8**)(entry + 0xd0) + 8);
                        break;
                    }
                    entry = *(u8**)(entry + 0x138);
                }
            }
            else
            {
                collisionWorld = *(u8**)(root + 8);
            }
            raycast.hitPointDst = hitPointDst;
            raycast.didHit = 0;
            raycast.nearestFraction = fGpffff82b4;
            raycast.intersectionType = 1;
            raycast.line[0] = lineCopy.point[0];
            raycast.line[1] = lineCopy.point[1];
            if (collisionWorld != NULL)
            {
                func_003bff30(collisionWorld, func_0016b430, &raycast);
                result = raycast.didHit;
            }
        }
    }
    return result;
}
