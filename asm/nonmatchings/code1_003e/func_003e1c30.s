.section .text
.set noat
.set noreorder
glabel func_003e1c30
    /* 2E1C30 003E1C30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2E1C34 003E1C34 78B78227 */  addiu      $2, $28, -0x4888
    /* 2E1C38 003E1C38 0000BFFF */  sd         $31, 0x0($29)
    /* 2E1C3C 003E1C3C 78B7858F */  lw         $5, -0x4888($28)
    /* 2E1C40 003E1C40 0D00A210 */  beq        $5, $2, .L003E1C78
    /* 2E1C44 003E1C44 00000000 */   nop
  .L003E1C48:
    /* 2E1C48 003E1C48 0000A38C */  lw         $3, 0x0($5)
    /* 2E1C4C 003E1C4C E4FFA424 */  addiu      $4, $5, -0x1C
    /* 2E1C50 003E1C50 0400A28C */  lw         $2, 0x4($5)
    /* 2E1C54 003E1C54 000043AC */  sw         $3, 0x0($2)
    /* 2E1C58 003E1C58 0400A38C */  lw         $3, 0x4($5)
    /* 2E1C5C 003E1C5C 0000A28C */  lw         $2, 0x0($5)
    /* 2E1C60 003E1C60 8C840F0C */  jal        func_003e1230
    /* 2E1C64 003E1C64 040043AC */   sw        $3, 0x4($2)
    /* 2E1C68 003E1C68 78B7858F */  lw         $5, -0x4888($28)
    /* 2E1C6C 003E1C6C 78B78227 */  addiu      $2, $28, -0x4888
    /* 2E1C70 003E1C70 F5FFA214 */  bne        $5, $2, .L003E1C48
    /* 2E1C74 003E1C74 00000000 */   nop
  .L003E1C78:
    /* 2E1C78 003E1C78 74B7848F */  lw         $4, -0x488C($28)
    /* 2E1C7C 003E1C7C 1C00838C */  lw         $3, 0x1C($4)
    /* 2E1C80 003E1C80 2000828C */  lw         $2, 0x20($4)
    /* 2E1C84 003E1C84 000043AC */  sw         $3, 0x0($2)
    /* 2E1C88 003E1C88 2000838C */  lw         $3, 0x20($4)
    /* 2E1C8C 003E1C8C 1C00828C */  lw         $2, 0x1C($4)
    /* 2E1C90 003E1C90 8C840F0C */  jal        func_003e1230
    /* 2E1C94 003E1C94 040043AC */   sw        $3, 0x4($2)
    /* 2E1C98 003E1C98 74B780AF */  sw         $0, -0x488C($28)
    /* 2E1C9C 003E1C9C 70B780AF */  sw         $0, -0x4890($28)
    /* 2E1CA0 003E1CA0 0000BFDF */  ld         $31, 0x0($29)
    /* 2E1CA4 003E1CA4 0800E003 */  jr         $31
    /* 2E1CA8 003E1CA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 2E1CAC 003E1CAC 00000000 */  nop
.size func_003e1c30, 0x80
