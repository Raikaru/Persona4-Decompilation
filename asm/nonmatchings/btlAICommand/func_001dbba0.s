.section .text
.set noat
.set noreorder
glabel func_001dbba0
    /* DBBA0 001DBBA0 E0FEBD27 */  addiu      $29, $29, -0x120
    /* DBBA4 001DBBA4 9000BFFF */  sd         $31, 0x90($29)
    /* DBBA8 001DBBA8 8000BE7F */  sq         $30, 0x80($29)
    /* DBBAC 001DBBAC 7000B77F */  sq         $23, 0x70($29)
    /* DBBB0 001DBBB0 6000B67F */  sq         $22, 0x60($29)
    /* DBBB4 001DBBB4 5000B57F */  sq         $21, 0x50($29)
    /* DBBB8 001DBBB8 4000B47F */  sq         $20, 0x40($29)
    /* DBBBC 001DBBBC 3000B37F */  sq         $19, 0x30($29)
    /* DBBC0 001DBBC0 2000B27F */  sq         $18, 0x20($29)
    /* DBBC4 001DBBC4 1000B17F */  sq         $17, 0x10($29)
    /* DBBC8 001DBBC8 0000B07F */  sq         $16, 0x0($29)
    /* DBBCC 001DBBCC 2DA88000 */  daddu      $21, $4, $0
    /* DBBD0 001DBBD0 2DA0A000 */  daddu      $20, $5, $0
    /* DBBD4 001DBBD4 2DF0C000 */  daddu      $30, $6, $0
    /* DBBD8 001DBBD8 2D80E000 */  daddu      $16, $7, $0
    /* DBBDC 001DBBDC EC00A8AF */  sw         $8, 0xEC($29)
    /* DBBE0 001DBBE0 E800A9AF */  sw         $9, 0xE8($29)
    /* DBBE4 001DBBE4 FFFF1732 */  andi       $23, $16, 0xFFFF
    /* DBBE8 001DBBE8 2000E232 */  andi       $2, $23, 0x20
    /* DBBEC 001DBBEC 09004010 */  beqz       $2, .L001DBC14
    /* DBBF0 001DBBF0 00000000 */   nop
    /* DBBF4 001DBBF4 9800A526 */  addiu      $5, $21, 0x98
    /* DBBF8 001DBBF8 02000624 */  addiu      $6, $0, 0x2
    /* DBBFC 001DBBFC 2D380000 */  daddu      $7, $0, $0
    /* DBC00 001DBC00 2D400000 */  daddu      $8, $0, $0
    /* DBC04 001DBC04 185F070C */  jal        func_001d7c60
    /* DBC08 001DBC08 00000000 */   nop
    /* DBC0C 001DBC0C 1C000010 */  b          .L001DBC80
    /* DBC10 001DBC10 00000000 */   nop
  .L001DBC14:
    /* DBC14 001DBC14 9800A526 */  addiu      $5, $21, 0x98
    /* DBC18 001DBC18 6E00A696 */  lhu        $6, 0x6E($21)
    /* DBC1C 001DBC1C 2D380000 */  daddu      $7, $0, $0
    /* DBC20 001DBC20 C45F070C */  jal        func_001d7f10
    /* DBC24 001DBC24 00000000 */   nop
    /* DBC28 001DBC28 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DBC2C 001DBC2C 14004010 */  beqz       $2, .L001DBC80
    /* DBC30 001DBC30 00000000 */   nop
    /* DBC34 001DBC34 2D200000 */  daddu      $4, $0, $0
    /* DBC38 001DBC38 08000010 */  b          .L001DBC5C
    /* DBC3C 001DBC3C 00000000 */   nop
  .L001DBC40:
    /* DBC40 001DBC40 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DBC44 001DBC44 80100200 */  sll        $2, $2, 2
    /* DBC48 001DBC48 2118A202 */  addu       $3, $21, $2
    /* DBC4C 001DBC4C 9800628C */  lw         $2, 0x98($3)
    /* DBC50 001DBC50 380062AC */  sw         $2, 0x38($3)
    /* DBC54 001DBC54 01008224 */  addiu      $2, $4, 0x1
    /* DBC58 001DBC58 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DBC5C:
    /* DBC5C 001DBC5C D000A396 */  lhu        $3, 0xD0($21)
    /* DBC60 001DBC60 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DBC64 001DBC64 2A104300 */  slt        $2, $2, $3
    /* DBC68 001DBC68 F5FF4014 */  bnez       $2, .L001DBC40
    /* DBC6C 001DBC6C 00000000 */   nop
    /* DBC70 001DBC70 6A00A3A6 */  sh         $3, 0x6A($21)
    /* DBC74 001DBC74 01000224 */  addiu      $2, $0, 0x1
    /* DBC78 001DBC78 9A000010 */  b          .L001DBEE4
    /* DBC7C 001DBC7C 00000000 */   nop
  .L001DBC80:
    /* DBC80 001DBC80 2D900000 */  daddu      $18, $0, $0
    /* DBC84 001DBC84 2DB00000 */  daddu      $22, $0, $0
    /* DBC88 001DBC88 FFFF1132 */  andi       $17, $16, 0xFFFF
    /* DBC8C 001DBC8C 01002232 */  andi       $2, $17, 0x1
    /* DBC90 001DBC90 D000A27F */  sq         $2, 0xD0($29)
    /* DBC94 001DBC94 02002232 */  andi       $2, $17, 0x2
    /* DBC98 001DBC98 C000A27F */  sq         $2, 0xC0($29)
    /* DBC9C 001DBC9C 10002232 */  andi       $2, $17, 0x10
    /* DBCA0 001DBCA0 B000A27F */  sq         $2, 0xB0($29)
    /* DBCA4 001DBCA4 40002232 */  andi       $2, $17, 0x40
    /* DBCA8 001DBCA8 A000A27F */  sq         $2, 0xA0($29)
    /* DBCAC 001DBCAC 55000010 */  b          .L001DBE04
    /* DBCB0 001DBCB0 00000000 */   nop
  .L001DBCB4:
    /* DBCB4 001DBCB4 FFFFC232 */  andi       $2, $22, 0xFFFF
    /* DBCB8 001DBCB8 80100200 */  sll        $2, $2, 2
    /* DBCBC 001DBCBC 2110A202 */  addu       $2, $21, $2
    /* DBCC0 001DBCC0 9800538C */  lw         $19, 0x98($2)
    /* DBCC4 001DBCC4 1A006296 */  lhu        $2, 0x1A($19)
    /* DBCC8 001DBCC8 01004230 */  andi       $2, $2, 0x1
    /* DBCCC 001DBCCC 4B004010 */  beqz       $2, .L001DBDFC
    /* DBCD0 001DBCD0 00000000 */   nop
    /* DBCD4 001DBCD4 3000708E */  lw         $16, 0x30($19)
    /* DBCD8 001DBCD8 29002012 */  beqz       $17, .L001DBD80
    /* DBCDC 001DBCDC 00000000 */   nop
    /* DBCE0 001DBCE0 D000A27B */  lq         $2, 0xD0($29)
    /* DBCE4 001DBCE4 07004010 */  beqz       $2, .L001DBD04
    /* DBCE8 001DBCE8 00000000 */   nop
    /* DBCEC 001DBCEC 640A048E */  lw         $4, 0xA64($16)
    /* DBCF0 001DBCF0 1000053C */  lui        $5, (0x100000 >> 16)
    /* DBCF4 001DBCF4 C4C9080C */  jal        func_00232710
    /* DBCF8 001DBCF8 00000000 */   nop
    /* DBCFC 001DBCFC 3F004010 */  beqz       $2, .L001DBDFC
    /* DBD00 001DBD00 00000000 */   nop
  .L001DBD04:
    /* DBD04 001DBD04 C000A27B */  lq         $2, 0xC0($29)
    /* DBD08 001DBD08 12004010 */  beqz       $2, .L001DBD54
    /* DBD0C 001DBD0C 00000000 */   nop
    /* DBD10 001DBD10 A2000392 */  lbu        $3, 0xA2($16)
    /* DBD14 001DBD14 01000224 */  addiu      $2, $0, 0x1
    /* DBD18 001DBD18 0E006214 */  bne        $3, $2, .L001DBD54
    /* DBD1C 001DBD1C 00000000 */   nop
    /* DBD20 001DBD20 3C2C1400 */  dsll32     $5, $20, 16
    /* DBD24 001DBD24 3F2C0500 */  dsra32     $5, $5, 16
    /* DBD28 001DBD28 2D206002 */  daddu      $4, $19, $0
    /* DBD2C 001DBD2C 38E7070C */  jal        func_001f9ce0
    /* DBD30 001DBD30 00000000 */   nop
    /* DBD34 001DBD34 07004014 */  bnez       $2, .L001DBD54
    /* DBD38 001DBD38 00000000 */   nop
    /* DBD3C 001DBD3C FFFF8532 */  andi       $5, $20, 0xFFFF
    /* DBD40 001DBD40 A4000496 */  lhu        $4, 0xA4($16)
    /* DBD44 001DBD44 083D040C */  jal        func_0010f420
    /* DBD48 001DBD48 00000000 */   nop
    /* DBD4C 001DBD4C 2B004010 */  beqz       $2, .L001DBDFC
    /* DBD50 001DBD50 00000000 */   nop
  .L001DBD54:
    /* DBD54 001DBD54 B000A27B */  lq         $2, 0xB0($29)
    /* DBD58 001DBD58 09004010 */  beqz       $2, .L001DBD80
    /* DBD5C 001DBD5C 00000000 */   nop
    /* DBD60 001DBD60 2D20A002 */  daddu      $4, $21, $0
    /* DBD64 001DBD64 2D286002 */  daddu      $5, $19, $0
    /* DBD68 001DBD68 2D300000 */  daddu      $6, $0, $0
    /* DBD6C 001DBD6C 2D380000 */  daddu      $7, $0, $0
    /* DBD70 001DBD70 5C75070C */  jal        func_001dd570
    /* DBD74 001DBD74 00000000 */   nop
    /* DBD78 001DBD78 20004004 */  bltz       $2, .L001DBDFC
    /* DBD7C 001DBD7C 00000000 */   nop
  .L001DBD80:
    /* DBD80 001DBD80 A000A27B */  lq         $2, 0xA0($29)
    /* DBD84 001DBD84 09004014 */  bnez       $2, .L001DBDAC
    /* DBD88 001DBD88 00000000 */   nop
    /* DBD8C 001DBD8C 640A048E */  lw         $4, 0xA64($16)
    /* DBD90 001DBD90 2D28C003 */  daddu      $5, $30, $0
    /* DBD94 001DBD94 C4C9080C */  jal        func_00232710
    /* DBD98 001DBD98 00000000 */   nop
    /* DBD9C 001DBD9C 09004010 */  beqz       $2, .L001DBDC4
    /* DBDA0 001DBDA0 00000000 */   nop
    /* DBDA4 001DBDA4 15000010 */  b          .L001DBDFC
    /* DBDA8 001DBDA8 00000000 */   nop
  .L001DBDAC:
    /* DBDAC 001DBDAC 640A048E */  lw         $4, 0xA64($16)
    /* DBDB0 001DBDB0 2D28C003 */  daddu      $5, $30, $0
    /* DBDB4 001DBDB4 30D0080C */  jal        func_002340c0
    /* DBDB8 001DBDB8 00000000 */   nop
    /* DBDBC 001DBDBC 0F004014 */  bnez       $2, .L001DBDFC
    /* DBDC0 001DBDC0 00000000 */   nop
  .L001DBDC4:
    /* DBDC4 001DBDC4 2D206002 */  daddu      $4, $19, $0
    /* DBDC8 001DBDC8 2D288002 */  daddu      $5, $20, $0
    /* DBDCC 001DBDCC E800A28F */  lw         $2, 0xE8($29)
    /* DBDD0 001DBDD0 09F84000 */  jalr       $2
    /* DBDD4 001DBDD4 00000000 */   nop
    /* DBDD8 001DBDD8 EC00A38F */  lw         $3, 0xEC($29)
    /* DBDDC 001DBDDC 07006210 */  beq        $3, $2, .L001DBDFC
    /* DBDE0 001DBDE0 00000000 */   nop
    /* DBDE4 001DBDE4 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DBDE8 001DBDE8 80100200 */  sll        $2, $2, 2
    /* DBDEC 001DBDEC 21105D00 */  addu       $2, $2, $29
    /* DBDF0 001DBDF0 F00053AC */  sw         $19, 0xF0($2)
    /* DBDF4 001DBDF4 01004226 */  addiu      $2, $18, 0x1
    /* DBDF8 001DBDF8 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DBDFC:
    /* DBDFC 001DBDFC 0100C226 */  addiu      $2, $22, 0x1
    /* DBE00 001DBE00 FFFF5630 */  andi       $22, $2, 0xFFFF
  .L001DBE04:
    /* DBE04 001DBE04 FFFFC332 */  andi       $3, $22, 0xFFFF
    /* DBE08 001DBE08 D000A296 */  lhu        $2, 0xD0($21)
    /* DBE0C 001DBE0C 2A106200 */  slt        $2, $3, $2
    /* DBE10 001DBE10 A8FF4014 */  bnez       $2, .L001DBCB4
    /* DBE14 001DBE14 00000000 */   nop
    /* DBE18 001DBE18 FFFF4432 */  andi       $4, $18, 0xFFFF
    /* DBE1C 001DBE1C 0D008014 */  bnez       $4, .L001DBE54
    /* DBE20 001DBE20 00000000 */   nop
    /* DBE24 001DBE24 0800E232 */  andi       $2, $23, 0x8
    /* DBE28 001DBE28 04004010 */  beqz       $2, .L001DBE3C
    /* DBE2C 001DBE2C 00000000 */   nop
    /* DBE30 001DBE30 2D100000 */  daddu      $2, $0, $0
    /* DBE34 001DBE34 05000010 */  b          .L001DBE4C
    /* DBE38 001DBE38 00000000 */   nop
  .L001DBE3C:
    /* DBE3C 001DBE3C 2D20A002 */  daddu      $4, $21, $0
    /* DBE40 001DBE40 2D288002 */  daddu      $5, $20, $0
    /* DBE44 001DBE44 C86F070C */  jal        func_001dbf20
    /* DBE48 001DBE48 00000000 */   nop
  .L001DBE4C:
    /* DBE4C 001DBE4C 25000010 */  b          .L001DBEE4
    /* DBE50 001DBE50 00000000 */   nop
  .L001DBE54:
    /* DBE54 001DBE54 0400E232 */  andi       $2, $23, 0x4
    /* DBE58 001DBE58 11004014 */  bnez       $2, .L001DBEA0
    /* DBE5C 001DBE5C 00000000 */   nop
    /* DBE60 001DBE60 2D100000 */  daddu      $2, $0, $0
    /* DBE64 001DBE64 02008128 */  slti       $1, $4, 0x2
    /* DBE68 001DBE68 04002014 */  bnez       $1, .L001DBE7C
    /* DBE6C 001DBE6C 00000000 */   nop
    /* DBE70 001DBE70 5CC7080C */  jal        func_00231d70
    /* DBE74 001DBE74 00000000 */   nop
    /* DBE78 001DBE78 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L001DBE7C:
    /* DBE7C 001DBE7C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DBE80 001DBE80 80100200 */  sll        $2, $2, 2
    /* DBE84 001DBE84 21105D00 */  addu       $2, $2, $29
    /* DBE88 001DBE88 F000428C */  lw         $2, 0xF0($2)
    /* DBE8C 001DBE8C 3800A2AE */  sw         $2, 0x38($21)
    /* DBE90 001DBE90 01000224 */  addiu      $2, $0, 0x1
    /* DBE94 001DBE94 6A00A2A6 */  sh         $2, 0x6A($21)
    /* DBE98 001DBE98 11000010 */  b          .L001DBEE0
    /* DBE9C 001DBE9C 00000000 */   nop
  .L001DBEA0:
    /* DBEA0 001DBEA0 2D300000 */  daddu      $6, $0, $0
    /* DBEA4 001DBEA4 09000010 */  b          .L001DBECC
    /* DBEA8 001DBEA8 00000000 */   nop
  .L001DBEAC:
    /* DBEAC 001DBEAC FFFFC230 */  andi       $2, $6, 0xFFFF
    /* DBEB0 001DBEB0 80280200 */  sll        $5, $2, 2
    /* DBEB4 001DBEB4 2110BD00 */  addu       $2, $5, $29
    /* DBEB8 001DBEB8 F000438C */  lw         $3, 0xF0($2)
    /* DBEBC 001DBEBC 2110A502 */  addu       $2, $21, $5
    /* DBEC0 001DBEC0 380043AC */  sw         $3, 0x38($2)
    /* DBEC4 001DBEC4 0100C224 */  addiu      $2, $6, 0x1
    /* DBEC8 001DBEC8 FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001DBECC:
    /* DBECC 001DBECC FFFFC230 */  andi       $2, $6, 0xFFFF
    /* DBED0 001DBED0 2A104400 */  slt        $2, $2, $4
    /* DBED4 001DBED4 F5FF4014 */  bnez       $2, .L001DBEAC
    /* DBED8 001DBED8 00000000 */   nop
    /* DBEDC 001DBEDC 6A00B2A6 */  sh         $18, 0x6A($21)
  .L001DBEE0:
    /* DBEE0 001DBEE0 01000224 */  addiu      $2, $0, 0x1
  .L001DBEE4:
    /* DBEE4 001DBEE4 9000BFDF */  ld         $31, 0x90($29)
    /* DBEE8 001DBEE8 8000BE7B */  lq         $30, 0x80($29)
    /* DBEEC 001DBEEC 7000B77B */  lq         $23, 0x70($29)
    /* DBEF0 001DBEF0 6000B67B */  lq         $22, 0x60($29)
    /* DBEF4 001DBEF4 5000B57B */  lq         $21, 0x50($29)
    /* DBEF8 001DBEF8 4000B47B */  lq         $20, 0x40($29)
    /* DBEFC 001DBEFC 3000B37B */  lq         $19, 0x30($29)
    /* DBF00 001DBF00 2000B27B */  lq         $18, 0x20($29)
    /* DBF04 001DBF04 1000B17B */  lq         $17, 0x10($29)
    /* DBF08 001DBF08 0000B07B */  lq         $16, 0x0($29)
    /* DBF0C 001DBF0C 2001BD27 */  addiu      $29, $29, 0x120
    /* DBF10 001DBF10 0800E003 */  jr         $31
    /* DBF14 001DBF14 00000000 */   nop
    /* DBF18 001DBF18 00000000 */  nop
    /* DBF1C 001DBF1C 00000000 */  nop
.size func_001dbba0, 0x380
