.section .text
.set noat
.set noreorder
glabel func_002b82d0
    /* 1B82D0 002B82D0 5C0085A0 */  sb         $5, 0x5C($4)
    /* 1B82D4 002B82D4 5D0086A0 */  sb         $6, 0x5D($4)
    /* 1B82D8 002B82D8 5E0085A0 */  sb         $5, 0x5E($4)
    /* 1B82DC 002B82DC 5A0080A4 */  sh         $0, 0x5A($4)
    /* 1B82E0 002B82E0 580088A4 */  sh         $8, 0x58($4)
    /* 1B82E4 002B82E4 600089A4 */  sh         $9, 0x60($4)
    /* 1B82E8 002B82E8 620087A0 */  sb         $7, 0x62($4)
    /* 1B82EC 002B82EC 00008384 */  lh         $3, 0x0($4)
    /* 1B82F0 002B82F0 04006334 */  ori        $3, $3, 0x4
    /* 1B82F4 002B82F4 000083A4 */  sh         $3, 0x0($4)
    /* 1B82F8 002B82F8 0800E003 */  jr         $31
    /* 1B82FC 002B82FC 00000000 */   nop
.size func_002b82d0, 0x30
