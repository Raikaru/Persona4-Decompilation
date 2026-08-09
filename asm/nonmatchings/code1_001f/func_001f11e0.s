.section .text
.set noat
.set noreorder
glabel func_001f11e0
    /* F11E0 001F11E0 B8B3858F */  lw         $5, -0x4C48($28)
    /* F11E4 001F11E4 3C1C0400 */  dsll32     $3, $4, 16
    /* F11E8 001F11E8 3F1C0300 */  dsra32     $3, $3, 16
    /* F11EC 001F11EC 80100300 */  sll        $2, $3, 2
    /* F11F0 001F11F0 21104300 */  addu       $2, $2, $3
    /* F11F4 001F11F4 C0100200 */  sll        $2, $2, 3
    /* F11F8 001F11F8 21104500 */  addu       $2, $2, $5
    /* F11FC 001F11FC 02004290 */  lbu        $2, 0x2($2)
    /* F1200 001F1200 01004238 */  xori       $2, $2, 0x1
    /* F1204 001F1204 0100422C */  sltiu      $2, $2, 0x1
    /* F1208 001F1208 0800E003 */  jr         $31
    /* F120C 001F120C 00000000 */   nop
.size func_001f11e0, 0x30
