.section .text
.set noat
.set noreorder
glabel func_001e8bb0
    /* E8BB0 001E8BB0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* E8BB4 001E8BB4 4000BFFF */  sd         $31, 0x40($29)
    /* E8BB8 001E8BB8 3000B37F */  sq         $19, 0x30($29)
    /* E8BBC 001E8BBC 2000B27F */  sq         $18, 0x20($29)
    /* E8BC0 001E8BC0 1000B17F */  sq         $17, 0x10($29)
    /* E8BC4 001E8BC4 0000B07F */  sq         $16, 0x0($29)
    /* E8BC8 001E8BC8 14740A0C */  jal        func_0029d050
    /* E8BCC 001E8BCC 00000000 */   nop
    /* E8BD0 001E8BD0 2D984000 */  daddu      $19, $2, $0
    /* E8BD4 001E8BD4 2D200000 */  daddu      $4, $0, $0
    /* E8BD8 001E8BD8 00730A0C */  jal        func_0029cc00
    /* E8BDC 001E8BDC 00000000 */   nop
    /* E8BE0 001E8BE0 2D884000 */  daddu      $17, $2, $0
    /* E8BE4 001E8BE4 01000424 */  addiu      $4, $0, 0x1
    /* E8BE8 001E8BE8 00730A0C */  jal        func_0029cc00
    /* E8BEC 001E8BEC 00000000 */   nop
    /* E8BF0 001E8BF0 2D804000 */  daddu      $16, $2, $0
    /* E8BF4 001E8BF4 02000424 */  addiu      $4, $0, 0x2
    /* E8BF8 001E8BF8 00730A0C */  jal        func_0029cc00
    /* E8BFC 001E8BFC 00000000 */   nop
    /* E8C00 001E8C00 2D904000 */  daddu      $18, $2, $0
    /* E8C04 001E8C04 3C211100 */  dsll32     $4, $17, 4
    /* E8C08 001E8C08 3E210400 */  dsrl32     $4, $4, 4
    /* E8C0C 001E8C0C 30C3060C */  jal        func_001b0cc0
    /* E8C10 001E8C10 00000000 */   nop
    /* E8C14 001E8C14 3C341000 */  dsll32     $6, $16, 16
    /* E8C18 001E8C18 3F340600 */  dsra32     $6, $6, 16
    /* E8C1C 001E8C1C 2D206002 */  daddu      $4, $19, $0
    /* E8C20 001E8C20 2D284000 */  daddu      $5, $2, $0
    /* E8C24 001E8C24 2D384002 */  daddu      $7, $18, $0
    /* E8C28 001E8C28 0078070C */  jal        func_001de000
    /* E8C2C 001E8C2C 00000000 */   nop
    /* E8C30 001E8C30 2D204000 */  daddu      $4, $2, $0
    /* E8C34 001E8C34 D4730A0C */  jal        func_0029cf50
    /* E8C38 001E8C38 00000000 */   nop
    /* E8C3C 001E8C3C 01000224 */  addiu      $2, $0, 0x1
    /* E8C40 001E8C40 4000BFDF */  ld         $31, 0x40($29)
    /* E8C44 001E8C44 3000B37B */  lq         $19, 0x30($29)
    /* E8C48 001E8C48 2000B27B */  lq         $18, 0x20($29)
    /* E8C4C 001E8C4C 1000B17B */  lq         $17, 0x10($29)
    /* E8C50 001E8C50 0000B07B */  lq         $16, 0x0($29)
    /* E8C54 001E8C54 5000BD27 */  addiu      $29, $29, 0x50
    /* E8C58 001E8C58 0800E003 */  jr         $31
    /* E8C5C 001E8C5C 00000000 */   nop
.size func_001e8bb0, 0xb0
