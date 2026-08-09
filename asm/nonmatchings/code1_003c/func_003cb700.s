.section .text
.set noat
.set noreorder
glabel func_003cb700
    /* 2CB700 003CB700 2D108000 */  daddu      $2, $4, $0
    /* 2CB704 003CB704 2D28C000 */  daddu      $5, $6, $0
    /* 2CB708 003CB708 5400C48C */  lw         $4, 0x54($6)
    /* 2CB70C 003CB70C 2000A724 */  addiu      $7, $5, 0x20
    /* 2CB710 003CB710 A4160F08 */  j          func_003c5a90
    /* 2CB714 003CB714 2D304000 */   daddu     $6, $2, $0
    /* 2CB718 003CB718 00000000 */  nop
    /* 2CB71C 003CB71C 00000000 */  nop
.size func_003cb700, 0x20
