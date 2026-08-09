.section .text
.set noat
.set noreorder
glabel func_00503aa0
    /* 403AA0 00503AA0 7400033C */  lui        $3, %hi(D_00743CE8)
    /* 403AA4 00503AA4 2D300000 */  daddu      $6, $0, $0
    /* 403AA8 00503AA8 E83C628C */  lw         $2, %lo(D_00743CE8)($3)
    /* 403AAC 00503AAC 0C00458C */  lw         $5, 0xC($2)
    /* 403AB0 00503AB0 0E00A018 */  blez       $5, .L00503AEC
    /* 403AB4 00503AB4 10004224 */   addiu     $2, $2, 0x10
    /* 403AB8 00503AB8 2D204000 */  daddu      $4, $2, $0
    /* 403ABC 00503ABC 01000724 */  addiu      $7, $0, 0x1
    /* 403AC0 00503AC0 0000838C */  lw         $3, 0x0($4)
    /* 403AC4 00503AC4 00000000 */  nop
  .L00503AC8:
    /* 403AC8 00503AC8 2D108000 */  daddu      $2, $4, $0
    /* 403ACC 00503ACC 08006710 */  beq        $3, $7, .L00503AF0
    /* 403AD0 00503AD0 00018424 */   addiu     $4, $4, 0x100
    /* 403AD4 00503AD4 0100C624 */  addiu      $6, $6, 0x1
    /* 403AD8 00503AD8 2A10C500 */  slt        $2, $6, $5
    /* 403ADC 00503ADC 00000000 */  nop
    /* 403AE0 00503AE0 00000000 */  nop
    /* 403AE4 00503AE4 F8FF4054 */  bnel       $2, $0, .L00503AC8
    /* 403AE8 00503AE8 0000838C */   lw        $3, 0x0($4)
  .L00503AEC:
    /* 403AEC 00503AEC 2D100000 */  daddu      $2, $0, $0
  .L00503AF0:
    /* 403AF0 00503AF0 0800E003 */  jr         $31
    /* 403AF4 00503AF4 00000000 */   nop
.size func_00503aa0, 0x58
