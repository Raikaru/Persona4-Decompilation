.section .text
.set noat
.set noreorder
glabel func_003d4d80
    /* 2D4D80 003D4D80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D4D84 003D4D84 0000BFFF */  sd         $31, 0x0($29)
    /* 2D4D88 003D4D88 B86D0E0C */  jal        func_0039b6e0
    /* 2D4D8C 003D4D8C 01100424 */   addiu     $4, $0, 0x1001
    /* 2D4D90 003D4D90 B8B9848F */  lw         $4, -0x4648($28)
    /* 2D4D94 003D4D94 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2D4D98 003D4D98 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2D4D9C 003D4D9C 21186400 */  addu       $3, $3, $4
    /* 2D4DA0 003D4DA0 05004010 */  beqz       $2, .L003D4DB8
    /* 2D4DA4 003D4DA4 5C0062AC */   sw        $2, 0x5C($3)
    /* 2D4DA8 003D4DA8 34300F0C */  jal        func_003cc0d0
    /* 2D4DAC 003D4DAC 2D204000 */   daddu     $4, $2, $0
    /* 2D4DB0 003D4DB0 0E000010 */  b          .L003D4DEC
    /* 2D4DB4 003D4DB4 01000224 */   addiu     $2, $0, 0x1
  .L003D4DB8:
    /* 2D4DB8 003D4DB8 34300F0C */  jal        func_003cc0d0
    /* 2D4DBC 003D4DBC 2D200000 */   daddu     $4, $0, $0
    /* 2D4DC0 003D4DC0 02000324 */  addiu      $3, $0, 0x2
    /* 2D4DC4 003D4DC4 0080023C */  lui        $2, (0x80000006 >> 16)
    /* 2D4DC8 003D4DC8 7100053C */  lui        $5, %hi(D_0070B590)
    /* 2D4DCC 003D4DCC 1800A3AF */  sw         $3, 0x18($29)
    /* 2D4DD0 003D4DD0 06004434 */  ori        $4, $2, (0x80000006 & 0xFFFF)
    /* 2D4DD4 003D4DD4 647D0F0C */  jal        func_003df590
    /* 2D4DD8 003D4DD8 90B5A524 */   addiu     $5, $5, %lo(D_0070B590)
    /* 2D4DDC 003D4DDC 1C00A2AF */  sw         $2, 0x1C($29)
    /* 2D4DE0 003D4DE0 347D0F0C */  jal        func_003df4d0
    /* 2D4DE4 003D4DE4 1800A427 */   addiu     $4, $29, 0x18
    /* 2D4DE8 003D4DE8 01000224 */  addiu      $2, $0, 0x1
  .L003D4DEC:
    /* 2D4DEC 003D4DEC 0000BFDF */  ld         $31, 0x0($29)
    /* 2D4DF0 003D4DF0 0800E003 */  jr         $31
    /* 2D4DF4 003D4DF4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D4DF8 003D4DF8 00000000 */  nop
    /* 2D4DFC 003D4DFC 00000000 */  nop
.size func_003d4d80, 0x80
