.section .text
.set noat
.set noreorder
glabel func_004ea1c8
    /* 3EA1C8 004EA1C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA1CC 004EA1CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA1D0 004EA1D0 2D808000 */  daddu      $16, $4, $0
    /* 3EA1D4 004EA1D4 09000012 */  beqz       $16, .L004EA1FC
    /* 3EA1D8 004EA1D8 0800BFFF */   sd        $31, 0x8($29)
    /* 3EA1DC 004EA1DC 24A9130C */  jal        func_004ea490
    /* 3EA1E0 004EA1E0 00000000 */   nop
    /* 3EA1E4 004EA1E4 01000324 */  addiu      $3, $0, 0x1
    /* 3EA1E8 004EA1E8 00000282 */  lb         $2, 0x0($16)
    /* 3EA1EC 004EA1EC 03004314 */  bne        $2, $3, .L004EA1FC
    /* 3EA1F0 004EA1F0 2D200002 */   daddu     $4, $16, $0
    /* 3EA1F4 004EA1F4 26A8130C */  jal        func_004ea098
    /* 3EA1F8 004EA1F8 000000A2 */   sb        $0, 0x0($16)
  .L004EA1FC:
    /* 3EA1FC 004EA1FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA200 004EA200 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA204 004EA204 0800E003 */  jr         $31
    /* 3EA208 004EA208 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA20C 004EA20C 00000000 */  nop
.size func_004ea1c8, 0x48
