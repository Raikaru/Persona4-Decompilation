#include "model_motion_internal.h"
#include "texture_callback_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
/* Source unit: src/Graphics/Model/mdlManager_004711e0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c 0x003115a0 (verified MATCH there). */
/* W8 negative census corrected: 004776C0 is complete in C at 264B; its
   272B retail window has two zero words after jr/nop. 00475B90 (304B body
   plus jr/nop and two zero words) and 00473710 (332B body plus jr/nop and
   three zero words) likewise use placement padding, not missing logic.
   Remaining short probes are unresolved; do not add source-only padding.
   Best probes (object/window, nd): 00477810 232/240 nd169; 004776C0
   264/272 nd6; 00474BA0 316/320 nd153; 00475B90 304/320 nd147;
   00473710 332/352 nd202; 00477FB0 388/400 nd272. */
/* Keep optimization pragmas scoped to the functions whose retail code requires them. */
#include "type.h"
#include "model_matrix_internal.h"
#include "mdl_file_internal.h"
#include "rw/std/stddef.h"
#include "member_access.h"
#include "Kosaka/k_clump_internal.h"
#include "Kosaka/k_clump_draw_internal.h"
/* measured: index-first addu operand-order carrier (lever 3). Kept at top of
   file, OUTSIDE the opt_propagation pragma regions, so it inlines cleanly and
   does not emit a standalone symbol. */
static inline u32 mdlAddOffset(u32 offset, u32 base) { return offset + base; }
static inline f32 mdlMultiplyOrdered(f32 a, f32 b) { return a * b; }
extern f32 iGpffff8040;
extern f32 fGpffff809c;
extern u8 D_00713180[];
extern u8 D_007131A0[];
extern u8 D_007131C0[];
extern s32 K_Clump_MatUsrDataHasData(void* material, u8* name);
extern f32 K_Clump_MatUsrDataGetFloat(const RpMaterial* material, const char* name);
extern s32 mdlSeUpdateRecord(void** owner);

extern u32 RpHAnimFrameGetHierarchy(s32 object);
typedef void (*CallbackFn)(void);

extern s32 func_003b83d0(s32 object, s32 hierarchy);

extern void func_003e0e20(void *owner, void *input, s32 mode);
extern f32 DAT_0076112c;
extern void func_0039a260(void* a, void* b);
extern void func_0039ab20(void* a, int b, int c, int d);
extern int mdlComputeAttachMatrix(void* destination, void* tableData, u32 attachmentId, void* clumpData);
extern void* K_Clump_FindIntUsrDataFrame(void* object, const char* name, s32 value);
extern u8* func_003e9700(u8* a);
extern void func_003d5840(void* a, void* b);
extern u8* func_003d5790(s32 numNodes, s32 maxInterpKeyFrameSize);
extern s32 func_003d5e40(u8* a, f32 b);
extern void hMaestroUpdateClumpObjects(void* clump, void* context);

typedef struct RtAnimAnimation RtAnimAnimation;

typedef void (*RtAnimKeyFrameBlendCallBack)(void* voidOut, void* voidIn1, void* voidIn2, f32 alpha);

typedef struct RtAnimInterpolatorInfo RtAnimInterpolatorInfo;
struct RtAnimAnimation {
    RtAnimInterpolatorInfo *interpInfo;
    s32 numFrames;
    s32 flags;
    f32 duration;
    void *pFrames;
    void *customData;
};

typedef struct RtAnimInterpolator RtAnimInterpolator;

// 76 bytes. Layout from P3FES include/rw/rtanim.h.
struct RtAnimInterpolator
{
    RtAnimAnimation* pCurrentAnim;               // 0x00
    f32 currentTime;                             // 0x04
    void* pNextFrame;                            // 0x08
    void* pAnimCallBack;                         // 0x0c
    void* pAnimCallBackData;                     // 0x10
    f32 animCallBackTime;                        // 0x14
    void* pAnimLoopCallBack;                     // 0x18
    void* pAnimLoopCallBackData;                 // 0x1c
    s32 maxInterpKeyFrameSize;                   // 0x20
    s32 currentInterpKeyFrameSize;               // 0x24
    s32 currentAnimKeyFrameSize;                 // 0x28
    s32 numNodes;                                // 0x2c
    s32 isSubInterpoaltor;                       // 0x30
    s32 offsetInParent;                          // 0x34
    RtAnimInterpolator* parentAnimation;         // 0x38
    void* keyFrameApplyCB;                       // 0x3c
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB; // 0x40
    void* keyFrameInterpolateCB;                 // 0x44
    void* keyFrameAddCB;                         // 0x48
};

typedef int (*code)();

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern code DAT_00922ba0;
extern s32 DAT_00922ba4;
extern s32 DAT_00922ba8;
extern float* DAT_00922bac;
extern code DAT_00922ba0_abs[];
extern u8 DAT_00922ba4_abs[];
extern u8 DAT_00922ba8_abs[];
extern u8 DAT_00922bac_abs[];
extern f32 D_00922BB0_abs[];
extern f32 D_00922BB4_abs[];
extern u8 D_00922BC0;
extern u8 D_00922BC0_abs[];

extern void RwMatrixScale(void* matrix, const RwV3d* scale, int combineOp);

extern u32 RpMatFXMaterialGetEffects();
extern s32 func_0039b6e0(s32 owner);

extern u32 func_003b83f0(int object);
extern s32 func_003b85b0(u8* object);
extern void func_003b8520(u8* object, s32 value);
extern s32 func_00399b10(s32 object);
extern u32 func_003b8500(int object);
extern void mdlSetupMatFXMaterial(int material);

typedef struct MdlAnimResourceEntry
{
    void* resource;
    u8 flags;
    u8 unk_05[3];
} MdlAnimResourceEntry;

/* Eight-byte material table header, confirmed by the loader allocation. */
typedef struct MdlAnimEntryTable
{
    MdlAnimResourceEntry* entries; // 0x00
    u16 count;             // 0x04
    u16 references;            // 0x06
} MdlAnimEntryTable;

// 8 bytes


extern void mdlMatAnimFreeList(int list);
extern void (*DAT_008873ec[])(void* memory);

extern s32 func_003df7f0(u8* owner);
extern void func_003d6230();

extern s32 func_003df890(s32* owner);
extern void* func_003df8a0();
extern void* func_003df6e0(void* list, s32 index);

extern void func_003c21e0(u32 object, u32 input, u32 mode);
extern void func_003d5e40_typed(f32 frame, void* interpolator);

extern s32 func_003bd0b0(u8* object, s32 index);
extern int strcmp(const char* s1, const char* s2);
extern char DAT_007641c8[1];

extern u32 func_003df5d0();
extern int mdlAppendUniqueListEntry(int entry, void* listData);
extern void* mdlMatFXSetEnvMapValueCallback(void*, void*);
extern void* mdlMatFXSetEnvMapStateCallback(void*, void*);
extern void* mdlDrawAtomicIfVisible(void*, void*);
extern void* mdlSetFrameColorIfNamed(void* atomic, void* context);
extern void* mdlForEachAtomicListEntry(void* atomic, void* data);
extern u32 mdlGetFrameNameUserData(void* frame);
extern int strncmp();
extern int func_003d8130();
extern void RtAnimInterpolatorSetAnimLoopCallBack();
extern void* mdlAnimLoopCallback(void* interpolator, void* control);
extern char gp0xffff9d10;
extern u8 LAB_00474a50;
extern u8 LAB_00474a50_abs[];
extern u8 LAB_00474a90;
extern u8 LAB_00474a90_abs[];

extern s32 func_00397470(u8* frame);
extern void RwMatrixMultiply(void* a, void* b, void* c);

extern void K_Clump_EnsureMatColorUsrData(u8* material);
extern void* mdlMatColorScaleCallback(void* atomic, void* context);
extern u8 D_00713160[];
extern s32 K_Clump_CountIntUsrData(void* object, const char* name);
extern u8 D_007131D8[];
extern f32 DAT_00761130;
extern u8 D_00713138[];
extern u8 D_007241d0;
extern void func_00440b68(void* a, void* b, int c);
extern u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags);
extern void chkmemAllocSiteTag(const void* file, s32 line);
extern void* memset(void* destination, int value, size_t count);
extern void* DAT_008873e8[];
extern s64 DAT_00723cd8;
extern void mdlDestroyModelObject(u8* model);
extern void mdlEffectEmitTagPair(void);
extern s32 mdlPrepareModel(u8* model);
extern void* func_003bfae0(void);
extern int RwCameraFrustumTestSphere(void* a, void* b);
extern void* D_008872E0[];
extern void mdlAllocAuxBlock(void* model);
extern void mdlSetAuxResource(void* model, void* path);
extern void mdlSetAuxPair(void* model, void* pairData);
typedef void (*FnVoidPtr)(void*);

extern s32 K_Clump_MatUsrDataGetInt(const RpMaterial* material, const char* name);

typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
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

/* RwOpCombineType from rw/plcore/bamatrix.h; RWFORCEENUMSIZEINT is 0x7FFFFFFF. */
enum RwOpCombineType
{
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
};
typedef enum RwOpCombineType RwOpCombineType;

extern RwMatrix* RwMatrixTranslate(RwMatrix* matrix, const RwV3d* translation, RwOpCombineType combineOp);
struct RwMatrixTag;
extern struct RwMatrixTag* RwMatrixRotate(struct RwMatrixTag* matrix, const RwV3d* axis, f32 angle, RwOpCombineType combineOp);

// 12-byte attached-weapon slot: flags at 0x00, model at 0x04, signed frame ID at 0x08.
typedef struct MdlWpnSlot
{
    u8 flags;      // 0x00
    u8 pad1[3];    // 0x01..0x03
    void* wpnMdl; // 0x04
    s32 frameID;   // 0x08
} MdlWpnSlot;

// Model: mat 0x00, identityMat 0x40, scale 0x80, color 0xd0, clump 0xdc (layout from P3FES include/Graphics/Model/mdlManager.h).
/* SDK layouts: bamateri.h, bageomet.h and baclump.h. The full headers
 * conflict with this unit's existing matrix/vector definitions. */
typedef struct MdlMaterial {
    void *texture;
    RwRGBA color;
    void *pipeline;
    RwV3d surfaceProperties;
} MdlMaterial;

typedef struct MdlMorphTarget {
    void *geometry;
    RwV3d center;
    f32 radius;
    void *vertices;
    void *normals;
} MdlMorphTarget;

typedef struct MdlGeometry {
    u8 pad00[8];
    u32 flags;
    u8 pad0C[0xC];
    s32 morphTargetCount;            /* 0x18 */
    s32 texCoordSetCount;
    MdlMaterial **materials;         /* 0x20 */
    u32 count;
    u8 pad28[0x34];
    u8 *morphTargets;                /* 0x5c; stride 0x1c */
} MdlGeometry;



/* Four directional clips and their interpolators; allocation is 0x4c bytes.
 * The final eight bytes are loaded from the controller chunk at +0x3c. */
typedef struct MdlDirectionalBlend {
    u8 *animations[4];
    u8 *interpolators[4];
    f32 rotation[4];
    f32 weight;
    f32 duration;
    f32 progress;
    u16 unk3C;
    u16 yawRange;
    u16 unk40;
    u16 initialized;
    u32 selected;
    f32 fadeWeight;
} MdlDirectionalBlend;

/* HAnim keyframe prefix: header, quaternion, then translation. */
typedef struct MdlKeyFrame {
    u8 header[8];
    f32 rotation[4];
    RwV3d translation;
    u8 pad24[0xc];
    f32 blendWeight;
} MdlKeyFrame;

/* Callback records built by the clump wrappers below. */
/* Direct resource inputs expose this memory/byte-count pair. The archive
 * alternative is accessed only through H_Cdvd_GetArchiveEntry. */
typedef struct MdlResourceSource {
    u8 pad000[0x110];
    void *memory;
    u8 pad114[4];
    u32 byteCount;
} MdlResourceSource;

/* RwStream.Type.memory.position (bastream.h); this loader opens memory streams. */
typedef struct MdlMemoryStream {
    u8 pad00[0xC];
    u32 position;
} MdlMemoryStream;

/* Material-animation state is the pair at Model +0x234. */
typedef struct MdlMaterialTrack {
    MdlAnimEntryTable *resource;
    void *active;
} MdlMaterialTrack;

typedef struct MdlMemoryPair {
    void *memory;
    u32 byteCount;
} MdlMemoryPair;

typedef struct MdlColorScale {
    const RwRGBA *color;
    u16 flags;
} MdlColorScale;

typedef struct MdlNamedColor {
    u8 alpha;
    u8 pad01[3];
    const char *name;
} MdlNamedColor;

/* The loader allocates 0x2b8 bytes for this properties chunk. Only these
 * scale operands and sixteen unsigned node counters have known consumers. */
typedef struct MdlScaleProperties {
    u8 pad000[0x184];
    f32 scaleDivisorX;
    f32 scaleDivisorYZ;
    f32 scaleFactor;
    f32 aspectFactor;
    u8 pad194[4];
    u16 nodeCounts[16];
    u8 pad1B8[0x100];
} MdlScaleProperties;

typedef struct MdlDispatchAnimEntry {
    RwMatrix matrix;
    void* animation;
    u32 unknown44;
    u8* blendControl;
    s32* startFrame;
} MdlDispatchAnimEntry;

typedef struct MdlDispatchAnimTable {
    MdlDispatchAnimEntry* entries;
    u32 unknown; /* base animation address, zero when absent */
    u16 count;
    u16 references;
    u8 pad0C[4];
} MdlDispatchAnimTable;

typedef struct MdlCloneAttachmentTable {
    union {
        u32 word;
        struct {
            u16 count;
            u16 unknown02;
        } halves;
    } count;
    RwRGBA color;                  /* 0x04 */
    RwV3d scale;                   /* 0x08 */
    void** primary;                 /* 0x14 */
    void* primaryDraw;             /* 0x18 */
    void* nextPrimary;             /* 0x1c */
    void** secondary;               /* 0x20 */
    void* secondaryDraw;           /* 0x24 */
    void* nextSecondary;           /* 0x28 */
    u32 pendingSecondary;          /* 0x2c */
    u16 delay;                     /* 0x30 */
    u16 unknown32;                 /* 0x32 */
} MdlCloneAttachmentTable;

/* One pointer-sized attachment slot selected from the primary/secondary arrays. */
typedef struct MdlAttachmentSlot { void *object; } MdlAttachmentSlot;

typedef struct MdlAnimResource {
    MdlAnimResourceEntry* entries;
    u32 unknown04; /* base UV dictionary address */
    void* objects;
    u16 count;
    u16 references;
} MdlAnimResource;

typedef struct MdlAnimControl {
    u16 flags;
    u8 mode;
    u8 unknown03;
    s16 index;
    u16 unknown06;
    f32 speed;
    f32 primaryTime;
    f32 secondaryTime;
    u16 ticks;
    u16 unknown16;
    MdlAnimResource* resource;
} MdlAnimControl;

/* Slot initialization, animation dispatch and controller setters prove this
 * 0xa4-byte layer record. Controller offsets below are relative to +0x54. */
typedef struct MdlLookState {
    u16 flags;
    u16 unk02;
    f32 blend;
    f32 pitchLimit;
    f32 yawLimit;
    f32 rotation[4];
    f32 limitedRotation[4];
    RwV3d scale;
    RwV3d target;
    f32 yawOffset;
    f32 pitchOffset;
} MdlLookState;

/* Contiguous scale-hook parameters beginning at the layer's scaleNode. */
typedef struct MdlHierarchyScale {
    s32 node;
    RwV3d scale;
    f32 modelScale;
    f32 aspect;
} MdlHierarchyScale;

typedef struct MdlLayerState {
    u16 flags;
    u8 finished;
    u8 unk03;
    s16 animationIndex;
    u16 unk06;
    f32 speed;
    f32 time;
    s16 previousIndex;
    u16 unk12;
    f32 previousTime;
    u16 blendTicks;
    u16 unk1A;
    f32 blend;
    u8 *hierarchy;
    u8 *blendFrom;
    u8 *blendTo;
    u8 *rebaseInput;
    u8 *rebaseRotation;
    MdlDispatchAnimTable *resource;
    MdlCloneAttachmentTable *attachments;
    s32 scaleNode;
    RwV3d scale;
    f32 modelScale;
    f32 aspect;
    MdlLookState look;
} MdlLayerState;

/* RwFrame prefix used by hierarchy traversal and clump-root lookups. */
typedef struct MdlFrame {
    u8 type, subType, flags, privateFlags;
    u8 *parent;
    u8 pad08[8];
    RwMatrix modelling;
    RwMatrix localToWorld;
    u8 pad90[0x10];
    u8 *root;
} MdlFrame;

/* RwObject prefix from batype.h; clumps and lights store their frame in parent. */
typedef struct RwObject {
    u8 type, subType, flags, privateFlags;
    void *parent;
} RwObject;

/* Auxiliary loader work is allocated as 0x48 bytes by mdlAllocAuxBlock. */
typedef struct MdlLoaderMaterial {
    u32 kind;
    u16 slot;
    void *stream;
    struct MdlLoaderMaterial *next;
} MdlLoaderMaterial;

typedef struct MdlLoaderState {
    void *stream;
    u8 *textureRequest;
    u8 *uvRequest;
    u8 **uvRequests;
    u8 *clumpRequest;
    void *clumpStream;
    MdlLoaderMaterial *materials;
    u16 layer, slot;
    u16 capacities[2];
    s16 *cloneSlots[2];
    u8 *memory;
    u32 memoryLength;
    u32 *textureList;
    u8 *fileRequest;
    u32 unknown3c;
    s32 mode;
    s32 baseAnimation;
} MdlLoaderState;

typedef struct MdlLoaderEntry {
    void *value;
    u32 flags;
} MdlLoaderEntry;

typedef struct MdlLoaderMaterialTable {
    MdlLoaderEntry *entries;
    u16 count, references;
} MdlLoaderMaterialTable;

typedef struct MdlLoaderUvTable {
    MdlLoaderEntry *entries;
    void *base;
    void *objects;
    u16 count, references;
} MdlLoaderUvTable;

typedef struct MdlMatrixEntry {
    RwMatrix matrix;
    s32 id;
    s32 frameId;
    u8 unknown[8];
} MdlMatrixEntry;

typedef struct MdlMatrixTable {
    u16 count;
    u16 unknown;
    MdlMatrixEntry* entries;
} MdlMatrixTable;

typedef struct Model
{
    RwMatrix mat;                 /* 0x000 */
    RwMatrix identityMat;         /* 0x040 */
    RwV3d scale;                  /* 0x080 */
    u8 pad8C[4];
    RwMatrix attachmentMatrix;    /* 0x090 */
    RwRGBA color;                 /* 0x0d0 */
    u16 type;
    u16 id;
    u32 flags;
    void *clump;                  /* 0x0dc */
    void *drawBuckets;
    s32 skyAlpha;
    s32 skyTest;
    MdlLayerState layers[2];      /* 0x0ec; stride 0xa4 */
    MdlAnimEntryTable *materialResource; /* 0x234 */
    void *materialAnimation;
    MdlAnimControl animControl; /* 0x23c */
    u16 unk258;
    u8 unk25A;
    u8 unk25B;
    f32 unk25C;
    u8 drawFlags;                 /* 0x260 */
    u8 pad261[3];
    f32 drawRotation[4];
    f32 limit;
    f32 targetLimit;
    f32 limitRate;
    u8 alpha;
    u8 targetAlpha;
    u8 alphaStep;
    u8 unk283;
    f32 minBlend;
    f32 maxAngle;
    MdlWpnSlot attachedWpns[5];    /* 0x28c; stride 0xc */
    void *matrixTable;            /* 0x2c8 */
    void *effects;
    MdlMotionState motion;        /* 0x2d0 */
    void *queue;
    void *owner;
    RwRGBA effectColor;
    void *previous;
    void *next;
    u8 *auxiliary;                /* 0x30c */
    void *drawCallback;
    void *drawData;
    void *resetCallback;
    void *resetData;
} Model;

typedef char MdlModelSize[(sizeof(Model) == 0x320) ? 1 : -1];
typedef char MdlLayerStateSize[(sizeof(MdlLayerState) == 0xA4) ? 1 : -1];
typedef char MdlLookStateSize[(sizeof(MdlLookState) == 0x50) ? 1 : -1];
typedef char MdlLoaderStateSize[(sizeof(MdlLoaderState) == 0x48) ? 1 : -1];
typedef char MdlDirectionalBlendSize[(sizeof(MdlDirectionalBlend) == 0x4C) ? 1 : -1];
typedef char MdlDispatchAnimTableSize[(sizeof(MdlDispatchAnimTable) == 0x10) ? 1 : -1];
typedef char MdlAnimEntryTableSize[(sizeof(MdlAnimEntryTable) == 8) ? 1 : -1];
typedef char MdlScalePropertiesSize[(sizeof(MdlScaleProperties) == 0x2B8) ? 1 : -1];
typedef char MdlMaterialStateOffset[(offsetof(Model, materialResource) == 0x234) ? 1 : -1];
typedef char MdlAttachmentOffset[(offsetof(Model, attachedWpns) == 0x28C) ? 1 : -1];
typedef char MdlAuxiliaryOffset[(offsetof(Model, auxiliary) == 0x30C) ? 1 : -1];
typedef char MdlFrameRootOffset[(offsetof(MdlFrame, root) == 0xA0) ? 1 : -1];


extern void func_003e9cb0(void* frame, void* transform, u32 combine);
extern void mdlSetAttachedModelMatrices(Model* model, RwMatrix* matrix);
extern void mdlDetachSlotModel(u8* model, u16 slotIndex);
extern void mdlEffectListCallFlagged();
extern void mdlNoopSecondaryEffect();
extern void mdlInitObjectSlots(u8* state);
extern void mdlSetAttachedSlotValue(u8* model, u16 slotIndex, s32 frameId);
extern s32 iGpffffbb28;
extern f32 iGpffff80cc;
extern void* mdlAllocModelObject(u32 type, u16 id);
extern s32 mdlLayerIsPresent(void* model, s32 layer);
extern u32* func_003971d0(u8*, s32, s32, s32);
extern void* sdkClumpCreateBuckets(void* sourceClump);
extern void mdlEffectListRefreshHandles();
extern void* func_003c0520();
extern u32 *mdlEffectListCopy(u32 **source);
extern u32 *mdlEffectListWrapShared(u32 **source);
extern void mdlRetainObject();
extern s32 mdlPrepareSlotModel(u8* model, u16 slotIndex);
extern void mdlCopyModelState(u8* source, u8* destination);
extern void mdlSetAuxValue(void* model, int value);




/* measured: mwcc b210 rematerializes the 1.0f and 0x20003 constants inside the
   loop body; #pragma opt_loop_invariants on hoists both to function top to
   match retail (nd 54 -> 0). */
/* Allocates a dispatch anim table: a 16-byte header plus owner entries of 0x50 bytes each, zeroed. Callers create one lazily per layer. */
/* measured: keep the count store before identity initialization
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00470E90
#pragma opt_loop_invariants on
u8* mdlDispatchAnimTableCreate(u16 count)
{
    s32 size;
    u8* table;
    u32 entryIndex;

    size = (s32)count * 0x50 + 0x10;
    chkmemAllocSiteTag(D_00713138, 0x142);
    table = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
    memset(table, 0, size);
    *(u8* *)&((MdlDispatchAnimTable *)table)->entries = table + 0x10;
    MEMBER(u16, table, MdlDispatchAnimTable, count) = count;
    for (entryIndex = 0; entryIndex < ((MdlDispatchAnimTable *)table)->count; entryIndex++) {
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.at.z = 0x3F800000;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.up.y = 0x3F800000;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.right.x = 0x3F800000;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.up.x = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.right.z = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.right.y = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.at.y = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.at.x = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.up.z = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.pos.z = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.pos.y = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.pos.x = 0;
        *(s32 *)&((MdlDispatchAnimEntry *)(*(u8* *)&((MdlDispatchAnimTable *)table)->entries + entryIndex * 0x50))->matrix.flags |= 0x20003;
    }
    *(s16 *)&((MdlDispatchAnimTable *)table)->references = 1;
    return table;
}
#pragma opt_loop_invariants off

/* MATCHED this wave (nd 0, object 452B/window 464B): the former CSE-of-mask
   floor was disproved.  `#pragma opt_common_subs off`, declaration order
   animationIndex, entryBlendControl, clipIndex, interpolatorIndex, and explicit (u32) inner guards reproduce
   the retail body masks and sltiu tests; the prior nd~6 omission is gone. */
/* measured: opt_common_subs off probe for repeated u16 counter masks. */
#pragma opt_common_subs off
/* Drops one reference on a dispatch anim table (count at +0xA). On the last release it cleans up the table's entries and then the table. */
// FUN_00471010
void mdlDispatchAnimTableRelease(u8* table)
{
    extern s32 func_003d5300(u8* table);
    extern void func_003d5830(u8* value);
    s32 offset;
    u8* baseAnimation;
    u8* entryAnimation;
    u8* blendInterpolator;
    s32 animationIndex;
    u8* entryBlendControl;
    s32 clipIndex;
    s32 interpolatorIndex;
    u8* animationEntry;
    u8* frameMetadata;

    ((MdlDispatchAnimTable *)table)->references -= 1;
    if (((MdlDispatchAnimTable *)table)->references == 0) {
        baseAnimation = *(u8* *)&((MdlDispatchAnimTable *)table)->unknown;
        if (baseAnimation != (u8*)0) {
            func_003d5300(baseAnimation);
        }
        animationIndex = 0;
        goto entryLoopCheck;
entryLoopBody:
        animationEntry = *(u8* *)&((MdlDispatchAnimTable *)table)->entries;
        offset = (animationIndex & 0xFFFF) * 0x50;
        animationEntry += offset;
        entryAnimation = *(u8* *)&((MdlDispatchAnimEntry *)animationEntry)->animation;
        if ((entryAnimation != (u8*)0) &&
            ((((MdlDispatchAnimEntry *)animationEntry)->unknown44 & 1) == 0) &&
            (entryAnimation != (u8*)D_00922BC0_abs)) {
            func_003d5300(entryAnimation);
            animationEntry = *(u8* *)&((MdlDispatchAnimTable *)table)->entries;
            animationEntry += offset;
            entryBlendControl = ((MdlDispatchAnimEntry *)animationEntry)->blendControl;
            if (entryBlendControl != (u8*)0) {
                clipIndex = 0;
                goto clipLoopCheck;
clipLoopBody:
                func_003d5300(((MdlDirectionalBlend *)(entryBlendControl + ((clipIndex & 0xFFFF) * 4)))->animations[0]);
                clipIndex = (clipIndex + 1) & 0xFFFF;
clipLoopCheck:
                if ((u32)(clipIndex & 0xFFFF) < 4) {
                    goto clipLoopBody;
                }
                interpolatorIndex = 0;
                goto interpolatorLoopCheck;
interpolatorLoopBody:
                blendInterpolator = ((MdlDirectionalBlend *)(entryBlendControl + ((interpolatorIndex & 0xFFFF) * 4)))->interpolators[0];
                if (blendInterpolator != (u8*)0) {
                    func_003d5830(blendInterpolator);
                }
                interpolatorIndex = (interpolatorIndex + 1) & 0xFFFF;
interpolatorLoopCheck:
                if ((u32)(interpolatorIndex & 0xFFFF) < 4) {
                    goto interpolatorLoopBody;
                }
                DAT_008873ec[0](entryBlendControl);
            }
            animationEntry = *(u8* *)&((MdlDispatchAnimTable *)table)->entries;
            animationEntry += offset;
            frameMetadata = *(u8* *)&((MdlDispatchAnimEntry *)animationEntry)->startFrame;
            if (frameMetadata != (u8*)0) {
                DAT_008873ec[0](frameMetadata);
            }
        }
        animationIndex = (animationIndex + 1) & 0xFFFF;
entryLoopCheck:
        if ((animationIndex & 0xFFFF) < ((MdlDispatchAnimTable *)table)->count) {
            goto entryLoopBody;
        }
        DAT_008873ec[0](table);
    }
}
/* measured: closes opt_common_subs off probe around mdlDispatchAnimTableRelease. */
#pragma opt_common_subs on
/* Looks up the HAnim hierarchy of frame object. If none exists it queues the frame with func_003e9af0, using this function as the callback, and returns the frame. Otherwise it stores the hierarchy in *data and returns NULL. */
// FUN_004711E0
void* mdlFindFrameHierarchy(void* frame, void* hierarchyOut)
{
    u32 value;

    value = RpHAnimFrameGetHierarchy((s32)frame);
    if (value != 0)
    {
        goto store_value;
    }
    func_003e9af0(frame, mdlFindFrameHierarchy, hierarchyOut);
    return frame;
store_value:
    *(u32*)hierarchyOut = value;
    return NULL;
}



/* Per-atomic callback for RpClumpForAllAtomics: attaches hierarchy to atomic frame through func_003b83d0 and returns the atomic. Passed as a function pointer by the clump hierarchy setup. */
// FUN_00471250
void* mdlSetAtomicHierarchy(void* atomic, void* hierarchy)
{
    func_003b83d0((s32)atomic, (s32)hierarchy);
    return atomic;
}



/* Blends two animation interpolators' keyframe state for one frame, with blend factor atomic. The layer update calls it with 1.0f when a second animation is present. */
// FUN_00471280
u32 mdlBlendAnimInterpolators(RtAnimInterpolator* destination, RtAnimInterpolator* first,
                  RtAnimInterpolator* second, f32 blend)
{
    s32 frame;
    s32 offset2;
    s32 offset3;
    s32 offset4;
    f32 alpha;
    u8* out;
    u8* in1;
    u8* in2;
    u8* in2Out;
    offset2 = destination->offsetInParent;
    offset3 = first->offsetInParent;
    offset4 = second->offsetInParent;
    for (frame = offset2; frame < destination->numNodes + destination->offsetInParent; frame++)
    {
        in2 = (u8*)(second->currentInterpKeyFrameSize * (frame - offset4) -
                     (0u - (u32)second)) + 0x4c;
        out = (u8*)(destination->currentInterpKeyFrameSize * (frame - offset2) -
                    (0u - (u32)destination));
        in1 = (u8*)(first->currentInterpKeyFrameSize * (frame - offset3) -
                    (0u - (u32)first));
        alpha = ((MdlKeyFrame *)in2)->blendWeight;
        destination->keyFrameBlendCB(out + 0x4c, in1 + 0x4c, in2,
                                 blend * alpha);
    }
    return 1;
}



/* Hierarchy controller update. blend is an RpHAnimHierarchy, destination/first
 * the model state and controller halfwords, second an optional parent matrix. */
/* Layout from include/rw/inc/rphanim.h. */
typedef struct RpHAnimNodeInfo
{
    s32 nodeID;              /* 0x00 */
    s32 nodeIndex;           /* 0x04 */
    s32 flags;               /* 0x08 */
    struct RwFrame *pFrame;  /* 0x0c */
} RpHAnimNodeInfo;

/* Layout from include/rw/inc/rphanim.h. */
typedef struct RpHAnimHierarchy RpHAnimHierarchy;
struct RpHAnimHierarchy
{
    s32 flags;                           /* 0x00 */
    s32 numNodes;                        /* 0x04 */
    RwMatrix *pMatrixArray;              /* 0x08 */
    void *pMatrixArrayUnaligned;         /* 0x0c */
    RpHAnimNodeInfo *pNodeInfo;          /* 0x10 */
    struct RwFrame *parentFrame;         /* 0x14 */
    RpHAnimHierarchy *parentHierarchy;   /* 0x18 */
    s32 rootParentOffset;                /* 0x1c */
    RtAnimInterpolator *currentAnim;     /* 0x20 */
};

#pragma push
/* measured: without opt_loop_invariants the per-node mode masks are not hoisted
 * (554 fnalign edits); opt_lifetimes gives the s0/s1 list-walk colours (+9 without). */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
static inline u32 mdlTableEntryAddress(u32 offset, u32 base)
{
    return offset + base;
}

/* Read the scalar snapshot retained across the hierarchy callbacks. */
static inline u32 mdlAnimationFlag(const u32 *flag)
{
    return *flag;
}

/* measured: the parent matrix is a local assigned just before the node loop; the
 * copy coalesces into second, which then spills to a quadword slot as retail. */
/* Updates the hierarchy pose from the owner's animation flags: quaternion slerp and matrix composition over the nodes. Callers gate it on flags 0x81E0. Not every step has been traced. */
/* measured: keep the dispatch-entry cursor and the retained controller snapshots
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00471370
s32 mdlUpdateHierarchyPose(u8 *hierarchyData, u8 *layerState, u8 *controllerState, void *parentTransform)

{
    RwMatrix *parentMatrix;
    struct RtQuat;
    struct RtQuatSlerpCache;
    struct RwObjectOwnerLink;
    extern void *func_003d5790(int, int);
    extern s32 func_003e9240(struct RwObjectOwnerLink *); /* RwBool: retail tests the result unmasked */
    extern u8 * func_003e9700(u8 *);
    extern float func_0044b920(float);
    extern float func_0044b950(float, float);
    extern int func_003d5e40(unsigned char *, float);
    extern int func_003d5e90(unsigned char *, unsigned char *, unsigned char *, float);
    extern float effMiscQuatAngle(unsigned char *, unsigned char *);
    extern void func_003954b0(void *matrix, void *keyFrame);
    extern s32 func_00397c40(void* hierarchy);
    extern void func_003d5840(RtAnimInterpolator *, RtAnimAnimation *);
    extern s32 RtQuatConvertFromMatrix(struct RtQuat *, const RwMatrix *);
    extern struct RtQuat *func_003dc740(struct RtQuat *, const RwV3d *, f32, s32);
    extern RwV3d * RtQuatTransformVectors(RwV3d *, const RwV3d *, s32, const struct RtQuat *);
    extern void func_003dcc70(struct RtQuat *, struct RtQuat *, struct RtQuatSlerpCache *);
    extern RwMatrix * RwMatrixMultiply(RwMatrix *, const RwMatrix *, const RwMatrix *);
    extern RwMatrix * func_003e0960(RwMatrix *, const RwMatrix *);
    extern RwMatrix * RwMatrixScale(RwMatrix *, const RwV3d *, RwOpCombineType);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern RwV3d * func_003e42a0(RwV3d *, const RwV3d *, const RwMatrix *);
    extern RwV3d * func_003e4320(RwV3d *, const RwV3d *, const RwMatrix *);
    extern u8 * func_003e9680(u8 *);
    extern void func_003ed960(u8 *object);
/* Local declarations above follow the actual pointer/float call contracts. */
    extern s32 DAT_0088739c[];
    extern float DAT_00922bb0[];
    extern float DAT_00922bb4[];
    extern float fGpffff8040;
    extern float fGpffff8048;
    extern float fGpffff804c;
    extern float fGpffff8050;
    extern float fGpffff8054;
    extern float fGpffff8058;
    extern float fGpffff805c;
    extern float fGpffff8060;
    extern float fGpffff8064;
    extern float fGpffff8068;
    extern float fGpffff806c;
    extern float fGpffff8070;
    extern float fGpffff8074;
  typedef union { f32 value[4]; u32 bits[4]; } ControllerQuat;
  typedef struct { f32 from[4]; f32 to[4]; f32 omega; s32 nearlyZero; } ControllerSlerpCache;
  unsigned short controllerFlags;
  void (*applyKeyFrame)(void *matrix, void *keyFrame);
  unsigned int *blendControl;
  int *startFrame;
  float *outputMatrix;
  int workValue;
  unsigned int animationAddress;
  unsigned int interpolatorAddress;
  RpHAnimHierarchy *hierarchy;
  int nodeFrame;
  int frameValue;
  int frameOrStride;
  float *floatValues;
  float *nextFloatValues;
  unsigned int hierarchyFlags;
  unsigned char *sourceInterpolator;
  int keyFrameAddress;
  float *nodeParentMatrix;
  unsigned int *parentStackTop;
  unsigned int modeValue;
  unsigned int nodeValue;
  unsigned int cachedValue;
  float blendStep;
  float angleOrTime;
  /* Retail sp+0x100 is conditionally assigned at 004719dc/00471d7c/
   * 00471f0c and read at 00472280. Preserve that original lifetime. */
  int nodeIndex;
  unsigned int nodeInfoAddress;
  s32 hasParentMatrix;
  unsigned int parent;
  u32 animated;
  s32 resetAnimation;
  int limitRotation;
  RwMatrix baseMatrix;
  RwMatrix identityMatrix;
  unsigned int parentStack [31];
  RwMatrix scaleMatrix;
  RwMatrix ancestorMatrix;
  RwMatrix frameMatrix;
  RwMatrix axisMatrix;
  unsigned char rotationMatrix [64];
  unsigned char inverseBaseMatrix [64];
  RwMatrix localMatrix;
  ControllerQuat rotation;
  ControllerQuat negatedRotation;
  ControllerSlerpCache interpolation;
  ControllerQuat rotationSnapshot;
  ControllerQuat blendedRotation;
  ControllerQuat startRotation;
  ControllerQuat fallbackRotation;
  unsigned char inverseDirectionMatrix [64];
  
  u32 axis[3];
  RwV3d position;
  RwV3d workingVector;
  f32 look[3];
  f32 eye[3];
  f32 direction[3];
  u32 forwardAxis[3];

  typedef char ControllerPointerSize[(sizeof(void *) == 4) ? 1 : -1];
  typedef char ControllerMatrixSize[(sizeof(RwMatrix) == 64) ? 1 : -1];
  typedef char ControllerMatrixFlags[(offsetof(RwMatrix, flags) == 12) ? 1 : -1];
  typedef char ControllerMatrixUp[(offsetof(RwMatrix, up) == 16) ? 1 : -1];
  typedef char ControllerMatrixAt[(offsetof(RwMatrix, at) == 32) ? 1 : -1];
  typedef char ControllerMatrixPosition[(offsetof(RwMatrix, pos) == 48) ? 1 : -1];
  typedef char ControllerQuaternionSize[(sizeof(ControllerQuat) == 16) ? 1 : -1];
  typedef char ControllerCacheSize[(sizeof(ControllerSlerpCache) == 40) ? 1 : -1];
  typedef char ControllerCacheTo[(offsetof(ControllerSlerpCache, to) == 16) ? 1 : -1];
  typedef char ControllerCacheOmega[(offsetof(ControllerSlerpCache, omega) == 32) ? 1 : -1];
  typedef char ControllerCacheFlag[(offsetof(ControllerSlerpCache, nearlyZero) == 36) ? 1 : -1];
  typedef char ControllerPositionSize[(sizeof(position) == 12) ? 1 : -1];
  RtAnimInterpolator *poseInterpolator;
  MdlLookState *lookState = (MdlLookState *)controllerState;
  MdlLayerState *modelLayer = (MdlLayerState *)layerState;
  typedef char ControllerWorkingVectorSize[(sizeof(workingVector) == 12) ? 1 : -1];
  typedef char ControllerWorkingVectorX[(offsetof(RwV3d, x) == 0) ? 1 : -1];
  typedef char ControllerWorkingVectorY[(offsetof(RwV3d, y) == 4) ? 1 : -1];
  typedef char ControllerWorkingVectorZ[(offsetof(RwV3d, z) == 8) ? 1 : -1];
  typedef char ControllerDirectionSize[(sizeof(direction) == 12) ? 1 : -1];
  typedef char ControllerAxisSize[(sizeof(axis) == 12) ? 1 : -1];

  u16 *modelState = (u16 *)layerState;
  u16 *controller = (u16 *)controllerState;

  hasParentMatrix = 0;
  parent = 0;
  resetAnimation = 0;
  hierarchy = (RpHAnimHierarchy *)hierarchyData;
  hierarchyFlags = hierarchy->flags;
  if (((hierarchyFlags & 1) != 0) && (hierarchy->rootParentOffset != -1)) {
    animationAddress = (unsigned int)hierarchy->parentHierarchy;
    workValue = hierarchy->rootParentOffset * 0x40;
    nodeParentMatrix = (float *)(*(int *)&((RpHAnimHierarchy *)animationAddress)->pMatrixArray + workValue);
    if (((hierarchyFlags & 0x2000) != 0) && ((hierarchyFlags & 0x4000) != 0)) {
      hasParentMatrix = 1;
      parent = (unsigned int)hierarchy->parentHierarchy->parentFrame;
    }
  } else {
    if ((hierarchyFlags & 0x4000) != 0) {
      (*(u32 *)&identityMatrix.at.z) = 0x3f800000;
      (*(u32 *)&identityMatrix.up.y) = 0x3f800000;
      ((f32 *)&identityMatrix)[0] = 1.0f;
      (*(u32 *)&identityMatrix.up.x) = 0;
      ((f32 *)&identityMatrix)[2] = 0.0f;
      ((f32 *)&identityMatrix)[1] = 0.0f;
      (*(u32 *)&identityMatrix.at.y) = 0;
      (*(u32 *)&identityMatrix.at.x) = 0;
      (*(u32 *)&identityMatrix.up.z) = 0;
      (*(u32 *)&identityMatrix.pos.z) = 0;
      (*(u32 *)&identityMatrix.pos.y) = 0;
      (*(u32 *)&identityMatrix.pos.x) = 0;
      /* Retail 00471460 reads this flag word before any defining store. */
      identityMatrix.flags = identityMatrix.flags | 0x20003;
      nodeParentMatrix = ((f32 *)&identityMatrix);
      if ((hierarchyFlags & 0x2000) != 0) {
        hasParentMatrix = 1;
        parent = (unsigned int)hierarchy->parentFrame;
      }
    } else {
      hasParentMatrix = 1;
      parent = (unsigned int)hierarchy->parentFrame;
      nodeParentMatrix = ((f32 *)&baseMatrix);
    }
  }
  if (hasParentMatrix) {
    if ((parent != 0) && (frameOrStride = *(int *)&((MdlFrame *)parent)->parent, frameOrStride != 0)) {
      workValue = func_003e9240((struct RwObjectOwnerLink *)((void *)frameOrStride));
      if (workValue == 0) {
        baseMatrix = *(const RwMatrix *)func_003e9700((u8 *)frameOrStride);
      }
      else {
        baseMatrix = *(const RwMatrix *)&((MdlFrame *)frameOrStride)->modelling;
        for (frameOrStride = *(int *)&((MdlFrame *)frameOrStride)->parent; frameOrStride != 0; frameOrStride = *(int *)&((MdlFrame *)frameOrStride)->parent) {
          ancestorMatrix = baseMatrix;
          RwMatrixMultiply((RwMatrix *)(((f32 *)&baseMatrix)),(const RwMatrix *)(((f32 *)&ancestorMatrix)),(const RwMatrix *)((u8 *)frameOrStride + 0x10));
        }
      }
    }
    else {
      (*(u32 *)&baseMatrix.at.z) = 0x3f800000;
      ((f32 *)&baseMatrix)[5] = 1.0f;
      ((f32 *)&baseMatrix)[0] = 1.0f;
      ((f32 *)&baseMatrix)[4] = 0.0f;
      ((f32 *)&baseMatrix)[2] = 0.0f;
      ((f32 *)&baseMatrix)[1] = 0.0f;
      (*(u32 *)&baseMatrix.at.y) = 0;
      (*(u32 *)&baseMatrix.at.x) = 0;
      ((f32 *)&baseMatrix)[6] = 0.0f;
      (*(u32 *)&baseMatrix.pos.z) = 0;
      (*(u32 *)&baseMatrix.pos.y) = 0;
      (*(u32 *)&baseMatrix.pos.x) = 0;
      /* Retail 004715d0 likewise preserves the unwritten flag bits. */
      baseMatrix.flags |= 0x20003;
    }
  }
  animated = hierarchyFlags & 0x2000;
  if ((mdlAnimationFlag(&animated) != 0) && ((((MdlFrame *)*(int *)&((MdlFrame *)(u32)hierarchy->parentFrame)->root)->privateFlags & 3) == 0)) {
    typedef struct ControllerLink { struct ControllerLink *next; struct ControllerLink *prev; } ControllerLink;
    ControllerLink *list = (ControllerLink *)DAT_0088739c;

    ((ControllerLink *)(*(int *)&((MdlFrame *)(u32)hierarchy->parentFrame)->root + 8))->next = list->next;
    ((ControllerLink *)(*(int *)&((MdlFrame *)(u32)hierarchy->parentFrame)->root + 8))->prev = list;
    list->next->prev = (ControllerLink *)(*(int *)&((MdlFrame *)(u32)hierarchy->parentFrame)->root + 8);
    frameOrStride = *(int *)&((MdlFrame *)(u32)hierarchy->parentFrame)->root;
    list->next = (ControllerLink *)(frameOrStride + 8);
    ((MdlFrame *)frameOrStride)->privateFlags = ((MdlFrame *)frameOrStride)->privateFlags | 2;
  }
  interpolatorAddress = (unsigned int)hierarchy->currentAnim;
  poseInterpolator = (RtAnimInterpolator *)interpolatorAddress;
  applyKeyFrame = *(void (**)(void *, void *))&poseInterpolator->keyFrameApplyCB;
  frameOrStride = ((RtAnimInterpolator *)interpolatorAddress)->currentInterpKeyFrameSize;
  parentStackTop = &parentStack[1];
  nodeInfoAddress = (unsigned int)hierarchy->pNodeInfo;
  outputMatrix = (float *)hierarchy->pMatrixArray;
  keyFrameAddress = interpolatorAddress + 0x4c;
  workValue = **(int **)&modelLayer->resource;
  blendControl = *(unsigned int **)&((MdlDispatchAnimEntry *)mdlTableEntryAddress((short)modelState[2] * 0x50, workValue))->blendControl;
  if ((blendControl != (unsigned int *)0x0) && (((MdlLayerState *)modelState)->speed == 0.0f)) {
    return 1;
  }
  {
    /* Per-hierarchy modes are snapped before callbacks and reused for all
     * nodes, as at retail 004716d0-004716dc. The full entry flags need not
     * remain live throughout the node traversal. */
    parentMatrix = (RwMatrix *)parentTransform;
    for (nodeIndex = 0; nodeIndex < hierarchy->numNodes; nodeIndex = nodeIndex + 1) {
      if (func_003954b0 == applyKeyFrame) {
        /* RtQuatUnitConvertToMatrixMacro: independent square/cross/wimag
         * products precede matrix construction, as in retail 0047170c-0047172c. */
        const f32 x = ((MdlKeyFrame *)keyFrameAddress)->rotation[0];
        const f32 y = ((MdlKeyFrame *)keyFrameAddress)->rotation[1];
        const f32 z = ((MdlKeyFrame *)keyFrameAddress)->rotation[2];
        const f32 w = ((MdlKeyFrame *)keyFrameAddress)->rotation[3];
        RwV3d square;
        RwV3d cross;
        RwV3d wimag;
        square.x = x * x;
        square.y = y * y;
        square.z = z * z;
        cross.x = y * z;
        cross.y = z * x;
        cross.z = x * y;
        wimag.x = w * x;
        wimag.y = w * y;
        wimag.z = w * z;
        frameMatrix.right.x = 1.0f - 2.0f * (square.y + square.z);
        frameMatrix.right.y = 2.0f * (cross.z + wimag.z);
        frameMatrix.right.z = 2.0f * (cross.y - wimag.y);
        frameMatrix.up.x = 2.0f * (cross.z - wimag.z);
        frameMatrix.up.y = 1.0f - 2.0f * (square.x + square.z);
        frameMatrix.up.z = 2.0f * (cross.x + wimag.x);
        frameMatrix.at.x = 2.0f * (cross.y + wimag.y);
        frameMatrix.at.y = 2.0f * (cross.x - wimag.x);
        frameMatrix.at.z = 1.0f - 2.0f * (square.x + square.y);
        frameMatrix.pos.x = 0.0f;
        frameMatrix.pos.y = 0.0f;
        frameMatrix.pos.z = 0.0f;
        frameMatrix.flags = 3;
        frameMatrix.pos.x = ((MdlKeyFrame *)keyFrameAddress)->translation.x;
        frameMatrix.pos.y = ((MdlKeyFrame *)keyFrameAddress)->translation.y;
        frameMatrix.pos.z = ((MdlKeyFrame *)keyFrameAddress)->translation.z;
      }
      else {
        (*applyKeyFrame)(&frameMatrix.right.x,(void *)keyFrameAddress);
      }
      switch (hierarchy->pNodeInfo[nodeIndex].nodeID) {
      case 0x1389: {
        s32 angleLimited;
        if ((parentMatrix == 0) && ((*controller & 0x400) == 0)) {
          *controller = *controller | 0x600;
        }
        angleLimited = 0;
        workingVector.x = 1.0f / lookState->scale.x;
        workingVector.y = 1.0f / ((MdlLookState *)controller)->scale.y;
        workingVector.z = 1.0f / ((MdlLookState *)controller)->scale.z;
        if ((*modelState & 0x10) != 0) {
          workingVector.x = workingVector.x * (1.0f / DAT_00922bb0[0]);
          angleOrTime = (1.0f / DAT_00922bb0[0]) * DAT_00922bb4[0];
          workingVector.y = workingVector.y * angleOrTime;
          workingVector.z = workingVector.z * angleOrTime;
        }
        scaleMatrix = *(const RwMatrix *)nodeParentMatrix;
        RwMatrixScale((RwMatrix *)(((f32 *)&scaleMatrix)),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
        RwMatrixMultiply((RwMatrix *)(&localMatrix.right.x),(const RwMatrix *)(&frameMatrix.right.x),(const RwMatrix *)(((f32 *)&scaleMatrix)));
        position = localMatrix.pos;
        if (parentMatrix == 0) {
          RwMatrixScale((RwMatrix *)(&localMatrix.right.x),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
          axis[0] = 0;
          axis[1] = 0x3f800000;
          axis[2] = 0;
          RwMatrixRotate((struct RwMatrixTag*)rotationMatrix, (const RwV3d*)&axis[0], 180.0f, rwCOMBINEREPLACE);
          axis[0] = 0;
          axis[1] = 0;
          axis[2] = 0x3f800000;
          RwMatrixRotate((struct RwMatrixTag*)rotationMatrix, (const RwV3d*)&axis[0], -90.0f, rwCOMBINEPOSTCONCAT);
          RwMatrixMultiply((RwMatrix *)(((u8 *)&axisMatrix)),(const RwMatrix *)(rotationMatrix),(const RwMatrix *)(((f32 *)&baseMatrix)));
          controllerFlags = *controller;
          if ((controllerFlags & 0x100) == 0) {
            if ((controllerFlags & 0x60) != 0) {
              limitRotation = 1;
              if ((controllerFlags & 0x40) != 0) {
                workingVector.x = position.x - ((MdlLookState *)controller)->target.x;
                workingVector.y = position.y - ((MdlLookState *)controller)->target.y;
                workingVector.z = position.z - ((MdlLookState *)controller)->target.z;
              } else {
                workingVector = *(const RwV3d *)&((MdlLookState *)controller)->target.x;
                workingVector.x = -workingVector.x;
                workingVector.y = -workingVector.y;
                workingVector.z = -workingVector.z;
              }
              RwV3dNormalize((RwV3d *)(&workingVector),(const RwV3d *)(&workingVector));
              func_003e0960((RwMatrix *)(inverseBaseMatrix),(const RwMatrix *)(((f32 *)&baseMatrix)));
              func_003e4320((RwV3d *)(&workingVector),(const RwV3d *)(&workingVector),(const RwMatrix *)(inverseBaseMatrix));
              RwV3dNormalize((RwV3d *)(&workingVector),(const RwV3d *)(&workingVector));
              eye[0] = 0.0f;
              eye[1] = 0.0f;
              eye[2] = -100.0f;
              func_003e42a0((RwV3d *)(&eye[0]),(const RwV3d *)(&eye[0]),(const RwMatrix *)(((f32 *)&scaleMatrix)));
              look[0] = position.x - eye[0];
              look[1] = position.y - eye[1];
              look[2] = position.z - eye[2];
              func_003e4320((RwV3d *)(&look[0]),(const RwV3d *)(&look[0]),(const RwMatrix *)(inverseBaseMatrix));
              RwV3dNormalize((RwV3d *)(&look[0]),(const RwV3d *)(&look[0]));
               {
                 f32 pitch;
                 f32 yaw;
                 f32 baseYaw;
                 f32 basePitch;
                 f32 limit;

                 basePitch = fGpffff8048 * func_0044b920(look[1]) - 90.0f;
                 baseYaw = fGpffff8048 * func_0044b950(look[0],look[2]) + 180.0f;
                 pitch = fGpffff8048 * func_0044b920(workingVector.y) - 90.0f;
                 yaw = fGpffff8048 * func_0044b950(workingVector.x,workingVector.z) + 180.0f;
                 for (pitch = pitch - basePitch; pitch < 0.0f; pitch = pitch + 360.0f) {
                 }
                 for (; pitch > 360.0f; pitch = pitch - 360.0f) {
                 }
                 limit = ((MdlLookState *)controller)->pitchLimit;
                 if (!(pitch <= limit) && pitch < 360.0f - limit) {
                   if (pitch < 180.0f) {
                     pitch = limit;
                   } else {
                     pitch = 360.0f - limit;
                   }
                   angleLimited = 1;
                 }
                 RwMatrixRotate((struct RwMatrixTag*)rotationMatrix, (const RwV3d*)((u8 *)&axisMatrix.up), -(pitch + basePitch), rwCOMBINEREPLACE);
                 for (yaw = yaw - baseYaw; yaw < 0.0f; yaw = yaw + 360.0f) {
                 }
                 for (; yaw > 360.0f; yaw = yaw - 360.0f) {
                 }
                 limit = ((MdlLookState *)controller)->yawLimit;
                 if (!(yaw <= limit) && yaw < 360.0f - limit) {
                   if (yaw < 180.0f) {
                     yaw = limit;
                   } else {
                     yaw = 360.0f - limit;
                   }
                   angleLimited = 1;
                 }
                 RwMatrixRotate((struct RwMatrixTag*)rotationMatrix, (const RwV3d*)((u8 *)&axisMatrix), yaw + baseYaw, rwCOMBINEPOSTCONCAT);
               }
              RwMatrixMultiply((RwMatrix *)(outputMatrix),(const RwMatrix *)(((u8 *)&axisMatrix)),(const RwMatrix *)(rotationMatrix));
              RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(outputMatrix));
            } else {
              if ((controllerFlags & 0x80) != 0) {
                limitRotation = 0;
                axis[0] = 0x3f800000;
                axis[1] = 0;
                axis[2] = 0;
                func_003e4320((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(const RwMatrix *)(((f32 *)&baseMatrix)));
                RwMatrixRotate((struct RwMatrixTag*)rotationMatrix, (const RwV3d*)&axis[0], ((MdlLookState *)controller)->target.x, rwCOMBINEREPLACE);
                axis[0] = 0;
                axis[1] = 0x3f800000;
                axis[2] = 0;
                func_003e4320((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(const RwMatrix *)(((f32 *)&baseMatrix)));
                RwMatrixRotate((struct RwMatrixTag*)rotationMatrix, (const RwV3d*)&axis[0], ((MdlLookState *)controller)->target.y, rwCOMBINEPOSTCONCAT);
                RwMatrixMultiply((RwMatrix *)(outputMatrix),(const RwMatrix *)(((u8 *)&axisMatrix)),(const RwMatrix *)(rotationMatrix));
                RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(outputMatrix));
              } else {
                RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(&localMatrix.right.x));
              }
            }
            if (((*controller & 0x1000) != 0) && angleLimited) {
              if ((*controller & 0x800) == 0) {
                *(ControllerQuat *)&((MdlLookState *)controller)->limitedRotation[0] = rotation;
              }
              *controller = *controller | 0x800;
            }
            else {
              *(u16 *)controller = *(u16 *)controller & 0xf7ff;
            }
            if ((*controller & 0x800) != 0) {
              rotation = *(ControllerQuat *)&((MdlLookState *)controller)->limitedRotation[0];
            }
            if (((*controller & 0x8000) != 0) &&
               ((lookState->yawOffset != 0.0f || (((MdlLookState *)controller)->pitchOffset != 0.0f)))) {
              rotationSnapshot = rotation;
              limitRotation = 0;
              axis[0] = 0;
              axis[1] = 0x3f800000;
              axis[2] = 0;
              RtQuatTransformVectors((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(s32)(1),(const struct RtQuat *)(&rotationSnapshot.value[0]));
              func_003dc740((struct RtQuat *)&rotation.value[0],(const RwV3d *)&axis[0],((MdlLookState *)controller)->yawOffset,2);
              axis[0] = 0x3f800000;
              axis[1] = 0;
              axis[2] = 0;
              RtQuatTransformVectors((RwV3d *)(&axis[0]),(const RwV3d *)(&axis[0]),(s32)(1),(const struct RtQuat *)(&rotationSnapshot.value[0]));
              func_003dc740((struct RtQuat *)&rotation.value[0],(const RwV3d *)&axis[0],((MdlLookState *)controller)->pitchOffset,2);
            }
          }
          else {
            RtQuatConvertFromMatrix((struct RtQuat *)(&rotation.value[0]),(const RwMatrix *)(&localMatrix.right.x));
          }
          if ((*controller & 0x200) != 0) {
            RtQuatConvertFromMatrix((struct RtQuat *)(controller + 8),(const RwMatrix *)(&localMatrix.right.x));
            *controller = *controller & 0xfdff;
            resetAnimation = 1;
            if ((*controller & 0x100) != 0) {
              *controller = *controller & 0x7e1f;
              *controller = *controller & 0xfbff;
              *controller = *controller & 0xf7ff;
            }
          } else {
            if ((blendControl == (unsigned int *)0x0) && ((*controller & 0x100) != 0)) {
              {
                f32 dot;

                dot = effMiscQuatAngle((unsigned char *)(controller + 8),(unsigned char *)&rotation.value[0]);
                if (dot < 0.0f) {
                  negatedRotation.value[3] = -rotation.value[3];
                  negatedRotation.value[0] = -rotation.value[0];
                  negatedRotation.value[1] = -rotation.value[1];
                  negatedRotation.value[2] = -rotation.value[2];
                  dot = effMiscQuatAngle((unsigned char *)(controller + 8),(unsigned char *)negatedRotation.value);
                }
                angleOrTime = func_0044b920(dot);
              }
              if (angleOrTime * 2.0f < fGpffff804c) {
                *controller = *controller & 0x7e1f;
                *controller = *controller & 0xfbff;
              }
              *controller = *controller & 0xf7ff;
            }
            /* Snapshot the complete starting controller quaternion. */
            startRotation = *(const ControllerQuat *)&lookState->rotation[0];
            func_003dcc70((struct RtQuat *)(&startRotation.value[0]),(struct RtQuat *)(&rotation.value[0]),(struct RtQuatSlerpCache *)(&interpolation.from[0]));
            {
              f32 interpolationTime = ((MdlLookState *)controller)->blend;
              if (interpolationTime <= 0.0f) {
                blendedRotation = startRotation;
              }
              else if (1.0f <= interpolationTime) {
                blendedRotation = rotation;
              }
              else {
                f32 fromWeight = 1.0f - interpolationTime;
                f32 toWeight = interpolationTime;
                if (interpolation.nearlyZero == 0) {
                  fromWeight = fromWeight * interpolation.omega;
                  {
                    const f32 z = fromWeight * fromWeight;
                    f32 polynomial = fGpffff8050 * z + fGpffff8054;
                    polynomial = z * polynomial + fGpffff8058;
                    polynomial = z * polynomial + fGpffff805c;
                    polynomial = z * polynomial + fGpffff8060;
                    polynomial = z * polynomial + fGpffff8064;
                    { f32 zw = z * fromWeight; fromWeight = zw * polynomial + fromWeight; }
                  }
                  toWeight = toWeight * interpolation.omega;
                  {
                    const f32 z = toWeight * toWeight;
                    f32 polynomial = fGpffff8050 * z + fGpffff8054;
                    polynomial = z * polynomial + fGpffff8058;
                    polynomial = z * polynomial + fGpffff805c;
                    polynomial = z * polynomial + fGpffff8060;
                    polynomial = z * polynomial + fGpffff8064;
                    { f32 zw = z * toWeight; toWeight = zw * polynomial + toWeight; }
                  }
                }
                blendedRotation.value[0] = interpolation.from[0] * fromWeight;
                blendedRotation.value[1] = interpolation.from[1] * fromWeight;
                blendedRotation.value[2] = interpolation.from[2] * fromWeight;
                blendedRotation.value[0] = blendedRotation.value[0] + interpolation.to[0] * toWeight;
                blendedRotation.value[1] = blendedRotation.value[1] + interpolation.to[1] * toWeight;
                blendedRotation.value[2] = blendedRotation.value[2] + interpolation.to[2] * toWeight;
                blendedRotation.value[3] = interpolation.from[3] * fromWeight + interpolation.to[3] * toWeight;
              }
            }
            if (((*controller & 0x2000) != 0) && (limitRotation != 0)) {
              RtQuatConvertFromMatrix((struct RtQuat *)(&fallbackRotation.bits[0]),(const RwMatrix *)(&localMatrix.right.x));
              {
                f32 dot;

                dot = effMiscQuatAngle((unsigned char *)&fallbackRotation.bits[0],(unsigned char *)&blendedRotation.value[0]);
                if (dot < 0.0f) {
                  negatedRotation.value[3] = -blendedRotation.value[3];
                  negatedRotation.value[0] = -blendedRotation.value[0];
                  negatedRotation.value[1] = -blendedRotation.value[1];
                  negatedRotation.value[2] = -blendedRotation.value[2];
                  dot = effMiscQuatAngle((unsigned char *)&fallbackRotation.bits[0],(unsigned char *)negatedRotation.value);
                }
                angleOrTime = func_0044b920(dot);
              }
              if (angleOrTime * 2.0f <= fGpffff8068 * ((MdlLookState *)controller)->yawLimit) {
                *(ControllerQuat *)&((MdlLookState *)controller)->rotation[0] = blendedRotation;
              }
              else {
                angleOrTime = 1.0f - fGpffff806c / (angleOrTime * 2.0f);
                func_003dcc70((struct RtQuat *)(&blendedRotation.value[0]),(struct RtQuat *)(&fallbackRotation.bits[0]),(struct RtQuatSlerpCache *)(&interpolation.from[0]));
                if (angleOrTime <= 0.0f) {
                  *(ControllerQuat *)&((MdlLookState *)controller)->rotation[0] = blendedRotation;
                }
                else if (1.0f <= angleOrTime) {
                  *(ControllerQuat *)&((MdlLookState *)controller)->rotation[0] = fallbackRotation;
                }
                else {
                  f32 fromWeight = 1.0f - angleOrTime;
                  f32 toWeight = angleOrTime;
                  if (interpolation.nearlyZero == 0) {
                    fromWeight = fromWeight * interpolation.omega;
                    {
                      const f32 z = fromWeight * fromWeight;
                      f32 polynomial = fGpffff8070 * z + fGpffff8054;
                      polynomial = z * polynomial + fGpffff8058;
                      polynomial = z * polynomial + fGpffff805c;
                      polynomial = z * polynomial + fGpffff8060;
                      polynomial = z * polynomial + fGpffff8064;
                      { f32 zw = z * fromWeight; fromWeight = zw * polynomial + fromWeight; }
                    }
                    toWeight = toWeight * interpolation.omega;
                    {
                      const f32 z = toWeight * toWeight;
                      f32 polynomial = fGpffff8070 * z + fGpffff8054;
                      polynomial = z * polynomial + fGpffff8058;
                      polynomial = z * polynomial + fGpffff805c;
                      polynomial = z * polynomial + fGpffff8060;
                      polynomial = z * polynomial + fGpffff8064;
                      { f32 zw = z * toWeight; toWeight = zw * polynomial + toWeight; }
                    }
                  }
                  ((MdlLookState *)controller)->rotation[0] = interpolation.from[0] * fromWeight;
                  ((MdlLookState *)controller)->rotation[1] = interpolation.from[1] * fromWeight;
                  ((MdlLookState *)controller)->rotation[2] = interpolation.from[2] * fromWeight;
                  ((MdlLookState *)controller)->rotation[0] = ((MdlLookState *)controller)->rotation[0] + interpolation.to[0] * toWeight;
                  ((MdlLookState *)controller)->rotation[1] = ((MdlLookState *)controller)->rotation[1] + interpolation.to[1] * toWeight;
                  ((MdlLookState *)controller)->rotation[2] = ((MdlLookState *)controller)->rotation[2] + interpolation.to[2] * toWeight;
                  ((MdlLookState *)controller)->rotation[3] = interpolation.from[3] * fromWeight + interpolation.to[3] * toWeight;
                }
              }
            } else {
              *(ControllerQuat *)&((MdlLookState *)controller)->rotation[0] = blendedRotation;
            }
          }
        }
        if (blendControl == (unsigned int *)0x0) {
          if (parentMatrix == 0) {
            {
              const ControllerQuat *controllerRotation = (const ControllerQuat *)(controller + 8);
              RwV3d scaled;
              RwV3d realScaled;
              RwV3d square;
              RwV3d cross;
              f32 scale = 2.0f / (controllerRotation->value[3] * controllerRotation->value[3] +
                  ((controllerRotation->value[0] * controllerRotation->value[0] +
                    controllerRotation->value[1] * controllerRotation->value[1]) +
                    controllerRotation->value[2] * controllerRotation->value[2]));
              scaled.x = controllerRotation->value[0] * scale;
              scaled.y = controllerRotation->value[1] * scale;
              scaled.z = controllerRotation->value[2] * scale;
              realScaled.x = scaled.x * controllerRotation->value[3];
              realScaled.y = scaled.y * controllerRotation->value[3];
              realScaled.z = scaled.z * controllerRotation->value[3];
              square.x = controllerRotation->value[0] * scaled.x;
              square.y = controllerRotation->value[1] * scaled.y;
              square.z = controllerRotation->value[2] * scaled.z;
              cross.x = controllerRotation->value[1] * scaled.z;
              cross.y = controllerRotation->value[2] * scaled.x;
              cross.z = controllerRotation->value[0] * scaled.y;
              ((RwMatrix *)outputMatrix)->right.x = 1.0f - (square.y + square.z);
              ((RwMatrix *)outputMatrix)->right.y = cross.z + realScaled.z;
              ((RwMatrix *)outputMatrix)->right.z = cross.y - realScaled.y;
              ((RwMatrix *)outputMatrix)->up.x = cross.z - realScaled.z;
              ((RwMatrix *)outputMatrix)->up.y = 1.0f - (square.z + square.x);
              ((RwMatrix *)outputMatrix)->up.z = cross.x + realScaled.x;
              ((RwMatrix *)outputMatrix)->at.x = cross.y + realScaled.y;
              ((RwMatrix *)outputMatrix)->at.y = cross.x - realScaled.x;
              ((RwMatrix *)outputMatrix)->at.z = 1.0f - (square.x + square.y);
              ((RwMatrix *)outputMatrix)->pos.x = 0.0f;
              ((RwMatrix *)outputMatrix)->pos.y = 0.0f;
              ((RwMatrix *)outputMatrix)->pos.z = 0.0f;
              ((RwMatrix *)outputMatrix)->flags = 3;
            }
            /* Retail snapshots all controller-scale components before use:
             * 00472638-0047264c and 004727a0-004727b4. */
            workingVector = *(const RwV3d *)&((MdlLookState *)controller)->scale.x;
            if ((*modelState & 0x10) != 0) {
              /* Retail combines model scale and aspect before scaling Y/Z. */
              f32 modelScale = DAT_00922bb0[0];
              workingVector.x = workingVector.x * modelScale;
              modelScale = modelScale * DAT_00922bb4[0];
              workingVector.y = workingVector.y * modelScale;
              workingVector.z = workingVector.z * modelScale;
            }
            RwMatrixScale((RwMatrix *)(outputMatrix),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
            *(RwV3d *)&outputMatrix[0xc] = position;
          }
          else {
            {
              const ControllerQuat *controllerRotation = (const ControllerQuat *)(controller + 8);
              RwV3d scaled;
              RwV3d realScaled;
              RwV3d square;
              RwV3d cross;
              f32 scale = 2.0f / (controllerRotation->value[3] * controllerRotation->value[3] +
                  ((controllerRotation->value[0] * controllerRotation->value[0] +
                    controllerRotation->value[1] * controllerRotation->value[1]) +
                    controllerRotation->value[2] * controllerRotation->value[2]));
              scaled.x = controllerRotation->value[0] * scale;
              scaled.y = controllerRotation->value[1] * scale;
              scaled.z = controllerRotation->value[2] * scale;
              realScaled.x = scaled.x * controllerRotation->value[3];
              realScaled.y = scaled.y * controllerRotation->value[3];
              realScaled.z = scaled.z * controllerRotation->value[3];
              square.x = controllerRotation->value[0] * scaled.x;
              square.y = controllerRotation->value[1] * scaled.y;
              square.z = controllerRotation->value[2] * scaled.z;
              cross.x = controllerRotation->value[1] * scaled.z;
              cross.y = controllerRotation->value[2] * scaled.x;
              cross.z = controllerRotation->value[0] * scaled.y;
              (&localMatrix)->right.x = 1.0f - (square.y + square.z);
              (&localMatrix)->right.y = cross.z + realScaled.z;
              (&localMatrix)->right.z = cross.y - realScaled.y;
              (&localMatrix)->up.x = cross.z - realScaled.z;
              (&localMatrix)->up.y = 1.0f - (square.z + square.x);
              (&localMatrix)->up.z = cross.x + realScaled.x;
              (&localMatrix)->at.x = cross.y + realScaled.y;
              (&localMatrix)->at.y = cross.x - realScaled.x;
              (&localMatrix)->at.z = 1.0f - (square.x + square.y);
              (&localMatrix)->pos.x = 0.0f;
              (&localMatrix)->pos.y = 0.0f;
              (&localMatrix)->pos.z = 0.0f;
              (&localMatrix)->flags = 3;
            }
            /* Retail snapshots all controller-scale components before use:
             * 00472638-0047264c and 004727a0-004727b4. */
            workingVector = *(const RwV3d *)&((MdlLookState *)controller)->scale.x;
            if ((*modelState & 0x10) != 0) {
              /* Retail combines model scale and aspect before scaling Y/Z. */
              f32 modelScale = DAT_00922bb0[0];
              workingVector.x = workingVector.x * modelScale;
              modelScale = modelScale * DAT_00922bb4[0];
              workingVector.y = workingVector.y * modelScale;
              workingVector.z = workingVector.z * modelScale;
            }
            RwMatrixScale((RwMatrix *)(&localMatrix.right.x),(const RwV3d *)(&workingVector),(RwOpCombineType)(1));
            localMatrix.pos = position;
            RwMatrixMultiply((RwMatrix *)(outputMatrix),(const RwMatrix *)(&localMatrix.right.x),(const RwMatrix *)(parentMatrix));
          }
          if (((*(int *)&((RpHAnimNodeInfo *)nodeInfoAddress)->pFrame != 0) &&
              (nodeFrame = *(int *)&((MdlFrame *)*(int *)&((RpHAnimNodeInfo *)nodeInfoAddress)->pFrame)->parent, nodeFrame != 0)) &&
             ((((MdlFrame *)*(int *)&((MdlFrame *)nodeFrame)->root)->privateFlags & 1) != 0)) {
            func_003ed960(((MdlFrame *)nodeFrame)->root);
          }
        }
        else {
          RwMatrixMultiply((RwMatrix *)(outputMatrix),(const RwMatrix *)(&frameMatrix.right.x),(const RwMatrix *)(nodeParentMatrix));
        }
      }
        break;
      default:
      {
        RwMatrixMultiply((RwMatrix *)(outputMatrix),(const RwMatrix *)(&frameMatrix.right.x),(const RwMatrix *)(nodeParentMatrix));
      }
        break;
      }
      nodeFrame = *(int *)&((RpHAnimNodeInfo *)nodeInfoAddress)->pFrame;
      if (nodeFrame != 0) {
        if ((hierarchyFlags & 0x1000) != 0) {
          *(RwMatrix *)&((MdlFrame *)(u8 *)(u32)(nodeFrame))->modelling.right.x = frameMatrix;
          if (mdlAnimationFlag(&animated) == 0) {
            func_003e9680((u8 *)(nodeFrame));
          }
        }
        if (mdlAnimationFlag(&animated) != 0) {
          if ((hierarchyFlags & 0x4000) != 0) {
            RwMatrixMultiply((RwMatrix *)(nodeFrame + 0x50),(const RwMatrix *)(outputMatrix),(const RwMatrix *)(((f32 *)&baseMatrix)));
          } else {
            *(RwMatrix *)&((MdlFrame *)(u8 *)(u32)(nodeFrame))->localToWorld.right.x = *(const RwMatrix *)outputMatrix;
          }
          ((MdlFrame *)nodeFrame)->privateFlags = (((MdlFrame *)nodeFrame)->privateFlags & ~4) | 8;
        }
      }
      /* HAnim node parent-stack control: POP=1, PUSH=2. Both bits leave
       * the parent unchanged; retail dispatch 0047298c-004729f0. */
      switch (*(unsigned int *)&((RpHAnimNodeInfo *)nodeInfoAddress)->flags & 3) {
      case 0:
        nodeParentMatrix = outputMatrix;
        break;
      case 1:
        parentStackTop--;
        nodeParentMatrix = (float *)*parentStackTop;
        break;
      case 2:
        *parentStackTop++ = (unsigned int)nodeParentMatrix;
        nodeParentMatrix = outputMatrix;
        break;
      case 3:
        break;
      }
      keyFrameAddress = keyFrameAddress + frameOrStride;
      outputMatrix = outputMatrix + 0x10;
      nodeInfoAddress = nodeInfoAddress + 0x10;
    }
    if ((blendControl != (unsigned int *)0x0) && ((*controller & 0x81e0) != 0)) {
      if (((MdlDirectionalBlend *)(u8 *)blendControl)->initialized == 0) {
        for (hierarchyFlags = 0; hierarchyFlags < 4; hierarchyFlags = hierarchyFlags + 1) {
          unsigned int *slot = blendControl + hierarchyFlags;
          unsigned int *interp = slot + 4;

          animationAddress = (unsigned int)func_003d5790(hierarchy->numNodes, hierarchy->currentAnim->maxInterpKeyFrameSize);
          *interp = animationAddress;
          func_003d5840((RtAnimInterpolator *)((void *)*interp),(RtAnimAnimation *)((void *)*slot));
        }
        *((u16 *)&blendControl[0x10] + 1) = 1;
      }
      if (resetAnimation) {
        blendControl[0xc] = 0x3f800000;
        blendControl[0x12] = 0;
      }
      /* Preserve retail's less-than test and unordered fallback selection. */
      if ((!(*(float *)&blendControl[0xe] < 1.0f)) ||
         (sourceInterpolator = ((MdlLayerState *)modelState)->blendTo, sourceInterpolator == (unsigned char *)0x0)) {
        sourceInterpolator = (unsigned char *)hierarchy->currentAnim;
        angleOrTime = ((RtAnimInterpolator *)sourceInterpolator)->currentTime;
      }
      else {
        workValue = (short)modelState[2] * 0x50;
        startFrame = *(int **)(**(int * *)&((MdlLayerState *)modelState)->resource + MEMBER_OFFSET(MdlDispatchAnimEntry, startFrame) + workValue);
        if (startFrame == (int *)0x0) {
          angleOrTime = 0.0f;
        }
        else {
          angleOrTime = fGpffff8040 * (float)*startFrame;
        }
      }
      forwardAxis[0] = 0;
      forwardAxis[1] = 0;
      forwardAxis[2] = 0x3f800000;
      if ((*controller & 0x100) == 0) {
        RtQuatTransformVectors((RwV3d *)(&direction[0]),(const RwV3d *)(&forwardAxis[0]),(s32)(1),(const struct RtQuat *)(controller + 8));
        /* Complete orientation snapshot, retail 00472b78-00472b94. */
        *(ControllerQuat *)&((MdlDirectionalBlend *)blendControl)->rotation[0] = *(const ControllerQuat *)&((MdlLookState *)controller)->rotation[0];
      }
      else {
        RtQuatTransformVectors((RwV3d *)(&direction[0]),(const RwV3d *)(&forwardAxis[0]),(s32)(1),(const struct RtQuat *)(blendControl + 8));
      }
      func_003e0960((RwMatrix *)(inverseDirectionMatrix),(const RwMatrix *)(((f32 *)&baseMatrix)));
      func_003e4320((RwV3d *)(&direction[0]),(const RwV3d *)(&direction[0]),(const RwMatrix *)(inverseDirectionMatrix));
      RwV3dNormalize((RwV3d *)(&direction[0]),(const RwV3d *)(&direction[0]));
      blendStep = (float)((MdlDirectionalBlend *)(u8 *)blendControl)->yawRange / ((MdlLookState *)controller)->yawLimit;
      if (!(direction[0] < 0.0f)) {
        func_003d5840((RtAnimInterpolator *)(blendControl[5]),(RtAnimAnimation *)(blendControl[1]));
        func_003d5e40((unsigned char *)blendControl[5],angleOrTime);
        func_003d5e90((unsigned char *)blendControl[6],sourceInterpolator,(unsigned char *)blendControl[5],direction[0] / blendStep);
        frameOrStride = 2;
      }
      else {
        func_003d5840((RtAnimInterpolator *)(blendControl[6]),(RtAnimAnimation *)(blendControl[2]));
        func_003d5e40((unsigned char *)blendControl[6],angleOrTime);
        func_003d5e90((unsigned char *)blendControl[5],sourceInterpolator,(unsigned char *)blendControl[6],-direction[0] / blendStep);
        frameOrStride = 1;
      }
      if (!(direction[1] < 0.0f)) {
        func_003d5840((RtAnimInterpolator *)(blendControl[7]),(RtAnimAnimation *)(blendControl[3]));
        func_003d5e40((unsigned char *)blendControl[7],angleOrTime);
        func_003d5e90((unsigned char *)blendControl[4],(unsigned char *)blendControl[frameOrStride + 4],(unsigned char *)blendControl[7],direction[1]);
        blendControl[0x11] = 0;
      }
      else {
        func_003d5840((RtAnimInterpolator *)(blendControl[4]),(RtAnimAnimation *)(*blendControl));
        func_003d5e40((unsigned char *)blendControl[4],angleOrTime);
        func_003d5e90((unsigned char *)blendControl[7],(unsigned char *)blendControl[frameOrStride + 4],(unsigned char *)blendControl[4],-direction[1]);
        blendControl[0x11] = 3;
      }
      /* Preserve retail's less-than test and unordered fallback selection. */
      if ((*(float *)&blendControl[0xe] < 1.0f) && (((MdlLayerState *)modelState)->blendFrom != (unsigned char *)0x0)) {
        func_003d5e90((unsigned char *)hierarchy->currentAnim,((MdlLayerState *)modelState)->blendFrom,(unsigned char *)blendControl[blendControl[0x11] + 4]
                      ,*(float *)&blendControl[0xe]);
        /* mdlStartLayerAnimation stores blend duration as f32 at control+0x34;
         * retail 00472dd0-00472de0 loads it directly without integer conversion. */
        blendStep = *(float *)&blendControl[0xd];
        blendStep = 1.0f / blendStep;
        *(float *)&blendControl[0xe] = *(float *)&blendControl[0xe] + blendStep;
        blendControl[0xc] = 0;
      }
      else {
        if ((*(u16 *)controller & 0x100) == 0) {
          *(float *)&blendControl[0xc] = *(float *)&blendControl[0xc] * (1.0f - ((MdlLookState *)controller)->blend);
          blendControl[0x12] = 0x3f800000;
          func_003d5e90((unsigned char *)hierarchy->currentAnim,(unsigned char *)hierarchy->currentAnim,(unsigned char *)blendControl[blendControl[0x11] + 4],
                        1.0f - *(float *)&blendControl[0xc]);
        }
        else {
          *(float *)&blendControl[0x12] = *(float *)&blendControl[0x12] * (1.0f - ((MdlLookState *)controller)->blend);
          func_003d5e90((unsigned char *)hierarchy->currentAnim,(unsigned char *)hierarchy->currentAnim,(unsigned char *)blendControl[blendControl[0x11] + 4],
                        *(float *)&blendControl[0x12]);
          if (*(float *)&blendControl[0x12] < fGpffff8074) {
            *(u16 *)controller = *(u16 *)controller & 0x7e1f;
            *(u16 *)controller = *(u16 *)controller & 0xfbff;
          }
          *(u16 *)controller = *(u16 *)controller & 0xf7ff;
        }
      }
      func_00397c40(hierarchyData);
    }
  }
  return 1;
}
#pragma pop

extern s32 func_00397c40(void* hierarchy);
extern s32 mdlUpdateHierarchyPose(u8 *hierarchyData, u8 *layerState, u8 *controllerState, void *parentTransform);
/* Per-node hook installed by mdlInstallHierarchyScaleHook. Scales the node's translation by the stored vector when the node matches the saved pointer, then calls the previous hook. */
// FUN_00472F30
void mdlHierarchyScaleHook(u8* matrix, int keyFrame)
{
    if (*(s32*)DAT_00922ba8_abs == keyFrame) {
        ((MdlKeyFrame *)keyFrame)->translation.x = ((MdlKeyFrame *)keyFrame)->translation.x * *(*(float**)DAT_00922bac_abs);
        ((MdlKeyFrame *)keyFrame)->translation.y = ((MdlKeyFrame *)keyFrame)->translation.y * (*(float**)DAT_00922bac_abs)[1];
        ((MdlKeyFrame *)keyFrame)->translation.z = ((MdlKeyFrame *)keyFrame)->translation.z * (*(float**)DAT_00922bac_abs)[2];
    }
    (*DAT_00922ba0_abs)(matrix, keyFrame);
    if (*(s32*)DAT_00922ba4_abs == keyFrame) {
        RwMatrixScale((void*)matrix, (const RwV3d*)*(float**)DAT_00922bac_abs, 1);
    }
    return;
}




/* Saves the existing per-node hook at the hierarchy root and installs mdlHierarchyScaleHook, so each node's translation is scaled. Used when animation flag 0x10 is set. */
/* measured: keep the hierarchy/interpolator reloads and the scale-field cursor
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00473000
void mdlInstallHierarchyScaleHook(u8* hierarchyData, u8* layer)
{
    u8* scaleFields;
    u8* interpolator;
    u8* activeInterpolator;
    s32 keyFrameSize;
    s32 keyFrameAddress;
    RpHAnimHierarchy *hierarchy = (RpHAnimHierarchy *)hierarchyData;
    MdlHierarchyScale *hierarchyScale;

    scaleFields = layer + 0x3C;
    hierarchyScale = (MdlHierarchyScale *)scaleFields;
    interpolator = *(u8 **)&hierarchy->currentAnim;
    if (interpolator != 0) {
        *(s32*)DAT_00922ba0_abs = *(s32 *)&((RtAnimInterpolator *)interpolator)->keyFrameApplyCB;
        *(s32 *)&((RtAnimInterpolator *)interpolator)->keyFrameApplyCB = (s32)mdlHierarchyScaleHook;
        activeInterpolator = *(u8 **)&hierarchy->currentAnim;
        keyFrameSize = ((RtAnimInterpolator *)activeInterpolator)->currentInterpKeyFrameSize;
        keyFrameAddress = (s32)activeInterpolator + 0x4C;
        *(s32*)DAT_00922ba4_abs = keyFrameAddress;
        keyFrameAddress = keyFrameAddress + keyFrameSize * hierarchyScale->node;
        *(s32*)DAT_00922ba4_abs = keyFrameAddress;
        if (((MdlLayerState *)layer)->speed != 0.0f) {
            *(s32*)DAT_00922ba8_abs = keyFrameAddress;
        } else {
            *(s32*)DAT_00922ba8_abs = 0;
        }
        *(float**)DAT_00922bac_abs = (float*)(scaleFields + 4);
        *(f32*)D_00922BB0_abs = hierarchyScale->modelScale;
        *(f32*)D_00922BB4_abs = hierarchyScale->aspect;
        if ((MEMBER(u16, layer, MdlLayerState, look.flags) & 0x81E0) != 0) {
            mdlUpdateHierarchyPose(hierarchyData, layer, layer + 0x54, 0);
            ((MdlLayerState *)layer)->look.flags |= 0x4000;
        } else {
            func_00397c40(hierarchyData);
            ((MdlLayerState *)layer)->look.flags &= 0xBFFF;
        }
        *(s32 *)&((RtAnimInterpolator *)*(u8* *)&((RpHAnimHierarchy *)hierarchyData)->currentAnim)->keyFrameApplyCB = *(s32*)DAT_00922ba0_abs;
    }
}
/* Dispatches on the material's MatFX effect type (RpMatFXMaterialGetEffects) and sets up the matching effect state. Callers pass each material from an owner's material array at +0x20. */
// FUN_00473140
void mdlSetupMatFXMaterial(int material)
{
    u32 pipeline;
    u32 effects;

    effects = RpMatFXMaterialGetEffects();
    switch (effects) {
    case 1:
        pipeline = func_0039b6e0(0x10021);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    case 2:
        pipeline = func_0039b6e0(0x10022);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    case 3:
        pipeline = func_0039b6e0(0x10023);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    case 4:
        pipeline = func_0039b6e0(0x10024);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    case 5:
        pipeline = func_0039b6e0(0x1002a);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    case 6:
        pipeline = func_0039b6e0(0x1002b);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    default:
        pipeline = func_0039b6e0(0x10020);
        *(u32 *)&((MdlMaterial *)material)->pipeline = pipeline;
        break;
    }

    return;
}



/* Per-atomic callback for RpClumpForAllAtomics. When the atomic's hierarchy has more than 0x40 nodes it stores a MatFX plugin handle at +0x6c and sets up each material of the hierarchy. */
/* measured: keep the first geometry load before the atomic/geometry cursor changes role
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00473250
void* mdlSetupAtomicMatFX(void* atomic, void* data)
{
    int geometryOrCount;
    u32 pipeline;
    u32 skin;
    u32 boneCount;
    u8* geometryData;
    int materialIndex;
    struct RpAtomic *modelAtomic = (struct RpAtomic *)atomic;

    geometryData = atomic;
    geometryOrCount = *(int *)&modelAtomic->geometry;
    if (geometryOrCount == 0) {
        return atomic;
    }

    skin = func_003b83f0(geometryOrCount);
    if (skin == 0) {
        return atomic;
    }

    boneCount = func_003b8500(skin);
    if (boneCount <= 0x40) {
        return atomic;
    }

    if (atomic != 0) {
        pipeline = func_0039b6e0(0x1001f);
        *(u32 *)&((struct RpAtomic *)geometryData)->pipeline = pipeline;
        geometryData = *(u8 **)&((struct RpAtomic *)geometryData)->geometry;
        geometryOrCount = *(int *)&((MdlGeometry *)geometryData)->count;
        for (materialIndex = 0; materialIndex < geometryOrCount; materialIndex = materialIndex + 1) {
            mdlSetupMatFXMaterial((u32)((MdlGeometry *)geometryData)->materials[materialIndex]);
        }
        return atomic;
    }

    return atomic;
}




/* Anim-loop callback for RtAnimInterpolatorSetAnimLoopCallBack. Looks up the animation for the slot at input's raw index in the layer's dispatch table and returns it, or the placeholder entry. */
/* measured: keep the callback-visible layer/table reloads and member-first clip lookup
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00473350
void* mdlResolveLoopAnimation(void* interpolator, u8* layer)
{
    s16 rawIndex;
    s64 signedIndex;
    u16 count;
    s32* table;
    s32 off;
    u8* animation;
    void* attachments;
    void* startFrame;
    void* activeInterpolator;
    u8* metadataField;
    f32 timeScale;
    MdlLayerState *layerState = (MdlLayerState *)layer;

    rawIndex = ((MdlLayerState *)layer)->animationIndex;
    table = *(s32 **)&layerState->resource;
    if (table != 0 &&
        (signedIndex = (s64)rawIndex, count = ((MdlDispatchAnimTable *)table)->count,
         signedIndex < (s64)(u32)count) &&
        (off = rawIndex * 0x50, animation = *(u8**)(*(s32 *)&((MdlDispatchAnimTable *)table)->entries + MEMBER_OFFSET(MdlDispatchAnimEntry, animation) + off)) != 0 &&
        animation != D_00922BC0_abs) {
        if (!(((MdlLayerState *)layer)->flags & 1)) {
            if (signedIndex < (s64)(u32)count && rawIndex >= 0) {
                activeInterpolator = *(void* *)&((RpHAnimHierarchy *)(u8*)*(void* *)&((MdlLayerState *)layer)->hierarchy)->currentAnim;
                func_003d5e40_typed(((RtAnimAnimation *)animation)->duration, activeInterpolator);
                ((MdlLayerState *)layer)->finished = 1;
            }
        } else {
            attachments = *(void* *)&((MdlLayerState *)layer)->attachments;
            if (attachments != 0) {
                if (*(s32 *)&((MdlCloneAttachmentTable *)attachments)->primaryDraw != 0) {
                    mdlEffectListCallFlagged(*(s32 *)&((MdlCloneAttachmentTable *)attachments)->primaryDraw, rawIndex);
                }
                if (*(s32 *)&((MdlCloneAttachmentTable *)attachments)->secondaryDraw != 0) {
                    mdlNoopSecondaryEffect(*(s32 *)&((MdlCloneAttachmentTable *)attachments)->secondaryDraw);
                }
            }
            activeInterpolator = *(void* *)&((RpHAnimHierarchy *)layerState->hierarchy)->currentAnim;
            RtAnimInterpolatorSetAnimLoopCallBack(activeInterpolator, 0, 0);
            timeScale = iGpffff8040;
            layerState->time = timeScale * ((MdlLayerState *)layer)->speed;
            metadataField = (u8*)*(s32 *)&((MdlDispatchAnimTable *)(u8*)*(s32* *)&((MdlLayerState *)layer)->resource)->entries;
            metadataField += 0x4C;
            metadataField += off;
            startFrame = *(void**)metadataField;
            if (startFrame != 0) {
                ((MdlLayerState *)layer)->time = ((MdlLayerState *)layer)->time + timeScale * (f32)(s32)*(s32*)startFrame;
            }
            activeInterpolator = *(void* *)&((RpHAnimHierarchy *)layerState->hierarchy)->currentAnim;
            func_003d5e40_typed(((MdlLayerState *)layer)->time, activeInterpolator);
            activeInterpolator = *(void* *)&((RpHAnimHierarchy *)(u8*)*(void* *)&((MdlLayerState *)layer)->hierarchy)->currentAnim;
            RtAnimInterpolatorSetAnimLoopCallBack(activeInterpolator, mdlResolveLoopAnimation, layer);
        }
    } else if (((MdlLayerState *)layer)->flags & 1) {
        ((MdlLayerState *)layer)->time = 0.0f;
    }
    return interpolator;
}

/* Initializes a 0xA4-byte slot record: clears it, sets the index fields to -1 and the scale fields to 1.0. */
// FUN_00473520
void mdlInitSlotRecord(void* layer)
{
    memset(layer, 0, 0xA4);
    ((MdlLayerState *)layer)->finished = 1;
    ((MdlLayerState *)layer)->animationIndex = -1;
    ((MdlLayerState *)layer)->speed = 1.0f;
    *(u32 *)&((MdlLayerState *)layer)->time = 0;
    ((MdlLayerState *)layer)->previousIndex = -1;
    ((MdlLayerState *)layer)->blend = 1.0f;
    ((MdlLayerState *)layer)->look.blend = DAT_0076112c;
    *(u32 *)&((MdlLayerState *)layer)->look.rotation[0] = 0;
    *(u32 *)&((MdlLayerState *)layer)->look.rotation[1] = 0;
    *(u32 *)&((MdlLayerState *)layer)->look.rotation[2] = 0;
    ((MdlLayerState *)layer)->look.rotation[3] = 1.0f;
    ((MdlLayerState *)layer)->look.pitchLimit = 70.0f;
    ((MdlLayerState *)layer)->look.yawLimit = 80.0f;
    ((MdlLayerState *)layer)->look.flags = 0;
    ((MdlLayerState *)layer)->look.scale.x = 1.0f;
    ((MdlLayerState *)layer)->look.scale.y = 1.0f;
    ((MdlLayerState *)layer)->look.scale.z = 1.0f;
}

/* measured: retail allocates q=$s0, i=$s1, owner=$s2, i*4=$s3; mwcc b210
   rotates to i*4=$s0, q=$s2, owner=$s3 (25 words, all register names; u8*
   param typing fixed the owner+0x38 address-CSE frame growth, nd 81 -> 25).
   Tried: q,i,idx and i,q,idx declaration orders (25/28), idx named local.
   Saved-register rotation floor. */
/* MATCHED this wave (nd 0, was 25). Levers: (4) opt_propagation off forces the
   early obj[0x14]/obj[0x20] base load before the i*4 chain (FLYDraw), and
   declaring the loop counter i BEFORE obj steers allocation to retail's
   obj=$s0/i=$s1 (pure statement-order, cf FLYList). i*4 kept as a separate
   local named j. */
/* Destroys the effect list of each slot in the record array at owner+0x38 (mdlEffectListDestroy for each non-null entry). */
/* measured: keep the interpolator/resource presence tests across destruction callbacks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_004735B0
#pragma opt_propagation off
void mdlDestroySlotEffects(u8 *layer)
{
    u32 animationIndex;
    u32 *attachments;
    u32 *drawSlot;
    u32 pointerOffset;
    u32 arrayAddress;
    MdlLayerState *layerState = (MdlLayerState *)layer;

    attachments = (u32 *)layerState->attachments;
    if (attachments != 0)
    {
        animationIndex = 0;
        while (animationIndex < *attachments)
        {
            arrayAddress = *(u32 *)&((MdlCloneAttachmentTable *)attachments)->primary;
            pointerOffset = animationIndex * 4;
            drawSlot = (u32*)(arrayAddress + pointerOffset);
            if (*drawSlot != 0)
            {
                mdlEffectListDestroy(*drawSlot);
            }
            arrayAddress = *(u32 *)&((MdlCloneAttachmentTable *)attachments)->secondary;
            drawSlot = (u32*)(arrayAddress + pointerOffset);
            if (*drawSlot != 0)
            {
                mdlReleaseSharedWrapper(*drawSlot);
            }
            animationIndex++;
        }
        DAT_008873ec[0](attachments);
        *(u32* *)&((MdlLayerState *)layer)->attachments = 0;
    }
    if ((u32)layerState->blendFrom != 0)
    {
        func_003d5830((u32)layerState->blendFrom);
        *(u32 *)&((MdlLayerState *)layer)->blendFrom = 0;
    }
    if ((u32)layerState->blendTo != 0)
    {
        func_003d5830((u32)layerState->blendTo);
        *(u32 *)&((MdlLayerState *)layer)->blendTo = 0;
    }
    if ((u32)layerState->rebaseInput != 0)
    {
        func_003d5830((u32)layerState->rebaseInput);
        *(u32 *)&((MdlLayerState *)layer)->rebaseInput = 0;
    }
    if ((u32)layerState->rebaseRotation != 0)
    {
        func_003d5830((u32)layerState->rebaseRotation);
        *(u32 *)&((MdlLayerState *)layer)->rebaseRotation = 0;
    }
    if ((u32)layerState->resource != 0)
    {
        mdlDispatchAnimTableRelease((u8*)layerState->resource);
        *(u32 *)&((MdlLayerState *)layer)->resource = 0;
    }
    if ((((MdlLayerState *)layer)->flags & 2) != 0)
    {
        if ((u32)layerState->hierarchy != 0)
        {
            func_00397120((u32)layerState->hierarchy);
            *(u32 *)&((MdlLayerState *)layer)->hierarchy = 0;
        }
    }
}
#pragma opt_propagation on
/* MATCH: 340B/352B; the remaining 12 bytes are zero tail padding.
   IDA preserves a hierarchy snapshot separately from the escaped output slot.
   Typed object fields and pointer-valued traversal data retain the retail
   reloads, frame address lifetime, and argument evaluation order. */
/* Attaches a clump's frame hierarchy to a slot record: stores the hierarchy at the slot, sets the atomic hierarchy, optionally sets up MatFX (mode != 0), and builds two interpolators from the slot's source animation (flag 0x80). */
// FUN_00473710
void mdlAttachSlotHierarchy(u8 *layer, u8 *clump, s32 setupMatFx)
{
    typedef struct MdlAttachedHierarchy {
        u32 flags;
        s32 numNodes;
        u8 unknown08[0x18];
        RtAnimInterpolator *interpolator;
    } MdlAttachedHierarchy;
    typedef struct MdlAnimationSource {
        u32 unknown00;
        RtAnimAnimation *animation;
    } MdlAnimationSource;
    typedef struct MdlAttachState {
        u16 flags;
        u8 unknown02[0x1e];
        MdlAttachedHierarchy *hierarchy;
        u8 unknown24[8];
        RtAnimInterpolator *first;
        RtAnimInterpolator *second;
        MdlAnimationSource *source;
    } MdlAttachState;
    MdlAttachState *model = (MdlAttachState *)layer;
    MdlAttachedHierarchy *selected;
    u32 hierarchy = 0;
    u8 **frame = (u8 **)&((RwObject *)clump)->parent;

    func_003e9af0(*frame, mdlFindFrameHierarchy, &hierarchy);
    selected = (MdlAttachedHierarchy *)hierarchy;
    model->hierarchy = selected;
    RpClumpForAllAtomics(clump, mdlSetAtomicHierarchy, selected);
    if (setupMatFx != 0)
        RpClumpForAllAtomics(clump, mdlSetupAtomicMatFX, *frame);
    hMaestroUpdateClumpObjects(clump, model->hierarchy);
    model->hierarchy->flags |= 0x3000;
    if (model->source != 0 && model->source->animation != 0) {
        model->first = (RtAnimInterpolator *)func_003d5790(
            model->hierarchy->numNodes,
            model->hierarchy->interpolator->maxInterpKeyFrameSize);
        model->second = (RtAnimInterpolator *)func_003d5790(
            model->hierarchy->numNodes,
            model->hierarchy->interpolator->maxInterpKeyFrameSize);
        func_003d5840(model->first, model->source->animation);
        func_003d5840(model->second, model->source->animation);
        func_003d5e40((u8 *)model->second, 0.0f);
        model->flags |= 0x80;
    }
}
extern s32 func_003d5bc0(void* a, f32 b);

/* measured: probing opt_loop_invariants on for loop-constant placement. */
#pragma push
#pragma opt_loop_invariants on
/* Rebases each node of a layer's output pose by the layer's reference rotation and input clip: out = out * conj(rotation) * input (normalized quaternions), and out.values += rotation.values - input.values. The consumer of the output pose is not yet traced. */
/* measured: keep the reference-interpolator and hierarchy snapshots before the node loop
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00473870
void mdlRebaseLayerPose(u8 *layer)
{
    typedef struct
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } MdlQuat;
    typedef struct
    {
        u8 pad0[8];
        MdlQuat quat;
        f32 values[6];
    } MdlBlendRecord;
    u8 *referenceInterpolator;
    u8 *outputInterpolator;
    u8 *inputInterpolator;
    u8 *rotationInterpolator;
    MdlBlendRecord *out;
    MdlBlendRecord *input;
    MdlBlendRecord *rotation;
    s32 nodeIndex;
    s32 count;
    f32 one;
    f32 zero;
    f32 norm;
    f32 inverse;
    f32 rawY;
    f32 rawX;
    f32 rawZ;
    f32 rawW;
    f32 normW;
    f32 normX;
    f32 normY;
    f32 normZ;
    f32 inputY;
    f32 inputX;
    f32 inputZ;
    f32 inputW;
    f32 quatW;
    f32 crossX;
    f32 crossY;
    f32 crossZ;
    f32 quatX;
    f32 quatY;
    f32 quatZ;
    MdlQuat savedQuat;
    f32 diff1;
    f32 diff2;
    f32 diff0;
    MdlLayerState *layerState = (MdlLayerState *)layer;

    referenceInterpolator = layerState->rebaseInput;
    if ((referenceInterpolator != 0) && ((*(u16 *)layer & 0x80) != 0))
    {
        func_003d5bc0(referenceInterpolator, iGpffff8040);
        count = ((RtAnimInterpolator *)*(u8 * *)&((RpHAnimHierarchy *)layerState->hierarchy)->currentAnim)->numNodes;
        for (nodeIndex = 0, one = 1.0f, zero = 0.0f; nodeIndex < count; nodeIndex++)
        {
            outputInterpolator = *(u8 * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim;
            out = (MdlBlendRecord *)(mdlAddOffset(nodeIndex * ((RtAnimInterpolator *)outputInterpolator)->currentInterpKeyFrameSize,
                                             (u32)outputInterpolator) + 0x4C);
            inputInterpolator = ((MdlLayerState *)layer)->rebaseInput;
            input = (MdlBlendRecord *)(mdlAddOffset(nodeIndex * ((RtAnimInterpolator *)inputInterpolator)->currentInterpKeyFrameSize,
                                               (u32)inputInterpolator) + 0x4C);
            rotationInterpolator = ((MdlLayerState *)layer)->rebaseRotation;
            rotation = (MdlBlendRecord *)(mdlAddOffset(nodeIndex * ((RtAnimInterpolator *)rotationInterpolator)->currentInterpKeyFrameSize,
                                                  (u32)rotationInterpolator) + 0x4C);
            rawY = rotation->quat.y;
            rawX = rotation->quat.x;
            rawZ = rotation->quat.z;
            rawW = rotation->quat.w;
            norm = rawY * rawY;
            norm += rawX * rawX;
            norm += rawZ * rawZ;
            norm += rawW * rawW;
            if (norm > zero)
            {
                inverse = one / norm;
                normW = rawW * inverse;
                inverse = -inverse;
                normX = rawX * inverse;
                normY = rawY * inverse;
                normZ = rawZ * inverse;
            }
            inputY = input->quat.y;
            inputX = input->quat.x;
            inputZ = input->quat.z;
            inputW = input->quat.w;

            quatW = normW * inputW -
                    (normX * inputX +
                     normY * inputY +
                     normZ * inputZ);
            crossX = normY * inputZ - normZ * inputY;
            crossY = normZ * inputX - normX * inputZ;
            crossZ = normX * inputY - normY * inputX;
            crossX = crossX + inputX * normW;
            crossY = crossY + inputY * normW;
            crossZ = crossZ + inputZ * normW;
            quatX = crossX + normX * inputW;
            quatY = crossY + normY * inputW;
            quatZ = crossZ + normZ * inputW;

            savedQuat = *(MdlQuat *)&out->quat;
            out->quat.w = savedQuat.w * quatW -
                          (savedQuat.x * quatX +
                           savedQuat.y * quatY +
                           savedQuat.z * quatZ);
            out->quat.x = savedQuat.y * quatZ - savedQuat.z * quatY;
            out->quat.y = savedQuat.z * quatX - savedQuat.x * quatZ;
            out->quat.z = savedQuat.x * quatY - savedQuat.y * quatX;
            out->quat.x = out->quat.x + quatX * savedQuat.w;
            out->quat.y = out->quat.y + quatY * savedQuat.w;
            out->quat.z = out->quat.z + quatZ * savedQuat.w;
            out->quat.x = out->quat.x + savedQuat.x * quatW;
            out->quat.y = out->quat.y + savedQuat.y * quatW;
            out->quat.z = out->quat.z + savedQuat.z * quatW;

            diff1 = rotation->values[1] - input->values[1];
            diff2 = rotation->values[2] - input->values[2];
            diff0 = rotation->values[0] - input->values[0];
            out->values[0] = out->values[0] + diff0;
            out->values[1] = out->values[1] + diff1;
            out->values[2] = out->values[2] + diff2;
        }
    }
}
#pragma pop

extern void mdlRebaseLayerPose(u8* layer);
extern s32 func_003d5e90(void* a, void* b, void* c, f32 d);
/* Native b210 O2 MATCH: 1432B/window 1440B; the remaining eight bytes are zero.
   Narrow each animation index after its table guard, including the repeated
   sentinel fallback check. Keep the blend input separate from post-callback
   increments, and share only the actual count, sentinel and conversion inputs. */
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
/* Returns input when the layer has no animation. Otherwise advances the layer's clock or blend by the frame delta, rebases its pose, and returns the layer. */
/* measured: keep the member-first clip/start-frame cursors across time/blend callbacks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00473B20
u8 *mdlAdvanceLayer(u8 *layer, u8 *previousLayer, s32 updatePose)
{
    s32 animationIndex;
    u8 *table;
    u8 *animation;
    u8 *animationBase;
    s32 offset;
    s32 selectedIndex;
    s64 count;
    f32 elapsed;
    f32 duration;
    f32 one;
    f32 step;
    f32 progress;
    f32 inputProgress;
    f32 fallbackDuration;
    f32 fallbackStep;
    f32 frameScale;
    f32 frameOffset;
    f32 frameTime;
    u32 flags;
    u8 *emptyAnimation;
    void *currentInterpolator;
    u8 **animationField;

    animationIndex = ((MdlLayerState *)layer)->animationIndex;
    if (animationIndex < 0) {
        return previousLayer;
    }
    if (layer[2] == 1) {
        table = *(u8 * *)&((MdlLayerState *)layer)->resource;
        if (table != 0 && animationIndex < ((MdlDispatchAnimTable *)table)->count) {
            offset = animationIndex * 0x50;
            animation = *(u8 **)(*(u32 *)table + MEMBER_OFFSET(MdlDispatchAnimEntry, animation) + offset);
            if (animation != 0 && animation != (u8 *)D_00922BC0_abs) {
                if (table != 0 && ((MdlDispatchAnimTable *)table)->unknown != 0) {
                    func_003d5e40(*(u8 * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim,
                        ((MdlLayerState *)layer)->time - 1.0f);
                    func_003d5e40(*(u8 * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim,
                        ((MdlLayerState *)layer)->time);
                    mdlRebaseLayerPose(layer);
                }
                func_00397c40(*(void * *)&((MdlLayerState *)layer)->hierarchy);
            }
        }
        return previousLayer;
    }
    elapsed = iGpffff8040 * ((MdlLayerState *)layer)->speed;
    if (!(elapsed <= 0.0f) || (*(u16 *)layer & 6) != 0) {
        inputProgress = ((MdlLayerState *)layer)->blend;
        if (inputProgress < 1.0f) {
            table = *(u8 * *)&((MdlLayerState *)layer)->resource;
            if (table == 0) {
                goto advance_blend;
            }
            selectedIndex = (s16)animationIndex;
            count = ((MdlDispatchAnimTable *)table)->count;
            if (selectedIndex >= count) {
                goto advance_blend;
            }
            offset = selectedIndex * 0x50;
            animationBase = *(u8 **)table + 0x40;
            animationField = (u8 **)(animationBase + offset);
            animation = *animationField;
            if (animation == 0) {
                goto advance_blend;
            }
            emptyAnimation = (u8 *)D_00922BC0_abs;
            if (animation == emptyAnimation) {
                goto advance_blend;
            }
            if (table == 0) {
                goto advance_blend;
            }
            selectedIndex = ((MdlLayerState *)layer)->previousIndex;
            if (selectedIndex >= count) {
                goto advance_blend;
            }
            animationField = (u8 **)(animationBase + selectedIndex * 0x50);
            animation = *animationField;
            if (animation == 0 || animation == emptyAnimation) {
                goto advance_blend;
            }
            func_003d5e90(*(void * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim,
                *(void * *)&((MdlLayerState *)layer)->blendFrom, *(void * *)&((MdlLayerState *)layer)->blendTo,
                inputProgress);
            duration = (f32)(u32)((MdlLayerState *)layer)->blendTicks;
            one = 1.0f;
            step = one / duration;
            progress = ((MdlLayerState *)layer)->blend + step;
            ((MdlLayerState *)layer)->blend = progress;
            if (!(progress < one)) {
                func_003d5840(*(void * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim,
                    *(void **)*(void * *)&((MdlLayerState *)layer)->blendTo);
                animation = *(u8 **)(*(u32 *)*(u8 * *)&((MdlLayerState *)layer)->resource + MEMBER_OFFSET(MdlDispatchAnimEntry, startFrame) + offset);
                if (animation == 0) {
                    func_003d5e40(*(u8 * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim, elapsed);
                } else {
                    frameScale = iGpffff8040;
                    frameOffset = (f32)*(s32 *)animation;
                    frameTime = elapsed + frameScale * frameOffset;
                    func_003d5e40(*(u8 * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim, frameTime);
                }
            }
            goto finish_time;
advance_blend:
            fallbackDuration = (f32)(u32)((MdlLayerState *)layer)->blendTicks;
            fallbackStep = 1.0f / fallbackDuration;
            ((MdlLayerState *)layer)->blend = ((MdlLayerState *)layer)->blend + fallbackStep;
        } else {
            table = *(u8 * *)&((MdlLayerState *)layer)->resource;
            if (table != 0) {
                selectedIndex = (s16)animationIndex;
                if (selectedIndex < (s64)(u32)((MdlDispatchAnimTable *)table)->count) {
                    offset = selectedIndex * 0x50;
                    animation = *(u8 **)(*(u32 *)table + MEMBER_OFFSET(MdlDispatchAnimEntry, animation) + offset);
                    if (animation != 0 && animation != (u8 *)D_00922BC0_abs) {
                        func_003d5bc0(*(void * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim, elapsed);
                        goto finish_time;
                    }
                }
            }
            if (table == 0) {
                goto advance_clock;
            }
            selectedIndex = (s16)animationIndex;
            if (selectedIndex >= (s64)(u32)((MdlDispatchAnimTable *)table)->count) {
                goto advance_clock;
            }
            animationBase = *(u8 **)table;
            offset = selectedIndex * 0x50;
            if (((MdlDispatchAnimEntry *)(offset + (u32)animationBase))->animation == (u8 *)D_00922BC0_abs) {
                goto finish_time;
            }
advance_clock:
            ((MdlLayerState *)layer)->time = ((MdlLayerState *)layer)->time + elapsed;
        }
finish_time:
        *(u16 *)layer &= 0xFFFB;
    }
    table = *(u8 * *)&((MdlLayerState *)layer)->resource;
    if (table != 0) {
        selectedIndex = (s16)animationIndex;
        if (selectedIndex < (s64)(u32)((MdlDispatchAnimTable *)table)->count) {
            offset = selectedIndex * 0x50;
            animation = *(u8 **)(*(u32 *)table + MEMBER_OFFSET(MdlDispatchAnimEntry, animation) + offset);
            if (animation != 0 && animation != (u8 *)D_00922BC0_abs) {
                if ((*(u16 *)layer & 2) != 0 && previousLayer != 0) {
                    currentInterpolator = *(void * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim;
                    mdlBlendAnimInterpolators(currentInterpolator,
                        *(void * *)&((RpHAnimHierarchy *)((MdlLayerState *)previousLayer)->hierarchy)->currentAnim,
                        currentInterpolator, 1.0f);
                }
                mdlRebaseLayerPose(layer);
                if (updatePose != 0) {
                    if ((*(u16 *)layer & 0x10) != 0) {
                        mdlInstallHierarchyScaleHook(*(void * *)&((MdlLayerState *)layer)->hierarchy, layer);
                    } else if ((((MdlLayerState *)layer)->look.flags & 0x81E0) != 0) {
                        mdlUpdateHierarchyPose(*(void * *)&((MdlLayerState *)layer)->hierarchy, layer, layer + 0x54, 0);
                    } else {
                        func_00397c40(*(void * *)&((MdlLayerState *)layer)->hierarchy);
                    }
                }
                flags = ((MdlLayerState *)layer)->look.flags;
                if ((flags & 0x81E0) != 0) {
                    ((MdlLayerState *)layer)->look.flags = flags | 0x4000;
                } else {
                    ((MdlLayerState *)layer)->look.flags = flags & 0xBFFF;
                }
                ((MdlLayerState *)layer)->time = ((RtAnimInterpolator *)*(u8 * *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim)->currentTime;
            }
        }
    }
    return layer;
}

#pragma pop
extern void func_003d59a0(void* a, void* b);
/* MATCH: 1320B instructions plus eight zero-tail bytes. Member-first
   field bases, signed promoted counts and separate attachment offsets
   preserve retail lifetimes. Reuse mdlAddOffset for index-first address sums. */


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
/* Starts an animation on a layer: records the animation index and flags, and stores the blend duration (blendTicks) as f32 at the control block's +0x34. */
/* measured: keep the member-first field bases and attachment-array lookups
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_004740C0
void mdlStartLayerAnimation(u8* layer, s16 animation, u16 blendTicks, s32 flags)
{
    u32 narrowFlags;
    s32 entryCount;
    void* missingClip;
    MdlDispatchAnimTable* table;
    u8* animationFields;
    s32 currentIndex;
    s32 currentOffset;
    s32 nextIndex;
    s32 nextOffset;
    void* clip;
    u8* hierarchy;
    RtAnimInterpolator* base;
    s32* startFrame;
    u8* control;
    u8* fieldBase;
    void **clipField;
    s32 **startFrameField;
    u8 **blendControlField;

    *(u16*)layer &= ~1u;
    narrowFlags = (u16)flags;
    *(u16*)layer |= narrowFlags & 1;
    layer[2] = 0;
    if ((u16)blendTicks > 0 &&
        (currentIndex = ((MdlLayerState *)layer)->animationIndex) != -1 &&
        (table = ((MdlLayerState *)layer)->resource) != 0 &&
        currentIndex < (entryCount = table->count) &&
        (currentOffset = currentIndex * (s32)sizeof(MdlDispatchAnimEntry),
         animationFields = (u8*)table->entries + offsetof(MdlDispatchAnimEntry, animation),
         clipField = (void **)(animationFields + currentOffset), clip = *clipField) != 0 &&
        clip != (missingClip = D_00922BC0_abs) &&
        table != 0 &&
        (nextIndex = (s16)animation) < entryCount &&
        (nextOffset = nextIndex * (s32)sizeof(MdlDispatchAnimEntry),
         clipField = (void **)(animationFields + nextOffset), clip = *clipField) != 0 &&
        clip != missingClip) {
        if (*(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendFrom == 0) {
            hierarchy = ((MdlLayerState *)layer)->hierarchy;
            base = ((RpHAnimHierarchy *)hierarchy)->currentAnim;
            *(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendFrom = (RtAnimInterpolator*)
                func_003d5790(((RpHAnimHierarchy *)hierarchy)->numNodes, base->maxInterpKeyFrameSize);
        }
        if (*(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendTo == 0) {
            hierarchy = ((MdlLayerState *)layer)->hierarchy;
            base = ((RpHAnimHierarchy *)hierarchy)->currentAnim;
            *(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendTo = (RtAnimInterpolator*)
                func_003d5790(((RpHAnimHierarchy *)hierarchy)->numNodes, base->maxInterpKeyFrameSize);
        }
        func_003d5840(*(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendFrom,
            (((MdlLayerState *)layer)->resource)->entries[((MdlLayerState *)layer)->animationIndex].animation);
        func_003d5840(*(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendTo,
            ((MdlDispatchAnimEntry*)(mdlAddOffset((u32)nextOffset, (u32)(((MdlLayerState *)layer)->resource)->entries)))->animation);
        table = ((MdlLayerState *)layer)->resource;
        if (table == 0 || table->unknown == 0) {
            func_003d59a0(*(RtAnimInterpolator* *)&((MdlLayerState *)layer)->blendFrom,
                ((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim);
        } else {
            func_003d5e40(((MdlLayerState *)layer)->blendFrom, ((MdlLayerState *)layer)->time);
        }
        fieldBase = (u8*)(((MdlLayerState *)layer)->resource)->entries + offsetof(MdlDispatchAnimEntry, startFrame);
        startFrameField = (s32 **)(fieldBase + nextOffset);
        startFrame = *startFrameField;
        if (startFrame != 0) {
            func_003d5e40(((MdlLayerState *)layer)->blendTo, iGpffff8040 * (f32)*startFrame);
        }
        ((MdlLayerState *)layer)->previousIndex = ((MdlLayerState *)layer)->animationIndex;
        ((MdlLayerState *)layer)->previousTime = ((MdlLayerState *)layer)->time;
        ((MdlLayerState *)layer)->blendTicks = blendTicks;
        ((MdlLayerState *)layer)->blend = 0.0f;
    } else {
        table = ((MdlLayerState *)layer)->resource;
        if (table != 0 && (nextIndex = (s16)animation) < table->count &&
            (nextOffset = nextIndex * (s32)sizeof(MdlDispatchAnimEntry),
             animationFields = (u8*)table->entries + offsetof(MdlDispatchAnimEntry, animation),
             clipField = (void **)(animationFields + nextOffset), clip = *clipField) != 0 &&
            clip != D_00922BC0_abs) {
            func_003d5840(((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim, clip);
            fieldBase = (u8*)(((MdlLayerState *)layer)->resource)->entries + offsetof(MdlDispatchAnimEntry, startFrame);
            startFrameField = (s32 **)(fieldBase + nextOffset);
            startFrame = *startFrameField;
            if (startFrame == 0) {
                func_003d5e40(*(u8* *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim, 0.0f);
            } else {
                func_003d5e40(*(u8* *)&((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim,
                    iGpffff8040 * (f32)*startFrame);
            }
            RtAnimInterpolatorSetAnimLoopCallBack(((RpHAnimHierarchy *)((MdlLayerState *)layer)->hierarchy)->currentAnim,
                mdlResolveLoopAnimation, layer);
        }
        ((MdlLayerState *)layer)->blendTicks = 0;
        ((MdlLayerState *)layer)->blend = 1.0f;
    }
    ((MdlLayerState *)layer)->look.flags &= ~0x800u;
    if (((MdlLayerState *)layer)->look.flags & 0x81e0) {
        currentOffset = ((MdlLayerState *)layer)->animationIndex * (s32)sizeof(MdlDispatchAnimEntry);
        fieldBase = (u8*)(((MdlLayerState *)layer)->resource)->entries + offsetof(MdlDispatchAnimEntry, blendControl);
        blendControlField = (u8 **)(fieldBase + currentOffset);
        control = *blendControlField;
        if (control != 0) {
            u32 one;
            ((MdlDirectionalBlend *)control)->duration = 0.0f;
            one = 0x3f800000; /* IEEE-754 1.0f, shared by the raw control fields. */
            *(u32 *)&((MdlDirectionalBlend *)(((MdlLayerState *)layer)->resource)->entries[((MdlLayerState *)layer)->animationIndex].blendControl)->progress = one;
            *(u32 *)&((MdlDirectionalBlend *)(((MdlLayerState *)layer)->resource)->entries[((MdlLayerState *)layer)->animationIndex].blendControl)->rotation[3] = one;
            ((MdlDirectionalBlend *)(((MdlLayerState *)layer)->resource)->entries[((MdlLayerState *)layer)->animationIndex].blendControl)->rotation[0] = 0.0f;
            ((MdlDirectionalBlend *)(((MdlLayerState *)layer)->resource)->entries[((MdlLayerState *)layer)->animationIndex].blendControl)->rotation[1] = 0.0f;
            ((MdlDirectionalBlend *)(((MdlLayerState *)layer)->resource)->entries[((MdlLayerState *)layer)->animationIndex].blendControl)->rotation[2] = 0.0f;
        }
        nextOffset = (s16)animation * (s32)sizeof(MdlDispatchAnimEntry);
        fieldBase = (u8*)(((MdlLayerState *)layer)->resource)->entries + offsetof(MdlDispatchAnimEntry, blendControl);
        blendControlField = (u8 **)(fieldBase + nextOffset);
        control = *blendControlField;
        if (control != 0) {
            f32 fraction;
            ((MdlDirectionalBlend *)control)->duration = (f32)(u32)((MdlLayerState *)layer)->blendTicks;
            fraction = ((MdlLayerState *)layer)->blend;
            ((MdlDirectionalBlend *)((MdlDispatchAnimEntry*)(mdlAddOffset((u32)nextOffset, (u32)(((MdlLayerState *)layer)->resource)->entries)))->blendControl)->progress = fraction;
        }
    }
    control = *(u8* *)&((MdlLayerState *)layer)->attachments;
    if (control != 0) {
        nextOffset = (s16)animation * (s32)sizeof(void*);
        ((MdlCloneAttachmentTable *)control)->nextPrimary =
            ((MdlAttachmentSlot *)(*(u8 **)&((MdlCloneAttachmentTable *)control)->primary + nextOffset))->object;
        if (narrowFlags & 0x20) {
            clip = 0;
        } else {
            clip = ((MdlAttachmentSlot *)(*(u8 **)&((MdlCloneAttachmentTable *)control)->secondary + nextOffset))->object;
        }
        ((MdlCloneAttachmentTable *)control)->nextSecondary = clip;
        *(s32 *)&((MdlCloneAttachmentTable *)control)->pendingSecondary = 1;
        ((MdlCloneAttachmentTable *)control)->delay = blendTicks;
    }
    ((MdlLayerState *)layer)->time = 0.0f;
    ((MdlLayerState *)layer)->animationIndex = animation;
}
#pragma pop
/* Releases one reference on an anim entry table (count at +0x6). On the last release it releases the table's entries. */
// FUN_004745F0
void mdlReleaseAnimEntryTable(MdlAnimEntryTable* table)
{
    u16 i;

    table->references--;
    if (table->references == 0) {
        for (i = 0; i < table->count; i++) {
            MdlAnimResourceEntry* entry;

            entry = (MdlAnimResourceEntry*)table->entries;
            entry += i;

            if ((entry->resource != NULL) && ((entry->flags & 1) == 0)) {
                mdlMatAnimFreeList((int)entry->resource);
            }
        }

        (*DAT_008873ec)(table);
    }
}




extern void mdlMatAnimCopyNodeMaterial(int *object);
extern void mdlMatAnimUpdateList(u8 **list, f32 scale1, u8 **referenceList, f32 scale2, f32 scale3);
extern void mdlMatAnimApplyWithPivot(u8 **list, f32 scale1, f32 scale2);
extern void mdlMatAnimApplyScaled(u8 **list, f32 scale);
extern f32 mdlMatAnimMaxDuration(u8 **list);
extern void* mdlResolveLoopAnimation(void* interpolator, u8* layer);
/* measured: u8* params fixed the data+0xC address-CSE (nd 106 -> 54) and
   the mdlMatAnimUpdateList call needs FOUR args (e2, e, *(p2+0x14), 0.0f — the
   a1=$s0 move is deliberate, fixing it removes the shift). Residual
   (nd 54-79): the s16 t lands in $a2 vs retail $a1, the f32 alpha local lands
   in $f13 (arg reg, dead before calls) vs retail $f14 (forcing the
   mov.s $f13,$f14 in the fe90 call), and the fd10 arg materialization order
   (move/lwc1) swaps. Tried: one=1.0f local, alpha/one decl order, void*
   params. FP/integer register-allocation floor. */
/* Updates the blend track in state owner from the animation entry for the slot at input+4. It cross-fades between the current and next entries by the blend factor at input+0x1C when that factor is below 1.0. */
/* measured: keep the entry-array clip lookups and final layer-time reload
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_004746B0
void mdlUpdateBlendTrack(u8* state, u8* layer)
{
    f32 blendFraction;
    f32 animationTime;
    s16 animationIndex;
    s32* resourceTable;
    u8** animation;
    s32 animationClip;
    s32 entries;
    u8** previousAnimation;
    s32 previousMaterialAnimation;
    u32 dispatchTableAddress;
    s32 animationOffset;
    MdlLayerState *layerState = (MdlLayerState *)layer;
    resourceTable = *(s32**)state;
    if ((resourceTable != NULL) &&
        ((animationIndex = ((MdlLayerState *)layer)->animationIndex), (animationIndex >= 0))) {
        entries = *resourceTable;
        animation = (u8 **)((MdlAnimResourceEntry *)entries)[animationIndex].resource;
        blendFraction = ((MdlLayerState *)layer)->blend;
        if (blendFraction < 1.0f) {
            previousAnimation = (u8 **)((MdlAnimResourceEntry *)entries)[((MdlLayerState *)layer)->previousIndex].resource;
            if (previousAnimation != NULL) {
                if (animation != NULL) {
                    mdlMatAnimUpdateList(previousAnimation, ((MdlLayerState *)layer)->previousTime, animation,
                                  0.0f, blendFraction);
                } else {
                    mdlMatAnimApplyWithPivot(previousAnimation, 0.0f, blendFraction);
                }
            } else if (animation != NULL) {
                mdlMatAnimApplyWithPivot(animation, 0.0f, 1.0f - blendFraction);
            }
            *(s32 *)&((MdlMaterialTrack *)state)->active = (s32)animation;
            return;
        }
        if (animation == NULL) {
            previousMaterialAnimation = *(s32 *)&((MdlMaterialTrack *)state)->active;
            if (previousMaterialAnimation != 0) {
                mdlMatAnimCopyNodeMaterial((int*)previousMaterialAnimation);
            }
        } else {
            dispatchTableAddress = *(u32 *)&((MdlLayerState *)layer)->resource;
            if ((dispatchTableAddress != 0) &&
                (animationIndex < ((MdlDispatchAnimTable *)dispatchTableAddress)->count) &&
                ((animationOffset = animationIndex * 0x50,
                 /* measured: plain animationOffset changes 23 bytes; retain the existing address operand order. */
                 animationClip = *(s32*)((u32)((u32)*(s32*)dispatchTableAddress + MEMBER_OFFSET(MdlDispatchAnimEntry, animation)) +
                                    (u32)(animationOffset, animationOffset))),
                 (animationClip != 0)) &&
                ((u8*)animationClip != (u8*)D_00922BC0_abs)) {
                if (animationIndex < 0) {
                    animationTime = 0.0f;
                } else {
                    animationTime = ((MdlLayerState *)layer)->time;
                }
                mdlMatAnimApplyScaled(animation, animationTime);
            } else {
                mdlMatAnimApplyScaled(animation, layerState->time);
                if (((MdlLayerState *)layer)->time > mdlMatAnimMaxDuration(animation)) {
                    mdlResolveLoopAnimation(NULL, layer);
                }
            }
        }
        *(s32 *)&((MdlMaterialTrack *)state)->active = (s32)animation;
    }
}

/* Drops the count at +0xE of a blend track. On the last release it releases the two subobjects, each 8-byte entry, and then the block. */
// FUN_00474890
void mdlReleaseBlendTrack(void* resourceTable)
{
    void* entry;
    int* table;
    s32 entryIndex;

    table = (int*)resourceTable;

    ((MdlAnimResource *)table)->references = ((MdlAnimResource *)table)->references + -1;

    if (((MdlAnimResource *)table)->references == 0) {
        if (*(int *)&((MdlAnimResource *)table)->objects != 0) {
            func_003df7f0((void*)*(int *)&((MdlAnimResource *)table)->objects);
        }

        if (*(int *)&((MdlAnimResource *)table)->unknown04 != 0) {
            func_003d6230((void*)*(int *)&((MdlAnimResource *)table)->unknown04);
        }

        for (entryIndex = 0; (entryIndex & 0xffff) < ((MdlAnimResource *)table)->count; entryIndex = entryIndex + 1 & 0xffff) {
            entry = (void*)((MdlAnimResource *)table)->entries;
            entry = (void*)((u8*)entry + (u16)entryIndex * 8);

            if ((*(int*)entry != 0) &&
                ((*(u8 *)&((MdlLoaderEntry *)(u8*)entry)->flags & 1) == 0)) {
                func_003d6230(*(void**)entry);
            }
        }

        (*DAT_008873ec)(resourceTable);
    }

    return;
}


/* P4 port probe: removing opt_propagation off regresses 00474970 MATCH nd0 -> MISMATCH nd8 (s0/s1 coloring swap, 10 differing words) - measured. */
#pragma opt_propagation off

/* Callback for the clump walk in mdlSetupNamedFrameAnims: appends resource to the list in data unless it is already present, and returns resource. */
// FUN_00474970
int mdlAppendUniqueListEntry(int entry, void* listData)
{
    int* cursor;
    void* list;

    list = listData;
    cursor = (int*)func_003df890(list);
    while (cursor != (int*)func_003df8a0(list)) {
        if (entry == *cursor) {
            return entry;
        }
        cursor++;
    }

    *(int*)func_003df6e0(list, 0) = entry;
    return entry;
}
#pragma opt_propagation on



// Per-atomic step for RpClumpForAllAtomics: runs the callback in data[0] with data[1] over the atomic's entry list at +0x18 (via func_003c21e0), then returns the atomic.
// FUN_00474A10
void* mdlForEachAtomicListEntry(void* atomic, void* data)
{
    u32* callbackData = data;
    func_003c21e0(*(u32 *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry, *callbackData, callbackData[1]);
    return atomic;
}





/* Keyframe blend hook: copies the six floats at +0x8..+0x1C from callbackData to atomic. Installed as keyFrameBlendCB and at interpolator +0x40. The body is identical to mdlKeyFrameInterpolateCopy; retail keeps them at separate addresses, so both stay. */
// FUN_00474A50
void mdlKeyFrameBlendCopy(void* destination, void* source)
{
    ((MdlKeyFrame *)destination)->rotation[0] = ((MdlKeyFrame *)source)->rotation[0];
    ((MdlKeyFrame *)destination)->rotation[1] = ((MdlKeyFrame *)source)->rotation[1];
    ((MdlKeyFrame *)destination)->rotation[2] = ((MdlKeyFrame *)source)->rotation[2];
    ((MdlKeyFrame *)destination)->rotation[3] = ((MdlKeyFrame *)source)->rotation[3];
    ((MdlKeyFrame *)destination)->translation.x = ((MdlKeyFrame *)source)->translation.x;
    ((MdlKeyFrame *)destination)->translation.y = ((MdlKeyFrame *)source)->translation.y;
}

/* Keyframe interpolate hook: copies the six floats at +0x8..+0x1C from data to object. Installed as keyFrameInterpolateCB and at interpolator +0x44. The body is identical to mdlKeyFrameBlendCopy. */
// FUN_00474A90
void mdlKeyFrameInterpolateCopy(void* destination, void* source)
{
    ((MdlKeyFrame *)destination)->rotation[0] = ((MdlKeyFrame *)source)->rotation[0];
    ((MdlKeyFrame *)destination)->rotation[1] = ((MdlKeyFrame *)source)->rotation[1];
    ((MdlKeyFrame *)destination)->rotation[2] = ((MdlKeyFrame *)source)->rotation[2];
    ((MdlKeyFrame *)destination)->rotation[3] = ((MdlKeyFrame *)source)->rotation[3];
    ((MdlKeyFrame *)destination)->translation.x = ((MdlKeyFrame *)source)->translation.x;
    ((MdlKeyFrame *)destination)->translation.y = ((MdlKeyFrame *)source)->translation.y;
}

/* No-op keyframe blend hook (empty body). In this file it is only compared against keyFrameBlendCB (keyframe-hook path near line 2851); the install site is not yet traced. */
// FUN_00474AD0
void mdlKeyFrameBlendNoOp(void) {}

/* No-op keyframe interpolate hook (empty body). Compared against keyFrameInterpolateCB beside mdlKeyFrameBlendNoOp; the install site is not yet traced. */
// FUN_00474AE0
void mdlKeyFrameInterpolateNoOp(void) {}
/* Anim-loop callback for RtAnimInterpolatorSetAnimLoopCallBack. When the slot entry at the state's raw index is valid and not already flagged, it sets the interpolator time from its first sub-object (func_003d5e40_typed) and sets the loop-done byte at state+1. */
// FUN_00474AF0
void* mdlAnimLoopRewind(void* interpolator, u16* control)
{
    s16 rawIndex;
    u16 count;
    s64 signedIndex;
    int* resource;

    rawIndex = (s16)control[2];
    resource = *(int* *)&((MdlAnimControl *)control)->resource;
    if (resource != (int*)0x0) {
        signedIndex = (s64)rawIndex;
        count = ((MdlAnimResource *)resource)->count;
        if ((((signedIndex < (s64)(u32)count) &&
              (*(int *)&((MdlLoaderEntry *)(*resource + rawIndex * 8))->value != 0)) && ((*control & 1) == 0)) &&
            ((signedIndex < (s64)(u32)count && (0 <= rawIndex)))) {
            func_003d5e40_typed(((RtAnimAnimation *)*(int*)interpolator)->duration, interpolator);
            ((MdlAnimControl *)control)->mode = 1;
        }
    }

    return interpolator;
}




/* measured: probing opt_propagation off for first-target register scheduling. */
#pragma opt_propagation off
/* Anim-loop callback with two modes. With no state, or a valid state whose flag bit 0 is set, it re-seeds the interpolator (func_003d5840) and installs the accessor hooks at +0x40 and +0x44. Otherwise it sets the interpolator time as mdlAnimLoopRewind does and sets the state's +2 byte. */
/* measured: keep the state index/resource snapshots on the rewind path
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00474BA0
void* mdlAnimLoopCallback(void* interpolator, void* control)
{
    struct MdlAnimLoopContext {
        u16 flags;
        u8 pad2[2];
        s16 rawIndex;
        u8 pad[0x12];
        int* list;
    };
    s16 rawIndex;
    u16 count;
    s64 signedIndex;
    int* resource;
    MdlAnimControl *animationControl = (MdlAnimControl *)control;

    if (control == (void*)0 ||
        ((rawIndex = ((struct MdlAnimLoopContext*)control)->rawIndex,
          resource = ((struct MdlAnimLoopContext*)control)->list,
          resource != (int*)0) &&
         (signedIndex = (s64)rawIndex,
          count = ((MdlAnimResource *)resource)->count,
          signedIndex < (s64)(u32)count) &&
         (*(int *)&((MdlLoaderEntry *)(*resource + rawIndex * 8))->value != 0) &&
         ((*(u16*)control & 1) != 0))) {
        func_003d5840(interpolator, *(void**)interpolator);
        *(void* *)&((RtAnimInterpolator *)(u8*)interpolator)->keyFrameBlendCB = (void*)mdlKeyFrameBlendCopy;
        ((RtAnimInterpolator *)(u8*)interpolator)->keyFrameInterpolateCB = (void*)mdlKeyFrameInterpolateCopy;
        return interpolator;
    }

    rawIndex = animationControl->index;
    resource = (int *)animationControl->resource;
    if (resource != (int*)0) {
        signedIndex = (s64)rawIndex;
        count = ((MdlAnimResource *)resource)->count;
        if ((signedIndex < (s64)(u32)count) &&
            (*(int *)&((MdlLoaderEntry *)(*resource + rawIndex * 8))->value != 0) &&
            ((*(u16*)control & 1) == 0) &&
            (signedIndex < (s64)(u32)count) &&
            (rawIndex >= 0)) {
            func_003d5e40(interpolator, ((RtAnimAnimation *)*(int*)interpolator)->duration);
            ((MdlAnimControl *)control)->mode = 1;
        }
    }

    return interpolator;
}
#pragma opt_propagation on
/* Returns the string value of the frame's name-keyed user-data entry, or 0 when the frame has none. The key string at DAT_007641c8 is not yet read from rodata; callers use the result as the object name (consumer not yet traced). */
// FUN_00474CE0
u32 mdlGetFrameNameUserData(void* frame)
{
    s32 valueCount;
    s32 arrayCount;
    s32 arrayIndex;
    char* arrayName;
    s32 userDataType;
    s32 valueIndex;
    RpUserDataArray* userDataEntry;

    arrayCount = func_003bcfb0(frame);
    arrayIndex = 0;
    while (arrayIndex < arrayCount) {
        userDataEntry = func_003bd000(frame, arrayIndex);
        arrayName = func_003bd040(userDataEntry);
        if (strcmp(arrayName, DAT_007641c8) == 0) {
            valueCount = func_003bd060(userDataEntry);
            valueIndex = 0;
            while (valueIndex < valueCount) {
                userDataType = func_003bd050(userDataEntry);
                if (userDataType == 3) {
                    return (u32)func_003bd0b0((u8*)userDataEntry, valueIndex);
                }
                valueIndex++;
            }
        }
        arrayIndex++;
    }
    return 0;
}



/* Sets up the named-frame animations of a clump. Collects the clump's frames into a new list stored at frame+0x18, then for each frame whose name user data begins with the five-character prefix it installs the loop callback and the copy hooks on that frame's animation interpolator. */
/* measured: keep the resource pointer reloads around frame enumeration
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00474DF0
void mdlSetupNamedFrameAnims(u8* control, void* clump)
{
    u32 frames;
    u32* frameEntry;
    u32* framesEnd;
    u32 userData;
    u32 animation;

    struct {
        code callback;
        u32 value;
    } callbackData;
    MdlAnimControl *animationControl = (MdlAnimControl *)control;

    if ((animationControl->resource != 0) &&
        (*(u32 *)&((MdlAnimControl *)control)->primaryTime = 0, animationControl->resource->objects == 0)) {
        frames = func_003df5d0(4, 0);

        callbackData.callback = (code)mdlAppendUniqueListEntry;
        callbackData.value = frames;

        RpClumpForAllAtomics(clump, mdlForEachAtomicListEntry, &callbackData);

        *(u32 *)&animationControl->resource->objects = frames;

        for (frameEntry = (u32*)func_003df890((s32*)animationControl->resource->objects);
             framesEnd = (u32*)func_003df8a0(*(u32 *)&((MdlAnimResource *)*(int *)&((MdlAnimControl *)control)->resource)->objects),
             frameEntry != framesEnd; frameEntry = frameEntry + 1) {
            userData = mdlGetFrameNameUserData((void*)*frameEntry);

            if (((userData != 0) && (strncmp(userData, &gp0xffff9d10, 5) == 0)) &&
                (animation = func_003d8130(*frameEntry, 0), animation != 0)) {
                RtAnimInterpolatorSetAnimLoopCallBack(animation, mdlAnimLoopCallback, 0);

                *(u8* *)&((RtAnimInterpolator *)(int)animation)->keyFrameBlendCB = LAB_00474a50_abs;
                *(u8* *)&((RtAnimInterpolator *)(int)animation)->keyFrameInterpolateCB = LAB_00474a90_abs;
            }
        }
    }

    return;
}




/* Atomic callback: when the clump's MatFX state is active, sets the atomic's MatFX mode to 2 if any material has MatFX effects and to 1 otherwise (modes 0 and 3 are left alone). When the state is inactive but effects are present, it calls func_00399b10. */
// FUN_00474F40
void* mdlSyncAtomicMatFx(void* atomic, void* context)
{
    void* geometry;
    s32 materialCount;
    s32 materialIndex;
    s32 hasEffects;
    s32 mode;

    geometry = *(void* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    if (geometry == 0) {
        return atomic;
    }
    hasEffects = 0;
    materialCount = *(s32 *)&((MdlGeometry *)geometry)->count;
    materialIndex = 0;
    while (materialIndex < materialCount && hasEffects == 0) {
        if (RpMatFXMaterialGetEffects(((MdlGeometry *)geometry)->materials[materialIndex]) != 0) {
            hasEffects = 1;
        }
        materialIndex++;
    }
    if (func_003b83f0((int)geometry) != 0) {
        mode = func_003b85b0(atomic);
        switch (mode) {
        case 0:
        case 3:
            break;
        default:
        case 1:
        case 2:
            if (hasEffects != 0) {
                func_003b8520(atomic, 2);
            } else {
                func_003b8520(atomic, 1);
            }
            break;
        }
    } else if (hasEffects != 0) {
        func_00399b10((s32)atomic);
    }
    return atomic;
}
/* Atomic callback: when the atomic's object is larger than 0x40 units, runs mdlSetupMatFXMaterial on each of its materials. */
// FUN_00475090
void* mdlSetupMatFXMaterials(void* atomic, void* data)
{
    int geometry;
    int materialCount;
    u32 skin;
    u32 boneCount;
    int materialIndex;

    geometry = *(int *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    if (geometry == 0) {
        return atomic;
    }

    skin = func_003b83f0(geometry);
    if (skin == 0) {
        return atomic;
    }

    boneCount = func_003b8500(skin);
    if (boneCount <= 0x40) {
        return atomic;
    }

    materialCount = *(int *)&((MdlGeometry *)geometry)->count;
    for (materialIndex = 0; materialIndex < materialCount; materialIndex = materialIndex + 1) {
        mdlSetupMatFXMaterial((u32)((MdlGeometry *)geometry)->materials[materialIndex]);
    }

    return atomic;
}




/* measured: MATCHED this wave (nd 0) — the old note's nd 111 floor was an
   artifact of the || / if-else-if dispatch spelling. Working spelling:
   switch(func_00399d80(*it)){case 5: case 6:} reproduces retail's
   beq 6/beq 5/b-skip with the body out of line; the cb checks must compare
   and store *(void**)(obj2+0x40) against (void*)mdlKeyFrameBlendCopy/mdlKeyFrameInterpolateCopy
   (u32 casts also work, void* keeps mwcc from adding conversions);
   re-read owner->0x18 fresh for `list` (retail re-issues the lw). */
/* Sets the animation control time (owner+0xC and +0x10) to fparg0, and applies the same time to the copy-hooked interpolators of the frame's MatFX objects (effect kinds 5 and 6), on the primary and, unless owner+2 is 1, the secondary slot. */
/* measured: keep the resource/list snapshot and copy-hook callback comparisons
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00475170
void mdlSetAnimControlTime(u8* control, f32 time)
{
    u32* objectEntry;
    u32 objects;
    u8* entryState;
    MdlAnimResource *resource;
    RtAnimInterpolator *frameAnimation;

    entryState = MEMBER(u8*, control, MdlAnimControl, resource);
    resource = (MdlAnimResource *)entryState;
    if (entryState != 0 && *(u32 *)&resource->objects != 0) {
        ((MdlAnimControl *)control)->primaryTime = time;
        ((MdlAnimControl *)control)->secondaryTime = time;
        objects = *(u32 *)&((MdlAnimResource *)*(u8* *)&((MdlAnimControl *)control)->resource)->objects;
        objectEntry = (u32*)func_003df890((s32*)objects);
        while (objectEntry != (u32*)func_003df8a0(objects)) {
            switch (RpMatFXMaterialGetEffects(*objectEntry)) {
            case 5:
            case 6:
                entryState = (u8*)func_003d8130(*objectEntry, 0);
                frameAnimation = (RtAnimInterpolator *)entryState;
                if (entryState != 0) {
                    if (*(void **)&frameAnimation->keyFrameBlendCB == (void*)mdlKeyFrameBlendCopy &&
                        frameAnimation->keyFrameInterpolateCB == (void*)mdlKeyFrameInterpolateCopy) {
                        func_003d5e40(entryState, time);
                        *(void* *)&((RtAnimInterpolator *)entryState)->keyFrameBlendCB = (void*)mdlKeyFrameBlendCopy;
                        ((RtAnimInterpolator *)entryState)->keyFrameInterpolateCB = (void*)mdlKeyFrameInterpolateCopy;
                    } else {
                        func_003d5e40(entryState, time);
                    }
                }
                if (((MdlAnimControl *)control)->mode != 1) {
                    entryState = (u8*)func_003d8130(*objectEntry, 1);
                    frameAnimation = (RtAnimInterpolator *)entryState;
                    if (entryState != 0) {
                        if (*(void **)&frameAnimation->keyFrameBlendCB == (void*)mdlKeyFrameBlendCopy &&
                            frameAnimation->keyFrameInterpolateCB == (void*)mdlKeyFrameInterpolateCopy) {
                            func_003d5e40(entryState, time);
                            *(void* *)&((RtAnimInterpolator *)entryState)->keyFrameBlendCB = (void*)mdlKeyFrameBlendCopy;
                            ((RtAnimInterpolator *)entryState)->keyFrameInterpolateCB = (void*)mdlKeyFrameInterpolateCopy;
                        } else {
                            func_003d5e40(entryState, time);
                        }
                    }
                }
                break;
            }
            objectEntry++;
        }
    }
}



/* Prefix view of the interpolation scheme in rw/inc/rtanim.h. */
typedef struct MdlAnimScheme {
    s32 typeID;
    s32 interpKeyFrameSize;
    s32 animKeyFrameSize;
    void *keyFrameApplyCB;
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB;
    void *keyFrameInterpolateCB;
} MdlAnimScheme;
typedef struct RtAnimInterpolatorInfo RtAnimInterpolatorInfo;

extern RtAnimAnimation *func_003d6170(void *, u32);
extern s32 func_003d5750(RtAnimAnimation *);
extern void func_003d7c50(RtAnimAnimation *);
extern void func_003d7cd0(RtAnimAnimation *);
extern void func_003d8070();
extern void func_0039a700();
extern void func_00399bf0();
extern s32 iGpffffb74c;

/* The registered runtime offset selects the plugin; its secondary-interpolator
 * slot follows the fixed twelve-byte plugin header. */
typedef struct MdlInterpolatorPlugin {
    u8 pad00[12];
    u32 secondary;
} MdlInterpolatorPlugin;
static inline void mdlSetupDetach(u32 *object) {
    RtAnimInterpolator *interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
    if (interpolator != 0) {
        func_003d7c50(interpolator->pCurrentAnim);
        func_003d5830(interpolator);
        ((MdlInterpolatorPlugin *)((u8 *)*object + iGpffffb74c))->secondary = 0;
    }
}

/* 1220/1232 bytes; 46 resolved relocations and twelve zero alignment bytes.
 * Animation and blend use their signed/unsigned short domains. The raw
 * flag word is narrowed at use; the dispatcher shares this typed boundary.
 * Keep the animation and interpolator lifetimes in this declaration order. */
/* Starts resource animation index on the clump's named frames, blending from the current one over blend ticks. Frames whose clip is missing are detached. */
// FUN_00475350
void mdlStartAnimation(void *clump, MdlAnimControl *state,
                       s16 index, u16 blend, s32 flags)
{
    MdlAnimResource *resource;
    u32 *object;
    u32 name;
    RtAnimInterpolator *interpolator;
    RtAnimAnimation *animation;
    s32 special;
    if (state->resource != 0) {
        state->flags &= ~1u;
        state->flags |= (u16)flags & 0xffff & 1;
        state->mode = 0;
        state->secondaryTime = 0;
        if (blend > 0 && state->index != -1 && state->resource != 0 &&
            state->index < state->resource->count && state->resource->entries[state->index].resource != 0 &&
            state->resource != 0 && (s64)index < state->resource->count && state->resource->entries[index].resource != 0)
            state->ticks = blend;
        else
            state->ticks = 0;
        resource = state->resource;
        if (resource != 0 && (s64)index < resource->count && resource->entries[index].resource != 0) {
            s32 *objects = resource->objects;
            for (object = (u32 *)func_003df890(objects); object != (u32 *)func_003df8a0(objects); ++object) {
                switch (RpMatFXMaterialGetEffects(*object)) {
                case 5: case 6: func_0039a700(*object, 0, 0); break;
                }
                name = mdlGetFrameNameUserData((void *)*object);
                if (name != 0) {
                    animation = func_003d6170(((MdlAnimResourceEntry *)mdlAddOffset((s32)index * 8, (u32)state->resource->entries))->resource, name);
                    if (animation != 0) {
                        special = strncmp(name, &gp0xffff9d10, 5) == 0;
                        interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
                        if (interpolator != 0) {
                            s32 nodeCount;
                            func_003d7c50(interpolator->pCurrentAnim);
                            nodeCount = interpolator->numNodes;
                            if (nodeCount != func_003d5750(animation) || interpolator->currentInterpKeyFrameSize != ((MdlAnimScheme *)animation->interpInfo)->interpKeyFrameSize) {
                                func_003d5830(interpolator);
                                interpolator = 0;
                            }
                        }
                        if (interpolator != 0) {
                            func_003d5840(interpolator, animation);
                            func_003d7cd0(animation);
                        } else {
                            func_003d8070(*object, animation, 1);
                            interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
                        }
                        if (func_003d5750(animation) == 1) func_00399bf0(*object, 5);
                        else func_00399bf0(*object, 6);
                        if (special == 1) {
                            RtAnimInterpolatorSetAnimLoopCallBack(interpolator, mdlAnimLoopCallback, state);
                            interpolator->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendCopy;
                            interpolator->keyFrameInterpolateCB = (void *)mdlKeyFrameInterpolateCopy;
                        } else {
                            RtAnimInterpolatorSetAnimLoopCallBack(interpolator, mdlAnimLoopRewind, state);
                            interpolator->keyFrameBlendCB = ((MdlAnimScheme *)animation->interpInfo)->keyFrameBlendCB;
                            interpolator->keyFrameInterpolateCB = ((MdlAnimScheme *)animation->interpInfo)->keyFrameInterpolateCB;
                        }
                    } else mdlSetupDetach(object);
                }
            }
            RpClumpForAllAtomics(clump, mdlSetupMatFXMaterials, 0);
            RpClumpForAllAtomics(clump, mdlSyncAtomicMatFx, 0);
        } else {
            s32 *objects = resource->objects;
            for (object = (u32 *)func_003df890(objects); object != (u32 *)func_003df8a0(objects); ++object)
                if (mdlGetFrameNameUserData((void *)*object) != 0) mdlSetupDetach(object);
        }
        state->index = index;
    }
}

/* IDA 00475820, mdlManager.c:1687-1775: primary and secondary interpolators
   have separate lifetimes, including the mode-1 callback-only path.
   Measured 744B/752B: instruction match, followed by 8 zero tail bytes. */
#pragma push
#pragma always_inline on

static inline void mdlStepSecondary(MdlAnimControl* state, u32* it)
{
    if (state->mode != 1) {
        RtAnimInterpolator* interp;
        interp = (RtAnimInterpolator*)func_003d8130(*it, 1);
        if (interp != NULL) {
            if (interp->keyFrameBlendCB == (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendCopy &&
                interp->keyFrameInterpolateCB == (void*)mdlKeyFrameInterpolateCopy) {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, mdlAnimLoopCallback, state);
                func_003d5e40((u8*)interp, state->secondaryTime);
                interp->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendCopy;
                interp->keyFrameInterpolateCB = (void*)mdlKeyFrameInterpolateCopy;
            } else {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, mdlAnimLoopRewind, state);
                if (interp->keyFrameBlendCB != (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendNoOp &&
                    interp->keyFrameInterpolateCB != (void*)mdlKeyFrameInterpolateNoOp) {
                    func_003d5e40((u8*)interp, state->secondaryTime);
                }
            }
            state->secondaryTime = interp->currentTime;
        }
        return;
    }
    {
        RtAnimInterpolator* interp;
        interp = (RtAnimInterpolator*)func_003d8130(*it, 1);
        if (interp != NULL) {
            if (interp->keyFrameBlendCB == (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendCopy &&
                interp->keyFrameInterpolateCB == (void*)mdlKeyFrameInterpolateCopy) {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, mdlAnimLoopCallback, state);
            } else {
                RtAnimInterpolatorSetAnimLoopCallBack(interp, mdlAnimLoopRewind, state);
            }
        }
    }
}

static inline void mdlStepAnimObject(MdlAnimControl* state, u32* it)
{
    extern s32 func_003d7cf0(u32 object);
    RtAnimInterpolator* interp;
    switch (RpMatFXMaterialGetEffects(*it)) {
    case 5:
    case 6:
        break;
    default:
        return;
    }
    interp = (RtAnimInterpolator*)func_003d8130(*it, 0);
    if (interp != NULL) {
        if (interp->keyFrameBlendCB == (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendCopy &&
            interp->keyFrameInterpolateCB == (void*)mdlKeyFrameInterpolateCopy) {
            func_003d5e40((u8*)interp, state->primaryTime);
            interp->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)mdlKeyFrameBlendCopy;
            interp->keyFrameInterpolateCB = (void*)mdlKeyFrameInterpolateCopy;
        } else {
            func_003d5e40((u8*)interp, state->primaryTime);
        }
        state->primaryTime = interp->currentTime;
    }
    mdlStepSecondary(state, it);
    func_003d7cf0(*it);
}

/* Advances an animation control by one tick: decrements the tick count, adds the global step to primaryTime, copies input's primaryTime to secondaryTime, and steps each object of the resource (mdlStepAnimObject). */
// FUN_00475820
void mdlAdvanceAnimControl(void* controlData, void* layerData)
{
    MdlAnimControl* state = (MdlAnimControl*)controlData;
    u32* it;
    void* list;
    if (state->resource != NULL && state->resource->objects != NULL) {
        if (state->ticks != 0)
            --state->ticks;
        state->primaryTime = state->primaryTime + iGpffff8040;
        state->secondaryTime = ((MdlAnimControl*)layerData)->primaryTime;
        list = state->resource->objects;
        for (it = (u32*)func_003df890(list); it != (u32*)func_003df8a0(list); ++it) {
            mdlStepAnimObject(state, it);
        }
    }
}
#pragma pop

typedef struct MdlFrameSearch {
    void* frame;
    s32 id;
} MdlFrameSearch;

/* Recursive frame search by id: when the object's id (func_00397470) matches the search id, it stores the object in the search and stops; otherwise it recurses into the object's children. */
// FUN_00475B10
void* mdlFindFrameById(void* object, void* data)
{
    MdlFrameSearch* search = (MdlFrameSearch*)data;
    if (search->id == func_00397470(object)) {
        search->frame = object;
        return NULL;
    }

    func_003e9af0(object, mdlFindFrameById, data);
    return object;
}




/* Keep the root fast path separate from recursive child traversal.
   The inlined return paths preserve the retail branch layout. */
static inline u8* mdlFindFrame(u8* frame, s32 id)
{
    MdlFrameSearch data;
    if (id == func_00397470(frame))
        return frame;
    data.id = id;
    data.frame = NULL;
    func_003e9af0(frame, mdlFindFrameById, &data);
    return data.frame;
}

/* MATCH: 312B/320B, with two zero-tail words. IDA-backed frame lookup
   lifetime and pointer-valued userdata preserve every retail instruction. */
/* Computes an attachment matrix: finds the entry with key idx in the table v, and writes entry * frame matrix into buf, where the frame is found by the entry's field at +0x44 under the clump of obj. Returns 0 when no entry or frame matches. */
// FUN_00475B90
int mdlComputeAttachMatrix(void* destination, void* tableData, u32 attachmentId, void* clumpData)
{
    s32 count;
    u16 entryIndex;
    u32 maskedId;
    void* entry;
    u8* clump;
    s32 frameId;

    count = (s32)*(u16*)tableData;
    entryIndex = 0;
    maskedId = attachmentId & 0xFFFF;
    while ((s32)(u16)entryIndex < count) {
        entry = (void*)((u8*)*(void* *)&((MdlMatrixTable *)tableData)->entries + (u32)(u16)entryIndex * 0x50);
        if (maskedId == ((MdlMatrixEntry *)entry)->id) {
            break;
        }
        entryIndex++;
    }
    if ((s32)(u16)entryIndex == count) {
        return 0;
    }

    entry = (void*)((u8*)*(void* *)&((MdlMatrixTable *)tableData)->entries + (u32)(u16)entryIndex * 0x50);
    frameId = ((MdlMatrixEntry *)entry)->frameId;
    clump = ((RwObject *)clumpData)->parent;
    clump = mdlFindFrame(clump, frameId);
    if (clump == 0) {
        return 0;
    }

    RwMatrixMultiply(destination, entry, func_003e9700(clump));
    return 1;
}

/* RenderWare quaternion/slerp definitions mirror rtquat.h, rtslerp.h and rwplcore.h.
 * The full SDK headers conflict with this unit's existing RwV3d/RwMatrix types. */
extern f32 fabsf(f32);
typedef struct MdlRenderDevice {
    void (*set)(s32, s32);
    void (*get)(s32, void*);
} MdlRenderDevice;
typedef f32 RwReal;
typedef s32 RwBool;
#define MACRO_START do
#define MACRO_STOP while(0)
typedef struct RtQuat RtQuat;
struct RtQuat
{
    RwV3d               imag;   /**< The imaginary part(s) */
    RwReal              real;   /**< The real part */
};

typedef struct RtQuatSlerpCache RtQuatSlerpCache;
struct RtQuatSlerpCache
{
    RtQuat              raFrom; /**< Scaled initial quaternion  */
    RtQuat              raTo;   /**< Scaled final quaternion */
    RwReal              omega;  /**< Angular displacement in radians */
    RwBool              nearlyZeroOm; /**< Flags near-zero angular 
                                                displacement*/
};
#define   _RW_S1      ( (float)-1.6666667163e-01 )
#define   _RW_S2      ( (float) 8.3333337680e-03 )
#define   _RW_S3      ( (float)-1.9841270114e-04 )
#define   _RW_S4      ( (float) 2.7557314297e-06 )
#define   _RW_S5      ( (float)-2.5050759689e-08 )
#define   _RW_S6      ( (float) 1.5896910177e-10 )
#define RwSinMinusPiToPiMacro(result, x)                          \
do                                                                \
{                                                                 \
    const float z = x * x;                                        \
    const float v = z * x;                                        \
    const float r = ( _RW_S2 +                                    \
                      z * (_RW_S3 +                               \
                           z * (_RW_S4 +                          \
                                z * (_RW_S5 +                     \
                                     z * _RW_S6))) );             \
    result = x + v * (_RW_S1 + z * r);                            \
}                                                                 \
while(0)                                                                  

#define RwV3dScaleMacro(o, a, s)                                \
MACRO_START                                                     \
{                                                               \
    (o)->x = (((a)->x) * ( (s)));                               \
    (o)->y = (((a)->y) * ( (s)));                               \
    (o)->z = (((a)->z) * ( (s)));                               \
}                                                               \
MACRO_STOP

#define RwV3dIncrementScaledMacro(o, a, s)                      \
MACRO_START                                                     \
{                                                               \
    (o)->x += (((a)->x) * ( (s)));                              \
    (o)->y += (((a)->y) * ( (s)));                              \
    (o)->z += (((a)->z) * ( (s)));                              \
}                                                               \
MACRO_STOP

#define RtQuatSlerpMacro(qpResult, qpFrom, qpTo, rT, sCache)            \
MACRO_START                                                             \
{                                                                       \
    if ((rT) <= ((RwReal) 0))                                           \
    {                                                                   \
        /* t is before start */                                         \
        *(qpResult) = *(qpFrom);                                        \
    }                                                                   \
    else if (((RwReal) 1) <= (rT))                                      \
    {                                                                   \
                                                                        \
        /* t is after end */                                            \
        *(qpResult) = *(qpTo);                                          \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* ... so t must be in the interior then */                     \
        /* Calc coefficients rSclFrom, rSclTo */                        \
        RwReal rSclFrom = ((RwReal) 1) - (rT);                          \
        RwReal rSclTo = (rT);                                           \
                                                                        \
        if (!((sCache)->nearlyZeroOm))                                  \
        {                                                               \
            /* Standard case: slerp */                                  \
            /* SLERPMESSAGE(("Neither nearly ZERO nor nearly PI")); */  \
                                                                        \
            rSclFrom *= (sCache)->omega;                                \
            RwSinMinusPiToPiMacro(rSclFrom, rSclFrom);                   \
            rSclTo *= (sCache)->omega;                                  \
            RwSinMinusPiToPiMacro(rSclTo, rSclTo);                       \
        }                                                               \
                                                                        \
        /* Calc final values */                                         \
        RwV3dScaleMacro(&(qpResult)->imag,                              \
                        &(sCache)->raFrom.imag, rSclFrom);              \
        RwV3dIncrementScaledMacro(&(qpResult)->imag,                    \
                             &(sCache)->raTo.imag, rSclTo);             \
        (qpResult)->real =                                              \
            ((sCache)->raFrom.real * rSclFrom) +                        \
            ((sCache)->raTo.real * rSclTo);                             \
    }                                                                   \
}                                                                       \
MACRO_STOP
#define RtQuatNegateMacro( result, q )                                     \
MACRO_START                                                                \
{                                                                          \
    (result)->real = -(q)->real;                                           \
    (result)->imag.x = -(q)->imag.x;                                       \
    (result)->imag.y = -(q)->imag.y;                                       \
    (result)->imag.z = -(q)->imag.z;                                       \
}                                                                          \
MACRO_STOP
typedef struct MdlDrawState {
    RwMatrix matrix;
    RwMatrix identityMatrix;
    RwV3d scale;
    u8 unknown8c[0xD0-0x8C];
    RwRGBA color;
    u32 unknownD4;
    u32 flagsD8;
    void* clump;
    void* e0;
    u8 unknownE4[8];
    u16 animFlags;
    u8 unknownEE[2];
    s16 animIndex;
    u8 unknownF2[0x10C-0xF2];
    void* hierarchy;
    u8 unknown110[0x120-0x110];
    void* animations;
    void* effect124;
    u8 unknown128[0x140-0x128];
    u16 flags140;
    u8 unknown142[0x234-0x142];
    u8 state234[0x2C];
    u8 flags;
    u8 unknown261[3];
    RtQuat rotation;
    f32 limit;
    f32 targetLimit;
    f32 limitRate;
    u8 alpha;
    u8 targetAlpha;
    u8 alphaStep;
    u8 unknown283;
    f32 minBlend;
    f32 maxAngle;
    u8 unknown28C[0x2CC-0x28C];
    u8* effect2CC;
} MdlDrawState;

extern void RpSkyRenderStateSet(s32 a, s32 b);
extern void mdlClumpApplyMatColorScale(void* clump, u32* color, u16 flags);
extern void mdlUpdateModelMatrix(Model* model);
extern s32 RtQuatConvertFromMatrix(RtQuat* out, const RwMatrix* in);
extern RwV3d* RtQuatTransformVectors(RwV3d* out, const RwV3d* in, s32 count, const RtQuat* quat);
extern void func_003dcc70(f32* first, f32* second, void* result);
extern f32 func_0044b920(f32 value);
extern u8 *K_Clump_GetLightB(void);
extern u8 *K_Clump_GetLightC(void);
extern void mdlUpdateBlendTrack(u8* state, u8* layer);
extern void mdlDrawVisibleAtomics(void* clump);
extern void* mdlGetMatrix(void* model);
extern s32 mdlCopyIndexedMatrix(void* model, s32 index, void* destination);
extern s32 mdlPrepareSlotModel(u8* model, u16 slotIndex);
extern void mdlEffectListBuildTransforms(u8** list, u8* model);
extern void mdlEffectListSetUniformScale(s32* list, f32* scale);
extern void mdlRefreshSecondaryEffect(u8* attachment, void* model);
extern void (*D_00887300_abs[])(s32, s32);
extern void (*D_00887304[])(s32, void*);

// Advances one model's draw state by one frame: steps owner->alpha toward owner->targetAlpha by alphaStep, sets the colour alpha from it, and blends owner->rotation toward a light-derived quaternion, limited by owner->minBlend.
/* Retail ORs identity.flags at sp+0xCC (0x004764F0) before its first store at
 * 0x00476500; nothing earlier defines that word. The C keeps the same
 * read-modify-write of the uninitialised field. */
/* measured: keep the delayed attachment draw/delay accesses
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00475CD0
void mdlUpdateDrawState(MdlDrawState* owner)
{
    s32 current;
    s32 target;
    s32 value;
    u32 flags;
    u16 j;
    u16 layer;
    MdlDrawState* model;
    RwRGBA color;
    s32 renderState;
    RwV3d direction;
    RwMatrix matrix1;
    RwMatrix matrix0;
    RwMatrix identity;
    RtQuatSlerpCache interpolation;
    RtQuat result;
    RtQuat quaternion;
    MdlRenderDevice* renderStateSet;

    target = owner->targetAlpha;
    current = owner->alpha;
    if (current < target) {
        value = current + owner->alphaStep;
        if (target < value) {
            owner->alpha = (u8)target;
        } else {
            owner->alpha = (u8)value;
        }
    } else if (target < current) {
        value = current - owner->alphaStep;
        if (value < target) {
            owner->alpha = (u8)target;
        } else {
            owner->alpha = (u8)value;
        }
    } else {
        owner->alpha = (u8)target;
    }

    color.red = 0;
    color.green = 0;
    color.blue = 0;
    color.alpha = (u8)(255.0f * ((f32)(owner->alpha
                         * owner->color.alpha) / (255 * 255)));

    {
    u8* material;
    flags = owner->flags;
    if ((flags & 1) != 0 && (flags & 0x20) == 0) {
        material = (u8 *)((RwObject *)K_Clump_GetLightB())->parent;
    } else {
        material = (u8 *)((RwObject *)K_Clump_GetLightC())->parent;
    }

    flags = owner->flags;
    if ((flags & 2) != 0 && (flags & 0x20) == 0) {
        if ((flags & 4) == 0) {
            RtQuatConvertFromMatrix(&quaternion, (const RwMatrix*)(material + 0x10));
        } else {
            quaternion.imag.x = 0.707107f;
            quaternion.imag.y = 0.0f;
            quaternion.imag.z = 0.0f;
            quaternion.real = quaternion.imag.x;
        }
        {
            f32 dot;
            f32 angle;
            f32 amount;
            f32 limit;
            dot = owner->rotation.imag.x * quaternion.imag.x
                + owner->rotation.imag.y * quaternion.imag.y
                + owner->rotation.imag.z * quaternion.imag.z;
            dot += owner->rotation.real * quaternion.real;
            if (dot < 0.0f) {
                RtQuatNegateMacro(&result, &quaternion);
                dot = owner->rotation.real * result.real
                    + (owner->rotation.imag.x * result.imag.x
                    + owner->rotation.imag.y * result.imag.y
                    + owner->rotation.imag.z * result.imag.z);
            }
            angle = 2.0f * func_0044b920(dot);
            limit = owner->minBlend;
            if (limit < 1.0f) {
                f32 maximum;
                maximum = owner->maxAngle;
                if (!(angle <= maximum)) {
                    amount = maximum / angle;
                    if (amount < limit) {
                        amount = limit;
                    }
                } else {
                    amount = limit;
                }
                func_003dcc70((f32*)&owner->rotation, (f32*)&quaternion,
                              &interpolation);
                RtQuatSlerpMacro(&result, &owner->rotation, &quaternion,
                                amount, &interpolation);
                *&owner->rotation = result;
            } else {
                owner->rotation = quaternion;
            }
        }
        RtQuatTransformVectors(&direction, (const RwV3d*)(D_00713138 + 0x10), 1,
                      &owner->rotation);
    } else {
        u8* source = material + 0x10;
        RtQuatConvertFromMatrix(&owner->rotation, (const RwMatrix*)source);
        direction = ((RwMatrix*)source)->at;
    }

    }

    if (color.alpha == 0) {
        if ((owner->animFlags & 0x10) != 0) {
            mdlInstallHierarchyScaleHook(owner->hierarchy,
                          (u8*)&owner->animFlags);
        } else if ((owner->flags140 & 0x81E0) != 0) {
            mdlUpdateHierarchyPose(owner->hierarchy,
                          (u8*)&owner->animFlags, (u8*)&owner->flags140, 0);
        } else {
            func_00397c40(owner->hierarchy);
        }
        if ((owner->flagsD8 & 0x80000) != 0) {
            mdlUpdateBlendTrack(owner->state234, (u8*)&owner->animFlags);
        }
        {
        u32 needsReset;
        u32 hasItem;
        u32 hasIndex;
        u8* animation;
        u8* slot;
        u8** child;
        s32* frameID;
        j = 0;
        while ((s64)j < 5) {
            slot = (u8*)owner + j * 0xC;
            if ((((Model *)slot)->attachedWpns[0].flags & 1) != 0 &&
                *(child = (u8**)(slot + 0x290)) != 0 &&
                mdlPrepareSlotModel((u8*)owner, j) != 0) {
                model = (MdlDrawState*)*child;
                if ((model->flagsD8 & 2) == 0) {
                    if (*(frameID = (s32*)(slot + 0x294)) != -1) {
                        {
                        void* matrix = mdlGetMatrix(model);
                        s64 index = *frameID;
                        mdlCopyIndexedMatrix(owner, index, matrix);
                    }
                    } else {
                        model->matrix = owner->matrix;
                    }
                    needsReset = 0;
                    hasItem = 0;
                    hasIndex = 0;
                    animation = model->animations;
                    if (animation != 0 &&
                        ((MdlDispatchAnimTable *)animation)->count > model->animIndex) {
                        hasIndex = 1;
                    }
                    if (hasIndex != 0 &&
                        ((MdlDispatchAnimEntry *)((u8*)*(void**)animation + model->animIndex * 0x50))->animation != 0) {
                        hasItem = 1;
                    }
                    if (hasItem != 0 &&
                        ((MdlDispatchAnimEntry *)((u8*)*(void**)animation + model->animIndex * 0x50))->animation
                            != (void*)D_00922BC0_abs) {
                        needsReset = 1;
                    }
                    if (needsReset != 0) {
                        func_00397c40(model->hierarchy);
                    }
                    if ((model->flagsD8 & 0x80000) != 0) {
                        mdlUpdateBlendTrack(model->state234, (u8*)&model->animFlags);
                    }
                }
            }
            j++;
        }
        }
        return;
    }

    if (!(direction.y < 0.0f)) {
        f32 unit;
        unit = 0.707107f;
        owner->rotation.imag.x = unit;
        owner->rotation.imag.y = 0.0f;
        owner->rotation.imag.z = 0.0f;
        owner->rotation.real = unit;
        RtQuatTransformVectors(&direction, (const RwV3d*)(D_00713138 + 0x10), 1,
                      &owner->rotation);
    }
    if (owner->limit !=
        owner->targetLimit) {
        owner->limit =
            owner->limit
            + owner->limitRate
              * (owner->targetLimit
                 - owner->limit);
    }
    {
        f32 limit;
        limit = owner->limit;
        if (fabsf(direction.y) < limit) {
            if (!(direction.y < 0.0f)) {
                direction.y = limit;
            } else {
                direction.y = -limit;
            }
        }
    }

    identity.right.x = identity.up.y = identity.at.z = 1.0f;
    identity.right.y = identity.right.z = identity.up.x = 0.0f;
    identity.up.z = identity.at.x = identity.at.y = 0.0f;
    identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
    identity.flags |= 0x20003;
    identity.up.x = -direction.x / direction.y;
    identity.up.y = 0.01f;
    identity.up.z = -direction.z / direction.y;

    {
    void* frame = *(void* *)&((RwObject *)(u8*)owner->clump)->parent;
    RwMatrixMultiply(&matrix0, &owner->identityMatrix, owner);
    RwMatrixMultiply(&matrix1, &matrix0, &identity);
    func_003e9cb0(frame, &matrix1, 0);
    }
    if ((owner->flags140 & 0x4000) != 0) {
        mdlUpdateHierarchyPose(owner->hierarchy,
                      (u8*)&owner->animFlags, (u8*)&owner->flags140,
                      &identity);
    } else {
        func_00397c40(owner->hierarchy);
    }
    renderStateSet = (MdlRenderDevice*)D_00887300_abs;
    renderStateSet->set(6, 1);
    renderStateSet->set(8, 0);
    D_00887304[0](0xE, &renderState);
    renderStateSet->set(0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    if ((owner->flagsD8 & 0x80000) != 0) {
        mdlUpdateBlendTrack(owner->state234, (u8*)&owner->animFlags);
    }
    mdlClumpApplyMatColorScale(owner->clump, (u32*)&color,
                        (u16)(s64)((owner->flags & 8) != 0));
    {
    u8* effect;
    effect = (u8*)owner->e0;
    if (effect == 0) {
        RpSkyRenderStateSet(3, 0x7C01B);
    } else if ((*(s32 *)&((KClumpDrawBuckets *)effect)->heads[4] != 0 || *(s32 *)&((KClumpDrawBuckets *)effect)->heads[7] != 0)
               && ((owner->flags & 0x80) == 0)) {
        RpSkyRenderStateSet(3, 0x7F06B);
    } else {
        RpSkyRenderStateSet(3, 0x7D7FB);
    }
    }
    mdlDrawVisibleAtomics(owner->clump);
    mdlUpdateModelMatrix((Model*)owner);
    if ((owner->animFlags & 0x10) != 0) {
        mdlInstallHierarchyScaleHook(owner->hierarchy,
                      (u8*)&owner->animFlags);
    } else if ((owner->flags140 & 0x81E0) != 0) {
        mdlUpdateHierarchyPose(owner->hierarchy,
                      (u8*)&owner->animFlags, (u8*)&owner->flags140, 0);
    } else {
        func_00397c40(owner->hierarchy);
    }
    {
    u8* effect;
    effect = owner->effect2CC;
    if (effect != 0) {
        mdlEffectListSetUniformScale((s32*)effect, (f32*)(&owner->scale));
        mdlEffectListBuildTransforms((u8**)owner->effect2CC, (u8*)owner);
    }
    }
    {
    u8* model;
    u8* effect;
    MdlCloneAttachmentTable *attachments;
    layer = 0;
    while ((s64)layer < 2) {
        model = *(u8* *)&((Model *)((u8*)owner + layer * 0xA4))->layers[0].attachments;
        if (model != 0) {
            attachments = (MdlCloneAttachmentTable *)model;
            effect = attachments->primaryDraw;
            if (effect != 0 && ((MdlCloneAttachmentTable *)model)->delay == 0) {
                mdlEffectListSetUniformScale((s32*)effect, (f32*)(model + 8));
                mdlEffectListBuildTransforms(*(u8 ***)&((MdlCloneAttachmentTable *)model)->primaryDraw, (u8*)owner);
            }
            effect = *(u8 **)&((MdlCloneAttachmentTable *)model)->secondaryDraw;
            if (effect != 0 && ((MdlCloneAttachmentTable *)model)->delay == 0) {
                mdlRefreshSecondaryEffect(effect, owner);
            }
            if (attachments->delay > 0) {
                ((MdlCloneAttachmentTable *)model)->delay -= 1;
            }
        }
        layer++;
    }
    }
    {
    struct { u16 index; u8* slot; MdlDrawState* model; } attached;
    u8** child;
    s32* frameID;
    u32 hasItem;
    u32 hasIndex;
    u8* animation;
    u8* effect;
    attached.index = 0;
    while ((s64)attached.index < 5) {
        attached.slot = (u8*)((MdlWpnSlot*)owner + attached.index);
        if ((((Model *)attached.slot)->attachedWpns[0].flags & 1) != 0 &&
            *(child = (u8**)(attached.slot + 0x290)) != 0 &&
            mdlPrepareSlotModel((u8*)owner, attached.index) != 0) {
            attached.slot = (u8*)owner + attached.index * 0xC;
            attached.model = (MdlDrawState*)*child;
            if (*(frameID = (s32*)(attached.slot + 0x294)) != -1) {
                {
                        void* matrix = mdlGetMatrix(attached.model);
                        s64 index = *frameID;
                        mdlCopyIndexedMatrix(owner, index, matrix);
                    }
            } else {
                attached.model->matrix = owner->matrix;
            }
            if ((attached.model->flagsD8 & 2) == 0 &&
                owner->color.alpha != 0) {
                u8* source = attached.model->clump;
                u8* material = *(u8* *)&((RwObject *)source)->parent;
                u32 needsReset;
                RwMatrixMultiply(&matrix0, &attached.model->identityMatrix, attached.model);
                RwMatrixMultiply(&matrix1, &matrix0, &identity);
                func_003e9cb0(material, &matrix1, 0);
                needsReset = 0;
                hasItem = 0;
                hasIndex = 0;
                animation = attached.model->animations;
                if (animation != 0 &&
                    ((MdlDispatchAnimTable *)animation)->count > attached.model->animIndex) {
                    hasIndex = 1;
                }
                if (hasIndex != 0 &&
                    ((MdlDispatchAnimEntry *)((u8*)*(void**)animation + attached.model->animIndex * 0x50))->animation != 0) {
                    hasItem = 1;
                }
                if (hasItem != 0 &&
                    ((MdlDispatchAnimEntry *)((u8*)*(void**)animation + attached.model->animIndex * 0x50))->animation
                        != (void*)D_00922BC0_abs) {
                    needsReset = 1;
                }
                if (needsReset != 0) {
                    func_00397c40(attached.model->hierarchy);
                }
                if ((attached.model->flagsD8 & 0x80000) != 0) {
                    mdlUpdateBlendTrack(attached.model->state234, (u8*)&attached.model->animFlags);
                }
                mdlClumpApplyMatColorScale(source, (u32*)&color,
                                    (u16)(s64)((attached.model->flags & 8) != 0));
                effect = (u8*)owner->e0;
                if (effect == 0) {
                    RpSkyRenderStateSet(3, 0x7C01B);
                } else if (*(s32 *)&((KClumpDrawBuckets *)effect)->heads[4] != 0 ||
                           *(s32 *)&((KClumpDrawBuckets *)effect)->heads[7] != 0) {
                    RpSkyRenderStateSet(3, 0x7F08B);
                } else {
                    RpSkyRenderStateSet(3, 0x7D7FB);
                }
                mdlDrawVisibleAtomics(source);
                mdlUpdateModelMatrix((Model*)attached.model);
                if (needsReset != 0) {
                    func_00397c40(attached.model->hierarchy);
                }
                effect = attached.model->effect2CC;
                if (effect != 0) {
                    mdlEffectListSetUniformScale((s32*)effect, (f32*)&attached.model->scale);
                    mdlEffectListBuildTransforms((u8**)attached.model->effect2CC, (u8*)attached.model);
                }
                {
                struct { u16 index; u8* table; } layerCursor;
                MdlCloneAttachmentTable *attachments;
                layerCursor.index = 0;
                while ((s64)layerCursor.index < 2) {
                    layerCursor.table = *(u8* *)&((Model *)((u8*)attached.model + layerCursor.index * 0xA4))->layers[0].attachments;
                    if (layerCursor.table != 0) {
                        attachments = (MdlCloneAttachmentTable *)layerCursor.table;
                        source = attachments->primaryDraw;
                        if (source != 0 && ((MdlCloneAttachmentTable *)layerCursor.table)->delay == 0) {
                            mdlEffectListSetUniformScale((s32*)source, (f32*)(layerCursor.table + 8));
                            mdlEffectListBuildTransforms(*(u8** *)&((MdlCloneAttachmentTable *)layerCursor.table)->primaryDraw, (u8*)attached.model);
                        }
                        source = *(u8* *)&((MdlCloneAttachmentTable *)layerCursor.table)->secondaryDraw;
                        if (source != 0 && ((MdlCloneAttachmentTable *)layerCursor.table)->delay == 0) {
                            mdlRefreshSecondaryEffect(source, attached.model);
                        }
                        if (attachments->delay > 0) {
                            ((MdlCloneAttachmentTable *)layerCursor.table)->delay -= 1;
                        }
                    }
                    layerCursor.index++;
                }
                }
            }
        }
        attached.index++;
    }
    }
    renderStateSet = (MdlRenderDevice*)D_00887300_abs;
    renderStateSet->set(0xE, renderState);
    RpSkyRenderStateSet(3, 0x717FB);
    renderStateSet->set(8, 1);
}

#undef RtQuatNegateMacro
#undef RtQuatSlerpMacro
#undef RwV3dIncrementScaledMacro
#undef RwV3dScaleMacro
#undef RwSinMinusPiToPiMacro
#undef _RW_S1
#undef _RW_S2
#undef _RW_S3
#undef _RW_S4
#undef _RW_S5
#undef _RW_S6
#undef MACRO_START
#undef MACRO_STOP

extern void RpSkyRenderStateSet(s32 a, s32 b);
extern void (*D_00887304[])(s32, void*);
extern void mdlDrawVisibleAtomics(void* clump);
extern void* func_003bfae0_1(void* a);
extern void (*D_00887300_abs[])(s32, s32);
/* P4 port probe: opt_propagation off prevents mwcc folding the D_00887300_abs
   array address into per-call lui/lw (same measured fix as mdlApplyDrawState). */
#pragma opt_propagation off

/* measured: the D3/7000F branch condition is (f&0x200)!=0 && (f&0x400)==0
   (the 0x400-beqz goes to the D3 part, not the 7000F). Residual: mwcc b210
   materializes object+0xD8 into $s0 (frame 0x40 vs 0x50, retail keeps the
   D_00887300 base in $s0) and mirrors the block layout (D3 inline + 7000F
   out-of-line vs retail's 7000F inline + D3 out-of-line). Tried: u8* params
   (94), condition flips. Address-CSE + if-placement floor. */
/* Sky draw pass: sets the sky render states from the model's flags, runs the sky state table, then draws its atomics or walks its effect list. */
// FUN_00476C70
void mdlDrawSkyPass(Model* model)
{
    void (**renderStates)(s32, s32);
    void* entry;
    void* camera;
    void* atomic;
    s32 previousRenderState;

    RpSkyRenderStateSet(2, 0x64);
    if (!(model->flags & 0x200) || (model->flags & 0x400)) {
        RpSkyRenderStateSet(3, 0x7000F);
    } else if (((Model *)(u8*)model)->color.alpha > 0xC8) {
        RpSkyRenderStateSet(3, 0x704FD);
    } else {
        RpSkyRenderStateSet(3, 0x7008D);
    }
    renderStates = D_00887300_abs;
    renderStates[0](6, 1);
    D_00887304[0](0xE, &previousRenderState);
    renderStates[0](0xE, 0);
    if (model->drawBuckets == NULL || (model->flags & 0x200)) {
        mdlDrawVisibleAtomics(model->clump);
    } else {
        camera = D_008872E0[0];
        entry = *(void* *)&((KClumpDrawBuckets *)(u8*)model->drawBuckets)->heads[2];
        while (entry != NULL) {
            if (RwCameraFrustumTestSphere(camera, func_003bfae0_1(*(void* *)&((KClumpDrawEntry *)(u8*)entry)->atomic)) != 0) {
                atomic = *(void* *)&((KClumpDrawEntry *)(u8*)entry)->atomic;
                ((void (*)(void*))*(void* *)&((struct RpAtomic *)(u8*)atomic)->renderCallBack)(atomic);
            }
            entry = *(void* *)&((KClumpDrawEntry *)(u8*)entry)->next;
        }
    }
    renderStates[0](0xE, previousRenderState);
}
#pragma opt_propagation on

/* Atomic callback: ensures the colour user-data entry on every material of the atomic's geometry. */
// FUN_00476E10
void* mdlEnsureAtomicMatColors(void* atomic, void* data)
{
    u8* geometry;
    u32 materialCount;
    u32 materialIndex;

    geometry = *(u8 **)&((struct RpAtomic *)atomic)->geometry;
    materialCount = ((MdlGeometry *)geometry)->count;
    for (materialIndex = 0; materialIndex < materialCount; materialIndex = materialIndex + 1) {
        K_Clump_EnsureMatColorUsrData((u8*)(*(u32* *)&((MdlGeometry *)geometry)->materials)[materialIndex]);
    }

    return atomic;
}




typedef struct MdlMaterialColorReal { f32 red, green, blue, alpha; } MdlMaterialColorReal;



/* RwRGBA -> RwRGBAReal normalisation.  The 1/255 scale is a float literal, so
 * MWCC places it in .sdata and reloads it per channel (gp-relative), while the
 * shared 0.0f accumulator seed of the quantiser stays CSE'd across channels. */
#pragma push
#pragma always_inline on

static inline void mdlColorToReal(MdlMaterialColorReal* out, const RwRGBA* color)
{
    out->red = (f32)(u32)color->red * (1.0f / 255.0f);
    out->green = (f32)(u32)color->green * (1.0f / 255.0f);
    out->blue = (f32)(u32)color->blue * (1.0f / 255.0f);
    out->alpha = (f32)(u32)color->alpha * (1.0f / 255.0f);
}

static inline void mdlColorUnpack(RwRGBA* out, u32 packed)
{
    out->blue = packed;
    out->green = packed >> 8;
    out->red = packed >> 16;
    out->alpha = packed >> 24;
}

static inline void mdlColorQuantize(RwRGBA* out, const MdlMaterialColorReal* color)
{
    f32 maximum = 255.0f;
    f32 bias = 0.5f;
    out->red = (s32)(bias + maximum * color->red);
    out->green = (s32)(bias + maximum * color->green);
    out->blue = (s32)(bias + maximum * color->blue);
    out->alpha = (s32)(bias + maximum * color->alpha);
}

/* Multiplies each material's per3modelMatColor by the tint; the flag bit in data+4 replaces alpha instead of scaling it. */
// FUN_00476E90
void* mdlMatColorScaleCallback(void* atomic, void* context)
{
    MdlGeometry* geometry;
    u32 count;
    MdlMaterialColorReal scale;
    u32 index;
    geometry = *(MdlGeometry* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    geometry->flags |= 0x40;
    count = geometry->count;
    mdlColorToReal(&scale, *(const RwRGBA**)context);
    for (index = 0; index < count; ++index) {
        MdlMaterial* material = geometry->materials[index];
        RwRGBA color;
        MdlMaterialColorReal real;
        mdlColorUnpack(&color, (u32)K_Clump_MatUsrDataGetInt((const RpMaterial*)material, (const char*)D_00713160));
        mdlColorToReal(&real, &color);
        real.red *= scale.red;
        real.green *= scale.green;
        real.blue *= scale.blue;
        if ((((MdlColorScale *)context)->flags & 1) == 0)
            real.alpha *= scale.alpha;
        else
            real.alpha = scale.alpha;
        mdlColorQuantize(&color, &real);
        material->color = color;
    }
    return atomic;
}
#pragma pop
/* Applies the tint to every atomic in the clump via mdlMatColorScaleCallback. */
// FUN_00477260
void mdlClumpApplyMatColorScale(void* clump, u32* color, u16 flags)
{
    struct {
        u32* ptr;
        u16 value;
    } context;

    context.ptr = color;
    context.value = flags;
    RpClumpForAllAtomics(clump, mdlMatColorScaleCallback, &context);
    return;
}



/* Clump predicate: clears *data and returns NULL when any material has a non-zero per3modelMatColor high byte; otherwise returns the clump. */
// FUN_004772A0
u32 mdlMatColorUncoloredCallback(void* atomic, u32* uncolored)
{
    int geometry;
    u32 materialCount;
    u32 color;
    u32 materialIndex;
    u32* entries;

    geometry = *(int *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    materialCount = ((MdlGeometry *)geometry)->count;
    materialIndex = 0;
    while (materialIndex < materialCount) {
        entries = *(u32* *)&((MdlGeometry *)geometry)->materials;
        color = K_Clump_MatUsrDataGetInt((const RpMaterial*)entries[materialIndex], "per3modelMatColor");
        if (color >> 0x18 != 0) {
            *uncolored = 0;
            return 0;
        }
        materialIndex = materialIndex + 1;
    }
    return (u32)atomic;
}



/* Stores *uncolored as the env-map value on each MatFX material of the atomic. */
// FUN_00477350
void* mdlMatFXSetEnvMapValueCallback(void* atomic, void* valueData)
{
    void* geometry = *(void* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    u32 count = ((MdlGeometry *)geometry)->count;
    u32 materialIndex = 0;
    while (materialIndex < count) {
        void* material = (void*)(u32)((MdlGeometry *)geometry)->materials[materialIndex];
        if ((RpMatFXMaterialGetEffects(material) & 2) != 0) {
            func_0039a260(material, (void*)*(u32*)valueData);
        }
        materialIndex++;
    }
    return atomic;
}

/* Clump wrapper that stores the env-map value on each MatFX material. */
// FUN_00477400
void mdlClumpSetEnvMapValue(void* clump, int envMapValue)
{
    RpClumpForAllAtomics(clump, mdlMatFXSetEnvMapValueCallback, &envMapValue);
}

/* Enables the env-map state on each MatFX material of the atomic. */
// FUN_00477430
void* mdlMatFXSetEnvMapStateCallback(void* atomic, void* context)
{
    void* geometry = *(void* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    u32 count = ((MdlGeometry *)geometry)->count;
    u32 materialIndex = 0;
    while (materialIndex < count) {
        void* material = (void*)(u32)((MdlGeometry *)geometry)->materials[materialIndex];
        if ((RpMatFXMaterialGetEffects(material) & 2) != 0) {
            func_0039ab20(material, 2, 3, 0x73001);
        }
        materialIndex++;
    }
    return atomic;
}

/* Clump wrapper that applies the env-map state to every atomic. */
// FUN_004774E0
void mdlClumpSetEnvMapState(void* clump)
{
    RpClumpForAllAtomics(clump, mdlMatFXSetEnvMapStateCallback, 0);
}

/* Atomic callback: sets the +0xC vector of every material entry from the material user-data floats, or from the fallback value when any of the three keys is missing. */
// FUN_00477510
void* mdlSetAtomicMaterialVector(void* atomic, void* context)
{
    void* geometry;
    u32 count;
    u32 materialIndex;
    void* material;
    f32 vector[3];

    geometry = *(void* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    count = ((MdlGeometry *)geometry)->count;
    for (materialIndex = 0; materialIndex < count; materialIndex++) {
        material = (void*)(u32)((MdlGeometry *)geometry)->materials[materialIndex];
        if (K_Clump_MatUsrDataHasData(material, D_00713180) != 0 &&
            K_Clump_MatUsrDataHasData(material, D_007131A0) != 0 &&
            K_Clump_MatUsrDataHasData(material, D_007131C0) != 0) {
            vector[0] = K_Clump_MatUsrDataGetFloat((const RpMaterial*)material, (const char*)D_00713180);
            vector[2] = K_Clump_MatUsrDataGetFloat((const RpMaterial*)material, (const char*)D_007131A0);
            vector[1] = K_Clump_MatUsrDataGetFloat((const RpMaterial*)material, (const char*)D_007131C0);
        } else {
            vector[0] = fGpffff809c;
            vector[2] = fGpffff809c;
            vector[1] = fGpffff809c;
        }
        ((MdlMaterial *)material)->surfaceProperties = *(RwV3d*)vector;
    }
    return atomic;
}

/* Atomic callback: copies the RwV3d at data into the +0xC slot of every entry in the atomic's entry table. */
// FUN_00477660
void* mdlSetAtomicEntryVector(void* atomic, void* data)
{
    RwV3d* vector = data;
    void* geometry = *(void* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    u32 count = ((MdlGeometry *)geometry)->count;
    u32 materialIndex = 0;
    while (materialIndex < count) {
        void* material = (void*)(u32)((MdlGeometry *)geometry)->materials[materialIndex];
        ((MdlMaterial *)material)->surfaceProperties = *vector;
        materialIndex++;
    }
    return atomic;
}

/* measured: complete aggregate-buffer reconstruction matches every real
   instruction (264B object versus 272B window); the trailing 8B are two
   alignment nops after jr/nop. The previous six residual rows were the
   filter-result/item-pointer and loop-counter $s-register allocation swaps;
   declaration order now reproduces retail exactly (nd 0). */
/* RpClumpForAllAtomics callback: for each frame entry whose user-data name matches the string at +4 of input, sets its colour from the material user-data int and alpha from input+0. */
/* measured: keep the name-pointer load before prefix comparison
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_004776C0
void *mdlSetFrameColorIfNamed(void *atomic, void *context)
{
    extern s32 strlen(s32 packedColor);
    extern s32 strncmp(s32 a, s32 b, s32 c);
    extern u32 K_Clump_MatUsrDataGetInt(void* material, void* name);
    extern void K_ClumpMatColorStore(void* material, void* color);
    u8 color[4];
    u8 *namedColor;
    u32 packedColor;
    u8 *material;
    u32 materialIndex;
    u32 materialCount;
    s32 nameLength;
    u8 *geometry;
    namedColor = (u8 *)context;
    geometry = *(u8 **)&((struct RpAtomic *)atomic)->geometry;
    materialCount = ((MdlGeometry *)geometry)->count;
    nameLength = strlen((s32)((MdlNamedColor *)namedColor)->name);
    materialIndex = 0;
    while (materialIndex < materialCount) {
        material = (u8*)(u32)((MdlGeometry *)geometry)->materials[materialIndex];
        if (strncmp(*(s32 *)&((MdlNamedColor *)namedColor)->name, (s32)mdlGetFrameNameUserData(material), nameLength) == 0) {
            packedColor = K_Clump_MatUsrDataGetInt(material, D_00713160);
            color[2] = (u8)packedColor;
            color[1] = (u8)(packedColor >> 8);
            color[0] = (u8)(packedColor >> 16);
            color[3] = ((MdlNamedColor *)namedColor)->alpha;
            K_ClumpMatColorStore(material, color);
        }
        materialIndex += 1;
    }
    return atomic;
}
/* Sets the colour and alpha of every frame named by the string in data (the name pointer) on the model's clump. */
// FUN_004777D0
void mdlSetFrameColorByName(void* model, int name, u8 alpha)
{
    struct {
        u8 b;
        int i;
    } context;
    context.b = alpha;
    context.i = name;
    RpClumpForAllAtomics(((Model *)model)->clump, mdlSetFrameColorIfNamed, &context);
}

/* measured: retail hoists the 1.0f const (lui/mtc1 -> $f3) to function top and
   allocates inv184=$f2, inv188=$f1, product=$f5; mwcc b210 materializes the
   const at the use site into $f1 and lands the product in $f2; with
   #pragma opt_loop_invariants on the const hoists but the whole allocation
   permutes (counter $v1<->$a2, const $f4, nd 55). Integer t-regs are permuted
   in both loops regardless (p8 $t0 vs $t1, mask regs). Tried: plain C (nd 45),
   one=1.0f local (nd 45), pragma on (nd 55). Register-coloring floor. */
 
// Builds two 0xA4-byte records at owner for each nonzero counter at input+0x198. The records take their scale terms from input (+0x184 and +0x188 are inverted) and their count from the counter, and set flag 0x10 in +0xEC.
/* measured: keep the leading node-count test before scale-factor setup
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00477810
/* measured probe: hoist invariant constant for retail prologue. */
#pragma opt_loop_invariants on
void mdlBuildScaledSlotRecords(void *model, void *properties)
{
    s32 propertyIndex;
    s32 layerIndex;
    s32 propertySlot;
    s32 layerSlot;
    f32 one;
    f32 scaledYZ;
    f32 scaleValue;
    f32 scaledX;
    f32 inverseX;
    f32 scaleFactor;
    u8 *propertyCursor;
    u8 *layerCursor;

    one = 1.0f;
    propertyIndex = 0;
    while ((propertyIndex & 0xFFFF) < 0x10) {
        propertySlot = (u16)propertyIndex;
        propertyCursor = (u8 *)properties + propertySlot * 2;
        if (((MdlScaleProperties *)properties)->nodeCounts[propertySlot] > 0) {
            if ((propertyIndex & 0xFFFF) == 0) {
                scaleFactor = ((MdlScaleProperties *)properties)->scaleFactor;
                scaleValue = ((MdlScaleProperties *)properties)->scaleDivisorX;
                inverseX = one / scaleValue;
                scaleValue = ((MdlScaleProperties *)properties)->scaleDivisorYZ;
                scaledX = one / scaleValue;
                scaleValue = ((MdlScaleProperties *)properties)->aspectFactor;
                scaleValue = mdlMultiplyOrdered(scaleFactor, scaleValue);
                scaleValue = mdlMultiplyOrdered(inverseX, scaleValue);
                scaledYZ = mdlMultiplyOrdered(scaledX, scaleValue);
                scaledX = mdlMultiplyOrdered(scaleFactor, inverseX);
            }
            layerIndex = 0;
            while ((layerIndex & 0xFFFF) < 2) {
                layerSlot = (u16)layerIndex;
                layerCursor = (u8 *)model + layerSlot * 0xA4;
                ((Model *)layerCursor)->layers[0].scale.x = scaledX;
                ((Model *)layerCursor)->layers[0].scale.y = scaledYZ;
                ((Model *)layerCursor)->layers[0].scale.z = scaledYZ;
                ((Model *)layerCursor)->layers[0].modelScale = ((MdlScaleProperties *)properties)->scaleFactor;
                ((Model *)layerCursor)->layers[0].aspect = ((MdlScaleProperties *)properties)->aspectFactor;
                ((Model *)layerCursor)->layers[0].scaleNode = ((MdlScaleProperties *)propertyCursor)->nodeCounts[0];
                ((Model *)layerCursor)->layers[0].flags |= 0x10;
                layerIndex = (layerIndex + 1) & 0xFFFF;
            }
        }
        propertyIndex = (propertyIndex + 1) & 0xFFFF;
    }
}
/* measured probe: close invariant pragma. */
#pragma opt_loop_invariants off

/* Removing this loses 0x00477900 (MATCH nd0 -> MISMATCH nd51) - measured W161 (ported from P3FES donor; re-probed in P4: nd0 -> nd51). */
#pragma opt_loop_invariants on

/* Doubles each morph target's bounding-sphere radius and sets interpolator flag 2.
 * The volatile sphere snapshot is an existing measured matching requirement. */
// FUN_00477900
void* mdlDoubleAtomicEntryW(void* atomic, void* context)
{
    u8* geometry;
    u32 targetCount;
    int byteOffset;
    u8* targets;
    u8* target;
    u8* atomicData;
    u32 targetIndex;
    f32 radiusScale;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 radius;
    volatile /* Removing this qualifier loses mdlDoubleAtomicEntryW (MATCH nd0 -> MISMATCH nd105, size 172 -> 132) - measured W170 (ported from P3FES donor; re-probed in P4: nd0 -> nd105, size 132). */ f32 sphereSnapshot[4];

    atomicData = atomic;
    geometry = *(u8 **)&((struct RpAtomic *)atomicData)->geometry;
    if (geometry == 0)
        goto done;

    targetCount = *(u32 *)&((MdlGeometry *)geometry)->morphTargetCount;
    targetIndex = 0;
    radiusScale = 2.0f;
    goto check;

loop:
    byteOffset = targetIndex * 8;
    byteOffset = byteOffset - targetIndex;
    byteOffset = byteOffset * 4;
    targets = ((MdlGeometry *)geometry)->morphTargets;
    target = targets + byteOffset;
    sphereSnapshot[0] = ((MdlMorphTarget *)target)->center.x;
    sphereSnapshot[1] = ((MdlMorphTarget *)target)->center.y;
    sphereSnapshot[2] = ((MdlMorphTarget *)target)->center.z;
    sphereSnapshot[3] = radiusScale * ((MdlMorphTarget *)target)->radius;
    centerX = sphereSnapshot[0];
    centerY = sphereSnapshot[1];
    centerZ = sphereSnapshot[2];
    radius = sphereSnapshot[3];
    ((MdlMorphTarget *)target)->center.x = centerX;
    ((MdlMorphTarget *)target)->center.y = centerY;
    ((MdlMorphTarget *)target)->center.z = centerZ;
    ((MdlMorphTarget *)target)->radius = radius;
    targetIndex = targetIndex + 1;
check:
    if (targetIndex < targetCount)
        goto loop;

done:
    ((struct RpAtomic *)atomicData)->interpolatorFlags = ((struct RpAtomic *)atomicData)->interpolatorFlags | 2;
    return atomic;
}
#pragma opt_loop_invariants off




/* measured: volatile RwRGBA* color forces the four lbu color loads in source
   order (removing it rotates/reorders them, nd 9). */
/* Allocates a model object of 0x320 bytes, stamps its type at +0xD4 and id at +0xD6, sets default colour, scale and slot records, and links it into the head of its type bucket in D_00922BE0. */
// FUN_004779B0
void* mdlAllocModelObject(u32 type, u16 id)
{
    u8* model;
    u32 index;
    void** head;
    u8* prev;
    volatile RwRGBA* color;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;

    chkmemAllocSiteTag(D_00713138, 0x108A);
    model = ((void* (*)(int, int))DAT_008873e8[0])(0x320, 0x40000);
    memset(model, 0, 0x320);
    *(s32 *)&((Model *)model)->flags = 0x10118;
    ((Model *)model)->color.red = 0xFF;
    ((Model *)model)->color.green = 0xFF;
    ((Model *)model)->color.blue = 0xFF;
    ((Model *)model)->color.alpha = 0xFF;
    color = (RwRGBA*)(model + 0xD0);
    red = color->red;
    green = color->green;
    blue = color->blue;
    alpha = color->alpha;
    ((Model *)model)->effectColor.red = red;
    ((Model *)model)->effectColor.green = green;
    ((Model *)model)->effectColor.blue = blue;
    ((Model *)model)->effectColor.alpha = alpha;
    ((Model *)model)->type = type;
    ((Model *)model)->id = id;
    ((Model *)model)->skyAlpha = 0x44;
    ((Model *)model)->skyTest = 0x717FB;
    *(s32 *)&((Model *)model)->owner = iGpffffbb28;
    *(s32 *)&((Model *)model)->mat.at.z = 0x3F800000;
    *(s32 *)&((Model *)model)->mat.up.y = 0x3F800000;
    *(s32 *)&((Model *)model)->mat.right.x = 0x3F800000;
    *(s32 *)&((Model *)model)->mat.up.x = 0;
    *(s32 *)&((Model *)model)->mat.right.z = 0;
    *(s32 *)&((Model *)model)->mat.right.y = 0;
    *(s32 *)&((Model *)model)->mat.at.y = 0;
    *(s32 *)&((Model *)model)->mat.at.x = 0;
    *(s32 *)&((Model *)model)->mat.up.z = 0;
    *(s32 *)&((Model *)model)->mat.pos.z = 0;
    *(s32 *)&((Model *)model)->mat.pos.y = 0;
    *(s32 *)&((Model *)model)->mat.pos.x = 0;
    *(s32 *)&((Model *)model)->mat.flags |= 0x20003;
    *(s32 *)&((Model *)model)->identityMat.at.z = 0x3F800000;
    *(s32 *)&((Model *)model)->identityMat.up.y = 0x3F800000;
    *(s32 *)&((Model *)model)->identityMat.right.x = 0x3F800000;
    *(s32 *)&((Model *)model)->identityMat.up.x = 0;
    *(s32 *)&((Model *)model)->identityMat.right.z = 0;
    *(s32 *)&((Model *)model)->identityMat.right.y = 0;
    *(s32 *)&((Model *)model)->identityMat.at.y = 0;
    *(s32 *)&((Model *)model)->identityMat.at.x = 0;
    *(s32 *)&((Model *)model)->identityMat.up.z = 0;
    *(s32 *)&((Model *)model)->identityMat.pos.z = 0;
    *(s32 *)&((Model *)model)->identityMat.pos.y = 0;
    *(s32 *)&((Model *)model)->identityMat.pos.x = 0;
    *(s32 *)&((Model *)model)->identityMat.flags |= 0x20003;
    *(s32 *)&((Model *)model)->scale.x = 0x3F800000;
    *(s32 *)&((Model *)model)->scale.y = 0x3F800000;
    *(s32 *)&((Model *)model)->scale.z = 0x3F800000;
    for (index = 0; index < 2; index++) {
        mdlInitSlotRecord(model + index * 0xA4 + 0xEC);
    }
    *(s32 *)&((Model *)model)->materialAnimation = 0;
    *(s8 *)&((Model *)model)->animControl.mode = 1;
    ((Model *)model)->animControl.index = -1;
    *(s32 *)&((Model *)model)->animControl.speed = 0x3F800000;
    memset(model + 0x258, 0, 8);
    *(s8 *)&((Model *)model)->unk25A = 1;
    *(s32 *)&((Model *)model)->unk25C = 0x3F800000;
    *(s8 *)&((Model *)model)->drawFlags = 0;
    *(s32 *)&((Model *)model)->limit = 0;
    *(s32 *)&((Model *)model)->targetLimit = 0;
    *(s32 *)&((Model *)model)->limitRate = 0;
    *(s8 *)&((Model *)model)->alpha = 0x70;
    *(s8 *)&((Model *)model)->targetAlpha = 0x70;
    *(s8 *)&((Model *)model)->alphaStep = 0;
    mdlInitObjectSlots(model + 0x2D0);
    for (index = 0; index < 5; index++) {
        mdlSetAttachedSlotValue(model, index & 0xFFFF, -1);
    }
    head = &D_00922BE0[(u16)type];
    prev = *head;
    ((Model *)model)->previous = 0;
    if (prev != 0) {
        ((Model *)prev)->previous = model;
        ((Model *)model)->next = prev;
    } else {
        ((Model *)model)->next = 0;
    }
    *head = model;
    return model;
}

/* Finds the model object with the given id in bucket type. When flags is nonzero, the object must also have one of those bits set in its flags at +0xD8. */
// FUN_00477C40
void* mdlFindModelObject(u32 type, u16 id, u32 flags)
{
    void* model = D_00922BE0[type & 0xFFFF];
    u32 targetId = id;
    u32 requiredFlags = flags & 0xFFFF;
    while (model != 0) {
        if (((Model *)model)->id == targetId &&
            (requiredFlags == 0 || (((Model *)model)->flags & requiredFlags) != 0)) {
            break;
        }
        model = ((Model *)model)->next;
    }
    return model;
}

extern void mdlFreeAuxBlock(void* model);
/* measured: MATCH (468B instructions plus 12 zero-tail bytes). The u16
   loop counter preserves retail masks; the canonical hierarchy constructor
   prototype preserves load-before-move argument materialization. */
/* Finishes a model once its resource is ready: named-frame animations, the base layer's hierarchy and animation, per-atomic entries, and effect-list handles. */
/* measured: keep the clump snapshots around atomic setup callbacks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00477CA0
void mdlSetupPreparedModel(u8* model)
{
    extern void mdlEffectListRefreshHandles(u32*);
    extern f32 fGpffff80cc;
    f32 values[3];
    u8 (*entries)[0xA4];
    s32* hierarchy;
    u16 layerIndex;
    u16 modelType;
    u32 hierarchyFlagsOrEffects;
    u8* layerBase;
    Model *modelObject = (Model *)model;

    entries = (u8 (*)[0xA4])model;
    RpClumpForAllAtomics(modelObject->clump, mdlDoubleAtomicEntryW, NULL);
    if (*(s32 *)&((Model *)model)->animControl.resource != 0) {
        mdlSetupNamedFrameAnims(model + 0x23C, ((Model *)model)->clump);
    }
    if (mdlLayerIsPresent(model, 0) != 0) {
        mdlAttachSlotHierarchy(model + 0xEC, ((Model *)model)->clump, 1);
        mdlDispatchAnimIfPresent(model, 0, 0, 0, 1);
        for (layerIndex = (u64)1; (layerIndex & 0xFFFF) < 2; layerIndex++) {
            layerBase = entries[layerIndex];
            if (*(s32 *)&((Model *)layerBase)->layers[0].resource != 0) {
                ((Model *)layerBase)->layers[0].flags = ((Model *)layerBase)->layers[0].flags | 2;
                hierarchy = *(s32* *)&((Model *)model)->layers[0].hierarchy;
                hierarchyFlagsOrEffects = *hierarchy;
                *(s32 *)&((Model *)layerBase)->layers[0].hierarchy = (s32)func_003971d0((u8*)hierarchy, 0, hierarchyFlagsOrEffects, -1);
            }
        }
    }
    ((Model *)model)->drawBuckets = sdkClumpCreateBuckets(modelObject->clump);
    RpClumpForAllAtomics(modelObject->clump, mdlEnsureAtomicMatColors, NULL);
    modelType = ((Model *)model)->type;
    switch (modelType) {
    case 1:
    case 2:
        values[0] = fGpffff80cc;
        values[2] = 1.0f;
        values[1] = fGpffff809c;
        RpClumpForAllAtomics(((Model *)model)->clump, mdlSetAtomicEntryVector, values);
        break;
    default:
        RpClumpForAllAtomics(((Model *)model)->clump, mdlSetAtomicMaterialVector, NULL);
        break;
    }
    hierarchyFlagsOrEffects = *(u32 *)&((Model *)model)->effects;
    if (hierarchyFlagsOrEffects != 0) {
        mdlEffectListRefreshHandles((u32*)hierarchyFlagsOrEffects);
    }
}
/* Creates a model object with mdlAllocModelObject, sets flag 0x4000 when option bit 0 is set, applies the data buffer value through mdlSetAuxResource, and runs the readiness step mdlPrepareModel. */
// FUN_00477E80
void* mdlCreateModelObjectFromData(u32 type, u16 id, void* resource, u32 flags)
{
    void* model = mdlAllocModelObject(type, id);
    if ((flags & 1) != 0) {
        ((Model *)model)->flags |= 0x4000;
    }
    mdlAllocAuxBlock(model);
    mdlSetAuxResource(model, resource);
    mdlPrepareModel(model);
    return model;
}

/* Like mdlCreateModelObjectFromData, but applies the (memory, size) pair through mdlSetAuxPair. Sets flag 0x4000 when flags bit 0 is set. */
// FUN_00477F10
void* mdlCreateModelObjectFromMemory(u32 type, u16 id, void* memory, u32 size, u32 flags)
{
    void* model = mdlAllocModelObject(type, id);
    if ((flags & 1) != 0) {
        ((Model *)model)->flags |= 0x4000;
    }
    mdlAllocAuxBlock(model);
    {
        struct {
            void* memory;
            u32 size;
        } data;
        data.memory = memory;
        data.size = size;
        mdlSetAuxPair(model, &data);
    }
    mdlPrepareModel(model);
    return model;
}

/* MATCHED this wave (nd 0, object 400B/window 400B): the former slot-coalescing
   / saved-register-rotation floor was disproved.  A return-tail `return mode;`
   shape and distinct pair structs reproduce the retail stack layout and
   return path; the previous nd-74/nd-9 layouts are retained here only as
   historical probe context. */
/* Creates a model object for type and id from resource mode, using H_Cdvd_GetArchiveEntry's pair (or an existing object's pair when mdlQueryModelType matches), and prepares it. */
// FUN_00477FB0
void* mdlCreateModelObjectFromResource(u32 type, u16 id, void* resourceOrModel, u32 flags)
{
    extern u8* H_Cdvd_GetArchiveEntry(u8*, s32, s32*);
    extern void mdlSeRequestLoad(void**, u32, u16, s32, u32);
    void* model;
    void* result;
    u32 dataBytes;
    u32 primaryMemory;
    u32 primaryBytes;
    u32 motionMemory;
    struct {
        u32 memory;
        u32 byteCount;
    } directPair;
    struct {
        u32 memory;
        u32 byteCount;
    } archivePair;

    if (mdlQueryModelType(type, id) == 0) {
        primaryMemory = *(u32 *)&((MdlResourceSource *)resourceOrModel)->memory;
        primaryBytes = ((MdlResourceSource *)resourceOrModel)->byteCount;
        dataBytes = primaryBytes;
        resourceOrModel = mdlAllocModelObject(type, id);
        if ((flags & 1) != 0) {
            ((Model *)resourceOrModel)->flags |= 0x4000;
        }
        mdlAllocAuxBlock(resourceOrModel);
        directPair.memory = primaryMemory;
        directPair.byteCount = primaryBytes;
        mdlSetAuxPair(resourceOrModel, &directPair);
        mdlPrepareModel(resourceOrModel);
        return resourceOrModel;
    }
    primaryMemory = (u32)H_Cdvd_GetArchiveEntry(resourceOrModel, 0, (s32*)&dataBytes);
    primaryBytes = dataBytes;
    model = mdlAllocModelObject(type, id);
    if ((flags & 1) != 0) {
        ((Model *)model)->flags |= 0x4000;
    }
    mdlAllocAuxBlock(model);
    archivePair.memory = primaryMemory;
    archivePair.byteCount = primaryBytes;
    mdlSetAuxPair(model, &archivePair);
    mdlPrepareModel(model);
    motionMemory = (u32)H_Cdvd_GetArchiveEntry(resourceOrModel, 1, (s32*)&dataBytes);
    mdlSeRequestLoad((void**)((u8*)model + 0x2D0), type, id, (s32)motionMemory, dataBytes);
    result = model;
done:
    return result;
}

/* Creates a fresh model: loads its path when no matching source exists,
 * otherwise requests clone preparation with flag 0x2000. */
// FUN_00478140
void* mdlFindOrCreateModelObject(u32 type, u16 id, u32 flags)
{
    void* node;
    void* obj;
    void* result;
    u8 path[0x100];
    u32 targetId;

    node = D_00922BE0[type & 0xFFFF];
    targetId = id & 0xFFFF;
    while (node != 0) {
        if (((Model *)node)->id == targetId) {
            break;
        }
        node = ((Model *)node)->next;
    }
    if (node == 0) {
        mdlBuildModelPath(type, id, (char*)path);
        obj = mdlAllocModelObject(type, id);
        if ((flags & 1) != 0) {
            ((Model *)obj)->flags |= 0x4000;
        }
        mdlAllocAuxBlock(obj);
        mdlSetAuxResource(obj, path);
        mdlPrepareModel(obj);
        if (mdlQueryModelType(type, id) != 0) {
            mdlSetAuxValue(obj, 1);
        }
        result = obj;
        goto done;
    } else {
        obj = mdlAllocModelObject(type, id);
        if ((flags & 1) != 0) {
            ((Model *)obj)->flags |= 0x4000;
        }
        ((Model *)obj)->flags |= 0x2000;
        mdlPrepareModel(obj);
        result = obj;
    }
done:
    return result;
}

/* Returns 1 once the model is ready (flag 0x1000 set). Until then it advances the load and clone steps and returns 0 while a step is still pending. */
/* measured: keep the initial readiness/clone flag snapshot
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_004782B0
s32 mdlPrepareModel(u8* model)
{
    s32 flags;
    void* source;
    s32 id;

    flags = MEMBER(s32, model, Model, flags);
    if ((flags & 0x1000) != 0) {
        return 1;
    }
    if ((flags & 0x2000) == 0) {
        if (mdlAdvanceAuxLoad() == 0) {
            return 0;
        }
        if (mdlSeUpdateRecord((void**)(model + 0x2D0)) == 0) {
            return 0;
        }
        mdlFreeAuxBlock(model);
        mdlSetupPreparedModel(model);
    } else {
        if (mdlSeUpdateRecord((void**)(model + 0x2D0)) == 0) {
            return 0;
        }
        id = ((Model *)model)->id;
        source = D_00922BE0[((Model *)model)->type];
        while (source != 0) {
            if (((Model *)source)->id == id &&
                (*(s32 *)&((Model *)source)->flags & 0x1000) != 0) {
                break;
            }
            source = ((Model *)source)->next;
        }
        if (source == 0) {
            return 0;
        }
        mdlCopyModelState(source, model);
        *(s32 *)&((Model *)model)->flags &= ~0x2000;
    }
    *(s32 *)&((Model *)model)->flags |= 0x1000;
    return 1;
}







typedef struct MdlCloneHierarchy {
    u32 flags;
} MdlCloneHierarchy;

typedef struct MdlCloneLayer {
    u16 flags;                     /* relative 0x00, model 0xec */
    u8 unknown02[0x1e];
    MdlCloneHierarchy* hierarchy; /* relative 0x20, model 0x10c */
    u8 unknown24[8];
    RtAnimInterpolator* first;     /* relative 0x2c */
    RtAnimInterpolator* second;    /* relative 0x30 */
    MdlDispatchAnimTable* resource; /* relative 0x34, model 0x120 */
    MdlCloneAttachmentTable* attachments; /* relative 0x38 */
    u8 unknown3c[0x68];             /* next layer at 0xa4 */
} MdlCloneLayer;

static inline MdlCloneAttachmentTable* mdlCloneAttachmentStorage(u32 count)
{
    MdlCloneAttachmentTable* copy;
    s32 size = sizeof(MdlCloneAttachmentTable);
    size += count * sizeof(void*);
    size += count * sizeof(void*);
    chkmemAllocSiteTag(D_00713138, 0x1d6);
    copy = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
    memset(copy, 0, size);
    copy->count.word = (u16)count;
    copy->primary = (void**)(copy + 1);
    copy->secondary = copy->primary + (u16)count;
    return copy;
}

/* IDA mdlManager.c:2448-2545; 824B instructions plus eight zero-tail bytes.
   Preserve the model-relative layer base, separately sized attachment arrays
   and callback-visible table reloads. Counts originate in unsigned halfwords. */
/* Copies a model's clump, layer and attachment state from source into destination. The destination takes references on the source's animation resources. */
// FUN_00478410
void mdlCopyModelState(u8* source, u8* destination)
{
    u32 layer;

    if (((Model *)source)->clump != 0) {
        void* clump = func_003c0520(((Model *)source)->clump);
        ((Model *)destination)->clump = clump;
        ((Model *)destination)->drawBuckets = sdkClumpCreateBuckets(clump);
    }
    for (layer = 0; layer < 2; layer++) {
        if (mdlLayerIsPresent(source, (u16)layer) != 0) {
            MdlCloneLayer* sourceLayer =
                (MdlCloneLayer*)(source + 0xec + layer * 0xa4);
            MdlDispatchAnimTable* resource = sourceLayer->resource;
            u8* destinationBase;

            resource->references++;
            destinationBase = destination + layer * 0xa4;
            ((MdlCloneLayer*)(destinationBase + 0xec))->resource = resource;
            if ((sourceLayer->flags & 2) == 0) {
                mdlAttachSlotHierarchy(destinationBase + 0xec, *(u8* *)&((Model *)destination)->clump, 0);
            } else {
                ((MdlCloneLayer*)(destinationBase + 0xec))->flags |= 2;
                {
                    MdlCloneHierarchy* hierarchy =
                        ((MdlCloneLayer*)(destination + 0xec))->hierarchy;
                    ((MdlCloneLayer*)(destinationBase + 0xec))->hierarchy =
                        (MdlCloneHierarchy*)func_003971d0((u8*)hierarchy, 0, hierarchy->flags, -1);
                }
            }
        }
        {
            MdlCloneAttachmentTable* original =
                ((MdlCloneLayer*)(source + 0xec + layer * 0xa4))->attachments;
            if (original != 0) {
                MdlCloneAttachmentTable* copy = mdlCloneAttachmentStorage(original->count.halves.count);
                u32 index;
                for (index = 0; index < copy->count.word; index++) {
                    void** primary = original->primary;
                    if (primary[index] != 0) {
                        void* cloned = mdlEffectListCopy(primary[index]);
                        copy->primary[index] = cloned;
                    }
                    if (original->secondary[index] != 0) {
                        void* cloned = mdlEffectListWrapShared(original->secondary[index]);
                        copy->secondary[index] = cloned;
                    }
                }
                ((MdlCloneLayer*)(destination + 0xec + layer * 0xa4))->attachments = copy;
            }
        }
    }
    {
        MdlAnimEntryTable* resource = ((Model *)source)->materialResource;
        if (resource != 0) {
            resource->references++;
            ((Model *)destination)->materialResource = resource;
        }
    }
    {
        MdlAnimResource* resource = ((MdlAnimControl*)(source + 0x23c))->resource;
        if (resource != 0) {
            resource->references++;
            ((MdlAnimControl*)(destination + 0x23c))->resource = resource;
            mdlSetupNamedFrameAnims(destination + 0x23c, ((Model *)destination)->clump);
            ((MdlAnimControl*)(destination + 0x23c))->mode = 1;
        }
    }
    {
        MdlMatrixTable* resource = *(MdlMatrixTable* *)&((Model *)source)->matrixTable;
        if (resource != 0) {
            resource->unknown++;
            *(MdlMatrixTable* *)&((Model *)destination)->matrixTable = resource;
        }
    }
    if (((Model *)source)->effects != 0) {
        void* copy = mdlEffectListCopy(((Model *)source)->effects);
        ((Model *)destination)->effects = copy;
        mdlEffectListRefreshHandles(copy);
    }
    if (*(void* *)&((Model *)source)->motion.object != 0)
        mdlRetainObject(destination + 0x2d0, source + 0x2d0);
    if (mdlLayerIsPresent(destination, 0) != 0)
        mdlDispatchAnimIfPresent(destination, 0, 0, 0, 1);
}
/* Allocates a model object sized like object; copies the state into it when the source has the 0x1000 flag, otherwise marks the new object with 0x2000. */
// FUN_00478750
u32* mdlCloneModelObject(u8* source)
{
    u32* clone;

    clone = mdlAllocModelObject(((Model *)source)->type, ((Model *)source)->id);
    if ((*(s32 *)&((Model *)source)->flags & 0x1000) != 0) {
        mdlCopyModelState(source, (u8*)clone);
        *(s32 *)&((Model *)clone)->flags |= 0x1000;
    } else {
        *(s32 *)&((Model *)clone)->flags |= 0x2000;
    }
    return clone;
}

/* Releases a model object: unlinks it from its registry bucket, destroys its effects and animation tables, then frees it through the free callback. */
/* measured: keep the resource/link snapshots spanning release callbacks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_004787E0
void mdlDestroyModelObject(u8* model)
{
    u32 slotIndex;
    void* matrixTable;
    Model *modelObject = (Model *)model;
    MdlMatrixTable *matrices;

    if (((Model *)model)->clump != 0) {
        func_003c0700(((Model *)model)->clump);
    }
    for (slotIndex = 0; slotIndex < 2; slotIndex++) {
        mdlDestroySlotEffects(model + slotIndex * 0xA4 + 0xEC);
    }
    if (modelObject->materialResource != 0) {
        mdlReleaseAnimEntryTable(modelObject->materialResource);
        *(void* *)&((Model *)model)->materialResource = 0;
    }
    if (modelObject->animControl.resource != 0) {
        mdlReleaseBlendTrack(modelObject->animControl.resource);
        *(void* *)&((Model *)model)->animControl.resource = 0;
    }
    matrixTable = ((Model *)model)->matrixTable;
    matrices = (MdlMatrixTable *)matrixTable;
    if (matrixTable != 0) {
        matrices->unknown = matrices->unknown - 1;
        if (matrices->unknown == 0) {
            DAT_008873ec[0](matrices->entries);
        }
    }
    if (((Model *)model)->drawBuckets != 0) {
        hMaestroFreeListSet(((Model *)model)->drawBuckets);
    }
    for (slotIndex = 0; slotIndex < 5; slotIndex++) {
        if ((((Model *)(model + slotIndex * 0xC))->attachedWpns[0].flags & 1) != 0 &&
            ((Model *)(model + slotIndex * 0xC))->attachedWpns[0].wpnMdl != 0) {
            mdlDetachSlotModel(model, slotIndex & 0xFFFF);
        }
    }
    AfPackReleaseByOwner(model);
    if (((Model *)model)->effects != 0) {
        mdlEffectListDestroy(((Model *)model)->effects);
    }
    mdlReleaseObject(model + 0x2D0);
    if (modelObject->next != 0) {
        ((Model *)(u8*)((Model *)model)->next)->previous = ((Model *)model)->previous;
    }
    if (((Model *)model)->previous != 0) {
        ((Model *)(u8*)((Model *)model)->previous)->next = ((Model *)model)->next;
    } else {
        D_00922BE0[((Model *)model)->type] = ((Model *)model)->next;
    }
    DAT_008873ec[0](model);
}
/* Recomputes the frame matrix from the model's identity matrix and clump root, then updates the owner matrix. */
// FUN_004789C0
void mdlUpdateModelMatrix(Model* model)
{
    RwMatrix matrix;
    void* frame;

    frame = *(void* *)&((RwObject *)(u8*)model->clump)->parent;
    RwMatrixMultiply(&matrix, &model->identityMat, (void*)model);
    func_003e9cb0(frame, &matrix, 0);
    mdlSetAttachedModelMatrices(model, &matrix);
}



extern void mdlAdvanceAnimControl(void* controlData, void* layerData);
extern u8* mdlAdvanceLayer(u8* layer, u8* previousLayer, s32 updatePose);
extern s32 mdlCopyIndexedMatrix(void* model, s32 index, void* destination);
extern void* mdlGetMatrix(void* model);
extern void mdlEffectListReleaseHandles(u32 *list);
extern void mdlClearWrapperHandle(u32 wrapper);
extern void mdlSetWrapperValue(u32 wrapper, void* value);
extern void mdlRefreshSecondaryEffect(u8* attachment, void* model);
extern void mdlEffectListSetUniformScale(s32* list, f32* scale);
extern void mdlEffectListBuildTransforms(u8** list, u8* model);
extern void mdlTickMotionState(void* state);
extern void mdlSetLayerWeight(u8* model, s32 layer, f32 speed);
extern void mdlCopyScale(void* model, RwV3d* scale);
extern int mdlHasActiveMode(void* model);
/* Measured: 1080B/window 1088B, MATCH with two zero-padding words.
   Cache predicate inputs only until their immediate call; reload every
   callback-visible field afterward. CSE-off retains per-phase matrix
   addresses; propagation-off preserves the post-getter frame-ID snapshot. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
/* Advances a model by tick: refreshes its frame matrix and attachment state, updates both animation layers, then recurses into child models with the same tick. */
// FUN_00478A30
void mdlAdvanceModel(u8* model, s32 tick)
{
    RwMatrix matrix;
    void* frame;
    u8* previousLayer;
    u32 animationLayer;
    u32 switchLayer;
    u32 updateLayer;
    MdlCloneAttachmentTable* attachments;
    u32 child;
    void* draw;
    s32 delay;

    if ((((Model *)model)->flags & 0x1000) != 0) {
        frame = *(void* *)&((RwObject *)(u8*)((Model*)model)->clump)->parent;
        RwMatrixMultiply(&matrix, &((Model*)model)->identityMat, model);
        func_003e9cb0(frame, &matrix, 0);
        mdlSetAttachedModelMatrices((Model*)model, &matrix);
        previousLayer = 0;
        if (mdlHasActiveMode(model) != 0) {
            mdlCopyScale(model, &((Model*)model)->scale);
        }
        for (animationLayer = 0; animationLayer < 2; animationLayer++) {
            if (mdlLayerIsPresent(model, (u16)animationLayer) != 0) {
                previousLayer = mdlAdvanceLayer(model + animationLayer * 0xA4 + 0xEC,
                                             previousLayer, tick);
            }
        }
        ((Model *)model)->flags |= 0x80000;
        mdlAdvanceAnimControl(model + 0x23C, model + 0xEC);
        for (switchLayer = 0; switchLayer < 2; switchLayer++) {
            attachments = ((MdlCloneLayer*)(model + switchLayer * 0xA4 + 0xEC))->attachments;
            if (attachments != 0) {
                draw = attachments->primaryDraw;
                if (attachments->nextPrimary != draw) {
                    if (draw != 0) {
                        mdlEffectListReleaseHandles((u32 *)draw);
                    }
                    draw = attachments->nextPrimary;
                    if (draw != 0) {
                        mdlEffectListRefreshHandles(draw);
                    }
                    attachments->primaryDraw = attachments->nextPrimary;
                }
                if (attachments->pendingSecondary != 0) {
                    draw = attachments->secondaryDraw;
                    if (draw != 0) {
                        mdlClearWrapperHandle((u32)draw);
                    }
                    draw = attachments->nextSecondary;
                    if (draw != 0) {
                        mdlSetWrapperValue((u32)draw, model);
                    }
                    attachments->secondaryDraw = attachments->nextSecondary;
                    attachments->pendingSecondary = 0;
                }
            }
        }
        if (tick != 0) {
            draw = ((Model *)model)->effects;
            if (draw != 0) {
                mdlEffectListSetUniformScale((s32*)draw, (f32*)&((Model*)model)->scale);
                mdlEffectListBuildTransforms(*(u8** *)&((Model *)model)->effects, model);
            }
            for (updateLayer = 0; updateLayer < 2; updateLayer++) {
                attachments = ((MdlCloneLayer*)(model + updateLayer * 0xA4 + 0xEC))->attachments;
                if (attachments != 0) {
                    draw = attachments->primaryDraw;
                    if (draw != 0 && attachments->delay == 0) {
                        mdlEffectListSetUniformScale((s32*)draw, (f32*)&attachments->scale);
                        mdlEffectListBuildTransforms((u8**)attachments->primaryDraw, model);
                    }
                    draw = attachments->secondaryDraw;
                    if (draw != 0 && attachments->delay == 0) {
                        mdlRefreshSecondaryEffect((u8*)draw, model);
                    }
                    delay = attachments->delay;
                    if (delay > 0) {
                        attachments->delay = delay - 1;
                    }
                }
            }
        }
        mdlTickMotionState(model + 0x2D0);
        for (child = 0; child < 5; child++) {
            u8* childBase = model + child * 0xC;
            if ((((Model *)childBase)->attachedWpns[0].flags & 1) != 0) {
                void** childSlot = (void**)(childBase + 0x290);
                if (*childSlot != 0 && mdlPrepareSlotModel(model, (u16)child) != 0) {
                    ((Model*)*childSlot)->identityMat = ((Model*)model)->identityMat;
                    if (tick != 0) {
                        s32* frameId = (s32*)(childBase + 0x294);
                        if (*frameId != -1) {
                            void* childMatrix = mdlGetMatrix(*childSlot);
                            s32 childFrame = *frameId;
                            mdlCopyIndexedMatrix(model, childFrame, childMatrix);
                        } else {
                            ((Model*)*childSlot)->mat = ((Model*)model)->mat;
                        }
                    }
                    {
                        void** updateSlot = (void**)(model + child * 0xC + 0x290);
                        mdlSetLayerWeight(*updateSlot, 0, ((Model *)model)->layers[0].speed);
                        mdlAdvanceModel(*updateSlot, tick);
                    }
                }
            }
        }
    }
}
#pragma pop

/* Advances a model by its update flags: the tick is set unless bit 0 of d8 is set. */
// FUN_00478E70
void mdlAdvanceModelFromFlags(u8 *model)
{
    mdlAdvanceModel(model, (*(s32 *)&((Model *)model)->flags & 1) == 0);
}

/* Stores the draw callback at +0x310 and its context at +0x314. mdlApplyDrawState runs it at the end of the draw state. */
// FUN_00478EA0
void mdlSetDrawCallback(void* model, int callback, int context)
{
    *(int *)&((Model *)model)->drawCallback = callback;
    *(int *)&((Model *)model)->drawData = context;
}

/* Stores the post-draw callback at +0x318 and its context at +0x31C. mdlResetDrawState runs it after the draw. */
// FUN_00478EB0
void mdlSetResetCallback(void* model, int callback, int context)
{
    *(int *)&((Model *)model)->resetCallback = callback;
    *(int *)&((Model *)model)->resetData = context;
}

extern void mdlUpdateBlendTrack(u8* state, u8* layer);
extern void mdlEffectEmitMaskedTagPair(u32 a);
extern s64 iGpffffabe8;

/* P4 port probe: opt_propagation off prevents mwcc folding the D_00887300_abs
   array address into per-call lui/lw (measured: with it on, mid-function base
   assignment rematerializes per use). */
#pragma opt_propagation off

/* Applies a model's draw state: blend-track update, colour scale over its atomics, render-state flags from d8, and the optional callbacks at +0x310. */
// FUN_00478EC0
void mdlApplyDrawState(void* drawObject, Model* model)
{
    struct {
        void* p38;
        u16 p3C;
    } colorScaleContext;
    void (**renderStates)(s32, s32);
    s32 alphaMode;
    void* clump;
    s32 vertexAlphaEnabled;

    if (model->flags & 0x80000) {
        mdlUpdateBlendTrack((u8*)model + 0x234, (u8*)model + 0xEC);
        model->flags &= 0xFFF7FFFF;
    }
    clump = model->clump;
    colorScaleContext.p38 = (u8*)model + 0xD0;
    colorScaleContext.p3C = 0;
    RpClumpForAllAtomics(clump, mdlMatColorScaleCallback, &colorScaleContext);
    vertexAlphaEnabled = (model->flags & 8) != 0;
    renderStates = D_00887300_abs;
    renderStates[0](6, vertexAlphaEnabled);
    renderStates[0](8, (model->flags & 0x10) != 0);
    renderStates[0](0xE, (model->flags & 0x100) != 0);
    if (model->flags & 0x40) {
        alphaMode = 3;
    } else {
        alphaMode = 2;
    }
    renderStates[0](0x14, alphaMode);
    if (model->flags & 0x40000) {
        iGpffffabe8 |= 0x80;
    }
    if (model->flags & 0x100000) {
        mdlEffectEmitMaskedTagPair(model->flags);
    }
    if (model->drawCallback != NULL) {
        ((void (*)(void*))model->drawCallback)((void*)model->drawData);
    }
}
#pragma opt_propagation on

/* Draw callback: applies the model's draw state, then the sky render-state pair from +0xE4 and +0xE8. The second argument is the model. */
// FUN_00479030
void mdlApplySkyDrawState(u8 *drawObject, u8 *model)
{
    mdlApplyDrawState(drawObject, (struct Model*)model);
    RpSkyRenderStateSet(2, ((Model *)model)->skyAlpha);
    RpSkyRenderStateSet(3, ((Model *)model)->skyTest);
}

/* Post-draw callback: clears the global 0x80 draw bit when the model requests it, runs the 0x100000 hook, then calls the model's callback at +0x318. */
// FUN_00479080
void mdlResetDrawState(void* drawObject, void* modelData)
{
    /* measured: keep the flag snapshot word-indexed; direct Model.flags
     * access changes the whole-owner instruction comparison. */
    u32* modelWords = (u32*)modelData;
    if ((modelWords[0xD8 / 4] & 0x40000) != 0) {
        DAT_00723cd8 &= ~0x80;
    }
    if ((modelWords[0xD8 / 4] & 0x100000) != 0) {
        mdlEffectEmitTagPair();
    }
    if (((Model *)modelWords)->resetCallback != 0) {
        ((FnVoidPtr)((Model *)modelWords)->resetCallback)(((Model *)modelWords)->resetData);
    }
}

/* Colour tint uses the same RwRGBA <-> real helpers as mdlMatColorScaleCallback; the
 * draw-colour forwarder mdlEffectListSetColor takes the colour by pointer. */
/* measured: keep the model flag/effect snapshots spanning queue and colour callbacks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
/* IDA mdlManager.c:2696-2870; retail 00479100-00479870.
 * Integration requirements, including attachment fields and the corrected
 * color-forwarding wrapper, are recorded in IDA_model_followthrough.json. */
/* Queue commands use the shared OtPrimitiveNode layout from sdk_ot_node.h. */

extern u8* PrimAllocQueueNode(void);
extern void PrimAppendNode(void*, void*);
extern void mdlAdvanceModel(u8*, s32);
extern void mdlApplySkyDrawState(u8*, u8*);
extern void mdlEffectListSetColor(u8**, s32*);
extern void mdlEffectListInvokeEach(s32, u8**);
extern void mdlSetAttachmentColor(u8*, const u8*);
extern void mdlMarkSecondaryDirty(u8*, u8*);
extern void mdlSetColor(Model*, const RwRGBA*);

/* Queues the model, its effects and attached children with their draw-state callbacks. */
// FUN_00479100
void mdlQueueModelForDraw(void* queue, u8* model)
{
    u8* command;
    u8* renderCommand;
    u32 flags;
    u16 layer;
    u16 childIndex;
    RwRGBA color;
    u32 uncolored;
    u32 childUncolored;
    Model *modelObject = (Model *)model;

    flags = modelObject->flags;
    if ((flags & 0x1000) == 0)
        return;
    if ((flags & 4) == 0)
        mdlAdvanceModel(model, (flags & 1) == 0);
    flags = modelObject->flags;
    if ((flags & 2) != 0)
        return;
    if (model[0xd3] <= 0)
        return;

    if ((flags & 1) != 0 && (flags & 0x8000) == 0)
    {
        command = PrimAllocQueueNode();
        ((OtPrimitiveNode *)command)->command = 0x1c;
        *(void* *)&((OtPrimitiveNode *)command)->primitive = model;
        PrimAppendNode(((Model *)model)->queue, command);
    }
    renderCommand = PrimAllocQueueNode();
    if (modelObject->drawBuckets != 0)
    {
        *(void* *)&((OtPrimitiveNode *)renderCommand)->callback = (void*)mdlApplyDrawState;
        ((OtPrimitiveNode *)renderCommand)->callbackData = model;
    }
    else
    {
        *(void* *)&((OtPrimitiveNode *)renderCommand)->callback = (void*)mdlApplySkyDrawState;
        ((OtPrimitiveNode *)renderCommand)->callbackData = model;
    }
    *(void* *)&((OtPrimitiveNode *)renderCommand)->endCallback = (void*)mdlResetDrawState;
    ((OtPrimitiveNode *)renderCommand)->endCallbackData = model;
    flags = modelObject->flags;
    if ((flags & 0x20) == 0 || ((Model*)model)->color.alpha == 255)
    {
        if (modelObject->drawBuckets == 0)
        {
            ((OtPrimitiveNode *)renderCommand)->command = 9;
            *(void* *)&((OtPrimitiveNode *)renderCommand)->primitive = ((Model*)model)->clump;
            PrimAppendNode(queue, renderCommand);
        }
        else
        {
            if ((flags & 0x18) == 0x18)
                ((OtPrimitiveNode *)renderCommand)->reserved1A &= 0xFFFD;
            else
                ((OtPrimitiveNode *)renderCommand)->reserved1A |= 2;
            ((OtPrimitiveNode *)renderCommand)->command = 5;
            *(void* *)&((OtPrimitiveNode *)renderCommand)->primitive = ((Model *)model)->drawBuckets;
            PrimAppendNode(queue, renderCommand);
        }
    }
    else
    {
        ((OtPrimitiveNode *)renderCommand)->command = 0x1B;
        *(void* *)&((OtPrimitiveNode *)renderCommand)->primitive = model;
        PrimAppendNode(queue, renderCommand);
    }

    if (modelObject->effects != 0)
    {
        flags = modelObject->flags;
        if ((flags & 0x20000) != 0)
            goto layers;
        if ((flags & 0x8000) != 0)
        {
            void* clump = ((Model*)model)->clump;
            uncolored = 1;
            RpClumpForAllAtomics(clump, (KClumpCallback)mdlMatColorUncoloredCallback, &uncolored);
            if (uncolored != 0)
                goto layers;
        }
        if ((((Model *)model)->flags & 0x80) == 0)
        {
            MdlMaterialColorReal real;
            MdlMaterialColorReal tint;
            mdlColorToReal(&real, &((Model*)model)->color);
            mdlColorToReal(&tint, (RwRGBA*)(model + 0x300));
            real.red *= tint.red;
            real.green *= tint.green;
            real.blue *= tint.blue;
            real.alpha *= tint.alpha;
            mdlColorQuantize(&color, &real);
            mdlEffectListSetColor(*(u8 ***)&modelObject->effects, (s32*)&color);
            if (color.alpha > 0)
                mdlEffectListInvokeEach(*(s32 *)&((Model *)model)->owner, *(u8** *)&((Model *)model)->effects);
        }
        else
        {
            mdlEffectListInvokeEach(*(s32 *)&((Model *)model)->owner, *(u8** *)&((Model *)model)->effects);
        }
    }

layers:
    for (layer = 0; layer < 2; ++layer)
    {
        MdlCloneAttachmentTable** slot = &((MdlCloneLayer*)(model + 0xec + (u32)layer * sizeof(MdlCloneLayer)))->attachments;
        MdlCloneAttachmentTable* attachments = *slot;
        if (attachments != 0 && (modelObject->flags & 0x20000) == 0)
        {
            u8* attachmentQueue;
            void* draw;
            attachments->scale = ((Model*)model)->scale;
            if ((((Model *)model)->flags & 0x80) == 0)
                (*slot)->color = ((Model*)model)->color;
            attachments = *slot;
            attachmentQueue = *(u8* *)&((Model *)model)->owner;
            draw = attachments->primaryDraw;
            if (draw != 0)
            {
                mdlEffectListSetColor(draw, (s32*)&attachments->color);
                mdlEffectListInvokeEach((s32)attachmentQueue, attachments->primaryDraw);
            }
            draw = attachments->secondaryDraw;
            if (draw != 0)
            {
                mdlSetAttachmentColor(draw, (const u8*)&attachments->color);
                mdlMarkSecondaryDirty(attachmentQueue, attachments->secondaryDraw);
            }
        }
    }
    for (childIndex = 0; (s64)childIndex < 5; childIndex++)
    {
        u8* childBase = (u8*)((MdlWpnSlot*)model + (u16)childIndex);
        if ((childBase[0x28c] & 1) != 0)
        {
            void** child = (void**)(childBase + 0x290);
            if (*child != 0 && mdlPrepareSlotModel(model, childIndex) != 0)
            {
                void* childClump = ((Model*)*child)->clump;
                childUncolored = 1;
                RpClumpForAllAtomics(childClump, (KClumpCallback)mdlMatColorUncoloredCallback, &childUncolored);
                if (childUncolored == 0)
                    ((Model *)(u8*)*child)->flags &= ~0x20000u;
                else
                    ((Model *)(u8*)*child)->flags |= 0x20000;
                mdlSetColor((Model*)*child, &((Model*)model)->color);
                if ((((Model *)model)->flags & 0x20) == 0)
                    ((Model *)(u8*)*child)->flags &= ~0x20u;
                else
                    ((Model *)(u8*)*child)->flags |= 0x20;
                mdlQueueModelForDraw(queue, *child);
            }
        }
    }
}

/* Per-atomic callback for mdlDrawVisibleAtomics: when the atomic has flag 4 and a non-null object at +0x18 that passes the frustum test, it calls the draw hook at +0x48 of the atomic. */
// FUN_00479880
void* mdlDrawAtomicIfVisible(void* atomic, void* context)
{
    if ((((struct RpAtomic *)atomic)->flags & 4) == 0) {
        return atomic;
    }
    if (*(void* *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry != 0) {
        if (RwCameraFrustumTestSphere(D_008872E0[0], func_003bfae0()) != 0) {
            ((FnVoidPtr)*(void **)&((struct RpAtomic *)atomic)->renderCallBack)(atomic);
        }
    }
    return atomic;
}

/* Draws the visible atomics of a clump: runs mdlDrawAtomicIfVisible over each atomic of object. */
// FUN_00479910
void mdlDrawVisibleAtomics(void* clump)
{
    RpClumpForAllAtomics(clump, mdlDrawAtomicIfVisible, 0);
}

/* IDA 00479940, mdlManager.c:2873-2957: validate raw arguments before
   dispatching the base transform, layer animation and attached children.
   Measured 752B/752B, fully relocated exact match. */
#pragma push
#pragma opt_common_subs off

static inline void mdlDispatchAnimation(u8* mdl, u32 layer, s16 animation, u16 frame, s32 flags)
{
    u32 baseLayer;
    u32 narrowFlags;
    u8** blend;
    u16 i;
    void** child;
    baseLayer = (u16)layer;
    if (baseLayer == 0) {
        {
            MdlDispatchAnimTable* table;
            MdlDispatchAnimEntry* entries;
            void* clip;
            s32 offset;
            s32 index = (s16)animation;
            if (index >= 0 && (table = ((Model *)mdl)->layers[0].resource) != 0 &&
                index < table->count &&
                (offset = index * 80, entries = table->entries,
                 clip = *(void**)mdlAddOffset((u32)entries + 64, offset)) != 0 && clip != D_00922BC0_abs) {
                *(RwMatrix *)&((Model *)mdl)->identityMat.right.x = *(RwMatrix *)&((MdlDispatchAnimEntry *)((u8*)entries + offset))->matrix.right.x;
            } else {
                RwMatrix* matrix = (RwMatrix*)(mdl + 64);
                matrix->right.x = matrix->up.y = matrix->at.z = 1.0f;
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
        }
        if (*(void* *)&((Model *)mdl)->materialResource && (blend = *(u8** *)&((Model *)mdl)->materialAnimation))
            mdlMatAnimApplyWithPivot(blend, 0.0f, 1.0f);
        mdlStartAnimation(((Model *)mdl)->clump, (MdlAnimControl*)(mdl + 0x23c), animation, frame, flags);
    }
    mdlStartLayerAnimation(mdl + 0xec + (u16)layer * 0xa4, animation, frame, flags);
    if (*(void* *)&((Model *)mdl)->motion.object && !((narrowFlags = (u16)flags) & 0x40) && baseLayer == 0) {
        if (narrowFlags & 0x100) {
            ((Model *)mdl)->motion.flags &= ~0x20;
            mdlRequestMotionAnim(mdl + 0x2d0, animation, frame);
        } else {
            ((Model *)mdl)->motion.flags |= 0x20;
            mdlRequestMotionAnim(mdl + 0x2d0, animation, frame);
        }
    }
    if (((Model *)mdl)->flags & 0x10000) {
        for (i = 0; (s64)i < 5; i++) {
            u8* slot = mdl + (u16)i * 12;
            if (((Model *)slot)->attachedWpns[0].flags & 1) {
                child = (void**)(slot + 0x290);
                if (*child && mdlPrepareSlotModel(mdl, i))
                    mdlDispatchAnimIfPresent(*child, 0, animation, frame, flags);
            }
        }
    }
}
#pragma opt_common_subs on
/* Dispatches the animation through mdlDispatchAnimation when mdlLayerHasAnimation reports the animation present, and always returns 1. */
// FUN_00479940
s32 mdlDispatchAnimIfPresent(u8* mdl, u32 layer, s16 animation, u16 frame, s32 flags)
{
    if (mdlLayerHasAnimation(mdl, layer, animation))
        mdlDispatchAnimation(mdl, layer, animation, frame, flags);
    return 1;
}
#pragma pop

/* Returns the layer's animation index from its state record (+0xF0), or -1 when the layer has no animation state. */
// FUN_00479C30
s16 mdlGetLayerAnimation(s32 model, s32 layer)
{
    if (mdlLayerIsPresent((u8 *)model, layer) != 0) {
        s32 off = (layer & 0xFFFF) * 0xA4;
        return *(s16 *)&((Model *)(off + (s32)model + 0xF0))->mat.right.x;
    }
    return -1;
}

/* Returns 1 when the layer has animation state. Layer 0 counts either the primary state (+0x120) or the secondary list (+0x234); other layers check their own state record at +0x120. */
// FUN_00479CA0
s32 mdlLayerIsPresent(void* model, s32 layer)
{
    u16 layerIndex = (u16)layer;
    s32 layerOffset;
    void* layerBase;
    if (layerIndex == 0) {
        if (*(s32 *)&((Model *)model)->layers[0].resource == 0 && *(s32 *)&((Model *)model)->materialResource == 0) {
            return 0;
        }
    } else {
        layerOffset = (s32)layerIndex * 0xA4;
        layerBase = (void*)(layerOffset + (s32)model);
        if (*(s32 *)&((Model *)layerBase)->layers[0].resource == 0) {
            return 0;
        }
    }
    return 1;
}

/* measured: MATCHED this wave (nd 0, was 91). Levers: (3) mdlAddOffset index-first
   addu helper, (4) explicit entryData temp for the *(u16*)(resourceAddress+8) load, and
   reusing resourceAddress for *obj (resourceAddress = *(int*)(resourceAddress+0)) which routes the load into
   the $a3 mask reg exactly as retail does, with mdlAddOffset folding index into the
   addu. The (u16)data second check uses plain ints (no mask local). */
/* The signed-short animation contract is shared by the model and battle
   callers. Integer comparisons perform the retail sign extension here. */
/* Returns 1 when the layer's animation table has an entry for the animation. Layer 0 also checks the secondary list at +0x234. */
// FUN_00479D10
s32 mdlLayerHasAnimation(u8* model, u32 layer, s16 animation)
{
    int result = 0;
    int tableOrEntries;
    int entryCount;
    tableOrEntries = *(int *)&((Model *)mdlAddOffset((layer & 0xffff) * 0xa4, (u32)model))->layers[0].resource;
    if (tableOrEntries != 0) {
        entryCount = ((MdlDispatchAnimTable *)tableOrEntries)->count;
        if (animation < entryCount) {
            tableOrEntries = *(int *)&((MdlDispatchAnimTable *)tableOrEntries)->entries;
            if (*(int *)&((MdlDispatchAnimEntry *)mdlAddOffset(animation * 0x50, (u32)tableOrEntries))->animation != 0) result = 1;
        }
    }
    if ((u16)layer == 0) {
        int materialResource = *(int *)&((Model *)model)->materialResource;
        if (materialResource != 0) {
            if (animation < ((MdlAnimEntryTable *)materialResource)->count) {
                int materialEntries = *(int *)&((MdlAnimEntryTable *)materialResource)->entries;
                if (*(int *)&((MdlLoaderEntry *)(materialEntries + animation * 8))->value != 0) result = 1;
            }
        }
    }
    return result;
}

/* measured: 4 attempts (nd 33/36/36/36). Correct spellings found: the byte
   chain wants 32-bit arithmetic on a byte base - *(void**)((u8*)arr +
   idx*0x50 + 0x40) folds 0x40 into the lw (element form *0x50+0x10 emits an
   extra sll 6 chain + daddiu, nd 33; (s16) param typing emits no dance at
   all). Residual: (1) retail re-derives the s16 sign-extension (dsll32/
   dsra32) at BOTH use sites; b210 CSEs the two conversions into one pair in
   every spelling tried (s64 shifts, (s64)(s16) casts, s32 param + (s16)
   narrowing, named s32 local nd 22); (2) retail loads arr = *elem at the top
   of the flag body, b210 sinks it below the idx re-derivation + 0x50 chain
   (load-sinking, brief-confirmed); (3) the return-1 path gets its own b to
   the epilogue where retail falls through. Load-CSE +
   sign-extension-reissue floor (same family as 79d10). */
/* MATCHED this wave (nd 0, was 33). Levers: (3) mdlAddOffset index-first addu
   helper, (7) D_00922BC0_abs lui/addiu address, (4) opt_propagation off forces
   the lhu-before-signext load order (FLYDraw/FLYCmbcardeff combo). Helper is
   defined at top of file, outside the pragma. */
/* Returns 1 when layer input has a key at index mode whose animation is the empty-clip sentinel D_00922BC0, and 0 otherwise, including when the index is out of range. */
// FUN_00479DD0
#pragma opt_propagation off
s32 mdlIsLayerKeyEmpty(u8* model, u16 layer, s16 animation)
{
    int isEmpty;
    int hasIndex;
    int entryOffset;
    int tableOrEntries;
    int entryCount;

    isEmpty = 0;
    hasIndex = 0;
    entryOffset = (layer & 0xffff) * 0xa4;
    tableOrEntries = *(int *)&((Model *)mdlAddOffset(entryOffset, (u32)model))->layers[0].resource;
    if (tableOrEntries != 0)
    {
        entryCount = ((MdlDispatchAnimTable *)tableOrEntries)->count;
        if (animation < entryCount)
        {
            hasIndex = 1;
        }
    }
    if (hasIndex != 0)
    {
        tableOrEntries = *(int *)&((MdlDispatchAnimTable *)tableOrEntries)->entries;
        entryOffset = mdlAddOffset(animation * 0x50, (u32)tableOrEntries);
        if (*(int *)&((MdlDispatchAnimEntry *)entryOffset)->animation == (int)D_00922BC0_abs)
        {
            isEmpty = 1;
        }
    }
    return isEmpty;
}
#pragma opt_propagation on
/* measured: probing opt_common_subs off to retain the raw parameter register. */
#pragma opt_common_subs off
/* Sets the layer's animation time to frame scaled by the global time factor, through the layer's key interpolator. Layer 0 also updates the animation control time. */
/* measured: keep the member-first clip pointer lookup
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_00479E60
void mdlSetLayerTime(void* model, s32 layer, f32 frameValue)
{
    s32 layerIndex;
    s32 layerOffset;
    u8* table;
    s32 animationIndex;
    s32 entryOffset;
    s32 clip;
    s32 layerBase;
    f32 time;

    layerIndex = layer;
    time = iGpffff8040 * frameValue;
    layerOffset = (layerIndex & 0xFFFF) * 0xA4;
    layerBase = mdlAddOffset(layerOffset, (u32)model);
    animationIndex = ((Model *)layerBase)->layers[0].animationIndex;
    if (animationIndex < 0)
        goto tail;
    table = *(u8* *)&((Model *)layerBase)->layers[0].resource;
    if (table == 0)
        goto tail;
    if (((MdlDispatchAnimTable *)table)->count <= animationIndex)
        goto tail;
    entryOffset = animationIndex * 0x50;
    /* measured: plain entryOffset changes 25 bytes; retain the existing address operand order. */
    clip = *(s32 *)((u32)((u32)*(s32 *)table + MEMBER_OFFSET(MdlDispatchAnimEntry, animation)) + (u32)(entryOffset, entryOffset));
    if (clip == 0)
        goto tail;
    if (clip == (s32)D_00922BC0_abs)
        goto tail;
    func_003d5e40(*(void* *)&((RpHAnimHierarchy *)((Model *)layerBase)->layers[0].hierarchy)->currentAnim, time);
    layerBase = mdlAddOffset(layerOffset, (u32)model);
    ((Model *)layerBase)->layers[0].flags |= 4;
tail:
    if ((layerIndex & 0xFFFF) == 0) {
        mdlSetAnimControlTime((u8*)model + 0x23C, time);
    }
}
/* measured: closes the scoped opt_common_subs probe for mdlSetLayerTime. */
#pragma opt_common_subs on
/* Returns the current clip's duration in frames, or zero without a valid clip. */
// FUN_00479F60
f32 mdlGetLayerTime(void* model, s32 layer)
{
    f32 duration;
    s32 layerOffset;
    void* layerBase;
    layerOffset = (s32)(layer & 0xFFFF) * 0xA4;
    layerBase = (void*)(layerOffset + (s32)model);
    if (((Model *)layerBase)->layers[0].animationIndex < 0) {
        duration = 0.0f;
    } else if (*(void* *)&((Model *)layerBase)->layers[0].hierarchy == 0 ||
               *(void* *)&((RpHAnimHierarchy *)(u8*)*(void* *)&((Model *)layerBase)->layers[0].hierarchy)->currentAnim == 0) {
        duration = 0.0f;
    } else if (*(void* *)&((RtAnimInterpolator *)(u8*)*(void* *)&((RpHAnimHierarchy *)(u8*)*(void* *)&((Model *)layerBase)->layers[0].hierarchy)->currentAnim)->pCurrentAnim == 0) {
        duration = 0.0f;
    } else {
        duration = ((RtAnimAnimation *)(u8*)*(void* *)&((RtAnimInterpolator *)(u8*)*(void* *)&((RpHAnimHierarchy *)(u8*)*(void* *)&((Model *)layerBase)->layers[0].hierarchy)->currentAnim)->pCurrentAnim)->duration;
    }
    return duration / iGpffff8040;
}

/* Returns the indexed animation clip's duration in frames; requires a layer hierarchy. */
// FUN_0047A000
f32 mdlGetLayerKeyTime(void* model, s32 layer, s64 animationIndex)
{
    f32 duration;
    u16 layerIndex = (u16)layer;
    s32 layerOffset;
    void* layerBase;
    void* table;
    void* entries;
    void* entry;
    s32 keyIndex;
    s32 entryOffset;
    layerOffset = (s32)layerIndex * 0xA4;
    layerBase = (void*)(layerOffset + (s32)model);
    if (*(s32 *)&((Model *)layerBase)->layers[0].hierarchy == 0) {
        duration = 0.0f;
    } else {
        table = *(void* *)&((Model *)layerBase)->layers[0].resource;
        entries = *(void**)table;
        keyIndex = (s16)animationIndex;
        entryOffset = keyIndex * 0x50;
        entry = (void*)(entryOffset + (s32)entries);
        duration = ((RtAnimAnimation *)(u8*)((MdlDispatchAnimEntry *)(u8*)entry)->animation)->duration;
    }
    return duration / iGpffff8040;
}

/* Returns the layer clock in frames, or zero when its animation index is negative. */
// FUN_0047A080
f32 mdlGetLayerWeight(s32 model, s32 layer) {
    s32 layerOffset = (layer & 0xFFFF) * 0xA4;
    u8 *layerBase = (u8 *)(layerOffset + model);
    f32 time;

    if (((Model *)layerBase)->layers[0].animationIndex < 0) {
        time = 0.0f;
    } else {
        time = ((Model *)layerBase)->layers[0].time;
    }
    return time / iGpffff8040;
}

/* Sets the animation speed multiplier; layer zero also updates named-frame control speed. */
// FUN_0047A0E0
void mdlSetLayerWeight(u8 *model, s32 layer, f32 speed) {
    s32 layerIndex = layer & 0xFFFF;
    s32 layerOffset = layerIndex * 0xA4;

    ((Model *)(layerOffset + (s32)model))->layers[0].speed = speed;
    if (layerIndex == 0) {
        ((Model *)model)->animControl.speed = speed;
    }
}

/* Sets flag 0x80 in the layer record when its handle at +0x120 has data at +4. */
// FUN_0047A120
void mdlSetLayerHandleFlag(void* model)
{
    void* table = *(void* *)&((Model *)model)->layers[0].resource;
    if (table != 0 && *(void* *)&((MdlDispatchAnimTable *)table)->unknown != 0) {
        ((Model *)model)->layers[0].flags |= 0x80;
    }
}

/* Clears flag 0x80 under the same condition as mdlSetLayerHandleFlag. */
// FUN_0047A150
void mdlClearLayerHandleFlag(void* model)
{
    void* table = *(void* *)&((Model *)model)->layers[0].resource;
    if (table != 0 && *(void* *)&((MdlDispatchAnimTable *)table)->unknown != 0) {
        ((Model *)model)->layers[0].flags &= 0xFF7F;
    }
}

/* Translates matrix by translation through RwMatrixTranslate, keeping the caller's combine mode. */
// FUN_0047A180
RwMatrix* mdlTranslateMatrix(RwMatrix* matrix, const RwV3d* translation, int combineOp)
{
    return RwMatrixTranslate(matrix, translation, (RwOpCombineType)combineOp);
}

/* Rotates matrix about axis by angle through RwMatrixRotate, keeping the caller's combine mode. */
// FUN_0047A1A0
void mdlRotateMatrix(void *matrix, const void *axis, f32 angle, s32 combineOp)
{
    RwMatrixRotate((struct RwMatrixTag *)matrix, (const RwV3d *)axis,
                  angle, (RwOpCombineType)combineOp);
}

/* Applies matrix input to model owner through func_003e0e20 with combine mode mode. */
// FUN_0047A1C0
void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp)
{
    func_003e0e20(model, matrix, combineOp);
}
/* Records model scale, then applies it to the matrix with the requested combine mode. */
// FUN_0047A1E0
void mdlScale(Model* model, const RwV3d* scale, int combineOp)
{
    model->scale = *scale;
    RwMatrixScale(&model->mat, scale, combineOp);
}



// FUN_0047A220
void mdlSetColor(Model* model, const RwRGBA* color)
{
    model->color = *color;
}




// FUN_0047A250
void* mdlGetColor(void* model)
{
    return &((Model *)model)->color;
}

/* Applies the colour at +0xD0 to every atomic of the clump through mdlMatColorScaleCallback. */
// FUN_0047A260
void mdlApplyColorToAtomics(void* model)
{
    struct {
        void* ptr;
        u16 v;
    } s;
    void* clump = ((Model *)model)->clump;
    s.ptr = (u8*)model + 0xD0;
    s.v = 0;
    RpClumpForAllAtomics(clump, mdlMatColorScaleCallback, &s);
}
/* Sets a 4x4 matrix to identity with zero translation and writes 0x20003 into its flag word at index 3. */
// FUN_0047A2A0
void mdlInitIdentityMatrix(u32* matrixWords)
{
    /* Store IEEE-754 identity bit patterns through the original word API;
     * preserve the flag word's read-modify-write of 0x20003. */
    *(u32 *)&((RwMatrix *)matrixWords)->at.z = 0x3f800000;
    *(u32 *)&((RwMatrix *)matrixWords)->up.y = 0x3f800000;
    *(u32 *)&((RwMatrix *)matrixWords)->right.x = 0x3f800000;
    *(u32 *)&((RwMatrix *)matrixWords)->up.x = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->right.z = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->right.y = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->at.y = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->at.x = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->up.z = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->pos.z = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->pos.y = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->pos.x = 0;
    *(u32 *)&((RwMatrix *)matrixWords)->flags = *(u32 *)&((RwMatrix *)matrixWords)->flags | 0x20003;
    return;
}

// FUN_0047A2F0
void* mdlGetMatrix(void* model)
{
    return model;
}

/* Returns the clump's root frame; the caller must supply a prepared model. */
// FUN_0047A300
void* mdlGetClumpFrame(void* model)
{
    void* clump = ((Model *)model)->clump;
    return *(void* *)&((RwObject *)clump)->parent;
}

// FUN_0047A310
void* mdlGetClump(void* model)
{
    return ((Model *)model)->clump;
}

/* measured (recipe A retest, 4 attempts nd 82/67/63/6): no u16 sign-test in
   this function - recipe A does not apply. Working spellings: goto-shared
   fail (single move $v0,0 block), s32 loop counter with explicit (u16)
   casts (increment andi $s0 + re-mask andi $v0 at the test, exactly retail),
   p = owner + (i & 0xFFFF) * 0xC (the explicit mask keeps the andi at the
   chain), nested ifs with t2 = p + 0x290 materialized between the 0x28C and
   0x290 tests (retail's addiu $s2, $v1, 0x290 position), named mp for the
   inner ptr load (load-before-chain order). Residual nd 6 is the recorded
   outer-block schedule: [sll chain; addiu 0x40; lw ptr] vs retail [sll
   chain; lw ptr; addiu 0x40] - the chain result lands in $v0 vs retail $v1
   and the addiu applies to the chain instead of the loaded ptr; `*a + (0x40
   + idx)` avoids the fold but keeps this order, plain `*a + 0x40 + idx`
   folds 0x40 into the load (3 words, nd 84). Chain-vs-load schedule floor
   (same as recorded). */
// Looks up the owner's current item (list index at +0xF0). When that item is valid, prepares each slot model that has a sub-model, calls func_00397c40 on the owner's hierarchy and on each sub-model's hierarchy, and returns 1. Returns 0 when the item is missing or is the sentinel.
/* measured: 0047A320 now loads the inner list base into a named local before
   the index chain, reproducing retail's lw-base-then-sll order and all inner
   register colors. Scoped verify: normalized_diff 0, object 372B/window 384B;
   the remaining 12-byte tail is zero padding after the matching jr/nop. */
/* measured: keep the clip lookup and child-slot snapshots around preparation
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_0047A320
s32 mdlPrepareItemSlots(void* model) {
    void* table;
    void* clip;
    void* child;
    void* childTable;
    void* childEntries;
    void* slotBase;
    s16 animationIndex;
    s16 childIndex;
    u16 slotIndex;
    s32 entryOffset;
    table = *(void* *)&((Model *)(u8*)model)->layers[0].resource;
    if (table != (void*)0) {
        animationIndex = ((Model *)(u8*)model)->layers[0].animationIndex;
        if (animationIndex < ((MdlDispatchAnimTable *)(u8*)table)->count) {
            entryOffset = (s32)animationIndex * 0x50;
            clip = *(void**)((u32)((u32)*(s32*)table + MEMBER_OFFSET(MdlDispatchAnimEntry, animation)) + (u32)entryOffset);
            if (clip != (void*)0 && clip != (void*)D_00922BC0_abs) {
                func_00397c40(*(void* *)&((Model *)(u8*)model)->layers[0].hierarchy);
                slotIndex = 0;
                while ((s64)slotIndex < 5) {
                    entryOffset = (u16)slotIndex;
                    slotBase = (u8*)model + (entryOffset * 0xC);
                    if ((((Model *)(u8*)slotBase)->attachedWpns[0].flags & 1) != 0 && ((Model *)slotBase)->attachedWpns[0].wpnMdl != (void*)0 && mdlPrepareSlotModel(model, slotIndex) != 0) {
                        child = ((Model *)slotBase)->attachedWpns[0].wpnMdl;
                        childTable = *(void* *)&((Model *)(u8*)child)->layers[0].resource;
                        if (childTable != (void*)0) {
                            childIndex = ((Model *)(u8*)child)->layers[0].animationIndex;
                            if (childIndex < ((MdlDispatchAnimTable *)(u8*)childTable)->count) {
                                childEntries = *(void**)childTable;
                                clip = ((MdlDispatchAnimEntry *)((u32)childEntries + (u32)((s32)childIndex * 0x50)))->animation;
                                if (clip != (void*)0 && clip != (void*)D_00922BC0_abs) {
                                    func_00397c40(*(void* *)&((Model *)(u8*)child)->layers[0].hierarchy);
                                }
                            }
                        }
                    }
                    slotIndex++;
                }
                return 1;
            }
        }
    }
    return 0;
  }

/* Clears the bits of the mask read from data in the word at +0x8 of the atomic's +0x18 block. Walker callback for mdlClearAtomicFlags; returns the atomic. */
// FUN_0047A4A0
void *mdlClearAtomicFlagsCallback(void *atomic, void *geometryOrMaskData) {
    /* geometryOrMaskData is reassigned rather than using a fresh local: retail reuses the
       $a1 argument register for the node pointer once the mask is loaded. */
    s32 mask = *(s32 *)geometryOrMaskData;

    geometryOrMaskData = *(void * *)&*(u8 **)&((struct RpAtomic *)atomic)->geometry;
    *(s32 *)&((MdlGeometry *)geometryOrMaskData)->flags &= ~mask;
    return atomic;
}

/* Clears the mask bits from every atomic of a model's clump through mdlClearAtomicFlagsCallback. */
// FUN_0047A4D0
void mdlClearAtomicFlags(void* model, int flags)
{
    RpClumpForAllAtomics(((Model *)model)->clump, mdlClearAtomicFlagsCallback, &flags);
}


#pragma push
/* Retain the separate body, test and found-index masks from retail. */
#pragma opt_common_subs off
static inline s32 mdlMatrixFromTable(MdlMatrixTable* list, void* owner,
                                       s32 input, u8* dst)
{
    u8* container;
    s32 count, key, bodyIndex, testIndex, foundIndex, value, result;
    u16 index;
    MdlMatrixEntry* entry;
    u8* temp;

    container = *(u8* *)&((Model *)(u8*)owner)->clump;
    count = list->count;
    index = 0;
    key = input & 0xFFFF;
    goto loop_test;
loop_body:
    bodyIndex = index & 0xFFFF;
    entry = list->entries + bodyIndex;
    if (key == entry->id) {
        goto found;
    }
    index += 1;
loop_test:
    testIndex = index & 0xFFFF;
    if (testIndex < count) {
        goto loop_body;
    }
found:
    if (testIndex == count) {
        result = 0;
    } else {
        foundIndex = index & 0xFFFF;
        entry = list->entries + foundIndex;
        value = entry->frameId;
        temp = ((RwObject *)container)->parent;
        temp = mdlFindFrame(temp, value);
        if (temp == 0) {
            result = 0;
        } else {
            RwMatrixMultiply(dst, &entry->matrix, func_003e9700(temp));
            result = 1;
        }
    }
    return result;
}

/* MATCH: 440B/448B, with two zero-tail words. The table helper retains
   its shared return block; RwMatrix assignment emits the retail pair-copy. */
/* Copies the matrix for index input into mode from the matrix table at +0x2C8, or from the user-data frame when there is no table. Returns 1 when a matrix was copied. */
// FUN_0047A510
s32 mdlCopyIndexedMatrix(void* model, s32 index, void* destination)
{
    MdlMatrixTable* table;
    s32 result;
    u8* destinationBytes;
    u8* sourceBytes;

    destinationBytes = (u8*)destination;
    table = *(MdlMatrixTable* *)&((Model *)model)->matrixTable;
    if (table != 0) {
        result = mdlMatrixFromTable(table, model, index, destinationBytes);
    } else {
        sourceBytes = (u8*)K_Clump_FindIntUsrDataFrame(((Model *)model)->clump,
                               (const char*)D_007131D8, index);
        if (sourceBytes == NULL) {
            result = 0;
        } else {
            sourceBytes = func_003e9700(sourceBytes);
            *(RwMatrix*)destinationBytes = *(RwMatrix*)sourceBytes;
            result = 1;
        }
    }
    return result;
}
#pragma pop
/* Computes the attach matrix for index input into mode: through mdlComputeAttachMatrix when the table at +0x2C8 exists, else from the user-data frame. Returns 0 when that frame is absent. */
// FUN_0047A6D0
s32 mdlComputeIndexedAttachMatrix(void* model, s32 index, void* destination)
{
    s32 result;
    u8* matrixBytes;
    RwMatrix matrix;

    if (((Model *)model)->matrixTable != 0) {
        result = mdlComputeAttachMatrix(&matrix, ((Model *)model)->matrixTable, index & 0xFFFF, ((Model *)model)->clump);
    } else {
        matrixBytes = (u8*)K_Clump_FindIntUsrDataFrame(((Model *)model)->clump, (const char*)D_007131D8, (s32)index);
        if (matrixBytes == 0) {
            result = 0;
        } else {
            matrixBytes = (u8*)func_003e9700(matrixBytes);
            matrix = *(const RwMatrix *)matrixBytes;
            result = 1;
        }
    }
    if (result == 0) {
        return 0;
    }
    *(RwV3d*)destination = matrix.pos;
    return 1;
}
/* Returns the model's int user-data count: the cached count at +0x2C8 when set, else the count of int user data on its clump. */
// FUN_0047A7C0
u32 mdlCountIntUserData(void* model)
{
    u16* tableCounts = *(u16* *)&((Model *)model)->matrixTable;
    if (tableCounts != 0) {
        return tableCounts[0];
    }
    return K_Clump_CountIntUsrData(((Model *)model)->clump, (const char*)D_007131D8);
}

/* Sets bit 0 of the model flags at +0xD8, the inverse of mdlClearBattleStateFlag. Called from battle unit code and the field shadow code. */
// FUN_0047A810
void mdlSetBattleStateFlag(void* model)
{
    ((Model *)model)->flags |= 1;
}

/* Clears bit 0 of the model flags at +0xD8. Called from the battle look-at reset path (code1_0019 case 1), which then clears the 0x260 state bits. Consumer of bit 0 not yet traced. */
// FUN_0047A830
void mdlClearBattleStateFlag(void* model)
{
    ((Model *)model)->flags &= ~1;
}

/* Sets the alpha-blend flag (0x20) at +0xD8. Scene and field code calls it for translucent models (mt_sceneFunc, k_fldAI). Consumer of the flag not yet traced. */
// FUN_0047A850
void mdlSetAlphaBlend(void* model)
{
    ((Model *)model)->flags |= 0x20;
}

/* Clears the alpha-blend flag (0x20) at +0xD8, the inverse of mdlSetAlphaBlend. Called when a model is fully opaque or a fade completes. */
// FUN_0047A870
void mdlClearAlphaBlend(void* model)
{
    ((Model *)model)->flags &= ~0x20;
}

/* Sets the 0..1 weight at +0x144. Consumer: evtModel's state code, which sets it from its timer and reads it back (2.0f * value). No reader in mdlManager. */
// FUN_0047A890
void mdlSetBlendWeight(void* model, float value)
{
    ((Model *)model)->layers[0].look.blend = value;
}

/* Stores a high/low pair at +0x148/+0x14C for look-at setup. Battle passes the unit's look-at range (or the 70/60 and 70/80 pairs and call angles) next to the blend weight. Consumer not yet traced. */
// FUN_0047A8A0
void mdlLookAtSetupSetRange(void* model, float pitchLimit, float yawLimit)
{
    ((Model *)model)->layers[0].look.pitchLimit = pitchLimit;
    ((Model *)model)->layers[0].look.yawLimit = yawLimit;
}

/* Sets the look target point at +0x17C and selects target mode: sets flag 0x40 and clears 0x20, 0x80 and 0x100. Battle and promoted look-at code pass the unit's look target. Consumer not yet traced. */
// FUN_0047A8B0
void mdlSetLookAtTargetPoint(void* model, RwV3d* target)
{
    ((Model *)model)->layers[0].look.flags |= 0x40;
    ((Model *)model)->layers[0].look.flags &= 0xFF5F;
    ((Model *)model)->layers[0].look.flags &= 0xFEFF;
    *(RwV3d *)&((Model *)model)->layers[0].look.target.x = *target;
}

/* Sets the look direction vector at +0x17C from a matrix at-axis and selects direction mode: sets flag 0x20 and clears 0x40, 0x80 and 0x100. Event code passes the at vector. Consumer not yet traced. */
// FUN_0047A900
void mdlSetLookAtDirection(void* model, RwV3d* direction)
{
    ((Model *)model)->layers[0].look.flags |= 0x20;
    ((Model *)model)->layers[0].look.flags &= 0xFF3F;
    ((Model *)model)->layers[0].look.flags &= 0xFEFF;
    *(RwV3d *)&((Model *)model)->layers[0].look.target.x = *direction;
}

/* Sets the look controller's yaw/pitch rotation offsets, enables offset rotation
 * (0x8000), and clears the requested-mode bit (0x100). */
// FUN_0047A950
void mdlSetTrackScaleRange(void* model, float yawOffset, float pitchOffset)
{
    ((Model *)model)->layers[0].look.flags |= 0x8000;
    ((Model *)model)->layers[0].look.flags &= 0xFEFF;
    ((Model *)model)->layers[0].look.yawOffset = yawOffset;
    ((Model *)model)->layers[0].look.pitchOffset = pitchOffset;
}

/* Returns the four-float current look quaternion consumed by hierarchy pose updates. */
// FUN_0047A980
void* mdlGetLookAtSubobject(void* model)
{
    return ((Model *)model)->layers[0].look.rotation;
}

/* Sets flag 0x100 in the look state word at +0x140. The mode setters (look target, look direction, track scale) clear it. Battle and evtModel call it after configuring a look. Exact meaning not yet traced. */
// FUN_0047A990
void mdlSetLookAtRequested(void* model)
{
    ((Model *)model)->layers[0].look.flags |= 0x100;
}

/* Sets flag 0x200 in the look state word at +0x140. Battle look-at activation in code1_0019 case 3 and its state branches call it after the range is set. Exact meaning not yet traced. */
// FUN_0047A9B0
void mdlSetLookAtActive(void* model)
{
    ((Model *)model)->layers[0].look.flags |= 0x200;
}

/* Returns nonzero when a look-target, look-direction, look-requested or track-scale mode bit is set (mask 0x81E0 on the look state word at +0x140). evtModel, evtMain and code1_0019 gate their state machines on it; the draw path in this file does too. */
// FUN_0047A9D0
int mdlHasActiveMode(void* model)
{
    return (((Model *)model)->layers[0].look.flags & 0x81E0) != 0;
}

/* Stores a whole value into the look state word at +0x140. code1_0018 and code1_0019 case 3 write it during battle look-at transitions. Not all bit meanings are traced. */
// FUN_0047A9F0
void mdlSetLookStateWord(void* model, u16 value)
{
    ((Model *)model)->layers[0].look.flags = value;
}

/* Returns the look state word at +0x140. code1_0019 case 3 reads and masks it before rewriting it. */
// FUN_0047AA00
u16 mdlGetLookStateWord(void* model)
{
    return ((Model *)model)->layers[0].look.flags;
}

/* Copies scale into the model record at +0x170. */
// FUN_0047AA10
void mdlCopyScale(void* model, RwV3d* scale)
{
    *(RwV3d *)&((Model *)model)->layers[0].look.scale.x = *scale;
}

/* measured: retail masks the counter head (andi $v1,$a3,0xffff; slti $v1,$v1,5)
   AND at the body top (andi $a2,$a3,0xffff). A plain s32 counter with (u16)
   casts at each use CSEs the two masks into one carried register and emits a
   redundant self-mask. The matching form is a while loop that derives the body
   index into a separate u32 local (idx = (u16)i) so mwcc keeps the body-top
   andi distinct from the loop-head andi (nd 0, byte-exact). Committed at nd 0. */
/* Stores data at +0x2FC of the model, and of each attached slot model whose slot flag bit 0 is set. */
// FUN_0047AA30
void mdlSetAttachedOwner(void* model, void* owner) {
    s32 slotIndex;
    ((Model *)model)->owner = owner;
    slotIndex = 0;
    while ((u16)slotIndex < 5) {
        u32 slotIndexValue = (u16)slotIndex;
        void* slotBase = (u8*)model + slotIndexValue * 0xC;
        if ((((Model *)slotBase)->attachedWpns[0].flags & 1) != 0 && ((Model *)slotBase)->attachedWpns[0].wpnMdl != 0) {
            ((Model *)(u8*)((Model *)slotBase)->attachedWpns[0].wpnMdl)->owner = owner;
        }
        slotIndex = (u16)(slotIndex + 1);
    }
}

/* Creates a model for type and id from resource resource, prepares it, and attaches it to slot data; resourceValue bit 0 selects the 0x4000 flag. */
// FUN_0047AAA0
void mdlAttachSlotModelFromResource(void* model, u16 slotIndex, u32 type, u16 id, void* resource, u32 flags)
{
    void* child;
    s32 slotOffset;
    void* slotBase;
    child = mdlAllocModelObject(type, id);
    if ((flags & 1) != 0) {
        ((Model *)child)->flags |= 0x4000;
    }
    mdlAllocAuxBlock(child);
    mdlSetAuxResource(child, resource);
    mdlPrepareModel(child);
    slotOffset = (s32)(slotIndex & 0xFFFF) * 0xC;
    slotBase = (void*)(slotOffset + (s32)model);
    ((Model *)slotBase)->attachedWpns[0].wpnMdl = child;
    ((Model *)child)->flags |= 0x4;
    ((Model *)(u8*)((Model *)slotBase)->attachedWpns[0].wpnMdl)->flags |= 0x8000;
    ((Model *)slotBase)->attachedWpns[0].flags |= 0x1;
}

/* Like mdlAttachSlotModelFromResource, but applies the (int, int) pair through mdlSetAuxPair. */
// FUN_0047AB90
void mdlAttachSlotModelFromPair(void* model, u16 slotIndex, u32 type, u16 id, s32 memory, s32 byteCount, u32 flags)
{
    void* child;
    s32 slotOffset;
    void* slotBase;

    child = mdlAllocModelObject(type, id);
    if ((flags & 1) != 0) {
        ((Model *)child)->flags |= 0x4000;
    }
    mdlAllocAuxBlock(child);
    {
        int tmp[2];
        tmp[0] = memory;
        tmp[1] = byteCount;
        mdlSetAuxPair(child, tmp);
    }
    mdlPrepareModel(child);
    slotOffset = (s32)(slotIndex & 0xFFFF) * 0xC;
    slotBase = (void*)(slotOffset + (s32)model);
    ((Model *)slotBase)->attachedWpns[0].wpnMdl = child;
    ((Model *)child)->flags |= 0x4;
    ((Model *)(u8*)((Model *)slotBase)->attachedWpns[0].wpnMdl)->flags |= 0x8000;
    ((Model *)slotBase)->attachedWpns[0].flags |= 0x1;
}

/* Attaches the model for type and id to slot data. Uses the existing object (flag 0x2000) or creates one from the id's name, then marks it and the slot. */
// FUN_0047AC90
void mdlAttachSlotModelFindOrCreate(void* model, u16 slotIndex, u32 type, u16 id, u32 flags)
{
    void* child;
    void* result;
    u8 buf[0x100];
    u32 slotOffset;
    void* slotBase;

    if (mdlFindModelObject(type, id, 0) == (void*)0) {
        mdlBuildModelPath(type, id, (char*)buf);
        child = mdlCreateModelObjectFromData(type, id, buf, flags);
        if (mdlQueryModelType(type, id) != 0) {
            mdlSetAuxValue(child, 1);
        }
        result = child;
        goto done;
    } else {
        child = mdlAllocModelObject(type, id);
        if ((flags & 1) != 0) {
            ((Model *)child)->flags |= 0x4000;
        }
        ((Model *)child)->flags |= 0x2000;
        mdlPrepareModel(child);
        result = child;
    }
done:
    slotOffset = (slotIndex & 0xFFFF) * 0xC;
    slotBase = (void*)mdlAddOffset(slotOffset, (u32)(u8*)model);
    ((Model *)slotBase)->attachedWpns[0].wpnMdl = result;
    ((Model *)result)->flags |= 4;
    ((Model *)(u8*)((Model *)slotBase)->attachedWpns[0].wpnMdl)->flags |= 0x8000;
    ((Model *)slotBase)->attachedWpns[0].flags |= 1;
}

/* Stores mode at +0x294 of the attached slot at input; slots are 12 bytes from +0x28C. */
// FUN_0047ADF0
void mdlSetAttachedSlotValue(u8 *model, u16 slotIndex, s32 frameId) {
    /* Offset added to the base, not the other way round: `model + slotOffset` makes
       mwcc emit `addu $v1,$a0,$v1` where retail has `addu $v1,$v1,$a0`. */
    s32 slotOffset = slotIndex * 12;
    u8 *slotBase = (u8 *)(slotOffset + (s32)model);

    ((Model *)slotBase)->attachedWpns[0].frameID = frameId;
}

/* Ported from P3FES mdlManager.c func_003196f0 (verified MATCH there). Keep the
   entryState/entryCount/pWpnMdl local structure and the recompute of entryCount+object before
   the post-call byte clear exactly; P4 offsets are wpnMdl ptr 0x290, flags byte
   0x28C, stride 0xC (donor used 0x3b8/0x3b4). */
/* Destroys the model in attached slot wpnIdx, clears its pointer and bit 0 of the slot flags at +0x28C. */
// FUN_0047AE10
void mdlDetachSlotModel(u8* model, u16 slotIndex)
{
    int slotAddress;
    int slotOffset;
    int* childSlot;

    slotAddress = (int)(u8*)model;
    slotOffset = (slotIndex & 0xffff) * 0xc;
    slotAddress = slotOffset;
    slotAddress += (int)(u8*)model;
    childSlot = (int*)(slotAddress + 0x290);
    if (*childSlot != 0)
    {
        mdlDestroyModelObject((u8*)*childSlot);
        *childSlot = 0;
        slotOffset = slotOffset + (int)(u8*)model;
        ((Model *)slotOffset)->attachedWpns[0].flags = ((Model *)slotOffset)->attachedWpns[0].flags & 0xfe;
    }
}

/* Returns 1 when attached slot index is empty; otherwise the result of mdlPrepareModel on its model. */
// FUN_0047AE90
s32 mdlPrepareSlotModel(u8 *model, u16 slotIndex)
{
    s32 off = slotIndex * 0xC;
    u8 *slotBase = (u8 *)(off + (s32)model);
    u8 *child;

    child = *(u8 * *)&((Model *)slotBase)->attachedWpns[0].wpnMdl;
    if (child == NULL) {
        return 1;
    }
    return mdlPrepareModel(child);
}

/* Ported from P3FES mdlManager.c func_003197c0 (verified MATCH there).
   P4 offsets: attachedWpns base 0x28C, wpnMdl ptr 0x290, stride 0xC (donor used
   0x3b4/0x3b8). The RwMatrix copy at wpnMdl+0x90 is 8 words. */
/* measured: removing the pragma regresses this MATCH (nd 0) to a re-mask/hoist
   mismatch; the struct-access spelling needs it to reproduce retail's andi re-mask. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Copies matrix into the +0x90 matrix of every attached slot model. */
// FUN_0047AEE0
void mdlSetAttachedModelMatrices(Model* model, RwMatrix* matrix)
{
    u16 slotIndex;
    int child;

    slotIndex = 0;
    for (; slotIndex < 5; slotIndex++)
    {
        child = (int)model->attachedWpns[slotIndex].wpnMdl;
        if (child != 0)
        {
            *(RwMatrix *)&((Model *)(u8*)(u32)child)->attachmentMatrix.right.x = *matrix;
        }
    }
}
#pragma pop

/* Allocates and clears the model's 0x48-byte chunk-loader and pending-request state. */
// FUN_0047AF60
void mdlAllocAuxBlock(void* model)
{
    void* loader;
    chkmemAllocSiteTag(D_00713138, 0x1769);
    loader = ((void* (*)(int, int))DAT_008873e8[0])(0x48, 0x40000);
    *(void* *)&((Model *)model)->auxiliary = loader;
    memset(loader, 0, 0x48);
}

/* Copies the two words of data into the auxiliary block at +0x2C and +0x30. */
// FUN_0047AFD0
void mdlSetAuxPair(void* model, void* pairData)
{
    void* loader = *(void* *)&((Model *)model)->auxiliary;
    *(u32 *)&((MdlLoaderState *)loader)->memory = *(u32*)pairData;
    ((MdlLoaderState *)loader)->memoryLength = ((MdlMemoryPair *)pairData)->byteCount;
}

/* Stores H_Cdvd_AcquireDirectory(data, 0) at +0x38 of the auxiliary block and clears its first word. */
// FUN_0047AFF0
void mdlSetAuxResource(void* model, void* path)
{
    void* loader = *(void* *)&((Model *)model)->auxiliary;
    func_00440b68(&D_007241d0, D_00713138, 0x1786);
    *(u32 *)&((MdlLoaderState *)loader)->fileRequest = (u32)H_Cdvd_AcquireDirectory((u8*)path, 0);
    *(u32 *)&((MdlLoaderState *)loader)->stream = 0;
}

/* Stores data at +0x40 of the auxiliary block. */
// FUN_0047B050
void mdlSetAuxValue(void* model, int value)
{
    ((MdlLoaderState *)(u8*)*(void* *)&((Model *)model)->auxiliary)->mode = value;
}

/* Frees the auxiliary block at +0x30C and its child at +0xC, then clears the pointer. */
// FUN_0047B060
void mdlFreeAuxBlock(void* model)
{
    /* measured: keep the auxiliary slot word-indexed; a typed slot
     * lvalue changes the whole-owner instruction comparison. */
    u32* modelWords = (u32*)model;
    void* loader = (void*)modelWords[0x30C / 4];
    if (*(void* *)&((MdlLoaderState *)loader)->uvRequests != 0) {
        DAT_008873ec[0](*(void* *)&((MdlLoaderState *)loader)->uvRequests);
    }
    DAT_008873ec[0]((void*)modelWords[0x30C / 4]);
    modelWords[0x30C / 4] = 0;
}

/* Recover the full chunk/effect headers and memory-stream descriptor, the
   selected clone wrappers, and the schema argument for both deferred UV reads.
   The typed candidate retains retail's 0xd0 frame but does not match yet.
   Native measurements and the complete relocation/data proof are recorded in
   docs/probe_archive/Model_loader_contracts_20261005_worker15.md.
   2026-10-08: the chunk dispatch is a switch whose case bodies follow in source order; b210 compares the cases in reverse (385 edits).
   The base-animation store is the out-of-line else arm (378 edits). */
/* Model stream loader. Stack locals and block declarations follow retail's
   frame; the 0xf0f000e1 attachment table is allocated inline with table,
   size and count declared before payload (retail s5/s4/s2, payload s3).
   opt_loop_invariants hoists the -1 fill and loop constants as retail does. */
#pragma push
#pragma opt_loop_invariants on
/* Material and UV headers share only the first entry-array pointer; the
 * eight-byte entries are indexed here without assuming either header extent. */
static inline void **mdlLoaderValueAt(void *table, u32 index)
{
    return &((MdlLoaderEntry *)*(u8 **)table)[index].value;
}

static inline MdlDispatchAnimEntry *mdlLoaderAnimEntry(MdlDispatchAnimTable *table, u32 slot)
{
    return &table->entries[slot];
}

static inline void mdlLoaderSetFrame(s32 value, MdlDispatchAnimTable *table, u32 slot, s32 which)
{
    mdlLoaderAnimEntry(table, slot)->startFrame[which] = value;
}

static inline void mdlLoaderSetAnimation(void *value, MdlDispatchAnimTable *table, u32 slot)
{
    mdlLoaderAnimEntry(table, slot)->animation = value;
}

/* Reads the aux block's RenderWare chunk stream, dispatching each chunk type to its loader: texture dictionaries, animation, UV dictionaries, effect lists and materials. Data not yet ready is queued as a request. Returns 1 once the stream is consumed. */
/* measured: keep the material/UV slot macros and callback-visible model resource checks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_0047B0C0
s32 mdlReadAuxChunks(u8 *model)
{





    struct MdlEffectChunk {
        u16 first, last;
        u32 length, skip, flags, unknown10;
    } effect;
    struct RwChunkHeaderInfo {
        u32 type, length, version, buildNum;
        s32 isComplex;
    } chunk;
    struct RwMemory {
        u8 *start;
        u32 length;
    } memory;
    s32 metadata;
    u16 capacity;
    u16 sourceIndex;
    u16 matrixCount;
    MdlLoaderState *state;
    MdlDispatchAnimTable *layerResource;
    s32 index;
    Model *modelObject = (Model *)model;
    extern void *func_003df3c0(void *stream, struct RwChunkHeaderInfo *header);
    extern u32 func_003e2910(void *stream, void *buffer, u32 length);
    extern void *func_003e2ce0(void *stream, u32 length);
    extern void *func_003e2f60(s32 type, s32 access, const void *memory);
    extern void *func_003c0f20(void *stream);
    extern void *func_003d53c0(void *stream);
    extern void *func_003d6350(void *schema, void *stream);
    extern struct RwTexDictionary *func_003dc370(void *stream);
    extern struct RwTexDictionary *func_003e6a90(void *stream);
    extern s32 func_003ef1b0(void *dictionary);
    /* H011: pointer parameters keep D_0070B610 an address constant per call;
       the u32 definition in rtanim.c makes b210 hoist it (measured MISMATCH). */
    extern u32 func_003d60e0(void *object, void *value);
    extern u8 *filerEnqueueRequest(s32 kind, const char *name, const char *path,
        s32 flags, s32 source, s32 buffer, s32 byteCount, const char *cacheName,
        const void *resultKind, s32 memoryKind);
    extern u32 mdlEffectListCreate(void);
    extern u32 *mdlEffectListAppendBlock(u32 **list, s32 source, u32 size, u16 matrixIndex, u32 flags);
    extern u32 *mdlEffectListAppendNode(u32 *list, u32 *sourceNode, u16 matrixIndex);
    extern u32 *mdlEffectListWrapCopy(s32 source, s32 size);
    extern s32 *mdlMatAnimCreateList(void);
    extern s32 mdlMatAnimLoadChunk(void *stream, u8 **list, u32 chunkTag, void *clump);
    extern u8 D_0070B610[];

#define LOAD_LAYER() ((MdlCloneLayer *)(model + 0xec + (u32)state->layer * 0xa4))
#define LOAD_MATERIALS() (*(MdlLoaderMaterialTable **)&modelObject->materialResource)
#define LOAD_UVS() (*(MdlLoaderUvTable **)&modelObject->animControl.resource)
#define LOAD_MEMORY() do { \
    u32 position = ((MdlMemoryStream *)(u8 *)state->stream)->position; \
    memory.start = state->memory + position; \
    memory.length = state->memoryLength - position; \
} while (0)

    state = *(MdlLoaderState * *)&((Model *)model)->auxiliary;
    capacity = 32;
    {
        u16 c;

        for (c = 0; c < 2; c++) {
            u16 *destination = &state->capacities[c];
            *destination = 32;
        }
    }
    while (func_003df3c0(state->stream, &chunk) != 0) {
        if (chunk.type == 0) {
            break;
        }
        switch (chunk.type) {

        case 0x16:
        if ((((Model *)model)->flags & 0x4000) != 0) {
            struct RwTexDictionary *dictionary = func_003e6a90(state->stream);
            func_003ef260(dictionary, K_Clump_AppendTextureName, &state->textureList);
            func_003ef1b0(dictionary);
        } else {
            LOAD_MEMORY();
            state->textureRequest = filerEnqueueRequest(8, 0, 0, 0,
                (s32)func_003e2f60(3, 1, &memory), 0, 0, 0, 0, 0);
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0x23:
        {
            struct RwTexDictionary *dictionary = func_003dc370(state->stream);
            func_003ef260(dictionary, K_Clump_AppendTextureName, &state->textureList);
            func_003ef1b0(dictionary);
        }
        continue;

        case 0x1b:
        {
            void *animation;
            if (LOAD_LAYER()->resource == 0) {
                MdlDispatchAnimTable *table = (MdlDispatchAnimTable *)mdlDispatchAnimTableCreate(capacity);
                LOAD_LAYER()->resource = table;
            }
            animation = func_003d53c0(state->stream);
            if (state->baseAnimation == 0 || LOAD_LAYER()->resource->unknown != 0) {
                layerResource = LOAD_LAYER()->resource;
                ((MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry)))->animation = animation;
            } else {
                LOAD_LAYER()->resource->unknown = (u32)animation;
            }
        }
        continue;

        case 0x2b:
        if ((((Model *)model)->flags & 0x4000) != 0) {
            void *dictionary;
            MdlLoaderUvTable *table = LOAD_UVS();
            if (table == 0) {
                u16 count = capacity;
                s32 size = (u32)count * sizeof(MdlLoaderEntry) + sizeof(MdlLoaderUvTable);
                chkmemAllocSiteTag(D_00713138, 0x908);
                table = ((void *(*)(int, int))DAT_008873e8[0])(size, 0x40000);
                memset(table, 0, size);
                table->entries = (MdlLoaderEntry *)(table + 1);
                table->count = count;
                table->references = 1;
                LOAD_UVS() = table;
            }
            dictionary = func_003d6350(D_0070B610, state->stream);
            if (((Model *)model)->clump == 0) {
                LOAD_UVS()->base = dictionary;
                func_003d60e0(D_0070B610, dictionary);
            } else {
                LOAD_UVS()->entries[state->slot].value = dictionary;
            }
        } else {
            if (state->clumpStream == 0 && state->clumpRequest == 0) {
                LOAD_MEMORY();
                state->uvRequest = filerEnqueueRequest(7, 0, 0, 0,
                    (s32)func_003e2f60(3, 1, &memory), 0, 0, 0, D_0070B610, 0);
            } else {
                if (state->uvRequests == 0) {
                    chkmemAllocSiteTag(D_00713138, 0x1834);
                    state->uvRequests = ((void *(*)(int, int))DAT_008873e8[0])((u32)capacity * 4, 0x40000);
                    memset(state->uvRequests, 0, (u32)capacity * 4);
                }
                LOAD_MEMORY();
                {
                    u8 *request = filerEnqueueRequest(7, 0, 0, 0,
                        (s32)func_003e2f60(3, 1, &memory), 0, 0, 0, D_0070B610, 0);
                    state->uvRequests[state->slot] = request;
                }
            }
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0x10:
        if ((((Model *)model)->flags & 0x4000) != 0) {
            if (modelObject->clump == 0) {
                void *clump = func_003c0f20(state->stream);
                ((Model *)model)->clump = clump;
            }
        } else {
            if (((Model *)model)->clump == 0 && state->clumpStream == 0 && state->clumpRequest == 0) {
                LOAD_MEMORY();
                state->clumpStream = func_003e2f60(3, 1, &memory);
            }
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0x1e:
            continue;
        case 0xf0f00001:
        if (LOAD_LAYER()->resource == 0) {
            MdlDispatchAnimTable *table = (MdlDispatchAnimTable *)mdlDispatchAnimTableCreate(capacity);
            LOAD_LAYER()->resource = table;
        }
        mdlLoaderSetAnimation(D_00922BC0_abs, LOAD_LAYER()->resource, state->slot);
        func_003e2ce0(state->stream, chunk.length);
        continue;

        case 0xf0f00005:
        if (LOAD_LAYER()->resource == 0) {
            MdlDispatchAnimTable *table = (MdlDispatchAnimTable *)mdlDispatchAnimTableCreate(capacity);
            LOAD_LAYER()->resource = table;
        }
        layerResource = LOAD_LAYER()->resource;
        func_003e2910(state->stream, &layerResource->entries[state->slot].matrix, chunk.length);
        continue;

        case 0xf0f00004:
        state->slot++;
        func_003e2ce0(state->stream, chunk.length);
        continue;

        case 0xf0f00002:
        state->layer++;
        state->slot = 0;
        func_003e2ce0(state->stream, chunk.length);
        continue;

        case 0xf0f00003:
        if ((((Model *)model)->flags & 0x4000) != 0) {
            MdlDispatchAnimTable *animations;
            MdlCloneAttachmentTable *attachments;
            func_003e2910(state->stream, &sourceIndex, chunk.length);
            {
                u16 src = sourceIndex;
                u16 dst = state->slot;

                animations = LOAD_LAYER()->resource;
                {
                    MdlDispatchAnimEntry *entries = animations->entries;

                    entries[dst].matrix = entries[src].matrix;
                }
                if (*(u32 *)&animations->entries[src].animation != 0) {
                    *(u32 *)&animations->entries[dst].animation = *(u32 *)&animations->entries[src].animation;
                }
                animations->entries[dst].unknown44 |= 1;
            }
            {
                MdlLoaderMaterialTable *materials = LOAD_MATERIALS();

                if (materials != 0 && materials->count > sourceIndex) {
                    void *value = *mdlLoaderValueAt(materials, sourceIndex);
                    if (value != 0) {
                        u16 dst = state->slot;

                        materials->entries[dst].value = value;
                        *(u8 *)&materials->entries[dst].flags |= 1;
                    }
                }
            }
            {
                MdlLoaderUvTable *uvs = LOAD_UVS();

                if (uvs != 0 && sourceIndex < uvs->count) {
                    void *value = *mdlLoaderValueAt(uvs, sourceIndex);
                    if (value != 0) {
                        u16 dst = state->slot;

                        uvs->entries[dst].value = value;
                        *(u8 *)&uvs->entries[dst].flags |= 1;
                    }
                }
            }
            attachments = LOAD_LAYER()->attachments;
            if (attachments != 0) {
                u16 source = sourceIndex;
                u16 destination = state->slot;
                if (attachments->primary[source] != 0) {
                    void *copy = mdlEffectListCopy(attachments->primary[source]);
                    attachments->primary[destination] = copy;
                }
                if (attachments->secondary[source] != 0) {
                    void *copy = mdlEffectListWrapShared(attachments->secondary[source]);
                    attachments->secondary[destination] = copy;
                }
            }
        } else {
            func_003e2910(state->stream, &sourceIndex, chunk.length);
            if ((((MdlLoaderState *)((u8 *)state + state->layer * 4))->cloneSlots[0]) == 0) {
                u16 slot;
                chkmemAllocSiteTag(D_00713138, 0x1896);
                (((MdlLoaderState *)((u8 *)state + state->layer * 4))->cloneSlots[0]) = ((void *(*)(int, int))DAT_008873e8[0])((u32)capacity * 2, 0x40000);
                for (slot = 0; slot < capacity; slot++) {
                    (((MdlLoaderState *)((u8 *)state + state->layer * 4))->cloneSlots[0])[slot] = -1;
                }
            }
            (((MdlLoaderState *)((u8 *)state + state->layer * 4))->cloneSlots[0])[state->slot] = sourceIndex;
        }
        continue;

        case 0xf0f00080:
        case 0xf0f00081:
        case 0xf0f00083:
        case 0xf0f00082:
        if ((((Model *)model)->flags & 0x4000) != 0) {
            MdlLoaderMaterialTable *table = LOAD_MATERIALS();
            if (table == 0) {
                u16 count = capacity;
                s32 size = (u32)count * sizeof(MdlLoaderEntry) + sizeof(MdlLoaderMaterialTable);
                chkmemAllocSiteTag(D_00713138, 0x850);
                table = ((void *(*)(int, int))DAT_008873e8[0])(size, 0x40000);
                memset(table, 0, size);
                table->entries = (MdlLoaderEntry *)(table + 1);
                table->count = count;
                table->references = 1;
                LOAD_MATERIALS() = table;
            }
            if (LOAD_MATERIALS()->entries[state->slot].value == 0) {
                s32 *material = mdlMatAnimCreateList();
                LOAD_MATERIALS()->entries[state->slot].value = material;
            }
            mdlMatAnimLoadChunk(state->stream, LOAD_MATERIALS()->entries[state->slot].value,
                chunk.type, ((Model *)model)->clump);
        } else {
            MdlLoaderMaterial *pending;
            chkmemAllocSiteTag(D_00713138, 0x18b7);
            pending = ((void *(*)(int, int))DAT_008873e8[0])(sizeof(*pending), 0x40000);
            LOAD_MEMORY();
            pending->kind = chunk.type;
            pending->slot = state->slot;
            pending->stream = func_003e2f60(3, 1, &memory);
            func_003e2ce0(state->stream, chunk.length);
            pending->next = state->materials;
            state->materials = pending;
        }
        continue;

        case 0xf0f00070:
        {
            void *properties;
            chkmemAllocSiteTag(D_00713138, 0x18c5);
            properties = ((void *(*)(int, int))DAT_008873e8[0])(0x2b8, 0x40000);
            func_003e2910(state->stream, properties, chunk.length);
            mdlBuildScaledSlotRecords(model, properties);
            DAT_008873ec[0](properties);
        }
        continue;

        case 0xf0f00006:
        {
            void *stream = state->stream;
            MdlMatrixEntry *entries;
            MdlMatrixTable *table;
            s32 slot;
            s32 size;
            func_003e2910(stream, &matrixCount, 2);
            size = (u32)matrixCount * sizeof(MdlMatrixEntry) + sizeof(MdlMatrixTable);
            chkmemAllocSiteTag(D_00713138, 0xc93);
            entries = ((void *(*)(int, int))DAT_008873e8[0])(size, 0x40000);
            table = (MdlMatrixTable *)(entries + matrixCount);
            table->count = matrixCount;
            table->unknown = 1;
            table->entries = entries;
            for (slot = 0; (u16)slot < matrixCount; slot = (slot + 1) & 0xffff) {
                u32 offset = (slot & 0xffff) * sizeof(MdlMatrixEntry);
                func_003e2910(stream, (u8 *)table->entries + offset + 0x40, 4);
                func_003e2910(stream, (u8 *)table->entries + offset + 0x44, 4);
                func_003e2910(stream, (u8 *)table->entries + offset, sizeof(RwMatrix));
            }
            *(MdlMatrixTable * *)&((Model *)model)->matrixTable = table;
        }
        continue;

        case 0xf0f000f0:
        func_003e2910(state->stream, &capacity, chunk.length);
        (((MdlLoaderState *)((u8 *)state + state->layer * 2))->capacities[0]) = capacity;
        continue;

        case 0xf0f000e0:
        {
            u32 **head;
            u8 *payload;
            u32 *node;
            u16 slot;
            func_003e2910(state->stream, &effect, sizeof(effect));
            func_003e2ce0(state->stream, effect.skip);
            payload = state->memory + ((MdlMemoryStream *)(u8 *)state->stream)->position;
            if (((Model *)model)->clump == 0 && state->clumpStream == 0) {
                if (modelObject->effects == 0) {
                    *(u32 *)&((Model *)model)->effects = mdlEffectListCreate();
                }
                head = *(u32 ** *)&((Model *)model)->effects;
            } else {
                if (LOAD_LAYER()->attachments == 0) {
                    MdlCloneAttachmentTable *table = mdlCloneAttachmentStorage(capacity);
                    LOAD_LAYER()->attachments = table;
                }
                if (LOAD_LAYER()->attachments->primary[state->slot] == 0) {
                    void *wrapper = (void *)mdlEffectListCreate();
                    LOAD_LAYER()->attachments->primary[state->slot] = wrapper;
                }
                head = LOAD_LAYER()->attachments->primary[state->slot];
            }
            node = mdlEffectListAppendBlock(head, (s32)payload, (s32)effect.length, effect.first, effect.flags);
            for (slot = effect.first + 1; slot < effect.last + 1; slot++) {
                mdlEffectListAppendNode((u32 *)head, node, slot);
            }
            func_003e2ce0(state->stream, effect.length);
        }
        continue;

        case 0xf0f000e1:
        {
            MdlCloneAttachmentTable *table;
            s32 size;
            u32 count;
            u8 *payload = state->memory + ((MdlMemoryStream *)(u8 *)state->stream)->position;
            if (LOAD_LAYER()->attachments == 0) {
                count = capacity;
                size = sizeof(MdlCloneAttachmentTable);
                size += count * sizeof(void*);
                size += count * sizeof(void*);
                chkmemAllocSiteTag(D_00713138, 0x1d6);
                table = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
                memset(table, 0, size);
                table->count.word = (u16)count;
                table->primary = (void**)(table + 1);
                table->secondary = table->primary + (u16)count;
                LOAD_LAYER()->attachments = table;
            }
            {
                u32 *wrapper = mdlEffectListWrapCopy((s32)payload, chunk.length);
                LOAD_LAYER()->attachments->secondary[state->slot] = wrapper;
            }
            func_003e2ce0(state->stream, chunk.length);
        }
        continue;

        case 0xf0f000d0:
        {
            u8 *group;
            u16 slot;
            chkmemAllocSiteTag(D_00713138, 0xfa);
            group = ((void *(*)(int, int))DAT_008873e8[0])(0x4c, 0x40000);
            memset(group, 0, 0x4c);
            ((MdlDirectionalBlend *)group)->weight = 1.0f;
            ((MdlDirectionalBlend *)group)->progress = 1.0f;
            layerResource = LOAD_LAYER()->resource;
            ((MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry)))->blendControl = group;
            layerResource = LOAD_LAYER()->resource;
            func_003e2910(state->stream, ((MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry)))->blendControl + 0x3c,
                chunk.length);
            for (slot = 0; slot < 4; slot++) {
                func_003df3c0(state->stream, &chunk);
                {
                    void *animation = func_003d53c0(state->stream);
                    layerResource = LOAD_LAYER()->resource;
                    ((void **)((MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry)))->blendControl)[slot] = animation;
                }
            }
        }
        continue;

        case 0xf0f00007:
        case 0xf0f00008:
        func_003e2910(state->stream, &metadata, chunk.length);
        layerResource = LOAD_LAYER()->resource;
        if (((MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry)))->startFrame == 0) {
            s32 *values;
            chkmemAllocSiteTag(D_00713138, 0x125);
            values = ((void *(*)(int, int))DAT_008873e8[0])(8, 0x40000);
            memset(values, 0, 8);
            layerResource = LOAD_LAYER()->resource;
            ((MdlDispatchAnimEntry *)((u8 *)layerResource->entries + (state->slot) * sizeof(MdlDispatchAnimEntry)))->startFrame = values;
        }
        if (chunk.type == 0xf0f00007) {
            mdlLoaderSetFrame(metadata, LOAD_LAYER()->resource, state->slot, 0);
        } else {
            mdlLoaderSetFrame(metadata, LOAD_LAYER()->resource, state->slot, 1);
        }
        continue;

        case 0xf0f00009:
        state->baseAnimation = 1;
        func_003e2ce0(state->stream, chunk.length);
        continue;

        default:
        func_003e2ce0(state->stream, chunk.length);
        }
    }
#undef LOAD_MEMORY
#undef LOAD_UVS
#undef LOAD_MATERIALS
#undef LOAD_LAYER
    return 1;
}

#pragma pop



extern u8 *filerTakeCompletedRequest(u8 *request, s32 *completed, s32 *resultValue);
extern s32 func_003ef1b0(void* dictionary);
extern s32 func_003e2e40(void* stream, void* data);
extern void* func_003d60e0(void* object, void* value);
extern u8 *filerEnqueueRequest(s32 kind, const char *name, const char *path,
    s32 flags, s32 source, s32 buffer, s32 byteCount, const char *cacheName,
    s32 resultKind, s32 memoryKind);
extern s32 *mdlMatAnimCreateList(void);
extern s32 mdlMatAnimLoadChunk(void *stream, u8 **list, u32 chunkTag, void *clump);
extern u8 D_0070B610[];
/* Native b210 O2 MATCH: 1944B/window 1952B; the remaining eight bytes are zero.
   Poll results retain their real pointer type and their status/stream outputs.
   Copy the RwMatrix value, reload entry storage after writes and callbacks,
   and dereference the two effect-list pointer arrays at offsets 0x14/0x20.
   Full-width iteration and independently narrowed asset indices are distinct.
   Prior probe notes and native receipts are retained in model-manager-after-rebase. */
#pragma push
#pragma opt_propagation off
/* Polls the aux block's pending resources: the primary and secondary texture dictionaries, the request table, the pending clump and the node list. Attaches each one that is ready. When all are ready it copies each layer's keyframe maps. Returns 1 when everything is ready, 0 while any request is pending. */
/* measured: keep the request/resource snapshots and pointer-array destinations across load callbacks
 * byte-addressed: access-site typing/indexed alternatives change the
 * whole-owner instruction/size comparison. Other proven fields are typed. */
// FUN_0047C660
s32 mdlPollAuxResources(u8 *model)
{
    u8 *secondaryResult;
    u8 *primaryResult;
    u8 *loader;
    u8 *resourceTable;
    u32 layerIndex;
    s32 allReady;
    s32 textureReady;
    s32 baseUvReady;
    u32 allocationSize;
    u32 requestIndex;
    u8 *materialRequest;
    u32 slotIndex;
    u8 *nextRequest;
    u8 *entryResult;
    u8 *clumpResult;
    struct { s32 ready; s32 handle; } requestResult;
    u16 entryCount;
    s32 sourceMapIndex;
    s16 checkedMap;
    u32 sourceIndex;
    u32 destinationIndex;
    s32 sourceOffset;
    s32 destinationOffset;
    u8 *sourceEntry;
    u8 *destinationEntry;
    u32 animation;
    u8 *attachments;
    u8 *mapFields;
    u8 *slotMap;
    u8 *capacityFields;
    u8 *layerBase;
    u8 *resource;
    u8 *entryData;
    u8 **slotMapPointer;
    s32 sourcePointerOffset;
    s32 destinationPointerOffset;
    s32 pendingSource;
    u8 *requestTable;
    u8 *pendingRequest;
    u32 requestByteOffset;
    u32 resourceEntryOffset;
    s32 checkedByteOffset;
    Model *modelObject = (Model *)model;
    MdlLoaderState *loaderState;
    MdlLoaderMaterial *material;
    MdlLoaderState *mappedLoader;
    MdlCloneAttachmentTable *attachmentTable;

    loader = ((Model *)model)->auxiliary;
    loaderState = (MdlLoaderState *)loader;
    allReady = 1;
    textureReady = 1;
    baseUvReady = 1;
    if (*(u32 *)&loaderState->textureRequest != 0) {
        primaryResult = filerTakeCompletedRequest(loaderState->textureRequest, &requestResult.ready, &requestResult.handle);
        if (requestResult.ready == 1) {
            func_003ef260((const struct RwTexDictionary *)primaryResult, K_Clump_AppendTextureName, loader + 0x34);
            func_003ef1b0((void *)primaryResult);
            func_003e2e40((void *)requestResult.handle, 0);
            *(u32 *)&((MdlLoaderState *)loader)->textureRequest = 0;
        } else {
            textureReady = 0;
            allReady = 0;
        }
    }
    if (*(u32 *)&loaderState->uvRequest != 0) {
        secondaryResult = filerTakeCompletedRequest(loaderState->uvRequest, &requestResult.ready, &requestResult.handle);
        if (requestResult.ready == 1) {
            if (modelObject->animControl.resource == 0) {
                entryCount = ((MdlLoaderState *)loader)->capacities[0];
                allocationSize = (u32)entryCount * 8 + 0x10;
                chkmemAllocSiteTag(D_00713138, 0x908);
                resourceTable = ((void *(*)(int, int))DAT_008873e8[0])((int)allocationSize, 0x40000);
                memset(resourceTable, 0, (int)allocationSize);
                *(u8 * *)&((MdlAnimResource *)resourceTable)->entries = resourceTable + 0x10;
                ((MdlAnimResource *)resourceTable)->count = entryCount;
                ((MdlAnimResource *)resourceTable)->references = 1;
                *(u8 * *)&((Model *)model)->animControl.resource = resourceTable;
            }
            ((MdlAnimResource *)*(u8 * *)&((Model *)model)->animControl.resource)->unknown04 = (u32)secondaryResult;
            func_003d60e0(D_0070B610, secondaryResult);
            func_003e2e40((void *)requestResult.handle, 0);
            *(u32 *)&((MdlLoaderState *)loader)->uvRequest = 0;
        } else {
            allReady = 0;
            baseUvReady = 0;
        }
    }
    if (*(u32 *)&loaderState->uvRequests != 0) {
        requestIndex = 0;
        while (requestIndex < loaderState->capacities[0]) {
            requestTable = *(u8 **)&loaderState->uvRequests;
            requestByteOffset = requestIndex * 4;
            pendingRequest = ((u8 **)requestTable)[requestIndex];
            if (pendingRequest != 0) {
                entryResult = filerTakeCompletedRequest(pendingRequest, &requestResult.ready, &requestResult.handle);
                if (requestResult.ready == 1) {
                    if (modelObject->animControl.resource == 0) {
                        entryCount = ((MdlLoaderState *)loader)->capacities[0];
                        allocationSize = (u32)entryCount * 8 + 0x10;
                        chkmemAllocSiteTag(D_00713138, 0x908);
                        resourceTable = ((void *(*)(int, int))DAT_008873e8[0])((int)allocationSize, 0x40000);
                        memset(resourceTable, 0, (int)allocationSize);
                        *(u8 * *)&((MdlAnimResource *)resourceTable)->entries = resourceTable + 0x10;
                        ((MdlAnimResource *)resourceTable)->count = entryCount;
                        ((MdlAnimResource *)resourceTable)->references = 1;
                        *(u8 * *)&((Model *)model)->animControl.resource = resourceTable;
                    }
                    resource = *(u8 * *)&((Model *)model)->animControl.resource;
                    resourceEntryOffset = (u16)requestIndex * 8;
                    *(u32 *)&((MdlLoaderEntry *)(*(u8 **)resource + resourceEntryOffset))->value = (u32)entryResult;
                    func_003e2e40((void *)requestResult.handle, 0);
                    ((u32 *)loaderState->uvRequests)[requestIndex] = 0;
                } else {
                    allReady = 0;
                }
            }
            requestIndex++;
        }
    }
    pendingSource = *(s32 *)&loaderState->clumpStream;
    if (pendingSource != 0 || *(u32 *)&((MdlLoaderState *)loader)->clumpRequest != 0) {
        if (textureReady == 1 && baseUvReady == 1) {
            if (pendingSource != 0) {
                *(u32 *)&((MdlLoaderState *)loader)->clumpRequest = (u32)filerEnqueueRequest(2, 0, 0, 0, pendingSource, 0, 0, 0, 0, 0);
                *(u32 *)&((MdlLoaderState *)loader)->clumpStream = 0;
                allReady = 0;
            } else {
                clumpResult = filerTakeCompletedRequest(loaderState->clumpRequest, &requestResult.ready, &requestResult.handle);
                if (requestResult.ready == 1) {
                    *(u32 *)&((Model *)model)->clump = (u32)clumpResult;
                    func_003e2e40((void *)requestResult.handle, 0);
                    *(u32 *)&((MdlLoaderState *)loader)->clumpRequest = 0;
                } else {
                    allReady = 0;
                }
            }
        } else {
            allReady = 0;
        }
    }
    materialRequest = *(u8 **)&loaderState->materials;
    if (materialRequest != 0) {
        if (modelObject->clump != 0) {
            while (materialRequest != 0) {
                material = (MdlLoaderMaterial *)materialRequest;
                if (modelObject->materialResource == 0) {
                    entryCount = ((MdlLoaderState *)loader)->capacities[0];
                    allocationSize = (u32)entryCount * 8 + 8;
                    chkmemAllocSiteTag(D_00713138, 0x850);
                    resourceTable = ((void *(*)(int, int))DAT_008873e8[0])((int)allocationSize, 0x40000);
                    memset(resourceTable, 0, (int)allocationSize);
                    *(u8 * *)&((MdlAnimEntryTable *)resourceTable)->entries = resourceTable + 8;
                    ((MdlAnimEntryTable *)resourceTable)->count = entryCount;
                    ((MdlAnimEntryTable *)resourceTable)->references = 1;
                    *(u8 * *)&((Model *)model)->materialResource = resourceTable;
                }
                if (((MdlLoaderEntry *)*(u8 **)modelObject->materialResource)[material->slot].value == 0) {
                    *(u32 *)&((MdlLoaderEntry *)*(u8 **)modelObject->materialResource)[material->slot].value = (u32)mdlMatAnimCreateList();
                }
                mdlMatAnimLoadChunk(material->stream, (u8 **)((MdlLoaderEntry *)*(u8 **)modelObject->materialResource)[material->slot].value, ((MdlLoaderMaterial *)materialRequest)->kind, ((Model *)model)->clump);
                func_003e2e40(((MdlLoaderMaterial *)materialRequest)->stream, 0);
                nextRequest = *(u8 * *)&((MdlLoaderMaterial *)materialRequest)->next;
                DAT_008873ec[0](materialRequest);
                materialRequest = nextRequest;
            }
            *(u8 * *)&((MdlLoaderState *)loader)->materials = 0;
        } else {
            allReady = 0;
        }
    }
    if (allReady == 1) {
        layerIndex = 0;
        while (layerIndex < 2) {
            mapFields = loader + layerIndex * 4;
            mappedLoader = (MdlLoaderState *)mapFields;
            slotMapPointer = (u8 **)(mapFields + 0x24);
            if (mappedLoader->cloneSlots[0] != 0) {
                slotIndex = 0;
                layerBase = model + layerIndex * 0xA4;
                capacityFields = loader + layerIndex * 2;
                while (slotIndex < ((MdlLoaderState *)capacityFields)->capacities[0]) {
                    slotMap = *(u8 * *)&((MdlLoaderState *)mapFields)->cloneSlots[0];
                    sourceMapIndex = ((s16 *)slotMap)[slotIndex];
                    if (sourceMapIndex != -1) {
                        resource = *(u8 * *)&((Model *)layerBase)->layers[0].resource;
                        entryData = *(u8 **)resource;
                        sourceIndex = (u16)sourceMapIndex;
                        sourceOffset = sourceIndex * 0x50;
                        destinationIndex = (u16)slotIndex;
                        destinationOffset = destinationIndex * 0x50;
                        sourceEntry = entryData + sourceOffset;
                        destinationEntry = entryData + destinationOffset;
                        *(RwMatrix*)destinationEntry = *(RwMatrix*)sourceEntry;
                        entryData = *(u8 **)resource;
                        animation = *(u32 *)&((MdlDispatchAnimEntry *)(entryData + sourceOffset))->animation;
                        if (animation != 0) {
                            *(u32 *)&((MdlDispatchAnimEntry *)(entryData + destinationOffset))->animation = animation;
                        }
                        entryData = *(u8 **)resource;
                        ((MdlDispatchAnimEntry *)(entryData + destinationOffset))->unknown44 |= 1;
                        if (layerIndex == 0) {
                            resource = *(u8 * *)&((Model *)model)->materialResource;
                            if (resource != 0) {
                                checkedMap = (s16)sourceMapIndex;
                                if (checkedMap < (s64)(u32)((MdlAnimEntryTable *)resource)->count) {
                                    checkedByteOffset = checkedMap * 8;
                                    entryData = *(u8 **)resource;
                                    if (*(u32 *)&((MdlLoaderEntry *)(entryData + checkedByteOffset))->value != 0) {
                                        destinationPointerOffset = (u16)slotIndex * 8;
                                        *(u32 *)&((MdlLoaderEntry *)(entryData + destinationPointerOffset))->value = *(u32 *)&((MdlLoaderEntry *)(entryData + sourceIndex * 8))->value;
                                        entryData = *(u8 **)resource;
                                        *(u8 *)&((MdlLoaderEntry *)(entryData + destinationPointerOffset))->flags |= 1;
                                    }
                                }
                            }
                            resource = *(u8 * *)&((Model *)model)->animControl.resource;
                            if (resource != 0) {
                                checkedMap = (s16)sourceMapIndex;
                                if (checkedMap < (s64)(u32)((MdlAnimResource *)resource)->count) {
                                    checkedByteOffset = checkedMap * 8;
                                    entryData = *(u8 **)resource;
                                    if (*(u32 *)&((MdlLoaderEntry *)(entryData + checkedByteOffset))->value != 0) {
                                        destinationPointerOffset = (u16)slotIndex * 8;
                                        *(u32 *)&((MdlLoaderEntry *)(entryData + destinationPointerOffset))->value = *(u32 *)&((MdlLoaderEntry *)(entryData + sourceIndex * 8))->value;
                                        entryData = *(u8 **)resource;
                                        *(u8 *)&((MdlLoaderEntry *)(entryData + destinationPointerOffset))->flags |= 1;
                                    }
                                }
                            }
                            attachments = *(u8 * *)&((Model *)layerBase)->layers[0].attachments;
                            if (attachments != 0) {
                                attachmentTable = (MdlCloneAttachmentTable *)attachments;
                                entryData = *(u8 **)&attachmentTable->primary;
                                sourcePointerOffset = sourceIndex * 4;
                                if (*(u32 * *)&((MdlLoaderEntry *)(entryData + sourcePointerOffset))->value != 0) {
                                    ((u32 **)attachmentTable->primary)[destinationIndex] =
                                        mdlEffectListCopy(*(u32 ** *)&((MdlLoaderEntry *)(entryData + sourcePointerOffset))->value);
                                }
                                entryData = *(u8 **)&attachmentTable->secondary;
                                if (*(u32 * *)&((MdlLoaderEntry *)(entryData + sourcePointerOffset))->value != 0) {
                                    ((u32 **)attachmentTable->secondary)[destinationIndex] =
                                        mdlEffectListWrapShared(*(u32 ** *)&((MdlLoaderEntry *)(entryData + sourcePointerOffset))->value);
                                }
                            }
                        }
                    }
                    slotIndex++;
                }
                DAT_008873ec[0](*slotMapPointer);
            }
            layerIndex++;
        }
    }
    return allReady;
}

#pragma pop
