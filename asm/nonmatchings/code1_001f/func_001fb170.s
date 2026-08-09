.section .text
.set noat
.set noreorder
glabel func_001fb170
    /* FB170 001FB170 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* FB174 001FB174 0800412C */  sltiu      $1, $2, 0x8
    /* FB178 001FB178 1A002010 */  beqz       $1, .L001FB1E4
    /* FB17C 001FB17C 00000000 */   nop
    /* FB180 001FB180 7400033C */  lui        $3, %hi(jtbl_00747610)
    /* FB184 001FB184 10766324 */  addiu      $3, $3, %lo(jtbl_00747610)
    /* FB188 001FB188 80100200 */  sll        $2, $2, 2
    /* FB18C 001FB18C 21104300 */  addu       $2, $2, $3
    /* FB190 001FB190 0000428C */  lw         $2, 0x0($2)
    /* FB194 001FB194 08004000 */  jr         $2
    /* FB198 001FB198 00000000 */   nop
    /* FB19C 001FB19C 8A000224 */  addiu      $2, $0, 0x8A
    /* FB1A0 001FB1A0 11000010 */  b          .L001FB1E8
    /* FB1A4 001FB1A4 00000000 */   nop
    /* FB1A8 001FB1A8 8B000224 */  addiu      $2, $0, 0x8B
    /* FB1AC 001FB1AC 0E000010 */  b          .L001FB1E8
    /* FB1B0 001FB1B0 00000000 */   nop
    /* FB1B4 001FB1B4 8C000224 */  addiu      $2, $0, 0x8C
    /* FB1B8 001FB1B8 0B000010 */  b          .L001FB1E8
    /* FB1BC 001FB1BC 00000000 */   nop
    /* FB1C0 001FB1C0 8D000224 */  addiu      $2, $0, 0x8D
    /* FB1C4 001FB1C4 08000010 */  b          .L001FB1E8
    /* FB1C8 001FB1C8 00000000 */   nop
    /* FB1CC 001FB1CC 8E000224 */  addiu      $2, $0, 0x8E
    /* FB1D0 001FB1D0 05000010 */  b          .L001FB1E8
    /* FB1D4 001FB1D4 00000000 */   nop
    /* FB1D8 001FB1D8 98000224 */  addiu      $2, $0, 0x98
    /* FB1DC 001FB1DC 02000010 */  b          .L001FB1E8
    /* FB1E0 001FB1E0 00000000 */   nop
  .L001FB1E4:
    /* FB1E4 001FB1E4 2D100000 */  daddu      $2, $0, $0
  .L001FB1E8:
    /* FB1E8 001FB1E8 0800E003 */  jr         $31
    /* FB1EC 001FB1EC 00000000 */   nop
.size func_001fb170, 0x80
