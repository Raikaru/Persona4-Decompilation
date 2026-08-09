.section .text
.set noat
.set noreorder
glabel func_001faa60
    /* FAA60 001FAA60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAA64 001FAA64 0000BFFF */  sd         $31, 0x0($29)
    /* FAA68 001FAA68 070C0424 */  addiu      $4, $0, 0xC07
    /* FAA6C 001FAA6C 2D280000 */  daddu      $5, $0, $0
    /* FAA70 001FAA70 1C51060C */  jal        func_00194470
    /* FAA74 001FAA74 00000000 */   nop
    /* FAA78 001FAA78 47004390 */  lbu        $3, 0x47($2)
    /* FAA7C 001FAA7C EE006330 */  andi       $3, $3, 0xEE
    /* FAA80 001FAA80 470043A0 */  sb         $3, 0x47($2)
    /* FAA84 001FAA84 2000033C */  lui        $3, %hi(func_001faa00)
    /* FAA88 001FAA88 00AA6324 */  addiu      $3, $3, %lo(func_001faa00)
    /* FAA8C 001FAA8C 6C0043AC */  sw         $3, 0x6C($2)
    /* FAA90 001FAA90 0000BFDF */  ld         $31, 0x0($29)
    /* FAA94 001FAA94 1000BD27 */  addiu      $29, $29, 0x10
    /* FAA98 001FAA98 0800E003 */  jr         $31
    /* FAA9C 001FAA9C 00000000 */   nop
.size func_001faa60, 0x40
