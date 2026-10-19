#include "include_asm.h"
/* Original translation unit btlPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "btl_effect_internal.h"
#include "h_cdvd_internal.h"
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

extern u8* H_Cdvd_AcquireDirectory(u8* param, s32 mode);
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
/* Incrementally load party/common sprites, release the archive, and publish panel readiness. Measured:
 * direct resources[index] store reverses addu operands at offset 628; keep that indexed store raw. */
s32 btlPanelIsEnabled(void* panelData)
{
    BtlPanel* panel = (BtlPanel*)panelData;
    BtlPanelResources* resources = (BtlPanelResources*)kwlnTaskGetWork(panel->field34);
    s16 done = 0;
    s32 index;
    u8* archive;

    switch (panel->state) {
    case 0:
        archive = panel->records;
        if (archive == NULL) {
            if (datGetFlag(0x1438) == 0) {
                func_00440b68(&iGpffffa578, D_00626780, 0x532);
                panel->records = H_Cdvd_AcquireDirectory(D_00626790, 1);
            } else {
                func_00440b68(&iGpffffa578, D_00626780, 0x534);
                panel->records = H_Cdvd_AcquireDirectory(D_006267B0, 1);
            }
            goto check;
        }
        if (H_Cdvd_IsFileLoaded((HCdvd *)archive) != 0) {
            panel->state = 1;
        case 1:
            index = panel->index;
            if (resources->resources[panel->index] == 0) {
                if (index < 8) {
                    if (btlUnitFindInSideById(0, (index + 1) & 0xFFFF) != 0) {
                        if (datGetFlag(0x1438) == 0 || index != 0) {
                            resources->resources[index] = sdkSpriteCreateFromName(D_00626720[index]);
                        } else {
                            resources->resources[index] = sdkSpriteCreateFromName(iGpffffa570);
                        }
                    } else {
                        resources->resources[index] = 0;
                        panel->index++;
                    }
                } else if (index < 0xC) {
                    resources->resources[index] = sdkSpriteCreateFromName(D_00626720[index]);
                }
            } else if (hMaestroDecodeIsReady(resources->resources[panel->index]) != 0) {
                if (++panel->index == 0xC) {
                    H_Cdvd_Destroy((HCdvd *)panel->records);
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
        for (index = 0xC; index < 0x10; index++) {
            *(s32 *)((u8 *)resources + index * 4 + 0x2C) = resourceFindByName(D_00626720[index]);
        }
        resources->flags |= 1;
        return 1;
    }
    return 0;
}



// FUN_00202B60
s32 btlPanelIsEnabled(void* panel);

/* Create the panel resource loader packet, clear its work, and associate it with the owning task. */
u8* btlPanelCreatePacket(s32 ownerTask)
{
    u8* packet = btlPacketAlloc(0x508, 0x40);
    u8* work;

    ((BtlPacket *)packet)->flags &= 0xFE;
    *(u32 *)&((BtlPacket *)packet)->updateFunc = (u32)btlPanelIsEnabled;
    work = (u8 *)((BtlPacket *)packet)->workData;
    memset(work, 0, 0x40);
    ((BtlPanel *)work)->field34 = ownerTask;
    return packet;
}



// FUN_00202BE0
/* Synchronously acquire the panel stream archive, upload its file image, and release the directory
 * handle. */
void btlPanelLoadSync(void)
{
    u8* t;

    func_00440b68(&iGpffffa578, D_00626780, 0x5FB);
    t = H_Cdvd_AcquireDirectory(D_006267D0, 0);
    H_Cdvd_ReadSync(t);
    iGpffffb470 = TnUploadStream((s32)((HCdvd *)t)->fileMemory);
    H_Cdvd_Destroy((HCdvd *)t);
}
