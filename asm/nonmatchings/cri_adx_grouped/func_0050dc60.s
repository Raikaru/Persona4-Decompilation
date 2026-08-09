.section .text
.set noat
.set noreorder
glabel func_0050dc60
    /* 40DC60 0050DC60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40DC64 0050DC64 2D30A000 */  daddu      $6, $5, $0
    /* 40DC68 0050DC68 0000BFFF */  sd         $31, 0x0($29)
    /* 40DC6C 0050DC6C 24000524 */  addiu      $5, $0, 0x24
    /* 40DC70 0050DC70 05008010 */  beqz       $4, .L0050DC88
    /* 40DC74 0050DC74 3C00828C */   lw        $2, 0x3C($4)
    /* 40DC78 0050DC78 0000BFDF */  ld         $31, 0x0($29)
    /* 40DC7C 0050DC7C 2D204000 */  daddu      $4, $2, $0
    /* 40DC80 0050DC80 64931408 */  j          func_00524d90
    /* 40DC84 0050DC84 1000BD27 */   addiu     $29, $29, 0x10
  .L0050DC88:
    /* 40DC88 0050DC88 0000BFDF */  ld         $31, 0x0($29)
    /* 40DC8C 0050DC8C 0800E003 */  jr         $31
    /* 40DC90 0050DC90 1000BD27 */   addiu     $29, $29, 0x10
    /* 40DC94 0050DC94 00000000 */  nop
.size func_0050dc60, 0x38
