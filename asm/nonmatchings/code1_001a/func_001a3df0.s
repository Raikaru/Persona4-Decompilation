.section .text
.set noat
.set noreorder
glabel func_001a3df0
    /* A3DF0 001A3DF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* A3DF4 001A3DF4 2000BFFF */  sd         $31, 0x20($29)
    /* A3DF8 001A3DF8 1000B17F */  sq         $17, 0x10($29)
    /* A3DFC 001A3DFC 0000B07F */  sq         $16, 0x0($29)
    /* A3E00 001A3E00 2D808000 */  daddu      $16, $4, $0
    /* A3E04 001A3E04 ACB3828F */  lw         $2, -0x4C54($28)
    /* A3E08 001A3E08 7401518C */  lw         $17, 0x174($2)
    /* A3E0C 001A3E0C 11000010 */  b          .L001A3E54
    /* A3E10 001A3E10 00000000 */   nop
  .L001A3E14:
    /* A3E14 001A3E14 2D202002 */  daddu      $4, $17, $0
    /* A3E18 001A3E18 7C81060C */  jal        func_001a05f0
    /* A3E1C 001A3E1C 00000000 */   nop
    /* A3E20 001A3E20 0B004010 */  beqz       $2, .L001A3E50
    /* A3E24 001A3E24 00000000 */   nop
    /* A3E28 001A3E28 3000228E */  lw         $2, 0x30($17)
    /* A3E2C 001A3E2C 0C0A448C */  lw         $4, 0xA0C($2)
    /* A3E30 001A3E30 A86D060C */  jal        func_0019b6a0
    /* A3E34 001A3E34 00000000 */   nop
    /* A3E38 001A3E38 2D204000 */  daddu      $4, $2, $0
    /* A3E3C 001A3E3C 000023DE */  ld         $3, 0x0($17)
    /* A3E40 001A3E40 600043FC */  sd         $3, 0x60($2)
    /* A3E44 001A3E44 01000524 */  addiu      $5, $0, 0x1
    /* A3E48 001A3E48 6451060C */  jal        func_00194590
    /* A3E4C 001A3E4C 00000000 */   nop
  .L001A3E50:
    /* A3E50 001A3E50 5004318E */  lw         $17, 0x450($17)
  .L001A3E54:
    /* A3E54 001A3E54 EFFF2016 */  bnez       $17, .L001A3E14
    /* A3E58 001A3E58 00000000 */   nop
    /* A3E5C 001A3E5C 01001124 */  addiu      $17, $0, 0x1
    /* A3E60 001A3E60 50C5060C */  jal        func_001b1540
    /* A3E64 001A3E64 00000000 */   nop
    /* A3E68 001A3E68 2D204000 */  daddu      $4, $2, $0
    /* A3E6C 001A3E6C 18004294 */  lhu        $2, 0x18($2)
    /* A3E70 001A3E70 08004230 */  andi       $2, $2, 0x8
    /* A3E74 001A3E74 06004010 */  beqz       $2, .L001A3E90
    /* A3E78 001A3E78 00000000 */   nop
    /* A3E7C 001A3E7C D87F060C */  jal        func_0019ff60
    /* A3E80 001A3E80 00000000 */   nop
    /* A3E84 001A3E84 02004010 */  beqz       $2, .L001A3E90
    /* A3E88 001A3E88 00000000 */   nop
    /* A3E8C 001A3E8C 2D880000 */  daddu      $17, $0, $0
  .L001A3E90:
    /* A3E90 001A3E90 01000224 */  addiu      $2, $0, 0x1
    /* A3E94 001A3E94 14002216 */  bne        $17, $2, .L001A3EE8
    /* A3E98 001A3E98 00000000 */   nop
    /* A3E9C 001A3E9C 2D200002 */  daddu      $4, $16, $0
    /* A3EA0 001A3EA0 9000058E */  lw         $5, 0x90($16)
    /* A3EA4 001A3EA4 68C0070C */  jal        func_001f01a0
    /* A3EA8 001A3EA8 00000000 */   nop
    /* A3EAC 001A3EAC FFFF4530 */  andi       $5, $2, 0xFFFF
    /* A3EB0 001A3EB0 3000028E */  lw         $2, 0x30($16)
    /* A3EB4 001A3EB4 640A448C */  lw         $4, 0xA64($2)
    /* A3EB8 001A3EB8 38F6080C */  jal        func_0023d8e0
    /* A3EBC 001A3EBC 00000000 */   nop
    /* A3EC0 001A3EC0 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* A3EC4 001A3EC4 2D200002 */  daddu      $4, $16, $0
    /* A3EC8 001A3EC8 02000624 */  addiu      $6, $0, 0x2
    /* A3ECC 001A3ECC 0800073C */  lui        $7, (0x80000 >> 16)
    /* A3ED0 001A3ED0 2D40C000 */  daddu      $8, $6, $0
    /* A3ED4 001A3ED4 1E00093C */  lui        $9, %hi(func_001db5e0)
    /* A3ED8 001A3ED8 E0B52925 */  addiu      $9, $9, %lo(func_001db5e0)
    /* A3EDC 001A3EDC 3465070C */  jal        func_001d94d0
    /* A3EE0 001A3EE0 00000000 */   nop
    /* A3EE4 001A3EE4 2D884000 */  daddu      $17, $2, $0
  .L001A3EE8:
    /* A3EE8 001A3EE8 0F002016 */  bnez       $17, .L001A3F28
    /* A3EEC 001A3EEC 00000000 */   nop
    /* A3EF0 001A3EF0 70EA070C */  jal        func_001fa9c0
    /* A3EF4 001A3EF4 00000000 */   nop
    /* A3EF8 001A3EF8 2D204000 */  daddu      $4, $2, $0
    /* A3EFC 001A3EFC 000003DE */  ld         $3, 0x0($16)
    /* A3F00 001A3F00 600043FC */  sd         $3, 0x60($2)
    /* A3F04 001A3F04 01000524 */  addiu      $5, $0, 0x1
    /* A3F08 001A3F08 6451060C */  jal        func_00194590
    /* A3F0C 001A3F0C 00000000 */   nop
    /* A3F10 001A3F10 2D200002 */  daddu      $4, $16, $0
    /* A3F14 001A3F14 20000524 */  addiu      $5, $0, 0x20
    /* A3F18 001A3F18 00C2060C */  jal        func_001b0800
    /* A3F1C 001A3F1C 00000000 */   nop
    /* A3F20 001A3F20 12000010 */  b          .L001A3F6C
    /* A3F24 001A3F24 00000000 */   nop
  .L001A3F28:
    /* A3F28 001A3F28 18AE070C */  jal        func_001eb860
    /* A3F2C 001A3F2C 00000000 */   nop
    /* A3F30 001A3F30 01000324 */  addiu      $3, $0, 0x1
    /* A3F34 001A3F34 0B004314 */  bne        $2, $3, .L001A3F64
    /* A3F38 001A3F38 00000000 */   nop
    /* A3F3C 001A3F3C ACB3848F */  lw         $4, -0x4C54($28)
    /* A3F40 001A3F40 0C00838C */  lw         $3, 0xC($4)
    /* A3F44 001A3F44 FFDF0224 */  addiu      $2, $0, -0x2001
    /* A3F48 001A3F48 24106200 */  and        $2, $3, $2
    /* A3F4C 001A3F4C 0C0082AC */  sw         $2, 0xC($4)
    /* A3F50 001A3F50 ACB3828F */  lw         $2, -0x4C54($28)
    /* A3F54 001A3F54 D40D448C */  lw         $4, 0xDD4($2)
    /* A3F58 001A3F58 2D280000 */  daddu      $5, $0, $0
    /* A3F5C 001A3F5C 9048080C */  jal        func_00212240
    /* A3F60 001A3F60 00000000 */   nop
  .L001A3F64:
    /* A3F64 001A3F64 1C0400AE */  sw         $0, 0x41C($16)
    /* A3F68 001A3F68 200400AE */  sw         $0, 0x420($16)
  .L001A3F6C:
    /* A3F6C 001A3F6C 2000BFDF */  ld         $31, 0x20($29)
    /* A3F70 001A3F70 1000B17B */  lq         $17, 0x10($29)
    /* A3F74 001A3F74 0000B07B */  lq         $16, 0x0($29)
    /* A3F78 001A3F78 3000BD27 */  addiu      $29, $29, 0x30
    /* A3F7C 001A3F7C 0800E003 */  jr         $31
    /* A3F80 001A3F80 00000000 */   nop
    /* A3F84 001A3F84 00000000 */  nop
    /* A3F88 001A3F88 00000000 */  nop
    /* A3F8C 001A3F8C 00000000 */  nop
.size func_001a3df0, 0x1a0
