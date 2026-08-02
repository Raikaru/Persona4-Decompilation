.section .text
.set noat
.set noreorder
glabel func_001e2c10
    /* E2C10 001E2C10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E2C14 001E2C14 1000BFFF */  sd         $31, 0x10($29)
    /* E2C18 001E2C18 0000B07F */  sq         $16, 0x0($29)
    /* E2C1C 001E2C1C 14740A0C */  jal        func_0029d050
    /* E2C20 001E2C20 00000000 */   nop
    /* E2C24 001E2C24 3000428C */  lw         $2, 0x30($2)
    /* E2C28 001E2C28 A2004290 */  lbu        $2, 0xA2($2)
    /* E2C2C 001E2C2C 04004014 */  bnez       $2, .L001E2C40
    /* E2C30 001E2C30 00000000 */   nop
    /* E2C34 001E2C34 01001024 */  addiu      $16, $0, 0x1
    /* E2C38 001E2C38 02000010 */  b          .L001E2C44
    /* E2C3C 001E2C3C 00000000 */   nop
  .L001E2C40:
    /* E2C40 001E2C40 2D800000 */  daddu      $16, $0, $0
  .L001E2C44:
    /* E2C44 001E2C44 2D200000 */  daddu      $4, $0, $0
    /* E2C48 001E2C48 00730A0C */  jal        func_0029cc00
    /* E2C4C 001E2C4C 00000000 */   nop
    /* E2C50 001E2C50 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E2C54 001E2C54 01000224 */  addiu      $2, $0, 0x1
    /* E2C58 001E2C58 04100202 */  sllv       $2, $2, $16
    /* E2C5C 001E2C5C FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E2C60 001E2C60 0800063C */  lui        $6, (0x80000 >> 16)
    /* E2C64 001E2C64 A064070C */  jal        func_001d9280
    /* E2C68 001E2C68 00000000 */   nop
    /* E2C6C 001E2C6C 2D804000 */  daddu      $16, $2, $0
    /* E2C70 001E2C70 1E000012 */  beqz       $16, .L001E2CEC
    /* E2C74 001E2C74 00000000 */   nop
    /* E2C78 001E2C78 01000424 */  addiu      $4, $0, 0x1
    /* E2C7C 001E2C7C 00730A0C */  jal        func_0029cc00
    /* E2C80 001E2C80 00000000 */   nop
    /* E2C84 001E2C84 3C1A0200 */  dsll32     $3, $2, 8
    /* E2C88 001E2C88 3E1A0300 */  dsrl32     $3, $3, 8
    /* E2C8C 001E2C8C 0016023C */  lui        $2, (0x16000000 >> 16)
    /* E2C90 001E2C90 25206200 */  or         $4, $3, $2
    /* E2C94 001E2C94 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E2C98 001E2C98 24108200 */  and        $2, $4, $2
    /* E2C9C 001E2C9C 021E0200 */  srl        $3, $2, 24
    /* E2CA0 001E2CA0 3C2A0400 */  dsll32     $5, $4, 8
    /* E2CA4 001E2CA4 3E2A0500 */  dsrl32     $5, $5, 8
    /* E2CA8 001E2CA8 04006014 */  bnez       $3, .L001E2CBC
    /* E2CAC 001E2CAC 00000000 */   nop
    /* E2CB0 001E2CB0 2D100000 */  daddu      $2, $0, $0
    /* E2CB4 001E2CB4 0B000010 */  b          .L001E2CE4
    /* E2CB8 001E2CB8 00000000 */   nop
  .L001E2CBC:
    /* E2CBC 001E2CBC 2D200002 */  daddu      $4, $16, $0
    /* E2CC0 001E2CC0 40100300 */  sll        $2, $3, 1
    /* E2CC4 001E2CC4 21104300 */  addu       $2, $2, $3
    /* E2CC8 001E2CC8 80180200 */  sll        $3, $2, 2
    /* E2CCC 001E2CCC 6100023C */  lui        $2, %hi(D_00609850)
    /* E2CD0 001E2CD0 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E2CD4 001E2CD4 21104300 */  addu       $2, $2, $3
    /* E2CD8 001E2CD8 0000428C */  lw         $2, 0x0($2)
    /* E2CDC 001E2CDC 09F84000 */  jalr       $2
    /* E2CE0 001E2CE0 00000000 */   nop
  .L001E2CE4:
    /* E2CE4 001E2CE4 02000010 */  b          .L001E2CF0
    /* E2CE8 001E2CE8 00000000 */   nop
  .L001E2CEC:
    /* E2CEC 001E2CEC 2D100000 */  daddu      $2, $0, $0
  .L001E2CF0:
    /* E2CF0 001E2CF0 2B200200 */  sltu       $4, $0, $2
    /* E2CF4 001E2CF4 D4730A0C */  jal        func_0029cf50
    /* E2CF8 001E2CF8 00000000 */   nop
    /* E2CFC 001E2CFC 01000224 */  addiu      $2, $0, 0x1
    /* E2D00 001E2D00 1000BFDF */  ld         $31, 0x10($29)
    /* E2D04 001E2D04 0000B07B */  lq         $16, 0x0($29)
    /* E2D08 001E2D08 2000BD27 */  addiu      $29, $29, 0x20
    /* E2D0C 001E2D0C 0800E003 */  jr         $31
    /* E2D10 001E2D10 00000000 */   nop
    /* E2D14 001E2D14 00000000 */  nop
    /* E2D18 001E2D18 00000000 */  nop
    /* E2D1C 001E2D1C 00000000 */  nop
.size func_001e2c10, 0x110
