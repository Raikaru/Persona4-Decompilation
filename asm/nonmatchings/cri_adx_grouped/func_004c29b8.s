.section .text
.set noat
.set noreorder
glabel func_004c29b8
    /* 3C29B8 004C29B8 7500053C */  lui        $5, %hi(D_00757598)
    /* 3C29BC 004C29BC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C29C0 004C29C0 04000624 */  addiu      $6, $0, 0x4
    /* 3C29C4 004C29C4 9875A524 */  addiu      $5, $5, %lo(D_00757598)
    /* 3C29C8 004C29C8 0000B0FF */  sd         $16, 0x0($29)
    /* 3C29CC 004C29CC 0800BFFF */  sd         $31, 0x8($29)
    /* 3C29D0 004C29D0 DEFD100C */  jal        func_0043f778
    /* 3C29D4 004C29D4 2D808000 */   daddu     $16, $4, $0
    /* 3C29D8 004C29D8 7500053C */  lui        $5, %hi(D_007575A0)
    /* 3C29DC 004C29DC 2D200002 */  daddu      $4, $16, $0
    /* 3C29E0 004C29E0 A075A524 */  addiu      $5, $5, %lo(D_007575A0)
    /* 3C29E4 004C29E4 05004010 */  beqz       $2, .L004C29FC
    /* 3C29E8 004C29E8 04000624 */   addiu     $6, $0, 0x4
    /* 3C29EC 004C29EC DEFD100C */  jal        func_0043f778
    /* 3C29F0 004C29F0 00000000 */   nop
    /* 3C29F4 004C29F4 02004054 */  bnel       $2, $0, .L004C2A00
    /* 3C29F8 004C29F8 2D100000 */   daddu     $2, $0, $0
  .L004C29FC:
    /* 3C29FC 004C29FC 01000224 */  addiu      $2, $0, 0x1
  .L004C2A00:
    /* 3C2A00 004C2A00 0000B0DF */  ld         $16, 0x0($29)
    /* 3C2A04 004C2A04 0800BFDF */  ld         $31, 0x8($29)
    /* 3C2A08 004C2A08 0800E003 */  jr         $31
    /* 3C2A0C 004C2A0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c29b8, 0x58
