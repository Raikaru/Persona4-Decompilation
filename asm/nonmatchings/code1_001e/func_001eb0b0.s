.section .text
.set noat
.set noreorder
glabel func_001eb0b0
    /* EB0B0 001EB0B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EB0B4 001EB0B4 0000BFFF */  sd         $31, 0x0($29)
    /* EB0B8 001EB0B8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EB0BC 001EB0BC 7001448C */  lw         $4, 0x170($2)
    /* EB0C0 001EB0C0 EC80060C */  jal        func_001a03b0
    /* EB0C4 001EB0C4 00000000 */   nop
    /* EB0C8 001EB0C8 03000424 */  addiu      $4, $0, 0x3
    /* EB0CC 001EB0CC FF0F0524 */  addiu      $5, $0, 0xFFF
    /* EB0D0 001EB0D0 C04D070C */  jal        func_001d3700
    /* EB0D4 001EB0D4 00000000 */   nop
    /* EB0D8 001EB0D8 2D204000 */  daddu      $4, $2, $0
    /* EB0DC 001EB0DC 03000324 */  addiu      $3, $0, 0x3
    /* EB0E0 001EB0E0 480043A4 */  sh         $3, 0x48($2)
    /* EB0E4 001EB0E4 2D280000 */  daddu      $5, $0, $0
    /* EB0E8 001EB0E8 6451060C */  jal        func_00194590
    /* EB0EC 001EB0EC 00000000 */   nop
    /* EB0F0 001EB0F0 01000224 */  addiu      $2, $0, 0x1
    /* EB0F4 001EB0F4 0000BFDF */  ld         $31, 0x0($29)
    /* EB0F8 001EB0F8 1000BD27 */  addiu      $29, $29, 0x10
    /* EB0FC 001EB0FC 0800E003 */  jr         $31
    /* EB100 001EB100 00000000 */   nop
    /* EB104 001EB104 00000000 */  nop
    /* EB108 001EB108 00000000 */  nop
    /* EB10C 001EB10C 00000000 */  nop
.size func_001eb0b0, 0x60
