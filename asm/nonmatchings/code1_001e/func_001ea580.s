.section .text
.set noat
.set noreorder
glabel func_001ea580
    /* EA580 001EA580 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA584 001EA584 0000BFFF */  sd         $31, 0x0($29)
    /* EA588 001EA588 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA58C 001EA58C 7001448C */  lw         $4, 0x170($2)
    /* EA590 001EA590 EC80060C */  jal        func_001a03b0
    /* EA594 001EA594 00000000 */   nop
    /* EA598 001EA598 03000424 */  addiu      $4, $0, 0x3
    /* EA59C 001EA59C FF0F0524 */  addiu      $5, $0, 0xFFF
    /* EA5A0 001EA5A0 C04D070C */  jal        func_001d3700
    /* EA5A4 001EA5A4 00000000 */   nop
    /* EA5A8 001EA5A8 2D204000 */  daddu      $4, $2, $0
    /* EA5AC 001EA5AC 2D280000 */  daddu      $5, $0, $0
    /* EA5B0 001EA5B0 6451060C */  jal        func_00194590
    /* EA5B4 001EA5B4 00000000 */   nop
    /* EA5B8 001EA5B8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA5BC 001EA5BC 7001448C */  lw         $4, 0x170($2)
    /* EA5C0 001EA5C0 21000524 */  addiu      $5, $0, 0x21
    /* EA5C4 001EA5C4 48F2060C */  jal        func_001bc920
    /* EA5C8 001EA5C8 00000000 */   nop
    /* EA5CC 001EA5CC 2D204000 */  daddu      $4, $2, $0
    /* EA5D0 001EA5D0 2D280000 */  daddu      $5, $0, $0
    /* EA5D4 001EA5D4 6451060C */  jal        func_00194590
    /* EA5D8 001EA5D8 00000000 */   nop
    /* EA5DC 001EA5DC 01000224 */  addiu      $2, $0, 0x1
    /* EA5E0 001EA5E0 0000BFDF */  ld         $31, 0x0($29)
    /* EA5E4 001EA5E4 1000BD27 */  addiu      $29, $29, 0x10
    /* EA5E8 001EA5E8 0800E003 */  jr         $31
    /* EA5EC 001EA5EC 00000000 */   nop
.size func_001ea580, 0x70
