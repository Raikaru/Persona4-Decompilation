.section .text
.set noat
.set noreorder
glabel func_0051f098
    /* 41F098 0051F098 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 41F09C 0051F09C 1000B0FF */  sd         $16, 0x10($29)
    /* 41F0A0 0051F0A0 2D80A000 */  daddu      $16, $5, $0
    /* 41F0A4 0051F0A4 1800B1FF */  sd         $17, 0x18($29)
    /* 41F0A8 0051F0A8 2D88C000 */  daddu      $17, $6, $0
    /* 41F0AC 0051F0AC 2000B2FF */  sd         $18, 0x20($29)
    /* 41F0B0 0051F0B0 2D908000 */  daddu      $18, $4, $0
    /* 41F0B4 0051F0B4 2800BFFF */  sd         $31, 0x28($29)
    /* 41F0B8 0051F0B8 645F140C */  jal        func_00517d90
    /* 41F0BC 0051F0BC 2D20A003 */   daddu     $4, $29, $0
    /* 41F0C0 0051F0C0 2D204002 */  daddu      $4, $18, $0
    /* 41F0C4 0051F0C4 2D280002 */  daddu      $5, $16, $0
    /* 41F0C8 0051F0C8 3E7C140C */  jal        func_0051f0f8
    /* 41F0CC 0051F0CC 2D302002 */   daddu     $6, $17, $0
    /* 41F0D0 0051F0D0 2D20A003 */  daddu      $4, $29, $0
    /* 41F0D4 0051F0D4 6A5F140C */  jal        func_00517da8
    /* 41F0D8 0051F0D8 2D804000 */   daddu     $16, $2, $0
    /* 41F0DC 0051F0DC 2D100002 */  daddu      $2, $16, $0
    /* 41F0E0 0051F0E0 1800B1DF */  ld         $17, 0x18($29)
    /* 41F0E4 0051F0E4 1000B0DF */  ld         $16, 0x10($29)
    /* 41F0E8 0051F0E8 2000B2DF */  ld         $18, 0x20($29)
    /* 41F0EC 0051F0EC 2800BFDF */  ld         $31, 0x28($29)
    /* 41F0F0 0051F0F0 0800E003 */  jr         $31
    /* 41F0F4 0051F0F4 3000BD27 */   addiu     $29, $29, 0x30
.size func_0051f098, 0x60
