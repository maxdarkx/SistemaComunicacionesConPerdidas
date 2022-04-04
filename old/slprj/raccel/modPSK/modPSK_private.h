#ifndef RTW_HEADER_modPSK_private_h_
#define RTW_HEADER_modPSK_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "modPSK.h"
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
#ifdef __cplusplus
extern "C" {
#endif
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#ifdef __cplusplus
}
#endif
#endif
extern real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; void * rt_TDelayCreateBuf (
int_T numBuffer , int_T bufSz , int_T elemSz ) ; boolean_T
rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr , int_T *
headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
; real_T rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T *
uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx ,
real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) ; void rt_TDelayFreeBuf ( void * buf ) ;
extern void gc0pjwtrc1 ( hzskem2oxy * localB , pvhrmw3hdx * localP ) ; extern
void nrqkqpzimh ( SimStruct * rtS_e , real_T aoygi2u5jt , real_T juzrzar12t ,
hzskem2oxy * localB , jayuearsj1 * localDW , l32trj3bao * localZCE ) ; extern
void hczqpt1isa ( m0godxqmay * localB , n3okybeeky * localP ) ; extern void
ggca33mvdu ( SimStruct * rtS_m , real_T p4rplgseji , real_T kjl5thbuyf ,
real_T eptydx1lpx , m0godxqmay * localB , dturppu2h0 * localDW ) ; extern
void ecfdd3ntdn ( jjavt2chnr * localB , ivhfwjkeio * localP ) ; extern void
msxjrffonn ( SimStruct * rtS_e , real_T nw5gpz44qo , real_T hpscg20ufb ,
real_T fsecfkw1x5 , jjavt2chnr * localB , fucri11br2 * localDW ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
