.section .text
.set noat
.set noreorder
glabel func_003cf9b0
    /* 2CF9B0 003CF9B0 16008010 */  beqz       $4, .L003CFA0C
    /* 2CF9B4 003CF9B4 00000000 */   nop
    /* 2CF9B8 003CF9B8 1400838C */  lw         $3, 0x14($4)
    /* 2CF9BC 003CF9BC 15006010 */  beqz       $3, .L003CFA14
    /* 2CF9C0 003CF9C0 00000000 */   nop
    /* 2CF9C4 003CF9C4 02000224 */  addiu      $2, $0, 0x2
    /* 2CF9C8 003CF9C8 0B00A210 */  beq        $5, $2, .L003CF9F8
    /* 2CF9CC 003CF9CC 00000000 */   nop
    /* 2CF9D0 003CF9D0 01000224 */  addiu      $2, $0, 0x1
    /* 2CF9D4 003CF9D4 0300A210 */  beq        $5, $2, .L003CF9E4
    /* 2CF9D8 003CF9D8 00000000 */   nop
    /* 2CF9DC 003CF9DC 09000010 */  b          .L003CFA04
    /* 2CF9E0 003CF9E0 2D100000 */   daddu     $2, $0, $0
  .L003CF9E4:
    /* 2CF9E4 003CF9E4 0D00C010 */  beqz       $6, .L003CFA1C
    /* 2CF9E8 003CF9E8 00000000 */   nop
    /* 2CF9EC 003CF9EC 100066AC */  sw         $6, 0x10($3)
    /* 2CF9F0 003CF9F0 0B000010 */  b          .L003CFA20
    /* 2CF9F4 003CF9F4 2D108000 */   daddu     $2, $4, $0
  .L003CF9F8:
    /* 2CF9F8 003CF9F8 140066AC */  sw         $6, 0x14($3)
    /* 2CF9FC 003CF9FC 08000010 */  b          .L003CFA20
    /* 2CFA00 003CFA00 2D108000 */   daddu     $2, $4, $0
  .L003CFA04:
    /* 2CFA04 003CFA04 06000010 */  b          .L003CFA20
    /* 2CFA08 003CFA08 00000000 */   nop
  .L003CFA0C:
    /* 2CFA0C 003CFA0C 04000010 */  b          .L003CFA20
    /* 2CFA10 003CFA10 2D100000 */   daddu     $2, $0, $0
  .L003CFA14:
    /* 2CFA14 003CFA14 02000010 */  b          .L003CFA20
    /* 2CFA18 003CFA18 2D100000 */   daddu     $2, $0, $0
  .L003CFA1C:
    /* 2CFA1C 003CFA1C 2D100000 */  daddu      $2, $0, $0
  .L003CFA20:
    /* 2CFA20 003CFA20 0800E003 */  jr         $31
    /* 2CFA24 003CFA24 00000000 */   nop
    /* 2CFA28 003CFA28 00000000 */  nop
    /* 2CFA2C 003CFA2C 00000000 */  nop
.size func_003cf9b0, 0x80
