.section .text
.set noat
.set noreorder
glabel func_0048cd60
    /* 38CD60 0048CD60 2000868C */  lw         $6, 0x20($4)
    /* 38CD64 0048CD64 2400858C */  lw         $5, 0x24($4)
    /* 38CD68 0048CD68 6400A0C4 */  lwc1       $f0, 0x64($5)
    /* 38CD6C 0048CD6C 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CD70 0048CD70 6400C0E4 */  swc1       $f0, 0x64($6)
    /* 38CD74 0048CD74 6800A0C4 */  lwc1       $f0, 0x68($5)
    /* 38CD78 0048CD78 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CD7C 0048CD7C 6800C0E4 */  swc1       $f0, 0x68($6)
    /* 38CD80 0048CD80 2D380000 */  daddu      $7, $0, $0
    /* 38CD84 0048CD84 08000010 */  b          .L0048CDA8
    /* 38CD88 0048CD88 00000000 */   nop
  .L0048CD8C:
    /* 38CD8C 0048CD8C C0200700 */  sll        $4, $7, 3
    /* 38CD90 0048CD90 2118A400 */  addu       $3, $5, $4
    /* 38CD94 0048CD94 740060C4 */  lwc1       $f0, 0x74($3)
    /* 38CD98 0048CD98 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CD9C 0048CD9C 2118C400 */  addu       $3, $6, $4
    /* 38CDA0 0048CDA0 740060E4 */  swc1       $f0, 0x74($3)
    /* 38CDA4 0048CDA4 0100E724 */  addiu      $7, $7, 0x1
  .L0048CDA8:
    /* 38CDA8 0048CDA8 0300E32C */  sltiu      $3, $7, 0x3
    /* 38CDAC 0048CDAC F7FF6014 */  bnez       $3, .L0048CD8C
    /* 38CDB0 0048CDB0 00000000 */   nop
    /* 38CDB4 0048CDB4 C800A0C4 */  lwc1       $f0, 0xC8($5)
    /* 38CDB8 0048CDB8 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CDBC 0048CDBC C800C0E4 */  swc1       $f0, 0xC8($6)
    /* 38CDC0 0048CDC0 D000A0C4 */  lwc1       $f0, 0xD0($5)
    /* 38CDC4 0048CDC4 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CDC8 0048CDC8 D000C0E4 */  swc1       $f0, 0xD0($6)
    /* 38CDCC 0048CDCC D800A0C4 */  lwc1       $f0, 0xD8($5)
    /* 38CDD0 0048CDD0 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CDD4 0048CDD4 D800C0E4 */  swc1       $f0, 0xD8($6)
    /* 38CDD8 0048CDD8 DC00A0C4 */  lwc1       $f0, 0xDC($5)
    /* 38CDDC 0048CDDC 02000C46 */  mul.s      $f0, $f0, $f12
    /* 38CDE0 0048CDE0 DC00C0E4 */  swc1       $f0, 0xDC($6)
    /* 38CDE4 0048CDE4 0800E003 */  jr         $31
    /* 38CDE8 0048CDE8 00000000 */   nop
    /* 38CDEC 0048CDEC 00000000 */  nop
.size func_0048cd60, 0x90
