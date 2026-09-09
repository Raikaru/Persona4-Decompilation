/* Fresh SDK debug-overlay candidate: func_00450630.
 * Owner src/promoted/code1_0045.c. PRODUCTION REMAINS ASM.
 * Initial structured candidate:1028/1056 bytes,nd745,28 object relocations.
 * Preferred real vertex-array/scoped loop-invariant source:1044/1056 bytes,nd441,
 * 28 object relocations,12 zero alignment bytes. Executable extent is complete,
 * but allocation/instruction differences remain; this is NOT an exact match.
 * The agent's vertex struct with named pad fields is discarded. The preferred
 * source below uses four real64-byte vertex records as f32[4][16], plus the actual
 * four UV pairs and two2D position objects. No fabricated padding is introduced.
 * 
 * The callback has no ABI inputs. It computes camera near reciprocal before its
 * visibility guard; render-state callbacks precede the background quad and the
 * font-raster switch. Each row is a256-byte string record; at most53 characters
 * are considered, stopping at NUL and skipping space. Character normalization
 * subtracts0x20 in byte arithmetic, then subtracts another0x20 when>=0x80. Reload
 * text position per character, row limit at the loop test, and callback slots at
 * use. Existing production SDK callers are unchanged. No native/Wasm behavior
 * smoke or broad non-finite/input-validity claim was made.
 */

/* Grounded required types and provider declarations for func_00450630 in src/promoted/code1_0045.c */

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

/* Function prototype */
void func_00450630(void);

#pragma push
#pragma opt_loop_invariants on
// FUN_00450630
void func_00450630(void)
{
    f32 vertices[4][16];
    Code45TexCoords uvs[4];
    Code45Vec2 text_pos;
    Code45Vec2 box_pos;
    f32 recipZ;
    f32 row_y_base;
    f32 row_y;
    f32 col_x;
    u8 *line;
    s32 row;
    s32 col;
    s32 i;
    s32 j;
    u8 ch;

    recipZ = 1.0f / *(f32 *)(iGpffffb9e0 + 0x80);
    if (iGpffffb9d4 == 0) {
        return;
    }

    D_00887300[0](6, 1);
    D_00887300[0](7, 2);
    D_00887300[0](8, 1);
    D_00887300[0](9, 1);
    D_00887300[0](12, 1);
    box_pos = iGpffffac48;
    D_00887300[0](1, 0);

    for (i = 0; i < 4; i++) {
        vertices[i][6] = recipZ;
        vertices[i][8] = 64.0f;
        vertices[i][9] = 64.0f;
        vertices[i][10] = 64.0f;
        vertices[i][11] = 128.0f;
        vertices[i][2] = D_008872F8;
    }

    vertices[0][0] = box_pos.x;
    vertices[0][1] = box_pos.y;
    vertices[1][0] = 16.0f + (480.0f + box_pos.x);
    vertices[1][1] = box_pos.y;
    vertices[2][0] = box_pos.x;
    vertices[2][1] = 16.0f + (180.0f + box_pos.y);
    vertices[3][0] = vertices[1][0];
    vertices[3][1] = vertices[2][1];

    D_00887310[0](4, vertices, 4);
    D_00887300[0](1, iGpffffb9e8);

    for (i = 0; i < 4; i++) {
        vertices[i][6] = recipZ;
        vertices[i][8] = 255.0f;
        vertices[i][9] = 255.0f;
        vertices[i][10] = 255.0f;
        vertices[i][11] = 255.0f;
        vertices[i][2] = D_008872F8;
    }

    for (row = 0; row < iGpffffb9d8; row++) {
        line = D_008BE320[row];
        row_y_base = 12.0f * (f32)row;
        row_y = 11.0f + row_y_base;

        for (col = 0; col < 53; col++) {
            text_pos = iGpffffac50;
            ch = line[col];
            if (ch == 0) {
                break;
            }
            if (ch == ' ') {
                continue;
            }

            ch -= 0x20;
            if (ch >= 0x80) {
                ch -= 0x20;
            }

            col_x = 12.0f * (f32)col;
            vertices[0][0] = col_x + text_pos.x;
            vertices[0][1] = row_y_base + text_pos.y;
            vertices[1][0] = (11.0f + col_x) + text_pos.x;
            vertices[1][1] = vertices[0][1];
            vertices[2][0] = vertices[0][0];
            vertices[2][1] = row_y + text_pos.y;
            vertices[3][0] = vertices[1][0];
            vertices[3][1] = vertices[2][1];

            uvs[0].u = 0.0625f * (f32)(ch % 16);
            uvs[0].v = 0.0625f * (f32)(ch >> 4);
            uvs[1].u = 0.046875f + uvs[0].u;
            uvs[1].v = uvs[0].v;
            uvs[2].u = uvs[0].u;
            uvs[2].v = 0.046875f + uvs[0].v;
            uvs[3].u = uvs[1].u;
            uvs[3].v = uvs[2].v;

            for (j = 0; j < 4; j++) {
                vertices[j][4] = uvs[j].u;
                vertices[j][5] = uvs[j].v;
            }

            D_00887310[0](4, vertices, 4);
        }
    }
}

#pragma pop
