.section .text
.set noat
.set noreorder
glabel func_0051fdc0
    /* 41FDC0 0051FDC0 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* 41FDC4 0051FDC4 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 41FDC8 0051FDC8 FFFF4234 */  ori        $2, $2, (0xFFFFFFF & 0xFFFF)
    /* 41FDCC 0051FDCC 0020033C */  lui        $3, (0x20000000 >> 16)
    /* 41FDD0 0051FDD0 2430C200 */  and        $6, $6, $2
    /* 41FDD4 0051FDD4 01000224 */  addiu      $2, $0, 0x1
    /* 41FDD8 0051FDD8 2000B0FF */  sd         $16, 0x20($29)
    /* 41FDDC 0051FDDC 2D808000 */  daddu      $16, $4, $0
    /* 41FDE0 0051FDE0 2530C300 */  or         $6, $6, $3
    /* 41FDE4 0051FDE4 C0520700 */  sll        $10, $7, 11
    /* 41FDE8 0051FDE8 2800BFFF */  sd         $31, 0x28($29)
    /* 41FDEC 0051FDEC 2D20A003 */  daddu      $4, $29, $0
    /* 41FDF0 0051FDF0 540009AE */  sw         $9, 0x54($16)
    /* 41FDF4 0051FDF4 18000AAE */  sw         $10, 0x18($16)
    /* 41FDF8 0051FDF8 080007AE */  sw         $7, 0x8($16)
    /* 41FDFC 0051FDFC 000005AE */  sw         $5, 0x0($16)
    /* 41FE00 0051FE00 500008AE */  sw         $8, 0x50($16)
    /* 41FE04 0051FE04 040006AE */  sw         $6, 0x4($16)
    /* 41FE08 0051FE08 0400A2AF */  sw         $2, 0x4($29)
    /* 41FE0C 0051FE0C F885100C */  jal        func_004217e0
    /* 41FE10 0051FE10 0800A2AF */   sw        $2, 0x8($29)
    /* 41FE14 0051FE14 400002AE */  sw         $2, 0x40($16)
    /* 41FE18 0051FE18 8E7F140C */  jal        func_0051fe38
    /* 41FE1C 0051FE1C 2D200002 */   daddu     $4, $16, $0
    /* 41FE20 0051FE20 480000FE */  sd         $0, 0x48($16)
    /* 41FE24 0051FE24 2800BFDF */  ld         $31, 0x28($29)
    /* 41FE28 0051FE28 01000224 */  addiu      $2, $0, 0x1
    /* 41FE2C 0051FE2C 2000B0DF */  ld         $16, 0x20($29)
    /* 41FE30 0051FE30 0800E003 */  jr         $31
    /* 41FE34 0051FE34 3000BD27 */   addiu     $29, $29, 0x30
.size func_0051fdc0, 0x78
