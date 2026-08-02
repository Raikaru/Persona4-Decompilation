.section .text
.set noat
.set noreorder
glabel func_0010f390
    /* F390 0010F390 2D280000 */  daddu      $5, $0, $0
    /* F394 0010F394 7900043C */  lui        $4, %hi(D_007973A0)
    /* F398 0010F398 A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* F39C 0010F39C 05000010 */  b          .L0010F3B4
    /* F3A0 0010F3A0 00000000 */   nop
  .L0010F3A4:
    /* F3A4 0010F3A4 80180500 */  sll        $3, $5, 2
    /* F3A8 0010F3A8 21188300 */  addu       $3, $4, $3
    /* F3AC 0010F3AC 384960AC */  sw         $0, 0x4938($3)
    /* F3B0 0010F3B0 0100A524 */  addiu      $5, $5, 0x1
  .L0010F3B4:
    /* F3B4 0010F3B4 5500A32C */  sltiu      $3, $5, 0x55
    /* F3B8 0010F3B8 FAFF6014 */  bnez       $3, .L0010F3A4
    /* F3BC 0010F3BC 00000000 */   nop
    /* F3C0 0010F3C0 0800E003 */  jr         $31
    /* F3C4 0010F3C4 00000000 */   nop
    /* F3C8 0010F3C8 00000000 */  nop
    /* F3CC 0010F3CC 00000000 */  nop
.size func_0010f390, 0x40
