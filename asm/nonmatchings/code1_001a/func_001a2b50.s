.section .text
.set noat
.set noreorder
glabel func_001a2b50
    /* A2B50 001A2B50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* A2B54 001A2B54 1000BFFF */  sd         $31, 0x10($29)
    /* A2B58 001A2B58 0000B07F */  sq         $16, 0x0($29)
    /* A2B5C 001A2B5C 2D808000 */  daddu      $16, $4, $0
    /* A2B60 001A2B60 38000426 */  addiu      $4, $16, 0x38
    /* A2B64 001A2B64 AC7B070C */  jal        func_001deeb0
    /* A2B68 001A2B68 00000000 */   nop
    /* A2B6C 001A2B6C 05004014 */  bnez       $2, .L001A2B84
    /* A2B70 001A2B70 00000000 */   nop
    /* A2B74 001A2B74 2D200002 */  daddu      $4, $16, $0
    /* A2B78 001A2B78 38000526 */  addiu      $5, $16, 0x38
    /* A2B7C 001A2B7C 4C7B070C */  jal        func_001ded30
    /* A2B80 001A2B80 00000000 */   nop
  .L001A2B84:
    /* A2B84 001A2B84 38000426 */  addiu      $4, $16, 0x38
    /* A2B88 001A2B88 B87B070C */  jal        func_001deee0
    /* A2B8C 001A2B8C 00000000 */   nop
    /* A2B90 001A2B90 19004010 */  beqz       $2, .L001A2BF8
    /* A2B94 001A2B94 00000000 */   nop
    /* A2B98 001A2B98 ACB3828F */  lw         $2, -0x4C54($28)
    /* A2B9C 001A2B9C 0C00438C */  lw         $3, 0xC($2)
    /* A2BA0 001A2BA0 00106230 */  andi       $2, $3, 0x1000
    /* A2BA4 001A2BA4 0D004010 */  beqz       $2, .L001A2BDC
    /* A2BA8 001A2BA8 00000000 */   nop
    /* A2BAC 001A2BAC 0004023C */  lui        $2, (0x4000000 >> 16)
    /* A2BB0 001A2BB0 24106200 */  and        $2, $3, $2
    /* A2BB4 001A2BB4 09004010 */  beqz       $2, .L001A2BDC
    /* A2BB8 001A2BB8 00000000 */   nop
    /* A2BBC 001A2BBC 3000028E */  lw         $2, 0x30($16)
    /* A2BC0 001A2BC0 A2004390 */  lbu        $3, 0xA2($2)
    /* A2BC4 001A2BC4 01000224 */  addiu      $2, $0, 0x1
    /* A2BC8 001A2BC8 04006214 */  bne        $3, $2, .L001A2BDC
    /* A2BCC 001A2BCC 00000000 */   nop
    /* A2BD0 001A2BD0 18000296 */  lhu        $2, 0x18($16)
    /* A2BD4 001A2BD4 00404234 */  ori        $2, $2, 0x4000
    /* A2BD8 001A2BD8 180002A6 */  sh         $2, 0x18($16)
  .L001A2BDC:
    /* A2BDC 001A2BDC 18000296 */  lhu        $2, 0x18($16)
    /* A2BE0 001A2BE0 02004234 */  ori        $2, $2, 0x2
    /* A2BE4 001A2BE4 180002A6 */  sh         $2, 0x18($16)
    /* A2BE8 001A2BE8 2D200002 */  daddu      $4, $16, $0
    /* A2BEC 001A2BEC 0F000524 */  addiu      $5, $0, 0xF
    /* A2BF0 001A2BF0 00C2060C */  jal        func_001b0800
    /* A2BF4 001A2BF4 00000000 */   nop
  .L001A2BF8:
    /* A2BF8 001A2BF8 1000BFDF */  ld         $31, 0x10($29)
    /* A2BFC 001A2BFC 0000B07B */  lq         $16, 0x0($29)
    /* A2C00 001A2C00 2000BD27 */  addiu      $29, $29, 0x20
    /* A2C04 001A2C04 0800E003 */  jr         $31
    /* A2C08 001A2C08 00000000 */   nop
    /* A2C0C 001A2C0C 00000000 */  nop
.size func_001a2b50, 0xc0
