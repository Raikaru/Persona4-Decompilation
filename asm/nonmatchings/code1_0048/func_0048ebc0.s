.section .text
.set noat
.set noreorder
glabel func_0048ebc0
    /* 38EBC0 0048EBC0 2000868C */  lw         $6, 0x20($4)
    /* 38EBC4 0048EBC4 2400858C */  lw         $5, 0x24($4)
    /* 38EBC8 0048EBC8 6400A0C4 */  lwc1       $f0, 0x64($5)
    /* 38EBCC 0048EBCC 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EBD0 0048EBD0 6400C0E4 */  swc1       $f0, 0x64($6)
    /* 38EBD4 0048EBD4 6800A0C4 */  lwc1       $f0, 0x68($5)
    /* 38EBD8 0048EBD8 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EBDC 0048EBDC 6800C0E4 */  swc1       $f0, 0x68($6)
    /* 38EBE0 0048EBE0 2D380000 */  daddu      $7, $0, $0
    /* 38EBE4 0048EBE4 08000010 */  b          .L0048EC08
    /* 38EBE8 0048EBE8 00000000 */   nop
  .L0048EBEC:
    /* 38EBEC 0048EBEC C0200700 */  sll        $4, $7, 3
    /* 38EBF0 0048EBF0 2118A400 */  addu       $3, $5, $4
    /* 38EBF4 0048EBF4 740060C4 */  lwc1       $f0, 0x74($3)
    /* 38EBF8 0048EBF8 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EBFC 0048EBFC 2118C400 */  addu       $3, $6, $4
    /* 38EC00 0048EC00 740060E4 */  swc1       $f0, 0x74($3)
    /* 38EC04 0048EC04 0100E724 */  addiu      $7, $7, 0x1
  .L0048EC08:
    /* 38EC08 0048EC08 0300E32C */  sltiu      $3, $7, 0x3
    /* 38EC0C 0048EC0C F7FF6014 */  bnez       $3, .L0048EBEC
    /* 38EC10 0048EC10 00000000 */   nop
    /* 38EC14 0048EC14 C800A0C4 */  lwc1       $f0, 0xC8($5)
    /* 38EC18 0048EC18 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EC1C 0048EC1C C800C0E4 */  swc1       $f0, 0xC8($6)
    /* 38EC20 0048EC20 D800A0C4 */  lwc1       $f0, 0xD8($5)
    /* 38EC24 0048EC24 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EC28 0048EC28 D800C0E4 */  swc1       $f0, 0xD8($6)
    /* 38EC2C 0048EC2C E000A0C4 */  lwc1       $f0, 0xE0($5)
    /* 38EC30 0048EC30 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EC34 0048EC34 E000C0E4 */  swc1       $f0, 0xE0($6)
    /* 38EC38 0048EC38 E400A0C4 */  lwc1       $f0, 0xE4($5)
    /* 38EC3C 0048EC3C 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38EC40 0048EC40 E400C0E4 */  swc1       $f0, 0xE4($6)
    /* 38EC44 0048EC44 0800E003 */  jr         $31
    /* 38EC48 0048EC48 00000000 */   nop
    /* 38EC4C 0048EC4C 00000000 */  nop
.size func_0048ebc0, 0x90
