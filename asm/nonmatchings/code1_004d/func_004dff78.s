.section .text
.set noat
.set noreorder
glabel func_004dff78
    /* 3DFF78 004DFF78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DFF7C 004DFF7C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DFF80 004DFF80 2D888000 */  daddu      $17, $4, $0
    /* 3DFF84 004DFF84 1000B2FF */  sd         $18, 0x10($29)
    /* 3DFF88 004DFF88 2D900000 */  daddu      $18, $0, $0
    /* 3DFF8C 004DFF8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DFF90 004DFF90 1800BFFF */  sd         $31, 0x18($29)
    /* 3DFF94 004DFF94 03002282 */  lb         $2, 0x3($17)
    /* 3DFF98 004DFF98 0F004018 */  blez       $2, .L004DFFD8
    /* 3DFF9C 004DFF9C 03002392 */   lbu       $3, 0x3($17)
    /* 3DFFA0 004DFFA0 0C003026 */  addiu      $16, $17, 0xC
    /* 3DFFA4 004DFFA4 00000000 */  nop
  .L004DFFA8:
    /* 3DFFA8 004DFFA8 0000028E */  lw         $2, 0x0($16)
    /* 3DFFAC 004DFFAC 04004010 */  beqz       $2, .L004DFFC0
    /* 3DFFB0 004DFFB0 2D204000 */   daddu     $4, $2, $0
    /* 3DFFB4 004DFFB4 364F130C */  jal        func_004d3cd8
    /* 3DFFB8 004DFFB8 000000AE */   sw        $0, 0x0($16)
    /* 3DFFBC 004DFFBC 03002392 */  lbu        $3, 0x3($17)
  .L004DFFC0:
    /* 3DFFC0 004DFFC0 00160300 */  sll        $2, $3, 24
    /* 3DFFC4 004DFFC4 01005226 */  addiu      $18, $18, 0x1
    /* 3DFFC8 004DFFC8 03160200 */  sra        $2, $2, 24
    /* 3DFFCC 004DFFCC 2A104202 */  slt        $2, $18, $2
    /* 3DFFD0 004DFFD0 F5FF4014 */  bnez       $2, .L004DFFA8
    /* 3DFFD4 004DFFD4 04001026 */   addiu     $16, $16, 0x4
  .L004DFFD8:
    /* 3DFFD8 004DFFD8 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFFDC 004DFFDC 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFFE0 004DFFE0 1000B2DF */  ld         $18, 0x10($29)
    /* 3DFFE4 004DFFE4 1800BFDF */  ld         $31, 0x18($29)
    /* 3DFFE8 004DFFE8 0800E003 */  jr         $31
    /* 3DFFEC 004DFFEC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004dff78, 0x78
