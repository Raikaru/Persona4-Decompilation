.section .text
.set noat
.set noreorder
glabel func_001ea390
    /* EA390 001EA390 D0FFBD27 */  addiu      $29, $29, -0x30
    /* EA394 001EA394 2000BFFF */  sd         $31, 0x20($29)
    /* EA398 001EA398 1000B17F */  sq         $17, 0x10($29)
    /* EA39C 001EA39C 0000B07F */  sq         $16, 0x0($29)
    /* EA3A0 001EA3A0 14740A0C */  jal        func_0029d050
    /* EA3A4 001EA3A4 00000000 */   nop
    /* EA3A8 001EA3A8 2D884000 */  daddu      $17, $2, $0
    /* EA3AC 001EA3AC 2D200000 */  daddu      $4, $0, $0
    /* EA3B0 001EA3B0 00730A0C */  jal        func_0029cc00
    /* EA3B4 001EA3B4 00000000 */   nop
    /* EA3B8 001EA3B8 2D804000 */  daddu      $16, $2, $0
    /* EA3BC 001EA3BC 80101000 */  sll        $2, $16, 2
    /* EA3C0 001EA3C0 21105000 */  addu       $2, $2, $16
    /* EA3C4 001EA3C4 C0180200 */  sll        $3, $2, 3
    /* EA3C8 001EA3C8 B8B3828F */  lw         $2, -0x4C48($28)
    /* EA3CC 001EA3CC 21104300 */  addu       $2, $2, $3
    /* EA3D0 001EA3D0 00004290 */  lbu        $2, 0x0($2)
    /* EA3D4 001EA3D4 02004230 */  andi       $2, $2, 0x2
    /* EA3D8 001EA3D8 06004014 */  bnez       $2, .L001EA3F4
    /* EA3DC 001EA3DC 00000000 */   nop
    /* EA3E0 001EA3E0 6100043C */  lui        $4, %hi(D_00609E30)
    /* EA3E4 001EA3E4 309E8424 */  addiu      $4, $4, %lo(D_00609E30)
    /* EA3E8 001EA3E8 4F160524 */  addiu      $5, $0, 0x164F
    /* EA3EC 001EA3EC CCB5110C */  jal        func_0046d730
    /* EA3F0 001EA3F0 00000000 */   nop
  .L001EA3F4:
    /* EA3F4 001EA3F4 01000224 */  addiu      $2, $0, 0x1
    /* EA3F8 001EA3F8 6C0022A6 */  sh         $2, 0x6C($17)
    /* EA3FC 001EA3FC 6E0030A6 */  sh         $16, 0x6E($17)
    /* EA400 001EA400 2000BFDF */  ld         $31, 0x20($29)
    /* EA404 001EA404 1000B17B */  lq         $17, 0x10($29)
    /* EA408 001EA408 0000B07B */  lq         $16, 0x0($29)
    /* EA40C 001EA40C 3000BD27 */  addiu      $29, $29, 0x30
    /* EA410 001EA410 0800E003 */  jr         $31
    /* EA414 001EA414 00000000 */   nop
    /* EA418 001EA418 00000000 */  nop
    /* EA41C 001EA41C 00000000 */  nop
.size func_001ea390, 0x90
