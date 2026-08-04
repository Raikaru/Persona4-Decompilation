.section .text
.set noat
.set noreorder
glabel func_001da1b0
    /* DA1B0 001DA1B0 2000828C */  lw         $2, 0x20($4)
    /* DA1B4 001DA1B4 04004018 */  blez       $2, .L001DA1C8
    /* DA1B8 001DA1B8 00000000 */   nop
    /* DA1BC 001DA1BC 2D100000 */  daddu      $2, $0, $0
    /* DA1C0 001DA1C0 17000010 */  b          .L001DA220
    /* DA1C4 001DA1C4 00000000 */   nop
  .L001DA1C8:
    /* DA1C8 001DA1C8 3000828C */  lw         $2, 0x30($4)
    /* DA1CC 001DA1CC A2004390 */  lbu        $3, 0xA2($2)
    /* DA1D0 001DA1D0 01000224 */  addiu      $2, $0, 0x1
    /* DA1D4 001DA1D4 0B006210 */  beq        $3, $2, .L001DA204
    /* DA1D8 001DA1D8 00000000 */   nop
    /* DA1DC 001DA1DC 03006010 */  beqz       $3, .L001DA1EC
    /* DA1E0 001DA1E0 00000000 */   nop
    /* DA1E4 001DA1E4 0D000010 */  b          .L001DA21C
    /* DA1E8 001DA1E8 00000000 */   nop
  .L001DA1EC:
    /* DA1EC 001DA1EC ACB3828F */  lw         $2, -0x4C54($28)
    /* DA1F0 001DA1F0 1A004294 */  lhu        $2, 0x1A($2)
    /* DA1F4 001DA1F4 01004238 */  xori       $2, $2, 0x1
    /* DA1F8 001DA1F8 0100422C */  sltiu      $2, $2, 0x1
    /* DA1FC 001DA1FC 08000010 */  b          .L001DA220
    /* DA200 001DA200 00000000 */   nop
  .L001DA204:
    /* DA204 001DA204 ACB3828F */  lw         $2, -0x4C54($28)
    /* DA208 001DA208 1A004294 */  lhu        $2, 0x1A($2)
    /* DA20C 001DA20C 02004238 */  xori       $2, $2, 0x2
    /* DA210 001DA210 0100422C */  sltiu      $2, $2, 0x1
    /* DA214 001DA214 02000010 */  b          .L001DA220
    /* DA218 001DA218 00000000 */   nop
  .L001DA21C:
    /* DA21C 001DA21C 2D100000 */  daddu      $2, $0, $0
  .L001DA220:
    /* DA220 001DA220 0800E003 */  jr         $31
    /* DA224 001DA224 00000000 */   nop
    /* DA228 001DA228 00000000 */  nop
    /* DA22C 001DA22C 00000000 */  nop
.size func_001da1b0, 0x80
