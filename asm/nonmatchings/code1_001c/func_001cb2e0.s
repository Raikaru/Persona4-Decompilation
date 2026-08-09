.section .text
.set noat
.set noreorder
glabel func_001cb2e0
    /* CB2E0 001CB2E0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CB2E4 001CB2E4 2000BFFF */  sd         $31, 0x20($29)
    /* CB2E8 001CB2E8 1000B17F */  sq         $17, 0x10($29)
    /* CB2EC 001CB2EC 0000B07F */  sq         $16, 0x0($29)
    /* CB2F0 001CB2F0 2D888000 */  daddu      $17, $4, $0
    /* CB2F4 001CB2F4 E000828C */  lw         $2, 0xE0($4)
    /* CB2F8 001CB2F8 3000428C */  lw         $2, 0x30($2)
    /* CB2FC 001CB2FC A4005094 */  lhu        $16, 0xA4($2)
    /* CB300 001CB300 2D200000 */  daddu      $4, $0, $0
    /* CB304 001CB304 14F4120C */  jal        func_004bd050
    /* CB308 001CB308 00000000 */   nop
    /* CB30C 001CB30C 01004330 */  andi       $3, $2, 0x1
    /* CB310 001CB310 00110300 */  sll        $2, $3, 4
    /* CB314 001CB314 23104300 */  subu       $2, $2, $3
    /* CB318 001CB318 80100200 */  sll        $2, $2, 2
    /* CB31C 001CB31C 21104300 */  addu       $2, $2, $3
    /* CB320 001CB320 80200200 */  sll        $4, $2, 2
    /* CB324 001CB324 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* CB328 001CB328 00110300 */  sll        $2, $3, 4
    /* CB32C 001CB32C 23104300 */  subu       $2, $2, $3
    /* CB330 001CB330 80100200 */  sll        $2, $2, 2
    /* CB334 001CB334 21104300 */  addu       $2, $2, $3
    /* CB338 001CB338 C0180200 */  sll        $3, $2, 3
    /* CB33C 001CB33C 5F00023C */  lui        $2, %hi(D_005F7CA0)
    /* CB340 001CB340 A07C4224 */  addiu      $2, $2, %lo(D_005F7CA0)
    /* CB344 001CB344 21104300 */  addu       $2, $2, $3
    /* CB348 001CB348 21288200 */  addu       $5, $4, $2
    /* CB34C 001CB34C 2D202002 */  daddu      $4, $17, $0
    /* CB350 001CB350 02000624 */  addiu      $6, $0, 0x2
    /* CB354 001CB354 60F7060C */  jal        func_001bdd80
    /* CB358 001CB358 00000000 */   nop
    /* CB35C 001CB35C 2000BFDF */  ld         $31, 0x20($29)
    /* CB360 001CB360 1000B17B */  lq         $17, 0x10($29)
    /* CB364 001CB364 0000B07B */  lq         $16, 0x0($29)
    /* CB368 001CB368 3000BD27 */  addiu      $29, $29, 0x30
    /* CB36C 001CB36C 0800E003 */  jr         $31
    /* CB370 001CB370 00000000 */   nop
    /* CB374 001CB374 00000000 */  nop
    /* CB378 001CB378 00000000 */  nop
    /* CB37C 001CB37C 00000000 */  nop
.size func_001cb2e0, 0xa0
