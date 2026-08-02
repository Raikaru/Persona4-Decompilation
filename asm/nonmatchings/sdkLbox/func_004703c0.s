.section .text
.set noat
.set noreorder
glabel func_004703c0
    /* 3703C0 004703C0 3800838C */  lw         $3, 0x38($4)
    /* 3703C4 004703C4 040065AC */  sw         $5, 0x4($3)
    /* 3703C8 004703C8 0800E003 */  jr         $31
    /* 3703CC 004703CC 00000000 */   nop
.size func_004703c0, 0x10
