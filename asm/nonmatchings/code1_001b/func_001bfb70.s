.section .text
.set noat
.set noreorder
glabel func_001bfb70
    /* BFB70 001BFB70 C0FFBD27 */  addiu      $29, $29, -0x40
    /* BFB74 001BFB74 2000BFFF */  sd         $31, 0x20($29)
    /* BFB78 001BFB78 1000B17F */  sq         $17, 0x10($29)
    /* BFB7C 001BFB7C 0000B07F */  sq         $16, 0x0($29)
    /* BFB80 001BFB80 2D888000 */  daddu      $17, $4, $0
    /* BFB84 001BFB84 E000848C */  lw         $4, 0xE0($4)
    /* BFB88 001BFB88 17008010 */  beqz       $4, .L001BFBE8
    /* BFB8C 001BFB8C 00000000 */   nop
    /* BFB90 001BFB90 1A008394 */  lhu        $3, 0x1A($4)
    /* BFB94 001BFB94 01006330 */  andi       $3, $3, 0x1
    /* BFB98 001BFB98 13006010 */  beqz       $3, .L001BFBE8
    /* BFB9C 001BFB9C 00000000 */   nop
    /* BFBA0 001BFBA0 3000908C */  lw         $16, 0x30($4)
    /* BFBA4 001BFBA4 2D200002 */  daddu      $4, $16, $0
    /* BFBA8 001BFBA8 3000A527 */  addiu      $5, $29, 0x30
    /* BFBAC 001BFBAC 1456060C */  jal        func_00195850
    /* BFBB0 001BFBB0 00000000 */   nop
    /* BFBB4 001BFBB4 900001C6 */  lwc1       $f1, 0x90($16)
    /* BFBB8 001BFBB8 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* BFBBC 001BFBBC 42080046 */  mul.s      $f1, $f1, $f0
    /* BFBC0 001BFBC0 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* BFBC4 001BFBC4 00008244 */  mtc1       $2, $f0
    /* BFBC8 001BFBC8 00000000 */  nop
    /* BFBCC 001BFBCC 02030146 */  mul.s      $f12, $f0, $f1
    /* BFBD0 001BFBD0 E000248E */  lw         $4, 0xE0($17)
    /* BFBD4 001BFBD4 9C002526 */  addiu      $5, $17, 0x9C
    /* BFBD8 001BFBD8 3000A627 */  addiu      $6, $29, 0x30
    /* BFBDC 001BFBDC C3000724 */  addiu      $7, $0, 0xC3
    /* BFBE0 001BFBE0 50F3060C */  jal        func_001bcd40
    /* BFBE4 001BFBE4 00000000 */   nop
  .L001BFBE8:
    /* BFBE8 001BFBE8 2000BFDF */  ld         $31, 0x20($29)
    /* BFBEC 001BFBEC 1000B17B */  lq         $17, 0x10($29)
    /* BFBF0 001BFBF0 0000B07B */  lq         $16, 0x0($29)
    /* BFBF4 001BFBF4 4000BD27 */  addiu      $29, $29, 0x40
    /* BFBF8 001BFBF8 0800E003 */  jr         $31
    /* BFBFC 001BFBFC 00000000 */   nop
.size func_001bfb70, 0x90
