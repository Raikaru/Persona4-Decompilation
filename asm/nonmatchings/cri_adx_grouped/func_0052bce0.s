.section .text
.set noat
.set noreorder
glabel func_0052bce0
    /* 42BCE0 0052BCE0 C2170500 */  srl        $2, $5, 31
    /* 42BCE4 0052BCE4 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42BCE8 0052BCE8 21104500 */  addu       $2, $2, $5
    /* 42BCEC 0052BCEC 0000B0FF */  sd         $16, 0x0($29)
    /* 42BCF0 0052BCF0 43100200 */  sra        $2, $2, 1
    /* 42BCF4 0052BCF4 2D808000 */  daddu      $16, $4, $0
    /* 42BCF8 0052BCF8 40100200 */  sll        $2, $2, 1
    /* 42BCFC 0052BCFC 0800B1FF */  sd         $17, 0x8($29)
    /* 42BD00 0052BD00 2D284000 */  daddu      $5, $2, $0
    /* 42BD04 0052BD04 04000426 */  addiu      $4, $16, 0x4
    /* 42BD08 0052BD08 1000BFFF */  sd         $31, 0x10($29)
    /* 42BD0C 0052BD0C 50AF140C */  jal        func_0052bd40
    /* 42BD10 0052BD10 43880200 */   sra       $17, $2, 1
    /* 42BD14 0052BD14 14000426 */  addiu      $4, $16, 0x14
    /* 42BD18 0052BD18 50AF140C */  jal        func_0052bd40
    /* 42BD1C 0052BD1C 2D282002 */   daddu     $5, $17, $0
    /* 42BD20 0052BD20 24000426 */  addiu      $4, $16, 0x24
    /* 42BD24 0052BD24 2D282002 */  daddu      $5, $17, $0
    /* 42BD28 0052BD28 0800B1DF */  ld         $17, 0x8($29)
    /* 42BD2C 0052BD2C 0000B0DF */  ld         $16, 0x0($29)
    /* 42BD30 0052BD30 1000BFDF */  ld         $31, 0x10($29)
    /* 42BD34 0052BD34 50AF1408 */  j          func_0052bd40
    /* 42BD38 0052BD38 2000BD27 */   addiu     $29, $29, 0x20
    /* 42BD3C 0052BD3C 00000000 */  nop
.size func_0052bce0, 0x60
