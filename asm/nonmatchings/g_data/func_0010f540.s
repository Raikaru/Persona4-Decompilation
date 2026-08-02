.section .text
.set noat
.set noreorder
glabel func_0010f540
    /* F540 0010F540 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F544 0010F544 0000BFFF */  sd         $31, 0x0($29)
    /* F548 0010F548 90CA080C */  jal        func_00232a40
    /* F54C 0010F54C 00000000 */   nop
    /* F550 0010F550 0000BFDF */  ld         $31, 0x0($29)
    /* F554 0010F554 1000BD27 */  addiu      $29, $29, 0x10
    /* F558 0010F558 0800E003 */  jr         $31
    /* F55C 0010F55C 00000000 */   nop
.size func_0010f540, 0x20
