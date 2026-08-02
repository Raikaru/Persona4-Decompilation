.section .text
.set noat
.set noreorder
glabel func_0010f4c0
    /* F4C0 0010F4C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F4C4 0010F4C4 0000BFFF */  sd         $31, 0x0($29)
    /* F4C8 0010F4C8 7A00043C */  lui        $4, %hi(D_0079BE2C)
    /* F4CC 0010F4CC 2CBE8424 */  addiu      $4, $4, %lo(D_0079BE2C)
    /* F4D0 0010F4D0 B44E060C */  jal        func_00193ad0
    /* F4D4 0010F4D4 00000000 */   nop
    /* F4D8 0010F4D8 0000BFDF */  ld         $31, 0x0($29)
    /* F4DC 0010F4DC 1000BD27 */  addiu      $29, $29, 0x10
    /* F4E0 0010F4E0 0800E003 */  jr         $31
    /* F4E4 0010F4E4 00000000 */   nop
    /* F4E8 0010F4E8 00000000 */  nop
    /* F4EC 0010F4EC 00000000 */  nop
.size func_0010f4c0, 0x30
