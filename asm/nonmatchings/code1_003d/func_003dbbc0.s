.section .text
.set noat
.set noreorder
glabel func_003dbbc0
    /* 2DBBC0 003DBBC0 80FEBD27 */  addiu      $29, $29, -0x180
    /* 2DBBC4 003DBBC4 01000524 */  addiu      $5, $0, 0x1
    /* 2DBBC8 003DBBC8 5000BFFF */  sd         $31, 0x50($29)
    /* 2DBBCC 003DBBCC 7C01A627 */  addiu      $6, $29, 0x17C
    /* 2DBBD0 003DBBD0 4000B47F */  sq         $20, 0x40($29)
    /* 2DBBD4 003DBBD4 7801A727 */  addiu      $7, $29, 0x178
    /* 2DBBD8 003DBBD8 3000B37F */  sq         $19, 0x30($29)
    /* 2DBBDC 003DBBDC 2000B27F */  sq         $18, 0x20($29)
    /* 2DBBE0 003DBBE0 1000B17F */  sq         $17, 0x10($29)
    /* 2DBBE4 003DBBE4 0000B07F */  sq         $16, 0x0($29)
    /* 2DBBE8 003DBBE8 147C0F0C */  jal        func_003df050
    /* 2DBBEC 003DBBEC 2D808000 */   daddu     $16, $4, $0
    /* 2DBBF0 003DBBF0 5B004010 */  beqz       $2, .L003DBD60
    /* 2DBBF4 003DBBF4 00000000 */   nop
    /* 2DBBF8 003DBBF8 7801A38F */  lw         $3, 0x178($29)
    /* 2DBBFC 003DBBFC 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2DBC00 003DBC00 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2DBC04 003DBC04 2B106200 */  sltu       $2, $3, $2
    /* 2DBC08 003DBC08 7C004014 */  bnez       $2, .L003DBDFC
    /* 2DBC0C 003DBC0C 00000000 */   nop
    /* 2DBC10 003DBC10 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2DBC14 003DBC14 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2DBC18 003DBC18 2B086100 */  sltu       $1, $3, $1
    /* 2DBC1C 003DBC1C 77002010 */  beqz       $1, .L003DBDFC
    /* 2DBC20 003DBC20 00000000 */   nop
    /* 2DBC24 003DBC24 7401A427 */  addiu      $4, $29, 0x174
    /* 2DBC28 003DBC28 2D280000 */  daddu      $5, $0, $0
    /* 2DBC2C 003DBC2C 72FE100C */  jal        func_0043f9c8
    /* 2DBC30 003DBC30 04000624 */   addiu     $6, $0, 0x4
    /* 2DBC34 003DBC34 7C01B18F */  lw         $17, 0x17C($29)
    /* 2DBC38 003DBC38 2D200002 */  daddu      $4, $16, $0
    /* 2DBC3C 003DBC3C 7401A527 */  addiu      $5, $29, 0x174
    /* 2DBC40 003DBC40 448A0F0C */  jal        func_003e2910
    /* 2DBC44 003DBC44 2D302002 */   daddu     $6, $17, $0
    /* 2DBC48 003DBC48 47002216 */  bne        $17, $2, .L003DBD68
    /* 2DBC4C 003DBC4C 00000000 */   nop
    /* 2DBC50 003DBC50 7401A48F */  lw         $4, 0x174($29)
    /* 2DBC54 003DBC54 02120400 */  srl        $2, $4, 8
    /* 2DBC58 003DBC58 0F004330 */  andi       $3, $2, 0xF
    /* 2DBC5C 003DBC5C 02130400 */  srl        $2, $4, 12
    /* 2DBC60 003DBC60 0F004230 */  andi       $2, $2, 0xF
    /* 2DBC64 003DBC64 42004010 */  beqz       $2, .L003DBD70
    /* 2DBC68 003DBC68 FF009230 */   andi      $18, $4, 0xFF
  .L003DBC6C:
    /* 2DBC6C 003DBC6C 7401A28F */  lw         $2, 0x174($29)
    /* 2DBC70 003DBC70 02140200 */  srl        $2, $2, 16
    /* 2DBC74 003DBC74 08BC0F0C */  jal        func_003ef020
    /* 2DBC78 003DBC78 FF005130 */   andi      $17, $2, 0xFF
    /* 2DBC7C 003DBC7C 18BC0F0C */  jal        func_003ef060
    /* 2DBC80 003DBC80 2DA04000 */   daddu     $20, $2, $0
    /* 2DBC84 003DBC84 2D984000 */  daddu      $19, $2, $0
    /* 2DBC88 003DBC88 FDFF4226 */  addiu      $2, $18, -0x3
    /* 2DBC8C 003DBC8C 0400412C */  sltiu      $1, $2, 0x4
    /* 2DBC90 003DBC90 0E002010 */  beqz       $1, .L003DBCCC
    /* 2DBC94 003DBC94 00000000 */   nop
    /* 2DBC98 003DBC98 00BC0F0C */  jal        func_003ef000
    /* 2DBC9C 003DBC9C 01000424 */   addiu     $4, $0, 0x1
    /* 2DBCA0 003DBCA0 01002232 */  andi       $2, $17, 0x1
    /* 2DBCA4 003DBCA4 05004010 */  beqz       $2, .L003DBCBC
    /* 2DBCA8 003DBCA8 00000000 */   nop
    /* 2DBCAC 003DBCAC 10BC0F0C */  jal        func_003ef040
    /* 2DBCB0 003DBCB0 2D200000 */   daddu     $4, $0, $0
    /* 2DBCB4 003DBCB4 0A000010 */  b          .L003DBCE0
    /* 2DBCB8 003DBCB8 E000A427 */   addiu     $4, $29, 0xE0
  .L003DBCBC:
    /* 2DBCBC 003DBCBC 10BC0F0C */  jal        func_003ef040
    /* 2DBCC0 003DBCC0 01000424 */   addiu     $4, $0, 0x1
    /* 2DBCC4 003DBCC4 05000010 */  b          .L003DBCDC
    /* 2DBCC8 003DBCC8 00000000 */   nop
  .L003DBCCC:
    /* 2DBCCC 003DBCCC 00BC0F0C */  jal        func_003ef000
    /* 2DBCD0 003DBCD0 2D200000 */   daddu     $4, $0, $0
    /* 2DBCD4 003DBCD4 10BC0F0C */  jal        func_003ef040
    /* 2DBCD8 003DBCD8 2D200000 */   daddu     $4, $0, $0
  .L003DBCDC:
    /* 2DBCDC 003DBCDC E000A427 */  addiu      $4, $29, 0xE0
  .L003DBCE0:
    /* 2DBCE0 003DBCE0 D8930F0C */  jal        func_003e4f60
    /* 2DBCE4 003DBCE4 2D280002 */   daddu     $5, $16, $0
    /* 2DBCE8 003DBCE8 26004010 */  beqz       $2, .L003DBD84
    /* 2DBCEC 003DBCEC 00000000 */   nop
    /* 2DBCF0 003DBCF0 6000A427 */  addiu      $4, $29, 0x60
    /* 2DBCF4 003DBCF4 D8930F0C */  jal        func_003e4f60
    /* 2DBCF8 003DBCF8 2D280002 */   daddu     $5, $16, $0
    /* 2DBCFC 003DBCFC 27004010 */  beqz       $2, .L003DBD9C
    /* 2DBD00 003DBD00 00000000 */   nop
    /* 2DBD04 003DBD04 B8BC0F0C */  jal        func_003ef2e0
    /* 2DBD08 003DBD08 2D200000 */   daddu     $4, $0, $0
    /* 2DBD0C 003DBD0C 2D884000 */  daddu      $17, $2, $0
    /* 2DBD10 003DBD10 28002012 */  beqz       $17, .L003DBDB4
    /* 2DBD14 003DBD14 00000000 */   nop
    /* 2DBD18 003DBD18 2D202002 */  daddu      $4, $17, $0
    /* 2DBD1C 003DBD1C 1CBD0F0C */  jal        func_003ef470
    /* 2DBD20 003DBD20 E000A527 */   addiu     $5, $29, 0xE0
    /* 2DBD24 003DBD24 6000A527 */  addiu      $5, $29, 0x60
    /* 2DBD28 003DBD28 2C00A010 */  beqz       $5, .L003DBDDC
    /* 2DBD2C 003DBD2C 00000000 */   nop
    /* 2DBD30 003DBD30 44BD0F0C */  jal        func_003ef510
    /* 2DBD34 003DBD34 2D202002 */   daddu     $4, $17, $0
    /* 2DBD38 003DBD38 5400238E */  lw         $3, 0x54($17)
  .L003DBD3C:
    /* 2DBD3C 003DBD3C 01000224 */  addiu      $2, $0, 0x1
    /* 2DBD40 003DBD40 2B006210 */  beq        $3, $2, .L003DBDF0
    /* 2DBD44 003DBD44 00000000 */   nop
  .L003DBD48:
    /* 2DBD48 003DBD48 00BC0F0C */  jal        func_003ef000
    /* 2DBD4C 003DBD4C 2D208002 */   daddu     $4, $20, $0
    /* 2DBD50 003DBD50 10BC0F0C */  jal        func_003ef040
    /* 2DBD54 003DBD54 2D206002 */   daddu     $4, $19, $0
    /* 2DBD58 003DBD58 31000010 */  b          .L003DBE20
    /* 2DBD5C 003DBD5C 2D102002 */   daddu     $2, $17, $0
  .L003DBD60:
    /* 2DBD60 003DBD60 2F000010 */  b          .L003DBE20
    /* 2DBD64 003DBD64 2D100000 */   daddu     $2, $0, $0
  .L003DBD68:
    /* 2DBD68 003DBD68 2D000010 */  b          .L003DBE20
    /* 2DBD6C 003DBD6C 2D100000 */   daddu     $2, $0, $0
  .L003DBD70:
    /* 2DBD70 003DBD70 0F006230 */  andi       $2, $3, 0xF
    /* 2DBD74 003DBD74 00130200 */  sll        $2, $2, 12
    /* 2DBD78 003DBD78 25108200 */  or         $2, $4, $2
    /* 2DBD7C 003DBD7C BBFF0010 */  b          .L003DBC6C
    /* 2DBD80 003DBD80 7401A2AF */   sw        $2, 0x174($29)
  .L003DBD84:
    /* 2DBD84 003DBD84 00BC0F0C */  jal        func_003ef000
    /* 2DBD88 003DBD88 2D208002 */   daddu     $4, $20, $0
    /* 2DBD8C 003DBD8C 10BC0F0C */  jal        func_003ef040
    /* 2DBD90 003DBD90 2D206002 */   daddu     $4, $19, $0
    /* 2DBD94 003DBD94 22000010 */  b          .L003DBE20
    /* 2DBD98 003DBD98 2D100000 */   daddu     $2, $0, $0
  .L003DBD9C:
    /* 2DBD9C 003DBD9C 00BC0F0C */  jal        func_003ef000
    /* 2DBDA0 003DBDA0 2D208002 */   daddu     $4, $20, $0
    /* 2DBDA4 003DBDA4 10BC0F0C */  jal        func_003ef040
    /* 2DBDA8 003DBDA8 2D206002 */   daddu     $4, $19, $0
    /* 2DBDAC 003DBDAC 1C000010 */  b          .L003DBE20
    /* 2DBDB0 003DBDB0 2D100000 */   daddu     $2, $0, $0
  .L003DBDB4:
    /* 2DBDB4 003DBDB4 7100043C */  lui        $4, %hi(D_0070B800)
    /* 2DBDB8 003DBDB8 2D280002 */  daddu      $5, $16, $0
    /* 2DBDBC 003DBDBC 588D0F0C */  jal        func_003e3560
    /* 2DBDC0 003DBDC0 00B88424 */   addiu     $4, $4, %lo(D_0070B800)
    /* 2DBDC4 003DBDC4 00BC0F0C */  jal        func_003ef000
    /* 2DBDC8 003DBDC8 2D208002 */   daddu     $4, $20, $0
    /* 2DBDCC 003DBDCC 10BC0F0C */  jal        func_003ef040
    /* 2DBDD0 003DBDD0 2D206002 */   daddu     $4, $19, $0
    /* 2DBDD4 003DBDD4 12000010 */  b          .L003DBE20
    /* 2DBDD8 003DBDD8 2D100000 */   daddu     $2, $0, $0
  .L003DBDDC:
    /* 2DBDDC 003DBDDC 2D202002 */  daddu      $4, $17, $0
    /* 2DBDE0 003DBDE0 44BD0F0C */  jal        func_003ef510
    /* 2DBDE4 003DBDE4 38AB8527 */   addiu     $5, $28, -0x54C8
    /* 2DBDE8 003DBDE8 D4FF0010 */  b          .L003DBD3C
    /* 2DBDEC 003DBDEC 5400238E */   lw        $3, 0x54($17)
  .L003DBDF0:
    /* 2DBDF0 003DBDF0 7401A297 */  lhu        $2, 0x174($29)
    /* 2DBDF4 003DBDF4 D4FF0010 */  b          .L003DBD48
    /* 2DBDF8 003DBDF8 500022AE */   sw        $2, 0x50($17)
  .L003DBDFC:
    /* 2DBDFC 003DBDFC B3010324 */  addiu      $3, $0, 0x1B3
    /* 2DBE00 003DBE00 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2DBE04 003DBE04 6801A3AF */  sw         $3, 0x168($29)
    /* 2DBE08 003DBE08 647D0F0C */  jal        func_003df590
    /* 2DBE0C 003DBE0C 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2DBE10 003DBE10 6C01A2AF */  sw         $2, 0x16C($29)
    /* 2DBE14 003DBE14 347D0F0C */  jal        func_003df4d0
    /* 2DBE18 003DBE18 6801A427 */   addiu     $4, $29, 0x168
    /* 2DBE1C 003DBE1C 2D100000 */  daddu      $2, $0, $0
  .L003DBE20:
    /* 2DBE20 003DBE20 5000BFDF */  ld         $31, 0x50($29)
    /* 2DBE24 003DBE24 4000B47B */  lq         $20, 0x40($29)
    /* 2DBE28 003DBE28 3000B37B */  lq         $19, 0x30($29)
    /* 2DBE2C 003DBE2C 2000B27B */  lq         $18, 0x20($29)
    /* 2DBE30 003DBE30 1000B17B */  lq         $17, 0x10($29)
    /* 2DBE34 003DBE34 0000B07B */  lq         $16, 0x0($29)
    /* 2DBE38 003DBE38 0800E003 */  jr         $31
    /* 2DBE3C 003DBE3C 8001BD27 */   addiu     $29, $29, 0x180
.size func_003dbbc0, 0x280
