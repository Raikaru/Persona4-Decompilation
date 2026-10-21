#include "operand_order_internal.h"
#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_camera_internal.h"
extern f32 fGpffff81f0;
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern f32 fGpffff8200;
extern void func_00446ed8(void *buf, const void *fmt, void *va);
extern void sdkDbprtDrawText(PackedColor4 color, PackedVec2f position, f32 depth, void *characters);
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
extern u8 *iGpffffb9e0;
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern u8 D_007124C0[];
typedef struct {
    f32 v[4];
} Code45Float4;
#include "rw_types_internal.h"
typedef RwV3d Code45Vec3;


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
extern s32 iGpffffb9d4;
extern Code45Vec2 iGpffffac48;
extern Code45Vec2 iGpffffac50;
extern s8 iGpffffb9d8;
extern u8 D_008BE320[][256];
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
/* measured: retail hoists the near depth out of the vertex initialization loops. */
#pragma opt_loop_invariants on
/* Draws the enabled debug overlay panel and its buffered text rows. Each initialization loop keeps
 * an explicit vertex pointer, and the panel extent is copied before its border is added. */
// FUN_00450630
void sdkDbprtDrawOverlay(void)
{
    typedef Code45Im2DVertex OverlayVertex;
    Code45TexCoords uvs[4];
    OverlayVertex vertices[4];
    Code45Vec2 panelOrigin;
    Code45Vec2 textOrigin;
    struct { s32 (*setState)(s32, void *); } *state;
    struct { s32 (*draw)(s32, void *, s32); } *renderer;
    f32 reciprocalDepth;
    f32 rowTop;
    f32 rowBottom;
    f32 columnOffset;
    f32 panelRight;
    f32 right;
    const u8 *line;
    s32 column;
    s32 row;
    s32 vertexIndex;
    s32 uvIndex;
    u8 glyph;
    s32 atlasColumn;

    reciprocalDepth = 1.0f / ((RwCamera *)iGpffffb9e0)->nearPlane;
    if (iGpffffb9d4 == 0) {
        return;
    }

    state = (void *)D_00887300;
    state->setState(6, (void *)1);
    state->setState(7, (void *)2);
    state->setState(8, (void *)1);
    state->setState(9, (void *)1);
    state->setState(12, (void *)1);
    panelOrigin = iGpffffac48;
    state->setState(1, 0);

    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
        OverlayVertex *vertex = &vertices[vertexIndex];
        vertex->reciprocal = reciprocalDepth;
        vertex->color[0] = 64.0f;
        vertex->color[1] = 64.0f;
        vertex->color[2] = 64.0f;
        vertex->color[3] = 128.0f;
        vertex->position[2] = D_008872F0.nearDepth;
    }

    vertices[0].position[0] = panelOrigin.x;
    vertices[0].position[1] = panelOrigin.y;
    panelRight = 480.0f + panelOrigin.x;
    right = panelRight;
    vertices[1].position[0] = 16.0f + right;
    vertices[1].position[1] = panelOrigin.y;
    vertices[2].position[0] = panelOrigin.x;
    vertices[2].position[1] = 16.0f + (180.0f + panelOrigin.y);
    vertices[3].position[0] = vertices[1].position[0];
    vertices[3].position[1] = vertices[2].position[1];

    renderer = (void *)D_00887310;
    renderer->draw(4, vertices, 4);
    state->setState(1, (void *)iGpffffb9e8);

    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
        OverlayVertex *vertex = &vertices[vertexIndex];
        vertex->reciprocal = reciprocalDepth;
        vertex->color[0] = 255.0f;
        vertex->color[1] = 255.0f;
        vertex->color[2] = 255.0f;
        vertex->color[3] = 255.0f;
        vertex->position[2] = D_008872F0.nearDepth;
    }

    for (row = 0; row < iGpffffb9d8; row++) {
        line = D_008BE320[row];
        column = 0;
        rowTop = 12.0f * (f32)row;
        rowBottom = 11.0f + rowTop;

        for (; column < 53; column++) {
            textOrigin = iGpffffac50;
            glyph = line[column];
            if (glyph == 0) {
                break;
            }
            if (glyph == ' ') {
                continue;
            }

            glyph -= 0x20;
            if (glyph >= 0x80) {
                glyph -= 0x20;
            }

            columnOffset = 12.0f * (f32)column;
            vertices[0].position[0] = columnOffset + textOrigin.x;
            vertices[0].position[1] = rowTop + textOrigin.y;
            vertices[1].position[0] = (11.0f + columnOffset) + textOrigin.x;
            vertices[1].position[1] = vertices[0].position[1];
            vertices[2].position[0] = vertices[0].position[0];
            vertices[2].position[1] = rowBottom + textOrigin.y;
            vertices[3].position[0] = vertices[1].position[0];
            vertices[3].position[1] = vertices[2].position[1];

            atlasColumn = operandOrderRemainder((s32)glyph, 16);
            uvs[0].u = 0.0625f * (f32)atlasColumn;
            uvs[0].v = 0.0625f * (f32)(s32)((u32)glyph >> 4);
            uvs[1].u = 0.046875f + uvs[0].u;
            uvs[1].v = uvs[0].v;
            uvs[2].u = uvs[0].u;
            uvs[2].v = 0.046875f + uvs[0].v;
            uvs[3].u = uvs[1].u;
            uvs[3].v = uvs[2].v;

            for (uvIndex = 0; uvIndex < 4; uvIndex++) {
                Code45TexCoords *uv = &uvs[uvIndex];
                OverlayVertex *vertex = &vertices[uvIndex];
                vertex->uv[0] = uv->u;
                vertex->uv[1] = uv->v;
            }

            renderer->draw(4, vertices, 4);
        }
    }
}

#pragma pop
#pragma push
/* measured: retail hoists the depth value out of the glyph loop. */
#pragma opt_loop_invariants on
/* Draws an immediate string using packed color, position and depth values; both variadic callers
 * pass the complete packed-value arguments. */
// FUN_00450A50
void sdkDbprtDrawText(PackedColor4 color, PackedVec2f position, f32 depth, void *characters)
{
    Code45TexCoords uvs[4];
    typedef Code45Im2DVertex FontVertex;
    FontVertex vertices[4];
    const u8 *text;
    f32 originX;
    f32 originY;
    u32 alpha;
    u32 blue;
    u32 green;
    u32 red;
    f32 reciprocal;
    f32 bottom;
    s32 font;
    s32 vertexIndex;
    s32 characterIndex;
    s32 uvIndex;

    text = (const u8 *)characters;
    originY = position.xy.y;
    originX = position.xy.x;
    alpha = color.rgba[3];
    blue = color.rgba[2];
    green = color.rgba[1];
    red = color.rgba[0];
    reciprocal = 1.0f / ((RwCamera *)iGpffffb9e0)->nearPlane;
    font = iGpffffb9e8;
    if (font == 0) {
        return;
    }
    D_00887300[0](1, font);
    vertexIndex = 0;
    while (vertexIndex < 4) {
        FontVertex *vertex = &vertices[vertexIndex];
        vertex->reciprocal = reciprocal;
        vertex->color[0] = (f32)red;
        vertex->color[1] = (f32)green;
        vertex->color[2] = (f32)blue;
        vertex->color[3] = (f32)alpha;
        vertex->position[2] = D_008872F0.nearDepth - depth;
        vertexIndex++;
    }
    characterIndex = 0;
    bottom = 11.0f + originY;
    for (; characterIndex < 256; characterIndex++) {
        s32 character;
        s32 atlasColumn;
        f32 column;
        f32 left;
        f32 right;
        character = text[characterIndex];
        if (character == 0) {
            return;
        }
        if (character == 32) {
            continue;
        }
        character = (u8)(character - 32);
        if (character >= 128) {
            character = (u8)(character - 32);
        }
        column = 12.0f * (f32)characterIndex;
        left = column + originX;
        vertices[0].position[0] = left;
        vertices[0].position[1] = originY;
        right = 11.0f + column + originX;
        vertices[1].position[0] = right;
        vertices[1].position[1] = originY;
        vertices[2].position[0] = left;
        vertices[2].position[1] = bottom;
        vertices[3].position[0] = right;
        vertices[3].position[1] = bottom;
        atlasColumn = operandOrderRemainder(((s32)(u8)character), 16);
        uvs[0].u = 0.0625f * (f32)atlasColumn;
        uvs[0].v = 0.0625f * (f32)(s32)((u32)(u8)character >> 4);
        uvs[1].u = 0.046875f + uvs[0].u;
        uvs[1].v = uvs[0].v;
        uvs[2].u = uvs[0].u;
        uvs[2].v = 0.046875f + uvs[0].v;
        uvs[3].u = uvs[1].u;
        uvs[3].v = uvs[2].v;
        for (uvIndex = 0; uvIndex < 4; uvIndex++) {
            Code45TexCoords *uv = &uvs[uvIndex];
            FontVertex *vertex = &vertices[uvIndex];
            vertex->uv[0] = uv->u;
            vertex->uv[1] = uv->v;
        }
        D_00887310[0](4, vertices, 4);
    }
}

#pragma pop
/* Formats an immediate string and draws it with the default packed color. */
// FUN_00450DD0
void sdkDbprtPrint(PackedVec2f position, f32 z, const void *format, ...)
{
    char buffer[0x100];
    union { f32 f; s32 bits; PackedColor4 color; } scale;
    char *args;
    s32 count;
    extern f32 fGpffffac58;

    scale.f = fGpffffac58;
    count = __builtin_args_info(2);
    if (count >= 8) count = 0; else count = (8 - count) * 8;
    args = (char *)__builtin_next_arg(format) - count;
    func_00446ed8(buffer, format, args);
    sdkDbprtDrawText(scale.color, position, z, buffer);
}

/* Color and position aggregates use the compiler's real variadic save area. Formats and draws an
 * immediate string using the supplied packed color. */
// FUN_00450E80
void sdkDbprtPrintColor(PackedColor4 color, PackedVec2f position, f32 z,
                   const void *format, ...)
{
    char buffer[0x100];
    char *args;
    s32 count;
    s32 remaining;

    count = __builtin_args_info(2);
    if (count >= 8) {
        count = 0;
    } else {
        remaining = 8 - count;
        count = remaining * 8;
    }
    args = (char *)__builtin_next_arg(format) - count;
    func_00446ed8(buffer, format, args);
    sdkDbprtDrawText(color, position, z, buffer);
}

