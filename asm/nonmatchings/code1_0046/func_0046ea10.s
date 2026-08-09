.section .text
.set noat
.set noreorder
glabel func_0046ea10
    /* 36EA10 0046EA10 3800828C */  lw         $2, 0x38($4)
    /* 36EA14 0046EA14 0000438C */  lw         $3, 0x0($2)
    /* 36EA18 0046EA18 06000224 */  addiu      $2, $0, 0x6
    /* 36EA1C 0046EA1C 04006210 */  beq        $3, $2, .L0046EA30
    /* 36EA20 0046EA20 00000000 */   nop
    /* 36EA24 0046EA24 08000224 */  addiu      $2, $0, 0x8
    /* 36EA28 0046EA28 04006214 */  bne        $3, $2, .L0046EA3C
    /* 36EA2C 0046EA2C 00000000 */   nop
  .L0046EA30:
    /* 36EA30 0046EA30 2D100000 */  daddu      $2, $0, $0
    /* 36EA34 0046EA34 02000010 */  b          .L0046EA40
    /* 36EA38 0046EA38 00000000 */   nop
  .L0046EA3C:
    /* 36EA3C 0046EA3C 01000224 */  addiu      $2, $0, 0x1
  .L0046EA40:
    /* 36EA40 0046EA40 0800E003 */  jr         $31
    /* 36EA44 0046EA44 00000000 */   nop
    /* 36EA48 0046EA48 00000000 */  nop
    /* 36EA4C 0046EA4C 00000000 */  nop
.size func_0046ea10, 0x40
