.section .text
.set noat
.set noreorder
glabel func_004d2ed8
    /* 3D2ED8 004D2ED8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2EDC 004D2EDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2EE0 004D2EE0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2EE4 004D2EE4 D888130C */  jal        func_004e2360
    /* 3D2EE8 004D2EE8 2D80A000 */   daddu     $16, $5, $0
    /* 3D2EEC 004D2EEC 2D284000 */  daddu      $5, $2, $0
    /* 3D2EF0 004D2EF0 01000224 */  addiu      $2, $0, 0x1
    /* 3D2EF4 004D2EF4 FF07A624 */  addiu      $6, $5, 0x7FF
    /* 3D2EF8 004D2EF8 0000A428 */  slti       $4, $5, 0x0
    /* 3D2EFC 004D2EFC 2D18A000 */  daddu      $3, $5, $0
    /* 3D2F00 004D2F00 0B18C400 */  movn       $3, $6, $4
    /* 3D2F04 004D2F04 C31A0300 */  sra        $3, $3, 11
    /* 3D2F08 004D2F08 C0220300 */  sll        $4, $3, 11
    /* 3D2F0C 004D2F0C 01006624 */  addiu      $6, $3, 0x1
    /* 3D2F10 004D2F10 2328A400 */  subu       $5, $5, $4
    /* 3D2F14 004D2F14 0200A018 */  blez       $5, .L004D2F20
    /* 3D2F18 004D2F18 000003AE */   sw        $3, 0x0($16)
    /* 3D2F1C 004D2F1C 000006AE */  sw         $6, 0x0($16)
  .L004D2F20:
    /* 3D2F20 004D2F20 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2F24 004D2F24 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2F28 004D2F28 0800E003 */  jr         $31
    /* 3D2F2C 004D2F2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2ed8, 0x58
