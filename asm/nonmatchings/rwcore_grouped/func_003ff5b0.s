.section .text
.set noat
.set noreorder
glabel func_003ff5b0
    /* 2FF5B0 003FF5B0 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 2FF5B4 003FF5B4 01000C64 */  daddiu     $12, $0, 0x1
    /* 2FF5B8 003FF5B8 9000BFFF */  sd         $31, 0x90($29)
    /* 2FF5BC 003FF5BC 8900023C */  lui        $2, %hi(D_0088C9F0)
    /* 2FF5C0 003FF5C0 8000BE7F */  sq         $30, 0x80($29)
    /* 2FF5C4 003FF5C4 00800624 */  addiu      $6, $0, -0x8000
    /* 2FF5C8 003FF5C8 7000B77F */  sq         $23, 0x70($29)
    /* 2FF5CC 003FF5CC FF3F0330 */  andi       $3, $0, 0x3FFF
    /* 2FF5D0 003FF5D0 6000B67F */  sq         $22, 0x60($29)
    /* 2FF5D4 003FF5D4 FFFF0424 */  addiu      $4, $0, -0x1
    /* 2FF5D8 003FF5D8 5000B57F */  sq         $21, 0x50($29)
    /* 2FF5DC 003FF5DC FFFF0734 */  ori        $7, $0, 0xFFFF
    /* 2FF5E0 003FF5E0 4000B47F */  sq         $20, 0x40($29)
    /* 2FF5E4 003FF5E4 F85B0C00 */  dsll       $11, $12, 15
    /* 2FF5E8 003FF5E8 3000B37F */  sq         $19, 0x30($29)
    /* 2FF5EC 003FF5EC 01000524 */  addiu      $5, $0, 0x1
    /* 2FF5F0 003FF5F0 2000B27F */  sq         $18, 0x20($29)
    /* 2FF5F4 003FF5F4 1000B17F */  sq         $17, 0x10($29)
    /* 2FF5F8 003FF5F8 0000B07F */  sq         $16, 0x0($29)
    /* 2FF5FC 003FF5FC F0C948DC */  ld         $8, %lo(D_0088C9F0)($2)
    /* 2FF600 003FF600 FFFF023C */  lui        $2, (0xFFFF0FFF >> 16)
    /* 2FF604 003FF604 24300601 */  and        $6, $8, $6
    /* 2FF608 003FF608 FF7F4A34 */  ori        $10, $2, (0xFFFF7FFF & 0xFFFF)
    /* 2FF60C 003FF60C FF0F4D34 */  ori        $13, $2, (0xFFFF0FFF & 0xFFFF)
    /* 2FF610 003FF610 FFFF0230 */  andi       $2, $0, 0xFFFF
    /* 2FF614 003FF614 3C400300 */  dsll32     $8, $3, 0
    /* 2FF618 003FF618 2518CC00 */  or         $3, $6, $12
    /* 2FF61C 003FF61C 384C0200 */  dsll       $9, $2, 16
    /* 2FF620 003FF620 3C100400 */  dsll32     $2, $4, 0
    /* 2FF624 003FF624 24506A00 */  and        $10, $3, $10
    /* 2FF628 003FF628 381C0700 */  dsll       $3, $7, 16
    /* 2FF62C 003FF62C 2530E200 */  or         $6, $7, $2
    /* 2FF630 003FF630 25384B01 */  or         $7, $10, $11
    /* 2FF634 003FF634 FFFF6334 */  ori        $3, $3, 0xFFFF
    /* 2FF638 003FF638 2438E600 */  and        $7, $7, $6
    /* 2FF63C 003FF63C F0FF0C24 */  addiu      $12, $0, -0x10
    /* 2FF640 003FF640 00C00624 */  addiu      $6, $0, -0x4000
    /* 2FF644 003FF644 2548E900 */  or         $9, $7, $9
    /* 2FF648 003FF648 3C300600 */  dsll32     $6, $6, 0
    /* 2FF64C 003FF64C 25386600 */  or         $7, $3, $6
    /* 2FF650 003FF650 24382701 */  and        $7, $9, $7
    /* 2FF654 003FF654 01000630 */  andi       $6, $0, 0x1
    /* 2FF658 003FF658 BC4B0600 */  dsll32     $9, $6, 14
    /* 2FF65C 003FF65C 2550E800 */  or         $10, $7, $8
    /* 2FF660 003FF660 FFBF0624 */  addiu      $6, $0, -0x4001
    /* 2FF664 003FF664 3C380600 */  dsll32     $7, $6, 0
    /* 2FF668 003FF668 FF070630 */  andi       $6, $0, 0x7FF
    /* 2FF66C 003FF66C 25386700 */  or         $7, $3, $7
    /* 2FF670 003FF670 FC430600 */  dsll32     $8, $6, 15
    /* 2FF674 003FF674 24384701 */  and        $7, $10, $7
    /* 2FF678 003FF678 00FC063C */  lui        $6, (0xFC007FFF >> 16)
    /* 2FF67C 003FF67C 2550E900 */  or         $10, $7, $9
    /* 2FF680 003FF680 FF7FC634 */  ori        $6, $6, (0xFC007FFF & 0xFFFF)
    /* 2FF684 003FF684 3C380600 */  dsll32     $7, $6, 0
    /* 2FF688 003FF688 03000630 */  andi       $6, $0, 0x3
    /* 2FF68C 003FF68C 25386700 */  or         $7, $3, $7
    /* 2FF690 003FF690 BC4E0600 */  dsll32     $9, $6, 26
    /* 2FF694 003FF694 24384701 */  and        $7, $10, $7
    /* 2FF698 003FF698 FFF3063C */  lui        $6, (0xF3FFFFFF >> 16)
    /* 2FF69C 003FF69C 2550E800 */  or         $10, $7, $8
    /* 2FF6A0 003FF6A0 FFFFC634 */  ori        $6, $6, (0xF3FFFFFF & 0xFFFF)
    /* 2FF6A4 003FF6A4 3C380600 */  dsll32     $7, $6, 0
    /* 2FF6A8 003FF6A8 0C000664 */  daddiu     $6, $0, 0xC
    /* 2FF6AC 003FF6AC 25386700 */  or         $7, $3, $7
    /* 2FF6B0 003FF6B0 3C470600 */  dsll32     $8, $6, 28
    /* 2FF6B4 003FF6B4 24384701 */  and        $7, $10, $7
    /* 2FF6B8 003FF6B8 FF0F063C */  lui        $6, (0xFFFFFFF >> 16)
    /* 2FF6BC 003FF6BC 2548E900 */  or         $9, $7, $9
    /* 2FF6C0 003FF6C0 FFFFC634 */  ori        $6, $6, (0xFFFFFFF & 0xFFFF)
    /* 2FF6C4 003FF6C4 0FFF0A24 */  addiu      $10, $0, -0xF1
    /* 2FF6C8 003FF6C8 2538C200 */  or         $7, $6, $2
    /* 2FF6CC 003FF6CC 3C100600 */  dsll32     $2, $6, 0
    /* 2FF6D0 003FF6D0 25106200 */  or         $2, $3, $2
    /* 2FF6D4 003FF6D4 8900063C */  lui        $6, %hi(D_0088C9F0)
    /* 2FF6D8 003FF6D8 89138270 */  pcpyld     $2, $4, $2
    /* 2FF6DC 003FF6DC 24202201 */  and        $4, $9, $2
    /* 2FF6E0 003FF6E0 25208800 */  or         $4, $4, $8
    /* 2FF6E4 003FF6E4 8900023C */  lui        $2, %hi(D_0088C9F8)
    /* 2FF6E8 003FF6E8 F8C948DC */  ld         $8, %lo(D_0088C9F8)($2)
    /* 2FF6EC 003FF6EC FFF00924 */  addiu      $9, $0, -0xF01
    /* 2FF6F0 003FF6F0 F0C9C4FC */  sd         $4, %lo(D_0088C9F0)($6)
    /* 2FF6F4 003FF6F4 F0FF043C */  lui        $4, (0xFFF0FFFF >> 16)
    /* 2FF6F8 003FF6F8 FFFF8634 */  ori        $6, $4, (0xFFF0FFFF & 0xFFFF)
    /* 2FF6FC 003FF6FC 3C200C00 */  dsll32     $4, $12, 0
    /* 2FF700 003FF700 0E000264 */  daddiu     $2, $0, 0xE
    /* 2FF704 003FF704 24400C01 */  and        $8, $8, $12
    /* 2FF708 003FF708 25400201 */  or         $8, $8, $2
    /* 2FF70C 003FF70C 25606400 */  or         $12, $3, $4
    /* 2FF710 003FF710 38810200 */  dsll       $16, $2, 4
    /* 2FF714 003FF714 24400A01 */  and        $8, $8, $10
    /* 2FF718 003FF718 25401001 */  or         $8, $8, $16
    /* 2FF71C 003FF71C 3C200A00 */  dsll32     $4, $10, 0
    /* 2FF720 003FF720 25506400 */  or         $10, $3, $4
    /* 2FF724 003FF724 387A0200 */  dsll       $15, $2, 8
    /* 2FF728 003FF728 24400901 */  and        $8, $8, $9
    /* 2FF72C 003FF72C 3C200900 */  dsll32     $4, $9, 0
    /* 2FF730 003FF730 25400F01 */  or         $8, $8, $15
    /* 2FF734 003FF734 38730200 */  dsll       $14, $2, 12
    /* 2FF738 003FF738 24480D01 */  and        $9, $8, $13
    /* 2FF73C 003FF73C 385C0200 */  dsll       $11, $2, 16
    /* 2FF740 003FF740 25406400 */  or         $8, $3, $4
    /* 2FF744 003FF744 25482E01 */  or         $9, $9, $14
    /* 2FF748 003FF748 3C200D00 */  dsll32     $4, $13, 0
    /* 2FF74C 003FF74C 24482601 */  and        $9, $9, $6
    /* 2FF750 003FF750 25306400 */  or         $6, $3, $4
    /* 2FF754 003FF754 25682B01 */  or         $13, $9, $11
    /* 2FF758 003FF758 0FFF033C */  lui        $3, (0xFF0FFFFF >> 16)
    /* 2FF75C 003FF75C 385D0200 */  dsll       $11, $2, 20
    /* 2FF760 003FF760 FFFF6434 */  ori        $4, $3, (0xFF0FFFFF & 0xFFFF)
    /* 2FF764 003FF764 384E0200 */  dsll       $9, $2, 24
    /* 2FF768 003FF768 2420A401 */  and        $4, $13, $4
    /* 2FF76C 003FF76C FFF0033C */  lui        $3, (0xF0FFFFFF >> 16)
    /* 2FF770 003FF770 25208B00 */  or         $4, $4, $11
    /* 2FF774 003FF774 FFFF6334 */  ori        $3, $3, (0xF0FFFFFF & 0xFFFF)
    /* 2FF778 003FF778 24188300 */  and        $3, $4, $3
    /* 2FF77C 003FF77C 386F0200 */  dsll       $13, $2, 28
    /* 2FF780 003FF780 25186900 */  or         $3, $3, $9
    /* 2FF784 003FF784 3C200200 */  dsll32     $4, $2, 0
    /* 2FF788 003FF788 24186700 */  and        $3, $3, $7
    /* 2FF78C 003FF78C 3C590200 */  dsll32     $11, $2, 4
    /* 2FF790 003FF790 3C4A0200 */  dsll32     $9, $2, 8
    /* 2FF794 003FF794 25186D00 */  or         $3, $3, $13
    /* 2FF798 003FF798 3C3B0200 */  dsll32     $7, $2, 12
    /* 2FF79C 003FF79C 24106C00 */  and        $2, $3, $12
    /* 2FF7A0 003FF7A0 25204400 */  or         $4, $2, $4
    /* 2FF7A4 003FF7A4 8900033C */  lui        $3, %hi(D_0088C9F8)
    /* 2FF7A8 003FF7A8 8900023C */  lui        $2, %hi(D_0088CA00)
    /* 2FF7AC 003FF7AC 24208A00 */  and        $4, $4, $10
    /* 2FF7B0 003FF7B0 00CA40FC */  sd         $0, %lo(D_0088CA00)($2)
    /* 2FF7B4 003FF7B4 25108B00 */  or         $2, $4, $11
    /* 2FF7B8 003FF7B8 24404800 */  and        $8, $2, $8
    /* 2FF7BC 003FF7BC 42000424 */  addiu      $4, $0, 0x42
    /* 2FF7C0 003FF7C0 8900023C */  lui        $2, %hi(D_0088CA08)
    /* 2FF7C4 003FF7C4 08CA44FC */  sd         $4, %lo(D_0088CA08)($2)
    /* 2FF7C8 003FF7C8 25100901 */  or         $2, $8, $9
    /* 2FF7CC 003FF7CC 1000043C */  lui        $4, (0x100000 >> 16)
    /* 2FF7D0 003FF7D0 24104600 */  and        $2, $2, $6
    /* 2FF7D4 003FF7D4 25304700 */  or         $6, $2, $7
    /* 2FF7D8 003FF7D8 F8C966FC */  sd         $6, %lo(D_0088C9F8)($3)
    /* 2FF7DC 003FF7DC 8900023C */  lui        $2, %hi(D_0088CA10)
    /* 2FF7E0 003FF7E0 10CA44FC */  sd         $4, %lo(D_0088CA10)($2)
    /* 2FF7E4 003FF7E4 4C000324 */  addiu      $3, $0, 0x4C
    /* 2FF7E8 003FF7E8 8900023C */  lui        $2, %hi(D_0088CA18)
    /* 2FF7EC 003FF7EC 1A000424 */  addiu      $4, $0, 0x1A
    /* 2FF7F0 003FF7F0 18CA43FC */  sd         $3, %lo(D_0088CA18)($2)
    /* 2FF7F4 003FF7F4 3C300500 */  dsll32     $6, $5, 0
    /* 2FF7F8 003FF7F8 8900023C */  lui        $2, %hi(D_0088CA20)
    /* 2FF7FC 003FF7FC FF03033C */  lui        $3, (0x3FF0000 >> 16)
    /* 2FF800 003FF800 20CA45FC */  sd         $5, %lo(D_0088CA20)($2)
    /* 2FF804 003FF804 8900023C */  lui        $2, %hi(D_0088CA28)
    /* 2FF808 003FF808 28CA44FC */  sd         $4, %lo(D_0088CA28)($2)
    /* 2FF80C 003FF80C 3C100300 */  dsll32     $2, $3, 0
    /* 2FF810 003FF810 40000424 */  addiu      $4, $0, 0x40
    /* 2FF814 003FF814 25186200 */  or         $3, $3, $2
    /* 2FF818 003FF818 8900023C */  lui        $2, %hi(D_0088CA30)
    /* 2FF81C 003FF81C 30CA43FC */  sd         $3, %lo(D_0088CA30)($2)
    /* 2FF820 003FF820 8900023C */  lui        $2, %hi(D_0088CA38)
    /* 2FF824 003FF824 0300033C */  lui        $3, (0x30000 >> 16)
    /* 2FF828 003FF828 38CA44FC */  sd         $4, %lo(D_0088CA38)($2)
    /* 2FF82C 003FF82C 8900023C */  lui        $2, %hi(D_0088CA40)
    /* 2FF830 003FF830 47000424 */  addiu      $4, $0, 0x47
    /* 2FF834 003FF834 40CA43FC */  sd         $3, %lo(D_0088CA40)($2)
    /* 2FF838 003FF838 8900033C */  lui        $3, %hi(D_0088CA48)
    /* 2FF83C 003FF83C 8900023C */  lui        $2, %hi(D_0088CA50)
    /* 2FF840 003FF840 48CA64FC */  sd         $4, %lo(D_0088CA48)($3)
    /* 2FF844 003FF844 50CA40FC */  sd         $0, %lo(D_0088CA50)($2)
    /* 2FF848 003FF848 18000324 */  addiu      $3, $0, 0x18
    /* 2FF84C 003FF84C 8900023C */  lui        $2, %hi(D_0088CA58)
    /* 2FF850 003FF850 4E000424 */  addiu      $4, $0, 0x4E
    /* 2FF854 003FF854 58CA43FC */  sd         $3, %lo(D_0088CA58)($2)
    /* 2FF858 003FF858 000A023C */  lui        $2, (0xA000100 >> 16)
    /* 2FF85C 003FF85C 8900033C */  lui        $3, %hi(D_0088CA60)
    /* 2FF860 003FF860 00014234 */  ori        $2, $2, (0xA000100 & 0xFFFF)
    /* 2FF864 003FF864 25304600 */  or         $6, $2, $6
    /* 2FF868 003FF868 60CA66FC */  sd         $6, %lo(D_0088CA60)($3)
    /* 2FF86C 003FF86C 8900023C */  lui        $2, %hi(D_0088CA68)
    /* 2FF870 003FF870 68CA44FC */  sd         $4, %lo(D_0088CA68)($2)
    /* 2FF874 003FF874 06000324 */  addiu      $3, $0, 0x6
    /* 2FF878 003FF878 8900023C */  lui        $2, %hi(D_0088CA70)
    /* 2FF87C 003FF87C 05000624 */  addiu      $6, $0, 0x5
    /* 2FF880 003FF880 70CA43FC */  sd         $3, %lo(D_0088CA70)($2)
    /* 2FF884 003FF884 8900023C */  lui        $2, %hi(D_0088CA78)
    /* 2FF888 003FF888 8900033C */  lui        $3, %hi(D_0088CAA0)
    /* 2FF88C 003FF88C 78CA40FC */  sd         $0, %lo(D_0088CA78)($2)
    /* 2FF890 003FF890 8900023C */  lui        $2, %hi(D_0088CA80)
    /* 2FF894 003FF894 A0CA60FC */  sd         $0, %lo(D_0088CAA0)($3)
    /* 2FF898 003FF898 80CA40FC */  sd         $0, %lo(D_0088CA80)($2)
    /* 2FF89C 003FF89C 8900033C */  lui        $3, %hi(D_0088CAB0)
    /* 2FF8A0 003FF8A0 8900023C */  lui        $2, %hi(D_0088CA88)
    /* 2FF8A4 003FF8A4 88CA45FC */  sd         $5, %lo(D_0088CA88)($2)
    /* 2FF8A8 003FF8A8 8900023C */  lui        $2, %hi(D_0088CA90)
    /* 2FF8AC 003FF8AC 90CA40FC */  sd         $0, %lo(D_0088CA90)($2)
    /* 2FF8B0 003FF8B0 8900023C */  lui        $2, %hi(D_0088CA98)
    /* 2FF8B4 003FF8B4 98CA46FC */  sd         $6, %lo(D_0088CA98)($2)
    /* 2FF8B8 003FF8B8 8900023C */  lui        $2, %hi(D_0088CAA8)
    /* 2FF8BC 003FF8BC A8CA45FC */  sd         $5, %lo(D_0088CAA8)($2)
    /* 2FF8C0 003FF8C0 FF3F023C */  lui        $2, (0x3FFF3FFF >> 16)
    /* 2FF8C4 003FF8C4 FF3F4434 */  ori        $4, $2, (0x3FFF3FFF & 0xFFFF)
    /* 2FF8C8 003FF8C8 B0CA64FC */  sd         $4, %lo(D_0088CAB0)($3)
    /* 2FF8CC 003FF8CC 8900023C */  lui        $2, %hi(D_0088CAB8)
    /* 2FF8D0 003FF8D0 8900033C */  lui        $3, %hi(D_0088CAC0)
    /* 2FF8D4 003FF8D4 8900043C */  lui        $4, %hi(D_0088C9F0)
    /* 2FF8D8 003FF8D8 C0CA6324 */  addiu      $3, $3, %lo(D_0088CAC0)
    /* 2FF8DC 003FF8DC B8CA46FC */  sd         $6, %lo(D_0088CAB8)($2)
    /* 2FF8E0 003FF8E0 7F006524 */  addiu      $5, $3, 0x7F
    /* 2FF8E4 003FF8E4 3688100C */  jal        func_004220d8
    /* 2FF8E8 003FF8E8 F0C98424 */   addiu     $4, $4, %lo(D_0088C9F0)
    /* 2FF8EC 003FF8EC FCD30F0C */  jal        func_003f4ff0
    /* 2FF8F0 003FF8F0 00000000 */   nop
    /* 2FF8F4 003FF8F4 E65F100C */  jal        func_00417f98
    /* 2FF8F8 003FF8F8 2D200000 */   daddu     $4, $0, $0
    /* 2FF8FC 003FF8FC 60B9848F */  lw         $4, -0x46A0($28)
    /* 2FF900 003FF900 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2FF904 003FF904 09058214 */  bne        $4, $2, .L00400D2C
    /* 2FF908 003FF908 00000000 */   nop
  .L003FF90C:
    /* 2FF90C 003FF90C 58FC0F0C */  jal        func_003ff160
    /* 2FF910 003FF910 00000000 */   nop
    /* 2FF914 003FF914 53054010 */  beqz       $2, .L00400E64
    /* 2FF918 003FF918 00000000 */   nop
    /* 2FF91C 003FF91C 8900023C */  lui        $2, %hi(D_0088C9E2)
    /* 2FF920 003FF920 8900033C */  lui        $3, %hi(D_0088C9B0)
    /* 2FF924 003FF924 E2C94690 */  lbu        $6, %lo(D_0088C9E2)($2)
    /* 2FF928 003FF928 B0C96324 */  addiu      $3, $3, %lo(D_0088C9B0)
    /* 2FF92C 003FF92C A0B883AF */  sw         $3, -0x4760($28)
    /* 2FF930 003FF930 50000324 */  addiu      $3, $0, 0x50
    /* 2FF934 003FF934 4D05C310 */  beq        $6, $3, .L00400E6C
    /* 2FF938 003FF938 00000000 */   nop
    /* 2FF93C 003FF93C 8900023C */  lui        $2, %hi(D_0088C9D4)
    /* 2FF940 003FF940 D4C9438C */  lw         $3, %lo(D_0088C9D4)($2)
    /* 2FF944 003FF944 04006230 */  andi       $2, $3, 0x4
    /* 2FF948 003FF948 4F054014 */  bnez       $2, .L00400E88
    /* 2FF94C 003FF94C 00000000 */   nop
    /* 2FF950 003FF950 02006230 */  andi       $2, $3, 0x2
    /* 2FF954 003FF954 52054014 */  bnez       $2, .L00400EA0
    /* 2FF958 003FF958 00000000 */   nop
    /* 2FF95C 003FF95C 00016230 */  andi       $2, $3, 0x100
    /* 2FF960 003FF960 07004010 */  beqz       $2, .L003FF980
    /* 2FF964 003FF964 00000000 */   nop
    /* 2FF968 003FF968 01000524 */  addiu      $5, $0, 0x1
    /* 2FF96C 003FF96C 2D200000 */  daddu      $4, $0, $0
    /* 2FF970 003FF970 445D100C */  jal        func_00417510
    /* 2FF974 003FF974 2D38A000 */   daddu     $7, $5, $0
    /* 2FF978 003FF978 06000010 */  b          .L003FF994
    /* 2FF97C 003FF97C 02000424 */   addiu     $4, $0, 0x2
  .L003FF980:
    /* 2FF980 003FF980 2D200000 */  daddu      $4, $0, $0
    /* 2FF984 003FF984 2D280000 */  daddu      $5, $0, $0
    /* 2FF988 003FF988 445D100C */  jal        func_00417510
    /* 2FF98C 003FF98C 01000724 */   addiu     $7, $0, 0x1
  .L003FF990:
    /* 2FF990 003FF990 02000424 */  addiu      $4, $0, 0x2
  .L003FF994:
    /* 2FF994 003FF994 D463100C */  jal        func_00418f50
    /* 2FF998 003FF998 00000000 */   nop
    /* 2FF99C 003FF99C 8900053C */  lui        $5, %hi(D_0088C9F0)
    /* 2FF9A0 003FF9A0 2D204000 */  daddu      $4, $2, $0
    /* 2FF9A4 003FF9A4 F0C9A524 */  addiu      $5, $5, %lo(D_0088C9F0)
    /* 2FF9A8 003FF9A8 BA64100C */  jal        func_004192e8
    /* 2FF9AC 003FF9AC 0D000624 */   addiu     $6, $0, 0xD
  .L003FF9B0:
    /* 2FF9B0 003FF9B0 01000424 */  addiu      $4, $0, 0x1
    /* 2FF9B4 003FF9B4 0C60100C */  jal        func_00418030
    /* 2FF9B8 003FF9B8 2D280000 */   daddu     $5, $0, $0
    /* 2FF9BC 003FF9BC 00000000 */  nop
    /* 2FF9C0 003FF9C0 00000000 */  nop
    /* 2FF9C4 003FF9C4 FAFF4014 */  bnez       $2, .L003FF9B0
    /* 2FF9C8 003FF9C8 00000000 */   nop
    /* 2FF9CC 003FF9CC 04000324 */  addiu      $3, $0, 0x4
    /* 2FF9D0 003FF9D0 0110023C */  lui        $2, (0x10010000 >> 16)
    /* 2FF9D4 003FF9D4 10E043AC */  sw         $3, -0x1FF0($2)
    /* 2FF9D8 003FF9D8 8900023C */  lui        $2, %hi(D_0088C9D0)
    /* 2FF9DC 003FF9DC D0C9438C */  lw         $3, %lo(D_0088C9D0)($2)
    /* 2FF9E0 003FF9E0 10000224 */  addiu      $2, $0, 0x10
    /* 2FF9E4 003FF9E4 03006214 */  bne        $3, $2, .L003FF9F4
    /* 2FF9E8 003FF9E8 00000000 */   nop
    /* 2FF9EC 003FF9EC 02000010 */  b          .L003FF9F8
    /* 2FF9F0 003FF9F0 0A000224 */   addiu     $2, $0, 0xA
  .L003FF9F4:
    /* 2FF9F4 003FF9F4 2D100000 */  daddu      $2, $0, $0
  .L003FF9F8:
    /* 2FF9F8 003FF9F8 3C2C0200 */  dsll32     $5, $2, 16
    /* 2FF9FC 003FF9FC 8900043C */  lui        $4, %hi(D_0088BC00)
    /* 2FFA00 003FFA00 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 2FFA04 003FFA04 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FFA08 003FFA08 C8C94684 */  lh         $6, %lo(D_0088C9C8)($2)
    /* 2FFA0C 003FFA0C 00BC8424 */  addiu      $4, $4, %lo(D_0088BC00)
    /* 2FFA10 003FFA10 2D400000 */  daddu      $8, $0, $0
    /* 2FFA14 003FFA14 8900023C */  lui        $2, %hi(D_0088C9CC)
    /* 2FFA18 003FFA18 CCC94784 */  lh         $7, %lo(D_0088C9CC)($2)
    /* 2FFA1C 003FFA1C F25D100C */  jal        func_004177c8
    /* 2FFA20 003FFA20 2D480000 */   daddu     $9, $0, $0
    /* 2FFA24 003FFA24 8900023C */  lui        $2, %hi(D_0088C9D0)
    /* 2FFA28 003FFA28 10000324 */  addiu      $3, $0, 0x10
    /* 2FFA2C 003FFA2C D0C9428C */  lw         $2, %lo(D_0088C9D0)($2)
    /* 2FFA30 003FFA30 03004314 */  bne        $2, $3, .L003FFA40
    /* 2FFA34 003FFA34 00000000 */   nop
    /* 2FFA38 003FFA38 02000010 */  b          .L003FFA44
    /* 2FFA3C 003FFA3C 0A000224 */   addiu     $2, $0, 0xA
  .L003FFA40:
    /* 2FFA40 003FFA40 2D100000 */  daddu      $2, $0, $0
  .L003FFA44:
    /* 2FFA44 003FFA44 3C2C0200 */  dsll32     $5, $2, 16
    /* 2FFA48 003FFA48 8900043C */  lui        $4, %hi(D_0088BC28)
    /* 2FFA4C 003FFA4C 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 2FFA50 003FFA50 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FFA54 003FFA54 C8C94684 */  lh         $6, %lo(D_0088C9C8)($2)
    /* 2FFA58 003FFA58 28BC8424 */  addiu      $4, $4, %lo(D_0088BC28)
    /* 2FFA5C 003FFA5C 2D400000 */  daddu      $8, $0, $0
    /* 2FFA60 003FFA60 8900023C */  lui        $2, %hi(D_0088C9CC)
    /* 2FFA64 003FFA64 CCC94784 */  lh         $7, %lo(D_0088C9CC)($2)
    /* 2FFA68 003FFA68 F25D100C */  jal        func_004177c8
    /* 2FFA6C 003FFA6C 2D480000 */   daddu     $9, $0, $0
    /* 2FFA70 003FFA70 00AC838F */  lw         $3, -0x5400($28)
    /* 2FFA74 003FFA74 10000224 */  addiu      $2, $0, 0x10
    /* 2FFA78 003FFA78 03006214 */  bne        $3, $2, .L003FFA88
    /* 2FFA7C 003FFA7C 00000000 */   nop
    /* 2FFA80 003FFA80 02000010 */  b          .L003FFA8C
    /* 2FFA84 003FFA84 3A000424 */   addiu     $4, $0, 0x3A
  .L003FFA88:
    /* 2FFA88 003FFA88 31000424 */  addiu      $4, $0, 0x31
  .L003FFA8C:
    /* 2FFA8C 003FFA8C 8900023C */  lui        $2, %hi(D_0088C9B8)
    /* 2FFA90 003FFA90 10000324 */  addiu      $3, $0, 0x10
    /* 2FFA94 003FFA94 B8C9428C */  lw         $2, %lo(D_0088C9B8)($2)
    /* 2FFA98 003FFA98 03004314 */  bne        $2, $3, .L003FFAA8
    /* 2FFA9C 003FFA9C 00000000 */   nop
    /* 2FFAA0 003FFAA0 02000010 */  b          .L003FFAAC
    /* 2FFAA4 003FFAA4 0A000224 */   addiu     $2, $0, 0xA
  .L003FFAA8:
    /* 2FFAA8 003FFAA8 2D100000 */  daddu      $2, $0, $0
  .L003FFAAC:
    /* 2FFAAC 003FFAAC 3C2C0200 */  dsll32     $5, $2, 16
    /* 2FFAB0 003FFAB0 3C4C0400 */  dsll32     $9, $4, 16
    /* 2FFAB4 003FFAB4 8900033C */  lui        $3, %hi(D_0088C9B0)
    /* 2FFAB8 003FFAB8 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFABC 003FFABC B0C96684 */  lh         $6, %lo(D_0088C9B0)($3)
    /* 2FFAC0 003FFAC0 8900043C */  lui        $4, %hi(D_0088BC60)
    /* 2FFAC4 003FFAC4 B4C94784 */  lh         $7, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFAC8 003FFAC8 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FFACC 003FFACC 3F4C0900 */  dsra32     $9, $9, 16
    /* 2FFAD0 003FFAD0 60BC8424 */  addiu      $4, $4, %lo(D_0088BC60)
    /* 2FFAD4 003FFAD4 325F100C */  jal        func_00417cc8
    /* 2FFAD8 003FFAD8 02000824 */   addiu     $8, $0, 0x2
    /* 2FFADC 003FFADC 00AC838F */  lw         $3, -0x5400($28)
    /* 2FFAE0 003FFAE0 10000224 */  addiu      $2, $0, 0x10
    /* 2FFAE4 003FFAE4 03006214 */  bne        $3, $2, .L003FFAF4
    /* 2FFAE8 003FFAE8 00000000 */   nop
    /* 2FFAEC 003FFAEC 02000010 */  b          .L003FFAF8
    /* 2FFAF0 003FFAF0 3A000424 */   addiu     $4, $0, 0x3A
  .L003FFAF4:
    /* 2FFAF4 003FFAF4 31000424 */  addiu      $4, $0, 0x31
  .L003FFAF8:
    /* 2FFAF8 003FFAF8 8900023C */  lui        $2, %hi(D_0088C9B8)
    /* 2FFAFC 003FFAFC 10000324 */  addiu      $3, $0, 0x10
    /* 2FFB00 003FFB00 B8C9428C */  lw         $2, %lo(D_0088C9B8)($2)
    /* 2FFB04 003FFB04 03004314 */  bne        $2, $3, .L003FFB14
    /* 2FFB08 003FFB08 00000000 */   nop
    /* 2FFB0C 003FFB0C 02000010 */  b          .L003FFB18
    /* 2FFB10 003FFB10 0A000224 */   addiu     $2, $0, 0xA
  .L003FFB14:
    /* 2FFB14 003FFB14 2D100000 */  daddu      $2, $0, $0
  .L003FFB18:
    /* 2FFB18 003FFB18 3C2C0200 */  dsll32     $5, $2, 16
    /* 2FFB1C 003FFB1C 3C4C0400 */  dsll32     $9, $4, 16
    /* 2FFB20 003FFB20 8900033C */  lui        $3, %hi(D_0088C9B0)
    /* 2FFB24 003FFB24 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFB28 003FFB28 B0C96684 */  lh         $6, %lo(D_0088C9B0)($3)
    /* 2FFB2C 003FFB2C 8900043C */  lui        $4, %hi(D_0088BCE0)
    /* 2FFB30 003FFB30 B4C94784 */  lh         $7, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFB34 003FFB34 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FFB38 003FFB38 3F4C0900 */  dsra32     $9, $9, 16
    /* 2FFB3C 003FFB3C E0BC8424 */  addiu      $4, $4, %lo(D_0088BCE0)
    /* 2FFB40 003FFB40 EE62100C */  jal        func_00418bb8
    /* 2FFB44 003FFB44 02000824 */   addiu     $8, $0, 0x2
    /* 2FFB48 003FFB48 00AC838F */  lw         $3, -0x5400($28)
    /* 2FFB4C 003FFB4C 10000224 */  addiu      $2, $0, 0x10
    /* 2FFB50 003FFB50 03006214 */  bne        $3, $2, .L003FFB60
    /* 2FFB54 003FFB54 00000000 */   nop
    /* 2FFB58 003FFB58 02000010 */  b          .L003FFB64
    /* 2FFB5C 003FFB5C 3A000424 */   addiu     $4, $0, 0x3A
  .L003FFB60:
    /* 2FFB60 003FFB60 31000424 */  addiu      $4, $0, 0x31
  .L003FFB64:
    /* 2FFB64 003FFB64 8900023C */  lui        $2, %hi(D_0088C9B8)
    /* 2FFB68 003FFB68 10000324 */  addiu      $3, $0, 0x10
    /* 2FFB6C 003FFB6C B8C9428C */  lw         $2, %lo(D_0088C9B8)($2)
    /* 2FFB70 003FFB70 03004314 */  bne        $2, $3, .L003FFB80
    /* 2FFB74 003FFB74 00000000 */   nop
    /* 2FFB78 003FFB78 02000010 */  b          .L003FFB84
    /* 2FFB7C 003FFB7C 0A000224 */   addiu     $2, $0, 0xA
  .L003FFB80:
    /* 2FFB80 003FFB80 2D100000 */  daddu      $2, $0, $0
  .L003FFB84:
    /* 2FFB84 003FFB84 3C2C0200 */  dsll32     $5, $2, 16
    /* 2FFB88 003FFB88 3C4C0400 */  dsll32     $9, $4, 16
    /* 2FFB8C 003FFB8C 8900033C */  lui        $3, %hi(D_0088C9B0)
    /* 2FFB90 003FFB90 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFB94 003FFB94 B0C96684 */  lh         $6, %lo(D_0088C9B0)($3)
    /* 2FFB98 003FFB98 8900043C */  lui        $4, %hi(D_0088BDD0)
    /* 2FFB9C 003FFB9C B4C94784 */  lh         $7, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFBA0 003FFBA0 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FFBA4 003FFBA4 3F4C0900 */  dsra32     $9, $9, 16
    /* 2FFBA8 003FFBA8 D0BD8424 */  addiu      $4, $4, %lo(D_0088BDD0)
    /* 2FFBAC 003FFBAC 325F100C */  jal        func_00417cc8
    /* 2FFBB0 003FFBB0 02000824 */   addiu     $8, $0, 0x2
    /* 2FFBB4 003FFBB4 00AC838F */  lw         $3, -0x5400($28)
    /* 2FFBB8 003FFBB8 10000224 */  addiu      $2, $0, 0x10
    /* 2FFBBC 003FFBBC 03006214 */  bne        $3, $2, .L003FFBCC
    /* 2FFBC0 003FFBC0 00000000 */   nop
    /* 2FFBC4 003FFBC4 02000010 */  b          .L003FFBD0
    /* 2FFBC8 003FFBC8 3A000424 */   addiu     $4, $0, 0x3A
  .L003FFBCC:
    /* 2FFBCC 003FFBCC 31000424 */  addiu      $4, $0, 0x31
  .L003FFBD0:
    /* 2FFBD0 003FFBD0 8900023C */  lui        $2, %hi(D_0088C9B8)
    /* 2FFBD4 003FFBD4 10000324 */  addiu      $3, $0, 0x10
    /* 2FFBD8 003FFBD8 B8C9428C */  lw         $2, %lo(D_0088C9B8)($2)
    /* 2FFBDC 003FFBDC 03004314 */  bne        $2, $3, .L003FFBEC
    /* 2FFBE0 003FFBE0 00000000 */   nop
    /* 2FFBE4 003FFBE4 02000010 */  b          .L003FFBF0
    /* 2FFBE8 003FFBE8 0A000224 */   addiu     $2, $0, 0xA
  .L003FFBEC:
    /* 2FFBEC 003FFBEC 2D100000 */  daddu      $2, $0, $0
  .L003FFBF0:
    /* 2FFBF0 003FFBF0 3C2C0200 */  dsll32     $5, $2, 16
    /* 2FFBF4 003FFBF4 3C4C0400 */  dsll32     $9, $4, 16
    /* 2FFBF8 003FFBF8 8900033C */  lui        $3, %hi(D_0088C9B0)
    /* 2FFBFC 003FFBFC 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFC00 003FFC00 B0C96684 */  lh         $6, %lo(D_0088C9B0)($3)
    /* 2FFC04 003FFC04 8900043C */  lui        $4, %hi(D_0088BE50)
    /* 2FFC08 003FFC08 B4C94784 */  lh         $7, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFC0C 003FFC0C 3F2C0500 */  dsra32     $5, $5, 16
    /* 2FFC10 003FFC10 3F4C0900 */  dsra32     $9, $9, 16
    /* 2FFC14 003FFC14 50BE8424 */  addiu      $4, $4, %lo(D_0088BE50)
    /* 2FFC18 003FFC18 EE62100C */  jal        func_00418bb8
    /* 2FFC1C 003FFC1C 02000824 */   addiu     $8, $0, 0x2
    /* 2FFC20 003FFC20 2D180000 */  daddu      $3, $0, $0
    /* 2FFC24 003FFC24 2D100000 */  daddu      $2, $0, $0
    /* 2FFC28 003FFC28 895B6270 */  pcpyld     $11, $3, $2
    /* 2FFC2C 003FFC2C 8900023C */  lui        $2, %hi(D_0088BC50)
    /* 2FFC30 003FFC30 00800824 */  addiu      $8, $0, -0x8000
    /* 2FFC34 003FFC34 50BC4B7C */  sq         $11, %lo(D_0088BC50)($2)
    /* 2FFC38 003FFC38 10000964 */  daddiu     $9, $0, 0x10
    /* 2FFC3C 003FFC3C 8900023C */  lui        $2, %hi(D_0088BC50)
    /* 2FFC40 003FFC40 FFFF0424 */  addiu      $4, $0, -0x1
    /* 2FFC44 003FFC44 50BC4CDC */  ld         $12, %lo(D_0088BC50)($2)
    /* 2FFC48 003FFC48 89000E3C */  lui        $14, %hi(D_0088BC58)
    /* 2FFC4C 003FFC4C 89000D3C */  lui        $13, %hi(D_0088BDC0)
    /* 2FFC50 003FFC50 10000A24 */  addiu      $10, $0, 0x10
    /* 2FFC54 003FFC54 01000264 */  daddiu     $2, $0, 0x1
    /* 2FFC58 003FFC58 24608801 */  and        $12, $12, $8
    /* 2FFC5C 003FFC5C F83B0200 */  dsll       $7, $2, 15
    /* 2FFC60 003FFC60 3C2F0200 */  dsll32     $5, $2, 28
    /* 2FFC64 003FFC64 FFFF023C */  lui        $2, (0xFFFF7FFF >> 16)
    /* 2FFC68 003FFC68 25608901 */  or         $12, $12, $9
    /* 2FFC6C 003FFC6C FF7F4634 */  ori        $6, $2, (0xFFFF7FFF & 0xFFFF)
    /* 2FFC70 003FFC70 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* 2FFC74 003FFC74 24608601 */  and        $12, $12, $6
    /* 2FFC78 003FFC78 FFFF4334 */  ori        $3, $2, (0xFFFFFFF & 0xFFFF)
    /* 2FFC7C 003FFC7C FFFF0234 */  ori        $2, $0, 0xFFFF
    /* 2FFC80 003FFC80 3C180300 */  dsll32     $3, $3, 0
    /* 2FFC84 003FFC84 38140200 */  dsll       $2, $2, 16
    /* 2FFC88 003FFC88 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* 2FFC8C 003FFC8C 25104300 */  or         $2, $2, $3
    /* 2FFC90 003FFC90 25188701 */  or         $3, $12, $7
    /* 2FFC94 003FFC94 89238270 */  pcpyld     $4, $4, $2
    /* 2FFC98 003FFC98 24106400 */  and        $2, $3, $4
    /* 2FFC9C 003FFC9C 25604500 */  or         $12, $2, $5
    /* 2FFCA0 003FFCA0 8900033C */  lui        $3, %hi(D_0088BC50)
    /* 2FFCA4 003FFCA4 50BC6CFC */  sd         $12, %lo(D_0088BC50)($3)
    /* 2FFCA8 003FFCA8 8900023C */  lui        $2, %hi(D_0088BC58)
    /* 2FFCAC 003FFCAC 89000C3C */  lui        $12, %hi(D_0088BDC0)
    /* 2FFCB0 003FFCB0 58BC51DC */  ld         $17, %lo(D_0088BC58)($2)
    /* 2FFCB4 003FFCB4 C0BD8B7D */  sq         $11, %lo(D_0088BDC0)($12)
    /* 2FFCB8 003FFCB8 0E000364 */  daddiu     $3, $0, 0xE
    /* 2FFCBC 003FFCBC 89000B3C */  lui        $11, %hi(D_0088BDC0)
    /* 2FFCC0 003FFCC0 89000C3C */  lui        $12, %hi(D_0088BDC8)
    /* 2FFCC4 003FFCC4 C0BD70DD */  ld         $16, %lo(D_0088BDC0)($11)
    /* 2FFCC8 003FFCC8 F0FF0224 */  addiu      $2, $0, -0x10
    /* 2FFCCC 003FFCCC 24882202 */  and        $17, $17, $2
    /* 2FFCD0 003FFCD0 25882302 */  or         $17, $17, $3
    /* 2FFCD4 003FFCD4 89000B3C */  lui        $11, %hi(D_0088BDC8)
    /* 2FFCD8 003FFCD8 24400802 */  and        $8, $16, $8
    /* 2FFCDC 003FFCDC C8BD6FDD */  ld         $15, %lo(D_0088BDC8)($11)
    /* 2FFCE0 003FFCE0 25400901 */  or         $8, $8, $9
    /* 2FFCE4 003FFCE4 24300601 */  and        $6, $8, $6
    /* 2FFCE8 003FFCE8 58BCD1FD */  sd         $17, %lo(D_0088BC58)($14)
    /* 2FFCEC 003FFCEC 2530C700 */  or         $6, $6, $7
    /* 2FFCF0 003FFCF0 89000B3C */  lui        $11, %hi(D_0088C9E3)
    /* 2FFCF4 003FFCF4 2410E201 */  and        $2, $15, $2
    /* 2FFCF8 003FFCF8 E3C96B91 */  lbu        $11, %lo(D_0088C9E3)($11)
    /* 2FFCFC 003FFCFC 25104300 */  or         $2, $2, $3
    /* 2FFD00 003FFD00 C8BD82FD */  sd         $2, %lo(D_0088BDC8)($12)
    /* 2FFD04 003FFD04 2410C400 */  and        $2, $6, $4
    /* 2FFD08 003FFD08 25104500 */  or         $2, $2, $5
    /* 2FFD0C 003FFD0C 30006011 */  beqz       $11, .L003FFDD0
    /* 2FFD10 003FFD10 C0BDA2FD */   sd        $2, %lo(D_0088BDC0)($13)
    /* 2FFD14 003FFD14 8900023C */  lui        $2, %hi(D_0088C9B8)
    /* 2FFD18 003FFD18 B8C9458C */  lw         $5, %lo(D_0088C9B8)($2)
    /* 2FFD1C 003FFD1C 0700AA14 */  bne        $5, $10, .L003FFD3C
    /* 2FFD20 003FFD20 00000000 */   nop
    /* 2FFD24 003FFD24 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFD28 003FFD28 C0FF0324 */  addiu      $3, $0, -0x40
    /* 2FFD2C 003FFD2C B4C9448C */  lw         $4, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFD30 003FFD30 3F008224 */  addiu      $2, $4, 0x3F
    /* 2FFD34 003FFD34 06000010 */  b          .L003FFD50
    /* 2FFD38 003FFD38 24304300 */   and       $6, $2, $3
  .L003FFD3C:
    /* 2FFD3C 003FFD3C 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFD40 003FFD40 E0FF0324 */  addiu      $3, $0, -0x20
    /* 2FFD44 003FFD44 B4C9448C */  lw         $4, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFD48 003FFD48 1F008224 */  addiu      $2, $4, 0x1F
    /* 2FFD4C 003FFD4C 24304300 */  and        $6, $2, $3
  .L003FFD50:
    /* 2FFD50 003FFD50 8900023C */  lui        $2, %hi(D_0088C9B0)
    /* 2FFD54 003FFD54 C0FF0324 */  addiu      $3, $0, -0x40
    /* 2FFD58 003FFD58 B0C9428C */  lw         $2, %lo(D_0088C9B0)($2)
    /* 2FFD5C 003FFD5C 3F004224 */  addiu      $2, $2, 0x3F
    /* 2FFD60 003FFD60 24184300 */  and        $3, $2, $3
    /* 2FFD64 003FFD64 18306600 */  mult       $6, $3, $6
    /* 2FFD68 003FFD68 1000A238 */  xori       $2, $5, 0x10
    /* 2FFD6C 003FFD6C 0100452C */  sltiu      $5, $2, 0x1
    /* 2FFD70 003FFD70 00FE0B24 */  addiu      $11, $0, -0x200
    /* 2FFD74 003FFD74 8900023C */  lui        $2, %hi(D_0088BC38)
    /* 2FFD78 003FFD78 8900083C */  lui        $8, %hi(D_0088BC38)
    /* 2FFD7C 003FFD7C 38BC4A8C */  lw         $10, %lo(D_0088BC38)($2)
    /* 2FFD80 003FFD80 8900073C */  lui        $7, %hi(D_0088BC60)
    /* 2FFD84 003FFD84 0628A600 */  srlv       $5, $6, $5
    /* 2FFD88 003FFD88 8900063C */  lui        $6, %hi(D_0088BCE0)
    /* 2FFD8C 003FFD8C E0BCC6DC */  ld         $6, %lo(D_0088BCE0)($6)
    /* 2FFD90 003FFD90 8900023C */  lui        $2, %hi(D_0088BC60)
    /* 2FFD94 003FFD94 24504B01 */  and        $10, $10, $11
    /* 2FFD98 003FFD98 60BC49DC */  ld         $9, %lo(D_0088BC60)($2)
    /* 2FFD9C 003FFD9C 2430CB00 */  and        $6, $6, $11
    /* 2FFDA0 003FFDA0 C2120500 */  srl        $2, $5, 11
    /* 2FFDA4 003FFDA4 FF014C30 */  andi       $12, $2, 0x1FF
    /* 2FFDA8 003FFDA8 40280200 */  sll        $5, $2, 1
    /* 2FFDAC 003FFDAC 25504C01 */  or         $10, $10, $12
    /* 2FFDB0 003FFDB0 8900023C */  lui        $2, %hi(D_0088BCE0)
    /* 2FFDB4 003FFDB4 38BC0AAD */  sw         $10, %lo(D_0088BC38)($8)
    /* 2FFDB8 003FFDB8 2530CC00 */  or         $6, $6, $12
    /* 2FFDBC 003FFDBC 24402B01 */  and        $8, $9, $11
    /* 2FFDC0 003FFDC0 E0BC46FC */  sd         $6, %lo(D_0088BCE0)($2)
    /* 2FFDC4 003FFDC4 25400C01 */  or         $8, $8, $12
    /* 2FFDC8 003FFDC8 5A000010 */  b          .L003FFF34
    /* 2FFDCC 003FFDCC 60BCE8FC */   sd        $8, %lo(D_0088BC60)($7)
  .L003FFDD0:
    /* 2FFDD0 003FFDD0 8900023C */  lui        $2, %hi(D_0088C9D0)
    /* 2FFDD4 003FFDD4 D0C9468C */  lw         $6, %lo(D_0088C9D0)($2)
    /* 2FFDD8 003FFDD8 0700CA14 */  bne        $6, $10, .L003FFDF8
    /* 2FFDDC 003FFDDC 00000000 */   nop
    /* 2FFDE0 003FFDE0 8900023C */  lui        $2, %hi(D_0088C9CC)
    /* 2FFDE4 003FFDE4 C0FF0324 */  addiu      $3, $0, -0x40
    /* 2FFDE8 003FFDE8 CCC9428C */  lw         $2, %lo(D_0088C9CC)($2)
    /* 2FFDEC 003FFDEC 3F004224 */  addiu      $2, $2, 0x3F
    /* 2FFDF0 003FFDF0 06000010 */  b          .L003FFE0C
    /* 2FFDF4 003FFDF4 24204300 */   and       $4, $2, $3
  .L003FFDF8:
    /* 2FFDF8 003FFDF8 8900023C */  lui        $2, %hi(D_0088C9CC)
    /* 2FFDFC 003FFDFC E0FF0324 */  addiu      $3, $0, -0x20
    /* 2FFE00 003FFE00 CCC9428C */  lw         $2, %lo(D_0088C9CC)($2)
    /* 2FFE04 003FFE04 1F004224 */  addiu      $2, $2, 0x1F
    /* 2FFE08 003FFE08 24204300 */  and        $4, $2, $3
  .L003FFE0C:
    /* 2FFE0C 003FFE0C 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 2FFE10 003FFE10 C0FF0324 */  addiu      $3, $0, -0x40
    /* 2FFE14 003FFE14 C8C9428C */  lw         $2, %lo(D_0088C9C8)($2)
    /* 2FFE18 003FFE18 3F004224 */  addiu      $2, $2, 0x3F
    /* 2FFE1C 003FFE1C 24104300 */  and        $2, $2, $3
    /* 2FFE20 003FFE20 18284400 */  mult       $5, $2, $4
    /* 2FFE24 003FFE24 1000C238 */  xori       $2, $6, 0x10
    /* 2FFE28 003FFE28 0100442C */  sltiu      $4, $2, 0x1
    /* 2FFE2C 003FFE2C 8900023C */  lui        $2, %hi(D_0088C9E1)
    /* 2FFE30 003FFE30 06208500 */  srlv       $4, $5, $4
    /* 2FFE34 003FFE34 E1C94390 */  lbu        $3, %lo(D_0088C9E1)($2)
    /* 2FFE38 003FFE38 02000224 */  addiu      $2, $0, 0x2
    /* 2FFE3C 003FFE3C 1E046210 */  beq        $3, $2, .L00400EB8
    /* 2FFE40 003FFE40 C22A0400 */   srl       $5, $4, 11
  .L003FFE44:
    /* 2FFE44 003FFE44 8900023C */  lui        $2, %hi(D_0088BDD0)
    /* 2FFE48 003FFE48 00FE0924 */  addiu      $9, $0, -0x200
    /* 2FFE4C 003FFE4C D0BD4BDC */  ld         $11, %lo(D_0088BDD0)($2)
    /* 2FFE50 003FFE50 FF01AA30 */  andi       $10, $5, 0x1FF
    /* 2FFE54 003FFE54 8900043C */  lui        $4, %hi(D_0088BDD0)
    /* 2FFE58 003FFE58 8900033C */  lui        $3, %hi(D_0088BE50)
    /* 2FFE5C 003FFE5C 10000624 */  addiu      $6, $0, 0x10
    /* 2FFE60 003FFE60 8900023C */  lui        $2, %hi(D_0088BE50)
    /* 2FFE64 003FFE64 50BE48DC */  ld         $8, %lo(D_0088BE50)($2)
    /* 2FFE68 003FFE68 8900023C */  lui        $2, %hi(D_0088C9B8)
    /* 2FFE6C 003FFE6C B8C9478C */  lw         $7, %lo(D_0088C9B8)($2)
    /* 2FFE70 003FFE70 24106901 */  and        $2, $11, $9
    /* 2FFE74 003FFE74 25104A00 */  or         $2, $2, $10
    /* 2FFE78 003FFE78 D0BD82FC */  sd         $2, %lo(D_0088BDD0)($4)
    /* 2FFE7C 003FFE7C 24100901 */  and        $2, $8, $9
    /* 2FFE80 003FFE80 25104A00 */  or         $2, $2, $10
    /* 2FFE84 003FFE84 0700E614 */  bne        $7, $6, .L003FFEA4
    /* 2FFE88 003FFE88 50BE62FC */   sd        $2, %lo(D_0088BE50)($3)
    /* 2FFE8C 003FFE8C 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFE90 003FFE90 C0FF0324 */  addiu      $3, $0, -0x40
    /* 2FFE94 003FFE94 B4C9448C */  lw         $4, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFE98 003FFE98 3F008224 */  addiu      $2, $4, 0x3F
    /* 2FFE9C 003FFE9C 06000010 */  b          .L003FFEB8
    /* 2FFEA0 003FFEA0 24304300 */   and       $6, $2, $3
  .L003FFEA4:
    /* 2FFEA4 003FFEA4 8900023C */  lui        $2, %hi(D_0088C9B0 + 0x4)
    /* 2FFEA8 003FFEA8 E0FF0324 */  addiu      $3, $0, -0x20
    /* 2FFEAC 003FFEAC B4C9448C */  lw         $4, %lo(D_0088C9B0 + 0x4)($2)
    /* 2FFEB0 003FFEB0 1F008224 */  addiu      $2, $4, 0x1F
    /* 2FFEB4 003FFEB4 24304300 */  and        $6, $2, $3
  .L003FFEB8:
    /* 2FFEB8 003FFEB8 8900023C */  lui        $2, %hi(D_0088C9B0)
    /* 2FFEBC 003FFEBC C0FF0324 */  addiu      $3, $0, -0x40
    /* 2FFEC0 003FFEC0 B0C9428C */  lw         $2, %lo(D_0088C9B0)($2)
    /* 2FFEC4 003FFEC4 3F004224 */  addiu      $2, $2, 0x3F
    /* 2FFEC8 003FFEC8 24184300 */  and        $3, $2, $3
    /* 2FFECC 003FFECC 18406600 */  mult       $8, $3, $6
    /* 2FFED0 003FFED0 1000E238 */  xori       $2, $7, 0x10
    /* 2FFED4 003FFED4 0100472C */  sltiu      $7, $2, 0x1
    /* 2FFED8 003FFED8 8900023C */  lui        $2, %hi(D_0088C9E0)
    /* 2FFEDC 003FFEDC E0C94690 */  lbu        $6, %lo(D_0088C9E0)($2)
    /* 2FFEE0 003FFEE0 02000224 */  addiu      $2, $0, 0x2
    /* 2FFEE4 003FFEE4 0300C214 */  bne        $6, $2, .L003FFEF4
    /* 2FFEE8 003FFEE8 0638E800 */   srlv      $7, $8, $7
    /* 2FFEEC 003FFEEC C2120700 */  srl        $2, $7, 11
    /* 2FFEF0 003FFEF0 2128A200 */  addu       $5, $5, $2
  .L003FFEF4:
    /* 2FFEF4 003FFEF4 8900023C */  lui        $2, %hi(D_0088BC60)
    /* 2FFEF8 003FFEF8 C2320700 */  srl        $6, $7, 11
    /* 2FFEFC 003FFEFC 60BC48DC */  ld         $8, %lo(D_0088BC60)($2)
    /* 2FFF00 003FFF00 FF01AA30 */  andi       $10, $5, 0x1FF
    /* 2FFF04 003FFF04 00FE0924 */  addiu      $9, $0, -0x200
    /* 2FFF08 003FFF08 2128A600 */  addu       $5, $5, $6
    /* 2FFF0C 003FFF0C 8900063C */  lui        $6, %hi(D_0088BC60)
    /* 2FFF10 003FFF10 8900023C */  lui        $2, %hi(D_0088BCE0)
    /* 2FFF14 003FFF14 24400901 */  and        $8, $8, $9
    /* 2FFF18 003FFF18 E0BC47DC */  ld         $7, %lo(D_0088BCE0)($2)
    /* 2FFF1C 003FFF1C 25400A01 */  or         $8, $8, $10
    /* 2FFF20 003FFF20 60BCC8FC */  sd         $8, %lo(D_0088BC60)($6)
    /* 2FFF24 003FFF24 2430E900 */  and        $6, $7, $9
    /* 2FFF28 003FFF28 8900023C */  lui        $2, %hi(D_0088BCE0)
    /* 2FFF2C 003FFF2C 2530CA00 */  or         $6, $6, $10
    /* 2FFF30 003FFF30 E0BC46FC */  sd         $6, %lo(D_0088BCE0)($2)
  .L003FFF34:
    /* 2FFF34 003FFF34 8900063C */  lui        $6, %hi(D_0088BC70)
    /* 2FFF38 003FFF38 00FE1024 */  addiu      $16, $0, -0x200
    /* 2FFF3C 003FFF3C 70BCCADC */  ld         $10, %lo(D_0088BC70)($6)
    /* 2FFF40 003FFF40 FF01A230 */  andi       $2, $5, 0x1FF
    /* 2FFF44 003FFF44 8900093C */  lui        $9, %hi(D_0088BC70)
    /* 2FFF48 003FFF48 00AC8B8F */  lw         $11, -0x5400($28)
    /* 2FFF4C 003FFF4C 8900083C */  lui        $8, %hi(D_0088BCF0)
    /* 2FFF50 003FFF50 8900073C */  lui        $7, %hi(D_0088BDE0)
    /* 2FFF54 003FFF54 8900063C */  lui        $6, %hi(D_0088BCF0)
    /* 2FFF58 003FFF58 24505001 */  and        $10, $10, $16
    /* 2FFF5C 003FFF5C F0BCCEDC */  ld         $14, %lo(D_0088BCF0)($6)
    /* 2FFF60 003FFF60 25784201 */  or         $15, $10, $2
    /* 2FFF64 003FFF64 70BC2FFD */  sd         $15, %lo(D_0088BC70)($9)
    /* 2FFF68 003FFF68 10000A24 */  addiu      $10, $0, 0x10
    /* 2FFF6C 003FFF6C 8900063C */  lui        $6, %hi(D_0088BDE0)
    /* 2FFF70 003FFF70 2448D001 */  and        $9, $14, $16
    /* 2FFF74 003FFF74 E0BDCDDC */  ld         $13, %lo(D_0088BDE0)($6)
    /* 2FFF78 003FFF78 25482201 */  or         $9, $9, $2
    /* 2FFF7C 003FFF7C F0BC09FD */  sd         $9, %lo(D_0088BCF0)($8)
    /* 2FFF80 003FFF80 8900063C */  lui        $6, %hi(D_0088BE60)
    /* 2FFF84 003FFF84 2448B001 */  and        $9, $13, $16
    /* 2FFF88 003FFF88 60BECCDC */  ld         $12, %lo(D_0088BE60)($6)
    /* 2FFF8C 003FFF8C 25482201 */  or         $9, $9, $2
    /* 2FFF90 003FFF90 E0BDE9FC */  sd         $9, %lo(D_0088BDE0)($7)
    /* 2FFF94 003FFF94 24409001 */  and        $8, $12, $16
    /* 2FFF98 003FFF98 8900063C */  lui        $6, %hi(D_0088BE60)
    /* 2FFF9C 003FFF9C 25100201 */  or         $2, $8, $2
    /* 2FFFA0 003FFFA0 05006A15 */  bne        $11, $10, .L003FFFB8
    /* 2FFFA4 003FFFA4 60BEC2FC */   sd        $2, %lo(D_0088BE60)($6)
    /* 2FFFA8 003FFFA8 3F008424 */  addiu      $4, $4, 0x3F
    /* 2FFFAC 003FFFAC C0FF0224 */  addiu      $2, $0, -0x40
    /* 2FFFB0 003FFFB0 04000010 */  b          .L003FFFC4
    /* 2FFFB4 003FFFB4 24108200 */   and       $2, $4, $2
  .L003FFFB8:
    /* 2FFFB8 003FFFB8 1F008424 */  addiu      $4, $4, 0x1F
    /* 2FFFBC 003FFFBC E0FF0224 */  addiu      $2, $0, -0x20
    /* 2FFFC0 003FFFC0 24108200 */  and        $2, $4, $2
  .L003FFFC4:
    /* 2FFFC4 003FFFC4 18306200 */  mult       $6, $3, $2
    /* 2FFFC8 003FFFC8 10006239 */  xori       $2, $11, 0x10
    /* 2FFFCC 003FFFCC 0100442C */  sltiu      $4, $2, 0x1
    /* 2FFFD0 003FFFD0 8900023C */  lui        $2, %hi(D_0088C9D4)
    /* 2FFFD4 003FFFD4 D4C9438C */  lw         $3, %lo(D_0088C9D4)($2)
    /* 2FFFD8 003FFFD8 06108600 */  srlv       $2, $6, $4
    /* 2FFFDC 003FFFDC C2120200 */  srl        $2, $2, 11
    /* 2FFFE0 003FFFE0 2110A200 */  addu       $2, $5, $2
    /* 2FFFE4 003FFFE4 C0120200 */  sll        $2, $2, 11
    /* 2FFFE8 003FFFE8 2CB982AF */  sw         $2, -0x46D4($28)
    /* 2FFFEC 003FFFEC 02006230 */  andi       $2, $3, 0x2
    /* 2FFFF0 003FFFF0 0A004010 */  beqz       $2, .L0040001C
    /* 2FFFF4 003FFFF4 00000000 */   nop
    /* 2FFFF8 003FFFF8 00026230 */  andi       $2, $3, 0x200
    /* 2FFFFC 003FFFFC B8034014 */  bnez       $2, .L00400EE0
    /* 300000 00400000 00000000 */   nop
  .L00400004:
    /* 300004 00400004 8900023C */  lui        $2, %hi(D_0088BFD0)
    /* 300008 00400008 8900043C */  lui        $4, %hi(D_0088BC00)
    /* 30000C 0040000C D0BF4224 */  addiu      $2, $2, %lo(D_0088BFD0)
    /* 300010 00400010 00BC8424 */  addiu      $4, $4, %lo(D_0088BC00)
    /* 300014 00400014 3688100C */  jal        func_004220d8
    /* 300018 00400018 7F004524 */   addiu     $5, $2, 0x7F
  .L0040001C:
    /* 30001C 0040001C 2CB9848F */  lw         $4, -0x46D4($28)
    /* 300020 00400020 1000023C */  lui        $2, (0x100000 >> 16)
    /* 300024 00400024 B83B100C */  jal        func_0040eee0
    /* 300028 00400028 23284400 */   subu      $5, $2, $4
    /* 30002C 0040002C 01000424 */  addiu      $4, $0, 0x1
    /* 300030 00400030 24B980AF */  sw         $0, -0x46DC($28)
    /* 300034 00400034 A4B884AF */  sw         $4, -0x475C($28)
    /* 300038 00400038 D463100C */  jal        func_00418f50
    /* 30003C 0040003C BCB880AF */   sw        $0, -0x4744($28)
    /* 300040 00400040 7400053C */  lui        $5, %hi(D_00746400)
    /* 300044 00400044 2D204000 */  daddu      $4, $2, $0
    /* 300048 00400048 A064100C */  jal        func_00419280
    /* 30004C 0040004C 0064A524 */   addiu     $5, $5, %lo(D_00746400)
  .L00400050:
    /* 300050 00400050 01000424 */  addiu      $4, $0, 0x1
    /* 300054 00400054 0C60100C */  jal        func_00418030
    /* 300058 00400058 2D280000 */   daddu     $5, $0, $0
    /* 30005C 0040005C 00000000 */  nop
    /* 300060 00400060 00000000 */  nop
    /* 300064 00400064 FAFF4014 */  bnez       $2, .L00400050
    /* 300068 00400068 00000000 */   nop
    /* 30006C 0040006C 02000324 */  addiu      $3, $0, 0x2
    /* 300070 00400070 0110023C */  lui        $2, (0x10010000 >> 16)
    /* 300074 00400074 10E043AC */  sw         $3, -0x1FF0($2)
    /* 300078 00400078 00FF133C */  lui        $19, (0xFF00FFFF >> 16)
    /* 30007C 0040007C 8900023C */  lui        $2, %hi(D_0088BC80)
    /* 300080 00400080 FFFF7336 */  ori        $19, $19, (0xFF00FFFF & 0xFFFF)
    /* 300084 00400084 80BC49DC */  ld         $9, %lo(D_0088BC80)($2)
    /* 300088 00400088 8900063C */  lui        $6, %hi(D_0088BDF0)
    /* 30008C 0040008C 8900033C */  lui        $3, %hi(D_0088BF50)
    /* 300090 00400090 8900053C */  lui        $5, %hi(D_0088BCD0)
    /* 300094 00400094 8900043C */  lui        $4, %hi(D_0088BE40)
    /* 300098 00400098 FEFF1124 */  addiu      $17, $0, -0x2
    /* 30009C 0040009C 00F00B24 */  addiu      $11, $0, -0x1000
    /* 3000A0 004000A0 A000B37F */  sq         $19, 0xA0($29)
    /* 3000A4 004000A4 8900173C */  lui        $23, %hi(D_0088BF7C)
    /* 3000A8 004000A8 8900163C */  lui        $22, %hi(D_0088BF78)
    /* 3000AC 004000AC 89001E3C */  lui        $30, %hi(D_0088BF80)
    /* 3000B0 004000B0 8900023C */  lui        $2, %hi(D_0088BCD0)
    /* 3000B4 004000B4 F0BDC9FC */  sd         $9, %lo(D_0088BDF0)($6)
    /* 3000B8 004000B8 D0BC48DC */  ld         $8, %lo(D_0088BCD0)($2)
    /* 3000BC 004000BC 50BF668C */  lw         $6, %lo(D_0088BF50)($3)
    /* 3000C0 004000C0 8900023C */  lui        $2, %hi(D_0088BE40)
    /* 3000C4 004000C4 40BE47DC */  ld         $7, %lo(D_0088BE40)($2)
    /* 3000C8 004000C8 0B140335 */  ori        $3, $8, 0x140B
    /* 3000CC 004000CC D0BCA3FC */  sd         $3, %lo(D_0088BCD0)($5)
    /* 3000D0 004000D0 2428D100 */  and        $5, $6, $17
    /* 3000D4 004000D4 8900023C */  lui        $2, %hi(D_0088BC00)
    /* 3000D8 004000D8 0B14E334 */  ori        $3, $7, 0x140B
    /* 3000DC 004000DC 00BC428C */  lw         $2, %lo(D_0088BC00)($2)
    /* 3000E0 004000E0 40BE83FC */  sd         $3, %lo(D_0088BE40)($4)
    /* 3000E4 004000E4 BC1F0200 */  dsll32     $3, $2, 30
    /* 3000E8 004000E8 01004730 */  andi       $7, $2, 0x1
    /* 3000EC 004000EC FE1F0300 */  dsrl32     $3, $3, 31
    /* 3000F0 004000F0 2528A700 */  or         $5, $5, $7
    /* 3000F4 004000F4 01006330 */  andi       $3, $3, 0x1
    /* 3000F8 004000F8 FC260200 */  dsll32     $4, $2, 27
    /* 3000FC 004000FC 40300300 */  sll        $6, $3, 1
    /* 300100 00400100 FDFF0324 */  addiu      $3, $0, -0x3
    /* 300104 00400104 2428A300 */  and        $5, $5, $3
    /* 300108 00400108 7E1F0400 */  dsrl32     $3, $4, 29
    /* 30010C 0040010C 2528A600 */  or         $5, $5, $6
    /* 300110 00400110 07006330 */  andi       $3, $3, 0x7
    /* 300114 00400114 80200300 */  sll        $4, $3, 2
    /* 300118 00400118 E3FF0324 */  addiu      $3, $0, -0x1D
    /* 30011C 0040011C 2418A300 */  and        $3, $5, $3
    /* 300120 00400120 25206400 */  or         $4, $3, $4
    /* 300124 00400124 BC1E0200 */  dsll32     $3, $2, 26
    /* 300128 00400128 FE2F0300 */  dsrl32     $5, $3, 31
    /* 30012C 0040012C DFFF0324 */  addiu      $3, $0, -0x21
    /* 300130 00400130 0100A530 */  andi       $5, $5, 0x1
    /* 300134 00400134 24208300 */  and        $4, $4, $3
    /* 300138 00400138 40290500 */  sll        $5, $5, 5
    /* 30013C 0040013C 7C1E0200 */  dsll32     $3, $2, 25
    /* 300140 00400140 25288500 */  or         $5, $4, $5
    /* 300144 00400144 FE1F0300 */  dsrl32     $3, $3, 31
    /* 300148 00400148 01006330 */  andi       $3, $3, 0x1
    /* 30014C 0040014C 80210300 */  sll        $4, $3, 6
    /* 300150 00400150 BFFF0324 */  addiu      $3, $0, -0x41
    /* 300154 00400154 2418A300 */  and        $3, $5, $3
    /* 300158 00400158 25206400 */  or         $4, $3, $4
    /* 30015C 0040015C 3C1E0200 */  dsll32     $3, $2, 24
    /* 300160 00400160 FE1F0300 */  dsrl32     $3, $3, 31
    /* 300164 00400164 01006530 */  andi       $5, $3, 0x1
    /* 300168 00400168 7FFF0324 */  addiu      $3, $0, -0x81
    /* 30016C 0040016C C0290500 */  sll        $5, $5, 7
    /* 300170 00400170 24208300 */  and        $4, $4, $3
    /* 300174 00400174 3C1C0200 */  dsll32     $3, $2, 16
    /* 300178 00400178 25288500 */  or         $5, $4, $5
    /* 30017C 0040017C 3E1E0300 */  dsrl32     $3, $3, 24
    /* 300180 00400180 3C100200 */  dsll32     $2, $2, 0
    /* 300184 00400184 FF006330 */  andi       $3, $3, 0xFF
    /* 300188 00400188 3E140200 */  dsrl32     $2, $2, 16
    /* 30018C 0040018C 00220300 */  sll        $4, $3, 8
    /* 300190 00400190 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 300194 00400194 FFFF033C */  lui        $3, (0xFFFF00FF >> 16)
    /* 300198 00400198 00340200 */  sll        $6, $2, 16
    /* 30019C 0040019C FF007034 */  ori        $16, $3, (0xFFFF00FF & 0xFFFF)
    /* 3001A0 004001A0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3001A4 004001A4 2418B000 */  and        $3, $5, $16
    /* 3001A8 004001A8 3C100200 */  dsll32     $2, $2, 0
    /* 3001AC 004001AC 25286400 */  or         $5, $3, $4
    /* 3001B0 004001B0 FFFF0334 */  ori        $3, $0, 0xFFFF
    /* 3001B4 004001B4 8900043C */  lui        $4, %hi(D_0088BF50)
    /* 3001B8 004001B8 25C86200 */  or         $25, $3, $2
    /* 3001BC 004001BC 8900033C */  lui        $3, %hi(D_0088BC04)
    /* 3001C0 004001C0 2428B900 */  and        $5, $5, $25
    /* 3001C4 004001C4 04BC678C */  lw         $7, %lo(D_0088BC04)($3)
    /* 3001C8 004001C8 2518A600 */  or         $3, $5, $6
    /* 3001CC 004001CC 50BF83AC */  sw         $3, %lo(D_0088BF50)($4)
    /* 3001D0 004001D0 8900053C */  lui        $5, %hi(D_0088BF54)
    /* 3001D4 004001D4 8900043C */  lui        $4, %hi(D_0088BF58)
    /* 3001D8 004001D8 54BFA7AC */  sw         $7, %lo(D_0088BF54)($5)
    /* 3001DC 004001DC 58BF888C */  lw         $8, %lo(D_0088BF58)($4)
    /* 3001E0 004001E0 8900033C */  lui        $3, %hi(D_0088BC08)
    /* 3001E4 004001E4 08BC638C */  lw         $3, %lo(D_0088BC08)($3)
    /* 3001E8 004001E8 8900053C */  lui        $5, %hi(D_0088BF5C)
    /* 3001EC 004001EC 8900063C */  lui        $6, %hi(D_0088BF58)
    /* 3001F0 004001F0 0F000424 */  addiu      $4, $0, 0xF
    /* 3001F4 004001F4 24401101 */  and        $8, $8, $17
    /* 3001F8 004001F8 25C08200 */  or         $24, $4, $2
    /* 3001FC 004001FC 01006A30 */  andi       $10, $3, 0x1
    /* 300200 00400200 8900043C */  lui        $4, %hi(D_0088BC0C)
    /* 300204 00400204 25400A01 */  or         $8, $8, $10
    /* 300208 00400208 0CBC878C */  lw         $7, %lo(D_0088BC0C)($4)
    /* 30020C 0040020C 8900043C */  lui        $4, %hi(D_0088BC10)
    /* 300210 00400210 5CBFA7AC */  sw         $7, %lo(D_0088BF5C)($5)
    /* 300214 00400214 10BC898C */  lw         $9, %lo(D_0088BC10)($4)
    /* 300218 00400218 BC270300 */  dsll32     $4, $3, 30
    /* 30021C 0040021C FE270400 */  dsrl32     $4, $4, 31
    /* 300220 00400220 01008A30 */  andi       $10, $4, 0x1
    /* 300224 00400224 FDFF0424 */  addiu      $4, $0, -0x3
    /* 300228 00400228 40500A00 */  sll        $10, $10, 1
    /* 30022C 0040022C 24400401 */  and        $8, $8, $4
    /* 300230 00400230 3C270300 */  dsll32     $4, $3, 28
    /* 300234 00400234 25380A01 */  or         $7, $8, $10
    /* 300238 00400238 BE2F0400 */  dsrl32     $5, $4, 30
    /* 30023C 0040023C 3C180300 */  dsll32     $3, $3, 0
    /* 300240 00400240 F3FF0424 */  addiu      $4, $0, -0xD
    /* 300244 00400244 0300A530 */  andi       $5, $5, 0x3
    /* 300248 00400248 3E190300 */  dsrl32     $3, $3, 4
    /* 30024C 0040024C 2420E400 */  and        $4, $7, $4
    /* 300250 00400250 80280500 */  sll        $5, $5, 2
    /* 300254 00400254 3C190300 */  dsll32     $3, $3, 4
    /* 300258 00400258 25288500 */  or         $5, $4, $5
    /* 30025C 0040025C 3E190300 */  dsrl32     $3, $3, 4
    /* 300260 00400260 00210300 */  sll        $4, $3, 4
    /* 300264 00400264 FF012831 */  andi       $8, $9, 0x1FF
    /* 300268 00400268 2418B800 */  and        $3, $5, $24
    /* 30026C 0040026C 25186400 */  or         $3, $3, $4
    /* 300270 00400270 58BFC3AC */  sw         $3, %lo(D_0088BF58)($6)
    /* 300274 00400274 8900033C */  lui        $3, %hi(D_0088BF60)
    /* 300278 00400278 60BF658C */  lw         $5, %lo(D_0088BF60)($3)
    /* 30027C 0040027C 7C1C0900 */  dsll32     $3, $9, 17
    /* 300280 00400280 BE260300 */  dsrl32     $4, $3, 26
    /* 300284 00400284 3C1B0900 */  dsll32     $3, $9, 12
    /* 300288 00400288 3F008430 */  andi       $4, $4, 0x3F
    /* 30028C 0040028C FE1E0300 */  dsrl32     $3, $3, 27
    /* 300290 00400290 403A0400 */  sll        $7, $4, 9
    /* 300294 00400294 1F006330 */  andi       $3, $3, 0x1F
    /* 300298 00400298 3C200900 */  dsll32     $4, $9, 0
    /* 30029C 0040029C C0330300 */  sll        $6, $3, 15
    /* 3002A0 004002A0 00FE0324 */  addiu      $3, $0, -0x200
    /* 3002A4 004002A4 2428A300 */  and        $5, $5, $3
    /* 3002A8 004002A8 3E1D0400 */  dsrl32     $3, $4, 20
    /* 3002AC 004002AC 2528A800 */  or         $5, $5, $8
    /* 3002B0 004002B0 FF0F6430 */  andi       $4, $3, 0xFFF
    /* 3002B4 004002B4 FF810324 */  addiu      $3, $0, -0x7E01
    /* 3002B8 004002B8 2418A300 */  and        $3, $5, $3
    /* 3002BC 004002BC 002D0400 */  sll        $5, $4, 20
    /* 3002C0 004002C0 25206700 */  or         $4, $3, $7
    /* 3002C4 004002C4 F0FF033C */  lui        $3, (0xFFF07FFF >> 16)
    /* 3002C8 004002C8 FF7F6F34 */  ori        $15, $3, (0xFFF07FFF & 0xFFFF)
    /* 3002CC 004002CC 0F00033C */  lui        $3, (0xFFFFF >> 16)
    /* 3002D0 004002D0 24208F00 */  and        $4, $4, $15
    /* 3002D4 004002D4 FFFF6334 */  ori        $3, $3, (0xFFFFF & 0xFFFF)
    /* 3002D8 004002D8 25208600 */  or         $4, $4, $6
    /* 3002DC 004002DC 25706200 */  or         $14, $3, $2
    /* 3002E0 004002E0 8900063C */  lui        $6, %hi(D_0088BF64)
    /* 3002E4 004002E4 24188E00 */  and        $3, $4, $14
    /* 3002E8 004002E8 25286500 */  or         $5, $3, $5
    /* 3002EC 004002EC 8900043C */  lui        $4, %hi(D_0088BF60)
    /* 3002F0 004002F0 60BF85AC */  sw         $5, %lo(D_0088BF60)($4)
    /* 3002F4 004002F4 8900033C */  lui        $3, %hi(D_0088BC14)
    /* 3002F8 004002F8 8900043C */  lui        $4, %hi(D_0088BF64)
    /* 3002FC 004002FC 8900053C */  lui        $5, %hi(D_0088BF68)
    /* 300300 00400300 64BF888C */  lw         $8, %lo(D_0088BF64)($4)
    /* 300304 00400304 68BFA78C */  lw         $7, %lo(D_0088BF68)($5)
    /* 300308 00400308 14BC638C */  lw         $3, %lo(D_0088BC14)($3)
    /* 30030C 0040030C C0FF043C */  lui        $4, (0xFFC007FF >> 16)
    /* 300310 00400310 00F80524 */  addiu      $5, $0, -0x800
    /* 300314 00400314 FF078D34 */  ori        $13, $4, (0xFFC007FF & 0xFFFF)
    /* 300318 00400318 24400501 */  and        $8, $8, $5
    /* 30031C 0040031C 3F00043C */  lui        $4, (0x3FFFFF >> 16)
    /* 300320 00400320 FF076930 */  andi       $9, $3, 0x7FF
    /* 300324 00400324 BC2A0300 */  dsll32     $5, $3, 10
    /* 300328 00400328 FFFF8434 */  ori        $4, $4, (0x3FFFFF & 0xFFFF)
    /* 30032C 0040032C 3C180300 */  dsll32     $3, $3, 0
    /* 300330 00400330 25608200 */  or         $12, $4, $2
    /* 300334 00400334 25480901 */  or         $9, $8, $9
    /* 300338 00400338 7E2D0500 */  dsrl32     $5, $5, 21
    /* 30033C 0040033C 8900043C */  lui        $4, %hi(D_0088BC18)
    /* 300340 00400340 FF07A830 */  andi       $8, $5, 0x7FF
    /* 300344 00400344 18BC848C */  lw         $4, %lo(D_0088BC18)($4)
    /* 300348 00400348 24282D01 */  and        $5, $9, $13
    /* 30034C 0040034C C0420800 */  sll        $8, $8, 11
    /* 300350 00400350 2540A800 */  or         $8, $5, $8
    /* 300354 00400354 BE1D0300 */  dsrl32     $3, $3, 22
    /* 300358 00400358 FF036530 */  andi       $5, $3, 0x3FF
    /* 30035C 0040035C 24180C01 */  and        $3, $8, $12
    /* 300360 00400360 80450500 */  sll        $8, $5, 22
    /* 300364 00400364 25186800 */  or         $3, $3, $8
    /* 300368 00400368 FF0F8530 */  andi       $5, $4, 0xFFF
    /* 30036C 0040036C 64BFC3AC */  sw         $3, %lo(D_0088BF64)($6)
    /* 300370 00400370 2418EB00 */  and        $3, $7, $11
    /* 300374 00400374 25306500 */  or         $6, $3, $5
    /* 300378 00400378 7C1A0400 */  dsll32     $3, $4, 9
    /* 30037C 0040037C 7E2D0300 */  dsrl32     $5, $3, 21
    /* 300380 00400380 80FF033C */  lui        $3, (0xFF800FFF >> 16)
    /* 300384 00400384 FF07A530 */  andi       $5, $5, 0x7FF
    /* 300388 00400388 FF0F6A34 */  ori        $10, $3, (0xFF800FFF & 0xFFFF)
    /* 30038C 0040038C 002B0500 */  sll        $5, $5, 12
    /* 300390 00400390 2418CA00 */  and        $3, $6, $10
    /* 300394 00400394 25306500 */  or         $6, $3, $5
    /* 300398 00400398 7C190400 */  dsll32     $3, $4, 5
    /* 30039C 0040039C 3E2F0300 */  dsrl32     $5, $3, 28
    /* 3003A0 004003A0 7FF8033C */  lui        $3, (0xF87FFFFF >> 16)
    /* 3003A4 004003A4 0F00A530 */  andi       $5, $5, 0xF
    /* 3003A8 004003A8 FFFF6934 */  ori        $9, $3, (0xF87FFFFF & 0xFFFF)
    /* 3003AC 004003AC C02D0500 */  sll        $5, $5, 23
    /* 3003B0 004003B0 2418C900 */  and        $3, $6, $9
    /* 3003B4 004003B4 25186500 */  or         $3, $3, $5
    /* 3003B8 004003B8 FC280400 */  dsll32     $5, $4, 3
    /* 3003BC 004003BC BE2F0500 */  dsrl32     $5, $5, 30
    /* 3003C0 004003C0 3C200400 */  dsll32     $4, $4, 0
    /* 3003C4 004003C4 0300A530 */  andi       $5, $5, 0x3
    /* 3003C8 004003C8 7E270400 */  dsrl32     $4, $4, 29
    /* 3003CC 004003CC C03E0500 */  sll        $7, $5, 27
    /* 3003D0 004003D0 07008430 */  andi       $4, $4, 0x7
    /* 3003D4 004003D4 402F0400 */  sll        $5, $4, 29
    /* 3003D8 004003D8 FFE7043C */  lui        $4, (0xE7FFFFFF >> 16)
    /* 3003DC 004003DC FFFF8834 */  ori        $8, $4, (0xE7FFFFFF & 0xFFFF)
    /* 3003E0 004003E0 FF1F043C */  lui        $4, (0x1FFFFFFF >> 16)
    /* 3003E4 004003E4 24306800 */  and        $6, $3, $8
    /* 3003E8 004003E8 FFFF8334 */  ori        $3, $4, (0x1FFFFFFF & 0xFFFF)
    /* 3003EC 004003EC 2520C700 */  or         $4, $6, $7
    /* 3003F0 004003F0 25386200 */  or         $7, $3, $2
    /* 3003F4 004003F4 24208700 */  and        $4, $4, $7
    /* 3003F8 004003F8 8900033C */  lui        $3, %hi(D_0088BF68)
    /* 3003FC 004003FC 25288500 */  or         $5, $4, $5
    /* 300400 00400400 68BF65AC */  sw         $5, %lo(D_0088BF68)($3)
    /* 300404 00400404 8900043C */  lui        $4, %hi(D_0088BC1C)
    /* 300408 00400408 1CBC948C */  lw         $20, %lo(D_0088BC1C)($4)
    /* 30040C 0040040C 8900033C */  lui        $3, %hi(D_0088BF6C)
    /* 300410 00400410 6CBF728C */  lw         $18, %lo(D_0088BF6C)($3)
    /* 300414 00400414 8900053C */  lui        $5, %hi(D_0088BC20)
    /* 300418 00400418 20BCA58C */  lw         $5, %lo(D_0088BC20)($5)
    /* 30041C 0040041C 7F00043C */  lui        $4, (0x7FFFFF >> 16)
    /* 300420 00400420 FF0F9332 */  andi       $19, $20, 0xFFF
    /* 300424 00400424 FFFF8334 */  ori        $3, $4, (0x7FFFFF & 0xFFFF)
    /* 300428 00400428 24904B02 */  and        $18, $18, $11
    /* 30042C 0040042C 8900043C */  lui        $4, %hi(D_0088BF70)
    /* 300430 00400430 7CAA1400 */  dsll32     $21, $20, 9
    /* 300434 00400434 25905302 */  or         $18, $18, $19
    /* 300438 00400438 70BF848C */  lw         $4, %lo(D_0088BF70)($4)
    /* 30043C 0040043C 7E9D1500 */  dsrl32     $19, $21, 21
    /* 300440 00400440 25306200 */  or         $6, $3, $2
    /* 300444 00400444 FF077532 */  andi       $21, $19, 0x7FF
    /* 300448 00400448 8900033C */  lui        $3, %hi(D_0088BF6C)
    /* 30044C 0040044C 24984A02 */  and        $19, $18, $10
    /* 300450 00400450 00AB1500 */  sll        $21, $21, 12
    /* 300454 00400454 3C901400 */  dsll32     $18, $20, 0
    /* 300458 00400458 25987502 */  or         $19, $19, $21
    /* 30045C 0040045C FE951200 */  dsrl32     $18, $18, 23
    /* 300460 00400460 24986602 */  and        $19, $19, $6
    /* 300464 00400464 FF015232 */  andi       $18, $18, 0x1FF
    /* 300468 00400468 C0A51200 */  sll        $20, $18, 23
    /* 30046C 0040046C 00FF1224 */  addiu      $18, $0, -0x100
    /* 300470 00400470 25987402 */  or         $19, $19, $20
    /* 300474 00400474 24209200 */  and        $4, $4, $18
    /* 300478 00400478 6CBF73AC */  sw         $19, %lo(D_0088BF6C)($3)
    /* 30047C 0040047C FF00B230 */  andi       $18, $5, 0xFF
    /* 300480 00400480 8900133C */  lui        $19, %hi(D_0088BF70)
    /* 300484 00400484 25189200 */  or         $3, $4, $18
    /* 300488 00400488 24207000 */  and        $4, $3, $16
    /* 30048C 0040048C 3C1C0500 */  dsll32     $3, $5, 16
    /* 300490 00400490 3E960300 */  dsrl32     $18, $3, 24
    /* 300494 00400494 3C1A0500 */  dsll32     $3, $5, 8
    /* 300498 00400498 FF005232 */  andi       $18, $18, 0xFF
    /* 30049C 0040049C 3E1E0300 */  dsrl32     $3, $3, 24
    /* 3004A0 004004A0 00921200 */  sll        $18, $18, 8
    /* 3004A4 004004A4 FF006330 */  andi       $3, $3, 0xFF
    /* 3004A8 004004A8 25209200 */  or         $4, $4, $18
    /* 3004AC 004004AC 00940300 */  sll        $18, $3, 16
    /* 3004B0 004004B0 A000A37B */  lq         $3, 0xA0($29)
    /* 3004B4 004004B4 24208300 */  and        $4, $4, $3
    /* 3004B8 004004B8 3C180500 */  dsll32     $3, $5, 0
    /* 3004BC 004004BC 25209200 */  or         $4, $4, $18
    /* 3004C0 004004C0 FF00053C */  lui        $5, (0xFFFFFF >> 16)
    /* 3004C4 004004C4 3E1E0300 */  dsrl32     $3, $3, 24
    /* 3004C8 004004C8 FFFFA534 */  ori        $5, $5, (0xFFFFFF & 0xFFFF)
    /* 3004CC 004004CC FF006330 */  andi       $3, $3, 0xFF
    /* 3004D0 004004D0 2528A200 */  or         $5, $5, $2
    /* 3004D4 004004D4 001E0300 */  sll        $3, $3, 24
    /* 3004D8 004004D8 24208500 */  and        $4, $4, $5
    /* 3004DC 004004DC 8900023C */  lui        $2, %hi(D_0088BC24)
    /* 3004E0 004004E0 25188300 */  or         $3, $4, $3
    /* 3004E4 004004E4 24BC528C */  lw         $18, %lo(D_0088BC24)($2)
    /* 3004E8 004004E8 70BF63AE */  sw         $3, %lo(D_0088BF70)($19)
    /* 3004EC 004004EC 8900043C */  lui        $4, %hi(D_0088BC28)
    /* 3004F0 004004F0 8900133C */  lui        $19, %hi(D_0088BC2C)
    /* 3004F4 004004F4 8900033C */  lui        $3, %hi(D_0088BF74)
    /* 3004F8 004004F8 2CBC748E */  lw         $20, %lo(D_0088BC2C)($19)
    /* 3004FC 004004FC 28BC848C */  lw         $4, %lo(D_0088BC28)($4)
    /* 300500 00400500 74BF72AC */  sw         $18, %lo(D_0088BF74)($3)
    /* 300504 00400504 8900023C */  lui        $2, %hi(D_0088BF78)
    /* 300508 00400508 8900033C */  lui        $3, %hi(D_0088BC30)
    /* 30050C 0040050C 78BF428C */  lw         $2, %lo(D_0088BF78)($2)
    /* 300510 00400510 30BC6324 */  addiu      $3, $3, %lo(D_0088BC30)
    /* 300514 00400514 0000738C */  lw         $19, 0x0($3)
    /* 300518 00400518 7CBFF4AE */  sw         $20, %lo(D_0088BF7C)($23)
    /* 30051C 0040051C BCAF0400 */  dsll32     $21, $4, 30
    /* 300520 00400520 FEAF1500 */  dsrl32     $21, $21, 31
    /* 300524 00400524 FDFF1424 */  addiu      $20, $0, -0x3
    /* 300528 00400528 00FE1724 */  addiu      $23, $0, -0x200
    /* 30052C 0040052C 24105100 */  and        $2, $2, $17
    /* 300530 00400530 8900033C */  lui        $3, %hi(D_0088BF80)
    /* 300534 00400534 80BF728C */  lw         $18, %lo(D_0088BF80)($3)
    /* 300538 00400538 01008330 */  andi       $3, $4, 0x1
    /* 30053C 0040053C 24885102 */  and        $17, $18, $17
    /* 300540 00400540 25184300 */  or         $3, $2, $3
    /* 300544 00400544 E3FF1224 */  addiu      $18, $0, -0x1D
    /* 300548 00400548 0100A232 */  andi       $2, $21, 0x1
    /* 30054C 0040054C 24187400 */  and        $3, $3, $20
    /* 300550 00400550 40A00200 */  sll        $20, $2, 1
    /* 300554 00400554 FC160400 */  dsll32     $2, $4, 27
    /* 300558 00400558 25187400 */  or         $3, $3, $20
    /* 30055C 0040055C 24187200 */  and        $3, $3, $18
    /* 300560 00400560 7E170200 */  dsrl32     $2, $2, 29
    /* 300564 00400564 07005230 */  andi       $18, $2, 0x7
    /* 300568 00400568 BC160400 */  dsll32     $2, $4, 26
    /* 30056C 0040056C 80901200 */  sll        $18, $18, 2
    /* 300570 00400570 FE170200 */  dsrl32     $2, $2, 31
    /* 300574 00400574 25187200 */  or         $3, $3, $18
    /* 300578 00400578 01004230 */  andi       $2, $2, 0x1
    /* 30057C 0040057C DFFF1224 */  addiu      $18, $0, -0x21
    /* 300580 00400580 24187200 */  and        $3, $3, $18
    /* 300584 00400584 40110200 */  sll        $2, $2, 5
    /* 300588 00400588 25186200 */  or         $3, $3, $2
    /* 30058C 0040058C 7C960400 */  dsll32     $18, $4, 25
    /* 300590 00400590 BFFF0224 */  addiu      $2, $0, -0x41
    /* 300594 00400594 24186200 */  and        $3, $3, $2
    /* 300598 00400598 FE171200 */  dsrl32     $2, $18, 31
    /* 30059C 0040059C 01005230 */  andi       $18, $2, 0x1
    /* 3005A0 004005A0 3C160400 */  dsll32     $2, $4, 24
    /* 3005A4 004005A4 80911200 */  sll        $18, $18, 6
    /* 3005A8 004005A8 FE170200 */  dsrl32     $2, $2, 31
    /* 3005AC 004005AC 25187200 */  or         $3, $3, $18
    /* 3005B0 004005B0 01004230 */  andi       $2, $2, 0x1
    /* 3005B4 004005B4 7FFF1224 */  addiu      $18, $0, -0x81
    /* 3005B8 004005B8 24187200 */  and        $3, $3, $18
    /* 3005BC 004005BC C0110200 */  sll        $2, $2, 7
    /* 3005C0 004005C0 25186200 */  or         $3, $3, $2
    /* 3005C4 004005C4 3C140400 */  dsll32     $2, $4, 16
    /* 3005C8 004005C8 24187000 */  and        $3, $3, $16
    /* 3005CC 004005CC 3E160200 */  dsrl32     $2, $2, 24
    /* 3005D0 004005D0 FF005230 */  andi       $18, $2, 0xFF
    /* 3005D4 004005D4 3C100400 */  dsll32     $2, $4, 0
    /* 3005D8 004005D8 00221200 */  sll        $4, $18, 8
    /* 3005DC 004005DC 3E140200 */  dsrl32     $2, $2, 16
    /* 3005E0 004005E0 25206400 */  or         $4, $3, $4
    /* 3005E4 004005E4 8900123C */  lui        $18, %hi(D_0088BF84)
    /* 3005E8 004005E8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* 3005EC 004005EC 24109900 */  and        $2, $4, $25
    /* 3005F0 004005F0 001C0300 */  sll        $3, $3, 16
    /* 3005F4 004005F4 25184300 */  or         $3, $2, $3
    /* 3005F8 004005F8 01006232 */  andi       $2, $19, 0x1
    /* 3005FC 004005FC 78BFC3AE */  sw         $3, %lo(D_0088BF78)($22)
    /* 300600 00400600 25182202 */  or         $3, $17, $2
    /* 300604 00400604 FDFF0224 */  addiu      $2, $0, -0x3
    /* 300608 00400608 8900113C */  lui        $17, %hi(D_0088BF88)
    /* 30060C 0040060C 24186200 */  and        $3, $3, $2
    /* 300610 00400610 88BF358E */  lw         $21, %lo(D_0088BF88)($17)
    /* 300614 00400614 BC171300 */  dsll32     $2, $19, 30
    /* 300618 00400618 FE270200 */  dsrl32     $4, $2, 31
    /* 30061C 0040061C 3C171300 */  dsll32     $2, $19, 28
    /* 300620 00400620 01008430 */  andi       $4, $4, 0x1
    /* 300624 00400624 BE170200 */  dsrl32     $2, $2, 30
    /* 300628 00400628 40200400 */  sll        $4, $4, 1
    /* 30062C 0040062C 03004230 */  andi       $2, $2, 0x3
    /* 300630 00400630 25186400 */  or         $3, $3, $4
    /* 300634 00400634 80200200 */  sll        $4, $2, 2
    /* 300638 00400638 8900113C */  lui        $17, %hi(D_0088BC3C)
    /* 30063C 0040063C F3FF0224 */  addiu      $2, $0, -0xD
    /* 300640 00400640 3CBC3126 */  addiu      $17, $17, %lo(D_0088BC3C)
    /* 300644 00400644 24186200 */  and        $3, $3, $2
    /* 300648 00400648 0000348E */  lw         $20, 0x0($17)
    /* 30064C 0040064C 3C101300 */  dsll32     $2, $19, 0
    /* 300650 00400650 25186400 */  or         $3, $3, $4
    /* 300654 00400654 3E110200 */  dsrl32     $2, $2, 4
    /* 300658 00400658 24187800 */  and        $3, $3, $24
    /* 30065C 0040065C 3C110200 */  dsll32     $2, $2, 4
    /* 300660 00400660 24A8B702 */  and        $21, $21, $23
    /* 300664 00400664 3E110200 */  dsrl32     $2, $2, 4
    /* 300668 00400668 8900183C */  lui        $24, %hi(D_0088BF9C)
    /* 30066C 0040066C 00210200 */  sll        $4, $2, 4
    /* 300670 00400670 25206400 */  or         $4, $3, $4
    /* 300674 00400674 8900023C */  lui        $2, %hi(D_0088BC34)
    /* 300678 00400678 34BC438C */  lw         $3, %lo(D_0088BC34)($2)
    /* 30067C 0040067C 8900113C */  lui        $17, %hi(D_0088BF8C)
    /* 300680 00400680 8CBF338E */  lw         $19, %lo(D_0088BF8C)($17)
    /* 300684 00400684 80BFC4AF */  sw         $4, %lo(D_0088BF80)($30)
    /* 300688 00400688 8900043C */  lui        $4, %hi(D_0088BF88)
    /* 30068C 0040068C 8900023C */  lui        $2, %hi(D_0088BC38)
    /* 300690 00400690 84BF43AE */  sw         $3, %lo(D_0088BF84)($18)
    /* 300694 00400694 38BC4224 */  addiu      $2, $2, %lo(D_0088BC38)
    /* 300698 00400698 8900113C */  lui        $17, %hi(D_0088BC40)
    /* 30069C 0040069C 0000428C */  lw         $2, 0x0($2)
    /* 3006A0 004006A0 40BC3126 */  addiu      $17, $17, %lo(D_0088BC40)
    /* 3006A4 004006A4 0000328E */  lw         $18, 0x0($17)
    /* 3006A8 004006A8 8900033C */  lui        $3, %hi(D_0088BF8C)
    /* 3006AC 004006AC FF015630 */  andi       $22, $2, 0x1FF
    /* 3006B0 004006B0 7CBC0200 */  dsll32     $23, $2, 17
    /* 3006B4 004006B4 25A8B602 */  or         $21, $21, $22
    /* 3006B8 004006B8 8900113C */  lui        $17, %hi(D_0088BF90)
    /* 3006BC 004006BC BEB61700 */  dsrl32     $22, $23, 26
    /* 3006C0 004006C0 90BF318E */  lw         $17, %lo(D_0088BF90)($17)
    /* 3006C4 004006C4 FF811724 */  addiu      $23, $0, -0x7E01
    /* 3006C8 004006C8 3F00D632 */  andi       $22, $22, 0x3F
    /* 3006CC 004006CC 24A8B702 */  and        $21, $21, $23
    /* 3006D0 004006D0 40B21600 */  sll        $22, $22, 9
    /* 3006D4 004006D4 00F81724 */  addiu      $23, $0, -0x800
    /* 3006D8 004006D8 24987702 */  and        $19, $19, $23
    /* 3006DC 004006DC 25B8B602 */  or         $23, $21, $22
    /* 3006E0 004006E0 3CAB0200 */  dsll32     $21, $2, 12
    /* 3006E4 004006E4 FEB61500 */  dsrl32     $22, $21, 27
    /* 3006E8 004006E8 3C100200 */  dsll32     $2, $2, 0
    /* 3006EC 004006EC 1F00D632 */  andi       $22, $22, 0x1F
    /* 3006F0 004006F0 3E150200 */  dsrl32     $2, $2, 20
    /* 3006F4 004006F4 24A8EF02 */  and        $21, $23, $15
    /* 3006F8 004006F8 C0B31600 */  sll        $22, $22, 15
    /* 3006FC 004006FC 25B0B602 */  or         $22, $21, $22
    /* 300700 00400700 FF0F4230 */  andi       $2, $2, 0xFFF
    /* 300704 00400704 00AD0200 */  sll        $21, $2, 20
    /* 300708 00400708 2410CE02 */  and        $2, $22, $14
    /* 30070C 0040070C 25A85500 */  or         $21, $2, $21
    /* 300710 00400710 88BF95AC */  sw         $21, %lo(D_0088BF88)($4)
    /* 300714 00400714 24102B02 */  and        $2, $17, $11
    /* 300718 00400718 FF078432 */  andi       $4, $20, 0x7FF
    /* 30071C 0040071C 25886402 */  or         $17, $19, $4
    /* 300720 00400720 BC221400 */  dsll32     $4, $20, 10
    /* 300724 00400724 24882D02 */  and        $17, $17, $13
    /* 300728 00400728 7E250400 */  dsrl32     $4, $4, 21
    /* 30072C 0040072C FF079330 */  andi       $19, $4, 0x7FF
    /* 300730 00400730 3C201400 */  dsll32     $4, $20, 0
    /* 300734 00400734 C09A1300 */  sll        $19, $19, 11
    /* 300738 00400738 BE250400 */  dsrl32     $4, $4, 22
    /* 30073C 0040073C 25983302 */  or         $19, $17, $19
    /* 300740 00400740 FF038430 */  andi       $4, $4, 0x3FF
    /* 300744 00400744 808D0400 */  sll        $17, $4, 22
    /* 300748 00400748 24206C02 */  and        $4, $19, $12
    /* 30074C 0040074C 25889100 */  or         $17, $4, $17
    /* 300750 00400750 FF0F4432 */  andi       $4, $18, 0xFFF
    /* 300754 00400754 8CBF71AC */  sw         $17, %lo(D_0088BF8C)($3)
    /* 300758 00400758 25104400 */  or         $2, $2, $4
    /* 30075C 0040075C 8900113C */  lui        $17, %hi(D_0088BF98)
    /* 300760 00400760 24184A00 */  and        $3, $2, $10
    /* 300764 00400764 7C121200 */  dsll32     $2, $18, 9
    /* 300768 00400768 7E250200 */  dsrl32     $4, $2, 21
    /* 30076C 0040076C 7C111200 */  dsll32     $2, $18, 5
    /* 300770 00400770 FF078430 */  andi       $4, $4, 0x7FF
    /* 300774 00400774 3E170200 */  dsrl32     $2, $2, 28
    /* 300778 00400778 00230400 */  sll        $4, $4, 12
    /* 30077C 0040077C 25186400 */  or         $3, $3, $4
    /* 300780 00400780 0F004230 */  andi       $2, $2, 0xF
    /* 300784 00400784 C0250200 */  sll        $4, $2, 23
    /* 300788 00400788 24186900 */  and        $3, $3, $9
    /* 30078C 0040078C FC101200 */  dsll32     $2, $18, 3
    /* 300790 00400790 25186400 */  or         $3, $3, $4
    /* 300794 00400794 BE170200 */  dsrl32     $2, $2, 30
    /* 300798 00400798 24186800 */  and        $3, $3, $8
    /* 30079C 0040079C 03004230 */  andi       $2, $2, 0x3
    /* 3007A0 004007A0 C0260200 */  sll        $4, $2, 27
    /* 3007A4 004007A4 3C101200 */  dsll32     $2, $18, 0
    /* 3007A8 004007A8 25186400 */  or         $3, $3, $4
    /* 3007AC 004007AC 7E170200 */  dsrl32     $2, $2, 29
    /* 3007B0 004007B0 24186700 */  and        $3, $3, $7
    /* 3007B4 004007B4 07004230 */  andi       $2, $2, 0x7
    /* 3007B8 004007B8 8900123C */  lui        $18, %hi(D_0088BF94)
    /* 3007BC 004007BC 40270200 */  sll        $4, $2, 29
    /* 3007C0 004007C0 25206400 */  or         $4, $3, $4
    /* 3007C4 004007C4 8900023C */  lui        $2, %hi(D_0088BF90)
    /* 3007C8 004007C8 90BF44AC */  sw         $4, %lo(D_0088BF90)($2)
    /* 3007CC 004007CC 8900033C */  lui        $3, %hi(D_0088BC44)
    /* 3007D0 004007D0 8900043C */  lui        $4, %hi(D_0088BC48)
    /* 3007D4 004007D4 44BC6324 */  addiu      $3, $3, %lo(D_0088BC44)
    /* 3007D8 004007D8 48BC8424 */  addiu      $4, $4, %lo(D_0088BC48)
    /* 3007DC 004007DC 8900023C */  lui        $2, %hi(D_0088BF94)
    /* 3007E0 004007E0 0000968C */  lw         $22, 0x0($4)
    /* 3007E4 004007E4 0000638C */  lw         $3, 0x0($3)
    /* 3007E8 004007E8 94BF428C */  lw         $2, %lo(D_0088BF94)($2)
    /* 3007EC 004007EC 8900043C */  lui        $4, %hi(D_0088BF98)
    /* 3007F0 004007F0 98BF958C */  lw         $21, %lo(D_0088BF98)($4)
    /* 3007F4 004007F4 FF0F7730 */  andi       $23, $3, 0xFFF
    /* 3007F8 004007F8 24104B00 */  and        $2, $2, $11
    /* 3007FC 004007FC 25105700 */  or         $2, $2, $23
    /* 300800 00400800 24104A00 */  and        $2, $2, $10
    /* 300804 00400804 8900043C */  lui        $4, %hi(D_0088BC4C)
    /* 300808 00400808 4CBC948C */  lw         $20, %lo(D_0088BC4C)($4)
    /* 30080C 0040080C 8900043C */  lui        $4, %hi(D_0088BF30)
    /* 300810 00400810 9CBF14AF */  sw         $20, %lo(D_0088BF9C)($24)
    /* 300814 00400814 30BF938C */  lw         $19, %lo(D_0088BF30)($4)
    /* 300818 00400818 7C220300 */  dsll32     $4, $3, 9
    /* 30081C 0040081C 7EBD0400 */  dsrl32     $23, $4, 21
    /* 300820 00400820 00FF0424 */  addiu      $4, $0, -0x100
    /* 300824 00400824 2420A402 */  and        $4, $21, $4
    /* 300828 00400828 FF07F532 */  andi       $21, $23, 0x7FF
    /* 30082C 0040082C 00AB1500 */  sll        $21, $21, 12
    /* 300830 00400830 25A05500 */  or         $20, $2, $21
    /* 300834 00400834 3C100300 */  dsll32     $2, $3, 0
    /* 300838 00400838 24A08602 */  and        $20, $20, $6
    /* 30083C 0040083C FE1D0200 */  dsrl32     $3, $2, 23
    /* 300840 00400840 FF00C232 */  andi       $2, $22, 0xFF
    /* 300844 00400844 25108200 */  or         $2, $4, $2
    /* 300848 00400848 FF016430 */  andi       $4, $3, 0x1FF
    /* 30084C 0040084C 24185000 */  and        $3, $2, $16
    /* 300850 00400850 C0150400 */  sll        $2, $4, 23
    /* 300854 00400854 00FE1024 */  addiu      $16, $0, -0x200
    /* 300858 00400858 25208202 */  or         $4, $20, $2
    /* 30085C 0040085C 3C141600 */  dsll32     $2, $22, 16
    /* 300860 00400860 94BF44AE */  sw         $4, %lo(D_0088BF94)($18)
    /* 300864 00400864 3E160200 */  dsrl32     $2, $2, 24
    /* 300868 00400868 FF004430 */  andi       $4, $2, 0xFF
    /* 30086C 0040086C 3C121600 */  dsll32     $2, $22, 8
    /* 300870 00400870 00220400 */  sll        $4, $4, 8
    /* 300874 00400874 3E160200 */  dsrl32     $2, $2, 24
    /* 300878 00400878 25206400 */  or         $4, $3, $4
    /* 30087C 0040087C FF004330 */  andi       $3, $2, 0xFF
    /* 300880 00400880 A000A27B */  lq         $2, 0xA0($29)
    /* 300884 00400884 001C0300 */  sll        $3, $3, 16
    /* 300888 00400888 24108200 */  and        $2, $4, $2
    /* 30088C 0040088C 25184300 */  or         $3, $2, $3
    /* 300890 00400890 3C101600 */  dsll32     $2, $22, 0
    /* 300894 00400894 24186500 */  and        $3, $3, $5
    /* 300898 00400898 3E160200 */  dsrl32     $2, $2, 24
    /* 30089C 0040089C FF016532 */  andi       $5, $19, 0x1FF
    /* 3008A0 004008A0 FF004230 */  andi       $2, $2, 0xFF
    /* 3008A4 004008A4 00260200 */  sll        $4, $2, 24
    /* 3008A8 004008A8 25186400 */  or         $3, $3, $4
    /* 3008AC 004008AC 8900023C */  lui        $2, %hi(D_0088BFA0)
    /* 3008B0 004008B0 A0BF448C */  lw         $4, %lo(D_0088BFA0)($2)
    /* 3008B4 004008B4 98BF23AE */  sw         $3, %lo(D_0088BF98)($17)
    /* 3008B8 004008B8 3C881300 */  dsll32     $17, $19, 0
    /* 3008BC 004008BC 24809000 */  and        $16, $4, $16
    /* 3008C0 004008C0 7C141300 */  dsll32     $2, $19, 17
    /* 3008C4 004008C4 BE1E0200 */  dsrl32     $3, $2, 26
    /* 3008C8 004008C8 3E251100 */  dsrl32     $4, $17, 20
    /* 3008CC 004008CC 25800502 */  or         $16, $16, $5
    /* 3008D0 004008D0 3F006330 */  andi       $3, $3, 0x3F
    /* 3008D4 004008D4 FF0F8530 */  andi       $5, $4, 0xFFF
    /* 3008D8 004008D8 401A0300 */  sll        $3, $3, 9
    /* 3008DC 004008DC FF810424 */  addiu      $4, $0, -0x7E01
    /* 3008E0 004008E0 3C131300 */  dsll32     $2, $19, 12
    /* 3008E4 004008E4 24200402 */  and        $4, $16, $4
    /* 3008E8 004008E8 FE160200 */  dsrl32     $2, $2, 27
    /* 3008EC 004008EC 25188300 */  or         $3, $4, $3
    /* 3008F0 004008F0 1F004230 */  andi       $2, $2, 0x1F
    /* 3008F4 004008F4 24806F00 */  and        $16, $3, $15
    /* 3008F8 004008F8 C0130200 */  sll        $2, $2, 15
    /* 3008FC 004008FC 8900033C */  lui        $3, %hi(D_0088BF34)
    /* 300900 00400900 25100202 */  or         $2, $16, $2
    /* 300904 00400904 34BF718C */  lw         $17, %lo(D_0088BF34)($3)
    /* 300908 00400908 002D0500 */  sll        $5, $5, 20
    /* 30090C 0040090C 8900043C */  lui        $4, %hi(D_0088BFA0)
    /* 300910 00400910 24184E00 */  and        $3, $2, $14
    /* 300914 00400914 BC921100 */  dsll32     $18, $17, 10
    /* 300918 00400918 25186500 */  or         $3, $3, $5
    /* 30091C 0040091C 8900023C */  lui        $2, %hi(D_0088BFA4)
    /* 300920 00400920 A0BF83AC */  sw         $3, %lo(D_0088BFA0)($4)
    /* 300924 00400924 FF073432 */  andi       $20, $17, 0x7FF
    /* 300928 00400928 8900033C */  lui        $3, %hi(D_0088BFA8)
    /* 30092C 0040092C A4BF538C */  lw         $19, %lo(D_0088BFA4)($2)
    /* 300930 00400930 A8BF708C */  lw         $16, %lo(D_0088BFA8)($3)
    /* 300934 00400934 3C881100 */  dsll32     $17, $17, 0
    /* 300938 00400938 8900043C */  lui        $4, %hi(D_0088BFA4)
    /* 30093C 0040093C 8900053C */  lui        $5, %hi(D_0088BFA8)
    /* 300940 00400940 8900023C */  lui        $2, %hi(D_0088BF38)
    /* 300944 00400944 00F80324 */  addiu      $3, $0, -0x800
    /* 300948 00400948 38BF428C */  lw         $2, %lo(D_0088BF38)($2)
    /* 30094C 0040094C 24986302 */  and        $19, $19, $3
    /* 300950 00400950 7E1D1200 */  dsrl32     $3, $18, 21
    /* 300954 00400954 25987402 */  or         $19, $19, $20
    /* 300958 00400958 FF076330 */  andi       $3, $3, 0x7FF
    /* 30095C 0040095C C0920300 */  sll        $18, $3, 11
    /* 300960 00400960 24186D02 */  and        $3, $19, $13
    /* 300964 00400964 25907200 */  or         $18, $3, $18
    /* 300968 00400968 BE1D1100 */  dsrl32     $3, $17, 22
    /* 30096C 0040096C FF036330 */  andi       $3, $3, 0x3FF
    /* 300970 00400970 24884C02 */  and        $17, $18, $12
    /* 300974 00400974 80950300 */  sll        $18, $3, 22
    /* 300978 00400978 24180B02 */  and        $3, $16, $11
    /* 30097C 0040097C 25883202 */  or         $17, $17, $18
    /* 300980 00400980 FF0F5030 */  andi       $16, $2, 0xFFF
    /* 300984 00400984 A4BF91AC */  sw         $17, %lo(D_0088BFA4)($4)
    /* 300988 00400988 25187000 */  or         $3, $3, $16
    /* 30098C 0040098C 24206A00 */  and        $4, $3, $10
    /* 300990 00400990 7C1A0200 */  dsll32     $3, $2, 9
    /* 300994 00400994 7E850300 */  dsrl32     $16, $3, 21
    /* 300998 00400998 7C190200 */  dsll32     $3, $2, 5
    /* 30099C 0040099C FF071032 */  andi       $16, $16, 0x7FF
    /* 3009A0 004009A0 3E1F0300 */  dsrl32     $3, $3, 28
    /* 3009A4 004009A4 00831000 */  sll        $16, $16, 12
    /* 3009A8 004009A8 25209000 */  or         $4, $4, $16
    /* 3009AC 004009AC 0F006330 */  andi       $3, $3, 0xF
    /* 3009B0 004009B0 C0850300 */  sll        $16, $3, 23
    /* 3009B4 004009B4 24208900 */  and        $4, $4, $9
    /* 3009B8 004009B8 FC180200 */  dsll32     $3, $2, 3
    /* 3009BC 004009BC 25809000 */  or         $16, $4, $16
    /* 3009C0 004009C0 BE1F0300 */  dsrl32     $3, $3, 30
    /* 3009C4 004009C4 3C100200 */  dsll32     $2, $2, 0
    /* 3009C8 004009C8 03006430 */  andi       $4, $3, 0x3
    /* 3009CC 004009CC 7E170200 */  dsrl32     $2, $2, 29
    /* 3009D0 004009D0 24180802 */  and        $3, $16, $8
    /* 3009D4 004009D4 C0260400 */  sll        $4, $4, 27
    /* 3009D8 004009D8 25186400 */  or         $3, $3, $4
    /* 3009DC 004009DC 07004230 */  andi       $2, $2, 0x7
    /* 3009E0 004009E0 40270200 */  sll        $4, $2, 29
    /* 3009E4 004009E4 24186700 */  and        $3, $3, $7
    /* 3009E8 004009E8 25186400 */  or         $3, $3, $4
    /* 3009EC 004009EC 8900023C */  lui        $2, %hi(D_0088BF3C)
    /* 3009F0 004009F0 3CBF448C */  lw         $4, %lo(D_0088BF3C)($2)
    /* 3009F4 004009F4 8900103C */  lui        $16, %hi(D_0088BFAC)
    /* 3009F8 004009F8 A8BFA3AC */  sw         $3, %lo(D_0088BFA8)($5)
    /* 3009FC 004009FC 8900033C */  lui        $3, %hi(D_0088BF40)
    /* 300A00 00400A00 8900053C */  lui        $5, %hi(D_0088BFB0)
    /* 300A04 00400A04 40BF638C */  lw         $3, %lo(D_0088BF40)($3)
    /* 300A08 00400A08 8900023C */  lui        $2, %hi(D_0088BFAC)
    /* 300A0C 00400A0C FF0F9530 */  andi       $21, $4, 0xFFF
    /* 300A10 00400A10 ACBF548C */  lw         $20, %lo(D_0088BFAC)($2)
    /* 300A14 00400A14 7C9A0400 */  dsll32     $19, $4, 9
    /* 300A18 00400A18 3C900400 */  dsll32     $18, $4, 0
    /* 300A1C 00400A1C 7E251300 */  dsrl32     $4, $19, 21
    /* 300A20 00400A20 FF078430 */  andi       $4, $4, 0x7FF
    /* 300A24 00400A24 009B0400 */  sll        $19, $4, 12
    /* 300A28 00400A28 8900023C */  lui        $2, %hi(D_0088BFB0)
    /* 300A2C 00400A2C 24A08B02 */  and        $20, $20, $11
    /* 300A30 00400A30 B0BF518C */  lw         $17, %lo(D_0088BFB0)($2)
    /* 300A34 00400A34 25A09502 */  or         $20, $20, $21
    /* 300A38 00400A38 24208A02 */  and        $4, $20, $10
    /* 300A3C 00400A3C 25989300 */  or         $19, $4, $19
    /* 300A40 00400A40 00FE0424 */  addiu      $4, $0, -0x200
    /* 300A44 00400A44 24202402 */  and        $4, $17, $4
    /* 300A48 00400A48 8900023C */  lui        $2, %hi(D_0088BF44)
    /* 300A4C 00400A4C FE8D1200 */  dsrl32     $17, $18, 23
    /* 300A50 00400A50 44BF428C */  lw         $2, %lo(D_0088BF44)($2)
    /* 300A54 00400A54 24906602 */  and        $18, $19, $6
    /* 300A58 00400A58 FF013332 */  andi       $19, $17, 0x1FF
    /* 300A5C 00400A5C FF017130 */  andi       $17, $3, 0x1FF
    /* 300A60 00400A60 25889100 */  or         $17, $4, $17
    /* 300A64 00400A64 C0251300 */  sll        $4, $19, 23
    /* 300A68 00400A68 25904402 */  or         $18, $18, $4
    /* 300A6C 00400A6C FF810424 */  addiu      $4, $0, -0x7E01
    /* 300A70 00400A70 ACBF12AE */  sw         $18, %lo(D_0088BFAC)($16)
    /* 300A74 00400A74 24882402 */  and        $17, $17, $4
    /* 300A78 00400A78 7C240300 */  dsll32     $4, $3, 17
    /* 300A7C 00400A7C BE860400 */  dsrl32     $16, $4, 26
    /* 300A80 00400A80 3C230300 */  dsll32     $4, $3, 12
    /* 300A84 00400A84 3F001032 */  andi       $16, $16, 0x3F
    /* 300A88 00400A88 FE260400 */  dsrl32     $4, $4, 27
    /* 300A8C 00400A8C 40821000 */  sll        $16, $16, 9
    /* 300A90 00400A90 1F008430 */  andi       $4, $4, 0x1F
    /* 300A94 00400A94 25883002 */  or         $17, $17, $16
    /* 300A98 00400A98 C0830400 */  sll        $16, $4, 15
    /* 300A9C 00400A9C 3C180300 */  dsll32     $3, $3, 0
    /* 300AA0 00400AA0 24202F02 */  and        $4, $17, $15
    /* 300AA4 00400AA4 25789000 */  or         $15, $4, $16
    /* 300AA8 00400AA8 8900113C */  lui        $17, %hi(D_0088BFB4)
    /* 300AAC 00400AAC 3E250300 */  dsrl32     $4, $3, 20
    /* 300AB0 00400AB0 8900103C */  lui        $16, %hi(D_0088BFB8)
    /* 300AB4 00400AB4 2418EE01 */  and        $3, $15, $14
    /* 300AB8 00400AB8 FF0F8430 */  andi       $4, $4, 0xFFF
    /* 300ABC 00400ABC 00250400 */  sll        $4, $4, 20
    /* 300AC0 00400AC0 00F80F24 */  addiu      $15, $0, -0x800
    /* 300AC4 00400AC4 25206400 */  or         $4, $3, $4
    /* 300AC8 00400AC8 FF074E30 */  andi       $14, $2, 0x7FF
    /* 300ACC 00400ACC B0BFA4AC */  sw         $4, %lo(D_0088BFB0)($5)
    /* 300AD0 00400AD0 8900033C */  lui        $3, %hi(D_0088BFB4)
    /* 300AD4 00400AD4 B4BF658C */  lw         $5, %lo(D_0088BFB4)($3)
    /* 300AD8 00400AD8 BC220200 */  dsll32     $4, $2, 10
    /* 300ADC 00400ADC 3C100200 */  dsll32     $2, $2, 0
    /* 300AE0 00400AE0 BE150200 */  dsrl32     $2, $2, 22
    /* 300AE4 00400AE4 FF034230 */  andi       $2, $2, 0x3FF
    /* 300AE8 00400AE8 2428AF00 */  and        $5, $5, $15
    /* 300AEC 00400AEC 7E1D0400 */  dsrl32     $3, $4, 21
    /* 300AF0 00400AF0 2528AE00 */  or         $5, $5, $14
    /* 300AF4 00400AF4 FF076330 */  andi       $3, $3, 0x7FF
    /* 300AF8 00400AF8 C0220300 */  sll        $4, $3, 11
    /* 300AFC 00400AFC 2468AD00 */  and        $13, $5, $13
    /* 300B00 00400B00 2520A401 */  or         $4, $13, $4
    /* 300B04 00400B04 801D0200 */  sll        $3, $2, 22
    /* 300B08 00400B08 24608C00 */  and        $12, $4, $12
    /* 300B0C 00400B0C 8900023C */  lui        $2, %hi(D_0088BF48)
    /* 300B10 00400B10 25608301 */  or         $12, $12, $3
    /* 300B14 00400B14 8900043C */  lui        $4, %hi(D_0088BFBC)
    /* 300B18 00400B18 48BF428C */  lw         $2, %lo(D_0088BF48)($2)
    /* 300B1C 00400B1C 8900053C */  lui        $5, %hi(D_0088BF4C)
    /* 300B20 00400B20 BCBF838C */  lw         $3, %lo(D_0088BFBC)($4)
    /* 300B24 00400B24 89000E3C */  lui        $14, %hi(D_0088BFB8)
    /* 300B28 00400B28 B8BF0F8E */  lw         $15, %lo(D_0088BFB8)($16)
    /* 300B2C 00400B2C B4BF2CAE */  sw         $12, %lo(D_0088BFB4)($17)
    /* 300B30 00400B30 4CBFA58C */  lw         $5, %lo(D_0088BF4C)($5)
    /* 300B34 00400B34 FF0F4D30 */  andi       $13, $2, 0xFFF
    /* 300B38 00400B38 7C220200 */  dsll32     $4, $2, 9
    /* 300B3C 00400B3C 24186B00 */  and        $3, $3, $11
    /* 300B40 00400B40 2460EB01 */  and        $12, $15, $11
    /* 300B44 00400B44 7E250400 */  dsrl32     $4, $4, 21
    /* 300B48 00400B48 25608D01 */  or         $12, $12, $13
    /* 300B4C 00400B4C FF078430 */  andi       $4, $4, 0x7FF
    /* 300B50 00400B50 006B0400 */  sll        $13, $4, 12
    /* 300B54 00400B54 24608A01 */  and        $12, $12, $10
    /* 300B58 00400B58 7C210200 */  dsll32     $4, $2, 5
    /* 300B5C 00400B5C 25608D01 */  or         $12, $12, $13
    /* 300B60 00400B60 3E270400 */  dsrl32     $4, $4, 28
    /* 300B64 00400B64 24488901 */  and        $9, $12, $9
    /* 300B68 00400B68 0F008B30 */  andi       $11, $4, 0xF
    /* 300B6C 00400B6C FC200200 */  dsll32     $4, $2, 3
    /* 300B70 00400B70 C05D0B00 */  sll        $11, $11, 23
    /* 300B74 00400B74 3C100200 */  dsll32     $2, $2, 0
    /* 300B78 00400B78 BE270400 */  dsrl32     $4, $4, 30
    /* 300B7C 00400B7C 25582B01 */  or         $11, $9, $11
    /* 300B80 00400B80 7E170200 */  dsrl32     $2, $2, 29
    /* 300B84 00400B84 03008930 */  andi       $9, $4, 0x3
    /* 300B88 00400B88 24206801 */  and        $4, $11, $8
    /* 300B8C 00400B8C C0460900 */  sll        $8, $9, 27
    /* 300B90 00400B90 25208800 */  or         $4, $4, $8
    /* 300B94 00400B94 24208700 */  and        $4, $4, $7
    /* 300B98 00400B98 07004730 */  andi       $7, $2, 0x7
    /* 300B9C 00400B9C FF0FA230 */  andi       $2, $5, 0xFFF
    /* 300BA0 00400BA0 25106200 */  or         $2, $3, $2
    /* 300BA4 00400BA4 401F0700 */  sll        $3, $7, 29
    /* 300BA8 00400BA8 25208300 */  or         $4, $4, $3
    /* 300BAC 00400BAC 24184A00 */  and        $3, $2, $10
    /* 300BB0 00400BB0 B8BFC4AD */  sw         $4, %lo(D_0088BFB8)($14)
    /* 300BB4 00400BB4 7C120500 */  dsll32     $2, $5, 9
    /* 300BB8 00400BB8 7E250200 */  dsrl32     $4, $2, 21
    /* 300BBC 00400BBC 3C100500 */  dsll32     $2, $5, 0
    /* 300BC0 00400BC0 FF078430 */  andi       $4, $4, 0x7FF
    /* 300BC4 00400BC4 FE150200 */  dsrl32     $2, $2, 23
    /* 300BC8 00400BC8 00230400 */  sll        $4, $4, 12
    /* 300BCC 00400BCC 25186400 */  or         $3, $3, $4
    /* 300BD0 00400BD0 FF014230 */  andi       $2, $2, 0x1FF
    /* 300BD4 00400BD4 C0250200 */  sll        $4, $2, 23
    /* 300BD8 00400BD8 24186600 */  and        $3, $3, $6
    /* 300BDC 00400BDC 25206400 */  or         $4, $3, $4
    /* 300BE0 00400BE0 8900023C */  lui        $2, %hi(D_0088BFBC)
    /* 300BE4 00400BE4 8900033C */  lui        $3, %hi(D_0088BFD0)
    /* 300BE8 00400BE8 BCBF44AC */  sw         $4, %lo(D_0088BFBC)($2)
    /* 300BEC 00400BEC D0BF6324 */  addiu      $3, $3, %lo(D_0088BFD0)
    /* 300BF0 00400BF0 8900043C */  lui        $4, %hi(D_0088BC00)
    /* 300BF4 00400BF4 7F006524 */  addiu      $5, $3, 0x7F
    /* 300BF8 00400BF8 3688100C */  jal        func_004220d8
    /* 300BFC 00400BFC 00BC8424 */   addiu     $4, $4, %lo(D_0088BC00)
    /* 300C00 00400C00 08B980AF */  sw         $0, -0x46F8($28)
    /* 300C04 00400C04 8900043C */  lui        $4, %hi(D_0088BC00)
    /* 300C08 00400C08 08B9858F */  lw         $5, -0x46F8($28)
    /* 300C0C 00400C0C 00BC8424 */  addiu      $4, $4, %lo(D_0088BC00)
    /* 300C10 00400C10 0100A224 */  addiu      $2, $5, 0x1
    /* 300C14 00400C14 6663100C */  jal        func_00418d98
    /* 300C18 00400C18 08B982AF */   sw        $2, -0x46F8($28)
  .L00400C1C:
    /* 300C1C 00400C1C 01000424 */  addiu      $4, $0, 0x1
    /* 300C20 00400C20 0C60100C */  jal        func_00418030
    /* 300C24 00400C24 2D280000 */   daddu     $5, $0, $0
    /* 300C28 00400C28 00000000 */  nop
    /* 300C2C 00400C2C 00000000 */  nop
    /* 300C30 00400C30 FAFF4014 */  bnez       $2, .L00400C1C
    /* 300C34 00400C34 00000000 */   nop
    /* 300C38 00400C38 04000324 */  addiu      $3, $0, 0x4
    /* 300C3C 00400C3C 0110023C */  lui        $2, (0x10010000 >> 16)
    /* 300C40 00400C40 10E043AC */  sw         $3, -0x1FF0($2)
    /* 300C44 00400C44 8900023C */  lui        $2, %hi(D_0088BFCC)
    /* 300C48 00400C48 CCBF40AC */  sw         $0, %lo(D_0088BFCC)($2)
    /* 300C4C 00400C4C 8900023C */  lui        $2, %hi(D_0088BFC8)
    /* 300C50 00400C50 C8BF40AC */  sw         $0, %lo(D_0088BFC8)($2)
    /* 300C54 00400C54 8900023C */  lui        $2, %hi(D_0088BFC4)
    /* 300C58 00400C58 C4BF40AC */  sw         $0, %lo(D_0088BFC4)($2)
    /* 300C5C 00400C5C 8900023C */  lui        $2, %hi(D_0088BFC0)
    /* 300C60 00400C60 24D30F0C */  jal        func_003f4c90
    /* 300C64 00400C64 C0BF40AC */   sw        $0, %lo(D_0088BFC0)($2)
    /* 300C68 00400C68 2D804000 */  daddu      $16, $2, $0
    /* 300C6C 00400C6C FF000012 */  beqz       $16, .L0040106C
    /* 300C70 00400C70 00000000 */   nop
    /* 300C74 00400C74 8900033C */  lui        $3, %hi(D_0088BC60)
    /* 300C78 00400C78 8900023C */  lui        $2, %hi(D_0088BC70)
    /* 300C7C 00400C7C 60BC68DC */  ld         $8, %lo(D_0088BC60)($3)
    /* 300C80 00400C80 70BC47DC */  ld         $7, %lo(D_0088BC70)($2)
    /* 300C84 00400C84 8900033C */  lui        $3, %hi(D_0088BCD0)
    /* 300C88 00400C88 C8B888FF */  sd         $8, -0x4738($28)
    /* 300C8C 00400C8C D0BC66DC */  ld         $6, %lo(D_0088BCD0)($3)
    /* 300C90 00400C90 8900023C */  lui        $2, %hi(D_0088BC80)
    /* 300C94 00400C94 80BC45DC */  ld         $5, %lo(D_0088BC80)($2)
    /* 300C98 00400C98 C0B887FF */  sd         $7, -0x4740($28)
    /* 300C9C 00400C9C F7FF0324 */  addiu      $3, $0, -0x9
    /* 300CA0 00400CA0 D0B886FF */  sd         $6, -0x4730($28)
    /* 300CA4 00400CA4 3C200300 */  dsll32     $4, $3, 0
    /* 300CA8 00400CA8 01000224 */  addiu      $2, $0, 0x1
    /* 300CAC 00400CAC FFFF0334 */  ori        $3, $0, 0xFFFF
    /* 300CB0 00400CB0 A4B982AF */  sw         $2, -0x465C($28)
    /* 300CB4 00400CB4 38140300 */  dsll       $2, $3, 16
    /* 300CB8 00400CB8 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* 300CBC 00400CBC 25104400 */  or         $2, $2, $4
    /* 300CC0 00400CC0 2420A200 */  and        $4, $5, $2
    /* 300CC4 00400CC4 3B110400 */  dsra       $2, $4, 4
    /* 300CC8 00400CC8 D8B884FF */  sd         $4, -0x4728($28)
    /* 300CCC 00400CCC FF0F4330 */  andi       $3, $2, 0xFFF
    /* 300CD0 00400CD0 3F110400 */  dsra32     $2, $4, 4
    /* 300CD4 00400CD4 10B983FF */  sd         $3, -0x46F0($28)
    /* 300CD8 00400CD8 FF0F4230 */  andi       $2, $2, 0xFFF
    /* 300CDC 00400CDC C8F80F0C */  jal        func_003fe320
    /* 300CE0 00400CE0 18B982FF */   sd        $2, -0x46E8($28)
    /* 300CE4 00400CE4 8900023C */  lui        $2, %hi(D_0088C9BC)
    /* 300CE8 00400CE8 BCC9428C */  lw         $2, %lo(D_0088C9BC)($2)
    /* 300CEC 00400CEC 04004230 */  andi       $2, $2, 0x4
    /* 300CF0 00400CF0 04004010 */  beqz       $2, .L00400D04
    /* 300CF4 00400CF4 00000000 */   nop
    /* 300CF8 00400CF8 01000224 */  addiu      $2, $0, 0x1
    /* 300CFC 00400CFC 02000010 */  b          .L00400D08
    /* 300D00 00400D00 28B882A3 */   sb        $2, -0x47D8($28)
  .L00400D04:
    /* 300D04 00400D04 28B880A3 */  sb         $0, -0x47D8($28)
  .L00400D08:
    /* 300D08 00400D08 8900023C */  lui        $2, %hi(D_0088C9D4)
    /* 300D0C 00400D0C D4C9428C */  lw         $2, %lo(D_0088C9D4)($2)
    /* 300D10 00400D10 00014230 */  andi       $2, $2, 0x100
    /* 300D14 00400D14 D9004014 */  bnez       $2, .L0040107C
    /* 300D18 00400D18 00000000 */   nop
    /* 300D1C 00400D1C 01000224 */  addiu      $2, $0, 0x1
  .L00400D20:
    /* 300D20 00400D20 58B982AF */  sw         $2, -0x46A8($28)
  .L00400D24:
    /* 300D24 00400D24 DA000010 */  b          .L00401090
    /* 300D28 00400D28 2D100002 */   daddu     $2, $16, $0
  .L00400D2C:
    /* 300D2C 00400D2C 40180400 */  sll        $3, $4, 1
    /* 300D30 00400D30 7100023C */  lui        $2, %hi(D_0070B840)
    /* 300D34 00400D34 21186400 */  addu       $3, $3, $4
    /* 300D38 00400D38 40B84224 */  addiu      $2, $2, %lo(D_0070B840)
    /* 300D3C 00400D3C C0180300 */  sll        $3, $3, 3
    /* 300D40 00400D40 8900053C */  lui        $5, %hi(D_0088C9D4)
    /* 300D44 00400D44 21104300 */  addu       $2, $2, $3
    /* 300D48 00400D48 8900083C */  lui        $8, %hi(D_0088C9C8)
    /* 300D4C 00400D4C 0C0042C4 */  lwc1       $f2, 0xC($2)
    /* 300D50 00400D50 8900073C */  lui        $7, %hi(D_0088C9CC)
    /* 300D54 00400D54 000045C4 */  lwc1       $f5, 0x0($2)
    /* 300D58 00400D58 89000A3C */  lui        $10, %hi(D_0088C9B0)
    /* 300D5C 00400D5C 040044C4 */  lwc1       $f4, 0x4($2)
    /* 300D60 00400D60 8900093C */  lui        $9, %hi(D_0088C9C0)
    /* 300D64 00400D64 100041C4 */  lwc1       $f1, 0x10($2)
    /* 300D68 00400D68 8900063C */  lui        $6, %hi(D_0088C9D0)
    /* 300D6C 00400D6C 140040C4 */  lwc1       $f0, 0x14($2)
    /* 300D70 00400D70 8900043C */  lui        $4, %hi(D_0088C9D8)
    /* 300D74 00400D74 080043C4 */  lwc1       $f3, 0x8($2)
    /* 300D78 00400D78 8900033C */  lui        $3, %hi(D_0088C9DC)
    /* 300D7C 00400D7C BC00A2E7 */  swc1       $f2, 0xBC($29)
    /* 300D80 00400D80 BC00A2C7 */  lwc1       $f2, 0xBC($29)
    /* 300D84 00400D84 B000A5E7 */  swc1       $f5, 0xB0($29)
    /* 300D88 00400D88 C000A1E7 */  swc1       $f1, 0xC0($29)
    /* 300D8C 00400D8C C400A0E7 */  swc1       $f0, 0xC4($29)
    /* 300D90 00400D90 B400A4E7 */  swc1       $f4, 0xB4($29)
    /* 300D94 00400D94 C000ABDF */  ld         $11, 0xC0($29)
    /* 300D98 00400D98 B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* 300D9C 00400D9C 8900023C */  lui        $2, %hi(D_0088C9D4)
    /* 300DA0 00400DA0 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* 300DA4 00400DA4 B800A3E7 */  swc1       $f3, 0xB8($29)
    /* 300DA8 00400DA8 D4C9A2E4 */  swc1       $f2, %lo(D_0088C9D4)($5)
    /* 300DAC 00400DAC B000AC7B */  lq         $12, 0xB0($29)
    /* 300DB0 00400DB0 D4C9428C */  lw         $2, %lo(D_0088C9D4)($2)
    /* 300DB4 00400DB4 B800A3C7 */  lwc1       $f3, 0xB8($29)
    /* 300DB8 00400DB8 C0C92BFD */  sd         $11, %lo(D_0088C9C0)($9)
    /* 300DBC 00400DBC C8C901E5 */  swc1       $f1, %lo(D_0088C9C8)($8)
    /* 300DC0 00400DC0 CCC9E0E4 */  swc1       $f0, %lo(D_0088C9CC)($7)
    /* 300DC4 00400DC4 C000A1C7 */  lwc1       $f1, 0xC0($29)
    /* 300DC8 00400DC8 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* 300DCC 00400DCC B0C94C7D */  sq         $12, %lo(D_0088C9B0)($10)
    /* 300DD0 00400DD0 00014230 */  andi       $2, $2, 0x100
    /* 300DD4 00400DD4 D0C9C3E4 */  swc1       $f3, %lo(D_0088C9D0)($6)
    /* 300DD8 00400DD8 D8C981E4 */  swc1       $f1, %lo(D_0088C9D8)($4)
    /* 300DDC 00400DDC 12004010 */  beqz       $2, .L00400E28
    /* 300DE0 00400DE0 DCC960E4 */   swc1      $f0, %lo(D_0088C9DC)($3)
    /* 300DE4 00400DE4 01000324 */  addiu      $3, $0, 0x1
    /* 300DE8 00400DE8 8900023C */  lui        $2, %hi(D_0088C9E0)
    /* 300DEC 00400DEC E0C943A0 */  sb         $3, %lo(D_0088C9E0)($2)
    /* 300DF0 00400DF0 8900023C */  lui        $2, %hi(D_0088C9E1)
    /* 300DF4 00400DF4 E1C943A0 */  sb         $3, %lo(D_0088C9E1)($2)
    /* 300DF8 00400DF8 8900023C */  lui        $2, %hi(D_0088C9CC)
    /* 300DFC 00400DFC 20B9838F */  lw         $3, -0x46E0($28)
    /* 300E00 00400E00 CCC9448C */  lw         $4, %lo(D_0088C9CC)($2)
    /* 300E04 00400E04 8900023C */  lui        $2, %hi(D_0088C9CC)
    /* 300E08 00400E08 43200400 */  sra        $4, $4, 1
    /* 300E0C 00400E0C 11006010 */  beqz       $3, .L00400E54
    /* 300E10 00400E10 CCC944AC */   sw        $4, %lo(D_0088C9CC)($2)
    /* 300E14 00400E14 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 300E18 00400E18 C8C943AC */  sw         $3, %lo(D_0088C9C8)($2)
  .L00400E1C:
    /* 300E1C 00400E1C 8900023C */  lui        $2, %hi(D_0088C9E3)
    /* 300E20 00400E20 09000010 */  b          .L00400E48
    /* 300E24 00400E24 E3C940A0 */   sb        $0, %lo(D_0088C9E3)($2)
  .L00400E28:
    /* 300E28 00400E28 02000324 */  addiu      $3, $0, 0x2
    /* 300E2C 00400E2C 8900023C */  lui        $2, %hi(D_0088C9E0)
    /* 300E30 00400E30 E0C943A0 */  sb         $3, %lo(D_0088C9E0)($2)
    /* 300E34 00400E34 8900023C */  lui        $2, %hi(D_0088C9E1)
    /* 300E38 00400E38 E1C943A0 */  sb         $3, %lo(D_0088C9E1)($2)
    /* 300E3C 00400E3C 01000324 */  addiu      $3, $0, 0x1
    /* 300E40 00400E40 8900023C */  lui        $2, %hi(D_0088C9E3)
    /* 300E44 00400E44 E3C943A0 */  sb         $3, %lo(D_0088C9E3)($2)
  .L00400E48:
    /* 300E48 00400E48 8900023C */  lui        $2, %hi(D_0088C9E2)
    /* 300E4C 00400E4C AFFA0010 */  b          .L003FF90C
    /* 300E50 00400E50 E2C940A0 */   sb        $0, %lo(D_0088C9E2)($2)
  .L00400E54:
    /* 300E54 00400E54 8900023C */  lui        $2, %hi(D_0088C9C8)
    /* 300E58 00400E58 C8C9428C */  lw         $2, %lo(D_0088C9C8)($2)
    /* 300E5C 00400E5C EFFF0010 */  b          .L00400E1C
    /* 300E60 00400E60 20B982AF */   sw        $2, -0x46E0($28)
  .L00400E64:
    /* 300E64 00400E64 8A000010 */  b          .L00401090
    /* 300E68 00400E68 2D100000 */   daddu     $2, $0, $0
  .L00400E6C:
    /* 300E6C 00400E6C 2D306000 */  daddu      $6, $3, $0
    /* 300E70 00400E70 2D200000 */  daddu      $4, $0, $0
    /* 300E74 00400E74 2D280000 */  daddu      $5, $0, $0
    /* 300E78 00400E78 445D100C */  jal        func_00417510
    /* 300E7C 00400E7C 01000724 */   addiu     $7, $0, 0x1
    /* 300E80 00400E80 C3FA0010 */  b          .L003FF990
    /* 300E84 00400E84 00000000 */   nop
  .L00400E88:
    /* 300E88 00400E88 01000524 */  addiu      $5, $0, 0x1
    /* 300E8C 00400E8C 2D200000 */  daddu      $4, $0, $0
    /* 300E90 00400E90 445D100C */  jal        func_00417510
    /* 300E94 00400E94 2D38A000 */   daddu     $7, $5, $0
    /* 300E98 00400E98 BDFA0010 */  b          .L003FF990
    /* 300E9C 00400E9C 00000000 */   nop
  .L00400EA0:
    /* 300EA0 00400EA0 2D200000 */  daddu      $4, $0, $0
    /* 300EA4 00400EA4 01000524 */  addiu      $5, $0, 0x1
    /* 300EA8 00400EA8 445D100C */  jal        func_00417510
    /* 300EAC 00400EAC 2D380000 */   daddu     $7, $0, $0
    /* 300EB0 00400EB0 B7FA0010 */  b          .L003FF990
    /* 300EB4 00400EB4 00000000 */   nop
  .L00400EB8:
    /* 300EB8 00400EB8 8900023C */  lui        $2, %hi(D_0088BC38)
    /* 300EBC 00400EBC FF01A430 */  andi       $4, $5, 0x1FF
    /* 300EC0 00400EC0 38BC468C */  lw         $6, %lo(D_0088BC38)($2)
    /* 300EC4 00400EC4 00FE0324 */  addiu      $3, $0, -0x200
    /* 300EC8 00400EC8 40280500 */  sll        $5, $5, 1
    /* 300ECC 00400ECC 2418C300 */  and        $3, $6, $3
    /* 300ED0 00400ED0 8900023C */  lui        $2, %hi(D_0088BC38)
    /* 300ED4 00400ED4 25186400 */  or         $3, $3, $4
    /* 300ED8 00400ED8 DAFB0010 */  b          .L003FFE44
    /* 300EDC 00400EDC 38BC43AC */   sw        $3, %lo(D_0088BC38)($2)
  .L00400EE0:
    /* 300EE0 00400EE0 8900023C */  lui        $2, %hi(D_0088BC1C)
    /* 300EE4 00400EE4 8900033C */  lui        $3, %hi(D_0088BC18)
    /* 300EE8 00400EE8 1CBC42C4 */  lwc1       $f2, %lo(D_0088BC1C)($2)
    /* 300EEC 00400EEC 8900063C */  lui        $6, %hi(D_0088BF3C)
    /* 300EF0 00400EF0 18BC63C4 */  lwc1       $f3, %lo(D_0088BC18)($3)
    /* 300EF4 00400EF4 8900073C */  lui        $7, %hi(D_0088BF38)
    /* 300EF8 00400EF8 8900043C */  lui        $4, %hi(D_0088BC44)
    /* 300EFC 00400EFC 8900053C */  lui        $5, %hi(D_0088BF34)
    /* 300F00 00400F00 00080A64 */  daddiu     $10, $0, 0x800
    /* 300F04 00400F04 89000C3C */  lui        $12, %hi(D_0088BC00)
    /* 300F08 00400F08 8900023C */  lui        $2, %hi(D_0088BC14)
    /* 300F0C 00400F0C 14BC40C4 */  lwc1       $f0, %lo(D_0088BC14)($2)
    /* 300F10 00400F10 8900033C */  lui        $3, %hi(D_0088BC10)
    /* 300F14 00400F14 3CBFC2E4 */  swc1       $f2, %lo(D_0088BF3C)($6)
    /* 300F18 00400F18 10BC61C4 */  lwc1       $f1, %lo(D_0088BC10)($3)
    /* 300F1C 00400F1C 8900063C */  lui        $6, %hi(D_0088BF4C)
    /* 300F20 00400F20 44BC82C4 */  lwc1       $f2, %lo(D_0088BC44)($4)
    /* 300F24 00400F24 38BFE3E4 */  swc1       $f3, %lo(D_0088BF38)($7)
    /* 300F28 00400F28 8900073C */  lui        $7, %hi(D_0088BF48)
    /* 300F2C 00400F2C 8900023C */  lui        $2, %hi(D_0088BC40)
    /* 300F30 00400F30 40BC43C4 */  lwc1       $f3, %lo(D_0088BC40)($2)
    /* 300F34 00400F34 8900033C */  lui        $3, %hi(D_0088BF30)
    /* 300F38 00400F38 30BF61E4 */  swc1       $f1, %lo(D_0088BF30)($3)
    /* 300F3C 00400F3C 8900043C */  lui        $4, %hi(D_0088BF44)
    /* 300F40 00400F40 34BFA0E4 */  swc1       $f0, %lo(D_0088BF34)($5)
    /* 300F44 00400F44 8900033C */  lui        $3, %hi(D_0088BC3C)
    /* 300F48 00400F48 3CBC60C4 */  lwc1       $f0, %lo(D_0088BC3C)($3)
    /* 300F4C 00400F4C 8900053C */  lui        $5, %hi(D_0088BF40)
    /* 300F50 00400F50 4CBFC2E4 */  swc1       $f2, %lo(D_0088BF4C)($6)
    /* 300F54 00400F54 8900023C */  lui        $2, %hi(D_0088BC38)
    /* 300F58 00400F58 38BC41C4 */  lwc1       $f1, %lo(D_0088BC38)($2)
    /* 300F5C 00400F5C 48BFE3E4 */  swc1       $f3, %lo(D_0088BF48)($7)
    /* 300F60 00400F60 00800734 */  ori        $7, $0, 0x8000
    /* 300F64 00400F64 44BF80E4 */  swc1       $f0, %lo(D_0088BF44)($4)
    /* 300F68 00400F68 8900033C */  lui        $3, %hi(D_0088BC14)
    /* 300F6C 00400F6C 8900023C */  lui        $2, %hi(D_0088BC14)
    /* 300F70 00400F70 14BC488C */  lw         $8, %lo(D_0088BC14)($2)
    /* 300F74 00400F74 40BFA1E4 */  swc1       $f1, %lo(D_0088BF40)($5)
    /* 300F78 00400F78 C0FF023C */  lui        $2, (0xFFC007FF >> 16)
    /* 300F7C 00400F7C FF074934 */  ori        $9, $2, (0xFFC007FF & 0xFFFF)
    /* 300F80 00400F80 8900023C */  lui        $2, %hi(D_0088BC1C)
    /* 300F84 00400F84 24200901 */  and        $4, $8, $9
    /* 300F88 00400F88 1CBC468C */  lw         $6, %lo(D_0088BC1C)($2)
    /* 300F8C 00400F8C 25208A00 */  or         $4, $4, $10
    /* 300F90 00400F90 14BC64AC */  sw         $4, %lo(D_0088BC14)($3)
    /* 300F94 00400F94 8900033C */  lui        $3, %hi(D_0088BC1C)
    /* 300F98 00400F98 80FF023C */  lui        $2, (0xFF800FFF >> 16)
    /* 300F9C 00400F9C FF0F4834 */  ori        $8, $2, (0xFF800FFF & 0xFFFF)
    /* 300FA0 00400FA0 8900023C */  lui        $2, %hi(D_0088BC00)
    /* 300FA4 00400FA4 2420C800 */  and        $4, $6, $8
    /* 300FA8 00400FA8 00BC4B8C */  lw         $11, %lo(D_0088BC00)($2)
    /* 300FAC 00400FAC 7C120600 */  dsll32     $2, $6, 9
    /* 300FB0 00400FB0 7E150200 */  dsrl32     $2, $2, 21
    /* 300FB4 00400FB4 FFFF4524 */  addiu      $5, $2, -0x1
    /* 300FB8 00400FB8 FFFF023C */  lui        $2, (0xFFFF00FF >> 16)
    /* 300FBC 00400FBC FF07A530 */  andi       $5, $5, 0x7FF
    /* 300FC0 00400FC0 FF004634 */  ori        $6, $2, (0xFFFF00FF & 0xFFFF)
    /* 300FC4 00400FC4 00130500 */  sll        $2, $5, 12
    /* 300FC8 00400FC8 25108200 */  or         $2, $4, $2
    /* 300FCC 00400FCC 01000564 */  daddiu     $5, $0, 0x1
    /* 300FD0 00400FD0 1CBC62AC */  sw         $2, %lo(D_0088BC1C)($3)
    /* 300FD4 00400FD4 FEFF0424 */  addiu      $4, $0, -0x2
    /* 300FD8 00400FD8 24106601 */  and        $2, $11, $6
    /* 300FDC 00400FDC 02000364 */  daddiu     $3, $0, 0x2
    /* 300FE0 00400FE0 25104700 */  or         $2, $2, $7
    /* 300FE4 00400FE4 24584400 */  and        $11, $2, $4
    /* 300FE8 00400FE8 FDFF0224 */  addiu      $2, $0, -0x3
    /* 300FEC 00400FEC 25586501 */  or         $11, $11, $5
    /* 300FF0 00400FF0 24686201 */  and        $13, $11, $2
    /* 300FF4 00400FF4 89000B3C */  lui        $11, %hi(D_0088BC3C)
    /* 300FF8 00400FF8 2568A301 */  or         $13, $13, $3
    /* 300FFC 00400FFC 3CBC708D */  lw         $16, %lo(D_0088BC3C)($11)
    /* 301000 00401000 00BC8DAD */  sw         $13, %lo(D_0088BC00)($12)
    /* 301004 00401004 89000D3C */  lui        $13, %hi(D_0088BC3C)
    /* 301008 00401008 89000C3C */  lui        $12, %hi(D_0088BC44)
    /* 30100C 0040100C 89000B3C */  lui        $11, %hi(D_0088BC44)
    /* 301010 00401010 24480902 */  and        $9, $16, $9
    /* 301014 00401014 44BC6F8D */  lw         $15, %lo(D_0088BC44)($11)
    /* 301018 00401018 25482A01 */  or         $9, $9, $10
    /* 30101C 0040101C 3CBCA9AD */  sw         $9, %lo(D_0088BC3C)($13)
    /* 301020 00401020 89000B3C */  lui        $11, %hi(D_0088BC28)
    /* 301024 00401024 7C4A0F00 */  dsll32     $9, $15, 9
    /* 301028 00401028 28BC6E8D */  lw         $14, %lo(D_0088BC28)($11)
    /* 30102C 0040102C 7E4D0900 */  dsrl32     $9, $9, 21
    /* 301030 00401030 2440E801 */  and        $8, $15, $8
    /* 301034 00401034 2430C601 */  and        $6, $14, $6
    /* 301038 00401038 89000B3C */  lui        $11, %hi(D_0088BC28)
    /* 30103C 0040103C 2530C700 */  or         $6, $6, $7
    /* 301040 00401040 2420C400 */  and        $4, $6, $4
    /* 301044 00401044 FFFF2725 */  addiu      $7, $9, -0x1
    /* 301048 00401048 25208500 */  or         $4, $4, $5
    /* 30104C 0040104C FF07E630 */  andi       $6, $7, 0x7FF
    /* 301050 00401050 002B0600 */  sll        $5, $6, 12
    /* 301054 00401054 24108200 */  and        $2, $4, $2
    /* 301058 00401058 25280501 */  or         $5, $8, $5
    /* 30105C 0040105C 25104300 */  or         $2, $2, $3
    /* 301060 00401060 44BC85AD */  sw         $5, %lo(D_0088BC44)($12)
    /* 301064 00401064 E7FB0010 */  b          .L00400004
    /* 301068 00401068 28BC62AD */   sw        $2, %lo(D_0088BC28)($11)
  .L0040106C:
    /* 30106C 0040106C 083C100C */  jal        func_0040f020
    /* 301070 00401070 00000000 */   nop
    /* 301074 00401074 2BFF0010 */  b          .L00400D24
    /* 301078 00401078 00000000 */   nop
  .L0040107C:
    /* 30107C 0040107C 8900043C */  lui        $4, %hi(D_0088BC00)
    /* 301080 00401080 A4FA0F0C */  jal        func_003fea90
    /* 301084 00401084 00BC8424 */   addiu     $4, $4, %lo(D_0088BC00)
    /* 301088 00401088 25FF0010 */  b          .L00400D20
    /* 30108C 0040108C 01000224 */   addiu     $2, $0, 0x1
  .L00401090:
    /* 301090 00401090 9000BFDF */  ld         $31, 0x90($29)
    /* 301094 00401094 8000BE7B */  lq         $30, 0x80($29)
    /* 301098 00401098 7000B77B */  lq         $23, 0x70($29)
    /* 30109C 0040109C 6000B67B */  lq         $22, 0x60($29)
    /* 3010A0 004010A0 5000B57B */  lq         $21, 0x50($29)
    /* 3010A4 004010A4 4000B47B */  lq         $20, 0x40($29)
    /* 3010A8 004010A8 3000B37B */  lq         $19, 0x30($29)
    /* 3010AC 004010AC 2000B27B */  lq         $18, 0x20($29)
    /* 3010B0 004010B0 1000B17B */  lq         $17, 0x10($29)
    /* 3010B4 004010B4 0000B07B */  lq         $16, 0x0($29)
    /* 3010B8 004010B8 0800E003 */  jr         $31
    /* 3010BC 004010BC D000BD27 */   addiu     $29, $29, 0xD0
.size func_003ff5b0, 0x1b10
