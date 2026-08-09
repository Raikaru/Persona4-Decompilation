.section .text
.set noat
.set noreorder
glabel func_0033d3e0
    /* 23D3E0 0033D3E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 23D3E4 0033D3E4 0000BFFF */  sd         $31, 0x0($29)
    /* 23D3E8 0033D3E8 1000A5FF */  sd         $5, 0x10($29)
    /* 23D3EC 0033D3EC 1800A6FF */  sd         $6, 0x18($29)
    /* 23D3F0 0033D3F0 3800828C */  lw         $2, 0x38($4)
    /* 23D3F4 0033D3F4 3C4C0900 */  dsll32     $9, $9, 16
    /* 23D3F8 0033D3F8 3F4C0900 */  dsra32     $9, $9, 16
    /* 23D3FC 0033D3FC 04004424 */  addiu      $4, $2, 0x4
    /* 23D400 0033D400 9CE00A0C */  jal        func_002b8270
    /* 23D404 0033D404 00000000 */   nop
    /* 23D408 0033D408 0000BFDF */  ld         $31, 0x0($29)
    /* 23D40C 0033D40C 2000BD27 */  addiu      $29, $29, 0x20
    /* 23D410 0033D410 0800E003 */  jr         $31
    /* 23D414 0033D414 00000000 */   nop
    /* 23D418 0033D418 00000000 */  nop
    /* 23D41C 0033D41C 00000000 */  nop
.size func_0033d3e0, 0x40
