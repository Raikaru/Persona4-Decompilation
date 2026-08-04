.section .text
.set noat
.set noreorder
glabel func_0041e198
    /* 31E198 0041E198 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 31E19C 0041E19C 0000B0FF */  sd         $16, 0x0($29)
    /* 31E1A0 0041E1A0 1000BFFF */  sd         $31, 0x10($29)
    /* 31E1A4 0041E1A4 FE77100C */  jal        func_0041dff8
    /* 31E1A8 0041E1A8 2D808000 */   daddu     $16, $4, $0
    /* 31E1AC 0041E1AC 0010023C */  lui        $2, (0x10002020 >> 16)
    /* 31E1B0 0041E1B0 20204234 */  ori        $2, $2, (0x10002020 & 0xFFFF)
    /* 31E1B4 0041E1B4 0000438C */  lw         $3, 0x0($2)
    /* 31E1B8 0041E1B8 07006330 */  andi       $3, $3, 0x7
    /* 31E1BC 0041E1BC 23180300 */  negu       $3, $3
    /* 31E1C0 0041E1C0 07006530 */  andi       $5, $3, 0x7
    /* 31E1C4 0041E1C4 0500A010 */  beqz       $5, .L0041E1DC
    /* 31E1C8 0041E1C8 1000BFDF */   ld        $31, 0x10($29)
    /* 31E1CC 0041E1CC 2D200002 */  daddu      $4, $16, $0
    /* 31E1D0 0041E1D0 0000B0DF */  ld         $16, 0x0($29)
    /* 31E1D4 0041E1D4 0C781008 */  j          func_0041e030
    /* 31E1D8 0041E1D8 2000BD27 */   addiu     $29, $29, 0x20
  .L0041E1DC:
    /* 31E1DC 0041E1DC 0000B0DF */  ld         $16, 0x0($29)
    /* 31E1E0 0041E1E0 0800E003 */  jr         $31
    /* 31E1E4 0041E1E4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0041e198, 0x50
