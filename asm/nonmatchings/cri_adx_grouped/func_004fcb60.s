.section .text
.set noat
.set noreorder
glabel func_004fcb60
    /* 3FCB60 004FCB60 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3FCB64 004FCB64 3000B2FF */  sd         $18, 0x30($29)
    /* 3FCB68 004FCB68 2D908000 */  daddu      $18, $4, $0
    /* 3FCB6C 004FCB6C 4000B4FF */  sd         $20, 0x40($29)
    /* 3FCB70 004FCB70 4800B5FF */  sd         $21, 0x48($29)
    /* 3FCB74 004FCB74 2DA8C000 */  daddu      $21, $6, $0
    /* 3FCB78 004FCB78 5000B6FF */  sd         $22, 0x50($29)
    /* 3FCB7C 004FCB7C 2000B0FF */  sd         $16, 0x20($29)
    /* 3FCB80 004FCB80 2800B1FF */  sd         $17, 0x28($29)
    /* 3FCB84 004FCB84 3800B3FF */  sd         $19, 0x38($29)
    /* 3FCB88 004FCB88 5800BFFF */  sd         $31, 0x58($29)
    /* 3FCB8C 004FCB8C E405538E */  lw         $19, 0x5E4($18)
    /* 3FCB90 004FCB90 40101300 */  sll        $2, $19, 1
    /* 3FCB94 004FCB94 21105300 */  addu       $2, $2, $19
    /* 3FCB98 004FCB98 80100200 */  sll        $2, $2, 2
    /* 3FCB9C 004FCB9C 10015424 */  addiu      $20, $2, 0x110
    /* 3FCBA0 004FCBA0 21185402 */  addu       $3, $18, $20
    /* 3FCBA4 004FCBA4 0800718C */  lw         $17, 0x8($3)
    /* 3FCBA8 004FCBA8 2F002012 */  beqz       $17, .L004FCC68
    /* 3FCBAC 004FCBAC 2DB0A000 */   daddu     $22, $5, $0
    /* 3FCBB0 004FCBB0 0000238E */  lw         $3, 0x0($17)
    /* 3FCBB4 004FCBB4 2D38A003 */  daddu      $7, $29, $0
    /* 3FCBB8 004FCBB8 2D202002 */  daddu      $4, $17, $0
    /* 3FCBBC 004FCBBC 1800628C */  lw         $2, 0x18($3)
    /* 3FCBC0 004FCBC0 09F84000 */  jalr       $2
    /* 3FCBC4 004FCBC4 2D280000 */   daddu     $5, $0, $0
    /* 3FCBC8 004FCBC8 2D28C002 */  daddu      $5, $22, $0
    /* 3FCBCC 004FCBCC 0000A48F */  lw         $4, 0x0($29)
    /* 3FCBD0 004FCBD0 04FE100C */  jal        func_0043f810
    /* 3FCBD4 004FCBD4 0400A68F */   lw        $6, 0x4($29)
    /* 3FCBD8 004FCBD8 0000238E */  lw         $3, 0x0($17)
    /* 3FCBDC 004FCBDC 2D202002 */  daddu      $4, $17, $0
    /* 3FCBE0 004FCBE0 01000524 */  addiu      $5, $0, 0x1
    /* 3FCBE4 004FCBE4 2000628C */  lw         $2, 0x20($3)
    /* 3FCBE8 004FCBE8 09F84000 */  jalr       $2
    /* 3FCBEC 004FCBEC 2D30A003 */   daddu     $6, $29, $0
    /* 3FCBF0 004FCBF0 0400A48F */  lw         $4, 0x4($29)
    /* 3FCBF4 004FCBF4 2A109500 */  slt        $2, $4, $21
    /* 3FCBF8 004FCBF8 15004010 */  beqz       $2, .L004FCC50
    /* 3FCBFC 004FCBFC 21105402 */   addu      $2, $18, $20
    /* 3FCC00 004FCC00 0000238E */  lw         $3, 0x0($17)
    /* 3FCC04 004FCC04 1000B027 */  addiu      $16, $29, 0x10
    /* 3FCC08 004FCC08 2330A402 */  subu       $6, $21, $4
    /* 3FCC0C 004FCC0C 2D202002 */  daddu      $4, $17, $0
    /* 3FCC10 004FCC10 1800628C */  lw         $2, 0x18($3)
    /* 3FCC14 004FCC14 2D280000 */  daddu      $5, $0, $0
    /* 3FCC18 004FCC18 09F84000 */  jalr       $2
    /* 3FCC1C 004FCC1C 2D380002 */   daddu     $7, $16, $0
    /* 3FCC20 004FCC20 0400A58F */  lw         $5, 0x4($29)
    /* 3FCC24 004FCC24 1000A48F */  lw         $4, 0x10($29)
    /* 3FCC28 004FCC28 1400A68F */  lw         $6, 0x14($29)
    /* 3FCC2C 004FCC2C 04FE100C */  jal        func_0043f810
    /* 3FCC30 004FCC30 2128C502 */   addu      $5, $22, $5
    /* 3FCC34 004FCC34 0000238E */  lw         $3, 0x0($17)
    /* 3FCC38 004FCC38 2D202002 */  daddu      $4, $17, $0
    /* 3FCC3C 004FCC3C 2D300002 */  daddu      $6, $16, $0
    /* 3FCC40 004FCC40 2000628C */  lw         $2, 0x20($3)
    /* 3FCC44 004FCC44 09F84000 */  jalr       $2
    /* 3FCC48 004FCC48 01000524 */   addiu     $5, $0, 0x1
    /* 3FCC4C 004FCC4C 21105402 */  addu       $2, $18, $20
  .L004FCC50:
    /* 3FCC50 004FCC50 0C00438C */  lw         $3, 0xC($2)
    /* 3FCC54 004FCC54 05006050 */  beql       $3, $0, .L004FCC6C
    /* 3FCC58 004FCC58 03000224 */   addiu     $2, $0, 0x3
    /* 3FCC5C 004FCC5C 1000448C */  lw         $4, 0x10($2)
    /* 3FCC60 004FCC60 09F86000 */  jalr       $3
    /* 3FCC64 004FCC64 2D286002 */   daddu     $5, $19, $0
  .L004FCC68:
    /* 3FCC68 004FCC68 03000224 */  addiu      $2, $0, 0x3
  .L004FCC6C:
    /* 3FCC6C 004FCC6C 10006216 */  bne        $19, $2, .L004FCCB0
    /* 3FCC70 004FCC70 2000B0DF */   ld        $16, 0x20($29)
    /* 3FCC74 004FCC74 4801428E */  lw         $2, 0x148($18)
    /* 3FCC78 004FCC78 0E004010 */  beqz       $2, .L004FCCB4
    /* 3FCC7C 004FCC7C 2800B1DF */   ld        $17, 0x28($29)
    /* 3FCC80 004FCC80 2405428E */  lw         $2, 0x524($18)
    /* 3FCC84 004FCC84 05004010 */  beqz       $2, .L004FCC9C
    /* 3FCC88 004FCC88 7600053C */   lui       $5, %hi(D_0075DCE8)
    /* 3FCC8C 004FCC8C 2D204002 */  daddu      $4, $18, $0
    /* 3FCC90 004FCC90 E8DCA524 */  addiu      $5, $5, %lo(D_0075DCE8)
    /* 3FCC94 004FCC94 36F3130C */  jal        func_004fccd8
    /* 3FCC98 004FCC98 08000624 */   addiu     $6, $0, 0x8
  .L004FCC9C:
    /* 3FCC9C 004FCC9C 2D204002 */  daddu      $4, $18, $0
    /* 3FCCA0 004FCCA0 2D28C002 */  daddu      $5, $22, $0
    /* 3FCCA4 004FCCA4 36F3130C */  jal        func_004fccd8
    /* 3FCCA8 004FCCA8 2D30A002 */   daddu     $6, $21, $0
    /* 3FCCAC 004FCCAC 2000B0DF */  ld         $16, 0x20($29)
  .L004FCCB0:
    /* 3FCCB0 004FCCB0 2800B1DF */  ld         $17, 0x28($29)
  .L004FCCB4:
    /* 3FCCB4 004FCCB4 3000B2DF */  ld         $18, 0x30($29)
    /* 3FCCB8 004FCCB8 3800B3DF */  ld         $19, 0x38($29)
    /* 3FCCBC 004FCCBC 4000B4DF */  ld         $20, 0x40($29)
    /* 3FCCC0 004FCCC0 4800B5DF */  ld         $21, 0x48($29)
    /* 3FCCC4 004FCCC4 5000B6DF */  ld         $22, 0x50($29)
    /* 3FCCC8 004FCCC8 5800BFDF */  ld         $31, 0x58($29)
    /* 3FCCCC 004FCCCC 0800E003 */  jr         $31
    /* 3FCCD0 004FCCD0 6000BD27 */   addiu     $29, $29, 0x60
    /* 3FCCD4 004FCCD4 00000000 */  nop
.size func_004fcb60, 0x178
