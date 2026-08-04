.section .text
.set noat
.set noreorder
glabel func_001f75b0
    /* F75B0 001F75B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F75B4 001F75B4 0000BFFF */  sd         $31, 0x0($29)
    /* F75B8 001F75B8 ACB3838F */  lw         $3, -0x4C54($28)
    /* F75BC 001F75BC 0C00638C */  lw         $3, 0xC($3)
    /* F75C0 001F75C0 40006330 */  andi       $3, $3, 0x40
    /* F75C4 001F75C4 0F006010 */  beqz       $3, .L001F7604
    /* F75C8 001F75C8 00000000 */   nop
    /* F75CC 001F75CC 01000424 */  addiu      $4, $0, 0x1
    /* F75D0 001F75D0 2D280000 */  daddu      $5, $0, $0
    /* F75D4 001F75D4 686A110C */  jal        func_0045a9a0
    /* F75D8 001F75D8 00000000 */   nop
    /* F75DC 001F75DC 02000424 */  addiu      $4, $0, 0x2
    /* F75E0 001F75E0 2D280000 */  daddu      $5, $0, $0
    /* F75E4 001F75E4 686A110C */  jal        func_0045a9a0
    /* F75E8 001F75E8 00000000 */   nop
    /* F75EC 001F75EC 03000424 */  addiu      $4, $0, 0x3
    /* F75F0 001F75F0 2D280000 */  daddu      $5, $0, $0
    /* F75F4 001F75F4 686A110C */  jal        func_0045a9a0
    /* F75F8 001F75F8 00000000 */   nop
    /* F75FC 001F75FC 2066110C */  jal        func_00459880
    /* F7600 001F7600 00000000 */   nop
  .L001F7604:
    /* F7604 001F7604 0000BFDF */  ld         $31, 0x0($29)
    /* F7608 001F7608 1000BD27 */  addiu      $29, $29, 0x10
    /* F760C 001F760C 0800E003 */  jr         $31
    /* F7610 001F7610 00000000 */   nop
    /* F7614 001F7614 00000000 */  nop
    /* F7618 001F7618 00000000 */  nop
    /* F761C 001F761C 00000000 */  nop
.size func_001f75b0, 0x70
