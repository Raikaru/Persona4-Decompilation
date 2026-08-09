.section .text
.set noat
.set noreorder
glabel func_0050fd60
    /* 40FD60 0050FD60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40FD64 0050FD64 0000B0FF */  sd         $16, 0x0($29)
    /* 40FD68 0050FD68 2D80A000 */  daddu      $16, $5, $0
    /* 40FD6C 0050FD6C 0800B1FF */  sd         $17, 0x8($29)
    /* 40FD70 0050FD70 1000BFFF */  sd         $31, 0x10($29)
    /* 40FD74 0050FD74 0A35140C */  jal        func_0050d428
    /* 40FD78 0050FD78 2D888000 */   daddu     $17, $4, $0
    /* 40FD7C 0050FD7C 7600043C */  lui        $4, %hi(D_0075FC78)
    /* 40FD80 0050FD80 01000324 */  addiu      $3, $0, 0x1
    /* 40FD84 0050FD84 06004310 */  beq        $2, $3, .L0050FDA0
    /* 40FD88 0050FD88 78FC8424 */   addiu     $4, $4, %lo(D_0075FC78)
    /* 40FD8C 0050FD8C 0000B0DF */  ld         $16, 0x0($29)
    /* 40FD90 0050FD90 0800B1DF */  ld         $17, 0x8($29)
    /* 40FD94 0050FD94 1000BFDF */  ld         $31, 0x10($29)
    /* 40FD98 0050FD98 88441408 */  j          func_00511220
    /* 40FD9C 0050FD9C 2000BD27 */   addiu     $29, $29, 0x20
  .L0050FDA0:
    /* 40FDA0 0050FDA0 09000056 */  bnel       $16, $0, .L0050FDC8
    /* 40FDA4 0050FDA4 4800248E */   lw        $4, 0x48($17)
    /* 40FDA8 0050FDA8 7600043C */  lui        $4, %hi(D_0075FCA8)
    /* 40FDAC 0050FDAC 0000B0DF */  ld         $16, 0x0($29)
    /* 40FDB0 0050FDB0 0800B1DF */  ld         $17, 0x8($29)
    /* 40FDB4 0050FDB4 A8FC8424 */  addiu      $4, $4, %lo(D_0075FCA8)
    /* 40FDB8 0050FDB8 1000BFDF */  ld         $31, 0x10($29)
    /* 40FDBC 0050FDBC 88441408 */  j          func_00511220
    /* 40FDC0 0050FDC0 2000BD27 */   addiu     $29, $29, 0x20
    /* 40FDC4 0050FDC4 00000000 */  nop
  .L0050FDC8:
    /* 40FDC8 0050FDC8 24A4130C */  jal        func_004e9090
    /* 40FDCC 0050FDCC 2D280002 */   daddu     $5, $16, $0
    /* 40FDD0 0050FDD0 7600043C */  lui        $4, %hi(D_0075FCD8)
    /* 40FDD4 0050FDD4 2D280002 */  daddu      $5, $16, $0
    /* 40FDD8 0050FDD8 09004104 */  bgez       $2, .L0050FE00
    /* 40FDDC 0050FDDC D8FC8424 */   addiu     $4, $4, %lo(D_0075FCD8)
    /* 40FDE0 0050FDE0 04000224 */  addiu      $2, $0, 0x4
    /* 40FDE4 0050FDE4 0000B0DF */  ld         $16, 0x0($29)
    /* 40FDE8 0050FDE8 040022AE */  sw         $2, 0x4($17)
    /* 40FDEC 0050FDEC 1000BFDF */  ld         $31, 0x10($29)
    /* 40FDF0 0050FDF0 0800B1DF */  ld         $17, 0x8($29)
    /* 40FDF4 0050FDF4 88441408 */  j          func_00511220
    /* 40FDF8 0050FDF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 40FDFC 0050FDFC 00000000 */  nop
  .L0050FE00:
    /* 40FE00 0050FE00 7400228E */  lw         $2, 0x74($17)
    /* 40FE04 0050FE04 0000B0DF */  ld         $16, 0x0($29)
    /* 40FE08 0050FE08 01004224 */  addiu      $2, $2, 0x1
    /* 40FE0C 0050FE0C 1000BFDF */  ld         $31, 0x10($29)
    /* 40FE10 0050FE10 740022AE */  sw         $2, 0x74($17)
    /* 40FE14 0050FE14 0800B1DF */  ld         $17, 0x8($29)
    /* 40FE18 0050FE18 0800E003 */  jr         $31
    /* 40FE1C 0050FE1C 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050fd60, 0xc0
