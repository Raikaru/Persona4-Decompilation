/* object_size=not_measured; window=4576; normalized_diff=not_measured; differing_offsets=not_applicable; classification=COP1_ACCUMULATOR_CHAIN_FLOOR+RECONSTRUCTION_SCALE; ruled_out=retail has no movz/movn, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; retail prologue is frame=0xB0 with sq s0-s5 and saved f20-f25; ordinary COP1 accumulator chains appear at 0x001365C0 (adda.s $f0,$f1 followed by madd.s $f1,$f3,$f2), so plain C cannot reproduce the retail bytes under H009; the window also contains repeated c.le.s 0x4F000000/trunc.w.s/mfc1/andi u8/u16 narrowing guards and many conditional UI draw branches; no body kept or probed further. */

/* Retail reconstruction outline (not compiled):
 * derive the normalized alpha from arg0+0 and draw optional 1/2/4/8/0x100/
 * 0x200/0x400/0x800/0x1000 UI sections; iterate 120-entry and 84-entry
 * stat tables; draw each selected persona via func_00137890; submit the
 * final gauge/icon draw through func_0034F9D0. */
