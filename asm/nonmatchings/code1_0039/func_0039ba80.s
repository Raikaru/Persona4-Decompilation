.section .text
.set noat
.set noreorder
glabel func_0039ba80
    /* 29BA80 0039BA80 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 29BA84 0039BA84 4000BFFF */  sd         $31, 0x40($29)
    /* 29BA88 0039BA88 3000B37F */  sq         $19, 0x30($29)
    /* 29BA8C 0039BA8C 2000B27F */  sq         $18, 0x20($29)
    /* 29BA90 0039BA90 2D988000 */  daddu      $19, $4, $0
    /* 29BA94 0039BA94 1000B17F */  sq         $17, 0x10($29)
    /* 29BA98 0039BA98 0000B07F */  sq         $16, 0x0($29)
    /* 29BA9C 0039BA9C 0400838C */  lw         $3, 0x4($4)
    /* 29BAA0 0039BAA0 2B080300 */  sltu       $1, $0, $3
    /* 29BAA4 0039BAA4 0E002010 */  beqz       $1, .L0039BAE0
    /* 29BAA8 0039BAA8 2D900000 */   daddu     $18, $0, $0
    /* 29BAAC 0039BAAC 2D880000 */  daddu      $17, $0, $0
  .L0039BAB0:
    /* 29BAB0 0039BAB0 0000638E */  lw         $3, 0x0($19)
    /* 29BAB4 0039BAB4 01000224 */  addiu      $2, $0, 0x1
    /* 29BAB8 0039BAB8 21807100 */  addu       $16, $3, $17
    /* 29BABC 0039BABC 0C00038E */  lw         $3, 0xC($16)
    /* 29BAC0 0039BAC0 0E006210 */  beq        $3, $2, .L0039BAFC
    /* 29BAC4 0039BAC4 00000000 */   nop
  .L0039BAC8:
    /* 29BAC8 0039BAC8 0400638E */  lw         $3, 0x4($19)
    /* 29BACC 0039BACC 01005226 */  addiu      $18, $18, 0x1
    /* 29BAD0 0039BAD0 2B104302 */  sltu       $2, $18, $3
    /* 29BAD4 0039BAD4 F6FF4014 */  bnez       $2, .L0039BAB0
    /* 29BAD8 0039BAD8 14003126 */   addiu     $17, $17, 0x14
    /* 29BADC 0039BADC 00000000 */  nop
  .L0039BAE0:
    /* 29BAE0 0039BAE0 2B100300 */  sltu       $2, $0, $3
    /* 29BAE4 0039BAE4 0C004014 */  bnez       $2, .L0039BB18
    /* 29BAE8 0039BAE8 2D800000 */   daddu     $16, $0, $0
    /* 29BAEC 0039BAEC 01000324 */  addiu      $3, $0, 0x1
  .L0039BAF0:
    /* 29BAF0 0039BAF0 2D106002 */  daddu      $2, $19, $0
    /* 29BAF4 0039BAF4 14000010 */  b          .L0039BB48
    /* 29BAF8 0039BAF8 0C0063AE */   sw        $3, 0xC($19)
  .L0039BAFC:
    /* 29BAFC 0039BAFC F46E0E0C */  jal        func_0039bbd0
    /* 29BB00 0039BB00 0000048E */   lw        $4, 0x0($16)
    /* 29BB04 0039BB04 100002AE */  sw         $2, 0x10($16)
    /* 29BB08 0039BB08 0800038E */  lw         $3, 0x8($16)
    /* 29BB0C 0039BB0C 1000028E */  lw         $2, 0x10($16)
    /* 29BB10 0039BB10 EDFF0010 */  b          .L0039BAC8
    /* 29BB14 0039BB14 300043AC */   sw        $3, 0x30($2)
  .L0039BB18:
    /* 29BB18 0039BB18 2D880000 */  daddu      $17, $0, $0
  .L0039BB1C:
    /* 29BB1C 0039BB1C 0000628E */  lw         $2, 0x0($19)
    /* 29BB20 0039BB20 2D286002 */  daddu      $5, $19, $0
    /* 29BB24 0039BB24 C86D0E0C */  jal        func_0039b720
    /* 29BB28 0039BB28 21205100 */   addu      $4, $2, $17
    /* 29BB2C 0039BB2C 0400628E */  lw         $2, 0x4($19)
    /* 29BB30 0039BB30 01001026 */  addiu      $16, $16, 0x1
    /* 29BB34 0039BB34 2B100202 */  sltu       $2, $16, $2
    /* 29BB38 0039BB38 F8FF4014 */  bnez       $2, .L0039BB1C
    /* 29BB3C 0039BB3C 14003126 */   addiu     $17, $17, 0x14
    /* 29BB40 0039BB40 EBFF0010 */  b          .L0039BAF0
    /* 29BB44 0039BB44 01000324 */   addiu     $3, $0, 0x1
  .L0039BB48:
    /* 29BB48 0039BB48 4000BFDF */  ld         $31, 0x40($29)
    /* 29BB4C 0039BB4C 3000B37B */  lq         $19, 0x30($29)
    /* 29BB50 0039BB50 2000B27B */  lq         $18, 0x20($29)
    /* 29BB54 0039BB54 1000B17B */  lq         $17, 0x10($29)
    /* 29BB58 0039BB58 0000B07B */  lq         $16, 0x0($29)
    /* 29BB5C 0039BB5C 0800E003 */  jr         $31
    /* 29BB60 0039BB60 5000BD27 */   addiu     $29, $29, 0x50
    /* 29BB64 0039BB64 00000000 */  nop
    /* 29BB68 0039BB68 00000000 */  nop
    /* 29BB6C 0039BB6C 00000000 */  nop
.size func_0039ba80, 0xf0
