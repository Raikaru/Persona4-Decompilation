.section .text
.set noat
.set noreorder
glabel func_004eb228
    /* 3EB228 004EB228 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EB22C 004EB22C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EB230 004EB230 0800B1FF */  sd         $17, 0x8($29)
    /* 3EB234 004EB234 1000BFFF */  sd         $31, 0x10($29)
    /* 3EB238 004EB238 0400828C */  lw         $2, 0x4($4)
    /* 3EB23C 004EB23C 0400518C */  lw         $17, 0x4($2)
    /* 3EB240 004EB240 E800308E */  lw         $16, 0xE8($17)
    /* 3EB244 004EB244 10000052 */  beql       $16, $0, .L004EB288
    /* 3EB248 004EB248 0000B0DF */   ld        $16, 0x0($29)
    /* 3EB24C 004EB24C C250130C */  jal        func_004d4308
    /* 3EB250 004EB250 00000000 */   nop
    /* 3EB254 004EB254 7432130C */  jal        func_004cc9d0
    /* 3EB258 004EB258 00000000 */   nop
    /* 3EB25C 004EB25C 72AA130C */  jal        func_004ea9c8
    /* 3EB260 004EB260 2D200002 */   daddu     $4, $16, $0
    /* 3EB264 004EB264 E80020AE */  sw         $0, 0xE8($17)
    /* 3EB268 004EB268 0EAA130C */  jal        func_004ea838
    /* 3EB26C 004EB26C 2D200000 */   daddu     $4, $0, $0
    /* 3EB270 004EB270 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB274 004EB274 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB278 004EB278 1000BFDF */  ld         $31, 0x10($29)
    /* 3EB27C 004EB27C 7A321308 */  j          func_004cc9e8
    /* 3EB280 004EB280 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EB284 004EB284 00000000 */  nop
  .L004EB288:
    /* 3EB288 004EB288 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB28C 004EB28C 1000BFDF */  ld         $31, 0x10($29)
    /* 3EB290 004EB290 0800E003 */  jr         $31
    /* 3EB294 004EB294 2000BD27 */   addiu     $29, $29, 0x20
.size func_004eb228, 0x70
