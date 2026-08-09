.section .text
.set noat
.set noreorder
glabel func_001d6ad0
    /* D6AD0 001D6AD0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D6AD4 001D6AD4 4000BFFF */  sd         $31, 0x40($29)
    /* D6AD8 001D6AD8 3000B37F */  sq         $19, 0x30($29)
    /* D6ADC 001D6ADC 2000B27F */  sq         $18, 0x20($29)
    /* D6AE0 001D6AE0 1000B17F */  sq         $17, 0x10($29)
    /* D6AE4 001D6AE4 0000B07F */  sq         $16, 0x0($29)
    /* D6AE8 001D6AE8 6100043C */  lui        $4, %hi(D_00609558)
    /* D6AEC 001D6AEC 58958424 */  addiu      $4, $4, %lo(D_00609558)
    /* D6AF0 001D6AF0 51000524 */  addiu      $5, $0, 0x51
    /* D6AF4 001D6AF4 A43A110C */  jal        func_0044ea90
    /* D6AF8 001D6AF8 00000000 */   nop
    /* D6AFC 001D6AFC 8800103C */  lui        $16, %hi(jtbl_008873E8)
    /* D6B00 001D6B00 E8731026 */  addiu      $16, $16, %lo(jtbl_008873E8)
    /* D6B04 001D6B04 C8000424 */  addiu      $4, $0, 0xC8
    /* D6B08 001D6B08 0400053C */  lui        $5, (0x40000 >> 16)
    /* D6B0C 001D6B0C 0000028E */  lw         $2, 0x0($16)
    /* D6B10 001D6B10 09F84000 */  jalr       $2
    /* D6B14 001D6B14 00000000 */   nop
    /* D6B18 001D6B18 2D984000 */  daddu      $19, $2, $0
    /* D6B1C 001D6B1C 2D206002 */  daddu      $4, $19, $0
    /* D6B20 001D6B20 2D280000 */  daddu      $5, $0, $0
    /* D6B24 001D6B24 C8000624 */  addiu      $6, $0, 0xC8
    /* D6B28 001D6B28 72FE100C */  jal        func_0043f9c8
    /* D6B2C 001D6B2C 00000000 */   nop
    /* D6B30 001D6B30 2D900000 */  daddu      $18, $0, $0
    /* D6B34 001D6B34 2A000010 */  b          .L001D6BE0
    /* D6B38 001D6B38 00000000 */   nop
  .L001D6B3C:
    /* D6B3C 001D6B3C 6100043C */  lui        $4, %hi(D_00609558)
    /* D6B40 001D6B40 58958424 */  addiu      $4, $4, %lo(D_00609558)
    /* D6B44 001D6B44 51000524 */  addiu      $5, $0, 0x51
    /* D6B48 001D6B48 A43A110C */  jal        func_0044ea90
    /* D6B4C 001D6B4C 00000000 */   nop
    /* D6B50 001D6B50 24000424 */  addiu      $4, $0, 0x24
    /* D6B54 001D6B54 0400053C */  lui        $5, (0x40000 >> 16)
    /* D6B58 001D6B58 0000028E */  lw         $2, 0x0($16)
    /* D6B5C 001D6B5C 09F84000 */  jalr       $2
    /* D6B60 001D6B60 00000000 */   nop
    /* D6B64 001D6B64 2D884000 */  daddu      $17, $2, $0
    /* D6B68 001D6B68 2D202002 */  daddu      $4, $17, $0
    /* D6B6C 001D6B6C 2D280000 */  daddu      $5, $0, $0
    /* D6B70 001D6B70 24000624 */  addiu      $6, $0, 0x24
    /* D6B74 001D6B74 72FE100C */  jal        func_0043f9c8
    /* D6B78 001D6B78 00000000 */   nop
    /* D6B7C 001D6B7C FFFF0224 */  addiu      $2, $0, -0x1
    /* D6B80 001D6B80 040022AE */  sw         $2, 0x4($17)
    /* D6B84 001D6B84 14000224 */  addiu      $2, $0, 0x14
    /* D6B88 001D6B88 080022A2 */  sb         $2, 0x8($17)
    /* D6B8C 001D6B8C 0C0020AE */  sw         $0, 0xC($17)
    /* D6B90 001D6B90 00020224 */  addiu      $2, $0, 0x200
    /* D6B94 001D6B94 000022A6 */  sh         $2, 0x0($17)
    /* D6B98 001D6B98 1C0020AE */  sw         $0, 0x1C($17)
    /* D6B9C 001D6B9C ACB3828F */  lw         $2, -0x4C54($28)
    /* D6BA0 001D6BA0 B801428C */  lw         $2, 0x1B8($2)
    /* D6BA4 001D6BA4 07004010 */  beqz       $2, .L001D6BC4
    /* D6BA8 001D6BA8 00000000 */   nop
    /* D6BAC 001D6BAC 1C0051AC */  sw         $17, 0x1C($2)
    /* D6BB0 001D6BB0 ACB3828F */  lw         $2, -0x4C54($28)
    /* D6BB4 001D6BB4 B801428C */  lw         $2, 0x1B8($2)
    /* D6BB8 001D6BB8 200022AE */  sw         $2, 0x20($17)
    /* D6BBC 001D6BBC 02000010 */  b          .L001D6BC8
    /* D6BC0 001D6BC0 00000000 */   nop
  .L001D6BC4:
    /* D6BC4 001D6BC4 200020AE */  sw         $0, 0x20($17)
  .L001D6BC8:
    /* D6BC8 001D6BC8 ACB3828F */  lw         $2, -0x4C54($28)
    /* D6BCC 001D6BCC B80151AC */  sw         $17, 0x1B8($2)
    /* D6BD0 001D6BD0 80101200 */  sll        $2, $18, 2
    /* D6BD4 001D6BD4 21106202 */  addu       $2, $19, $2
    /* D6BD8 001D6BD8 000051AC */  sw         $17, 0x0($2)
    /* D6BDC 001D6BDC 01005226 */  addiu      $18, $18, 0x1
  .L001D6BE0:
    /* D6BE0 001D6BE0 3000422E */  sltiu      $2, $18, 0x30
    /* D6BE4 001D6BE4 D5FF4014 */  bnez       $2, .L001D6B3C
    /* D6BE8 001D6BE8 00000000 */   nop
    /* D6BEC 001D6BEC 2D106002 */  daddu      $2, $19, $0
    /* D6BF0 001D6BF0 4000BFDF */  ld         $31, 0x40($29)
    /* D6BF4 001D6BF4 3000B37B */  lq         $19, 0x30($29)
    /* D6BF8 001D6BF8 2000B27B */  lq         $18, 0x20($29)
    /* D6BFC 001D6BFC 1000B17B */  lq         $17, 0x10($29)
    /* D6C00 001D6C00 0000B07B */  lq         $16, 0x0($29)
    /* D6C04 001D6C04 5000BD27 */  addiu      $29, $29, 0x50
    /* D6C08 001D6C08 0800E003 */  jr         $31
    /* D6C0C 001D6C0C 00000000 */   nop
.size func_001d6ad0, 0x140
