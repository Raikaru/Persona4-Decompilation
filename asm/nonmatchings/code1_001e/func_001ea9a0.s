.section .text
.set noat
.set noreorder
glabel func_001ea9a0
    /* EA9A0 001EA9A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* EA9A4 001EA9A4 2000BFFF */  sd         $31, 0x20($29)
    /* EA9A8 001EA9A8 1000B17F */  sq         $17, 0x10($29)
    /* EA9AC 001EA9AC 0000B07F */  sq         $16, 0x0($29)
    /* EA9B0 001EA9B0 2D200000 */  daddu      $4, $0, $0
    /* EA9B4 001EA9B4 00730A0C */  jal        func_0029cc00
    /* EA9B8 001EA9B8 00000000 */   nop
    /* EA9BC 001EA9BC 2D884000 */  daddu      $17, $2, $0
    /* EA9C0 001EA9C0 01000424 */  addiu      $4, $0, 0x1
    /* EA9C4 001EA9C4 00730A0C */  jal        func_0029cc00
    /* EA9C8 001EA9C8 00000000 */   nop
    /* EA9CC 001EA9CC 2D804000 */  daddu      $16, $2, $0
    /* EA9D0 001EA9D0 30D8070C */  jal        func_001f60c0
    /* EA9D4 001EA9D4 00000000 */   nop
    /* EA9D8 001EA9D8 2D204000 */  daddu      $4, $2, $0
    /* EA9DC 001EA9DC 480050A4 */  sh         $16, 0x48($2)
    /* EA9E0 001EA9E0 01000524 */  addiu      $5, $0, 0x1
    /* EA9E4 001EA9E4 6451060C */  jal        func_00194590
    /* EA9E8 001EA9E8 00000000 */   nop
    /* EA9EC 001EA9EC 20000424 */  addiu      $4, $0, 0x20
    /* EA9F0 001EA9F0 2D282002 */  daddu      $5, $17, $0
    /* EA9F4 001EA9F4 0CD8070C */  jal        func_001f6030
    /* EA9F8 001EA9F8 00000000 */   nop
    /* EA9FC 001EA9FC 2D204000 */  daddu      $4, $2, $0
    /* EAA00 001EAA00 480050A4 */  sh         $16, 0x48($2)
    /* EAA04 001EAA04 01000524 */  addiu      $5, $0, 0x1
    /* EAA08 001EAA08 6451060C */  jal        func_00194590
    /* EAA0C 001EAA0C 00000000 */   nop
    /* EAA10 001EAA10 01000224 */  addiu      $2, $0, 0x1
    /* EAA14 001EAA14 2000BFDF */  ld         $31, 0x20($29)
    /* EAA18 001EAA18 1000B17B */  lq         $17, 0x10($29)
    /* EAA1C 001EAA1C 0000B07B */  lq         $16, 0x0($29)
    /* EAA20 001EAA20 3000BD27 */  addiu      $29, $29, 0x30
    /* EAA24 001EAA24 0800E003 */  jr         $31
    /* EAA28 001EAA28 00000000 */   nop
    /* EAA2C 001EAA2C 00000000 */  nop
.size func_001ea9a0, 0x90
