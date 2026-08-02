.section .text
.set noat
.set noreorder
glabel func_0034c4a0
    /* 24C4A0 0034C4A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 24C4A4 0034C4A4 0000BFFF */  sd         $31, 0x0($29)
    /* 24C4A8 0034C4A8 1800A327 */  addiu      $3, $29, 0x18
    /* 24C4AC 0034C4AC 08000224 */  addiu      $2, $0, 0x8
    /* 24C4B0 0034C4B0 08006010 */  beqz       $3, .L0034C4D4
    /* 24C4B4 0034C4B4 00000000 */   nop
  .L0034C4B8:
    /* 24C4B8 0034C4B8 000060A0 */  sb         $0, 0x0($3)
    /* 24C4BC 0034C4BC 01006324 */  addiu      $3, $3, 0x1
    /* 24C4C0 0034C4C0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 24C4C4 0034C4C4 00000000 */  nop
    /* 24C4C8 0034C4C8 00000000 */  nop
    /* 24C4CC 0034C4CC FAFF4014 */  bnez       $2, .L0034C4B8
    /* 24C4D0 0034C4D0 00000000 */   nop
  .L0034C4D4:
    /* 24C4D4 0034C4D4 8800043C */  lui        $4, %hi(D_00882FF0)
    /* 24C4D8 0034C4D8 F02F8424 */  addiu      $4, $4, %lo(D_00882FF0)
    /* 24C4DC 0034C4DC 1800A5DF */  ld         $5, 0x18($29)
    /* 24C4E0 0034C4E0 FF000624 */  addiu      $6, $0, 0xFF
    /* 24C4E4 0034C4E4 40310D0C */  jal        func_0034c500
    /* 24C4E8 0034C4E8 00000000 */   nop
    /* 24C4EC 0034C4EC 0000BFDF */  ld         $31, 0x0($29)
    /* 24C4F0 0034C4F0 2000BD27 */  addiu      $29, $29, 0x20
    /* 24C4F4 0034C4F4 0800E003 */  jr         $31
    /* 24C4F8 0034C4F8 00000000 */   nop
    /* 24C4FC 0034C4FC 00000000 */  nop
.size func_0034c4a0, 0x60
