.section .text
.set noat
.set noreorder
glabel func_001d9b90
    /* D9B90 001D9B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D9B94 001D9B94 0000BFFF */  sd         $31, 0x0($29)
    /* D9B98 001D9B98 3000828C */  lw         $2, 0x30($4)
    /* D9B9C 001D9B9C A2004390 */  lbu        $3, 0xA2($2)
    /* D9BA0 001D9BA0 01000224 */  addiu      $2, $0, 0x1
    /* D9BA4 001D9BA4 04106200 */  sllv       $2, $2, $3
    /* D9BA8 001D9BA8 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* D9BAC 001D9BAC 0800073C */  lui        $7, (0x80000 >> 16)
    /* D9BB0 001D9BB0 2410A700 */  and        $2, $5, $7
    /* D9BB4 001D9BB4 09004010 */  beqz       $2, .L001D9BDC
    /* D9BB8 001D9BB8 00000000 */   nop
    /* D9BBC 001D9BBC 2D380000 */  daddu      $7, $0, $0
    /* D9BC0 001D9BC0 2D400000 */  daddu      $8, $0, $0
    /* D9BC4 001D9BC4 1E00093C */  lui        $9, %hi(func_001d9b60)
    /* D9BC8 001D9BC8 609B2925 */  addiu      $9, $9, %lo(func_001d9b60)
    /* D9BCC 001D9BCC 3465070C */  jal        func_001d94d0
    /* D9BD0 001D9BD0 00000000 */   nop
    /* D9BD4 001D9BD4 06000010 */  b          .L001D9BF0
    /* D9BD8 001D9BD8 00000000 */   nop
  .L001D9BDC:
    /* D9BDC 001D9BDC 2D400000 */  daddu      $8, $0, $0
    /* D9BE0 001D9BE0 1E00093C */  lui        $9, %hi(func_001d9b60)
    /* D9BE4 001D9BE4 609B2925 */  addiu      $9, $9, %lo(func_001d9b60)
    /* D9BE8 001D9BE8 3465070C */  jal        func_001d94d0
    /* D9BEC 001D9BEC 00000000 */   nop
  .L001D9BF0:
    /* D9BF0 001D9BF0 0000BFDF */  ld         $31, 0x0($29)
    /* D9BF4 001D9BF4 1000BD27 */  addiu      $29, $29, 0x10
    /* D9BF8 001D9BF8 0800E003 */  jr         $31
    /* D9BFC 001D9BFC 00000000 */   nop
.size func_001d9b90, 0x70
