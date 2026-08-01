/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0044F6B0)
/* Source unit: src/h_dbprt_0044f6b0.c */
#include "type.h"

#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

typedef struct HDbText3D HDbText3D;
struct HDbText3D
{
    HDbText3D* next; // 0x00
};

static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
static HDbText3D* sText3DList;

extern void* memset(void* destination, s32 value, size_t count);
/* rwGlobals.memFuncs.RwFree slot: indirect call through data. */
extern void (*RwFree_abs[])(void* memory);

// FUN_0044F6B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = sText3DList;
    sText3DList = NULL;
    while (1)
    {
        if (curr == NULL)
        {
            break;
        }

        next = curr->next;
        RwFree_abs[0](curr);
        curr = next;
    }
}
#endif /* P4_UNIT_0044F6B0 */

#if defined(P4_UNIT_004504F0)
/* Source unit: src/h_dbprt_004504f0.c */
#include "type.h"

#define HDBPRT_LOG_MAXLINE 15
#define HDBPRT_LOG_MAXCHAR 256

typedef char* va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)
extern int vsprintf(char* buffer, const char* fmt, va_list args);

static s8 sLogLine;
static char sLogs[HDBPRT_LOG_MAXLINE][HDBPRT_LOG_MAXCHAR];

extern void* memcpy(void* destination, const void* source, size_t count);

// FUN_004504F0
void H_Dbprt_FmtLog(const char* fmt, ...)
{
    char buffer[HDBPRT_LOG_MAXCHAR];
    s32 i;
    s32 line;
    va_list args;

    for (line = 0; line < HDBPRT_LOG_MAXCHAR; line++)
    {
        buffer[line] = 0;
    }

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    if (sLogLine == HDBPRT_LOG_MAXLINE)
    {
        for (i = 1; i < HDBPRT_LOG_MAXLINE; i++)
        {
            memcpy(sLogs[i - 1], sLogs[i], HDBPRT_LOG_MAXCHAR);
        }
        sLogLine--;
    }

    memcpy(sLogs[sLogLine], buffer, HDBPRT_LOG_MAXCHAR);
    sLogLine++;
}
#endif /* P4_UNIT_004504F0 */
