#include "type.h"
#include "field_event_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
struct RwV3d; struct RwMatrix; struct RwMatrixTag; struct Resrc;
struct DatUnitGenusBase; struct P4_0015_Vec3; struct KwlnTask;
typedef struct { f32 x,y,z; } FldEventVec3;
typedef struct { s32 x; } FldEventFlag;
static unsigned scenario, cases;
#define CHECK(x) do { if (!(x)) native32_failure(__LINE__,scenario,#x); } while (0)
enum { ID_K_FldEvent_ArePosWithinDist, ID_K_FldEvent_IsPosWithinFov, ID_MT_Scene_GetRes, ID_RpRandom, ID_datGetFlag, ID_func_001056e0, ID_func_00105d50, ID_func_00106390, ID_func_00113480, ID_func_00122640, ID_func_00122720, ID_func_001238c0, ID_func_00144c90, ID_func_00144e10, ID_func_00144ed0, ID_func_00144f60, ID_func_00145080, ID_func_00145ac0, ID_func_0014a0f0, ID_func_0014a200, ID_func_0014a270, ID_func_0014b510, ID_func_0014c540, ID_func_0014e740, ID_func_0014e8c0, ID_func_0014eed0, ID_func_0014ef40, ID_func_0014ef80, ID_func_00151f80, ID_func_001546a0, ID_func_00155280, ID_func_00156170, ID_func_00156180, ID_func_00156190, ID_func_0015a100, ID_func_0015a130, ID_func_0015a160, ID_func_0015a350, ID_func_0015a520, ID_func_0015a7c0, ID_func_0015c1e0, ID_func_0015ff20, ID_func_00160000, ID_func_001601e0, ID_func_001602a0, ID_func_00160440, ID_func_00163fc0, ID_func_00164020, ID_func_001641d0, ID_func_00164f40, ID_func_00164f50, ID_func_00165270, ID_func_00165300, ID_func_00165380, ID_func_001657e0, ID_func_00165840, ID_func_00165b00, ID_func_00165be0, ID_func_001664a0, ID_func_00166b40, ID_func_00166c30, ID_func_00166c60, ID_func_0016e2e0, ID_func_0016ea40, ID_func_0016f630, ID_func_0016f750, ID_func_0016fd00, ID_func_00172ba0, ID_func_00175ea0, ID_func_00182310, ID_func_00182390, ID_func_001823c0, ID_func_00186640, ID_func_0018a000, ID_func_0018c7e0, ID_func_0018df60, ID_func_00192e90, ID_func_001fc1b0, ID_func_001fc270, ID_func_002319f0, ID_func_0029da90, ID_func_0029db50, ID_func_002ae630, ID_func_002b2950, ID_func_002bd3c0, ID_func_002bd410, ID_func_00452080, ID_func_00452490, ID_func_00457120, ID_func_00457130, ID_func_00457140, ID_func_0045af60, ID_func_00477e80, ID_func_004782b0, ID_func_00479940, ID_func_00479e60, ID_func_0047a080, ID_func_0047a180, ID_mdlGetMatrix, ID_COUNT };

static unsigned calls[ID_COUNT], results[ID_COUNT], args[ID_COUNT][6];
struct Resrc * MT_Scene_GetRes(u16 a0) { calls[ID_MT_Scene_GetRes]++; args[ID_MT_Scene_GetRes][0] = (u32)a0; return (struct Resrc *)results[ID_MT_Scene_GetRes]; }
u32 RpRandom(void) { calls[ID_RpRandom]++;  return (u32)results[ID_RpRandom]; }
void func_001056e0(s16 a0, s16 a1) { calls[ID_func_001056e0]++; args[ID_func_001056e0][0] = (u32)a0; args[ID_func_001056e0][1] = (u32)a1; }
void func_00105d50(s16 a0, u32 a1) { calls[ID_func_00105d50]++; args[ID_func_00105d50][0] = (u32)a0; args[ID_func_00105d50][1] = (u32)a1; }
void func_00113480(s32 a0, s32 a1, s32 a2, s32 a3) { calls[ID_func_00113480]++; args[ID_func_00113480][0] = (u32)a0; args[ID_func_00113480][1] = (u32)a1; args[ID_func_00113480][2] = (u32)a2; args[ID_func_00113480][3] = (u32)a3; }
s32 func_00122640(s32 a0, s32 a1) { calls[ID_func_00122640]++; args[ID_func_00122640][0] = (u32)a0; args[ID_func_00122640][1] = (u32)a1; return (s32)results[ID_func_00122640]; }
s32 func_00122720(void) { calls[ID_func_00122720]++;  return (s32)results[ID_func_00122720]; }
void func_001238c0(s32 a0) { calls[ID_func_001238c0]++; args[ID_func_001238c0][0] = (u32)a0; }
void func_00144c90(s32 a0, s32 a1) { calls[ID_func_00144c90]++; args[ID_func_00144c90][0] = (u32)a0; args[ID_func_00144c90][1] = (u32)a1; }
void func_00144e10(s64 a0) { calls[ID_func_00144e10]++; args[ID_func_00144e10][0] = (u32)a0; }
void func_00144ed0(s64 a0) { calls[ID_func_00144ed0]++; args[ID_func_00144ed0][0] = (u32)a0; }
s32 func_00144f60(void) { calls[ID_func_00144f60]++;  return (s32)results[ID_func_00144f60]; }
void func_00145080(void) { calls[ID_func_00145080]++;  }
s32 func_00145ac0(u16 a0, s32 a1) { calls[ID_func_00145ac0]++; args[ID_func_00145ac0][0] = (u32)a0; args[ID_func_00145ac0][1] = (u32)a1; return (s32)results[ID_func_00145ac0]; }
void func_0014a0f0(u16 a0, u32 a1) { calls[ID_func_0014a0f0]++; args[ID_func_0014a0f0][0] = (u32)a0; args[ID_func_0014a0f0][1] = (u32)a1; }
s32 func_0014a200(void) { calls[ID_func_0014a200]++;  return (s32)results[ID_func_0014a200]; }
s32 func_0014a270(void) { calls[ID_func_0014a270]++;  return (s32)results[ID_func_0014a270]; }
u16 func_0014b510(s32 a0) { calls[ID_func_0014b510]++; args[ID_func_0014b510][0] = (u32)a0; return (u16)results[ID_func_0014b510]; }
s32 func_0014e8c0(u8 * a0, s32 a1) { calls[ID_func_0014e8c0]++; args[ID_func_0014e8c0][0] = (u32)a0; args[ID_func_0014e8c0][1] = (u32)a1; return (s32)results[ID_func_0014e8c0]; }
void func_0014eed0(s32 a0, s32 a1) { calls[ID_func_0014eed0]++; args[ID_func_0014eed0][0] = (u32)a0; args[ID_func_0014eed0][1] = (u32)a1; }
s32 func_0014ef40(void) { calls[ID_func_0014ef40]++;  return (s32)results[ID_func_0014ef40]; }
s32 func_0014ef80(void) { calls[ID_func_0014ef80]++;  return (s32)results[ID_func_0014ef80]; }
void func_00151f80(u8 * a0) { calls[ID_func_00151f80]++; args[ID_func_00151f80][0] = (u32)a0; }
s32 func_001546a0(s32 a0, s32 a1) { calls[ID_func_001546a0]++; args[ID_func_001546a0][0] = (u32)a0; args[ID_func_001546a0][1] = (u32)a1; return (s32)results[ID_func_001546a0]; }
s32 func_00156170(u8 * a0) { calls[ID_func_00156170]++; args[ID_func_00156170][0] = (u32)a0; return (s32)results[ID_func_00156170]; }
s32 func_00156180(u8 * a0) { calls[ID_func_00156180]++; args[ID_func_00156180][0] = (u32)a0; return (s32)results[ID_func_00156180]; }
s32 func_00156190(u8 * a0) { calls[ID_func_00156190]++; args[ID_func_00156190][0] = (u32)a0; return (s32)results[ID_func_00156190]; }
s32 func_0015a100(void) { calls[ID_func_0015a100]++;  return (s32)results[ID_func_0015a100]; }
s32 func_0015a130(void) { calls[ID_func_0015a130]++;  return (s32)results[ID_func_0015a130]; }
s32 func_0015a160(void) { calls[ID_func_0015a160]++;  return (s32)results[ID_func_0015a160]; }
void func_0015a520(s32 a0) { calls[ID_func_0015a520]++; args[ID_func_0015a520][0] = (u32)a0; }
s32 func_0015a7c0(s32 a0) { calls[ID_func_0015a7c0]++; args[ID_func_0015a7c0][0] = (u32)a0; return (s32)results[ID_func_0015a7c0]; }
s32 func_0015c1e0(s32 a0) { calls[ID_func_0015c1e0]++; args[ID_func_0015c1e0][0] = (u32)a0; return (s32)results[ID_func_0015c1e0]; }
u8 * func_0015ff20(s32 a0, s32 a1) { calls[ID_func_0015ff20]++; args[ID_func_0015ff20][0] = (u32)a0; args[ID_func_0015ff20][1] = (u32)a1; return (u8 *)results[ID_func_0015ff20]; }
s32 func_00160000(u8 * a0) { calls[ID_func_00160000]++; args[ID_func_00160000][0] = (u32)a0; return (s32)results[ID_func_00160000]; }
u8 * func_001601e0(s32 a0) { calls[ID_func_001601e0]++; args[ID_func_001601e0][0] = (u32)a0; return (u8 *)results[ID_func_001601e0]; }
s32 func_001602a0(u8 * a0, s32 a1) { calls[ID_func_001602a0]++; args[ID_func_001602a0][0] = (u32)a0; args[ID_func_001602a0][1] = (u32)a1; return (s32)results[ID_func_001602a0]; }
void func_00160440(void) { calls[ID_func_00160440]++;  }
s32 func_00163fc0(void) { calls[ID_func_00163fc0]++;  return (s32)results[ID_func_00163fc0]; }
void func_00164020(u8 * a0) { calls[ID_func_00164020]++; args[ID_func_00164020][0] = (u32)a0; }
void func_001641d0(void) { calls[ID_func_001641d0]++;  }
s32 func_00164f40(void) { calls[ID_func_00164f40]++;  return (s32)results[ID_func_00164f40]; }
void func_00164f50(s32 a0) { calls[ID_func_00164f50]++; args[ID_func_00164f50][0] = (u32)a0; }
void func_00165270(void) { calls[ID_func_00165270]++;  }
s32 func_00165300(void) { calls[ID_func_00165300]++;  return (s32)results[ID_func_00165300]; }
void func_00165380(void) { calls[ID_func_00165380]++;  }
void func_001657e0(s32 a0) { calls[ID_func_001657e0]++; args[ID_func_001657e0][0] = (u32)a0; }
void func_00165840(s32 a0) { calls[ID_func_00165840]++; args[ID_func_00165840][0] = (u32)a0; }
void func_00165b00(void) { calls[ID_func_00165b00]++;  }
s32 func_00165be0(void) { calls[ID_func_00165be0]++;  return (s32)results[ID_func_00165be0]; }
void func_001664a0(void) { calls[ID_func_001664a0]++;  }
s32 func_00166b40(u8 * a0, s32 a1) { calls[ID_func_00166b40]++; args[ID_func_00166b40][0] = (u32)a0; args[ID_func_00166b40][1] = (u32)a1; return (s32)results[ID_func_00166b40]; }
u32 func_00166c30(u8 * a0) { calls[ID_func_00166c30]++; args[ID_func_00166c30][0] = (u32)a0; return (u32)results[ID_func_00166c30]; }
void func_00166c60(u8 * a0, s32 a1) { calls[ID_func_00166c60]++; args[ID_func_00166c60][0] = (u32)a0; args[ID_func_00166c60][1] = (u32)a1; }
s32 func_0016e2e0(s32 a0) { calls[ID_func_0016e2e0]++; args[ID_func_0016e2e0][0] = (u32)a0; return (s32)results[ID_func_0016e2e0]; }
void func_0016ea40(u8 * a0, u16 a1) { calls[ID_func_0016ea40]++; args[ID_func_0016ea40][0] = (u32)a0; args[ID_func_0016ea40][1] = (u32)a1; }
s32 func_0016fd00(s32 a0) { calls[ID_func_0016fd00]++; args[ID_func_0016fd00][0] = (u32)a0; return (s32)results[ID_func_0016fd00]; }
s32 func_00172ba0(void) { calls[ID_func_00172ba0]++;  return (s32)results[ID_func_00172ba0]; }
s32 func_00175ea0(s32 a0, s32 a1, s32 a2) { calls[ID_func_00175ea0]++; args[ID_func_00175ea0][0] = (u32)a0; args[ID_func_00175ea0][1] = (u32)a1; args[ID_func_00175ea0][2] = (u32)a2; return (s32)results[ID_func_00175ea0]; }
void func_00182310(s32 a0) { calls[ID_func_00182310]++; args[ID_func_00182310][0] = (u32)a0; }
void func_00182390(void) { calls[ID_func_00182390]++;  }
s32 func_00186640(u8 * a0) { calls[ID_func_00186640]++; args[ID_func_00186640][0] = (u32)a0; return (s32)results[ID_func_00186640]; }
void func_0018a000(u8 * a0, s32 a1) { calls[ID_func_0018a000]++; args[ID_func_0018a000][0] = (u32)a0; args[ID_func_0018a000][1] = (u32)a1; }
s32 func_0018c7e0(void) { calls[ID_func_0018c7e0]++;  return (s32)results[ID_func_0018c7e0]; }
s32 func_0018df60(s32 a0) { calls[ID_func_0018df60]++; args[ID_func_0018df60][0] = (u32)a0; return (s32)results[ID_func_0018df60]; }
s32 func_00192e90(s32 a0) { calls[ID_func_00192e90]++; args[ID_func_00192e90][0] = (u32)a0; return (s32)results[ID_func_00192e90]; }
void func_001fc1b0(s16 a0) { calls[ID_func_001fc1b0]++; args[ID_func_001fc1b0][0] = (u32)a0; }
s32 func_001fc270(void) { calls[ID_func_001fc270]++;  return (s32)results[ID_func_001fc270]; }
u32 func_002319f0(struct DatUnitGenusBase * a0) { calls[ID_func_002319f0]++; args[ID_func_002319f0][0] = (u32)a0; return (u32)results[ID_func_002319f0]; }
s32 func_0029da90(s32 a0, u8 * a1, s32 a2) { calls[ID_func_0029da90]++; args[ID_func_0029da90][0] = (u32)a0; args[ID_func_0029da90][1] = (u32)a1; args[ID_func_0029da90][2] = (u32)a2; return (s32)results[ID_func_0029da90]; }
s32 func_0029db50(s32 a0, s32 a1, s32 a2, s32 a3) { calls[ID_func_0029db50]++; args[ID_func_0029db50][0] = (u32)a0; args[ID_func_0029db50][1] = (u32)a1; args[ID_func_0029db50][2] = (u32)a2; args[ID_func_0029db50][3] = (u32)a3; return (s32)results[ID_func_0029db50]; }
u8 * func_002ae630(u8 * a0) { calls[ID_func_002ae630]++; args[ID_func_002ae630][0] = (u32)a0; return (u8 *)results[ID_func_002ae630]; }
void func_002b2950(s32 a0) { calls[ID_func_002b2950]++; args[ID_func_002b2950][0] = (u32)a0; }
void func_002bd3c0(void) { calls[ID_func_002bd3c0]++;  }
void func_002bd410(void) { calls[ID_func_002bd410]++;  }
s32 func_00452080(struct KwlnTask * a0) { calls[ID_func_00452080]++; args[ID_func_00452080][0] = (u32)a0; return (s32)results[ID_func_00452080]; }
s32 func_00452490(void * a0) { calls[ID_func_00452490]++; args[ID_func_00452490][0] = (u32)a0; return (s32)results[ID_func_00452490]; }
void func_00457140(u8 a0, u8 a1, u8 a2, u8 a3) { calls[ID_func_00457140]++; args[ID_func_00457140][0] = (u32)a0; args[ID_func_00457140][1] = (u32)a1; args[ID_func_00457140][2] = (u32)a2; args[ID_func_00457140][3] = (u32)a3; }
s32 func_0045af60(s16 a0, s16 a1, s16 a2, s16 a3) { calls[ID_func_0045af60]++; args[ID_func_0045af60][0] = (u32)a0; args[ID_func_0045af60][1] = (u32)a1; args[ID_func_0045af60][2] = (u32)a2; args[ID_func_0045af60][3] = (u32)a3; return (s32)results[ID_func_0045af60]; }
void * func_00477e80(u32 a0, u16 a1, void * a2, u32 a3) { calls[ID_func_00477e80]++; args[ID_func_00477e80][0] = (u32)a0; args[ID_func_00477e80][1] = (u32)a1; args[ID_func_00477e80][2] = (u32)a2; args[ID_func_00477e80][3] = (u32)a3; return (void *)results[ID_func_00477e80]; }
s32 func_004782b0(u8 * a0) { calls[ID_func_004782b0]++; args[ID_func_004782b0][0] = (u32)a0; return (s32)results[ID_func_004782b0]; }
struct RwMatrixTag * func_0047a180(struct RwMatrixTag * a0, const struct RwV3d * a1, s32 a2) { calls[ID_func_0047a180]++; args[ID_func_0047a180][0] = (u32)a0; args[ID_func_0047a180][1] = (u32)a1; args[ID_func_0047a180][2] = (u32)a2; return (struct RwMatrixTag *)results[ID_func_0047a180]; }u32 D_007EFA00[1],D_007EFA04[1],D_00762EA0;
FldEventFlag D_007EF9F8[1];
u8 D_007EF9B0[4*0x750] __attribute__((aligned(16)));
u8 D_007E8C00[15*0x750] __attribute__((aligned(16)));
s32 D_007E8060[16];
char D_005F17B0[]="field%03d";
FldEventAttack *iGpffffb2cc;
u8 *iGpffffb2c8;
s32 iGpffffb284;
u8 iGpffffba4c,iGpffffba50,iGpffffba54,iGpffffba58;
f32 iGpffffba6c;
static FldEventWork work;
static FldEventAttack attacks[2];
static FldEventUnit units[20];
static u8 task[64],world[0x40],scene[0x100],camera[0x100],resource[0x240],unitData[0x20];
static u8 cameraColor[4],encounters[15][0x18],kindTable[4*64];
static f32 matrices[16][16],animationFrame,initialFrame,lastTarget[3];
static u32 flags[0x1600];
static FldEventActor *found,*interaction;
static s32 fovResult,nearMask;
static FldEventSnapshot capturedSnapshot;
static int sprintf(char *dst,const char *fmt,...) { dst[0]='x';dst[1]=0;return 1; }
void *mdlGetMatrix(void *model) { ++calls[ID_mdlGetMatrix];return model; }
f32 func_0047a080(s32 model,s32 layer) { CHECK(model==(s32)D_007EFA00[0]);CHECK(layer==0);return animationFrame; }
s32 func_00479940(u8 *model,u32 layer,s16 animation,u16 blend,s32 mode) {
    calls[ID_func_00479940]++;args[ID_func_00479940][0]=(u32)model;
    args[ID_func_00479940][1]=layer;args[ID_func_00479940][2]=(s32)animation;
    args[ID_func_00479940][3]=blend;args[ID_func_00479940][4]=mode;return 0;
}
void func_00479e60(void *model,s32 layer,f32 frame) { CHECK(model==(void*)D_007EFA00[0]);CHECK(layer==0);initialFrame=frame; }
u8 *func_0014c540(u8 *party,f32 distance,f32 fov) {
    CHECK(party==D_007EF9B0);CHECK(distance==work.attack->distance);CHECK(fov==work.attack->fov);
    calls[ID_func_0014c540]++;return (u8*)found;
}
s32 *func_00155280(void) { return (s32*)world; }
u8 *func_001823c0(void) { return (u8*)&interaction; }
s32 func_00457120(void) { return (s32)camera; }
s8 *func_00457130(void) { return (s8*)cameraColor; }
void func_0016f630(FldEventSnapshot *out,u8 *cameraTask) {
    CHECK(cameraTask==(u8*)*(s32*)(world+4));calls[ID_func_0016f630]++;
    for(unsigned i=0;i<28;i++)out->words[i]=0xA0B00000+i;
}
void func_0016f750(u8 *cameraTask,u8 *snapshot) {
    CHECK(cameraTask==(u8*)*(s32*)(world+4));CHECK(snapshot==(u8*)&work.snapshot);
    capturedSnapshot=*(FldEventSnapshot*)snapshot;calls[ID_func_0016f750]++;
}
u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *a,const struct RwV3d *b,f32 limit) {
    CHECK((void*)a==&matrices[0][12]);CHECK(limit==2400.0f);
    unsigned index=((const f32*)b-&matrices[1][12])/16;
    CHECK(index<15);calls[ID_K_FldEvent_ArePosWithinDist]++;return (nearMask>>index)&1;
}
u32 K_FldEvent_IsPosWithinFov(const struct RwMatrix *viewer,const struct RwV3d *target,f32 fov) {
    calls[ID_K_FldEvent_IsPosWithinFov]++;
    if(work.state==1) { CHECK(viewer==(void*)matrices[1]);CHECK((void*)target==&matrices[0][12]);CHECK(fov==270); }
    else { CHECK(viewer==(void*)matrices[0]);CHECK((void*)target==&matrices[1][12]);CHECK(fov==attacks[0].fov); }
    return fovResult;
}
u32 datGetFlag(s32 id) { CHECK(id>=0 && id<0x1600);return flags[id]; }
void func_00106390(s32 id,s32 value) { CHECK(id>=0 && id<0x1600);flags[id]=value;calls[ID_func_00106390]++; }
void func_0015a350(struct P4_0015_Vec3 *out) { *(FldEventVec3*)out=(FldEventVec3){7,8,9}; }
s32 func_0014e740(u8 *cameraTask,f32 *target) {
    CHECK(cameraTask==(u8*)results[ID_func_0015c1e0]);
    for(unsigned i=0;i<3;i++)lastTarget[i]=target[i];calls[ID_func_0014e740]++;return 1;
}
static FldEventActor *enemy(unsigned i) { return (FldEventActor*)(D_007E8C00+i*0x750); }
static FldEventActor *party(unsigned i) { return (FldEventActor*)(D_007EF9B0+i*0x750); }
static void reset(s32 state) {
    ++scenario;++cases;
    memset(&work,0,sizeof(work));memset(calls,0,sizeof(calls));memset(results,0,sizeof(results));
    memset(args,0,sizeof(args));memset(D_007EF9B0,0,sizeof(D_007EF9B0));memset(D_007E8C00,0,sizeof(D_007E8C00));
    memset(units,0,sizeof(units));memset(flags,0,sizeof(flags));memset(world,0,sizeof(world));
    memset(scene,0,sizeof(scene));memset(camera,0,sizeof(camera));memset(resource,0,sizeof(resource));
    memset(kindTable,0,sizeof(kindTable));memset(encounters,0,sizeof(encounters));memset(D_007E8060,0,sizeof(D_007E8060));
    memset(lastTarget,0,sizeof(lastTarget));memset(&capturedSnapshot,0,sizeof(capturedSnapshot));
    *(FldEventWork**)(task+0x38)=&work;work.state=state;work.attack=&attacks[0];work.target=enemy(0);
    attacks[0]=(FldEventAttack){-7,0,3,20,0,10,135.0f,250.0f,30.5f,2,4};attacks[1]=attacks[0];attacks[1].animation=9;
    iGpffffb2cc=attacks;iGpffffb2c8=kindTable;D_007EFA00[0]=(u32)matrices[0];D_007EFA04[0]=(u32)unitData;
    D_00762EA0=(u32)scene;D_007EF9F8[0].x=(s32)&units[0];
    *(s32*)scene=55;*(s32*)world=(s32)task;
    for(unsigned i=0;i<15;i++) { enemy(i)->unit=&units[i+4];enemy(i)->encounterData=encounters[i];enemy(i)->model=(u32)matrices[i+1];enemy(i)->active=1; }
    for(unsigned i=1;i<4;i++) { party(i)->unit=&units[i];party(i)->partyId=i+2; }
    for(unsigned i=0;i<16;i++) { matrices[i][12]=10+i;matrices[i][13]=20+i;matrices[i][14]=30+i; }
    found=enemy(0);interaction=enemy(0);animationFrame=10;fovResult=1;nearMask=0x7fff;
    cameraColor[0]=11;cameraColor[1]=22;cameraColor[2]=33;cameraColor[3]=44;
    iGpffffba4c=5;iGpffffba50=6;iGpffffba54=7;iGpffffba58=8;iGpffffba6c=321;
    *(f32*)(camera+0x88)=123;
    results[ID_func_0015c1e0]=(u32)unitData;
    results[ID_func_0014e8c0]=5;
    results[ID_func_00156170]=28;results[ID_func_00156180]=2;results[ID_func_00156190]=0xFFFF;
    results[ID_func_001546a0]=0x8001;
    results[ID_MT_Scene_GetRes]=(u32)resource;
    results[ID_func_00145ac0]=0x402;
}
static void checkBattle(void) {
    CHECK(work.battle.party[0]==&units[0]);
    for(unsigned i=1;i<4;i++) { CHECK(work.battle.party[i]==&units[i]);CHECK(units[i].flags&1); }
    CHECK(work.battle.enemies[0]==enemy(0)->unit);
    CHECK(work.nearby[0]==enemy(1));CHECK(work.nearby[1]==enemy(2));
    CHECK(work.battle.enemies[1]==enemy(1)->unit);CHECK(work.battle.enemies[2]==enemy(2)->unit);
    CHECK(work.battle.fieldId==235 && work.battle.roomId==1);
}
