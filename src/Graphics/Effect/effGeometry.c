#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "eff_geometry_block_internal.h"
#include "include_asm.h"
/* Original translation unit effGeometry.c (from __FILE__ assert strings). */
#include "type.h"
/* RenderWare's public RwFrame typedef carries the SDK's 16-byte alignment. */
typedef struct RwFrame RwFrame __attribute__((aligned(16)));
typedef struct RpAtomic RpAtomic;
typedef struct RpGeometry RpGeometry;
typedef struct RpMaterial RpMaterial;
extern s32 TnGetOffset1C();
extern void PrimAppendNode();
extern s32 TnUploadStreamTagged();
extern u8 *func_003c42b0(void *object, s32 value);
extern void func_003ef3a0();
extern void func_003a2760(u8 *object);
extern void func_003c02e0(u8 *arg0);
extern void func_003e9390();
extern void func_003c4220();
extern void (*jtbl_008873EC[])(void *ptr);
extern void mdlEffectBuildBasisRows();
extern void RwMatrixScale(void *object, f32 *value, s32 options);
extern void RwMatrixTranslate(void *object, void *value, s32 options);
extern void RwMatrixMultiply(void *object, void *value, void *options);
extern void func_003a2950();
extern void kAssertFail(void *file, s32 line);
extern u8 D_00713448[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern RwFrame *func_003e9320(void);
extern RpAtomic *func_003c00e0(void);
extern RpMaterial *func_003c4140(void);
extern RpGeometry *func_003c2630(s32 object, s32 value, u32 options);
extern RpAtomic *RpAtomicSetFrame(RpAtomic *atomic, RwFrame *frame);
extern RpAtomic *func_003c0210(RpAtomic *atomic, RpGeometry *geometry, u32 flags);
extern s32 func_003c2a80(RpGeometry *geometry);
extern void *memset(void *dst, s32 value, u32 size);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern f32 fGpffff8078;
extern s32 iGpffffb610;
extern s32 func_003a2340();
extern u8 D_00713460[];
extern void memcpy(void *dst, const void *src, u32 size);
extern s32 func_003c2130(void *object, void *value, s32 options, s32 context, s32 flags);
extern s32 func_003c2150(u8 *object, u8 *value, s32 options);
extern void func_003c22f0(void *object);

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes; layout from P3FES rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

typedef struct RwSphere
{
    RwV3d center;
    f32 radius;
} RwSphere;

/* Partial RpGeometry and RpMorphTarget layouts holding only the fields this file reads; RpGeometry
 * starts with an 8-byte RwObject. */
typedef struct RpMorphTarget {
    u8 field_0x00[0x4];
    RwSphere boundingSphere;         /* +0x4 */
} RpMorphTarget;

struct RpGeometry {
    u8 pad00[0x20];
    u8 **materials;
    u8 pad24[8];
    u8 *triangles;                   /* +0x2C */
    u8 field_0x30[0x5C - 0x30];
    RpMorphTarget *morphTarget;  /* +0x5C */
};

/* Multipart blocks extend the shared 0x48-byte prefix to 0x58 and append one
 * material pointer per part. Triangle records have three 16-bit indices plus
 * the material slot at the eight-byte stride. */

typedef struct EffGeometryMultiPart {
    EffGeometryBlock base;
    union {
        s16 signedHalf[2];
    } partCount; /* +0x48 */
    union {
        s16 signedHalf[2];
        u8 byte[4];
    } totalTriangles; /* +0x4C */
    union {
        u8 byte[4];
    } unk50; /* +0x50 */
    s32 materials; /* +0x54 */
} EffGeometryMultiPart;

typedef struct EffGeometryIndices {
    union {
        u16 half[2];
    } unk00; /* +0x00 */
    u16 unk04; /* +0x04 */
} EffGeometryIndices;

typedef struct EffGeometryTriangle {
    union {
        u16 half[2];
    } firstVertex; /* +0x00 */
    u16 thirdVertex; /* +0x04 */
    u8 pad06[0x2];
} EffGeometryTriangle;

typedef struct EffGeometryRaster {
    u8 pad00[0xC];
    u32 unk0C; /* +0x0C */
    u32 unk10; /* +0x10 */
} EffGeometryRaster;

/* RpAtomic's geometry link is at +0x18 in the public SDK layout. */
typedef struct EffGeometryAtomic {
    u8 pad00[0x18];
    u8 *geometry;
} EffGeometryAtomic;

typedef struct EffGeometryMaterial {
    s32 texture;
} EffGeometryMaterial;

typedef struct EffGeometryAtomicPlugin {
    u8 pad00[4];
    s32 unk04;
    u8 pad08[0x38];
    s32 flags;
    u8 pad44[0x70];
    s32 unkB4;
    u8 padB8[0x28];
    u8 color[0x10];
} EffGeometryAtomicPlugin;

typedef signed __int128 s128;

void GeometryMatrixBuild(RwMatrix *matrix, RwV3d *translation, void *basis, f32 scale);
void func_003e9cb0(void *frame, void *transform, u32 combine);

extern u8 *GeometryCreateMultiPart(s32 partCount, s32 verticesPerPart, s32 trianglesPerPart, s32 flags);


// Single-part block: an atomic, geometry with object vertices and value triangles, flags options, a frame and a default bounding sphere.
// FUN_00482C40
u8 *GeometryBlockCreate(s32 vertexCount, s32 triangleCount, s32 flags) {
    struct F4 { f32 x, y, z, w; } vec;
    void *block;
    void *geometry;
    s32 frame;
    s32 atomic;
    s32 material;

    chkmemAllocSiteTag(D_00713448, 0x1B);
    block = jtbl_008873E8[0](0x48, 0x40000);
    frame = (s32)func_003e9320();
    atomic = (s32)func_003c00e0();
    material = (s32)func_003c4140();
    geometry = func_003c2630(vertexCount, triangleCount, flags);
    RpAtomicSetFrame((RpAtomic *)atomic, (RwFrame *)frame);
    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = 0.0f;
    vec.w = fGpffff8078;
    {
        u8 *q = (u8 *)((RpGeometry *)geometry)->morphTarget;
        /* The morph target starts with its parent geometry pointer. */
        ((RpMorphTarget *)q)->boundingSphere = *(RwSphere *)&vec;
    }
    func_003c0210((RpAtomic *)atomic, (RpGeometry *)geometry, 0);
    func_003c2a80((RpGeometry *)geometry);
    ((EffGeometryBlock *)block)->kindData.signedHalf[0] = 5;
    ((EffGeometryBlock *)block)->flags = flags;
    ((EffGeometryBlock *)block)->vertexCounts.signedHalf[0] = (s16)vertexCount;
    ((EffGeometryBlock *)block)->vertexCounts.signedHalf[1] = (s16)triangleCount;
    ((EffGeometryBlock *)block)->frameData.signedValue = frame;
    ((EffGeometryBlock *)block)->atomicData.signedValue = atomic;
    ((EffGeometryBlock *)block)->materialData.signedValue = material;
    memset((u8 *)block + 0x18, 0, 0x30);
    ((EffGeometryBlock *)block)->tag = 0x15;
    ((EffGeometryBlock *)block)->drawOwner.pointer = block;
    return block;
}

// Strip grid: builds the (rows+1) x cols vertex block through GeometryBlockCreate, then one set of triangles per row from the index table.
// FUN_00482DC0
u8 *GeometryCreateStripGrid(u16 rowCount, void *indices, s32 verticesPerRow, s32 flags) {
    s32 segmentCount;
    u16 rows;
    s32 firstVertex;
    u8 *geometry;
    u8 *triangle;
    s32 rowIndex;
    s32 indexOffset;
    s32 vertexOffset;
    u8 *block;
    u8 *indexTriple;
    u8 *result;
    s32 material;
    s32 indicesPerRow;

    if ((rowCount & 0xFFFF) < 2) {
        kAssertFail(D_00713448, 0x4C);
    }
    if ((verticesPerRow & 0xFFFF) < 2) {
        kAssertFail(D_00713448, 0x4D);
    }
    segmentCount = (verticesPerRow & 0xFFFF) - 1;
    indicesPerRow = segmentCount * 4 + segmentCount * 2;
    rows = (u16)rowCount;
    block = (u8 *)GeometryBlockCreate((rows + 1) * (verticesPerRow & 0xFFFF),
                                   rows * (segmentCount * 2), flags);
    result = block;
    geometry = ((EffGeometryAtomic *)((EffGeometryBlock *)block)->atomicData.bytes)->geometry;
    material = ((EffGeometryBlock *)block)->materialData.signedValue;
    triangle = ((RpGeometry *)geometry)->triangles;
    vertexOffset = 0;
    rowIndex = 0;
    while (rowIndex < rows) {
        indexOffset = 0;
        firstVertex = vertexOffset & 0xFFFF;
        while (indexOffset < indicesPerRow) {
            indexTriple = (u8 *)indices + (indexOffset * 2);
            func_003c2130(geometry, triangle,
                          (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[0]) & 0xFFFF,
                          (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[1]) & 0xFFFF,
                          (firstVertex + ((EffGeometryIndices *)indexTriple)->unk04) & 0xFFFF);
            func_003c2150(geometry, triangle, material);
            triangle += 8;
            indexOffset += 3;
        }
        vertexOffset = (vertexOffset + verticesPerRow) & 0xFFFF;
        rowIndex += 1;
    }
    return result;
}

// Table-driven grid: rowCount rows, verticesPerRow vertices per row, indices table entries per row (three u16 offsets each), flags flags.
// FUN_00482F70
u8 *GeometryCreateTableGrid(s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow, const void *indices, s32 flags) {
    s32 rows;
    s32 columns;
    s32 firstVertex;
    s32 triangleCount;
    u8 *geometry;
    u8 *triangle;
    s32 rowIndex;
    s32 indexOffset;
    s32 vertexOffset;
    u8 *block;
    u8 *indexTriple;
    u8 *result;
    s32 material;
    s32 indicesPerRow;

    columns = verticesPerRow & 0xFFFF;
    if (columns < 2) {
        kAssertFail(D_00713448, 0x7F);
    }
    triangleCount = trianglesPerRow & 0xFFFF;
    indicesPerRow = triangleCount * 3;
    rows = rowCount & 0xFFFF;
    block = (u8 *)GeometryBlockCreate(rows * columns, rows * triangleCount, flags);
    geometry = ((EffGeometryAtomic *)((EffGeometryBlock *)block)->atomicData.bytes)->geometry;
    material = ((EffGeometryBlock *)block)->materialData.signedValue;
    result = block;
    triangle = ((RpGeometry *)geometry)->triangles;
    vertexOffset = 0;
    rowIndex = 0;
    while (rowIndex < rows) {
        indexOffset = 0;
        firstVertex = vertexOffset & 0xFFFF;
        while (indexOffset < indicesPerRow) {
            indexTriple = (u8 *)indices + (indexOffset * 2);
            func_003c2130(geometry, triangle, (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[0]) & 0xFFFF, (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[1]) & 0xFFFF, (firstVertex + ((EffGeometryIndices *)indexTriple)->unk04) & 0xFFFF);
            func_003c2150(geometry, triangle, material);
            triangle += 8;
            indexOffset += 3;
        }
        vertexOffset = (vertexOffset + verticesPerRow) & 0xFFFF;
        rowIndex += 1;
    }
    return result;
}

// Creates a type-3 resource atomic and its frame; flag 0x80000 also installs the default plugin colour.
// FUN_004830F0
u8 *GeometryCreateAtomicFromResource(u16 resourceId, s32 flags) {
    /* A separate typed local keeps retail's reloads of the atomic link. */
    u8 *block;
    s32 frame;
    EffGeometryBlock *geometryBlock;

    chkmemAllocSiteTag(D_00713448, 0xA6);
    block = jtbl_008873E8[0](0x48, 0x40000);
    geometryBlock = (EffGeometryBlock *)block;
    ((EffGeometryBlock *)block)->kindData.signedHalf[0] = 3;
    ((EffGeometryBlock *)block)->flags = flags;
    ((EffGeometryBlock *)block)->vertexCounts.signedHalf[0] = 0;
    ((EffGeometryBlock *)block)->vertexCounts.half[1] = resourceId;
    ((EffGeometryBlock *)block)->materialData.signedValue = 0;
    ((EffGeometryBlock *)block)->atomicData.signedValue = func_003a2340(resourceId & 0xFFFF, flags, 2);
    frame = (s32)func_003e9320();
    ((EffGeometryBlock *)block)->frameData.signedValue = frame;
    RpAtomicSetFrame((RpAtomic *)geometryBlock->atomicData.bytes, (RwFrame *)frame);
    /* RenderWare registers the pointer slot at a runtime plugin displacement. */
    ((EffGeometryAtomicPlugin **)(geometryBlock->atomicData.bytes + iGpffffb610))[0]->unkB4 = 1;
    if (flags & 0x80000) {
        memcpy(((EffGeometryAtomicPlugin **)(geometryBlock->atomicData.bytes + iGpffffb610))[0]->color, D_00713460, 0x10);
        ((EffGeometryAtomicPlugin **)(geometryBlock->atomicData.bytes + iGpffffb610))[0]->flags |= 0x80000;
    }
    ((EffGeometryAtomicPlugin **)(geometryBlock->atomicData.bytes + iGpffffb610))[0]->flags |= 0x800000;
    ((EffGeometryAtomicPlugin **)(geometryBlock->atomicData.bytes + iGpffffb610))[0]->unk04 = 0;
    memset(block + 0x18, 0, 0x30);
    ((EffGeometryBlock *)block)->tag = 0x15;
    ((EffGeometryBlock *)block)->drawOwner.bytes = block;
    return block;
}

// Clones a block: type-3 blocks are rebuilt from the resource; others copy the vertex table into a new grid block.
// FUN_00483270
u8 *GeometryCloneBlock(u8 *source) {
    extern u8 *func_003c42b0(void *source, s32 value);
    extern s32 func_003c2150(u8 *source, u8 *value, s32 options);
    extern void func_003c22f0(void *source);
    u8 *self;
    u8 *copy;
    s32 material;
    s32 sourceTexture;
    s32 materialTexture;
    s32 triangleIndex;
    u8 *sourceGeometry;
    u8 *copyGeometry;
    u8 *sourceTriangle;
    u8 *copyTriangle;
    self = source;

    if (((EffGeometryBlock *)self)->kindData.half[0] & 2) {
        copy = GeometryCreateAtomicFromResource(((EffGeometryBlock *)self)->vertexCounts.half[1], ((EffGeometryBlock *)self)->flags);
        sourceTexture = ((EffGeometryMaterial *)((RpGeometry *)((EffGeometryAtomic *)((EffGeometryBlock *)self)->atomicData.bytes)->geometry)->materials[0])->texture;
        if (sourceTexture != 0) {
            copyGeometry = ((RpGeometry *)((EffGeometryAtomic *)((EffGeometryBlock *)copy)->atomicData.bytes)->geometry)->materials[0];
            func_003c42b0(copyGeometry, sourceTexture);
        }
    } else {
        copy = GeometryBlockCreate(((EffGeometryBlock *)self)->vertexCounts.signedHalf[0], ((EffGeometryBlock *)self)->vertexCounts.signedHalf[1],
                               ((EffGeometryBlock *)self)->flags);
        material = ((EffGeometryBlock *)copy)->materialData.signedValue;
        sourceGeometry = ((EffGeometryAtomic *)((EffGeometryBlock *)self)->atomicData.bytes)->geometry;
        copyGeometry = ((EffGeometryAtomic *)((EffGeometryBlock *)copy)->atomicData.bytes)->geometry;
        materialTexture = ((EffGeometryMaterial *)((EffGeometryBlock *)self)->materialData.bytes)->texture;
        if (materialTexture != 0) {
            func_003c42b0((void *)(u32)material, materialTexture);
        }
        RpGeometryLock((RpGeometry *)sourceGeometry, 1);
        sourceTriangle = ((RpGeometry *)sourceGeometry)->triangles;
        copyTriangle = ((RpGeometry *)copyGeometry)->triangles;
        triangleIndex = 0;
        while (triangleIndex < ((EffGeometryBlock *)self)->vertexCounts.signedHalf[1]) {
            ((EffGeometryTriangle *)copyTriangle)->firstVertex.half[0] = ((EffGeometryTriangle *)sourceTriangle)->firstVertex.half[0];
            ((EffGeometryTriangle *)copyTriangle)->firstVertex.half[1] = ((EffGeometryTriangle *)sourceTriangle)->firstVertex.half[1];
            ((EffGeometryTriangle *)copyTriangle)->thirdVertex = ((EffGeometryTriangle *)sourceTriangle)->thirdVertex;
            func_003c2150(copyGeometry, copyTriangle, material);
            sourceTriangle += 8;
            copyTriangle += 8;
            triangleIndex += 1;
        }
        func_003c22f0(sourceGeometry);
    }
    return copy;
}

// Releases the block's atomic or geometry (chosen by flag 2), its frame and its texture slot, then the block.
// FUN_004833F0
void GeometryBlockDestroy(void *block) {
    s32 resource = ((EffGeometryBlock *)block)->atomicData.signedValue;
    if (resource != 0) {
        if (((EffGeometryBlock *)block)->kindData.half[0] & 2) {
            func_003a2760((u8 *)(resource));
        } else {
            func_003c02e0((u8 *)(resource));
        }
    }
    resource = ((EffGeometryBlock *)block)->frameData.signedValue;
    if (resource != 0) {
        func_003e9390(resource);
    }
    resource = ((EffGeometryBlock *)block)->materialData.signedValue;
    if (resource != 0) {
        func_003c4220(resource);
    }
    jtbl_008873EC[0](block);
}

// Clears the node links (nodeNext/nodePrevious) and appends the block to the resource's node list.
// FUN_00483490
void GeometryBlockBindResource(u8 *block, s32 resourceId) {
    s32 nodeList = TnGetOffset1C(resourceId);

    ((EffGeometryBlock *)block)->nodeNext = 0;
    ((EffGeometryBlock *)block)->nodePrevious = 0;
    PrimAppendNode(nodeList, block + 0x18);
}

// Selects the atomic's paired material settings for states zero through six; other states assert.
// FUN_004834E0
void GeometryBlockSetPartState(u8 *block, s32 state) {
    EffGeometryBlock *geometryBlock = (EffGeometryBlock *)block;
    /* The byte cursor and typed local stay distinct so register allocation across calls follows
     * retail. */
    if (((EffGeometryBlock *)block)->kindData.half[0] & 2) {
        switch (state & 0xFFFF) {
        case 0:
            func_003a2950(geometryBlock->atomicData.words, 2, 0x717FB);
            func_003a2950(((EffGeometryBlock *)block)->atomicData.words, 1, 0x44);
            break;
        case 1:
            func_003a2950(geometryBlock->atomicData.words, 2, 0x71801);
            func_003a2950(((EffGeometryBlock *)block)->atomicData.words, 1, 0x44);
            break;
        case 2:
            func_003a2950(geometryBlock->atomicData.words, 2, 0x71801);
            func_003a2950(((EffGeometryBlock *)block)->atomicData.words, 1, 0x48);
            break;
        case 3:
        case 4:
            func_003a2950(geometryBlock->atomicData.words, 2, 0x71801);
            func_003a2950(((EffGeometryBlock *)block)->atomicData.words, 1, 0x42);
            break;
        case 5:
        case 6:
            func_003a2950(geometryBlock->atomicData.words, 2, 0x71801);
            func_003a2950(((EffGeometryBlock *)block)->atomicData.words, 1, 6);
            break;
        default:
            kAssertFail(D_00713448, 0x14C);
            break;
        }
    }
}

// Build the incoming transform and apply it to the block's frame.
// FUN_00483660
void GeometryBlockSetFrameMatrix(u8 *block, RwV3d *translation, void *basis, f32 scale)
{
    RwMatrix matrix;

    GeometryMatrixBuild(&matrix, translation, basis, scale);
    func_003e9cb0(((EffGeometryBlock *)block)->frameData.pointer, &matrix, 0);
}


// Build the incoming combined transform and apply it to the block's frame.
// FUN_004836B0
void GeometryBlockSetFrameMatrixCombined(u8 *block, RwV3d *translation, void *basis, RwV3d *scale)
{
    RwMatrix matrix;

    GeometryMatrixBuildCombined(&matrix, translation, basis, scale);
    func_003e9cb0(((EffGeometryBlock *)block)->frameData.pointer, &matrix, 0);
}


// Transform: copies the source matrix or the identity, applies scale scalar when it is not 1.0, then translates by value.
// FUN_00483700
void GeometryMatrixBuild(RwMatrix *matrix, RwV3d *translation, void *basis, f32 scale) {
    f32 vector[3];

    if (basis != 0) {
        mdlEffectBuildBasisRows(matrix, basis);
    } else {
        matrix->at.z = 1.0f;
        matrix->up.y = 1.0f;
        matrix->right.x = 1.0f;
        matrix->up.x = 0.0f;
        matrix->right.z = 0.0f;
        matrix->right.y = 0.0f;
        matrix->at.y = 0.0f;
        matrix->at.x = 0.0f;
        matrix->up.z = 0.0f;
        matrix->pos.z = 0.0f;
        matrix->pos.y = 0.0f;
        matrix->pos.x = 0.0f;
        matrix->flags |= 0x20003;
    }
    if (scale != 1.0f) {
        vector[2] = scale;
        vector[1] = scale;
        vector[0] = scale;
        RwMatrixScale(matrix, vector, 2);
    }
    if (translation != 0) {
        vector[0] = translation->x;
        vector[1] = translation->y;
        vector[2] = translation->z;
        RwMatrixTranslate(matrix, vector, 2);
    }
}

// Scale matrix from context (identity when null), multiplied by the source basis when present, then translated by translation.
// FUN_00483810
void GeometryMatrixBuildCombined(RwMatrix *matrix, RwV3d *translation, void *basis, RwV3d *scale) {
    RwMatrix out;
    RwMatrix m;
    f32 v[3];

    if (scale != 0) {
        v[0] = scale->x;
        v[1] = scale->y;
        v[2] = scale->z;
        RwMatrixScale(&m, v, 0);
    } else {
        m.at.z = 1.0f;
        m.up.y = 1.0f;
        m.right.x = 1.0f;
        m.up.x = 0.0f;
        m.right.z = 0.0f;
        m.right.y = 0.0f;
        m.at.y = 0.0f;
        m.at.x = 0.0f;
        m.up.z = 0.0f;
        m.pos.z = 0.0f;
        m.pos.y = 0.0f;
        m.pos.x = 0.0f;
        m.flags |= 0x20003;
    }
    if (basis != 0) {
        mdlEffectBuildBasisRows(&out, basis);
        RwMatrixMultiply(matrix, &m, &out);
    } else {
        /* The 64-byte matrix is copied as eight word pairs, the same way retail does it. */
        s32 *sourceWords = (s32 *)&m;
        s32 *destinationWords;
        s32 pairCount;
        pairCount = 8;
        destinationWords = (s32 *)matrix;
        do {
            s32 firstWord = sourceWords[0];
            s32 secondWord = sourceWords[1];
            sourceWords += 2;
            pairCount -= 1;
            destinationWords[0] = firstWord;
            destinationWords[1] = secondWord;
            destinationWords += 2;
        } while (pairCount > 0);
    }
    if (translation != 0) {
        v[0] = translation->x;
        v[1] = translation->y;
        v[2] = translation->z;
        RwMatrixTranslate(matrix, v, 2);
    }
}

// Applies the texture resolved from translation to the block's material, then releases the handle.
// FUN_00483970
void GeometryBlockSetTextureFromHandle(u8 *block, u8 *handle) {
    s32 texture = TnUploadStreamTagged(handle);

    func_003c42b0(((EffGeometryBlock *)block)->materialData.words, texture);
    func_003ef3a0(texture);
}

// Copies words +0xC and +0x10 of the first texture entry into out[0] and out[1] and the texture into out[2]; null-safe.
// FUN_004839D0
void GeometryBlockGetTextureInfo(int block, u32 *info)
{
  int *texture;
  int raster;

  texture = (int *)((EffGeometryMaterial *)((EffGeometryBlock *)block)->materialData.bytes)->texture;
  info[2] = (u32)texture;

  if (texture != (int *)0x0) {
    raster = *texture;
    *info = ((EffGeometryRaster *)raster)->unk0C;
    info[1] = ((EffGeometryRaster *)raster)->unk10;
  }

  return;
}

// Multi-part block: partCount materials, geometry sized partCount x vertices and partCount x triangles, flags, bounding sphere at the origin.
// FUN_00483A00
u8 *GeometryCreateMultiPart(s32 partCount, s32 verticesPerPart, s32 trianglesPerPart, s32 flags)
{
    /* The count check uses the signed interpretation of the low product word. */
    if ((s32)((u32)(verticesPerPart & 0xFFFF) * (partCount & 0xFFFF)) > 0xFFFF) {
        kAssertFail(D_00713448, 459);
    }
    chkmemAllocSiteTag(D_00713448, 461);
    {
        RwSphere sphere;
        RwFrame *frame;
        RpMaterial **materials;
        u8 *effect;
        RpGeometry *geometry;
        RpAtomic *atomic;
        const s32 count = (u16)partCount;
        u16 index;
        RpMorphTarget *morphTarget;

        effect = jtbl_008873E8[0](count * 4 + 0x58, 0x40000);
        frame = func_003e9320();
        atomic = func_003c00e0();
        geometry = func_003c2630(
            (s32)((u32)(verticesPerPart & 0xFFFF) * (partCount & 0xFFFF)),
            (s32)((u32)(trianglesPerPart & 0xFFFF) * (s32)count), flags);
        materials = (RpMaterial **)(effect + 0x58);
        index = 0;
        while (index < count) {
            materials[index] = func_003c4140();
            index++;
        }
        RpAtomicSetFrame(atomic, frame);
        sphere.center.x = 0.0f;
        sphere.center.y = 0.0f;
        sphere.center.z = 0.0f;
        sphere.radius = fGpffff8078;
        morphTarget = ((RpGeometry *)geometry)->morphTarget;
        morphTarget->boundingSphere = sphere;
        func_003c0210(atomic, geometry, 0);
        func_003c2a80(geometry);
        ((EffGeometryBlock *)effect)->kindData.signedHalf[0] = 5;
        ((EffGeometryBlock *)effect)->flags = flags;
        ((EffGeometryBlock *)effect)->vertexCounts.signedHalf[0] = (s16)verticesPerPart;
        ((EffGeometryBlock *)effect)->vertexCounts.signedHalf[1] = (s16)trianglesPerPart;
        ((EffGeometryBlock *)effect)->frameData.pointer = frame;
        ((EffGeometryBlock *)effect)->atomicData.bytes = (u8 *)atomic;
        ((EffGeometryBlock *)effect)->materialData.signedValue = 0;
        ((EffGeometryMultiPart *)effect)->partCount.signedHalf[0] = (s16)partCount;
        ((EffGeometryMultiPart *)effect)->partCount.signedHalf[1] =
            (s16)(s32)((u32)(verticesPerPart & 0xFFFF) * (partCount & 0xFFFF));
        ((EffGeometryMultiPart *)effect)->totalTriangles.signedHalf[0] =
            (s16)(s32)((u32)(trianglesPerPart & 0xFFFF) * (s32)count);
        ((EffGeometryMultiPart *)effect)->materials = (s32)materials;
        ((EffGeometryMultiPart *)effect)->unk50.byte[1] = ((EffGeometryMultiPart *)effect)->unk50.byte[0] =
            ((EffGeometryMultiPart *)effect)->totalTriangles.byte[3] = ((EffGeometryMultiPart *)effect)->totalTriangles.byte[2] = 0xFF;
        memset(effect + 0x18, 0, 0x30);
        ((EffGeometryBlock *)effect)->tag = 0x15;
        ((EffGeometryBlock *)effect)->drawOwner.bytes = effect;
        return effect;
    }
}
// Multi-part table grid: partCount parts, each filled from the offset table flags and the per-part material handles.
// FUN_00483C40
u8 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow, s32 indices, s32 flags) {
    s32 columns;
    s32 triangles;
    u8 *block;
    u8 *indexTriple;
    s32 firstVertex;
    s32 rows;
    u8 *geometry;
    u8 *triangle;
    s32 rowIndex;
    s32 indexOffset;
    s32 partIndex;
    s32 vertexOffset;
    s32 indexTable;
    u8 *result;
    s32 indicesPerRow;
    s32 materials;
    s32 parts;
    u8 *materialSlot;

    indexTable = indices;
    columns = verticesPerRow & 0xFFFF;
    if (columns < 2) {
        kAssertFail(D_00713448, 0x20D);
    }
    triangles = trianglesPerRow & 0xFFFF;
    indicesPerRow = triangles * 3;
    rows = rowCount & 0xFFFF;
    block = (u8 *)GeometryCreateMultiPart(partCount, (rows * columns) & 0xFFFF, (rows * triangles) & 0xFFFF, flags);
    result = block;
    geometry = ((EffGeometryAtomic *)((EffGeometryBlock *)block)->atomicData.bytes)->geometry;
    materials = ((EffGeometryMultiPart *)block)->materials;
    triangle = ((RpGeometry *)geometry)->triangles;
    vertexOffset = 0;
    partIndex = 0;
    parts = partCount & 0xFFFF;
    while (partIndex < parts) {
        rowIndex = 0;
        materialSlot = (u8 *)(materials + (partIndex * 4));
        while (rowIndex < rows) {
            indexOffset = 0;
            firstVertex = vertexOffset & 0xFFFF;
            while (indexOffset < indicesPerRow) {
                indexTriple = (u8 *)(indexTable + (indexOffset * 2));
                func_003c2130(geometry, triangle, (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[0]) & 0xFFFF, (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[1]) & 0xFFFF, (firstVertex + ((EffGeometryIndices *)indexTriple)->unk04) & 0xFFFF);
                func_003c2150(geometry, triangle, *(s32 *)materialSlot);
                triangle += 8;
                indexOffset += 3;
            }
            vertexOffset = (vertexOffset + verticesPerRow) & 0xFFFF;
            rowIndex += 1;
        }
        partIndex += 1;
    }
    return result;
}

/* Multi-part strip grid: partCount parts, rowCount rows and verticesPerRow vertices per row,
 * triangles from the u16 table trianglesPerRow, flags indices. */
// FUN_00483E10
u8 *GeometryCreateStripGridMultiPart(s32 partCount, s32 rowCount, s32 indices, s32 verticesPerRow, s32 flags) {
    s32 segmentCount;
    u16 rows;
    s32 firstVertex;
    u8 *geometry;
    u8 *triangle;
    s32 rowIndex;
    s32 indexOffset;
    s32 partIndex;
    s32 vertexOffset;
    u8 *block;
    u8 *indexTriple;
    u8 *result;
    s32 indicesPerRow;
    s32 materials;
    s32 parts;
    u8 *materialSlot;

    if ((rowCount & 0xFFFF) < 2) {
        kAssertFail(D_00713448, 0x241);
    }
    if ((verticesPerRow & 0xFFFF) < 2) {
        kAssertFail(D_00713448, 0x242);
    }
    segmentCount = (verticesPerRow & 0xFFFF) - 1;
    indicesPerRow = segmentCount * 4 + segmentCount * 2;
    rows = (u16)rowCount;
    block = (u8 *)GeometryCreateMultiPart(partCount,
                                   ((rows + 1) * (verticesPerRow & 0xFFFF)) & 0xFFFF,
                                   (rows * (segmentCount * 2)) & 0xFFFF,
                                   flags);
    result = block;
    geometry = ((EffGeometryAtomic *)((EffGeometryBlock *)block)->atomicData.bytes)->geometry;
    materials = ((EffGeometryMultiPart *)block)->materials;
    triangle = ((RpGeometry *)geometry)->triangles;
    vertexOffset = 0;
    partIndex = 0;
    parts = partCount & 0xFFFF;
    while (partIndex < parts) {
        rowIndex = 0;
        materialSlot = (u8 *)(materials + (partIndex * 4));
        while (rowIndex < rows) {
            indexOffset = 0;
            firstVertex = vertexOffset & 0xFFFF;
            while (indexOffset < indicesPerRow) {
                indexTriple = (u8 *)(indices + (indexOffset * 2));
                func_003c2130(geometry, triangle,
                              (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[0]) & 0xFFFF,
                              (firstVertex + ((EffGeometryIndices *)indexTriple)->unk00.half[1]) & 0xFFFF,
                              (firstVertex + ((EffGeometryIndices *)indexTriple)->unk04) & 0xFFFF);
                func_003c2150(geometry, triangle, *(s32 *)materialSlot);
                triangle += 8;
                indexOffset += 3;
            }
            vertexOffset = (vertexOffset + verticesPerRow) & 0xFFFF;
            rowIndex += 1;
        }
        vertexOffset = (vertexOffset + verticesPerRow) & 0xFFFF;
        partIndex += 1;
    }
    return result;
}
