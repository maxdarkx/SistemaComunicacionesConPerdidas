#include "modPSK_mod3_capi_host.h"
static modPSK_mod3_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        modPSK_mod3_host_InitializeDataMapInfo(&(root), "modPSK_mod3");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
