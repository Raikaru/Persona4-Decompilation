#ifndef BTL_PACKET_CREATE_INTERNAL_H
#define BTL_PACKET_CREATE_INTERNAL_H

#include "type.h"

struct BtlAction;
struct BtlPacket;
struct BtlUnit;

/* Packet factories return the allocated packet so callers can attach the
 * action UID and dependency before submitting it to the dispatcher. */
struct BtlPacket *func_001f7d10(u16 channel, u16 cue, u16 variant);
struct BtlPacket *func_001f8140(u16 state);
/* These factories retain the unit in their four-byte work payload and return
 * the packet for dependency setup and submission by the opening controllers. */
struct BtlPacket *func_001f82b0(struct BtlUnit *unit);
struct BtlPacket *func_001f8330(struct BtlUnit *unit);
/* The selector arrives as a full word and is stored in a halfword work field. */
struct BtlPacket *func_001b9de0(struct BtlAction *action, u32 selector, u32 duration);
u8 *func_00202850(void);
/* Optional payloads contain three position floats, four quaternion floats,
 * and four color bytes, respectively. */
u8 *func_00195730(u8 *unit, u8 *position, u8 *rotation, u8 *color);

#endif
