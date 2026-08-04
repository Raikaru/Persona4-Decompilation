.section .text
.set noat
.set noreorder
glabel func_003c2c90
    /* 2C2C90 003C2C90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2C2C94 003C2C94 2000BFFF */  sd         $31, 0x20($29)
    /* 2C2C98 003C2C98 1000B17F */  sq         $17, 0x10($29)
    /* 2C2C9C 003C2C9C 2D888000 */  daddu      $17, $4, $0
    /* 2C2CA0 003C2CA0 F40A0F0C */  jal        func_003c2bd0
    /* 2C2CA4 003C2CA4 0000B07F */   sq        $16, 0x0($29)
    /* 2C2CA8 003C2CA8 0C005024 */  addiu      $16, $2, 0xC
    /* 2C2CAC 003C2CAC 00130F0C */  jal        func_003c4c00
    /* 2C2CB0 003C2CB0 20002426 */   addiu     $4, $17, 0x20
    /* 2C2CB4 003C2CB4 0C004224 */  addiu      $2, $2, 0xC
    /* 2C2CB8 003C2CB8 7100043C */  lui        $4, %hi(D_0070AFB0)
    /* 2C2CBC 003C2CBC 2D282002 */  daddu      $5, $17, $0
    /* 2C2CC0 003C2CC0 21800202 */  addu       $16, $16, $2
    /* 2C2CC4 003C2CC4 DC8C0F0C */  jal        func_003e3370
    /* 2C2CC8 003C2CC8 B0AF8424 */   addiu     $4, $4, %lo(D_0070AFB0)
    /* 2C2CCC 003C2CCC 0C004224 */  addiu      $2, $2, 0xC
    /* 2C2CD0 003C2CD0 2000BFDF */  ld         $31, 0x20($29)
    /* 2C2CD4 003C2CD4 21100202 */  addu       $2, $16, $2
    /* 2C2CD8 003C2CD8 1000B17B */  lq         $17, 0x10($29)
    /* 2C2CDC 003C2CDC 0000B07B */  lq         $16, 0x0($29)
    /* 2C2CE0 003C2CE0 0800E003 */  jr         $31
    /* 2C2CE4 003C2CE4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2C2CE8 003C2CE8 00000000 */  nop
    /* 2C2CEC 003C2CEC 00000000 */  nop
.size func_003c2c90, 0x60
