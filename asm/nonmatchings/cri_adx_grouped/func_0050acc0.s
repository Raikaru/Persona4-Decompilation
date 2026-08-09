.section .text
.set noat
.set noreorder
glabel func_0050acc0
    /* 40ACC0 0050ACC0 8000858C */  lw         $5, 0x80($4)
    /* 40ACC4 0050ACC4 7C00828C */  lw         $2, 0x7C($4)
    /* 40ACC8 0050ACC8 0100A424 */  addiu      $4, $5, 0x1
    /* 40ACCC 0050ACCC 2A18A200 */  slt        $3, $5, $2
    /* 40ACD0 0050ACD0 03006014 */  bnez       $3, .L0050ACE0
    /* 40ACD4 0050ACD4 26104500 */   xor       $2, $2, $5
    /* 40ACD8 0050ACD8 2D200000 */  daddu      $4, $0, $0
    /* 40ACDC 0050ACDC 0A20A200 */  movz       $4, $5, $2
  .L0050ACE0:
    /* 40ACE0 0050ACE0 0800E003 */  jr         $31
    /* 40ACE4 0050ACE4 2D108000 */   daddu     $2, $4, $0
.size func_0050acc0, 0x28
