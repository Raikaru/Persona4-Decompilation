#include "include_asm.h"
/* Source unit: src/Battle/btlSound_001f7530.c */
#include "type.h"

typedef struct Battle Battle;
struct Battle
{
    u8 _pad00[0xc];
    u32 flags;
};

extern Battle* iGpfffb3ac;
extern void func_00459880(void);
extern void func_004598e0(s32 fadeDuration);

extern void func_0045aac0(s16 channel, s32 unused, s32 fadeFrames);

typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x47];
    u8 unk_47;
    u8 _pad48[0x20];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 _pad74[4];
    void* workData;
};

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern void func_001f7ad0(void* work);
extern u32 func_001f7b40(void* work);

extern void func_0045aa90(s16 bank, s16 cue);

extern void func_0045af60(s32 bank, s32 channel, s32 cue, s32 variant);
extern void func_001f7ca0(u16* work);
extern u32 func_001f7cd0(s16* work);

typedef struct BtlSoundPacketSkillSE BtlSoundPacketSkillSE;
struct BtlSoundPacketSkillSE
{
    u32 timer;
    u16 skillId;
    u16 state;
    void* cdvd;
    u16 flags;
    u8 _pad0e[2];
};
extern u32 func_001f7d90(void* work);
extern u32 func_001f7e30(void* work);
extern u32 func_001f8070(void* work);

extern u32 sprintf(void* buffer, const void* format, ...);
extern char sGpffffa500[5];
extern char DAT_00624F40[15];
extern u8 func_0045aeb0(s16 channelIndex, const char* name);

extern u32 strlen(const char* text);
extern u32 func_001f8190(u16* work);
extern void strcpy(char* destination, const char* source);
extern u32 func_001f8280(void* work);
extern u32 func_001f8300(void* work);
extern u32 func_001f9750(void* work);



// FUN_001F7530
void func_001f7530(void)
{
    if ((iGpfffb3ac->flags & 0x40) != 0)
    {
        func_00459880();
    }
}



// FUN_001F7570
void func_001f7570(s16 fadeDuration)
{
    if ((iGpfffb3ac->flags & 0x40) != 0)
    {
        func_004598e0(fadeDuration);
    }
}



// FUN_001F7620
void func_001f7620(s16 channel, s32 fadeFrames)
{
    func_0045aac0(channel, 0, (u16)fadeFrames);
}



// FUN_001F7C20
void func_001f7c20(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet;
    u16* work;

    packet = func_00194470(0x902, 6);
    packet->initFunc = (BtlPacketFunc)func_001f7ad0;
    packet->updateFunc = func_001f7b40;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
}



// FUN_001F7CA0
void func_001f7ca0(u16* work)
{
    func_0045aa90(0, (s16)*work);
}



// FUN_001F7CD0
u32 func_001f7cd0(s16* work)
{
    func_0045af60(0, work[0], work[1], work[2]);
    return 1;
}



// FUN_001F7D10
void func_001f7d10(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet;
    u16* work;

    packet = func_00194470(0x901, 6);
    packet->initFunc = (BtlPacketFunc)func_001f7ca0;
    packet->updateFunc = (BtlPacketFunc)func_001f7cd0;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
}



// FUN_001F7D90
INCLUDE_ASM("asm/nonmatchings/btlSound", func_001f7d90);

// FUN_001F7E30
INCLUDE_ASM("asm/nonmatchings/btlSound", func_001f7e30);
// FUN_001F8000
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags)
{
    BtlPacket* packet;
    BtlSoundPacketSkillSE* work;

    packet = func_00194470(0x903, sizeof(BtlSoundPacketSkillSE));
    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = func_001f7d90;
    packet->updateFunc = func_001f7e30;
    work = (BtlSoundPacketSkillSE*)packet->workData;
    work->skillId = skillId;
    work->flags = flags;
    return packet;
}



// FUN_001F8140
void func_001f8140(u16 state)
{
    BtlPacket* packet;

    packet = func_00194470(0x904, 2);
    packet->updateFunc = func_001f8070;
    *(u16*)packet->workData = state;
}



// FUN_001F8190
u32 func_001f8190(u16* work)
{
    char path[512];

    sprintf(path, sGpffffa500, DAT_00624F40, *(u32*)(work + 2));
    func_0045aeb0((s16)*work, path);
    return 1;
}



// FUN_001F81F0
BtlPacket* func_001f81f0(u16 channel, const char* streamName)
{
    u32 length;
    BtlPacket* packet;
    u8* work;

    length = strlen(streamName);
    packet = func_00194470(0x905, length + 8);
    packet->updateFunc = (BtlPacketFunc)func_001f8190;
    work = (u8*)packet->workData;
    *(u16*)work = channel;
    *(char**)(work + 4) = (char*)(work + 8);
    strcpy((char*)work + 8, streamName);
    return packet;
}



// FUN_001F82B0
void func_001f82b0(void* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x909, 4);
    packet->updateFunc = func_001f8280;
    *(void**)packet->workData = unit;
}



// FUN_001F8330
void func_001f8330(void* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x90A, 4);
    packet->updateFunc = func_001f8300;
    *(void**)packet->workData = unit;
}



// FUN_001F97B0
void func_001f97b0(void)
{
    BtlPacket* packet;
    u32* work;

    packet = func_00194470(0xA00, 8);
    packet->unk_47 &= ~(1 << 0);
    packet->updateFunc = func_001f9750;
    work = (u32*)packet->workData;
    work[0] = 0;
    work[1] = 0;
}
