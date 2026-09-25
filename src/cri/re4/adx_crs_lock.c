/* ADX critical-section adapters and unused callbacks at the following two entrypoints. */
#include "cri_xpt.h"

extern void SVM_Lock(void);
extern void SVM_Unlock(void);

// FUN_004C54A8
void ADXCRS_Lock(void)
{
	SVM_Lock();
}

// FUN_004C54C0
void ADXCRS_Unlock(void)
{
	SVM_Unlock();
}

// FUN_004C54D8
void func_004c54d8(void)
{
}

// FUN_004C54E0
void func_004c54e0(void)
{
}
