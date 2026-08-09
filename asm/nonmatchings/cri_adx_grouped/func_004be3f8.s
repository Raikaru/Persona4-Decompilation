.section .text
.set noat
.set noreorder
glabel func_004be3f8
    /* 3BE3F8 004BE3F8 7500023C */  lui        $2, %hi(D_00756A50)
    /* 3BE3FC 004BE3FC 0C0080AC */  sw         $0, 0xC($4)
    /* 3BE400 004BE400 506A4224 */  addiu      $2, $2, %lo(D_00756A50)
    /* 3BE404 004BE404 040080AC */  sw         $0, 0x4($4)
    /* 3BE408 004BE408 000082AC */  sw         $2, 0x0($4)
    /* 3BE40C 004BE40C 0800E003 */  jr         $31
    /* 3BE410 004BE410 080080AC */   sw        $0, 0x8($4)
    /* 3BE414 004BE414 00000000 */  nop
.size func_004be3f8, 0x20
