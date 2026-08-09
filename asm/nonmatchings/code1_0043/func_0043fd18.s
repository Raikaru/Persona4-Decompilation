.section .text
.set noat
.set noreorder
glabel func_0043fd18
    /* 33FD18 0043FD18 09000F24 */  addiu      $15, $0, 0x9
    /* 33FD1C 0043FD1C 0800EE24 */  addiu      $14, $7, 0x8
    /* 33FD20 0043FD20 1A00CF01 */  div        $0, $14, $15
    /* 33FD24 0043FD24 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 33FD28 0043FD28 0000B0FF */  sd         $16, 0x0($29)
    /* 33FD2C 0043FD2C 01000C24 */  addiu      $12, $0, 0x1
    /* 33FD30 0043FD30 1000B2FF */  sd         $18, 0x10($29)
    /* 33FD34 0043FD34 1800B3FF */  sd         $19, 0x18($29)
    /* 33FD38 0043FD38 2D80A000 */  daddu      $16, $5, $0
    /* 33FD3C 0043FD3C 2000B4FF */  sd         $20, 0x20($29)
    /* 33FD40 0043FD40 2D908000 */  daddu      $18, $4, $0
    /* 33FD44 0043FD44 2800B5FF */  sd         $21, 0x28($29)
    /* 33FD48 0043FD48 2D98C000 */  daddu      $19, $6, $0
    /* 33FD4C 0043FD4C 0800B1FF */  sd         $17, 0x8($29)
    /* 33FD50 0043FD50 2DA00001 */  daddu      $20, $8, $0
    /* 33FD54 0043FD54 3000BFFF */  sd         $31, 0x30($29)
    /* 33FD58 0043FD58 2DA8E000 */  daddu      $21, $7, $0
    /* 33FD5C 0043FD5C 2D280000 */  daddu      $5, $0, $0
    /* 33FD60 0043FD60 0100E051 */  beql       $15, $0, .L0043FD68
    /* 33FD64 0043FD64 CD010000 */   break     0, 7
  .L0043FD68:
    /* 33FD68 0043FD68 12700000 */  mflo       $14
    /* 33FD6C 0043FD6C 2A788E01 */  slt        $15, $12, $14
    /* 33FD70 0043FD70 0900E011 */  beqz       $15, .L0043FD98
    /* 33FD74 0043FD74 2D204002 */   daddu     $4, $18, $0
  .L0043FD78:
    /* 33FD78 0043FD78 40600C00 */  sll        $12, $12, 1
    /* 33FD7C 0043FD7C 2A788E01 */  slt        $15, $12, $14
    /* 33FD80 0043FD80 00000000 */  nop
    /* 33FD84 0043FD84 00000000 */  nop
    /* 33FD88 0043FD88 00000000 */  nop
    /* 33FD8C 0043FD8C FAFFE015 */  bnez       $15, .L0043FD78
    /* 33FD90 0043FD90 0100A524 */   addiu     $5, $5, 0x1
    /* 33FD94 0043FD94 2D204002 */  daddu      $4, $18, $0
  .L0043FD98:
    /* 33FD98 0043FD98 CEFE100C */  jal        func_0043fb38
    /* 33FD9C 0043FD9C 09001124 */   addiu     $17, $0, 0x9
    /* 33FDA0 0043FDA0 01000F24 */  addiu      $15, $0, 0x1
    /* 33FDA4 0043FDA4 140054AC */  sw         $20, 0x14($2)
    /* 33FDA8 0043FDA8 0A006E2A */  slti       $14, $19, 0xA
    /* 33FDAC 0043FDAC 2300C015 */  bnez       $14, .L0043FE3C
    /* 33FDB0 0043FDB0 10004FAC */   sw        $15, 0x10($2)
    /* 33FDB4 0043FDB4 09001026 */  addiu      $16, $16, 0x9
  .L0043FDB8:
    /* 33FDB8 0043FDB8 00000782 */  lb         $7, 0x0($16)
    /* 33FDBC 0043FDBC 2D284000 */  daddu      $5, $2, $0
    /* 33FDC0 0043FDC0 2D204002 */  daddu      $4, $18, $0
    /* 33FDC4 0043FDC4 0A000624 */  addiu      $6, $0, 0xA
    /* 33FDC8 0043FDC8 D0FFE724 */  addiu      $7, $7, -0x30
    /* 33FDCC 0043FDCC 04FF100C */  jal        func_0043fc10
    /* 33FDD0 0043FDD0 01003126 */   addiu     $17, $17, 0x1
    /* 33FDD4 0043FDD4 2A783302 */  slt        $15, $17, $19
    /* 33FDD8 0043FDD8 F7FFE015 */  bnez       $15, .L0043FDB8
    /* 33FDDC 0043FDDC 01001026 */   addiu     $16, $16, 0x1
    /* 33FDE0 0043FDE0 01001026 */  addiu      $16, $16, 0x1
  .L0043FDE4:
    /* 33FDE4 0043FDE4 2A783502 */  slt        $15, $17, $21
    /* 33FDE8 0043FDE8 0B00E011 */  beqz       $15, .L0043FE18
    /* 33FDEC 0043FDEC 2388B102 */   subu      $17, $21, $17
    /* 33FDF0 0043FDF0 00000782 */  lb         $7, 0x0($16)
  .L0043FDF4:
    /* 33FDF4 0043FDF4 FFFF3126 */  addiu      $17, $17, -0x1
    /* 33FDF8 0043FDF8 2D284000 */  daddu      $5, $2, $0
    /* 33FDFC 0043FDFC 2D204002 */  daddu      $4, $18, $0
    /* 33FE00 0043FE00 0A000624 */  addiu      $6, $0, 0xA
    /* 33FE04 0043FE04 D0FFE724 */  addiu      $7, $7, -0x30
    /* 33FE08 0043FE08 04FF100C */  jal        func_0043fc10
    /* 33FE0C 0043FE0C 01001026 */   addiu     $16, $16, 0x1
    /* 33FE10 0043FE10 F8FF2056 */  bnel       $17, $0, .L0043FDF4
    /* 33FE14 0043FE14 00000782 */   lb        $7, 0x0($16)
  .L0043FE18:
    /* 33FE18 0043FE18 0000B0DF */  ld         $16, 0x0($29)
    /* 33FE1C 0043FE1C 0800B1DF */  ld         $17, 0x8($29)
    /* 33FE20 0043FE20 1000B2DF */  ld         $18, 0x10($29)
    /* 33FE24 0043FE24 1800B3DF */  ld         $19, 0x18($29)
    /* 33FE28 0043FE28 2000B4DF */  ld         $20, 0x20($29)
    /* 33FE2C 0043FE2C 2800B5DF */  ld         $21, 0x28($29)
    /* 33FE30 0043FE30 3000BFDF */  ld         $31, 0x30($29)
    /* 33FE34 0043FE34 0800E003 */  jr         $31
    /* 33FE38 0043FE38 4000BD27 */   addiu     $29, $29, 0x40
  .L0043FE3C:
    /* 33FE3C 0043FE3C E9FF0010 */  b          .L0043FDE4
    /* 33FE40 0043FE40 0A001026 */   addiu     $16, $16, 0xA
    /* 33FE44 0043FE44 00000000 */  nop
.size func_0043fd18, 0x130
