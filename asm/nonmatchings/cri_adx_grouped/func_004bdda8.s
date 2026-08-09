.section .text
.set noat
.set noreorder
glabel func_004bdda8
    /* 3BDDA8 004BDDA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDDAC 004BDDAC 0C00A52C */  sltiu      $5, $5, 0xC
    /* 3BDDB0 004BDDB0 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDDB4 004BDDB4 2D808000 */  daddu      $16, $4, $0
    /* 3BDDB8 004BDDB8 05000016 */  bnez       $16, .L004BDDD0
    /* 3BDDBC 004BDDBC 0800BFFF */   sd        $31, 0x8($29)
    /* 3BDDC0 004BDDC0 7500043C */  lui        $4, %hi(D_00756980)
    /* 3BDDC4 004BDDC4 06000010 */  b          .L004BDDE0
    /* 3BDDC8 004BDDC8 80698424 */   addiu     $4, $4, %lo(D_00756980)
    /* 3BDDCC 004BDDCC 00000000 */  nop
  .L004BDDD0:
    /* 3BDDD0 004BDDD0 0700A010 */  beqz       $5, .L004BDDF0
    /* 3BDDD4 004BDDD4 00000000 */   nop
    /* 3BDDD8 004BDDD8 7500043C */  lui        $4, %hi(D_007569B8)
    /* 3BDDDC 004BDDDC B8698424 */  addiu      $4, $4, %lo(D_007569B8)
  .L004BDDE0:
    /* 3BDDE0 004BDDE0 A8F5120C */  jal        func_004bd6a0
    /* 3BDDE4 004BDDE4 00000000 */   nop
    /* 3BDDE8 004BDDE8 04000010 */  b          .L004BDDFC
    /* 3BDDEC 004BDDEC 2D100000 */   daddu     $2, $0, $0
  .L004BDDF0:
    /* 3BDDF0 004BDDF0 34F8120C */  jal        func_004be0d0
    /* 3BDDF4 004BDDF4 00000000 */   nop
    /* 3BDDF8 004BDDF8 2D100002 */  daddu      $2, $16, $0
  .L004BDDFC:
    /* 3BDDFC 004BDDFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDE00 004BDE00 0800BFDF */  ld         $31, 0x8($29)
    /* 3BDE04 004BDE04 0800E003 */  jr         $31
    /* 3BDE08 004BDE08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BDE0C 004BDE0C 00000000 */  nop
.size func_004bdda8, 0x68
