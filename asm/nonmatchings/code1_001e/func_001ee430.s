.section .text
.set noat
.set noreorder
glabel func_001ee430
    /* EE430 001EE430 9C00858C */  lw         $5, 0x9C($4)
    /* EE434 001EE434 0400A330 */  andi       $3, $5, 0x4
    /* EE438 001EE438 13006010 */  beqz       $3, .L001EE488
    /* EE43C 001EE43C 00000000 */   nop
    /* EE440 001EE440 FBFF0324 */  addiu      $3, $0, -0x5
    /* EE444 001EE444 2418A300 */  and        $3, $5, $3
    /* EE448 001EE448 9C0083AC */  sw         $3, 0x9C($4)
    /* EE44C 001EE44C D409858C */  lw         $5, 0x9D4($4)
    /* EE450 001EE450 0300A010 */  beqz       $5, .L001EE460
    /* EE454 001EE454 00000000 */   nop
    /* EE458 001EE458 D009838C */  lw         $3, 0x9D0($4)
    /* EE45C 001EE45C C804A3AC */  sw         $3, 0x4C8($5)
  .L001EE460:
    /* EE460 001EE460 D009858C */  lw         $5, 0x9D0($4)
    /* EE464 001EE464 0500A010 */  beqz       $5, .L001EE47C
    /* EE468 001EE468 00000000 */   nop
    /* EE46C 001EE46C D409838C */  lw         $3, 0x9D4($4)
    /* EE470 001EE470 CC04A3AC */  sw         $3, 0x4CC($5)
    /* EE474 001EE474 04000010 */  b          .L001EE488
    /* EE478 001EE478 00000000 */   nop
  .L001EE47C:
    /* EE47C 001EE47C D409848C */  lw         $4, 0x9D4($4)
    /* EE480 001EE480 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE484 001EE484 180364AC */  sw         $4, 0x318($3)
  .L001EE488:
    /* EE488 001EE488 0800E003 */  jr         $31
    /* EE48C 001EE48C 00000000 */   nop
.size func_001ee430, 0x60
