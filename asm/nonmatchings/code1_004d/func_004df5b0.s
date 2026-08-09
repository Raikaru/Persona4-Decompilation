.section .text
.set noat
.set noreorder
glabel func_004df5b0
    /* 3DF5B0 004DF5B0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DF5B4 004DF5B4 01000524 */  addiu      $5, $0, 0x1
    /* 3DF5B8 004DF5B8 1000B0FF */  sd         $16, 0x10($29)
    /* 3DF5BC 004DF5BC 2D808000 */  daddu      $16, $4, $0
    /* 3DF5C0 004DF5C0 1800B1FF */  sd         $17, 0x18($29)
    /* 3DF5C4 004DF5C4 2000B2FF */  sd         $18, 0x20($29)
    /* 3DF5C8 004DF5C8 2800BFFF */  sd         $31, 0x28($29)
    /* 3DF5CC 004DF5CC AC01028E */  lw         $2, 0x1AC($16)
    /* 3DF5D0 004DF5D0 04004510 */  beq        $2, $5, .L004DF5E4
    /* 3DF5D4 004DF5D4 02000224 */   addiu     $2, $0, 0x2
    /* 3DF5D8 004DF5D8 01000382 */  lb         $3, 0x1($16)
    /* 3DF5DC 004DF5DC 44006254 */  bnel       $3, $2, .L004DF6F0
    /* 3DF5E0 004DF5E0 1000B0DF */   ld        $16, 0x10($29)
  .L004DF5E4:
    /* 3DF5E4 004DF5E4 BC01028E */  lw         $2, 0x1BC($16)
    /* 3DF5E8 004DF5E8 B0010382 */  lb         $3, 0x1B0($16)
    /* 3DF5EC 004DF5EC 01004424 */  addiu      $4, $2, 0x1
    /* 3DF5F0 004DF5F0 07006514 */  bne        $3, $5, .L004DF610
    /* 3DF5F4 004DF5F4 BC0104AE */   sw        $4, 0x1BC($16)
    /* 3DF5F8 004DF5F8 C801028E */  lw         $2, 0x1C8($16)
    /* 3DF5FC 004DF5FC 2A108200 */  slt        $2, $4, $2
    /* 3DF600 004DF600 04004054 */  bnel       $2, $0, .L004DF614
    /* 3DF604 004DF604 B1011282 */   lb        $18, 0x1B1($16)
    /* 3DF608 004DF608 C401028E */  lw         $2, 0x1C4($16)
    /* 3DF60C 004DF60C BC0102AE */  sw         $2, 0x1BC($16)
  .L004DF610:
    /* 3DF610 004DF610 B1011282 */  lb         $18, 0x1B1($16)
  .L004DF614:
    /* 3DF614 004DF614 01000224 */  addiu      $2, $0, 0x1
    /* 3DF618 004DF618 35004256 */  bnel       $18, $2, .L004DF6F0
    /* 3DF61C 004DF61C 1000B0DF */   ld        $16, 0x10($29)
    /* 3DF620 004DF620 8881130C */  jal        func_004e0620
    /* 3DF624 004DF624 0400048E */   lw        $4, 0x4($16)
    /* 3DF628 004DF628 BC01038E */  lw         $3, 0x1BC($16)
    /* 3DF62C 004DF62C 2A186200 */  slt        $3, $3, $2
    /* 3DF630 004DF630 2F006050 */  beql       $3, $0, .L004DF6F0
    /* 3DF634 004DF634 1000B0DF */   ld        $16, 0x10($29)
    /* 3DF638 004DF638 E080130C */  jal        func_004e0380
    /* 3DF63C 004DF63C 00000000 */   nop
    /* 3DF640 004DF640 BC01118E */  lw         $17, 0x1BC($16)
    /* 3DF644 004DF644 CA81130C */  jal        func_004e0728
    /* 3DF648 004DF648 0400048E */   lw        $4, 0x4($16)
    /* 3DF64C 004DF64C 06004050 */  beql       $2, $0, .L004DF668
    /* 3DF650 004DF650 0400048E */   lw        $4, 0x4($16)
    /* 3DF654 004DF654 1C005250 */  beql       $2, $18, .L004DF6C8
    /* 3DF658 004DF658 0800048E */   lw        $4, 0x8($16)
    /* 3DF65C 004DF65C 21000010 */  b          .L004DF6E4
    /* 3DF660 004DF660 00000000 */   nop
    /* 3DF664 004DF664 00000000 */  nop
  .L004DF668:
    /* 3DF668 004DF668 2D30A003 */  daddu      $6, $29, $0
    /* 3DF66C 004DF66C 0400A727 */  addiu      $7, $29, 0x4
    /* 3DF670 004DF670 9681130C */  jal        func_004e0658
    /* 3DF674 004DF674 2D282002 */   daddu     $5, $17, $0
    /* 3DF678 004DF678 0800048E */  lw         $4, 0x8($16)
    /* 3DF67C 004DF67C 0000A58F */  lw         $5, 0x0($29)
    /* 3DF680 004DF680 FF07A324 */  addiu      $3, $5, 0x7FF
    /* 3DF684 004DF684 0000A228 */  slti       $2, $5, 0x0
    /* 3DF688 004DF688 0B286200 */  movn       $5, $3, $2
    /* 3DF68C 004DF68C 0E48130C */  jal        func_004d2038
    /* 3DF690 004DF690 C32A0500 */   sra       $5, $5, 11
    /* 3DF694 004DF694 0800048E */  lw         $4, 0x8($16)
    /* 3DF698 004DF698 0400A28F */  lw         $2, 0x4($29)
    /* 3DF69C 004DF69C 0000A58F */  lw         $5, 0x0($29)
    /* 3DF6A0 004DF6A0 2128A200 */  addu       $5, $5, $2
    /* 3DF6A4 004DF6A4 FF07A324 */  addiu      $3, $5, 0x7FF
    /* 3DF6A8 004DF6A8 0000A228 */  slti       $2, $5, 0x0
    /* 3DF6AC 004DF6AC 0B286200 */  movn       $5, $3, $2
    /* 3DF6B0 004DF6B0 EA48130C */  jal        func_004d23a8
    /* 3DF6B4 004DF6B4 C32A0500 */   sra       $5, $5, 11
    /* 3DF6B8 004DF6B8 4A48130C */  jal        func_004d2128
    /* 3DF6BC 004DF6BC 0800048E */   lw        $4, 0x8($16)
    /* 3DF6C0 004DF6C0 08000010 */  b          .L004DF6E4
    /* 3DF6C4 004DF6C4 00000000 */   nop
  .L004DF6C8:
    /* 3DF6C8 004DF6C8 0E48130C */  jal        func_004d2038
    /* 3DF6CC 004DF6CC 2D280000 */   daddu     $5, $0, $0
    /* 3DF6D0 004DF6D0 0800048E */  lw         $4, 0x8($16)
    /* 3DF6D4 004DF6D4 EA48130C */  jal        func_004d23a8
    /* 3DF6D8 004DF6D8 FFFF0524 */   addiu     $5, $0, -0x1
    /* 3DF6DC 004DF6DC 4A48130C */  jal        func_004d2128
    /* 3DF6E0 004DF6E0 0800048E */   lw        $4, 0x8($16)
  .L004DF6E4:
    /* 3DF6E4 004DF6E4 E680130C */  jal        func_004e0398
    /* 3DF6E8 004DF6E8 00000000 */   nop
    /* 3DF6EC 004DF6EC 1000B0DF */  ld         $16, 0x10($29)
  .L004DF6F0:
    /* 3DF6F0 004DF6F0 1800B1DF */  ld         $17, 0x18($29)
    /* 3DF6F4 004DF6F4 2000B2DF */  ld         $18, 0x20($29)
    /* 3DF6F8 004DF6F8 2800BFDF */  ld         $31, 0x28($29)
    /* 3DF6FC 004DF6FC 0800E003 */  jr         $31
    /* 3DF700 004DF700 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DF704 004DF704 00000000 */  nop
.size func_004df5b0, 0x158
