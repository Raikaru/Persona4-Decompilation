.section .text
.set noat
.set noreorder
glabel func_001ea180
    /* EA180 001EA180 C0FFBD27 */  addiu      $29, $29, -0x40
    /* EA184 001EA184 0000BFFF */  sd         $31, 0x0($29)
    /* EA188 001EA188 14740A0C */  jal        func_0029d050
    /* EA18C 001EA18C 00000000 */   nop
    /* EA190 001EA190 2D204000 */  daddu      $4, $2, $0
    /* EA194 001EA194 2D280000 */  daddu      $5, $0, $0
    /* EA198 001EA198 0800063C */  lui        $6, (0x80000 >> 16)
    /* EA19C 001EA19C 02000724 */  addiu      $7, $0, 0x2
    /* EA1A0 001EA1A0 2D400000 */  daddu      $8, $0, $0
    /* EA1A4 001EA1A4 1E00093C */  lui        $9, %hi(func_001dbb90)
    /* EA1A8 001EA1A8 90BB2925 */  addiu      $9, $9, %lo(func_001dbb90)
    /* EA1AC 001EA1AC 1000AA27 */  addiu      $10, $29, 0x10
    /* EA1B0 001EA1B0 E464070C */  jal        func_001d9390
    /* EA1B4 001EA1B4 00000000 */   nop
    /* EA1B8 001EA1B8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* EA1BC 001EA1BC 0D008018 */  blez       $4, .L001EA1F4
    /* EA1C0 001EA1C0 00000000 */   nop
    /* EA1C4 001EA1C4 5CC7080C */  jal        func_00231d70
    /* EA1C8 001EA1C8 00000000 */   nop
    /* EA1CC 001EA1CC 80100200 */  sll        $2, $2, 2
    /* EA1D0 001EA1D0 21105D00 */  addu       $2, $2, $29
    /* EA1D4 001EA1D4 1000428C */  lw         $2, 0x10($2)
    /* EA1D8 001EA1D8 0800438C */  lw         $3, 0x8($2)
    /* EA1DC 001EA1DC 0080023C */  lui        $2, (0x80000000 >> 16)
    /* EA1E0 001EA1E0 25206200 */  or         $4, $3, $2
    /* EA1E4 001EA1E4 D4730A0C */  jal        func_0029cf50
    /* EA1E8 001EA1E8 00000000 */   nop
    /* EA1EC 001EA1EC 04000010 */  b          .L001EA200
    /* EA1F0 001EA1F0 00000000 */   nop
  .L001EA1F4:
    /* EA1F4 001EA1F4 FFFF0424 */  addiu      $4, $0, -0x1
    /* EA1F8 001EA1F8 D4730A0C */  jal        func_0029cf50
    /* EA1FC 001EA1FC 00000000 */   nop
  .L001EA200:
    /* EA200 001EA200 01000224 */  addiu      $2, $0, 0x1
    /* EA204 001EA204 0000BFDF */  ld         $31, 0x0($29)
    /* EA208 001EA208 4000BD27 */  addiu      $29, $29, 0x40
    /* EA20C 001EA20C 0800E003 */  jr         $31
    /* EA210 001EA210 00000000 */   nop
    /* EA214 001EA214 00000000 */  nop
    /* EA218 001EA218 00000000 */  nop
    /* EA21C 001EA21C 00000000 */  nop
.size func_001ea180, 0xa0
