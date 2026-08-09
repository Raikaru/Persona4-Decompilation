.section .text
.set noat
.set noreorder
glabel func_001eb3b0
    /* EB3B0 001EB3B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EB3B4 001EB3B4 1000BFFF */  sd         $31, 0x10($29)
    /* EB3B8 001EB3B8 0000B07F */  sq         $16, 0x0($29)
    /* EB3BC 001EB3BC 2D808000 */  daddu      $16, $4, $0
    /* EB3C0 001EB3C0 04AD070C */  jal        func_001eb410
    /* EB3C4 001EB3C4 00000000 */   nop
    /* EB3C8 001EB3C8 360000A6 */  sh         $0, 0x36($16)
    /* EB3CC 001EB3CC 380000A6 */  sh         $0, 0x38($16)
    /* EB3D0 001EB3D0 340000A6 */  sh         $0, 0x34($16)
    /* EB3D4 001EB3D4 500000AE */  sw         $0, 0x50($16)
    /* EB3D8 001EB3D8 540000AE */  sw         $0, 0x54($16)
    /* EB3DC 001EB3DC 580000AE */  sw         $0, 0x58($16)
    /* EB3E0 001EB3E0 3E000426 */  addiu      $4, $16, 0x3E
    /* EB3E4 001EB3E4 2D280000 */  daddu      $5, $0, $0
    /* EB3E8 001EB3E8 06000624 */  addiu      $6, $0, 0x6
    /* EB3EC 001EB3EC 72FE100C */  jal        func_0043f9c8
    /* EB3F0 001EB3F0 00000000 */   nop
    /* EB3F4 001EB3F4 1000BFDF */  ld         $31, 0x10($29)
    /* EB3F8 001EB3F8 0000B07B */  lq         $16, 0x0($29)
    /* EB3FC 001EB3FC 2000BD27 */  addiu      $29, $29, 0x20
    /* EB400 001EB400 0800E003 */  jr         $31
    /* EB404 001EB404 00000000 */   nop
    /* EB408 001EB408 00000000 */  nop
    /* EB40C 001EB40C 00000000 */  nop
.size func_001eb3b0, 0x60
