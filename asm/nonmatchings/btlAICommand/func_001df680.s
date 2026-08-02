.section .text
.set noat
.set noreorder
glabel func_001df680
    /* DF680 001DF680 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF684 001DF684 1000BFFF */  sd         $31, 0x10($29)
    /* DF688 001DF688 0000B07F */  sq         $16, 0x0($29)
    /* DF68C 001DF68C 2D200000 */  daddu      $4, $0, $0
    /* DF690 001DF690 00730A0C */  jal        func_0029cc00
    /* DF694 001DF694 00000000 */   nop
    /* DF698 001DF698 3C1A0200 */  dsll32     $3, $2, 8
    /* DF69C 001DF69C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF6A0 001DF6A0 0006023C */  lui        $2, (0x6000000 >> 16)
    /* DF6A4 001DF6A4 25806200 */  or         $16, $3, $2
    /* DF6A8 001DF6A8 14740A0C */  jal        func_0029d050
    /* DF6AC 001DF6AC 00000000 */   nop
    /* DF6B0 001DF6B0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF6B4 001DF6B4 24180302 */  and        $3, $16, $3
    /* DF6B8 001DF6B8 021E0300 */  srl        $3, $3, 24
    /* DF6BC 001DF6BC 3C2A1000 */  dsll32     $5, $16, 8
    /* DF6C0 001DF6C0 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF6C4 001DF6C4 04006014 */  bnez       $3, .L001DF6D8
    /* DF6C8 001DF6C8 00000000 */   nop
    /* DF6CC 001DF6CC 2D100000 */  daddu      $2, $0, $0
    /* DF6D0 001DF6D0 0B000010 */  b          .L001DF700
    /* DF6D4 001DF6D4 00000000 */   nop
  .L001DF6D8:
    /* DF6D8 001DF6D8 2D204000 */  daddu      $4, $2, $0
    /* DF6DC 001DF6DC 40100300 */  sll        $2, $3, 1
    /* DF6E0 001DF6E0 21104300 */  addu       $2, $2, $3
    /* DF6E4 001DF6E4 80180200 */  sll        $3, $2, 2
    /* DF6E8 001DF6E8 6100023C */  lui        $2, %hi(D_00609850)
    /* DF6EC 001DF6EC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF6F0 001DF6F0 21104300 */  addu       $2, $2, $3
    /* DF6F4 001DF6F4 0000428C */  lw         $2, 0x0($2)
    /* DF6F8 001DF6F8 09F84000 */  jalr       $2
    /* DF6FC 001DF6FC 00000000 */   nop
  .L001DF700:
    /* DF700 001DF700 2B200200 */  sltu       $4, $0, $2
    /* DF704 001DF704 D4730A0C */  jal        func_0029cf50
    /* DF708 001DF708 00000000 */   nop
    /* DF70C 001DF70C 01000224 */  addiu      $2, $0, 0x1
    /* DF710 001DF710 1000BFDF */  ld         $31, 0x10($29)
    /* DF714 001DF714 0000B07B */  lq         $16, 0x0($29)
    /* DF718 001DF718 2000BD27 */  addiu      $29, $29, 0x20
    /* DF71C 001DF71C 0800E003 */  jr         $31
    /* DF720 001DF720 00000000 */   nop
    /* DF724 001DF724 00000000 */  nop
    /* DF728 001DF728 00000000 */  nop
    /* DF72C 001DF72C 00000000 */  nop
.size func_001df680, 0xb0
