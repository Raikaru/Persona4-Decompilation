.section .text
.set noat
.set noreorder
glabel func_001e8c60
    /* E8C60 001E8C60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E8C64 001E8C64 1000BFFF */  sd         $31, 0x10($29)
    /* E8C68 001E8C68 0000B07F */  sq         $16, 0x0($29)
    /* E8C6C 001E8C6C 14740A0C */  jal        func_0029d050
    /* E8C70 001E8C70 00000000 */   nop
    /* E8C74 001E8C74 2D200000 */  daddu      $4, $0, $0
    /* E8C78 001E8C78 00730A0C */  jal        func_0029cc00
    /* E8C7C 001E8C7C 00000000 */   nop
    /* E8C80 001E8C80 2D804000 */  daddu      $16, $2, $0
    /* E8C84 001E8C84 01000424 */  addiu      $4, $0, 0x1
    /* E8C88 001E8C88 00730A0C */  jal        func_0029cc00
    /* E8C8C 001E8C8C 00000000 */   nop
    /* E8C90 001E8C90 02000424 */  addiu      $4, $0, 0x2
    /* E8C94 001E8C94 00730A0C */  jal        func_0029cc00
    /* E8C98 001E8C98 00000000 */   nop
    /* E8C9C 001E8C9C 3C211000 */  dsll32     $4, $16, 4
    /* E8CA0 001E8CA0 3E210400 */  dsrl32     $4, $4, 4
    /* E8CA4 001E8CA4 30C3060C */  jal        func_001b0cc0
    /* E8CA8 001E8CA8 00000000 */   nop
    /* E8CAC 001E8CAC FFFF0424 */  addiu      $4, $0, -0x1
    /* E8CB0 001E8CB0 D4730A0C */  jal        func_0029cf50
    /* E8CB4 001E8CB4 00000000 */   nop
    /* E8CB8 001E8CB8 01000224 */  addiu      $2, $0, 0x1
    /* E8CBC 001E8CBC 1000BFDF */  ld         $31, 0x10($29)
    /* E8CC0 001E8CC0 0000B07B */  lq         $16, 0x0($29)
    /* E8CC4 001E8CC4 2000BD27 */  addiu      $29, $29, 0x20
    /* E8CC8 001E8CC8 0800E003 */  jr         $31
    /* E8CCC 001E8CCC 00000000 */   nop
.size func_001e8c60, 0x70
