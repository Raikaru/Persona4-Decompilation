.section .text
.set noat
.set noreorder
glabel func_004dd840
    /* 3DD840 004DD840 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DD844 004DD844 2D280000 */  daddu      $5, $0, $0
    /* 3DD848 004DD848 0800BFFF */  sd         $31, 0x8($29)
    /* 3DD84C 004DD84C 14100624 */  addiu      $6, $0, 0x1014
    /* 3DD850 004DD850 0000B0FF */  sd         $16, 0x0($29)
    /* 3DD854 004DD854 72FE100C */  jal        func_0043f9c8
    /* 3DD858 004DD858 01009080 */   lb        $16, 0x1($4)
    /* 3DD85C 004DD85C 0800BFDF */  ld         $31, 0x8($29)
    /* 3DD860 004DD860 80801000 */  sll        $16, $16, 2
    /* 3DD864 004DD864 7300013C */  lui        $1, %hi(D_00729998)
    /* 3DD868 004DD868 21083000 */  addu       $1, $1, $16
    /* 3DD86C 004DD86C 989920AC */  sw         $0, %lo(D_00729998)($1)
    /* 3DD870 004DD870 0000B0DF */  ld         $16, 0x0($29)
    /* 3DD874 004DD874 0800E003 */  jr         $31
    /* 3DD878 004DD878 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DD87C 004DD87C 00000000 */  nop
.size func_004dd840, 0x40
