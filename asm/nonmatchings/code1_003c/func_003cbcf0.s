.section .text
.set noat
.set noreorder
glabel func_003cbcf0
    /* 2CBCF0 003CBCF0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2CBCF4 003CBCF4 4000BFFF */  sd         $31, 0x40($29)
    /* 2CBCF8 003CBCF8 3000B37F */  sq         $19, 0x30($29)
    /* 2CBCFC 003CBCFC 2000B27F */  sq         $18, 0x20($29)
    /* 2CBD00 003CBD00 2D988000 */  daddu      $19, $4, $0
    /* 2CBD04 003CBD04 1000B17F */  sq         $17, 0x10($29)
    /* 2CBD08 003CBD08 2D90A000 */  daddu      $18, $5, $0
    /* 2CBD0C 003CBD0C 0000B07F */  sq         $16, 0x0($29)
    /* 2CBD10 003CBD10 2C006226 */  addiu      $2, $19, 0x2C
    /* 2CBD14 003CBD14 10B7888F */  lw         $8, -0x48F0($28)
    /* 2CBD18 003CBD18 20004326 */  addiu      $3, $18, 0x20
    /* 2CBD1C 003CBD1C 0400B18C */  lw         $17, 0x4($5)
    /* 2CBD20 003CBD20 2D306002 */  daddu      $6, $19, $0
    /* 2CBD24 003CBD24 2C00878C */  lw         $7, 0x2C($4)
    /* 2CBD28 003CBD28 21804802 */  addu       $16, $18, $8
    /* 2CBD2C 003CBD2C 2000A7AC */  sw         $7, 0x20($5)
    /* 2CBD30 003CBD30 2400A2AC */  sw         $2, 0x24($5)
    /* 2CBD34 003CBD34 2C00828C */  lw         $2, 0x2C($4)
    /* 2CBD38 003CBD38 3D00053C */  lui        $5, %hi(func_003cb670)
    /* 2CBD3C 003CBD3C 70B6A524 */  addiu      $5, $5, %lo(func_003cb670)
    /* 2CBD40 003CBD40 040043AC */  sw         $3, 0x4($2)
    /* 2CBD44 003CBD44 2C0083AC */  sw         $3, 0x2C($4)
    /* 2CBD48 003CBD48 2400828C */  lw         $2, 0x24($4)
    /* 2CBD4C 003CBD4C 01004224 */  addiu      $2, $2, 0x1
    /* 2CBD50 003CBD50 240082AC */  sw         $2, 0x24($4)
    /* 2CBD54 003CBD54 2D204002 */  daddu      $4, $18, $0
    /* 2CBD58 003CBD58 CCFF0E0C */  jal        func_003bff30
    /* 2CBD5C 003CBD5C 000013AE */   sw        $19, 0x0($16)
    /* 2CBD60 003CBD60 3D00053C */  lui        $5, %hi(func_003cb6a0)
    /* 2CBD64 003CBD64 2D204002 */  daddu      $4, $18, $0
    /* 2CBD68 003CBD68 A0B6A524 */  addiu      $5, $5, %lo(func_003cb6a0)
    /* 2CBD6C 003CBD6C 14000F0C */  jal        func_003c0050
    /* 2CBD70 003CBD70 2D306002 */   daddu     $6, $19, $0
    /* 2CBD74 003CBD74 3D00053C */  lui        $5, %hi(func_003cb6d0)
    /* 2CBD78 003CBD78 2D204002 */  daddu      $4, $18, $0
    /* 2CBD7C 003CBD7C D0B6A524 */  addiu      $5, $5, %lo(func_003cb6d0)
    /* 2CBD80 003CBD80 F0FF0E0C */  jal        func_003bffc0
    /* 2CBD84 003CBD84 2D306002 */   daddu     $6, $19, $0
    /* 2CBD88 003CBD88 06002012 */  beqz       $17, .L003CBDA4
    /* 2CBD8C 003CBD8C 00000000 */   nop
    /* 2CBD90 003CBD90 10002426 */  addiu      $4, $17, 0x10
    /* 2CBD94 003CBD94 F8800F0C */  jal        func_003e03e0
    /* 2CBD98 003CBD98 2D280000 */   daddu     $5, $0, $0
    /* 2CBD9C 003CBD9C A0A50F0C */  jal        func_003e9680
    /* 2CBDA0 003CBDA0 2D202002 */   daddu     $4, $17, $0
  .L003CBDA4:
    /* 2CBDA4 003CBDA4 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CBDA8 003CBDA8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CBDAC 003CBDAC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CBDB0 003CBDB0 2D106002 */  daddu      $2, $19, $0
    /* 2CBDB4 003CBDB4 21186400 */  addu       $3, $3, $4
    /* 2CBDB8 003CBDB8 0800638C */  lw         $3, 0x8($3)
    /* 2CBDBC 003CBDBC 040003AE */  sw         $3, 0x4($16)
    /* 2CBDC0 003CBDC0 4000BFDF */  ld         $31, 0x40($29)
    /* 2CBDC4 003CBDC4 3000B37B */  lq         $19, 0x30($29)
    /* 2CBDC8 003CBDC8 2000B27B */  lq         $18, 0x20($29)
    /* 2CBDCC 003CBDCC 1000B17B */  lq         $17, 0x10($29)
    /* 2CBDD0 003CBDD0 0000B07B */  lq         $16, 0x0($29)
    /* 2CBDD4 003CBDD4 0800E003 */  jr         $31
    /* 2CBDD8 003CBDD8 5000BD27 */   addiu     $29, $29, 0x50
    /* 2CBDDC 003CBDDC 00000000 */  nop
.size func_003cbcf0, 0xf0
