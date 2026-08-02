.section .text
.set noat
.set noreorder
glabel func_001e3de0
    /* E3DE0 001E3DE0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E3DE4 001E3DE4 2000BFFF */  sd         $31, 0x20($29)
    /* E3DE8 001E3DE8 1000B17F */  sq         $17, 0x10($29)
    /* E3DEC 001E3DEC 0000B07F */  sq         $16, 0x0($29)
    /* E3DF0 001E3DF0 2D200000 */  daddu      $4, $0, $0
    /* E3DF4 001E3DF4 00730A0C */  jal        func_0029cc00
    /* E3DF8 001E3DF8 00000000 */   nop
    /* E3DFC 001E3DFC FFFF5130 */  andi       $17, $2, 0xFFFF
    /* E3E00 001E3E00 01000424 */  addiu      $4, $0, 0x1
    /* E3E04 001E3E04 00730A0C */  jal        func_0029cc00
    /* E3E08 001E3E08 00000000 */   nop
    /* E3E0C 001E3E0C FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E3E10 001E3E10 2D800000 */  daddu      $16, $0, $0
    /* E3E14 001E3E14 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* E3E18 001E3E18 01000524 */  addiu      $5, $0, 0x1
    /* E3E1C 001E3E1C 0B004510 */  beq        $2, $5, .L001E3E4C
    /* E3E20 001E3E20 00000000 */   nop
    /* E3E24 001E3E24 03004010 */  beqz       $2, .L001E3E34
    /* E3E28 001E3E28 00000000 */   nop
    /* E3E2C 001E3E2C 0C000010 */  b          .L001E3E60
    /* E3E30 001E3E30 00000000 */   nop
  .L001E3E34:
    /* E3E34 001E3E34 0800063C */  lui        $6, (0x80000 >> 16)
    /* E3E38 001E3E38 A064070C */  jal        func_001d9280
    /* E3E3C 001E3E3C 00000000 */   nop
    /* E3E40 001E3E40 2D804000 */  daddu      $16, $2, $0
    /* E3E44 001E3E44 06000010 */  b          .L001E3E60
    /* E3E48 001E3E48 00000000 */   nop
  .L001E3E4C:
    /* E3E4C 001E3E4C 02000524 */  addiu      $5, $0, 0x2
    /* E3E50 001E3E50 0800063C */  lui        $6, (0x80000 >> 16)
    /* E3E54 001E3E54 A064070C */  jal        func_001d9280
    /* E3E58 001E3E58 00000000 */   nop
    /* E3E5C 001E3E5C 2D804000 */  daddu      $16, $2, $0
  .L001E3E60:
    /* E3E60 001E3E60 1E000012 */  beqz       $16, .L001E3EDC
    /* E3E64 001E3E64 00000000 */   nop
    /* E3E68 001E3E68 02000424 */  addiu      $4, $0, 0x2
    /* E3E6C 001E3E6C 00730A0C */  jal        func_0029cc00
    /* E3E70 001E3E70 00000000 */   nop
    /* E3E74 001E3E74 3C1A0200 */  dsll32     $3, $2, 8
    /* E3E78 001E3E78 3E1A0300 */  dsrl32     $3, $3, 8
    /* E3E7C 001E3E7C 0019023C */  lui        $2, (0x19000000 >> 16)
    /* E3E80 001E3E80 25206200 */  or         $4, $3, $2
    /* E3E84 001E3E84 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E3E88 001E3E88 24108200 */  and        $2, $4, $2
    /* E3E8C 001E3E8C 021E0200 */  srl        $3, $2, 24
    /* E3E90 001E3E90 3C2A0400 */  dsll32     $5, $4, 8
    /* E3E94 001E3E94 3E2A0500 */  dsrl32     $5, $5, 8
    /* E3E98 001E3E98 04006014 */  bnez       $3, .L001E3EAC
    /* E3E9C 001E3E9C 00000000 */   nop
    /* E3EA0 001E3EA0 2D100000 */  daddu      $2, $0, $0
    /* E3EA4 001E3EA4 0B000010 */  b          .L001E3ED4
    /* E3EA8 001E3EA8 00000000 */   nop
  .L001E3EAC:
    /* E3EAC 001E3EAC 2D200002 */  daddu      $4, $16, $0
    /* E3EB0 001E3EB0 40100300 */  sll        $2, $3, 1
    /* E3EB4 001E3EB4 21104300 */  addu       $2, $2, $3
    /* E3EB8 001E3EB8 80180200 */  sll        $3, $2, 2
    /* E3EBC 001E3EBC 6100023C */  lui        $2, %hi(D_00609850)
    /* E3EC0 001E3EC0 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E3EC4 001E3EC4 21104300 */  addu       $2, $2, $3
    /* E3EC8 001E3EC8 0000428C */  lw         $2, 0x0($2)
    /* E3ECC 001E3ECC 09F84000 */  jalr       $2
    /* E3ED0 001E3ED0 00000000 */   nop
  .L001E3ED4:
    /* E3ED4 001E3ED4 02000010 */  b          .L001E3EE0
    /* E3ED8 001E3ED8 00000000 */   nop
  .L001E3EDC:
    /* E3EDC 001E3EDC 2D100000 */  daddu      $2, $0, $0
  .L001E3EE0:
    /* E3EE0 001E3EE0 2B200200 */  sltu       $4, $0, $2
    /* E3EE4 001E3EE4 D4730A0C */  jal        func_0029cf50
    /* E3EE8 001E3EE8 00000000 */   nop
    /* E3EEC 001E3EEC 01000224 */  addiu      $2, $0, 0x1
    /* E3EF0 001E3EF0 2000BFDF */  ld         $31, 0x20($29)
    /* E3EF4 001E3EF4 1000B17B */  lq         $17, 0x10($29)
    /* E3EF8 001E3EF8 0000B07B */  lq         $16, 0x0($29)
    /* E3EFC 001E3EFC 3000BD27 */  addiu      $29, $29, 0x30
    /* E3F00 001E3F00 0800E003 */  jr         $31
    /* E3F04 001E3F04 00000000 */   nop
    /* E3F08 001E3F08 00000000 */  nop
    /* E3F0C 001E3F0C 00000000 */  nop
.size func_001e3de0, 0x130
