.section .text
.set noat
.set noreorder
glabel func_00418ef0
    /* 318EF0 00418EF0 07000324 */  addiu      $3, $0, 0x7
    /* 318EF4 00418EF4 02170400 */  srl        $2, $4, 28
    /* 318EF8 00418EF8 05004314 */  bne        $2, $3, .L00418F10
    /* 318EFC 00418EFC FF0F023C */   lui       $2, (0xFFFFFFF >> 16)
    /* 318F00 00418F00 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 318F04 00418F04 FFFF4234 */  ori        $2, $2, (0xFFFFFFF & 0xFFFF)
    /* 318F08 00418F08 24208200 */  and        $4, $4, $2
    /* 318F0C 00418F0C 25208300 */  or         $4, $4, $3
  .L00418F10:
    /* 318F10 00418F10 0800E003 */  jr         $31
    /* 318F14 00418F14 2D108000 */   daddu     $2, $4, $0
.size func_00418ef0, 0x28
