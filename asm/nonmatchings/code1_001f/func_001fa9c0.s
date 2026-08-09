.section .text
.set noat
.set noreorder
glabel func_001fa9c0
    /* FA9C0 001FA9C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FA9C4 001FA9C4 0000BFFF */  sd         $31, 0x0($29)
    /* FA9C8 001FA9C8 060C0424 */  addiu      $4, $0, 0xC06
    /* FA9CC 001FA9CC 2D280000 */  daddu      $5, $0, $0
    /* FA9D0 001FA9D0 1C51060C */  jal        func_00194470
    /* FA9D4 001FA9D4 00000000 */   nop
    /* FA9D8 001FA9D8 47004390 */  lbu        $3, 0x47($2)
    /* FA9DC 001FA9DC EE006330 */  andi       $3, $3, 0xEE
    /* FA9E0 001FA9E0 470043A0 */  sb         $3, 0x47($2)
    /* FA9E4 001FA9E4 2000033C */  lui        $3, %hi(func_001fa940)
    /* FA9E8 001FA9E8 40A96324 */  addiu      $3, $3, %lo(func_001fa940)
    /* FA9EC 001FA9EC 6C0043AC */  sw         $3, 0x6C($2)
    /* FA9F0 001FA9F0 0000BFDF */  ld         $31, 0x0($29)
    /* FA9F4 001FA9F4 1000BD27 */  addiu      $29, $29, 0x10
    /* FA9F8 001FA9F8 0800E003 */  jr         $31
    /* FA9FC 001FA9FC 00000000 */   nop
.size func_001fa9c0, 0x40
