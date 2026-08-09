.section .text
.set noat
.set noreorder
glabel func_004ca720
    /* 3CA720 004CA720 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA724 004CA724 7200043C */  lui        $4, %hi(D_007188A0)
    /* 3CA728 004CA728 0000B0FF */  sd         $16, 0x0($29)
    /* 3CA72C 004CA72C A0889024 */  addiu      $16, $4, %lo(D_007188A0)
    /* 3CA730 004CA730 9200033C */  lui        $3, %hi(D_00922E18)
    /* 3CA734 004CA734 7600023C */  lui        $2, %hi(D_00758688)
    /* 3CA738 004CA738 0000048E */  lw         $4, 0x0($16)
    /* 3CA73C 004CA73C 182E6324 */  addiu      $3, $3, %lo(D_00922E18)
    /* 3CA740 004CA740 88864224 */  addiu      $2, $2, %lo(D_00758688)
    /* 3CA744 004CA744 0800BFFF */  sd         $31, 0x8($29)
    /* 3CA748 004CA748 000062AC */  sw         $2, 0x0($3)
    /* 3CA74C 004CA74C 4B008054 */  bnel       $4, $0, .L004CA87C
    /* 3CA750 004CA750 01008224 */   addiu     $2, $4, 0x1
    /* 3CA754 004CA754 1215130C */  jal        func_004c5448
    /* 3CA758 004CA758 00000000 */   nop
    /* 3CA75C 004CA75C 2A15130C */  jal        func_004c54a8
    /* 3CA760 004CA760 00000000 */   nop
    /* 3CA764 004CA764 C8BA130C */  jal        func_004eeb20
    /* 3CA768 004CA768 00000000 */   nop
    /* 3CA76C 004CA76C C6B7130C */  jal        func_004edf18
    /* 3CA770 004CA770 00000000 */   nop
    /* 3CA774 004CA774 40B5130C */  jal        func_004ed500
    /* 3CA778 004CA778 00000000 */   nop
    /* 3CA77C 004CA77C 801A130C */  jal        func_004c6a00
    /* 3CA780 004CA780 00000000 */   nop
    /* 3CA784 004CA784 4246130C */  jal        func_004d1908
    /* 3CA788 004CA788 00000000 */   nop
    /* 3CA78C 004CA78C 7636130C */  jal        func_004cd9d8
    /* 3CA790 004CA790 00000000 */   nop
    /* 3CA794 004CA794 441B130C */  jal        func_004c6d10
    /* 3CA798 004CA798 00000000 */   nop
    /* 3CA79C 004CA79C 9435130C */  jal        func_004cd650
    /* 3CA7A0 004CA7A0 00000000 */   nop
    /* 3CA7A4 004CA7A4 46A6130C */  jal        func_004e9918
    /* 3CA7A8 004CA7A8 00000000 */   nop
    /* 3CA7AC 004CA7AC 78C4130C */  jal        func_004f11e0
    /* 3CA7B0 004CA7B0 00000000 */   nop
    /* 3CA7B4 004CA7B4 4D00043C */  lui        $4, %hi(func_004ca668)
    /* 3CA7B8 004CA7B8 2D280000 */  daddu      $5, $0, $0
    /* 3CA7BC 004CA7BC A035130C */  jal        func_004cd680
    /* 3CA7C0 004CA7C0 68A68424 */   addiu     $4, $4, %lo(func_004ca668)
    /* 3CA7C4 004CA7C4 4D00043C */  lui        $4, %hi(func_004ca680)
    /* 3CA7C8 004CA7C8 80A68424 */  addiu      $4, $4, %lo(func_004ca680)
    /* 3CA7CC 004CA7CC 14A6130C */  jal        func_004e9850
    /* 3CA7D0 004CA7D0 2D280000 */   daddu     $5, $0, $0
    /* 3CA7D4 004CA7D4 7200043C */  lui        $4, %hi(D_007188C0)
    /* 3CA7D8 004CA7D8 C0888424 */  addiu      $4, $4, %lo(D_007188C0)
    /* 3CA7DC 004CA7DC 2D280000 */  daddu      $5, $0, $0
    /* 3CA7E0 004CA7E0 72FE100C */  jal        func_0043f9c8
    /* 3CA7E4 004CA7E4 800C0624 */   addiu     $6, $0, 0xC80
    /* 3CA7E8 004CA7E8 4D00063C */  lui        $6, %hi(func_004ca6e0)
    /* 3CA7EC 004CA7EC 7600083C */  lui        $8, %hi(D_007586D8)
    /* 3CA7F0 004CA7F0 E0A6C624 */  addiu      $6, $6, %lo(func_004ca6e0)
    /* 3CA7F4 004CA7F4 D8860825 */  addiu      $8, $8, %lo(D_007586D8)
    /* 3CA7F8 004CA7F8 02000424 */  addiu      $4, $0, 0x2
    /* 3CA7FC 004CA7FC 01000524 */  addiu      $5, $0, 0x1
    /* 3CA800 004CA800 1EC3130C */  jal        func_004f0c78
    /* 3CA804 004CA804 2D380000 */   daddu     $7, $0, $0
    /* 3CA808 004CA808 4D00053C */  lui        $5, %hi(func_004ca700)
    /* 3CA80C 004CA80C 7600073C */  lui        $7, %hi(D_007586E8)
    /* 3CA810 004CA810 00A7A524 */  addiu      $5, $5, %lo(func_004ca700)
    /* 3CA814 004CA814 E886E724 */  addiu      $7, $7, %lo(D_007586E8)
    /* 3CA818 004CA818 04000424 */  addiu      $4, $0, 0x4
    /* 3CA81C 004CA81C 98C2130C */  jal        func_004f0a60
    /* 3CA820 004CA820 2D300000 */   daddu     $6, $0, $0
    /* 3CA824 004CA824 7200033C */  lui        $3, %hi(D_007188B4)
    /* 3CA828 004CA828 4D00053C */  lui        $5, %hi(func_004ca6c0)
    /* 3CA82C 004CA82C 7600073C */  lui        $7, %hi(D_007586F8)
    /* 3CA830 004CA830 F886E724 */  addiu      $7, $7, %lo(D_007586F8)
    /* 3CA834 004CA834 C0A6A524 */  addiu      $5, $5, %lo(func_004ca6c0)
    /* 3CA838 004CA838 2D300000 */  daddu      $6, $0, $0
    /* 3CA83C 004CA83C 05000424 */  addiu      $4, $0, 0x5
    /* 3CA840 004CA840 98C2130C */  jal        func_004f0a60
    /* 3CA844 004CA844 B48862AC */   sw        $2, %lo(D_007188B4)($3)
    /* 3CA848 004CA848 7200033C */  lui        $3, %hi(D_007188B8)
    /* 3CA84C 004CA84C 7200053C */  lui        $5, %hi(D_007188A8)
    /* 3CA850 004CA850 B8886324 */  addiu      $3, $3, %lo(D_007188B8)
    /* 3CA854 004CA854 A888A2AC */  sw         $2, %lo(D_007188A8)($5)
    /* 3CA858 004CA858 000060AC */  sw         $0, 0x0($3)
    /* 3CA85C 004CA85C 3C000424 */  addiu      $4, $0, 0x3C
    /* 3CA860 004CA860 7200063C */  lui        $6, %hi(D_007188B0)
    /* 3CA864 004CA864 1055130C */  jal        func_004d5440
    /* 3CA868 004CA868 B088C0AC */   sw        $0, %lo(D_007188B0)($6)
    /* 3CA86C 004CA86C 3015130C */  jal        func_004c54c0
    /* 3CA870 004CA870 00000000 */   nop
    /* 3CA874 004CA874 0000048E */  lw         $4, 0x0($16)
    /* 3CA878 004CA878 01008224 */  addiu      $2, $4, 0x1
  .L004CA87C:
    /* 3CA87C 004CA87C 0800BFDF */  ld         $31, 0x8($29)
    /* 3CA880 004CA880 000002AE */  sw         $2, 0x0($16)
    /* 3CA884 004CA884 0000B0DF */  ld         $16, 0x0($29)
    /* 3CA888 004CA888 0800E003 */  jr         $31
    /* 3CA88C 004CA88C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca720, 0x170
