.section .text
.set noat
.set noreorder
glabel func_002bb680
    /* 1BB680 002BB680 3C160400 */  dsll32     $2, $4, 24
    /* 1BB684 002BB684 3F160200 */  dsra32     $2, $2, 24
    /* 1BB688 002BB688 80180200 */  sll        $3, $2, 2
    /* 1BB68C 002BB68C 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BB690 002BB690 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BB694 002BB694 21104300 */  addu       $2, $2, $3
    /* 1BB698 002BB698 0000448C */  lw         $4, 0x0($2)
    /* 1BB69C 002BB69C 04008014 */  bnez       $4, .L002BB6B0
    /* 1BB6A0 002BB6A0 00000000 */   nop
    /* 1BB6A4 002BB6A4 2D100000 */  daddu      $2, $0, $0
    /* 1BB6A8 002BB6A8 12000010 */  b          .L002BB6F4
    /* 1BB6AC 002BB6AC 00000000 */   nop
  .L002BB6B0:
    /* 1BB6B0 002BB6B0 0000828C */  lw         $2, 0x0($4)
    /* 1BB6B4 002BB6B4 04004104 */  bgez       $2, .L002BB6C8
    /* 1BB6B8 002BB6B8 00000000 */   nop
    /* 1BB6BC 002BB6BC 2D100000 */  daddu      $2, $0, $0
    /* 1BB6C0 002BB6C0 0C000010 */  b          .L002BB6F4
    /* 1BB6C4 002BB6C4 00000000 */   nop
  .L002BB6C8:
    /* 1BB6C8 002BB6C8 05008280 */  lb         $2, 0x5($4)
    /* 1BB6CC 002BB6CC 08004010 */  beqz       $2, .L002BB6F0
    /* 1BB6D0 002BB6D0 00000000 */   nop
    /* 1BB6D4 002BB6D4 04008380 */  lb         $3, 0x4($4)
    /* 1BB6D8 002BB6D8 02000224 */  addiu      $2, $0, 0x2
    /* 1BB6DC 002BB6DC 04006214 */  bne        $3, $2, .L002BB6F0
    /* 1BB6E0 002BB6E0 00000000 */   nop
    /* 1BB6E4 002BB6E4 2D100000 */  daddu      $2, $0, $0
    /* 1BB6E8 002BB6E8 02000010 */  b          .L002BB6F4
    /* 1BB6EC 002BB6EC 00000000 */   nop
  .L002BB6F0:
    /* 1BB6F0 002BB6F0 04008280 */  lb         $2, 0x4($4)
  .L002BB6F4:
    /* 1BB6F4 002BB6F4 0800E003 */  jr         $31
    /* 1BB6F8 002BB6F8 00000000 */   nop
    /* 1BB6FC 002BB6FC 00000000 */  nop
.size func_002bb680, 0x80
