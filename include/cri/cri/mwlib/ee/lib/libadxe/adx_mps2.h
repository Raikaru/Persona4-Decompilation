#ifndef _ADX_MPS2_H_
#define _ADX_MPS2_H_

#include <adx_ps2.h>
#include <eekernel.h>

#define bss_align(val) \
    __attribute__ ((aligned(val))) __attribute__ ((section (".bss"))) 

#define DEF_STACK_SIZE    2048

/* P4: the upstream tree had no Sony headers, so it forward-declared
 * ThreadParam here and left it incomplete - which is why its
 * ADXPS2_SetupThrd could never compile. <eekernel.h> above now
 * supplies the real definition, so the placeholder is removed. */

void adxps2_adx_thrd_func(void);
void ADXPS2_ExecServer(void);
void ADXPS2_Lock(void);
void ADXPS2_RestoreVsyncCallback(void);
void adxps2_safe_thrd_func(void);
void ADXPS2_SetupThrd(ADXPS2_TPRM *tprm);
void ADXPS2_SetupUsvr(void);
void ADXPS2_Shutdown(void);
void ADXPS2_ShutdownThrd(void);
void ADXPS2_Unlock(void);
int ADXPS2_VsyncCallback(int arg);

#endif
