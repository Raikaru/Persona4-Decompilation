.section .text
.set noat
.set noreorder
glabel func_003ce050
    /* 2CE050 003CE050 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2CE054 003CE054 6000BFFF */  sd         $31, 0x60($29)
    /* 2CE058 003CE058 5000B57F */  sq         $21, 0x50($29)
    /* 2CE05C 003CE05C 4000B47F */  sq         $20, 0x40($29)
    /* 2CE060 003CE060 2DA88000 */  daddu      $21, $4, $0
    /* 2CE064 003CE064 3000B37F */  sq         $19, 0x30($29)
    /* 2CE068 003CE068 2000B27F */  sq         $18, 0x20($29)
    /* 2CE06C 003CE06C 1000B17F */  sq         $17, 0x10($29)
    /* 2CE070 003CE070 0000B07F */  sq         $16, 0x0($29)
    /* 2CE074 003CE074 0000918C */  lw         $17, 0x0($4)
    /* 2CE078 003CE078 20002012 */  beqz       $17, .L003CE0FC
    /* 2CE07C 003CE07C 2DA0A000 */   daddu     $20, $5, $0
    /* 2CE080 003CE080 0000228E */  lw         $2, 0x0($17)
    /* 2CE084 003CE084 18004010 */  beqz       $2, .L003CE0E8
    /* 2CE088 003CE088 FFFF5324 */   addiu     $19, $2, -0x1
    /* 2CE08C 003CE08C 80101300 */  sll        $2, $19, 2
    /* 2CE090 003CE090 21902202 */  addu       $18, $17, $2
  .L003CE094:
    /* 2CE094 003CE094 0400508E */  lw         $16, 0x4($18)
    /* 2CE098 003CE098 0F000012 */  beqz       $16, .L003CE0D8
    /* 2CE09C 003CE09C 00000000 */   nop
    /* 2CE0A0 003CE0A0 0000028E */  lw         $2, 0x0($16)
    /* 2CE0A4 003CE0A4 04004010 */  beqz       $2, .L003CE0B8
    /* 2CE0A8 003CE0A8 00000000 */   nop
    /* 2CE0AC 003CE0AC 00000000 */  nop
  .L003CE0B0:
    /* 2CE0B0 003CE0B0 09000010 */  b          .L003CE0D8
    /* 2CE0B4 003CE0B4 100000AE */   sw        $0, 0x10($16)
  .L003CE0B8:
    /* 2CE0B8 003CE0B8 0400028E */  lw         $2, 0x4($16)
    /* 2CE0BC 003CE0BC FCFF4014 */  bnez       $2, .L003CE0B0
    /* 2CE0C0 003CE0C0 00000000 */   nop
    /* 2CE0C4 003CE0C4 B8310F0C */  jal        func_003cc6e0
    /* 2CE0C8 003CE0C8 2D200002 */   daddu     $4, $16, $0
    /* 2CE0CC 003CE0CC A8870F0C */  jal        func_003e1ea0
    /* 2CE0D0 003CE0D0 2D200002 */   daddu     $4, $16, $0
    /* 2CE0D4 003CE0D4 00000000 */  nop
  .L003CE0D8:
    /* 2CE0D8 003CE0D8 2D106002 */  daddu      $2, $19, $0
    /* 2CE0DC 003CE0DC FCFF5226 */  addiu      $18, $18, -0x4
    /* 2CE0E0 003CE0E0 ECFF4014 */  bnez       $2, .L003CE094
    /* 2CE0E4 003CE0E4 FFFF7326 */   addiu     $19, $19, -0x1
  .L003CE0E8:
    /* 2CE0E8 003CE0E8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2CE0EC 003CE0EC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2CE0F0 003CE0F0 09F84000 */  jalr       $2
    /* 2CE0F4 003CE0F4 2D202002 */   daddu     $4, $17, $0
    /* 2CE0F8 003CE0F8 0000A0AE */  sw         $0, 0x0($21)
  .L003CE0FC:
    /* 2CE0FC 003CE0FC 0300023C */  lui        $2, (0x3050D >> 16)
    /* 2CE100 003CE100 FFFF8326 */  addiu      $3, $20, -0x1
    /* 2CE104 003CE104 0D054534 */  ori        $5, $2, (0x3050D & 0xFFFF)
    /* 2CE108 003CE108 80180300 */  sll        $3, $3, 2
    /* 2CE10C 003CE10C 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2CE110 003CE110 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2CE114 003CE114 09F84000 */  jalr       $2
    /* 2CE118 003CE118 08006424 */   addiu     $4, $3, 0x8
    /* 2CE11C 003CE11C 0000A2AE */  sw         $2, 0x0($21)
    /* 2CE120 003CE120 0000A28E */  lw         $2, 0x0($21)
    /* 2CE124 003CE124 07004010 */  beqz       $2, .L003CE144
    /* 2CE128 003CE128 00000000 */   nop
    /* 2CE12C 003CE12C 000054AC */  sw         $20, 0x0($2)
    /* 2CE130 003CE130 80301400 */  sll        $6, $20, 2
    /* 2CE134 003CE134 0000A28E */  lw         $2, 0x0($21)
    /* 2CE138 003CE138 2D280000 */  daddu      $5, $0, $0
    /* 2CE13C 003CE13C 72FE100C */  jal        func_0043f9c8
    /* 2CE140 003CE140 04004424 */   addiu     $4, $2, 0x4
  .L003CE144:
    /* 2CE144 003CE144 2D10A002 */  daddu      $2, $21, $0
    /* 2CE148 003CE148 6000BFDF */  ld         $31, 0x60($29)
    /* 2CE14C 003CE14C 5000B57B */  lq         $21, 0x50($29)
    /* 2CE150 003CE150 4000B47B */  lq         $20, 0x40($29)
    /* 2CE154 003CE154 3000B37B */  lq         $19, 0x30($29)
    /* 2CE158 003CE158 2000B27B */  lq         $18, 0x20($29)
    /* 2CE15C 003CE15C 1000B17B */  lq         $17, 0x10($29)
    /* 2CE160 003CE160 0000B07B */  lq         $16, 0x0($29)
    /* 2CE164 003CE164 0800E003 */  jr         $31
    /* 2CE168 003CE168 7000BD27 */   addiu     $29, $29, 0x70
    /* 2CE16C 003CE16C 00000000 */  nop
.size func_003ce050, 0x120
