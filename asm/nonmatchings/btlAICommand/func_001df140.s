.section .text
.set noat
.set noreorder
glabel func_001df140
    /* DF140 001DF140 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF144 001DF144 1000BFFF */  sd         $31, 0x10($29)
    /* DF148 001DF148 0000B07F */  sq         $16, 0x0($29)
    /* DF14C 001DF14C 14740A0C */  jal        func_0029d050
    /* DF150 001DF150 00000000 */   nop
    /* DF154 001DF154 2D804000 */  daddu      $16, $2, $0
    /* DF158 001DF158 2D200000 */  daddu      $4, $0, $0
    /* DF15C 001DF15C 00730A0C */  jal        func_0029cc00
    /* DF160 001DF160 00000000 */   nop
    /* DF164 001DF164 EC0002A6 */  sh         $2, 0xEC($16)
    /* DF168 001DF168 2D200002 */  daddu      $4, $16, $0
    /* DF16C 001DF16C 38000526 */  addiu      $5, $16, 0x38
    /* DF170 001DF170 02800634 */  ori        $6, $0, 0x8002
    /* DF174 001DF174 9079070C */  jal        func_001de640
    /* DF178 001DF178 00000000 */   nop
    /* DF17C 001DF17C 01000224 */  addiu      $2, $0, 0x1
    /* DF180 001DF180 1000BFDF */  ld         $31, 0x10($29)
    /* DF184 001DF184 0000B07B */  lq         $16, 0x0($29)
    /* DF188 001DF188 2000BD27 */  addiu      $29, $29, 0x20
    /* DF18C 001DF18C 0800E003 */  jr         $31
    /* DF190 001DF190 00000000 */   nop
    /* DF194 001DF194 00000000 */  nop
    /* DF198 001DF198 00000000 */  nop
    /* DF19C 001DF19C 00000000 */  nop
.size func_001df140, 0x60
