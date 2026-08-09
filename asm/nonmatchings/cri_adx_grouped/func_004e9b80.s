.section .text
.set noat
.set noreorder
glabel func_004e9b80
    /* 3E9B80 004E9B80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E9B84 004E9B84 0000B0FF */  sd         $16, 0x0($29)
    /* 3E9B88 004E9B88 2D808000 */  daddu      $16, $4, $0
    /* 3E9B8C 004E9B8C 0800B1FF */  sd         $17, 0x8($29)
    /* 3E9B90 004E9B90 1000BFFF */  sd         $31, 0x10($29)
    /* 3E9B94 004E9B94 2800048E */  lw         $4, 0x28($16)
    /* 3E9B98 004E9B98 09008054 */  bnel       $4, $0, .L004E9BC0
    /* 3E9B9C 004E9B9C 2000028E */   lw        $2, 0x20($16)
    /* 3E9BA0 004E9BA0 7600043C */  lui        $4, %hi(D_0075BDB0)
    /* 3E9BA4 004E9BA4 0000B0DF */  ld         $16, 0x0($29)
    /* 3E9BA8 004E9BA8 0800B1DF */  ld         $17, 0x8($29)
    /* 3E9BAC 004E9BAC B0BD8424 */  addiu      $4, $4, %lo(D_0075BDB0)
    /* 3E9BB0 004E9BB0 1000BFDF */  ld         $31, 0x10($29)
    /* 3E9BB4 004E9BB4 1EA61308 */  j          func_004e9878
    /* 3E9BB8 004E9BB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E9BBC 004E9BBC 00000000 */  nop
  .L004E9BC0:
    /* 3E9BC0 004E9BC0 40110200 */  sll        $2, $2, 5
    /* 3E9BC4 004E9BC4 21100202 */  addu       $2, $16, $2
    /* 3E9BC8 004E9BC8 FE47130C */  jal        func_004d1ff8
    /* 3E9BCC 004E9BCC 38005124 */   addiu     $17, $2, 0x38
    /* 3E9BD0 004E9BD0 2D184000 */  daddu      $3, $2, $0
    /* 3E9BD4 004E9BD4 03000424 */  addiu      $4, $0, 0x3
    /* 3E9BD8 004E9BD8 11006410 */  beq        $3, $4, .L004E9C20
    /* 3E9BDC 004E9BDC 04006228 */   slti      $2, $3, 0x4
    /* 3E9BE0 004E9BE0 07004010 */  beqz       $2, .L004E9C00
    /* 3E9BE4 004E9BE4 04000224 */   addiu     $2, $0, 0x4
    /* 3E9BE8 004E9BE8 02000224 */  addiu      $2, $0, 0x2
    /* 3E9BEC 004E9BEC 08006210 */  beq        $3, $2, .L004E9C10
    /* 3E9BF0 004E9BF0 00000000 */   nop
    /* 3E9BF4 004E9BF4 0F000010 */  b          .L004E9C34
    /* 3E9BF8 004E9BF8 0000B0DF */   ld        $16, 0x0($29)
    /* 3E9BFC 004E9BFC 00000000 */  nop
  .L004E9C00:
    /* 3E9C00 004E9C00 0B006250 */  beql       $3, $2, .L004E9C30
    /* 3E9C04 004E9C04 010004A2 */   sb        $4, 0x1($16)
    /* 3E9C08 004E9C08 0A000010 */  b          .L004E9C34
    /* 3E9C0C 004E9C0C 0000B0DF */   ld        $16, 0x0($29)
  .L004E9C10:
    /* 3E9C10 004E9C10 2848130C */  jal        func_004d20a0
    /* 3E9C14 004E9C14 2800048E */   lw        $4, 0x28($16)
    /* 3E9C18 004E9C18 05000010 */  b          .L004E9C30
    /* 3E9C1C 004E9C1C 1C0022AE */   sw        $2, 0x1C($17)
  .L004E9C20:
    /* 3E9C20 004E9C20 2C00038E */  lw         $3, 0x2C($16)
    /* 3E9C24 004E9C24 02000224 */  addiu      $2, $0, 0x2
    /* 3E9C28 004E9C28 180022AE */  sw         $2, 0x18($17)
    /* 3E9C2C 004E9C2C 1C0023AE */  sw         $3, 0x1C($17)
  .L004E9C30:
    /* 3E9C30 004E9C30 0000B0DF */  ld         $16, 0x0($29)
  .L004E9C34:
    /* 3E9C34 004E9C34 0800B1DF */  ld         $17, 0x8($29)
    /* 3E9C38 004E9C38 1000BFDF */  ld         $31, 0x10($29)
    /* 3E9C3C 004E9C3C 0800E003 */  jr         $31
    /* 3E9C40 004E9C40 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E9C44 004E9C44 00000000 */  nop
.size func_004e9b80, 0xc8
