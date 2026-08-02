.section .text
.set noat
.set noreorder
glabel func_001e5e40
    /* E5E40 001E5E40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E5E44 001E5E44 1000BFFF */  sd         $31, 0x10($29)
    /* E5E48 001E5E48 0000B07F */  sq         $16, 0x0($29)
    /* E5E4C 001E5E4C 14740A0C */  jal        func_0029d050
    /* E5E50 001E5E50 00000000 */   nop
    /* E5E54 001E5E54 2D804000 */  daddu      $16, $2, $0
    /* E5E58 001E5E58 2D200000 */  daddu      $4, $0, $0
    /* E5E5C 001E5E5C 00730A0C */  jal        func_0029cc00
    /* E5E60 001E5E60 00000000 */   nop
    /* E5E64 001E5E64 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E5E68 001E5E68 08004014 */  bnez       $2, .L001E5E8C
    /* E5E6C 001E5E6C 00000000 */   nop
    /* E5E70 001E5E70 3000028E */  lw         $2, 0x30($16)
    /* E5E74 001E5E74 640A438C */  lw         $3, 0xA64($2)
    /* E5E78 001E5E78 00006294 */  lhu        $2, 0x0($3)
    /* E5E7C 001E5E7C 08004234 */  ori        $2, $2, 0x8
    /* E5E80 001E5E80 000062A4 */  sh         $2, 0x0($3)
    /* E5E84 001E5E84 06000010 */  b          .L001E5EA0
    /* E5E88 001E5E88 00000000 */   nop
  .L001E5E8C:
    /* E5E8C 001E5E8C 3000028E */  lw         $2, 0x30($16)
    /* E5E90 001E5E90 640A438C */  lw         $3, 0xA64($2)
    /* E5E94 001E5E94 00006294 */  lhu        $2, 0x0($3)
    /* E5E98 001E5E98 F7FF4230 */  andi       $2, $2, 0xFFF7
    /* E5E9C 001E5E9C 000062A4 */  sh         $2, 0x0($3)
  .L001E5EA0:
    /* E5EA0 001E5EA0 01000224 */  addiu      $2, $0, 0x1
    /* E5EA4 001E5EA4 1000BFDF */  ld         $31, 0x10($29)
    /* E5EA8 001E5EA8 0000B07B */  lq         $16, 0x0($29)
    /* E5EAC 001E5EAC 2000BD27 */  addiu      $29, $29, 0x20
    /* E5EB0 001E5EB0 0800E003 */  jr         $31
    /* E5EB4 001E5EB4 00000000 */   nop
    /* E5EB8 001E5EB8 00000000 */  nop
    /* E5EBC 001E5EBC 00000000 */  nop
.size func_001e5e40, 0x80
