.section .text
.set noat
.set noreorder
glabel func_003e89c0
    /* 2E89C0 003E89C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E89C4 003E89C4 8800043C */  lui        $4, %hi(D_008872F0)
    /* 2E89C8 003E89C8 0000BFFF */  sd         $31, 0x0($29)
    /* 2E89CC 003E89CC F0728424 */  addiu      $4, $4, %lo(D_008872F0)
    /* 2E89D0 003E89D0 0A000524 */  addiu      $5, $0, 0xA
    /* 2E89D4 003E89D4 1C00A627 */  addiu      $6, $29, 0x1C
    /* 2E89D8 003E89D8 2D380000 */  daddu      $7, $0, $0
    /* 2E89DC 003E89DC FCA10F0C */  jal        func_003e87f0
    /* 2E89E0 003E89E0 2D400000 */   daddu     $8, $0, $0
    /* 2E89E4 003E89E4 03004010 */  beqz       $2, .L003E89F4
    /* 2E89E8 003E89E8 00000000 */   nop
    /* 2E89EC 003E89EC 02000010 */  b          .L003E89F8
    /* 2E89F0 003E89F0 1C00A28F */   lw        $2, 0x1C($29)
  .L003E89F4:
    /* 2E89F4 003E89F4 FFFF0224 */  addiu      $2, $0, -0x1
  .L003E89F8:
    /* 2E89F8 003E89F8 0000BFDF */  ld         $31, 0x0($29)
    /* 2E89FC 003E89FC 0800E003 */  jr         $31
    /* 2E8A00 003E8A00 2000BD27 */   addiu     $29, $29, 0x20
    /* 2E8A04 003E8A04 00000000 */  nop
    /* 2E8A08 003E8A08 00000000 */  nop
    /* 2E8A0C 003E8A0C 00000000 */  nop
.size func_003e89c0, 0x50
