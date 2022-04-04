#ifndef RTW_HEADER_original_private_h_
#define RTW_HEADER_original_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "original.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
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
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) ;
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
; real_T rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T *
uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx ,
real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) ; void rt_TDelayFreeBuf ( void * buf ) ;
extern void jmit3vr51d ( lp5ztxd20y * localB , ehm3sgzrjf * localP ) ; extern
void mnr2afncj2 ( SimStruct * rtS_e , real_T pdfdnwdcb4 , real_T cagtww4tts ,
lp5ztxd20y * localB , mem4sagm4y * localDW , fgwwoolgrw * localZCE ) ; extern
void hpvik1zrta ( hh5f121zsr * localB , bgrpsvzorg * localP ) ; extern void
mjqilvpgl5 ( SimStruct * rtS_m , real_T c0gmvzy4fh , real_T l22fp4ju4c ,
real_T kmw1tns1nf , hh5f121zsr * localB , pzawjmwk3y * localDW ) ; extern
void h3xdm3koso ( dufzjkshrc * localB , o0jdhwlf44 * localP ) ; extern void
ligjpsfhvt ( SimStruct * rtS_e , real_T czgu4rdmf0 , real_T o01sow1ps0 ,
real_T hah1ogqu2h , dufzjkshrc * localB , d51rut2e0g * localDW ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
