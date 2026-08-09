.section .text
.set noat
.set noreorder
glabel func_004f9ab8
    /* 3F9AB8 004F9AB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9ABC 004F9ABC 9200033C */  lui        $3, %hi(D_00927010)
    /* 3F9AC0 004F9AC0 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9AC4 004F9AC4 7600023C */  lui        $2, %hi(D_0075DBF8)
    /* 3F9AC8 004F9AC8 10706324 */  addiu      $3, $3, %lo(D_00927010)
    /* 3F9ACC 004F9ACC F8DB4224 */  addiu      $2, $2, %lo(D_0075DBF8)
    /* 3F9AD0 004F9AD0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9AD4 004F9AD4 000062AC */  sw         $2, 0x0($3)
    /* 3F9AD8 004F9AD8 CAE61308 */  j          func_004f9b28
    /* 3F9ADC 004F9ADC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f9ab8, 0x28
