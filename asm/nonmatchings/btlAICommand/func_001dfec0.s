.section .text
.set noat
.set noreorder
glabel func_001dfec0
    /* DFEC0 001DFEC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFEC4 001DFEC4 1000BFFF */  sd         $31, 0x10($29)
    /* DFEC8 001DFEC8 0000B07F */  sq         $16, 0x0($29)
    /* DFECC 001DFECC 2D200000 */  daddu      $4, $0, $0
    /* DFED0 001DFED0 00730A0C */  jal        func_0029cc00
    /* DFED4 001DFED4 00000000 */   nop
    /* DFED8 001DFED8 3C1A0200 */  dsll32     $3, $2, 8
    /* DFEDC 001DFEDC 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFEE0 001DFEE0 0012023C */  lui        $2, (0x12000000 >> 16)
    /* DFEE4 001DFEE4 25806200 */  or         $16, $3, $2
    /* DFEE8 001DFEE8 14740A0C */  jal        func_0029d050
    /* DFEEC 001DFEEC 00000000 */   nop
    /* DFEF0 001DFEF0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFEF4 001DFEF4 24180302 */  and        $3, $16, $3
    /* DFEF8 001DFEF8 021E0300 */  srl        $3, $3, 24
    /* DFEFC 001DFEFC 3C2A1000 */  dsll32     $5, $16, 8
    /* DFF00 001DFF00 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFF04 001DFF04 04006014 */  bnez       $3, .L001DFF18
    /* DFF08 001DFF08 00000000 */   nop
    /* DFF0C 001DFF0C 2D100000 */  daddu      $2, $0, $0
    /* DFF10 001DFF10 0B000010 */  b          .L001DFF40
    /* DFF14 001DFF14 00000000 */   nop
  .L001DFF18:
    /* DFF18 001DFF18 2D204000 */  daddu      $4, $2, $0
    /* DFF1C 001DFF1C 40100300 */  sll        $2, $3, 1
    /* DFF20 001DFF20 21104300 */  addu       $2, $2, $3
    /* DFF24 001DFF24 80180200 */  sll        $3, $2, 2
    /* DFF28 001DFF28 6100023C */  lui        $2, %hi(D_00609850)
    /* DFF2C 001DFF2C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFF30 001DFF30 21104300 */  addu       $2, $2, $3
    /* DFF34 001DFF34 0000428C */  lw         $2, 0x0($2)
    /* DFF38 001DFF38 09F84000 */  jalr       $2
    /* DFF3C 001DFF3C 00000000 */   nop
  .L001DFF40:
    /* DFF40 001DFF40 2B200200 */  sltu       $4, $0, $2
    /* DFF44 001DFF44 D4730A0C */  jal        func_0029cf50
    /* DFF48 001DFF48 00000000 */   nop
    /* DFF4C 001DFF4C 01000224 */  addiu      $2, $0, 0x1
    /* DFF50 001DFF50 1000BFDF */  ld         $31, 0x10($29)
    /* DFF54 001DFF54 0000B07B */  lq         $16, 0x0($29)
    /* DFF58 001DFF58 2000BD27 */  addiu      $29, $29, 0x20
    /* DFF5C 001DFF5C 0800E003 */  jr         $31
    /* DFF60 001DFF60 00000000 */   nop
    /* DFF64 001DFF64 00000000 */  nop
    /* DFF68 001DFF68 00000000 */  nop
    /* DFF6C 001DFF6C 00000000 */  nop
.size func_001dfec0, 0xb0
