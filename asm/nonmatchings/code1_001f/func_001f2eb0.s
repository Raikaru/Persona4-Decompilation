.section .text
.set noat
.set noreorder
glabel func_001f2eb0
    /* F2EB0 001F2EB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* F2EB4 001F2EB4 3000BFFF */  sd         $31, 0x30($29)
    /* F2EB8 001F2EB8 2000B27F */  sq         $18, 0x20($29)
    /* F2EBC 001F2EBC 1000B17F */  sq         $17, 0x10($29)
    /* F2EC0 001F2EC0 0000B07F */  sq         $16, 0x0($29)
    /* F2EC4 001F2EC4 2D908000 */  daddu      $18, $4, $0
    /* F2EC8 001F2EC8 2D88A000 */  daddu      $17, $5, $0
    /* F2ECC 001F2ECC 3000908C */  lw         $16, 0x30($4)
    /* F2ED0 001F2ED0 640A048E */  lw         $4, 0xA64($16)
    /* F2ED4 001F2ED4 9C0F090C */  jal        func_00243e70
    /* F2ED8 001F2ED8 00000000 */   nop
    /* F2EDC 001F2EDC 01000524 */  addiu      $5, $0, 0x1
    /* F2EE0 001F2EE0 11002516 */  bne        $17, $5, .L001F2F28
    /* F2EE4 001F2EE4 00000000 */   nop
    /* F2EE8 001F2EE8 F4034396 */  lhu        $3, 0x3F4($18)
    /* F2EEC 001F2EEC 54010224 */  addiu      $2, $0, 0x154
    /* F2EF0 001F2EF0 04006210 */  beq        $3, $2, .L001F2F04
    /* F2EF4 001F2EF4 00000000 */   nop
    /* F2EF8 001F2EF8 640A048E */  lw         $4, 0xA64($16)
    /* F2EFC 001F2EFC C8C7080C */  jal        func_00231f20
    /* F2F00 001F2F00 00000000 */   nop
  .L001F2F04:
    /* F2F04 001F2F04 640A048E */  lw         $4, 0xA64($16)
    /* F2F08 001F2F08 0800053C */  lui        $5, (0x80000 >> 16)
    /* F2F0C 001F2F0C BCC9080C */  jal        func_002326f0
    /* F2F10 001F2F10 00000000 */   nop
    /* F2F14 001F2F14 9C00038E */  lw         $3, 0x9C($16)
    /* F2F18 001F2F18 10006334 */  ori        $3, $3, 0x10
    /* F2F1C 001F2F1C 9C0003AE */  sw         $3, 0x9C($16)
    /* F2F20 001F2F20 14000010 */  b          .L001F2F74
    /* F2F24 001F2F24 00000000 */   nop
  .L001F2F28:
    /* F2F28 001F2F28 640A048E */  lw         $4, 0xA64($16)
    /* F2F2C 001F2F2C 2D280000 */  daddu      $5, $0, $0
    /* F2F30 001F2F30 C8C7080C */  jal        func_00231f20
    /* F2F34 001F2F34 00000000 */   nop
    /* F2F38 001F2F38 640A048E */  lw         $4, 0xA64($16)
    /* F2F3C 001F2F3C FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* F2F40 001F2F40 FFFF4534 */  ori        $5, $2, (0xFFFFFF & 0xFFFF)
    /* F2F44 001F2F44 BCC9080C */  jal        func_002326f0
    /* F2F48 001F2F48 00000000 */   nop
    /* F2F4C 001F2F4C 640A048E */  lw         $4, 0xA64($16)
    /* F2F50 001F2F50 0800053C */  lui        $5, (0x80000 >> 16)
    /* F2F54 001F2F54 A0C9080C */  jal        func_00232680
    /* F2F58 001F2F58 00000000 */   nop
    /* F2F5C 001F2F5C 9C00038E */  lw         $3, 0x9C($16)
    /* F2F60 001F2F60 01006434 */  ori        $4, $3, 0x1
    /* F2F64 001F2F64 9C0004AE */  sw         $4, 0x9C($16)
    /* F2F68 001F2F68 EFFF0324 */  addiu      $3, $0, -0x11
    /* F2F6C 001F2F6C 24188300 */  and        $3, $4, $3
    /* F2F70 001F2F70 9C0003AE */  sw         $3, 0x9C($16)
  .L001F2F74:
    /* F2F74 001F2F74 3000BFDF */  ld         $31, 0x30($29)
    /* F2F78 001F2F78 2000B27B */  lq         $18, 0x20($29)
    /* F2F7C 001F2F7C 1000B17B */  lq         $17, 0x10($29)
    /* F2F80 001F2F80 0000B07B */  lq         $16, 0x0($29)
    /* F2F84 001F2F84 4000BD27 */  addiu      $29, $29, 0x40
    /* F2F88 001F2F88 0800E003 */  jr         $31
    /* F2F8C 001F2F8C 00000000 */   nop
.size func_001f2eb0, 0xe0
