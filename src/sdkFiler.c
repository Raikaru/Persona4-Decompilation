/* Original translation unit sdkFiler.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "shd_misc_internal.h"
#include "sdktask.h"
extern void (*jtbl_008873EC[])(void *ptr);


extern void strcpy(s8 *, s32 *);
extern void kwlnTaskDestroyWithHierarchy(u8 *);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_00712A40[];
extern u8 D_00712A50[];
extern u8 D_00712AB0[];
extern s32 sprintf(char *buf, const char *fmt, ...);
extern char iGpffffb01c;
typedef struct { f32 a; f32 b; } F2;

/* The selector constructor allocates 0x34 bytes; input and drawing establish
 * the character buffer, grid selection, position and redraw flag. */
typedef struct SdkFilerSelector {
    s32 state;
    s32 column;
    s32 row;
    s32 textLength;
    s8 text[0x18];
    F2 position;
    s32 flags;
} SdkFilerSelector;
s32 sdkFilerSelectorUpdate(u8 *arg0);
extern s32 sdkFilerTaskUpdate(u8 *);
extern void sdkFilerFreeTaskWork(u8 *);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0256[];
extern u8 *D_00712AA0[];
extern void PrimDrawFlatRectangle(void *, void *, f32 , s32 );
extern char iGpffffb030;

void sdkFilerSelectorDraw(u8 *arg0);




/* Allocates filer work, creates the child task and copies its initial path. */
// FUN_00468170
u8 *sdkFilerTaskCreate(void *parent, const char *path) {
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_00712A40, 0x1AB);
    work = D_008873F4[0](1, 0x81094, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreateChild((void *)(parent), (const void *)(D_00712A50), 0x100, 0, 0, sdkFilerTaskUpdate, sdkFilerFreeTaskWork, (u8 *)(work));
    if (task == NULL) {
        return NULL;
    }
    sprintf((char *)work, &iGpffffb01c, path);
    return task;
}

/* measured: b210 CSEs the four D_008C0256 button-mask reads into one
   register; retail re-loads per test. Each read spells its address in a
   different integer domain (&arr[0], (u8 *)+0, (u32), (s32)) so the CSE
   keys differ and the loads stay separate -- 3 differing words (padding
   only, MATCH), matching the previous spelling exactly. */
/* Processes character-grid movement, text editing and screen-position input. */
/* measured: the remaining selector field accesses change whole-owner instructions when typed individually. Character rows remain byte-indexed; button-mask address domains retain the measured reloads. */
// FUN_00468260
s32 sdkFilerSelectorUpdate(u8 *task) {
    u8 *filer;
    u8 *slot;
    u8 *slotFlag;
    s32 state;
    s32 textIndex;
    u16 buttons;

    filer = ((SdkTask *)task)->work;
    state = ((SdkFilerSelector *)filer)->state;
    switch (state) {
    case 0:
        ((SdkFilerSelector *)filer)->flags |= 1;
        ((SdkFilerSelector *)filer)->state = 1;
        break;
    case 1:
        buttons = D_008C024E[0];
        if (buttons & 0x800) {
            ((SdkFilerSelector *)filer)->state = 2;
        } else if (buttons & 0x40) {
            if (((SdkFilerSelector *)filer)->textLength == 0x14) {
                textIndex = ((SdkFilerSelector *)filer)->textLength;
                *(s8 *)(textIndex + (u32)filer + 0x10) = *(s8 *)(D_00712AA0[((SdkFilerSelector *)filer)->row] + ((SdkFilerSelector *)filer)->column);
            } else {
                textIndex = ((SdkFilerSelector *)filer)->textLength;
                *(s8 *)(textIndex + (u32)filer + 0x10) = *(s8 *)(D_00712AA0[((SdkFilerSelector *)filer)->row] + ((SdkFilerSelector *)filer)->column);
                *(s32 *)(filer + 0xC) += 1;
                textIndex = *(s32 *)(filer + 0xC);
                *(s8 *)(textIndex + (u32)filer + 0x10) = 0;
            }
        } else if (buttons & 0x20) {
            if (((SdkFilerSelector *)filer)->textLength == 0) {
                slot = (u8 *)(((SdkFilerSelector *)filer)->textLength + (u32)filer);
                slotFlag = slot + 0x10;
                if (*(s8 *)slotFlag == 0) {
                    ((SdkFilerSelector *)filer)->state = 2;
                } else {
                    *(s8 *)slotFlag = 0;
                }
            } else {
                *(s8 *)((u8 *)(((SdkFilerSelector *)filer)->textLength + (u32)filer) + 0x10) = 0;
                *(s32 *)(filer + 0xC) -= 1;
            }
        } else if (D_008C0252[0] & 0x1000) {
            if (((SdkFilerSelector *)filer)->row != 0) {
                *(s32 *)(filer + 8) -= 1;
            } else if (buttons & 0x1000) {
                *(s32 *)(filer + 8) = 3;
            }
        } else if (D_008C0252[0] & 0x4000) {
            if (((SdkFilerSelector *)filer)->row != 3) {
                *(s32 *)(filer + 8) += 1;
            } else if (buttons & 0x4000) {
                *(s32 *)(filer + 8) = 0;
            }
        } else if (D_008C0252[0] & 0x8000) {
            if (((SdkFilerSelector *)filer)->column != 0) {
                *(s32 *)(filer + 4) -= 1;
            } else if (buttons & 0x8000) {
                *(s32 *)(filer + 4) = 9;
            }
        } else if (D_008C0252[0] & 0x2000) {
            if (((SdkFilerSelector *)filer)->column != 9) {
                *(s32 *)(filer + 4) += 1;
            } else if (buttons & 0x2000) {
                *(s32 *)(filer + 4) = 0;
            }
        }
        if (*(u16 *)&D_008C0256[0] & 0x1000) {
            ((SdkFilerSelector *)filer)->position.b -= 5.0f;
        }
        if (*(u16 *)((u8 *)D_008C0256 + 0) & 0x4000) {
            ((SdkFilerSelector *)filer)->position.b += 5.0f;
        }
        if (*(u16 *)((u32)&D_008C0256[0]) & 0x8000) {
            ((SdkFilerSelector *)filer)->position.a -= 5.0f;
        }
        if (*(u16 *)((s32)&D_008C0256[0]) & 0x2000) {
            ((SdkFilerSelector *)filer)->position.a += 5.0f;
        }
        break;
    case 2:
        break;
    }
    if (((SdkFilerSelector *)filer)->flags & 1) {
        sdkFilerSelectorDraw(filer);
    }
    return 0;
}

/* Draws the selector text, character grid, selection marker and preview glyph. */
/* measured: the remaining selector field accesses change whole-owner instructions when typed individually. Character rows remain byte-indexed; button-mask address domains retain the measured reloads. */
// FUN_004685c0
void sdkFilerSelectorDraw(u8 *selector) {
    struct {
        s32 pos[2];
        s32 size[2];
        PackedVec2f position;
        u8 pad[4];
        PackedColor4 color;
    } work;
    s8 glyph;
    s32 i;

    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0;
    work.color.rgba[0] = 0;
    work.color.rgba[1] = 0;
    work.pos[0] = (s32)((SdkFilerSelector *)selector)->position.a;
    work.pos[1] = (s32)(((SdkFilerSelector *)selector)->position.b - 12.0f);
    work.size[0] = 0xF0;
    work.size[1] = 0x0C;
    PrimDrawFlatRectangle(work.color.rgba, work.pos, 0.0f, 1);

    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0;
    work.color.rgba[0] = 0;
    work.color.rgba[1] = 0x46;
    work.pos[0] = (s32)*(f32 *)(selector + 0x28);
    work.pos[1] = (s32)*(f32 *)(selector + 0x2C);
    work.size[0] = 0x78;
    work.size[1] = 0x30;
    PrimDrawFlatRectangle(work.color.rgba, work.pos, 0.0f, 1);

    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0x50;
    work.color.rgba[0] = 0x50;
    work.color.rgba[1] = 0x50;
    work.pos[0] = (s32)(12.0f * (f32)((SdkFilerSelector *)selector)->column +
                        *(f32 *)(selector + 0x28) + 0.0f);
    work.pos[1] = (s32)(12.0f * (f32)((SdkFilerSelector *)selector)->row +
                        *(f32 *)(selector + 0x2C) + 0.0f);
    work.size[0] = 0x0C;
    work.size[1] = 0x0C;
    PrimDrawFlatRectangle(work.color.rgba, work.pos, 0.0f, 1);

    work.position.xy.x = *(f32 *)(selector + 0x28);
    work.position.xy.y = *(f32 *)(selector + 0x2C);
    for (i = 0; i < 4; i++) {
        sdkDbprtPrint(work.position, 0.0f, &iGpffffb01c,
                      D_00712AA0[i]);
        work.position.xy.y += 12.0f;
    }

    work.position.xy.x = *(f32 *)(selector + 0x28);
    work.position.xy.y = *(f32 *)(selector + 0x2C) - 12.0f;
    sdkDbprtPrint(work.position, 0.0f, &iGpffffb01c, selector + 0x10);

    work.position.xy.x = (12.0f * (f32)*(s32 *)(selector + 4) +
                  *(f32 *)(selector + 0x28) + 0.0f);
    work.position.xy.y = (12.0f * (f32)*(s32 *)(selector + 8) +
                  *(f32 *)(selector + 0x2C) + 0.0f);
    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0;
    work.color.rgba[0] = 0xFF;
    work.color.rgba[1] = 0;
    glyph = *(s8 *)(D_00712AA0[*(s32 *)(selector + 8)] +
                    *(s32 *)(selector + 4));
    sdkDbprtPrintColor(work.color, work.position, 0.0f,
                  &iGpffffb030, glyph);
}

// FUN_004688A0
void sdkFilerSelectorDestroy(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

/* Copies the edited text and destroys the task when selection has finished. */
// FUN_004688D0
s32 sdkFilerSelectorPoll(u8 *task, s8 *output)
{
    s32 *selectorWords = (s32 *)((SdkTask *)task)->work;

    strcpy(output, (s32 *)((u8 *)selectorWords + 0x10));
    if (*selectorWords == 2) {
        kwlnTaskDestroyWithHierarchy(task);
        return 1;
    }
    return 0;
}

/* Allocates a 0x34-byte selector, creates its child task and stores its packed position. */
// FUN_00468940
u8 *sdkFilerSelectorCreate(u8 *parent, s64 positionBits) {
    s64 savedPosition;
    u8 *work;
    u8 *task;

    savedPosition = positionBits;
    chkmemAllocSiteTag(D_00712A40, 0x283);
    work = D_008873F4[0](1, 0x34, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreateChild((void *)(parent), (const void *)(D_00712AB0), 0x100, 0, 0, sdkFilerSelectorUpdate, sdkFilerSelectorDestroy, (u8 *)(work));
    if (task == NULL) {
        return NULL;
    }
    ((SdkFilerSelector *)work)->position = *(F2 *)&savedPosition;
    return task;
}

