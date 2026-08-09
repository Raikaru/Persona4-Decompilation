.section .text
.set noat
.set noreorder
glabel func_001ea8e0
    /* EA8E0 001EA8E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EA8E4 001EA8E4 0000BFFF */  sd         $31, 0x0($29)
    /* EA8E8 001EA8E8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA8EC 001EA8EC 7001448C */  lw         $4, 0x170($2)
    /* EA8F0 001EA8F0 EC80060C */  jal        func_001a03b0
    /* EA8F4 001EA8F4 00000000 */   nop
    /* EA8F8 001EA8F8 03000424 */  addiu      $4, $0, 0x3
    /* EA8FC 001EA8FC FF0F0524 */  addiu      $5, $0, 0xFFF
    /* EA900 001EA900 C04D070C */  jal        func_001d3700
    /* EA904 001EA904 00000000 */   nop
    /* EA908 001EA908 2D204000 */  daddu      $4, $2, $0
    /* EA90C 001EA90C 2D280000 */  daddu      $5, $0, $0
    /* EA910 001EA910 6451060C */  jal        func_00194590
    /* EA914 001EA914 00000000 */   nop
    /* EA918 001EA918 2D200000 */  daddu      $4, $0, $0
    /* EA91C 001EA91C 00730A0C */  jal        func_0029cc00
    /* EA920 001EA920 00000000 */   nop
    /* EA924 001EA924 00008244 */  mtc1       $2, $f0
    /* EA928 001EA928 00000000 */  nop
    /* EA92C 001EA92C 60008046 */  cvt.s.w    $f1, $f0
    /* EA930 001EA930 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* EA934 001EA934 00008244 */  mtc1       $2, $f0
    /* EA938 001EA938 00000000 */  nop
    /* EA93C 001EA93C 830B0046 */  div.s      $f14, $f1, $f0
    /* EA940 001EA940 ACB3828F */  lw         $2, -0x4C54($28)
    /* EA944 001EA944 7001448C */  lw         $4, 0x170($2)
    /* EA948 001EA948 8800053C */  lui        $5, %hi(D_00881420)
    /* EA94C 001EA94C 2014A524 */  addiu      $5, $5, %lo(D_00881420)
    /* EA950 001EA950 8800063C */  lui        $6, %hi(D_00881400)
    /* EA954 001EA954 0014C624 */  addiu      $6, $6, %lo(D_00881400)
    /* EA958 001EA958 58B48CC7 */  lwc1       $f12, -0x4BA8($28)
    /* EA95C 001EA95C 8800073C */  lui        $7, %hi(D_00881410)
    /* EA960 001EA960 1014E724 */  addiu      $7, $7, %lo(D_00881410)
    /* EA964 001EA964 8800083C */  lui        $8, %hi(D_008813F0)
    /* EA968 001EA968 F0130825 */  addiu      $8, $8, %lo(D_008813F0)
    /* EA96C 001EA96C 54B48DC7 */  lwc1       $f13, -0x4BAC($28)
    /* EA970 001EA970 D4F2060C */  jal        func_001bcb50
    /* EA974 001EA974 00000000 */   nop
    /* EA978 001EA978 2D204000 */  daddu      $4, $2, $0
    /* EA97C 001EA97C 2D280000 */  daddu      $5, $0, $0
    /* EA980 001EA980 6451060C */  jal        func_00194590
    /* EA984 001EA984 00000000 */   nop
    /* EA988 001EA988 01000224 */  addiu      $2, $0, 0x1
    /* EA98C 001EA98C 0000BFDF */  ld         $31, 0x0($29)
    /* EA990 001EA990 1000BD27 */  addiu      $29, $29, 0x10
    /* EA994 001EA994 0800E003 */  jr         $31
    /* EA998 001EA998 00000000 */   nop
    /* EA99C 001EA99C 00000000 */  nop
.size func_001ea8e0, 0xc0
