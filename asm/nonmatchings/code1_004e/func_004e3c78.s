.section .text
.set noat
.set noreorder
glabel func_004e3c78
    /* 3E3C78 004E3C78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E3C7C 004E3C7C 7300033C */  lui        $3, %hi(D_00731C4C)
    /* 3E3C80 004E3C80 0800B1FF */  sd         $17, 0x8($29)
    /* 3E3C84 004E3C84 2D888000 */  daddu      $17, $4, $0
    /* 3E3C88 004E3C88 0000B0FF */  sd         $16, 0x0($29)
    /* 3E3C8C 004E3C8C 4C1C6324 */  addiu      $3, $3, %lo(D_00731C4C)
    /* 3E3C90 004E3C90 1000B2FF */  sd         $18, 0x10($29)
    /* 3E3C94 004E3C94 2D100000 */  daddu      $2, $0, $0
    /* 3E3C98 004E3C98 1800BFFF */  sd         $31, 0x18($29)
    /* 3E3C9C 004E3C9C 0000648C */  lw         $4, 0x0($3)
    /* 3E3CA0 004E3CA0 32008010 */  beqz       $4, .L004E3D6C
    /* 3E3CA4 004E3CA4 02000324 */   addiu     $3, $0, 0x2
    /* 3E3CA8 004E3CA8 02002482 */  lb         $4, 0x2($17)
    /* 3E3CAC 004E3CAC 30008354 */  bnel       $4, $3, .L004E3D70
    /* 3E3CB0 004E3CB0 0000B0DF */   ld        $16, 0x0($29)
    /* 3E3CB4 004E3CB4 7300123C */  lui        $18, %hi(D_00731C54)
    /* 3E3CB8 004E3CB8 01000524 */  addiu      $5, $0, 0x1
    /* 3E3CBC 004E3CBC 541C4426 */  addiu      $4, $18, %lo(D_00731C54)
    /* 3E3CC0 004E3CC0 7300023C */  lui        $2, %hi(D_00731C48)
    /* 3E3CC4 004E3CC4 000085AC */  sw         $5, 0x0($4)
    /* 3E3CC8 004E3CC8 481C4224 */  addiu      $2, $2, %lo(D_00731C48)
    /* 3E3CCC 004E3CCC 0000438C */  lw         $3, 0x0($2)
    /* 3E3CD0 004E3CD0 0F006514 */  bne        $3, $5, .L004E3D10
    /* 3E3CD4 004E3CD4 00000000 */   nop
    /* 3E3CD8 004E3CD8 9AC1130C */  jal        func_004f0668
    /* 3E3CDC 004E3CDC 00000000 */   nop
    /* 3E3CE0 004E3CE0 8691130C */  jal        func_004e4618
    /* 3E3CE4 004E3CE4 00140424 */   addiu     $4, $0, 0x1400
    /* 3E3CE8 004E3CE8 2CBD100C */  jal        func_0042f4b0
    /* 3E3CEC 004E3CEC 00000000 */   nop
    /* 3E3CF0 004E3CF0 01140424 */  addiu      $4, $0, 0x1401
    /* 3E3CF4 004E3CF4 8691130C */  jal        func_004e4618
    /* 3E3CF8 004E3CF8 2D804000 */   daddu     $16, $2, $0
    /* 3E3CFC 004E3CFC B8C1130C */  jal        func_004f06e0
    /* 3E3D00 004E3D00 00000000 */   nop
    /* 3E3D04 004E3D04 0A000010 */  b          .L004E3D30
    /* 3E3D08 004E3D08 01000226 */   addiu     $2, $16, 0x1
    /* 3E3D0C 004E3D0C 00000000 */  nop
  .L004E3D10:
    /* 3E3D10 004E3D10 8691130C */  jal        func_004e4618
    /* 3E3D14 004E3D14 00150424 */   addiu     $4, $0, 0x1500
    /* 3E3D18 004E3D18 2CBD100C */  jal        func_0042f4b0
    /* 3E3D1C 004E3D1C 00000000 */   nop
    /* 3E3D20 004E3D20 01150424 */  addiu      $4, $0, 0x1501
    /* 3E3D24 004E3D24 8691130C */  jal        func_004e4618
    /* 3E3D28 004E3D28 2D804000 */   daddu     $16, $2, $0
    /* 3E3D2C 004E3D2C 01000226 */  addiu      $2, $16, 0x1
  .L004E3D30:
    /* 3E3D30 004E3D30 541C4326 */  addiu      $3, $18, %lo(D_00731C54)
    /* 3E3D34 004E3D34 0200422C */  sltiu      $2, $2, 0x2
    /* 3E3D38 004E3D38 000060AC */  sw         $0, 0x0($3)
    /* 3E3D3C 004E3D3C 0B004014 */  bnez       $2, .L004E3D6C
    /* 3E3D40 004E3D40 2D100000 */   daddu     $2, $0, $0
    /* 3E3D44 004E3D44 20000224 */  addiu      $2, $0, 0x20
    /* 3E3D48 004E3D48 07000212 */  beq        $16, $2, .L004E3D68
    /* 3E3D4C 004E3D4C 7600043C */   lui       $4, %hi(D_0075AB18)
    /* 3E3D50 004E3D50 340030AE */  sw         $16, 0x34($17)
    /* 3E3D54 004E3D54 2D280002 */  daddu      $5, $16, $0
    /* 3E3D58 004E3D58 3291100C */  jal        func_004244c8
    /* 3E3D5C 004E3D5C 18AB8424 */   addiu     $4, $4, %lo(D_0075AB18)
    /* 3E3D60 004E3D60 02000010 */  b          .L004E3D6C
    /* 3E3D64 004E3D64 01000224 */   addiu     $2, $0, 0x1
  .L004E3D68:
    /* 3E3D68 004E3D68 2D100000 */  daddu      $2, $0, $0
  .L004E3D6C:
    /* 3E3D6C 004E3D6C 0000B0DF */  ld         $16, 0x0($29)
  .L004E3D70:
    /* 3E3D70 004E3D70 0800B1DF */  ld         $17, 0x8($29)
    /* 3E3D74 004E3D74 1000B2DF */  ld         $18, 0x10($29)
    /* 3E3D78 004E3D78 1800BFDF */  ld         $31, 0x18($29)
    /* 3E3D7C 004E3D7C 0800E003 */  jr         $31
    /* 3E3D80 004E3D80 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E3D84 004E3D84 00000000 */  nop
.size func_004e3c78, 0x110
