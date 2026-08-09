.section .text
.set noat
.set noreorder
glabel func_004cba78
    /* 3CBA78 004CBA78 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CBA7C 004CBA7C 7200023C */  lui        $2, %hi(D_00719A88)
    /* 3CBA80 004CBA80 0000B0FF */  sd         $16, 0x0($29)
    /* 3CBA84 004CBA84 889A4624 */  addiu      $6, $2, %lo(D_00719A88)
    /* 3CBA88 004CBA88 0800B1FF */  sd         $17, 0x8($29)
    /* 3CBA8C 004CBA8C 1000B2FF */  sd         $18, 0x10($29)
    /* 3CBA90 004CBA90 1800B3FF */  sd         $19, 0x18($29)
    /* 3CBA94 004CBA94 2000B4FF */  sd         $20, 0x20($29)
    /* 3CBA98 004CBA98 2800B5FF */  sd         $21, 0x28($29)
    /* 3CBA9C 004CBA9C 3000B6FF */  sd         $22, 0x30($29)
    /* 3CBAA0 004CBAA0 3800B7FF */  sd         $23, 0x38($29)
    /* 3CBAA4 004CBAA4 4000BFFF */  sd         $31, 0x40($29)
    /* 3CBAA8 004CBAA8 0000C3DC */  ld         $3, 0x0($6)
    /* 3CBAAC 004CBAAC 32006014 */  bnez       $3, .L004CBB78
    /* 3CBAB0 004CBAB0 7200023C */   lui       $2, %hi(D_00719A90)
    /* 3CBAB4 004CBAB4 7200023C */  lui        $2, %hi(D_00719A10)
    /* 3CBAB8 004CBAB8 7200033C */  lui        $3, %hi(D_007199E4)
    /* 3CBABC 004CBABC 7200043C */  lui        $4, %hi(D_007199D4)
    /* 3CBAC0 004CBAC0 7200053C */  lui        $5, %hi(D_00719AB8)
    /* 3CBAC4 004CBAC4 109A5424 */  addiu      $20, $2, %lo(D_00719A10)
    /* 3CBAC8 004CBAC8 E4997324 */  addiu      $19, $3, %lo(D_007199E4)
    /* 3CBACC 004CBACC D4999224 */  addiu      $18, $4, %lo(D_007199D4)
    /* 3CBAD0 004CBAD0 B89AB724 */  addiu      $23, $5, %lo(D_00719AB8)
    /* 3CBAD4 004CBAD4 2DB0C000 */  daddu      $22, $6, $0
    /* 3CBAD8 004CBAD8 01001124 */  addiu      $17, $0, 0x1
    /* 3CBADC 004CBADC 7200153C */  lui        $21, %hi(D_00719A40)
  .L004CBAE0:
    /* 3CBAE0 004CBAE0 000082DE */  ld         $2, 0x0($20)
    /* 3CBAE4 004CBAE4 01004264 */  daddiu     $2, $2, 0x1
    /* 3CBAE8 004CBAE8 000082FE */  sd         $2, 0x0($20)
    /* 3CBAEC 004CBAEC 38C4130C */  jal        func_004f10e0
    /* 3CBAF0 004CBAF0 000071AE */   sw        $17, 0x0($19)
    /* 3CBAF4 004CBAF4 000060AE */  sw         $0, 0x0($19)
    /* 3CBAF8 004CBAF8 2D804000 */  daddu      $16, $2, $0
    /* 3CBAFC 004CBAFC 0000428E */  lw         $2, 0x0($18)
    /* 3CBB00 004CBB00 03005114 */  bne        $2, $17, .L004CBB10
    /* 3CBB04 004CBB04 00000000 */   nop
    /* 3CBB08 004CBB08 4A2F130C */  jal        func_004cbd28
    /* 3CBB0C 004CBB0C 000040AE */   sw        $0, 0x0($18)
  .L004CBB10:
    /* 3CBB10 004CBB10 16000016 */  bnez       $16, .L004CBB6C
    /* 3CBB14 004CBB14 00000000 */   nop
    /* 3CBB18 004CBB18 7830130C */  jal        func_004cc1e0
    /* 3CBB1C 004CBB1C 00000000 */   nop
    /* 3CBB20 004CBB20 09005114 */  bne        $2, $17, .L004CBB48
    /* 3CBB24 004CBB24 409AB026 */   addiu     $16, $21, %lo(D_00719A40)
    /* 3CBB28 004CBB28 0000048E */  lw         $4, 0x0($16)
    /* 3CBB2C 004CBB2C 502F130C */  jal        func_004cbd40
    /* 3CBB30 004CBB30 00000000 */   nop
    /* 3CBB34 004CBB34 0000038E */  lw         $3, 0x0($16)
    /* 3CBB38 004CBB38 03004314 */  bne        $2, $3, .L004CBB48
    /* 3CBB3C 004CBB3C 00000000 */   nop
    /* 3CBB40 004CBB40 362F130C */  jal        func_004cbcd8
    /* 3CBB44 004CBB44 0000048E */   lw        $4, 0x0($16)
  .L004CBB48:
    /* 3CBB48 004CBB48 0000428E */  lw         $2, 0x0($18)
    /* 3CBB4C 004CBB4C 01001024 */  addiu      $16, $0, 0x1
    /* 3CBB50 004CBB50 04005010 */  beq        $2, $16, .L004CBB64
    /* 3CBB54 004CBB54 00000000 */   nop
    /* 3CBB58 004CBB58 6834130C */  jal        func_004cd1a0
    /* 3CBB5C 004CBB5C 00000000 */   nop
    /* 3CBB60 004CBB60 0000F0AE */  sw         $16, 0x0($23)
  .L004CBB64:
    /* 3CBB64 004CBB64 4A2F130C */  jal        func_004cbd28
    /* 3CBB68 004CBB68 00000000 */   nop
  .L004CBB6C:
    /* 3CBB6C 004CBB6C 0000C2DE */  ld         $2, 0x0($22)
    /* 3CBB70 004CBB70 DBFF4010 */  beqz       $2, .L004CBAE0
    /* 3CBB74 004CBB74 7200023C */   lui       $2, %hi(D_00719A90)
  .L004CBB78:
    /* 3CBB78 004CBB78 0000B0DF */  ld         $16, 0x0($29)
    /* 3CBB7C 004CBB7C 0800B1DF */  ld         $17, 0x8($29)
    /* 3CBB80 004CBB80 01000324 */  addiu      $3, $0, 0x1
    /* 3CBB84 004CBB84 1000B2DF */  ld         $18, 0x10($29)
    /* 3CBB88 004CBB88 909A4224 */  addiu      $2, $2, %lo(D_00719A90)
    /* 3CBB8C 004CBB8C 1800B3DF */  ld         $19, 0x18($29)
    /* 3CBB90 004CBB90 2000B4DF */  ld         $20, 0x20($29)
    /* 3CBB94 004CBB94 2800B5DF */  ld         $21, 0x28($29)
    /* 3CBB98 004CBB98 3000B6DF */  ld         $22, 0x30($29)
    /* 3CBB9C 004CBB9C 3800B7DF */  ld         $23, 0x38($29)
    /* 3CBBA0 004CBBA0 4000BFDF */  ld         $31, 0x40($29)
    /* 3CBBA4 004CBBA4 000043FC */  sd         $3, 0x0($2)
    /* 3CBBA8 004CBBA8 88851008 */  j          func_00421620
    /* 3CBBAC 004CBBAC 5000BD27 */   addiu     $29, $29, 0x50
.size func_004cba78, 0x138
