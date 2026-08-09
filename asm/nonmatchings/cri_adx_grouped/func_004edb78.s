.section .text
.set noat
.set noreorder
glabel func_004edb78
    /* 3EDB78 004EDB78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDB7C 004EDB7C 08008014 */  bnez       $4, .L004EDBA0
    /* 3EDB80 004EDB80 0000BFFF */   sd        $31, 0x0($29)
    /* 3EDB84 004EDB84 7600043C */  lui        $4, %hi(D_0075CD10)
    /* 3EDB88 004EDB88 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3EDB8C 004EDB8C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDB90 004EDB90 10CD8424 */  addiu      $4, $4, %lo(D_0075CD10)
    /* 3EDB94 004EDB94 40CCA524 */  addiu      $5, $5, %lo(D_0075CC40)
    /* 3EDB98 004EDB98 2EB51308 */  j          func_004ed4b8
    /* 3EDB9C 004EDB9C 1000BD27 */   addiu     $29, $29, 0x10
  .L004EDBA0:
    /* 3EDBA0 004EDBA0 0400828C */  lw         $2, 0x4($4)
    /* 3EDBA4 004EDBA4 08004054 */  bnel       $2, $0, .L004EDBC8
    /* 3EDBA8 004EDBA8 0400C28C */   lw        $2, 0x4($6)
    /* 3EDBAC 004EDBAC 7600043C */  lui        $4, %hi(D_0075CD20)
    /* 3EDBB0 004EDBB0 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3EDBB4 004EDBB4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDBB8 004EDBB8 20CD8424 */  addiu      $4, $4, %lo(D_0075CD20)
    /* 3EDBBC 004EDBBC 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
    /* 3EDBC0 004EDBC0 2EB51308 */  j          func_004ed4b8
    /* 3EDBC4 004EDBC4 1000BD27 */   addiu     $29, $29, 0x10
  .L004EDBC8:
    /* 3EDBC8 004EDBC8 10004018 */  blez       $2, .L004EDC0C
    /* 3EDBCC 004EDBCC 0000BFDF */   ld        $31, 0x0($29)
    /* 3EDBD0 004EDBD0 0000C28C */  lw         $2, 0x0($6)
    /* 3EDBD4 004EDBD4 0D004010 */  beqz       $2, .L004EDC0C
    /* 3EDBD8 004EDBD8 00000000 */   nop
    /* 3EDBDC 004EDBDC 0B00A010 */  beqz       $5, .L004EDC0C
    /* 3EDBE0 004EDBE0 01000224 */   addiu     $2, $0, 0x1
    /* 3EDBE4 004EDBE4 0900A210 */  beq        $5, $2, .L004EDC0C
    /* 3EDBE8 004EDBE8 00000000 */   nop
    /* 3EDBEC 004EDBEC 1C00828C */  lw         $2, 0x1C($4)
    /* 3EDBF0 004EDBF0 0000C0AC */  sw         $0, 0x0($6)
    /* 3EDBF4 004EDBF4 05004010 */  beqz       $2, .L004EDC0C
    /* 3EDBF8 004EDBF8 0400C0AC */   sw        $0, 0x4($6)
    /* 3EDBFC 004EDBFC 2000848C */  lw         $4, 0x20($4)
    /* 3EDC00 004EDC00 09F84000 */  jalr       $2
    /* 3EDC04 004EDC04 FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EDC08 004EDC08 0000BFDF */  ld         $31, 0x0($29)
  .L004EDC0C:
    /* 3EDC0C 004EDC0C 0800E003 */  jr         $31
    /* 3EDC10 004EDC10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDC14 004EDC14 00000000 */  nop
.size func_004edb78, 0xa0
