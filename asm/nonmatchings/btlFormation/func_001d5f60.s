.section .text
.set noat
.set noreorder
glabel func_001d5f60
    /* D5F60 001D5F60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* D5F64 001D5F64 1000BFFF */  sd         $31, 0x10($29)
    /* D5F68 001D5F68 0000B07F */  sq         $16, 0x0($29)
    /* D5F6C 001D5F6C 2D808000 */  daddu      $16, $4, $0
    /* D5F70 001D5F70 180080AC */  sw         $0, 0x18($4)
    /* D5F74 001D5F74 0000848C */  lw         $4, 0x0($4)
    /* D5F78 001D5F78 3450070C */  jal        func_001d40d0
    /* D5F7C 001D5F7C 00000000 */   nop
    /* D5F80 001D5F80 0400038E */  lw         $3, 0x4($16)
    /* D5F84 001D5F84 A0006294 */  lhu        $2, 0xA0($3)
    /* D5F88 001D5F88 01004224 */  addiu      $2, $2, 0x1
    /* D5F8C 001D5F8C A00062A4 */  sh         $2, 0xA0($3)
    /* D5F90 001D5F90 0800038E */  lw         $3, 0x8($16)
    /* D5F94 001D5F94 A0006294 */  lhu        $2, 0xA0($3)
    /* D5F98 001D5F98 01004224 */  addiu      $2, $2, 0x1
    /* D5F9C 001D5F9C A00062A4 */  sh         $2, 0xA0($3)
    /* D5FA0 001D5FA0 0C000386 */  lh         $3, 0xC($16)
    /* D5FA4 001D5FA4 01000224 */  addiu      $2, $0, 0x1
    /* D5FA8 001D5FA8 0A006210 */  beq        $3, $2, .L001D5FD4
    /* D5FAC 001D5FAC 00000000 */   nop
    /* D5FB0 001D5FB0 03006010 */  beqz       $3, .L001D5FC0
    /* D5FB4 001D5FB4 00000000 */   nop
    /* D5FB8 001D5FB8 09000010 */  b          .L001D5FE0
    /* D5FBC 001D5FBC 00000000 */   nop
  .L001D5FC0:
    /* D5FC0 001D5FC0 0400028E */  lw         $2, 0x4($16)
    /* D5FC4 001D5FC4 080A428C */  lw         $2, 0xA08($2)
    /* D5FC8 001D5FC8 140002AE */  sw         $2, 0x14($16)
    /* D5FCC 001D5FCC 04000010 */  b          .L001D5FE0
    /* D5FD0 001D5FD0 00000000 */   nop
  .L001D5FD4:
    /* D5FD4 001D5FD4 0800028E */  lw         $2, 0x8($16)
    /* D5FD8 001D5FD8 080A428C */  lw         $2, 0xA08($2)
    /* D5FDC 001D5FDC 140002AE */  sw         $2, 0x14($16)
  .L001D5FE0:
    /* D5FE0 001D5FE0 1400048E */  lw         $4, 0x14($16)
    /* D5FE4 001D5FE4 385B070C */  jal        func_001d6ce0
    /* D5FE8 001D5FE8 00000000 */   nop
    /* D5FEC 001D5FEC 100002AE */  sw         $2, 0x10($16)
    /* D5FF0 001D5FF0 1000BFDF */  ld         $31, 0x10($29)
    /* D5FF4 001D5FF4 0000B07B */  lq         $16, 0x0($29)
    /* D5FF8 001D5FF8 2000BD27 */  addiu      $29, $29, 0x20
    /* D5FFC 001D5FFC 0800E003 */  jr         $31
    /* D6000 001D6000 00000000 */   nop
    /* D6004 001D6004 00000000 */  nop
    /* D6008 001D6008 00000000 */  nop
    /* D600C 001D600C 00000000 */  nop
.size func_001d5f60, 0xb0
