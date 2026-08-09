.section .text
.set noat
.set noreorder
glabel func_004ec8b8
    /* 3EC8B8 004EC8B8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC8BC 004EC8BC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EC8C0 004EC8C0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC8C4 004EC8C4 01000524 */  addiu      $5, $0, 0x1
    /* 3EC8C8 004EC8C8 0000B0FF */  sd         $16, 0x0($29)
    /* 3EC8CC 004EC8CC 2D808000 */  daddu      $16, $4, $0
    /* 3EC8D0 004EC8D0 05006514 */  bne        $3, $5, .L004EC8E8
    /* 3EC8D4 004EC8D4 0800BFFF */   sd        $31, 0x8($29)
    /* 3EC8D8 004EC8D8 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC8DC 004EC8DC 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC8E0 004EC8E0 09006058 */  blezl      $3, .L004EC908
    /* 3EC8E4 004EC8E4 0000B0DF */   ld        $16, 0x0($29)
  .L004EC8E8:
    /* 3EC8E8 004EC8E8 46B2130C */  jal        func_004ec918
    /* 3EC8EC 004EC8EC 2D280000 */   daddu     $5, $0, $0
    /* 3EC8F0 004EC8F0 2D200002 */  daddu      $4, $16, $0
    /* 3EC8F4 004EC8F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EC8F8 004EC8F8 2D280000 */  daddu      $5, $0, $0
    /* 3EC8FC 004EC8FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EC900 004EC900 6CB21308 */  j          func_004ec9b0
    /* 3EC904 004EC904 1000BD27 */   addiu     $29, $29, 0x10
  .L004EC908:
    /* 3EC908 004EC908 0800BFDF */  ld         $31, 0x8($29)
    /* 3EC90C 004EC90C 0800E003 */  jr         $31
    /* 3EC910 004EC910 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EC914 004EC914 00000000 */  nop
.size func_004ec8b8, 0x60
