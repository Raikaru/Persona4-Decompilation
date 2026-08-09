.section .text
.set noat
.set noreorder
glabel func_00443f18
    /* 343F18 00443F18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 343F1C 00443F1C 71000F3C */  lui        $15, %hi(D_00710070)
    /* 343F20 00443F20 0000BFFF */  sd         $31, 0x0($29)
    /* 343F24 00443F24 7000E68D */  lw         $6, %lo(D_00710070)($15)
    /* 343F28 00443F28 0000BFDF */  ld         $31, 0x0($29)
    /* 343F2C 00443F2C 5C00C624 */  addiu      $6, $6, 0x5C
    /* 343F30 00443F30 CE0F1108 */  j          func_00443f38
    /* 343F34 00443F34 1000BD27 */   addiu     $29, $29, 0x10
.size func_00443f18, 0x20
