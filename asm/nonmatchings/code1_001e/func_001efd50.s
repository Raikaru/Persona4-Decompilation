.section .text
.set noat
.set noreorder
glabel func_001efd50
    /* EFD50 001EFD50 90FFBD27 */  addiu      $29, $29, -0x70
    /* EFD54 001EFD54 5000BFFF */  sd         $31, 0x50($29)
    /* EFD58 001EFD58 4000B47F */  sq         $20, 0x40($29)
    /* EFD5C 001EFD5C 3000B37F */  sq         $19, 0x30($29)
    /* EFD60 001EFD60 2000B27F */  sq         $18, 0x20($29)
    /* EFD64 001EFD64 1000B17F */  sq         $17, 0x10($29)
    /* EFD68 001EFD68 0000B07F */  sq         $16, 0x0($29)
    /* EFD6C 001EFD6C 2DA08000 */  daddu      $20, $4, $0
    /* EFD70 001EFD70 3000828C */  lw         $2, 0x30($4)
    /* EFD74 001EFD74 A2004290 */  lbu        $2, 0xA2($2)
    /* EFD78 001EFD78 01000424 */  addiu      $4, $0, 0x1
    /* EFD7C 001EFD7C 04004410 */  beq        $2, $4, .L001EFD90
    /* EFD80 001EFD80 00000000 */   nop
    /* EFD84 001EFD84 2D100000 */  daddu      $2, $0, $0
    /* EFD88 001EFD88 65000010 */  b          .L001EFF20
    /* EFD8C 001EFD8C 00000000 */   nop
  .L001EFD90:
    /* EFD90 001EFD90 2D880000 */  daddu      $17, $0, $0
    /* EFD94 001EFD94 6E008386 */  lh         $3, 0x6E($20)
    /* EFD98 001EFD98 B8016128 */  slti       $1, $3, 0x1B8
    /* EFD9C 001EFD9C 0B002010 */  beqz       $1, .L001EFDCC
    /* EFDA0 001EFDA0 00000000 */   nop
    /* EFDA4 001EFDA4 80100300 */  sll        $2, $3, 2
    /* EFDA8 001EFDA8 21104300 */  addu       $2, $2, $3
    /* EFDAC 001EFDAC C0180200 */  sll        $3, $2, 3
    /* EFDB0 001EFDB0 B8B3828F */  lw         $2, -0x4C48($28)
    /* EFDB4 001EFDB4 21104300 */  addu       $2, $2, $3
    /* EFDB8 001EFDB8 00004290 */  lbu        $2, 0x0($2)
    /* EFDBC 001EFDBC 80004230 */  andi       $2, $2, 0x80
    /* EFDC0 001EFDC0 02004010 */  beqz       $2, .L001EFDCC
    /* EFDC4 001EFDC4 00000000 */   nop
    /* EFDC8 001EFDC8 2D888000 */  daddu      $17, $4, $0
  .L001EFDCC:
    /* EFDCC 001EFDCC 0D002016 */  bnez       $17, .L001EFE04
    /* EFDD0 001EFDD0 00000000 */   nop
    /* EFDD4 001EFDD4 ACB3828F */  lw         $2, -0x4C54($28)
    /* EFDD8 001EFDD8 0C00428C */  lw         $2, 0xC($2)
    /* EFDDC 001EFDDC 00104230 */  andi       $2, $2, 0x1000
    /* EFDE0 001EFDE0 05004014 */  bnez       $2, .L001EFDF8
    /* EFDE4 001EFDE4 00000000 */   nop
    /* EFDE8 001EFDE8 14008396 */  lhu        $3, 0x14($20)
    /* EFDEC 001EFDEC 09000224 */  addiu      $2, $0, 0x9
    /* EFDF0 001EFDF0 04006214 */  bne        $3, $2, .L001EFE04
    /* EFDF4 001EFDF4 00000000 */   nop
  .L001EFDF8:
    /* EFDF8 001EFDF8 2D100000 */  daddu      $2, $0, $0
    /* EFDFC 001EFDFC 48000010 */  b          .L001EFF20
    /* EFE00 001EFE00 00000000 */   nop
  .L001EFE04:
    /* EFE04 001EFE04 2D900000 */  daddu      $18, $0, $0
    /* EFE08 001EFE08 ACB3828F */  lw         $2, -0x4C54($28)
    /* EFE0C 001EFE0C 7401538C */  lw         $19, 0x174($2)
    /* EFE10 001EFE10 36000010 */  b          .L001EFEEC
    /* EFE14 001EFE14 00000000 */   nop
  .L001EFE18:
    /* EFE18 001EFE18 1A006396 */  lhu        $3, 0x1A($19)
    /* EFE1C 001EFE1C 01006230 */  andi       $2, $3, 0x1
    /* EFE20 001EFE20 31004010 */  beqz       $2, .L001EFEE8
    /* EFE24 001EFE24 00000000 */   nop
    /* EFE28 001EFE28 08006230 */  andi       $2, $3, 0x8
    /* EFE2C 001EFE2C 2E004010 */  beqz       $2, .L001EFEE8
    /* EFE30 001EFE30 00000000 */   nop
    /* EFE34 001EFE34 04002016 */  bnez       $17, .L001EFE48
    /* EFE38 001EFE38 00000000 */   nop
    /* EFE3C 001EFE3C 80006230 */  andi       $2, $3, 0x80
    /* EFE40 001EFE40 29004014 */  bnez       $2, .L001EFEE8
    /* EFE44 001EFE44 00000000 */   nop
  .L001EFE48:
    /* EFE48 001EFE48 27007412 */  beq        $19, $20, .L001EFEE8
    /* EFE4C 001EFE4C 00000000 */   nop
    /* EFE50 001EFE50 3000708E */  lw         $16, 0x30($19)
    /* EFE54 001EFE54 A2000292 */  lbu        $2, 0xA2($16)
    /* EFE58 001EFE58 23004014 */  bnez       $2, .L001EFEE8
    /* EFE5C 001EFE5C 00000000 */   nop
    /* EFE60 001EFE60 A4000396 */  lhu        $3, 0xA4($16)
    /* EFE64 001EFE64 01000224 */  addiu      $2, $0, 0x1
    /* EFE68 001EFE68 1F006210 */  beq        $3, $2, .L001EFEE8
    /* EFE6C 001EFE6C 00000000 */   nop
    /* EFE70 001EFE70 08002016 */  bnez       $17, .L001EFE94
    /* EFE74 001EFE74 00000000 */   nop
    /* EFE78 001EFE78 640A048E */  lw         $4, 0xA64($16)
    /* EFE7C 001EFE7C 1000023C */  lui        $2, (0x1001FF >> 16)
    /* EFE80 001EFE80 FF014534 */  ori        $5, $2, (0x1001FF & 0xFFFF)
    /* EFE84 001EFE84 C4C9080C */  jal        func_00232710
    /* EFE88 001EFE88 00000000 */   nop
    /* EFE8C 001EFE8C 16004014 */  bnez       $2, .L001EFEE8
    /* EFE90 001EFE90 00000000 */   nop
  .L001EFE94:
    /* EFE94 001EFE94 640A048E */  lw         $4, 0xA64($16)
    /* EFE98 001EFE98 2D280000 */  daddu      $5, $0, $0
    /* EFE9C 001EFE9C 3C0A090C */  jal        func_002428f0
    /* EFEA0 001EFEA0 00000000 */   nop
    /* EFEA4 001EFEA4 10004014 */  bnez       $2, .L001EFEE8
    /* EFEA8 001EFEA8 00000000 */   nop
    /* EFEAC 001EFEAC 0A002016 */  bnez       $17, .L001EFED8
    /* EFEB0 001EFEB0 00000000 */   nop
    /* EFEB4 001EFEB4 A4000486 */  lh         $4, 0xA4($16)
    /* EFEB8 001EFEB8 2C1F090C */  jal        func_00247cb0
    /* EFEBC 001EFEBC 00000000 */   nop
    /* EFEC0 001EFEC0 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* EFEC4 001EFEC4 B01E040C */  jal        func_00107ac0
    /* EFEC8 001EFEC8 00000000 */   nop
    /* EFECC 001EFECC FFFF4230 */  andi       $2, $2, 0xFFFF
    /* EFED0 001EFED0 05004018 */  blez       $2, .L001EFEE8
    /* EFED4 001EFED4 00000000 */   nop
  .L001EFED8:
    /* EFED8 001EFED8 80101200 */  sll        $2, $18, 2
    /* EFEDC 001EFEDC 21105D00 */  addu       $2, $2, $29
    /* EFEE0 001EFEE0 600053AC */  sw         $19, 0x60($2)
    /* EFEE4 001EFEE4 01005226 */  addiu      $18, $18, 0x1
  .L001EFEE8:
    /* EFEE8 001EFEE8 5004738E */  lw         $19, 0x450($19)
  .L001EFEEC:
    /* EFEEC 001EFEEC CAFF6016 */  bnez       $19, .L001EFE18
    /* EFEF0 001EFEF0 00000000 */   nop
    /* EFEF4 001EFEF4 04004016 */  bnez       $18, .L001EFF08
    /* EFEF8 001EFEF8 00000000 */   nop
    /* EFEFC 001EFEFC 2D100000 */  daddu      $2, $0, $0
    /* EFF00 001EFF00 07000010 */  b          .L001EFF20
    /* EFF04 001EFF04 00000000 */   nop
  .L001EFF08:
    /* EFF08 001EFF08 2D204002 */  daddu      $4, $18, $0
    /* EFF0C 001EFF0C 5CC7080C */  jal        func_00231d70
    /* EFF10 001EFF10 00000000 */   nop
    /* EFF14 001EFF14 80100200 */  sll        $2, $2, 2
    /* EFF18 001EFF18 21105D00 */  addu       $2, $2, $29
    /* EFF1C 001EFF1C 6000428C */  lw         $2, 0x60($2)
  .L001EFF20:
    /* EFF20 001EFF20 5000BFDF */  ld         $31, 0x50($29)
    /* EFF24 001EFF24 4000B47B */  lq         $20, 0x40($29)
    /* EFF28 001EFF28 3000B37B */  lq         $19, 0x30($29)
    /* EFF2C 001EFF2C 2000B27B */  lq         $18, 0x20($29)
    /* EFF30 001EFF30 1000B17B */  lq         $17, 0x10($29)
    /* EFF34 001EFF34 0000B07B */  lq         $16, 0x0($29)
    /* EFF38 001EFF38 7000BD27 */  addiu      $29, $29, 0x70
    /* EFF3C 001EFF3C 0800E003 */  jr         $31
    /* EFF40 001EFF40 00000000 */   nop
    /* EFF44 001EFF44 00000000 */  nop
    /* EFF48 001EFF48 00000000 */  nop
    /* EFF4C 001EFF4C 00000000 */  nop
.size func_001efd50, 0x200
