/* Fresh field camera callback recovery: func_0017bc60.
 * Owner: src/promoted/code1_0017.c. Production ASM replaced by the source below.
 * Measured owner-context result: 940/944 bytes, nd0,29 fully resolved relocations,
 * and four zero alignment bytes. Component-scaled translation closes the previous
 * 940/nd29 staged-result source. Keep 0.0f on the left of each accumulated
 * translation, the camera-frame reload after callbacks, and the matrix-result scope.
 * All69 previously recovered owner C bodies retain bytes and relocation meaning.
 * The existing color-restore caller retains its signed-word pointer conversion.
 * 
 * Provider cutover: func_003e9c10(u8 *,const f32 *,s32) now explicitly forwards
 * translation and combine mode to func_003e0c90. Its existing wrapper stays exact:
 * 148/160 bytes, nd0,three relocations. Both code1_004a.c C callers are migrated.
 * The previous one-argument source fails strict Wasm linking with signature
 * mismatches at both wrapper and matrix-translation provider; the corrected actual
 * wrapper passes396 numerical/dirty-list/input/canary cases across all three modes,
 * four low dirty-flag states and33 finite translation vectors.
 * 
 * The integrated field source passes11 disposable Wasm32 scenario groups: early
 * exit; both basis modes; clip/view-window behavior; component-wise translation;
 * begin-update success/failure; RGBA save/replacement; frame/data/model callback
 * mutation and reload; untouched state and canaries. The fixture uses four-byte
 * pointers, real matrix/clip/color offsets and instrumented provider boundaries.
 * It is not a complete RenderWare backend or a PS2 rendering check. Native i386
 * libc headers/runtime are unavailable; no native32 execution is claimed.
 * 
 * Full make all lint-errors:172 source objects linked; both retail SHA-1s match;
 * 12,720 functions scanned,7,791 MATCH/4,929 ASM overall; first-party6,161 MATCH/
 * 699 ASM. Lint338 first-party files,zero findings. This adds one first-party match.
 * The declarations below supplement existing owner definitions and providers.
 */

typedef struct { f32 x, y, z; } Vec3_00178590;
typedef struct { u8 red, green, blue, alpha; } FieldColor_0017;
typedef struct { u8 red, green, blue, alpha; } FieldColor_0017;
extern void *func_0014ad50(void);
extern u8 *func_003e81c0(u8 *, f32);
extern u8 *func_003e8180(u8 *, f32);
extern u8 *func_003e83a0(u8 *, const f32 *);
extern u8 *func_003e9c10(u8 *, const f32 *, s32);
extern u8 *func_003e9700(u8 *);
extern u8 *func_003e0670(u8 *, u8 *);
extern u8 *func_003e82a0(u8 *, void *, s32);
extern u32 func_003e8120(u32);
extern void *func_0047a250(void *);
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern void func_0046d730(const void *, s32);
extern void func_0047a220(u8 *, const void *);

// FUN_0017BC60
void func_0017bc60(u8 *unused, u8 *state)
{
    Vec3_00178590 position;
    f32 localTolerance[3];
    f32 sceneTolerance[3];
    f32 viewWindow[2];
    Vec3_00178590 translation;
    u8 *data;
    u8 *camera;
    u8 **frameSlot;
    u8 *frame;
    f32 height;
    f32 scaledHeight;

    data = *(u8 **)(*(u8 **)(state + 0x224) + 0x38);
    camera = *(u8 **)(data + 0x44);
    height = *(f32 *)(data + 0x18);
    position = *(Vec3_00178590 *)(func_0047a2f0(*(void **)(state + 0x164)) + 0x30);
    if (*(s32 *)(*(u8 **)(*(u8 **)(state + 0x224) + 0x38)) > 0) {
        if (*(u32 *)(state + 0x28) & 0x80000000U) {
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(Vec3_00178590 *)(frame + 0x10) = *(Vec3_00178590 *)(state + 0x190);
            *(Vec3_00178590 *)(frame + 0x20) = *(Vec3_00178590 *)(state + 0x1A0);
            *(Vec3_00178590 *)(frame + 0x30) = *(Vec3_00178590 *)(state + 0x1B0);
            func_003e0380(localTolerance);
            func_003e03e0(frame + 0x10, localTolerance);
            func_003e05d0(frame + 0x10);
        } else {
            u8 *basis = func_0014ad50();
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(Vec3_00178590 *)(frame + 0x10) = *(Vec3_00178590 *)(basis + 0);
            *(Vec3_00178590 *)(frame + 0x20) = *(Vec3_00178590 *)(basis + 0x10);
            *(Vec3_00178590 *)(frame + 0x30) = *(Vec3_00178590 *)(basis + 0x20);
            func_003e0380(sceneTolerance);
            func_003e03e0(frame + 0x10, sceneTolerance);
            func_003e05d0(frame + 0x10);
        }
        scaledHeight = iGpffff826c * height;
        func_003e81c0(camera, 10.0f * scaledHeight);
        func_003e8180(camera, iGpffff8214 * scaledHeight);
        if (func_0014a160() == 1) {
            viewWindow[0] = 2.0f * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        } else {
            viewWindow[0] = iGpffff8360 * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        }
        func_003e83a0(camera, viewWindow);
        position.y += height / 2.0f;
        frame = *frameSlot;
        translation.x = -*(f32 *)(frame + 0x40);
        translation.y = -*(f32 *)(frame + 0x44);
        translation.z = -*(f32 *)(frame + 0x48);
        translation.x += position.x;
        translation.y += position.y;
        translation.z += position.z;
        translation.x = (0.0f + translation.x) + *(f32 *)(frame + 0x30) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.y = (0.0f + translation.y) + *(f32 *)(frame + 0x34) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.z = (0.0f + translation.z) + *(f32 *)(frame + 0x38) * (-0.5f * *(f32 *)(camera + 0x84));
        func_003e9c10(frame, (const f32 *)&translation, 2);
        {
            u8 *matrix = func_003e9700(frame);
            func_003e0670(matrix, matrix);
        }
        func_003e82a0(camera, &iGpffffb308, 3);
        if (func_003e8120((u32)camera)) {
            FieldColor_0017 *savedColor = (FieldColor_0017 *)(*(u8 **)(*(u8 **)(state + 0x224) + 0x38) + 0x48);
            *savedColor = *(FieldColor_0017 *)func_0047a250(*(void **)(state + 0x164));
            func_0047a220(*(u8 **)(state + 0x164), &iGpffff9f4c);
        } else {
            func_0046d730(D_005F18C0, 0x764);
        }
    }
}
