.section .text
.set noat
.set noreorder
glabel func_0035fc90
    /* 25FC90 0035FC90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 25FC94 0035FC94 4000BFFF */  sd         $31, 0x40($29)
    /* 25FC98 0035FC98 3000B37F */  sq         $19, 0x30($29)
    /* 25FC9C 0035FC9C 2000B27F */  sq         $18, 0x20($29)
    /* 25FCA0 0035FCA0 1000B17F */  sq         $17, 0x10($29)
    /* 25FCA4 0035FCA4 0000B07F */  sq         $16, 0x0($29)
    /* 25FCA8 0035FCA8 2D908000 */  daddu      $18, $4, $0
    /* 25FCAC 0035FCAC 01001024 */  addiu      $16, $0, 0x1
    /* 25FCB0 0035FCB0 20008284 */  lh         $2, 0x20($4)
    /* 25FCB4 0035FCB4 64004128 */  slti       $1, $2, 0x64
    /* 25FCB8 0035FCB8 03002010 */  beqz       $1, .L0035FCC8
    /* 25FCBC 0035FCBC 00000000 */   nop
    /* 25FCC0 0035FCC0 01004224 */  addiu      $2, $2, 0x1
    /* 25FCC4 0035FCC4 200042A6 */  sh         $2, 0x20($18)
  .L0035FCC8:
    /* 25FCC8 0035FCC8 2D880000 */  daddu      $17, $0, $0
    /* 25FCCC 0035FCCC 0F000010 */  b          .L0035FD0C
    /* 25FCD0 0035FCD0 00000000 */   nop
  .L0035FCD4:
    /* 25FCD4 0035FCD4 40101100 */  sll        $2, $17, 1
    /* 25FCD8 0035FCD8 21105100 */  addu       $2, $2, $17
    /* 25FCDC 0035FCDC 00110200 */  sll        $2, $2, 4
    /* 25FCE0 0035FCE0 21984202 */  addu       $19, $18, $2
    /* 25FCE4 0035FCE4 20004586 */  lh         $5, 0x20($18)
    /* 25FCE8 0035FCE8 48006426 */  addiu      $4, $19, 0x48
    /* 25FCEC 0035FCEC 2D300000 */  daddu      $6, $0, $0
    /* 25FCF0 0035FCF0 EC0D050C */  jal        func_001437b0
    /* 25FCF4 0035FCF4 00000000 */   nop
    /* 25FCF8 0035FCF8 62006292 */  lbu        $2, 0x62($19)
    /* 25FCFC 0035FCFC 02004010 */  beqz       $2, .L0035FD08
    /* 25FD00 0035FD00 00000000 */   nop
    /* 25FD04 0035FD04 2D800000 */  daddu      $16, $0, $0
  .L0035FD08:
    /* 25FD08 0035FD08 01003126 */  addiu      $17, $17, 0x1
  .L0035FD0C:
    /* 25FD0C 0035FD0C 1D00222A */  slti       $2, $17, 0x1D
    /* 25FD10 0035FD10 F0FF4014 */  bnez       $2, .L0035FCD4
    /* 25FD14 0035FD14 00000000 */   nop
    /* 25FD18 0035FD18 2D204002 */  daddu      $4, $18, $0
    /* 25FD1C 0035FD1C B8860D0C */  jal        func_00361ae0
    /* 25FD20 0035FD20 00000000 */   nop
    /* 25FD24 0035FD24 2D204002 */  daddu      $4, $18, $0
    /* 25FD28 0035FD28 28870D0C */  jal        func_00361ca0
    /* 25FD2C 0035FD2C 00000000 */   nop
    /* 25FD30 0035FD30 2D204002 */  daddu      $4, $18, $0
    /* 25FD34 0035FD34 587F0D0C */  jal        func_0035fd60
    /* 25FD38 0035FD38 00000000 */   nop
    /* 25FD3C 0035FD3C 2D100002 */  daddu      $2, $16, $0
    /* 25FD40 0035FD40 4000BFDF */  ld         $31, 0x40($29)
    /* 25FD44 0035FD44 3000B37B */  lq         $19, 0x30($29)
    /* 25FD48 0035FD48 2000B27B */  lq         $18, 0x20($29)
    /* 25FD4C 0035FD4C 1000B17B */  lq         $17, 0x10($29)
    /* 25FD50 0035FD50 0000B07B */  lq         $16, 0x0($29)
    /* 25FD54 0035FD54 5000BD27 */  addiu      $29, $29, 0x50
    /* 25FD58 0035FD58 0800E003 */  jr         $31
    /* 25FD5C 0035FD5C 00000000 */   nop
.size func_0035fc90, 0xd0
