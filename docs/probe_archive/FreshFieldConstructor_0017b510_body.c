/* Exact field task constructor recovery, func_0017b510.
 * Owner: src/promoted/code1_0017.c. Main independently resolved all 48 relocations:
 * 1148 executable bytes equal retail, followed by four zero alignment bytes.
 * All 76 other owner functions preserve instruction bytes and relocation lists.
 * Both callers in code1_0014.c now accept/store the task as a pointer; all 126
 * compiled functions in that caller owner remain byte/relocation identical.
 * 
 * The corrected first candidate measured1112/1152 bytes,750 differing bytes.
 * Independent measured agent ownership closed it with scoped loop invariants on,
 * propagation off, allocator/mode/resource slot pointers, full first-node vector
 * snapshots, retail switch ordering, integer direction words, and the real
 * u64-plus-f32 constant copy (0,150,-150). No invented padding or inputs.
 * The full original32-bit ID is forwarded to lookup; only dispatch is narrowed.
 * 
 * Both batch references were consulted: IDA src/promoted/code1_0017.c:642-771,
 * Ghidra counterpart:582-703. IDA's qword+float split reflects actual retail loads.
 * Its texture-create second argument is spurious. The reversed ABS comparison
 * is equivalent for ordered finite values, not a general IEEE NaN equivalence.
 * Retail code and target compiler lowering are authoritative.
 * 
 * The sdkTask provider returns void*. The owner's established callback-pointer
 * projection remains; sdkTask's wrapper itself expresses callback/data slots as
 * s32 target words. Do not misreport the two declarations as textually identical.
 * A diagnostic using that raw-word declaration and explicit callback-address
 * casts retained1148 bytes but moved the callback address loads (26 differing
 * bytes); it was not promoted. RwCameraSetFrame takes two pointers. The historical
 * M2C texture setter candidate is not a reliable canonical API declaration.
 * 
 * Actual integrated source passed196608 guarded Wasm32 cases with UB,
 * float-cast-overflow and float-divide-by-zero sanitizer traps: six modes,
 * zero-to-three list nodes, high-bit IDs, initial allocation failure, optional
 * NULL color raster, and32 combinations of callback-time texture/frame/camera/
 * raster pointer mutations. Entire0xE0 data, allocation contents, surrounding
 * canaries, resource selections, and returned task are checked independently.
 * Scene/allocation/RW calls are deterministic boundaries, not real rendering.
 * 
 * Calloc zero-fill is required on untouched fields;0x40000 is flags, not alignment.
 * Retail failure fallthroughs are preserved, not repaired: failed secondary
 * allocation, texture/camera/z-raster creation, or object lookup can lead to null
 * dereferences after returning diagnostics. Those invalid paths are not claimed
 * as defined-C runtime coverage. No invented zero-fill for unwritten stack data.
 *
 */

extern u8 D_005F18C0[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 flags);
extern void *func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c, void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 arg0, void *arg1);
extern void *func_003ef080(void *texture, void *raster);
extern void func_003ef3a0(u8 *arg0);
extern void func_003efd20(u8 *camera, u8 *frame);
extern u8 D_005F18D0[];
extern const u64 D_005F18B0;
extern const f32 D_005F18B8;
extern u8 *func_003ef2e0(void *raster);
extern u8 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003e84a0(void);
extern u8 *func_003e9320(void);
extern void *func_003e9df0(void *frame);
extern void *func_003e8310(void *camera, s32 projection);
extern void func_001790a0(void *camera);
extern void *func_003cbc10(s32 world, void *camera);
extern u8 *func_00145270(s32 id);
extern void func_0017acc0(u8 *task);
#pragma opt_loop_invariants on
#pragma opt_propagation off
void *func_0017b510(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *data;
    void *task;
    u8 *node;
    s32 i;
    u8 **texture;
    u8 *raster;
    u8 *camera;
    u8 *zRaster;
    u8 *obj;
    Vec3_00178590 pos;
    u8 *(**table)(s32, s32, s32);
    u16 *mode;

    i = 0;
    func_0044ea90(D_005F18C0, 0x5E6);
    table = D_008873F4;
    data = table[0](1, 0xE0, 0x40000);
    if (data == NULL) {
        return NULL;
    }

    task = func_00451fc0(arg0, D_005F18D0, 0x10, 0, 0, func_0017acc0, func_0017b350, data);
    *(u16 *)(data + 0x8) = arg1;
    mode = (u16 *)(data + 0xA);
    *mode = arg2;

    for (node = func_001452b0(0x13); node != NULL; node = *(u8 **)(node + 0x138)) {
        if (i == 0) {
            f32 x = *(f32 *)(node + 0x140);
            f32 y = *(f32 *)(node + 0x144);
            f32 z = *(f32 *)(node + 0x148);
            *(f32 *)(data + 0xC0) = x;
            *(f32 *)(data + 0xC4) = y;
            *(f32 *)(data + 0xC8) = z;
        }
        if (i == 1) {
            if (fabsf(*(f32 *)(data + 0xC0) - *(f32 *)(node + 0x140)) >
                fabsf(*(f32 *)(data + 0xC8) - *(f32 *)(node + 0x148))) {
                *(u32 *)(data + 0xCC) = 0x3F800000;
                *(u32 *)(data + 0xD0) = 0;
                *(u32 *)(data + 0xD4) = 0;
            } else {
                *(u32 *)(data + 0xCC) = 0;
                *(u32 *)(data + 0xD0) = 0;
                *(u32 *)(data + 0xD4) = 0x3F800000;
            }
            *mode = 4;
        }
        i++;
    }

    switch (*mode) {
    case 1: {
        u8 **raster_slot;
        u8 **frame_slot;
        u8 **camera_slot;

        texture = (u8 **)(data + 0x3C);
        *texture = func_003ef2e0(NULL);
        if (*texture == NULL) {
            func_0046d730(D_005F18C0, 0x622);
        }
        *(u32 *)(*(u8 **)(data + 0x3C) + 0x50) = (*(u32 *)(*(u8 **)(data + 0x3C) + 0x50) & ~0xFF) | 2;
        *(u32 *)(*(u8 **)(data + 0x3C) + 0x50) = (*(u32 *)(*(u8 **)(data + 0x3C) + 0x50) & 0xFFFF00FF) | 0x3300;

        raster = func_003ec590(128, 128, 32, 0x505);
        if (raster != NULL) {
            func_0040fcd0(raster, 1);
        }
        raster_slot = (u8 **)(data + 0x40);
        *(u8 **)(data + 0x40) = raster;
        func_003ef080(*texture, raster);

        camera = func_003e84a0();
        if (camera != NULL) {
            u64 c_lo = D_005F18B0;
            f32 c_hi = D_005F18B8;
            *(u64 *)&pos = c_lo;
            pos.z = c_hi;
            func_003efd20(camera, func_003e9320());
            frame_slot = (u8 **)(camera + 0x4);
            func_003e9df0(*(u8 **)(camera + 0x4));
            func_003e9c10(*frame_slot, (const f32 *)&pos, 0);
            if (*frame_slot != NULL) {
                zRaster = func_003ec590(128, 128, 0, 1);
                if (zRaster != NULL) {
                    *(u8 **)(camera + 0x64) = zRaster;
                    func_003e8310(camera, 2);
                    goto camera_registered;
                }
            }
        }

        func_001790a0(camera);
        camera = NULL;

camera_registered:
        camera_slot = (u8 **)(data + 0x44);
        *(u8 **)(data + 0x44) = camera;
        {
            s32 world = func_00457190();
            func_003cbc10(world, *camera_slot);
        }
        *(u8 **)(*camera_slot + 0x60) = *raster_slot;

        func_0044ea90(D_005F18C0, 0x62F);
        *(u8 **)(data + 0x4C) = table[0](1, 0x54D0, 0x40000);
        break;
    }

    case 4:
    case 3:
        func_0044ea90(D_005F18C0, 0x634);
        *(f32 **)(data + 0x50) = (f32 *)table[0](1, 0xC, 0x40000);
        **(f32 **)(data + 0x50) = 30.0f;
        break;
    }

    if ((((u16)arg1 & 0xFFC00) >> 10) == 1) {
        obj = func_00145270(arg1);
        *(u8 **)(data + 0xC) = obj;
        if (obj == NULL) {
            func_0046d730(D_005F18C0, 0x63F);
        }
        *(void **)(data + 0x10) = *(void **)(obj + 0x164);
    } else if ((((u16)arg1 & 0xFFC00) >> 10) == 3) {
        obj = func_00145270(arg1);
        *(u8 **)(data + 0xC) = obj;
        if (obj == NULL) {
            func_0046d730(D_005F18C0, 0x648);
        }
        *(void **)(data + 0x10) = *(void **)(obj + 0x164);
    }

    return task;
}
#pragma opt_propagation on
#pragma opt_loop_invariants off