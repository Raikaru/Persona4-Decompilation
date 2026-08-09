.section .text
.set noat
.set noreorder
glabel func_003ee470
    /* 2EE470 003EE470 F0F8BD27 */  addiu      $29, $29, -0x710
    /* 2EE474 003EE474 00010624 */  addiu      $6, $0, 0x100
    /* 2EE478 003EE478 9000BFFF */  sd         $31, 0x90($29)
    /* 2EE47C 003EE47C 8000BE7F */  sq         $30, 0x80($29)
    /* 2EE480 003EE480 7000B77F */  sq         $23, 0x70($29)
    /* 2EE484 003EE484 6000B67F */  sq         $22, 0x60($29)
    /* 2EE488 003EE488 8800173C */  lui        $23, %hi(D_008873B0)
    /* 2EE48C 003EE48C 5000B57F */  sq         $21, 0x50($29)
    /* 2EE490 003EE490 B073F726 */  addiu      $23, $23, %lo(D_008873B0)
    /* 2EE494 003EE494 4000B47F */  sq         $20, 0x40($29)
    /* 2EE498 003EE498 3000B37F */  sq         $19, 0x30($29)
    /* 2EE49C 003EE49C 2DA08000 */  daddu      $20, $4, $0
    /* 2EE4A0 003EE4A0 2000B27F */  sq         $18, 0x20($29)
    /* 2EE4A4 003EE4A4 2D98A000 */  daddu      $19, $5, $0
    /* 2EE4A8 003EE4A8 1000B17F */  sq         $17, 0x10($29)
    /* 2EE4AC 003EE4AC A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EE4B0 003EE4B0 0000B07F */  sq         $16, 0x0($29)
    /* 2EE4B4 003EE4B4 0000E28E */  lw         $2, 0x0($23)
    /* 2EE4B8 003EE4B8 09F84000 */  jalr       $2
    /* 2EE4BC 003EE4BC 2D288002 */   daddu     $5, $20, $0
    /* 2EE4C0 003EE4C0 88001E3C */  lui        $30, %hi(D_008873D4)
    /* 2EE4C4 003EE4C4 D473DE27 */  addiu      $30, $30, %lo(D_008873D4)
    /* 2EE4C8 003EE4C8 0000C28F */  lw         $2, 0x0($30)
    /* 2EE4CC 003EE4CC 09F84000 */  jalr       $2
    /* 2EE4D0 003EE4D0 2D208002 */   daddu     $4, $20, $0
    /* 2EE4D4 003EE4D4 0001412C */  sltiu      $1, $2, 0x100
    /* 2EE4D8 003EE4D8 98002010 */  beqz       $1, .L003EE73C
    /* 2EE4DC 003EE4DC 00000000 */   nop
  .L003EE4E0:
    /* 2EE4E0 003EE4E0 1C006012 */  beqz       $19, .L003EE554
    /* 2EE4E4 003EE4E4 A000A0A3 */   sb        $0, 0xA0($29)
    /* 2EE4E8 003EE4E8 00006282 */  lb         $2, 0x0($19)
    /* 2EE4EC 003EE4EC 19004010 */  beqz       $2, .L003EE554
    /* 2EE4F0 003EE4F0 00000000 */   nop
    /* 2EE4F4 003EE4F4 0000E28E */  lw         $2, 0x0($23)
    /* 2EE4F8 003EE4F8 A000A427 */  addiu      $4, $29, 0xA0
    /* 2EE4FC 003EE4FC 2D286002 */  daddu      $5, $19, $0
    /* 2EE500 003EE500 09F84000 */  jalr       $2
    /* 2EE504 003EE504 00010624 */   addiu     $6, $0, 0x100
    /* 2EE508 003EE508 0000C28F */  lw         $2, 0x0($30)
    /* 2EE50C 003EE50C 09F84000 */  jalr       $2
    /* 2EE510 003EE510 2D206002 */   daddu     $4, $19, $0
    /* 2EE514 003EE514 0001422C */  sltiu      $2, $2, 0x100
    /* 2EE518 003EE518 0E004014 */  bnez       $2, .L003EE554
    /* 2EE51C 003EE51C 00000000 */   nop
    /* 2EE520 003EE520 FF006882 */  lb         $8, 0xFF($19)
    /* 2EE524 003EE524 01000224 */  addiu      $2, $0, 0x1
    /* 2EE528 003EE528 F006A2AF */  sw         $2, 0x6F0($29)
    /* 2EE52C 003EE52C 2D286002 */  daddu      $5, $19, $0
    /* 2EE530 003EE530 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE534 003EE534 00010624 */  addiu      $6, $0, 0x100
    /* 2EE538 003EE538 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE53C 003EE53C 647D0F0C */  jal        func_003df590
    /* 2EE540 003EE540 FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE544 003EE544 F406A2AF */  sw         $2, 0x6F4($29)
    /* 2EE548 003EE548 347D0F0C */  jal        func_003df4d0
    /* 2EE54C 003EE54C F006A427 */   addiu     $4, $29, 0x6F0
    /* 2EE550 003EE550 9F01A0A3 */  sb         $0, 0x19F($29)
  .L003EE554:
    /* 2EE554 003EE554 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EE558 003EE558 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EE55C 003EE55C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EE560 003EE560 21184300 */  addu       $3, $2, $3
    /* 2EE564 003EE564 1C00628C */  lw         $2, 0x1C($3)
    /* 2EE568 003EE568 05004010 */  beqz       $2, .L003EE580
    /* 2EE56C 003EE56C 04001624 */   addiu     $22, $0, 0x4
    /* 2EE570 003EE570 2000628C */  lw         $2, 0x20($3)
    /* 2EE574 003EE574 02004010 */  beqz       $2, .L003EE580
    /* 2EE578 003EE578 0080D636 */   ori       $22, $22, 0x8000
    /* 2EE57C 003EE57C 0010D636 */  ori        $22, $22, 0x1000
  .L003EE580:
    /* 2EE580 003EE580 A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EE584 003EE584 A000A527 */  addiu      $5, $29, 0xA0
    /* 2EE588 003EE588 2D300000 */  daddu      $6, $0, $0
    /* 2EE58C 003EE58C BCBD0F0C */  jal        func_003ef6f0
    /* 2EE590 003EE590 2D38C002 */   daddu     $7, $22, $0
    /* 2EE594 003EE594 A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EE598 003EE598 A000A527 */  addiu      $5, $29, 0xA0
    /* 2EE59C 003EE59C 2D30C002 */  daddu      $6, $22, $0
    /* 2EE5A0 003EE5A0 0C07A727 */  addiu      $7, $29, 0x70C
    /* 2EE5A4 003EE5A4 0807A827 */  addiu      $8, $29, 0x708
    /* 2EE5A8 003EE5A8 0407A927 */  addiu      $9, $29, 0x704
    /* 2EE5AC 003EE5AC 0007AA27 */  addiu      $10, $29, 0x700
    /* 2EE5B0 003EE5B0 0C07A0AF */  sw         $0, 0x70C($29)
    /* 2EE5B4 003EE5B4 94B70F0C */  jal        func_003ede50
    /* 2EE5B8 003EE5B8 0807A0AF */   sw        $0, 0x708($29)
    /* 2EE5BC 003EE5BC 6D004010 */  beqz       $2, .L003EE774
    /* 2EE5C0 003EE5C0 A006A2AF */   sw        $2, 0x6A0($29)
    /* 2EE5C4 003EE5C4 0807A58F */  lw         $5, 0x708($29)
    /* 2EE5C8 003EE5C8 0407A68F */  lw         $6, 0x704($29)
    /* 2EE5CC 003EE5CC 0007A78F */  lw         $7, 0x700($29)
    /* 2EE5D0 003EE5D0 64B10F0C */  jal        func_003ec590
    /* 2EE5D4 003EE5D4 0C07A48F */   lw        $4, 0x70C($29)
    /* 2EE5D8 003EE5D8 2D904000 */  daddu      $18, $2, $0
    /* 2EE5DC 003EE5DC 67004012 */  beqz       $18, .L003EE77C
    /* 2EE5E0 003EE5E0 00000000 */   nop
    /* 2EE5E4 003EE5E4 0007A38F */  lw         $3, 0x700($29)
    /* 2EE5E8 003EE5E8 00806230 */  andi       $2, $3, 0x8000
    /* 2EE5EC 003EE5EC 02014010 */  beqz       $2, .L003EE9F8
    /* 2EE5F0 003EE5F0 00000000 */   nop
    /* 2EE5F4 003EE5F4 00106230 */  andi       $2, $3, 0x1000
    /* 2EE5F8 003EE5F8 0A004010 */  beqz       $2, .L003EE624
    /* 2EE5FC 003EE5FC 00000000 */   nop
    /* 2EE600 003EE600 A006A58F */  lw         $5, 0x6A0($29)
    /* 2EE604 003EE604 60B00F0C */  jal        func_003ec180
    /* 2EE608 003EE608 2D204002 */   daddu     $4, $18, $0
    /* 2EE60C 003EE60C 5F004010 */  beqz       $2, .L003EE78C
    /* 2EE610 003EE610 00000000 */   nop
    /* 2EE614 003EE614 DCA80F0C */  jal        func_003ea370
    /* 2EE618 003EE618 A006A48F */   lw        $4, 0x6A0($29)
    /* 2EE61C 003EE61C 38000010 */  b          .L003EE700
    /* 2EE620 003EE620 00000000 */   nop
  .L003EE624:
    /* 2EE624 003EE624 08B10F0C */  jal        func_003ec420
    /* 2EE628 003EE628 2D204002 */   daddu     $4, $18, $0
    /* 2EE62C 003EE62C 2D884000 */  daddu      $17, $2, $0
    /* 2EE630 003EE630 0200212A */  slti       $1, $17, 0x2
    /* 2EE634 003EE634 5B002010 */  beqz       $1, .L003EE7A4
    /* 2EE638 003EE638 01001024 */   addiu     $16, $0, 0x1
    /* 2EE63C 003EE63C 23004292 */  lbu        $2, 0x23($18)
  .L003EE640:
    /* 2EE640 003EE640 001A0200 */  sll        $3, $2, 8
    /* 2EE644 003EE644 00606230 */  andi       $2, $3, 0x6000
    /* 2EE648 003EE648 CD004010 */  beqz       $2, .L003EE980
    /* 2EE64C 003EE64C 00000000 */   nop
    /* 2EE650 003EE650 00406230 */  andi       $2, $3, 0x4000
    /* 2EE654 003EE654 09004010 */  beqz       $2, .L003EE67C
    /* 2EE658 003EE658 00000000 */   nop
    /* 2EE65C 003EE65C A002A427 */  addiu      $4, $29, 0x2A0
    /* 2EE660 003EE660 2D280000 */  daddu      $5, $0, $0
    /* 2EE664 003EE664 A006A627 */  addiu      $6, $29, 0x6A0
    /* 2EE668 003EE668 2D382002 */  daddu      $7, $17, $0
    /* 2EE66C 003EE66C 0CB70F0C */  jal        func_003edc30
    /* 2EE670 003EE670 04000824 */   addiu     $8, $0, 0x4
    /* 2EE674 003EE674 08000010 */  b          .L003EE698
    /* 2EE678 003EE678 A006A48F */   lw        $4, 0x6A0($29)
  .L003EE67C:
    /* 2EE67C 003EE67C A002A427 */  addiu      $4, $29, 0x2A0
    /* 2EE680 003EE680 2D280000 */  daddu      $5, $0, $0
    /* 2EE684 003EE684 A006A627 */  addiu      $6, $29, 0x6A0
    /* 2EE688 003EE688 2D382002 */  daddu      $7, $17, $0
    /* 2EE68C 003EE68C 0CB70F0C */  jal        func_003edc30
    /* 2EE690 003EE690 08000824 */   addiu     $8, $0, 0x8
    /* 2EE694 003EE694 A006A48F */  lw         $4, 0x6A0($29)
  .L003EE698:
    /* 2EE698 003EE698 78AF0F0C */  jal        func_003ebde0
    /* 2EE69C 003EE69C 00000000 */   nop
  .L003EE6A0:
    /* 2EE6A0 003EE6A0 2A081100 */  slt        $1, $0, $17
  .L003EE6A4:
    /* 2EE6A4 003EE6A4 16002010 */  beqz       $1, .L003EE700
    /* 2EE6A8 003EE6A8 2D800000 */   daddu     $16, $0, $0
    /* 2EE6AC 003EE6AC A006B527 */  addiu      $21, $29, 0x6A0
  .L003EE6B0:
    /* 2EE6B0 003EE6B0 FF000532 */  andi       $5, $16, 0xFF
    /* 2EE6B4 003EE6B4 2D204002 */  daddu      $4, $18, $0
    /* 2EE6B8 003EE6B8 A8B10F0C */  jal        func_003ec6a0
    /* 2EE6BC 003EE6BC 05000624 */   addiu     $6, $0, 0x5
    /* 2EE6C0 003EE6C0 09004010 */  beqz       $2, .L003EE6E8
    /* 2EE6C4 003EE6C4 00000000 */   nop
    /* 2EE6C8 003EE6C8 0000A58E */  lw         $5, 0x0($21)
    /* 2EE6CC 003EE6CC 60B00F0C */  jal        func_003ec180
    /* 2EE6D0 003EE6D0 2D204002 */   daddu     $4, $18, $0
    /* 2EE6D4 003EE6D4 B7004010 */  beqz       $2, .L003EE9B4
    /* 2EE6D8 003EE6D8 00000000 */   nop
    /* 2EE6DC 003EE6DC A8B00F0C */  jal        func_003ec2a0
    /* 2EE6E0 003EE6E0 2D204002 */   daddu     $4, $18, $0
    /* 2EE6E4 003EE6E4 00000000 */  nop
  .L003EE6E8:
    /* 2EE6E8 003EE6E8 DCA80F0C */  jal        func_003ea370
    /* 2EE6EC 003EE6EC 0000A48E */   lw        $4, 0x0($21)
    /* 2EE6F0 003EE6F0 01001026 */  addiu      $16, $16, 0x1
    /* 2EE6F4 003EE6F4 2A101102 */  slt        $2, $16, $17
    /* 2EE6F8 003EE6F8 EDFF4014 */  bnez       $2, .L003EE6B0
    /* 2EE6FC 003EE6FC 0400B526 */   addiu     $21, $21, 0x4
  .L003EE700:
    /* 2EE700 003EE700 B8BC0F0C */  jal        func_003ef2e0
    /* 2EE704 003EE704 2D204002 */   daddu     $4, $18, $0
    /* 2EE708 003EE708 2D804000 */  daddu      $16, $2, $0
    /* 2EE70C 003EE70C CB000012 */  beqz       $16, .L003EEA3C
    /* 2EE710 003EE710 00000000 */   nop
    /* 2EE714 003EE714 2D288002 */  daddu      $5, $20, $0
    /* 2EE718 003EE718 1CBD0F0C */  jal        func_003ef470
    /* 2EE71C 003EE71C 2D200002 */   daddu     $4, $16, $0
    /* 2EE720 003EE720 CA006012 */  beqz       $19, .L003EEA4C
    /* 2EE724 003EE724 00000000 */   nop
    /* 2EE728 003EE728 2D286002 */  daddu      $5, $19, $0
    /* 2EE72C 003EE72C 44BD0F0C */  jal        func_003ef510
    /* 2EE730 003EE730 2D200002 */   daddu     $4, $16, $0
  .L003EE734:
    /* 2EE734 003EE734 CA000010 */  b          .L003EEA60
    /* 2EE738 003EE738 2D100002 */   daddu     $2, $16, $0
  .L003EE73C:
    /* 2EE73C 003EE73C FF008882 */  lb         $8, 0xFF($20)
    /* 2EE740 003EE740 01000224 */  addiu      $2, $0, 0x1
    /* 2EE744 003EE744 F806A2AF */  sw         $2, 0x6F8($29)
    /* 2EE748 003EE748 2D288002 */  daddu      $5, $20, $0
    /* 2EE74C 003EE74C 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE750 003EE750 00010624 */  addiu      $6, $0, 0x100
    /* 2EE754 003EE754 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE758 003EE758 647D0F0C */  jal        func_003df590
    /* 2EE75C 003EE75C FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE760 003EE760 FC06A2AF */  sw         $2, 0x6FC($29)
    /* 2EE764 003EE764 347D0F0C */  jal        func_003df4d0
    /* 2EE768 003EE768 F806A427 */   addiu     $4, $29, 0x6F8
    /* 2EE76C 003EE76C 5CFF0010 */  b          .L003EE4E0
    /* 2EE770 003EE770 9F02A0A3 */   sb        $0, 0x29F($29)
  .L003EE774:
    /* 2EE774 003EE774 BA000010 */  b          .L003EEA60
    /* 2EE778 003EE778 2D100000 */   daddu     $2, $0, $0
  .L003EE77C:
    /* 2EE77C 003EE77C DCA80F0C */  jal        func_003ea370
    /* 2EE780 003EE780 A006A48F */   lw        $4, 0x6A0($29)
    /* 2EE784 003EE784 B6000010 */  b          .L003EEA60
    /* 2EE788 003EE788 2D100000 */   daddu     $2, $0, $0
  .L003EE78C:
    /* 2EE78C 003EE78C CCB00F0C */  jal        func_003ec330
    /* 2EE790 003EE790 2D204002 */   daddu     $4, $18, $0
    /* 2EE794 003EE794 DCA80F0C */  jal        func_003ea370
    /* 2EE798 003EE798 A006A48F */   lw        $4, 0x6A0($29)
    /* 2EE79C 003EE79C B0000010 */  b          .L003EEA60
    /* 2EE7A0 003EE7A0 2D100000 */   daddu     $2, $0, $0
  .L003EE7A4:
    /* 2EE7A4 003EE7A4 A406B527 */  addiu      $21, $29, 0x6A4
  .L003EE7A8:
    /* 2EE7A8 003EE7A8 0000E28E */  lw         $2, 0x0($23)
    /* 2EE7AC 003EE7AC A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EE7B0 003EE7B0 2D288002 */  daddu      $5, $20, $0
    /* 2EE7B4 003EE7B4 09F84000 */  jalr       $2
    /* 2EE7B8 003EE7B8 00010624 */   addiu     $6, $0, 0x100
    /* 2EE7BC 003EE7BC 0000C28F */  lw         $2, 0x0($30)
    /* 2EE7C0 003EE7C0 09F84000 */  jalr       $2
    /* 2EE7C4 003EE7C4 2D208002 */   daddu     $4, $20, $0
    /* 2EE7C8 003EE7C8 0001412C */  sltiu      $1, $2, 0x100
    /* 2EE7CC 003EE7CC 4A002010 */  beqz       $1, .L003EE8F8
    /* 2EE7D0 003EE7D0 00000000 */   nop
    /* 2EE7D4 003EE7D4 00000000 */  nop
  .L003EE7D8:
    /* 2EE7D8 003EE7D8 1F006012 */  beqz       $19, .L003EE858
    /* 2EE7DC 003EE7DC A000A0A3 */   sb        $0, 0xA0($29)
    /* 2EE7E0 003EE7E0 00006282 */  lb         $2, 0x0($19)
    /* 2EE7E4 003EE7E4 1C004010 */  beqz       $2, .L003EE858
    /* 2EE7E8 003EE7E8 00000000 */   nop
    /* 2EE7EC 003EE7EC 0000E28E */  lw         $2, 0x0($23)
    /* 2EE7F0 003EE7F0 A000A427 */  addiu      $4, $29, 0xA0
    /* 2EE7F4 003EE7F4 2D286002 */  daddu      $5, $19, $0
    /* 2EE7F8 003EE7F8 09F84000 */  jalr       $2
    /* 2EE7FC 003EE7FC 00010624 */   addiu     $6, $0, 0x100
    /* 2EE800 003EE800 0000C28F */  lw         $2, 0x0($30)
    /* 2EE804 003EE804 09F84000 */  jalr       $2
    /* 2EE808 003EE808 2D206002 */   daddu     $4, $19, $0
    /* 2EE80C 003EE80C 0001422C */  sltiu      $2, $2, 0x100
    /* 2EE810 003EE810 11004014 */  bnez       $2, .L003EE858
    /* 2EE814 003EE814 00000000 */   nop
    /* 2EE818 003EE818 FF006882 */  lb         $8, 0xFF($19)
    /* 2EE81C 003EE81C 01000224 */  addiu      $2, $0, 0x1
    /* 2EE820 003EE820 E006A2AF */  sw         $2, 0x6E0($29)
    /* 2EE824 003EE824 2D286002 */  daddu      $5, $19, $0
    /* 2EE828 003EE828 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE82C 003EE82C 00010624 */  addiu      $6, $0, 0x100
    /* 2EE830 003EE830 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE834 003EE834 647D0F0C */  jal        func_003df590
    /* 2EE838 003EE838 FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE83C 003EE83C E406A327 */  addiu      $3, $29, 0x6E4
    /* 2EE840 003EE840 E006A427 */  addiu      $4, $29, 0x6E0
    /* 2EE844 003EE844 347D0F0C */  jal        func_003df4d0
    /* 2EE848 003EE848 000062AC */   sw        $2, 0x0($3)
    /* 2EE84C 003EE84C 9F01A227 */  addiu      $2, $29, 0x19F
    /* 2EE850 003EE850 000040A0 */  sb         $0, 0x0($2)
    /* 2EE854 003EE854 00000000 */  nop
  .L003EE858:
    /* 2EE858 003EE858 FF000632 */  andi       $6, $16, 0xFF
    /* 2EE85C 003EE85C A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EE860 003EE860 A000A527 */  addiu      $5, $29, 0xA0
    /* 2EE864 003EE864 BCBD0F0C */  jal        func_003ef6f0
    /* 2EE868 003EE868 2D38C002 */   daddu     $7, $22, $0
    /* 2EE86C 003EE86C FF000532 */  andi       $5, $16, 0xFF
    /* 2EE870 003EE870 2D204002 */  daddu      $4, $18, $0
    /* 2EE874 003EE874 A8B10F0C */  jal        func_003ec6a0
    /* 2EE878 003EE878 05000624 */   addiu     $6, $0, 0x5
    /* 2EE87C 003EE87C 0C00428E */  lw         $2, 0xC($18)
    /* 2EE880 003EE880 2D204002 */  daddu      $4, $18, $0
    /* 2EE884 003EE884 0C07A2AF */  sw         $2, 0x70C($29)
    /* 2EE888 003EE888 1000428E */  lw         $2, 0x10($18)
    /* 2EE88C 003EE88C 0807A2AF */  sw         $2, 0x708($29)
    /* 2EE890 003EE890 1400428E */  lw         $2, 0x14($18)
    /* 2EE894 003EE894 0407A2AF */  sw         $2, 0x704($29)
    /* 2EE898 003EE898 23004392 */  lbu        $3, 0x23($18)
    /* 2EE89C 003EE89C 20004292 */  lbu        $2, 0x20($18)
    /* 2EE8A0 003EE8A0 001A0300 */  sll        $3, $3, 8
    /* 2EE8A4 003EE8A4 25106200 */  or         $2, $3, $2
    /* 2EE8A8 003EE8A8 A8B00F0C */  jal        func_003ec2a0
    /* 2EE8AC 003EE8AC 0007A2AF */   sw        $2, 0x700($29)
    /* 2EE8B0 003EE8B0 A001A427 */  addiu      $4, $29, 0x1A0
    /* 2EE8B4 003EE8B4 A000A527 */  addiu      $5, $29, 0xA0
    /* 2EE8B8 003EE8B8 2D30C002 */  daddu      $6, $22, $0
    /* 2EE8BC 003EE8BC 0C07A727 */  addiu      $7, $29, 0x70C
    /* 2EE8C0 003EE8C0 0807A827 */  addiu      $8, $29, 0x708
    /* 2EE8C4 003EE8C4 0407A927 */  addiu      $9, $29, 0x704
    /* 2EE8C8 003EE8C8 94B70F0C */  jal        func_003ede50
    /* 2EE8CC 003EE8CC 0007AA27 */   addiu     $10, $29, 0x700
    /* 2EE8D0 003EE8D0 0000A2AE */  sw         $2, 0x0($21)
    /* 2EE8D4 003EE8D4 0000A28E */  lw         $2, 0x0($21)
    /* 2EE8D8 003EE8D8 17004010 */  beqz       $2, .L003EE938
    /* 2EE8DC 003EE8DC 00000000 */   nop
    /* 2EE8E0 003EE8E0 01001026 */  addiu      $16, $16, 0x1
    /* 2EE8E4 003EE8E4 2A101102 */  slt        $2, $16, $17
    /* 2EE8E8 003EE8E8 AFFF4014 */  bnez       $2, .L003EE7A8
    /* 2EE8EC 003EE8EC 0400B526 */   addiu     $21, $21, 0x4
    /* 2EE8F0 003EE8F0 53FF0010 */  b          .L003EE640
    /* 2EE8F4 003EE8F4 23004292 */   lbu       $2, 0x23($18)
  .L003EE8F8:
    /* 2EE8F8 003EE8F8 FF008882 */  lb         $8, 0xFF($20)
    /* 2EE8FC 003EE8FC 01000224 */  addiu      $2, $0, 0x1
    /* 2EE900 003EE900 E806A2AF */  sw         $2, 0x6E8($29)
    /* 2EE904 003EE904 2D288002 */  daddu      $5, $20, $0
    /* 2EE908 003EE908 0080023C */  lui        $2, (0x8000001E >> 16)
    /* 2EE90C 003EE90C 00010624 */  addiu      $6, $0, 0x100
    /* 2EE910 003EE910 1E004434 */  ori        $4, $2, (0x8000001E & 0xFFFF)
    /* 2EE914 003EE914 647D0F0C */  jal        func_003df590
    /* 2EE918 003EE918 FF000724 */   addiu     $7, $0, 0xFF
    /* 2EE91C 003EE91C EC06A327 */  addiu      $3, $29, 0x6EC
    /* 2EE920 003EE920 E806A427 */  addiu      $4, $29, 0x6E8
    /* 2EE924 003EE924 347D0F0C */  jal        func_003df4d0
    /* 2EE928 003EE928 000062AC */   sw        $2, 0x0($3)
    /* 2EE92C 003EE92C 9F02A227 */  addiu      $2, $29, 0x29F
    /* 2EE930 003EE930 A9FF0010 */  b          .L003EE7D8
    /* 2EE934 003EE934 000040A0 */   sb        $0, 0x0($2)
  .L003EE938:
    /* 2EE938 003EE938 FFFF1026 */  addiu      $16, $16, -0x1
    /* 2EE93C 003EE93C 0C000006 */  bltz       $16, .L003EE970
    /* 2EE940 003EE940 00000000 */   nop
    /* 2EE944 003EE944 80101000 */  sll        $2, $16, 2
    /* 2EE948 003EE948 21105D00 */  addu       $2, $2, $29
    /* 2EE94C 003EE94C A0065124 */  addiu      $17, $2, 0x6A0
  .L003EE950:
    /* 2EE950 003EE950 DCA80F0C */  jal        func_003ea370
    /* 2EE954 003EE954 0000248E */   lw        $4, 0x0($17)
    /* 2EE958 003EE958 FFFF1026 */  addiu      $16, $16, -0x1
    /* 2EE95C 003EE95C FCFF3126 */  addiu      $17, $17, -0x4
    /* 2EE960 003EE960 00000000 */  nop
    /* 2EE964 003EE964 FAFF0106 */  bgez       $16, .L003EE950
    /* 2EE968 003EE968 00000000 */   nop
    /* 2EE96C 003EE96C 00000000 */  nop
  .L003EE970:
    /* 2EE970 003EE970 CCB00F0C */  jal        func_003ec330
    /* 2EE974 003EE974 2D204002 */   daddu     $4, $18, $0
    /* 2EE978 003EE978 39000010 */  b          .L003EEA60
    /* 2EE97C 003EE97C 2D100000 */   daddu     $2, $0, $0
  .L003EE980:
    /* 2EE980 003EE980 2A081100 */  slt        $1, $0, $17
    /* 2EE984 003EE984 46FF2010 */  beqz       $1, .L003EE6A0
    /* 2EE988 003EE988 2DA80000 */   daddu     $21, $0, $0
    /* 2EE98C 003EE98C A006B027 */  addiu      $16, $29, 0x6A0
  .L003EE990:
    /* 2EE990 003EE990 78AF0F0C */  jal        func_003ebde0
    /* 2EE994 003EE994 0000048E */   lw        $4, 0x0($16)
    /* 2EE998 003EE998 0100B526 */  addiu      $21, $21, 0x1
    /* 2EE99C 003EE99C 04001026 */  addiu      $16, $16, 0x4
    /* 2EE9A0 003EE9A0 2A10B102 */  slt        $2, $21, $17
    /* 2EE9A4 003EE9A4 FAFF4014 */  bnez       $2, .L003EE990
    /* 2EE9A8 003EE9A8 00000000 */   nop
    /* 2EE9AC 003EE9AC 3DFF0010 */  b          .L003EE6A4
    /* 2EE9B0 003EE9B0 2A081100 */   slt       $1, $0, $17
  .L003EE9B4:
    /* 2EE9B4 003EE9B4 2A081102 */  slt        $1, $16, $17
    /* 2EE9B8 003EE9B8 0B002010 */  beqz       $1, .L003EE9E8
    /* 2EE9BC 003EE9BC 00000000 */   nop
    /* 2EE9C0 003EE9C0 80101000 */  sll        $2, $16, 2
    /* 2EE9C4 003EE9C4 21105D00 */  addu       $2, $2, $29
    /* 2EE9C8 003EE9C8 A0065324 */  addiu      $19, $2, 0x6A0
  .L003EE9CC:
    /* 2EE9CC 003EE9CC DCA80F0C */  jal        func_003ea370
    /* 2EE9D0 003EE9D0 0000648E */   lw        $4, 0x0($19)
    /* 2EE9D4 003EE9D4 01001026 */  addiu      $16, $16, 0x1
    /* 2EE9D8 003EE9D8 04007326 */  addiu      $19, $19, 0x4
    /* 2EE9DC 003EE9DC 2A101102 */  slt        $2, $16, $17
    /* 2EE9E0 003EE9E0 FAFF4014 */  bnez       $2, .L003EE9CC
    /* 2EE9E4 003EE9E4 00000000 */   nop
  .L003EE9E8:
    /* 2EE9E8 003EE9E8 CCB00F0C */  jal        func_003ec330
    /* 2EE9EC 003EE9EC 2D204002 */   daddu     $4, $18, $0
    /* 2EE9F0 003EE9F0 1B000010 */  b          .L003EEA60
    /* 2EE9F4 003EE9F4 2D100000 */   daddu     $2, $0, $0
  .L003EE9F8:
    /* 2EE9F8 003EE9F8 78AF0F0C */  jal        func_003ebde0
    /* 2EE9FC 003EE9FC A006A48F */   lw        $4, 0x6A0($29)
    /* 2EEA00 003EEA00 A006A58F */  lw         $5, 0x6A0($29)
    /* 2EEA04 003EEA04 60B00F0C */  jal        func_003ec180
    /* 2EEA08 003EEA08 2D204002 */   daddu     $4, $18, $0
    /* 2EEA0C 003EEA0C 05004010 */  beqz       $2, .L003EEA24
    /* 2EEA10 003EEA10 00000000 */   nop
    /* 2EEA14 003EEA14 DCA80F0C */  jal        func_003ea370
    /* 2EEA18 003EEA18 A006A48F */   lw        $4, 0x6A0($29)
    /* 2EEA1C 003EEA1C 38FF0010 */  b          .L003EE700
    /* 2EEA20 003EEA20 00000000 */   nop
  .L003EEA24:
    /* 2EEA24 003EEA24 CCB00F0C */  jal        func_003ec330
    /* 2EEA28 003EEA28 2D204002 */   daddu     $4, $18, $0
    /* 2EEA2C 003EEA2C DCA80F0C */  jal        func_003ea370
    /* 2EEA30 003EEA30 A006A48F */   lw        $4, 0x6A0($29)
    /* 2EEA34 003EEA34 0A000010 */  b          .L003EEA60
    /* 2EEA38 003EEA38 2D100000 */   daddu     $2, $0, $0
  .L003EEA3C:
    /* 2EEA3C 003EEA3C CCB00F0C */  jal        func_003ec330
    /* 2EEA40 003EEA40 2D204002 */   daddu     $4, $18, $0
    /* 2EEA44 003EEA44 06000010 */  b          .L003EEA60
    /* 2EEA48 003EEA48 2D100000 */   daddu     $2, $0, $0
  .L003EEA4C:
    /* 2EEA4C 003EEA4C 2D200002 */  daddu      $4, $16, $0
    /* 2EEA50 003EEA50 44BD0F0C */  jal        func_003ef510
    /* 2EEA54 003EEA54 B0AB8527 */   addiu     $5, $28, -0x5450
    /* 2EEA58 003EEA58 36FF0010 */  b          .L003EE734
    /* 2EEA5C 003EEA5C 00000000 */   nop
  .L003EEA60:
    /* 2EEA60 003EEA60 9000BFDF */  ld         $31, 0x90($29)
    /* 2EEA64 003EEA64 8000BE7B */  lq         $30, 0x80($29)
    /* 2EEA68 003EEA68 7000B77B */  lq         $23, 0x70($29)
    /* 2EEA6C 003EEA6C 6000B67B */  lq         $22, 0x60($29)
    /* 2EEA70 003EEA70 5000B57B */  lq         $21, 0x50($29)
    /* 2EEA74 003EEA74 4000B47B */  lq         $20, 0x40($29)
    /* 2EEA78 003EEA78 3000B37B */  lq         $19, 0x30($29)
    /* 2EEA7C 003EEA7C 2000B27B */  lq         $18, 0x20($29)
    /* 2EEA80 003EEA80 1000B17B */  lq         $17, 0x10($29)
    /* 2EEA84 003EEA84 0000B07B */  lq         $16, 0x0($29)
    /* 2EEA88 003EEA88 0800E003 */  jr         $31
    /* 2EEA8C 003EEA8C 1007BD27 */   addiu     $29, $29, 0x710
.size func_003ee470, 0x620
