.section .text
.set noat
.set noreorder
glabel func_001f62b0
    /* F62B0 001F62B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F62B4 001F62B4 0000BFFF */  sd         $31, 0x0($29)
    /* F62B8 001F62B8 F8F40A0C */  jal        func_002bd3e0
    /* F62BC 001F62BC 00000000 */   nop
    /* F62C0 001F62C0 04F50A0C */  jal        func_002bd410
    /* F62C4 001F62C4 00000000 */   nop
    /* F62C8 001F62C8 ACB3838F */  lw         $3, -0x4C54($28)
    /* F62CC 001F62CC 500A60A4 */  sh         $0, 0xA50($3)
    /* F62D0 001F62D0 ACB3848F */  lw         $4, -0x4C54($28)
    /* F62D4 001F62D4 4E0A8394 */  lhu        $3, 0xA4E($4)
    /* F62D8 001F62D8 FEFF6330 */  andi       $3, $3, 0xFFFE
    /* F62DC 001F62DC 4E0A83A4 */  sh         $3, 0xA4E($4)
    /* F62E0 001F62E0 0000BFDF */  ld         $31, 0x0($29)
    /* F62E4 001F62E4 1000BD27 */  addiu      $29, $29, 0x10
    /* F62E8 001F62E8 0800E003 */  jr         $31
    /* F62EC 001F62EC 00000000 */   nop
.size func_001f62b0, 0x40
