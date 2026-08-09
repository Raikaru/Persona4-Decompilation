.section .text
.set noat
.set noreorder
glabel func_001fac30
    /* FAC30 001FAC30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAC34 001FAC34 0000BFFF */  sd         $31, 0x0($29)
    /* FAC38 001FAC38 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAC3C 001FAC3C 0C00438C */  lw         $3, 0xC($2)
    /* FAC40 001FAC40 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAC44 001FAC44 24106200 */  and        $2, $3, $2
    /* FAC48 001FAC48 06004010 */  beqz       $2, .L001FAC64
    /* FAC4C 001FAC4C 00000000 */   nop
    /* FAC50 001FAC50 02000424 */  addiu      $4, $0, 0x2
    /* FAC54 001FAC54 20AF080C */  jal        func_0022bc80
    /* FAC58 001FAC58 00000000 */   nop
    /* FAC5C 001FAC5C 02000010 */  b          .L001FAC68
    /* FAC60 001FAC60 00000000 */   nop
  .L001FAC64:
    /* FAC64 001FAC64 2D100000 */  daddu      $2, $0, $0
  .L001FAC68:
    /* FAC68 001FAC68 0000BFDF */  ld         $31, 0x0($29)
    /* FAC6C 001FAC6C 1000BD27 */  addiu      $29, $29, 0x10
    /* FAC70 001FAC70 0800E003 */  jr         $31
    /* FAC74 001FAC74 00000000 */   nop
    /* FAC78 001FAC78 00000000 */  nop
    /* FAC7C 001FAC7C 00000000 */  nop
.size func_001fac30, 0x50
