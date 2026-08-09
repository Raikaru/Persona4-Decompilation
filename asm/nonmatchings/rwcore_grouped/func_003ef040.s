.section .text
.set noat
.set noreorder
glabel func_003ef040
    /* 2EF040 003EF040 E0B7858F */  lw         $5, -0x4820($28)
    /* 2EF044 003EF044 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EF048 003EF048 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EF04C 003EF04C 01000224 */  addiu      $2, $0, 0x1
    /* 2EF050 003EF050 21186500 */  addu       $3, $3, $5
    /* 2EF054 003EF054 0800E003 */  jr         $31
    /* 2EF058 003EF058 200064AC */   sw        $4, 0x20($3)
    /* 2EF05C 003EF05C 00000000 */  nop
.size func_003ef040, 0x20
