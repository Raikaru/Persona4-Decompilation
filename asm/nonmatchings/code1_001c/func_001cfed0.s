.section .text
.set noat
.set noreorder
glabel func_001cfed0
    /* CFED0 001CFED0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CFED4 001CFED4 0000BFFF */  sd         $31, 0x0($29)
    /* CFED8 001CFED8 2040023C */  lui        $2, (0x40200000 >> 16)
    /* CFEDC 001CFEDC 00688244 */  mtc1       $2, $f13
    /* CFEE0 001CFEE0 14818CC7 */  lwc1       $f12, -0x7EEC($28)
    /* CFEE4 001CFEE4 B43E070C */  jal        func_001cfad0
    /* CFEE8 001CFEE8 00000000 */   nop
    /* CFEEC 001CFEEC 0000BFDF */  ld         $31, 0x0($29)
    /* CFEF0 001CFEF0 1000BD27 */  addiu      $29, $29, 0x10
    /* CFEF4 001CFEF4 0800E003 */  jr         $31
    /* CFEF8 001CFEF8 00000000 */   nop
    /* CFEFC 001CFEFC 00000000 */  nop
.size func_001cfed0, 0x30
