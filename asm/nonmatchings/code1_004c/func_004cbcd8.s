.section .text
.set noat
.set noreorder
glabel func_004cbcd8
    /* 3CBCD8 004CBCD8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CBCDC 004CBCDC 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBCE0 004CBCE0 2D808000 */  daddu      $16, $4, $0
    /* 3CBCE4 004CBCE4 0C000012 */  beqz       $16, .L004CBD18
    /* 3CBCE8 004CBCE8 3800BFFF */   sd        $31, 0x38($29)
    /* 3CBCEC 004CBCEC B885100C */  jal        func_004216e0
    /* 3CBCF0 004CBCF0 2D28A003 */   daddu     $5, $29, $0
    /* 3CBCF4 004CBCF4 2D200002 */  daddu      $4, $16, $0
    /* 3CBCF8 004CBCF8 0000A38F */  lw         $3, 0x0($29)
    /* 3CBCFC 004CBCFC 04000224 */  addiu      $2, $0, 0x4
    /* 3CBD00 004CBD00 03006210 */  beq        $3, $2, .L004CBD10
    /* 3CBD04 004CBD04 0C000524 */   addiu     $5, $0, 0xC
    /* 3CBD08 004CBD08 04006514 */  bne        $3, $5, .L004CBD1C
    /* 3CBD0C 004CBD0C 3000B0DF */   ld        $16, 0x30($29)
  .L004CBD10:
    /* 3CBD10 004CBD10 C485100C */  jal        func_00421710
    /* 3CBD14 004CBD14 00000000 */   nop
  .L004CBD18:
    /* 3CBD18 004CBD18 3000B0DF */  ld         $16, 0x30($29)
  .L004CBD1C:
    /* 3CBD1C 004CBD1C 3800BFDF */  ld         $31, 0x38($29)
    /* 3CBD20 004CBD20 0800E003 */  jr         $31
    /* 3CBD24 004CBD24 4000BD27 */   addiu     $29, $29, 0x40
.size func_004cbcd8, 0x50
