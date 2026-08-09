.section .text
.set noat
.set noreorder
glabel func_0050cae0
    /* 40CAE0 0050CAE0 7400063C */  lui        $6, %hi(D_00745878)
    /* 40CAE4 0050CAE4 01000224 */  addiu      $2, $0, 0x1
    /* 40CAE8 0050CAE8 7400033C */  lui        $3, %hi(D_0074587C)
    /* 40CAEC 0050CAEC 7400043C */  lui        $4, %hi(D_00745880)
    /* 40CAF0 0050CAF0 7400053C */  lui        $5, %hi(D_00745884)
    /* 40CAF4 0050CAF4 7858C2AC */  sw         $2, %lo(D_00745878)($6)
    /* 40CAF8 0050CAF8 7C5860AC */  sw         $0, %lo(D_0074587C)($3)
    /* 40CAFC 0050CAFC 805880AC */  sw         $0, %lo(D_00745880)($4)
    /* 40CB00 0050CB00 0800E003 */  jr         $31
    /* 40CB04 0050CB04 8458A0AC */   sw        $0, %lo(D_00745884)($5)
.size func_0050cae0, 0x28
