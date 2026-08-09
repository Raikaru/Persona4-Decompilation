.section .text
.set noat
.set noreorder
glabel func_004ec008
    /* 3EC008 004EC008 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC00C 004EC00C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EC010 004EC010 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC014 004EC014 01000424 */  addiu      $4, $0, 0x1
    /* 3EC018 004EC018 05006414 */  bne        $3, $4, .L004EC030
    /* 3EC01C 004EC01C 0000BFFF */   sd        $31, 0x0($29)
    /* 3EC020 004EC020 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC024 004EC024 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC028 004EC028 0C006058 */  blezl      $3, .L004EC05C
    /* 3EC02C 004EC02C 0000BFDF */   ld        $31, 0x0($29)
  .L004EC030:
    /* 3EC030 004EC030 0D000424 */  addiu      $4, $0, 0xD
    /* 3EC034 004EC034 2D280000 */  daddu      $5, $0, $0
    /* 3EC038 004EC038 2D300000 */  daddu      $6, $0, $0
    /* 3EC03C 004EC03C 2D380000 */  daddu      $7, $0, $0
    /* 3EC040 004EC040 2896130C */  jal        func_004e58a0
    /* 3EC044 004EC044 2D400000 */   daddu     $8, $0, $0
    /* 3EC048 004EC048 7400033C */  lui        $3, %hi(D_0073A780)
    /* 3EC04C 004EC04C 80A76324 */  addiu      $3, $3, %lo(D_0073A780)
    /* 3EC050 004EC050 040060AC */  sw         $0, 0x4($3)
    /* 3EC054 004EC054 000060AC */  sw         $0, 0x0($3)
    /* 3EC058 004EC058 0000BFDF */  ld         $31, 0x0($29)
  .L004EC05C:
    /* 3EC05C 004EC05C 0800E003 */  jr         $31
    /* 3EC060 004EC060 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EC064 004EC064 00000000 */  nop
.size func_004ec008, 0x60
