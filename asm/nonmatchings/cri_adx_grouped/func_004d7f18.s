.section .text
.set noat
.set noreorder
glabel func_004d7f18
    /* 3D7F18 004D7F18 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D7F1C 004D7F1C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D7F20 004D7F20 2D888000 */  daddu      $17, $4, $0
    /* 3D7F24 004D7F24 0000B0FF */  sd         $16, 0x0($29)
    /* 3D7F28 004D7F28 1000B2FF */  sd         $18, 0x10($29)
    /* 3D7F2C 004D7F2C 1800B3FF */  sd         $19, 0x18($29)
    /* 3D7F30 004D7F30 2000B4FF */  sd         $20, 0x20($29)
    /* 3D7F34 004D7F34 2800BFFF */  sd         $31, 0x28($29)
    /* 3D7F38 004D7F38 6C002282 */  lb         $2, 0x6C($17)
    /* 3D7F3C 004D7F3C 0A004014 */  bnez       $2, .L004D7F68
    /* 3D7F40 004D7F40 00000000 */   nop
    /* 3D7F44 004D7F44 FC3A130C */  jal        func_004cebf0
    /* 3D7F48 004D7F48 0400248E */   lw        $4, 0x4($17)
    /* 3D7F4C 004D7F4C C400238E */  lw         $3, 0xC4($17)
    /* 3D7F50 004D7F50 2A104300 */  slt        $2, $2, $3
    /* 3D7F54 004D7F54 04004014 */  bnez       $2, .L004D7F68
    /* 3D7F58 004D7F58 00000000 */   nop
    /* 3D7F5C 004D7F5C 0400248E */  lw         $4, 0x4($17)
    /* 3D7F60 004D7F60 523B130C */  jal        func_004ced48
    /* 3D7F64 004D7F64 FFFF0524 */   addiu     $5, $0, -0x1
  .L004D7F68:
    /* 3D7F68 004D7F68 2637130C */  jal        func_004cdc98
    /* 3D7F6C 004D7F6C 0400248E */   lw        $4, 0x4($17)
    /* 3D7F70 004D7F70 03000324 */  addiu      $3, $0, 0x3
    /* 3D7F74 004D7F74 1B004354 */  bnel       $2, $3, .L004D7FE4
    /* 3D7F78 004D7F78 0000B0DF */   ld        $16, 0x0($29)
    /* 3D7F7C 004D7F7C 0400248E */  lw         $4, 0x4($17)
    /* 3D7F80 004D7F80 2D980000 */  daddu      $19, $0, $0
    /* 3D7F84 004D7F84 7200143C */  lui        $20, %hi(D_00724EC0)
    /* 3D7F88 004D7F88 6A3B130C */  jal        func_004ceda8
    /* 3D7F8C 004D7F8C 18003026 */   addiu     $16, $17, 0x18
    /* 3D7F90 004D7F90 2D904000 */  daddu      $18, $2, $0
    /* 3D7F94 004D7F94 7200023C */  lui        $2, %hi(D_00724EBC)
    /* 3D7F98 004D7F98 02000010 */  b          .L004D7FA4
    /* 3D7F9C 004D7F9C BC4E52AC */   sw        $18, %lo(D_00724EBC)($2)
  .L004D7FA0:
    /* 3D7FA0 004D7FA0 01007326 */  addiu      $19, $19, 0x1
  .L004D7FA4:
    /* 3D7FA4 004D7FA4 2A107202 */  slt        $2, $19, $18
    /* 3D7FA8 004D7FA8 0A004010 */  beqz       $2, .L004D7FD4
    /* 3D7FAC 004D7FAC 00000000 */   nop
    /* 3D7FB0 004D7FB0 0000048E */  lw         $4, 0x0($16)
    /* 3D7FB4 004D7FB4 04001026 */  addiu      $16, $16, 0x4
    /* 3D7FB8 004D7FB8 0000838C */  lw         $3, 0x0($4)
    /* 3D7FBC 004D7FBC 2400628C */  lw         $2, 0x24($3)
    /* 3D7FC0 004D7FC0 09F84000 */  jalr       $2
    /* 3D7FC4 004D7FC4 01000524 */   addiu     $5, $0, 0x1
    /* 3D7FC8 004D7FC8 40004328 */  slti       $3, $2, 0x40
    /* 3D7FCC 004D7FCC F4FF6014 */  bnez       $3, .L004D7FA0
    /* 3D7FD0 004D7FD0 C04E82AE */   sw        $2, %lo(D_00724EC0)($20)
  .L004D7FD4:
    /* 3D7FD4 004D7FD4 03007216 */  bne        $19, $18, .L004D7FE4
    /* 3D7FD8 004D7FD8 0000B0DF */   ld        $16, 0x0($29)
    /* 3D7FDC 004D7FDC 04000224 */  addiu      $2, $0, 0x4
    /* 3D7FE0 004D7FE0 010022A2 */  sb         $2, 0x1($17)
  .L004D7FE4:
    /* 3D7FE4 004D7FE4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D7FE8 004D7FE8 1000B2DF */  ld         $18, 0x10($29)
    /* 3D7FEC 004D7FEC 1800B3DF */  ld         $19, 0x18($29)
    /* 3D7FF0 004D7FF0 2000B4DF */  ld         $20, 0x20($29)
    /* 3D7FF4 004D7FF4 2800BFDF */  ld         $31, 0x28($29)
    /* 3D7FF8 004D7FF8 0800E003 */  jr         $31
    /* 3D7FFC 004D7FFC 3000BD27 */   addiu     $29, $29, 0x30
.size func_004d7f18, 0xe8
