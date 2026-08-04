.section .text
.set noat
.set noreorder
glabel func_003ca890
    /* 2CA890 003CA890 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CA894 003CA894 1000BFFF */  sd         $31, 0x10($29)
    /* 2CA898 003CA898 0000B07F */  sq         $16, 0x0($29)
    /* 2CA89C 003CA89C 08B7838F */  lw         $3, -0x48F8($28)
    /* 2CA8A0 003CA8A0 2D808000 */  daddu      $16, $4, $0
    /* 2CA8A4 003CA8A4 2110A300 */  addu       $2, $5, $3
    /* 2CA8A8 003CA8A8 0C00448C */  lw         $4, 0xC($2)
    /* 2CA8AC 003CA8AC 21180302 */  addu       $3, $16, $3
    /* 2CA8B0 003CA8B0 000060AC */  sw         $0, 0x0($3)
    /* 2CA8B4 003CA8B4 040060AC */  sw         $0, 0x4($3)
    /* 2CA8B8 003CA8B8 03008010 */  beqz       $4, .L003CA8C8
    /* 2CA8BC 003CA8BC 080060AC */   sw        $0, 0x8($3)
    /* 2CA8C0 003CA8C0 042F0F0C */  jal        func_003cbc10
    /* 2CA8C4 003CA8C4 2D280002 */   daddu     $5, $16, $0
  .L003CA8C8:
    /* 2CA8C8 003CA8C8 2D100002 */  daddu      $2, $16, $0
    /* 2CA8CC 003CA8CC 1000BFDF */  ld         $31, 0x10($29)
    /* 2CA8D0 003CA8D0 0000B07B */  lq         $16, 0x0($29)
    /* 2CA8D4 003CA8D4 0800E003 */  jr         $31
    /* 2CA8D8 003CA8D8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2CA8DC 003CA8DC 00000000 */  nop
.size func_003ca890, 0x50
