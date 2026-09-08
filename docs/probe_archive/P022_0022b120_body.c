/* Complete plain-C probe; production remains ASM.
 * classification=ARGUMENT_MATERIALIZATION_NONMATCH;
 * object_size=1860; window=1872; retail_executable_bytes=1860;
 * executable_byte_diff=28; differing_executable_words=8;
 * fully_resolved_code_relocations=67; unresolved_relocations=0;
 * missing_executable_bytes=0; window_overrun=0; no jump table.
 * The final twelve retail bytes are zero alignment, not missing code.
 *
 * First complete candidate: 1860B, 88 differing bytes in 68 words.
 * Reordering four ordinary local declarations resolves every saved-register
 * difference. The only remaining differences are argument materialization
 * order at the two func_001ebb00 calls (offsets 0xc8-0xd4 and 0x400-0x40c).
 * The neighboring setup functions' opt_propagation off profile produced
 * identical bytes, so no pragma is retained in this candidate.
 *
 * All 23 packets, both live formation resources, callback/data pairs,
 * complete u64 dependencies and action UIDs, delays and queues are present.
 * The resource-start packet intentionally has no action UID assignment.
 * Real provider pointer-return contracts were corrected in production;
 * all eleven corrected constructors retain exact executable bytes and tails.
 * The four-byte color input is declared with its real extent. No guards,
 * stack padding, fixed registers, omitted arguments, or undefined reads.
 * No native-behavior or game-execution claim is made for this candidate.
 * Additional declarations assume the live owner's existing declarations.
 */
extern u8 D_00635560[];
extern u8 D_00635580[];
extern u8 iGpffffa4d8[4];
extern u8 *func_001ebb00(s32 arg0, s32 arg1, s32 arg2);
extern u8 *func_00194c90(void *callback, void *data);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, u16 id, u16 blendFrameCount, f32 speed, u16 mode);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rotation, u32 flags);
extern BtlPacket *func_0019b6a0(BtlUnit *unit);
extern u8 *func_0019b550(u8 *unit, s16 resourceId, s16 flags);
extern BtlPacket *func_001d7ab0(u8 *color, u16 duration);
extern BtlPacket *func_001d7b60(u16 duration);
extern BtlPacket *func_001b7e20(u32 duration);
extern BtlPacket *func_001b9360(s32 duration, s16 mode);
extern BtlPacket *func_001b99a0(s32 duration);
extern BtlPacket *func_001ba090(s32 duration);
extern BtlPacket *func_002305c0(s32 resourceId);
extern BtlPacket *func_00230650(void);
extern BtlPacket *func_002306d0(void);
extern BtlPacket *func_00230750(void);

void func_0022b120(u8 *action)
{
    u8 *unit;
    u8 *side0;
    u8 *side1;
    u8 *script;
    s32 formation0;
    s32 formation1;
    u8 *oldBgm;
    u8 *packet;
    RwV3d rotation;

    unit = *(u8 **)(action + 0x30);
    *(u32 *)(iGpffffb3ac + 0xC) |= 0x400000;
    *(u16 *)(iGpffffb3ac + 0x18) |= 0x23;
    func_001a03b0((s64 *)action);
    formation0 = func_001d3d50(0);
    formation1 = func_001d3d50(0);
    func_001d3ea0(formation0, (u32)func_0022ced0(0xC));
    func_001d3ea0(formation1, (u32)func_0022ced0(0xD));
    *(u32 *)(iGpffffb3ac + 0xC) |= 0x80000;

    script = func_001ebb00((s32)action, 3, (s32)D_00635560);
    *(u64 *)(script + 0x60) = *(u64 *)action;
    func_00194590(script, 1);

    packet = func_00194c90((void *)func_0022b0b0, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x13, 0, 1.0f, 2);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    packet = (u8 *)func_002306d0();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(packet + 0x48) = 0x33;
    func_00194590(packet, 1);

    side0 = (u8 *)func_001d6240((u32)formation0, (u32)unit, (u32)unit, 0, 0x200);
    side0[0] = 4;
    *(u64 *)(side0 + 8) = *(u64 *)(script + 0x58);
    *(u64 *)(side0 + 0x60) = *(u64 *)action;
    func_00194590(side0, 2);

    side1 = (u8 *)func_001d6240((u32)formation0, (u32)unit, (u32)unit, 1, 0x200);
    side1[0] = 4;
    *(u64 *)(side1 + 8) = *(u64 *)(script + 0x58);
    *(u64 *)(side1 + 0x60) = *(u64 *)action;
    func_00194590(side1, 2);

    packet = (u8 *)func_001d7ab0(iGpffffa4d8, 0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(packet + 0x48) = 0x19A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = (f32)3000;
    packet = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &rotation, 2);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(side0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(side1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    script = (u8 *)func_0019b6a0((BtlUnit *)unit);
    script[0] = 4;
    *(u64 *)(script + 8) = *(u64 *)(side0 + 0x58);
    script[0x10] = 4;
    *(u64 *)(script + 0x18) = *(u64 *)(side1 + 0x58);
    *(s16 *)(script + 0x48) = 1;
    *(u64 *)(script + 0x60) = *(u64 *)action;
    func_00194590(script, 1);

    packet = (u8 *)func_00230750();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(side0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(side1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    oldBgm = (u8 *)func_00230650();
    oldBgm[0] = 4;
    *(u64 *)(oldBgm + 8) = *(u64 *)(side0 + 0x58);
    oldBgm[0x10] = 4;
    *(u64 *)(oldBgm + 0x18) = *(u64 *)(side1 + 0x58);
    *(s16 *)(oldBgm + 0x48) = 3;
    *(u64 *)(oldBgm + 0x60) = *(u64 *)action;
    func_00194590(oldBgm, 1);

    side1 = func_0019b550(unit, 0x10E, 0x216);
    side1[0] = 4;
    *(u64 *)(side1 + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(side1 + 0x48) = 2;
    *(u64 *)(side1 + 0x60) = *(u64 *)action;
    func_00194590(side1, 1);

    script = func_001ebb00((s32)action, 3, (s32)D_00635580);
    script[0] = 4;
    *(u64 *)(script + 8) = *(u64 *)(side1 + 0x58);
    *(s16 *)(script + 0x48) = 2;
    *(s16 *)(script + 0x4A) = 0xC;
    *(u64 *)(script + 0x60) = *(u64 *)action;
    func_00194590(script, 1);

    packet = func_00194c90((void *)func_0022b0e0, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_002305c0(0x10E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(oldBgm + 0x58);
    *(s16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_0019bbe0((BtlUnit *)unit, (u32)-1, 1, 0, 3, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001d7b60(0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(packet + 0x48) = 4;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    side1 = (u8 *)func_001d6240((u32)formation1, (u32)unit, (u32)unit, 0, 0x200);
    side1[0] = 4;
    *(u64 *)(side1 + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(side1 + 0x48) = 2;
    *(u64 *)(side1 + 0x60) = *(u64 *)action;
    func_00194590(side1, 2);

    side0 = (u8 *)func_001d6240((u32)formation1, (u32)unit, (u32)unit, 1, 0x200);
    side0[0] = 4;
    *(u64 *)(side0 + 8) = *(u64 *)(script + 0x58);
    *(s16 *)(side0 + 0x48) = 2;
    *(u64 *)(side0 + 0x60) = *(u64 *)action;
    func_00194590(side0, 2);

    packet = (u8 *)func_001b7e20(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(side1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(side0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001b9360(0x10, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(side1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(side0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001b99a0(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(side1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(side0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 1);

    packet = (u8 *)func_001ba090(8);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(side1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(side0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    func_00194590(packet, 0);

    func_001d3e00(formation1);
    func_001d3e00(formation0);
}
