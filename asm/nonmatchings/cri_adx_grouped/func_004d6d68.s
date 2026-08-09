.section .text
.set noat
.set noreorder
glabel func_004d6d68
    /* 3D6D68 004D6D68 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3D6D6C 004D6D6C 2000B0FF */  sd         $16, 0x20($29)
    /* 3D6D70 004D6D70 2D808000 */  daddu      $16, $4, $0
    /* 3D6D74 004D6D74 2800B1FF */  sd         $17, 0x28($29)
    /* 3D6D78 004D6D78 2D88A000 */  daddu      $17, $5, $0
    /* 3D6D7C 004D6D7C 3000B2FF */  sd         $18, 0x30($29)
    /* 3D6D80 004D6D80 2D90C000 */  daddu      $18, $6, $0
    /* 3D6D84 004D6D84 06000016 */  bnez       $16, .L004D6DA0
    /* 3D6D88 004D6D88 3800BFFF */   sd        $31, 0x38($29)
    /* 3D6D8C 004D6D8C 7600043C */  lui        $4, %hi(D_00759318)
    /* 3D6D90 004D6D90 A61A130C */  jal        func_004c6a98
    /* 3D6D94 004D6D94 18938424 */   addiu     $4, $4, %lo(D_00759318)
    /* 3D6D98 004D6D98 2C000010 */  b          .L004D6E4C
    /* 3D6D9C 004D6D9C 2000B0DF */   ld        $16, 0x20($29)
  .L004D6DA0:
    /* 3D6DA0 004D6DA0 C250130C */  jal        func_004d4308
    /* 3D6DA4 004D6DA4 00000000 */   nop
    /* 3D6DA8 004D6DA8 2D202002 */  daddu      $4, $17, $0
    /* 3D6DAC 004D6DAC B000068E */  lw         $6, 0xB0($16)
    /* 3D6DB0 004D6DB0 2D284002 */  daddu      $5, $18, $0
    /* 3D6DB4 004D6DB4 1000A727 */  addiu      $7, $29, 0x10
    /* 3D6DB8 004D6DB8 1400A827 */  addiu      $8, $29, 0x14
    /* 3D6DBC 004D6DBC 6826130C */  jal        func_004c99a0
    /* 3D6DC0 004D6DC0 1800A927 */   addiu     $9, $29, 0x18
    /* 3D6DC4 004D6DC4 21004054 */  bnel       $2, $0, .L004D6E4C
    /* 3D6DC8 004D6DC8 2000B0DF */   ld        $16, 0x20($29)
    /* 3D6DCC 004D6DCC 0800028E */  lw         $2, 0x8($16)
    /* 3D6DD0 004D6DD0 0F004054 */  bnel       $2, $0, .L004D6E10
    /* 3D6DD4 004D6DD4 1000A78F */   lw        $7, 0x10($29)
    /* 3D6DD8 004D6DD8 2D202002 */  daddu      $4, $17, $0
    /* 3D6DDC 004D6DDC 2D284002 */  daddu      $5, $18, $0
    /* 3D6DE0 004D6DE0 2D30A003 */  daddu      $6, $29, $0
    /* 3D6DE4 004D6DE4 1A1B130C */  jal        func_004c6c68
    /* 3D6DE8 004D6DE8 10000724 */   addiu     $7, $0, 0x10
    /* 3D6DEC 004D6DEC 7600043C */  lui        $4, %hi(D_00759348)
    /* 3D6DF0 004D6DF0 48938424 */  addiu      $4, $4, %lo(D_00759348)
    /* 3D6DF4 004D6DF4 BC1A130C */  jal        func_004c6af0
    /* 3D6DF8 004D6DF8 2D28A003 */   daddu     $5, $29, $0
    /* 3D6DFC 004D6DFC FFFF0224 */  addiu      $2, $0, -0x1
    /* 3D6E00 004D6E00 06000324 */  addiu      $3, $0, 0x6
    /* 3D6E04 004D6E04 600002A6 */  sh         $2, 0x60($16)
    /* 3D6E08 004D6E08 0F000010 */  b          .L004D6E48
    /* 3D6E0C 004D6E0C 010003A2 */   sb        $3, 0x1($16)
  .L004D6E10:
    /* 3D6E10 004D6E10 01000224 */  addiu      $2, $0, 0x1
    /* 3D6E14 004D6E14 1400A68F */  lw         $6, 0x14($29)
    /* 3D6E18 004D6E18 2D200002 */  daddu      $4, $16, $0
    /* 3D6E1C 004D6E1C 1800A38F */  lw         $3, 0x18($29)
    /* 3D6E20 004D6E20 2D280000 */  daddu      $5, $0, $0
    /* 3D6E24 004D6E24 B000088E */  lw         $8, 0xB0($16)
    /* 3D6E28 004D6E28 B80007AE */  sw         $7, 0xB8($16)
    /* 3D6E2C 004D6E2C B40008AE */  sw         $8, 0xB4($16)
    /* 3D6E30 004D6E30 BC0006AE */  sw         $6, 0xBC($16)
    /* 3D6E34 004D6E34 C00003AE */  sw         $3, 0xC0($16)
    /* 3D6E38 004D6E38 020002A2 */  sb         $2, 0x2($16)
    /* 3D6E3C 004D6E3C 010002A2 */  sb         $2, 0x1($16)
    /* 3D6E40 004D6E40 6E59130C */  jal        func_004d65b8
    /* 3D6E44 004D6E44 AC0002A2 */   sb        $2, 0xAC($16)
  .L004D6E48:
    /* 3D6E48 004D6E48 2000B0DF */  ld         $16, 0x20($29)
  .L004D6E4C:
    /* 3D6E4C 004D6E4C 2800B1DF */  ld         $17, 0x28($29)
    /* 3D6E50 004D6E50 3000B2DF */  ld         $18, 0x30($29)
    /* 3D6E54 004D6E54 3800BFDF */  ld         $31, 0x38($29)
    /* 3D6E58 004D6E58 0800E003 */  jr         $31
    /* 3D6E5C 004D6E5C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004d6d68, 0xf8
