#include "include_asm.h"
/* Original translation unit btlPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
typedef struct BtlPanel BtlPanel;
struct BtlPanel
{
    u8* records;    // 0x00
    u8 pad4[0x30];
    s32 field34;    // 0x34
    u8 pad38[4];
    s16 state;      // 0x3C
    s16 index;      // 0x3E
};

void func_00440b68();
extern u8* H_Cdvd_AcquireDirectory(u8* param, s32 mode);
void H_Cdvd_Destroy(u8* ptr);
s32 H_Cdvd_IsFileLoaded(u8* ptr);
s32 datGetFlag(s32 id);
s32 btlUnitFindInSideById(s32 a, s32 b);
s32 sdkSpriteCreateFromName(u32 param);
s32 hMaestroDecodeIsReady(s32 param);
s32 resourceFindByName(u32 param);
extern u8* kwlnTaskGetWork(s32 param);
extern char iGpffffa578;
extern s32 iGpffffa570;
extern char D_00626780[];
extern u8 D_00626790[];
extern u8 D_006267B0[];
extern u32 D_00626720[];
extern u8* btlPacketAlloc(u32 type, u32 workSize);
void memset(void* dst, s32 value, u32 size);
void H_Cdvd_ReadSync(u8* ptr);
s32 TnUploadStream(s32 param);
extern s32 iGpffffb470;
extern u8 D_006267D0[];



typedef struct {
    u32 flags;
    u8 pad04[0x28];
    s32 resources[16];
} BtlPanelResources;

/* 716/720 bytes; thirty-two resolved relocations; four zero alignment bytes.
 * Capture store indices but reload the panel index after readiness callbacks. */
// FUN_00202890
s32 btlPanelIsEnabled(void* param)
{
    BtlPanel* panel = (BtlPanel*)param;
    BtlPanelResources* recs = (BtlPanelResources*)kwlnTaskGetWork(panel->field34);
    s16 done = 0;
    s32 idx;
    u8* rec;

    switch (panel->state) {
    case 0:
        rec = panel->records;
        if (rec == NULL) {
            if (datGetFlag(0x1438) == 0) {
                func_00440b68(&iGpffffa578, D_00626780, 0x532);
                panel->records = H_Cdvd_AcquireDirectory(D_00626790, 1);
            } else {
                func_00440b68(&iGpffffa578, D_00626780, 0x534);
                panel->records = H_Cdvd_AcquireDirectory(D_006267B0, 1);
            }
            goto check;
        }
        if (H_Cdvd_IsFileLoaded(rec) != 0) {
            panel->state = 1;
        case 1:
            idx = panel->index;
            if (recs->resources[panel->index] == 0) {
                if (idx < 8) {
                    if (btlUnitFindInSideById(0, (idx + 1) & 0xFFFF) != 0) {
                        if (datGetFlag(0x1438) == 0 || idx != 0) {
                            recs->resources[idx] = sdkSpriteCreateFromName(D_00626720[idx]);
                        } else {
                            recs->resources[idx] = sdkSpriteCreateFromName(iGpffffa570);
                        }
                    } else {
                        recs->resources[idx] = 0;
                        panel->index++;
                    }
                } else if (idx < 0xC) {
                    recs->resources[idx] = sdkSpriteCreateFromName(D_00626720[idx]);
                }
            } else if (hMaestroDecodeIsReady(recs->resources[panel->index]) != 0) {
                if (++panel->index == 0xC) {
                    H_Cdvd_Destroy(panel->records);
                    panel->records = NULL;
                    done = 0xC;
                }
            }
        }
        break;
    default:
        break;
    }
check:
    if (done == 0xC) {
        for (idx = 0xC; idx < 0x10; idx++) {
            *(s32*)((u8*)recs + idx * 4 + 0x2C) = resourceFindByName(D_00626720[idx]);
        }
        recs->flags |= 1;
        return 1;
    }
    return 0;
}



// FUN_00202B60
s32 btlPanelIsEnabled(void* panel);

u8* btlPanelCreatePacket(s32 param)
{
    u8* p = btlPacketAlloc(0x508, 0x40);
    u8* rec;

    p[0x47] &= 0xFE;
    *(u32*)(p + 0x6C) = (u32)btlPanelIsEnabled;
    rec = *(u8**)(p + 0x78);
    memset(rec, 0, 0x40);
    *(s32*)(rec + 0x34) = param;
    return p;
}



// FUN_00202BE0
void btlPanelLoadSync(void)
{
    u8* t;

    func_00440b68(&iGpffffa578, D_00626780, 0x5FB);
    t = H_Cdvd_AcquireDirectory(D_006267D0, 0);
    H_Cdvd_ReadSync(t);
    iGpffffb470 = TnUploadStream(*(s32*)(t + 0x110));
    H_Cdvd_Destroy(t);
}
