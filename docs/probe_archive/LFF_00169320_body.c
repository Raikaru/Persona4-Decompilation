/* Closest C reconstruction attempt for 00169320; not an exact match. */

void* func_00169320(RwV3d* point, void* unused, RwV3d* triangle,
                    u8* context)
{
    typedef struct FldFrameTriangle
    {
        RwV3d vector;
        u8 gap[0x10];
        RwV3d* normal;
    } FldFrameTriangle;
    FldFrameTriangle* triangleData;
    RwV3d projected;
    RwV3d edgePoint;
    RwV3d delta;
    RwV3d* normal;
    f32 projection;
    f32 distance;
    f32* record;
    s32 count;
    s32 index;
    f32* fraction;
    s32 i;
    f32 tx;
    f32 ty;
    f32 tz;

    triangleData = (FldFrameTriangle*)triangle;
    ty = triangleData->vector.y;
    tx = triangleData->vector.x;
    tz = triangleData->vector.z;
    normal = triangleData->normal;
    projection =
        normal->x * tx +
        normal->y * ty +
        normal->z * tz -
        (point->x * tx +
         point->y * ty +
         point->z * tz);
    projected.x = tx * projection;
    projected.y = ty * projection;
    projected.z = tz * projection;
    projected.x += point->x;
    projected.y += point->y;
    projected.z += point->z;

    if (func_00168ec0(&projected, (u8*)triangle + 0x1c,
                      triangle) != 0)
    {
        distance = fabsf(projection);
        index = 0;
        count = *(s32*)(context + 0xb04);
        while (index < count)
        {
            record = (f32*)(context + 12 * index);
            if (record[192] == triangle->x &&
                record[193] == triangle->y &&
                record[194] == triangle->z)
                break;
            index++;
        }
        if (index == count)
            index = -1;

        if (index < 0)
        {
            fraction = (f32*)(context + 4 * count + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * count);
                record[0] = projected.x;
                record[1] = projected.y;
                record[2] = projected.z;
                record = (f32*)(context +
                                12 * *(s32*)(context + 0xb04));
                record[192] = triangle->x;
                record[193] = triangle->y;
                record[194] = triangle->z;
                fraction = (f32*)(context +
                                  4 * *(s32*)(context + 0xb04) + 0x600);
                *fraction = distance;
                (*(s32*)(context + 0xb04))++;
            }
        }
        else
        {
            fraction = (f32*)(context + 4 * index + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * index);
                record[0] = projected.x;
                record[1] = projected.y;
                record[2] = projected.z;
                record[192] = triangle->x;
                record[193] = triangle->y;
                record[194] = triangle->z;
                *fraction = distance;
            }
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            func_00169200(
                &edgePoint, &projected,
                *(RwV3d**)((u8*)triangle + 0x1c + 4 * i),
                *(RwV3d**)((u8*)triangle + 0x1c +
                           4 * ((i + 1) % 3)));
            delta.x = point->x - edgePoint.x;
            delta.y = point->y - edgePoint.y;
            delta.z = point->z - edgePoint.z;
            index = 0;
            count = *(s32*)(context + 0xb04);
            while (index < count)
            {
                record = (f32*)(context + 12 * index);
                if (record[192] == triangle->x &&
                    record[193] == triangle->y &&
                    record[194] == triangle->z)
                    break;
                index++;
            }
            if (index == count)
                index = -1;

            if (index < 0)
            {
                fraction = (f32*)(context + 4 * count + 0x600);
                if (distance < *fraction)
                {
                    record = (f32*)(context + 12 * count);
                    record[0] = edgePoint.x;
                    record[1] = edgePoint.y;
                    record[2] = edgePoint.z;
                    record = (f32*)(context +
                                    12 * *(s32*)(context + 0xb04));
                    record[192] = triangle->x;
                    record[193] = triangle->y;
                    record[194] = triangle->z;
                    fraction = (f32*)(context +
                                      4 * *(s32*)(context + 0xb04) + 0x600);
                    *fraction = distance;
                    (*(s32*)(context + 0xb04))++;
                }
            }
            else
            {
                fraction = (f32*)(context + 4 * index + 0x600);
                if (distance < *fraction)
                {
                    record = (f32*)(context + 12 * index);
                    record[0] = edgePoint.x;
                    record[1] = edgePoint.y;
                    record[2] = edgePoint.z;
                    record[192] = triangle->x;
                    record[193] = triangle->y;
                    record[194] = triangle->z;
                    *fraction = distance;
                }
            }
        }
    }

    return triangle;
}
