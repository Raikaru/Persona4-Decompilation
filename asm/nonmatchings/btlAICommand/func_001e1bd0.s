.section .text
.set noat
.set noreorder
glabel func_001e1bd0
    /* E1BD0 001E1BD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E1BD4 001E1BD4 1000BFFF */  sd         $31, 0x10($29)
    /* E1BD8 001E1BD8 0000B07F */  sq         $16, 0x0($29)
    /* E1BDC 001E1BDC 14740A0C */  jal        func_0029d050
    /* E1BE0 001E1BE0 00000000 */   nop
    /* E1BE4 001E1BE4 2D804000 */  daddu      $16, $2, $0
    /* E1BE8 001E1BE8 2D200000 */  daddu      $4, $0, $0
    /* E1BEC 001E1BEC 00730A0C */  jal        func_0029cc00
    /* E1BF0 001E1BF0 00000000 */   nop
    /* E1BF4 001E1BF4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1BF8 001E1BF8 3000028E */  lw         $2, 0x30($16)
    /* E1BFC 001E1BFC A2004390 */  lbu        $3, 0xA2($2)
    /* E1C00 001E1C00 01000224 */  addiu      $2, $0, 0x1
    /* E1C04 001E1C04 04106200 */  sllv       $2, $2, $3
    /* E1C08 001E1C08 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1C0C 001E1C0C 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1C10 001E1C10 A064070C */  jal        func_001d9280
    /* E1C14 001E1C14 00000000 */   nop
    /* E1C18 001E1C18 2D804000 */  daddu      $16, $2, $0
    /* E1C1C 001E1C1C 1E000012 */  beqz       $16, .L001E1C98
    /* E1C20 001E1C20 00000000 */   nop
    /* E1C24 001E1C24 01000424 */  addiu      $4, $0, 0x1
    /* E1C28 001E1C28 00730A0C */  jal        func_0029cc00
    /* E1C2C 001E1C2C 00000000 */   nop
    /* E1C30 001E1C30 3C1A0200 */  dsll32     $3, $2, 8
    /* E1C34 001E1C34 3E1A0300 */  dsrl32     $3, $3, 8
    /* E1C38 001E1C38 0018023C */  lui        $2, (0x18000000 >> 16)
    /* E1C3C 001E1C3C 25206200 */  or         $4, $3, $2
    /* E1C40 001E1C40 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E1C44 001E1C44 24108200 */  and        $2, $4, $2
    /* E1C48 001E1C48 021E0200 */  srl        $3, $2, 24
    /* E1C4C 001E1C4C 3C2A0400 */  dsll32     $5, $4, 8
    /* E1C50 001E1C50 3E2A0500 */  dsrl32     $5, $5, 8
    /* E1C54 001E1C54 04006014 */  bnez       $3, .L001E1C68
    /* E1C58 001E1C58 00000000 */   nop
    /* E1C5C 001E1C5C 2D100000 */  daddu      $2, $0, $0
    /* E1C60 001E1C60 0B000010 */  b          .L001E1C90
    /* E1C64 001E1C64 00000000 */   nop
  .L001E1C68:
    /* E1C68 001E1C68 2D200002 */  daddu      $4, $16, $0
    /* E1C6C 001E1C6C 40100300 */  sll        $2, $3, 1
    /* E1C70 001E1C70 21104300 */  addu       $2, $2, $3
    /* E1C74 001E1C74 80180200 */  sll        $3, $2, 2
    /* E1C78 001E1C78 6100023C */  lui        $2, %hi(D_00609850)
    /* E1C7C 001E1C7C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E1C80 001E1C80 21104300 */  addu       $2, $2, $3
    /* E1C84 001E1C84 0000428C */  lw         $2, 0x0($2)
    /* E1C88 001E1C88 09F84000 */  jalr       $2
    /* E1C8C 001E1C8C 00000000 */   nop
  .L001E1C90:
    /* E1C90 001E1C90 02000010 */  b          .L001E1C9C
    /* E1C94 001E1C94 00000000 */   nop
  .L001E1C98:
    /* E1C98 001E1C98 2D100000 */  daddu      $2, $0, $0
  .L001E1C9C:
    /* E1C9C 001E1C9C 2B200200 */  sltu       $4, $0, $2
    /* E1CA0 001E1CA0 D4730A0C */  jal        func_0029cf50
    /* E1CA4 001E1CA4 00000000 */   nop
    /* E1CA8 001E1CA8 01000224 */  addiu      $2, $0, 0x1
    /* E1CAC 001E1CAC 1000BFDF */  ld         $31, 0x10($29)
    /* E1CB0 001E1CB0 0000B07B */  lq         $16, 0x0($29)
    /* E1CB4 001E1CB4 2000BD27 */  addiu      $29, $29, 0x20
    /* E1CB8 001E1CB8 0800E003 */  jr         $31
    /* E1CBC 001E1CBC 00000000 */   nop
.size func_001e1bd0, 0xf0
