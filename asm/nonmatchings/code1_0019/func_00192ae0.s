.section .text
.set noat
.set noreorder
glabel func_00192ae0
    /* 92AE0 00192AE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 92AE4 00192AE4 0000BFFF */  sd         $31, 0x0($29)
    /* 92AE8 00192AE8 88A08427 */  addiu      $4, $28, -0x5F78
    /* 92AEC 00192AEC E048110C */  jal        func_00452380
    /* 92AF0 00192AF0 00000000 */   nop
    /* 92AF4 00192AF4 05004010 */  beqz       $2, .L00192B0C
    /* 92AF8 00192AF8 00000000 */   nop
    /* 92AFC 00192AFC ACB3828F */  lw         $2, -0x4C54($28)
    /* 92B00 00192B00 C80D448C */  lw         $4, 0xDC8($2)
    /* 92B04 00192B04 2048110C */  jal        func_00452080
    /* 92B08 00192B08 00000000 */   nop
  .L00192B0C:
    /* 92B0C 00192B0C 0000BFDF */  ld         $31, 0x0($29)
    /* 92B10 00192B10 1000BD27 */  addiu      $29, $29, 0x10
    /* 92B14 00192B14 0800E003 */  jr         $31
    /* 92B18 00192B18 00000000 */   nop
    /* 92B1C 00192B1C 00000000 */  nop
.size func_00192ae0, 0x40
