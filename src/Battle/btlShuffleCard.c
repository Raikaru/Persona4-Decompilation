/* Original translation unit btlShuffleCard.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"


extern void sflDataSetupQuadPanel(void);
extern void pscResAcquireMiscCardW00(void);
extern void btlShuffleCardUpdateCards(u8 *arg0);

extern void func_003dc740(void *dest, void *src, s32 mode, f32 fparg0);
extern void btlShuffleCardBindPacket(u8 *arg0, void *arg1);

extern void func_0036b5e0(u8 *arg0, f32 *out);

extern void sflDataSetupLayoutPanel(void);
extern void func_0036a820(u8 *arg0, s32 arg1);
extern void pscResAcquirePersonaCard(s32 arg0);
extern void sflDataSetupFramePanel(void);
extern void func_0036a880(u8 *arg0, u16 arg1, s32 arg2);
extern void pscResAcquireArcanaCard(s32 arg0, s32 arg1);
extern void func_00368d30(void);
extern void pscResAcquireMiscCardW01(void);
extern void func_0036b5a0(u8 *arg0, void *arg1);
extern void func_0036b5c0(u8 *arg0, void *arg1);
extern void func_0036b600(u8 *arg0, void *arg1);
extern void func_0036adc0(u8 *arg0, void *arg1);
extern void func_0036a6b0(void *arg0, const f32 *arg1, f32 fparg2, void *arg3);
extern f32 func_0036a790(const f32 *value, f32 scale);
extern void func_0036a8f0(u8 *arg0, s32 arg1);
extern void func_0036b630(u8 *arg0, s32 arg1);
extern void func_00368e80(u8 *arg0);
extern void func_003694d0(u8 *arg0);
extern void func_00369470(s32 objectAddress, u8 *queue);
extern void pscResReleaseArcanaCard(s32 arg0, s32 arg1);
extern void pscResReleasePersonaCard(s32 arg0);
extern void pscResReleaseMiscCardW00(void);
extern void pscResReleaseMiscCardW01(void);
extern void *func_00457120(void);
extern void kAssertFail(const char *file, s32 line);
extern char D_0064E5B0[];

/* Retail float-pool constant at gp - 0x7C44 = 0x007614AC (8.133125f). */
f32 fGpffff83bc = 8.133125f;

void btlShuffleCardSetupLayout(u8 *arg0, s32 arg1);
extern void btlShuffleCardSetupFrame(u8 *arg0, s32 arg1, s32 arg2);
void btlShuffleCardSetupQuad(u8 *arg0);
void btlShuffleCardReset(u8 *arg0);
void btlShuffleCardUpdateCards(u8 *arg0);
void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst);
void btlShuffleCardApplyScale(u8 *unit, f32 *src, f32 scale);
void btlShuffleCardAttachSprite(u8 *arg0, void *arg1);
void btlShuffleCardDetachSprite(u8 *arg0, void *arg1);
void btlShuffleCardSetTint(u8 *arg0, void *arg1, s32 arg2, f32 fparg0);
void btlShuffleCardBindPacket(u8 *arg0, void *arg1);
void btlShuffleCardBindSlot(u8 *arg0, void *arg1);
f32 btlShuffleCardWidth(u8 *arg0);
f32 btlShuffleCardHeight(u8 *arg0);
u16 btlShuffleCardStateFlags(u8 *arg0);
void btlShuffleCardQueueDraw(u8 *arg0);
void btlShuffleCardQueueEnqueue(u8 *arg0, u8 *queue);
void btlShuffleCardUpdateState(u8 *arg0);

// FUN_0036D990
void btlShuffleCardInit(u8 *arg0, u8 *arg1)
{
    u16 value1;
    u16 value2;
    switch (*(s32 *)arg1) {
    case 0:
        btlShuffleCardSetupLayout(arg0, *(u16 *)(arg1 + 4));
        break;
    case 1:
        btlShuffleCardSetupFrame(arg0, (value2 = *(u16 *)(arg1 + 6), value1 = *(u16 *)(arg1 + 4), value1), value2);
        break;
    case 2:
        btlShuffleCardSetupQuad(arg0);
        break;
    case 3:
        btlShuffleCardReset(arg0);
        break;
    default:
        kAssertFail(D_0064E5B0, 0x72);
        break;
    }
}
// FUN_0036DA40
void btlShuffleCardSetupLayout(u8 *arg0, s32 arg1)
{
    sflDataSetupLayoutPanel();
    func_0036a820(arg0, arg1);
    pscResAcquirePersonaCard(arg1);
    btlShuffleCardUpdateCards(arg0);
}

// FUN_0036DAA0
void btlShuffleCardSetupFrame(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 masked;

    sflDataSetupFramePanel();
    masked = arg1 & 0xFFFF;
    func_0036a880(arg0, masked, arg2);
    pscResAcquireArcanaCard(masked, arg2);
    btlShuffleCardUpdateCards(arg0);
}




// FUN_0036DB20
void btlShuffleCardSetupQuad(u8 *arg0)
{
    sflDataSetupQuadPanel();
    pscResAcquireMiscCardW00();
    btlShuffleCardUpdateCards(arg0);
}

// FUN_0036DB60
void btlShuffleCardReset(u8 *arg0)
{
    func_00368d30();
    pscResAcquireMiscCardW01();
    btlShuffleCardUpdateCards(arg0);
}

// FUN_0036DBA0
void btlShuffleCardUpdateCards(u8 *arg0)
{
    f32 sp30[3];
    f32 sp20[3];
    u8 sp3C[4];

    *(s32 *)(arg0 + 0xFA8) = 0;
    sp30[0] = 10.0f;
    sp30[1] = 10.0f;
    sp30[2] = 10.0f;
    btlShuffleCardDetachSprite(arg0, sp30);
    sp20[0] = 0.0f;
    sp20[1] = 1.0f;
    sp20[2] = 0.0f;
    btlShuffleCardSetTint(arg0, sp20, 0, 0.0f);
    sp3C[0] = 0xFF;
    sp3C[1] = 0xFF;
    sp3C[2] = 0xFF;
    sp3C[3] = 0xFF;
    btlShuffleCardBindSlot(arg0, sp3C);
    func_0036a8f0(arg0, *(s32 *)((u8 *)func_00457120() + 4));
    *(u16 *)(arg0 + 0xFAC) |= 1;
}

// FUN_0036DC60
void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst)
{
    if (src == NULL) {
        kAssertFail(D_0064E5B0, 0xD4);
    }
    if (dst == NULL) {
        kAssertFail(D_0064E5B0, 0xD5);
    }
    func_0036a6b0(unit, src, func_0036a790((const f32 *)unit, scale), dst);
}

// FUN_0036DD10
void btlShuffleCardApplyScale(u8 *unit, f32 *src, f32 scale)
{
    f32 sp40[4];

    if (src == NULL) {
        kAssertFail(D_0064E5B0, 0xD4);
    }
    func_0036a6b0(unit, src, func_0036a790((const f32 *)unit, scale), sp40);
    btlShuffleCardAttachSprite(unit, sp40);
}

// FUN_0036DDA0
void btlShuffleCardAttachSprite(u8 *arg0, void *arg1)
{
    func_0036b5c0(arg0, arg1);
}

// FUN_0036DDC0
void btlShuffleCardDetachSprite(u8 *arg0, void *arg1)
{
    func_0036b5a0(arg0, arg1);
}




// FUN_0036DDE0
void btlShuffleCardSetTint(u8 *arg0, void *arg1, s32 arg2, f32 fparg0)
{
    f32 sp20[4];

    func_003dc740(sp20, arg1, arg2, fparg0);
    btlShuffleCardBindPacket(arg0, sp20);
}

// FUN_0036DE20
void btlShuffleCardBindPacket(u8 *arg0, void *arg1)
{
    func_0036b600(arg0, arg1);
}

// FUN_0036DE40
void btlShuffleCardBindSlot(u8 *arg0, void *arg1)
{
    func_0036adc0(arg0, arg1);
}




// FUN_0036DE70
f32 btlShuffleCardWidth(u8 *arg0)
{
    f32 sp10[3];

    func_0036b5e0(arg0, sp10);
    return 6.0f * sp10[0];
}

// FUN_0036DEB0
f32 btlShuffleCardHeight(u8 *arg0)
{
    f32 sp10[3];

    func_0036b5e0(arg0, sp10);
    return fGpffff83bc * sp10[1];
}

// FUN_0036DEE0
u16 btlShuffleCardStateFlags(u8 *arg0)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        kAssertFail(D_0064E5B0, 0x160);
    }
    return *(u16 *)(arg0 + 0x174);
}

// FUN_0036DF30
void btlShuffleCardQueueDraw(u8 *arg0)
{
    s32 temp;

    temp = *(s32 *)(arg0 + 0xFA8);
    if (temp != 0) {
        func_0036b630(arg0 + 0x600, temp);
    }
    func_00368e80(arg0);
    func_003694d0(arg0);
}

/* The queue remains a pointer through the wrapper. The packet constructor
 * stores the card itself as an EE address word before queueing the draw. */
// FUN_0036DF90
void btlShuffleCardQueueEnqueue(u8 *arg0, u8 *queue)
{
    s32 temp;

    temp = *(s32 *)(arg0 + 0xFA8);
    if (temp != 0) {
        func_0036b630(arg0 + 0x600, temp);
    }
    func_00368e80(arg0);
    func_00369470((s32)arg0, queue);
}

// FUN_0036E000
void btlShuffleCardUpdateState(u8 *arg0)
{
    s32 handle;
    s32 state;

    if (*(u16 *)(arg0 + 0xFAC) & 1) {
        state = *(s32 *)(arg0 + 4);
        switch (state) {
        case 0:
            if (state != 0) {
                kAssertFail(D_0064E5B0, 0x160);
            }
            pscResReleasePersonaCard(*(u16 *)(arg0 + 0x174));
            break;
        case 1:
            if (state != 1) {
                kAssertFail(D_0064E5B0, 0x16A);
            }
            handle = *(s32 *)(arg0 + 0x170);
            if (*(s32 *)(arg0 + 4) != 1) {
                kAssertFail(D_0064E5B0, 0x174);
            }
            pscResReleaseArcanaCard(handle, *(s32 *)(arg0 + 0x174));
            break;
        case 2:
            pscResReleaseMiscCardW00();
            break;
        case 3:
            pscResReleaseMiscCardW01();
            break;
        default:
            kAssertFail(D_0064E5B0, 0x1E5);
            break;
        }
        *(u16 *)(arg0 + 0xFAC) &= ~1;
    }
}
