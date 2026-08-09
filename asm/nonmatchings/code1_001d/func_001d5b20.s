.section .text
.set noat
.set noreorder
glabel func_001d5b20
    /* D5B20 001D5B20 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D5B24 001D5B24 4000BFFF */  sd         $31, 0x40($29)
    /* D5B28 001D5B28 3000B37F */  sq         $19, 0x30($29)
    /* D5B2C 001D5B2C 2000B27F */  sq         $18, 0x20($29)
    /* D5B30 001D5B30 1000B17F */  sq         $17, 0x10($29)
    /* D5B34 001D5B34 0000B07F */  sq         $16, 0x0($29)
    /* D5B38 001D5B38 0800858C */  lw         $5, 0x8($4)
    /* D5B3C 001D5B3C 0004A330 */  andi       $3, $5, 0x400
    /* D5B40 001D5B40 4E006014 */  bnez       $3, .L001D5C7C
    /* D5B44 001D5B44 00000000 */   nop
    /* D5B48 001D5B48 5800928C */  lw         $18, 0x58($4)
    /* D5B4C 001D5B4C 54009094 */  lhu        $16, 0x54($4)
    /* D5B50 001D5B50 0080A330 */  andi       $3, $5, 0x8000
    /* D5B54 001D5B54 13006014 */  bnez       $3, .L001D5BA4
    /* D5B58 001D5B58 00000000 */   nop
    /* D5B5C 001D5B5C 2D880000 */  daddu      $17, $0, $0
    /* D5B60 001D5B60 FFFF1032 */  andi       $16, $16, 0xFFFF
    /* D5B64 001D5B64 09000010 */  b          .L001D5B8C
    /* D5B68 001D5B68 00000000 */   nop
  .L001D5B6C:
    /* D5B6C 001D5B6C 0000448E */  lw         $4, 0x0($18)
    /* D5B70 001D5B70 03008010 */  beqz       $4, .L001D5B80
    /* D5B74 001D5B74 00000000 */   nop
    /* D5B78 001D5B78 1C16120C */  jal        func_00485870
    /* D5B7C 001D5B7C 00000000 */   nop
  .L001D5B80:
    /* D5B80 001D5B80 01002326 */  addiu      $3, $17, 0x1
    /* D5B84 001D5B84 FFFF7130 */  andi       $17, $3, 0xFFFF
    /* D5B88 001D5B88 04005226 */  addiu      $18, $18, 0x4
  .L001D5B8C:
    /* D5B8C 001D5B8C FFFF2332 */  andi       $3, $17, 0xFFFF
    /* D5B90 001D5B90 2A187000 */  slt        $3, $3, $16
    /* D5B94 001D5B94 F5FF6014 */  bnez       $3, .L001D5B6C
    /* D5B98 001D5B98 00000000 */   nop
    /* D5B9C 001D5B9C 37000010 */  b          .L001D5C7C
    /* D5BA0 001D5BA0 00000000 */   nop
  .L001D5BA4:
    /* D5BA4 001D5BA4 1405120C */  jal        func_00481450
    /* D5BA8 001D5BA8 00000000 */   nop
    /* D5BAC 001D5BAC 2D984000 */  daddu      $19, $2, $0
    /* D5BB0 001D5BB0 5E00043C */  lui        $4, %hi(D_005DC824)
    /* D5BB4 001D5BB4 24C88424 */  addiu      $4, $4, %lo(D_005DC824)
    /* D5BB8 001D5BB8 1005120C */  jal        func_00481440
    /* D5BBC 001D5BBC 00000000 */   nop
    /* D5BC0 001D5BC0 6482110C */  jal        func_00460990
    /* D5BC4 001D5BC4 00000000 */   nop
    /* D5BC8 001D5BC8 2D284000 */  daddu      $5, $2, $0
    /* D5BCC 001D5BCC 000040AC */  sw         $0, 0x0($2)
    /* D5BD0 001D5BD0 040040AC */  sw         $0, 0x4($2)
    /* D5BD4 001D5BD4 1D00033C */  lui        $3, %hi(func_001d5990)
    /* D5BD8 001D5BD8 90596324 */  addiu      $3, $3, %lo(func_001d5990)
    /* D5BDC 001D5BDC 080043AC */  sw         $3, 0x8($2)
    /* D5BE0 001D5BE0 ACB3838F */  lw         $3, -0x4C54($28)
    /* D5BE4 001D5BE4 100043AC */  sw         $3, 0x10($2)
    /* D5BE8 001D5BE8 7900043C */  lui        $4, %hi(D_00794AE0)
    /* D5BEC 001D5BEC E04A8424 */  addiu      $4, $4, %lo(D_00794AE0)
    /* D5BF0 001D5BF0 B082110C */  jal        func_00460ac0
    /* D5BF4 001D5BF4 00000000 */   nop
    /* D5BF8 001D5BF8 2D880000 */  daddu      $17, $0, $0
    /* D5BFC 001D5BFC FFFF1032 */  andi       $16, $16, 0xFFFF
    /* D5C00 001D5C00 09000010 */  b          .L001D5C28
    /* D5C04 001D5C04 00000000 */   nop
  .L001D5C08:
    /* D5C08 001D5C08 0000448E */  lw         $4, 0x0($18)
    /* D5C0C 001D5C0C 03008010 */  beqz       $4, .L001D5C1C
    /* D5C10 001D5C10 00000000 */   nop
    /* D5C14 001D5C14 1C16120C */  jal        func_00485870
    /* D5C18 001D5C18 00000000 */   nop
  .L001D5C1C:
    /* D5C1C 001D5C1C 01002226 */  addiu      $2, $17, 0x1
    /* D5C20 001D5C20 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* D5C24 001D5C24 04005226 */  addiu      $18, $18, 0x4
  .L001D5C28:
    /* D5C28 001D5C28 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* D5C2C 001D5C2C 2A105000 */  slt        $2, $2, $16
    /* D5C30 001D5C30 F5FF4014 */  bnez       $2, .L001D5C08
    /* D5C34 001D5C34 00000000 */   nop
    /* D5C38 001D5C38 2D206002 */  daddu      $4, $19, $0
    /* D5C3C 001D5C3C 1005120C */  jal        func_00481440
    /* D5C40 001D5C40 00000000 */   nop
    /* D5C44 001D5C44 6482110C */  jal        func_00460990
    /* D5C48 001D5C48 00000000 */   nop
    /* D5C4C 001D5C4C 2D284000 */  daddu      $5, $2, $0
    /* D5C50 001D5C50 000040AC */  sw         $0, 0x0($2)
    /* D5C54 001D5C54 040040AC */  sw         $0, 0x4($2)
    /* D5C58 001D5C58 1D00033C */  lui        $3, %hi(func_001d5ac0)
    /* D5C5C 001D5C5C C05A6324 */  addiu      $3, $3, %lo(func_001d5ac0)
    /* D5C60 001D5C60 080043AC */  sw         $3, 0x8($2)
    /* D5C64 001D5C64 ACB3838F */  lw         $3, -0x4C54($28)
    /* D5C68 001D5C68 100043AC */  sw         $3, 0x10($2)
    /* D5C6C 001D5C6C 7900043C */  lui        $4, %hi(D_00794C00)
    /* D5C70 001D5C70 004C8424 */  addiu      $4, $4, %lo(D_00794C00)
    /* D5C74 001D5C74 B082110C */  jal        func_00460ac0
    /* D5C78 001D5C78 00000000 */   nop
  .L001D5C7C:
    /* D5C7C 001D5C7C 4000BFDF */  ld         $31, 0x40($29)
    /* D5C80 001D5C80 3000B37B */  lq         $19, 0x30($29)
    /* D5C84 001D5C84 2000B27B */  lq         $18, 0x20($29)
    /* D5C88 001D5C88 1000B17B */  lq         $17, 0x10($29)
    /* D5C8C 001D5C8C 0000B07B */  lq         $16, 0x0($29)
    /* D5C90 001D5C90 5000BD27 */  addiu      $29, $29, 0x50
    /* D5C94 001D5C94 0800E003 */  jr         $31
    /* D5C98 001D5C98 00000000 */   nop
    /* D5C9C 001D5C9C 00000000 */  nop
.size func_001d5b20, 0x180
