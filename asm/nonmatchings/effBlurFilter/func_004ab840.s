.section .text
.set noat
.set noreorder
glabel func_004ab840
    /* 3AB840 004AB840 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB844 004AB844 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB848 004AB848 0000B07F */  sq         $16, 0x0($29)
    /* 3AB84C 004AB84C 2D808000 */  daddu      $16, $4, $0
    /* 3AB850 004AB850 1C00838C */  lw         $3, 0x1C($4)
    /* 3AB854 004AB854 0B006018 */  blez       $3, .L004AB884
    /* 3AB858 004AB858 00000000 */   nop
    /* 3AB85C 004AB85C 2400028E */  lw         $2, 0x24($16)
    /* 3AB860 004AB860 2C0000AE */  sw         $0, 0x2C($16)
    /* 3AB864 004AB864 300000AE */  sw         $0, 0x30($16)
    /* 3AB868 004AB868 28004494 */  lhu        $4, 0x28($2)
    /* 3AB86C 004AB86C 3405120C */  jal        func_004814d0
    /* 3AB870 004AB870 00000000 */   nop
    /* 3AB874 004AB874 2D204000 */  daddu      $4, $2, $0
    /* 3AB878 004AB878 2C000526 */  addiu      $5, $16, 0x2C
    /* 3AB87C 004AB87C B082110C */  jal        func_00460ac0
    /* 3AB880 004AB880 00000000 */   nop
  .L004AB884:
    /* 3AB884 004AB884 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB888 004AB888 0000B07B */  lq         $16, 0x0($29)
    /* 3AB88C 004AB88C 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB890 004AB890 0800E003 */  jr         $31
    /* 3AB894 004AB894 00000000 */   nop
    /* 3AB898 004AB898 00000000 */  nop
    /* 3AB89C 004AB89C 00000000 */  nop
.size func_004ab840, 0x60
