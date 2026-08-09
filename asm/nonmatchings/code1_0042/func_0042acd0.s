.section .text
.set noat
.set noreorder
glabel func_0042acd0
    /* 32ACD0 0042ACD0 2D30A000 */  daddu      $6, $5, $0
    /* 32ACD4 0042ACD4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32ACD8 0042ACD8 7500053C */  lui        $5, %hi(D_007543B8)
    /* 32ACDC 0042ACDC 0000BFFF */  sd         $31, 0x0($29)
    /* 32ACE0 0042ACE0 B843A524 */  addiu      $5, $5, %lo(D_007543B8)
    /* 32ACE4 0042ACE4 EAAA100C */  jal        func_0042aba8
    /* 32ACE8 0042ACE8 01000724 */   addiu     $7, $0, 0x1
    /* 32ACEC 0042ACEC 0000BFDF */  ld         $31, 0x0($29)
    /* 32ACF0 0042ACF0 0800E003 */  jr         $31
    /* 32ACF4 0042ACF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0042acd0, 0x28
