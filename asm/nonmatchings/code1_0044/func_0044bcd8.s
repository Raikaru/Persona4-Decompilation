.section .text
.set noat
.set noreorder
glabel func_0044bcd8
    /* 34BCD8 0044BCD8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 34BCDC 0044BCDC 1000B2FF */  sd         $18, 0x10($29)
    /* 34BCE0 0044BCE0 1800BFFF */  sd         $31, 0x18($29)
    /* 34BCE4 0044BCE4 0000B0FF */  sd         $16, 0x0($29)
    /* 34BCE8 0044BCE8 3637110C */  jal        func_0044dcd8
    /* 34BCEC 0044BCEC 0800B1FF */   sd        $17, 0x8($29)
    /* 34BCF0 0044BCF0 2D904000 */  daddu      $18, $2, $0
    /* 34BCF4 0044BCF4 2D204000 */  daddu      $4, $2, $0
    /* 34BCF8 0044BCF8 8239110C */  jal        func_0044e608
    /* 34BCFC 0044BCFC 2D280000 */   daddu     $5, $0, $0
    /* 34BD00 0044BD00 DF030524 */  addiu      $5, $0, 0x3DF
    /* 34BD04 0044BD04 2D204002 */  daddu      $4, $18, $0
    /* 34BD08 0044BD08 3C2D0500 */  dsll32     $5, $5, 20
    /* 34BD0C 0044BD0C 22004004 */  bltz       $2, .L0044BD98
    /* 34BD10 0044BD10 2D780000 */   daddu     $15, $0, $0
    /* 34BD14 0044BD14 5A38110C */  jal        func_0044e168
    /* 34BD18 0044BD18 00000000 */   nop
    /* 34BD1C 0044BD1C 0C3A110C */  jal        func_0044e830
    /* 34BD20 0044BD20 2D204000 */   daddu     $4, $2, $0
    /* 34BD24 0044BD24 3C880200 */  dsll32     $17, $2, 0
    /* 34BD28 0044BD28 3E881100 */  dsrl32     $17, $17, 0
    /* 34BD2C 0044BD2C 3C881100 */  dsll32     $17, $17, 0
    /* 34BD30 0044BD30 7A781100 */  dsrl       $15, $17, 1
    /* 34BD34 0044BD34 01002E32 */  andi       $14, $17, 0x1
    /* 34BD38 0044BD38 2570CF01 */  or         $14, $14, $15
    /* 34BD3C 0044BD3C 23002006 */  bltz       $17, .L0044BDCC
    /* 34BD40 0044BD40 2D202002 */   daddu     $4, $17, $0
    /* 34BD44 0044BD44 802E110C */  jal        func_0044ba00
    /* 34BD48 0044BD48 00000000 */   nop
    /* 34BD4C 0044BD4C 2D204002 */  daddu      $4, $18, $0
  .L0044BD50:
    /* 34BD50 0044BD50 4038110C */  jal        func_0044e100
    /* 34BD54 0044BD54 2D284000 */   daddu     $5, $2, $0
    /* 34BD58 0044BD58 2D800000 */  daddu      $16, $0, $0
    /* 34BD5C 0044BD5C 2D904000 */  daddu      $18, $2, $0
    /* 34BD60 0044BD60 2D204000 */  daddu      $4, $2, $0
    /* 34BD64 0044BD64 8239110C */  jal        func_0044e608
    /* 34BD68 0044BD68 2D280002 */   daddu     $5, $16, $0
    /* 34BD6C 0044BD6C 2D284002 */  daddu      $5, $18, $0
    /* 34BD70 0044BD70 10004104 */  bgez       $2, .L0044BDB4
    /* 34BD74 0044BD74 2D200002 */   daddu     $4, $16, $0
    /* 34BD78 0044BD78 4038110C */  jal        func_0044e100
    /* 34BD7C 0044BD7C 00000000 */   nop
    /* 34BD80 0044BD80 0C3A110C */  jal        func_0044e830
    /* 34BD84 0044BD84 2D204000 */   daddu     $4, $2, $0
    /* 34BD88 0044BD88 3C100200 */  dsll32     $2, $2, 0
    /* 34BD8C 0044BD8C 3E100200 */  dsrl32     $2, $2, 0
    /* 34BD90 0044BD90 2F882202 */  dsubu      $17, $17, $2
  .L0044BD94:
    /* 34BD94 0044BD94 2D782002 */  daddu      $15, $17, $0
  .L0044BD98:
    /* 34BD98 0044BD98 0000B0DF */  ld         $16, 0x0($29)
    /* 34BD9C 0044BD9C 2D10E001 */  daddu      $2, $15, $0
    /* 34BDA0 0044BDA0 0800B1DF */  ld         $17, 0x8($29)
    /* 34BDA4 0044BDA4 1000B2DF */  ld         $18, 0x10($29)
    /* 34BDA8 0044BDA8 1800BFDF */  ld         $31, 0x18($29)
    /* 34BDAC 0044BDAC 0800E003 */  jr         $31
    /* 34BDB0 0044BDB0 2000BD27 */   addiu     $29, $29, 0x20
  .L0044BDB4:
    /* 34BDB4 0044BDB4 0C3A110C */  jal        func_0044e830
    /* 34BDB8 0044BDB8 2D204002 */   daddu     $4, $18, $0
    /* 34BDBC 0044BDBC 3C100200 */  dsll32     $2, $2, 0
    /* 34BDC0 0044BDC0 3E100200 */  dsrl32     $2, $2, 0
    /* 34BDC4 0044BDC4 F3FF0010 */  b          .L0044BD94
    /* 34BDC8 0044BDC8 2D882202 */   daddu     $17, $17, $2
  .L0044BDCC:
    /* 34BDCC 0044BDCC 802E110C */  jal        func_0044ba00
    /* 34BDD0 0044BDD0 2D20C001 */   daddu     $4, $14, $0
    /* 34BDD4 0044BDD4 2D204000 */  daddu      $4, $2, $0
    /* 34BDD8 0044BDD8 2A38110C */  jal        func_0044e0a8
    /* 34BDDC 0044BDDC 2D284000 */   daddu     $5, $2, $0
    /* 34BDE0 0044BDE0 DBFF0010 */  b          .L0044BD50
    /* 34BDE4 0044BDE4 2D204002 */   daddu     $4, $18, $0
.size func_0044bcd8, 0x110
