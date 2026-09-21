/* CRI ADXAMP (adx_amp.c): amplitude/volume processing stage between the decoder output and the
 * renderer stream joints. Never created in this game (ADXT_OBJ.amp stays NULL); the functions that
 * survived are called only through ADXT's NULL-guarded amp hooks. */
#include "cri_xpt.h"
#include "sj.h"
#include <string.h>

typedef struct {
	Sint8 used;         /* 0x00 */
	Sint8 stat;         /* 0x01 */
	Sint8 nch;          /* 0x02 */
	Sint8 rsv;          /* 0x03 */
	SJ sji[2];          /* 0x04 */
	SJ sjo[2];          /* 0x0C */
	Sint32 nsmpl[2];    /* 0x14 */
	Sint32 rsv1C;       /* 0x1C */
	Sint32 sfreq;       /* 0x20 */
	Float32 vol;        /* 0x24 */
	Sint32 rsv28;       /* 0x28 */
	Sint32 total;       /* 0x2C */
} ADXAMP_OBJ;

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);

static ADXAMP_OBJ *adxamp_cur;
static Sint32 adxamp_cnt;

/* dead-stripped by the linker: they own the int->float magic, 0.1f and the two statics */
void ADXAMP_SetVolume(ADXAMP_OBJ *amp, Sint32 vol)
{
	adxamp_cur = amp;
	adxamp_cnt++;
	amp->vol = (Float32)vol;
}

// Dead: volume from a linear rate (x 0.1).
void ADXAMP_SetVolumeRate(ADXAMP_OBJ *amp, Float32 rate)
{
	amp->vol = rate * 0.1f;
}

// Records the sampling rate.
void ADXAMP_SetSfreq(ADXAMP_OBJ *amp, Sint32 sfreq)
{
	amp->sfreq = sfreq;
}

// Stops the stage (stat 0).
// FUN_004C1710
void ADXAMP_Stop(ADXAMP_OBJ *amp)
{
	amp->stat = 0;
}

// Resets the sample counters and zero-fills / resets the input and output stream joints, then runs
// (stat 2). Called by adxt_start_sjd when a handle has an amp.
void ADXAMP_Start(ADXAMP_OBJ *amp)
{
	SJCK ck;
	Sint32 i;
	SJ sj;
	Sint32 n;

	for (i = 0; i < amp->nch; i++) {
		amp->nsmpl[i] = 0;
	}
	amp->total = 0;
	for (i = 0; i < amp->nch; i++) {
		sj = amp->sji[i];
		SJ_Reset(sj);
		n = SJ_GetNumData(sj, 0);
		SJ_GetChunk(sj, 0, n, &ck);
		memset(ck.data, 0, ck.len);
		SJ_UngetChunk(sj, 0, &ck);
	}
	for (i = 0; i < amp->nch; i++) {
		sj = amp->sjo[i];
		SJ_Reset(sj);
		n = SJ_GetNumData(sj, 0);
		SJ_GetChunk(sj, 0, n, &ck);
		memset(ck.data, 0, ck.len);
		SJ_UngetChunk(sj, 0, &ck);
	}
	amp->stat = 2;
}

// Clears the object under the ADX lock.
// FUN_004C1518
void ADXAMP_Destroy(ADXAMP_OBJ *amp)
{
	if (amp != NULL) {
		ADXCRS_Lock();
		memset(amp, 0, sizeof(ADXAMP_OBJ));
		ADXCRS_Unlock();
	}
}
