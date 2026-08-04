.section .text
.set noat
.set noreorder
glabel func_001ba710
    /* BA710 001BA710 D0FFBD27 */  addiu      $29, $29, -0x30
    /* BA714 001BA714 2000BFFF */  sd         $31, 0x20($29)
    /* BA718 001BA718 1000B17F */  sq         $17, 0x10($29)
    /* BA71C 001BA71C 0000B07F */  sq         $16, 0x0($29)
    /* BA720 001BA720 2D888000 */  daddu      $17, $4, $0
    /* BA724 001BA724 2D80A000 */  daddu      $16, $5, $0
    /* BA728 001BA728 0A060424 */  addiu      $4, $0, 0x60A
    /* BA72C 001BA72C 28000524 */  addiu      $5, $0, 0x28
    /* BA730 001BA730 1C51060C */  jal        func_00194470
    /* BA734 001BA734 00000000 */   nop
    /* BA738 001BA738 1C00033C */  lui        $3, %hi(func_001ba590)
    /* BA73C 001BA73C 90A56324 */  addiu      $3, $3, %lo(func_001ba590)
    /* BA740 001BA740 6C0043AC */  sw         $3, 0x6C($2)
    /* BA744 001BA744 7800438C */  lw         $3, 0x78($2)
    /* BA748 001BA748 000023C6 */  lwc1       $f3, 0x0($17)
    /* BA74C 001BA74C 040022C6 */  lwc1       $f2, 0x4($17)
    /* BA750 001BA750 080021C6 */  lwc1       $f1, 0x8($17)
    /* BA754 001BA754 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* BA758 001BA758 000063E4 */  swc1       $f3, 0x0($3)
    /* BA75C 001BA75C 040062E4 */  swc1       $f2, 0x4($3)
    /* BA760 001BA760 080061E4 */  swc1       $f1, 0x8($3)
    /* BA764 001BA764 0C0060E4 */  swc1       $f0, 0xC($3)
    /* BA768 001BA768 200070AC */  sw         $16, 0x20($3)
    /* BA76C 001BA76C 2000BFDF */  ld         $31, 0x20($29)
    /* BA770 001BA770 1000B17B */  lq         $17, 0x10($29)
    /* BA774 001BA774 0000B07B */  lq         $16, 0x0($29)
    /* BA778 001BA778 3000BD27 */  addiu      $29, $29, 0x30
    /* BA77C 001BA77C 0800E003 */  jr         $31
    /* BA780 001BA780 00000000 */   nop
    /* BA784 001BA784 00000000 */  nop
    /* BA788 001BA788 00000000 */  nop
    /* BA78C 001BA78C 00000000 */  nop
.size func_001ba710, 0x80
