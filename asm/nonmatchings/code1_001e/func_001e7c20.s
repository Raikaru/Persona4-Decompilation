.section .text
.set noat
.set noreorder
glabel func_001e7c20
    /* E7C20 001E7C20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* E7C24 001E7C24 3000BFFF */  sd         $31, 0x30($29)
    /* E7C28 001E7C28 2000B27F */  sq         $18, 0x20($29)
    /* E7C2C 001E7C2C 1000B17F */  sq         $17, 0x10($29)
    /* E7C30 001E7C30 0000B07F */  sq         $16, 0x0($29)
    /* E7C34 001E7C34 14740A0C */  jal        func_0029d050
    /* E7C38 001E7C38 00000000 */   nop
    /* E7C3C 001E7C3C 2D904000 */  daddu      $18, $2, $0
    /* E7C40 001E7C40 2D200000 */  daddu      $4, $0, $0
    /* E7C44 001E7C44 00730A0C */  jal        func_0029cc00
    /* E7C48 001E7C48 00000000 */   nop
    /* E7C4C 001E7C4C 2D204002 */  daddu      $4, $18, $0
    /* E7C50 001E7C50 2D284000 */  daddu      $5, $2, $0
    /* E7C54 001E7C54 2D300000 */  daddu      $6, $0, $0
    /* E7C58 001E7C58 2C000724 */  addiu      $7, $0, 0x2C
    /* E7C5C 001E7C5C 2D400000 */  daddu      $8, $0, $0
    /* E7C60 001E7C60 1E00093C */  lui        $9, %hi(func_001db580)
    /* E7C64 001E7C64 80B52925 */  addiu      $9, $9, %lo(func_001db580)
    /* E7C68 001E7C68 E86E070C */  jal        func_001dbba0
    /* E7C6C 001E7C6C 00000000 */   nop
    /* E7C70 001E7C70 01000324 */  addiu      $3, $0, 0x1
    /* E7C74 001E7C74 20004314 */  bne        $2, $3, .L001E7CF8
    /* E7C78 001E7C78 00000000 */   nop
    /* E7C7C 001E7C7C 2D800000 */  daddu      $16, $0, $0
    /* E7C80 001E7C80 2D880000 */  daddu      $17, $0, $0
    /* E7C84 001E7C84 12000010 */  b          .L001E7CD0
    /* E7C88 001E7C88 00000000 */   nop
  .L001E7C8C:
    /* E7C8C 001E7C8C FFFF2232 */  andi       $2, $17, 0xFFFF
    /* E7C90 001E7C90 80100200 */  sll        $2, $2, 2
    /* E7C94 001E7C94 21104202 */  addu       $2, $18, $2
    /* E7C98 001E7C98 3800428C */  lw         $2, 0x38($2)
    /* E7C9C 001E7C9C 3000428C */  lw         $2, 0x30($2)
    /* E7CA0 001E7CA0 640A448C */  lw         $4, 0xA64($2)
    /* E7CA4 001E7CA4 B0C9080C */  jal        func_002326c0
    /* E7CA8 001E7CA8 00000000 */   nop
    /* E7CAC 001E7CAC EFFF033C */  lui        $3, (0xFFEFFFFF >> 16)
    /* E7CB0 001E7CB0 FFFF6334 */  ori        $3, $3, (0xFFEFFFFF & 0xFFFF)
    /* E7CB4 001E7CB4 24104300 */  and        $2, $2, $3
    /* E7CB8 001E7CB8 03004014 */  bnez       $2, .L001E7CC8
    /* E7CBC 001E7CBC 00000000 */   nop
    /* E7CC0 001E7CC0 01000226 */  addiu      $2, $16, 0x1
    /* E7CC4 001E7CC4 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001E7CC8:
    /* E7CC8 001E7CC8 01002226 */  addiu      $2, $17, 0x1
    /* E7CCC 001E7CCC FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001E7CD0:
    /* E7CD0 001E7CD0 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* E7CD4 001E7CD4 6A004296 */  lhu        $2, 0x6A($18)
    /* E7CD8 001E7CD8 2A106200 */  slt        $2, $3, $2
    /* E7CDC 001E7CDC EBFF4014 */  bnez       $2, .L001E7C8C
    /* E7CE0 001E7CE0 00000000 */   nop
    /* E7CE4 001E7CE4 FFFF0432 */  andi       $4, $16, 0xFFFF
    /* E7CE8 001E7CE8 D4730A0C */  jal        func_0029cf50
    /* E7CEC 001E7CEC 00000000 */   nop
    /* E7CF0 001E7CF0 04000010 */  b          .L001E7D04
    /* E7CF4 001E7CF4 00000000 */   nop
  .L001E7CF8:
    /* E7CF8 001E7CF8 2D200000 */  daddu      $4, $0, $0
    /* E7CFC 001E7CFC D4730A0C */  jal        func_0029cf50
    /* E7D00 001E7D00 00000000 */   nop
  .L001E7D04:
    /* E7D04 001E7D04 FFFF0224 */  addiu      $2, $0, -0x1
    /* E7D08 001E7D08 3000BFDF */  ld         $31, 0x30($29)
    /* E7D0C 001E7D0C 2000B27B */  lq         $18, 0x20($29)
    /* E7D10 001E7D10 1000B17B */  lq         $17, 0x10($29)
    /* E7D14 001E7D14 0000B07B */  lq         $16, 0x0($29)
    /* E7D18 001E7D18 4000BD27 */  addiu      $29, $29, 0x40
    /* E7D1C 001E7D1C 0800E003 */  jr         $31
    /* E7D20 001E7D20 00000000 */   nop
    /* E7D24 001E7D24 00000000 */  nop
    /* E7D28 001E7D28 00000000 */  nop
    /* E7D2C 001E7D2C 00000000 */  nop
.size func_001e7c20, 0x110
