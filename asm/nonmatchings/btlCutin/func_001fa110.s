.section .text
.set noat
.set noreorder
glabel func_001fa110
    /* FA110 001FA110 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FA114 001FA114 2000BFFF */  sd         $31, 0x20($29)
    /* FA118 001FA118 1000B17F */  sq         $17, 0x10($29)
    /* FA11C 001FA11C 0000B07F */  sq         $16, 0x0($29)
    /* FA120 001FA120 2D888000 */  daddu      $17, $4, $0
    /* FA124 001FA124 000C0424 */  addiu      $4, $0, 0xC00
    /* FA128 001FA128 0A000524 */  addiu      $5, $0, 0xA
    /* FA12C 001FA12C 1C51060C */  jal        func_00194470
    /* FA130 001FA130 00000000 */   nop
    /* FA134 001FA134 2D804000 */  daddu      $16, $2, $0
    /* FA138 001FA138 47004390 */  lbu        $3, 0x47($2)
    /* FA13C 001FA13C EE006330 */  andi       $3, $3, 0xEE
    /* FA140 001FA140 470043A0 */  sb         $3, 0x47($2)
    /* FA144 001FA144 2000033C */  lui        $3, %hi(func_001f9cf0)
    /* FA148 001FA148 F09C6324 */  addiu      $3, $3, %lo(func_001f9cf0)
    /* FA14C 001FA14C 680043AC */  sw         $3, 0x68($2)
    /* FA150 001FA150 2000033C */  lui        $3, %hi(func_001f9fa0)
    /* FA154 001FA154 A09F6324 */  addiu      $3, $3, %lo(func_001f9fa0)
    /* FA158 001FA158 6C0043AC */  sw         $3, 0x6C($2)
    /* FA15C 001FA15C 7800448C */  lw         $4, 0x78($2)
    /* FA160 001FA160 2D282002 */  daddu      $5, $17, $0
    /* FA164 001FA164 0A000624 */  addiu      $6, $0, 0xA
    /* FA168 001FA168 04FE100C */  jal        func_0043f810
    /* FA16C 001FA16C 00000000 */   nop
    /* FA170 001FA170 2D100002 */  daddu      $2, $16, $0
    /* FA174 001FA174 2000BFDF */  ld         $31, 0x20($29)
    /* FA178 001FA178 1000B17B */  lq         $17, 0x10($29)
    /* FA17C 001FA17C 0000B07B */  lq         $16, 0x0($29)
    /* FA180 001FA180 3000BD27 */  addiu      $29, $29, 0x30
    /* FA184 001FA184 0800E003 */  jr         $31
    /* FA188 001FA188 00000000 */   nop
    /* FA18C 001FA18C 00000000 */  nop
.size func_001fa110, 0x80
