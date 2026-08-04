.section .text
.set noat
.set noreorder
glabel func_003cc680
    /* 2CC680 003CC680 000083C4 */  lwc1       $f3, 0x0($4)
    /* 2CC684 003CC684 7F43033C */  lui        $3, (0x437F0001 >> 16)
    /* 2CC688 003CC688 040082C4 */  lwc1       $f2, 0x4($4)
    /* 2CC68C 003CC68C 01006334 */  ori        $3, $3, (0x437F0001 & 0xFFFF)
    /* 2CC690 003CC690 080081C4 */  lwc1       $f1, 0x8($4)
    /* 2CC694 003CC694 00008344 */  mtc1       $3, $f0
    /* 2CC698 003CC698 82100046 */  mul.s      $f2, $f2, $f0
    /* 2CC69C 003CC69C 00600444 */  mfc1       $4, $f12
    /* 2CC6A0 003CC6A0 00100344 */  mfc1       $3, $f2
    /* 2CC6A4 003CC6A4 89270470 */  pexew      $4, $4
    /* 2CC6A8 003CC6A8 891F0370 */  pexew      $3, $3
    /* 2CC6AC 003CC6AC 42080046 */  mul.s      $f1, $f1, $f0
    /* 2CC6B0 003CC6B0 82180046 */  mul.s      $f2, $f3, $f0
    /* 2CC6B4 003CC6B4 00080444 */  mfc1       $4, $f1
    /* 2CC6B8 003CC6B8 00100344 */  mfc1       $3, $f2
    /* 2CC6BC 003CC6BC C8248370 */  ppacw      $4, $4, $3
    /* 2CC6C0 003CC6C0 84B8838F */  lw         $3, -0x477C($28)
    /* 2CC6C4 003CC6C4 0000647C */  sq         $4, 0x0($3)
    /* 2CC6C8 003CC6C8 84B8838F */  lw         $3, -0x477C($28)
    /* 2CC6CC 003CC6CC 10006324 */  addiu      $3, $3, 0x10
    /* 2CC6D0 003CC6D0 0800E003 */  jr         $31
    /* 2CC6D4 003CC6D4 84B883AF */   sw        $3, -0x477C($28)
    /* 2CC6D8 003CC6D8 00000000 */  nop
    /* 2CC6DC 003CC6DC 00000000 */  nop
.size func_003cc680, 0x60
