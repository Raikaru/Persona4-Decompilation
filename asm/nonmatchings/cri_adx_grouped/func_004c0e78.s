.section .text
.set noat
.set noreorder
glabel func_004c0e78
    /* 3C0E78 004C0E78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C0E7C 004C0E7C 6000A52C */  sltiu      $5, $5, 0x60
    /* 3C0E80 004C0E80 0000B0FF */  sd         $16, 0x0($29)
    /* 3C0E84 004C0E84 2D808000 */  daddu      $16, $4, $0
    /* 3C0E88 004C0E88 05000016 */  bnez       $16, .L004C0EA0
    /* 3C0E8C 004C0E8C 0800BFFF */   sd        $31, 0x8($29)
    /* 3C0E90 004C0E90 7500043C */  lui        $4, %hi(D_00757498)
    /* 3C0E94 004C0E94 06000010 */  b          .L004C0EB0
    /* 3C0E98 004C0E98 98748424 */   addiu     $4, $4, %lo(D_00757498)
    /* 3C0E9C 004C0E9C 00000000 */  nop
  .L004C0EA0:
    /* 3C0EA0 004C0EA0 0700A010 */  beqz       $5, .L004C0EC0
    /* 3C0EA4 004C0EA4 00000000 */   nop
    /* 3C0EA8 004C0EA8 7500043C */  lui        $4, %hi(D_007574D0)
    /* 3C0EAC 004C0EAC D0748424 */  addiu      $4, $4, %lo(D_007574D0)
  .L004C0EB0:
    /* 3C0EB0 004C0EB0 A8F5120C */  jal        func_004bd6a0
    /* 3C0EB4 004C0EB4 00000000 */   nop
    /* 3C0EB8 004C0EB8 04000010 */  b          .L004C0ECC
    /* 3C0EBC 004C0EBC 2D100000 */   daddu     $2, $0, $0
  .L004C0EC0:
    /* 3C0EC0 004C0EC0 9204130C */  jal        func_004c1248
    /* 3C0EC4 004C0EC4 00000000 */   nop
    /* 3C0EC8 004C0EC8 2D100002 */  daddu      $2, $16, $0
  .L004C0ECC:
    /* 3C0ECC 004C0ECC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C0ED0 004C0ED0 0800BFDF */  ld         $31, 0x8($29)
    /* 3C0ED4 004C0ED4 0800E003 */  jr         $31
    /* 3C0ED8 004C0ED8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C0EDC 004C0EDC 00000000 */  nop
.size func_004c0e78, 0x68
