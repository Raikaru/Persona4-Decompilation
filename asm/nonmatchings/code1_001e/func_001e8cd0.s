.section .text
.set noat
.set noreorder
glabel func_001e8cd0
    /* E8CD0 001E8CD0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* E8CD4 001E8CD4 4000BFFF */  sd         $31, 0x40($29)
    /* E8CD8 001E8CD8 3000B37F */  sq         $19, 0x30($29)
    /* E8CDC 001E8CDC 2000B27F */  sq         $18, 0x20($29)
    /* E8CE0 001E8CE0 1000B17F */  sq         $17, 0x10($29)
    /* E8CE4 001E8CE4 0000B07F */  sq         $16, 0x0($29)
    /* E8CE8 001E8CE8 14740A0C */  jal        func_0029d050
    /* E8CEC 001E8CEC 00000000 */   nop
    /* E8CF0 001E8CF0 2D984000 */  daddu      $19, $2, $0
    /* E8CF4 001E8CF4 2D200000 */  daddu      $4, $0, $0
    /* E8CF8 001E8CF8 00730A0C */  jal        func_0029cc00
    /* E8CFC 001E8CFC 00000000 */   nop
    /* E8D00 001E8D00 2D804000 */  daddu      $16, $2, $0
    /* E8D04 001E8D04 01000424 */  addiu      $4, $0, 0x1
    /* E8D08 001E8D08 00730A0C */  jal        func_0029cc00
    /* E8D0C 001E8D0C 00000000 */   nop
    /* E8D10 001E8D10 2D904000 */  daddu      $18, $2, $0
    /* E8D14 001E8D14 02000424 */  addiu      $4, $0, 0x2
    /* E8D18 001E8D18 00730A0C */  jal        func_0029cc00
    /* E8D1C 001E8D1C 00000000 */   nop
    /* E8D20 001E8D20 2D884000 */  daddu      $17, $2, $0
    /* E8D24 001E8D24 3C211000 */  dsll32     $4, $16, 4
    /* E8D28 001E8D28 3E210400 */  dsrl32     $4, $4, 4
    /* E8D2C 001E8D2C 30C3060C */  jal        func_001b0cc0
    /* E8D30 001E8D30 00000000 */   nop
    /* E8D34 001E8D34 2D206002 */  daddu      $4, $19, $0
    /* E8D38 001E8D38 2D284000 */  daddu      $5, $2, $0
    /* E8D3C 001E8D3C 2D304002 */  daddu      $6, $18, $0
    /* E8D40 001E8D40 2D382002 */  daddu      $7, $17, $0
    /* E8D44 001E8D44 5C75070C */  jal        func_001dd570
    /* E8D48 001E8D48 00000000 */   nop
    /* E8D4C 001E8D4C 2D204000 */  daddu      $4, $2, $0
    /* E8D50 001E8D50 D4730A0C */  jal        func_0029cf50
    /* E8D54 001E8D54 00000000 */   nop
    /* E8D58 001E8D58 01000224 */  addiu      $2, $0, 0x1
    /* E8D5C 001E8D5C 4000BFDF */  ld         $31, 0x40($29)
    /* E8D60 001E8D60 3000B37B */  lq         $19, 0x30($29)
    /* E8D64 001E8D64 2000B27B */  lq         $18, 0x20($29)
    /* E8D68 001E8D68 1000B17B */  lq         $17, 0x10($29)
    /* E8D6C 001E8D6C 0000B07B */  lq         $16, 0x0($29)
    /* E8D70 001E8D70 5000BD27 */  addiu      $29, $29, 0x50
    /* E8D74 001E8D74 0800E003 */  jr         $31
    /* E8D78 001E8D78 00000000 */   nop
    /* E8D7C 001E8D7C 00000000 */  nop
.size func_001e8cd0, 0xb0
