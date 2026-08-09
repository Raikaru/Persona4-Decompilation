.section .text
.set noat
.set noreorder
glabel func_003cad40
    /* 2CAD40 003CAD40 0CB7868F */  lw         $6, -0x48F4($28)
    /* 2CAD44 003CAD44 3D00053C */  lui        $5, %hi(func_003cac30)
    /* 2CAD48 003CAD48 8800033C */  lui        $3, %hi(D_008872E8)
    /* 2CAD4C 003CAD4C 30ACA524 */  addiu      $5, $5, %lo(func_003cac30)
    /* 2CAD50 003CAD50 2D108000 */  daddu      $2, $4, $0
    /* 2CAD54 003CAD54 21308600 */  addu       $6, $4, $6
    /* 2CAD58 003CAD58 0000C0AC */  sw         $0, 0x0($6)
    /* 2CAD5C 003CAD5C E8726394 */  lhu        $3, %lo(D_008872E8)($3)
    /* 2CAD60 003CAD60 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2CAD64 003CAD64 600083A4 */  sh         $3, 0x60($4)
    /* 2CAD68 003CAD68 1000838C */  lw         $3, 0x10($4)
    /* 2CAD6C 003CAD6C 0400C3AC */  sw         $3, 0x4($6)
    /* 2CAD70 003CAD70 0800E003 */  jr         $31
    /* 2CAD74 003CAD74 100085AC */   sw        $5, 0x10($4)
    /* 2CAD78 003CAD78 00000000 */  nop
    /* 2CAD7C 003CAD7C 00000000 */  nop
.size func_003cad40, 0x40
