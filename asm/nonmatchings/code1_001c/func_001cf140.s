.section .text
.set noat
.set noreorder
glabel func_001cf140
    /* CF140 001CF140 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CF144 001CF144 0000BFFF */  sd         $31, 0x0($29)
    /* CF148 001CF148 ACF7060C */  jal        func_001bdeb0
    /* CF14C 001CF14C 00000000 */   nop
    /* CF150 001CF150 0000BFDF */  ld         $31, 0x0($29)
    /* CF154 001CF154 1000BD27 */  addiu      $29, $29, 0x10
    /* CF158 001CF158 0800E003 */  jr         $31
    /* CF15C 001CF15C 00000000 */   nop
.size func_001cf140, 0x20
