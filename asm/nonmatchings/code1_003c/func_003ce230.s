.section .text
.set noat
.set noreorder
glabel func_003ce230
    /* 2CE230 003CE230 0800858C */  lw         $5, 0x8($4)
    /* 2CE234 003CE234 2D180000 */  daddu      $3, $0, $0
    /* 2CE238 003CE238 01000224 */  addiu      $2, $0, 0x1
    /* 2CE23C 003CE23C 75000B3C */  lui        $11, %hi(jtbl_00752EC0)
    /* 2CE240 003CE240 2D384000 */  daddu      $7, $2, $0
    /* 2CE244 003CE244 2D404000 */  daddu      $8, $2, $0
    /* 2CE248 003CE248 2D504000 */  daddu      $10, $2, $0
    /* 2CE24C 003CE24C C02E6B25 */  addiu      $11, $11, %lo(jtbl_00752EC0)
  .L003CE250:
    /* 2CE250 003CE250 0000A68C */  lw         $6, 0x0($5)
    /* 2CE254 003CE254 FFFFC930 */  andi       $9, $6, 0xFFFF
    /* 2CE258 003CE258 02370600 */  srl        $6, $6, 28
    /* 2CE25C 003CE25C 0700C630 */  andi       $6, $6, 0x7
    /* 2CE260 003CE260 0800C12C */  sltiu      $1, $6, 0x8
    /* 2CE264 003CE264 18002010 */  beqz       $1, .L003CE2C8
    /* 2CE268 003CE268 00000000 */   nop
    /* 2CE26C 003CE26C 80300600 */  sll        $6, $6, 2
    /* 2CE270 003CE270 2130CB00 */  addu       $6, $6, $11
    /* 2CE274 003CE274 0000C68C */  lw         $6, 0x0($6)
    /* 2CE278 003CE278 0800C000 */  jr         $6
    /* 2CE27C 003CE27C 00000000 */   nop
    /* 2CE280 003CE280 11000010 */  b          .L003CE2C8
    /* 2CE284 003CE284 2D184001 */   daddu     $3, $10, $0
    /* 2CE288 003CE288 01002625 */  addiu      $6, $9, 0x1
    /* 2CE28C 003CE28C 00310600 */  sll        $6, $6, 4
    /* 2CE290 003CE290 0D000010 */  b          .L003CE2C8
    /* 2CE294 003CE294 2128A600 */   addu      $5, $5, $6
    /* 2CE298 003CE298 0400A98C */  lw         $9, 0x4($5)
    /* 2CE29C 003CE29C 0800868C */  lw         $6, 0x8($4)
    /* 2CE2A0 003CE2A0 2D100000 */  daddu      $2, $0, $0
    /* 2CE2A4 003CE2A4 00490900 */  sll        $9, $9, 4
    /* 2CE2A8 003CE2A8 2130C900 */  addu       $6, $6, $9
    /* 2CE2AC 003CE2AC 0400A6AC */  sw         $6, 0x4($5)
    /* 2CE2B0 003CE2B0 05000010 */  b          .L003CE2C8
    /* 2CE2B4 003CE2B4 1000A524 */   addiu     $5, $5, 0x10
    /* 2CE2B8 003CE2B8 03000010 */  b          .L003CE2C8
    /* 2CE2BC 003CE2BC 2D180001 */   daddu     $3, $8, $0
    /* 2CE2C0 003CE2C0 2D18E000 */  daddu      $3, $7, $0
    /* 2CE2C4 003CE2C4 00000000 */  nop
  .L003CE2C8:
    /* 2CE2C8 003CE2C8 2B300300 */  sltu       $6, $0, $3
    /* 2CE2CC 003CE2CC 0100C638 */  xori       $6, $6, 0x1
    /* 2CE2D0 003CE2D0 DFFFC014 */  bnez       $6, .L003CE250
    /* 2CE2D4 003CE2D4 00000000 */   nop
    /* 2CE2D8 003CE2D8 0800E003 */  jr         $31
    /* 2CE2DC 003CE2DC 00000000 */   nop
.size func_003ce230, 0xb0
