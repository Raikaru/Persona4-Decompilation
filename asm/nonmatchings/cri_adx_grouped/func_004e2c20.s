.section .text
.set noat
.set noreorder
glabel func_004e2c20
    /* 3E2C20 004E2C20 80FDBD27 */  addiu      $29, $29, -0x280
    /* 3E2C24 004E2C24 6002B0FF */  sd         $16, 0x260($29)
    /* 3E2C28 004E2C28 2D808000 */  daddu      $16, $4, $0
    /* 3E2C2C 004E2C2C 6802B1FF */  sd         $17, 0x268($29)
    /* 3E2C30 004E2C30 05000016 */  bnez       $16, .L004E2C48
    /* 3E2C34 004E2C34 7002BFFF */   sd        $31, 0x270($29)
    /* 3E2C38 004E2C38 7600043C */  lui        $4, %hi(D_0075A570)
    /* 3E2C3C 004E2C3C 1F000010 */  b          .L004E2CBC
    /* 3E2C40 004E2C40 70A58424 */   addiu     $4, $4, %lo(D_0075A570)
    /* 3E2C44 004E2C44 00000000 */  nop
  .L004E2C48:
    /* 3E2C48 004E2C48 3001B127 */  addiu      $17, $29, 0x130
    /* 3E2C4C 004E2C4C 2D20A003 */  daddu      $4, $29, $0
    /* 3E2C50 004E2C50 2D282002 */  daddu      $5, $17, $0
    /* 3E2C54 004E2C54 9E87130C */  jal        func_004e1e78
    /* 3E2C58 004E2C58 2D300002 */   daddu     $6, $16, $0
    /* 3E2C5C 004E2C5C 3001A283 */  lb         $2, 0x130($29)
    /* 3E2C60 004E2C60 05004014 */  bnez       $2, .L004E2C78
    /* 3E2C64 004E2C64 2D300002 */   daddu     $6, $16, $0
    /* 3E2C68 004E2C68 7600043C */  lui        $4, %hi(D_0075A570)
    /* 3E2C6C 004E2C6C 13000010 */  b          .L004E2CBC
    /* 3E2C70 004E2C70 70A58424 */   addiu     $4, $4, %lo(D_0075A570)
    /* 3E2C74 004E2C74 00000000 */  nop
  .L004E2C78:
    /* 3E2C78 004E2C78 2D20A003 */  daddu      $4, $29, $0
    /* 3E2C7C 004E2C7C 0C87130C */  jal        func_004e1c30
    /* 3E2C80 004E2C80 2D282002 */   daddu     $5, $17, $0
    /* 3E2C84 004E2C84 2D804000 */  daddu      $16, $2, $0
    /* 3E2C88 004E2C88 05000056 */  bnel       $16, $0, .L004E2CA0
    /* 3E2C8C 004E2C8C 5400028E */   lw        $2, 0x54($16)
    /* 3E2C90 004E2C90 7600043C */  lui        $4, %hi(D_0075A5C0)
    /* 3E2C94 004E2C94 6A85130C */  jal        func_004e15a8
    /* 3E2C98 004E2C98 C0A58424 */   addiu     $4, $4, %lo(D_0075A5C0)
    /* 3E2C9C 004E2C9C 5400028E */  lw         $2, 0x54($16)
  .L004E2CA0:
    /* 3E2CA0 004E2CA0 05004050 */  beql       $2, $0, .L004E2CB8
    /* 3E2CA4 004E2CA4 7600043C */   lui       $4, %hi(D_0075A5E8)
    /* 3E2CA8 004E2CA8 09F84000 */  jalr       $2
    /* 3E2CAC 004E2CAC 2D202002 */   daddu     $4, $17, $0
    /* 3E2CB0 004E2CB0 06000010 */  b          .L004E2CCC
    /* 3E2CB4 004E2CB4 6002B0DF */   ld        $16, 0x260($29)
  .L004E2CB8:
    /* 3E2CB8 004E2CB8 E8A58424 */  addiu      $4, $4, %lo(D_0075A5E8)
  .L004E2CBC:
    /* 3E2CBC 004E2CBC 6A85130C */  jal        func_004e15a8
    /* 3E2CC0 004E2CC0 00000000 */   nop
    /* 3E2CC4 004E2CC4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3E2CC8 004E2CC8 6002B0DF */  ld         $16, 0x260($29)
  .L004E2CCC:
    /* 3E2CCC 004E2CCC 6802B1DF */  ld         $17, 0x268($29)
    /* 3E2CD0 004E2CD0 7002BFDF */  ld         $31, 0x270($29)
    /* 3E2CD4 004E2CD4 0800E003 */  jr         $31
    /* 3E2CD8 004E2CD8 8002BD27 */   addiu     $29, $29, 0x280
    /* 3E2CDC 004E2CDC 00000000 */  nop
.size func_004e2c20, 0xc0
