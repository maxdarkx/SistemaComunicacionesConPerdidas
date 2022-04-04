#ifndef RTW_HEADER_modPSK_acc_private_h_
#define RTW_HEADER_modPSK_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "modPSK_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)     (((v1)==(v2))?((double)(v1)):    (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?     muDoubleScalarFloor((v) + 0.5) :     muDoubleScalarCeil((v) - 0.5) )
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T
* tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T *
* uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) ; real_T modPSK_acc_rt_TDelayInterpolate ( real_T
tMinusDelay , real_T tStart , real_T * uBuf , int_T bufSz , int_T * lastIdx ,
int_T oldestIdx , int_T newIdx , real_T initOutput , boolean_T discrete ,
boolean_T minorStepAndTAtLastMajorOutput ) ; void modPSK_SampleandHold_Init (
SimStruct * S , B_SampleandHold_modPSK_T * localB , P_SampleandHold_modPSK_T
* localP ) ; void modPSK_SampleandHold ( SimStruct * S , real_T rtu_Trigger ,
real_T rtu_In , B_SampleandHold_modPSK_T * localB , DW_SampleandHold_modPSK_T
* localDW , ZCE_SampleandHold_modPSK_T * localZCE ) ; void
modPSK_NEGATIVEEdge_Init ( SimStruct * S , B_NEGATIVEEdge_modPSK_T * localB ,
P_NEGATIVEEdge_modPSK_T * localP ) ; void modPSK_NEGATIVEEdge_Disable (
SimStruct * S , DW_NEGATIVEEdge_modPSK_T * localDW ) ; void
modPSK_NEGATIVEEdge ( SimStruct * S , real_T rtu_Enable , real_T rtu_IN ,
real_T rtu_INprevious , B_NEGATIVEEdge_modPSK_T * localB ,
DW_NEGATIVEEdge_modPSK_T * localDW ) ; void modPSK_POSITIVEEdge_Init (
SimStruct * S , B_POSITIVEEdge_modPSK_T * localB , P_POSITIVEEdge_modPSK_T *
localP ) ; void modPSK_POSITIVEEdge_Disable ( SimStruct * S ,
DW_POSITIVEEdge_modPSK_T * localDW ) ; void modPSK_POSITIVEEdge ( SimStruct *
S , real_T rtu_Enable , real_T rtu_IN , real_T rtu_INprevious ,
B_POSITIVEEdge_modPSK_T * localB , DW_POSITIVEEdge_modPSK_T * localDW ) ;
void modPSK_SampleandHold_Term ( SimStruct * const S ) ; void
modPSK_NEGATIVEEdge_Term ( SimStruct * const S ) ; void
modPSK_POSITIVEEdge_Term ( SimStruct * const S ) ;
#endif
