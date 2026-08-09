.section .text
.set noat
.set noreorder
glabel func_003e8b10
    /* 2E8B10 003E8B10 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2E8B14 003E8B14 4000BFFF */  sd         $31, 0x40($29)
    /* 2E8B18 003E8B18 3000B37F */  sq         $19, 0x30($29)
    /* 2E8B1C 003E8B1C 2000B27F */  sq         $18, 0x20($29)
    /* 2E8B20 003E8B20 1000B17F */  sq         $17, 0x10($29)
    /* 2E8B24 003E8B24 0000B07F */  sq         $16, 0x0($29)
    /* 2E8B28 003E8B28 8800103C */  lui        $16, %hi(D_00887404)
    /* 2E8B2C 003E8B2C 04741026 */  addiu      $16, $16, %lo(D_00887404)
    /* 2E8B30 003E8B30 0000028E */  lw         $2, 0x0($16)
    /* 2E8B34 003E8B34 01004238 */  xori       $2, $2, 0x1
    /* 2E8B38 003E8B38 0100512C */  sltiu      $17, $2, 0x1
    /* 2E8B3C 003E8B3C 37002012 */  beqz       $17, .L003E8C1C
    /* 2E8B40 003E8B40 2D908000 */   daddu     $18, $4, $0
    /* 2E8B44 003E8B44 2B881200 */  sltu       $17, $0, $18
    /* 2E8B48 003E8B48 2A002012 */  beqz       $17, .L003E8BF4
    /* 2E8B4C 003E8B4C 00000000 */   nop
    /* 2E8B50 003E8B50 1405100C */  jal        func_00401450
    /* 2E8B54 003E8B54 00000000 */   nop
    /* 2E8B58 003E8B58 2D984000 */  daddu      $19, $2, $0
    /* 2E8B5C 003E8B5C 2B881300 */  sltu       $17, $0, $19
    /* 2E8B60 003E8B60 16002012 */  beqz       $17, .L003E8BBC
    /* 2E8B64 003E8B64 00000000 */   nop
    /* 2E8B68 003E8B68 8800063C */  lui        $6, %hi(D_008872F0)
    /* 2E8B6C 003E8B6C 8800073C */  lui        $7, %hi(jtbl_008873E8)
    /* 2E8B70 003E8B70 2D206002 */  daddu      $4, $19, $0
    /* 2E8B74 003E8B74 04000524 */  addiu      $5, $0, 0x4
    /* 2E8B78 003E8B78 F072C624 */  addiu      $6, $6, %lo(D_008872F0)
    /* 2E8B7C 003E8B7C E873E724 */  addiu      $7, $7, %lo(jtbl_008873E8)
    /* 2E8B80 003E8B80 FCA10F0C */  jal        func_003e87f0
    /* 2E8B84 003E8B84 2D400000 */   daddu     $8, $0, $0
    /* 2E8B88 003E8B88 2D384002 */  daddu      $7, $18, $0
    /* 2E8B8C 003E8B8C 2D206002 */  daddu      $4, $19, $0
    /* 2E8B90 003E8B90 2D280000 */  daddu      $5, $0, $0
    /* 2E8B94 003E8B94 2D300000 */  daddu      $6, $0, $0
    /* 2E8B98 003E8B98 FCA10F0C */  jal        func_003e87f0
    /* 2E8B9C 003E8B9C 2D400000 */   daddu     $8, $0, $0
    /* 2E8BA0 003E8BA0 08004014 */  bnez       $2, .L003E8BC4
    /* 2E8BA4 003E8BA4 00000000 */   nop
    /* 2E8BA8 003E8BA8 2D880000 */  daddu      $17, $0, $0
  .L003E8BAC:
    /* 2E8BAC 003E8BAC 03002012 */  beqz       $17, .L003E8BBC
    /* 2E8BB0 003E8BB0 00000000 */   nop
    /* 2E8BB4 003E8BB4 02000224 */  addiu      $2, $0, 0x2
    /* 2E8BB8 003E8BB8 000002AE */  sw         $2, 0x0($16)
  .L003E8BBC:
    /* 2E8BBC 003E8BBC 21000010 */  b          .L003E8C44
    /* 2E8BC0 003E8BC0 2D102002 */   daddu     $2, $17, $0
  .L003E8BC4:
    /* 2E8BC4 003E8BC4 8800063C */  lui        $6, %hi(D_00887328)
    /* 2E8BC8 003E8BC8 2D206002 */  daddu      $4, $19, $0
    /* 2E8BCC 003E8BCC 0B000524 */  addiu      $5, $0, 0xB
    /* 2E8BD0 003E8BD0 2873C624 */  addiu      $6, $6, %lo(D_00887328)
    /* 2E8BD4 003E8BD4 2D380000 */  daddu      $7, $0, $0
    /* 2E8BD8 003E8BD8 FCA10F0C */  jal        func_003e87f0
    /* 2E8BDC 003E8BDC 1D000824 */   addiu     $8, $0, 0x1D
    /* 2E8BE0 003E8BE0 B8B7828F */  lw         $2, -0x4848($28)
    /* 2E8BE4 003E8BE4 01001124 */  addiu      $17, $0, 0x1
    /* 2E8BE8 003E8BE8 01004224 */  addiu      $2, $2, 0x1
    /* 2E8BEC 003E8BEC EFFF0010 */  b          .L003E8BAC
    /* 2E8BF0 003E8BF0 B8B782AF */   sw        $2, -0x4848($28)
  .L003E8BF4:
    /* 2E8BF4 003E8BF4 01000324 */  addiu      $3, $0, 0x1
    /* 2E8BF8 003E8BF8 0080023C */  lui        $2, (0x80000016 >> 16)
    /* 2E8BFC 003E8BFC 5800A3AF */  sw         $3, 0x58($29)
    /* 2E8C00 003E8C00 647D0F0C */  jal        func_003df590
    /* 2E8C04 003E8C04 16004434 */   ori       $4, $2, (0x80000016 & 0xFFFF)
    /* 2E8C08 003E8C08 5C00A2AF */  sw         $2, 0x5C($29)
    /* 2E8C0C 003E8C0C 347D0F0C */  jal        func_003df4d0
    /* 2E8C10 003E8C10 5800A427 */   addiu     $4, $29, 0x58
    /* 2E8C14 003E8C14 E9FF0010 */  b          .L003E8BBC
    /* 2E8C18 003E8C18 00000000 */   nop
  .L003E8C1C:
    /* 2E8C1C 003E8C1C 01000324 */  addiu      $3, $0, 0x1
    /* 2E8C20 003E8C20 0080023C */  lui        $2, (0x80000001 >> 16)
    /* 2E8C24 003E8C24 5000A3AF */  sw         $3, 0x50($29)
    /* 2E8C28 003E8C28 647D0F0C */  jal        func_003df590
    /* 2E8C2C 003E8C2C 01004434 */   ori       $4, $2, (0x80000001 & 0xFFFF)
    /* 2E8C30 003E8C30 5400A2AF */  sw         $2, 0x54($29)
    /* 2E8C34 003E8C34 347D0F0C */  jal        func_003df4d0
    /* 2E8C38 003E8C38 5000A427 */   addiu     $4, $29, 0x50
    /* 2E8C3C 003E8C3C DFFF0010 */  b          .L003E8BBC
    /* 2E8C40 003E8C40 00000000 */   nop
  .L003E8C44:
    /* 2E8C44 003E8C44 4000BFDF */  ld         $31, 0x40($29)
    /* 2E8C48 003E8C48 3000B37B */  lq         $19, 0x30($29)
    /* 2E8C4C 003E8C4C 2000B27B */  lq         $18, 0x20($29)
    /* 2E8C50 003E8C50 1000B17B */  lq         $17, 0x10($29)
    /* 2E8C54 003E8C54 0000B07B */  lq         $16, 0x0($29)
    /* 2E8C58 003E8C58 0800E003 */  jr         $31
    /* 2E8C5C 003E8C5C 6000BD27 */   addiu     $29, $29, 0x60
.size func_003e8b10, 0x150
