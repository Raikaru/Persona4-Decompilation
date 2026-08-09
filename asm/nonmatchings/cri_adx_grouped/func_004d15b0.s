.section .text
.set noat
.set noreorder
glabel func_004d15b0
    /* 3D15B0 004D15B0 80100500 */  sll        $2, $5, 2
    /* 3D15B4 004D15B4 0200A52C */  sltiu      $5, $5, 0x2
    /* 3D15B8 004D15B8 0200A010 */  beqz       $5, .L004D15C4
    /* 3D15BC 004D15BC 21208200 */   addu      $4, $4, $2
    /* 3D15C0 004D15C0 040086AC */  sw         $6, 0x4($4)
  .L004D15C4:
    /* 3D15C4 004D15C4 0800E003 */  jr         $31
    /* 3D15C8 004D15C8 00000000 */   nop
    /* 3D15CC 004D15CC 00000000 */  nop
.size func_004d15b0, 0x20
