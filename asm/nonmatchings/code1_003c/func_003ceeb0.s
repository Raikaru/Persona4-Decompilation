.section .text
.set noat
.set noreorder
glabel func_003ceeb0
    /* 2CEEB0 003CEEB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2CEEB4 003CEEB4 3000BFFF */  sd         $31, 0x30($29)
    /* 2CEEB8 003CEEB8 2000B27F */  sq         $18, 0x20($29)
    /* 2CEEBC 003CEEBC 1000B17F */  sq         $17, 0x10($29)
    /* 2CEEC0 003CEEC0 0000B07F */  sq         $16, 0x0($29)
    /* 2CEEC4 003CEEC4 2D888000 */  daddu      $17, $4, $0
    /* 2CEEC8 003CEEC8 08270F0C */  jal        func_003c9c20
    /* 2CEECC 003CEECC 2D800000 */   daddu     $16, $0, $0
    /* 2CEED0 003CEED0 0800438C */  lw         $3, 0x8($2)
    /* 2CEED4 003CEED4 0001023C */  lui        $2, (0x1000000 >> 16)
    /* 2CEED8 003CEED8 24106200 */  and        $2, $3, $2
    /* 2CEEDC 003CEEDC 5A004010 */  beqz       $2, .L003CF048
    /* 2CEEE0 003CEEE0 00000000 */   nop
    /* 2CEEE4 003CEEE4 28B7828F */  lw         $2, -0x48D8($28)
    /* 2CEEE8 003CEEE8 10001026 */  addiu      $16, $16, 0x10
    /* 2CEEEC 003CEEEC 21102202 */  addu       $2, $17, $2
    /* 2CEEF0 003CEEF0 0000448C */  lw         $4, 0x0($2)
    /* 2CEEF4 003CEEF4 0000838C */  lw         $3, 0x0($4)
    /* 2CEEF8 003CEEF8 2B080300 */  sltu       $1, $0, $3
    /* 2CEEFC 003CEEFC 52002010 */  beqz       $1, .L003CF048
    /* 2CEF00 003CEF00 2D300000 */   daddu     $6, $0, $0
    /* 2CEF04 003CEF04 0900612C */  sltiu      $1, $3, 0x9
    /* 2CEF08 003CEF08 3F002014 */  bnez       $1, .L003CF008
    /* 2CEF0C 003CEF0C F8FF6224 */   addiu     $2, $3, -0x8
    /* 2CEF10 003CEF10 2D288000 */  daddu      $5, $4, $0
  .L003CEF14:
    /* 2CEF14 003CEF14 0400B28C */  lw         $18, 0x4($5)
    /* 2CEF18 003CEF18 0800C624 */  addiu      $6, $6, 0x8
    /* 2CEF1C 003CEF1C 0800B98C */  lw         $25, 0x8($5)
    /* 2CEF20 003CEF20 2B38C200 */  sltu       $7, $6, $2
    /* 2CEF24 003CEF24 0C00AE8C */  lw         $14, 0xC($5)
    /* 2CEF28 003CEF28 1000AA8C */  lw         $10, 0x10($5)
    /* 2CEF2C 003CEF2C 1400AF8C */  lw         $15, 0x14($5)
    /* 2CEF30 003CEF30 1800AB8C */  lw         $11, 0x18($5)
    /* 2CEF34 003CEF34 2000498E */  lw         $9, 0x20($18)
    /* 2CEF38 003CEF38 0800488E */  lw         $8, 0x8($18)
    /* 2CEF3C 003CEF3C 2000388F */  lw         $24, 0x20($25)
    /* 2CEF40 003CEF40 2000CD8D */  lw         $13, 0x20($14)
    /* 2CEF44 003CEF44 0800318F */  lw         $17, 0x8($25)
    /* 2CEF48 003CEF48 0800CC8D */  lw         $12, 0x8($14)
    /* 2CEF4C 003CEF4C 23903201 */  subu       $18, $9, $18
    /* 2CEF50 003CEF50 2000498D */  lw         $9, 0x20($10)
    /* 2CEF54 003CEF54 23901201 */  subu       $18, $8, $18
    /* 2CEF58 003CEF58 0800488D */  lw         $8, 0x8($10)
    /* 2CEF5C 003CEF5C 23C01903 */  subu       $24, $24, $25
    /* 2CEF60 003CEF60 08005926 */  addiu      $25, $18, 0x8
    /* 2CEF64 003CEF64 2368AE01 */  subu       $13, $13, $14
    /* 2CEF68 003CEF68 23883802 */  subu       $17, $17, $24
    /* 2CEF6C 003CEF6C 23608D01 */  subu       $12, $12, $13
    /* 2CEF70 003CEF70 21801902 */  addu       $16, $16, $25
    /* 2CEF74 003CEF74 08002E26 */  addiu      $14, $17, 0x8
    /* 2CEF78 003CEF78 21700E02 */  addu       $14, $16, $14
    /* 2CEF7C 003CEF7C 1C00AD8C */  lw         $13, 0x1C($5)
    /* 2CEF80 003CEF80 23482A01 */  subu       $9, $9, $10
    /* 2CEF84 003CEF84 08008A25 */  addiu      $10, $12, 0x8
    /* 2CEF88 003CEF88 23400901 */  subu       $8, $8, $9
    /* 2CEF8C 003CEF8C 2150CA01 */  addu       $10, $14, $10
    /* 2CEF90 003CEF90 08000825 */  addiu      $8, $8, 0x8
    /* 2CEF94 003CEF94 21804801 */  addu       $16, $10, $8
    /* 2CEF98 003CEF98 2000EE8D */  lw         $14, 0x20($15)
    /* 2CEF9C 003CEF9C 2000698D */  lw         $9, 0x20($11)
    /* 2CEFA0 003CEFA0 0800EC8D */  lw         $12, 0x8($15)
    /* 2CEFA4 003CEFA4 0800688D */  lw         $8, 0x8($11)
    /* 2CEFA8 003CEFA8 2000AA8C */  lw         $10, 0x20($5)
    /* 2CEFAC 003CEFAC 2370CF01 */  subu       $14, $14, $15
    /* 2CEFB0 003CEFB0 23482B01 */  subu       $9, $9, $11
    /* 2CEFB4 003CEFB4 23608E01 */  subu       $12, $12, $14
    /* 2CEFB8 003CEFB8 08008B25 */  addiu      $11, $12, 0x8
    /* 2CEFBC 003CEFBC 23400901 */  subu       $8, $8, $9
    /* 2CEFC0 003CEFC0 2000AC8D */  lw         $12, 0x20($13)
    /* 2CEFC4 003CEFC4 21580B02 */  addu       $11, $16, $11
    /* 2CEFC8 003CEFC8 08000825 */  addiu      $8, $8, 0x8
    /* 2CEFCC 003CEFCC 2000498D */  lw         $9, 0x20($10)
    /* 2CEFD0 003CEFD0 21706801 */  addu       $14, $11, $8
    /* 2CEFD4 003CEFD4 2000A524 */  addiu      $5, $5, 0x20
    /* 2CEFD8 003CEFD8 0800AB8D */  lw         $11, 0x8($13)
    /* 2CEFDC 003CEFDC 0800488D */  lw         $8, 0x8($10)
    /* 2CEFE0 003CEFE0 23608D01 */  subu       $12, $12, $13
    /* 2CEFE4 003CEFE4 23482A01 */  subu       $9, $9, $10
    /* 2CEFE8 003CEFE8 23586C01 */  subu       $11, $11, $12
    /* 2CEFEC 003CEFEC 08006A25 */  addiu      $10, $11, 0x8
    /* 2CEFF0 003CEFF0 23400901 */  subu       $8, $8, $9
    /* 2CEFF4 003CEFF4 2150CA01 */  addu       $10, $14, $10
    /* 2CEFF8 003CEFF8 08000825 */  addiu      $8, $8, 0x8
    /* 2CEFFC 003CEFFC C5FFE014 */  bnez       $7, .L003CEF14
    /* 2CF000 003CF000 21804801 */   addu      $16, $10, $8
    /* 2CF004 003CF004 00000000 */  nop
  .L003CF008:
    /* 2CF008 003CF008 2B08C300 */  sltu       $1, $6, $3
    /* 2CF00C 003CF00C 0E002010 */  beqz       $1, .L003CF048
    /* 2CF010 003CF010 00000000 */   nop
    /* 2CF014 003CF014 80100600 */  sll        $2, $6, 2
    /* 2CF018 003CF018 21408200 */  addu       $8, $4, $2
  .L003CF01C:
    /* 2CF01C 003CF01C 0400078D */  lw         $7, 0x4($8)
    /* 2CF020 003CF020 0100C624 */  addiu      $6, $6, 0x1
    /* 2CF024 003CF024 2B10C300 */  sltu       $2, $6, $3
    /* 2CF028 003CF028 2000E58C */  lw         $5, 0x20($7)
    /* 2CF02C 003CF02C 04000825 */  addiu      $8, $8, 0x4
    /* 2CF030 003CF030 0800E48C */  lw         $4, 0x8($7)
    /* 2CF034 003CF034 2328A700 */  subu       $5, $5, $7
    /* 2CF038 003CF038 23208500 */  subu       $4, $4, $5
    /* 2CF03C 003CF03C 08008424 */  addiu      $4, $4, 0x8
    /* 2CF040 003CF040 F6FF4014 */  bnez       $2, .L003CF01C
    /* 2CF044 003CF044 21800402 */   addu      $16, $16, $4
  .L003CF048:
    /* 2CF048 003CF048 2D100002 */  daddu      $2, $16, $0
    /* 2CF04C 003CF04C 3000BFDF */  ld         $31, 0x30($29)
    /* 2CF050 003CF050 2000B27B */  lq         $18, 0x20($29)
    /* 2CF054 003CF054 1000B17B */  lq         $17, 0x10($29)
    /* 2CF058 003CF058 0000B07B */  lq         $16, 0x0($29)
    /* 2CF05C 003CF05C 0800E003 */  jr         $31
    /* 2CF060 003CF060 4000BD27 */   addiu     $29, $29, 0x40
    /* 2CF064 003CF064 00000000 */  nop
    /* 2CF068 003CF068 00000000 */  nop
    /* 2CF06C 003CF06C 00000000 */  nop
.size func_003ceeb0, 0x1c0
