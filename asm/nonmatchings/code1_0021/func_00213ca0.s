.section .text
.set noat
.set noreorder
glabel func_00213ca0
    /* 113CA0 00213CA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 113CA4 00213CA4 0000BFFF */  sd         $31, 0x0($29)
    /* 113CA8 00213CA8 5849110C */  jal        func_00452560
    /* 113CAC 00213CAC 00000000 */   nop
    /* 113CB0 00213CB0 0C08448C */  lw         $4, 0x80C($2)
    /* 113CB4 00213CB4 FFFE0324 */  addiu      $3, $0, -0x101
    /* 113CB8 00213CB8 24188300 */  and        $3, $4, $3
    /* 113CBC 00213CBC 0C0843AC */  sw         $3, 0x80C($2)
    /* 113CC0 00213CC0 0000BFDF */  ld         $31, 0x0($29)
    /* 113CC4 00213CC4 1000BD27 */  addiu      $29, $29, 0x10
    /* 113CC8 00213CC8 0800E003 */  jr         $31
    /* 113CCC 00213CCC 00000000 */   nop
.size func_00213ca0, 0x30
