.section .text
.set noat
.set noreorder
glabel func_004afb10
    /* 3AFB10 004AFB10 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3AFB14 004AFB14 4000BFFF */  sd         $31, 0x40($29)
    /* 3AFB18 004AFB18 3000B37F */  sq         $19, 0x30($29)
    /* 3AFB1C 004AFB1C 2000B27F */  sq         $18, 0x20($29)
    /* 3AFB20 004AFB20 1000B17F */  sq         $17, 0x10($29)
    /* 3AFB24 004AFB24 0000B07F */  sq         $16, 0x0($29)
    /* 3AFB28 004AFB28 2D888000 */  daddu      $17, $4, $0
    /* 3AFB2C 004AFB2C 2D90A000 */  daddu      $18, $5, $0
    /* 3AFB30 004AFB30 2D80C000 */  daddu      $16, $6, $0
    /* 3AFB34 004AFB34 5C00848C */  lw         $4, 0x5C($4)
    /* 3AFB38 004AFB38 03008010 */  beqz       $4, .L004AFB48
    /* 3AFB3C 004AFB3C 00000000 */   nop
    /* 3AFB40 004AFB40 344B120C */  jal        func_00492cd0
    /* 3AFB44 004AFB44 00000000 */   nop
  .L004AFB48:
    /* 3AFB48 004AFB48 C000028E */  lw         $2, 0xC0($16)
    /* 3AFB4C 004AFB4C 06004010 */  beqz       $2, .L004AFB68
    /* 3AFB50 004AFB50 00000000 */   nop
    /* 3AFB54 004AFB54 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AFB58 004AFB58 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AFB5C 004AFB5C F4000524 */  addiu      $5, $0, 0xF4
    /* 3AFB60 004AFB60 CCB5110C */  jal        func_0046d730
    /* 3AFB64 004AFB64 00000000 */   nop
  .L004AFB68:
    /* 3AFB68 004AFB68 FFFF4432 */  andi       $4, $18, 0xFFFF
    /* 3AFB6C 004AFB6C 0000258E */  lw         $5, 0x0($17)
    /* 3AFB70 004AFB70 2D300002 */  daddu      $6, $16, $0
    /* 3AFB74 004AFB74 C84A120C */  jal        func_00492b20
    /* 3AFB78 004AFB78 00000000 */   nop
    /* 3AFB7C 004AFB7C 5C0022AE */  sw         $2, 0x5C($17)
    /* 3AFB80 004AFB80 6800248E */  lw         $4, 0x68($17)
    /* 3AFB84 004AFB84 05008010 */  beqz       $4, .L004AFB9C
    /* 3AFB88 004AFB88 00000000 */   nop
    /* 3AFB8C 004AFB8C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AFB90 004AFB90 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AFB94 004AFB94 09F84000 */  jalr       $2
    /* 3AFB98 004AFB98 00000000 */   nop
  .L004AFB9C:
    /* 3AFB9C 004AFB9C 5C00228E */  lw         $2, 0x5C($17)
    /* 3AFBA0 004AFBA0 0800508C */  lw         $16, 0x8($2)
    /* 3AFBA4 004AFBA4 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AFBA8 004AFBA8 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AFBAC 004AFBAC FE000524 */  addiu      $5, $0, 0xFE
    /* 3AFBB0 004AFBB0 A43A110C */  jal        func_0044ea90
    /* 3AFBB4 004AFBB4 00000000 */   nop
    /* 3AFBB8 004AFBB8 C0101000 */  sll        $2, $16, 3
    /* 3AFBBC 004AFBBC 23105000 */  subu       $2, $2, $16
    /* 3AFBC0 004AFBC0 80200200 */  sll        $4, $2, 2
    /* 3AFBC4 004AFBC4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3AFBC8 004AFBC8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3AFBCC 004AFBCC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3AFBD0 004AFBD0 09F84000 */  jalr       $2
    /* 3AFBD4 004AFBD4 00000000 */   nop
    /* 3AFBD8 004AFBD8 680022AE */  sw         $2, 0x68($17)
    /* 3AFBDC 004AFBDC 06004014 */  bnez       $2, .L004AFBF8
    /* 3AFBE0 004AFBE0 00000000 */   nop
    /* 3AFBE4 004AFBE4 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AFBE8 004AFBE8 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AFBEC 004AFBEC FF000524 */  addiu      $5, $0, 0xFF
    /* 3AFBF0 004AFBF0 CCB5110C */  jal        func_0046d730
    /* 3AFBF4 004AFBF4 00000000 */   nop
  .L004AFBF8:
    /* 3AFBF8 004AFBF8 6800338E */  lw         $19, 0x68($17)
    /* 3AFBFC 004AFBFC 640033AE */  sw         $19, 0x64($17)
    /* 3AFC00 004AFC00 2D900000 */  daddu      $18, $0, $0
    /* 3AFC04 004AFC04 07000010 */  b          .L004AFC24
    /* 3AFC08 004AFC08 00000000 */   nop
  .L004AFC0C:
    /* 3AFC0C 004AFC0C 2D202002 */  daddu      $4, $17, $0
    /* 3AFC10 004AFC10 2D286002 */  daddu      $5, $19, $0
    /* 3AFC14 004AFC14 20BF120C */  jal        func_004afc80
    /* 3AFC18 004AFC18 00000000 */   nop
    /* 3AFC1C 004AFC1C 01005226 */  addiu      $18, $18, 0x1
    /* 3AFC20 004AFC20 1C007326 */  addiu      $19, $19, 0x1C
  .L004AFC24:
    /* 3AFC24 004AFC24 2B185002 */  sltu       $3, $18, $16
    /* 3AFC28 004AFC28 F8FF6014 */  bnez       $3, .L004AFC0C
    /* 3AFC2C 004AFC2C 00000000 */   nop
    /* 3AFC30 004AFC30 4000BFDF */  ld         $31, 0x40($29)
    /* 3AFC34 004AFC34 3000B37B */  lq         $19, 0x30($29)
    /* 3AFC38 004AFC38 2000B27B */  lq         $18, 0x20($29)
    /* 3AFC3C 004AFC3C 1000B17B */  lq         $17, 0x10($29)
    /* 3AFC40 004AFC40 0000B07B */  lq         $16, 0x0($29)
    /* 3AFC44 004AFC44 5000BD27 */  addiu      $29, $29, 0x50
    /* 3AFC48 004AFC48 0800E003 */  jr         $31
    /* 3AFC4C 004AFC4C 00000000 */   nop
.size func_004afb10, 0x140
