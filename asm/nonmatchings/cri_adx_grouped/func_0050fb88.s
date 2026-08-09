.section .text
.set noat
.set noreorder
glabel func_0050fb88
    /* 40FB88 0050FB88 C0FEBD27 */  addiu      $29, $29, -0x140
    /* 40FB8C 0050FB8C F800B1FF */  sd         $17, 0xF8($29)
    /* 40FB90 0050FB90 2D880001 */  daddu      $17, $8, $0
    /* 40FB94 0050FB94 0001B2FF */  sd         $18, 0x100($29)
    /* 40FB98 0050FB98 2D902001 */  daddu      $18, $9, $0
    /* 40FB9C 0050FB9C 0801B3FF */  sd         $19, 0x108($29)
    /* 40FBA0 0050FBA0 2D984001 */  daddu      $19, $10, $0
    /* 40FBA4 0050FBA4 1001B4FF */  sd         $20, 0x110($29)
    /* 40FBA8 0050FBA8 2DA06001 */  daddu      $20, $11, $0
    /* 40FBAC 0050FBAC 1801B5FF */  sd         $21, 0x118($29)
    /* 40FBB0 0050FBB0 2DA8C000 */  daddu      $21, $6, $0
    /* 40FBB4 0050FBB4 2001B6FF */  sd         $22, 0x120($29)
    /* 40FBB8 0050FBB8 2D30A003 */  daddu      $6, $29, $0
    /* 40FBBC 0050FBBC 2801B7FF */  sd         $23, 0x128($29)
    /* 40FBC0 0050FBC0 2DB8E000 */  daddu      $23, $7, $0
    /* 40FBC4 0050FBC4 3001BFFF */  sd         $31, 0x130($29)
    /* 40FBC8 0050FBC8 F000B0FF */  sd         $16, 0xF0($29)
    /* 40FBCC 0050FBCC 3839140C */  jal        func_0050e4e0
    /* 40FBD0 0050FBD0 A800908C */   lw        $16, 0xA8($4)
    /* 40FBD4 0050FBD4 A000B627 */  addiu      $22, $29, 0xA0
    /* 40FBD8 0050FBD8 2D28A003 */  daddu      $5, $29, $0
    /* 40FBDC 0050FBDC 2D402002 */  daddu      $8, $17, $0
    /* 40FBE0 0050FBE0 2D484002 */  daddu      $9, $18, $0
    /* 40FBE4 0050FBE4 2D506002 */  daddu      $10, $19, $0
    /* 40FBE8 0050FBE8 2D588002 */  daddu      $11, $20, $0
    /* 40FBEC 0050FBEC 2D38C002 */  daddu      $7, $22, $0
    /* 40FBF0 0050FBF0 2D30A002 */  daddu      $6, $21, $0
    /* 40FBF4 0050FBF4 D6AC140C */  jal        func_0052b358
    /* 40FBF8 0050FBF8 2D200002 */   daddu     $4, $16, $0
    /* 40FBFC 0050FBFC 2D200002 */  daddu      $4, $16, $0
    /* 40FC00 0050FC00 44AB140C */  jal        func_0052ad10
    /* 40FC04 0050FC04 2D28E002 */   daddu     $5, $23, $0
    /* 40FC08 0050FC08 2D200002 */  daddu      $4, $16, $0
    /* 40FC0C 0050FC0C 2D30C002 */  daddu      $6, $22, $0
    /* 40FC10 0050FC10 56AB140C */  jal        func_0052ad58
    /* 40FC14 0050FC14 2D28A003 */   daddu     $5, $29, $0
    /* 40FC18 0050FC18 F000B0DF */  ld         $16, 0xF0($29)
    /* 40FC1C 0050FC1C F800B1DF */  ld         $17, 0xF8($29)
    /* 40FC20 0050FC20 0001B2DF */  ld         $18, 0x100($29)
    /* 40FC24 0050FC24 0801B3DF */  ld         $19, 0x108($29)
    /* 40FC28 0050FC28 1001B4DF */  ld         $20, 0x110($29)
    /* 40FC2C 0050FC2C 1801B5DF */  ld         $21, 0x118($29)
    /* 40FC30 0050FC30 2001B6DF */  ld         $22, 0x120($29)
    /* 40FC34 0050FC34 2801B7DF */  ld         $23, 0x128($29)
    /* 40FC38 0050FC38 3001BFDF */  ld         $31, 0x130($29)
    /* 40FC3C 0050FC3C 0800E003 */  jr         $31
    /* 40FC40 0050FC40 4001BD27 */   addiu     $29, $29, 0x140
    /* 40FC44 0050FC44 00000000 */  nop
.size func_0050fb88, 0xc0
