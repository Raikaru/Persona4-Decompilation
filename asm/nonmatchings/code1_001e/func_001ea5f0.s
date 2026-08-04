.section .text
.set noat
.set noreorder
glabel func_001ea5f0
    /* EA5F0 001EA5F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA5F4 001EA5F4 0000BFFF */  sd         $31, 0x0($29)
    /* EA5F8 001EA5F8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA5FC 001EA5FC 7001448C */  lw         $4, 0x170($2)
    /* EA600 001EA600 EC80060C */  jal        func_001a03b0
    /* EA604 001EA604 00000000 */   nop
    /* EA608 001EA608 03000424 */  addiu      $4, $0, 0x3
    /* EA60C 001EA60C FF0F0524 */  addiu      $5, $0, 0xFFF
    /* EA610 001EA610 C04D070C */  jal        func_001d3700
    /* EA614 001EA614 00000000 */   nop
    /* EA618 001EA618 2D204000 */  daddu      $4, $2, $0
    /* EA61C 001EA61C 2D280000 */  daddu      $5, $0, $0
    /* EA620 001EA620 6451060C */  jal        func_00194590
    /* EA624 001EA624 00000000 */   nop
    /* EA628 001EA628 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA62C 001EA62C 7001448C */  lw         $4, 0x170($2)
    /* EA630 001EA630 2C000524 */  addiu      $5, $0, 0x2C
    /* EA634 001EA634 48F2060C */  jal        func_001bc920
    /* EA638 001EA638 00000000 */   nop
    /* EA63C 001EA63C 2D204000 */  daddu      $4, $2, $0
    /* EA640 001EA640 2D280000 */  daddu      $5, $0, $0
    /* EA644 001EA644 6451060C */  jal        func_00194590
    /* EA648 001EA648 00000000 */   nop
    /* EA64C 001EA64C 01000224 */  addiu      $2, $0, 0x1
    /* EA650 001EA650 0000BFDF */  ld         $31, 0x0($29)
    /* EA654 001EA654 1000BD27 */  addiu      $29, $29, 0x10
    /* EA658 001EA658 0800E003 */  jr         $31
    /* EA65C 001EA65C 00000000 */   nop
.size func_001ea5f0, 0x70
