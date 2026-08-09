.section .text
.set noat
.set noreorder
glabel func_001ea050
    /* EA050 001EA050 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EA054 001EA054 4000BFFF */  sd         $31, 0x40($29)
    /* EA058 001EA058 3000B37F */  sq         $19, 0x30($29)
    /* EA05C 001EA05C 2000B27F */  sq         $18, 0x20($29)
    /* EA060 001EA060 1000B17F */  sq         $17, 0x10($29)
    /* EA064 001EA064 0000B07F */  sq         $16, 0x0($29)
    /* EA068 001EA068 2D200000 */  daddu      $4, $0, $0
    /* EA06C 001EA06C 00730A0C */  jal        func_0029cc00
    /* EA070 001EA070 00000000 */   nop
    /* EA074 001EA074 2D804000 */  daddu      $16, $2, $0
    /* EA078 001EA078 2D900000 */  daddu      $18, $0, $0
    /* EA07C 001EA07C FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* EA080 001EA080 FFFF5134 */  ori        $17, $2, (0xFFFFFFF & 0xFFFF)
    /* EA084 001EA084 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA088 001EA088 7401538C */  lw         $19, 0x174($2)
    /* EA08C 001EA08C 25000010 */  b          .L001EA124
    /* EA090 001EA090 00000000 */   nop
  .L001EA094:
    /* EA094 001EA094 1A006396 */  lhu        $3, 0x1A($19)
    /* EA098 001EA098 01006230 */  andi       $2, $3, 0x1
    /* EA09C 001EA09C 20004010 */  beqz       $2, .L001EA120
    /* EA0A0 001EA0A0 00000000 */   nop
    /* EA0A4 001EA0A4 08006230 */  andi       $2, $3, 0x8
    /* EA0A8 001EA0A8 1D004010 */  beqz       $2, .L001EA120
    /* EA0AC 001EA0AC 00000000 */   nop
    /* EA0B0 001EA0B0 3000648E */  lw         $4, 0x30($19)
    /* EA0B4 001EA0B4 A2008390 */  lbu        $3, 0xA2($4)
    /* EA0B8 001EA0B8 01000224 */  addiu      $2, $0, 0x1
    /* EA0BC 001EA0BC 18006214 */  bne        $3, $2, .L001EA120
    /* EA0C0 001EA0C0 00000000 */   nop
    /* EA0C4 001EA0C4 640A848C */  lw         $4, 0xA64($4)
    /* EA0C8 001EA0C8 2D280002 */  daddu      $5, $16, $0
    /* EA0CC 001EA0CC C4C9080C */  jal        func_00232710
    /* EA0D0 001EA0D0 00000000 */   nop
    /* EA0D4 001EA0D4 12004010 */  beqz       $2, .L001EA120
    /* EA0D8 001EA0D8 00000000 */   nop
    /* EA0DC 001EA0DC 3000628E */  lw         $2, 0x30($19)
    /* EA0E0 001EA0E0 640A448C */  lw         $4, 0xA64($2)
    /* EA0E4 001EA0E4 2D280000 */  daddu      $5, $0, $0
    /* EA0E8 001EA0E8 3C0A090C */  jal        func_002428f0
    /* EA0EC 001EA0EC 00000000 */   nop
    /* EA0F0 001EA0F0 0B004014 */  bnez       $2, .L001EA120
    /* EA0F4 001EA0F4 00000000 */   nop
    /* EA0F8 001EA0F8 3000628E */  lw         $2, 0x30($19)
    /* EA0FC 001EA0FC 640A448C */  lw         $4, 0xA64($2)
    /* EA100 001EA100 B4C7080C */  jal        func_00231ed0
    /* EA104 001EA104 00000000 */   nop
    /* EA108 001EA108 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* EA10C 001EA10C 2B085100 */  sltu       $1, $2, $17
    /* EA110 001EA110 03002010 */  beqz       $1, .L001EA120
    /* EA114 001EA114 00000000 */   nop
    /* EA118 001EA118 2D906002 */  daddu      $18, $19, $0
    /* EA11C 001EA11C 2D884000 */  daddu      $17, $2, $0
  .L001EA120:
    /* EA120 001EA120 5004738E */  lw         $19, 0x450($19)
  .L001EA124:
    /* EA124 001EA124 DBFF6016 */  bnez       $19, .L001EA094
    /* EA128 001EA128 00000000 */   nop
    /* EA12C 001EA12C 08004012 */  beqz       $18, .L001EA150
    /* EA130 001EA130 00000000 */   nop
    /* EA134 001EA134 0800438E */  lw         $3, 0x8($18)
    /* EA138 001EA138 0080023C */  lui        $2, (0x80000000 >> 16)
    /* EA13C 001EA13C 25206200 */  or         $4, $3, $2
    /* EA140 001EA140 D4730A0C */  jal        func_0029cf50
    /* EA144 001EA144 00000000 */   nop
    /* EA148 001EA148 04000010 */  b          .L001EA15C
    /* EA14C 001EA14C 00000000 */   nop
  .L001EA150:
    /* EA150 001EA150 FFFF0424 */  addiu      $4, $0, -0x1
    /* EA154 001EA154 D4730A0C */  jal        func_0029cf50
    /* EA158 001EA158 00000000 */   nop
  .L001EA15C:
    /* EA15C 001EA15C 01000224 */  addiu      $2, $0, 0x1
    /* EA160 001EA160 4000BFDF */  ld         $31, 0x40($29)
    /* EA164 001EA164 3000B37B */  lq         $19, 0x30($29)
    /* EA168 001EA168 2000B27B */  lq         $18, 0x20($29)
    /* EA16C 001EA16C 1000B17B */  lq         $17, 0x10($29)
    /* EA170 001EA170 0000B07B */  lq         $16, 0x0($29)
    /* EA174 001EA174 5000BD27 */  addiu      $29, $29, 0x50
    /* EA178 001EA178 0800E003 */  jr         $31
    /* EA17C 001EA17C 00000000 */   nop
.size func_001ea050, 0x130
