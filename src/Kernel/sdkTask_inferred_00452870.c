#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
extern f32 fGpffff81f0;
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern f32 fGpffff8200;
extern s32 iGpffffb9e8;
struct RwCamera;
struct RwSphere;
enum RwFrustumTestResult {
    rwSPHEREOUTSIDE = 0,
    rwSPHEREBOUNDARY = 1,
    rwSPHEREINSIDE = 2,
    rwFRUSTUMTESTRESULTFORCEENUMSIZEINT = 0x7fffffff
};
extern enum RwFrustumTestResult RwCameraFrustumTestSphere(const struct RwCamera *camera,
                                           const struct RwSphere *sphere);
struct RwV3d;
struct RwMatrixTag;
extern struct RwV3d *func_003e42a0(struct RwV3d *out, const struct RwV3d *in,
                                  const struct RwMatrixTag *matrix);
typedef struct Code45CurrentEntities {
    const struct RwCamera *camera;
    void *world;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
} Code45CurrentEntities;
extern Code45CurrentEntities D_008872E0;
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern s64 D_00711858[];
extern f32 D_00711860[];
static inline f32 add_f32(f32 a, f32 b) {
    return a + b;
}
extern u8 *iGpffffb9e0;
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern u8 D_007124C0[];
typedef struct {
    f32 v[4];
} Code45Float4;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} Code45Vec3;

typedef struct RwMatrixTag {
    Code45Vec3 right;
    u32 flags;
    Code45Vec3 up;
    u32 pad1;
    Code45Vec3 at;
    u32 pad2;
    Code45Vec3 pos;
    u32 pad3;
} Code45Matrix;

typedef struct RwSphere {
    Code45Vec3 center;
    f32 radius;
} Code45Sphere;
typedef struct {
    u8 red, green, blue, alpha;
} Code45RGBA;
typedef struct Code45RenderState {
    s32 state;
    s32 val;
} Code45RenderState;
extern Code45RenderState D_00712490[6];
extern s32 iGpffffac74;
extern s32 iGpffffad88;
extern s16 iGpffffba1c;
extern s16 iGpffffba20;
extern s16 iGpffffba24;
extern s16 iGpffffba28;
extern s16 iGpffffba2c;
extern s16 iGpffffba30;
extern s16 iGpffffba34;
extern void sdkPadUpdateRecord(void *arg0);
extern u8 D_008C02E0[];
extern s16 D_008C0336[];
extern s16 D_008C0338[];
extern s16 D_008C033C[];
extern s16 D_008C0340[];
extern s16 D_008C0342[];
extern u8 D_008C0346[];
extern u8 D_008C0347[];
extern u8 D_008C0348[];
extern u8 D_008C0349[];
extern u8 D_007117B0[];
extern u8 D_00711738[];
extern u8 D_00711720[];
extern s32 D_00711870_abs[];
extern s32 D_00711890_abs[];
extern u8 D_008E4090[];
extern u8 D_008E4230[];
extern s32 D_008E4018_abs[];
extern s32 D_008E40B4_abs[];
extern s32 D_008E40F8_abs[];
extern s32 D_008E413C_abs[];
extern s32 D_008E4180_abs[];
extern s32 D_008E41C4_abs[];
extern s32 D_008E4208_abs[];
extern u8 D_007117C8[];
extern u8 D_007117E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00711800[];
extern u8 D_00711810[];
extern u8 D_00711820[];
extern u8 D_00711830[];
extern u8 D_00756500[];
extern u8 D_00756510[];
extern f32 fGpffff802c;
extern f32 fGpffff8030;
extern s32 iGpffffba80;
extern s32 iGpffffba70;
extern u8 *iGpffffba74;
extern u8 *iGpffffba78;
extern u8 *iGpffffba7c;
extern s8 iGpffffba84;
extern s8 iGpffffba85;
extern s8 iGpffffba86;
extern s8 iGpffffba87;
extern s8 iGpffffba88;
extern s8 iGpffffba89;
extern s8 iGpffffba8a;
extern s8 iGpffffba8b;
extern s32 iGpffffba10;
extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];
extern u8 D_008C02EC[];
extern u8 D_008C02EE[];
extern u8 D_008C02F0[];
extern u8 D_008C02F6[];
extern u8 D_008C02F8[];
extern u8 D_008C02FA[];
extern u8 D_008C02FC[];
extern u8 D_008C02FD[];
extern u8 D_008C02FE[];
extern u8 D_008C02FF[];
extern u8 D_008C0318[];
extern u8 D_008C02F2[];
extern u8 D_008C0300[];
extern u8 D_008C0314[];
extern u8 D_008C0316[];
extern u8 D_008C031A[];
extern s16 D_008C030C[];
extern s16 D_008C030E[];
extern u8 D_008C031E[];

extern u8 D_008C8780[];
extern u8 D_008D1B80[];
extern u8 D_008D1B84[];
extern u8 D_008D1B88[];
extern u8 D_008D1C90[];
extern u8 D_008D1C98[];
extern u8 D_008D1CD4[];


typedef struct {
    f32 x;
    f32 y;
} Code45Vec2;

typedef struct {
    f32 u;
    f32 v;
} Code45TexCoords;


/* Providers and external symbols */
extern s32 iGpffffb9d4;
extern Code45Vec2 iGpffffac48;
extern Code45Vec2 iGpffffac50;
extern s8 iGpffffb9d8;
extern f32 D_008872F8;
extern u8 D_008BE320[][256];


/* RwDevice's near-screen depth and callback slots are one real object.
 * The complete Sky immediate-mode vertex has a 64-byte stride. */
typedef struct Code45RenderDevice {
    f32 gamma;
    s32 (*system)(s32, void *, void *, s32);
    f32 nearDepth;
    f32 farDepth;
    s32 (*setState)(s32, void *);
    s32 (*getState)(s32, void *);
    u32 renderCallbackAddresses[8];
} Code45RenderDevice;
extern Code45RenderDevice D_008872F0;

typedef struct Code45Im2DVertex {
    f32 position[3];
    f32 cameraZ;
    f32 uv[2];
    f32 reciprocal;
    f32 pad1;
    f32 color[4];
    f32 normal[3];
    f32 pad2;
} Code45Im2DVertex;

#pragma push
static inline s32 overlayAtlasColumn(s32 value)
{
    return value % 16;
}


#pragma pop
#pragma push
/* Character codes are normalized as bytes; the atlas column retains
 * the signed remainder operation used by the original renderer. */
static inline s32 fontAtlasColumn(s32 value)
{
    return value % 16;
}

/* Source unit: src/promoted/code1_0045.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0045.c; members 00452870-00452870 */

#pragma pop
/* measured: restore O2 after func_00450e80. */
/* measured: opt_propagation off preserves the constant 3 as a live local in $a0 and the computed pointer in $v1. */
#pragma push
#pragma pop
/* MATCH.  The last three differing words were a frame-slot placement: retail
   puts the actuator pair at sp+0x40 and b210 put it at sp+0x48, with the
   pressed pair at sp+0x4C in both.  0x40 is sixteen-byte aligned and 0x48 is
   not, and `s8 actuator[2] __attribute__((aligned(16)))` is what reproduces
   it - a two-byte buffer whose address is handed to func_00430630, which is
   pad-actuator DMA, so the alignment is a real requirement rather than a
   decoration.  Measured and rejected first: all thirteen declaration
   positions for the array (3 everywhere except the first two slots, which
   cost 6), block-scoping it at its use (3), declaring it `u16` and casting
   (3), `u8` instead of `s8` (3), widening it to `s8[4]` (3), and
   `aligned(8)` (3).  Aligning the pressed pair as well is also 0, so the
   actuator alignment alone is the cause. */
// Intent: polls the pad hardware for record `arg0`, then updates its port state and its pressed pair.
// FUN_00452870
void sdkPadUpdateRecord(void *arg0)
{
    extern void func_0042ffa0(u16 port, u16 slot, u8 *out);
    extern s32 func_00430018(u16 port, u16 slot);
    extern s32 func_00430180(u16 port, u16 slot, u16 state);
    extern s32 func_00430210(u16 port, u16 slot, s32 arg2, s32 arg3);
    extern s32 func_00430578(u16 port, u16 slot, s32 arg2, s32 arg3);
    extern s32 func_00430630(u16 port, u16 slot, s8 *arg2);
    extern s32 func_004306f8(u16 port, u16 slot, void *arg2);
    extern u8 D_008C0000[];
    extern u8 D_008C0001[];
    extern u8 D_008C0002[];
    extern u8 D_008C0003[];
    extern u8 D_008C0004[];
    extern u8 D_008C0005[];
    extern u8 D_008C0006[];
    extern u8 D_008C0007[];
    extern s32 iGpffffac78;
    u16 mode;
    s8 pressed[2];
    u8 *pad;
    u16 port;
    s32 result;
    s32 buttons;
    u16 state;
    u16 slot;
    u16 x;
    s8 actuator[2] __attribute__((aligned(16)));
    u16 y;
    s32 status;
    s32 analog;

    pad = (u8 *)arg0;
    D_008C0000[0] = 0xFF;
    port = *(u16 *)(pad + 8);
    slot = *(u16 *)(pad + 0xA);
    status = func_00430018(port, slot);
    state = *(u16 *)(pad + 2);
    switch (state) {
    case 0:
        if (status == 2 || status == 6) {
            *(u16 *)(pad + 0x30) = 0xFFFF;
            *(u16 *)(pad + 0x32) = 0xFFFF;
            mode = *(u16 *)(pad + 4);
            *(u16 *)(pad + 0) = mode;
            switch (mode) {
            case 0:
                *(u16 *)(pad + 2) = 3;
                break;
            case 1:
                if (status == 6) {
                    if (func_00430578(port, slot, 0, 0) == 1) {
                        *(u16 *)(pad + 2) = 1;
                    }
                } else {
                    *(u16 *)(pad + 2) = 3;
                }
                break;
            case 2:
                if (status == 6) {
                    if (func_00430578(port, slot, 0, 3) == 1) {
                        *(u16 *)(pad + 2) = 1;
                    }
                } else {
                    *(u16 *)(pad + 2) = 3;
                }
                break;
            case 3:
                if (status == 6) {
                    if (func_00430578(port, slot, 1, 3) == 1) {
                        *(u16 *)(pad + 2) = 1;
                    }
                } else {
                    *(u16 *)(pad + 2) = 3;
                }
                break;
            }
        }
        break;
    case 1:
        if (status == 6) {
            *(u16 *)(pad + 2) = 3;
        } else if (status != 5) {
            *(u16 *)(pad + 2) = 0;
        }
        break;
    case 3:
        if (func_00430210(port, slot, -1, 0) == 0) {
            *(u16 *)(pad + 2) = 5;
        } else if (func_004306f8(port, slot, &iGpffffac78) != 0) {
            *(u16 *)(pad + 2) = 4;
        }
        break;
    case 4:
        result = func_00430180(port, slot, state);
        switch (result) {
        case 1:
            *(u16 *)(pad + 2) = 3;
            break;
        case 0:
            *(u16 *)(pad + 2) = 5;
            break;
        }
        break;
    case 5:
        if (status != 2 && status != 6) {
            *(u16 *)(pad + 2) = 0;
        } else if (*(u16 *)(pad + 0) != *(u16 *)(pad + 4)) {
            *(u16 *)(pad + 2) = 0;
        } else {
            func_0042ffa0(port, slot, D_008C0000);
            x = *(u16 *)(pad + 0x2C);
            y = *(u16 *)(pad + 0x2E);
            if (x != *(u16 *)(pad + 0x30) || y != *(u16 *)(pad + 0x32)) {
                *(u16 *)(pad + 0x30) = x;
                *(u16 *)(pad + 0x32) = y;
                actuator[0] = (s8)x;
                actuator[1] = (s8)y;
                func_00430630(port, slot, actuator);
            }
        }
        break;
    }
    analog = 0;
    buttons = 0;
    if (D_008C0000[0] == 0) {
        switch (D_008C0001[0]) {
        case 0x41:
            buttons = 1;
            break;
        case 0x73:
            buttons = 1;
            analog = 1;
            break;
        case 0x79:
            buttons = 1;
            analog = 1;
            break;
        }
    }
    *(u16 *)(pad + 0x10) = *(u16 *)(pad + 0xC);
    *(u16 *)(pad + 0x1A) = *(u16 *)(pad + 0x16);
    *(u16 *)(pad + 0x38) = *(u16 *)(pad + 0x34);
    if (buttons != 0) {
        pressed[1] = ~D_008C0002[0];
        pressed[0] = ~D_008C0003[0];
        *(u16 *)(pad + 0xC) = *(u16 *)pressed;
    } else {
        *(u16 *)(pad + 0xC) = 0;
        *(u16 *)(pad + 0x10) = 0;
    }
    if (analog != 0) {
        *(u8 *)(pad + 0x1E) = D_008C0004[0];
        *(u8 *)(pad + 0x1F) = D_008C0005[0];
        *(u8 *)(pad + 0x1C) = D_008C0006[0];
        *(u8 *)(pad + 0x1D) = D_008C0007[0];
        return;
    }
    *(u8 *)(pad + 0x1E) = 0x80;
    *(u8 *)(pad + 0x1F) = 0x80;
    *(u8 *)(pad + 0x1C) = 0x80;
    *(u8 *)(pad + 0x1D) = 0x80;
}

