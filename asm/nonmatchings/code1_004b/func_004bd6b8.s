.section .text
.set noat
.set noreorder
glabel func_004bd6b8
    /* 3BD6B8 004BD6B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD6BC 004BD6BC 4400A52C */  sltiu      $5, $5, 0x44
    /* 3BD6C0 004BD6C0 0000B0FF */  sd         $16, 0x0($29)
    /* 3BD6C4 004BD6C4 2D808000 */  daddu      $16, $4, $0
    /* 3BD6C8 004BD6C8 05000016 */  bnez       $16, .L004BD6E0
    /* 3BD6CC 004BD6CC 0800BFFF */   sd        $31, 0x8($29)
    /* 3BD6D0 004BD6D0 7500043C */  lui        $4, %hi(D_007568C8)
    /* 3BD6D4 004BD6D4 06000010 */  b          .L004BD6F0
    /* 3BD6D8 004BD6D8 C8688424 */   addiu     $4, $4, %lo(D_007568C8)
    /* 3BD6DC 004BD6DC 00000000 */  nop
  .L004BD6E0:
    /* 3BD6E0 004BD6E0 0700A010 */  beqz       $5, .L004BD700
    /* 3BD6E4 004BD6E4 00000000 */   nop
    /* 3BD6E8 004BD6E8 7500043C */  lui        $4, %hi(D_00756900)
    /* 3BD6EC 004BD6EC 00698424 */  addiu      $4, $4, %lo(D_00756900)
  .L004BD6F0:
    /* 3BD6F0 004BD6F0 A8F5120C */  jal        func_004bd6a0
    /* 3BD6F4 004BD6F4 00000000 */   nop
    /* 3BD6F8 004BD6F8 04000010 */  b          .L004BD70C
    /* 3BD6FC 004BD6FC 2D100000 */   daddu     $2, $0, $0
  .L004BD700:
    /* 3BD700 004BD700 7EF6120C */  jal        func_004bd9f8
    /* 3BD704 004BD704 00000000 */   nop
    /* 3BD708 004BD708 2D100002 */  daddu      $2, $16, $0
  .L004BD70C:
    /* 3BD70C 004BD70C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BD710 004BD710 0800BFDF */  ld         $31, 0x8($29)
    /* 3BD714 004BD714 0800E003 */  jr         $31
    /* 3BD718 004BD718 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD71C 004BD71C 00000000 */  nop
.size func_004bd6b8, 0x68
