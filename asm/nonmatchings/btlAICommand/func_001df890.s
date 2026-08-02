.section .text
.set noat
.set noreorder
glabel func_001df890
    /* DF890 001DF890 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF894 001DF894 1000BFFF */  sd         $31, 0x10($29)
    /* DF898 001DF898 0000B07F */  sq         $16, 0x0($29)
    /* DF89C 001DF89C 2D200000 */  daddu      $4, $0, $0
    /* DF8A0 001DF8A0 00730A0C */  jal        func_0029cc00
    /* DF8A4 001DF8A4 00000000 */   nop
    /* DF8A8 001DF8A8 3C1A0200 */  dsll32     $3, $2, 8
    /* DF8AC 001DF8AC 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF8B0 001DF8B0 0009023C */  lui        $2, (0x9000000 >> 16)
    /* DF8B4 001DF8B4 25806200 */  or         $16, $3, $2
    /* DF8B8 001DF8B8 14740A0C */  jal        func_0029d050
    /* DF8BC 001DF8BC 00000000 */   nop
    /* DF8C0 001DF8C0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF8C4 001DF8C4 24180302 */  and        $3, $16, $3
    /* DF8C8 001DF8C8 021E0300 */  srl        $3, $3, 24
    /* DF8CC 001DF8CC 3C2A1000 */  dsll32     $5, $16, 8
    /* DF8D0 001DF8D0 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF8D4 001DF8D4 04006014 */  bnez       $3, .L001DF8E8
    /* DF8D8 001DF8D8 00000000 */   nop
    /* DF8DC 001DF8DC 2D100000 */  daddu      $2, $0, $0
    /* DF8E0 001DF8E0 0B000010 */  b          .L001DF910
    /* DF8E4 001DF8E4 00000000 */   nop
  .L001DF8E8:
    /* DF8E8 001DF8E8 2D204000 */  daddu      $4, $2, $0
    /* DF8EC 001DF8EC 40100300 */  sll        $2, $3, 1
    /* DF8F0 001DF8F0 21104300 */  addu       $2, $2, $3
    /* DF8F4 001DF8F4 80180200 */  sll        $3, $2, 2
    /* DF8F8 001DF8F8 6100023C */  lui        $2, %hi(D_00609850)
    /* DF8FC 001DF8FC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF900 001DF900 21104300 */  addu       $2, $2, $3
    /* DF904 001DF904 0000428C */  lw         $2, 0x0($2)
    /* DF908 001DF908 09F84000 */  jalr       $2
    /* DF90C 001DF90C 00000000 */   nop
  .L001DF910:
    /* DF910 001DF910 2B200200 */  sltu       $4, $0, $2
    /* DF914 001DF914 D4730A0C */  jal        func_0029cf50
    /* DF918 001DF918 00000000 */   nop
    /* DF91C 001DF91C 01000224 */  addiu      $2, $0, 0x1
    /* DF920 001DF920 1000BFDF */  ld         $31, 0x10($29)
    /* DF924 001DF924 0000B07B */  lq         $16, 0x0($29)
    /* DF928 001DF928 2000BD27 */  addiu      $29, $29, 0x20
    /* DF92C 001DF92C 0800E003 */  jr         $31
    /* DF930 001DF930 00000000 */   nop
    /* DF934 001DF934 00000000 */  nop
    /* DF938 001DF938 00000000 */  nop
    /* DF93C 001DF93C 00000000 */  nop
.size func_001df890, 0xb0
