.section .text
.set noat
.set noreorder
glabel func_003f69f0
    /* 2F69F0 003F69F0 05008010 */  beqz       $4, .L003F6A08
    /* 2F69F4 003F69F4 2D100000 */   daddu     $2, $0, $0
    /* 2F69F8 003F69F8 0000838C */  lw         $3, 0x0($4)
    /* 2F69FC 003F69FC 02006010 */  beqz       $3, .L003F6A08
    /* 2F6A00 003F6A00 00000000 */   nop
    /* 2F6A04 003F6A04 04000224 */  addiu      $2, $0, 0x4
  .L003F6A08:
    /* 2F6A08 003F6A08 0800E003 */  jr         $31
    /* 2F6A0C 003F6A0C 00000000 */   nop
.size func_003f69f0, 0x20
