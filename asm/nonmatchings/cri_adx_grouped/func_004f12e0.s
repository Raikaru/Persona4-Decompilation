.section .text
.set noat
.set noreorder
glabel func_004f12e0
    /* 3F12E0 004F12E0 9200023C */  lui        $2, %hi(D_00925E78)
    /* 3F12E4 004F12E4 785E4524 */  addiu      $5, $2, %lo(D_00925E78)
    /* 3F12E8 004F12E8 0000A38C */  lw         $3, 0x0($5)
    /* 3F12EC 004F12EC 03006014 */  bnez       $3, .L004F12FC
    /* 3F12F0 004F12F0 2D100000 */   daddu     $2, $0, $0
    /* 3F12F4 004F12F4 0000A4AC */  sw         $4, 0x0($5)
    /* 3F12F8 004F12F8 01000224 */  addiu      $2, $0, 0x1
  .L004F12FC:
    /* 3F12FC 004F12FC 0800E003 */  jr         $31
    /* 3F1300 004F1300 00000000 */   nop
    /* 3F1304 004F1304 00000000 */  nop
.size func_004f12e0, 0x28
