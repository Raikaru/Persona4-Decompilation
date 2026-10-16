/* Original translation unit sdkFiler.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "shd_misc_internal.h"
extern void (*jtbl_008873EC[])(void *ptr);


extern void strcpy(s8 *arg0, s32 *arg1);
extern void kwlnTaskDestroyWithHierarchy(u8 *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_00712A40[];
extern u8 D_00712A50[];
extern u8 D_00712AB0[];
extern s32 sprintf(char *buf, const char *fmt, ...);
extern char iGpffffb01c;
typedef struct { f32 a; f32 b; } F2;
s32 func_00468260(u8 *arg0);
extern s32 func_00467bd0(u8 *arg0);
extern void func_004680c0(u8 *arg0);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0256[];
extern u8 *D_00712AA0[];
extern void PrimDrawFlatRectangle(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern char iGpffffb030;

void func_004685c0(u8 *arg0);




// FUN_00468170
u8 *func_00468170(void *arg0, const char *arg1) {
    u8 *work;
    u8 *temp;

    chkmemAllocSiteTag(D_00712A40, 0x1AB);
    work = D_008873F4[0](1, 0x81094, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    temp = kwlnTaskCreateChild((void *)(arg0), (const void *)(D_00712A50), 0x100, 0, 0, func_00467bd0, func_004680c0, (u8 *)(work));
    if (temp == NULL) {
        return NULL;
    }
    sprintf((char *)work, &iGpffffb01c, arg1);
    return temp;
}

/* measured: b210 CSEs the four D_008C0256 button-mask reads into one
   register; retail re-loads per test. Each read spells its address in a
   different integer domain (&arr[0], (u8 *)+0, (u32), (s32)) so the CSE
   keys differ and the loads stay separate -- 3 differing words (padding
   only, MATCH), matching the previous spelling exactly. */
// FUN_00468260
s32 func_00468260(u8 *arg0) {
    u8 *filer;
    u8 *slot;
    u8 *slotFlag;
    s32 state;
    s32 idx;
    u16 buttons;

    filer = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)filer;
    switch (state) {
    case 0:
        *(s32 *)(filer + 0x30) |= 1;
        *(s32 *)filer = 1;
        break;
    case 1:
        buttons = D_008C024E[0];
        if (buttons & 0x800) {
            *(s32 *)filer = 2;
        } else if (buttons & 0x40) {
            if (*(s32 *)(filer + 0xC) == 0x14) {
                idx = *(s32 *)(filer + 0xC);
                *(s8 *)(idx + (u32)filer + 0x10) = *(s8 *)(D_00712AA0[*(s32 *)(filer + 8)] + *(s32 *)(filer + 4));
            } else {
                idx = *(s32 *)(filer + 0xC);
                *(s8 *)(idx + (u32)filer + 0x10) = *(s8 *)(D_00712AA0[*(s32 *)(filer + 8)] + *(s32 *)(filer + 4));
                *(s32 *)(filer + 0xC) += 1;
                idx = *(s32 *)(filer + 0xC);
                *(s8 *)(idx + (u32)filer + 0x10) = 0;
            }
        } else if (buttons & 0x20) {
            if (*(s32 *)(filer + 0xC) == 0) {
                slot = (u8 *)(*(s32 *)(filer + 0xC) + (u32)filer);
                slotFlag = slot + 0x10;
                if (*(s8 *)slotFlag == 0) {
                    *(s32 *)filer = 2;
                } else {
                    *(s8 *)slotFlag = 0;
                }
            } else {
                *(s8 *)((u8 *)(*(s32 *)(filer + 0xC) + (u32)filer) + 0x10) = 0;
                *(s32 *)(filer + 0xC) -= 1;
            }
        } else if (D_008C0252[0] & 0x1000) {
            if (*(s32 *)(filer + 8) != 0) {
                *(s32 *)(filer + 8) -= 1;
            } else if (buttons & 0x1000) {
                *(s32 *)(filer + 8) = 3;
            }
        } else if (D_008C0252[0] & 0x4000) {
            if (*(s32 *)(filer + 8) != 3) {
                *(s32 *)(filer + 8) += 1;
            } else if (buttons & 0x4000) {
                *(s32 *)(filer + 8) = 0;
            }
        } else if (D_008C0252[0] & 0x8000) {
            if (*(s32 *)(filer + 4) != 0) {
                *(s32 *)(filer + 4) -= 1;
            } else if (buttons & 0x8000) {
                *(s32 *)(filer + 4) = 9;
            }
        } else if (D_008C0252[0] & 0x2000) {
            if (*(s32 *)(filer + 4) != 9) {
                *(s32 *)(filer + 4) += 1;
            } else if (buttons & 0x2000) {
                *(s32 *)(filer + 4) = 0;
            }
        }
        if (*(u16 *)&D_008C0256[0] & 0x1000) {
            *(f32 *)(filer + 0x2C) -= 5.0f;
        }
        if (*(u16 *)((u8 *)D_008C0256 + 0) & 0x4000) {
            *(f32 *)(filer + 0x2C) += 5.0f;
        }
        if (*(u16 *)((u32)&D_008C0256[0]) & 0x8000) {
            *(f32 *)(filer + 0x28) -= 5.0f;
        }
        if (*(u16 *)((s32)&D_008C0256[0]) & 0x2000) {
            *(f32 *)(filer + 0x28) += 5.0f;
        }
        break;
    case 2:
        break;
    }
    if (*(s32 *)(filer + 0x30) & 1) {
        func_004685c0(filer);
    }
    return 0;
}

// FUN_004685c0
void func_004685c0(u8 *arg0) {
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
    work.pos[0] = (s32)*(f32 *)(arg0 + 0x28);
    work.pos[1] = (s32)(*(f32 *)(arg0 + 0x2C) - 12.0f);
    work.size[0] = 0xF0;
    work.size[1] = 0x0C;
    PrimDrawFlatRectangle(work.color.rgba, work.pos, 0.0f, 1);

    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0;
    work.color.rgba[0] = 0;
    work.color.rgba[1] = 0x46;
    work.pos[0] = (s32)*(f32 *)(arg0 + 0x28);
    work.pos[1] = (s32)*(f32 *)(arg0 + 0x2C);
    work.size[0] = 0x78;
    work.size[1] = 0x30;
    PrimDrawFlatRectangle(work.color.rgba, work.pos, 0.0f, 1);

    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0x50;
    work.color.rgba[0] = 0x50;
    work.color.rgba[1] = 0x50;
    work.pos[0] = (s32)(12.0f * (f32)*(s32 *)(arg0 + 4) +
                        *(f32 *)(arg0 + 0x28) + 0.0f);
    work.pos[1] = (s32)(12.0f * (f32)*(s32 *)(arg0 + 8) +
                        *(f32 *)(arg0 + 0x2C) + 0.0f);
    work.size[0] = 0x0C;
    work.size[1] = 0x0C;
    PrimDrawFlatRectangle(work.color.rgba, work.pos, 0.0f, 1);

    work.position.xy.x = *(f32 *)(arg0 + 0x28);
    work.position.xy.y = *(f32 *)(arg0 + 0x2C);
    for (i = 0; i < 4; i++) {
        func_00450dd0(work.position, 0.0f, &iGpffffb01c,
                      D_00712AA0[i]);
        work.position.xy.y += 12.0f;
    }

    work.position.xy.x = *(f32 *)(arg0 + 0x28);
    work.position.xy.y = *(f32 *)(arg0 + 0x2C) - 12.0f;
    func_00450dd0(work.position, 0.0f, &iGpffffb01c, arg0 + 0x10);

    work.position.xy.x = (12.0f * (f32)*(s32 *)(arg0 + 4) +
                  *(f32 *)(arg0 + 0x28) + 0.0f);
    work.position.xy.y = (12.0f * (f32)*(s32 *)(arg0 + 8) +
                  *(f32 *)(arg0 + 0x2C) + 0.0f);
    work.color.rgba[3] = 0x80;
    work.color.rgba[2] = 0;
    work.color.rgba[0] = 0xFF;
    work.color.rgba[1] = 0;
    glyph = *(s8 *)(D_00712AA0[*(s32 *)(arg0 + 8)] +
                    *(s32 *)(arg0 + 4));
    func_00450e80(work.color, work.position, 0.0f,
                  &iGpffffb030, glyph);
}

// FUN_004688A0
void func_004688a0(u8 *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_004688D0
s32 func_004688d0(u8 *arg0, s8 *arg1)
{
    s32 *temp_16 = *(s32 **)(arg0 + 0x38);

    strcpy(arg1, (s32 *)((u8 *)temp_16 + 0x10));
    if (*temp_16 == 2) {
        kwlnTaskDestroyWithHierarchy(arg0);
        return 1;
    }
    return 0;
}

// FUN_00468940
u8 *func_00468940(u8 *arg0, s64 arg1) {
    s64 sp38;
    u8 *work;
    u8 *temp;

    sp38 = arg1;
    chkmemAllocSiteTag(D_00712A40, 0x283);
    work = D_008873F4[0](1, 0x34, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    temp = kwlnTaskCreateChild((void *)(arg0), (const void *)(D_00712AB0), 0x100, 0, 0, func_00468260, func_004688a0, (u8 *)(work));
    if (temp == NULL) {
        return NULL;
    }
    *(F2 *)(work + 0x28) = *(F2 *)&sp38;
    return temp;
}

