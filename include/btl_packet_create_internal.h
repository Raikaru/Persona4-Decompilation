#ifndef BTL_PACKET_CREATE_INTERNAL_H
#define BTL_PACKET_CREATE_INTERNAL_H

#include "type.h"

struct BtlAction;
struct BtlPacket;
struct BtlUnit;
struct BtlMainLerpWork;

u32 btlMainUpdateTintLerp(struct BtlMainLerpWork *work);

/* Packet factories return the allocated packet so callers can attach the
 * action UID and dependency before submitting it to the dispatcher. */
struct BtlPacket *btlSoundCreateCuePacket(u16 channel, u16 cue, u16 variant);
struct BtlPacket *btlSoundCreateCueQueuePacket(u16 state);
/* These factories retain the unit in their four-byte work payload and return
 * the packet for dependency setup and submission by the opening controllers. */
struct BtlPacket *btlSoundCreateUnitFlagClearPacket(struct BtlUnit *unit);
struct BtlPacket *btlSoundCreateUnitFlagSetPacket(struct BtlUnit *unit);
/* The selector arrives as a full word and is stored in a halfword work field. */
struct BtlPacket *btlMainCreateUnitTintPacket(struct BtlAction *action, u32 selector, u32 duration);
// Intent: allocate the end-sequence packet (type 0x50E). [inferred]
u8 *btlPacketCreateEndSequence(void);
/* Optional payloads contain three position floats, four quaternion floats,
 * and four color bytes, respectively. */
u8 *btlUnitCreateOverridePacket(u8 *unit, u8 *position, u8 *rotation, u8 *color);

#endif
