.section .text
.set noat
.set noreorder
glabel func_004ecfa0
    /* 3ECFA0 004ECFA0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECFA4 004ECFA4 01000724 */  addiu      $7, $0, 0x1
    /* 3ECFA8 004ECFA8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECFAC 004ECFAC F1FFC928 */  slti       $9, $6, -0xF
    /* 3ECFB0 004ECFB0 05006714 */  bne        $3, $7, .L004ECFC8
    /* 3ECFB4 004ECFB4 2D408000 */   daddu     $8, $4, $0
    /* 3ECFB8 004ECFB8 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECFBC 004ECFBC 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECFC0 004ECFC0 09006018 */  blez       $3, .L004ECFE8
    /* 3ECFC4 004ECFC4 00000000 */   nop
  .L004ECFC8:
    /* 3ECFC8 004ECFC8 F1FF0224 */  addiu      $2, $0, -0xF
    /* 3ECFCC 004ECFCC 80200500 */  sll        $4, $5, 2
    /* 3ECFD0 004ECFD0 0A10C900 */  movz       $2, $6, $9
    /* 3ECFD4 004ECFD4 0F000524 */  addiu      $5, $0, 0xF
    /* 3ECFD8 004ECFD8 10004328 */  slti       $3, $2, 0x10
    /* 3ECFDC 004ECFDC 21208800 */  addu       $4, $4, $8
    /* 3ECFE0 004ECFE0 0A10A300 */  movz       $2, $5, $3
    /* 3ECFE4 004ECFE4 400082AC */  sw         $2, 0x40($4)
  .L004ECFE8:
    /* 3ECFE8 004ECFE8 0800E003 */  jr         $31
    /* 3ECFEC 004ECFEC 00000000 */   nop
.size func_004ecfa0, 0x50
