.section .text
.set noat
.set noreorder
glabel func_001fa370
    /* FA370 001FA370 D0FFBD27 */  addiu      $29, $29, -0x30
    /* FA374 001FA374 2000BFFF */  sd         $31, 0x20($29)
    /* FA378 001FA378 1000B17F */  sq         $17, 0x10($29)
    /* FA37C 001FA37C 0000B07F */  sq         $16, 0x0($29)
    /* FA380 001FA380 2D800000 */  daddu      $16, $0, $0
    /* FA384 001FA384 15000010 */  b          .L001FA3DC
    /* FA388 001FA388 00000000 */   nop
  .L001FA38C:
    /* FA38C 001FA38C ACB3848F */  lw         $4, -0x4C54($28)
    /* FA390 001FA390 80881000 */  sll        $17, $16, 2
    /* FA394 001FA394 21189100 */  addu       $3, $4, $17
    /* FA398 001FA398 6C0B628C */  lw         $2, 0xB6C($3)
    /* FA39C 001FA39C 06004010 */  beqz       $2, .L001FA3B8
    /* FA3A0 001FA3A0 00000000 */   nop
    /* FA3A4 001FA3A4 4C0B828C */  lw         $2, 0xB4C($4)
    /* FA3A8 001FA3A8 01004234 */  ori        $2, $2, 0x1
    /* FA3AC 001FA3AC 4C0B82AC */  sw         $2, 0xB4C($4)
    /* FA3B0 001FA3B0 09000010 */  b          .L001FA3D8
    /* FA3B4 001FA3B4 00000000 */   nop
  .L001FA3B8:
    /* FA3B8 001FA3B8 5C0B648C */  lw         $4, 0xB5C($3)
    /* FA3BC 001FA3BC 06008010 */  beqz       $4, .L001FA3D8
    /* FA3C0 001FA3C0 00000000 */   nop
    /* FA3C4 001FA3C4 C816120C */  jal        func_00485b20
    /* FA3C8 001FA3C8 00000000 */   nop
    /* FA3CC 001FA3CC ACB3828F */  lw         $2, -0x4C54($28)
    /* FA3D0 001FA3D0 21105100 */  addu       $2, $2, $17
    /* FA3D4 001FA3D4 5C0B40AC */  sw         $0, 0xB5C($2)
  .L001FA3D8:
    /* FA3D8 001FA3D8 01001026 */  addiu      $16, $16, 0x1
  .L001FA3DC:
    /* FA3DC 001FA3DC 0400022A */  slti       $2, $16, 0x4
    /* FA3E0 001FA3E0 EAFF4014 */  bnez       $2, .L001FA38C
    /* FA3E4 001FA3E4 00000000 */   nop
    /* FA3E8 001FA3E8 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA3EC 001FA3EC 580B628C */  lw         $2, 0xB58($3)
    /* FA3F0 001FA3F0 06004010 */  beqz       $2, .L001FA40C
    /* FA3F4 001FA3F4 00000000 */   nop
    /* FA3F8 001FA3F8 4C0B628C */  lw         $2, 0xB4C($3)
    /* FA3FC 001FA3FC 01004234 */  ori        $2, $2, 0x1
    /* FA400 001FA400 4C0B62AC */  sw         $2, 0xB4C($3)
    /* FA404 001FA404 08000010 */  b          .L001FA428
    /* FA408 001FA408 00000000 */   nop
  .L001FA40C:
    /* FA40C 001FA40C 540B648C */  lw         $4, 0xB54($3)
    /* FA410 001FA410 05008010 */  beqz       $4, .L001FA428
    /* FA414 001FA414 00000000 */   nop
    /* FA418 001FA418 C816120C */  jal        func_00485b20
    /* FA41C 001FA41C 00000000 */   nop
    /* FA420 001FA420 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA424 001FA424 540B40AC */  sw         $0, 0xB54($2)
  .L001FA428:
    /* FA428 001FA428 01000224 */  addiu      $2, $0, 0x1
    /* FA42C 001FA42C 2000BFDF */  ld         $31, 0x20($29)
    /* FA430 001FA430 1000B17B */  lq         $17, 0x10($29)
    /* FA434 001FA434 0000B07B */  lq         $16, 0x0($29)
    /* FA438 001FA438 3000BD27 */  addiu      $29, $29, 0x30
    /* FA43C 001FA43C 0800E003 */  jr         $31
    /* FA440 001FA440 00000000 */   nop
    /* FA444 001FA444 00000000 */  nop
    /* FA448 001FA448 00000000 */  nop
    /* FA44C 001FA44C 00000000 */  nop
.size func_001fa370, 0xe0
