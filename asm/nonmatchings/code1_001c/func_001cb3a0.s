.section .text
.set noat
.set noreorder
glabel func_001cb3a0
    /* CB3A0 001CB3A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CB3A4 001CB3A4 2000BFFF */  sd         $31, 0x20($29)
    /* CB3A8 001CB3A8 1000B17F */  sq         $17, 0x10($29)
    /* CB3AC 001CB3AC 0000B07F */  sq         $16, 0x0($29)
    /* CB3B0 001CB3B0 2D888000 */  daddu      $17, $4, $0
    /* CB3B4 001CB3B4 E000828C */  lw         $2, 0xE0($4)
    /* CB3B8 001CB3B8 3000448C */  lw         $4, 0x30($2)
    /* CB3BC 001CB3BC A4009094 */  lhu        $16, 0xA4($4)
    /* CB3C0 001CB3C0 FCDC060C */  jal        func_001b73f0
    /* CB3C4 001CB3C4 00000000 */   nop
    /* CB3C8 001CB3C8 2D200000 */  daddu      $4, $0, $0
    /* CB3CC 001CB3CC 14F4120C */  jal        func_004bd050
    /* CB3D0 001CB3D0 00000000 */   nop
    /* CB3D4 001CB3D4 01004330 */  andi       $3, $2, 0x1
    /* CB3D8 001CB3D8 00110300 */  sll        $2, $3, 4
    /* CB3DC 001CB3DC 23104300 */  subu       $2, $2, $3
    /* CB3E0 001CB3E0 80100200 */  sll        $2, $2, 2
    /* CB3E4 001CB3E4 21104300 */  addu       $2, $2, $3
    /* CB3E8 001CB3E8 80200200 */  sll        $4, $2, 2
    /* CB3EC 001CB3EC FFFF0232 */  andi       $2, $16, 0xFFFF
    /* CB3F0 001CB3F0 FEFF4324 */  addiu      $3, $2, -0x2
    /* CB3F4 001CB3F4 00110300 */  sll        $2, $3, 4
    /* CB3F8 001CB3F8 23104300 */  subu       $2, $2, $3
    /* CB3FC 001CB3FC 80100200 */  sll        $2, $2, 2
    /* CB400 001CB400 21104300 */  addu       $2, $2, $3
    /* CB404 001CB404 C0180200 */  sll        $3, $2, 3
    /* CB408 001CB408 6000023C */  lui        $2, %hi(D_005F91A0)
    /* CB40C 001CB40C A0914224 */  addiu      $2, $2, %lo(D_005F91A0)
    /* CB410 001CB410 21104300 */  addu       $2, $2, $3
    /* CB414 001CB414 21288200 */  addu       $5, $4, $2
    /* CB418 001CB418 2D202002 */  daddu      $4, $17, $0
    /* CB41C 001CB41C 02000624 */  addiu      $6, $0, 0x2
    /* CB420 001CB420 60F7060C */  jal        func_001bdd80
    /* CB424 001CB424 00000000 */   nop
    /* CB428 001CB428 2000BFDF */  ld         $31, 0x20($29)
    /* CB42C 001CB42C 1000B17B */  lq         $17, 0x10($29)
    /* CB430 001CB430 0000B07B */  lq         $16, 0x0($29)
    /* CB434 001CB434 3000BD27 */  addiu      $29, $29, 0x30
    /* CB438 001CB438 0800E003 */  jr         $31
    /* CB43C 001CB43C 00000000 */   nop
.size func_001cb3a0, 0xa0
