.section .text
.set noat
.set noreorder
glabel func_004deb58
    /* 3DEB58 004DEB58 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DEB5C 004DEB5C 1000B0FF */  sd         $16, 0x10($29)
    /* 3DEB60 004DEB60 2D808000 */  daddu      $16, $4, $0
    /* 3DEB64 004DEB64 1800B1FF */  sd         $17, 0x18($29)
    /* 3DEB68 004DEB68 2D88C000 */  daddu      $17, $6, $0
    /* 3DEB6C 004DEB6C 2000B2FF */  sd         $18, 0x20($29)
    /* 3DEB70 004DEB70 2D90A000 */  daddu      $18, $5, $0
    /* 3DEB74 004DEB74 06000016 */  bnez       $16, .L004DEB90
    /* 3DEB78 004DEB78 2800BFFF */   sd        $31, 0x28($29)
    /* 3DEB7C 004DEB7C 7600043C */  lui        $4, %hi(D_00759708)
    /* 3DEB80 004DEB80 B078130C */  jal        func_004de2c0
    /* 3DEB84 004DEB84 08978424 */   addiu     $4, $4, %lo(D_00759708)
    /* 3DEB88 004DEB88 23000010 */  b          .L004DEC18
    /* 3DEB8C 004DEB8C 1000B0DF */   ld        $16, 0x10($29)
  .L004DEB90:
    /* 3DEB90 004DEB90 587B130C */  jal        func_004ded60
    /* 3DEB94 004DEB94 00000000 */   nop
    /* 3DEB98 004DEB98 E080130C */  jal        func_004e0380
    /* 3DEB9C 004DEB9C 00000000 */   nop
    /* 3DEBA0 004DEBA0 9200063C */  lui        $6, %hi(D_009230F0)
    /* 3DEBA4 004DEBA4 2D38A003 */  daddu      $7, $29, $0
    /* 3DEBA8 004DEBA8 2D204002 */  daddu      $4, $18, $0
    /* 3DEBAC 004DEBAC 2D282002 */  daddu      $5, $17, $0
    /* 3DEBB0 004DEBB0 F030C624 */  addiu      $6, $6, %lo(D_009230F0)
    /* 3DEBB4 004DEBB4 0400A827 */  addiu      $8, $29, 0x4
    /* 3DEBB8 004DEBB8 6826130C */  jal        func_004c99a0
    /* 3DEBBC 004DEBBC 0800A927 */   addiu     $9, $29, 0x8
    /* 3DEBC0 004DEBC0 12004014 */  bnez       $2, .L004DEC0C
    /* 3DEBC4 004DEBC4 2D204002 */   daddu     $4, $18, $0
    /* 3DEBC8 004DEBC8 E026130C */  jal        func_004c9b80
    /* 3DEBCC 004DEBCC 00000000 */   nop
    /* 3DEBD0 004DEBD0 8C00058E */  lw         $5, 0x8C($16)
    /* 3DEBD4 004DEBD4 CC0102AE */  sw         $2, 0x1CC($16)
    /* 3DEBD8 004DEBD8 900005AE */  sw         $5, 0x90($16)
    /* 3DEBDC 004DEBDC 0400048E */  lw         $4, 0x4($16)
    /* 3DEBE0 004DEBE0 0000A28F */  lw         $2, 0x0($29)
    /* 3DEBE4 004DEBE4 0400A38F */  lw         $3, 0x4($29)
    /* 3DEBE8 004DEBE8 0800A68F */  lw         $6, 0x8($29)
    /* 3DEBEC 004DEBEC D00102AE */  sw         $2, 0x1D0($16)
    /* 3DEBF0 004DEBF0 D40103AE */  sw         $3, 0x1D4($16)
    /* 3DEBF4 004DEBF4 7681130C */  jal        func_004e05d8
    /* 3DEBF8 004DEBF8 D80106AE */   sw        $6, 0x1D8($16)
    /* 3DEBFC 004DEBFC 01000224 */  addiu      $2, $0, 0x1
    /* 3DEC00 004DEC00 010002A2 */  sb         $2, 0x1($16)
    /* 3DEC04 004DEC04 DC0102AE */  sw         $2, 0x1DC($16)
    /* 3DEC08 004DEC08 B20102A2 */  sb         $2, 0x1B2($16)
  .L004DEC0C:
    /* 3DEC0C 004DEC0C E680130C */  jal        func_004e0398
    /* 3DEC10 004DEC10 00000000 */   nop
    /* 3DEC14 004DEC14 1000B0DF */  ld         $16, 0x10($29)
  .L004DEC18:
    /* 3DEC18 004DEC18 1800B1DF */  ld         $17, 0x18($29)
    /* 3DEC1C 004DEC1C 2000B2DF */  ld         $18, 0x20($29)
    /* 3DEC20 004DEC20 2800BFDF */  ld         $31, 0x28($29)
    /* 3DEC24 004DEC24 0800E003 */  jr         $31
    /* 3DEC28 004DEC28 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DEC2C 004DEC2C 00000000 */  nop
.size func_004deb58, 0xd8
