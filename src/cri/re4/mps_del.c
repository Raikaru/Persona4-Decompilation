/* CRI Sofdec MPS start-code classifier (mps_del.c): tells a 00 00 01 xx MPEG system start code
 * apart for the demuxer (pack 0xBA, system header 0xBB, program end 0xB9, packets >= 0xBC). */
#include "cri_xpt.h"

// Start-code class of the 4 bytes at p: 0x80000 program end (0xB9), 0x10000 pack (0xBA), 0x20000
// system header (0xBB), 0x40000 packet (0xBC..0xFF), 0 not a start code.
Uint32 MPS_CheckDelim(Uint8 *p)
{
	if (p[0] == 0 && p[1] == 0 && p[2] == 1) {
		switch (p[3]) {
		case 0xB9:
			return 0x80000;
		case 0xBA:
			return 0x10000;
		case 0xBB:
			return 0x20000;
		default:
			if (p[3] >= 0xBC) {
				return 0x40000;
			}
		}
	}
	return 0;
}
