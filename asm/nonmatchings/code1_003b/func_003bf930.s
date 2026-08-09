.section .text
.set noat
.set noreorder
glabel func_003bf930
    /* 2BF930 003BF930 1800868C */  lw         $6, 0x18($4)
    /* 2BF934 003BF934 6800C010 */  beqz       $6, .L003BFAD8
    /* 2BF938 003BF938 00000000 */   nop
    /* 2BF93C 003BF93C 52008984 */  lh         $9, 0x52($4)
    /* 2BF940 003BF940 50008884 */  lh         $8, 0x50($4)
    /* 2BF944 003BF944 3D000911 */  beq        $8, $9, .L003BFA3C
    /* 2BF948 003BF948 4C008324 */   addiu     $3, $4, 0x4C
    /* 2BF94C 003BF94C 1800C58C */  lw         $5, 0x18($6)
    /* 2BF950 003BF950 2A080501 */  slt        $1, $8, $5
    /* 2BF954 003BF954 39002010 */  beqz       $1, .L003BFA3C
    /* 2BF958 003BF958 00000000 */   nop
    /* 2BF95C 003BF95C 2A082501 */  slt        $1, $9, $5
    /* 2BF960 003BF960 36002010 */  beqz       $1, .L003BFA3C
    /* 2BF964 003BF964 00000000 */   nop
    /* 2BF968 003BF968 5C00C78C */  lw         $7, 0x5C($6)
    /* 2BF96C 003BF96C C0280800 */  sll        $5, $8, 3
    /* 2BF970 003BF970 0C0064C4 */  lwc1       $f4, 0xC($3)
    /* 2BF974 003BF974 100063C4 */  lwc1       $f3, 0x10($3)
    /* 2BF978 003BF978 00008044 */  mtc1       $0, $f0
    /* 2BF97C 003BF97C 2330A800 */  subu       $6, $5, $8
    /* 2BF980 003BF980 C0280900 */  sll        $5, $9, 3
    /* 2BF984 003BF984 80300600 */  sll        $6, $6, 2
    /* 2BF988 003BF988 2328A900 */  subu       $5, $5, $9
    /* 2BF98C 003BF98C 2130E600 */  addu       $6, $7, $6
    /* 2BF990 003BF990 80280500 */  sll        $5, $5, 2
    /* 2BF994 003BF994 2128E500 */  addu       $5, $7, $5
    /* 2BF998 003BF998 1000C2C4 */  lwc1       $f2, 0x10($6)
    /* 2BF99C 003BF99C 1000A1C4 */  lwc1       $f1, 0x10($5)
    /* 2BF9A0 003BF9A0 C2200346 */  mul.s      $f3, $f4, $f3
    /* 2BF9A4 003BF9A4 18000246 */  adda.s     $f0, $f2
    /* 2BF9A8 003BF9A8 01080246 */  sub.s      $f0, $f1, $f2
    /* 2BF9AC 003BF9AC 1C180046 */  madd.s     $f0, $f3, $f0
    /* 2BF9B0 003BF9B0 280080E4 */  swc1       $f0, 0x28($4)
    /* 2BF9B4 003BF9B4 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 2BF9B8 003BF9B8 0400C0C4 */  lwc1       $f0, 0x4($6)
    /* 2BF9BC 003BF9BC 01080046 */  sub.s      $f0, $f1, $f0
    /* 2BF9C0 003BF9C0 1C0080E4 */  swc1       $f0, 0x1C($4)
    /* 2BF9C4 003BF9C4 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 2BF9C8 003BF9C8 0800C0C4 */  lwc1       $f0, 0x8($6)
    /* 2BF9CC 003BF9CC 01080046 */  sub.s      $f0, $f1, $f0
    /* 2BF9D0 003BF9D0 200080E4 */  swc1       $f0, 0x20($4)
    /* 2BF9D4 003BF9D4 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2BF9D8 003BF9D8 0C00C0C4 */  lwc1       $f0, 0xC($6)
    /* 2BF9DC 003BF9DC 01080046 */  sub.s      $f0, $f1, $f0
    /* 2BF9E0 003BF9E0 240080E4 */  swc1       $f0, 0x24($4)
    /* 2BF9E4 003BF9E4 1C0080C4 */  lwc1       $f0, 0x1C($4)
    /* 2BF9E8 003BF9E8 02000346 */  mul.s      $f0, $f0, $f3
    /* 2BF9EC 003BF9EC 1C0080E4 */  swc1       $f0, 0x1C($4)
    /* 2BF9F0 003BF9F0 200080C4 */  lwc1       $f0, 0x20($4)
    /* 2BF9F4 003BF9F4 02000346 */  mul.s      $f0, $f0, $f3
    /* 2BF9F8 003BF9F8 200080E4 */  swc1       $f0, 0x20($4)
    /* 2BF9FC 003BF9FC 240080C4 */  lwc1       $f0, 0x24($4)
    /* 2BFA00 003BFA00 02000346 */  mul.s      $f0, $f0, $f3
    /* 2BFA04 003BFA04 240080E4 */  swc1       $f0, 0x24($4)
    /* 2BFA08 003BFA08 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* 2BFA0C 003BFA0C 1C0080C4 */  lwc1       $f0, 0x1C($4)
    /* 2BFA10 003BFA10 00000146 */  add.s      $f0, $f0, $f1
    /* 2BFA14 003BFA14 1C0080E4 */  swc1       $f0, 0x1C($4)
    /* 2BFA18 003BFA18 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 2BFA1C 003BFA1C 200080C4 */  lwc1       $f0, 0x20($4)
    /* 2BFA20 003BFA20 00000146 */  add.s      $f0, $f0, $f1
    /* 2BFA24 003BFA24 200080E4 */  swc1       $f0, 0x20($4)
    /* 2BFA28 003BFA28 0C00C1C4 */  lwc1       $f1, 0xC($6)
    /* 2BFA2C 003BFA2C 240080C4 */  lwc1       $f0, 0x24($4)
    /* 2BFA30 003BFA30 00000146 */  add.s      $f0, $f0, $f1
    /* 2BFA34 003BFA34 15000010 */  b          .L003BFA8C
    /* 2BFA38 003BFA38 240080E4 */   swc1      $f0, 0x24($4)
  .L003BFA3C:
    /* 2BFA3C 003BFA3C 1800C58C */  lw         $5, 0x18($6)
    /* 2BFA40 003BFA40 2A080501 */  slt        $1, $8, $5
    /* 2BFA44 003BFA44 1A002010 */  beqz       $1, .L003BFAB0
    /* 2BFA48 003BFA48 00000000 */   nop
    /* 2BFA4C 003BFA4C 2A082501 */  slt        $1, $9, $5
    /* 2BFA50 003BFA50 17002010 */  beqz       $1, .L003BFAB0
    /* 2BFA54 003BFA54 00000000 */   nop
    /* 2BFA58 003BFA58 5C00C68C */  lw         $6, 0x5C($6)
    /* 2BFA5C 003BFA5C C0280800 */  sll        $5, $8, 3
    /* 2BFA60 003BFA60 2328A800 */  subu       $5, $5, $8
    /* 2BFA64 003BFA64 80280500 */  sll        $5, $5, 2
    /* 2BFA68 003BFA68 2128A600 */  addu       $5, $5, $6
    /* 2BFA6C 003BFA6C 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2BFA70 003BFA70 0800A2C4 */  lwc1       $f2, 0x8($5)
    /* 2BFA74 003BFA74 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2BFA78 003BFA78 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 2BFA7C 003BFA7C 1C0083E4 */  swc1       $f3, 0x1C($4)
    /* 2BFA80 003BFA80 200082E4 */  swc1       $f2, 0x20($4)
    /* 2BFA84 003BFA84 240081E4 */  swc1       $f1, 0x24($4)
    /* 2BFA88 003BFA88 280080E4 */  swc1       $f0, 0x28($4)
  .L003BFA8C:
    /* 2BFA8C 003BFA8C 0000668C */  lw         $6, 0x0($3)
    /* 2BFA90 003BFA90 FDFF0524 */  addiu      $5, $0, -0x3
    /* 2BFA94 003BFA94 2428C500 */  and        $5, $6, $5
    /* 2BFA98 003BFA98 000065AC */  sw         $5, 0x0($3)
    /* 2BFA9C 003BFA9C 03008390 */  lbu        $3, 0x3($4)
    /* 2BFAA0 003BFAA0 01006334 */  ori        $3, $3, 0x1
    /* 2BFAA4 003BFAA4 030083A0 */  sb         $3, 0x3($4)
    /* 2BFAA8 003BFAA8 0B000010 */  b          .L003BFAD8
    /* 2BFAAC 003BFAAC 00000000 */   nop
  .L003BFAB0:
    /* 2BFAB0 003BFAB0 5C00C58C */  lw         $5, 0x5C($6)
    /* 2BFAB4 003BFAB4 0400A3C4 */  lwc1       $f3, 0x4($5)
    /* 2BFAB8 003BFAB8 0800A2C4 */  lwc1       $f2, 0x8($5)
    /* 2BFABC 003BFABC 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 2BFAC0 003BFAC0 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 2BFAC4 003BFAC4 1C0083E4 */  swc1       $f3, 0x1C($4)
    /* 2BFAC8 003BFAC8 200082E4 */  swc1       $f2, 0x20($4)
    /* 2BFACC 003BFACC 240081E4 */  swc1       $f1, 0x24($4)
    /* 2BFAD0 003BFAD0 EEFF0010 */  b          .L003BFA8C
    /* 2BFAD4 003BFAD4 280080E4 */   swc1      $f0, 0x28($4)
  .L003BFAD8:
    /* 2BFAD8 003BFAD8 0800E003 */  jr         $31
    /* 2BFADC 003BFADC 00000000 */   nop
.size func_003bf930, 0x1b0
