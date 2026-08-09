.section .text
.set noat
.set noreorder
glabel func_0042c0d8
    /* 32C0D8 0042C0D8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 32C0DC 0042C0DC 0000B0FF */  sd         $16, 0x0($29)
    /* 32C0E0 0042C0E0 1000BFFF */  sd         $31, 0x10($29)
    /* 32C0E4 0042C0E4 06B0100C */  jal        func_0042c018
    /* 32C0E8 0042C0E8 2D808000 */   daddu     $16, $4, $0
    /* 32C0EC 0042C0EC 2D200002 */  daddu      $4, $16, $0
    /* 32C0F0 0042C0F0 1000BFDF */  ld         $31, 0x10($29)
    /* 32C0F4 0042C0F4 0000B0DF */  ld         $16, 0x0($29)
    /* 32C0F8 0042C0F8 00851008 */  j          func_00421400
    /* 32C0FC 0042C0FC 2000BD27 */   addiu     $29, $29, 0x20
.size func_0042c0d8, 0x28
