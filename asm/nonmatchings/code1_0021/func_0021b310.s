.section .text
.set noat
.set noreorder
glabel func_0021b310
    /* 11B310 0021B310 0200A010 */  beqz       $5, .L0021B31C
    /* 11B314 0021B314 00000000 */   nop
    /* 11B318 0021B318 000080AC */  sw         $0, 0x0($4)
  .L0021B31C:
    /* 11B31C 0021B31C 040085AC */  sw         $5, 0x4($4)
    /* 11B320 0021B320 0800E003 */  jr         $31
    /* 11B324 0021B324 00000000 */   nop
    /* 11B328 0021B328 00000000 */  nop
    /* 11B32C 0021B32C 00000000 */  nop
.size func_0021b310, 0x20
