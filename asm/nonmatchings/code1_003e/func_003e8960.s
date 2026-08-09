.section .text
.set noat
.set noreorder
glabel func_003e8960
    /* 2E8960 003E8960 2D288000 */  daddu      $5, $4, $0
    /* 2E8964 003E8964 7100043C */  lui        $4, %hi(D_0070B760)
    /* 2E8968 003E8968 0C8E0F08 */  j          func_003e3830
    /* 2E896C 003E896C 60B78424 */   addiu     $4, $4, %lo(D_0070B760)
.size func_003e8960, 0x10
