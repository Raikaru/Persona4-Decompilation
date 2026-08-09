.section .text
.set noat
.set noreorder
glabel func_003ec2e0
    /* 2EC2E0 003EC2E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC2E4 003EC2E4 8800023C */  lui        $2, %hi(D_00887388)
    /* 2EC2E8 003EC2E8 1000BFFF */  sd         $31, 0x10($29)
    /* 2EC2EC 003EC2EC 2D300000 */  daddu      $6, $0, $0
    /* 2EC2F0 003EC2F0 0000B07F */  sq         $16, 0x0($29)
    /* 2EC2F4 003EC2F4 8873428C */  lw         $2, %lo(D_00887388)($2)
    /* 2EC2F8 003EC2F8 2D808000 */  daddu      $16, $4, $0
    /* 2EC2FC 003EC2FC 2D200000 */  daddu      $4, $0, $0
    /* 2EC300 003EC300 09F84000 */  jalr       $2
    /* 2EC304 003EC304 2D280002 */   daddu     $5, $16, $0
    /* 2EC308 003EC308 22000492 */  lbu        $4, 0x22($16)
    /* 2EC30C 003EC30C E7FF0324 */  addiu      $3, $0, -0x19
    /* 2EC310 003EC310 2D100002 */  daddu      $2, $16, $0
    /* 2EC314 003EC314 24188300 */  and        $3, $4, $3
    /* 2EC318 003EC318 220003A2 */  sb         $3, 0x22($16)
    /* 2EC31C 003EC31C 1000BFDF */  ld         $31, 0x10($29)
    /* 2EC320 003EC320 0000B07B */  lq         $16, 0x0($29)
    /* 2EC324 003EC324 0800E003 */  jr         $31
    /* 2EC328 003EC328 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC32C 003EC32C 00000000 */  nop
.size func_003ec2e0, 0x50
