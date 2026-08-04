.section .text
.set noat
.set noreorder
glabel func_003ca960
    /* 2CA960 003CA960 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2CA964 003CA964 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CA968 003CA968 0000BFFF */  sd         $31, 0x0($29)
    /* 2CA96C 003CA96C 2D288000 */  daddu      $5, $4, $0
    /* 2CA970 003CA970 0C00878C */  lw         $7, 0xC($4)
    /* 2CA974 003CA974 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CA978 003CA978 1000868C */  lw         $6, 0x10($4)
    /* 2CA97C 003CA97C 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2CA980 003CA980 0000C7AC */  sw         $7, 0x0($6)
    /* 2CA984 003CA984 1000878C */  lw         $7, 0x10($4)
    /* 2CA988 003CA988 0C00868C */  lw         $6, 0xC($4)
    /* 2CA98C 003CA98C 0400C7AC */  sw         $7, 0x4($6)
    /* 2CA990 003CA990 0000878C */  lw         $7, 0x0($4)
    /* 2CA994 003CA994 0400868C */  lw         $6, 0x4($4)
    /* 2CA998 003CA998 0000C7AC */  sw         $7, 0x0($6)
    /* 2CA99C 003CA99C 0400868C */  lw         $6, 0x4($4)
    /* 2CA9A0 003CA9A0 0000848C */  lw         $4, 0x0($4)
    /* 2CA9A4 003CA9A4 040086AC */  sw         $6, 0x4($4)
    /* 2CA9A8 003CA9A8 18B7848F */  lw         $4, -0x48E8($28)
    /* 2CA9AC 003CA9AC FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2CA9B0 003CA9B0 21186400 */  addu       $3, $3, $4
    /* 2CA9B4 003CA9B4 09F84000 */  jalr       $2
    /* 2CA9B8 003CA9B8 0400648C */   lw        $4, 0x4($3)
    /* 2CA9BC 003CA9BC 0000BFDF */  ld         $31, 0x0($29)
    /* 2CA9C0 003CA9C0 01000224 */  addiu      $2, $0, 0x1
    /* 2CA9C4 003CA9C4 0800E003 */  jr         $31
    /* 2CA9C8 003CA9C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 2CA9CC 003CA9CC 00000000 */  nop
.size func_003ca960, 0x70
