.section .text
.set noat
.set noreorder
glabel func_003c9c20
    /* 2C9C20 003C9C20 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2C9C24 003C9C24 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2C9C28 003C9C28 5000BFFF */  sd         $31, 0x50($29)
    /* 2C9C2C 003C9C2C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2C9C30 003C9C30 4000B47F */  sq         $20, 0x40($29)
    /* 2C9C34 003C9C34 3000B37F */  sq         $19, 0x30($29)
    /* 2C9C38 003C9C38 2000B27F */  sq         $18, 0x20($29)
    /* 2C9C3C 003C9C3C 1000B17F */  sq         $17, 0x10($29)
    /* 2C9C40 003C9C40 0000B07F */  sq         $16, 0x0($29)
    /* 2C9C44 003C9C44 00B7838F */  lw         $3, -0x4900($28)
    /* 2C9C48 003C9C48 21104300 */  addu       $2, $2, $3
    /* 2C9C4C 003C9C4C 0400538C */  lw         $19, 0x4($2)
    /* 2C9C50 003C9C50 04005224 */  addiu      $18, $2, 0x4
    /* 2C9C54 003C9C54 14007212 */  beq        $19, $18, .L003C9CA8
    /* 2C9C58 003C9C58 2DA08000 */   daddu     $20, $4, $0
    /* 2C9C5C 003C9C5C 6C00B127 */  addiu      $17, $29, 0x6C
  .L003C9C60:
    /* 2C9C60 003C9C60 F8FF628E */  lw         $2, -0x8($19)
    /* 2C9C64 003C9C64 03004390 */  lbu        $3, 0x3($2)
    /* 2C9C68 003C9C68 01006330 */  andi       $3, $3, 0x1
    /* 2C9C6C 003C9C6C 10006010 */  beqz       $3, .L003C9CB0
    /* 2C9C70 003C9C70 F8FF7026 */   addiu     $16, $19, -0x8
    /* 2C9C74 003C9C74 2B188202 */  sltu       $3, $20, $2
    /* 2C9C78 003C9C78 08006014 */  bnez       $3, .L003C9C9C
    /* 2C9C7C 003C9C7C 00000000 */   nop
    /* 2C9C80 003C9C80 0400038E */  lw         $3, 0x4($16)
    /* 2C9C84 003C9C84 21184300 */  addu       $3, $2, $3
    /* 2C9C88 003C9C88 2B088302 */  sltu       $1, $20, $3
    /* 2C9C8C 003C9C8C 03002010 */  beqz       $1, .L003C9C9C
    /* 2C9C90 003C9C90 00000000 */   nop
    /* 2C9C94 003C9C94 12000010 */  b          .L003C9CE0
    /* 2C9C98 003C9C98 5000BFDF */   ld        $31, 0x50($29)
  .L003C9C9C:
    /* 2C9C9C 003C9C9C 0000738E */  lw         $19, 0x0($19)
    /* 2C9CA0 003C9CA0 EFFF7216 */  bne        $19, $18, .L003C9C60
    /* 2C9CA4 003C9CA4 00000000 */   nop
  .L003C9CA8:
    /* 2C9CA8 003C9CA8 0C000010 */  b          .L003C9CDC
    /* 2C9CAC 003C9CAC 2D100000 */   daddu     $2, $0, $0
  .L003C9CB0:
    /* 2C9CB0 003C9CB0 6800B4AF */  sw         $20, 0x68($29)
    /* 2C9CB4 003C9CB4 3D00053C */  lui        $5, %hi(func_003c8da0)
    /* 2C9CB8 003C9CB8 000020AE */  sw         $0, 0x0($17)
    /* 2C9CBC 003C9CBC A08DA524 */  addiu      $5, $5, %lo(func_003c8da0)
    /* 2C9CC0 003C9CC0 0000048E */  lw         $4, 0x0($16)
    /* 2C9CC4 003C9CC4 C8280F0C */  jal        func_003ca320
    /* 2C9CC8 003C9CC8 6800A627 */   addiu     $6, $29, 0x68
    /* 2C9CCC 003C9CCC 0000228E */  lw         $2, 0x0($17)
    /* 2C9CD0 003C9CD0 F2FF4010 */  beqz       $2, .L003C9C9C
    /* 2C9CD4 003C9CD4 00000000 */   nop
    /* 2C9CD8 003C9CD8 0000028E */  lw         $2, 0x0($16)
  .L003C9CDC:
    /* 2C9CDC 003C9CDC 5000BFDF */  ld         $31, 0x50($29)
  .L003C9CE0:
    /* 2C9CE0 003C9CE0 4000B47B */  lq         $20, 0x40($29)
    /* 2C9CE4 003C9CE4 3000B37B */  lq         $19, 0x30($29)
    /* 2C9CE8 003C9CE8 2000B27B */  lq         $18, 0x20($29)
    /* 2C9CEC 003C9CEC 1000B17B */  lq         $17, 0x10($29)
    /* 2C9CF0 003C9CF0 0000B07B */  lq         $16, 0x0($29)
    /* 2C9CF4 003C9CF4 0800E003 */  jr         $31
    /* 2C9CF8 003C9CF8 7000BD27 */   addiu     $29, $29, 0x70
    /* 2C9CFC 003C9CFC 00000000 */  nop
.size func_003c9c20, 0xe0
