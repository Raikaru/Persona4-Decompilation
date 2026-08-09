.section .text
.set noat
.set noreorder
glabel func_003bb0d0
    /* 2BB0D0 003BB0D0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2BB0D4 003BB0D4 4000BFFF */  sd         $31, 0x40($29)
    /* 2BB0D8 003BB0D8 3000B37F */  sq         $19, 0x30($29)
    /* 2BB0DC 003BB0DC 2000B27F */  sq         $18, 0x20($29)
    /* 2BB0E0 003BB0E0 1000B17F */  sq         $17, 0x10($29)
    /* 2BB0E4 003BB0E4 0000B07F */  sq         $16, 0x0($29)
    /* 2BB0E8 003BB0E8 54B6828F */  lw         $2, -0x49AC($28)
    /* 2BB0EC 003BB0EC 06004010 */  beqz       $2, .L003BB108
    /* 2BB0F0 003BB0F0 2D888000 */   daddu     $17, $4, $0
  .L003BB0F4:
    /* 2BB0F4 003BB0F4 54B6838F */  lw         $3, -0x49AC($28)
    /* 2BB0F8 003BB0F8 2D102002 */  daddu      $2, $17, $0
    /* 2BB0FC 003BB0FC 01006324 */  addiu      $3, $3, 0x1
    /* 2BB100 003BB100 3B000010 */  b          .L003BB1F0
    /* 2BB104 003BB104 54B683AF */   sw        $3, -0x49AC($28)
  .L003BB108:
    /* 2BB108 003BB108 94E30E0C */  jal        func_003b8e50
    /* 2BB10C 003BB10C 00000000 */   nop
    /* 2BB110 003BB110 1E004010 */  beqz       $2, .L003BB18C
    /* 2BB114 003BB114 00000000 */   nop
    /* 2BB118 003BB118 8800103C */  lui        $16, %hi(D_008864D0)
    /* 2BB11C 003BB11C 04001224 */  addiu      $18, $0, 0x4
    /* 2BB120 003BB120 D0641026 */  addiu      $16, $16, %lo(D_008864D0)
  .L003BB124:
    /* 2BB124 003BB124 2CE40E0C */  jal        func_003b90b0
    /* 2BB128 003BB128 2D204002 */   daddu     $4, $18, $0
    /* 2BB12C 003BB12C 07004014 */  bnez       $2, .L003BB14C
    /* 2BB130 003BB130 000002AE */   sw        $2, 0x0($16)
    /* 2BB134 003BB134 FFFF5026 */  addiu      $16, $18, -0x1
    /* 2BB138 003BB138 0400012A */  slti       $1, $16, 0x4
    /* 2BB13C 003BB13C 1C002010 */  beqz       $1, .L003BB1B0
    /* 2BB140 003BB140 00000000 */   nop
  .L003BB144:
    /* 2BB144 003BB144 06000010 */  b          .L003BB160
    /* 2BB148 003BB148 2D100000 */   daddu     $2, $0, $0
  .L003BB14C:
    /* 2BB14C 003BB14C 01005226 */  addiu      $18, $18, 0x1
    /* 2BB150 003BB150 0B00412A */  slti       $1, $18, 0xB
    /* 2BB154 003BB154 F3FF2014 */  bnez       $1, .L003BB124
    /* 2BB158 003BB158 04001026 */   addiu     $16, $16, 0x4
    /* 2BB15C 003BB15C 01000224 */  addiu      $2, $0, 0x1
  .L003BB160:
    /* 2BB160 003BB160 E4FF4014 */  bnez       $2, .L003BB0F4
    /* 2BB164 003BB164 00000000 */   nop
    /* 2BB168 003BB168 02010224 */  addiu      $2, $0, 0x102
    /* 2BB16C 003BB16C 03000424 */  addiu      $4, $0, 0x3
    /* 2BB170 003BB170 647D0F0C */  jal        func_003df590
    /* 2BB174 003BB174 5000A2AF */   sw        $2, 0x50($29)
    /* 2BB178 003BB178 5400A2AF */  sw         $2, 0x54($29)
    /* 2BB17C 003BB17C 347D0F0C */  jal        func_003df4d0
    /* 2BB180 003BB180 5000A427 */   addiu     $4, $29, 0x50
    /* 2BB184 003BB184 1A000010 */  b          .L003BB1F0
    /* 2BB188 003BB188 2D100000 */   daddu     $2, $0, $0
  .L003BB18C:
    /* 2BB18C 003BB18C 02010224 */  addiu      $2, $0, 0x102
    /* 2BB190 003BB190 03000424 */  addiu      $4, $0, 0x3
    /* 2BB194 003BB194 647D0F0C */  jal        func_003df590
    /* 2BB198 003BB198 5800A2AF */   sw        $2, 0x58($29)
    /* 2BB19C 003BB19C 5C00A2AF */  sw         $2, 0x5C($29)
    /* 2BB1A0 003BB1A0 347D0F0C */  jal        func_003df4d0
    /* 2BB1A4 003BB1A4 5800A427 */   addiu     $4, $29, 0x58
    /* 2BB1A8 003BB1A8 11000010 */  b          .L003BB1F0
    /* 2BB1AC 003BB1AC 2D100000 */   daddu     $2, $0, $0
  .L003BB1B0:
    /* 2BB1B0 003BB1B0 8800023C */  lui        $2, %hi(D_008864C0)
    /* 2BB1B4 003BB1B4 8800123C */  lui        $18, %hi(jtbl_008873EC)
    /* 2BB1B8 003BB1B8 80181000 */  sll        $3, $16, 2
    /* 2BB1BC 003BB1BC C0644224 */  addiu      $2, $2, %lo(D_008864C0)
    /* 2BB1C0 003BB1C0 21984300 */  addu       $19, $2, $3
    /* 2BB1C4 003BB1C4 EC735226 */  addiu      $18, $18, %lo(jtbl_008873EC)
  .L003BB1C8:
    /* 2BB1C8 003BB1C8 0000428E */  lw         $2, 0x0($18)
    /* 2BB1CC 003BB1CC 09F84000 */  jalr       $2
    /* 2BB1D0 003BB1D0 0000648E */   lw        $4, 0x0($19)
    /* 2BB1D4 003BB1D4 FFFF1026 */  addiu      $16, $16, -0x1
    /* 2BB1D8 003BB1D8 000060AE */  sw         $0, 0x0($19)
    /* 2BB1DC 003BB1DC 0400012A */  slti       $1, $16, 0x4
    /* 2BB1E0 003BB1E0 F9FF2010 */  beqz       $1, .L003BB1C8
    /* 2BB1E4 003BB1E4 FCFF7326 */   addiu     $19, $19, -0x4
    /* 2BB1E8 003BB1E8 D6FF0010 */  b          .L003BB144
    /* 2BB1EC 003BB1EC 00000000 */   nop
  .L003BB1F0:
    /* 2BB1F0 003BB1F0 4000BFDF */  ld         $31, 0x40($29)
    /* 2BB1F4 003BB1F4 3000B37B */  lq         $19, 0x30($29)
    /* 2BB1F8 003BB1F8 2000B27B */  lq         $18, 0x20($29)
    /* 2BB1FC 003BB1FC 1000B17B */  lq         $17, 0x10($29)
    /* 2BB200 003BB200 0000B07B */  lq         $16, 0x0($29)
    /* 2BB204 003BB204 0800E003 */  jr         $31
    /* 2BB208 003BB208 6000BD27 */   addiu     $29, $29, 0x60
    /* 2BB20C 003BB20C 00000000 */  nop
.size func_003bb0d0, 0x140
