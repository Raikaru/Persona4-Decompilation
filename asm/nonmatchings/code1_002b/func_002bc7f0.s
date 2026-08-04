.section .text
.set noat
.set noreorder
glabel func_002bc7f0
    /* 1BC7F0 002BC7F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BC7F4 002BC7F4 0000BFFF */  sd         $31, 0x0($29)
    /* 1BC7F8 002BC7F8 2D588000 */  daddu      $11, $4, $0
    /* 1BC7FC 002BC7FC 3C160800 */  dsll32     $2, $8, 24
    /* 1BC800 002BC800 3F160200 */  dsra32     $2, $2, 24
    /* 1BC804 002BC804 80180200 */  sll        $3, $2, 2
    /* 1BC808 002BC808 6400023C */  lui        $2, %hi(D_0063F2B0)
    /* 1BC80C 002BC80C B0F24224 */  addiu      $2, $2, %lo(D_0063F2B0)
    /* 1BC810 002BC810 21404300 */  addu       $8, $2, $3
    /* 1BC814 002BC814 40100900 */  sll        $2, $9, 1
    /* 1BC818 002BC818 21104900 */  addu       $2, $2, $9
    /* 1BC81C 002BC81C 00190200 */  sll        $3, $2, 4
    /* 1BC820 002BC820 7900023C */  lui        $2, %hi(D_00793E80)
    /* 1BC824 002BC824 803E4224 */  addiu      $2, $2, %lo(D_00793E80)
    /* 1BC828 002BC828 21504300 */  addu       $10, $2, $3
    /* 1BC82C 002BC82C 2D20A000 */  daddu      $4, $5, $0
    /* 1BC830 002BC830 2D28C000 */  daddu      $5, $6, $0
    /* 1BC834 002BC834 2D30E000 */  daddu      $6, $7, $0
    /* 1BC838 002BC838 01000724 */  addiu      $7, $0, 0x1
    /* 1BC83C 002BC83C 0000088D */  lw         $8, 0x0($8)
    /* 1BC840 002BC840 2D486001 */  daddu      $9, $11, $0
    /* 1BC844 002BC844 D4E4090C */  jal        func_00279350
    /* 1BC848 002BC848 00000000 */   nop
    /* 1BC84C 002BC84C 0000BFDF */  ld         $31, 0x0($29)
    /* 1BC850 002BC850 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BC854 002BC854 0800E003 */  jr         $31
    /* 1BC858 002BC858 00000000 */   nop
    /* 1BC85C 002BC85C 00000000 */  nop
.size func_002bc7f0, 0x70
