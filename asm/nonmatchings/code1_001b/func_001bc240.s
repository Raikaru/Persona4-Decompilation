.section .text
.set noat
.set noreorder
glabel func_001bc240
    /* BC240 001BC240 ACB3828F */  lw         $2, -0x4C54($28)
    /* BC244 001BC244 0C00438C */  lw         $3, 0xC($2)
    /* BC248 001BC248 2000023C */  lui        $2, (0x200000 >> 16)
    /* BC24C 001BC24C 24106200 */  and        $2, $3, $2
    /* BC250 001BC250 04004010 */  beqz       $2, .L001BC264
    /* BC254 001BC254 00000000 */   nop
    /* BC258 001BC258 01000224 */  addiu      $2, $0, 0x1
    /* BC25C 001BC25C 30000010 */  b          .L001BC320
    /* BC260 001BC260 00000000 */   nop
  .L001BC264:
    /* BC264 001BC264 E000828C */  lw         $2, 0xE0($4)
    /* BC268 001BC268 6E004494 */  lhu        $4, 0x6E($2)
    /* BC26C 001BC26C 3000428C */  lw         $2, 0x30($2)
    /* BC270 001BC270 0C0A428C */  lw         $2, 0xA0C($2)
    /* BC274 001BC274 10004010 */  beqz       $2, .L001BC2B8
    /* BC278 001BC278 00000000 */   nop
    /* BC27C 001BC27C A4004394 */  lhu        $3, 0xA4($2)
    /* BC280 001BC280 80100300 */  sll        $2, $3, 2
    /* BC284 001BC284 21104300 */  addu       $2, $2, $3
    /* BC288 001BC288 40100200 */  sll        $2, $2, 1
    /* BC28C 001BC28C 21104300 */  addu       $2, $2, $3
    /* BC290 001BC290 C0180200 */  sll        $3, $2, 3
    /* BC294 001BC294 E0B3828F */  lw         $2, -0x4C20($28)
    /* BC298 001BC298 21104300 */  addu       $2, $2, $3
    /* BC29C 001BC29C 00004294 */  lhu        $2, 0x0($2)
    /* BC2A0 001BC2A0 01004230 */  andi       $2, $2, 0x1
    /* BC2A4 001BC2A4 04004010 */  beqz       $2, .L001BC2B8
    /* BC2A8 001BC2A8 00000000 */   nop
    /* BC2AC 001BC2AC 2D100000 */  daddu      $2, $0, $0
    /* BC2B0 001BC2B0 0D000010 */  b          .L001BC2E8
    /* BC2B4 001BC2B4 00000000 */   nop
  .L001BC2B8:
    /* BC2B8 001BC2B8 BCB3838F */  lw         $3, -0x4C44($28)
    /* BC2BC 001BC2BC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* BC2C0 001BC2C0 80100200 */  sll        $2, $2, 2
    /* BC2C4 001BC2C4 21104300 */  addu       $2, $2, $3
    /* BC2C8 001BC2C8 02004294 */  lhu        $2, 0x2($2)
    /* BC2CC 001BC2CC 10004230 */  andi       $2, $2, 0x10
    /* BC2D0 001BC2D0 04004010 */  beqz       $2, .L001BC2E4
    /* BC2D4 001BC2D4 00000000 */   nop
    /* BC2D8 001BC2D8 2D100000 */  daddu      $2, $0, $0
    /* BC2DC 001BC2DC 02000010 */  b          .L001BC2E8
    /* BC2E0 001BC2E0 00000000 */   nop
  .L001BC2E4:
    /* BC2E4 001BC2E4 01000224 */  addiu      $2, $0, 0x1
  .L001BC2E8:
    /* BC2E8 001BC2E8 0C004010 */  beqz       $2, .L001BC31C
    /* BC2EC 001BC2EC 00000000 */   nop
    /* BC2F0 001BC2F0 BCB3838F */  lw         $3, -0x4C44($28)
    /* BC2F4 001BC2F4 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* BC2F8 001BC2F8 80100200 */  sll        $2, $2, 2
    /* BC2FC 001BC2FC 21104300 */  addu       $2, $2, $3
    /* BC300 001BC300 02004294 */  lhu        $2, 0x2($2)
    /* BC304 001BC304 20004230 */  andi       $2, $2, 0x20
    /* BC308 001BC308 04004010 */  beqz       $2, .L001BC31C
    /* BC30C 001BC30C 00000000 */   nop
    /* BC310 001BC310 01000224 */  addiu      $2, $0, 0x1
    /* BC314 001BC314 02000010 */  b          .L001BC320
    /* BC318 001BC318 00000000 */   nop
  .L001BC31C:
    /* BC31C 001BC31C 2D100000 */  daddu      $2, $0, $0
  .L001BC320:
    /* BC320 001BC320 0800E003 */  jr         $31
    /* BC324 001BC324 00000000 */   nop
    /* BC328 001BC328 00000000 */  nop
    /* BC32C 001BC32C 00000000 */  nop
.size func_001bc240, 0xf0
