.section .text
.set noat
.set noreorder
glabel func_004ae880
    /* 3AE880 004AE880 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AE884 004AE884 2000BFFF */  sd         $31, 0x20($29)
    /* 3AE888 004AE888 1000B17F */  sq         $17, 0x10($29)
    /* 3AE88C 004AE88C 0000B07F */  sq         $16, 0x0($29)
    /* 3AE890 004AE890 2D888000 */  daddu      $17, $4, $0
    /* 3AE894 004AE894 2D80A000 */  daddu      $16, $5, $0
    /* 3AE898 004AE898 0C00A394 */  lhu        $3, 0xC($5)
    /* 3AE89C 004AE89C 03000224 */  addiu      $2, $0, 0x3
    /* 3AE8A0 004AE8A0 03006210 */  beq        $3, $2, .L004AE8B0
    /* 3AE8A4 004AE8A4 00000000 */   nop
    /* 3AE8A8 004AE8A8 12000010 */  b          .L004AE8F4
    /* 3AE8AC 004AE8AC 00000000 */   nop
  .L004AE8B0:
    /* 3AE8B0 004AE8B0 5400248E */  lw         $4, 0x54($17)
    /* 3AE8B4 004AE8B4 03008010 */  beqz       $4, .L004AE8C4
    /* 3AE8B8 004AE8B8 00000000 */   nop
    /* 3AE8BC 004AE8BC C0010F0C */  jal        func_003c0700
    /* 3AE8C0 004AE8C0 00000000 */   nop
  .L004AE8C4:
    /* 3AE8C4 004AE8C4 5400048E */  lw         $4, 0x54($16)
    /* 3AE8C8 004AE8C8 48010F0C */  jal        func_003c0520
    /* 3AE8CC 004AE8CC 00000000 */   nop
    /* 3AE8D0 004AE8D0 540022AE */  sw         $2, 0x54($17)
    /* 3AE8D4 004AE8D4 2D204000 */  daddu      $4, $2, $0
    /* 3AE8D8 004AE8D8 4B00053C */  lui        $5, %hi(func_004ae080)
    /* 3AE8DC 004AE8DC 80E0A524 */  addiu      $5, $5, %lo(func_004ae080)
    /* 3AE8E0 004AE8E0 2D300000 */  daddu      $6, $0, $0
    /* 3AE8E4 004AE8E4 CCFF0E0C */  jal        func_003bff30
    /* 3AE8E8 004AE8E8 00000000 */   nop
    /* 3AE8EC 004AE8EC 06000010 */  b          .L004AE908
    /* 3AE8F0 004AE8F0 00000000 */   nop
  .L004AE8F4:
    /* 3AE8F4 004AE8F4 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AE8F8 004AE8F8 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AE8FC 004AE8FC 72010524 */  addiu      $5, $0, 0x172
    /* 3AE900 004AE900 CCB5110C */  jal        func_0046d730
    /* 3AE904 004AE904 00000000 */   nop
  .L004AE908:
    /* 3AE908 004AE908 0C000396 */  lhu        $3, 0xC($16)
    /* 3AE90C 004AE90C 0C0023A6 */  sh         $3, 0xC($17)
    /* 3AE910 004AE910 2000BFDF */  ld         $31, 0x20($29)
    /* 3AE914 004AE914 1000B17B */  lq         $17, 0x10($29)
    /* 3AE918 004AE918 0000B07B */  lq         $16, 0x0($29)
    /* 3AE91C 004AE91C 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AE920 004AE920 0800E003 */  jr         $31
    /* 3AE924 004AE924 00000000 */   nop
    /* 3AE928 004AE928 00000000 */  nop
    /* 3AE92C 004AE92C 00000000 */  nop
.size func_004ae880, 0xb0
