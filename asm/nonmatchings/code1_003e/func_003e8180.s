.section .text
.set noat
.set noreorder
glabel func_003e8180
    /* 2E8180 003E8180 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E8184 003E8184 1000BFFF */  sd         $31, 0x10($29)
    /* 2E8188 003E8188 0000B07F */  sq         $16, 0x0($29)
    /* 2E818C 003E818C 2D808000 */  daddu      $16, $4, $0
    /* 2E8190 003E8190 6C9B0F0C */  jal        func_003e6db0
    /* 2E8194 003E8194 80008CE4 */   swc1      $f12, 0x80($4)
    /* 2E8198 003E8198 0400048E */  lw         $4, 0x4($16)
    /* 2E819C 003E819C 03008010 */  beqz       $4, .L003E81AC
    /* 2E81A0 003E81A0 00000000 */   nop
    /* 2E81A4 003E81A4 A0A50F0C */  jal        func_003e9680
    /* 2E81A8 003E81A8 00000000 */   nop
  .L003E81AC:
    /* 2E81AC 003E81AC 2D100002 */  daddu      $2, $16, $0
    /* 2E81B0 003E81B0 1000BFDF */  ld         $31, 0x10($29)
    /* 2E81B4 003E81B4 0000B07B */  lq         $16, 0x0($29)
    /* 2E81B8 003E81B8 0800E003 */  jr         $31
    /* 2E81BC 003E81BC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003e8180, 0x40
