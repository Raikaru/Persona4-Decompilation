/* Closest candidate archived before reverting: frame/register layout still differed (obj 1376B vs 1344B). */
// FUN_00196610
u32 func_00196610(u8 *arg0)
{
    struct Btl966Work
    {
        f32 rotation[4];
        f32 pad10;
        f32 pad14;
        f32 currentX;
        f32 currentZ;
        f32 deltaX;
        f32 deltaZ;
        f32 nextDeltaX;
        f32 nextDeltaZ;
        RwV3d targetPos;
        f32 pad3c;
        RwV3d finalPos;
    } frame;
    u8 *entry;
    u8 *point;
    u32 index;
    u32 count;
    f32 pathLength;
    f32 lastDistance;
    f32 nextX;
    f32 nextZ;
    f32 turn;

    if ((*(u16 *)(arg0 + 0xC8) & 1) &&
        (*(u16 *)(arg0 + 0xC8) & 0x10))
    {
        entry = arg0 + 0xEC;
        index = *(u16 *)(arg0 + 0x4EE);
        count = *(u16 *)(arg0 + 0x4EC);
        lastDistance = 0.0f;
        pathLength = *(f32 *)(arg0 + 0xCC);
        frame.currentX = *(f32 *)(arg0 + 4);
        frame.currentZ = *(f32 *)(arg0 + 0xC);
        while (index < count - 1)
        {
            pathLength -= lastDistance;
            point = entry + (index * 8) + 8;
            frame.deltaX = *(f32 *)(point + 0) - frame.currentX;
            frame.deltaZ = *(f32 *)(point + 4) - frame.currentZ;
            lastDistance = func_003e41e0(&frame.deltaX, &frame.deltaX);
            if (lastDistance < pathLength)
            {
                frame.currentX = *(f32 *)(point + 0);
                frame.currentZ = *(f32 *)(point + 4);
                index += 1;
            }
            else
            {
                break;
            }
        }
        if (*(u32 *)(arg0 + 0xC4) & 1)
            index = count - 1;
        if (index < count - 1)
        {
            frame.deltaX *= pathLength;
            frame.deltaZ *= pathLength;
            nextX = frame.currentX + frame.deltaX;
            nextZ = frame.currentZ + frame.deltaZ;
            point = entry + (count * 8);
            frame.nextDeltaX = frame.currentX - *(f32 *)(point - 8);
            frame.nextDeltaZ = frame.currentZ - *(f32 *)(point - 4);
            lastDistance = func_003e41b0(&frame.nextDeltaX);
            if (lastDistance < *(f32 *)(arg0 + 0xE8))
            {
                lastDistance = (lastDistance + pathLength) -
                               *(f32 *)(arg0 + 0xE8);
                frame.deltaX = frame.deltaX * lastDistance;
                frame.deltaZ = frame.deltaZ * lastDistance;
                nextX = frame.currentX + frame.deltaX;
                nextZ = frame.currentZ + frame.deltaZ;
                *(u32 *)(arg0 + 0xC4) &= ~1;
                *(u16 *)(arg0 + 0xC8) &= 0xFFFE;
                *(u16 *)(arg0 + 0xC8) &= 0xFFEF;
            }
            frame.finalPos.x = nextX;
            frame.finalPos.y = *(f32 *)(arg0 + 8);
            frame.finalPos.z = nextZ;
            frame.currentX = nextX + frame.deltaX;
            frame.currentZ = nextZ + frame.deltaZ;
            frame.targetPos.x = frame.currentX;
            frame.targetPos.y = frame.finalPos.y;
            frame.targetPos.z = frame.currentZ;
        }
        else
        {
            point = entry + (index * 8);
            frame.finalPos.x = *(f32 *)(point + 0);
            frame.finalPos.y = *(f32 *)(arg0 + 8);
            frame.finalPos.z = *(f32 *)(point + 4);
            frame.targetPos = frame.finalPos;
            *(u32 *)(arg0 + 0xC4) &= ~1;
            *(u16 *)(arg0 + 0xC8) &= 0xFFFE;
            *(u16 *)(arg0 + 0xC8) &= 0xFFEF;
        }
        *(f32 *)(arg0 + 4) = frame.finalPos.x;
        *(f32 *)(arg0 + 8) = frame.finalPos.y;
        *(f32 *)(arg0 + 0xC) = frame.finalPos.z;
        *(u32 *)(arg0 + 0x98) |= 4;
        *(u16 *)(entry + 0x402) = index;
        if (!(*(u32 *)(arg0 + 0xC4) & 0x100))
        {
            *(f32 *)(arg0 + 0xD0) = frame.targetPos.x;
            *(f32 *)(arg0 + 0xD4) = frame.targetPos.y;
            *(f32 *)(arg0 + 0xD8) = frame.targetPos.z;
        }
        else
        {
            *(f32 *)(arg0 + 0xD0) = *(f32 *)(arg0 + 0x4F8);
            *(f32 *)(arg0 + 0xD4) = *(f32 *)(arg0 + 0x4FC);
            *(f32 *)(arg0 + 0xD8) = *(f32 *)(arg0 + 0x500);
        }
        *(u16 *)(arg0 + 0xC8) |= 2;
    }
    if (*(u16 *)(arg0 + 0xC8) & 2)
    {
        frame.deltaX = *(f32 *)(arg0 + 0xD0) - *(f32 *)(arg0 + 4);
        frame.deltaZ = *(f32 *)(arg0 + 0xD8) - *(f32 *)(arg0 + 0xC);
        frame.targetPos.x = frame.deltaX;
        frame.targetPos.z = frame.deltaZ;
        if (((frame.deltaX != 0.0f) || (frame.deltaZ != 0.0f)) &&
            !(*(u32 *)(arg0 + 0x9C) & 0x2000))
        {
            turn = fGpffff8048 *
                   func_0044b950(frame.targetPos.x, frame.targetPos.z);
            func_003dcb40(&frame.targetPos, &D_0060A0F0, 1,
                          (RwV3d *)(arg0 + 0x1C));
            nextZ = turn -
                    (fGpffff8048 *
                     func_0044b950(frame.targetPos.x, frame.targetPos.z));
            lastDistance =
                func_0044e7d8(func_0044b310(func_0044dcd8(nextZ)));
            if ((lastDistance > fGpffff83d0) &&
                !(*(u32 *)(arg0 + 0xC4) & 2))
            {
                if (lastDistance > 180.0f)
                {
                    if (nextZ > 0.0f)
                        nextZ -= 360.0f;
                    else
                        nextZ += 360.0f;
                }
                nextZ /= *(f32 *)(arg0 + 0x4F4);
                frame.rotation[0] = *(f32 *)(arg0 + 0x1C);
                frame.rotation[1] = *(f32 *)(arg0 + 0x20);
                frame.rotation[2] = *(f32 *)(arg0 + 0x24);
                frame.rotation[3] = *(f32 *)(arg0 + 0x28);
                func_003dc740(frame.rotation, D_0060A0E0, 2, nextZ);
            }
            else
            {
                frame.rotation[0] = *(f32 *)(arg0 + 0x1C);
                frame.rotation[1] = *(f32 *)(arg0 + 0x20);
                frame.rotation[2] = *(f32 *)(arg0 + 0x24);
                frame.rotation[3] = *(f32 *)(arg0 + 0x28);
                *(u32 *)(arg0 + 0xC4) &= ~2;
                func_003dc740(frame.rotation, D_0060A0E0, 0, turn);
            }
            if (!(*(u32 *)(arg0 + 0x9C) & 0x2000))
            {
                *(f32 *)(arg0 + 0x1C) = frame.rotation[0];
                *(f32 *)(arg0 + 0x20) = frame.rotation[1];
                *(f32 *)(arg0 + 0x24) = frame.rotation[2];
                *(f32 *)(arg0 + 0x28) = frame.rotation[3];
                *(u32 *)(arg0 + 0x98) |= 4;
            }
        }
        else
        {
            *(u32 *)(arg0 + 0xC4) &= ~2;
            *(u16 *)(arg0 + 0xC8) &= 0xFFFD;
        }
    }
    return 0;
}
