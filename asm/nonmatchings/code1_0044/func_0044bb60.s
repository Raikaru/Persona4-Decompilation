.section .text
.set noat
.set noreorder
glabel func_0044bb60
    /* 34BB60 0044BB60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 34BB64 0044BB64 2D280000 */  daddu      $5, $0, $0
    /* 34BB68 0044BB68 1000B2FF */  sd         $18, 0x10($29)
    /* 34BB6C 0044BB6C 0000B0FF */  sd         $16, 0x0($29)
    /* 34BB70 0044BB70 0800B1FF */  sd         $17, 0x8($29)
    /* 34BB74 0044BB74 1800BFFF */  sd         $31, 0x18($29)
    /* 34BB78 0044BB78 8239110C */  jal        func_0044e608
    /* 34BB7C 0044BB7C 2D908000 */   daddu     $18, $4, $0
    /* 34BB80 0044BB80 DF030524 */  addiu      $5, $0, 0x3DF
    /* 34BB84 0044BB84 2D204002 */  daddu      $4, $18, $0
    /* 34BB88 0044BB88 3C2D0500 */  dsll32     $5, $5, 20
    /* 34BB8C 0044BB8C 22004004 */  bltz       $2, .L0044BC18
    /* 34BB90 0044BB90 2D780000 */   daddu     $15, $0, $0
    /* 34BB94 0044BB94 5A38110C */  jal        func_0044e168
    /* 34BB98 0044BB98 00000000 */   nop
    /* 34BB9C 0044BB9C 0C3A110C */  jal        func_0044e830
    /* 34BBA0 0044BBA0 2D204000 */   daddu     $4, $2, $0
    /* 34BBA4 0044BBA4 3C880200 */  dsll32     $17, $2, 0
    /* 34BBA8 0044BBA8 3E881100 */  dsrl32     $17, $17, 0
    /* 34BBAC 0044BBAC 3C881100 */  dsll32     $17, $17, 0
    /* 34BBB0 0044BBB0 7A781100 */  dsrl       $15, $17, 1
    /* 34BBB4 0044BBB4 01002E32 */  andi       $14, $17, 0x1
    /* 34BBB8 0044BBB8 2570CF01 */  or         $14, $14, $15
    /* 34BBBC 0044BBBC 23002006 */  bltz       $17, .L0044BC4C
    /* 34BBC0 0044BBC0 2D202002 */   daddu     $4, $17, $0
    /* 34BBC4 0044BBC4 802E110C */  jal        func_0044ba00
    /* 34BBC8 0044BBC8 00000000 */   nop
    /* 34BBCC 0044BBCC 2D204002 */  daddu      $4, $18, $0
  .L0044BBD0:
    /* 34BBD0 0044BBD0 4038110C */  jal        func_0044e100
    /* 34BBD4 0044BBD4 2D284000 */   daddu     $5, $2, $0
    /* 34BBD8 0044BBD8 2D800000 */  daddu      $16, $0, $0
    /* 34BBDC 0044BBDC 2D904000 */  daddu      $18, $2, $0
    /* 34BBE0 0044BBE0 2D204000 */  daddu      $4, $2, $0
    /* 34BBE4 0044BBE4 8239110C */  jal        func_0044e608
    /* 34BBE8 0044BBE8 2D280002 */   daddu     $5, $16, $0
    /* 34BBEC 0044BBEC 2D284002 */  daddu      $5, $18, $0
    /* 34BBF0 0044BBF0 10004104 */  bgez       $2, .L0044BC34
    /* 34BBF4 0044BBF4 2D200002 */   daddu     $4, $16, $0
    /* 34BBF8 0044BBF8 4038110C */  jal        func_0044e100
    /* 34BBFC 0044BBFC 00000000 */   nop
    /* 34BC00 0044BC00 0C3A110C */  jal        func_0044e830
    /* 34BC04 0044BC04 2D204000 */   daddu     $4, $2, $0
    /* 34BC08 0044BC08 3C100200 */  dsll32     $2, $2, 0
    /* 34BC0C 0044BC0C 3E100200 */  dsrl32     $2, $2, 0
    /* 34BC10 0044BC10 2F882202 */  dsubu      $17, $17, $2
  .L0044BC14:
    /* 34BC14 0044BC14 2D782002 */  daddu      $15, $17, $0
  .L0044BC18:
    /* 34BC18 0044BC18 0000B0DF */  ld         $16, 0x0($29)
    /* 34BC1C 0044BC1C 2D10E001 */  daddu      $2, $15, $0
    /* 34BC20 0044BC20 0800B1DF */  ld         $17, 0x8($29)
    /* 34BC24 0044BC24 1000B2DF */  ld         $18, 0x10($29)
    /* 34BC28 0044BC28 1800BFDF */  ld         $31, 0x18($29)
    /* 34BC2C 0044BC2C 0800E003 */  jr         $31
    /* 34BC30 0044BC30 2000BD27 */   addiu     $29, $29, 0x20
  .L0044BC34:
    /* 34BC34 0044BC34 0C3A110C */  jal        func_0044e830
    /* 34BC38 0044BC38 2D204002 */   daddu     $4, $18, $0
    /* 34BC3C 0044BC3C 3C100200 */  dsll32     $2, $2, 0
    /* 34BC40 0044BC40 3E100200 */  dsrl32     $2, $2, 0
    /* 34BC44 0044BC44 F3FF0010 */  b          .L0044BC14
    /* 34BC48 0044BC48 2D882202 */   daddu     $17, $17, $2
  .L0044BC4C:
    /* 34BC4C 0044BC4C 802E110C */  jal        func_0044ba00
    /* 34BC50 0044BC50 2D20C001 */   daddu     $4, $14, $0
    /* 34BC54 0044BC54 2D204000 */  daddu      $4, $2, $0
    /* 34BC58 0044BC58 2A38110C */  jal        func_0044e0a8
    /* 34BC5C 0044BC5C 2D284000 */   daddu     $5, $2, $0
    /* 34BC60 0044BC60 DBFF0010 */  b          .L0044BBD0
    /* 34BC64 0044BC64 2D204002 */   daddu     $4, $18, $0
.size func_0044bb60, 0x108
