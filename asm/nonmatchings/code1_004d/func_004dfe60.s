.section .text
.set noat
.set noreorder
glabel func_004dfe60
    /* 3DFE60 004DFE60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3DFE64 004DFE64 3F00A224 */  addiu      $2, $5, 0x3F
    /* 3DFE68 004DFE68 0800B1FF */  sd         $17, 0x8($29)
    /* 3DFE6C 004DFE6C 2D888000 */  daddu      $17, $4, $0
    /* 3DFE70 004DFE70 1800B3FF */  sd         $19, 0x18($29)
    /* 3DFE74 004DFE74 C0FF0424 */  addiu      $4, $0, -0x40
    /* 3DFE78 004DFE78 2000B4FF */  sd         $20, 0x20($29)
    /* 3DFE7C 004DFE7C 24A04400 */  and        $20, $2, $4
    /* 3DFE80 004DFE80 0000B0FF */  sd         $16, 0x0($29)
    /* 3DFE84 004DFE84 23288502 */  subu       $5, $20, $5
    /* 3DFE88 004DFE88 1000B2FF */  sd         $18, 0x10($29)
    /* 3DFE8C 004DFE8C 01000224 */  addiu      $2, $0, 0x1
    /* 3DFE90 004DFE90 2800B5FF */  sd         $21, 0x28($29)
    /* 3DFE94 004DFE94 3000B6FF */  sd         $22, 0x30($29)
    /* 3DFE98 004DFE98 3800BFFF */  sd         $31, 0x38($29)
    /* 3DFE9C 004DFE9C 6802238E */  lw         $3, 0x268($17)
    /* 3DFEA0 004DFEA0 03006214 */  bne        $3, $2, .L004DFEB0
    /* 3DFEA4 004DFEA4 2398C500 */   subu      $19, $6, $5
    /* 3DFEA8 004DFEA8 09000010 */  b          .L004DFED0
    /* 3DFEAC 004DFEAC C0851234 */   ori       $18, $0, 0x85C0
  .L004DFEB0:
    /* 3DFEB0 004DFEB0 02002382 */  lb         $3, 0x2($17)
    /* 3DFEB4 004DFEB4 80110300 */  sll        $2, $3, 6
    /* 3DFEB8 004DFEB8 21104300 */  addu       $2, $2, $3
    /* 3DFEBC 004DFEBC 80100200 */  sll        $2, $2, 2
    /* 3DFEC0 004DFEC0 23104300 */  subu       $2, $2, $3
    /* 3DFEC4 004DFEC4 80110200 */  sll        $2, $2, 6
    /* 3DFEC8 004DFEC8 7F004224 */  addiu      $2, $2, 0x7F
    /* 3DFECC 004DFECC 24904400 */  and        $18, $2, $4
  .L004DFED0:
    /* 3DFED0 004DFED0 03002282 */  lb         $2, 0x3($17)
    /* 3DFED4 004DFED4 1D004018 */  blez       $2, .L004DFF4C
    /* 3DFED8 004DFED8 2DA80000 */   daddu     $21, $0, $0
    /* 3DFEDC 004DFEDC 01001624 */  addiu      $22, $0, 0x1
    /* 3DFEE0 004DFEE0 0C003026 */  addiu      $16, $17, 0xC
    /* 3DFEE4 004DFEE4 00000000 */  nop
  .L004DFEE8:
    /* 3DFEE8 004DFEE8 2D108002 */  daddu      $2, $20, $0
    /* 3DFEEC 004DFEEC 23987202 */  subu       $19, $19, $18
    /* 3DFEF0 004DFEF0 2D204000 */  daddu      $4, $2, $0
    /* 3DFEF4 004DFEF4 2D284000 */  daddu      $5, $2, $0
    /* 3DFEF8 004DFEF8 21A05200 */  addu       $20, $2, $18
    /* 3DFEFC 004DFEFC 14006006 */  bltz       $19, .L004DFF50
    /* 3DFF00 004DFF00 FFFF0224 */   addiu     $2, $0, -0x1
    /* 3DFF04 004DFF04 6802228E */  lw         $2, 0x268($17)
    /* 3DFF08 004DFF08 07005654 */  bnel       $2, $22, .L004DFF28
    /* 3DFF0C 004DFF0C 02002482 */   lb        $4, 0x2($17)
    /* 3DFF10 004DFF10 F04E130C */  jal        func_004d3bc0
    /* 3DFF14 004DFF14 2D284002 */   daddu     $5, $18, $0
    /* 3DFF18 004DFF18 07004014 */  bnez       $2, .L004DFF38
    /* 3DFF1C 004DFF1C 000002AE */   sw        $2, 0x0($16)
  .L004DFF20:
    /* 3DFF20 004DFF20 0B000010 */  b          .L004DFF50
    /* 3DFF24 004DFF24 FFFF0224 */   addiu     $2, $0, -0x1
  .L004DFF28:
    /* 3DFF28 004DFF28 144E130C */  jal        func_004d3850
    /* 3DFF2C 004DFF2C 2D304002 */   daddu     $6, $18, $0
    /* 3DFF30 004DFF30 FBFF4010 */  beqz       $2, .L004DFF20
    /* 3DFF34 004DFF34 000002AE */   sw        $2, 0x0($16)
  .L004DFF38:
    /* 3DFF38 004DFF38 03002282 */  lb         $2, 0x3($17)
    /* 3DFF3C 004DFF3C 0100B526 */  addiu      $21, $21, 0x1
    /* 3DFF40 004DFF40 2A10A202 */  slt        $2, $21, $2
    /* 3DFF44 004DFF44 E8FF4014 */  bnez       $2, .L004DFEE8
    /* 3DFF48 004DFF48 04001026 */   addiu     $16, $16, 0x4
  .L004DFF4C:
    /* 3DFF4C 004DFF4C 2D100000 */  daddu      $2, $0, $0
  .L004DFF50:
    /* 3DFF50 004DFF50 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFF54 004DFF54 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFF58 004DFF58 1000B2DF */  ld         $18, 0x10($29)
    /* 3DFF5C 004DFF5C 1800B3DF */  ld         $19, 0x18($29)
    /* 3DFF60 004DFF60 2000B4DF */  ld         $20, 0x20($29)
    /* 3DFF64 004DFF64 2800B5DF */  ld         $21, 0x28($29)
    /* 3DFF68 004DFF68 3000B6DF */  ld         $22, 0x30($29)
    /* 3DFF6C 004DFF6C 3800BFDF */  ld         $31, 0x38($29)
    /* 3DFF70 004DFF70 0800E003 */  jr         $31
    /* 3DFF74 004DFF74 4000BD27 */   addiu     $29, $29, 0x40
.size func_004dfe60, 0x118
