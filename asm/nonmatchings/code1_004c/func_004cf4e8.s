.section .text
.set noat
.set noreorder
glabel func_004cf4e8
    /* 3CF4E8 004CF4E8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CF4EC 004CF4EC 2D580001 */  daddu      $11, $8, $0
    /* 3CF4F0 004CF4F0 2000B0FF */  sd         $16, 0x20($29)
    /* 3CF4F4 004CF4F4 2D80E000 */  daddu      $16, $7, $0
    /* 3CF4F8 004CF4F8 2800B1FF */  sd         $17, 0x28($29)
    /* 3CF4FC 004CF4FC 2D88C000 */  daddu      $17, $6, $0
    /* 3CF500 004CF500 0000A9AF */  sw         $9, 0x0($29)
    /* 3CF504 004CF504 1400A927 */  addiu      $9, $29, 0x14
    /* 3CF508 004CF508 1800A227 */  addiu      $2, $29, 0x18
    /* 3CF50C 004CF50C 1300A827 */  addiu      $8, $29, 0x13
    /* 3CF510 004CF510 1000A627 */  addiu      $6, $29, 0x10
    /* 3CF514 004CF514 1200A727 */  addiu      $7, $29, 0x12
    /* 3CF518 004CF518 1500AA27 */  addiu      $10, $29, 0x15
    /* 3CF51C 004CF51C 3000BFFF */  sd         $31, 0x30($29)
    /* 3CF520 004CF520 DC15130C */  jal        func_004c5770
    /* 3CF524 004CF524 0800A2AF */   sw        $2, 0x8($29)
    /* 3CF528 004CF528 1500A383 */  lb         $3, 0x15($29)
    /* 3CF52C 004CF52C 1300A483 */  lb         $4, 0x13($29)
    /* 3CF530 004CF530 000003AE */  sw         $3, 0x0($16)
    /* 3CF534 004CF534 3000BFDF */  ld         $31, 0x30($29)
    /* 3CF538 004CF538 000024AE */  sw         $4, 0x0($17)
    /* 3CF53C 004CF53C 2000B0DF */  ld         $16, 0x20($29)
    /* 3CF540 004CF540 2800B1DF */  ld         $17, 0x28($29)
    /* 3CF544 004CF544 0800E003 */  jr         $31
    /* 3CF548 004CF548 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CF54C 004CF54C 00000000 */  nop
.size func_004cf4e8, 0x68
