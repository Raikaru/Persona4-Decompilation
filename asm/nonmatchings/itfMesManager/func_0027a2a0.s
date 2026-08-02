.section .text
.set noat
.set noreorder
glabel func_0027a2a0
    /* 17A2A0 0027A2A0 2000868C */  lw         $6, 0x20($4)
    /* 17A2A4 0027A2A4 02008390 */  lbu        $3, 0x2($4)
    /* 17A2A8 0027A2A8 43180300 */  sra        $3, $3, 1
    /* 17A2AC 0027A2AC 0D00A3A0 */  sb         $3, 0xD($5)
    /* 17A2B0 0027A2B0 1500C390 */  lbu        $3, 0x15($6)
    /* 17A2B4 0027A2B4 0A00A3A0 */  sb         $3, 0xA($5)
    /* 17A2B8 0027A2B8 1400C390 */  lbu        $3, 0x14($6)
    /* 17A2BC 0027A2BC 0B00A3A0 */  sb         $3, 0xB($5)
    /* 17A2C0 0027A2C0 1600C390 */  lbu        $3, 0x16($6)
    /* 17A2C4 0027A2C4 0C00A3A0 */  sb         $3, 0xC($5)
    /* 17A2C8 0027A2C8 0800E003 */  jr         $31
    /* 17A2CC 0027A2CC 00000000 */   nop
.size func_0027a2a0, 0x30
