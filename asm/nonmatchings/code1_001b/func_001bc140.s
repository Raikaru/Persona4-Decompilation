.section .text
.set noat
.set noreorder
glabel func_001bc140
    /* BC140 001BC140 E0FFBD27 */  addiu      $29, $29, -0x20
    /* BC144 001BC144 1000BFFF */  sd         $31, 0x10($29)
    /* BC148 001BC148 0000B07F */  sq         $16, 0x0($29)
    /* BC14C 001BC14C E000908C */  lw         $16, 0xE0($4)
    /* BC150 001BC150 04000016 */  bnez       $16, .L001BC164
    /* BC154 001BC154 00000000 */   nop
    /* BC158 001BC158 2D100000 */  daddu      $2, $0, $0
    /* BC15C 001BC15C 0F000010 */  b          .L001BC19C
    /* BC160 001BC160 00000000 */   nop
  .L001BC164:
    /* BC164 001BC164 3000028E */  lw         $2, 0x30($16)
    /* BC168 001BC168 640A448C */  lw         $4, 0xA64($2)
    /* BC16C 001BC16C 60000524 */  addiu      $5, $0, 0x60
    /* BC170 001BC170 C4C9080C */  jal        func_00232710
    /* BC174 001BC174 00000000 */   nop
    /* BC178 001BC178 04004010 */  beqz       $2, .L001BC18C
    /* BC17C 001BC17C 00000000 */   nop
    /* BC180 001BC180 01000224 */  addiu      $2, $0, 0x1
    /* BC184 001BC184 05000010 */  b          .L001BC19C
    /* BC188 001BC188 00000000 */   nop
  .L001BC18C:
    /* BC18C 001BC18C 2D200002 */  daddu      $4, $16, $0
    /* BC190 001BC190 E4C2070C */  jal        func_001f0b90
    /* BC194 001BC194 00000000 */   nop
    /* BC198 001BC198 2B100200 */  sltu       $2, $0, $2
  .L001BC19C:
    /* BC19C 001BC19C 1000BFDF */  ld         $31, 0x10($29)
    /* BC1A0 001BC1A0 0000B07B */  lq         $16, 0x0($29)
    /* BC1A4 001BC1A4 2000BD27 */  addiu      $29, $29, 0x20
    /* BC1A8 001BC1A8 0800E003 */  jr         $31
    /* BC1AC 001BC1AC 00000000 */   nop
.size func_001bc140, 0x70
