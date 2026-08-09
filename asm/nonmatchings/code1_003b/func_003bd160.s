.section .text
.set noat
.set noreorder
glabel func_003bd160
    /* 2BD160 003BD160 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2BD164 003BD164 3C00063C */  lui        $6, %hi(func_003bbe60)
    /* 2BD168 003BD168 3C00073C */  lui        $7, %hi(func_003bbe80)
    /* 2BD16C 003BD16C 0000BFFF */  sd         $31, 0x0($29)
    /* 2BD170 003BD170 2D200000 */  daddu      $4, $0, $0
    /* 2BD174 003BD174 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD178 003BD178 60BEC624 */  addiu      $6, $6, %lo(func_003bbe60)
    /* 2BD17C 003BD17C 4CA20F0C */  jal        func_003e8930
    /* 2BD180 003BD180 80BEE724 */   addiu     $7, $7, %lo(func_003bbe80)
    /* 2BD184 003BD184 03004104 */  bgez       $2, .L003BD194
    /* 2BD188 003BD188 00000000 */   nop
    /* 2BD18C 003BD18C B3000010 */  b          .L003BD45C
    /* 2BD190 003BD190 2D100000 */   daddu     $2, $0, $0
  .L003BD194:
    /* 2BD194 003BD194 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD198 003BD198 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD19C 003BD19C 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD1A0 003BD1A0 08000424 */  addiu      $4, $0, 0x8
    /* 2BD1A4 003BD1A4 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD1A8 003BD1A8 C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD1AC 003BD1AC E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD1B0 003BD1B0 DC0A0F0C */  jal        func_003c2b70
    /* 2BD1B4 003BD1B4 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD1B8 003BD1B8 03004104 */  bgez       $2, .L003BD1C8
    /* 2BD1BC 003BD1BC 58B682AF */   sw        $2, -0x49A8($28)
    /* 2BD1C0 003BD1C0 A6000010 */  b          .L003BD45C
    /* 2BD1C4 003BD1C4 2D100000 */   daddu     $2, $0, $0
  .L003BD1C8:
    /* 2BD1C8 003BD1C8 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD1CC 003BD1CC 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD1D0 003BD1D0 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD1D4 003BD1D4 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD1D8 003BD1D8 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD1DC 003BD1DC 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD1E0 003BD1E0 E80A0F0C */  jal        func_003c2ba0
    /* 2BD1E4 003BD1E4 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD1E8 003BD1E8 03004104 */  bgez       $2, .L003BD1F8
    /* 2BD1EC 003BD1EC 5CB682AF */   sw        $2, -0x49A4($28)
    /* 2BD1F0 003BD1F0 9A000010 */  b          .L003BD45C
    /* 2BD1F4 003BD1F4 2D100000 */   daddu     $2, $0, $0
  .L003BD1F8:
    /* 2BD1F8 003BD1F8 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD1FC 003BD1FC 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD200 003BD200 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD204 003BD204 08000424 */  addiu      $4, $0, 0x8
    /* 2BD208 003BD208 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD20C 003BD20C C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD210 003BD210 E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD214 003BD214 40230F0C */  jal        func_003c8d00
    /* 2BD218 003BD218 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD21C 003BD21C 60B682AF */  sw         $2, -0x49A0($28)
    /* 2BD220 003BD220 58B6828F */  lw         $2, -0x49A8($28)
    /* 2BD224 003BD224 03004104 */  bgez       $2, .L003BD234
    /* 2BD228 003BD228 00000000 */   nop
    /* 2BD22C 003BD22C 8B000010 */  b          .L003BD45C
    /* 2BD230 003BD230 2D100000 */   daddu     $2, $0, $0
  .L003BD234:
    /* 2BD234 003BD234 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD238 003BD238 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD23C 003BD23C 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD240 003BD240 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD244 003BD244 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD248 003BD248 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD24C 003BD24C 4C230F0C */  jal        func_003c8d30
    /* 2BD250 003BD250 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD254 003BD254 64B682AF */  sw         $2, -0x499C($28)
    /* 2BD258 003BD258 5CB6828F */  lw         $2, -0x49A4($28)
    /* 2BD25C 003BD25C 03004104 */  bgez       $2, .L003BD26C
    /* 2BD260 003BD260 00000000 */   nop
    /* 2BD264 003BD264 7D000010 */  b          .L003BD45C
    /* 2BD268 003BD268 2D100000 */   daddu     $2, $0, $0
  .L003BD26C:
    /* 2BD26C 003BD26C 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD270 003BD270 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD274 003BD274 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD278 003BD278 08000424 */  addiu      $4, $0, 0x8
    /* 2BD27C 003BD27C 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD280 003BD280 C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD284 003BD284 E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD288 003BD288 ACA70F0C */  jal        func_003e9eb0
    /* 2BD28C 003BD28C 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD290 003BD290 03004104 */  bgez       $2, .L003BD2A0
    /* 2BD294 003BD294 68B682AF */   sw        $2, -0x4998($28)
    /* 2BD298 003BD298 70000010 */  b          .L003BD45C
    /* 2BD29C 003BD29C 2D100000 */   daddu     $2, $0, $0
  .L003BD2A0:
    /* 2BD2A0 003BD2A0 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD2A4 003BD2A4 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD2A8 003BD2A8 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD2AC 003BD2AC 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD2B0 003BD2B0 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD2B4 003BD2B4 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD2B8 003BD2B8 48950F0C */  jal        func_003e5520
    /* 2BD2BC 003BD2BC 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD2C0 003BD2C0 03004104 */  bgez       $2, .L003BD2D0
    /* 2BD2C4 003BD2C4 6CB682AF */   sw        $2, -0x4994($28)
    /* 2BD2C8 003BD2C8 64000010 */  b          .L003BD45C
    /* 2BD2CC 003BD2CC 2D100000 */   daddu     $2, $0, $0
  .L003BD2D0:
    /* 2BD2D0 003BD2D0 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD2D4 003BD2D4 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD2D8 003BD2D8 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD2DC 003BD2DC 08000424 */  addiu      $4, $0, 0x8
    /* 2BD2E0 003BD2E0 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD2E4 003BD2E4 C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD2E8 003BD2E8 E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD2EC 003BD2EC 04A10F0C */  jal        func_003e8410
    /* 2BD2F0 003BD2F0 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD2F4 003BD2F4 03004104 */  bgez       $2, .L003BD304
    /* 2BD2F8 003BD2F8 70B682AF */   sw        $2, -0x4990($28)
    /* 2BD2FC 003BD2FC 57000010 */  b          .L003BD45C
    /* 2BD300 003BD300 2D100000 */   daddu     $2, $0, $0
  .L003BD304:
    /* 2BD304 003BD304 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD308 003BD308 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD30C 003BD30C 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD310 003BD310 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD314 003BD314 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD318 003BD318 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD31C 003BD31C 88940F0C */  jal        func_003e5220
    /* 2BD320 003BD320 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD324 003BD324 03004104 */  bgez       $2, .L003BD334
    /* 2BD328 003BD328 74B682AF */   sw        $2, -0x498C($28)
    /* 2BD32C 003BD32C 4B000010 */  b          .L003BD45C
    /* 2BD330 003BD330 2D100000 */   daddu     $2, $0, $0
  .L003BD334:
    /* 2BD334 003BD334 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD338 003BD338 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD33C 003BD33C 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD340 003BD340 08000424 */  addiu      $4, $0, 0x8
    /* 2BD344 003BD344 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD348 003BD348 C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD34C 003BD34C E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD350 003BD350 480E0F0C */  jal        func_003c3920
    /* 2BD354 003BD354 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD358 003BD358 03004104 */  bgez       $2, .L003BD368
    /* 2BD35C 003BD35C 78B682AF */   sw        $2, -0x4988($28)
    /* 2BD360 003BD360 3E000010 */  b          .L003BD45C
    /* 2BD364 003BD364 2D100000 */   daddu     $2, $0, $0
  .L003BD368:
    /* 2BD368 003BD368 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD36C 003BD36C 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD370 003BD370 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD374 003BD374 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD378 003BD378 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD37C 003BD37C 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD380 003BD380 540E0F0C */  jal        func_003c3950
    /* 2BD384 003BD384 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD388 003BD388 03004104 */  bgez       $2, .L003BD398
    /* 2BD38C 003BD38C 7CB682AF */   sw        $2, -0x4984($28)
    /* 2BD390 003BD390 32000010 */  b          .L003BD45C
    /* 2BD394 003BD394 2D100000 */   daddu     $2, $0, $0
  .L003BD398:
    /* 2BD398 003BD398 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD39C 003BD39C 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD3A0 003BD3A0 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD3A4 003BD3A4 08000424 */  addiu      $4, $0, 0x8
    /* 2BD3A8 003BD3A8 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD3AC 003BD3AC C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD3B0 003BD3B0 E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD3B4 003BD3B4 C4100F0C */  jal        func_003c4310
    /* 2BD3B8 003BD3B8 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD3BC 003BD3BC 03004104 */  bgez       $2, .L003BD3CC
    /* 2BD3C0 003BD3C0 80B682AF */   sw        $2, -0x4980($28)
    /* 2BD3C4 003BD3C4 25000010 */  b          .L003BD45C
    /* 2BD3C8 003BD3C8 2D100000 */   daddu     $2, $0, $0
  .L003BD3CC:
    /* 2BD3CC 003BD3CC 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD3D0 003BD3D0 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD3D4 003BD3D4 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD3D8 003BD3D8 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD3DC 003BD3DC 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD3E0 003BD3E0 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD3E4 003BD3E4 D0100F0C */  jal        func_003c4340
    /* 2BD3E8 003BD3E8 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD3EC 003BD3EC 03004104 */  bgez       $2, .L003BD3FC
    /* 2BD3F0 003BD3F0 84B682AF */   sw        $2, -0x497C($28)
    /* 2BD3F4 003BD3F4 19000010 */  b          .L003BD45C
    /* 2BD3F8 003BD3F8 2D100000 */   daddu     $2, $0, $0
  .L003BD3FC:
    /* 2BD3FC 003BD3FC 3C00063C */  lui        $6, %hi(func_003bcbc0)
    /* 2BD400 003BD400 3C00073C */  lui        $7, %hi(func_003bcbe0)
    /* 2BD404 003BD404 3C00083C */  lui        $8, %hi(func_003bcc80)
    /* 2BD408 003BD408 08000424 */  addiu      $4, $0, 0x8
    /* 2BD40C 003BD40C 1F010524 */  addiu      $5, $0, 0x11F
    /* 2BD410 003BD410 C0CBC624 */  addiu      $6, $6, %lo(func_003bcbc0)
    /* 2BD414 003BD414 E0CBE724 */  addiu      $7, $7, %lo(func_003bcbe0)
    /* 2BD418 003BD418 24BE0F0C */  jal        func_003ef890
    /* 2BD41C 003BD41C 80CC0825 */   addiu     $8, $8, %lo(func_003bcc80)
    /* 2BD420 003BD420 03004104 */  bgez       $2, .L003BD430
    /* 2BD424 003BD424 88B682AF */   sw        $2, -0x4978($28)
    /* 2BD428 003BD428 0C000010 */  b          .L003BD45C
    /* 2BD42C 003BD42C 2D100000 */   daddu     $2, $0, $0
  .L003BD430:
    /* 2BD430 003BD430 3C00053C */  lui        $5, %hi(func_003bcd50)
    /* 2BD434 003BD434 3C00063C */  lui        $6, %hi(func_003bce20)
    /* 2BD438 003BD438 3C00073C */  lui        $7, %hi(func_003bce50)
    /* 2BD43C 003BD43C 1F010424 */  addiu      $4, $0, 0x11F
    /* 2BD440 003BD440 50CDA524 */  addiu      $5, $5, %lo(func_003bcd50)
    /* 2BD444 003BD444 20CEC624 */  addiu      $6, $6, %lo(func_003bce20)
    /* 2BD448 003BD448 84980F0C */  jal        func_003e6210
    /* 2BD44C 003BD44C 50CEE724 */   addiu     $7, $7, %lo(func_003bce50)
    /* 2BD450 003BD450 8CB682AF */  sw         $2, -0x4974($28)
    /* 2BD454 003BD454 2A104000 */  slt        $2, $2, $0
    /* 2BD458 003BD458 01004238 */  xori       $2, $2, 0x1
  .L003BD45C:
    /* 2BD45C 003BD45C 0000BFDF */  ld         $31, 0x0($29)
    /* 2BD460 003BD460 0800E003 */  jr         $31
    /* 2BD464 003BD464 1000BD27 */   addiu     $29, $29, 0x10
    /* 2BD468 003BD468 00000000 */  nop
    /* 2BD46C 003BD46C 00000000 */  nop
.size func_003bd160, 0x310
