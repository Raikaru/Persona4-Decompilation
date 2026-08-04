.section .text
.set noat
.set noreorder
glabel func_003dc590
    /* 2DC590 003DC590 0000A8C4 */  lwc1       $f8, 0x0($5)
    /* 2DC594 003DC594 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2DC598 003DC598 1400A7C4 */  lwc1       $f7, 0x14($5)
    /* 2DC59C 003DC59C 00288244 */  mtc1       $2, $f5
    /* 2DC5A0 003DC5A0 2800A6C4 */  lwc1       $f6, 0x28($5)
    /* 2DC5A4 003DC5A4 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2DC5A8 003DC5A8 00208244 */  mtc1       $2, $f4
    /* 2DC5AC 003DC5AC 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2DC5B0 003DC5B0 C0410746 */  add.s      $f7, $f8, $f7
    /* 2DC5B4 003DC5B4 2D108000 */  daddu      $2, $4, $0
    /* 2DC5B8 003DC5B8 1000A2C4 */  lwc1       $f2, 0x10($5)
    /* 2DC5BC 003DC5BC 81310746 */  sub.s      $f6, $f6, $f7
    /* 2DC5C0 003DC5C0 40290646 */  add.s      $f5, $f5, $f6
    /* 2DC5C4 003DC5C4 81180246 */  sub.s      $f2, $f3, $f2
    /* 2DC5C8 003DC5C8 C4000546 */  c1         0x500C4
    /* 2DC5CC 003DC5CC 2000A1C4 */  lwc1       $f1, 0x20($5)
    /* 2DC5D0 003DC5D0 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 2DC5D4 003DC5D4 00080046 */  add.s      $f0, $f1, $f0
    /* 2DC5D8 003DC5D8 42200346 */  mul.s      $f1, $f4, $f3
    /* 2DC5DC 003DC5DC C3200346 */  div.s      $f3, $f4, $f3
    /* 2DC5E0 003DC5E0 080081E4 */  swc1       $f1, 0x8($4)
    /* 2DC5E4 003DC5E4 42180246 */  mul.s      $f1, $f3, $f2
    /* 2DC5E8 003DC5E8 0C0081E4 */  swc1       $f1, 0xC($4)
    /* 2DC5EC 003DC5EC 02180046 */  mul.s      $f0, $f3, $f0
    /* 2DC5F0 003DC5F0 000080E4 */  swc1       $f0, 0x0($4)
    /* 2DC5F4 003DC5F4 2400A1C4 */  lwc1       $f1, 0x24($5)
    /* 2DC5F8 003DC5F8 1800A0C4 */  lwc1       $f0, 0x18($5)
    /* 2DC5FC 003DC5FC 00080046 */  add.s      $f0, $f1, $f0
    /* 2DC600 003DC600 02180046 */  mul.s      $f0, $f3, $f0
    /* 2DC604 003DC604 0800E003 */  jr         $31
    /* 2DC608 003DC608 040080E4 */   swc1      $f0, 0x4($4)
    /* 2DC60C 003DC60C 00000000 */  nop
.size func_003dc590, 0x80
