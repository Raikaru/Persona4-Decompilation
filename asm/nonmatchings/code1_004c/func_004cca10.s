.section .text
.set noat
.set noreorder
glabel func_004cca10
    /* 3CCA10 004CCA10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CCA14 004CCA14 7200023C */  lui        $2, %hi(D_007188B8)
    /* 3CCA18 004CCA18 0800B1FF */  sd         $17, 0x8($29)
    /* 3CCA1C 004CCA1C 2D888000 */  daddu      $17, $4, $0
    /* 3CCA20 004CCA20 1000B2FF */  sd         $18, 0x10($29)
    /* 3CCA24 004CCA24 7200123C */  lui        $18, %hi(D_00719AAC)
    /* 3CCA28 004CCA28 0000B0FF */  sd         $16, 0x0($29)
    /* 3CCA2C 004CCA2C B8884224 */  addiu      $2, $2, %lo(D_007188B8)
    /* 3CCA30 004CCA30 1800BFFF */  sd         $31, 0x18($29)
    /* 3CCA34 004CCA34 AC9A4526 */  addiu      $5, $18, %lo(D_00719AAC)
    /* 3CCA38 004CCA38 0000438C */  lw         $3, 0x0($2)
    /* 3CCA3C 004CCA3C 01006324 */  addiu      $3, $3, 0x1
    /* 3CCA40 004CCA40 000043AC */  sw         $3, 0x0($2)
    /* 3CCA44 004CCA44 0000A48C */  lw         $4, 0x0($5)
    /* 3CCA48 004CCA48 2D008014 */  bnez       $4, .L004CCB00
    /* 3CCA4C 004CCA4C 7200023C */   lui       $2, %hi(D_00719AB0)
    /* 3CCA50 004CCA50 7200023C */  lui        $2, %hi(D_00719994)
    /* 3CCA54 004CCA54 01001024 */  addiu      $16, $0, 0x1
    /* 3CCA58 004CCA58 9499438C */  lw         $3, %lo(D_00719994)($2)
    /* 3CCA5C 004CCA5C 0000B0AC */  sw         $16, 0x0($5)
    /* 3CCA60 004CCA60 22006018 */  blez       $3, .L004CCAEC
    /* 3CCA64 004CCA64 7200023C */   lui       $2, %hi(D_007199D8)
    /* 3CCA68 004CCA68 D8994224 */  addiu      $2, $2, %lo(D_007199D8)
    /* 3CCA6C 004CCA6C 0000438C */  lw         $3, 0x0($2)
    /* 3CCA70 004CCA70 04007010 */  beq        $3, $16, .L004CCA84
    /* 3CCA74 004CCA74 7200023C */   lui       $2, %hi(D_00719A30)
    /* 3CCA78 004CCA78 309A4224 */  addiu      $2, $2, %lo(D_00719A30)
    /* 3CCA7C 004CCA7C 222F130C */  jal        func_004cbc88
    /* 3CCA80 004CCA80 0000448C */   lw        $4, 0x0($2)
  .L004CCA84:
    /* 3CCA84 004CCA84 7200023C */  lui        $2, %hi(D_007199E0)
    /* 3CCA88 004CCA88 E0994224 */  addiu      $2, $2, %lo(D_007199E0)
    /* 3CCA8C 004CCA8C 0000438C */  lw         $3, 0x0($2)
    /* 3CCA90 004CCA90 04007010 */  beq        $3, $16, .L004CCAA4
    /* 3CCA94 004CCA94 7200023C */   lui       $2, %hi(D_00719A34)
    /* 3CCA98 004CCA98 349A4224 */  addiu      $2, $2, %lo(D_00719A34)
    /* 3CCA9C 004CCA9C 222F130C */  jal        func_004cbc88
    /* 3CCAA0 004CCAA0 0000448C */   lw        $4, 0x0($2)
  .L004CCAA4:
    /* 3CCAA4 004CCAA4 7830130C */  jal        func_004cc1e0
    /* 3CCAA8 004CCAA8 00000000 */   nop
    /* 3CCAAC 004CCAAC 2D204000 */  daddu      $4, $2, $0
    /* 3CCAB0 004CCAB0 0A009014 */  bne        $4, $16, .L004CCADC
    /* 3CCAB4 004CCAB4 7200033C */   lui       $3, %hi(D_00719A20)
    /* 3CCAB8 004CCAB8 7200023C */  lui        $2, %hi(D_007199DC)
    /* 3CCABC 004CCABC DC994224 */  addiu      $2, $2, %lo(D_007199DC)
    /* 3CCAC0 004CCAC0 0000438C */  lw         $3, 0x0($2)
    /* 3CCAC4 004CCAC4 04006410 */  beq        $3, $4, .L004CCAD8
    /* 3CCAC8 004CCAC8 7200023C */   lui       $2, %hi(D_00719A2C)
    /* 3CCACC 004CCACC 2C9A4224 */  addiu      $2, $2, %lo(D_00719A2C)
    /* 3CCAD0 004CCAD0 222F130C */  jal        func_004cbc88
    /* 3CCAD4 004CCAD4 0000448C */   lw        $4, 0x0($2)
  .L004CCAD8:
    /* 3CCAD8 004CCAD8 7200033C */  lui        $3, %hi(D_00719A20)
  .L004CCADC:
    /* 3CCADC 004CCADC 209A6324 */  addiu      $3, $3, %lo(D_00719A20)
    /* 3CCAE0 004CCAE0 000062DC */  ld         $2, 0x0($3)
    /* 3CCAE4 004CCAE4 01004264 */  daddiu     $2, $2, 0x1
    /* 3CCAE8 004CCAE8 000062FC */  sd         $2, 0x0($3)
  .L004CCAEC:
    /* 3CCAEC 004CCAEC D82C130C */  jal        func_004cb360
    /* 3CCAF0 004CCAF0 00000000 */   nop
    /* 3CCAF4 004CCAF4 AC9A4326 */  addiu      $3, $18, %lo(D_00719AAC)
    /* 3CCAF8 004CCAF8 000060AC */  sw         $0, 0x0($3)
    /* 3CCAFC 004CCAFC 7200023C */  lui        $2, %hi(D_00719AB0)
  .L004CCB00:
    /* 3CCB00 004CCB00 B09A428C */  lw         $2, %lo(D_00719AB0)($2)
    /* 3CCB04 004CCB04 06004050 */  beql       $2, $0, .L004CCB20
    /* 3CCB08 004CCB08 2D100000 */   daddu     $2, $0, $0
    /* 3CCB0C 004CCB0C 09F84000 */  jalr       $2
    /* 3CCB10 004CCB10 2D202002 */   daddu     $4, $17, $0
    /* 3CCB14 004CCB14 03000010 */  b          .L004CCB24
    /* 3CCB18 004CCB18 0000B0DF */   ld        $16, 0x0($29)
    /* 3CCB1C 004CCB1C 00000000 */  nop
  .L004CCB20:
    /* 3CCB20 004CCB20 0000B0DF */  ld         $16, 0x0($29)
  .L004CCB24:
    /* 3CCB24 004CCB24 0800B1DF */  ld         $17, 0x8($29)
    /* 3CCB28 004CCB28 1000B2DF */  ld         $18, 0x10($29)
    /* 3CCB2C 004CCB2C 1800BFDF */  ld         $31, 0x18($29)
    /* 3CCB30 004CCB30 0800E003 */  jr         $31
    /* 3CCB34 004CCB34 2000BD27 */   addiu     $29, $29, 0x20
.size func_004cca10, 0x128
