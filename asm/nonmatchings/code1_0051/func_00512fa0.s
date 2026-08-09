.section .text
.set noat
.set noreorder
glabel func_00512fa0
    /* 412FA0 00512FA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 412FA4 00512FA4 0000BFFF */  sd         $31, 0x0($29)
    /* 412FA8 00512FA8 0420828C */  lw         $2, 0x2004($4)
    /* 412FAC 00512FAC FE50130C */  jal        func_004d43f8
    /* 412FB0 00512FB0 0000448C */   lw        $4, 0x0($2)
    /* 412FB4 00512FB4 03004238 */  xori       $2, $2, 0x3
    /* 412FB8 00512FB8 0000BFDF */  ld         $31, 0x0($29)
    /* 412FBC 00512FBC 0100422C */  sltiu      $2, $2, 0x1
    /* 412FC0 00512FC0 0800E003 */  jr         $31
    /* 412FC4 00512FC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00512fa0, 0x28
