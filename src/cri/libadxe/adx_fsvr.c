#include "../../../cri/mwlib/ee/lib/libadxe/adx_fsvr.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_stmc.h"

// 100% matching!
// FUN_004C6F08
void ADXT_ExecFsSvr(void)
{
    cvFsExecServer();
    ADXF_ExecServer();
    ADXSTM_ExecServer();
}
