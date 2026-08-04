.section .text
.set noat
.set noreorder
glabel func_003be820
    /* 2BE820 003BE820 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BE824 003BE824 04000624 */  addiu      $6, $0, 0x4
    /* 2BE828 003BE828 2000BFFF */  sd         $31, 0x20($29)
    /* 2BE82C 003BE82C 1000B17F */  sq         $17, 0x10($29)
    /* 2BE830 003BE830 0000B07F */  sq         $16, 0x0($29)
    /* 2BE834 003BE834 2D888000 */  daddu      $17, $4, $0
    /* 2BE838 003BE838 2D80A000 */  daddu      $16, $5, $0
    /* 2BE83C 003BE83C D87C0F0C */  jal        func_003df360
    /* 2BE840 003BE840 BCB68527 */   addiu     $5, $28, -0x4944
    /* 2BE844 003BE844 06004010 */  beqz       $2, .L003BE860
    /* 2BE848 003BE848 00000000 */   nop
    /* 2BE84C 003BE84C 08000224 */  addiu      $2, $0, 0x8
    /* 2BE850 003BE850 05000212 */  beq        $16, $2, .L003BE868
    /* 2BE854 003BE854 00000000 */   nop
  .L003BE858:
    /* 2BE858 003BE858 0A000010 */  b          .L003BE884
    /* 2BE85C 003BE85C 2D102002 */   daddu     $2, $17, $0
  .L003BE860:
    /* 2BE860 003BE860 08000010 */  b          .L003BE884
    /* 2BE864 003BE864 2D100000 */   daddu     $2, $0, $0
  .L003BE868:
    /* 2BE868 003BE868 2D202002 */  daddu      $4, $17, $0
    /* 2BE86C 003BE86C B8B68527 */  addiu      $5, $28, -0x4948
    /* 2BE870 003BE870 D87C0F0C */  jal        func_003df360
    /* 2BE874 003BE874 04000624 */   addiu     $6, $0, 0x4
    /* 2BE878 003BE878 F7FF4014 */  bnez       $2, .L003BE858
    /* 2BE87C 003BE87C 00000000 */   nop
    /* 2BE880 003BE880 2D100000 */  daddu      $2, $0, $0
  .L003BE884:
    /* 2BE884 003BE884 2000BFDF */  ld         $31, 0x20($29)
    /* 2BE888 003BE888 1000B17B */  lq         $17, 0x10($29)
    /* 2BE88C 003BE88C 0000B07B */  lq         $16, 0x0($29)
    /* 2BE890 003BE890 0800E003 */  jr         $31
    /* 2BE894 003BE894 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BE898 003BE898 00000000 */  nop
    /* 2BE89C 003BE89C 00000000 */  nop
.size func_003be820, 0x80
