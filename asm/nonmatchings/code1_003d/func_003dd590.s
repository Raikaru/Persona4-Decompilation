.section .text
.set noat
.set noreorder
glabel func_003dd590
    /* 2DD590 003DD590 100083DC */  ld         $3, 0x10($4)
    /* 2DD594 003DD594 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2DD598 003DD598 03006214 */  bne        $3, $2, .L003DD5A8
    /* 2DD59C 003DD59C 00000000 */   nop
    /* 2DD5A0 003DD5A0 04000010 */  b          .L003DD5B4
    /* 2DD5A4 003DD5A4 01000224 */   addiu     $2, $0, 0x1
  .L003DD5A8:
    /* 2DD5A8 003DD5A8 000082DC */  ld         $2, 0x0($4)
    /* 2DD5AC 003DD5AC 2A106200 */  slt        $2, $3, $2
    /* 2DD5B0 003DD5B0 01004238 */  xori       $2, $2, 0x1
  .L003DD5B4:
    /* 2DD5B4 003DD5B4 0800E003 */  jr         $31
    /* 2DD5B8 003DD5B8 00000000 */   nop
    /* 2DD5BC 003DD5BC 00000000 */  nop
.size func_003dd590, 0x30
