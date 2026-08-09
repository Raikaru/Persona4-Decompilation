.section .text
.set noat
.set noreorder
glabel func_00523f90
    /* 423F90 00523F90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 423F94 00523F94 0000B0FF */  sd         $16, 0x0($29)
    /* 423F98 00523F98 0800B1FF */  sd         $17, 0x8($29)
    /* 423F9C 00523F9C 0900A018 */  blez       $5, .L00523FC4
    /* 423FA0 00523FA0 1000BFFF */   sd        $31, 0x10($29)
    /* 423FA4 00523FA4 2D888000 */  daddu      $17, $4, $0
    /* 423FA8 00523FA8 2D80A000 */  daddu      $16, $5, $0
    /* 423FAC 00523FAC 2D202002 */  daddu      $4, $17, $0
  .L00523FB0:
    /* 423FB0 00523FB0 D80D3126 */  addiu      $17, $17, 0xDD8
    /* 423FB4 00523FB4 F68F140C */  jal        func_00523fd8
    /* 423FB8 00523FB8 FFFF1026 */   addiu     $16, $16, -0x1
    /* 423FBC 00523FBC FCFF0016 */  bnez       $16, .L00523FB0
    /* 423FC0 00523FC0 2D202002 */   daddu     $4, $17, $0
  .L00523FC4:
    /* 423FC4 00523FC4 0000B0DF */  ld         $16, 0x0($29)
    /* 423FC8 00523FC8 0800B1DF */  ld         $17, 0x8($29)
    /* 423FCC 00523FCC 1000BFDF */  ld         $31, 0x10($29)
    /* 423FD0 00523FD0 0800E003 */  jr         $31
    /* 423FD4 00523FD4 2000BD27 */   addiu     $29, $29, 0x20
.size func_00523f90, 0x48
