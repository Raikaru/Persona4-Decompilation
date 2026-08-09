.section .text
.set noat
.set noreorder
glabel func_00264cb0
    /* 164CB0 00264CB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 164CB4 00264CB4 2000BFFF */  sd         $31, 0x20($29)
    /* 164CB8 00264CB8 1000B17F */  sq         $17, 0x10($29)
    /* 164CBC 00264CBC 0000B07F */  sq         $16, 0x0($29)
    /* 164CC0 00264CC0 2D888000 */  daddu      $17, $4, $0
    /* 164CC4 00264CC4 2D80A000 */  daddu      $16, $5, $0
    /* 164CC8 00264CC8 6482110C */  jal        func_00460990
    /* 164CCC 00264CCC 00000000 */   nop
    /* 164CD0 00264CD0 2D284000 */  daddu      $5, $2, $0
    /* 164CD4 00264CD4 2600033C */  lui        $3, %hi(func_00263cb0)
    /* 164CD8 00264CD8 B03C6324 */  addiu      $3, $3, %lo(func_00263cb0)
    /* 164CDC 00264CDC 080043AC */  sw         $3, 0x8($2)
    /* 164CE0 00264CE0 100051AC */  sw         $17, 0x10($2)
    /* 164CE4 00264CE4 2D200002 */  daddu      $4, $16, $0
    /* 164CE8 00264CE8 B082110C */  jal        func_00460ac0
    /* 164CEC 00264CEC 00000000 */   nop
    /* 164CF0 00264CF0 2000BFDF */  ld         $31, 0x20($29)
    /* 164CF4 00264CF4 1000B17B */  lq         $17, 0x10($29)
    /* 164CF8 00264CF8 0000B07B */  lq         $16, 0x0($29)
    /* 164CFC 00264CFC 3000BD27 */  addiu      $29, $29, 0x30
    /* 164D00 00264D00 0800E003 */  jr         $31
    /* 164D04 00264D04 00000000 */   nop
    /* 164D08 00264D08 00000000 */  nop
    /* 164D0C 00264D0C 00000000 */  nop
.size func_00264cb0, 0x60
