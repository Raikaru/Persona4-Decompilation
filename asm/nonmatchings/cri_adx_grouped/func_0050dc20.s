.section .text
.set noat
.set noreorder
glabel func_0050dc20
    /* 40DC20 0050DC20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40DC24 0050DC24 01000224 */  addiu      $2, $0, 0x1
    /* 40DC28 0050DC28 0000BFFF */  sd         $31, 0x0($29)
    /* 40DC2C 0050DC2C 0600A214 */  bne        $5, $2, .L0050DC48
    /* 40DC30 0050DC30 3C00848C */   lw        $4, 0x3C($4)
    /* 40DC34 0050DC34 0000BFDF */  ld         $31, 0x0($29)
    /* 40DC38 0050DC38 27000524 */  addiu      $5, $0, 0x27
    /* 40DC3C 0050DC3C 01000624 */  addiu      $6, $0, 0x1
    /* 40DC40 0050DC40 64931408 */  j          func_00524d90
    /* 40DC44 0050DC44 1000BD27 */   addiu     $29, $29, 0x10
  .L0050DC48:
    /* 40DC48 0050DC48 0000BFDF */  ld         $31, 0x0($29)
    /* 40DC4C 0050DC4C 27000524 */  addiu      $5, $0, 0x27
    /* 40DC50 0050DC50 2D300000 */  daddu      $6, $0, $0
    /* 40DC54 0050DC54 64931408 */  j          func_00524d90
    /* 40DC58 0050DC58 1000BD27 */   addiu     $29, $29, 0x10
    /* 40DC5C 0050DC5C 00000000 */  nop
.size func_0050dc20, 0x40
