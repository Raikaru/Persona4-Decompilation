.section .text
.set noat
.set noreorder
glabel func_002ac3c0
    /* 1AC3C0 002AC3C0 FF008430 */  andi       $4, $4, 0xFF
    /* 1AC3C4 002AC3C4 FF00A230 */  andi       $2, $5, 0xFF
    /* 1AC3C8 002AC3C8 40180200 */  sll        $3, $2, 1
    /* 1AC3CC 002AC3CC 68B5828F */  lw         $2, -0x4A98($28)
    /* 1AC3D0 002AC3D0 21104300 */  addu       $2, $2, $3
    /* 1AC3D4 002AC3D4 00004394 */  lhu        $3, 0x0($2)
    /* 1AC3D8 002AC3D8 01000224 */  addiu      $2, $0, 0x1
    /* 1AC3DC 002AC3DC 04108200 */  sllv       $2, $2, $4
    /* 1AC3E0 002AC3E0 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1AC3E4 002AC3E4 24104300 */  and        $2, $2, $3
    /* 1AC3E8 002AC3E8 07108200 */  srav       $2, $2, $4
    /* 1AC3EC 002AC3EC 3C160200 */  dsll32     $2, $2, 24
    /* 1AC3F0 002AC3F0 3F160200 */  dsra32     $2, $2, 24
    /* 1AC3F4 002AC3F4 0800E003 */  jr         $31
    /* 1AC3F8 002AC3F8 00000000 */   nop
    /* 1AC3FC 002AC3FC 00000000 */  nop
.size func_002ac3c0, 0x40
