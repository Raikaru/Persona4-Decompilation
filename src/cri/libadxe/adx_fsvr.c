#include "../../../cri/mwlib/ee/lib/libadxe/adx_fsvr.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_stmc.h"

extern void func_004c7228(void);

// 100% matching!
// FUN_004C6F08
void ADXT_ExecFsSvr(void)
{
    func_004c7228();
    ADXF_ExecServer();
    ADXSTM_ExecServer();
}
