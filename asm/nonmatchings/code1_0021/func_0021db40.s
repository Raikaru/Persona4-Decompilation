.section .text
.set noat
.set noreorder
glabel func_0021db40
    /* 11DB40 0021DB40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 11DB44 0021DB44 0000BFFF */  sd         $31, 0x0($29)
    /* 11DB48 0021DB48 5849110C */  jal        func_00452560
    /* 11DB4C 0021DB4C 00000000 */   nop
    /* 11DB50 0021DB50 3809438C */  lw         $3, 0x938($2)
    /* 11DB54 0021DB54 04006010 */  beqz       $3, .L0021DB68
    /* 11DB58 0021DB58 00000000 */   nop
    /* 11DB5C 0021DB5C 2D100000 */  daddu      $2, $0, $0
    /* 11DB60 0021DB60 09000010 */  b          .L0021DB88
    /* 11DB64 0021DB64 00000000 */   nop
  .L0021DB68:
    /* 11DB68 0021DB68 3C09448C */  lw         $4, 0x93C($2)
    /* 11DB6C 0021DB6C 05008010 */  beqz       $4, .L0021DB84
    /* 11DB70 0021DB70 00000000 */   nop
    /* 11DB74 0021DB74 5086080C */  jal        func_00221940
    /* 11DB78 0021DB78 00000000 */   nop
    /* 11DB7C 0021DB7C 02000010 */  b          .L0021DB88
    /* 11DB80 0021DB80 00000000 */   nop
  .L0021DB84:
    /* 11DB84 0021DB84 2D100000 */  daddu      $2, $0, $0
  .L0021DB88:
    /* 11DB88 0021DB88 0000BFDF */  ld         $31, 0x0($29)
    /* 11DB8C 0021DB8C 1000BD27 */  addiu      $29, $29, 0x10
    /* 11DB90 0021DB90 0800E003 */  jr         $31
    /* 11DB94 0021DB94 00000000 */   nop
    /* 11DB98 0021DB98 00000000 */  nop
    /* 11DB9C 0021DB9C 00000000 */  nop
.size func_0021db40, 0x60
