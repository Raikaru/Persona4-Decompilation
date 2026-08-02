.section .text
.set noat
.set noreorder
glabel func_001e6a50
    /* E6A50 001E6A50 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E6A54 001E6A54 2000BFFF */  sd         $31, 0x20($29)
    /* E6A58 001E6A58 1000B17F */  sq         $17, 0x10($29)
    /* E6A5C 001E6A5C 0000B07F */  sq         $16, 0x0($29)
    /* E6A60 001E6A60 2D200000 */  daddu      $4, $0, $0
    /* E6A64 001E6A64 00730A0C */  jal        func_0029cc00
    /* E6A68 001E6A68 00000000 */   nop
    /* E6A6C 001E6A6C 2D804000 */  daddu      $16, $2, $0
    /* E6A70 001E6A70 01000424 */  addiu      $4, $0, 0x1
    /* E6A74 001E6A74 00730A0C */  jal        func_0029cc00
    /* E6A78 001E6A78 00000000 */   nop
    /* E6A7C 001E6A7C 2D884000 */  daddu      $17, $2, $0
    /* E6A80 001E6A80 3C211000 */  dsll32     $4, $16, 4
    /* E6A84 001E6A84 3E210400 */  dsrl32     $4, $4, 4
    /* E6A88 001E6A88 30C3060C */  jal        func_001b0cc0
    /* E6A8C 001E6A8C 00000000 */   nop
    /* E6A90 001E6A90 2D804000 */  daddu      $16, $2, $0
    /* E6A94 001E6A94 FFFF3132 */  andi       $17, $17, 0xFFFF
    /* E6A98 001E6A98 4002222A */  slti       $2, $17, 0x240
    /* E6A9C 001E6A9C 06004014 */  bnez       $2, .L001E6AB8
    /* E6AA0 001E6AA0 00000000 */   nop
    /* E6AA4 001E6AA4 6100043C */  lui        $4, %hi(D_006095E0)
    /* E6AA8 001E6AA8 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* E6AAC 001E6AAC 5F040524 */  addiu      $5, $0, 0x45F
    /* E6AB0 001E6AB0 CCB5110C */  jal        func_0046d730
    /* E6AB4 001E6AB4 00000000 */   nop
  .L001E6AB8:
    /* E6AB8 001E6AB8 3000108E */  lw         $16, 0x30($16)
    /* E6ABC 001E6ABC B801212A */  slti       $1, $17, 0x1B8
    /* E6AC0 001E6AC0 1D002010 */  beqz       $1, .L001E6B38
    /* E6AC4 001E6AC4 00000000 */   nop
    /* E6AC8 001E6AC8 640A048E */  lw         $4, 0xA64($16)
    /* E6ACC 001E6ACC 0800023C */  lui        $2, (0x80008 >> 16)
    /* E6AD0 001E6AD0 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* E6AD4 001E6AD4 C4C9080C */  jal        func_00232710
    /* E6AD8 001E6AD8 00000000 */   nop
    /* E6ADC 001E6ADC 04004010 */  beqz       $2, .L001E6AF0
    /* E6AE0 001E6AE0 00000000 */   nop
    /* E6AE4 001E6AE4 2D100000 */  daddu      $2, $0, $0
    /* E6AE8 001E6AE8 1D000010 */  b          .L001E6B60
    /* E6AEC 001E6AEC 00000000 */   nop
  .L001E6AF0:
    /* E6AF0 001E6AF0 640A048E */  lw         $4, 0xA64($16)
    /* E6AF4 001E6AF4 2D282002 */  daddu      $5, $17, $0
    /* E6AF8 001E6AF8 CCC9080C */  jal        func_00232730
    /* E6AFC 001E6AFC 00000000 */   nop
    /* E6B00 001E6B00 04004014 */  bnez       $2, .L001E6B14
    /* E6B04 001E6B04 00000000 */   nop
    /* E6B08 001E6B08 2D100000 */  daddu      $2, $0, $0
    /* E6B0C 001E6B0C 14000010 */  b          .L001E6B60
    /* E6B10 001E6B10 00000000 */   nop
  .L001E6B14:
    /* E6B14 001E6B14 640A048E */  lw         $4, 0xA64($16)
    /* E6B18 001E6B18 2D282002 */  daddu      $5, $17, $0
    /* E6B1C 001E6B1C 70F7080C */  jal        func_0023ddc0
    /* E6B20 001E6B20 00000000 */   nop
    /* E6B24 001E6B24 0D004010 */  beqz       $2, .L001E6B5C
    /* E6B28 001E6B28 00000000 */   nop
    /* E6B2C 001E6B2C 2D100000 */  daddu      $2, $0, $0
    /* E6B30 001E6B30 0B000010 */  b          .L001E6B60
    /* E6B34 001E6B34 00000000 */   nop
  .L001E6B38:
    /* E6B38 001E6B38 640A048E */  lw         $4, 0xA64($16)
    /* E6B3C 001E6B3C 2D282002 */  daddu      $5, $17, $0
    /* E6B40 001E6B40 CCC9080C */  jal        func_00232730
    /* E6B44 001E6B44 00000000 */   nop
    /* E6B48 001E6B48 04004014 */  bnez       $2, .L001E6B5C
    /* E6B4C 001E6B4C 00000000 */   nop
    /* E6B50 001E6B50 2D100000 */  daddu      $2, $0, $0
    /* E6B54 001E6B54 02000010 */  b          .L001E6B60
    /* E6B58 001E6B58 00000000 */   nop
  .L001E6B5C:
    /* E6B5C 001E6B5C 01000224 */  addiu      $2, $0, 0x1
  .L001E6B60:
    /* E6B60 001E6B60 2B200200 */  sltu       $4, $0, $2
    /* E6B64 001E6B64 D4730A0C */  jal        func_0029cf50
    /* E6B68 001E6B68 00000000 */   nop
    /* E6B6C 001E6B6C 01000224 */  addiu      $2, $0, 0x1
    /* E6B70 001E6B70 2000BFDF */  ld         $31, 0x20($29)
    /* E6B74 001E6B74 1000B17B */  lq         $17, 0x10($29)
    /* E6B78 001E6B78 0000B07B */  lq         $16, 0x0($29)
    /* E6B7C 001E6B7C 3000BD27 */  addiu      $29, $29, 0x30
    /* E6B80 001E6B80 0800E003 */  jr         $31
    /* E6B84 001E6B84 00000000 */   nop
    /* E6B88 001E6B88 00000000 */  nop
    /* E6B8C 001E6B8C 00000000 */  nop
.size func_001e6a50, 0x140
