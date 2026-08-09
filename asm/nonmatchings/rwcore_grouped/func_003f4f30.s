.section .text
.set noat
.set noreorder
glabel func_003f4f30
    /* 2F4F30 003F4F30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2F4F34 003F4F34 0000BFFF */  sd         $31, 0x0($29)
    /* 2F4F38 003F4F38 A0D20F0C */  jal        func_003f4a80
    /* 2F4F3C 003F4F3C 00000000 */   nop
    /* 2F4F40 003F4F40 F8B7838F */  lw         $3, -0x4808($28)
    /* 2F4F44 003F4F44 06006010 */  beqz       $3, .L003F4F60
    /* 2F4F48 003F4F48 E8B780AF */   sw        $0, -0x4818($28)
    /* 2F4F4C 003F4F4C F4B780AF */  sw         $0, -0x480C($28)
  .L003F4F50:
    /* 2F4F50 003F4F50 F8B780AF */  sw         $0, -0x4808($28)
    /* 2F4F54 003F4F54 ECB780AF */  sw         $0, -0x4814($28)
    /* 2F4F58 003F4F58 07000010 */  b          .L003F4F78
    /* 2F4F5C 003F4F5C F0B780A3 */   sb        $0, -0x4810($28)
  .L003F4F60:
    /* 2F4F60 003F4F60 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2F4F64 003F4F64 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2F4F68 003F4F68 09F84000 */  jalr       $2
    /* 2F4F6C 003F4F6C F4B7848F */   lw        $4, -0x480C($28)
    /* 2F4F70 003F4F70 F7FF0010 */  b          .L003F4F50
    /* 2F4F74 003F4F74 F4B780AF */   sw        $0, -0x480C($28)
  .L003F4F78:
    /* 2F4F78 003F4F78 0000BFDF */  ld         $31, 0x0($29)
    /* 2F4F7C 003F4F7C 0800E003 */  jr         $31
    /* 2F4F80 003F4F80 1000BD27 */   addiu     $29, $29, 0x10
    /* 2F4F84 003F4F84 00000000 */  nop
    /* 2F4F88 003F4F88 00000000 */  nop
    /* 2F4F8C 003F4F8C 00000000 */  nop
.size func_003f4f30, 0x60
