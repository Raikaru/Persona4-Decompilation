.section .text
.set noat
.set noreorder
glabel func_003bbbe0
    /* 2BBBE0 003BBBE0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 2BBBE4 003BBBE4 02000224 */  addiu      $2, $0, 0x2
    /* 2BBBE8 003BBBE8 7000BFFF */  sd         $31, 0x70($29)
    /* 2BBBEC 003BBBEC 6000B67F */  sq         $22, 0x60($29)
    /* 2BBBF0 003BBBF0 5000B57F */  sq         $21, 0x50($29)
    /* 2BBBF4 003BBBF4 2DB0C000 */  daddu      $22, $6, $0
    /* 2BBBF8 003BBBF8 4000B47F */  sq         $20, 0x40($29)
    /* 2BBBFC 003BBBFC 3000B37F */  sq         $19, 0x30($29)
    /* 2BBC00 003BBC00 2000B27F */  sq         $18, 0x20($29)
    /* 2BBC04 003BBC04 1000B17F */  sq         $17, 0x10($29)
    /* 2BBC08 003BBC08 2D908000 */  daddu      $18, $4, $0
    /* 2BBC0C 003BBC0C 2D88A000 */  daddu      $17, $5, $0
    /* 2BBC10 003BBC10 19002212 */  beq        $17, $2, .L003BBC78
    /* 2BBC14 003BBC14 0000B07F */   sq        $16, 0x0($29)
    /* 2BBC18 003BBC18 01000424 */  addiu      $4, $0, 0x1
    /* 2BBC1C 003BBC1C 03002412 */  beq        $17, $4, .L003BBC2C
    /* 2BBC20 003BBC20 00000000 */   nop
    /* 2BBC24 003BBC24 43000010 */  b          .L003BBD34
    /* 2BBC28 003BBC28 02010224 */   addiu     $2, $0, 0x102
  .L003BBC2C:
    /* 2BBC2C 003BBC2C 0300023C */  lui        $2, (0x3000C >> 16)
    /* 2BBC30 003BBC30 8800133C */  lui        $19, %hi(jtbl_008873E8)
    /* 2BBC34 003BBC34 0C005434 */  ori        $20, $2, (0x3000C & 0xFFFF)
    /* 2BBC38 003BBC38 01004326 */  addiu      $3, $18, 0x1
    /* 2BBC3C 003BBC3C 40100300 */  sll        $2, $3, 1
    /* 2BBC40 003BBC40 E8737326 */  addiu      $19, $19, %lo(jtbl_008873E8)
    /* 2BBC44 003BBC44 21104300 */  addu       $2, $2, $3
    /* 2BBC48 003BBC48 2D288002 */  daddu      $5, $20, $0
    /* 2BBC4C 003BBC4C 80100200 */  sll        $2, $2, 2
    /* 2BBC50 003BBC50 44005524 */  addiu      $21, $2, 0x44
    /* 2BBC54 003BBC54 0000628E */  lw         $2, 0x0($19)
    /* 2BBC58 003BBC58 09F84000 */  jalr       $2
    /* 2BBC5C 003BBC5C 2D20A002 */   daddu     $4, $21, $0
    /* 2BBC60 003BBC60 2D804000 */  daddu      $16, $2, $0
    /* 2BBC64 003BBC64 3A000012 */  beqz       $16, .L003BBD50
    /* 2BBC68 003BBC68 00000000 */   nop
    /* 2BBC6C 003BBC6C 02004226 */  addiu      $2, $18, 0x2
    /* 2BBC70 003BBC70 13000010 */  b          .L003BBCC0
    /* 2BBC74 003BBC74 080002AE */   sw        $2, 0x8($16)
  .L003BBC78:
    /* 2BBC78 003BBC78 0300023C */  lui        $2, (0x3000C >> 16)
    /* 2BBC7C 003BBC7C 8800133C */  lui        $19, %hi(jtbl_008873E8)
    /* 2BBC80 003BBC80 0C005434 */  ori        $20, $2, (0x3000C & 0xFFFF)
    /* 2BBC84 003BBC84 02004326 */  addiu      $3, $18, 0x2
    /* 2BBC88 003BBC88 40100300 */  sll        $2, $3, 1
    /* 2BBC8C 003BBC8C E8737326 */  addiu      $19, $19, %lo(jtbl_008873E8)
    /* 2BBC90 003BBC90 21104300 */  addu       $2, $2, $3
    /* 2BBC94 003BBC94 2D288002 */  daddu      $5, $20, $0
    /* 2BBC98 003BBC98 80100200 */  sll        $2, $2, 2
    /* 2BBC9C 003BBC9C 44005524 */  addiu      $21, $2, 0x44
    /* 2BBCA0 003BBCA0 0000628E */  lw         $2, 0x0($19)
    /* 2BBCA4 003BBCA4 09F84000 */  jalr       $2
    /* 2BBCA8 003BBCA8 2D20A002 */   daddu     $4, $21, $0
    /* 2BBCAC 003BBCAC 2D804000 */  daddu      $16, $2, $0
    /* 2BBCB0 003BBCB0 32000012 */  beqz       $16, .L003BBD7C
    /* 2BBCB4 003BBCB4 00000000 */   nop
    /* 2BBCB8 003BBCB8 03004226 */  addiu      $2, $18, 0x3
    /* 2BBCBC 003BBCBC 080002AE */  sw         $2, 0x8($16)
  .L003BBCC0:
    /* 2BBCC0 003BBCC0 100000AE */  sw         $0, 0x10($16)
    /* 2BBCC4 003BBCC4 0C000224 */  addiu      $2, $0, 0xC
    /* 2BBCC8 003BBCC8 180000A2 */  sb         $0, 0x18($16)
    /* 2BBCCC 003BBCCC 2D200002 */  daddu      $4, $16, $0
    /* 2BBCD0 003BBCD0 0C0011AE */  sw         $17, 0xC($16)
    /* 2BBCD4 003BBCD4 2D28C002 */  daddu      $5, $22, $0
    /* 2BBCD8 003BBCD8 90E60E0C */  jal        func_003b9a40
    /* 2BBCDC 003BBCDC 000002A2 */   sb        $2, 0x0($16)
    /* 2BBCE0 003BBCE0 31004010 */  beqz       $2, .L003BBDA8
    /* 2BBCE4 003BBCE4 00000000 */   nop
    /* 2BBCE8 003BBCE8 0C000224 */  addiu      $2, $0, 0xC
    /* 2BBCEC 003BBCEC 2D288002 */  daddu      $5, $20, $0
    /* 2BBCF0 003BBCF0 000002A2 */  sb         $2, 0x0($16)
    /* 2BBCF4 003BBCF4 40101200 */  sll        $2, $18, 1
    /* 2BBCF8 003BBCF8 21185200 */  addu       $3, $2, $18
    /* 2BBCFC 003BBCFC 0000628E */  lw         $2, 0x0($19)
    /* 2BBD00 003BBD00 80880300 */  sll        $17, $3, 2
    /* 2BBD04 003BBD04 09F84000 */  jalr       $2
    /* 2BBD08 003BBD08 2D202002 */   daddu     $4, $17, $0
    /* 2BBD0C 003BBD0C 2C004010 */  beqz       $2, .L003BBDC0
    /* 2BBD10 003BBD10 140002AE */   sw        $2, 0x14($16)
    /* 2BBD14 003BBD14 1400048E */  lw         $4, 0x14($16)
    /* 2BBD18 003BBD18 40101200 */  sll        $2, $18, 1
    /* 2BBD1C 003BBD1C 21105200 */  addu       $2, $2, $18
    /* 2BBD20 003BBD20 2D28C002 */  daddu      $5, $22, $0
    /* 2BBD24 003BBD24 04FE100C */  jal        func_0043f810
    /* 2BBD28 003BBD28 80300200 */   sll       $6, $2, 2
    /* 2BBD2C 003BBD2C 32000010 */  b          .L003BBDF8
    /* 2BBD30 003BBD30 2D100002 */   daddu     $2, $16, $0
  .L003BBD34:
    /* 2BBD34 003BBD34 647D0F0C */  jal        func_003df590
    /* 2BBD38 003BBD38 8800A2AF */   sw        $2, 0x88($29)
    /* 2BBD3C 003BBD3C 8C00A2AF */  sw         $2, 0x8C($29)
    /* 2BBD40 003BBD40 347D0F0C */  jal        func_003df4d0
    /* 2BBD44 003BBD44 8800A427 */   addiu     $4, $29, 0x88
    /* 2BBD48 003BBD48 2B000010 */  b          .L003BBDF8
    /* 2BBD4C 003BBD4C 2D100000 */   daddu     $2, $0, $0
  .L003BBD50:
    /* 2BBD50 003BBD50 02010224 */  addiu      $2, $0, 0x102
    /* 2BBD54 003BBD54 2D28A002 */  daddu      $5, $21, $0
    /* 2BBD58 003BBD58 9800A2AF */  sw         $2, 0x98($29)
    /* 2BBD5C 003BBD5C 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BBD60 003BBD60 647D0F0C */  jal        func_003df590
    /* 2BBD64 003BBD64 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2BBD68 003BBD68 9C00A2AF */  sw         $2, 0x9C($29)
    /* 2BBD6C 003BBD6C 347D0F0C */  jal        func_003df4d0
    /* 2BBD70 003BBD70 9800A427 */   addiu     $4, $29, 0x98
    /* 2BBD74 003BBD74 20000010 */  b          .L003BBDF8
    /* 2BBD78 003BBD78 2D100000 */   daddu     $2, $0, $0
  .L003BBD7C:
    /* 2BBD7C 003BBD7C 02010224 */  addiu      $2, $0, 0x102
    /* 2BBD80 003BBD80 2D28A002 */  daddu      $5, $21, $0
    /* 2BBD84 003BBD84 9000A2AF */  sw         $2, 0x90($29)
    /* 2BBD88 003BBD88 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BBD8C 003BBD8C 647D0F0C */  jal        func_003df590
    /* 2BBD90 003BBD90 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2BBD94 003BBD94 9400A2AF */  sw         $2, 0x94($29)
    /* 2BBD98 003BBD98 347D0F0C */  jal        func_003df4d0
    /* 2BBD9C 003BBD9C 9000A427 */   addiu     $4, $29, 0x90
    /* 2BBDA0 003BBDA0 15000010 */  b          .L003BBDF8
    /* 2BBDA4 003BBDA4 2D100000 */   daddu     $2, $0, $0
  .L003BBDA8:
    /* 2BBDA8 003BBDA8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBDAC 003BBDAC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBDB0 003BBDB0 09F84000 */  jalr       $2
    /* 2BBDB4 003BBDB4 2D200002 */   daddu     $4, $16, $0
    /* 2BBDB8 003BBDB8 0F000010 */  b          .L003BBDF8
    /* 2BBDBC 003BBDBC 2D100000 */   daddu     $2, $0, $0
  .L003BBDC0:
    /* 2BBDC0 003BBDC0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BBDC4 003BBDC4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BBDC8 003BBDC8 09F84000 */  jalr       $2
    /* 2BBDCC 003BBDCC 2D200002 */   daddu     $4, $16, $0
    /* 2BBDD0 003BBDD0 02010224 */  addiu      $2, $0, 0x102
    /* 2BBDD4 003BBDD4 2D282002 */  daddu      $5, $17, $0
    /* 2BBDD8 003BBDD8 8000A2AF */  sw         $2, 0x80($29)
    /* 2BBDDC 003BBDDC 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2BBDE0 003BBDE0 647D0F0C */  jal        func_003df590
    /* 2BBDE4 003BBDE4 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2BBDE8 003BBDE8 8400A2AF */  sw         $2, 0x84($29)
    /* 2BBDEC 003BBDEC 347D0F0C */  jal        func_003df4d0
    /* 2BBDF0 003BBDF0 8000A427 */   addiu     $4, $29, 0x80
    /* 2BBDF4 003BBDF4 2D100000 */  daddu      $2, $0, $0
  .L003BBDF8:
    /* 2BBDF8 003BBDF8 7000BFDF */  ld         $31, 0x70($29)
    /* 2BBDFC 003BBDFC 6000B67B */  lq         $22, 0x60($29)
    /* 2BBE00 003BBE00 5000B57B */  lq         $21, 0x50($29)
    /* 2BBE04 003BBE04 4000B47B */  lq         $20, 0x40($29)
    /* 2BBE08 003BBE08 3000B37B */  lq         $19, 0x30($29)
    /* 2BBE0C 003BBE0C 2000B27B */  lq         $18, 0x20($29)
    /* 2BBE10 003BBE10 1000B17B */  lq         $17, 0x10($29)
    /* 2BBE14 003BBE14 0000B07B */  lq         $16, 0x0($29)
    /* 2BBE18 003BBE18 0800E003 */  jr         $31
    /* 2BBE1C 003BBE1C A000BD27 */   addiu     $29, $29, 0xA0
.size func_003bbbe0, 0x240
