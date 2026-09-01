void* func_0016b260(const RwV3d* line, void* unused,
                    const void* triangle, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    const FldFrameCollisionTriangle* candidate;
    FldFrameLine lineCopy;
    RwV3d segment;
    f32 normalZ;
    f32 normalX;
    f32 normalY;
    f32 denominator;
    f32 vertexDot;
    f32 lineDot;
    f32 fraction;

    lineCopy = *(const FldFrameLine*)line;
    candidate = (const FldFrameCollisionTriangle*)triangle;
    segment.x = lineCopy.point[0].x - lineCopy.point[1].x;
    segment.y = lineCopy.point[0].y - lineCopy.point[1].y;
    segment.z = lineCopy.point[0].z - lineCopy.point[1].z;
    normalY = candidate->normal.y;
    normalX = candidate->normal.x;
    normalZ = candidate->normal.z;
    denominator = normalY * segment.y;
    denominator += normalX * segment.x;
    denominator += normalZ * segment.z;
    vertexDot = normalZ * candidate->vertices[0]->z;
    vertexDot += normalX * candidate->vertices[0]->x;
    vertexDot += normalY * candidate->vertices[0]->y;
    lineDot = normalZ * lineCopy.point[0].z;
    lineDot += normalX * lineCopy.point[0].x;
    lineDot += normalY * lineCopy.point[0].y;
    fraction = -(-vertexDot + lineDot) / denominator;
    raycast->hitPointDst->x = lineCopy.point[0].x + segment.x * fraction;
    raycast->hitPointDst->y = lineCopy.point[0].y + segment.y * fraction;
    raycast->hitPointDst->z = lineCopy.point[0].z + segment.z * fraction;
    raycast->didHit = 1;
    return NULL;
}
