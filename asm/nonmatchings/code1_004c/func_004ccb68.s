.section .text
.set noat
.set noreorder
glabel func_004ccb68
    /* 3CCB68 004CCB68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCB6C 004CCB6C 7200023C */  lui        $2, %hi(D_00719A3C)
    /* 3CCB70 004CCB70 0000B0FF */  sd         $16, 0x0($29)
    /* 3CCB74 004CCB74 3C9A5024 */  addiu      $16, $2, %lo(D_00719A3C)
    /* 3CCB78 004CCB78 0800BFFF */  sd         $31, 0x8($29)
    /* 3CCB7C 004CCB7C 502F130C */  jal        func_004cbd40
    /* 3CCB80 004CCB80 0000048E */   lw        $4, 0x0($16)
    /* 3CCB84 004CCB84 0000038E */  lw         $3, 0x0($16)
    /* 3CCB88 004CCB88 03004314 */  bne        $2, $3, .L004CCB98
    /* 3CCB8C 004CCB8C 00000000 */   nop
    /* 3CCB90 004CCB90 362F130C */  jal        func_004cbcd8
    /* 3CCB94 004CCB94 0000048E */   lw        $4, 0x0($16)
  .L004CCB98:
    /* 3CCB98 004CCB98 7830130C */  jal        func_004cc1e0
    /* 3CCB9C 004CCB9C 00000000 */   nop
    /* 3CCBA0 004CCBA0 7200033C */  lui        $3, %hi(D_00719A40)
    /* 3CCBA4 004CCBA4 01000424 */  addiu      $4, $0, 0x1
    /* 3CCBA8 004CCBA8 0D004414 */  bne        $2, $4, .L004CCBE0
    /* 3CCBAC 004CCBAC 409A7024 */   addiu     $16, $3, %lo(D_00719A40)
    /* 3CCBB0 004CCBB0 0000048E */  lw         $4, 0x0($16)
    /* 3CCBB4 004CCBB4 502F130C */  jal        func_004cbd40
    /* 3CCBB8 004CCBB8 00000000 */   nop
    /* 3CCBBC 004CCBBC 0000038E */  lw         $3, 0x0($16)
    /* 3CCBC0 004CCBC0 08004354 */  bnel       $2, $3, .L004CCBE4
    /* 3CCBC4 004CCBC4 0000B0DF */   ld        $16, 0x0($29)
    /* 3CCBC8 004CCBC8 0000048E */  lw         $4, 0x0($16)
    /* 3CCBCC 004CCBCC 0800BFDF */  ld         $31, 0x8($29)
    /* 3CCBD0 004CCBD0 0000B0DF */  ld         $16, 0x0($29)
    /* 3CCBD4 004CCBD4 362F1308 */  j          func_004cbcd8
    /* 3CCBD8 004CCBD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCBDC 004CCBDC 00000000 */  nop
  .L004CCBE0:
    /* 3CCBE0 004CCBE0 0000B0DF */  ld         $16, 0x0($29)
  .L004CCBE4:
    /* 3CCBE4 004CCBE4 0800BFDF */  ld         $31, 0x8($29)
    /* 3CCBE8 004CCBE8 0800E003 */  jr         $31
    /* 3CCBEC 004CCBEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ccb68, 0x88
