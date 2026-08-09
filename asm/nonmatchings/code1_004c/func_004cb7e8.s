.section .text
.set noat
.set noreorder
glabel func_004cb7e8
    /* 3CB7E8 004CB7E8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3CB7EC 004CB7EC 7200023C */  lui        $2, %hi(D_00719A58)
    /* 3CB7F0 004CB7F0 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB7F4 004CB7F4 589A4424 */  addiu      $4, $2, %lo(D_00719A58)
    /* 3CB7F8 004CB7F8 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB7FC 004CB7FC 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB800 004CB800 1800B3FF */  sd         $19, 0x18($29)
    /* 3CB804 004CB804 2000BFFF */  sd         $31, 0x20($29)
    /* 3CB808 004CB808 000083DC */  ld         $3, 0x0($4)
    /* 3CB80C 004CB80C 12006014 */  bnez       $3, .L004CB858
    /* 3CB810 004CB810 7200023C */   lui       $2, %hi(D_00719A60)
    /* 3CB814 004CB814 7200023C */  lui        $2, %hi(D_007199F8)
    /* 3CB818 004CB818 7200033C */  lui        $3, %hi(D_007199DC)
    /* 3CB81C 004CB81C F8995124 */  addiu      $17, $2, %lo(D_007199F8)
    /* 3CB820 004CB820 DC997024 */  addiu      $16, $3, %lo(D_007199DC)
    /* 3CB824 004CB824 2D988000 */  daddu      $19, $4, $0
    /* 3CB828 004CB828 01001224 */  addiu      $18, $0, 0x1
    /* 3CB82C 004CB82C 00000000 */  nop
  .L004CB830:
    /* 3CB830 004CB830 000022DE */  ld         $2, 0x0($17)
    /* 3CB834 004CB834 01004264 */  daddiu     $2, $2, 0x1
    /* 3CB838 004CB838 000022FE */  sd         $2, 0x0($17)
    /* 3CB83C 004CB83C 1AC4130C */  jal        func_004f1068
    /* 3CB840 004CB840 000012AE */   sw        $18, 0x0($16)
    /* 3CB844 004CB844 4A2F130C */  jal        func_004cbd28
    /* 3CB848 004CB848 000000AE */   sw        $0, 0x0($16)
    /* 3CB84C 004CB84C 000062DE */  ld         $2, 0x0($19)
    /* 3CB850 004CB850 F7FF4010 */  beqz       $2, .L004CB830
    /* 3CB854 004CB854 7200023C */   lui       $2, %hi(D_00719A60)
  .L004CB858:
    /* 3CB858 004CB858 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB85C 004CB85C 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB860 004CB860 01000324 */  addiu      $3, $0, 0x1
    /* 3CB864 004CB864 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB868 004CB868 609A4224 */  addiu      $2, $2, %lo(D_00719A60)
    /* 3CB86C 004CB86C 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB870 004CB870 2000BFDF */  ld         $31, 0x20($29)
    /* 3CB874 004CB874 000043FC */  sd         $3, 0x0($2)
    /* 3CB878 004CB878 88851008 */  j          func_00421620
    /* 3CB87C 004CB87C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004cb7e8, 0x98
