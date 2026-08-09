.section .text
.set noat
.set noreorder
glabel func_001d9c00
    /* D9C00 001D9C00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D9C04 001D9C04 0000BFFF */  sd         $31, 0x0($29)
    /* D9C08 001D9C08 3000828C */  lw         $2, 0x30($4)
    /* D9C0C 001D9C0C A2004290 */  lbu        $2, 0xA2($2)
    /* D9C10 001D9C10 04004014 */  bnez       $2, .L001D9C24
    /* D9C14 001D9C14 00000000 */   nop
    /* D9C18 001D9C18 01000224 */  addiu      $2, $0, 0x1
    /* D9C1C 001D9C1C 02000010 */  b          .L001D9C28
    /* D9C20 001D9C20 00000000 */   nop
  .L001D9C24:
    /* D9C24 001D9C24 2D100000 */  daddu      $2, $0, $0
  .L001D9C28:
    /* D9C28 001D9C28 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* D9C2C 001D9C2C 0800073C */  lui        $7, (0x80000 >> 16)
    /* D9C30 001D9C30 2410A700 */  and        $2, $5, $7
    /* D9C34 001D9C34 0D004010 */  beqz       $2, .L001D9C6C
    /* D9C38 001D9C38 00000000 */   nop
    /* D9C3C 001D9C3C FFFF6330 */  andi       $3, $3, 0xFFFF
    /* D9C40 001D9C40 01000224 */  addiu      $2, $0, 0x1
    /* D9C44 001D9C44 04106200 */  sllv       $2, $2, $3
    /* D9C48 001D9C48 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* D9C4C 001D9C4C 2D380000 */  daddu      $7, $0, $0
    /* D9C50 001D9C50 2D400000 */  daddu      $8, $0, $0
    /* D9C54 001D9C54 1E00093C */  lui        $9, %hi(func_001d9b60)
    /* D9C58 001D9C58 609B2925 */  addiu      $9, $9, %lo(func_001d9b60)
    /* D9C5C 001D9C5C 3465070C */  jal        func_001d94d0
    /* D9C60 001D9C60 00000000 */   nop
    /* D9C64 001D9C64 0A000010 */  b          .L001D9C90
    /* D9C68 001D9C68 00000000 */   nop
  .L001D9C6C:
    /* D9C6C 001D9C6C FFFF6330 */  andi       $3, $3, 0xFFFF
    /* D9C70 001D9C70 01000224 */  addiu      $2, $0, 0x1
    /* D9C74 001D9C74 04106200 */  sllv       $2, $2, $3
    /* D9C78 001D9C78 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* D9C7C 001D9C7C 2D400000 */  daddu      $8, $0, $0
    /* D9C80 001D9C80 1E00093C */  lui        $9, %hi(func_001d9b60)
    /* D9C84 001D9C84 609B2925 */  addiu      $9, $9, %lo(func_001d9b60)
    /* D9C88 001D9C88 3465070C */  jal        func_001d94d0
    /* D9C8C 001D9C8C 00000000 */   nop
  .L001D9C90:
    /* D9C90 001D9C90 0000BFDF */  ld         $31, 0x0($29)
    /* D9C94 001D9C94 1000BD27 */  addiu      $29, $29, 0x10
    /* D9C98 001D9C98 0800E003 */  jr         $31
    /* D9C9C 001D9C9C 00000000 */   nop
.size func_001d9c00, 0xa0
