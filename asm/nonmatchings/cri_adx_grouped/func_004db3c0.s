.section .text
.set noat
.set noreorder
glabel func_004db3c0
    /* 3DB3C0 004DB3C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DB3C4 004DB3C4 0000B0FF */  sd         $16, 0x0($29)
    /* 3DB3C8 004DB3C8 0800B1FF */  sd         $17, 0x8($29)
    /* 3DB3CC 004DB3CC 1000BFFF */  sd         $31, 0x10($29)
    /* 3DB3D0 004DB3D0 C250130C */  jal        func_004d4308
    /* 3DB3D4 004DB3D4 2D808000 */   daddu     $16, $4, $0
    /* 3DB3D8 004DB3D8 0400028E */  lw         $2, 0x4($16)
    /* 3DB3DC 004DB3DC 0400518C */  lw         $17, 0x4($2)
    /* 3DB3E0 004DB3E0 B400308E */  lw         $16, 0xB4($17)
    /* 3DB3E4 004DB3E4 0E000052 */  beql       $16, $0, .L004DB420
    /* 3DB3E8 004DB3E8 0000B0DF */   ld        $16, 0x0($29)
    /* 3DB3EC 004DB3EC 7432130C */  jal        func_004cc9d0
    /* 3DB3F0 004DB3F0 00000000 */   nop
    /* 3DB3F4 004DB3F4 4477130C */  jal        func_004ddd10
    /* 3DB3F8 004DB3F8 2D200002 */   daddu     $4, $16, $0
    /* 3DB3FC 004DB3FC 0477130C */  jal        func_004ddc10
    /* 3DB400 004DB400 2D200002 */   daddu     $4, $16, $0
    /* 3DB404 004DB404 7A32130C */  jal        func_004cc9e8
    /* 3DB408 004DB408 B40020AE */   sw        $0, 0xB4($17)
    /* 3DB40C 004DB40C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DB410 004DB410 0800B1DF */  ld         $17, 0x8($29)
    /* 3DB414 004DB414 1000BFDF */  ld         $31, 0x10($29)
    /* 3DB418 004DB418 8C761308 */  j          func_004dda30
    /* 3DB41C 004DB41C 2000BD27 */   addiu     $29, $29, 0x20
  .L004DB420:
    /* 3DB420 004DB420 0800B1DF */  ld         $17, 0x8($29)
    /* 3DB424 004DB424 1000BFDF */  ld         $31, 0x10($29)
    /* 3DB428 004DB428 0800E003 */  jr         $31
    /* 3DB42C 004DB42C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004db3c0, 0x70
