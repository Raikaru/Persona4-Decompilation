.section .text
.set noat
.set noreorder
glabel func_003e1f50
    /* 2E1F50 003E1F50 80B7848F */  lw         $4, -0x4880($28)
    /* 2E1F54 003E1F54 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E1F58 003E1F58 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E1F5C 003E1F5C 21186400 */  addu       $3, $3, $4
    /* 2E1F60 003E1F60 2000658C */  lw         $5, 0x20($3)
    /* 2E1F64 003E1F64 0000A48C */  lw         $4, 0x0($5)
    /* 2E1F68 003E1F68 16008510 */  beq        $4, $5, .L003E1FC4
    /* 2E1F6C 003E1F6C 2400668C */   lw        $6, 0x24($3)
    /* 2E1F70 003E1F70 0000C38C */  lw         $3, 0x0($6)
    /* 2E1F74 003E1F74 0A006610 */  beq        $3, $6, .L003E1FA0
    /* 2E1F78 003E1F78 00000000 */   nop
    /* 2E1F7C 003E1F7C 0400C38C */  lw         $3, 0x4($6)
    /* 2E1F80 003E1F80 000064AC */  sw         $4, 0x0($3)
    /* 2E1F84 003E1F84 040083AC */  sw         $3, 0x4($4)
    /* 2E1F88 003E1F88 0400A38C */  lw         $3, 0x4($5)
    /* 2E1F8C 003E1F8C 000066AC */  sw         $6, 0x0($3)
    /* 2E1F90 003E1F90 0400C3AC */  sw         $3, 0x4($6)
    /* 2E1F94 003E1F94 0000A5AC */  sw         $5, 0x0($5)
    /* 2E1F98 003E1F98 0A000010 */  b          .L003E1FC4
    /* 2E1F9C 003E1F9C 0400A5AC */   sw        $5, 0x4($5)
  .L003E1FA0:
    /* 2E1FA0 003E1FA0 0000C4AC */  sw         $4, 0x0($6)
    /* 2E1FA4 003E1FA4 0000C38C */  lw         $3, 0x0($6)
    /* 2E1FA8 003E1FA8 040066AC */  sw         $6, 0x4($3)
    /* 2E1FAC 003E1FAC 0400A38C */  lw         $3, 0x4($5)
    /* 2E1FB0 003E1FB0 0400C3AC */  sw         $3, 0x4($6)
    /* 2E1FB4 003E1FB4 0400C38C */  lw         $3, 0x4($6)
    /* 2E1FB8 003E1FB8 000066AC */  sw         $6, 0x0($3)
    /* 2E1FBC 003E1FBC 0000A5AC */  sw         $5, 0x0($5)
    /* 2E1FC0 003E1FC0 0400A5AC */  sw         $5, 0x4($5)
  .L003E1FC4:
    /* 2E1FC4 003E1FC4 80B7848F */  lw         $4, -0x4880($28)
    /* 2E1FC8 003E1FC8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E1FCC 003E1FCC E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E1FD0 003E1FD0 21186400 */  addu       $3, $3, $4
    /* 2E1FD4 003E1FD4 240065AC */  sw         $5, 0x24($3)
    /* 2E1FD8 003E1FD8 200066AC */  sw         $6, 0x20($3)
    /* 2E1FDC 003E1FDC 0800E003 */  jr         $31
    /* 2E1FE0 003E1FE0 080060AC */   sw        $0, 0x8($3)
    /* 2E1FE4 003E1FE4 00000000 */  nop
    /* 2E1FE8 003E1FE8 00000000 */  nop
    /* 2E1FEC 003E1FEC 00000000 */  nop
.size func_003e1f50, 0xa0
