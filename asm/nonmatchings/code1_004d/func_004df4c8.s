.section .text
.set noat
.set noreorder
glabel func_004df4c8
    /* 3DF4C8 004DF4C8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DF4CC 004DF4CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF4D0 004DF4D0 0800B1FF */  sd         $17, 0x8($29)
    /* 3DF4D4 004DF4D4 1000B2FF */  sd         $18, 0x10($29)
    /* 3DF4D8 004DF4D8 1800B3FF */  sd         $19, 0x18($29)
    /* 3DF4DC 004DF4DC 2000B4FF */  sd         $20, 0x20($29)
    /* 3DF4E0 004DF4E0 07008014 */  bnez       $4, .L004DF500
    /* 3DF4E4 004DF4E4 2800BFFF */   sd        $31, 0x28($29)
    /* 3DF4E8 004DF4E8 7600043C */  lui        $4, %hi(D_00759B40)
    /* 3DF4EC 004DF4EC B078130C */  jal        func_004de2c0
    /* 3DF4F0 004DF4F0 409B8424 */   addiu     $4, $4, %lo(D_00759B40)
    /* 3DF4F4 004DF4F4 25000010 */  b          .L004DF58C
    /* 3DF4F8 004DF4F8 FFFF0224 */   addiu     $2, $0, -0x1
    /* 3DF4FC 004DF4FC 00000000 */  nop
  .L004DF500:
    /* 3DF500 004DF500 01008290 */  lbu        $2, 0x1($4)
    /* 3DF504 004DF504 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DF508 004DF508 0300422C */  sltiu      $2, $2, 0x3
    /* 3DF50C 004DF50C 1F004050 */  beql       $2, $0, .L004DF58C
    /* 3DF510 004DF510 2D100000 */   daddu     $2, $0, $0
    /* 3DF514 004DF514 0400928C */  lw         $18, 0x4($4)
    /* 3DF518 004DF518 2D880000 */  daddu      $17, $0, $0
    /* 3DF51C 004DF51C 2DA00000 */  daddu      $20, $0, $0
    /* 3DF520 004DF520 7E81130C */  jal        func_004e05f8
    /* 3DF524 004DF524 2D204002 */   daddu     $4, $18, $0
    /* 3DF528 004DF528 2D984000 */  daddu      $19, $2, $0
    /* 3DF52C 004DF52C 1700601A */  blez       $19, .L004DF58C
    /* 3DF530 004DF530 2D108002 */   daddu     $2, $20, $0
    /* 3DF534 004DF534 00000000 */  nop
  .L004DF538:
    /* 3DF538 004DF538 2D282002 */  daddu      $5, $17, $0
    /* 3DF53C 004DF53C 8081130C */  jal        func_004e0600
    /* 3DF540 004DF540 2D204002 */   daddu     $4, $18, $0
    /* 3DF544 004DF544 2D204002 */  daddu      $4, $18, $0
    /* 3DF548 004DF548 2D282002 */  daddu      $5, $17, $0
    /* 3DF54C 004DF54C 01003126 */  addiu      $17, $17, 0x1
    /* 3DF550 004DF550 8481130C */  jal        func_004e0610
    /* 3DF554 004DF554 2D804000 */   daddu     $16, $2, $0
    /* 3DF558 004DF558 18800202 */  mult       $16, $16, $2
    /* 3DF55C 004DF55C 2A283302 */  slt        $5, $17, $19
    /* 3DF560 004DF560 C0101000 */  sll        $2, $16, 3
    /* 3DF564 004DF564 21105000 */  addu       $2, $2, $16
    /* 3DF568 004DF568 40100200 */  sll        $2, $2, 1
    /* 3DF56C 004DF56C 2D184000 */  daddu      $3, $2, $0
    /* 3DF570 004DF570 1F004424 */  addiu      $4, $2, 0x1F
    /* 3DF574 004DF574 00004228 */  slti       $2, $2, 0x0
    /* 3DF578 004DF578 0B188200 */  movn       $3, $4, $2
    /* 3DF57C 004DF57C 43190300 */  sra        $3, $3, 5
    /* 3DF580 004DF580 EDFFA014 */  bnez       $5, .L004DF538
    /* 3DF584 004DF584 21A08302 */   addu      $20, $20, $3
    /* 3DF588 004DF588 2D108002 */  daddu      $2, $20, $0
  .L004DF58C:
    /* 3DF58C 004DF58C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF590 004DF590 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF594 004DF594 1000B2DF */  ld         $18, 0x10($29)
    /* 3DF598 004DF598 1800B3DF */  ld         $19, 0x18($29)
    /* 3DF59C 004DF59C 2000B4DF */  ld         $20, 0x20($29)
    /* 3DF5A0 004DF5A0 2800BFDF */  ld         $31, 0x28($29)
    /* 3DF5A4 004DF5A4 0800E003 */  jr         $31
    /* 3DF5A8 004DF5A8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DF5AC 004DF5AC 00000000 */  nop
.size func_004df4c8, 0xe8
