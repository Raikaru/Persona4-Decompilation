.section .text
.set noat
.set noreorder
glabel func_003c1c70
    /* 2C1C70 003C1C70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C1C74 003C1C74 FF0F0524 */  addiu      $5, $0, 0xFFF
    /* 2C1C78 003C1C78 1000BFFF */  sd         $31, 0x10($29)
    /* 2C1C7C 003C1C7C 0000B07F */  sq         $16, 0x0($29)
    /* 2C1C80 003C1C80 0E008284 */  lh         $2, 0xE($4)
    /* 2C1C84 003C1C84 2D808000 */  daddu      $16, $4, $0
    /* 2C1C88 003C1C88 01004224 */  addiu      $2, $2, 0x1
    /* 2C1C8C 003C1C8C A4080F0C */  jal        func_003c2290
    /* 2C1C90 003C1C90 0E0082A4 */   sh        $2, 0xE($4)
    /* 2C1C94 003C1C94 7100043C */  lui        $4, %hi(D_0070AFB0)
    /* 2C1C98 003C1C98 2D280002 */  daddu      $5, $16, $0
    /* 2C1C9C 003C1C9C 088F0F0C */  jal        func_003e3c20
    /* 2C1CA0 003C1CA0 B0AF8424 */   addiu     $4, $4, %lo(D_0070AFB0)
    /* 2C1CA4 003C1CA4 5C00048E */  lw         $4, 0x5C($16)
    /* 2C1CA8 003C1CA8 06008010 */  beqz       $4, .L003C1CC4
    /* 2C1CAC 003C1CAC 00000000 */   nop
    /* 2C1CB0 003C1CB0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C1CB4 003C1CB4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C1CB8 003C1CB8 09F84000 */  jalr       $2
    /* 2C1CBC 003C1CBC 00000000 */   nop
    /* 2C1CC0 003C1CC0 5C0000AE */  sw         $0, 0x5C($16)
  .L003C1CC4:
    /* 2C1CC4 003C1CC4 68120F0C */  jal        func_003c49a0
    /* 2C1CC8 003C1CC8 20000426 */   addiu     $4, $16, 0x20
    /* 2C1CCC 003C1CCC 0E000386 */  lh         $3, 0xE($16)
    /* 2C1CD0 003C1CD0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2C1CD4 003C1CD4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2C1CD8 003C1CD8 0E0003A6 */  sh         $3, 0xE($16)
    /* 2C1CDC 003C1CDC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2C1CE0 003C1CE0 09F84000 */  jalr       $2
    /* 2C1CE4 003C1CE4 2D200002 */   daddu     $4, $16, $0
    /* 2C1CE8 003C1CE8 1000BFDF */  ld         $31, 0x10($29)
    /* 2C1CEC 003C1CEC 01000224 */  addiu      $2, $0, 0x1
    /* 2C1CF0 003C1CF0 0000B07B */  lq         $16, 0x0($29)
    /* 2C1CF4 003C1CF4 0800E003 */  jr         $31
    /* 2C1CF8 003C1CF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2C1CFC 003C1CFC 00000000 */  nop
.size func_003c1c70, 0x90
