#include "../../../cri/mwlib/ee/lib/libadxe/lsc.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_stmc.h"
#include "../../../cri/mwlib/ee/lib/libadxe/lsc_crs.h"
#include "../../../cri/mwlib/ee/lib/libadxe/lsc_err.h"
#include "../../../cri/mwlib/ee/lib/libadxe/lsc_ini.h"
#include "../../../cri/mwlib/ee/lib/libadxe/lsc_svr.h"

#include <string.h>

/* The KATANA SDK has a header for this file, cri_lsc.h, while the PS2 CRIware headers don't. */

LSC_STATFN lsc_stat_func = NULL;
void *lsc_stat_obj1 = NULL;
void *lsc_stat_obj2 = NULL;

// 100% matching!
LSC lsc_Alloc(void) 
{
    LSC lsc;
    Sint32 i;

    lsc = NULL;

    for (i = 0; i < LSC_OBJ_MAX; i++) 
    {
        if (lsc_obj[i].used == FALSE) 
        {
            lsc = &lsc_obj[i];
            break;
        }
    }

    return lsc;
}

// 100% matching!
LSC LSC_Create(SJ sj)
{
    LSC lsc;
    LSC_CRS crs;
    Sint32 i;

    if (sj == NULL)
    {
        LSC_CallErrFunc("E0001: Illigal parameter=sj (LSC_Create)");
        
        return NULL;
    }
    
    LSC_LockCrs(&crs);
    
    lsc = lsc_Alloc();

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0002: Not enough instance (LSC_Create)");
    } 
    else 
    {
        lsc->stat = LSC_STAT_STOP;
        
        lsc->sj = sj;

        lsc->bsize = SJ_GetNumData(sj, 0) + SJ_GetNumData(sj, 1);
        
        lsc->bufmin = (lsc->bsize * 8) / 10;

        for (i = 0; i < LSC_STM_MAX; i++) 
        {
            lsc->sinfo[i].stat = LSC_STM_STAT_WAIT;
        }

        lsc->used = TRUE;
    }

    LSC_UnlockCrs(&crs);
    
    return lsc;
}

// 100% matching!
void LSC_Destroy(LSC lsc) 
{
    LSC_CRS crs;
    
    if (lsc != NULL) 
    {
        LSC_LockCrs(&crs);
        
        LSC_Stop(lsc);
        
        lsc->used = FALSE;
        
        memset(lsc, 0, sizeof(LSC_OBJ));

        LSC_UnlockCrs(&crs);
    }
}

// 100% matching!
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname) 
{
    void *fp;
	Sint32 fsize;
	Sint32 fsct;

    fp = ADXSTM_OpenFname(fname, lsc->sj);
    
    if (fp == NULL) 
    {
        LSC_CallErrFunc("E0004: Can not open '%s'", fname);
    }

    fsct = (ADXSTM_GetFileLen(fp) + 2047) / 2048;
        
    ADXSTM_Close(fp);
    
    fsize = LSC_EntryFileRange(lsc, fname, NULL, 0, fsct);

    return fsize;
}

// Retail 0x4E90B8: NULL/full/fname-NULL all li -1 (0x4E9104/0x4E9114/0x4E9130 2402ffff);
// entry 32B stride sll 5 (0x4E94F8) + base 56 (0x4E9500) + table 0x38; fname ptr +4
// (0x4E9170 ae120004), chksum +8 (0x4E9198), ofst +16 (0x4E91C8), fsct +20 (0x4E91D0),
// rdsct +28 (0x4E91D4) before stat +24 (0x4E91D8), dir +12 LAST (0x4E91DC). Reverted
// -3 to -1 (3 paths); replaced fname[40] strncpy with ptr+chksum to match re4/retail.
// 100% matching!
Sint32 LSC_EntryFileRange(LSC lsc, Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct)
{
    LSC_SINFO *sinfo;
    Sint32 sid;
    Sint32 pos;
    Uint32 len;
    Sint32 i;

    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return -1;
    }

    if (lsc->nstm >= LSC_STM_MAX)
    {
        return -1;
    }

    if (fname == NULL)
    {
        LSC_CallErrFunc("E0011: Illigal parameter fname=%s", fname);
        return -1;
    }

    sinfo = &lsc->sinfo[lsc->wpos];
    sinfo->fname = fname;
    pos = (lsc->wpos + 15) % LSC_STM_MAX;
    sid = (lsc->sinfo[pos].sid == 0x7FFFFFFF) ? 0 : lsc->sinfo[pos].sid + 1;
    sinfo->sid = sid;
    len = strlen((char *)fname);
    sinfo->chksum = 0;
    for (i = 0; i < len; i++) {
        sinfo->chksum += (Uint8)fname[i];
    }
    sinfo->ofst = ofst;
    sinfo->fsct = nsct;
    sinfo->rdsct = 0;
    sinfo->stat = LSC_STM_STAT_WAIT;
    sinfo->dir = dir;
    lsc->nstm++;
    lsc->wpos = (lsc->wpos + 1) % LSC_STM_MAX;
    if (lsc->stat == LSC_STAT_WAIT)
    {
        lsc->stat = LSC_STAT_EXEC;
    }

    return sid;
}

// 100% matching!
void LSC_Start(LSC lsc)
{
    LSC_CRS crs;
    
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    LSC_LockCrs(&crs);

    if (lsc->stat != LSC_STAT_STOP) 
    {
        LSC_Stop(lsc);
    }

    if (lsc->nstm > 0)
    {
        lsc->stat = LSC_STAT_EXEC;
    } 
    else 
    {
        lsc->stat = LSC_STAT_WAIT;
    }

    LSC_UnlockCrs(&crs);
}

// 100% matching!
void LSC_Stop(LSC lsc) 
{
    LSC_CRS crs;

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }
    
    LSC_LockCrs(&crs);
    
    if (lsc->fp != NULL) 
    {
        if (lsc->rdflg == 1) 
        {
            ADXSTM_Stop(lsc->fp);
            
            lsc->rdflg = 0;
        }
        
        ADXSTM_Close(lsc->fp);
        
        lsc->fp = NULL;
    }
    
    lsc->fsct = 0;
    
    lsc->wpos = 0;
    lsc->rpos = 0;
    
    lsc->nstm = 0;
    
    lsc->errcnt = 0;
    
    lsc->stat = LSC_STAT_STOP;
    
    LSC_UnlockCrs(&crs); 
}

// 100% matching!
// FUN_004E9380
void LSC_Pause(LSC lsc, Sint32 sw)
{
    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    if (sw == 1) 
    {
        lsc->pause = TRUE;
    } 
    else
    {
        lsc->pause = FALSE;
    }
}

// 100% matching!
void LSC_ExecServer(void)
{
    LSC lsc;
    LSC_CRS crs;
    Sint32 i;
    
    LSC_LockCrs(&crs);
    
    for (i = 0; i < LSC_OBJ_MAX; i++) 
    {
        lsc = &lsc_obj[i];

        if (lsc->used == TRUE) 
        {
            lsc_ExecHndl(lsc);
        }
    }
    
    LSC_UnlockCrs(&crs);
}

// 100% matching!
Sint32 LSC_GetStat(LSC lsc) 
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -3;
    }
    
    return lsc->stat;
}

// Retail 0x4C95C8 GetNumStm is lw 20(a0) (0x4C95E8 8c820014) with li -3 (0x4C95E4 2402fffd):
// a DIFFERENT LSC_OBJ (0x14) from the 0x4E tree (nstm at 0x24). Both trees use 0x24
// (1 diff each) because 0x4E Create/Entry/Start/Reset all prove 0x24/0x1C/0x20/0x24
// (0x4E8FD0 ae500018 sw s0,24(s2), 0x4E8FE8 ae420014 sw v0,20(s2), 0x4E94B0 8cc20024
// lw v0,36(a2), 0x4E94F8 00021940 sll 5 + 0x4E9500 8c620038 lw 56). Do NOT move to 0x14.
// 100% matching!
Sint32 LSC_GetNumStm(LSC lsc) 
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -3;
    }
    
    return lsc->nstm;
}

// Retail 0x4E9480 GetStmId: NULL li -1 (0x4E94A4 2402ffff), bounds lw 36(a2)=0x24 nstm
// (0x4E94B0 8cc20024), out-of-range li -1 (0x4E94D0 2402ffff), stride sll 5
// (0x4E94F8 00021940) + table base 56 (0x4E9500 8c620038). Reverted -3 to -1 (2 paths).
// 100% matching!
// FUN_004E9480
Sint32 LSC_GetStmId(LSC lsc, Sint32 no)
{
    Sint32 pos;
    
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }

    if ((no < 0) || (no >= lsc->nstm)) 
    {
        LSC_CallErrFunc("E0009: Illigal parameter no=%d", no);
        
        return -1;
    }
    
    pos = (lsc->rpos + no) % LSC_STM_MAX;
    
    return lsc->sinfo[pos].sid;
}

// 100% matching!
// FUN_004E9510
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid)
{
    Sint32 i;

    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return NULL;
    }

    for (i = 0; i < LSC_STM_MAX; i++) 
    {
        if (lsc->sinfo[i].sid == sid) 
        {
            break;
        }
    }

    if (i == LSC_STM_MAX) 
    {
        LSC_CallErrFunc("E0012: Can not find stream ID =%d", sid);
        
        return NULL;
    }

    return lsc->sinfo[i].fname;
}

// Retail 0x4E95A8 GetStmStat: NULL li -1 (0x4E95C4 2402ffff), loop base a2=lsc+56
// (0x4E95C8 24860038) stepping +32 (0x4E95E8 24c60020) with sll 5 (0x4E960C 00031940),
// not-found li -1 (0x4E9620 2402ffff), stat +80 (0x4E962C 8c620050). Reverted -3 to -1
// (2 paths); stride 64->32 and stat 0x70->0x50 via 32B SINFO.
// 100% matching!
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid) 
{
    Sint32 i;

    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -1;
    }

    for (i = 0; i < LSC_STM_MAX; i++) 
    {
        if (lsc->sinfo[i].sid == sid)
        {
            break;
        }
    }

    if (i == LSC_STM_MAX) 
    {
        LSC_CallErrFunc("E0012: Can not find stream ID =%d", sid);
        
        return -1;
    }

    return lsc->sinfo[i].stat;
}

// 100% matching!
// FUN_004E9640
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid)
{
    Sint32 i;

    if (lsc == NULL)
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return 0;
    }

    for (i = 0; i < LSC_STM_MAX; i++) 
    {
        if (lsc->sinfo[i].sid == sid) 
        {
            break;
        }
    }

    if (i == LSC_STM_MAX) 
    {
        LSC_CallErrFunc("E0012: Can not find stream ID =%d", sid);
        
        return 0;
    }

    return lsc->sinfo[i].rdsct;
}

// 100% matching!
void LSC_SetFlowLimit(LSC lsc, Sint32 min)
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }

    if ((min < 0) || (min > lsc->bsize)) 
    {
        LSC_CallErrFunc("E0010: Illigal parameter min=%d", min);
        return;
    }
    
    lsc->bufmin = min;
}

// 100% matching!
Sint32 LSC_GetFlowLimit(LSC lsc) 
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        
        return -3;
    }
    
    return lsc->bufmin;
}

// 100% matching!
// FUN_004E9770
void LSC_EntryChgStatFunc(LSC_STATFN statfn, void *obj1, void *obj2)
{
    if (statfn == NULL) 
    {
        lsc_stat_func = NULL;
        
        lsc_stat_obj1 = NULL;
        lsc_stat_obj2 = NULL;
    }
    else 
    {
        lsc_stat_func = statfn;
        
        lsc_stat_obj1 = obj1;
        lsc_stat_obj2 = obj2;
    }
}

// 100% matching!
void LSC_CallStatFunc(void) 
{
    if (lsc_stat_func != NULL) 
    {
        lsc_stat_func(lsc_stat_obj1, lsc_stat_obj2);
    }
}

// 100% matching!
// FUN_004E97E8
void LSC_SetLpFlg(LSC lsc, Sint32 flg)
{
    if (lsc == NULL) 
    {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL");
        return;
    }
    
    lsc->lpflg = flg;
}
