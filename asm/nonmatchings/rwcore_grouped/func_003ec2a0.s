.section .text
.set noat
.set noreorder
glabel func_003ec2a0
    /* 2EC2A0 003EC2A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC2A4 003EC2A4 8800023C */  lui        $2, %hi(D_00887368)
    /* 2EC2A8 003EC2A8 1000BFFF */  sd         $31, 0x10($29)
    /* 2EC2AC 003EC2AC 2D300000 */  daddu      $6, $0, $0
    /* 2EC2B0 003EC2B0 0000B07F */  sq         $16, 0x0($29)
    /* 2EC2B4 003EC2B4 6873428C */  lw         $2, %lo(D_00887368)($2)
    /* 2EC2B8 003EC2B8 2D808000 */  daddu      $16, $4, $0
    /* 2EC2BC 003EC2BC 2D200000 */  daddu      $4, $0, $0
    /* 2EC2C0 003EC2C0 09F84000 */  jalr       $2
    /* 2EC2C4 003EC2C4 2D280002 */   daddu     $5, $16, $0
    /* 2EC2C8 003EC2C8 2D100002 */  daddu      $2, $16, $0
    /* 2EC2CC 003EC2CC 1000BFDF */  ld         $31, 0x10($29)
    /* 2EC2D0 003EC2D0 0000B07B */  lq         $16, 0x0($29)
    /* 2EC2D4 003EC2D4 0800E003 */  jr         $31
    /* 2EC2D8 003EC2D8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC2DC 003EC2DC 00000000 */  nop
.size func_003ec2a0, 0x40
