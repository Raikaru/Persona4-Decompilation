.section .text
.set noat
.set noreorder
glabel func_003cb6a0
    /* 2CB6A0 003CB6A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB6A4 003CB6A4 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB6A8 003CB6A8 0000B07F */  sq         $16, 0x0($29)
    /* 2CB6AC 003CB6AC 2D808000 */  daddu      $16, $4, $0
    /* 2CB6B0 003CB6B0 2D20A000 */  daddu      $4, $5, $0
    /* 2CB6B4 003CB6B4 A02F0F0C */  jal        func_003cbe80
    /* 2CB6B8 003CB6B8 2D280002 */   daddu     $5, $16, $0
    /* 2CB6BC 003CB6BC 2D100002 */  daddu      $2, $16, $0
    /* 2CB6C0 003CB6C0 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB6C4 003CB6C4 0000B07B */  lq         $16, 0x0($29)
    /* 2CB6C8 003CB6C8 0800E003 */  jr         $31
    /* 2CB6CC 003CB6CC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb6a0, 0x30
