#include "cri_xpt.h"

typedef struct SFD_TAG *SFD;

extern Sint32 func_00515980(SFD sfd, Sint32 id, Sint32 flag);
extern Sint32 func_0051ace8(SFD sfd, Sint32 *out0, Sint32 *out1, Sint32 *out2);
extern Sint32 func_0051b498(SFD sfd, Sint32 p1, Sint32 p2, Sint32 p3, Sint32 *out);
extern void func_0051e5e8(SFD sfd);

// FUN_0051AC48
Sint32 func_0051ac48(SFD sfd, Sint32 flag)
{
    return func_00515980(sfd, *(Sint32 *)((Uint8 *)sfd + 0x1FCC), flag);
}

// FUN_0051AC68
Sint32 func_0051ac68(SFD sfd)
{
    Sint32 v0, v1, v2, rest;
    Sint32 ret;

    for (;;) {
        ret = func_0051ace8(sfd, &v0, &v1, &v2);
        if (ret == 0) {
            ret = func_0051b498(sfd, v0, v1, v2, &rest);
            if (ret == 0 && rest != 0) {
                continue;
            }
        }
        break;
    }
    func_0051e5e8(sfd);
    return ret;
}
