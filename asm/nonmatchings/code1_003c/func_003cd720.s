.section .text
.set noat
.set noreorder
glabel func_003cd720
    /* 2CD720 003CD720 F0FDBD27 */  addiu      $29, $29, -0x210
    /* 2CD724 003CD724 2D300000 */  daddu      $6, $0, $0
    /* 2CD728 003CD728 8000BE7F */  sq         $30, 0x80($29)
    /* 2CD72C 003CD72C 7000B77F */  sq         $23, 0x70($29)
    /* 2CD730 003CD730 6000B67F */  sq         $22, 0x60($29)
    /* 2CD734 003CD734 5000B57F */  sq         $21, 0x50($29)
    /* 2CD738 003CD738 4000B47F */  sq         $20, 0x40($29)
    /* 2CD73C 003CD73C 3000B37F */  sq         $19, 0x30($29)
    /* 2CD740 003CD740 2000B27F */  sq         $18, 0x20($29)
    /* 2CD744 003CD744 1000B17F */  sq         $17, 0x10($29)
    /* 2CD748 003CD748 0000B07F */  sq         $16, 0x0($29)
    /* 2CD74C 003CD74C 0400828C */  lw         $2, 0x4($4)
    /* 2CD750 003CD750 3000858C */  lw         $5, 0x30($4)
    /* 2CD754 003CD754 0C00838C */  lw         $3, 0xC($4)
    /* 2CD758 003CD758 0002A2AF */  sw         $2, 0x200($29)
    /* 2CD75C 003CD75C 2D100000 */  daddu      $2, $0, $0
    /* 2CD760 003CD760 0000A78C */  lw         $7, 0x0($5)
    /* 2CD764 003CD764 89CBC270 */  pcpyld     $25, $6, $2
    /* 2CD768 003CD768 0002A28F */  lw         $2, 0x200($29)
    /* 2CD76C 003CD76C 0000668C */  lw         $6, 0x0($3)
    /* 2CD770 003CD770 2000F48C */  lw         $20, 0x20($7)
    /* 2CD774 003CD774 1800F524 */  addiu      $21, $7, 0x18
    /* 2CD778 003CD778 B6004290 */  lbu        $2, 0xB6($2)
    /* 2CD77C 003CD77C 3400E38C */  lw         $3, 0x34($7)
    /* 2CD780 003CD780 0100C530 */  andi       $5, $6, 0x1
    /* 2CD784 003CD784 B001A27F */  sq         $2, 0x1B0($29)
    /* 2CD788 003CD788 2400E28C */  lw         $2, 0x24($7)
    /* 2CD78C 003CD78C F001A2AF */  sw         $2, 0x1F0($29)
    /* 2CD790 003CD790 3800E28C */  lw         $2, 0x38($7)
    /* 2CD794 003CD794 E701A014 */  bnez       $5, .L003CDF34
    /* 2CD798 003CD798 C001A27F */   sq        $2, 0x1C0($29)
    /* 2CD79C 003CD79C 0800C230 */  andi       $2, $6, 0x8
    /* 2CD7A0 003CD7A0 E4014014 */  bnez       $2, .L003CDF34
    /* 2CD7A4 003CD7A4 00000000 */   nop
    /* 2CD7A8 003CD7A8 0002A28F */  lw         $2, 0x200($29)
    /* 2CD7AC 003CD7AC F1014290 */  lbu        $2, 0x1F1($2)
    /* 2CD7B0 003CD7B0 9000A2AF */  sw         $2, 0x90($29)
  .L003CD7B4:
    /* 2CD7B4 003CD7B4 2A080300 */  slt        $1, $0, $3
    /* 2CD7B8 003CD7B8 2D988002 */  daddu      $19, $20, $0
    /* 2CD7BC 003CD7BC 2D900000 */  daddu      $18, $0, $0
    /* 2CD7C0 003CD7C0 C7012010 */  beqz       $1, .L003CDEE0
    /* 2CD7C4 003CD7C4 2D880000 */   daddu     $17, $0, $0
    /* 2CD7C8 003CD7C8 2A080300 */  slt        $1, $0, $3
    /* 2CD7CC 003CD7CC C4012010 */  beqz       $1, .L003CDEE0
    /* 2CD7D0 003CD7D0 D801A0FF */   sd        $0, 0x1D8($29)
    /* 2CD7D4 003CD7D4 B001A27B */  lq         $2, 0x1B0($29)
    /* 2CD7D8 003CD7D8 0001063C */  lui        $6, (0x1000404 >> 16)
    /* 2CD7DC 003CD7DC B001A57B */  lq         $5, 0x1B0($29)
    /* 2CD7E0 003CD7E0 0011073C */  lui        $7, (0x11000000 >> 16)
    /* 2CD7E4 003CD7E4 2D700000 */  daddu      $14, $0, $0
    /* 2CD7E8 003CD7E8 3C100200 */  dsll32     $2, $2, 0
    /* 2CD7EC 003CD7EC 3E100200 */  dsrl32     $2, $2, 0
    /* 2CD7F0 003CD7F0 A001A27F */  sq         $2, 0x1A0($29)
    /* 2CD7F4 003CD7F4 0001C234 */  ori        $2, $6, (0x1000100 & 0xFFFF)
    /* 2CD7F8 003CD7F8 9001A27F */  sq         $2, 0x190($29)
    /* 2CD7FC 003CD7FC 2510A200 */  or         $2, $5, $2
    /* 2CD800 003CD800 3C580200 */  dsll32     $11, $2, 0
    /* 2CD804 003CD804 2D280000 */  daddu      $5, $0, $0
    /* 2CD808 003CD808 0404C234 */  ori        $2, $6, (0x1000404 & 0xFFFF)
    /* 2CD80C 003CD80C 3E580B00 */  dsrl32     $11, $11, 0
    /* 2CD810 003CD810 B000A27F */  sq         $2, 0xB0($29)
    /* 2CD814 003CD814 3C300700 */  dsll32     $6, $7, 0
    /* 2CD818 003CD818 00FF0234 */  ori        $2, $0, 0xFF00
    /* 2CD81C 003CD81C 38140200 */  dsll       $2, $2, 16
    /* 2CD820 003CD820 00404234 */  ori        $2, $2, 0x4000
    /* 2CD824 003CD824 7001A27F */  sq         $2, 0x170($29)
    /* 2CD828 003CD828 0010023C */  lui        $2, (0x10000000 >> 16)
    /* 2CD82C 003CD82C 8913A270 */  pcpyld     $2, $5, $2
    /* 2CD830 003CD830 0068053C */  lui        $5, (0x68008000 >> 16)
    /* 2CD834 003CD834 E001A27F */  sq         $2, 0x1E0($29)
    /* 2CD838 003CD838 0080A534 */  ori        $5, $5, (0x68008000 & 0xFFFF)
    /* 2CD83C 003CD83C 0005023C */  lui        $2, (0x5000000 >> 16)
    /* 2CD840 003CD840 6001A57F */  sq         $5, 0x160($29)
    /* 2CD844 003CD844 3C100200 */  dsll32     $2, $2, 0
    /* 2CD848 003CD848 2528E600 */  or         $5, $7, $6
    /* 2CD84C 003CD84C 8001A57F */  sq         $5, 0x180($29)
    /* 2CD850 003CD850 006C053C */  lui        $5, (0x6C008000 >> 16)
    /* 2CD854 003CD854 0080A534 */  ori        $5, $5, (0x6C008000 & 0xFFFF)
    /* 2CD858 003CD858 5001A57F */  sq         $5, 0x150($29)
    /* 2CD85C 003CD85C 0064053C */  lui        $5, (0x64008000 >> 16)
    /* 2CD860 003CD860 0080A534 */  ori        $5, $5, (0x64008000 & 0xFFFF)
    /* 2CD864 003CD864 3001A57F */  sq         $5, 0x130($29)
    /* 2CD868 003CD868 006E053C */  lui        $5, (0x6E00C000 >> 16)
    /* 2CD86C 003CD86C 00C0A534 */  ori        $5, $5, (0x6E00C000 & 0xFFFF)
    /* 2CD870 003CD870 F000A57F */  sq         $5, 0xF0($29)
    /* 2CD874 003CD874 006A053C */  lui        $5, (0x6A008000 >> 16)
    /* 2CD878 003CD878 0080A534 */  ori        $5, $5, (0x6A008000 & 0xFFFF)
    /* 2CD87C 003CD87C C000A57F */  sq         $5, 0xC0($29)
    /* 2CD880 003CD880 B001A57B */  lq         $5, 0x1B0($29)
    /* 2CD884 003CD884 0100A524 */  addiu      $5, $5, 0x1
    /* 2CD888 003CD888 A000A57F */  sq         $5, 0xA0($29)
  .L003CD88C:
    /* 2CD88C 003CD88C FFFF6524 */  addiu      $5, $3, -0x1
    /* 2CD890 003CD890 2A082502 */  slt        $1, $17, $5
    /* 2CD894 003CD894 03002010 */  beqz       $1, .L003CD8A4
    /* 2CD898 003CD898 00000000 */   nop
    /* 2CD89C 003CD89C 05000010 */  b          .L003CD8B4
    /* 2CD8A0 003CD8A0 1800B88E */   lw        $24, 0x18($21)
  .L003CD8A4:
    /* 2CD8A4 003CD8A4 1800A38E */  lw         $3, 0x18($21)
    /* 2CD8A8 003CD8A8 1828A300 */  mult       $5, $5, $3
    /* 2CD8AC 003CD8AC F001A38F */  lw         $3, 0x1F0($29)
    /* 2CD8B0 003CD8B0 23C06500 */  subu       $24, $3, $5
  .L003CD8B4:
    /* 2CD8B4 003CD8B4 C001A37B */  lq         $3, 0x1C0($29)
    /* 2CD8B8 003CD8B8 1B002302 */  divu       $0, $17, $3
    /* 2CD8BC 003CD8BC 10180000 */  mfhi       $3
    /* 2CD8C0 003CD8C0 16006014 */  bnez       $3, .L003CD91C
    /* 2CD8C4 003CD8C4 00000000 */   nop
    /* 2CD8C8 003CD8C8 23289302 */  subu       $5, $20, $19
    /* 2CD8CC 003CD8CC 0300A104 */  bgez       $5, .L003CD8DC
    /* 2CD8D0 003CD8D0 03190500 */   sra       $3, $5, 4
    /* 2CD8D4 003CD8D4 0F00A324 */  addiu      $3, $5, 0xF
    /* 2CD8D8 003CD8D8 03190300 */  sra        $3, $3, 4
  .L003CD8DC:
    /* 2CD8DC 003CD8DC FFFF6624 */  addiu      $6, $3, -0x1
    /* 2CD8E0 003CD8E0 8001A57B */  lq         $5, 0x180($29)
    /* 2CD8E4 003CD8E4 0010033C */  lui        $3, (0x10000000 >> 16)
    /* 2CD8E8 003CD8E8 2518C300 */  or         $3, $6, $3
    /* 2CD8EC 003CD8EC 3C300300 */  dsll32     $6, $3, 0
    /* 2CD8F0 003CD8F0 0002A38F */  lw         $3, 0x200($29)
    /* 2CD8F4 003CD8F4 3F300600 */  dsra32     $6, $6, 0
    /* 2CD8F8 003CD8F8 0B281100 */  movn       $5, $0, $17
    /* 2CD8FC 003CD8FC B4006390 */  lbu        $3, 0xB4($3)
    /* 2CD900 003CD900 95016010 */  beqz       $3, .L003CDF58
    /* 2CD904 003CD904 892BA670 */   pcpyld    $5, $5, $6
    /* 2CD908 003CD908 93012012 */  beqz       $17, .L003CDF58
    /* 2CD90C 003CD90C 00000000 */   nop
    /* 2CD910 003CD910 000066FE */  sd         $6, 0x0($19)
    /* 2CD914 003CD914 01001224 */  addiu      $18, $0, 0x1
    /* 2CD918 003CD918 2D988002 */  daddu      $19, $20, $0
  .L003CD91C:
    /* 2CD91C 003CD91C 2400858C */  lw         $5, 0x24($4)
    /* 2CD920 003CD920 0A00A624 */  addiu      $6, $5, 0xA
    /* 2CD924 003CD924 2A080600 */  slt        $1, $0, $6
    /* 2CD928 003CD928 6B002010 */  beqz       $1, .L003CDAD8
    /* 2CD92C 003CD92C 2D800000 */   daddu     $16, $0, $0
    /* 2CD930 003CD930 0002AD8F */  lw         $13, 0x200($29)
    /* 2CD934 003CD934 2D60A002 */  daddu      $12, $21, $0
  .L003CD938:
    /* 2CD938 003CD938 2000A68D */  lw         $6, 0x20($13)
    /* 2CD93C 003CD93C 0100C330 */  andi       $3, $6, 0x1
    /* 2CD940 003CD940 5D006010 */  beqz       $3, .L003CDAB8
    /* 2CD944 003CD944 00000000 */   nop
    /* 2CD948 003CD948 0020C330 */  andi       $3, $6, 0x2000
    /* 2CD94C 003CD94C 5A006014 */  bnez       $3, .L003CDAB8
    /* 2CD950 003CD950 00000000 */   nop
    /* 2CD954 003CD954 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* 2CD958 003CD958 2418C300 */  and        $3, $6, $3
    /* 2CD95C 003CD95C 006C063C */  lui        $6, (0x6C000000 >> 16)
    /* 2CD960 003CD960 1B006610 */  beq        $3, $6, .L003CD9D0
    /* 2CD964 003CD964 00000000 */   nop
    /* 2CD968 003CD968 0068063C */  lui        $6, (0x68000000 >> 16)
    /* 2CD96C 003CD96C 16006610 */  beq        $3, $6, .L003CD9C8
    /* 2CD970 003CD970 00000000 */   nop
    /* 2CD974 003CD974 006D063C */  lui        $6, (0x6D000000 >> 16)
    /* 2CD978 003CD978 11006610 */  beq        $3, $6, .L003CD9C0
    /* 2CD97C 003CD97C 00000000 */   nop
    /* 2CD980 003CD980 0064063C */  lui        $6, (0x64000000 >> 16)
    /* 2CD984 003CD984 0E006610 */  beq        $3, $6, .L003CD9C0
    /* 2CD988 003CD988 00000000 */   nop
    /* 2CD98C 003CD98C 0065063C */  lui        $6, (0x65000000 >> 16)
    /* 2CD990 003CD990 09006610 */  beq        $3, $6, .L003CD9B8
    /* 2CD994 003CD994 00000000 */   nop
    /* 2CD998 003CD998 006E063C */  lui        $6, (0x6E000000 >> 16)
    /* 2CD99C 003CD99C 06006610 */  beq        $3, $6, .L003CD9B8
    /* 2CD9A0 003CD9A0 00000000 */   nop
    /* 2CD9A4 003CD9A4 0060063C */  lui        $6, (0x60000000 >> 16)
    /* 2CD9A8 003CD9A8 03006610 */  beq        $3, $6, .L003CD9B8
    /* 2CD9AC 003CD9AC 00000000 */   nop
    /* 2CD9B0 003CD9B0 07000010 */  b          .L003CD9D0
    /* 2CD9B4 003CD9B4 00000000 */   nop
  .L003CD9B8:
    /* 2CD9B8 003CD9B8 07000010 */  b          .L003CD9D8
    /* 2CD9BC 003CD9BC 01000F24 */   addiu     $15, $0, 0x1
  .L003CD9C0:
    /* 2CD9C0 003CD9C0 05000010 */  b          .L003CD9D8
    /* 2CD9C4 003CD9C4 02000F24 */   addiu     $15, $0, 0x2
  .L003CD9C8:
    /* 2CD9C8 003CD9C8 03000010 */  b          .L003CD9D8
    /* 2CD9CC 003CD9CC 03000F24 */   addiu     $15, $0, 0x3
  .L003CD9D0:
    /* 2CD9D0 003CD9D0 04000F24 */  addiu      $15, $0, 0x4
    /* 2CD9D4 003CD9D4 00000000 */  nop
  .L003CD9D8:
    /* 2CD9D8 003CD9D8 0300A010 */  beqz       $5, .L003CD9E8
    /* 2CD9DC 003CD9DC 9800888D */   lw        $8, 0x98($12)
    /* 2CD9E0 003CD9E0 9C00888D */  lw         $8, 0x9C($12)
    /* 2CD9E4 003CD9E4 00000000 */  nop
  .L003CD9E8:
    /* 2CD9E8 003CD9E8 18380F03 */  mult       $7, $24, $15
    /* 2CD9EC 003CD9EC 1800A68E */  lw         $6, 0x18($21)
    /* 2CD9F0 003CD9F0 9000A58F */  lw         $5, 0x90($29)
    /* 2CD9F4 003CD9F4 0300E324 */  addiu      $3, $7, 0x3
    /* 2CD9F8 003CD9F8 2330C500 */  subu       $6, $6, $5
    /* 2CD9FC 003CD9FC 1828EE71 */  mult1      $5, $15, $14
    /* 2CDA00 003CDA00 1830C500 */  mult       $6, $6, $5
    /* 2CDA04 003CDA04 00490800 */  sll        $9, $8, 4
    /* 2CDA08 003CDA08 0800A88E */  lw         $8, 0x8($21)
    /* 2CDA0C 003CDA0C 83500300 */  sra        $10, $3, 2
    /* 2CDA10 003CDA10 FFFFF625 */  addiu      $22, $15, -0x1
    /* 2CDA14 003CDA14 0030053C */  lui        $5, (0x30000000 >> 16)
    /* 2CDA18 003CDA18 25284501 */  or         $5, $10, $5
    /* 2CDA1C 003CDA1C FCFF0A24 */  addiu      $10, $0, -0x4
    /* 2CDA20 003CDA20 24186A00 */  and        $3, $3, $10
    /* 2CDA24 003CDA24 21400901 */  addu       $8, $8, $9
    /* 2CDA28 003CDA28 23186700 */  subu       $3, $3, $7
    /* 2CDA2C 003CDA2C 3C500600 */  dsll32     $10, $6, 0
    /* 2CDA30 003CDA30 21187600 */  addu       $3, $3, $22
    /* 2CDA34 003CDA34 3C380500 */  dsll32     $7, $5, 0
    /* 2CDA38 003CDA38 1A006F00 */  div        $0, $3, $15
    /* 2CDA3C 003CDA3C 3C400800 */  dsll32     $8, $8, 0
    /* 2CDA40 003CDA40 A6008591 */  lbu        $5, 0xA6($12)
    /* 2CDA44 003CDA44 3E500A00 */  dsrl32     $10, $10, 0
    /* 2CDA48 003CDA48 3F400800 */  dsra32     $8, $8, 0
    /* 2CDA4C 003CDA4C 2000A69D */  lwu        $6, 0x20($13)
    /* 2CDA50 003CDA50 2D400A01 */  daddu      $8, $8, $10
    /* 2CDA54 003CDA54 3F380700 */  dsra32     $7, $7, 0
    /* 2CDA58 003CDA58 3C480800 */  dsll32     $9, $8, 0
    /* 2CDA5C 003CDA5C 7001A87B */  lq         $8, 0x170($29)
    /* 2CDA60 003CDA60 3C280500 */  dsll32     $5, $5, 0
    /* 2CDA64 003CDA64 3F280500 */  dsra32     $5, $5, 0
    /* 2CDA68 003CDA68 2440C800 */  and        $8, $6, $8
    /* 2CDA6C 003CDA6C 2530E900 */  or         $6, $7, $9
    /* 2CDA70 003CDA70 00800735 */  ori        $7, $8, 0x8000
    /* 2CDA74 003CDA74 2528E500 */  or         $5, $7, $5
    /* 2CDA78 003CDA78 12180000 */  mflo       $3
    /* 2CDA7C 003CDA7C 21180303 */  addu       $3, $24, $3
    /* 2CDA80 003CDA80 001C0300 */  sll        $3, $3, 16
    /* 2CDA84 003CDA84 2518A300 */  or         $3, $5, $3
    /* 2CDA88 003CDA88 3C280300 */  dsll32     $5, $3, 0
    /* 2CDA8C 003CDA8C 9001A37B */  lq         $3, 0x190($29)
    /* 2CDA90 003CDA90 2528A300 */  or         $5, $5, $3
    /* 2CDA94 003CDA94 A001A37B */  lq         $3, 0x1A0($29)
    /* 2CDA98 003CDA98 2518A300 */  or         $3, $5, $3
    /* 2CDA9C 003CDA9C 891B6670 */  pcpyld     $3, $3, $6
    /* 2CDAA0 003CDAA0 0000637E */  sq         $3, 0x0($19)
    /* 2CDAA4 003CDAA4 E001A37B */  lq         $3, 0x1E0($29)
    /* 2CDAA8 003CDAA8 10009326 */  addiu      $19, $20, 0x10
    /* 2CDAAC 003CDAAC 0000837E */  sq         $3, 0x0($20)
    /* 2CDAB0 003CDAB0 20009426 */  addiu      $20, $20, 0x20
    /* 2CDAB4 003CDAB4 00000000 */  nop
  .L003CDAB8:
    /* 2CDAB8 003CDAB8 2400858C */  lw         $5, 0x24($4)
    /* 2CDABC 003CDABC 01001026 */  addiu      $16, $16, 0x1
    /* 2CDAC0 003CDAC0 0800AD25 */  addiu      $13, $13, 0x8
    /* 2CDAC4 003CDAC4 0A00A624 */  addiu      $6, $5, 0xA
    /* 2CDAC8 003CDAC8 2A180602 */  slt        $3, $16, $6
    /* 2CDACC 003CDACC 9AFF6014 */  bnez       $3, .L003CD938
    /* 2CDAD0 003CDAD0 18008C25 */   addiu     $12, $12, 0x18
    /* 2CDAD4 003CDAD4 00000000 */  nop
  .L003CDAD8:
    /* 2CDAD8 003CDAD8 2A080600 */  slt        $1, $0, $6
    /* 2CDADC 003CDADC EE002010 */  beqz       $1, .L003CDE98
    /* 2CDAE0 003CDAE0 2D400000 */   daddu     $8, $0, $0
    /* 2CDAE4 003CDAE4 6001A37B */  lq         $3, 0x160($29)
    /* 2CDAE8 003CDAE8 00641800 */  sll        $12, $24, 16
    /* 2CDAEC 003CDAEC 80681800 */  sll        $13, $24, 2
    /* 2CDAF0 003CDAF0 01000527 */  addiu      $5, $24, 0x1
    /* 2CDAF4 003CDAF4 0300AD25 */  addiu      $13, $13, 0x3
    /* 2CDAF8 003CDAF8 0002AA8F */  lw         $10, 0x200($29)
    /* 2CDAFC 003CDAFC 2D48A002 */  daddu      $9, $21, $0
    /* 2CDB00 003CDB00 25388301 */  or         $7, $12, $3
    /* 2CDB04 003CDB04 40180500 */  sll        $3, $5, 1
    /* 2CDB08 003CDB08 21306500 */  addu       $6, $3, $5
    /* 2CDB0C 003CDB0C 5001A37B */  lq         $3, 0x150($29)
    /* 2CDB10 003CDB10 83300600 */  sra        $6, $6, 2
    /* 2CDB14 003CDB14 00310600 */  sll        $6, $6, 4
    /* 2CDB18 003CDB18 25288301 */  or         $5, $12, $3
    /* 2CDB1C 003CDB1C 00191800 */  sll        $3, $24, 4
    /* 2CDB20 003CDB20 4001A37F */  sq         $3, 0x140($29)
    /* 2CDB24 003CDB24 3001A37B */  lq         $3, 0x130($29)
    /* 2CDB28 003CDB28 25188301 */  or         $3, $12, $3
    /* 2CDB2C 003CDB2C 2001A37F */  sq         $3, 0x120($29)
    /* 2CDB30 003CDB30 40181800 */  sll        $3, $24, 1
    /* 2CDB34 003CDB34 03006F24 */  addiu      $15, $3, 0x3
    /* 2CDB38 003CDB38 83800F00 */  sra        $16, $15, 2
    /* 2CDB3C 003CDB3C 21187800 */  addu       $3, $3, $24
    /* 2CDB40 003CDB40 83780D00 */  sra        $15, $13, 2
    /* 2CDB44 003CDB44 00691000 */  sll        $13, $16, 4
    /* 2CDB48 003CDB48 1001AD7F */  sq         $13, 0x110($29)
    /* 2CDB4C 003CDB4C 00690F00 */  sll        $13, $15, 4
    /* 2CDB50 003CDB50 0001AD7F */  sq         $13, 0x100($29)
    /* 2CDB54 003CDB54 F000AD7B */  lq         $13, 0xF0($29)
    /* 2CDB58 003CDB58 25688D01 */  or         $13, $12, $13
    /* 2CDB5C 003CDB5C E000AD7F */  sq         $13, 0xE0($29)
    /* 2CDB60 003CDB60 C000AD7B */  lq         $13, 0xC0($29)
    /* 2CDB64 003CDB64 25B08D01 */  or         $22, $12, $13
    /* 2CDB68 003CDB68 0F006C24 */  addiu      $12, $3, 0xF
    /* 2CDB6C 003CDB6C F0FF0324 */  addiu      $3, $0, -0x10
    /* 2CDB70 003CDB70 24188301 */  and        $3, $12, $3
    /* 2CDB74 003CDB74 03000C27 */  addiu      $12, $24, 0x3
    /* 2CDB78 003CDB78 83600C00 */  sra        $12, $12, 2
    /* 2CDB7C 003CDB7C 00610C00 */  sll        $12, $12, 4
    /* 2CDB80 003CDB80 D000AC7F */  sq         $12, 0xD0($29)
    /* 2CDB84 003CDB84 B001AC7B */  lq         $12, 0x1B0($29)
    /* 2CDB88 003CDB88 18600C03 */  mult       $12, $24, $12
    /* 2CDB8C 003CDB8C 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDB90 003CDB90 3E600C00 */  dsrl32     $12, $12, 0
    /* 2CDB94 003CDB94 2560EC00 */  or         $12, $7, $12
    /* 2CDB98 003CDB98 3C680C00 */  dsll32     $13, $12, 0
    /* 2CDB9C 003CDB9C B000AC7B */  lq         $12, 0xB0($29)
    /* 2CDBA0 003CDBA0 25B8AC01 */  or         $23, $13, $12
    /* 2CDBA4 003CDBA4 A000AC7B */  lq         $12, 0xA0($29)
    /* 2CDBA8 003CDBA8 18600C73 */  mult1      $12, $24, $12
    /* 2CDBAC 003CDBAC 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDBB0 003CDBB0 3E600C00 */  dsrl32     $12, $12, 0
    /* 2CDBB4 003CDBB4 2560CC02 */  or         $12, $22, $12
    /* 2CDBB8 003CDBB8 3C680C00 */  dsll32     $13, $12, 0
    /* 2CDBBC 003CDBBC B000AC7B */  lq         $12, 0xB0($29)
    /* 2CDBC0 003CDBC0 25F0AC01 */  or         $30, $13, $12
  .L003CDBC4:
    /* 2CDBC4 003CDBC4 20004D8D */  lw         $13, 0x20($10)
    /* 2CDBC8 003CDBC8 0100AC31 */  andi       $12, $13, 0x1
    /* 2CDBCC 003CDBCC AA008011 */  beqz       $12, .L003CDE78
    /* 2CDBD0 003CDBD0 00000000 */   nop
    /* 2CDBD4 003CDBD4 0020AC31 */  andi       $12, $13, 0x2000
    /* 2CDBD8 003CDBD8 A7008011 */  beqz       $12, .L003CDE78
    /* 2CDBDC 003CDBDC 00000000 */   nop
    /* 2CDBE0 003CDBE0 0C00012D */  sltiu      $1, $8, 0xC
    /* 2CDBE4 003CDBE4 A4002010 */  beqz       $1, .L003CDE78
    /* 2CDBE8 003CDBE8 00000000 */   nop
    /* 2CDBEC 003CDBEC 75000C3C */  lui        $12, %hi(jtbl_00752E70)
    /* 2CDBF0 003CDBF0 80680800 */  sll        $13, $8, 2
    /* 2CDBF4 003CDBF4 702E8C25 */  addiu      $12, $12, %lo(jtbl_00752E70)
    /* 2CDBF8 003CDBF8 2160AC01 */  addu       $12, $13, $12
    /* 2CDBFC 003CDBFC 00008C8D */  lw         $12, 0x0($12)
    /* 2CDC00 003CDC00 08008001 */  jr         $12
    /* 2CDC04 003CDC04 00000000 */   nop
    /* 2CDC08 003CDC08 05004012 */  beqz       $18, .L003CDC20
    /* 2CDC0C 003CDC0C 00000000 */   nop
    /* 2CDC10 003CDC10 00008CDE */  ld         $12, 0x0($20)
    /* 2CDC14 003CDC14 04000010 */  b          .L003CDC28
    /* 2CDC18 003CDC18 2D900000 */   daddu     $18, $0, $0
    /* 2CDC1C 003CDC1C 00000000 */  nop
  .L003CDC20:
    /* 2CDC20 003CDC20 2D604000 */  daddu      $12, $2, $0
    /* 2CDC24 003CDC24 00000000 */  nop
  .L003CDC28:
    /* 2CDC28 003CDC28 A6002F91 */  lbu        $15, 0xA6($9)
    /* 2CDC2C 003CDC2C 21688602 */  addu       $13, $20, $6
    /* 2CDC30 003CDC30 3C780F00 */  dsll32     $15, $15, 0
    /* 2CDC34 003CDC34 3F780F00 */  dsra32     $15, $15, 0
    /* 2CDC38 003CDC38 2578EF00 */  or         $15, $7, $15
    /* 2CDC3C 003CDC3C 3C780F00 */  dsll32     $15, $15, 0
    /* 2CDC40 003CDC40 25786F01 */  or         $15, $11, $15
    /* 2CDC44 003CDC44 8963EC71 */  pcpyld     $12, $15, $12
    /* 2CDC48 003CDC48 00008C7E */  sq         $12, 0x0($20)
    /* 2CDC4C 003CDC4C 0000B97D */  sq         $25, 0x0($13)
    /* 2CDC50 003CDC50 89000010 */  b          .L003CDE78
    /* 2CDC54 003CDC54 1000B425 */   addiu     $20, $13, 0x10
    /* 2CDC58 003CDC58 05004012 */  beqz       $18, .L003CDC70
    /* 2CDC5C 003CDC5C 00000000 */   nop
    /* 2CDC60 003CDC60 00008DDE */  ld         $13, 0x0($20)
    /* 2CDC64 003CDC64 04000010 */  b          .L003CDC78
    /* 2CDC68 003CDC68 2D900000 */   daddu     $18, $0, $0
    /* 2CDC6C 003CDC6C 00000000 */  nop
  .L003CDC70:
    /* 2CDC70 003CDC70 2D684000 */  daddu      $13, $2, $0
    /* 2CDC74 003CDC74 00000000 */  nop
  .L003CDC78:
    /* 2CDC78 003CDC78 A6002C91 */  lbu        $12, 0xA6($9)
    /* 2CDC7C 003CDC7C 4001AF7B */  lq         $15, 0x140($29)
    /* 2CDC80 003CDC80 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDC84 003CDC84 3F600C00 */  dsra32     $12, $12, 0
    /* 2CDC88 003CDC88 21788F02 */  addu       $15, $20, $15
    /* 2CDC8C 003CDC8C 2560AC00 */  or         $12, $5, $12
    /* 2CDC90 003CDC90 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDC94 003CDC94 25606C01 */  or         $12, $11, $12
    /* 2CDC98 003CDC98 89638D71 */  pcpyld     $12, $12, $13
    /* 2CDC9C 003CDC9C 00008C7E */  sq         $12, 0x0($20)
    /* 2CDCA0 003CDCA0 0000F97D */  sq         $25, 0x0($15)
    /* 2CDCA4 003CDCA4 74000010 */  b          .L003CDE78
    /* 2CDCA8 003CDCA8 1000F425 */   addiu     $20, $15, 0x10
    /* 2CDCAC 003CDCAC 00000000 */  nop
    /* 2CDCB0 003CDCB0 05004012 */  beqz       $18, .L003CDCC8
    /* 2CDCB4 003CDCB4 00000000 */   nop
    /* 2CDCB8 003CDCB8 000090DE */  ld         $16, 0x0($20)
    /* 2CDCBC 003CDCBC 04000010 */  b          .L003CDCD0
    /* 2CDCC0 003CDCC0 2D900000 */   daddu     $18, $0, $0
    /* 2CDCC4 003CDCC4 00000000 */  nop
  .L003CDCC8:
    /* 2CDCC8 003CDCC8 2D804000 */  daddu      $16, $2, $0
    /* 2CDCCC 003CDCCC 00000000 */  nop
  .L003CDCD0:
    /* 2CDCD0 003CDCD0 A6002C91 */  lbu        $12, 0xA6($9)
    /* 2CDCD4 003CDCD4 1001AD7B */  lq         $13, 0x110($29)
    /* 2CDCD8 003CDCD8 3C780C00 */  dsll32     $15, $12, 0
    /* 2CDCDC 003CDCDC 2001AC7B */  lq         $12, 0x120($29)
    /* 2CDCE0 003CDCE0 3F780F00 */  dsra32     $15, $15, 0
    /* 2CDCE4 003CDCE4 21688D02 */  addu       $13, $20, $13
    /* 2CDCE8 003CDCE8 25608F01 */  or         $12, $12, $15
    /* 2CDCEC 003CDCEC 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDCF0 003CDCF0 25606C01 */  or         $12, $11, $12
    /* 2CDCF4 003CDCF4 89639071 */  pcpyld     $12, $12, $16
    /* 2CDCF8 003CDCF8 00008C7E */  sq         $12, 0x0($20)
    /* 2CDCFC 003CDCFC 0000B97D */  sq         $25, 0x0($13)
    /* 2CDD00 003CDD00 5D000010 */  b          .L003CDE78
    /* 2CDD04 003CDD04 1000B425 */   addiu     $20, $13, 0x10
    /* 2CDD08 003CDD08 05004012 */  beqz       $18, .L003CDD20
    /* 2CDD0C 003CDD0C 00000000 */   nop
    /* 2CDD10 003CDD10 00008DDE */  ld         $13, 0x0($20)
    /* 2CDD14 003CDD14 04000010 */  b          .L003CDD28
    /* 2CDD18 003CDD18 2D900000 */   daddu     $18, $0, $0
    /* 2CDD1C 003CDD1C 00000000 */  nop
  .L003CDD20:
    /* 2CDD20 003CDD20 2D684000 */  daddu      $13, $2, $0
    /* 2CDD24 003CDD24 00000000 */  nop
  .L003CDD28:
    /* 2CDD28 003CDD28 A6002C91 */  lbu        $12, 0xA6($9)
    /* 2CDD2C 003CDD2C 0001AF7B */  lq         $15, 0x100($29)
    /* 2CDD30 003CDD30 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDD34 003CDD34 3F600C00 */  dsra32     $12, $12, 0
    /* 2CDD38 003CDD38 21788F02 */  addu       $15, $20, $15
    /* 2CDD3C 003CDD3C 2560AC00 */  or         $12, $5, $12
    /* 2CDD40 003CDD40 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDD44 003CDD44 25606C01 */  or         $12, $11, $12
    /* 2CDD48 003CDD48 89638D71 */  pcpyld     $12, $12, $13
    /* 2CDD4C 003CDD4C 00008C7E */  sq         $12, 0x0($20)
    /* 2CDD50 003CDD50 0000F97D */  sq         $25, 0x0($15)
    /* 2CDD54 003CDD54 48000010 */  b          .L003CDE78
    /* 2CDD58 003CDD58 1000F425 */   addiu     $20, $15, 0x10
    /* 2CDD5C 003CDD5C 00000000 */  nop
    /* 2CDD60 003CDD60 05004012 */  beqz       $18, .L003CDD78
    /* 2CDD64 003CDD64 00000000 */   nop
    /* 2CDD68 003CDD68 000090DE */  ld         $16, 0x0($20)
    /* 2CDD6C 003CDD6C 04000010 */  b          .L003CDD80
    /* 2CDD70 003CDD70 2D900000 */   daddu     $18, $0, $0
    /* 2CDD74 003CDD74 00000000 */  nop
  .L003CDD78:
    /* 2CDD78 003CDD78 2D804000 */  daddu      $16, $2, $0
    /* 2CDD7C 003CDD7C 00000000 */  nop
  .L003CDD80:
    /* 2CDD80 003CDD80 A6002C91 */  lbu        $12, 0xA6($9)
    /* 2CDD84 003CDD84 D000AD7B */  lq         $13, 0xD0($29)
    /* 2CDD88 003CDD88 3C780C00 */  dsll32     $15, $12, 0
    /* 2CDD8C 003CDD8C E000AC7B */  lq         $12, 0xE0($29)
    /* 2CDD90 003CDD90 3F780F00 */  dsra32     $15, $15, 0
    /* 2CDD94 003CDD94 21688D02 */  addu       $13, $20, $13
    /* 2CDD98 003CDD98 25608F01 */  or         $12, $12, $15
    /* 2CDD9C 003CDD9C 3C600C00 */  dsll32     $12, $12, 0
    /* 2CDDA0 003CDDA0 25606C01 */  or         $12, $11, $12
    /* 2CDDA4 003CDDA4 89639071 */  pcpyld     $12, $12, $16
    /* 2CDDA8 003CDDA8 00008C7E */  sq         $12, 0x0($20)
    /* 2CDDAC 003CDDAC 0000B97D */  sq         $25, 0x0($13)
    /* 2CDDB0 003CDDB0 31000010 */  b          .L003CDE78
    /* 2CDDB4 003CDDB4 1000B425 */   addiu     $20, $13, 0x10
    /* 2CDDB8 003CDDB8 05004012 */  beqz       $18, .L003CDDD0
    /* 2CDDBC 003CDDBC 00000000 */   nop
    /* 2CDDC0 003CDDC0 00008CDE */  ld         $12, 0x0($20)
    /* 2CDDC4 003CDDC4 04000010 */  b          .L003CDDD8
    /* 2CDDC8 003CDDC8 2D900000 */   daddu     $18, $0, $0
    /* 2CDDCC 003CDDCC 00000000 */  nop
  .L003CDDD0:
    /* 2CDDD0 003CDDD0 2D604000 */  daddu      $12, $2, $0
    /* 2CDDD4 003CDDD4 00000000 */  nop
  .L003CDDD8:
    /* 2CDDD8 003CDDD8 A6002F91 */  lbu        $15, 0xA6($9)
    /* 2CDDDC 003CDDDC 21688302 */  addu       $13, $20, $3
    /* 2CDDE0 003CDDE0 3C780F00 */  dsll32     $15, $15, 0
    /* 2CDDE4 003CDDE4 3F780F00 */  dsra32     $15, $15, 0
    /* 2CDDE8 003CDDE8 2578CF02 */  or         $15, $22, $15
    /* 2CDDEC 003CDDEC 3C780F00 */  dsll32     $15, $15, 0
    /* 2CDDF0 003CDDF0 25786F01 */  or         $15, $11, $15
    /* 2CDDF4 003CDDF4 8963EC71 */  pcpyld     $12, $15, $12
    /* 2CDDF8 003CDDF8 00008C7E */  sq         $12, 0x0($20)
    /* 2CDDFC 003CDDFC 0000B97D */  sq         $25, 0x0($13)
    /* 2CDE00 003CDE00 1D000010 */  b          .L003CDE78
    /* 2CDE04 003CDE04 1000B425 */   addiu     $20, $13, 0x10
    /* 2CDE08 003CDE08 05004012 */  beqz       $18, .L003CDE20
    /* 2CDE0C 003CDE0C 00000000 */   nop
    /* 2CDE10 003CDE10 00008DDE */  ld         $13, 0x0($20)
    /* 2CDE14 003CDE14 04000010 */  b          .L003CDE28
    /* 2CDE18 003CDE18 2D900000 */   daddu     $18, $0, $0
    /* 2CDE1C 003CDE1C 00000000 */  nop
  .L003CDE20:
    /* 2CDE20 003CDE20 2D684000 */  daddu      $13, $2, $0
    /* 2CDE24 003CDE24 00000000 */  nop
  .L003CDE28:
    /* 2CDE28 003CDE28 21608602 */  addu       $12, $20, $6
    /* 2CDE2C 003CDE2C 896BED72 */  pcpyld     $13, $23, $13
    /* 2CDE30 003CDE30 00008D7E */  sq         $13, 0x0($20)
    /* 2CDE34 003CDE34 0000997D */  sq         $25, 0x0($12)
    /* 2CDE38 003CDE38 0F000010 */  b          .L003CDE78
    /* 2CDE3C 003CDE3C 10009425 */   addiu     $20, $12, 0x10
    /* 2CDE40 003CDE40 05004012 */  beqz       $18, .L003CDE58
    /* 2CDE44 003CDE44 00000000 */   nop
    /* 2CDE48 003CDE48 00008DDE */  ld         $13, 0x0($20)
    /* 2CDE4C 003CDE4C 04000010 */  b          .L003CDE60
    /* 2CDE50 003CDE50 2D900000 */   daddu     $18, $0, $0
    /* 2CDE54 003CDE54 00000000 */  nop
  .L003CDE58:
    /* 2CDE58 003CDE58 2D684000 */  daddu      $13, $2, $0
    /* 2CDE5C 003CDE5C 00000000 */  nop
  .L003CDE60:
    /* 2CDE60 003CDE60 21608302 */  addu       $12, $20, $3
    /* 2CDE64 003CDE64 896BCD73 */  pcpyld     $13, $30, $13
    /* 2CDE68 003CDE68 00008D7E */  sq         $13, 0x0($20)
    /* 2CDE6C 003CDE6C 0000997D */  sq         $25, 0x0($12)
    /* 2CDE70 003CDE70 10009425 */  addiu      $20, $12, 0x10
    /* 2CDE74 003CDE74 00000000 */  nop
  .L003CDE78:
    /* 2CDE78 003CDE78 24008C8C */  lw         $12, 0x24($4)
    /* 2CDE7C 003CDE7C 01000825 */  addiu      $8, $8, 0x1
    /* 2CDE80 003CDE80 08004A25 */  addiu      $10, $10, 0x8
    /* 2CDE84 003CDE84 0A008C25 */  addiu      $12, $12, 0xA
    /* 2CDE88 003CDE88 2A600C01 */  slt        $12, $8, $12
    /* 2CDE8C 003CDE8C 4DFF8015 */  bnez       $12, .L003CDBC4
    /* 2CDE90 003CDE90 18002925 */   addiu     $9, $9, 0x18
    /* 2CDE94 003CDE94 00000000 */  nop
  .L003CDE98:
    /* 2CDE98 003CDE98 0004033C */  lui        $3, (0x4000000 >> 16)
    /* 2CDE9C 003CDE9C 25180303 */  or         $3, $24, $3
    /* 2CDEA0 003CDEA0 0015063C */  lui        $6, (0x15000000 >> 16)
    /* 2CDEA4 003CDEA4 3C280300 */  dsll32     $5, $3, 0
    /* 2CDEA8 003CDEA8 0400CE25 */  addiu      $14, $14, 0x4
    /* 2CDEAC 003CDEAC 0017033C */  lui        $3, (0x17000000 >> 16)
    /* 2CDEB0 003CDEB0 3F280500 */  dsra32     $5, $5, 0
    /* 2CDEB4 003CDEB4 0B307100 */  movn       $6, $3, $17
    /* 2CDEB8 003CDEB8 3C180600 */  dsll32     $3, $6, 0
    /* 2CDEBC 003CDEBC 01003126 */  addiu      $17, $17, 0x1
    /* 2CDEC0 003CDEC0 25286500 */  or         $5, $3, $5
    /* 2CDEC4 003CDEC4 D801A3DF */  ld         $3, 0x1D8($29)
    /* 2CDEC8 003CDEC8 891B6570 */  pcpyld     $3, $3, $5
    /* 2CDECC 003CDECC 0000837E */  sq         $3, 0x0($20)
    /* 2CDED0 003CDED0 1C00A38E */  lw         $3, 0x1C($21)
    /* 2CDED4 003CDED4 2A282302 */  slt        $5, $17, $3
    /* 2CDED8 003CDED8 6CFEA014 */  bnez       $5, .L003CD88C
    /* 2CDEDC 003CDEDC 10009426 */   addiu     $20, $20, 0x10
  .L003CDEE0:
    /* 2CDEE0 003CDEE0 0011053C */  lui        $5, (0x11000000 >> 16)
    /* 2CDEE4 003CDEE4 23189302 */  subu       $3, $20, $19
    /* 2CDEE8 003CDEE8 3C200500 */  dsll32     $4, $5, 0
    /* 2CDEEC 003CDEEC 03110300 */  sra        $2, $3, 4
    /* 2CDEF0 003CDEF0 2520A400 */  or         $4, $5, $4
    /* 2CDEF4 003CDEF4 03006104 */  bgez       $3, .L003CDF04
    /* 2CDEF8 003CDEF8 F8FF84FE */   sd        $4, -0x8($20)
    /* 2CDEFC 003CDEFC 0F006224 */  addiu      $2, $3, 0xF
    /* 2CDF00 003CDF00 03110200 */  sra        $2, $2, 4
  .L003CDF04:
    /* 2CDF04 003CDF04 FFFF4324 */  addiu      $3, $2, -0x1
    /* 2CDF08 003CDF08 0060023C */  lui        $2, (0x60000000 >> 16)
    /* 2CDF0C 003CDF0C 25106200 */  or         $2, $3, $2
    /* 2CDF10 003CDF10 3C100200 */  dsll32     $2, $2, 0
    /* 2CDF14 003CDF14 3F100200 */  dsra32     $2, $2, 0
    /* 2CDF18 003CDF18 000062FE */  sd         $2, 0x0($19)
    /* 2CDF1C 003CDF1C 0002A28F */  lw         $2, 0x200($29)
    /* 2CDF20 003CDF20 B4004290 */  lbu        $2, 0xB4($2)
    /* 2CDF24 003CDF24 10004010 */  beqz       $2, .L003CDF68
    /* 2CDF28 003CDF28 00000000 */   nop
  .L003CDF2C:
    /* 2CDF2C 003CDF2C 10000010 */  b          .L003CDF70
    /* 2CDF30 003CDF30 01000224 */   addiu     $2, $0, 0x1
  .L003CDF34:
    /* 2CDF34 003CDF34 0002A28F */  lw         $2, 0x200($29)
    /* 2CDF38 003CDF38 FFFF6524 */  addiu      $5, $3, -0x1
    /* 2CDF3C 003CDF3C B9004290 */  lbu        $2, 0xB9($2)
    /* 2CDF40 003CDF40 9000A2AF */  sw         $2, 0x90($29)
    /* 2CDF44 003CDF44 18284500 */  mult       $5, $2, $5
    /* 2CDF48 003CDF48 F001A28F */  lw         $2, 0x1F0($29)
    /* 2CDF4C 003CDF4C 21104500 */  addu       $2, $2, $5
    /* 2CDF50 003CDF50 18FE0010 */  b          .L003CD7B4
    /* 2CDF54 003CDF54 F001A2AF */   sw        $2, 0x1F0($29)
  .L003CDF58:
    /* 2CDF58 003CDF58 0000657E */  sq         $5, 0x0($19)
    /* 2CDF5C 003CDF5C 2D988002 */  daddu      $19, $20, $0
    /* 2CDF60 003CDF60 6EFE0010 */  b          .L003CD91C
    /* 2CDF64 003CDF64 10009426 */   addiu     $20, $20, 0x10
  .L003CDF68:
    /* 2CDF68 003CDF68 F0FF0010 */  b          .L003CDF2C
    /* 2CDF6C 003CDF6C 080060FE */   sd        $0, 0x8($19)
  .L003CDF70:
    /* 2CDF70 003CDF70 8000BE7B */  lq         $30, 0x80($29)
    /* 2CDF74 003CDF74 7000B77B */  lq         $23, 0x70($29)
    /* 2CDF78 003CDF78 6000B67B */  lq         $22, 0x60($29)
    /* 2CDF7C 003CDF7C 5000B57B */  lq         $21, 0x50($29)
    /* 2CDF80 003CDF80 4000B47B */  lq         $20, 0x40($29)
    /* 2CDF84 003CDF84 3000B37B */  lq         $19, 0x30($29)
    /* 2CDF88 003CDF88 2000B27B */  lq         $18, 0x20($29)
    /* 2CDF8C 003CDF8C 1000B17B */  lq         $17, 0x10($29)
    /* 2CDF90 003CDF90 0000B07B */  lq         $16, 0x0($29)
    /* 2CDF94 003CDF94 0800E003 */  jr         $31
    /* 2CDF98 003CDF98 1002BD27 */   addiu     $29, $29, 0x210
    /* 2CDF9C 003CDF9C 00000000 */  nop
.size func_003cd720, 0x880
