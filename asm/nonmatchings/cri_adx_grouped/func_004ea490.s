.section .text
.set noat
.set noreorder
glabel func_004ea490
    /* 3EA490 004EA490 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA494 004EA494 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA498 004EA498 2D808000 */  daddu      $16, $4, $0
    /* 3EA49C 004EA49C 08000016 */  bnez       $16, .L004EA4C0
    /* 3EA4A0 004EA4A0 0800BFFF */   sd        $31, 0x8($29)
    /* 3EA4A4 004EA4A4 7600053C */  lui        $5, %hi(D_0075BFA8)
    /* 3EA4A8 004EA4A8 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA4AC 004EA4AC 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA4B0 004EA4B0 A8BFA524 */  addiu      $5, $5, %lo(D_0075BFA8)
    /* 3EA4B4 004EA4B4 9AA71308 */  j          func_004e9e68
    /* 3EA4B8 004EA4B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA4BC 004EA4BC 00000000 */  nop
  .L004EA4C0:
    /* 3EA4C0 004EA4C0 88A7130C */  jal        func_004e9e20
    /* 3EA4C4 004EA4C4 00000000 */   nop
    /* 3EA4C8 004EA4C8 010000A2 */  sb         $0, 0x1($16)
    /* 3EA4CC 004EA4CC 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA4D0 004EA4D0 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA4D4 004EA4D4 8EA71308 */  j          func_004e9e38
    /* 3EA4D8 004EA4D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA4DC 004EA4DC 00000000 */  nop
.size func_004ea490, 0x50
