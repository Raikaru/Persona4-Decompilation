.section .text
.set noat
.set noreorder
glabel func_003ddf20
    /* 2DDF20 003DDF20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DDF24 003DDF24 2000BFFF */  sd         $31, 0x20($29)
    /* 2DDF28 003DDF28 1000B17F */  sq         $17, 0x10($29)
    /* 2DDF2C 003DDF2C 0000B07F */  sq         $16, 0x0($29)
    /* 2DDF30 003DDF30 2D888000 */  daddu      $17, $4, $0
    /* 2DDF34 003DDF34 5000828C */  lw         $2, 0x50($4)
    /* 2DDF38 003DDF38 54B7848F */  lw         $4, -0x48AC($28)
    /* 2DDF3C 003DDF3C 0886100C */  jal        func_00421820
    /* 2DDF40 003DDF40 28005024 */   addiu     $16, $2, 0x28
    /* 2DDF44 003DDF44 01000224 */  addiu      $2, $0, 0x1
    /* 2DDF48 003DDF48 380022AE */  sw         $2, 0x38($17)
    /* 2DDF4C 003DDF4C 0400028E */  lw         $2, 0x4($16)
    /* 2DDF50 003DDF50 09F84000 */  jalr       $2
    /* 2DDF54 003DDF54 2D202002 */   daddu     $4, $17, $0
    /* 2DDF58 003DDF58 0086100C */  jal        func_00421800
    /* 2DDF5C 003DDF5C 54B7848F */   lw        $4, -0x48AC($28)
    /* 2DDF60 003DDF60 2000BFDF */  ld         $31, 0x20($29)
    /* 2DDF64 003DDF64 2D100000 */  daddu      $2, $0, $0
    /* 2DDF68 003DDF68 1000B17B */  lq         $17, 0x10($29)
    /* 2DDF6C 003DDF6C 0000B07B */  lq         $16, 0x0($29)
    /* 2DDF70 003DDF70 0800E003 */  jr         $31
    /* 2DDF74 003DDF74 3000BD27 */   addiu     $29, $29, 0x30
    /* 2DDF78 003DDF78 00000000 */  nop
    /* 2DDF7C 003DDF7C 00000000 */  nop
.size func_003ddf20, 0x60
