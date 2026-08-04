.section .text
.set noat
.set noreorder
glabel func_0025ce90
    /* 15CE90 0025CE90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 15CE94 0025CE94 2000BFFF */  sd         $31, 0x20($29)
    /* 15CE98 0025CE98 1000B17F */  sq         $17, 0x10($29)
    /* 15CE9C 0025CE9C 0000B07F */  sq         $16, 0x0($29)
    /* 15CEA0 0025CEA0 2D200000 */  daddu      $4, $0, $0
    /* 15CEA4 0025CEA4 00730A0C */  jal        func_0029cc00
    /* 15CEA8 0025CEA8 00000000 */   nop
    /* 15CEAC 0025CEAC 2D884000 */  daddu      $17, $2, $0
    /* 15CEB0 0025CEB0 01000424 */  addiu      $4, $0, 0x1
    /* 15CEB4 0025CEB4 00730A0C */  jal        func_0029cc00
    /* 15CEB8 0025CEB8 00000000 */   nop
    /* 15CEBC 0025CEBC 2D804000 */  daddu      $16, $2, $0
    /* 15CEC0 0025CEC0 02000424 */  addiu      $4, $0, 0x2
    /* 15CEC4 0025CEC4 00730A0C */  jal        func_0029cc00
    /* 15CEC8 0025CEC8 00000000 */   nop
    /* 15CECC 0025CECC FFFF2432 */  andi       $4, $17, 0xFFFF
    /* 15CED0 0025CED0 FFFF0532 */  andi       $5, $16, 0xFFFF
    /* 15CED4 0025CED4 3C360200 */  dsll32     $6, $2, 24
    /* 15CED8 0025CED8 3F360600 */  dsra32     $6, $6, 24
    /* 15CEDC 0025CEDC 102A040C */  jal        func_0010a840
    /* 15CEE0 0025CEE0 00000000 */   nop
    /* 15CEE4 0025CEE4 01000224 */  addiu      $2, $0, 0x1
    /* 15CEE8 0025CEE8 2000BFDF */  ld         $31, 0x20($29)
    /* 15CEEC 0025CEEC 1000B17B */  lq         $17, 0x10($29)
    /* 15CEF0 0025CEF0 0000B07B */  lq         $16, 0x0($29)
    /* 15CEF4 0025CEF4 3000BD27 */  addiu      $29, $29, 0x30
    /* 15CEF8 0025CEF8 0800E003 */  jr         $31
    /* 15CEFC 0025CEFC 00000000 */   nop
.size func_0025ce90, 0x70
