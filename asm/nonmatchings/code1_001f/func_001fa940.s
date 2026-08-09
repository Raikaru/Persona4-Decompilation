.section .text
.set noat
.set noreorder
glabel func_001fa940
    /* FA940 001FA940 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FA944 001FA944 0000BFFF */  sd         $31, 0x0($29)
    /* FA948 001FA948 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA94C 001FA94C 840B628C */  lw         $2, 0xB84($3)
    /* FA950 001FA950 06004010 */  beqz       $2, .L001FA96C
    /* FA954 001FA954 00000000 */   nop
    /* FA958 001FA958 4C0B628C */  lw         $2, 0xB4C($3)
    /* FA95C 001FA95C 02004234 */  ori        $2, $2, 0x2
    /* FA960 001FA960 4C0B62AC */  sw         $2, 0xB4C($3)
    /* FA964 001FA964 08000010 */  b          .L001FA988
    /* FA968 001FA968 00000000 */   nop
  .L001FA96C:
    /* FA96C 001FA96C 800B648C */  lw         $4, 0xB80($3)
    /* FA970 001FA970 05008010 */  beqz       $4, .L001FA988
    /* FA974 001FA974 00000000 */   nop
    /* FA978 001FA978 C816120C */  jal        func_00485b20
    /* FA97C 001FA97C 00000000 */   nop
    /* FA980 001FA980 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA984 001FA984 800B40AC */  sw         $0, 0xB80($2)
  .L001FA988:
    /* FA988 001FA988 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA98C 001FA98C 880B448C */  lw         $4, 0xB88($2)
    /* FA990 001FA990 05008010 */  beqz       $4, .L001FA9A8
    /* FA994 001FA994 00000000 */   nop
    /* FA998 001FA998 C883040C */  jal        func_00120f20
    /* FA99C 001FA99C 00000000 */   nop
    /* FA9A0 001FA9A0 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA9A4 001FA9A4 880B40AC */  sw         $0, 0xB88($2)
  .L001FA9A8:
    /* FA9A8 001FA9A8 01000224 */  addiu      $2, $0, 0x1
    /* FA9AC 001FA9AC 0000BFDF */  ld         $31, 0x0($29)
    /* FA9B0 001FA9B0 1000BD27 */  addiu      $29, $29, 0x10
    /* FA9B4 001FA9B4 0800E003 */  jr         $31
    /* FA9B8 001FA9B8 00000000 */   nop
    /* FA9BC 001FA9BC 00000000 */  nop
.size func_001fa940, 0x80
