.section .text
.set noat
.set noreorder
glabel func_001dc9a0
    /* DC9A0 001DC9A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DC9A4 001DC9A4 1000BFFF */  sd         $31, 0x10($29)
    /* DC9A8 001DC9A8 0000B07F */  sq         $16, 0x0($29)
    /* DC9AC 001DC9AC 2D808000 */  daddu      $16, $4, $0
    /* DC9B0 001DC9B0 98000526 */  addiu      $5, $16, 0x98
    /* DC9B4 001DC9B4 6E008694 */  lhu        $6, 0x6E($4)
    /* DC9B8 001DC9B8 01000724 */  addiu      $7, $0, 0x1
    /* DC9BC 001DC9BC C45F070C */  jal        func_001d7f10
    /* DC9C0 001DC9C0 00000000 */   nop
    /* DC9C4 001DC9C4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DC9C8 001DC9C8 14004010 */  beqz       $2, .L001DCA1C
    /* DC9CC 001DC9CC 00000000 */   nop
    /* DC9D0 001DC9D0 2D200000 */  daddu      $4, $0, $0
    /* DC9D4 001DC9D4 08000010 */  b          .L001DC9F8
    /* DC9D8 001DC9D8 00000000 */   nop
  .L001DC9DC:
    /* DC9DC 001DC9DC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DC9E0 001DC9E0 80100200 */  sll        $2, $2, 2
    /* DC9E4 001DC9E4 21180202 */  addu       $3, $16, $2
    /* DC9E8 001DC9E8 9800628C */  lw         $2, 0x98($3)
    /* DC9EC 001DC9EC 380062AC */  sw         $2, 0x38($3)
    /* DC9F0 001DC9F0 01008224 */  addiu      $2, $4, 0x1
    /* DC9F4 001DC9F4 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DC9F8:
    /* DC9F8 001DC9F8 D0000396 */  lhu        $3, 0xD0($16)
    /* DC9FC 001DC9FC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DCA00 001DCA00 2A104300 */  slt        $2, $2, $3
    /* DCA04 001DCA04 F5FF4014 */  bnez       $2, .L001DC9DC
    /* DCA08 001DCA08 00000000 */   nop
    /* DCA0C 001DCA0C 6A0003A6 */  sh         $3, 0x6A($16)
    /* DCA10 001DCA10 01000224 */  addiu      $2, $0, 0x1
    /* DCA14 001DCA14 0B000010 */  b          .L001DCA44
    /* DCA18 001DCA18 00000000 */   nop
  .L001DCA1C:
    /* DCA1C 001DCA1C D0000496 */  lhu        $4, 0xD0($16)
    /* DCA20 001DCA20 5CC7080C */  jal        func_00231d70
    /* DCA24 001DCA24 00000000 */   nop
    /* DCA28 001DCA28 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DCA2C 001DCA2C 80100200 */  sll        $2, $2, 2
    /* DCA30 001DCA30 21105000 */  addu       $2, $2, $16
    /* DCA34 001DCA34 9800428C */  lw         $2, 0x98($2)
    /* DCA38 001DCA38 380002AE */  sw         $2, 0x38($16)
    /* DCA3C 001DCA3C 01000224 */  addiu      $2, $0, 0x1
    /* DCA40 001DCA40 6A0002A6 */  sh         $2, 0x6A($16)
  .L001DCA44:
    /* DCA44 001DCA44 1000BFDF */  ld         $31, 0x10($29)
    /* DCA48 001DCA48 0000B07B */  lq         $16, 0x0($29)
    /* DCA4C 001DCA4C 2000BD27 */  addiu      $29, $29, 0x20
    /* DCA50 001DCA50 0800E003 */  jr         $31
    /* DCA54 001DCA54 00000000 */   nop
    /* DCA58 001DCA58 00000000 */  nop
    /* DCA5C 001DCA5C 00000000 */  nop
.size func_001dc9a0, 0xc0
