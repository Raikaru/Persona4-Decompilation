/* Original translation unit pscRes.c (from __FILE__ assert strings). */
#include "type.h"
#include "member_access.h"
#include "member_access.h"
#include "member_access.h"
#include "member_access.h"
#include "h_cdvd_internal.h"

/* Slot strides and fields are shared by allocation, retain/release and polling. */
typedef struct PscImageEntry
{
    s32 offset;
    s32 unk04;
} PscImageEntry;

typedef struct PscImageContainer
{
    u32 unk00;
    u16 count;
    u16 unk06;
    PscImageEntry entries[];
} PscImageContainer;

typedef struct PscArcanaCard
{
    u32 flags;
    s32 group;
    s32 index;
    s32 raster;
    s32 references;
} PscArcanaCard;

typedef struct PscPersonaCard
{
    u32 flags;
    u16 id;
    u8 pad06[2];
    s32 raster;
    s32 references;
} PscPersonaCard;

typedef struct PscCardRequest
{
    u32 flags;
    s32 state;
    s32 file;
    u8 unk0C[0x104];
    s32 kind;
    s32 slotIndex;
    u8 pad118[0xC];
} PscCardRequest;

typedef struct PscResourceContext
{
    u32 flags;
    s32 baseRaster;
    s32 miscW00Raster;
    s32 miscW01Raster;
    u32 readyFlags;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[4];
    s32 textures[7];
    s32 subTextures[2];
    s32 unk48;
    s32 miscW00References;
    s32 miscW01References;
    PscArcanaCard arcana[16];
    PscPersonaCard personas[16];
    PscCardRequest requests[32];
} PscResourceContext;

extern void kAssertFail(const void *file, u32 line);
extern void func_003ec330(s32);
extern u32 *pscResFindPersonaCard(s32 personaId);
extern void *pscResFindArcanaCard(s32 group, s32 cardIndex);
extern s32 pscResHasPersonaCard(s32 personaId);
extern void pscResRetainPersonaCard(s32 personaId);
extern s32 pscResFindFreePersonaSlot(void);
extern u32 *pscResFindFreeRequest(void);
extern s32 sprintf(char *buf, char *fmt, ...);
extern s32 H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern char D_00723A78;
extern char D_0064E4F0[];
extern char D_0064E510[];
extern char D_0064E530[];
extern char D_00723A80;
extern char D_00723A88;
extern char D_00723A90;
extern char D_00723A98;
extern s32 pscResHasArcanaCard(s32 group, s32 cardIndex);
extern void pscResRetainArcanaCard(s32 group, s32 cardIndex);
extern s32 pscResFindFreeArcanaSlot(void);
extern void strcpy(char *dst, char *src);
extern char D_0064E550[];
extern char D_0064E570[];
extern s32 pscResDecodeImage(const void *input);
typedef struct RwRaster RwRaster;
extern RwRaster *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003ec3d0(RwRaster *raster, s32 lockMode);
extern RwRaster *func_003ec2e0(RwRaster *raster);
extern u8 *func_003ec6a0(RwRaster *raster, u8 level, s32 lockMode);
extern RwRaster *func_003ec2a0(RwRaster *raster);
extern const u8 D_0064E4E0[];
extern void *D_0072469C;


// Initialises the social card resource context: clears slot flags, refcounts and handles, and
// publishes it as the singleton.
// FUN_0036B650
void pscResInit(void *context) {
    s32 i;
    void *p;

    if (D_0072469C != 0) {
        kAssertFail(D_0064E4E0, 0x90);
    }
    p = context;
    *(s32 *)&((PscResourceContext *)p)->flags = 0;
    ((PscResourceContext *)p)->unk18 = 0;
    ((PscResourceContext *)p)->unk1C = 0;
    *(s32 *)&((PscResourceContext *)p)->readyFlags = 0;
    ((PscResourceContext *)p)->unk14 = 0;
    ((PscResourceContext *)p)->baseRaster = 0;
    ((PscResourceContext *)p)->miscW00Raster = 0;
    ((PscResourceContext *)p)->miscW01Raster = 0;
    ((PscResourceContext *)p)->unk48 = 0;
    ((PscResourceContext *)p)->miscW00References = 0;
    for (i = 0; i < 0x20; i++) {
        ((PscResourceContext *)p)->requests[i].flags = 0;
    }
    for (i = 0; i < 0x10; i++) {
        ((PscResourceContext *)p)->arcana[i].flags = 0;
    }
    for (i = 0; i < 0x10; i++) {
        ((PscResourceContext *)p)->personas[i].flags = 0;
    }
    D_0072469C = context;
}

// Poll pending card files, decode completed images into their destination slots, and release each
// completed file request.
// FUN_0036B750
void pscResUpdate(void) {
    PscCardRequest *requestFields;
    HCdvd *loadedFile;
    PscResourceContext *cardContext;
    u8 *e;
    u8 *p;
    s32 i;
    s32 t;
    s32 t2;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    for (i = 0; i < 0x20; i++) {
        e = (u8 *)p + i * 0x124 + 0x294;
        requestFields = (PscCardRequest *)e;
        if (!(~((PscResourceContext *)p)->requests[i].flags & 1)) {
            t = ((PscCardRequest *)e)->state;
            switch (t) {
            case 0:
                kAssertFail(D_0064E4E0, 0xBF);
                break;
            case 1:
                if (H_Cdvd_IsFileLoaded((void *)((PscCardRequest *)e)->file) != 0) {
                    t2 = ((PscCardRequest *)e)->kind;
                    switch (t2) {
                    case 2:
                        switch (((PscCardRequest *)e)->slotIndex) {
                        case 0:
                            if (!(~((PscResourceContext *)p)->readyFlags & 1)) {
                                kAssertFail(D_0064E4E0, 0xCD);
                            }
                            loadedFile = (HCdvd *)(uintptr_t)(u32)requestFields->file;
                            ((PscResourceContext *)p)->baseRaster = pscResDecodeImage((void *)(u32)loadedFile->fileMemory);
                            cardContext->readyFlags |= 1;
                            H_Cdvd_Destroy((void *)requestFields->file);
                            *(u32 *)e &= ~1;
                            break;
                        case 1:
                            if (!(~((PscResourceContext *)p)->readyFlags & 2)) {
                                kAssertFail(D_0064E4E0, 0xD4);
                            }
                            loadedFile = (HCdvd *)(uintptr_t)(u32)requestFields->file;
                            ((PscResourceContext *)p)->miscW00Raster = pscResDecodeImage((void *)(u32)loadedFile->fileMemory);
                            cardContext->readyFlags |= 2;
                            ((PscResourceContext *)p)->flags &= ~4;
                            H_Cdvd_Destroy((void *)requestFields->file);
                            *(u32 *)e &= ~1;
                            break;
                        case 2:
                            if (!(~((PscResourceContext *)p)->readyFlags & 0x10)) {
                                kAssertFail(D_0064E4E0, 0xE0);
                            }
                            loadedFile = (HCdvd *)(uintptr_t)(u32)requestFields->file;
                            ((PscResourceContext *)p)->miscW01Raster = pscResDecodeImage((void *)(u32)loadedFile->fileMemory);
                            cardContext->readyFlags |= 0x10;
                            ((PscResourceContext *)p)->flags &= ~0x10;
                            H_Cdvd_Destroy((void *)requestFields->file);
                            *(u32 *)e &= ~1;
                            break;
                        }
                        break;
                    case 0:
                        if (!(~((PscResourceContext *)p)->arcana[((PscCardRequest *)e)->slotIndex].flags & 2)) {
                            kAssertFail(D_0064E4E0, 0xEB);
                        }
                        loadedFile = (HCdvd *)(uintptr_t)(u32)requestFields->file;
                        ((PscResourceContext *)p)->arcana[requestFields->slotIndex].raster =
                            pscResDecodeImage((void *)(u32)loadedFile->fileMemory);
                        ((PscResourceContext *)p)->arcana[requestFields->slotIndex].flags |= 2;
                        H_Cdvd_Destroy((void *)requestFields->file);
                        *(u32 *)e &= ~1;
                        break;
                    case 1:
                        if (!(~((PscResourceContext *)p)->personas[((PscCardRequest *)e)->slotIndex].flags & 2)) {
                            kAssertFail(D_0064E4E0, 0xF3);
                        }
                        loadedFile = (HCdvd *)(uintptr_t)(u32)requestFields->file;
                        ((PscResourceContext *)p)->personas[requestFields->slotIndex].raster =
                            pscResDecodeImage((void *)(u32)loadedFile->fileMemory);
                        ((PscResourceContext *)p)->personas[requestFields->slotIndex].flags |= 2;
                        H_Cdvd_Destroy((void *)requestFields->file);
                        *(u32 *)e &= ~1;
                        break;
                    }
                    requestFields->state = 2;
                }
                break;
            case 2:
                kAssertFail(D_0064E4E0, 0x100);
                break;
            }
        }
    }
}

// Reports whether any card resource slot is in use.
// FUN_0036BB60
s32 pscResAnySlotInUse(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x20; i++) {
        if (((PscResourceContext *)p)->requests[i].flags & 1) {
            break;
        }
    }
    return i < 0x20;
}

// Destroys every ready shared raster and occupied card-slot raster, then clears the resource
// context singleton.
// FUN_0036BBF0
void pscResDestroy(void) {
    PscResourceContext *cardContext;
    u8 *p;
    s32 i;
    s32 j;
    u32 v;
    u8 *e;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    if (((PscResourceContext *)p)->readyFlags & 0x10) {
        func_003ec330(((PscResourceContext *)p)->miscW01Raster);
    }
    if (cardContext->readyFlags & 1) {
        func_003ec330(((PscResourceContext *)p)->baseRaster);
    }
    if (cardContext->readyFlags & 2) {
        func_003ec330(((PscResourceContext *)p)->miscW00Raster);
    }
    if (cardContext->readyFlags & 4) {
        for (i = 0; i < 7; i++) {
            func_003ec330(((PscResourceContext *)p)->textures[i]);
        }
    }
    if (cardContext->readyFlags & 8) {
        for (i = 0; i < 2; i++) {
            func_003ec330(((PscResourceContext *)p)->subTextures[i]);
        }
    }
    for (j = 0; j < 0x10; j++) {
        v = *(u32 *)(p + j * 0x14 + MEMBER_OFFSET(PscResourceContext, arcana[0].flags));
        if (!(~v & 1)) {
            if (!(v & 2)) {
                kAssertFail(D_0064E4E0, 0x13F);
            }
            e = p + j * 0x14 + 0x54;
            func_003ec330(((PscArcanaCard *)e)->raster);
        }
    }
    for (j = 0; j < 0x10; j++) {
        v = *(u32 *)(p + j * 0x10 + MEMBER_OFFSET(PscResourceContext, personas[0].flags));
        if (!(~v & 1)) {
            if (!(v & 2)) {
                kAssertFail(D_0064E4E0, 0x148);
            }
            e = p + j * 0x10 + 0x194;
            func_003ec330(((PscPersonaCard *)e)->raster);
        }
    }
    D_0072469C = 0;
}


/* Return the base card raster after asserting that its ready flag has been set. */
// FUN_0036BE00
/* Return the base card raster after asserting that its ready flag is set. */
s32 pscResGetBaseRaster(void) {
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(((PscResourceContext *)p)->readyFlags & 1)) {
        kAssertFail(D_0064E4E0, 0x155);
    }
    return ((PscResourceContext *)p)->baseRaster;
}

// Returns the raster of the misc card w_c00.
// FUN_0036BE70
s32 pscResGetMiscCardW00Raster(void) {
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(((PscResourceContext *)p)->readyFlags & 2)) {
        kAssertFail(D_0064E4E0, 0x15F);
    }
    return ((PscResourceContext *)p)->miscW00Raster;
}

// Find the requested Arcana group and card index and return its raster only after checking
// readiness.
// FUN_0036BEE0
/* The slot stride and fields follow the shared card layouts above. */
s32 pscResGetArcanaRaster(s32 group, s32 cardIndex) {
    PscResourceContext *cardContext;
    s32 i;
    s32 entryGroup;
    s32 entryIndex;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    for (i = 0; i < 0x10; i++) {
        entryGroup = ((PscResourceContext *)p)->arcana[i].group;
        if (entryGroup == group) {
            entryIndex = ((PscResourceContext *)p)->arcana[i].index;
            if (entryIndex == cardIndex) {
                break;
            }
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x170);
    }
    if (!(cardContext->arcana[i].flags & 2)) {
        kAssertFail(D_0064E4E0, 0x171);
    }
    return cardContext->arcana[i].raster;
}

// Returns the raster of the loaded persona card with the given 16-bit id, only after checking that
// resources are ready.
// FUN_0036BFF0
/* The slot stride and fields follow the shared card layouts above. */
s32 pscResGetPersonaRaster(s32 personaId) {
    PscResourceContext *cardContext;
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    for (i = 0, key = personaId & 0xFFFF; i < 0x10; i++) {
        v = ((PscResourceContext *)p)->personas[i].id;
        if (v == key) {
            break;
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x182);
    }
    if (!(cardContext->personas[i].flags & 2)) {
        kAssertFail(D_0064E4E0, 0x184);
    }
    return cardContext->personas[i].raster;
}

// Returns the raster of the misc card w_c01.
// FUN_0036C0D0
s32 pscResGetMiscCardW01Raster(void) {
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(((PscResourceContext *)p)->readyFlags & 0x10)) {
        kAssertFail(D_0064E4E0, 0x18E);
    }
    return ((PscResourceContext *)p)->miscW01Raster;
}

// Drops one reference to an Arcana card and frees its raster at zero.
// FUN_0036C140
void pscResReleaseArcanaCard(s32 group, s32 cardIndex) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = pscResFindArcanaCard(group, cardIndex);
    if (((PscArcanaCard *)p)->references == 0) {
        kAssertFail(D_0064E4E0, 0x19B);
    }
    v = ((PscArcanaCard *)p)->references - 1;
    ((PscArcanaCard *)p)->references = v;
    if (v == 0) {
        if (!(((PscArcanaCard *)p)->flags & 2)) {
            kAssertFail(D_0064E4E0, 0x1A4);
        }
        func_003ec330(((PscArcanaCard *)p)->raster);
        ((PscArcanaCard *)p)->flags &= ~2;
        ((PscArcanaCard *)p)->flags &= ~1;
    }
}

// Drops one reference to a persona card and frees its raster at zero.
// FUN_0036C230
void pscResReleasePersonaCard(s32 personaId) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = pscResFindPersonaCard(personaId);
    if (((PscPersonaCard *)p)->references == 0) {
        kAssertFail(D_0064E4E0, 0x1B4);
    }
    v = ((PscPersonaCard *)p)->references - 1;
    ((PscPersonaCard *)p)->references = v;
    if (v == 0) {
        if (!(((PscPersonaCard *)p)->flags & 2)) {
            kAssertFail(D_0064E4E0, 0x1BD);
        }
        func_003ec330(((PscPersonaCard *)p)->raster);
        ((PscPersonaCard *)p)->flags &= ~2;
        ((PscPersonaCard *)p)->flags &= ~1;
    }
}

// Drops one reference to misc card w_c00 and frees its raster at zero.
// FUN_0036C310
void pscResReleaseMiscCardW00(void) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (((PscResourceContext *)p)->miscW00References == 0) {
        kAssertFail(D_0064E4E0, 0x1DF);
    }
    v = ((PscResourceContext *)p)->miscW00References - 1;
    ((PscResourceContext *)p)->miscW00References = v;
    if (v == 0) {
        func_003ec330(((PscResourceContext *)p)->miscW00Raster);
        *(s32 *)&((PscResourceContext *)p)->readyFlags &= ~2;
    }
}

// Drops one reference to misc card w_c01 and frees its raster at zero.
// FUN_0036C3B0
void pscResReleaseMiscCardW01(void) {
    void *p;
    s32 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (((PscResourceContext *)p)->miscW01References == 0) {
        kAssertFail(D_0064E4E0, 0x1F3);
    }
    v = ((PscResourceContext *)p)->miscW01References - 1;
    ((PscResourceContext *)p)->miscW01References = v;
    if (v == 0) {
        func_003ec330(((PscResourceContext *)p)->miscW01Raster);
        *(s32 *)&((PscResourceContext *)p)->readyFlags &= ~0x10;
    }
}

// Takes a reference to misc card w_c00, starting its CD load (card/misc/w_c00.tmx) only when it is
// neither ready nor already loading.
// FUN_0036C450
void pscResAcquireMiscCardW00(void) {
    PscResourceContext *cardContext;
    void *p;
    void *q;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    if (((PscResourceContext *)p)->readyFlags & 2) {
        ((PscResourceContext *)p)->miscW00References += 1;
    } else if (((PscResourceContext *)p)->flags & 4) {
        if (((PscResourceContext *)p)->miscW00References == 0) {
            kAssertFail(D_0064E4E0, 0x212);
        }
        cardContext->miscW00References += 1;
    } else {
        ((PscResourceContext *)p)->miscW00References = 1;
        ((PscResourceContext *)p)->flags |= 4;
        q = pscResFindFreeRequest();
        ((PscCardRequest *)q)->kind = 2;
        ((PscCardRequest *)q)->slotIndex = 1;
        func_00440b68(&D_00723A78, D_0064E4E0, 0x21E);
        ((PscCardRequest *)q)->file = H_Cdvd_AcquireDirectory(D_0064E4F0, 0);
        ((PscCardRequest *)q)->state = 1;
        ((PscCardRequest *)q)->flags |= 1;
    }
}

// Takes a reference to the Arcana card for (group, index), starting its CD load from card/sarcana
// on first use.
// FUN_0036C570
void pscResAcquireArcanaCard(s32 group, s32 cardIndex) {
    char buf1[0x10];
    char buf2[0x100];
    void *p;
    u8 *e;
    void *q;
    s32 i;
    s32 s;
    s8 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (pscResHasArcanaCard(group, cardIndex) != 0) {
        pscResRetainArcanaCard(group, cardIndex);
        return;
    }
    i = pscResFindFreeArcanaSlot();
    e = (u8 *)p + i * 0x14 + 0x54;
    ((PscResourceContext *)p)->arcana[i].group = group;
    ((PscResourceContext *)p)->arcana[i].index = cardIndex;
    ((PscResourceContext *)p)->arcana[i].raster = 0;
    ((PscResourceContext *)p)->arcana[i].references = 1;
    ((PscResourceContext *)p)->arcana[i].flags |= 1;
    q = pscResFindFreeRequest();
    ((PscCardRequest *)q)->kind = 0;
    ((PscCardRequest *)q)->slotIndex = i;
    switch (group) {
    case 0:
        strcpy(buf1, &D_00723A80);
        break;
    case 1:
        strcpy(buf1, &D_00723A88);
        break;
    case 2:
        strcpy(buf1, &D_00723A90);
        break;
    case 3:
        strcpy(buf1, &D_00723A98);
        break;
    }
    s = ((PscArcanaCard *)e)->index;
    if (s < 11) {
        sprintf(buf2, D_0064E510, buf1, s);
    } else {
        switch (s) {
        case 11:
            v = 0x70;
            break;
        case 12:
            v = 0x6E;
            break;
        case 13:
            v = 0x71;
            break;
        case 14:
            v = 0x6B;
            break;
        }
        sprintf(buf2, D_0064E530, buf1, v);
    }
    func_00440b68(&D_00723A78, D_0064E4E0, 0x260);
    ((PscCardRequest *)q)->file = H_Cdvd_AcquireDirectory(buf2, 0);
    ((PscCardRequest *)q)->state = 1;
    ((PscCardRequest *)q)->flags |= 1;
}
// Takes a reference to the persona card with the given id, starting its CD load from card/persona
// on first use.
// FUN_0036C7E0
void pscResAcquirePersonaCard(s32 personaId) {
    char buf[0x100];
    void *p;
    void *q;
    s32 i;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (pscResHasPersonaCard(personaId) != 0) {
        pscResRetainPersonaCard(personaId);
        return;
    }
    i = pscResFindFreePersonaSlot();
    ((PscResourceContext *)p)->personas[i].flags |= 1;
    ((PscResourceContext *)p)->personas[i].id = personaId;
    ((PscResourceContext *)p)->personas[i].raster = 0;
    ((PscResourceContext *)p)->personas[i].references = 1;
    q = pscResFindFreeRequest();
    ((PscCardRequest *)q)->kind = 1;
    ((PscCardRequest *)q)->slotIndex = i;
    sprintf(buf, D_0064E550, personaId & 0xFFFF);
    func_00440b68(&D_00723A78, D_0064E4E0, 0x285);
    ((PscCardRequest *)q)->file = H_Cdvd_AcquireDirectory(buf, 0);
    ((PscCardRequest *)q)->state = 1;
    ((PscCardRequest *)q)->flags |= 1;
}

/* Add a reference to the w_c01 misc card, queuing a CD load for its image file the first time it is
 * needed if it is not already ready or loading. */
// FUN_0036C900
void pscResAcquireMiscCardW01(void) {
    PscResourceContext *cardContext;
    void *p;
    void *q;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    if (((PscResourceContext *)p)->readyFlags & 0x10) {
        ((PscResourceContext *)p)->miscW01References += 1;
    } else if (((PscResourceContext *)p)->flags & 0x10) {
        if (((PscResourceContext *)p)->miscW01References == 0) {
            kAssertFail(D_0064E4E0, 0x29B);
        }
        cardContext->miscW01References += 1;
    } else {
        ((PscResourceContext *)p)->miscW01References = 1;
        ((PscResourceContext *)p)->flags |= 0x10;
        q = pscResFindFreeRequest();
        ((PscCardRequest *)q)->kind = 2;
        ((PscCardRequest *)q)->slotIndex = 2;
        func_00440b68(&D_00723A78, D_0064E4E0, 0x2A7);
        ((PscCardRequest *)q)->file = H_Cdvd_AcquireDirectory(D_0064E570, 0);
        ((PscCardRequest *)q)->state = 1;
        ((PscCardRequest *)q)->flags |= 1;
    }
}

// Reports whether an Arcana card for (group, index) is in a slot.
// FUN_0036CA20
s32 pscResHasArcanaCard(s32 group, s32 cardIndex) {
    s32 i;
    s32 entryIndex;
    s32 entryGroup;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (!(~((PscResourceContext *)p)->arcana[i].flags & 1)) {
            entryIndex = ((PscResourceContext *)p)->arcana[i].index;
            if (entryIndex == cardIndex) {
                entryGroup = ((PscResourceContext *)p)->arcana[i].group;
                if (entryGroup == group) {
                    break;
                }
            }
        }
    }
    return i < 0x10;
}

// Returns the slot entry of the Arcana card for (group, index), asserting it exists.
// FUN_0036CAD0
void *pscResFindArcanaCard(s32 group, s32 cardIndex) {
    s32 i;
    s32 entryIndex;
    s32 entryGroup;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (!(~((PscResourceContext *)p)->arcana[i].flags & 1)) {
            entryIndex = ((PscResourceContext *)p)->arcana[i].index;
            if (entryIndex == cardIndex) {
                entryGroup = ((PscResourceContext *)p)->arcana[i].group;
                if (entryGroup == group) {
                    break;
                }
            }
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x2D3);
    }
    return (u8 *)p + i * 0x14 + 0x54;
}

// Adds a reference to an Arcana card already in a slot.
// FUN_0036CBC0
void pscResRetainArcanaCard(s32 group, s32 cardIndex) {
    s32 i;
    s32 entryIndex;
    s32 entryGroup;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (!(~((PscResourceContext *)p)->arcana[i].flags & 1)) {
            entryIndex = ((PscResourceContext *)p)->arcana[i].index;
            if (entryIndex == cardIndex) {
                entryGroup = ((PscResourceContext *)p)->arcana[i].group;
                if (entryGroup == group) {
                    break;
                }
            }
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x2D3);
    }
    *(u32 *)&((PscResourceContext *)p)->arcana[i].references += 1;
}

// Returns the first free Arcana slot index, asserting one exists.
// FUN_0036CCC0
s32 pscResFindFreeArcanaSlot(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (~((PscResourceContext *)p)->arcana[i].flags & 1) {
            break;
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x2F0);
    }
    return i;
}

// Reports whether a persona card with the given id is in a slot.
// FUN_0036CD70
s32 pscResHasPersonaCard(s32 personaId) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = personaId & 0xFFFF; i < 0x10; i++) {
        if (!(~((PscResourceContext *)p)->personas[i].flags & 1)) {
            v = ((PscResourceContext *)p)->personas[i].id;
            if (v == key) {
                break;
            }
        }
    }
    return i < 0x10;
}

// Returns the slot entry of the persona card with the given id, asserting it exists.
// FUN_0036CE10
u32 *pscResFindPersonaCard(s32 personaId) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = personaId & 0xFFFF; i < 0x10; i++) {
        if (!(~((PscResourceContext *)p)->personas[i].flags & 1)) {
            v = ((PscResourceContext *)p)->personas[i].id;
            if (v == key) {
                break;
            }
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x319);
    }
    return (u32 *)((u8 *)p + i * 0x10 + 0x194);
}

// Returns the first free persona slot index, asserting one exists.
// FUN_0036CEE0
s32 pscResFindFreePersonaSlot(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x10; i++) {
        if (~((PscResourceContext *)p)->personas[i].flags & 1) {
            break;
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x32B);
    }
    return i;
}

// Adds a reference to a persona card already in a slot.
// FUN_0036CF80
void pscResRetainPersonaCard(s32 personaId) {
    s32 i;
    u32 key;
    void *p;
    u16 v;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0, key = personaId & 0xFFFF; i < 0x10; i++) {
        if (!(~((PscResourceContext *)p)->personas[i].flags & 1)) {
            v = ((PscResourceContext *)p)->personas[i].id;
            if (v == key) {
                break;
            }
        }
    }
    if (i >= 0x10) {
        kAssertFail(D_0064E4E0, 0x319);
    }
    *(u32 *)&((PscResourceContext *)p)->personas[i].references += 1;
}

// Returns the first free load-request block, asserting one exists.
// FUN_0036D060
u32 *pscResFindFreeRequest(void) {
    s32 i;
    void *p;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    for (i = 0; i < 0x20; i++) {
        if (~((PscResourceContext *)p)->requests[i].flags & 1) {
            break;
        }
    }
    if (i >= 0x20) {
        kAssertFail(D_0064E4E0, 0x352);
    }
    return (u32 *)((u8 *)p + i * 0x124 + 0x294);
}

// Returns decoded texture i of the w_c00 image set (seven entries).
// FUN_0036D130
s32 pscResGetMiscCardW00Texture(s32 textureIndex) {
    void *p;
    u32 *q;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(((PscResourceContext *)p)->readyFlags & 4)) {
        kAssertFail(D_0064E4E0, 0x371);
    }
    q = p;
    return q[textureIndex + 9];
}
// Returns decoded texture i of the w_c00 secondary set (two entries).
// FUN_0036D1B0
s32 pscResGetMiscCardW00SubTexture(s32 textureIndex) {
    void *p;
    u32 *q;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    if (!(((PscResourceContext *)p)->readyFlags & 8)) {
        kAssertFail(D_0064E4E0, 0x37C);
    }
    q = p;
    return q[textureIndex + 0x10];
}

// Decode the ten-entry miscellaneous container into seven textures, the base raster, and two
// secondary textures.
// FUN_0036D230
void pscResBuildMiscCardW00(u8 *container) {
    PscImageContainer *imageContainer = (PscImageContainer *)container;
    PscResourceContext *cardContext;
    s32 i;
    u8 *p;
    s32 j;
    u8 *base2;

    if (D_0072469C == 0) {
        kAssertFail(D_0064E4E0, 0x75);
    }
    p = D_0072469C;
    cardContext = (PscResourceContext *)p;
    if (!(~((PscResourceContext *)p)->readyFlags & 4)) {
        kAssertFail(D_0064E4E0, 0x3A4);
    }
    if (!(~cardContext->readyFlags & 8)) {
        kAssertFail(D_0064E4E0, 0x3A5);
    }
    if (!(~cardContext->readyFlags & 1)) {
        kAssertFail(D_0064E4E0, 0x3A6);
    }
    if (((PscImageContainer *)container)->count != 10) {
        kAssertFail(D_0064E4E0, 0x3A7);
    }
    for (i = 0; i < 7; i++) {
        ((PscResourceContext *)p)->textures[i] =
            pscResDecodeImage((u8 *)container + imageContainer->entries[i].offset);
    }
    base2 = (u8 *)container + 8;
    ((PscResourceContext *)p)->baseRaster =
        pscResDecodeImage((u8 *)container + ((PscImageContainer *)container)->entries[7].offset);
    for (j = 0; j < 2; j++) {
        ((PscResourceContext *)p)->subTextures[j] =
            pscResDecodeImage((u8 *)container + ((PscImageEntry *)base2)[j + 8].offset);
    }
    ((PscResourceContext *)p)->readyFlags |= 1;
    ((PscResourceContext *)p)->readyFlags |= 4;
    ((PscResourceContext *)p)->readyFlags |= 8;
}

typedef struct PscImageHeader {
    u8 reserved00[0x10];
    u8 paletteCount;
    u8 reserved11;
    u16 width;
    u16 height;
    u8 pixelFormat;
    u8 reserved17[0x29];
} PscImageHeader;

typedef struct PscPalette {
    const u32 *colors;
    s32 flags;
} PscPalette;

/* Decodes one PSC image (header, palette, pixels) into a new RwRaster. The input cursor is kept
 * separate from the retained header and palette base. */
// FUN_0036D3E0
s32 pscResDecodeImage(const void *input) {
    const u8 *source;
    PscPalette paletteView;
    s32 depth;
    RwRaster *raster;
    const PscImageHeader *header;
    u8 *paletteOut;
    u8 *pixelsOut;
    s32 rasterFlags;
    s32 paletteIndex8;
    s32 paletteIndex4;
    s32 column32;
    s32 row32;
    s32 row24;
    s32 column24;
    s32 row8;
    s32 column8;
    s32 row4;
    s32 column4;

    paletteView.flags = 0;
    source = (const u8 *)input;
    header = (const PscImageHeader *)source;
    {
        s32 decodedDepth;
        decodedDepth = 0;
        switch (((const PscImageHeader *)input)->pixelFormat) {
        case 0:
            decodedDepth = 0x20;
            break;
        case 1:
            decodedDepth = 0x18;
            break;
        case 2:
        case 10:
            decodedDepth = 0x10;
            break;
        case 19:
        case 27:
            decodedDepth = 8;
            break;
        case 20:
        case 36:
        case 44:
            decodedDepth = 4;
            break;
        }
        depth = decodedDepth;
    }
    if (depth == 0) {
        kAssertFail(D_0064E4E0, 0x409);
    }
    source += 0x40;
    switch (depth) {
    case 8:
        paletteView.colors = (const u32 *)source;
        source += (u32)header->paletteCount << 10;
        paletteView.flags |= 1;
        break;
    case 4:
        paletteView.colors = (const u32 *)source;
        source += (u32)header->paletteCount << 6;
        paletteView.flags |= 1;
        break;
    }
    rasterFlags = 0;
    rasterFlags |= 4;
    switch (depth) {
    case 0x20:
        rasterFlags |= 0x500;
        break;
    case 0x18:
        rasterFlags |= 0x600;
        break;
    case 8:
        rasterFlags |= 0x2500;
        break;
    case 4:
        rasterFlags |= 0x4500;
        break;
    default:
        kAssertFail(D_0064E4E0, 0x431);
        break;
    }
    raster = func_003ec590(header->width, header->height, depth, rasterFlags);
    if (paletteView.flags & 1) {
        const u32 *colors = paletteView.colors;
        paletteOut = func_003ec3d0(raster, 1);
        switch (depth) {
        case 8:
            for (paletteIndex8 = 0; paletteIndex8 < 0x100; paletteIndex8++) {
                *(u32 *)paletteOut = *colors;
                colors++;
                paletteOut += 4;
            }
            break;
        case 4:
            for (paletteIndex4 = 0; paletteIndex4 < 0x10; paletteIndex4++) {
                *(u32 *)paletteOut = *colors;
                colors++;
                paletteOut += 4;
            }
            break;
        }
        func_003ec2e0(raster);
    }
    pixelsOut = func_003ec6a0(raster, 0, 1);
    switch (depth) {
    case 0x20:
        for (row32 = 0; row32 < (s32)header->height; row32++) {
            for (column32 = 0; column32 < (s32)header->width; column32++) {
                *(s32 *)pixelsOut = *(const s32 *)source;
                source += 4;
                pixelsOut += 4;
            }
        }
        break;
    case 0x18:
        for (row24 = 0; row24 < (s32)header->height; row24++) {
            for (column24 = 0; column24 < (s32)header->width * 3; column24++) {
                *pixelsOut = *source;
                source += 1;
                pixelsOut += 1;
            }
        }
        break;
    case 8:
        for (row8 = 0; row8 < (s32)header->height; row8++) {
            for (column8 = 0; column8 < (s32)header->width; column8++) {
                *pixelsOut = *source;
                source += 1;
                pixelsOut += 1;
            }
        }
        break;
    case 4:
        for (row4 = 0; row4 < (s32)header->height; row4++) {
            for (column4 = 0; column4 < (s32)header->width >> 3; column4++) {
                *(s32 *)pixelsOut = *(const s32 *)source;
                source += 4;
                pixelsOut += 4;
            }
        }
        break;
    }
    func_003ec2a0(raster);
    return (s32)raster;
}
