.section .text
.set noat
.set noreorder
glabel func_001f3f60
    /* F3F60 001F3F60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F3F64 001F3F64 0000BFFF */  sd         $31, 0x0($29)
    /* F3F68 001F3F68 ACB3828F */  lw         $2, -0x4C54($28)
    /* F3F6C 001F3F6C 580A438C */  lw         $3, 0xA58($2)
    /* F3F70 001F3F70 FC000224 */  addiu      $2, $0, 0xFC
    /* F3F74 001F3F74 04006214 */  bne        $3, $2, .L001F3F88
    /* F3F78 001F3F78 00000000 */   nop
    /* F3F7C 001F3F7C FFFF0224 */  addiu      $2, $0, -0x1
    /* F3F80 001F3F80 0D000010 */  b          .L001F3FB8
    /* F3F84 001F3F84 00000000 */   nop
  .L001F3F88:
    /* F3F88 001F3F88 01000424 */  addiu      $4, $0, 0x1
    /* F3F8C 001F3F8C 0800053C */  lui        $5, (0x80000 >> 16)
    /* F3F90 001F3F90 C8BD070C */  jal        func_001ef720
    /* F3F94 001F3F94 00000000 */   nop
    /* F3F98 001F3F98 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* F3F9C 001F3F9C 02004128 */  slti       $1, $2, 0x2
    /* F3FA0 001F3FA0 04002010 */  beqz       $1, .L001F3FB4
    /* F3FA4 001F3FA4 00000000 */   nop
    /* F3FA8 001F3FA8 FFFF0224 */  addiu      $2, $0, -0x1
    /* F3FAC 001F3FAC 02000010 */  b          .L001F3FB8
    /* F3FB0 001F3FB0 00000000 */   nop
  .L001F3FB4:
    /* F3FB4 001F3FB4 FC000224 */  addiu      $2, $0, 0xFC
  .L001F3FB8:
    /* F3FB8 001F3FB8 0000BFDF */  ld         $31, 0x0($29)
    /* F3FBC 001F3FBC 1000BD27 */  addiu      $29, $29, 0x10
    /* F3FC0 001F3FC0 0800E003 */  jr         $31
    /* F3FC4 001F3FC4 00000000 */   nop
    /* F3FC8 001F3FC8 00000000 */  nop
    /* F3FCC 001F3FCC 00000000 */  nop
.size func_001f3f60, 0x70
