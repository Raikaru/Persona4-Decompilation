.section .text
.set noat
.set noreorder
glabel func_0043ddf8
    /* 33DDF8 0043DDF8 44000F3C */  lui        $15, %hi(func_00442220)
    /* 33DDFC 0043DDFC 540087AC */  sw         $7, 0x54($4)
    /* 33DE00 0043DE00 44000E3C */  lui        $14, %hi(D_00442280)
    /* 33DE04 0043DE04 0C0085A4 */  sh         $5, 0xC($4)
    /* 33DE08 0043DE08 2022EF25 */  addiu      $15, $15, %lo(func_00442220)
    /* 33DE0C 0043DE0C 0E0086A4 */  sh         $6, 0xE($4)
    /* 33DE10 0043DE10 8022CE25 */  addiu      $14, $14, %lo(D_00442280)
    /* 33DE14 0043DE14 20008FAC */  sw         $15, 0x20($4)
    /* 33DE18 0043DE18 24008EAC */  sw         $14, 0x24($4)
    /* 33DE1C 0043DE1C 44000F3C */  lui        $15, %hi(func_00442300)
    /* 33DE20 0043DE20 000080AC */  sw         $0, 0x0($4)
    /* 33DE24 0043DE24 44000E3C */  lui        $14, %hi(D_00442368)
    /* 33DE28 0043DE28 040080AC */  sw         $0, 0x4($4)
    /* 33DE2C 0043DE2C 0023EF25 */  addiu      $15, $15, %lo(func_00442300)
    /* 33DE30 0043DE30 080080AC */  sw         $0, 0x8($4)
    /* 33DE34 0043DE34 6823CE25 */  addiu      $14, $14, %lo(D_00442368)
    /* 33DE38 0043DE38 28008FAC */  sw         $15, 0x28($4)
    /* 33DE3C 0043DE3C 2C008EAC */  sw         $14, 0x2C($4)
    /* 33DE40 0043DE40 100080AC */  sw         $0, 0x10($4)
    /* 33DE44 0043DE44 140080AC */  sw         $0, 0x14($4)
    /* 33DE48 0043DE48 180080AC */  sw         $0, 0x18($4)
    /* 33DE4C 0043DE4C 0800E003 */  jr         $31
    /* 33DE50 0043DE50 1C0084AC */   sw        $4, 0x1C($4)
    /* 33DE54 0043DE54 00000000 */  nop
.size func_0043ddf8, 0x60
