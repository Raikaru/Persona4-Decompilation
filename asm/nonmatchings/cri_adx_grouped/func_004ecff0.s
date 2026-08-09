.section .text
.set noat
.set noreorder
glabel func_004ecff0
    /* 3ECFF0 004ECFF0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECFF4 004ECFF4 01000624 */  addiu      $6, $0, 0x1
    /* 3ECFF8 004ECFF8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECFFC 004ECFFC 05006654 */  bnel       $3, $6, .L004ED014
    /* 3ED000 004ED000 5C0085AC */   sw        $5, 0x5C($4)
    /* 3ED004 004ED004 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ED008 004ED008 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ED00C 004ED00C 0100605C */  bgtzl      $3, .L004ED014
    /* 3ED010 004ED010 5C0085AC */   sw        $5, 0x5C($4)
  .L004ED014:
    /* 3ED014 004ED014 0800E003 */  jr         $31
    /* 3ED018 004ED018 00000000 */   nop
    /* 3ED01C 004ED01C 00000000 */  nop
.size func_004ecff0, 0x30
