.section .text
.set noat
.set noreorder
glabel func_0024aa60
    /* 14AA60 0024AA60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 14AA64 0024AA64 1000BFFF */  sd         $31, 0x10($29)
    /* 14AA68 0024AA68 0000B07F */  sq         $16, 0x0($29)
    /* 14AA6C 0024AA6C 2D200000 */  daddu      $4, $0, $0
    /* 14AA70 0024AA70 00730A0C */  jal        func_0029cc00
    /* 14AA74 0024AA74 00000000 */   nop
    /* 14AA78 0024AA78 2D804000 */  daddu      $16, $2, $0
    /* 14AA7C 0024AA7C 01000424 */  addiu      $4, $0, 0x1
    /* 14AA80 0024AA80 00730A0C */  jal        func_0029cc00
    /* 14AA84 0024AA84 00000000 */   nop
    /* 14AA88 0024AA88 04004014 */  bnez       $2, .L0024AA9C
    /* 14AA8C 0024AA8C 00000000 */   nop
    /* 14AA90 0024AA90 8423040C */  jal        func_00108e10
    /* 14AA94 0024AA94 00000000 */   nop
    /* 14AA98 0024AA98 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L0024AA9C:
    /* 14AA9C 0024AA9C FFFF0432 */  andi       $4, $16, 0xFFFF
    /* 14AAA0 0024AAA0 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* 14AAA4 0024AAA4 7821090C */  jal        func_002485e0
    /* 14AAA8 0024AAA8 00000000 */   nop
    /* 14AAAC 0024AAAC 06004010 */  beqz       $2, .L0024AAC8
    /* 14AAB0 0024AAB0 00000000 */   nop
    /* 14AAB4 0024AAB4 01000424 */  addiu      $4, $0, 0x1
    /* 14AAB8 0024AAB8 D4730A0C */  jal        func_0029cf50
    /* 14AABC 0024AABC 00000000 */   nop
    /* 14AAC0 0024AAC0 04000010 */  b          .L0024AAD4
    /* 14AAC4 0024AAC4 00000000 */   nop
  .L0024AAC8:
    /* 14AAC8 0024AAC8 2D200000 */  daddu      $4, $0, $0
    /* 14AACC 0024AACC D4730A0C */  jal        func_0029cf50
    /* 14AAD0 0024AAD0 00000000 */   nop
  .L0024AAD4:
    /* 14AAD4 0024AAD4 01000224 */  addiu      $2, $0, 0x1
    /* 14AAD8 0024AAD8 1000BFDF */  ld         $31, 0x10($29)
    /* 14AADC 0024AADC 0000B07B */  lq         $16, 0x0($29)
    /* 14AAE0 0024AAE0 2000BD27 */  addiu      $29, $29, 0x20
    /* 14AAE4 0024AAE4 0800E003 */  jr         $31
    /* 14AAE8 0024AAE8 00000000 */   nop
    /* 14AAEC 0024AAEC 00000000 */  nop
.size func_0024aa60, 0x90
