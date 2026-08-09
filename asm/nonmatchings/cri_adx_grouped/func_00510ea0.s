.section .text
.set noat
.set noreorder
glabel func_00510ea0
    /* 410EA0 00510EA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 410EA4 00510EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 410EA8 00510EA8 78C4130C */  jal        func_004f11e0
    /* 410EAC 00510EAC 00000000 */   nop
    /* 410EB0 00510EB0 0000BFDF */  ld         $31, 0x0($29)
    /* 410EB4 00510EB4 9300023C */  lui        $2, %hi(D_00932C80)
    /* 410EB8 00510EB8 9300033C */  lui        $3, %hi(D_00932C84)
    /* 410EBC 00510EBC 9300043C */  lui        $4, %hi(D_00932C88)
    /* 410EC0 00510EC0 9300053C */  lui        $5, %hi(D_00932C8C)
    /* 410EC4 00510EC4 802C40AC */  sw         $0, %lo(D_00932C80)($2)
    /* 410EC8 00510EC8 842C60AC */  sw         $0, %lo(D_00932C84)($3)
    /* 410ECC 00510ECC 882C80AC */  sw         $0, %lo(D_00932C88)($4)
    /* 410ED0 00510ED0 8C2CA0AC */  sw         $0, %lo(D_00932C8C)($5)
    /* 410ED4 00510ED4 0800E003 */  jr         $31
    /* 410ED8 00510ED8 1000BD27 */   addiu     $29, $29, 0x10
    /* 410EDC 00510EDC 00000000 */  nop
.size func_00510ea0, 0x40
