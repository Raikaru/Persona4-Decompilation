.section .text
.set noat
.set noreorder
glabel func_001f40a0
    /* F40A0 001F40A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F40A4 001F40A4 0000BFFF */  sd         $31, 0x0($29)
    /* F40A8 001F40A8 02000424 */  addiu      $4, $0, 0x2
    /* F40AC 001F40AC 0800053C */  lui        $5, (0x80000 >> 16)
    /* F40B0 001F40B0 C8BD070C */  jal        func_001ef720
    /* F40B4 001F40B4 00000000 */   nop
    /* F40B8 001F40B8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* F40BC 001F40BC 05006228 */  slti       $2, $3, 0x5
    /* F40C0 001F40C0 04004014 */  bnez       $2, .L001F40D4
    /* F40C4 001F40C4 00000000 */   nop
    /* F40C8 001F40C8 FFFF0224 */  addiu      $2, $0, -0x1
    /* F40CC 001F40CC 08000010 */  b          .L001F40F0
    /* F40D0 001F40D0 00000000 */   nop
  .L001F40D4:
    /* F40D4 001F40D4 04006014 */  bnez       $3, .L001F40E8
    /* F40D8 001F40D8 00000000 */   nop
    /* F40DC 001F40DC FFFF0224 */  addiu      $2, $0, -0x1
    /* F40E0 001F40E0 03000010 */  b          .L001F40F0
    /* F40E4 001F40E4 00000000 */   nop
  .L001F40E8:
    /* F40E8 001F40E8 58000224 */  addiu      $2, $0, 0x58
    /* F40EC 001F40EC 23104300 */  subu       $2, $2, $3
  .L001F40F0:
    /* F40F0 001F40F0 0000BFDF */  ld         $31, 0x0($29)
    /* F40F4 001F40F4 1000BD27 */  addiu      $29, $29, 0x10
    /* F40F8 001F40F8 0800E003 */  jr         $31
    /* F40FC 001F40FC 00000000 */   nop
.size func_001f40a0, 0x60
