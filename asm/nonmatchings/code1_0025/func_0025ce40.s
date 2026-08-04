.section .text
.set noat
.set noreorder
glabel func_0025ce40
    /* 15CE40 0025CE40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15CE44 0025CE44 0000BFFF */  sd         $31, 0x0($29)
    /* 15CE48 0025CE48 2D200000 */  daddu      $4, $0, $0
    /* 15CE4C 0025CE4C 00730A0C */  jal        func_0029cc00
    /* 15CE50 0025CE50 00000000 */   nop
    /* 15CE54 0025CE54 3C240200 */  dsll32     $4, $2, 16
    /* 15CE58 0025CE58 3F240400 */  dsra32     $4, $4, 16
    /* 15CE5C 0025CE5C C413040C */  jal        func_00104f10
    /* 15CE60 0025CE60 00000000 */   nop
    /* 15CE64 0025CE64 3C240200 */  dsll32     $4, $2, 16
    /* 15CE68 0025CE68 3F240400 */  dsra32     $4, $4, 16
    /* 15CE6C 0025CE6C D4730A0C */  jal        func_0029cf50
    /* 15CE70 0025CE70 00000000 */   nop
    /* 15CE74 0025CE74 01000224 */  addiu      $2, $0, 0x1
    /* 15CE78 0025CE78 0000BFDF */  ld         $31, 0x0($29)
    /* 15CE7C 0025CE7C 1000BD27 */  addiu      $29, $29, 0x10
    /* 15CE80 0025CE80 0800E003 */  jr         $31
    /* 15CE84 0025CE84 00000000 */   nop
    /* 15CE88 0025CE88 00000000 */  nop
    /* 15CE8C 0025CE8C 00000000 */  nop
.size func_0025ce40, 0x50
