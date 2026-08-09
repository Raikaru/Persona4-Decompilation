.section .text
.set noat
.set noreorder
glabel func_00196b70
    /* 96B70 00196B70 C400858C */  lw         $5, 0xC4($4)
    /* 96B74 00196B74 FEFF0324 */  addiu      $3, $0, -0x2
    /* 96B78 00196B78 2418A300 */  and        $3, $5, $3
    /* 96B7C 00196B7C C40083AC */  sw         $3, 0xC4($4)
    /* 96B80 00196B80 C8008394 */  lhu        $3, 0xC8($4)
    /* 96B84 00196B84 FEFF6330 */  andi       $3, $3, 0xFFFE
    /* 96B88 00196B88 C80083A4 */  sh         $3, 0xC8($4)
    /* 96B8C 00196B8C 0800E003 */  jr         $31
    /* 96B90 00196B90 00000000 */   nop
    /* 96B94 00196B94 00000000 */  nop
    /* 96B98 00196B98 00000000 */  nop
    /* 96B9C 00196B9C 00000000 */  nop
.size func_00196b70, 0x30
