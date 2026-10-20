/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0046a770-0046ab40 */

#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "sdk_lbox_internal.h"
#include "type.h"
#include "member_access.h"
#include "btl_ui_task_internal.h"
#include "rw/plcore/barenderstate.h"
#include "h_cdvd_internal.h"
#include "Kosaka/k_clump_internal.h"
/* resourceFindByName and resourceLoadSprites share the name and next-link offsets. */
typedef struct SdkSpriteResourceLink {
    u8 pad0[2];
    char name[0x236];
    u8 *next;
} SdkSpriteResourceLink;

/* Four XY points are transformed using this attachment's position and angle. */
typedef struct SdkSpriteAttachment {
    u8 *resource;
    s32 segment;
    f32 x, y;
    u8 pad10[8];
    f32 angle;
    s16 offsetX, offsetY;
} SdkSpriteAttachment;

extern void sdkSpriteLoadStep(u8 *pack);
extern u8 *D_00724C08;
extern s32 strcmp(const char *a, const char *b);
/* Same RwV3d tag and fields as the ring provider and RenderWare. */
#include "rw_types_internal.h"
typedef struct RwMatrixTag RwMatrix;

typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;

extern RwMatrix *func_003e0f80(void);
extern RwMatrix *func_003e0680(RwMatrix *matrix, const RwV3d *axis,
                            f32 oneMinusCosine, f32 sine, RwOpCombineType combineOp);
extern RwV3d *func_003e42e0(RwV3d *dst, const RwV3d *src, s32 count, const RwMatrix *matrix);
extern s32 func_003e0f40(RwMatrix *matrix);
extern u8 D_007130B8[];
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8084;
extern f32 fGpffff81b0;
extern f32 fGpffff81b4;
extern f32 fGpffff81b8;
extern f32 fGpffff81bc;
extern f32 fGpffff81c0;
extern f32 fGpffff81c4;
extern f32 fGpffff81c8;
extern f32 fGpffff81cc;
/* Search the linked resource list for an exact name; return NULL when the name is absent. */
// FUN_0046A770
/* The list walk is written with an explicit goto loop: retail tests the
   cursor at the TOP of the loop and both early exits are out of line, which
   the natural `while (p != NULL)` form does not reproduce (nd 57). */
u8 *resourceFindByName(char *name) {
    u8 *p;

    p = D_00724C08;
loop:
    if (p == NULL) {
        return NULL;
    }
    if (strcmp(((SdkSpriteResourceLink *)p)->name, name) == 0) {
        return p;
    }
    p = ((SdkSpriteResourceLink *)p)->next;
    goto loop;
}

#pragma push
/* measured: baseline wrap constants yield 864/848 bytes; while-range and named-limit forms still differ. */
#pragma opt_loop_invariants on
/* measured: b210 -O2 emits 844/848 native bytes with all nineteen
 * relocations resolved and four zero alignment bytes. Keep the negated
 * upper-limit result separate from its branch and the Y subtotal separate
 * from the attachment-table load. Loop invariants retain the retail wrap
 * constants; see docs/probe_archive/Sprite_attachment_0046a7f0_20260924.md. */
/* Rotate four attachment points when needed, then add attachment and resource-segment positions. */
/* measured: a dedicated attachment alias preserves index reloads; resource-table loads retain MEMBER byte-base aliasing. */
// FUN_0046A7F0
void sdkSpriteTransformPoints(u8 *attachment, u8 *points)
{
    SdkSpriteAttachment *attachmentFields = (SdkSpriteAttachment *)(attachment);
    RwV3d source[4];
    RwV3d transformed[4];
    s32 copyIndex;
    s32 pointIndex;
    s32 vectorIndex;
    f32 angle;
    f32 x;
    f32 x2;
    f32 polynomial;
    f32 quadraticProduct;
    f32 correction;
    f32 oneMinusCosine;
    f32 sine;
    s32 wrapped;
    RwMatrix *matrix;
    RwMatrix *rotation;

    for (copyIndex = 0; copyIndex < 4; copyIndex++) {
        f32 *s = (f32 *)(points + copyIndex * 8);
        RwV3d *d = &source[copyIndex];

        d->x = s[0];
        d->y = s[1];
        /* Retail leaves the third component unwritten before rotation. */
    }
    angle = ((SdkSpriteAttachment *)attachment)->angle;
    if (angle != 0.0f) {
        do {
            s32 notAboveUpper;

            wrapped = 0;
            notAboveUpper = !(angle > 180.0f);
            if (!notAboveUpper) {
                angle -= 360.0f;
                wrapped = 1;
            } else if (angle < -180.0f) {
                angle += 360.0f;
                wrapped = 1;
            }
        } while (wrapped != 0);
        x = (fGpffff8084 * angle) / 180.0f;
        x2 = x * x;
        matrix = func_003e0f80();
        polynomial = fGpffff81b0 * x2 + fGpffff81b4;
        polynomial = x2 * polynomial + fGpffff81b8;
        polynomial = x2 * polynomial + fGpffff81bc;
        polynomial = x2 * polynomial + fGpffff81c0;
        polynomial = x2 * polynomial + fGpffff81c4;
        quadraticProduct = x2 * polynomial;
        correction = 0.5f * x2 - x2 * quadraticProduct;
        oneMinusCosine = 1.0f - (1.0f - correction);
        polynomial = fGpffff81c8 * x2 + fGpffff8054;
        polynomial = x2 * polynomial + fGpffff8058;
        polynomial = x2 * polynomial + fGpffff805c;
        polynomial = x2 * polynomial + fGpffff8060;
        polynomial = x2 * polynomial + fGpffff81cc;
        {
            f32 cubic = x2 * x;
            sine = x + cubic * polynomial;
        }
        rotation = func_003e0680(matrix, (const RwV3d *)D_007130B8, oneMinusCosine, sine, rwCOMBINEREPLACE);
        func_003e42e0(transformed, source, 4, rotation);
        func_003e0f40(rotation);
        for (vectorIndex = 0; vectorIndex < 4; vectorIndex++) {
            const RwV3d *s = &transformed[vectorIndex];
            RwV3d *d = &source[vectorIndex];

            *d = *s;
        }
    }
    for (pointIndex = 0; pointIndex < 4; pointIndex++) {
        RwV3d *p = &source[pointIndex];
        f32 *o = (f32 *)(points + pointIndex * 8);

        o[0] = ((SdkSpriteAttachment *)attachment)->x + ((f32)((SdkSpriteAttachment *)attachment)->offsetX + p->x) +
               (f32)((SdkSpriteSegment *)(MEMBER(s32, ((SdkSpriteAttachment *)attachment)->resource, SdkSpriteResource, segments) + (((SdkSpriteAttachment *)(attachment))->segment << 7)))->offsetX;
        {
            f32 subtotal;
            subtotal = ((SdkSpriteAttachment *)attachment)->y + ((f32)((SdkSpriteAttachment *)attachment)->offsetY + p->y);
            subtotal += (f32)((SdkSpriteSegment *)(MEMBER(s32, ((SdkSpriteAttachment *)attachment)->resource, SdkSpriteResource, segments) + (attachmentFields->segment << 7)))->offsetY;
            o[1] = subtotal;
        }
    }
}
#pragma pop

/* Advance sprite loading for each linked resource in list order. */
// FUN_0046AB40
void resourceLoadSprites(void)
{
    u8 *attachment = D_00724C08;
loop_1:
    if (attachment != NULL) {
        sdkSpriteLoadStep(attachment);
        attachment = ((SdkSpriteResourceLink *)attachment)->next;
        goto loop_1;
    }
}
