.section .text
.set noat
.set noreorder
glabel func_00512ea8
    /* 412EA8 00512EA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 412EAC 00512EAC 0000B0FF */  sd         $16, 0x0($29)
    /* 412EB0 00512EB0 2D80A000 */  daddu      $16, $5, $0
    /* 412EB4 00512EB4 0800B1FF */  sd         $17, 0x8($29)
    /* 412EB8 00512EB8 1000BFFF */  sd         $31, 0x10($29)
    /* 412EBC 00512EBC 724F140C */  jal        func_00513dc8
    /* 412EC0 00512EC0 2D88C000 */   daddu     $17, $6, $0
    /* 412EC4 00512EC4 2D184000 */  daddu      $3, $2, $0
    /* 412EC8 00512EC8 06006010 */  beqz       $3, .L00512EE4
    /* 412ECC 00512ECC FFFF0224 */   addiu     $2, $0, -0x1
    /* 412ED0 00512ED0 0C00648C */  lw         $4, 0xC($3)
    /* 412ED4 00512ED4 2D100000 */  daddu      $2, $0, $0
    /* 412ED8 00512ED8 000004AE */  sw         $4, 0x0($16)
    /* 412EDC 00512EDC 1000638C */  lw         $3, 0x10($3)
    /* 412EE0 00512EE0 000023AE */  sw         $3, 0x0($17)
  .L00512EE4:
    /* 412EE4 00512EE4 0000B0DF */  ld         $16, 0x0($29)
    /* 412EE8 00512EE8 0800B1DF */  ld         $17, 0x8($29)
    /* 412EEC 00512EEC 1000BFDF */  ld         $31, 0x10($29)
    /* 412EF0 00512EF0 0800E003 */  jr         $31
    /* 412EF4 00512EF4 2000BD27 */   addiu     $29, $29, 0x20
.size func_00512ea8, 0x50
