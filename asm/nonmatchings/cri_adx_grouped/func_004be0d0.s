.section .text
.set noat
.set noreorder
glabel func_004be0d0
    /* 3BE0D0 004BE0D0 7500023C */  lui        $2, %hi(D_00756940)
    /* 3BE0D4 004BE0D4 080080AC */  sw         $0, 0x8($4)
    /* 3BE0D8 004BE0D8 40694224 */  addiu      $2, $2, %lo(D_00756940)
    /* 3BE0DC 004BE0DC 040080AC */  sw         $0, 0x4($4)
    /* 3BE0E0 004BE0E0 0800E003 */  jr         $31
    /* 3BE0E4 004BE0E4 000082AC */   sw        $2, 0x0($4)
.size func_004be0d0, 0x18
