/* Source unit: src/Kernel/h_memcard_00464650.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

extern s32 D_00764BBC; /* sMemcardMode */
extern s32 D_00764BA0; /* sMemcardAsync */
extern s32 D_00764BB8; /* sMemcardFile */
extern void* D_00764BAC; /* sMemcardBuffer */
extern s32 D_00764BB4; /* sMemcardBufferSize */
extern s32 D_00764BC0; /* sMemcardSeqMode */
extern s32 *D_00764BA8; /* caller's slot availability and serialized summary table */
extern s32 iGpffffbab0;

extern s32 memcardPollCommand(s32* command, s32* result, s32* succeeded);
extern s32 sceMc2GetInfoAsync(s32 socket, s32* status);
extern s32 D_00764B9C;
extern s32 D_00764BA4;
extern s32 D_008E4B20[];
extern s32 D_008E4B24[];
extern s32 D_00764BB0; /* caller's result address, stored as a 32-bit word */
extern s32 iGpffffbaa8;
extern s32 iGpffffbaa4;
extern char D_00712950[];
extern char D_007127D0[];
extern char D_008E4900[];
extern char D_008E4A20[];
extern s32 D_008E4B28[];
extern void sprintf(void* dst, const void* fmt, s32, s32);
extern void func_00431d78(s32 socket, void* data, void* result);
extern void func_00440b68();
extern void func_00431f28();
extern char D_007127B0[];
extern char D_007128B0[];
extern char D_007128E0[];
extern s32 D_008E4910[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memcpy(void *dst, void *src, s32 size);
extern void memset(void *dst, s32 value, s32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_007128F8[];
extern char D_00712908[];
extern char D_00712920[];
extern char D_00712938[];
 



// FUN_00464650
/* Begin a buffered load by resetting the card sequence and recording its inputs. */
void H_Memcard_BeginLoad(s32 file, void* buffer, s32 size)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = file;
    D_00764BAC = buffer;
    D_00764BB4 = size;
    D_00764BA0 = 0;
}



/* Sets the memory-card sequence mode to 9. */
// FUN_004647A0
void H_Memcard_SetSeqMode9(void)
{
    D_00764BC0 = 9;
}

/* Sets the memory-card sequence mode to 4. */
// FUN_004647B0
void H_Memcard_SetSeqMode4(void)
{
    D_00764BC0 = 4;
}

// FUN_00465400
/* Poll card presence/type and translate backend errors to the caller's status codes. */
s32 H_Memcard_CheckCard(void)
{
    s32 status;
    s32 cardMode;
    s32 cardCode;
    s32 cardError;

    if (D_00764B9C != 0)
    {
        status = memcardPollCommand(&cardMode, &cardCode, &cardError);
        if (status == -1)
        {
            D_00764B9C = 0;
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
        }
    }
    else
    {
        status = memcardPollCommand(&cardMode, &cardCode, &cardError);
        if (status == 1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            if (cardError == 0)
            {
                switch (cardCode)
                {
                    case 0x9003:
                        goto card_error_9003;
                    case 0x6f:
                        goto card_error_6f;
                    case 0x13:
                        goto card_error_13;
                    case 0x9001:
                        goto card_error_9001;
                    case 0x2f:
                        goto card_error_2f;
                    default:
                        goto card_state;
                }
            }
            goto card_state;
        }
    }
    goto card_done;

card_error_9003:
    return 3;
card_error_6f:
    return -5;
card_error_13:
    return -5;
card_error_9001:
    return -4;
card_error_2f:
    return -2;

card_state:
    if (D_008E4B20[0] != 2)
    {
        return -1;
    }
    if (D_008E4B24[0] == 0)
    {
        return -2;
    }
    goto card_done;

card_done:
    return 0;
}



/* Raises the memory-card abort flag (D_00764B9C). */
// FUN_004653F0
void H_Memcard_SetAbort(void)
{
    D_00764B9C = 1;
}

// FUN_00465570
/* Begin a buffered save by recording the file, buffer and result-address word. */
void H_Memcard_BeginSave(s32 file, void* buffer, s32 resultAddress)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = file;
    D_00764BAC = buffer;
    D_00764BB0 = resultAddress;
    D_00764BA0 = 0;
}



// FUN_00465590
/* Advance the asynchronous save sequence; return 100 on completion or a negative error.
 * D_00764BB0 holds the caller's result address as a 32-bit word, not an object offset. */
s32 H_Memcard_SaveStep(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    s32 state;

    func_00440b68(D_007127B0, D_00764BC0);
    state = D_00764BC0;
    switch (state)
    {
    case 0:
        cardMode = 0;
        cardCode = 0;
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == -1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            D_00764BC0 = 1;
        }
        goto done;
    case 1:
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6f:
                    return -5;
                case 0x13:
                    return -5;
                case 0x9001:
                    return -4;
                case 0x2f:
                    return -2;
                default:
                    break;
                }
            }
            if (D_008E4B20[0] != 2)
            {
                return -1;
            }
            if (D_008E4B24[0] == 0)
            {
                return -2;
            }
            if (D_00764BA0 != 0)
            {
                sprintf(D_008E4A20, D_007128B0,
                              D_00764BB8, D_00764BB8);
            }
            else
            {
                sprintf(D_008E4A20, D_007127D0,
                              D_00764BB8, D_00764BB8);
            }
            func_00431d78(D_00764BA4, D_008E4A20, D_008E4900);
            D_00764BC0 = 2;
        }
        goto done;
    case 2:
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x6f:
                    return -5;
                case 0x16:
                    return -5;
                case 2:
                    return -8;
                case 0x13:
                    return -5;
                case 0x9002:
                    return -4;
                default:
                    break;
                }
            }
            if (D_00764BA0 != 0)
            {
                sprintf(D_008E4A20, D_007128B0,
                              D_00764BB8, D_00764BB8);
            }
            else
            {
                sprintf(D_008E4A20, D_007127D0,
                              D_00764BB8, D_00764BB8);
            }
            func_00431f28(D_00764BA4, D_008E4A20, D_00764BAC, 0,
                          D_008E4910[0]);
            D_00764BC0 = 3;
        }
        goto done;
    case 3:
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                *(s32 *)(uintptr_t)D_00764BB0 = cardCode;
                goto state3_message;
            }
            switch (cardCode)
            {
            case 0x6f:
                return -3;
            case 0x16:
                return -3;
            case 0xd:
                return -3;
            case 2:
                return -3;
            case 0x13:
                return -3;
            case 0x9002:
                return -4;
            default:
                break;
            }
state3_message:
            func_00440b68(D_007128E0, cardCode);
            return 100;
        }
        goto done;
    default:
        goto done;
    }
done:
    return 0;
}
// FUN_004659F0
/* Select the caller's availability/summary table and restart slot enumeration. */
void H_Memcard_SetRecordTable(s32 recordTableAddress)
{
    D_00764BC0 = 0;
    D_00764BA8 = (s32 *)(uintptr_t)recordTableAddress;
    D_00764BBC = 0;
    D_00764BB8 = 0;
    iGpffffbab0 = 0;
}
// FUN_00465A10
/* Read sixteen 0x34-byte slot summaries, check their byte-sum checksum and mark availability.
 * The data cursor scans serialized bytes; the trailing u16 checksum lives at 0x32. */
s32 H_Memcard_LoadStep(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    s32 index;
    u32 checksum;
    u32 i;
    u8 *recordData;

    switch (D_00764BC0)
    {
    case 0:
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == -1)
        {
            func_00440b68(D_007128F8,
                          sceMc2GetInfoAsync(D_00764BA4, D_008E4B20));
            D_00764BC0 = 1;
        }
        goto done;
    case 1:
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x9003:
                    break;
                case 0x6f:
                    return -5;
                case 0x13:
                    return -5;
                case 0x9001:
                    return -4;
                case 0x2f:
                    return -2;
                default:
                    break;
                }
            }
            if (D_008E4B20[0] != 2)
            {
                return -1;
            }
            if (D_008E4B24[0] == 0)
            {
                return -2;
            }
            D_00764BC0 = 2;
        }
        goto done;
    case 2:
        chkmemAllocSiteTag(D_00712908, 0x32d);
        D_00764BAC = (*jtbl_008873E8)(0x38, 0x40000);
        if (D_00764BA0 != 0)
        {
            sprintf(D_008E4A20, D_007128B0,
                          D_00764BB8, D_00764BB8);
        }
        else
        {
            sprintf(D_008E4A20, D_007127D0,
                          D_00764BB8, D_00764BB8);
        }
        func_00431f28(D_00764BA4, D_008E4A20, D_00764BAC, 0, 0x38);
        func_00440b68(D_00712920, D_008E4A20, 0x38);
        D_00764BC0 = 3;
        goto done;
    case 3:
        if (memcardPollCommand(&cardMode, &cardCode, &cardError) == 1)
        {
            func_00440b68(D_00712938, cardCode);
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x6f:
                    (*jtbl_008873EC)(D_00764BAC);
                    return -3;
                case 0x16:
                    (*jtbl_008873EC)(D_00764BAC);
                    return -3;
                case 0xd:
                    (*jtbl_008873EC)(D_00764BAC);
                    return -3;
                case 2:
                    (*jtbl_008873EC)(D_00764BAC);
                    D_00764BA8[D_00764BB8] = 0;
                    goto state3_done;
                case 0x13:
                    (*jtbl_008873EC)(D_00764BAC);
                    return -3;
                case 0x9002:
                    (*jtbl_008873EC)(D_00764BAC);
                    D_00764BA8[D_00764BB8] = 0;
                    goto state3_done;
                default:
                    goto state3_done;
                }
            }
            memcpy(
                (u8 *)D_00764BA8 + D_00764BB8 * 0x34 + 0x40,
                (u8 *)D_00764BAC + 4, 0x34);
            (*jtbl_008873EC)(D_00764BAC);
            if (cardCode >= 0)
            {
                recordData = (u8 *)D_00764BA8 +
                             D_00764BB8 * 0x34 + 0x40;
                checksum = 0;
                for (i = 0; i < 0x32; i++)
                {
                    checksum = (u16)((checksum + recordData[i]) & 0xff);
                }
                if (*(u16 *)(recordData + 0x32) != (checksum & 0xff))
                {
                    memset(recordData, 0, 0x34);
                }
                D_00764BA8[D_00764BB8] = 1;
            }
            else
            {
                D_00764BA8[D_00764BB8] = 0;
            }
state3_done:
            index = D_00764BB8 + 1;
            D_00764BB8 = index;
            if (index == 0x10)
            {
                return 100;
            }
            D_00764BC0 = 2;
        }
        goto done;
    default:
        goto done;
    }
done:
    return 0;
}
// FUN_00465F20
void H_Memcard_Reset(void)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = 0;
}
/* measured: plain C reproduces the complete 800-byte state machine except for the final-state result setup order (retail loads iGpffffbaa8 before materializing 100; b210 reverses those two instructions). Object 796B/window 800B, normalized_diff 6. Committed at nd 6. */
// FUN_00465F40
/* Probe each save slot when space is low; retain the already matched dispatch shape.
 * The redundant temporaries/constant branch forms predate this pass and are
 * deliberately unchanged rather than introducing new matching levers. */
s32 H_Memcard_CreateSlotsStep(void)
{
  s32 command;
  s32 cardCode;
  int completionStatus;
  s32 cardError;
  s32 sequenceMode;
  s32 fileIndex;
  int nextSlot;
  int result;
  s32 slotOrResult;
  int dispatchMode;
  int cardFailure;
  if (D_008E4A20 || nextSlot)
  {
    func_00440b68(D_00712950, D_00764BC0);
    sequenceMode = D_00764BC0;
  }
  else
  {
    fileIndex = D_00764BC0;
    func_00440b68(D_00712950, fileIndex);
    sequenceMode = D_00764BC0;
  }
  switch (dispatchMode = sequenceMode)
  {
    case 0:
      iGpffffbaa8 = -1;
      cardCode = result = command = 0;
      if (1 != 0)
    {
      iGpffffbaa4 = 0;
      if (memcardPollCommand(&command, &cardCode, &cardError) == -1)
      {
        sceMc2GetInfoAsync(D_00764BA4, (s32 *) D_008E4B20);
        D_00764BC0 = 1;
      }
    }

    default:
      goto block_44;

    case 1:
      if (memcardPollCommand(&command, &cardCode, &cardError) == 1)
    {
 do { if (((((-1) * 0, cardError)) & 0xFFFFFFFF) == (result = 0)) { switch (cardCode) { case 0x6F: return -5; case 0x13: return -5; case 0x9003: sceMc2GetInfoAsync(D_00764BA4, (s32 *) D_008E4B20); goto block_44; case 0x2F: return 100; default: return -9; } } else { if (D_008E4B20[0] == 2) { if (D_008E4B28[0] >= 0xE6) { return 100; } D_00764BC0 = 2; goto block_44; } return -1; } }
 while (0);
    }
    else
    {
      goto block_44;
    }
      break;

    case 2:
      if (-1 == memcardPollCommand(&command, &cardCode, &cardError))
    {
      slotOrResult = (fileIndex = D_00764BB8);
      sprintf(D_008E4A20, D_007127D0, slotOrResult, fileIndex);
      func_00431d78(D_00764BA4, D_008E4A20, D_008E4900);
      D_00764BC0 = 3;
    }
      goto block_44;

    case 3:
      cardFailure = -5;
      if (memcardPollCommand(&command, &cardCode, &cardError) == 1)
    {
      if (completionStatus = cardError == 0)
      {
        switch (cardCode)
        {
          case 0x9003:
            return cardFailure;

          case 0x6F:
            return cardFailure;

          case 0x16:
            return cardFailure;

          case 0x13:
            return cardFailure;

          case 2:
            nextSlot = (D_00764BB8 += 1);
            if (nextSlot == 0x10)
          {
            completionStatus = (slotOrResult = iGpffffbaa8);
            result = 100;
            if (slotOrResult != 100)
            {
              result = -6;
            }
            return result;
          }
            D_00764BC0 = 2;
            goto block_44;

          default:
            goto block_44;

        }

      }
      return 100;
    }
    else
    {
      goto block_44;
    }
      break;

  }

  block_44:
  return 0;

}



// FUN_00466260
void H_Memcard_SetSlot(s32 slot)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = slot;
}
