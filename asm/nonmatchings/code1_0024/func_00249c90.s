.section .text
.set noat
.set noreorder
glabel func_00249c90
    /* 149C90 00249C90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 149C94 00249C94 0000BFFF */  sd         $31, 0x0($29)
    /* 149C98 00249C98 2D200000 */  daddu      $4, $0, $0
    /* 149C9C 00249C9C 00730A0C */  jal        func_0029cc00
    /* 149CA0 00249CA0 00000000 */   nop
    /* 149CA4 00249CA4 04004014 */  bnez       $2, .L00249CB8
    /* 149CA8 00249CA8 00000000 */   nop
    /* 149CAC 00249CAC 8423040C */  jal        func_00108e10
    /* 149CB0 00249CB0 00000000 */   nop
    /* 149CB4 00249CB4 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L00249CB8:
    /* 149CB8 00249CB8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 149CBC 00249CBC F821040C */  jal        func_001087e0
    /* 149CC0 00249CC0 00000000 */   nop
    /* 149CC4 00249CC4 06004010 */  beqz       $2, .L00249CE0
    /* 149CC8 00249CC8 00000000 */   nop
    /* 149CCC 00249CCC 01000424 */  addiu      $4, $0, 0x1
    /* 149CD0 00249CD0 D4730A0C */  jal        func_0029cf50
    /* 149CD4 00249CD4 00000000 */   nop
    /* 149CD8 00249CD8 04000010 */  b          .L00249CEC
    /* 149CDC 00249CDC 00000000 */   nop
  .L00249CE0:
    /* 149CE0 00249CE0 2D200000 */  daddu      $4, $0, $0
    /* 149CE4 00249CE4 D4730A0C */  jal        func_0029cf50
    /* 149CE8 00249CE8 00000000 */   nop
  .L00249CEC:
    /* 149CEC 00249CEC 01000224 */  addiu      $2, $0, 0x1
    /* 149CF0 00249CF0 0000BFDF */  ld         $31, 0x0($29)
    /* 149CF4 00249CF4 1000BD27 */  addiu      $29, $29, 0x10
    /* 149CF8 00249CF8 0800E003 */  jr         $31
    /* 149CFC 00249CFC 00000000 */   nop
.size func_00249c90, 0x70
