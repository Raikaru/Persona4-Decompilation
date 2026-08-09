.section .text
.set noat
.set noreorder
glabel func_004ecf60
    /* 3ECF60 004ECF60 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECF64 004ECF64 01000624 */  addiu      $6, $0, 0x1
    /* 3ECF68 004ECF68 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECF6C 004ECF6C 2A100500 */  slt        $2, $0, $5
    /* 3ECF70 004ECF70 05006614 */  bne        $3, $6, .L004ECF88
    /* 3ECF74 004ECF74 0B280200 */   movn      $5, $0, $2
    /* 3ECF78 004ECF78 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECF7C 004ECF7C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECF80 004ECF80 05006018 */  blez       $3, .L004ECF98
    /* 3ECF84 004ECF84 00000000 */   nop
  .L004ECF88:
    /* 3ECF88 004ECF88 19FCA328 */  slti       $3, $5, -0x3E7
    /* 3ECF8C 004ECF8C 19FC0224 */  addiu      $2, $0, -0x3E7
    /* 3ECF90 004ECF90 0B284300 */  movn       $5, $2, $3
    /* 3ECF94 004ECF94 380085AC */  sw         $5, 0x38($4)
  .L004ECF98:
    /* 3ECF98 004ECF98 0800E003 */  jr         $31
    /* 3ECF9C 004ECF9C 00000000 */   nop
.size func_004ecf60, 0x40
