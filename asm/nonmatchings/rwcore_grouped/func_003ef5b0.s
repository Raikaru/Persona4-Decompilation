.section .text
.set noat
.set noreorder
glabel func_003ef5b0
    /* 2EF5B0 003EF5B0 0400A28C */  lw         $2, 0x4($5)
    /* 2EF5B4 003EF5B4 0C004014 */  bnez       $2, .L003EF5E8
    /* 2EF5B8 003EF5B8 00000000 */   nop
  .L003EF5BC:
    /* 2EF5BC 003EF5BC 0400A4AC */  sw         $4, 0x4($5)
    /* 2EF5C0 003EF5C0 08008324 */  addiu      $3, $4, 0x8
    /* 2EF5C4 003EF5C4 0800878C */  lw         $7, 0x8($4)
    /* 2EF5C8 003EF5C8 0800A624 */  addiu      $6, $5, 0x8
    /* 2EF5CC 003EF5CC 2D10A000 */  daddu      $2, $5, $0
    /* 2EF5D0 003EF5D0 0800A7AC */  sw         $7, 0x8($5)
    /* 2EF5D4 003EF5D4 0C00A3AC */  sw         $3, 0xC($5)
    /* 2EF5D8 003EF5D8 0800838C */  lw         $3, 0x8($4)
    /* 2EF5DC 003EF5DC 040066AC */  sw         $6, 0x4($3)
    /* 2EF5E0 003EF5E0 08000010 */  b          .L003EF604
    /* 2EF5E4 003EF5E4 080086AC */   sw        $6, 0x8($4)
  .L003EF5E8:
    /* 2EF5E8 003EF5E8 0800A38C */  lw         $3, 0x8($5)
    /* 2EF5EC 003EF5EC 0C00A28C */  lw         $2, 0xC($5)
    /* 2EF5F0 003EF5F0 000043AC */  sw         $3, 0x0($2)
    /* 2EF5F4 003EF5F4 0C00A38C */  lw         $3, 0xC($5)
    /* 2EF5F8 003EF5F8 0800A28C */  lw         $2, 0x8($5)
    /* 2EF5FC 003EF5FC EFFF0010 */  b          .L003EF5BC
    /* 2EF600 003EF600 040043AC */   sw        $3, 0x4($2)
  .L003EF604:
    /* 2EF604 003EF604 0800E003 */  jr         $31
    /* 2EF608 003EF608 00000000 */   nop
    /* 2EF60C 003EF60C 00000000 */  nop
.size func_003ef5b0, 0x60
