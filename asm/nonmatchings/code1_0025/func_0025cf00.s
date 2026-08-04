.section .text
.set noat
.set noreorder
glabel func_0025cf00
    /* 15CF00 0025CF00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 15CF04 0025CF04 2000BFFF */  sd         $31, 0x20($29)
    /* 15CF08 0025CF08 1000B17F */  sq         $17, 0x10($29)
    /* 15CF0C 0025CF0C 0000B07F */  sq         $16, 0x0($29)
    /* 15CF10 0025CF10 2D200000 */  daddu      $4, $0, $0
    /* 15CF14 0025CF14 00730A0C */  jal        func_0029cc00
    /* 15CF18 0025CF18 00000000 */   nop
    /* 15CF1C 0025CF1C 2D884000 */  daddu      $17, $2, $0
    /* 15CF20 0025CF20 01000424 */  addiu      $4, $0, 0x1
    /* 15CF24 0025CF24 00730A0C */  jal        func_0029cc00
    /* 15CF28 0025CF28 00000000 */   nop
    /* 15CF2C 0025CF2C 2D804000 */  daddu      $16, $2, $0
    /* 15CF30 0025CF30 02000424 */  addiu      $4, $0, 0x2
    /* 15CF34 0025CF34 00730A0C */  jal        func_0029cc00
    /* 15CF38 0025CF38 00000000 */   nop
    /* 15CF3C 0025CF3C FFFF2432 */  andi       $4, $17, 0xFFFF
    /* 15CF40 0025CF40 FFFF0532 */  andi       $5, $16, 0xFFFF
    /* 15CF44 0025CF44 2D304000 */  daddu      $6, $2, $0
    /* 15CF48 0025CF48 6027040C */  jal        func_00109d80
    /* 15CF4C 0025CF4C 00000000 */   nop
    /* 15CF50 0025CF50 01000224 */  addiu      $2, $0, 0x1
    /* 15CF54 0025CF54 2000BFDF */  ld         $31, 0x20($29)
    /* 15CF58 0025CF58 1000B17B */  lq         $17, 0x10($29)
    /* 15CF5C 0025CF5C 0000B07B */  lq         $16, 0x0($29)
    /* 15CF60 0025CF60 3000BD27 */  addiu      $29, $29, 0x30
    /* 15CF64 0025CF64 0800E003 */  jr         $31
    /* 15CF68 0025CF68 00000000 */   nop
    /* 15CF6C 0025CF6C 00000000 */  nop
.size func_0025cf00, 0x70
