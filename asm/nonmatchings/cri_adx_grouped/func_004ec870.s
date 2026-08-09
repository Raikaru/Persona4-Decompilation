.section .text
.set noat
.set noreorder
glabel func_004ec870
    /* 3EC870 004EC870 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC874 004EC874 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EC878 004EC878 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC87C 004EC87C 01000424 */  addiu      $4, $0, 0x1
    /* 3EC880 004EC880 05006414 */  bne        $3, $4, .L004EC898
    /* 3EC884 004EC884 0000BFFF */   sd        $31, 0x0($29)
    /* 3EC888 004EC888 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC88C 004EC88C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC890 004EC890 07006018 */  blez       $3, .L004EC8B0
    /* 3EC894 004EC894 0000BFDF */   ld        $31, 0x0($29)
  .L004EC898:
    /* 3EC898 004EC898 7600043C */  lui        $4, %hi(D_0075CA10)
    /* 3EC89C 004EC89C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EC8A0 004EC8A0 10CA8424 */  addiu      $4, $4, %lo(D_0075CA10)
    /* 3EC8A4 004EC8A4 FC341308 */  j          func_004cd3f0
    /* 3EC8A8 004EC8A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EC8AC 004EC8AC 00000000 */  nop
  .L004EC8B0:
    /* 3EC8B0 004EC8B0 0800E003 */  jr         $31
    /* 3EC8B4 004EC8B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ec870, 0x48
