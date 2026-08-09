.section .text
.set noat
.set noreorder
glabel func_004e8d68
    /* 3E8D68 004E8D68 07008010 */  beqz       $4, .L004E8D88
    /* 3E8D6C 004E8D6C 01000224 */   addiu     $2, $0, 0x1
    /* 3E8D70 004E8D70 06008214 */  bne        $4, $2, .L004E8D8C
    /* 3E8D74 004E8D74 7300033C */   lui       $3, %hi(D_00734380)
    /* 3E8D78 004E8D78 7300023C */  lui        $2, %hi(D_00734380)
    /* 3E8D7C 004E8D7C 0800E003 */  jr         $31
    /* 3E8D80 004E8D80 804344AC */   sw        $4, %lo(D_00734380)($2)
    /* 3E8D84 004E8D84 00000000 */  nop
  .L004E8D88:
    /* 3E8D88 004E8D88 7300033C */  lui        $3, %hi(D_00734380)
  .L004E8D8C:
    /* 3E8D8C 004E8D8C 01800234 */  ori        $2, $0, 0x8001
    /* 3E8D90 004E8D90 0800E003 */  jr         $31
    /* 3E8D94 004E8D94 804362AC */   sw        $2, %lo(D_00734380)($3)
.size func_004e8d68, 0x30
