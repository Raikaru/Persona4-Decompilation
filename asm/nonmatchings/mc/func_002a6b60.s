.section .text
.set noat
.set noreorder
glabel func_002a6b60
    /* 1A6B60 002A6B60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1A6B64 002A6B64 0000BFFF */  sd         $31, 0x0($29)
    /* 1A6B68 002A6B68 2D18E000 */  daddu      $3, $7, $0
    /* 1A6B6C 002A6B6C 2B00C010 */  beqz       $6, .L002A6C1C
    /* 1A6B70 002A6B70 00000000 */   nop
    /* 1A6B74 002A6B74 0400628C */  lw         $2, 0x4($3)
    /* 1A6B78 002A6B78 02004230 */  andi       $2, $2, 0x2
    /* 1A6B7C 002A6B7C 15004010 */  beqz       $2, .L002A6BD4
    /* 1A6B80 002A6B80 00000000 */   nop
    /* 1A6B84 002A6B84 C0018224 */  addiu      $2, $4, 0x1C0
    /* 1A6B88 002A6B88 00008244 */  mtc1       $2, $f0
    /* 1A6B8C 002A6B8C 00000000 */  nop
    /* 1A6B90 002A6B90 20038046 */  cvt.s.w    $f12, $f0
    /* 1A6B94 002A6B94 0C00A224 */  addiu      $2, $5, 0xC
    /* 1A6B98 002A6B98 00008244 */  mtc1       $2, $f0
    /* 1A6B9C 002A6B9C 00000000 */  nop
    /* 1A6BA0 002A6BA0 60038046 */  cvt.s.w    $f13, $f0
    /* 1A6BA4 002A6BA4 00708044 */  mtc1       $0, $f14
    /* 1A6BA8 002A6BA8 FF00C530 */  andi       $5, $6, 0xFF
    /* 1A6BAC 002A6BAC FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* 1A6BB0 002A6BB0 FFFF4434 */  ori        $4, $2, (0xFFFFFF & 0xFFFF)
    /* 1A6BB4 002A6BB4 3D000624 */  addiu      $6, $0, 0x3D
    /* 1A6BB8 002A6BB8 2D380000 */  daddu      $7, $0, $0
    /* 1A6BBC 002A6BBC 9803688C */  lw         $8, 0x398($3)
    /* 1A6BC0 002A6BC0 01000924 */  addiu      $9, $0, 0x1
    /* 1A6BC4 002A6BC4 FC7C090C */  jal        func_0025f3f0
    /* 1A6BC8 002A6BC8 00000000 */   nop
    /* 1A6BCC 002A6BCC 13000010 */  b          .L002A6C1C
    /* 1A6BD0 002A6BD0 00000000 */   nop
  .L002A6BD4:
    /* 1A6BD4 002A6BD4 9A018224 */  addiu      $2, $4, 0x19A
    /* 1A6BD8 002A6BD8 00008244 */  mtc1       $2, $f0
    /* 1A6BDC 002A6BDC 00000000 */  nop
    /* 1A6BE0 002A6BE0 20038046 */  cvt.s.w    $f12, $f0
    /* 1A6BE4 002A6BE4 0C00A224 */  addiu      $2, $5, 0xC
    /* 1A6BE8 002A6BE8 00008244 */  mtc1       $2, $f0
    /* 1A6BEC 002A6BEC 00000000 */  nop
    /* 1A6BF0 002A6BF0 60038046 */  cvt.s.w    $f13, $f0
    /* 1A6BF4 002A6BF4 00708044 */  mtc1       $0, $f14
    /* 1A6BF8 002A6BF8 FF00C530 */  andi       $5, $6, 0xFF
    /* 1A6BFC 002A6BFC FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* 1A6C00 002A6C00 FFFF4434 */  ori        $4, $2, (0xFFFFFF & 0xFFFF)
    /* 1A6C04 002A6C04 39000624 */  addiu      $6, $0, 0x39
    /* 1A6C08 002A6C08 2D380000 */  daddu      $7, $0, $0
    /* 1A6C0C 002A6C0C 9803688C */  lw         $8, 0x398($3)
    /* 1A6C10 002A6C10 01000924 */  addiu      $9, $0, 0x1
    /* 1A6C14 002A6C14 FC7C090C */  jal        func_0025f3f0
    /* 1A6C18 002A6C18 00000000 */   nop
  .L002A6C1C:
    /* 1A6C1C 002A6C1C 0000BFDF */  ld         $31, 0x0($29)
    /* 1A6C20 002A6C20 1000BD27 */  addiu      $29, $29, 0x10
    /* 1A6C24 002A6C24 0800E003 */  jr         $31
    /* 1A6C28 002A6C28 00000000 */   nop
    /* 1A6C2C 002A6C2C 00000000 */  nop
.size func_002a6b60, 0xd0
