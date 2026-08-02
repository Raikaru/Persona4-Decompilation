.section .text
.set noat
.set noreorder
glabel func_001e5ca0
    /* E5CA0 001E5CA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E5CA4 001E5CA4 2000BFFF */  sd         $31, 0x20($29)
    /* E5CA8 001E5CA8 1000B17F */  sq         $17, 0x10($29)
    /* E5CAC 001E5CAC 0000B07F */  sq         $16, 0x0($29)
    /* E5CB0 001E5CB0 2D200000 */  daddu      $4, $0, $0
    /* E5CB4 001E5CB4 00730A0C */  jal        func_0029cc00
    /* E5CB8 001E5CB8 00000000 */   nop
    /* E5CBC 001E5CBC 2D884000 */  daddu      $17, $2, $0
    /* E5CC0 001E5CC0 01000424 */  addiu      $4, $0, 0x1
    /* E5CC4 001E5CC4 00730A0C */  jal        func_0029cc00
    /* E5CC8 001E5CC8 00000000 */   nop
    /* E5CCC 001E5CCC 2D804000 */  daddu      $16, $2, $0
    /* E5CD0 001E5CD0 14740A0C */  jal        func_0029d050
    /* E5CD4 001E5CD4 00000000 */   nop
    /* E5CD8 001E5CD8 2D204000 */  daddu      $4, $2, $0
    /* E5CDC 001E5CDC 2D282002 */  daddu      $5, $17, $0
    /* E5CE0 001E5CE0 2D300002 */  daddu      $6, $16, $0
    /* E5CE4 001E5CE4 40000724 */  addiu      $7, $0, 0x40
    /* E5CE8 001E5CE8 2D400000 */  daddu      $8, $0, $0
    /* E5CEC 001E5CEC 1E00093C */  lui        $9, %hi(func_001dacc0)
    /* E5CF0 001E5CF0 C0AC2925 */  addiu      $9, $9, %lo(func_001dacc0)
    /* E5CF4 001E5CF4 E86E070C */  jal        func_001dbba0
    /* E5CF8 001E5CF8 00000000 */   nop
    /* E5CFC 001E5CFC 01000224 */  addiu      $2, $0, 0x1
    /* E5D00 001E5D00 2000BFDF */  ld         $31, 0x20($29)
    /* E5D04 001E5D04 1000B17B */  lq         $17, 0x10($29)
    /* E5D08 001E5D08 0000B07B */  lq         $16, 0x0($29)
    /* E5D0C 001E5D0C 3000BD27 */  addiu      $29, $29, 0x30
    /* E5D10 001E5D10 0800E003 */  jr         $31
    /* E5D14 001E5D14 00000000 */   nop
    /* E5D18 001E5D18 00000000 */  nop
    /* E5D1C 001E5D1C 00000000 */  nop
.size func_001e5ca0, 0x80
