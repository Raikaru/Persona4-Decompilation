/* Original translation unit btlShuffleCard.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "btl_shuffle_card_internal.h"


extern void sflDataSetupQuadPanel(void);
extern void pscResAcquireMiscCardW00(void);
extern void btlShuffleCardUpdateCards(u8 *card);

extern void func_003dc740(void *dest, void *src, s32 mode, f32 angle);
extern void btlShuffleCardBindPacket(u8 *card, void *value);

extern void sflResGetSecondaryVector(u8 *card, f32 *out);

extern void sflDataSetupLayoutPanel(void);
extern void pscModelSetPersonaCard(u8 *card, s32 value);
extern void pscResAcquirePersonaCard(s32 card);
extern void sflDataSetupFramePanel(void);
extern void pscModelSetArcanaCard(u8 *card, u16 value, s32 mode);
extern void pscResAcquireArcanaCard(s32 card, s32 value);
extern void pscModelInitPanel(void);
extern void pscResAcquireMiscCardW01(void);
extern void sflResSetSecondaryVector(u8 *card, void *value);
extern void sflResSetPrimaryVector(u8 *card, void *value);
extern void sflResSetVector(u8 *card, void *value);
extern void pscPanelSetColor(u8 *card, void *value);
extern void pscModelScreenPos(void *card, const f32 *value, f32 fparg2, void *arg3);
extern f32 pscModelPanelScale(const f32 *value, f32 scale);
extern void pscModelSetParentFrame(u8 *card, s32 value);
extern void pscModelCopyVector(u8 *card, s32 value);
extern void pscModelStepAnimation(u8 *card);
extern void pscModelDraw(u8 *card);
extern void pscModelEnqueueDrawNode(s32 objectAddress, u8 *queue);
extern void pscResReleaseArcanaCard(s32 card, s32 value);
extern void pscResReleasePersonaCard(s32 card);
extern void pscResReleaseMiscCardW00(void);
extern void pscResReleaseMiscCardW01(void);
extern void *kwlnGetCamera(void);
extern void kAssertFail(const char *file, s32 line);
extern char D_0064E5B0[];

/* Retail float-pool constant at gp - 0x7C44 = 0x007614AC (8.133125f). */
f32 fGpffff83bc = 8.133125f;

void btlShuffleCardSetupLayout(u8 *card, s32 value);
extern void btlShuffleCardSetupFrame(u8 *card, s32 value, s32 mode);
void btlShuffleCardSetupQuad(u8 *card);
void btlShuffleCardReset(u8 *card);
void btlShuffleCardUpdateCards(u8 *card);
void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst);
void btlShuffleCardApplyScale(u8 *unit, f32 *src, f32 scale);
void btlShuffleCardAttachSprite(u8 *card, void *value);
void btlShuffleCardDetachSprite(u8 *card, void *value);
void btlShuffleCardSetTint(u8 *card, void *value, s32 mode, f32 angle);
void btlShuffleCardBindPacket(u8 *card, void *value);
void btlShuffleCardBindSlot(u8 *card, void *value);
f32 btlShuffleCardWidth(u8 *card);
f32 btlShuffleCardHeight(u8 *card);
u16 btlShuffleCardStateFlags(u8 *card);
void btlShuffleCardQueueDraw(u8 *card);
void btlShuffleCardQueueEnqueue(u8 *card, u8 *queue);
void btlShuffleCardUpdateState(u8 *card);

/* Initialize a panel from its kind and resource selector pair. */
// FUN_0036D990
void btlShuffleCardInit(u8 *card, u8 *specification)
{
    u16 resourceId;
    u16 index;
    switch (((BtlShuffleCardSpec *)specification)->kind) {
    case 0:
        btlShuffleCardSetupLayout(card, ((BtlShuffleCardSpec *)specification)->id);
        break;
    case 1:
        btlShuffleCardSetupFrame(card, (index = ((BtlShuffleCardSpec *)specification)->index, resourceId = ((BtlShuffleCardSpec *)specification)->id, resourceId), index);
        break;
    case 2:
        btlShuffleCardSetupQuad(card);
        break;
    case 3:
        btlShuffleCardReset(card);
        break;
    default:
        kAssertFail(D_0064E5B0, 0x72);
        break;
    }
}
/* Acquire the selected persona texture and initialize its panel state. */
// FUN_0036DA40
void btlShuffleCardSetupLayout(u8 *card, s32 personaId)
{
    sflDataSetupLayoutPanel();
    pscModelSetPersonaCard(card, personaId);
    pscResAcquirePersonaCard(personaId);
    btlShuffleCardUpdateCards(card);
}

/* Acquire the selected arcana texture and initialize its panel state. */
// FUN_0036DAA0
void btlShuffleCardSetupFrame(u8 *card, s32 arcanaId, s32 index)
{
    s32 resourceId;

    sflDataSetupFramePanel();
    resourceId = arcanaId & 0xFFFF;
    pscModelSetArcanaCard(card, resourceId, index);
    pscResAcquireArcanaCard(resourceId, index);
    btlShuffleCardUpdateCards(card);
}




/* Acquire the first miscellaneous card texture and initialize its panel. */
// FUN_0036DB20
void btlShuffleCardSetupQuad(u8 *card)
{
    sflDataSetupQuadPanel();
    pscResAcquireMiscCardW00();
    btlShuffleCardUpdateCards(card);
}

/* Acquire the second miscellaneous card texture and initialize its panel. */
// FUN_0036DB60
void btlShuffleCardReset(u8 *card)
{
    pscModelInitPanel();
    pscResAcquireMiscCardW01();
    btlShuffleCardUpdateCards(card);
}

/* Reset the panel transform and color, attach the camera frame, and mark its resource acquired. */
// FUN_0036DBA0
void btlShuffleCardUpdateCards(u8 *card)
{
    f32 scale[3];
    f32 axis[3];
    u8 color[4];

    ((BtlShuffleCard *)card)->packet = 0;
    scale[0] = 10.0f;
    scale[1] = 10.0f;
    scale[2] = 10.0f;
    btlShuffleCardDetachSprite(card, scale);
    axis[0] = 0.0f;
    axis[1] = 1.0f;
    axis[2] = 0.0f;
    btlShuffleCardSetTint(card, axis, 0, 0.0f);
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = 0xFF;
    btlShuffleCardBindSlot(card, color);
    /* measured: typing the camera parent pointer swaps the argument move/load (two instructions). */
    pscModelSetParentFrame(card, *(s32 *)((u8 *)kwlnGetCamera() + 4));
    ((BtlShuffleCard *)card)->flags |= 1;
}

/* Project a source position with the scale derived from this panel. */
// FUN_0036DC60
void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst)
{
    if (src == NULL) {
        kAssertFail(D_0064E5B0, 0xD4);
    }
    if (dst == NULL) {
        kAssertFail(D_0064E5B0, 0xD5);
    }
    pscModelScreenPos(unit, src, pscModelPanelScale((const f32 *)unit, scale), dst);
}

/* Project a source position and apply it to the panel transform. */
// FUN_0036DD10
void btlShuffleCardApplyScale(u8 *unit, f32 *src, f32 scale)
{
    f32 position[4];

    if (src == NULL) {
        kAssertFail(D_0064E5B0, 0xD4);
    }
    pscModelScreenPos(unit, src, pscModelPanelScale((const f32 *)unit, scale), position);
    btlShuffleCardAttachSprite(unit, position);
}

// FUN_0036DDA0
void btlShuffleCardAttachSprite(u8 *card, void *position)
{
    sflResSetPrimaryVector(card, position);
}

// FUN_0036DDC0
void btlShuffleCardDetachSprite(u8 *card, void *scale)
{
    sflResSetSecondaryVector(card, scale);
}




/* Build an axis-angle quaternion and store it in the panel. */
// FUN_0036DDE0
void btlShuffleCardSetTint(u8 *card, void *axis, s32 combine, f32 angle)
{
    f32 rotation[4];

    func_003dc740(rotation, axis, combine, angle);
    btlShuffleCardBindPacket(card, rotation);
}

// FUN_0036DE20
void btlShuffleCardBindPacket(u8 *card, void *rotation)
{
    sflResSetVector(card, rotation);
}

// FUN_0036DE40
void btlShuffleCardBindSlot(u8 *card, void *color)
{
    pscPanelSetColor(card, color);
}




/* Return the scaled width of the six-unit panel. */
// FUN_0036DE70
f32 btlShuffleCardWidth(u8 *card)
{
    f32 scale[3];

    sflResGetSecondaryVector(card, scale);
    return 6.0f * scale[0];
}

/* Return the scaled height using the retail panel aspect constant. */
// FUN_0036DEB0
f32 btlShuffleCardHeight(u8 *card)
{
    f32 scale[3];

    sflResGetSecondaryVector(card, scale);
    return fGpffff83bc * scale[1];
}

/* Return the persona selector after checking that this is a persona panel. */
// FUN_0036DEE0
u16 btlShuffleCardStateFlags(u8 *card)
{
    if (((BtlShuffleCard *)card)->model.mode != 0) {
        kAssertFail(D_0064E5B0, 0x160);
    }
    return *(u16 *)&((BtlShuffleCard *)card)->model.u.m01.unk174;
}

/* Copy an optional animation packet, advance the panel, and draw it. */
// FUN_0036DF30
void btlShuffleCardQueueDraw(u8 *card)
{
    s32 packet;

    packet = ((BtlShuffleCard *)card)->packet;
    if (packet != 0) {
        pscModelCopyVector(card + 0x600, packet);
    }
    pscModelStepAnimation(card);
    pscModelDraw(card);
}

/* The queue remains a pointer through the wrapper. The packet constructor
 * stores the card itself as an EE address word before queueing the draw. */
// FUN_0036DF90
void btlShuffleCardQueueEnqueue(u8 *card, u8 *queue)
{
    s32 packet;

    packet = ((BtlShuffleCard *)card)->packet;
    if (packet != 0) {
        pscModelCopyVector(card + 0x600, packet);
    }
    pscModelStepAnimation(card);
    pscModelEnqueueDrawNode((s32)card, queue);
}

/* Release the texture selected by the panel mode, once per acquired resource. */
// FUN_0036E000
void btlShuffleCardUpdateState(u8 *card)
{
    s32 handle;
    s32 state;
    BtlShuffleCard *panel = (BtlShuffleCard *)card;

    if (panel->flags & 1) {
        state = panel->model.mode;
        switch (state) {
        case 0:
            if (state != 0) {
                kAssertFail(D_0064E5B0, 0x160);
            }
            pscResReleasePersonaCard(*(u16 *)&panel->model.u.m01.unk174);
            break;
        case 1:
            if (state != 1) {
                kAssertFail(D_0064E5B0, 0x16A);
            }
            handle = panel->model.u.m01.unk170;
            if (panel->model.mode != 1) {
                kAssertFail(D_0064E5B0, 0x174);
            }
            pscResReleaseArcanaCard(handle, panel->model.u.m01.unk174);
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
        panel->flags &= ~1;
    }
}
