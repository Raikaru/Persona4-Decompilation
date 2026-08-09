.section .text
.set noat
.set noreorder
glabel func_004bed38
    /* 3BED38 004BED38 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BED3C 004BED3C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BED40 004BED40 2D888000 */  daddu      $17, $4, $0
    /* 3BED44 004BED44 1800B3FF */  sd         $19, 0x18($29)
    /* 3BED48 004BED48 0000B0FF */  sd         $16, 0x0($29)
    /* 3BED4C 004BED4C 1000B2FF */  sd         $18, 0x10($29)
    /* 3BED50 004BED50 2000BFFF */  sd         $31, 0x20($29)
    /* 3BED54 004BED54 5000228E */  lw         $2, 0x50($17)
    /* 3BED58 004BED58 0B004014 */  bnez       $2, .L004BED88
    /* 3BED5C 004BED5C 2D98A000 */   daddu     $19, $5, $0
    /* 3BED60 004BED60 7500043C */  lui        $4, %hi(D_00756E80)
    /* 3BED64 004BED64 0000B0DF */  ld         $16, 0x0($29)
    /* 3BED68 004BED68 0800B1DF */  ld         $17, 0x8($29)
    /* 3BED6C 004BED6C 806E8424 */  addiu      $4, $4, %lo(D_00756E80)
    /* 3BED70 004BED70 1000B2DF */  ld         $18, 0x10($29)
    /* 3BED74 004BED74 1800B3DF */  ld         $19, 0x18($29)
    /* 3BED78 004BED78 2000BFDF */  ld         $31, 0x20($29)
    /* 3BED7C 004BED7C A8F51208 */  j          func_004bd6a0
    /* 3BED80 004BED80 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BED84 004BED84 00000000 */  nop
  .L004BED88:
    /* 3BED88 004BED88 96F5120C */  jal        func_004bd658
    /* 3BED8C 004BED8C 2D900000 */   daddu     $18, $0, $0
    /* 3BED90 004BED90 A000228E */  lw         $2, 0xA0($17)
    /* 3BED94 004BED94 0F004058 */  blezl      $2, .L004BEDD4
    /* 3BED98 004BED98 600033AE */   sw        $19, 0x60($17)
    /* 3BED9C 004BED9C 18003026 */  addiu      $16, $17, 0x18
    /* 3BEDA0 004BEDA0 0000048E */  lw         $4, 0x0($16)
    /* 3BEDA4 004BEDA4 00000000 */  nop
  .L004BEDA8:
    /* 3BEDA8 004BEDA8 0C001026 */  addiu      $16, $16, 0xC
    /* 3BEDAC 004BEDAC 2D286002 */  daddu      $5, $19, $0
    /* 3BEDB0 004BEDB0 0000828C */  lw         $2, 0x0($4)
    /* 3BEDB4 004BEDB4 1C00438C */  lw         $3, 0x1C($2)
    /* 3BEDB8 004BEDB8 09F86000 */  jalr       $3
    /* 3BEDBC 004BEDBC 01005226 */   addiu     $18, $18, 0x1
    /* 3BEDC0 004BEDC0 A000228E */  lw         $2, 0xA0($17)
    /* 3BEDC4 004BEDC4 2A104202 */  slt        $2, $18, $2
    /* 3BEDC8 004BEDC8 F7FF4054 */  bnel       $2, $0, .L004BEDA8
    /* 3BEDCC 004BEDCC 0000048E */   lw        $4, 0x0($16)
    /* 3BEDD0 004BEDD0 600033AE */  sw         $19, 0x60($17)
  .L004BEDD4:
    /* 3BEDD4 004BEDD4 0000B0DF */  ld         $16, 0x0($29)
    /* 3BEDD8 004BEDD8 0800B1DF */  ld         $17, 0x8($29)
    /* 3BEDDC 004BEDDC 1000B2DF */  ld         $18, 0x10($29)
    /* 3BEDE0 004BEDE0 1800B3DF */  ld         $19, 0x18($29)
    /* 3BEDE4 004BEDE4 2000BFDF */  ld         $31, 0x20($29)
    /* 3BEDE8 004BEDE8 9CF51208 */  j          func_004bd670
    /* 3BEDEC 004BEDEC 3000BD27 */   addiu     $29, $29, 0x30
.size func_004bed38, 0xb8
