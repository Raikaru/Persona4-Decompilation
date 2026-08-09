.section .text
.set noat
.set noreorder
glabel func_0021de60
    /* 11DE60 0021DE60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 11DE64 0021DE64 0000BFFF */  sd         $31, 0x0($29)
    /* 11DE68 0021DE68 6300043C */  lui        $4, %hi(D_006290E0)
    /* 11DE6C 0021DE6C E0908424 */  addiu      $4, $4, %lo(D_006290E0)
    /* 11DE70 0021DE70 E048110C */  jal        func_00452380
    /* 11DE74 0021DE74 00000000 */   nop
    /* 11DE78 0021DE78 26104000 */  xor        $2, $2, $0
    /* 11DE7C 0021DE7C 0100422C */  sltiu      $2, $2, 0x1
    /* 11DE80 0021DE80 0000BFDF */  ld         $31, 0x0($29)
    /* 11DE84 0021DE84 1000BD27 */  addiu      $29, $29, 0x10
    /* 11DE88 0021DE88 0800E003 */  jr         $31
    /* 11DE8C 0021DE8C 00000000 */   nop
.size func_0021de60, 0x30
