.section .text
.set noat
.set noreorder
glabel func_004ec278
    /* 3EC278 004EC278 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC27C 004EC27C E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EC280 004EC280 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC284 004EC284 2D488000 */  daddu      $9, $4, $0
    /* 3EC288 004EC288 01000524 */  addiu      $5, $0, 0x1
    /* 3EC28C 004EC28C 1000B0FF */  sd         $16, 0x10($29)
    /* 3EC290 004EC290 1800BFFF */  sd         $31, 0x18($29)
    /* 3EC294 004EC294 05006514 */  bne        $3, $5, .L004EC2AC
    /* 3EC298 004EC298 0200242D */   sltiu     $4, $9, 0x2
    /* 3EC29C 004EC29C 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC2A0 004EC2A0 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC2A4 004EC2A4 12006018 */  blez       $3, .L004EC2F0
    /* 3EC2A8 004EC2A8 1000B0DF */   ld        $16, 0x10($29)
  .L004EC2AC:
    /* 3EC2AC 004EC2AC 10008010 */  beqz       $4, .L004EC2F0
    /* 3EC2B0 004EC2B0 1000B0DF */   ld        $16, 0x10($29)
    /* 3EC2B4 004EC2B4 80100900 */  sll        $2, $9, 2
    /* 3EC2B8 004EC2B8 7400103C */  lui        $16, %hi(D_0073A780)
    /* 3EC2BC 004EC2BC 80A71026 */  addiu      $16, $16, %lo(D_0073A780)
    /* 3EC2C0 004EC2C0 21800202 */  addu       $16, $16, $2
    /* 3EC2C4 004EC2C4 0000038E */  lw         $3, 0x0($16)
    /* 3EC2C8 004EC2C8 08006010 */  beqz       $3, .L004EC2EC
    /* 3EC2CC 004EC2CC 11000424 */   addiu     $4, $0, 0x11
    /* 3EC2D0 004EC2D0 2D28A003 */  daddu      $5, $29, $0
    /* 3EC2D4 004EC2D4 01000624 */  addiu      $6, $0, 0x1
    /* 3EC2D8 004EC2D8 2D380000 */  daddu      $7, $0, $0
    /* 3EC2DC 004EC2DC 2D400000 */  daddu      $8, $0, $0
    /* 3EC2E0 004EC2E0 2896130C */  jal        func_004e58a0
    /* 3EC2E4 004EC2E4 0000A9AF */   sw        $9, 0x0($29)
    /* 3EC2E8 004EC2E8 000000AE */  sw         $0, 0x0($16)
  .L004EC2EC:
    /* 3EC2EC 004EC2EC 1000B0DF */  ld         $16, 0x10($29)
  .L004EC2F0:
    /* 3EC2F0 004EC2F0 1800BFDF */  ld         $31, 0x18($29)
    /* 3EC2F4 004EC2F4 0800E003 */  jr         $31
    /* 3EC2F8 004EC2F8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EC2FC 004EC2FC 00000000 */  nop
.size func_004ec278, 0x88
