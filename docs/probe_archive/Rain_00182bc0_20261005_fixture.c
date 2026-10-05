/* SDK producer stubs and independent observable rain scenarios. */
#define CHECK(condition) do { checks++; if (!(condition)) native32_failure(__LINE__, scenario, #condition); } while (0)
#define WORD(offset) (*(s32 *)(work + (offset)))
#define FLOAT(offset) (*(f32 *)(work + (offset)))
#define PTR(type, offset) (*(type **)(work + (offset)))

struct RpAtomic { u8 bytes[128]; } atomic;
struct RwFrame { u8 bytes[128]; } frame;
struct RpMaterial { u32 identity; } material;
struct RwTexture { u8 bytes[128]; } texture;
struct RwTexDictionary { u32 identity; } dictionary;
static struct RpMaterial *materials[1];
static _Alignas(16) u8 geometry[128], plugin[0x100], camera[0x100];
static _Alignas(16) u8 work[0x78], task[0x40], renderNode[0x30];
static _Alignas(16) u8 arena[32768], alternatePool[4096];
static _Alignas(16) u8 matrices[8 * 80], colors[8 * 8];
static RainMatrix cameraMatrix, outputMatrix, replacementMatrix;
static RainDrop drops[2];
static f32 motion[2][4];
static s32 timers[2];
static unsigned scenario, checks, calls, allocated, allocations, oldAllocatorCalls;
static unsigned rngIndex, changeSpacing, swapPool, swapMatrix;
static RainDrop *initialPool;

u8 D_005F1D80[32], D_005F1D10[24], D_005F1D70[16], D_00794420[8];
f32 fGpffff815c = 1.0f, fGpffff8198 = 0.25f, fGpffff841c = 1.0f;
s32 iGpffffb610 = 0x20;
static void *allocateNext(size_t count, size_t size, u32 hint);
static void *allocateFirst(size_t count, size_t size, u32 hint);
void *(*D_008873F4[])(size_t, size_t, u32) = {allocateFirst};

static void identity(RainMatrix *matrix) {
    memset(matrix, 0, sizeof(*matrix));
    matrix->right.x = matrix->up.y = matrix->at.z = 1.0f;
    matrix->flags = 0x20003;
}
static void *allocateNext(size_t count, size_t size, u32 hint) {
    void *result;
    CHECK(hint == 0x40000);
    CHECK(allocated + count * size <= sizeof(arena));
    result = arena + allocated;
    allocated += (count * size + 15) & ~15u;
    memset(result, 0, count * size);
    allocations++;
    if (allocations == 2 && swapPool) {
        initialPool = PTR(RainDrop, 0x5c);
        memcpy(alternatePool, initialPool, WORD(0x40) * sizeof(RainDrop));
        PTR(u8, 0x5c) = alternatePool;
    }
    return result;
}
static void *allocateFirst(size_t count, size_t size, u32 hint) {
    oldAllocatorCalls++;
    D_008873F4[0] = allocateNext;
    return allocateNext(count, size, hint);
}
s32 func_00457120(void) { calls++; return (s32)(uintptr_t)camera; }
RainMatrix *func_003e9700(struct RwFrame *value) {
    CHECK(value == &frame); calls++; return &cameraMatrix;
}
u32 RpRandom(void) {
    unsigned index = rngIndex++;
    calls++;
    if (changeSpacing && index == 0) FLOAT(0x20) = 8.0f;
    return changeSpacing && index < 2 ? 1 : 0;
}
struct RpAtomic *func_003a2340(s32 count, u32 flags, u32 platform) {
    CHECK(count == WORD(0x40) * WORD(0x2c));
    CHECK(flags == 0x2008000a && platform == 0); calls++;
    return &atomic;
}
struct RwFrame *func_003e9320(void) { calls++; return &frame; }
struct RpAtomic *RpAtomicSetFrame(struct RpAtomic *value, struct RwFrame *valueFrame) {
    CHECK(value == &atomic && valueFrame == &frame); calls++; return value;
}
s32 func_003a2950(struct RpAtomic *value, enum RpPTankSkyRenderState state, u32 bits) {
    CHECK(value == &atomic);
    CHECK((state == 1 && bits == 0x44) || (state == 2 && bits == 0x717fb)); calls++; return 1;
}
RwTexDictionary *func_003ef6d0(void) { calls++; return &dictionary; }
RwTexture *func_003ef650(RwTexDictionary *value, const char *name) {
    CHECK(value == &dictionary && name == (const char *)D_005F1D10); calls++; return &texture;
}
struct RpMaterial *func_003c42b0(struct RpMaterial *value, RwTexture *valueTexture) {
    CHECK(value == &material && valueTexture == &texture); calls++; return value;
}
RainMatrix *func_003e0f80(void) { calls++; identity(&outputMatrix); return &outputMatrix; }
f32 cosf(f32 value) { CHECK(value == fGpffff815c); calls++; return 0.0f; }
f32 sinf(f32 value) { CHECK(value == fGpffff815c); calls++; return 1.0f; }
void func_0044ea90(const void *file, s32 line) {
    CHECK(file == D_005F1D80 && (line == 0x9d || line == 0xa2 || line == 0xa6)); calls++;
}
f32 RwV3dNormalize(RainVector *out, const RainVector *in) {
    CHECK(out == in);
    CHECK(in->x * in->x + in->y * in->y + in->z * in->z == 1.0f); calls++; return 1.0f;
}
RainMatrix *RwMatrixScale(RainMatrix *out, const RainVector *scale, enum RwOpCombineType combine) {
    CHECK(combine == rwCOMBINEPOSTCONCAT);
    CHECK(scale == (RainVector *)(work + 0x68)); calls++;
    out->right.x *= scale->x; out->up.y *= scale->y; out->at.z *= scale->z;
    if (swapMatrix && out != &replacementMatrix) {
        replacementMatrix = *out;
        PTR(RainMatrix, 0x10) = &replacementMatrix;
    }
    return out;
}
s32 func_003a2770(struct RpAtomic *value, RainLock *lock, u32 flags, enum RpPTankLockFlags mode) {
    CHECK(value == &atomic && mode == rpPTANKLOCKWRITE); calls++;
    CHECK(flags == 8 || flags == 2);
    lock->data = flags == 8 ? matrices : colors;
    lock->stride = flags == 8 ? 80 : 8;
    return 1;
}
struct RpAtomic *func_003a2920(struct RpAtomic *value) { CHECK(value == &atomic); calls++; return value; }
u8 *func_00460d80(u8 *list, s32 payload) {
    CHECK(list == D_00794420 && payload == (s32)(uintptr_t)&atomic); calls++; return renderNode;
}
void func_00182b40(void) { calls++; }

static void reset(void) {
    memset(work, 0, sizeof(work)); memset(task, 0, sizeof(task));
    memset(camera, 0, sizeof(camera)); memset(plugin, 0, sizeof(plugin));
    memset(&atomic, 0, sizeof(atomic)); memset(&frame, 0, sizeof(frame));
    memset(drops, 0, sizeof(drops)); memset(motion, 0, sizeof(motion));
    memset(renderNode, 0, sizeof(renderNode)); memset(arena, 0, sizeof(arena));
    memset(alternatePool, 0, sizeof(alternatePool));
    memset(matrices, 0xa5, sizeof(matrices)); memset(colors, 0xa5, sizeof(colors));
    calls = allocated = allocations = oldAllocatorCalls = rngIndex = 0;
    changeSpacing = swapPool = swapMatrix = 0; initialPool = NULL;
    D_008873F4[0] = allocateFirst;
    *(u8 **)(task + 0x38) = work;
    *(struct RwFrame **)(camera + 4) = &frame;
    *(f32 *)(camera + 0x68) = 1.0f; *(f32 *)(camera + 0x6c) = 0.5f;
    *(u8 **)(atomic.bytes + 0x18) = geometry;
    *(u8 **)(atomic.bytes + 0x20) = plugin;
    materials[0] = &material; *(struct RpMaterial ***)(geometry + 0x20) = materials;
    WORD(0x2c) = 3; WORD(0x30) = 8; WORD(0x24) = 100;
    FLOAT(0x14) = 0.5f; FLOAT(0x18) = 10.0f; FLOAT(0x1c) = 6.0f; FLOAT(0x20) = 4.0f;
    FLOAT(0x68) = FLOAT(0x6c) = FLOAT(0x70) = 4.0f;
    identity(&cameraMatrix); identity(&outputMatrix); identity(&replacementMatrix);
    cameraMatrix.pos.x = 1; cameraMatrix.pos.y = 2; cameraMatrix.pos.z = 3;
}
static void prepare_update(void) {
    reset(); WORD(0) = 1; WORD(0x34) = 1; WORD(0x40) = 1; WORD(0x3c) = 2;
    PTR(struct RpAtomic, 8) = &atomic; PTR(RainMatrix, 0x10) = &outputMatrix;
    PTR(s32, 0x38) = timers; PTR(RainDrop, 0x5c) = drops;
    timers[0] = 3;
    FLOAT(0x18) = 7; FLOAT(0x48) = 10; FLOAT(0x4c) = 20; FLOAT(0x64) = 3;
    drops[0].active = 1; drops[0].count = 2; drops[0].x = 3; drops[0].motion = motion[0];
    motion[0][0] = 2; motion[0][1] = 5;
}
int main(void) {
    RainMatrix *head = (RainMatrix *)matrices;
    RainMatrix *tail = (RainMatrix *)(matrices + 80);
    CHECK(sizeof(RainVector) == 12 && sizeof(RainMatrix) == 64 && sizeof(RainDrop) == 16 && sizeof(RainLock) == 8);
    scenario = 1; reset(); WORD(4) = 1;
    CHECK(func_00182bc0(task) == 0 && calls == 0);
    scenario = 2; reset(); WORD(0) = 17;
    CHECK(func_00182bc0(task) == 0 && calls == 0);
    scenario = 3; reset(); swapPool = 1;
    CHECK(func_00182bc0(task) == 0);
    CHECK(WORD(0) == 1 && WORD(0x34) == 6 && WORD(0x40) == 48);
    CHECK(oldAllocatorCalls == 1 && allocations == 50);
    CHECK(PTR(u8, 0x5c) == alternatePool && initialPool[0].motion == NULL);
    CHECK(((RainDrop *)alternatePool)[0].motion != NULL);
    CHECK(FLOAT(0x54) == 20 && FLOAT(0x58) == 10 && FLOAT(0x4c) == 10);
    CHECK(PTR(RainMatrix, 0x10) == &outputMatrix && *(s32 *)(plugin + 4) == 0);
    scenario = 4; prepare_update(); swapMatrix = 1;
    CHECK(func_00182bc0(task) == 0);
    CHECK(timers[0] == 2 && WORD(0x74) == 2 && *(s32 *)(plugin + 4) == 2);
    CHECK(head->pos.x == 8 && head->pos.y == 17 && head->pos.z == 10);
    CHECK(tail->pos.x == 8 && tail->pos.y == 19 && tail->pos.z == 10);
    CHECK(motion[0][0] == 3 && motion[0][1] == 1 && motion[0][2] == 0);
    CHECK(colors[0] == 255 && colors[3] == 100 && colors[11] == 95);
    CHECK(matrices[64] == 0xa5 && colors[4] == 0xa5 && matrices[160] == 0xa5);
    CHECK(*(void (**)(void))(renderNode + 8) == func_00182b40);
    scenario = 5; prepare_update(); motion[0][1] = 100;
    CHECK(func_00182bc0(task) == 0);
    CHECK(drops[0].active == 0 && WORD(0x74) == 2);
    CHECK(motion[0][0] == 0 && motion[0][1] == 0 && motion[0][2] == 0 && motion[0][3] == 0);
    scenario = 6; prepare_update(); drops[0].active = 0; timers[0] = 0; changeSpacing = 1;
    CHECK(func_00182bc0(task) == 0);
    CHECK(drops[0].count == 2 && drops[0].x == -1.0f && FLOAT(0x20) == 8.0f);
    CHECK(WORD(0x74) == 2 && timers[0] == 8 && rngIndex == 4);
    native32_text("rain scenarios=6 checks="); native32_number(checks); native32_text("\n");
    return 0;
}
