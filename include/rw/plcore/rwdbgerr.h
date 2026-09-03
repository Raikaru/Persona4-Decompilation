



















/* RWPUBLIC */
#define RWECODE(a,b) a,

/* Construct an enum type with all the plugin error codes (for the app to use) */
enum RwErrorCodePlugin_errcore 
{
#include "errcore.def"
    rwLASTERROR_errcore = RWFORCEENUMSIZEINT
};
typedef enum RwErrorCodePlugin_errcore RwErrorCodePlugin_errcore;


#undef RWECODE

/* RWPUBLICEND */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */
RwChar *_rwdb_errcore(RwInt32 code, ...);
#ifdef    __cplusplus
}
#endif                          /* __cplusplus */
