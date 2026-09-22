#include "../../../cri/mwlib/ee/lib/libadxe/adx_rnap.h"
#include "../../../cri/mwlib/ee/lib/libadxe/ps2_rna.h"

#include <stdio.h>

/* There's little here of interest, most of these functions are thunks for the console-specific audio renderer code in ps2_rna. */

// 100% matching!
// FUN_004CB2A8
void ADXRNA_Init(void)
{
    PS2RNA_Init();
}

// 100% matching!
// FUN_004CB450
void ADXRNA_Finish(void)
{
    PS2RNA_Finish();
}

// 100% matching!
// FUN_004CB468
ADXRNA ADXRNA_Create(SJ *sj, Sint32 maxnch)
{
    return PS2RNA_Create(sj, maxnch);
}

// 100% matching!
void ADXRNA_Destroy(ADXRNA rna)
{
    PS2RNA_SetPlaySw(rna, 0);
    PS2RNA_SetTransSw(rna, 0);
    
    PS2RNA_Destroy(rna);
}

// 100% matching!
// FUN_004CB480
void ADXRNA_Start(ADXRNA rna)
{
    PS2RNA_Start(rna);
}

// 100% matching!
// FUN_004CB498
void ADXRNA_Stop(ADXRNA rna)
{
    PS2RNA_Stop(rna);
}

// 100% matching!
// FUN_004CB4B0
void ADXRNA_SetTransSw(ADXRNA rna, Sint32 sw)
{
    PS2RNA_SetTransSw(rna, sw);
}

// 100% matching!
// FUN_004CB4C8
void ADXRNA_SetPlaySw(ADXRNA rna, Sint32 sw)
{
    PS2RNA_SetPlaySw(rna, sw);
}

// 100% matching!
// FUN_004CD738
void ADXRNA_GetTime(ADXRNA rna, Sint32 *ncount, Sint32 *tscale)
{
    PS2RNA_GetTime(rna, ncount, tscale);
}

// 100% matching!
// FUN_004CB4F8
Sint32 ADXRNA_GetNumData(ADXRNA rna)
{
    return PS2RNA_GetNumData(rna);
}

// 100% matching!
// FUN_004CBD28
Sint32 ADXRNA_GetNumRoom(ADXRNA rna) 
{
    return PS2RNA_GetNumRoom(rna);
}

// 100% matching!
// FUN_004CD780
Sint32 ADXRNA_GetStat(ADXRNA rna)
{
    printf("ADXRNA_GetStat: not implemented\n");
    
    while (TRUE);
}

// 100% matching!
// FUN_004CD7B8
void ADXRNA_ExecServer(void) 
{
    PS2RNA_ExecServer();
}

// 100% matching!
// FUN_004CD7D0
void ADXRNA_SetStartSmpl(ADXRNA rna, Sint32 nsmpl) 
{
    PS2RNA_SetStartSmpl(rna, nsmpl);
}

// 100% matching!
// FUN_004CD7E8
void ADXRNA_SetNumChan(ADXRNA rna, Sint32 nch) 
{
    PS2RNA_SetNumChan(rna, nch);
}

// 100% matching!
// FUN_004CD800
void ADXRNA_SetSfreq(ADXRNA rna, Sint32 sfreq)
{
    PS2RNA_SetSfreq(rna, sfreq);
}

// 100% matching!
// FUN_004CD818
void ADXRNA_SetOutVol(ADXRNA rna, Sint32 vol)
{
    PS2RNA_SetOutVol(rna, vol);
}

// 100% matching!
// FUN_004CD830
void ADXRNA_SetOutPan(ADXRNA rna, Sint32 chno, Sint32 pan)
{
    PS2RNA_SetOutPan(rna, chno, pan);
}

// 100% matching!
// FUN_004CD848
void ADXRNA_SetBitPerSmpl(ADXRNA rna, Sint32 bps)
{
    PS2RNA_SetBitPerSmpl(rna, bps);
}

// 100% matching!
// FUN_004CD860
Sint32 ADXRNA_GetSfreq(ADXRNA rna)
{
    return PS2RNA_GetSfreq(rna);
}

// 100% matching!
// FUN_004CD878
Sint32 ADXRNA_GetOutVol(ADXRNA rna)
{
    return PS2RNA_GetOutVol(rna);
}

// 100% matching!
// FUN_004CD890
Sint32 ADXRNA_GetOutPan(ADXRNA rna, Sint32 chno)
{
    return PS2RNA_GetOutPan(rna, chno);
}

// 100% matching!
// FUN_004CD8A8
Sint32 ADXRNA_GetBitPerSmpl(ADXRNA rna) 
{
    return PS2RNA_GetBitPerSmpl(rna);
}

// 100% matching!
// FUN_004CD8C0
Sint32 ADXRNA_DiscardData(ADXRNA rna, Sint32 nsmpl)
{
    return PS2RNA_DiscardData(rna, nsmpl);
}

// 100% matching!
void ADXRNA_ClearBuf(ADXRNA rna)
{

}

// 100% matching!
void ADXRNA_SetPcmType(ADXRNA rna, Sint32 type)
{

}

// 100% matching!
void ADXRNA_SetTotalNumSmpl(ADXRNA rna, Sint32 nsmpl)
{

}

// 100% matching!
void ADXRNA_SetWavFname(ADXRNA rna, const Sint8 *fname)
{

}

// 100% matching!
// FUN_004CD958
Sint32 ADXRNA_SetStmHdInfo(ADXRNA rna, void *snddat)
{
    PS2RNA_SetStmHdInfo(rna, snddat);
    
    return 0;
}
