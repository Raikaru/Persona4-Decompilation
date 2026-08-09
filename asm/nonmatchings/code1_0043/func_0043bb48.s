.section .text
.set noat
.set noreorder
glabel func_0043bb48
    /* 33BB48 0043BB48 80FFBD27 */  addiu      $29, $29, -0x80
    /* 33BB4C 0043BB4C 4800A5FF */  sd         $5, 0x48($29)
    /* 33BB50 0043BB50 5000A6FF */  sd         $6, 0x50($29)
    /* 33BB54 0043BB54 5800A7FF */  sd         $7, 0x58($29)
    /* 33BB58 0043BB58 6000A8FF */  sd         $8, 0x60($29)
    /* 33BB5C 0043BB5C 6800A9FF */  sd         $9, 0x68($29)
    /* 33BB60 0043BB60 7000AAFF */  sd         $10, 0x70($29)
    /* 33BB64 0043BB64 7800ABFF */  sd         $11, 0x78($29)
    /* 33BB68 0043BB68 0800E003 */  jr         $31
    /* 33BB6C 0043BB6C 8000BD27 */   addiu     $29, $29, 0x80
.size func_0043bb48, 0x28
