/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00176C20)
/* Source unit: src/Kosaka/k_command/k_command_00176c20.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

// FUN_00176C20
u32 func_00176c20()
{
    s32 resourceId;

    resourceId = func_0029cc00(0);
    func_0014a0f0((u16)resourceId, func_0029cc00(1));
    return true;
}
#endif /* P4_UNIT_00176C20 */

#if defined(P4_UNIT_00177A10)
/* Source unit: src/Kosaka/k_command/k_command_00177a10.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

extern char* func_00442830(char* destination, const char* source);
extern s32 func_00442088(char* destination, const char* format, ...);
extern char* func_00442428(char* destination, const char* source);

// FUN_00177A10
u32 func_00177a10()
{
    char path[64];
    char buff[64];
    s32 majorId;
    u32 minorId;
    Model* mdl;

    majorId = func_0029cc00(0);
    minorId = func_0029cc00(1);

    if (majorId > -1)
    {
        func_00442830(path, "field/rmd/m");

        func_00442088(buff, "%03d_", majorId);
        func_00442428(path, buff);

        func_00442088(buff, "%03d.RMD", minorId);
        func_00442428(path, buff);
    }
    else
    {
        func_00442830(path, "field/grmd/fobj");
        func_00442088(buff, "%03d.RMD", minorId);
        func_00442428(path, buff);
    }

    mdl = func_00477e80(4, minorId, path, 0);
    func_0029cf50((s32)mdl);

    return true;
}
#endif /* P4_UNIT_00177A10 */

#if defined(P4_UNIT_00177D10)
/* Source unit: src/Kosaka/k_command/k_command_00177d10.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

// FUN_00177D10
u32 func_00177d10()
{
    Model* model;
    u32 resourceId;
    u32 created;

    model = (Model*)func_0029cc00(0);
    resourceId = 0;
    created = 0;
    if (func_004782b0(model) == true)
    {
        resourceId = (u16)func_00145ac0(func_0014b510(10), model);
        created = 1;
    }
    func_0029cf50(resourceId);

    return created;
}
#endif /* P4_UNIT_00177D10 */

#if defined(P4_UNIT_00177E20)
/* Source unit: src/Kosaka/k_command/k_command_00177e20.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

// FUN_00177E20
u32 func_00177e20()
{
    s32 type;
    s32 id;
    Model* mdl;

    type = func_0029cc00(0);
    id = func_0029cc00(1);

    mdl = func_00478140(type, id, 0);

    func_0029cf50((s32)mdl);

    return true;
}
#endif /* P4_UNIT_00177E20 */

#if defined(P4_UNIT_00178970)
/* Source unit: src/Kosaka/k_command/k_command_00178970.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

// FUN_00178970
u32 func_00178970()
{
    s32 resourceId;
    s32 value;

    resourceId = func_0029cc00(0);
    value = func_0029cc00(1);

    return func_002bd360(resourceId, value) == 0;
}
#endif /* P4_UNIT_00178970 */

#if defined(P4_UNIT_0025D100)
/* Source unit: src/Kosaka/k_command/k_command_0025d100.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

// FUN_0025D100
u32 func_0025d100()
{
    func_0029cf50(func_00106600(func_0029cc00(0)));

    return true;
}
#endif /* P4_UNIT_0025D100 */

#if defined(P4_UNIT_00299400)
/* Source unit: src/Kosaka/k_command/k_command_00299400.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

// FUN_00299400
u32 func_00299400()
{
    func_00106550(func_0029cc00(0), func_0029cc00(1));

    return true;
}
#endif /* P4_UNIT_00299400 */
