#include "include_asm.h"
/* Source unit: src/Battle/btlSound_001f7530.c */
#include "type.h"

typedef struct Battle Battle;
struct Battle
{
    u8 _pad00[0xc];
    u32 flags;
};

extern Battle* iGpffffb3ac;
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
extern void func_001f7d90(void* work);
extern u32 func_001f7e30(void* work);
extern u32 func_001f8070(u16* work);

extern u32 sprintf(void* buffer, const void* format, ...);
extern char sGpffffa500[5];
extern char sGpffffa4F0[7];
extern char sGpffffa4F8[7];
extern char DAT_00624F40[15];
extern char D_00624F20[];
extern char D_00624F30[];
extern u8 func_0045aeb0(s16 channelIndex, const char* name);
extern u8 *D_0076449C;

extern void func_00440b68(const char* fmt, const char* file, s32 line);
extern void* func_00454a60(const char* path, s32 flags);
extern s32 func_004553c0(void* handle);
extern void func_00454bd0(void* handle);
extern void* func_00455ea0(void* handle, s32 index, void* out);
extern void func_0045a570(s32 bank, void* file1, u32 size1, void* file2, u32 size2, void* file3, u32 size3);
extern s32 func_0045a890(s32 bank);

extern u32 strlen(const char* text);
extern u32 func_001f8190(u16* work);
extern void strcpy(char* destination, const char* source);
extern u32 func_001f8280(void* work);
extern u32 func_001f8300(void* work);
extern u32 func_001f9750(void* work);



// FUN_001F7530
void func_001f7530(void)
{
    if ((iGpffffb3ac->flags & 0x40) != 0)
    {
        func_00459880();
    }
}



// FUN_001F7570
void func_001f7570(s16 fadeDuration)
{
    if ((iGpffffb3ac->flags & 0x40) != 0)
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
void func_001f7d90(void* work)
{
    BtlSoundPacketSkillSE* packet;
    char buffer[128];

    packet = (BtlSoundPacketSkillSE*)work;

    if (!(packet->flags & 1))
    {
        sprintf(buffer, D_00624F30, sGpffffa4F8, packet->skillId);
        func_00440b68(sGpffffa4F0, D_00624F20, 0x274);
        packet->cdvd = func_00454a60(buffer, 0);
    }
    else
    {
        packet->cdvd = NULL;
    }

    packet->state = 1;
    packet->timer = 0;
}

// FUN_001F7E30
u32 func_001f7e30(void* work)
{
    BtlSoundPacketSkillSE* packet = (BtlSoundPacketSkillSE*)work;
    char buffer[128];
    void* file1;
    void* file2;
    void* file3;
    u32 file1Size;
    u32 file2Size;
    u32 file3Size;
    s32 i;

    if (packet->cdvd == NULL)
    {
        sprintf(buffer, D_00624F30, sGpffffa4F8, packet->skillId);
        func_00440b68(sGpffffa4F0, D_00624F20, 0x2AA);
        packet->cdvd = func_00454a60(buffer, 0);
    }

    switch (packet->state)
    {
    case 1:
        if (!func_004553c0(packet->cdvd))
        {
            return 0;
        }

        func_0045aa90(2, 4);
        for (i = 5; i <= 9; i++)
        {
            func_0045aa90(2, (s16)i);
        }

        file1 = func_00455ea0(packet->cdvd, 0, &file1Size);
        file2 = func_00455ea0(packet->cdvd, 1, &file2Size);
        file3 = func_00455ea0(packet->cdvd, 2, &file3Size);
        func_0045a570(2, file1, file1Size, file2, file2Size, file3, file3Size);
        packet->state = 2;
        break;
    case 2:
        if (!func_0045a890(2))
        {
            return 0;
        }

        func_00454bd0(packet->cdvd);
        return 1;
    }

    packet->timer++;
    return 0;
}
// FUN_001F8000
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags)
{
    BtlPacket* packet;
    BtlSoundPacketSkillSE* work;

    packet = func_00194470(0x903, sizeof(BtlSoundPacketSkillSE));
    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = (BtlPacketFunc)func_001f7d90;
    packet->updateFunc = func_001f7e30;
    work = (BtlSoundPacketSkillSE*)packet->workData;
    work->skillId = skillId;
    work->flags = flags;
    return packet;
}



// FUN_001F8070
u32 func_001f8070(u16* work)
{
    u16 state;
    s16 channel;
    u8* global;

    state = *work;
    switch (state)
    {
    case 0:
        func_0045af60(2, 4, 0, (s16)state);
        break;
    case 1:
        global = D_0076449C;
        if (*(s8*)(global + 0xaca) == -1)
        {
            channel = *(s16*)(global + 0xac8);
            func_0045af60(2, channel, 0, (s16)state);
            D_0076449C[0xaca] = 0;
            if ((*(u16*)(D_0076449C + 0xac8) += 1) >= 9)
            {
                *(u16*)(D_0076449C + 0xac8) = 5;
            }
        }
        break;
    }
    return 1;
}
// FUN_001F8140
void func_001f8140(u16 state)
{
    BtlPacket* packet;

    packet = func_00194470(0x904, 2);
    packet->updateFunc = (BtlPacketFunc)func_001f8070;
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



// FUN_001F8280
u32 func_001f8280(void* work)
{
    u8* unit;

    unit = *(u8**)work;
    if ((*(s32*)(unit + 0x98) & 2) != 0)
    {
        *(u16*)(unit + 0x9d8) &= (u16)~0x10;
    }
    return 1;
}
// FUN_001F82B0
void func_001f82b0(void* unit)
{
    BtlPacket* packet;

    packet = func_00194470(0x909, 4);
    packet->updateFunc = func_001f8280;
    *(void**)packet->workData = unit;
}



// FUN_001F8300
u32 func_001f8300(void* work)
{
    u8* unit;

    unit = *(u8**)work;
    if ((*(s32*)(unit + 0x98) & 2) != 0)
    {
        *(u16*)(unit + 0x9d8) |= 0x10;
    }
    return 1;
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
