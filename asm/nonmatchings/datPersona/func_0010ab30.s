.section .text
.set noat
.set noreorder
glabel func_0010ab30
    /* AB30 0010AB30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* AB34 0010AB34 2000BFFF */  sd         $31, 0x20($29)
    /* AB38 0010AB38 1000B17F */  sq         $17, 0x10($29)
    /* AB3C 0010AB3C 0000B07F */  sq         $16, 0x0($29)
    /* AB40 0010AB40 2D800000 */  daddu      $16, $0, $0
    /* AB44 0010AB44 12000010 */  b          .L0010AB90
    /* AB48 0010AB48 00000000 */   nop
  .L0010AB4C:
    /* AB4C 0010AB4C FFFF0332 */  andi       $3, $16, 0xFFFF
    /* AB50 0010AB50 40100300 */  sll        $2, $3, 1
    /* AB54 0010AB54 21104300 */  addu       $2, $2, $3
    /* AB58 0010AB58 00190200 */  sll        $3, $2, 4
    /* AB5C 0010AB5C 7900023C */  lui        $2, %hi(D_007973A0)
    /* AB60 0010AB60 A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* AB64 0010AB64 21104300 */  addu       $2, $2, $3
    /* AB68 0010AB68 EC0B4294 */  lhu        $2, 0xBEC($2)
    /* AB6C 0010AB6C 01004230 */  andi       $2, $2, 0x1
    /* AB70 0010AB70 05004014 */  bnez       $2, .L0010AB88
    /* AB74 0010AB74 00000000 */   nop
    /* AB78 0010AB78 3C141000 */  dsll32     $2, $16, 16
    /* AB7C 0010AB7C 3F140200 */  dsra32     $2, $2, 16
    /* AB80 0010AB80 0B000010 */  b          .L0010ABB0
    /* AB84 0010AB84 00000000 */   nop
  .L0010AB88:
    /* AB88 0010AB88 01000226 */  addiu      $2, $16, 0x1
    /* AB8C 0010AB8C FFFF5030 */  andi       $16, $2, 0xFFFF
  .L0010AB90:
    /* AB90 0010AB90 FFFF1132 */  andi       $17, $16, 0xFFFF
    /* AB94 0010AB94 6C2D040C */  jal        func_0010b5b0
    /* AB98 0010AB98 00000000 */   nop
    /* AB9C 0010AB9C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* ABA0 0010ABA0 2A102202 */  slt        $2, $17, $2
    /* ABA4 0010ABA4 E9FF4014 */  bnez       $2, .L0010AB4C
    /* ABA8 0010ABA8 00000000 */   nop
    /* ABAC 0010ABAC FFFF0224 */  addiu      $2, $0, -0x1
  .L0010ABB0:
    /* ABB0 0010ABB0 2000BFDF */  ld         $31, 0x20($29)
    /* ABB4 0010ABB4 1000B17B */  lq         $17, 0x10($29)
    /* ABB8 0010ABB8 0000B07B */  lq         $16, 0x0($29)
    /* ABBC 0010ABBC 3000BD27 */  addiu      $29, $29, 0x30
    /* ABC0 0010ABC0 0800E003 */  jr         $31
    /* ABC4 0010ABC4 00000000 */   nop
    /* ABC8 0010ABC8 00000000 */  nop
    /* ABCC 0010ABCC 00000000 */  nop
.size func_0010ab30, 0xa0
