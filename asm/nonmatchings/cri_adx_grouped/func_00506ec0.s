.section .text
.set noat
.set noreorder
glabel func_00506ec0
    /* 406EC0 00506EC0 9200023C */  lui        $2, %hi(D_00927080)
    /* 406EC4 00506EC4 80704224 */  addiu      $2, $2, %lo(D_00927080)
    /* 406EC8 00506EC8 5400448C */  lw         $4, 0x54($2)
    /* 406ECC 00506ECC 0B008018 */  blez       $4, .L00506EFC
    /* 406ED0 00506ED0 5800438C */   lw        $3, 0x58($2)
    /* 406ED4 00506ED4 2D108000 */  daddu      $2, $4, $0
    /* 406ED8 00506ED8 01000424 */  addiu      $4, $0, 0x1
    /* 406EDC 00506EDC 00000000 */  nop
  .L00506EE0:
    /* 406EE0 00506EE0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 406EE4 00506EE4 880164AC */  sw         $4, 0x188($3)
    /* 406EE8 00506EE8 00000000 */  nop
    /* 406EEC 00506EEC 00000000 */  nop
    /* 406EF0 00506EF0 00000000 */  nop
    /* 406EF4 00506EF4 FAFF4014 */  bnez       $2, .L00506EE0
    /* 406EF8 00506EF8 20046324 */   addiu     $3, $3, 0x420
  .L00506EFC:
    /* 406EFC 00506EFC 0800E003 */  jr         $31
    /* 406F00 00506F00 00000000 */   nop
    /* 406F04 00506F04 00000000 */  nop
.size func_00506ec0, 0x48
