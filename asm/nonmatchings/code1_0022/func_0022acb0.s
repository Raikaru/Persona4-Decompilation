.section .text
.set noat
.set noreorder
glabel func_0022acb0
    /* 12ACB0 0022ACB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 12ACB4 0022ACB4 1000BFFF */  sd         $31, 0x10($29)
    /* 12ACB8 0022ACB8 0000B07F */  sq         $16, 0x0($29)
    /* 12ACBC 0022ACBC 2D808000 */  daddu      $16, $4, $0
    /* 12ACC0 0022ACC0 ACB3858F */  lw         $5, -0x4C54($28)
    /* 12ACC4 0022ACC4 0C00A38C */  lw         $3, 0xC($5)
    /* 12ACC8 0022ACC8 0800023C */  lui        $2, (0x80000 >> 16)
    /* 12ACCC 0022ACCC 25106200 */  or         $2, $3, $2
    /* 12ACD0 0022ACD0 0C00A2AC */  sw         $2, 0xC($5)
    /* 12ACD4 0022ACD4 2C000524 */  addiu      $5, $0, 0x2C
    /* 12ACD8 0022ACD8 48F2060C */  jal        func_001bc920
    /* 12ACDC 0022ACDC 00000000 */   nop
    /* 12ACE0 0022ACE0 2D204000 */  daddu      $4, $2, $0
    /* 12ACE4 0022ACE4 000003DE */  ld         $3, 0x0($16)
    /* 12ACE8 0022ACE8 600043FC */  sd         $3, 0x60($2)
    /* 12ACEC 0022ACEC 2D280000 */  daddu      $5, $0, $0
    /* 12ACF0 0022ACF0 6451060C */  jal        func_00194590
    /* 12ACF4 0022ACF4 00000000 */   nop
    /* 12ACF8 0022ACF8 3000048E */  lw         $4, 0x30($16)
    /* 12ACFC 0022ACFC AF000524 */  addiu      $5, $0, 0xAF
    /* 12AD00 0022AD00 0009080C */  jal        func_00202400
    /* 12AD04 0022AD04 00000000 */   nop
    /* 12AD08 0022AD08 2D204000 */  daddu      $4, $2, $0
    /* 12AD0C 0022AD0C 000003DE */  ld         $3, 0x0($16)
    /* 12AD10 0022AD10 600043FC */  sd         $3, 0x60($2)
    /* 12AD14 0022AD14 03000524 */  addiu      $5, $0, 0x3
    /* 12AD18 0022AD18 6451060C */  jal        func_00194590
    /* 12AD1C 0022AD1C 00000000 */   nop
    /* 12AD20 0022AD20 1000BFDF */  ld         $31, 0x10($29)
    /* 12AD24 0022AD24 0000B07B */  lq         $16, 0x0($29)
    /* 12AD28 0022AD28 2000BD27 */  addiu      $29, $29, 0x20
    /* 12AD2C 0022AD2C 0800E003 */  jr         $31
    /* 12AD30 0022AD30 00000000 */   nop
    /* 12AD34 0022AD34 00000000 */  nop
    /* 12AD38 0022AD38 00000000 */  nop
    /* 12AD3C 0022AD3C 00000000 */  nop
.size func_0022acb0, 0x90
