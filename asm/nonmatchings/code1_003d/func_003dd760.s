.section .text
.set noat
.set noreorder
glabel func_003dd760
    /* 2DD760 003DD760 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DD764 003DD764 8800033C */  lui        $3, %hi(D_00887188)
    /* 2DD768 003DD768 0000BFFF */  sd         $31, 0x0($29)
    /* 2DD76C 003DD76C 8800023C */  lui        $2, %hi(D_00887184)
    /* 2DD770 003DD770 847144AC */  sw         $4, %lo(D_00887184)($2)
    /* 2DD774 003DD774 887160AC */  sw         $0, %lo(D_00887188)($3)
    /* 2DD778 003DD778 8800023C */  lui        $2, %hi(D_00887180)
    /* 2DD77C 003DD77C 8800033C */  lui        $3, %hi(D_00887194)
    /* 2DD780 003DD780 807140AC */  sw         $0, %lo(D_00887180)($2)
    /* 2DD784 003DD784 947160AC */  sw         $0, %lo(D_00887194)($3)
    /* 2DD788 003DD788 8800023C */  lui        $2, %hi(D_008871A8)
    /* 2DD78C 003DD78C 01000324 */  addiu      $3, $0, 0x1
    /* 2DD790 003DD790 8800043C */  lui        $4, %hi(D_008871A0)
    /* 2DD794 003DD794 A87143AC */  sw         $3, %lo(D_008871A8)($2)
    /* 2DD798 003DD798 A0718424 */  addiu      $4, $4, %lo(D_008871A0)
    /* 2DD79C 003DD79C 8800023C */  lui        $2, %hi(D_008871A4)
    /* 2DD7A0 003DD7A0 50B780AF */  sw         $0, -0x48B0($28)
    /* 2DD7A4 003DD7A4 F885100C */  jal        func_004217e0
    /* 2DD7A8 003DD7A8 A47143AC */   sw        $3, %lo(D_008871A4)($2)
    /* 2DD7AC 003DD7AC 54B782AF */  sw         $2, -0x48AC($28)
    /* 2DD7B0 003DD7B0 8800033C */  lui        $3, %hi(D_0088718C)
    /* 2DD7B4 003DD7B4 01000224 */  addiu      $2, $0, 0x1
    /* 2DD7B8 003DD7B8 8C7162AC */  sw         $2, %lo(D_0088718C)($3)
    /* 2DD7BC 003DD7BC 0000BFDF */  ld         $31, 0x0($29)
    /* 2DD7C0 003DD7C0 0800E003 */  jr         $31
    /* 2DD7C4 003DD7C4 1000BD27 */   addiu     $29, $29, 0x10
    /* 2DD7C8 003DD7C8 00000000 */  nop
    /* 2DD7CC 003DD7CC 00000000 */  nop
.size func_003dd760, 0x70
