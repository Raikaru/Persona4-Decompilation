.section .text
.set noat
.set noreorder
glabel func_004c12a8
    /* 3C12A8 004C12A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C12AC 004C12AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C12B0 004C12B0 2D808000 */  daddu      $16, $4, $0
    /* 3C12B4 004C12B4 0800BFFF */  sd         $31, 0x8($29)
    /* 3C12B8 004C12B8 D6F5120C */  jal        func_004bd758
    /* 3C12BC 004C12BC 0400048E */   lw        $4, 0x4($16)
    /* 3C12C0 004C12C0 5400048E */  lw         $4, 0x54($16)
    /* 3C12C4 004C12C4 5C00038E */  lw         $3, 0x5C($16)
    /* 3C12C8 004C12C8 18104400 */  mult       $2, $2, $4
    /* 3C12CC 004C12CC 23180300 */  negu       $3, $3
    /* 3C12D0 004C12D0 01006050 */  beql       $3, $0, .L004C12D8
    /* 3C12D4 004C12D4 CD010000 */   break     0, 7
  .L004C12D8:
    /* 3C12D8 004C12D8 0000B0DF */  ld         $16, 0x0($29)
    /* 3C12DC 004C12DC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C12E0 004C12E0 1A004300 */  div        $0, $2, $3
    /* 3C12E4 004C12E4 12100000 */  mflo       $2
    /* 3C12E8 004C12E8 23108200 */  subu       $2, $4, $2
    /* 3C12EC 004C12EC 0800E003 */  jr         $31
    /* 3C12F0 004C12F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C12F4 004C12F4 00000000 */  nop
.size func_004c12a8, 0x50
