.section .text
.set noat
.set noreorder
glabel func_001c8cf0
    /* C8CF0 001C8CF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* C8CF4 001C8CF4 2000BFFF */  sd         $31, 0x20($29)
    /* C8CF8 001C8CF8 1000B17F */  sq         $17, 0x10($29)
    /* C8CFC 001C8CFC 0000B07F */  sq         $16, 0x0($29)
    /* C8D00 001C8D00 2D888000 */  daddu      $17, $4, $0
    /* C8D04 001C8D04 E000908C */  lw         $16, 0xE0($4)
    /* C8D08 001C8D08 2D200002 */  daddu      $4, $16, $0
    /* C8D0C 001C8D0C 2D280000 */  daddu      $5, $0, $0
    /* C8D10 001C8D10 6E000696 */  lhu        $6, 0x6E($16)
    /* C8D14 001C8D14 2D380000 */  daddu      $7, $0, $0
    /* C8D18 001C8D18 C45F070C */  jal        func_001d7f10
    /* C8D1C 001C8D1C 00000000 */   nop
    /* C8D20 001C8D20 060122A6 */  sh         $2, 0x106($17)
    /* C8D24 001C8D24 98000426 */  addiu      $4, $16, 0x98
    /* C8D28 001C8D28 7C63070C */  jal        func_001d8df0
    /* C8D2C 001C8D2C 00000000 */   nop
    /* C8D30 001C8D30 040122A6 */  sh         $2, 0x104($17)
    /* C8D34 001C8D34 000120AE */  sw         $0, 0x100($17)
    /* C8D38 001C8D38 2000BFDF */  ld         $31, 0x20($29)
    /* C8D3C 001C8D3C 1000B17B */  lq         $17, 0x10($29)
    /* C8D40 001C8D40 0000B07B */  lq         $16, 0x0($29)
    /* C8D44 001C8D44 3000BD27 */  addiu      $29, $29, 0x30
    /* C8D48 001C8D48 0800E003 */  jr         $31
    /* C8D4C 001C8D4C 00000000 */   nop
.size func_001c8cf0, 0x60
