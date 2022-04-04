#ifndef RTW_HEADER_modPSK_mod3_private_h_
#define RTW_HEADER_modPSK_mod3_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "modPSK_mod3.h"
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
extern void ej24c2k4ef ( igetpbslua * localB , izzmnm4or4 * localP ) ; extern
void f5g5ssvz0o ( SimStruct * rtS_e , real_T a5pv3ym0hk , real_T gugk31myqr ,
igetpbslua * localB , kkwkju2b34 * localDW , mcilpbj4n3 * localZCE ) ; extern
void dodpev2jqu ( b25ph2maso * localB , akft0npbrm * localP ) ; extern void
akqqybeix5 ( SimStruct * rtS_i , d2girhkqx4 * localDW ) ; extern void
cum1qupdzn ( d2girhkqx4 * localDW ) ; extern void obgcvvf2c2 ( SimStruct *
rtS_i , real_T p5pgg55qc0 , real_T icsayk3iqt , real_T ish1rcvhs2 ,
b25ph2maso * localB , d2girhkqx4 * localDW ) ; extern void llehjofb4m (
iqmdugheux * localB , ft4pkmho30 * localP ) ; extern void k3cvpvfqnb (
SimStruct * rtS_g , aiayfqjngh * localDW ) ; extern void ai5wun410l (
aiayfqjngh * localDW ) ; extern void guziuj3nzo ( SimStruct * rtS_j , real_T
ifvgwahfd5 , real_T h4w2g3uqjk , real_T lwukqo0wc0 , iqmdugheux * localB ,
aiayfqjngh * localDW ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
