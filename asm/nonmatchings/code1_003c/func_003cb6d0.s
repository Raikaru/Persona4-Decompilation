.section .text
.set noat
.set noreorder
glabel func_003cb6d0
    /* 2CB6D0 003CB6D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB6D4 003CB6D4 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB6D8 003CB6D8 0000B07F */  sq         $16, 0x0($29)
    /* 2CB6DC 003CB6DC 2D808000 */  daddu      $16, $4, $0
    /* 2CB6E0 003CB6E0 2D20A000 */  daddu      $4, $5, $0
    /* 2CB6E4 003CB6E4 042F0F0C */  jal        func_003cbc10
    /* 2CB6E8 003CB6E8 2D280002 */   daddu     $5, $16, $0
    /* 2CB6EC 003CB6EC 2D100002 */  daddu      $2, $16, $0
    /* 2CB6F0 003CB6F0 1000BFDF */  ld         $31, 0x10($29)
    /* 2CB6F4 003CB6F4 0000B07B */  lq         $16, 0x0($29)
    /* 2CB6F8 003CB6F8 0800E003 */  jr         $31
    /* 2CB6FC 003CB6FC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003cb6d0, 0x30
