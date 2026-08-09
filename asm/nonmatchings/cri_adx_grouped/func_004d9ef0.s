.section .text
.set noat
.set noreorder
glabel func_004d9ef0
    /* 3D9EF0 004D9EF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D9EF4 004D9EF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D9EF8 004D9EF8 2D808000 */  daddu      $16, $4, $0
    /* 3D9EFC 004D9EFC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D9F00 004D9F00 1000BFFF */  sd         $31, 0x10($29)
    /* 3D9F04 004D9F04 B001028E */  lw         $2, 0x1B0($16)
    /* 3D9F08 004D9F08 A6011182 */  lb         $17, 0x1A6($16)
    /* 3D9F0C 004D9F0C 03004010 */  beqz       $2, .L004D9F1C
    /* 3D9F10 004D9F10 2D204000 */   daddu     $4, $2, $0
    /* 3D9F14 004D9F14 1076130C */  jal        func_004dd840
    /* 3D9F18 004D9F18 B00100AE */   sw        $0, 0x1B0($16)
  .L004D9F1C:
    /* 3D9F1C 004D9F1C 2D200002 */  daddu      $4, $16, $0
    /* 3D9F20 004D9F20 2D280000 */  daddu      $5, $0, $0
    /* 3D9F24 004D9F24 72FE100C */  jal        func_0043f9c8
    /* 3D9F28 004D9F28 280A0624 */   addiu     $6, $0, 0xA28
    /* 3D9F2C 004D9F2C 80181100 */  sll        $3, $17, 2
    /* 3D9F30 004D9F30 0000B0DF */  ld         $16, 0x0($29)
    /* 3D9F34 004D9F34 0800B1DF */  ld         $17, 0x8($29)
    /* 3D9F38 004D9F38 1000BFDF */  ld         $31, 0x10($29)
    /* 3D9F3C 004D9F3C 7300013C */  lui        $1, %hi(D_007288E8)
    /* 3D9F40 004D9F40 21082300 */  addu       $1, $1, $3
    /* 3D9F44 004D9F44 E88820AC */  sw         $0, %lo(D_007288E8)($1)
    /* 3D9F48 004D9F48 0800E003 */  jr         $31
    /* 3D9F4C 004D9F4C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d9ef0, 0x60
