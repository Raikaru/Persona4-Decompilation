.section .text
.set noat
.set noreorder
glabel func_0052bd90
    /* 42BD90 0052BD90 C2170600 */  srl        $2, $6, 31
    /* 42BD94 0052BD94 C21F0500 */  srl        $3, $5, 31
    /* 42BD98 0052BD98 21104600 */  addu       $2, $2, $6
    /* 42BD9C 0052BD9C 21186500 */  addu       $3, $3, $5
    /* 42BDA0 0052BDA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42BDA4 0052BDA4 43100200 */  sra        $2, $2, 1
    /* 42BDA8 0052BDA8 43180300 */  sra        $3, $3, 1
    /* 42BDAC 0052BDAC 40100200 */  sll        $2, $2, 1
    /* 42BDB0 0052BDB0 40180300 */  sll        $3, $3, 1
    /* 42BDB4 0052BDB4 0000B0FF */  sd         $16, 0x0($29)
    /* 42BDB8 0052BDB8 2D808000 */  daddu      $16, $4, $0
    /* 42BDBC 0052BDBC 0800B1FF */  sd         $17, 0x8($29)
    /* 42BDC0 0052BDC0 1000B2FF */  sd         $18, 0x10($29)
    /* 42BDC4 0052BDC4 43900300 */  sra        $18, $3, 1
    /* 42BDC8 0052BDC8 43880200 */  sra        $17, $2, 1
    /* 42BDCC 0052BDCC 2D284000 */  daddu      $5, $2, $0
    /* 42BDD0 0052BDD0 2D306000 */  daddu      $6, $3, $0
    /* 42BDD4 0052BDD4 1800BFFF */  sd         $31, 0x18($29)
    /* 42BDD8 0052BDD8 86AF140C */  jal        func_0052be18
    /* 42BDDC 0052BDDC 04000426 */   addiu     $4, $16, 0x4
    /* 42BDE0 0052BDE0 14000426 */  addiu      $4, $16, 0x14
    /* 42BDE4 0052BDE4 2D282002 */  daddu      $5, $17, $0
    /* 42BDE8 0052BDE8 86AF140C */  jal        func_0052be18
    /* 42BDEC 0052BDEC 2D304002 */   daddu     $6, $18, $0
    /* 42BDF0 0052BDF0 24000426 */  addiu      $4, $16, 0x24
    /* 42BDF4 0052BDF4 2D282002 */  daddu      $5, $17, $0
    /* 42BDF8 0052BDF8 0800B1DF */  ld         $17, 0x8($29)
    /* 42BDFC 0052BDFC 2D304002 */  daddu      $6, $18, $0
    /* 42BE00 0052BE00 1000B2DF */  ld         $18, 0x10($29)
    /* 42BE04 0052BE04 0000B0DF */  ld         $16, 0x0($29)
    /* 42BE08 0052BE08 1800BFDF */  ld         $31, 0x18($29)
    /* 42BE0C 0052BE0C 86AF1408 */  j          func_0052be18
    /* 42BE10 0052BE10 2000BD27 */   addiu     $29, $29, 0x20
    /* 42BE14 0052BE14 00000000 */  nop
.size func_0052bd90, 0x88
