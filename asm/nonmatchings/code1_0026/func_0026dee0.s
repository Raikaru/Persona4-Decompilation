.section .text
.set noat
.set noreorder
glabel func_0026dee0
    /* 16DEE0 0026DEE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 16DEE4 0026DEE4 1000BFFF */  sd         $31, 0x10($29)
    /* 16DEE8 0026DEE8 0000B07F */  sq         $16, 0x0($29)
    /* 16DEEC 0026DEEC 06000424 */  addiu      $4, $0, 0x6
    /* 16DEF0 0026DEF0 AC14050C */  jal        func_001452b0
    /* 16DEF4 0026DEF4 00000000 */   nop
    /* 16DEF8 0026DEF8 2D804000 */  daddu      $16, $2, $0
    /* 16DEFC 0026DEFC 2D200002 */  daddu      $4, $16, $0
    /* 16DF00 0026DF00 58B7090C */  jal        func_0026dd60
    /* 16DF04 0026DF04 00000000 */   nop
    /* 16DF08 0026DF08 15000010 */  b          .L0026DF60
    /* 16DF0C 0026DF0C 00000000 */   nop
  .L0026DF10:
    /* 16DF10 0026DF10 2800028E */  lw         $2, 0x28($16)
    /* 16DF14 0026DF14 02004230 */  andi       $2, $2, 0x2
    /* 16DF18 0026DF18 10004010 */  beqz       $2, .L0026DF5C
    /* 16DF1C 0026DF1C 00000000 */   nop
    /* 16DF20 0026DF20 4401058E */  lw         $5, 0x144($16)
    /* 16DF24 0026DF24 0D00A010 */  beqz       $5, .L0026DF5C
    /* 16DF28 0026DF28 00000000 */   nop
    /* 16DF2C 0026DF2C 40010382 */  lb         $3, 0x140($16)
    /* 16DF30 0026DF30 01000224 */  addiu      $2, $0, 0x1
    /* 16DF34 0026DF34 05006210 */  beq        $3, $2, .L0026DF4C
    /* 16DF38 0026DF38 00000000 */   nop
    /* 16DF3C 0026DF3C 07006010 */  beqz       $3, .L0026DF5C
    /* 16DF40 0026DF40 00000000 */   nop
    /* 16DF44 0026DF44 05000010 */  b          .L0026DF5C
    /* 16DF48 0026DF48 00000000 */   nop
  .L0026DF4C:
    /* 16DF4C 0026DF4C 5E00043C */  lui        $4, %hi(D_005DC824)
    /* 16DF50 0026DF50 24C88424 */  addiu      $4, $4, %lo(D_005DC824)
    /* 16DF54 0026DF54 74C4120C */  jal        func_004b11d0
    /* 16DF58 0026DF58 00000000 */   nop
  .L0026DF5C:
    /* 16DF5C 0026DF5C 3801108E */  lw         $16, 0x138($16)
  .L0026DF60:
    /* 16DF60 0026DF60 EBFF0016 */  bnez       $16, .L0026DF10
    /* 16DF64 0026DF64 00000000 */   nop
    /* 16DF68 0026DF68 2D100000 */  daddu      $2, $0, $0
    /* 16DF6C 0026DF6C 1000BFDF */  ld         $31, 0x10($29)
    /* 16DF70 0026DF70 0000B07B */  lq         $16, 0x0($29)
    /* 16DF74 0026DF74 2000BD27 */  addiu      $29, $29, 0x20
    /* 16DF78 0026DF78 0800E003 */  jr         $31
    /* 16DF7C 0026DF7C 00000000 */   nop
.size func_0026dee0, 0xa0
