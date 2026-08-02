.section .text
.set noat
.set noreorder
glabel func_00278da0
    /* 178DA0 00278DA0 01000524 */  addiu      $5, $0, 0x1
    /* 178DA4 00278DA4 0800838C */  lw         $3, 0x8($4)
    /* 178DA8 00278DA8 4730023C */  lui        $2, (0x3047534D >> 16)
    /* 178DAC 00278DAC 4D534234 */  ori        $2, $2, (0x3047534D & 0xFFFF)
    /* 178DB0 00278DB0 06006210 */  beq        $3, $2, .L00278DCC
    /* 178DB4 00278DB4 00000000 */   nop
    /* 178DB8 00278DB8 4731023C */  lui        $2, (0x3147534D >> 16)
    /* 178DBC 00278DBC 4D534234 */  ori        $2, $2, (0x3147534D & 0xFFFF)
    /* 178DC0 00278DC0 02006210 */  beq        $3, $2, .L00278DCC
    /* 178DC4 00278DC4 00000000 */   nop
    /* 178DC8 00278DC8 2D280000 */  daddu      $5, $0, $0
  .L00278DCC:
    /* 178DCC 00278DCC 2B100500 */  sltu       $2, $0, $5
    /* 178DD0 00278DD0 0800E003 */  jr         $31
    /* 178DD4 00278DD4 00000000 */   nop
    /* 178DD8 00278DD8 00000000 */  nop
    /* 178DDC 00278DDC 00000000 */  nop
.size func_00278da0, 0x40
