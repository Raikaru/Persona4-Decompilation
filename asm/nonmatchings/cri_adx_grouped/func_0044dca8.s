.section .text
.set noat
.set noreorder
glabel func_0044dca8
    /* 34DCA8 0044DCA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 34DCAC 0044DCAC 0000A4AF */  sw         $4, 0x0($29)
    /* 34DCB0 0044DCB0 1000BFFF */  sd         $31, 0x10($29)
    /* 34DCB4 0044DCB4 0400A5AF */  sw         $5, 0x4($29)
    /* 34DCB8 0044DCB8 2D20A003 */  daddu      $4, $29, $0
    /* 34DCBC 0044DCBC 0800A6AF */  sw         $6, 0x8($29)
    /* 34DCC0 0044DCC0 E636110C */  jal        func_0044db98
    /* 34DCC4 0044DCC4 0C00A7AF */   sw        $7, 0xC($29)
    /* 34DCC8 0044DCC8 1000BFDF */  ld         $31, 0x10($29)
    /* 34DCCC 0044DCCC 0800E003 */  jr         $31
    /* 34DCD0 0044DCD0 2000BD27 */   addiu     $29, $29, 0x20
    /* 34DCD4 0044DCD4 00000000 */  nop
.size func_0044dca8, 0x30
