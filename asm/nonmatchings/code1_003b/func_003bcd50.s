.section .text
.set noat
.set noreorder
glabel func_003bcd50
    /* 2BCD50 003BCD50 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2BCD54 003BCD54 5000BFFF */  sd         $31, 0x50($29)
    /* 2BCD58 003BCD58 4000B47F */  sq         $20, 0x40($29)
    /* 2BCD5C 003BCD5C 3000B37F */  sq         $19, 0x30($29)
    /* 2BCD60 003BCD60 2DA08000 */  daddu      $20, $4, $0
    /* 2BCD64 003BCD64 2000B27F */  sq         $18, 0x20($29)
    /* 2BCD68 003BCD68 1000B17F */  sq         $17, 0x10($29)
    /* 2BCD6C 003BCD6C 0000B07F */  sq         $16, 0x0($29)
    /* 2BCD70 003BCD70 2180C700 */  addu       $16, $6, $7
    /* 2BCD74 003BCD74 20000012 */  beqz       $16, .L003BCDF8
    /* 2BCD78 003BCD78 2D988002 */   daddu     $19, $20, $0
    /* 2BCD7C 003BCD7C 6C00A527 */  addiu      $5, $29, 0x6C
    /* 2BCD80 003BCD80 D87C0F0C */  jal        func_003df360
    /* 2BCD84 003BCD84 04000624 */   addiu     $6, $0, 0x4
    /* 2BCD88 003BCD88 1B004010 */  beqz       $2, .L003BCDF8
    /* 2BCD8C 003BCD8C 00000000 */   nop
    /* 2BCD90 003BCD90 6C00A38F */  lw         $3, 0x6C($29)
    /* 2BCD94 003BCD94 0300023C */  lui        $2, (0x3011F >> 16)
    /* 2BCD98 003BCD98 1F014534 */  ori        $5, $2, (0x3011F & 0xFFFF)
    /* 2BCD9C 003BCD9C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BCDA0 003BCDA0 000003AE */  sw         $3, 0x0($16)
    /* 2BCDA4 003BCDA4 0000038E */  lw         $3, 0x0($16)
    /* 2BCDA8 003BCDA8 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BCDAC 003BCDAC 09F84000 */  jalr       $2
    /* 2BCDB0 003BCDB0 00210300 */   sll       $4, $3, 4
    /* 2BCDB4 003BCDB4 040002AE */  sw         $2, 0x4($16)
    /* 2BCDB8 003BCDB8 0000028E */  lw         $2, 0x0($16)
    /* 2BCDBC 003BCDBC 2A080200 */  slt        $1, $0, $2
    /* 2BCDC0 003BCDC0 0D002010 */  beqz       $1, .L003BCDF8
    /* 2BCDC4 003BCDC4 2D900000 */   daddu     $18, $0, $0
    /* 2BCDC8 003BCDC8 2D880000 */  daddu      $17, $0, $0
  .L003BCDCC:
    /* 2BCDCC 003BCDCC 0400028E */  lw         $2, 0x4($16)
    /* 2BCDD0 003BCDD0 2D286002 */  daddu      $5, $19, $0
    /* 2BCDD4 003BCDD4 54F00E0C */  jal        func_003bc150
    /* 2BCDD8 003BCDD8 21205100 */   addu      $4, $2, $17
    /* 2BCDDC 003BCDDC 2D984000 */  daddu      $19, $2, $0
    /* 2BCDE0 003BCDE0 01005226 */  addiu      $18, $18, 0x1
    /* 2BCDE4 003BCDE4 0000028E */  lw         $2, 0x0($16)
    /* 2BCDE8 003BCDE8 2A104202 */  slt        $2, $18, $2
    /* 2BCDEC 003BCDEC F7FF4014 */  bnez       $2, .L003BCDCC
    /* 2BCDF0 003BCDF0 10003126 */   addiu     $17, $17, 0x10
    /* 2BCDF4 003BCDF4 00000000 */  nop
  .L003BCDF8:
    /* 2BCDF8 003BCDF8 2D108002 */  daddu      $2, $20, $0
    /* 2BCDFC 003BCDFC 5000BFDF */  ld         $31, 0x50($29)
    /* 2BCE00 003BCE00 4000B47B */  lq         $20, 0x40($29)
    /* 2BCE04 003BCE04 3000B37B */  lq         $19, 0x30($29)
    /* 2BCE08 003BCE08 2000B27B */  lq         $18, 0x20($29)
    /* 2BCE0C 003BCE0C 1000B17B */  lq         $17, 0x10($29)
    /* 2BCE10 003BCE10 0000B07B */  lq         $16, 0x0($29)
    /* 2BCE14 003BCE14 0800E003 */  jr         $31
    /* 2BCE18 003BCE18 7000BD27 */   addiu     $29, $29, 0x70
    /* 2BCE1C 003BCE1C 00000000 */  nop
.size func_003bcd50, 0xd0
