.section .text
.set noat
.set noreorder
glabel func_004a7a90
    /* 3A7A90 004A7A90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3A7A94 004A7A94 2000BFFF */  sd         $31, 0x20($29)
    /* 3A7A98 004A7A98 1000B17F */  sq         $17, 0x10($29)
    /* 3A7A9C 004A7A9C 0000B07F */  sq         $16, 0x0($29)
    /* 3A7AA0 004A7AA0 2411120C */  jal        func_00484490
    /* 3A7AA4 004A7AA4 00000000 */   nop
    /* 3A7AA8 004A7AA8 2D884000 */  daddu      $17, $2, $0
    /* 3A7AAC 004A7AAC 7100043C */  lui        $4, %hi(D_00714350)
    /* 3A7AB0 004A7AB0 50438424 */  addiu      $4, $4, %lo(D_00714350)
    /* 3A7AB4 004A7AB4 49020524 */  addiu      $5, $0, 0x249
    /* 3A7AB8 004A7AB8 A43A110C */  jal        func_0044ea90
    /* 3A7ABC 004A7ABC 00000000 */   nop
    /* 3A7AC0 004A7AC0 14000424 */  addiu      $4, $0, 0x14
    /* 3A7AC4 004A7AC4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3A7AC8 004A7AC8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3A7ACC 004A7ACC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3A7AD0 004A7AD0 09F84000 */  jalr       $2
    /* 3A7AD4 004A7AD4 00000000 */   nop
    /* 3A7AD8 004A7AD8 2D804000 */  daddu      $16, $2, $0
    /* 3A7ADC 004A7ADC 000040AC */  sw         $0, 0x0($2)
    /* 3A7AE0 004A7AE0 04000426 */  addiu      $4, $16, 0x4
    /* 3A7AE4 004A7AE4 2D282002 */  daddu      $5, $17, $0
    /* 3A7AE8 004A7AE8 10000624 */  addiu      $6, $0, 0x10
    /* 3A7AEC 004A7AEC 04FE100C */  jal        func_0043f810
    /* 3A7AF0 004A7AF0 00000000 */   nop
    /* 3A7AF4 004A7AF4 2D100002 */  daddu      $2, $16, $0
    /* 3A7AF8 004A7AF8 2000BFDF */  ld         $31, 0x20($29)
    /* 3A7AFC 004A7AFC 1000B17B */  lq         $17, 0x10($29)
    /* 3A7B00 004A7B00 0000B07B */  lq         $16, 0x0($29)
    /* 3A7B04 004A7B04 3000BD27 */  addiu      $29, $29, 0x30
    /* 3A7B08 004A7B08 0800E003 */  jr         $31
    /* 3A7B0C 004A7B0C 00000000 */   nop
.size func_004a7a90, 0x80
