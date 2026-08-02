.section .text
.set noat
.set noreorder
glabel func_00177db0
    /* 77DB0 00177DB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 77DB4 00177DB4 2000BFFF */  sd         $31, 0x20($29)
    /* 77DB8 00177DB8 1000B17F */  sq         $17, 0x10($29)
    /* 77DBC 00177DBC 0000B07F */  sq         $16, 0x0($29)
    /* 77DC0 00177DC0 2D200000 */  daddu      $4, $0, $0
    /* 77DC4 00177DC4 00730A0C */  jal        func_0029cc00
    /* 77DC8 00177DC8 00000000 */   nop
    /* 77DCC 00177DCC 2D884000 */  daddu      $17, $2, $0
    /* 77DD0 00177DD0 01000424 */  addiu      $4, $0, 0x1
    /* 77DD4 00177DD4 00730A0C */  jal        func_0029cc00
    /* 77DD8 00177DD8 00000000 */   nop
    /* 77DDC 00177DDC 2D804000 */  daddu      $16, $2, $0
    /* 77DE0 00177DE0 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* 77DE4 00177DE4 9C14050C */  jal        func_00145270
    /* 77DE8 00177DE8 00000000 */   nop
    /* 77DEC 00177DEC 02004010 */  beqz       $2, .L00177DF8
    /* 77DF0 00177DF0 00000000 */   nop
    /* 77DF4 00177DF4 500150AC */  sw         $16, 0x150($2)
  .L00177DF8:
    /* 77DF8 00177DF8 01000224 */  addiu      $2, $0, 0x1
    /* 77DFC 00177DFC 2000BFDF */  ld         $31, 0x20($29)
    /* 77E00 00177E00 1000B17B */  lq         $17, 0x10($29)
    /* 77E04 00177E04 0000B07B */  lq         $16, 0x0($29)
    /* 77E08 00177E08 3000BD27 */  addiu      $29, $29, 0x30
    /* 77E0C 00177E0C 0800E003 */  jr         $31
    /* 77E10 00177E10 00000000 */   nop
    /* 77E14 00177E14 00000000 */  nop
    /* 77E18 00177E18 00000000 */  nop
    /* 77E1C 00177E1C 00000000 */  nop
.size func_00177db0, 0x70
