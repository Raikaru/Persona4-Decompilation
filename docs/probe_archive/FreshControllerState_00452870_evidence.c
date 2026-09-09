/*
 * func_00452870: controller state updater, 1136-byte retail window.
 * Production remains ASM. No defined ordinary-C replacement is supplied.
 *
 * Confirmed blocker: the six-byte actuator submission consumes four unwritten
 * caller stack bytes. At 00452B84/00452B88 only sp+0x40/sp+0x41 are written;
 * 00452B94 passes sp+0x40 to func_00430630. The remaining sp+0x42..0x45
 * have no earlier writes or output-pointer provider initialization in this
 * function. A two-byte C array would be read out of bounds; a six-byte array
 * with only those stores leaves an indeterminate tail. Initializing the tail
 * would add behavior and instructions absent from retail.
 *
 * Consumer proof from retail bytes, not the lossy generated C candidate:
 *   00430650: func_0042fdf0(port, slot, local_status)
 *   00430658..64: proceed when local_status[0x72] == 1
 *   00430698: source = entry_a2 + i
 *   0043069C: destination = command_packet + 0x0C + i
 *   004306A0: load unsigned source byte
 *   004306A4: ++i
 *   004306A8: continue while i < 6
 *   004306AC: store destination byte
 *   004306B0/B4: loop branch and delay slot
 *   004306C0/C8: packet command = 1; packet length = 6
 *   004306CC: submit through func_0042fa38
 *
 * Reachable caller predicate: reloaded state == 5, queried pad state in {2,6},
 * active mode == requested mode, and either requested actuator halfword differs
 * from its cached halfword. Port/slot were snapshotted before the initial state
 * query. The connected-state query at 00430060..80 reads status[0x70] and
 * status[0x71], not the consumer's status[0x72]. An open entry with status
 * bytes {6,0,1} satisfies both checks. No excluding predicate was found in
 * these actual call paths; this is not a claim of exhaustive IOP behavior.
 *
 * The alignment table passed at 00452A90 is gp-0x5388 = 00763D68. Its six
 * retail bytes are 00 01 FF FF FF FF. Regardless of unmapped-actuator behavior,
 * it does not gate the EE consumer's six source-byte reads.
 *
 * Execution proof: a bounded interpreter executed the original instruction
 * bytes at 00430698..004306B4, including delay slots: 48 instructions for each
 * six-byte copy. Equal initialized bytes and distinct remaining bytes gave:
 *   input/output A: 01 7F 12 34 56 78
 *   input/output B: 01 7F 98 BA DC FE
 * Both source read and destination write offsets were exactly 0..5. This
 * proves the retail copy-loop dependency, not controller hardware or DMA.
 *
 * Retained control-flow facts: set D_008C0000 = 255; snapshot port/slot from
 * offsets 8/A; call 00430018; reload offset-2 state; dispatch states 0,1,3,4,5;
 * update history halfwords at 10/1A/38; invert packet button bytes for IDs
 * 41/73/79; copy analog axes for IDs 73/79 or center all four to 0x80.
 * No candidate was compiled or integrated across the unsupported stack path.
 */
