.section .text
.set noat
.set noreorder
glabel func_003efac0
    /* 2EFAC0 003EFAC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EFAC4 003EFAC4 8900083C */  lui        $8, %hi(D_0088B3D0)
    /* 2EFAC8 003EFAC8 2000BFFF */  sd         $31, 0x20($29)
    /* 2EFACC 003EFACC 7100023C */  lui        $2, %hi(D_0070B800)
    /* 2EFAD0 003EFAD0 1000B17F */  sq         $17, 0x10($29)
    /* 2EFAD4 003EFAD4 04000624 */  addiu      $6, $0, 0x4
    /* 2EFAD8 003EFAD8 0000B07F */  sq         $16, 0x0($29)
    /* 2EFADC 003EFADC 2D888000 */  daddu      $17, $4, $0
    /* 2EFAE0 003EFAE0 00B8448C */  lw         $4, %lo(D_0070B800)($2)
    /* 2EFAE4 003EFAE4 D0B30825 */  addiu      $8, $8, %lo(D_0088B3D0)
    /* 2EFAE8 003EFAE8 E0B785AF */  sw         $5, -0x4820($28)
    /* 2EFAEC 003EFAEC C0AB858F */  lw         $5, -0x5440($28)
    /* 2EFAF0 003EFAF0 C4AB878F */  lw         $7, -0x543C($28)
    /* 2EFAF4 003EFAF4 0400023C */  lui        $2, (0x40006 >> 16)
    /* 2EFAF8 003EFAF8 88840F0C */  jal        func_003e1220
    /* 2EFAFC 003EFAFC 06004934 */   ori       $9, $2, (0x40006 & 0xFFFF)
    /* 2EFB00 003EFB00 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EFB04 003EFB04 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EFB08 003EFB08 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EFB0C 003EFB0C 21186400 */  addu       $3, $3, $4
    /* 2EFB10 003EFB10 080062AC */  sw         $2, 0x8($3)
    /* 2EFB14 003EFB14 0800628C */  lw         $2, 0x8($3)
    /* 2EFB18 003EFB18 03004014 */  bnez       $2, .L003EFB28
    /* 2EFB1C 003EFB1C 00000000 */   nop
    /* 2EFB20 003EFB20 77000010 */  b          .L003EFD00
    /* 2EFB24 003EFB24 2D100000 */   daddu     $2, $0, $0
  .L003EFB28:
    /* 2EFB28 003EFB28 7100023C */  lui        $2, %hi(D_0070B820)
    /* 2EFB2C 003EFB2C 8900083C */  lui        $8, %hi(D_0088B3A0)
    /* 2EFB30 003EFB30 20B8448C */  lw         $4, %lo(D_0070B820)($2)
    /* 2EFB34 003EFB34 04000624 */  addiu      $6, $0, 0x4
    /* 2EFB38 003EFB38 C8AB858F */  lw         $5, -0x5438($28)
    /* 2EFB3C 003EFB3C A0B30825 */  addiu      $8, $8, %lo(D_0088B3A0)
    /* 2EFB40 003EFB40 CCAB878F */  lw         $7, -0x5434($28)
    /* 2EFB44 003EFB44 0400023C */  lui        $2, (0x40408 >> 16)
    /* 2EFB48 003EFB48 88840F0C */  jal        func_003e1220
    /* 2EFB4C 003EFB4C 08044934 */   ori       $9, $2, (0x40408 & 0xFFFF)
    /* 2EFB50 003EFB50 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFB54 003EFB54 8800063C */  lui        $6, %hi(D_008872E0)
    /* 2EFB58 003EFB58 E072C624 */  addiu      $6, $6, %lo(D_008872E0)
    /* 2EFB5C 003EFB5C 2118C300 */  addu       $3, $6, $3
    /* 2EFB60 003EFB60 0C0062AC */  sw         $2, 0xC($3)
    /* 2EFB64 003EFB64 0C00628C */  lw         $2, 0xC($3)
    /* 2EFB68 003EFB68 4B004010 */  beqz       $2, .L003EFC98
    /* 2EFB6C 003EFB6C 00000000 */   nop
    /* 2EFB70 003EFB70 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EFB74 003EFB74 0300023C */  lui        $2, (0x30016 >> 16)
    /* 2EFB78 003EFB78 000063AC */  sw         $3, 0x0($3)
    /* 2EFB7C 003EFB7C 16004534 */  ori        $5, $2, (0x30016 & 0xFFFF)
    /* 2EFB80 003EFB80 E4B7838F */  lw         $3, -0x481C($28)
    /* 2EFB84 003EFB84 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2EFB88 003EFB88 2120C400 */  addu       $4, $6, $4
    /* 2EFB8C 003EFB8C 040084AC */  sw         $4, 0x4($4)
    /* 2EFB90 003EFB90 0C00848C */  lw         $4, 0xC($4)
    /* 2EFB94 003EFB94 01006324 */  addiu      $3, $3, 0x1
    /* 2EFB98 003EFB98 F873428C */  lw         $2, %lo(D_008873F8)($2)
    /* 2EFB9C 003EFB9C 09F84000 */  jalr       $2
    /* 2EFBA0 003EFBA0 E4B783AF */   sw        $3, -0x481C($28)
    /* 2EFBA4 003EFBA4 2D804000 */  daddu      $16, $2, $0
    /* 2EFBA8 003EFBA8 44000012 */  beqz       $16, .L003EFCBC
    /* 2EFBAC 003EFBAC 00000000 */   nop
    /* 2EFBB0 003EFBB0 06000224 */  addiu      $2, $0, 0x6
    /* 2EFBB4 003EFBB4 8800073C */  lui        $7, %hi(D_008872E0)
    /* 2EFBB8 003EFBB8 000002A2 */  sb         $2, 0x0($16)
    /* 2EFBBC 003EFBBC 7100043C */  lui        $4, %hi(D_0070B820)
    /* 2EFBC0 003EFBC0 010000A2 */  sb         $0, 0x1($16)
    /* 2EFBC4 003EFBC4 E072E724 */  addiu      $7, $7, %lo(D_008872E0)
    /* 2EFBC8 003EFBC8 020000A2 */  sb         $0, 0x2($16)
    /* 2EFBCC 003EFBCC 10000626 */  addiu      $6, $16, 0x10
    /* 2EFBD0 003EFBD0 030000A2 */  sb         $0, 0x3($16)
    /* 2EFBD4 003EFBD4 08000226 */  addiu      $2, $16, 0x8
    /* 2EFBD8 003EFBD8 040000AE */  sw         $0, 0x4($16)
    /* 2EFBDC 003EFBDC 20B88424 */  addiu      $4, $4, %lo(D_0070B820)
    /* 2EFBE0 003EFBE0 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFBE4 003EFBE4 2D280002 */  daddu      $5, $16, $0
    /* 2EFBE8 003EFBE8 2118E300 */  addu       $3, $7, $3
    /* 2EFBEC 003EFBEC 0000638C */  lw         $3, 0x0($3)
    /* 2EFBF0 003EFBF0 100003AE */  sw         $3, 0x10($16)
    /* 2EFBF4 003EFBF4 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFBF8 003EFBF8 2118E300 */  addu       $3, $7, $3
    /* 2EFBFC 003EFBFC 140003AE */  sw         $3, 0x14($16)
    /* 2EFC00 003EFC00 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFC04 003EFC04 2118E300 */  addu       $3, $7, $3
    /* 2EFC08 003EFC08 0000638C */  lw         $3, 0x0($3)
    /* 2EFC0C 003EFC0C 040066AC */  sw         $6, 0x4($3)
    /* 2EFC10 003EFC10 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFC14 003EFC14 2118E300 */  addu       $3, $7, $3
    /* 2EFC18 003EFC18 000066AC */  sw         $6, 0x0($3)
    /* 2EFC1C 003EFC1C 080002AE */  sw         $2, 0x8($16)
    /* 2EFC20 003EFC20 DC8E0F0C */  jal        func_003e3b70
    /* 2EFC24 003EFC24 0C0002AE */   sw        $2, 0xC($16)
  .L003EFC28:
    /* 2EFC28 003EFC28 E0B7828F */  lw         $2, -0x4820($28)
    /* 2EFC2C 003EFC2C 8800083C */  lui        $8, %hi(D_008872E0)
    /* 2EFC30 003EFC30 E0720825 */  addiu      $8, $8, %lo(D_008872E0)
    /* 2EFC34 003EFC34 21180201 */  addu       $3, $8, $2
    /* 2EFC38 003EFC38 100070AC */  sw         $16, 0x10($3)
    /* 2EFC3C 003EFC3C 1000628C */  lw         $2, 0x10($3)
    /* 2EFC40 003EFC40 20004010 */  beqz       $2, .L003EFCC4
    /* 2EFC44 003EFC44 D8B790AF */   sw        $16, -0x4828($28)
    /* 2EFC48 003EFC48 E0B7878F */  lw         $7, -0x4820($28)
    /* 2EFC4C 003EFC4C 3F00063C */  lui        $6, %hi(func_003eef60)
    /* 2EFC50 003EFC50 1C0060AC */  sw         $0, 0x1C($3)
    /* 2EFC54 003EFC54 3F00053C */  lui        $5, %hi(func_003eea90)
    /* 2EFC58 003EFC58 3F00043C */  lui        $4, %hi(func_003eeae0)
    /* 2EFC5C 003EFC5C 3F00033C */  lui        $3, %hi(func_003eda60)
    /* 2EFC60 003EFC60 60EFC624 */  addiu      $6, $6, %lo(func_003eef60)
    /* 2EFC64 003EFC64 90EAA524 */  addiu      $5, $5, %lo(func_003eea90)
    /* 2EFC68 003EFC68 E0EA8424 */  addiu      $4, $4, %lo(func_003eeae0)
    /* 2EFC6C 003EFC6C 60DA6324 */  addiu      $3, $3, %lo(func_003eda60)
    /* 2EFC70 003EFC70 2D102002 */  daddu      $2, $17, $0
    /* 2EFC74 003EFC74 21380701 */  addu       $7, $8, $7
    /* 2EFC78 003EFC78 2000E0AC */  sw         $0, 0x20($7)
    /* 2EFC7C 003EFC7C 1800E6AC */  sw         $6, 0x18($7)
    /* 2EFC80 003EFC80 1400E5AC */  sw         $5, 0x14($7)
    /* 2EFC84 003EFC84 2C00E4AC */  sw         $4, 0x2C($7)
    /* 2EFC88 003EFC88 3000E3AC */  sw         $3, 0x30($7)
    /* 2EFC8C 003EFC8C 2400E0AC */  sw         $0, 0x24($7)
    /* 2EFC90 003EFC90 1B000010 */  b          .L003EFD00
    /* 2EFC94 003EFC94 2800E0A4 */   sh        $0, 0x28($7)
  .L003EFC98:
    /* 2EFC98 003EFC98 BC840F0C */  jal        func_003e12f0
    /* 2EFC9C 003EFC9C 0800648C */   lw        $4, 0x8($3)
    /* 2EFCA0 003EFCA0 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EFCA4 003EFCA4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EFCA8 003EFCA8 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EFCAC 003EFCAC 2D100000 */  daddu      $2, $0, $0
    /* 2EFCB0 003EFCB0 21186400 */  addu       $3, $3, $4
    /* 2EFCB4 003EFCB4 12000010 */  b          .L003EFD00
    /* 2EFCB8 003EFCB8 080060AC */   sw        $0, 0x8($3)
  .L003EFCBC:
    /* 2EFCBC 003EFCBC DAFF0010 */  b          .L003EFC28
    /* 2EFCC0 003EFCC0 2D800000 */   daddu     $16, $0, $0
  .L003EFCC4:
    /* 2EFCC4 003EFCC4 BC840F0C */  jal        func_003e12f0
    /* 2EFCC8 003EFCC8 0C00648C */   lw        $4, 0xC($3)
    /* 2EFCCC 003EFCCC E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFCD0 003EFCD0 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EFCD4 003EFCD4 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EFCD8 003EFCD8 21104300 */  addu       $2, $2, $3
    /* 2EFCDC 003EFCDC 0C0040AC */  sw         $0, 0xC($2)
    /* 2EFCE0 003EFCE0 BC840F0C */  jal        func_003e12f0
    /* 2EFCE4 003EFCE4 0800448C */   lw        $4, 0x8($2)
    /* 2EFCE8 003EFCE8 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EFCEC 003EFCEC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EFCF0 003EFCF0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EFCF4 003EFCF4 2D100000 */  daddu      $2, $0, $0
    /* 2EFCF8 003EFCF8 21186400 */  addu       $3, $3, $4
    /* 2EFCFC 003EFCFC 080060AC */  sw         $0, 0x8($3)
  .L003EFD00:
    /* 2EFD00 003EFD00 2000BFDF */  ld         $31, 0x20($29)
    /* 2EFD04 003EFD04 1000B17B */  lq         $17, 0x10($29)
    /* 2EFD08 003EFD08 0000B07B */  lq         $16, 0x0($29)
    /* 2EFD0C 003EFD0C 0800E003 */  jr         $31
    /* 2EFD10 003EFD10 3000BD27 */   addiu     $29, $29, 0x30
    /* 2EFD14 003EFD14 00000000 */  nop
    /* 2EFD18 003EFD18 00000000 */  nop
    /* 2EFD1C 003EFD1C 00000000 */  nop
.size func_003efac0, 0x260
