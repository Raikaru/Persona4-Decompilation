.section .text
.set noat
.set noreorder
glabel func_003e6db0
    /* 2E6DB0 003E6DB0 8800023C */  lui        $2, %hi(D_008872F8)
    /* 2E6DB4 003E6DB4 1400838C */  lw         $3, 0x14($4)
    /* 2E6DB8 003E6DB8 F87244C4 */  lwc1       $f4, %lo(D_008872F8)($2)
    /* 2E6DBC 003E6DBC 8800023C */  lui        $2, %hi(D_008872FC)
    /* 2E6DC0 003E6DC0 FC7243C4 */  lwc1       $f3, %lo(D_008872FC)($2)
    /* 2E6DC4 003E6DC4 01000224 */  addiu      $2, $0, 0x1
    /* 2E6DC8 003E6DC8 09006210 */  beq        $3, $2, .L003E6DF0
    /* 2E6DCC 003E6DCC 00000000 */   nop
    /* 2E6DD0 003E6DD0 02000224 */  addiu      $2, $0, 0x2
    /* 2E6DD4 003E6DD4 03006210 */  beq        $3, $2, .L003E6DE4
    /* 2E6DD8 003E6DD8 00000000 */   nop
    /* 2E6DDC 003E6DDC 05000010 */  b          .L003E6DF4
    /* 2E6DE0 003E6DE0 840081C4 */   lwc1      $f1, 0x84($4)
  .L003E6DE4:
    /* 2E6DE4 003E6DE4 800086C4 */  lwc1       $f6, 0x80($4)
    /* 2E6DE8 003E6DE8 08000010 */  b          .L003E6E0C
    /* 2E6DEC 003E6DEC 840085C4 */   lwc1      $f5, 0x84($4)
  .L003E6DF0:
    /* 2E6DF0 003E6DF0 840081C4 */  lwc1       $f1, 0x84($4)
  .L003E6DF4:
    /* 2E6DF4 003E6DF4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2E6DF8 003E6DF8 800080C4 */  lwc1       $f0, 0x80($4)
    /* 2E6DFC 003E6DFC 00108244 */  mtc1       $2, $f2
    /* 2E6E00 003E6E00 00000000 */  nop
    /* 2E6E04 003E6E04 43110146 */  div.s      $f5, $f2, $f1
    /* 2E6E08 003E6E08 83110046 */  div.s      $f6, $f2, $f0
  .L003E6E0C:
    /* 2E6E0C 003E6E0C D138023C */  lui        $2, (0x38D1B717 >> 16)
    /* 2E6E10 003E6E10 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2E6E14 003E6E14 17B74534 */  ori        $5, $2, (0x38D1B717 & 0xFFFF)
    /* 2E6E18 003E6E18 81180446 */  sub.s      $f2, $f3, $f4
    /* 2E6E1C 003E6E1C 2D108000 */  daddu      $2, $4, $0
    /* 2E6E20 003E6E20 00088544 */  mtc1       $5, $f1
    /* 2E6E24 003E6E24 00008344 */  mtc1       $3, $f0
    /* 2E6E28 003E6E28 00000000 */  nop
    /* 2E6E2C 003E6E2C 42080246 */  mul.s      $f1, $f1, $f2
    /* 2E6E30 003E6E30 81180146 */  sub.s      $f2, $f3, $f1
    /* 2E6E34 003E6E34 40200146 */  add.s      $f1, $f4, $f1
    /* 2E6E38 003E6E38 C1100146 */  sub.s      $f3, $f2, $f1
    /* 2E6E3C 003E6E3C 80100146 */  add.s      $f2, $f2, $f1
    /* 2E6E40 003E6E40 41280646 */  sub.s      $f1, $f5, $f6
    /* 2E6E44 003E6E44 03190146 */  div.s      $f4, $f3, $f1
    /* 2E6E48 003E6E48 00088044 */  mtc1       $0, $f1
    /* 2E6E4C 003E6E4C C0280646 */  add.s      $f3, $f5, $f6
    /* 2E6E50 003E6E50 18080246 */  adda.s     $f1, $f2
    /* 2E6E54 003E6E54 5D200346 */  msub.s     $f1, $f4, $f3
    /* 2E6E58 003E6E58 02000146 */  mul.s      $f0, $f0, $f1
    /* 2E6E5C 003E6E5C 8C0084E4 */  swc1       $f4, 0x8C($4)
    /* 2E6E60 003E6E60 0800E003 */  jr         $31
    /* 2E6E64 003E6E64 900080E4 */   swc1      $f0, 0x90($4)
    /* 2E6E68 003E6E68 00000000 */  nop
    /* 2E6E6C 003E6E6C 00000000 */  nop
.size func_003e6db0, 0xc0
