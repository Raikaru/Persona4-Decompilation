.section .text
.set noat
.set noreorder
glabel func_002bb180
    /* 1BB180 002BB180 3C160400 */  dsll32     $2, $4, 24
    /* 1BB184 002BB184 3F160200 */  dsra32     $2, $2, 24
    /* 1BB188 002BB188 80180200 */  sll        $3, $2, 2
    /* 1BB18C 002BB18C 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BB190 002BB190 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BB194 002BB194 21104300 */  addu       $2, $2, $3
    /* 1BB198 002BB198 0000428C */  lw         $2, 0x0($2)
    /* 1BB19C 002BB19C 04004014 */  bnez       $2, .L002BB1B0
    /* 1BB1A0 002BB1A0 00000000 */   nop
    /* 1BB1A4 002BB1A4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BB1A8 002BB1A8 02000010 */  b          .L002BB1B4
    /* 1BB1AC 002BB1AC 00000000 */   nop
  .L002BB1B0:
    /* 1BB1B0 002BB1B0 0D004280 */  lb         $2, 0xD($2)
  .L002BB1B4:
    /* 1BB1B4 002BB1B4 0800E003 */  jr         $31
    /* 1BB1B8 002BB1B8 00000000 */   nop
    /* 1BB1BC 002BB1BC 00000000 */  nop
.size func_002bb180, 0x40
