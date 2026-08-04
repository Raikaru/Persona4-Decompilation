.section .text
.set noat
.set noreorder
glabel func_003dc490
    /* 2DC490 003DC490 1400A8C4 */  lwc1       $f8, 0x14($5)
    /* 2DC494 003DC494 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DC498 003DC498 2800A7C4 */  lwc1       $f7, 0x28($5)
    /* 2DC49C 003DC49C 00288244 */  mtc1       $2, $f5
    /* 2DC4A0 003DC4A0 0000A6C4 */  lwc1       $f6, 0x0($5)
    /* 2DC4A4 003DC4A4 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2DC4A8 003DC4A8 00208244 */  mtc1       $2, $f4
    /* 2DC4AC 003DC4AC 1800A3C4 */  lwc1       $f3, 0x18($5)
    /* 2DC4B0 003DC4B0 C0410746 */  add.s      $f7, $f8, $f7
    /* 2DC4B4 003DC4B4 2D108000 */  daddu      $2, $4, $0
    /* 2DC4B8 003DC4B8 2400A2C4 */  lwc1       $f2, 0x24($5)
    /* 2DC4BC 003DC4BC 81310746 */  sub.s      $f6, $f6, $f7
    /* 2DC4C0 003DC4C0 40290646 */  add.s      $f5, $f5, $f6
    /* 2DC4C4 003DC4C4 81180246 */  sub.s      $f2, $f3, $f2
    /* 2DC4C8 003DC4C8 C4000546 */  c1         0x500C4
    /* 2DC4CC 003DC4CC 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 2DC4D0 003DC4D0 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 2DC4D4 003DC4D4 00080046 */  add.s      $f0, $f1, $f0
    /* 2DC4D8 003DC4D8 42200346 */  mul.s      $f1, $f4, $f3
    /* 2DC4DC 003DC4DC C3200346 */  div.s      $f3, $f4, $f3
    /* 2DC4E0 003DC4E0 000081E4 */  swc1       $f1, 0x0($4)
    /* 2DC4E4 003DC4E4 42180246 */  mul.s      $f1, $f3, $f2
    /* 2DC4E8 003DC4E8 0C0081E4 */  swc1       $f1, 0xC($4)
    /* 2DC4EC 003DC4EC 02180046 */  mul.s      $f0, $f3, $f0
    /* 2DC4F0 003DC4F0 040080E4 */  swc1       $f0, 0x4($4)
    /* 2DC4F4 003DC4F4 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 2DC4F8 003DC4F8 2000A0C4 */  lwc1       $f0, 0x20($5)
    /* 2DC4FC 003DC4FC 00080046 */  add.s      $f0, $f1, $f0
    /* 2DC500 003DC500 02180046 */  mul.s      $f0, $f3, $f0
    /* 2DC504 003DC504 0800E003 */  jr         $31
    /* 2DC508 003DC508 080080E4 */   swc1      $f0, 0x8($4)
    /* 2DC50C 003DC50C 00000000 */  nop
.size func_003dc490, 0x80
