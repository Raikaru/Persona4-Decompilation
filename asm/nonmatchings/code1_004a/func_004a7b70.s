.section .text
.set noat
.set noreorder
glabel func_004a7b70
    /* 3A7B70 004A7B70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3A7B74 004A7B74 2000BFFF */  sd         $31, 0x20($29)
    /* 3A7B78 004A7B78 1000B17F */  sq         $17, 0x10($29)
    /* 3A7B7C 004A7B7C 0000B07F */  sq         $16, 0x0($29)
    /* 3A7B80 004A7B80 2D888000 */  daddu      $17, $4, $0
    /* 3A7B84 004A7B84 7100043C */  lui        $4, %hi(D_00714350)
    /* 3A7B88 004A7B88 50438424 */  addiu      $4, $4, %lo(D_00714350)
    /* 3A7B8C 004A7B8C 49020524 */  addiu      $5, $0, 0x249
    /* 3A7B90 004A7B90 A43A110C */  jal        func_0044ea90
    /* 3A7B94 004A7B94 00000000 */   nop
    /* 3A7B98 004A7B98 14000424 */  addiu      $4, $0, 0x14
    /* 3A7B9C 004A7B9C 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3A7BA0 004A7BA0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3A7BA4 004A7BA4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3A7BA8 004A7BA8 09F84000 */  jalr       $2
    /* 3A7BAC 004A7BAC 00000000 */   nop
    /* 3A7BB0 004A7BB0 2D804000 */  daddu      $16, $2, $0
    /* 3A7BB4 004A7BB4 000040AC */  sw         $0, 0x0($2)
    /* 3A7BB8 004A7BB8 04000426 */  addiu      $4, $16, 0x4
    /* 3A7BBC 004A7BBC 04002526 */  addiu      $5, $17, 0x4
    /* 3A7BC0 004A7BC0 10000624 */  addiu      $6, $0, 0x10
    /* 3A7BC4 004A7BC4 04FE100C */  jal        func_0043f810
    /* 3A7BC8 004A7BC8 00000000 */   nop
    /* 3A7BCC 004A7BCC 2D100002 */  daddu      $2, $16, $0
    /* 3A7BD0 004A7BD0 2000BFDF */  ld         $31, 0x20($29)
    /* 3A7BD4 004A7BD4 1000B17B */  lq         $17, 0x10($29)
    /* 3A7BD8 004A7BD8 0000B07B */  lq         $16, 0x0($29)
    /* 3A7BDC 004A7BDC 3000BD27 */  addiu      $29, $29, 0x30
    /* 3A7BE0 004A7BE0 0800E003 */  jr         $31
    /* 3A7BE4 004A7BE4 00000000 */   nop
    /* 3A7BE8 004A7BE8 00000000 */  nop
    /* 3A7BEC 004A7BEC 00000000 */  nop
.size func_004a7b70, 0x80
