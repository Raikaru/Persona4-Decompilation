/* Scratch recovery of the three trail styles. The 0x24-byte vertex and
 * position/color setters follow include/rw/sky2/rwcore.h. Matrix flags are
 * defined explicitly: retail's load/OR of an unwritten stack flag word is
 * retained as an unresolved difference, not copied as an uninitialized read. */
typedef struct RwRGBA {
    u8 red, green, blue, alpha;
} TrailRGBA;

typedef union RxColorUnion {
    TrailRGBA preLitColor;
    TrailRGBA color;
} TrailColor;

typedef struct RxObjSpace3DVertex {
    ShuffleVec3 objVertex;
    TrailColor c;
    ShuffleVec3 objNormal;
    f32 u, v;
} TrailVertex;

typedef char TrailVertexSizeCheck[(sizeof(TrailVertex) == 0x24) ? 1 : -1];

#define TRAIL_POSITION(_vertex, _x, _y, _z) do { \
    ShuffleVec3 packed; \
    packed.x = (_x); \
    packed.y = (_y); \
    packed.z = (_z); \
    (_vertex)->objVertex = packed; \
} while (0)

#define TRAIL_COLOR(_vertex, _r, _g, _b, _a) do { \
    TrailRGBA *const color = &(_vertex)->c.color; \
    color->red = (_r); \
    color->green = (_g); \
    color->blue = (_b); \
    color->alpha = (_a); \
} while (0)

extern ShuffleVec3 D_0060A0E0;
extern f32 iGpffff8400;
extern f32 iGpffff8404;
extern f32 iGpffff8408;
extern f32 iGpffff8308;

#pragma push
#pragma opt_loop_invariants on
void func_003768e0(u8 *work, s32 cardIndex, s32 mode, u8 *rgba, f32 length)
{
    TrailVertex first[42];
    TrailVertex second[42];
    ShuffleVec3 samples[21];
    BtlShuffleMatrix identity;
    TrailVertex *front;
    TrailVertex *back;
    ShuffleVec3 *sample;
    u8 *card;
    u8 *motion;
    s32 kind;
    f32 opacity;

    kind = (s8)mode;
    if (kind >= 3) {
        func_0046d730(D_0064EA20, 0x5DE);
    }
    identity.right.x = identity.up.y = identity.at.z = 1.0f;
    identity.right.y = identity.right.z = identity.up.x = 0.0f;
    identity.up.z = identity.at.x = identity.at.y = 0.0f;
    identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
    identity.flags = 0x20003;
    RpSkyRenderStateSet(2, (void *)0x48);
    RpSkyRenderStateSet(3, (void *)0x71801);
    D_00887300[0](rwRENDERSTATECULLMODE, (void *)1);
    D_00887300[0](rwRENDERSTATEZTESTENABLE, (void *)1);
    D_00887300[0](rwRENDERSTATEZWRITEENABLE, NULL);
    motion = work + cardIndex * 0xE8 + 0x1D6A0;
    card = work + cardIndex * 0xFB0;
    if (*(s32 *)(motion + 4) == 6) {
        opacity = (f32)(u32)rgba[3] * ((f32)(u32)motion[0xD8] / 255.0f);
        switch (kind) {
        case 0:
            {
                s32 point;
                s32 side;
                f32 fadedOpacity;
                f32 taper;
                f32 time;
                f32 halfWidth;
                f32 halfHeight;
                front = first;
                back = second;
                fadedOpacity = iGpffff8400 * opacity;
                taper = 1.0f;
                time = 0.0f;
                length /= 21.0f;
                for (point = 0; point < 21; point++) {
                    func_003764b0(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= length;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], (u8)(opacity * taper));
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], (u8)(fadedOpacity * taper));
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], (u8)(fadedOpacity * taper));
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], (u8)(opacity * taper));
                    taper += iGpffff8404;
                    front += 2;
                    back += 2;
                }
                halfWidth = 0.5f * func_0036de70(card);
                halfHeight = 0.5f * func_0036deb0(card);
                for (side = 0; side < 4; side++) {
                    front = first;
                    back = second;
                    switch (side) {
                    case 0:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], halfWidth + sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front[1], halfWidth + sample->x, sample->y, sample->z);
                            TRAIL_POSITION(&back[0], halfWidth + sample->x, sample->y, sample->z);
                            TRAIL_POSITION(&back[1], halfWidth + sample->x, halfHeight + sample->y, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    case 1:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], sample->x - halfWidth, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front[1], sample->x - halfWidth, sample->y, sample->z);
                            TRAIL_POSITION(&back[0], sample->x - halfWidth, sample->y, sample->z);
                            TRAIL_POSITION(&back[1], sample->x - halfWidth, halfHeight + sample->y, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    case 2:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], halfWidth + sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&front[1], sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&back[0], sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&back[1], sample->x - halfWidth, halfHeight + sample->y, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    case 3:
                        for (point = 0; point < 21; point++) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front[0], halfWidth + sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front[1], sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&back[0], sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&back[1], sample->x - halfWidth, sample->y - halfHeight, sample->z);
                            front += 2;
                            back += 2;
                        }
                        break;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
                break;
            }
        case 1:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 time;
                f32 halfWidth;
                f32 halfHeight;
                f32 x;
                f32 y;
                f32 z;
                f32 offsetX;
                f32 offsetY;
                u8 alpha;
                f32 negativeWidth;
                f32 negativeHeight;
                front = first;
                back = second;
                alpha = (u8)opacity;
                time = 0.0f;
                length /= 21.0f;
                for (point = 0; point < 21; point++) {
                    func_003764b0(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= length;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], 0);
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], 0);
                    front += 2;
                    back += 2;
                }
                halfWidth = 0.5f * func_0036de70(card);
                halfHeight = 0.5f * func_0036deb0(card);
                side = 0;
                negativeWidth = -halfWidth;
                negativeHeight = -halfHeight;
                for (; side < 4; side++) {
                    switch (side) {
                    case 0: offsetX = halfWidth; offsetY = halfHeight; break;
                    case 1: offsetX = negativeWidth; offsetY = halfHeight; break;
                    case 2: offsetX = halfWidth; offsetY = negativeHeight; break;
                    case 3: offsetX = negativeWidth; offsetY = negativeHeight; break;
                    }
                    front = first;
                    back = second;
                    taper = 1.0f;
                    for (point = 0; point < 21; point++) {
                        f32 magnitude = 3.0f * taper;
                        f32 dx = D_0060A0E0.x * magnitude;
                        f32 dy = D_0060A0E0.y * magnitude;
                        f32 dz = D_0060A0E0.z * magnitude;
                        sample = &samples[point];
                        x = sample->x;
                        y = sample->y;
                        z = sample->z;
                        TRAIL_POSITION(&front[0], dx + x + offsetX, dy + y + offsetY, dz + z);
                        TRAIL_POSITION(&front[1], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[0], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[1], x - dx + offsetX, y - dy + offsetY, z - dz);
                        taper += iGpffff8404;
                        front += 2;
                        back += 2;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
            }
            break;
        case 2:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 time;
                f32 halfWidth;
                f32 halfHeight;
                f32 x;
                f32 y;
                f32 z;
                f32 offsetX;
                f32 offsetY;
                u8 alpha;
                f32 right;
                f32 left;
                f32 height;
                func_003e9700(*(struct RwFrame **)((u8 *)func_00457120() + 4));
                front = first;
                back = second;
                alpha = (u8)opacity;
                time = 0.0f;
                length /= 21.0f;
                for (point = 0; point < 21; point++) {
                    func_003764b0(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= length;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], 0);
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], 0);
                    front += 2;
                    back += 2;
                }
                halfWidth = 0.5f * func_0036de70(card);
                halfHeight = 0.5f * func_0036deb0(card);
                side = 0;
                right = iGpffff8218 * halfWidth;
                height = iGpffff8308 * halfHeight;
                left = iGpffff8218 * -halfWidth;
                for (; side < 2; side++) {
                    switch (side) {
                    case 0: offsetX = right; offsetY = height; break;
                    case 1: offsetX = left; offsetY = height; break;
                    }
                    front = first;
                    back = second;
                    taper = 1.0f;
                    for (point = 0; point < 21; point++) {
                        f32 magnitude = iGpffff8408 * taper;
                        f32 dx = D_0060A0E0.x * magnitude;
                        f32 dy = D_0060A0E0.y * magnitude;
                        f32 dz = D_0060A0E0.z * magnitude;
                        sample = &samples[point];
                        x = sample->x;
                        y = sample->y;
                        z = sample->z;
                        TRAIL_POSITION(&front[0], dx + x + offsetX, dy + y + offsetY, dz + z);
                        TRAIL_POSITION(&front[1], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[0], offsetX + x, offsetY + y, z);
                        TRAIL_POSITION(&back[1], x - dx + offsetX, y - dy + offsetY, z - dz);
                        taper += iGpffff8404;
                        front += 2;
                        back += 2;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
            }
            break;
        }
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
    }
}
#pragma pop
#undef TRAIL_COLOR
#undef TRAIL_POSITION

