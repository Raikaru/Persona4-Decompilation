.section .text
.set noat
.set noreorder
glabel func_001ef4a0
    /* EF4A0 001EF4A0 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* EF4A4 001EF4A4 80180200 */  sll        $3, $2, 2
    /* EF4A8 001EF4A8 BCB3828F */  lw         $2, -0x4C44($28)
    /* EF4AC 001EF4AC 21104300 */  addu       $2, $2, $3
    /* EF4B0 001EF4B0 00004290 */  lbu        $2, 0x0($2)
    /* EF4B4 001EF4B4 02004014 */  bnez       $2, .L001EF4C0
    /* EF4B8 001EF4B8 00000000 */   nop
    /* EF4BC 001EF4BC 01000224 */  addiu      $2, $0, 0x1
  .L001EF4C0:
    /* EF4C0 001EF4C0 0800E003 */  jr         $31
    /* EF4C4 001EF4C4 00000000 */   nop
    /* EF4C8 001EF4C8 00000000 */  nop
    /* EF4CC 001EF4CC 00000000 */  nop
.size func_001ef4a0, 0x30
