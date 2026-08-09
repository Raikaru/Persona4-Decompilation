.section .text
.set noat
.set noreorder
glabel func_001ec350
    /* EC350 001EC350 040081C4 */  lwc1       $f1, 0x4($4)
    /* EC354 001EC354 000083C4 */  lwc1       $f3, 0x0($4)
    /* EC358 001EC358 080082C4 */  lwc1       $f2, 0x8($4)
    /* EC35C 001EC35C 0C0080C4 */  lwc1       $f0, 0xC($4)
    /* EC360 001EC360 1A080146 */  mula.s     $f1, $f1
    /* EC364 001EC364 00088044 */  mtc1       $0, $f1
    /* EC368 001EC368 1E180346 */  madda.s    $f3, $f3
    /* EC36C 001EC36C 1E100246 */  madda.s    $f2, $f2
    /* EC370 001EC370 1C000046 */  madd.s     $f0, $f0, $f0
    /* EC374 001EC374 04000046 */  c1         0x4
    /* EC378 001EC378 00000000 */  nop
    /* EC37C 001EC37C 00000000 */  nop
    /* EC380 001EC380 32080046 */  c.eq.s     $f1, $f0
    /* EC384 001EC384 0E000145 */  bc1t       .L001EC3C0
    /* EC388 001EC388 00000000 */   nop
    /* EC38C 001EC38C 00000000 */  nop
    /* EC390 001EC390 00000000 */  nop
    /* EC394 001EC394 43180046 */  div.s      $f1, $f3, $f0
    /* EC398 001EC398 0000A1E4 */  swc1       $f1, 0x0($5)
    /* EC39C 001EC39C 040081C4 */  lwc1       $f1, 0x4($4)
    /* EC3A0 001EC3A0 43080046 */  div.s      $f1, $f1, $f0
    /* EC3A4 001EC3A4 0400A1E4 */  swc1       $f1, 0x4($5)
    /* EC3A8 001EC3A8 080081C4 */  lwc1       $f1, 0x8($4)
    /* EC3AC 001EC3AC 43080046 */  div.s      $f1, $f1, $f0
    /* EC3B0 001EC3B0 0800A1E4 */  swc1       $f1, 0x8($5)
    /* EC3B4 001EC3B4 0C0081C4 */  lwc1       $f1, 0xC($4)
    /* EC3B8 001EC3B8 43080046 */  div.s      $f1, $f1, $f0
    /* EC3BC 001EC3BC 0C00A1E4 */  swc1       $f1, 0xC($5)
  .L001EC3C0:
    /* EC3C0 001EC3C0 0800E003 */  jr         $31
    /* EC3C4 001EC3C4 00000000 */   nop
    /* EC3C8 001EC3C8 00000000 */  nop
    /* EC3CC 001EC3CC 00000000 */  nop
.size func_001ec350, 0x80
