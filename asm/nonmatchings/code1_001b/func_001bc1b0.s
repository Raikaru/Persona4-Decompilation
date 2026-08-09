.section .text
.set noat
.set noreorder
glabel func_001bc1b0
    /* BC1B0 001BC1B0 E000838C */  lw         $3, 0xE0($4)
    /* BC1B4 001BC1B4 3000628C */  lw         $2, 0x30($3)
    /* BC1B8 001BC1B8 0C0A428C */  lw         $2, 0xA0C($2)
    /* BC1BC 001BC1BC 6E006494 */  lhu        $4, 0x6E($3)
    /* BC1C0 001BC1C0 10004010 */  beqz       $2, .L001BC204
    /* BC1C4 001BC1C4 00000000 */   nop
    /* BC1C8 001BC1C8 A4004394 */  lhu        $3, 0xA4($2)
    /* BC1CC 001BC1CC 80100300 */  sll        $2, $3, 2
    /* BC1D0 001BC1D0 21104300 */  addu       $2, $2, $3
    /* BC1D4 001BC1D4 40100200 */  sll        $2, $2, 1
    /* BC1D8 001BC1D8 21104300 */  addu       $2, $2, $3
    /* BC1DC 001BC1DC C0180200 */  sll        $3, $2, 3
    /* BC1E0 001BC1E0 E0B3828F */  lw         $2, -0x4C20($28)
    /* BC1E4 001BC1E4 21104300 */  addu       $2, $2, $3
    /* BC1E8 001BC1E8 00004294 */  lhu        $2, 0x0($2)
    /* BC1EC 001BC1EC 01004230 */  andi       $2, $2, 0x1
    /* BC1F0 001BC1F0 04004010 */  beqz       $2, .L001BC204
    /* BC1F4 001BC1F4 00000000 */   nop
    /* BC1F8 001BC1F8 2D100000 */  daddu      $2, $0, $0
    /* BC1FC 001BC1FC 0D000010 */  b          .L001BC234
    /* BC200 001BC200 00000000 */   nop
  .L001BC204:
    /* BC204 001BC204 BCB3838F */  lw         $3, -0x4C44($28)
    /* BC208 001BC208 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* BC20C 001BC20C 80100200 */  sll        $2, $2, 2
    /* BC210 001BC210 21104300 */  addu       $2, $2, $3
    /* BC214 001BC214 02004294 */  lhu        $2, 0x2($2)
    /* BC218 001BC218 10004230 */  andi       $2, $2, 0x10
    /* BC21C 001BC21C 04004010 */  beqz       $2, .L001BC230
    /* BC220 001BC220 00000000 */   nop
    /* BC224 001BC224 2D100000 */  daddu      $2, $0, $0
    /* BC228 001BC228 02000010 */  b          .L001BC234
    /* BC22C 001BC22C 00000000 */   nop
  .L001BC230:
    /* BC230 001BC230 01000224 */  addiu      $2, $0, 0x1
  .L001BC234:
    /* BC234 001BC234 0800E003 */  jr         $31
    /* BC238 001BC238 00000000 */   nop
    /* BC23C 001BC23C 00000000 */  nop
.size func_001bc1b0, 0x90
