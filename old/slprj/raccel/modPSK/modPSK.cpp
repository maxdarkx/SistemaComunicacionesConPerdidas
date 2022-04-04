#include "rt_logging_mmi.h"
#include "modPSK_capi.h"
#include <math.h>
#include "modPSK.h"
#include "modPSK_private.h"
#include "modPSK_dt.h"
extern "C" { extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char *
id , int nargs , ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "9.6 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
}
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; PeriodicIndX rtPeriodicIndX ;
PeriodicRngX rtPeriodicRngX ;
#ifdef __cplusplus
extern "C" {
#endif
static SimStruct model_S ; SimStruct * const rtS = & model_S ;
#ifdef __cplusplus
}
#endif
#ifndef __RTW_UTFREE__  
#ifdef __cplusplus
extern "C" {
#endif
extern void * utMalloc ( size_t ) ;
#ifdef __cplusplus
}
#endif
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
#ifdef __cplusplus
extern "C" {
#endif
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#ifdef __cplusplus
}
#endif
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ;
if ( istransportdelay ) { numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; }
testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <=
tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * uBuf ,
int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T
initOutput , boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput )
{ int_T i ; real_T yout , t1 , t2 , u1 , u2 ; real_T * tBuf = uBuf + bufSz ;
if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
#ifdef __cplusplus
extern "C" {
#endif
extern void utFree ( void * ) ;
#ifdef __cplusplus
}
#endif
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void gc0pjwtrc1 (
hzskem2oxy * localB , pvhrmw3hdx * localP ) { localB -> olytfz4wp1 = localP
-> _Y0 ; } void nrqkqpzimh ( SimStruct * rtS_e , real_T aoygi2u5jt , real_T
juzrzar12t , hzskem2oxy * localB , jayuearsj1 * localDW , l32trj3bao *
localZCE ) { ZCEventType zcEvent ; if ( ssIsMajorTimeStep ( rtS_e ) ) {
zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & localZCE -> pbvwazbpud , (
aoygi2u5jt ) ) ; if ( zcEvent != NO_ZCEVENT ) { localB -> olytfz4wp1 =
juzrzar12t ; localDW -> j13iuzvksk = 4 ; } } } void hczqpt1isa ( m0godxqmay *
localB , n3okybeeky * localP ) { localB -> e5aa54psh5 = localP -> OUT_Y0 ; }
void ggca33mvdu ( SimStruct * rtS_m , real_T p4rplgseji , real_T kjl5thbuyf ,
real_T eptydx1lpx , m0godxqmay * localB , dturppu2h0 * localDW ) { if (
p4rplgseji > 0.0 ) { localB -> e5aa54psh5 = ( eptydx1lpx > kjl5thbuyf ) ; if
( ssIsMajorTimeStep ( rtS_m ) ) { srUpdateBC ( localDW -> o0iconal0v ) ; } }
} void ecfdd3ntdn ( jjavt2chnr * localB , ivhfwjkeio * localP ) { localB ->
k0x4is02ar = localP -> OUT_Y0 ; } void msxjrffonn ( SimStruct * rtS_e ,
real_T nw5gpz44qo , real_T hpscg20ufb , real_T fsecfkw1x5 , jjavt2chnr *
localB , fucri11br2 * localDW ) { if ( nw5gpz44qo > 0.0 ) { localB ->
k0x4is02ar = ( hpscg20ufb > fsecfkw1x5 ) ; if ( ssIsMajorTimeStep ( rtS_e ) )
{ srUpdateBC ( localDW -> o3j2yaswp3 ) ; } } } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return static_cast <
real_T > ( * u ) * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T si ; real_T sr ; real_T
y ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } extern "C" void MdlInitialize ( void ) { real_T tmp ;
int32_T r ; int32_T t ; uint32_T tseed ; rtX . emjc3fqnss [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . emjc3fqnss [ 1 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . emjc3fqnss [ 2 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . emjc3fqnss [ 3 ] = rtP .
AnalogFilterDesign_InitialCondition ; tmp = muDoubleScalarFloor ( rtP .
RuidoAGWN_Seed ) ; if ( muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf (
tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9
) ; } tseed = tmp < 0.0 ? static_cast < uint32_T > ( - static_cast < int32_T
> ( static_cast < uint32_T > ( - tmp ) ) ) : static_cast < uint32_T > ( tmp )
; r = static_cast < int32_T > ( tseed >> 16U ) ; t = static_cast < int32_T >
( tseed & 32768U ) ; tseed = ( ( ( ( tseed - ( static_cast < uint32_T > ( r )
<< 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U
; } else if ( tseed > 2147483646U ) { tseed = 2147483646U ; } rtDW .
afqavbs5ty = tseed ; rtDW . bssa0c1myd = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW
. afqavbs5ty ) * muDoubleScalarSqrt ( rtP . Pot_Ruido ) + rtP .
RuidoAGWN_Mean ; rtX . cyh0kmfhle [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . cyh0kmfhle [ 1 ] = rtP
. AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . cyh0kmfhle [ 2 ] =
rtP . AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . cyh0kmfhle [ 3 ]
= rtP . AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . owcac5vhsm =
rtP . Integrator_IC ; rtX . pokwk5dsee = rtP . ModuloIntegrator_IC ; for ( r
= 0 ; r < 8 ; r ++ ) { rtX . bqamom4kaa [ r ] = rtP .
AnalogFilterDesign_InitialCondition_gxj5snzs0v ; } rtDW . jddr3btzwa = rtP .
Memory_InitialCondition ; rtDW . m0i1af3trd = rtP . Monostable_ic ; rtDW .
phadp4f3b4 = rtP . SampleandHold_ic ; rtX . e1epvwdkhs = rtP .
ModuloIntegrator_IC_g1vo2kap3u ; rtX . dhvzxe4g3s = rtP .
Integrator_IC_oxpanuusbm ; rtDW . kwrhw5www5 = rtP .
TmpLatchAtDFlipFlopInport1_InitialCondition ; rtX . gc00zq2jpx = rtP .
Integrator1_IC ; rtDW . hz35lsskp2 = rtP . Memory_InitialCondition_oggd2r4odw
; rtDW . mse1diqmww = rtP . Monostable1_ic ; rtDW . bhmfx0qy3i = rtP .
SampleHold_ic ; rtX . e1jmtpc2vb = rtP . Integrator_IC_a5b0eygpkp ; rtDW .
bf33xtbrhg = rtP . Memory_InitialCondition_ljulw4woig ; rtDW . cmv1b20lsy =
rtP . Monostable3_ic ; rtDW . lvp0eixlb4 = rtP . SampleHold_ic_cvpetr2ktj ;
gc0pjwtrc1 ( & rtB . nrqkqpzimhq , & rtP . nrqkqpzimhq ) ; rtB . po2rfexerf =
rtP . OUT_Y0_gbikirmbla ; rtB . p0reyhkgec = rtP . OUT_Y0 ; rtB . g5n3z2eyy3
= rtP . Out1_Y0 ; rtB . bhwit4pfgp = rtP . Q_Y0 ; rtB . lb3j4jh0k1 = rtP .
Q_Y0_ngs1cr5pq5 ; ecfdd3ntdn ( & rtB . msxjrffonnn , & rtP . msxjrffonnn ) ;
hczqpt1isa ( & rtB . ggca33mvdun , & rtP . ggca33mvdun ) ; ecfdd3ntdn ( & rtB
. jdw3pbikft , & rtP . jdw3pbikft ) ; hczqpt1isa ( & rtB . hdzoplw4kn , & rtP
. hdzoplw4kn ) ; rtB . nylejvpk25 = rtP . _Y0 ; gc0pjwtrc1 ( & rtB .
cmjzvpvpsf , & rtP . cmjzvpvpsf ) ; { int_T rootPeriodicContStateIndices [ 2
] = { 9 , 18 } ; real_T rootPeriodicContStateRanges [ 4 ] = { 0.0 , 1.0 , 0.0
, 1.0 } ; ( void ) memcpy ( ( void * ) rtPeriodicIndX ,
rootPeriodicContStateIndices , 2 * sizeof ( int_T ) ) ; ( void ) memcpy ( (
void * ) rtPeriodicRngX , rootPeriodicContStateRanges , 4 * sizeof ( real_T )
) ; } } extern "C" void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { int_T dimensions [ 2 ] = { 1 , 1 } ; rtDW . ewzvvg2wnk . LoggedData =
rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal
( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "Rx" , SS_DOUBLE , 0 , 0 , 1
, 1 , 2 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , - 1.0 ,
1 ) ; if ( rtDW . ewzvvg2wnk . LoggedData == ( NULL ) ) return ; } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"modPSK/Receptor/Sincronismo de s&#xED;mbolo/Sign" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
2 ] = { 1 , 1 } ; sigDims . nDims = 2 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dmnu1nlz2m . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "f453babb-7d79-4740-976d-2b86b4c66b8d" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. dmnu1nlz2m . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . dmnu1nlz2m
. AQHandles , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime
( rtDW . dmnu1nlz2m . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . dmnu1nlz2m . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . dmnu1nlz2m . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } if ( ! isStreamoutAlreadyRegistered ) { } } }
} { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "s" ; fromwksInfo -> origDataTypeId = 0
; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints = 1111 ;
fromwksInfo -> time = ( NULL ) ; rtDW . f5j5cwamx4 . TimePtr = fromwksInfo ->
time ; rtDW . f5j5cwamx4 . DataPtr = fromwksInfo -> data ; rtDW . f5j5cwamx4
. RSimInfoPtr = fromwksInfo ; } rtDW . eidamkhewj . PrevIndex = - 1 ; } {
char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf (
2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } rtDW
. dazeyaom3l . Tail = 0 ; rtDW . dazeyaom3l . Head = 0 ; rtDW . dazeyaom3l .
Last = 0 ; rtDW . dazeyaom3l . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
ozcsecc153 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf (
ptrKey , "modPSK/Canal/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
ozcsecc153 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . hpsposfxjp . Tail = 0 ; rtDW . hpsposfxjp . Head = 0 ; rtDW .
hpsposfxjp . Last = 0 ; rtDW . hpsposfxjp . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput_m3b1lj5lye ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; rtDW . psh3vd4qdr . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; sprintf ( ptrKey ,
"modPSK/Receptor/Correlación/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
psh3vd4qdr . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . achc50k0kr . Tail = 0 ; rtDW . achc50k0kr . Head = 0 ; rtDW .
achc50k0kr . Last = 0 ; rtDW . achc50k0kr . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay12_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . lhdff4g1zf . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay12_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
lhdff4g1zf . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . h2kosmawcp . Tail = 0 ; rtDW . h2kosmawcp . Head = 0 ; rtDW .
h2kosmawcp . Last = 0 ; rtDW . h2kosmawcp . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . kt2rdibexx . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay2_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
kt2rdibexx . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . jklfnyaqcu . Tail = 0 ; rtDW . jklfnyaqcu . Head = 0 ; rtDW .
jklfnyaqcu . Last = 0 ; rtDW . jklfnyaqcu . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . h1me53arog . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay1_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
h1me53arog . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . bl1p0blo4b . Tail = 0 ; rtDW . bl1p0blo4b . Head = 0 ; rtDW .
bl1p0blo4b . Last = 0 ; rtDW . bl1p0blo4b . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay4_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . pu2m2nsrgd . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay4_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
pu2m2nsrgd . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . ahczbduber . Tail = 0 ; rtDW . ahczbduber . Head = 0 ; rtDW .
ahczbduber . Last = 0 ; rtDW . ahczbduber . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay3_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . lfbf1a2jus . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay3_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
lfbf1a2jus . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . mehfzxnojj . Tail = 0 ; rtDW . mehfzxnojj . Head = 0 ; rtDW .
mehfzxnojj . Last = 0 ; rtDW . mehfzxnojj . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay6_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . othjjrceoi . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay6_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
othjjrceoi . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . bxfujbkphp . Tail = 0 ; rtDW . bxfujbkphp . Head = 0 ; rtDW .
bxfujbkphp . Last = 0 ; rtDW . bxfujbkphp . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay5_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . m4vidzf1kq . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay5_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
m4vidzf1kq . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . jcgpwdcw13 . Tail = 0 ; rtDW . jcgpwdcw13 . Head = 0 ; rtDW .
jcgpwdcw13 . Last = 0 ; rtDW . jcgpwdcw13 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay8_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . ogkqvonou1 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay8_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
ogkqvonou1 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . adt2xe2pd0 . Tail = 0 ; rtDW . adt2xe2pd0 . Head = 0 ; rtDW .
adt2xe2pd0 . Last = 0 ; rtDW . adt2xe2pd0 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay7_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . iyhbqhzckm . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay7_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
iyhbqhzckm . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . mijwxy1gfd . Tail = 0 ; rtDW . mijwxy1gfd . Head = 0 ; rtDW .
mijwxy1gfd . Last = 0 ; rtDW . mijwxy1gfd . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay9_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . fdlikytedu . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay9_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
fdlikytedu . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . ewfcczil0j . Tail = 0 ; rtDW . ewfcczil0j . Head = 0 ; rtDW .
ewfcczil0j . Last = 0 ; rtDW . ewfcczil0j . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay11_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . g0jka410r5 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay11_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
g0jka410r5 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } MdlInitialize ( ) ; } extern "C" void MdlOutputs ( int_T tid
) { real_T bxdbnm30kj ; real_T asuaogf0oj ; real_T egzs33uxqr ; real_T
hrlxqi5osl ; real_T jtinpn2vu2 ; real_T chxvpheep2 ; int32_T ci ; uint32_T ri
; boolean_T eihbrr5yaz ; ZCEventType zcEvent ; srClearBC ( rtDW . nrqkqpzimhq
. j13iuzvksk ) ; srClearBC ( rtDW . hfhvsoe1hu ) ; srClearBC ( rtDW .
j3dn4gfhs1 ) ; srClearBC ( rtDW . fbu1o32502 ) ; srClearBC ( rtDW .
aece3kamvy ) ; srClearBC ( rtDW . ggca33mvdun . o0iconal0v ) ; srClearBC (
rtDW . msxjrffonnn . o3j2yaswp3 ) ; srClearBC ( rtDW . f5bd1tnerd ) ;
srClearBC ( rtDW . izid4kf2wl ) ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { {
int_T currIndex = rtDW . eidamkhewj . PrevIndex + 1 ; real_T * pDataValues =
( real_T * ) rtDW . f5j5cwamx4 . DataPtr ; int numPoints ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . f5j5cwamx4 . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; if ( currIndex < numPoints ) { pDataValues +=
currIndex ; rtB . ee42tgof2b = * pDataValues ; } else { rtB . ee42tgof2b =
0.0 ; } rtDW . eidamkhewj . PrevIndex = currIndex ; } } rtB . o5tdwwqd3u =
0.0 ; for ( ri = rtP . AnalogFilterDesign_C_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign_C_jc [ 1U ] ; ri ++ ) { rtB . o5tdwwqd3u += rtP .
AnalogFilterDesign_C_pr * rtX . emjc3fqnss [ 0U ] ; } for ( ri = rtP .
AnalogFilterDesign_C_jc [ 1U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 2U ] ;
ri ++ ) { rtB . o5tdwwqd3u += rtP . AnalogFilterDesign_C_pr * rtX .
emjc3fqnss [ 1U ] ; } for ( ri = rtP . AnalogFilterDesign_C_jc [ 2U ] ; ri <
rtP . AnalogFilterDesign_C_jc [ 3U ] ; ri ++ ) { rtB . o5tdwwqd3u += rtP .
AnalogFilterDesign_C_pr * rtX . emjc3fqnss [ 2U ] ; } for ( ri = rtP .
AnalogFilterDesign_C_jc [ 3U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 4U ] ;
ri ++ ) { rtB . o5tdwwqd3u += rtP . AnalogFilterDesign_C_pr * rtX .
emjc3fqnss [ 3U ] ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
ozcsecc153 . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . Retraso_Canal ; bxdbnm30kj =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . dazeyaom3l .
CircularBufSize , & rtDW . dazeyaom3l . Last , rtDW . dazeyaom3l . Tail ,
rtDW . dazeyaom3l . Head , rtP . TransportDelay_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . p5kktr1wyk =
rtDW . bssa0c1myd ; } rtB . mvhgymrwqe = 1.0 / rtP . Att_Volt_Canal *
bxdbnm30kj + rtB . p5kktr1wyk ; chxvpheep2 = 0.0 ; for ( ri = rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 0U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 1U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . cyh0kmfhle [ 0U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 1U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 2U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . cyh0kmfhle [ 1U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 2U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 3U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . cyh0kmfhle [ 2U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 3U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 4U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . cyh0kmfhle [ 3U ] ; } rtB .
gqtvp2z5yf = rtP . Amplitud / rtP . Att_Volt_Canal * chxvpheep2 ; { real_T *
* uBuffer = ( real_T * * ) & rtDW . psh3vd4qdr . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay_Delay ; rtB . d4ytgmijes = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , rtDW . hpsposfxjp . CircularBufSize , & rtDW . hpsposfxjp
. Last , rtDW . hpsposfxjp . Tail , rtDW . hpsposfxjp . Head , rtP .
TransportDelay_InitOutput_m3b1lj5lye , 1 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , &
rtPrevZCX . hvekerdey5 , ( rtB . d4ytgmijes ) ) ; if ( zcEvent != NO_ZCEVENT
) { rtX . owcac5vhsm = rtP . Integrator_IC ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . ijwiii2est = rtX
. owcac5vhsm ; } else { rtB . ijwiii2est = rtX . owcac5vhsm ; } rtB .
krai04vzyy = muDoubleScalarCos ( rtX . pokwk5dsee * 6.2831853071795862 +
5.497787143782138 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB .
krai04vzyy > 0.0 ) { rtDW . es3p4dnuna = 1 ; } else if ( rtB . krai04vzyy <
0.0 ) { rtDW . es3p4dnuna = - 1 ; } else { rtDW . es3p4dnuna = 0 ; } rtB .
exkkdo4tfp = rtDW . es3p4dnuna ; nrqkqpzimh ( rtS , rtB . exkkdo4tfp , rtB .
ijwiii2est , & rtB . nrqkqpzimhq , & rtDW . nrqkqpzimhq , & rtPrevZCX .
nrqkqpzimhq ) ; rtB . fpr0eiute3 = muDoubleScalarSign ( rtB . nrqkqpzimhq .
olytfz4wp1 ) ; rtB . kqemtml2w3 = ( rtB . fpr0eiute3 + rtP . AddConstant_Bias
) * rtP . Multiply_Gain ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
lhdff4g1zf . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . Tb ; rtB . da4cqxiizn = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , rtDW . achc50k0kr . CircularBufSize , & rtDW
. achc50k0kr . Last , rtDW . achc50k0kr . Tail , rtDW . achc50k0kr . Head ,
rtP . TransportDelay12_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) && ssIsMajorTimeStep ( rtS ) ) { zcEvent =
rt_ZCFcn ( FALLING_ZERO_CROSSING , & rtPrevZCX . mexgwhndus , ( rtB .
da4cqxiizn ) ) ; if ( zcEvent != NO_ZCEVENT ) { if ( ssGetLogOutput ( rtS ) )
{ { double locTime = ssGetTaskTime ( rtS , 1 ) ; if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . ewzvvg2wnk . LoggedData ) , & rtB . kqemtml2w3 , 0 ) ; }
} } rtDW . izid4kf2wl = 4 ; } } rtB . atcqfparc4 = 0.0 ; for ( ci = 0 ; ci <
8 ; ci ++ ) { for ( ri = rtP . AnalogFilterDesign_C_jc_d2bgogmalx [
static_cast < uint32_T > ( ci ) ] ; ri < rtP .
AnalogFilterDesign_C_jc_d2bgogmalx [ ci + 1U ] ; ri ++ ) { rtB . atcqfparc4
+= rtP . AnalogFilterDesign_C_pr_e3t31otpuq * rtX . bqamom4kaa [ static_cast
< uint32_T > ( ci ) ] ; } } rtB . c2cnah1c34 = rtB . mvhgymrwqe * rtB .
gqtvp2z5yf ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ooymnwvq5a = rtB .
fpr0eiute3 * rtP . Constant1_Value ; } { real_T * * uBuffer = ( real_T * * )
& rtDW . kt2rdibexx . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . ijuklwld0a =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . h2kosmawcp .
CircularBufSize , & rtDW . h2kosmawcp . Last , rtDW . h2kosmawcp . Tail ,
rtDW . h2kosmawcp . Head , rtP . TransportDelay2_InitOutput , 1 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . h1me53arog .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . Tb ; rtB . nryqbxo330 = rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , rtDW . jklfnyaqcu . CircularBufSize , & rtDW . jklfnyaqcu .
Last , rtDW . jklfnyaqcu . Tail , rtDW . jklfnyaqcu . Head , rtP .
TransportDelay1_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . pu2m2nsrgd . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ; rtB .
hihmi4odjo = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW .
bl1p0blo4b . CircularBufSize , & rtDW . bl1p0blo4b . Last , rtDW . bl1p0blo4b
. Tail , rtDW . bl1p0blo4b . Head , rtP . TransportDelay4_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
lfbf1a2jus . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . Tb ; rtB . hcmaylj25a = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , rtDW . ahczbduber . CircularBufSize , & rtDW
. ahczbduber . Last , rtDW . ahczbduber . Tail , rtDW . ahczbduber . Head ,
rtP . TransportDelay3_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . othjjrceoi . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . cyqeay1yht = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . mehfzxnojj . CircularBufSize , & rtDW . mehfzxnojj . Last , rtDW .
mehfzxnojj . Tail , rtDW . mehfzxnojj . Head , rtP .
TransportDelay6_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . m4vidzf1kq . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ; rtB .
gmgguax0lb = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW .
bxfujbkphp . CircularBufSize , & rtDW . bxfujbkphp . Last , rtDW . bxfujbkphp
. Tail , rtDW . bxfujbkphp . Head , rtP . TransportDelay5_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
ogkqvonou1 . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . Tb ; rtB . e0stmf0wje = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , rtDW . jcgpwdcw13 . CircularBufSize , & rtDW
. jcgpwdcw13 . Last , rtDW . jcgpwdcw13 . Tail , rtDW . jcgpwdcw13 . Head ,
rtP . TransportDelay8_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . iyhbqhzckm . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . ggvs3qvpfu = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . adt2xe2pd0 . CircularBufSize , & rtDW . adt2xe2pd0 . Last , rtDW .
adt2xe2pd0 . Tail , rtDW . adt2xe2pd0 . Head , rtP .
TransportDelay7_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . fdlikytedu . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ; rtB .
mdt0d44sb1 = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW .
mijwxy1gfd . CircularBufSize , & rtDW . mijwxy1gfd . Last , rtDW . mijwxy1gfd
. Tail , rtDW . mijwxy1gfd . Head , rtP . TransportDelay9_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
g0jka410r5 . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . Tb ; asuaogf0oj = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , rtDW . ewfcczil0j . CircularBufSize , & rtDW
. ewfcczil0j . Last , rtDW . ewfcczil0j . Tail , rtDW . ewfcczil0j . Head ,
rtP . TransportDelay11_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB .
kxicx45q5w = ( ( ( ( ( ( ( ( ( rtB . ijuklwld0a * rtP . Constant2_Value + rtB
. ooymnwvq5a ) + rtB . nryqbxo330 * rtP . Constant3_Value ) + rtB .
hihmi4odjo * rtP . Constant4_Value ) + rtB . hcmaylj25a * rtP .
Constant5_Value ) + rtB . cyqeay1yht * rtP . Constant6_Value ) + rtB .
gmgguax0lb * rtP . Constant7_Value ) + rtB . e0stmf0wje * rtP .
Constant8_Value ) + rtB . ggvs3qvpfu * rtP . Constant9_Value ) + rtB .
mdt0d44sb1 * rtP . Constant10_Value ) + asuaogf0oj * rtP . Constant13_Value ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . ezpzvynldc = ( rtB . kxicx45q5w >=
rtP . Switch_Threshold ) ; } if ( rtDW . ezpzvynldc ) { rtB . i0rkndmb13 =
rtP . Constant15_Value ; } else { rtB . i0rkndmb13 = rtP . Constant14_Value ;
} rtB . owsmsehx52 = ssGetT ( rtS ) ; rtB . djf3ji5ytw = ( rtB . i0rkndmb13
!= 0.0 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . fxorr2mhne [ 0 ]
> 0.0 ) { rtB . po2rfexerf = ( static_cast < int32_T > ( rtDW . m0i1af3trd )
< static_cast < int32_T > ( rtB . djf3ji5ytw ) ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . fbu1o32502 ) ; } } if ( rtB . fxorr2mhne [ 1 ]
> 0.0 ) { rtB . p0reyhkgec = ( static_cast < int32_T > ( rtDW . m0i1af3trd )
> static_cast < int32_T > ( rtB . djf3ji5ytw ) ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . j3dn4gfhs1 ) ; } } eihbrr5yaz = ( rtB .
po2rfexerf || rtB . p0reyhkgec ) ; rtB . bkyaf0nkhx = ( ( ! rtDW . jddr3btzwa
) && eihbrr5yaz ) ; rtB . nsdd2hdqf1 = rtDW . phadp4f3b4 ; rtB . jyhhxwku5j =
1000.0 * rtP . Tb - 2.2204460492503131E-16 ; } if ( rtB . bkyaf0nkhx ) { rtB
. a34p2x24w2 = rtB . owsmsehx52 ; } else { rtB . a34p2x24w2 = rtB .
nsdd2hdqf1 ; } rtB . jers21a5nu = rtB . a34p2x24w2 + rtB . jyhhxwku5j ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
nssittgb5o = ( rtB . jers21a5nu > rtB . owsmsehx52 ) ; } rtB . pzi0oq2mxf =
rtDW . nssittgb5o ; } rtB . fpmqgmj2cy = ssGetT ( rtS ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( eihbrr5yaz && (
rtPrevZCX . f2owmsmztm != POS_ZCSIG ) ) { rtB . g5n3z2eyy3 = rtB . fpmqgmj2cy
; rtDW . hfhvsoe1hu = 4 ; } rtPrevZCX . f2owmsmztm = eihbrr5yaz ; } rtB .
gnebrkauvk = rtB . g5n3z2eyy3 + rtP . Constant_Value ; if ( ssIsMajorTimeStep
( rtS ) ) { rtDW . iwr1b2avuw = ( rtB . gnebrkauvk > rtB . fpmqgmj2cy ) ; } }
if ( rtB . pzi0oq2mxf ) { rtB . jkw11eafiz = rtB . exkkdo4tfp ; } else { rtB
. jkw11eafiz = rtP . Constant16_Value ; } rtB . acvegdxqsb =
muDoubleScalarCos ( rtX . e1epvwdkhs * 6.2831853071795862 ) ; chxvpheep2 =
rtP . Att_Volt_Canal / rtP . Amplitud * rtB . mvhgymrwqe ; chxvpheep2 =
chxvpheep2 * chxvpheep2 * rtB . acvegdxqsb ; egzs33uxqr = rtP . R2 / rtP . R1
* chxvpheep2 + rtX . dhvzxe4g3s ; rtB . c1quq2kkeo = rtP . Kv /
6.2831853071795862 * egzs33uxqr + 2.0 * rtP . Frec_port ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { eihbrr5yaz = rtDW . kwrhw5www5 ; if ( rtB . acvegdxqsb >
0.0 ) { rtDW . hr4s0kwfwa = 1 ; } else if ( rtB . acvegdxqsb < 0.0 ) { rtDW .
hr4s0kwfwa = - 1 ; } else { rtDW . hr4s0kwfwa = 0 ; } zcEvent = NO_ZCEVENT ;
if ( ssIsMajorTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING
, & rtPrevZCX . cmf42mhbgp , ( static_cast < real_T > ( rtDW . hr4s0kwfwa ) )
) ; } if ( rtP . Constant2_Value_mwviqzbxqh > 0.0 ) { if ( ! rtDW .
ehwgl0hfyk ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . ehwgl0hfyk =
true ; } if ( ssIsMajorTimeStep ( rtS ) && ( zcEvent != NO_ZCEVENT ) ) { rtB
. bhwit4pfgp = eihbrr5yaz ; rtB . lb3j4jh0k1 = ! rtB . bhwit4pfgp ; rtDW .
aece3kamvy = 4 ; } } else if ( rtDW . ehwgl0hfyk ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . bhwit4pfgp = rtP .
Q_Y0 ; rtB . lb3j4jh0k1 = rtP . Q_Y0_ngs1cr5pq5 ; rtDW . ehwgl0hfyk = false ;
} rtB . bqly4iysyb = rtP . Constant6_Value_dkmziwbikw * static_cast < real_T
> ( rtB . bhwit4pfgp ) + rtP . Constant5_Value_hu2bresth1 ; } rtB .
apaian0okb = 1.0 / ( rtP . R1 * rtP . C ) * chxvpheep2 ; rtB . c1co2zjsgy =
rtP . Constant1_Value_hcjo4f4r5j * rtB . atcqfparc4 ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( rtB . c1co2zjsgy > 0.0 ) { rtDW . lfe1ibkwop = 1 ; }
else if ( rtB . c1co2zjsgy < 0.0 ) { rtDW . lfe1ibkwop = - 1 ; } else { rtDW
. lfe1ibkwop = 0 ; } rtB . ktfxpbuyoi = rtDW . lfe1ibkwop ; } if (
ssIsMajorTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , &
rtPrevZCX . gzsjhe3j3h , ( rtB . exkkdo4tfp ) ) ; if ( zcEvent != NO_ZCEVENT
) { rtX . gc00zq2jpx = rtP . Integrator1_IC ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . max2gpqnqf = rtX
. gc00zq2jpx ; } else { rtB . max2gpqnqf = rtX . gc00zq2jpx ; } rtB .
ewn2wlainw = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
hrlxqi5osl = rtDW . mse1diqmww ; msxjrffonn ( rtS , rtB . nhjc2m3cbx [ 0 ] ,
rtB . exkkdo4tfp , hrlxqi5osl , & rtB . msxjrffonnn , & rtDW . msxjrffonnn )
; ggca33mvdu ( rtS , rtB . nhjc2m3cbx [ 1 ] , rtB . exkkdo4tfp , hrlxqi5osl ,
& rtB . ggca33mvdun , & rtDW . ggca33mvdun ) ; rtB . owu2nywhc4 = ( ( ! rtDW
. hz35lsskp2 ) && ( rtB . msxjrffonnn . k0x4is02ar || rtB . ggca33mvdun .
e5aa54psh5 ) ) ; rtB . jxbxouhvpz = rtDW . bhmfx0qy3i ; } if ( rtB .
owu2nywhc4 ) { rtB . m0n2ncikto = rtB . ewn2wlainw ; } else { rtB .
m0n2ncikto = rtB . jxbxouhvpz ; } rtB . blc3ahlqoa = ( ( 1.0 - rtP . b ) /
rtP . Rb - 2.2204460492503131E-16 ) + rtB . m0n2ncikto ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . jf03aj3gmd = (
rtB . blc3ahlqoa > rtB . ewn2wlainw ) ; } rtB . lgqv4rlpjm = rtDW .
jf03aj3gmd ; } if ( ssIsMajorTimeStep ( rtS ) ) { eihbrr5yaz = ( ( ! rtB .
lgqv4rlpjm ) && ( rtPrevZCX . cqolqyndhe != ZERO_ZCSIG ) ) ; rtPrevZCX .
cqolqyndhe = rtB . lgqv4rlpjm ; if ( eihbrr5yaz ) { rtX . e1jmtpc2vb = rtP .
Integrator_IC_a5b0eygpkp ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } rtB . n2wkjomta0 = rtX . e1jmtpc2vb ; } else { rtB . n2wkjomta0 = rtX .
e1jmtpc2vb ; } rtB . f14htfpour = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { jtinpn2vu2 = rtDW . cmv1b20lsy ; msxjrffonn ( rtS , rtB .
ap3kp501sl [ 0 ] , rtB . exkkdo4tfp , jtinpn2vu2 , & rtB . jdw3pbikft , &
rtDW . jdw3pbikft ) ; ggca33mvdu ( rtS , rtB . ap3kp501sl [ 1 ] , rtB .
exkkdo4tfp , jtinpn2vu2 , & rtB . hdzoplw4kn , & rtDW . hdzoplw4kn ) ; rtB .
pehstkjnkd = ( ( ! rtDW . bf33xtbrhg ) && ( rtB . jdw3pbikft . k0x4is02ar ||
rtB . hdzoplw4kn . e5aa54psh5 ) ) ; rtB . k3ehqfnhji = rtDW . lvp0eixlb4 ; }
if ( rtB . pehstkjnkd ) { rtB . dxkeuerubi = rtB . f14htfpour ; } else { rtB
. dxkeuerubi = rtB . k3ehqfnhji ; } rtB . e2pyl4rib3 = ( rtP . b / rtP . Rb -
2.2204460492503131E-16 ) + rtB . dxkeuerubi ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . itvjzmhcag = ( rtB .
e2pyl4rib3 > rtB . f14htfpour ) ; } rtB . hehncpsx5o = rtDW . itvjzmhcag ; if
( ssIsMajorTimeStep ( rtS ) ) { if ( ( ! rtB . hehncpsx5o ) && ( rtPrevZCX .
lzwwl1jhb5 != ZERO_ZCSIG ) ) { rtB . nylejvpk25 = rtB . max2gpqnqf ; rtDW .
f5bd1tnerd = 4 ; } rtPrevZCX . lzwwl1jhb5 = rtB . hehncpsx5o ; } rtB .
nnbbyhuwe5 = muDoubleScalarAbs ( rtB . nylejvpk25 ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . m2jub0kxpz = ( rtB . n2wkjomta0 >= 0.0 )
; } rtB . pjddsfuka3 = rtB . nnbbyhuwe5 - ( rtDW . m2jub0kxpz > 0 ? rtB .
n2wkjomta0 : - rtB . n2wkjomta0 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
nrqkqpzimh ( rtS , rtB . exkkdo4tfp , rtB . pjddsfuka3 , & rtB . cmjzvpvpsf ,
& rtDW . cmjzvpvpsf , & rtPrevZCX . cmjzvpvpsf ) ; } if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { { if ( rtDW . dmnu1nlz2m . AQHandles && ssGetLogOutput ( rtS )
) { sdiWriteSignal ( rtDW . dmnu1nlz2m . AQHandles , ssGetTaskTime ( rtS , 1
) , ( char * ) & rtB . ktfxpbuyoi + 0 ) ; } } rtB . gpdt1s5m43 = rtP . kv2 *
rtB . cmjzvpvpsf . olytfz4wp1 + rtP . Rb ; } if ( ssIsSampleHit ( rtS , 2 , 0
) ) { rtB . df1ir0te5a = rtP . Multiply_Gain_ptvyavefxe * rtB . ee42tgof2b +
rtP . AddConstant_Bias_ljcfbacsm3 ; } rtB . nag5slvt33 = ( muDoubleScalarSin
( 6.2831853071795862 * rtP . Frec_port * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWave_Phase ) * rtP . Amplitud + rtP . SineWave_Bias ) * rtB . df1ir0te5a
; UNUSED_PARAMETER ( tid ) ; } extern "C" void MdlOutputsTID4 ( int_T tid ) {
switch ( static_cast < int32_T > ( rtP . Constant1_Value_afssjxve00 ) ) {
case 1 : rtB . fxorr2mhne [ 0 ] = rtP . posedge_Value [ 0 ] ; rtB .
fxorr2mhne [ 1 ] = rtP . posedge_Value [ 1 ] ; break ; case 2 : rtB .
fxorr2mhne [ 0 ] = rtP . negedge_Value [ 0 ] ; rtB . fxorr2mhne [ 1 ] = rtP .
negedge_Value [ 1 ] ; break ; default : rtB . fxorr2mhne [ 0 ] = rtP .
eitheredge_Value [ 0 ] ; rtB . fxorr2mhne [ 1 ] = rtP . eitheredge_Value [ 1
] ; break ; } switch ( static_cast < int32_T > ( rtP . Monostable1_EdgeDetect
) ) { case 1 : rtB . nhjc2m3cbx [ 0 ] = rtP . posedge_Value_av2r5ustik [ 0 ]
; rtB . nhjc2m3cbx [ 1 ] = rtP . posedge_Value_av2r5ustik [ 1 ] ; break ;
case 2 : rtB . nhjc2m3cbx [ 0 ] = rtP . negedge_Value_fef1hh2jz4 [ 0 ] ; rtB
. nhjc2m3cbx [ 1 ] = rtP . negedge_Value_fef1hh2jz4 [ 1 ] ; break ; default :
rtB . nhjc2m3cbx [ 0 ] = rtP . eitheredge_Value_nntils3rkv [ 0 ] ; rtB .
nhjc2m3cbx [ 1 ] = rtP . eitheredge_Value_nntils3rkv [ 1 ] ; break ; } switch
( static_cast < int32_T > ( rtP . Monostable3_EdgeDetect ) ) { case 1 : rtB .
ap3kp501sl [ 0 ] = rtP . posedge_Value_j0croo5cnv [ 0 ] ; rtB . ap3kp501sl [
1 ] = rtP . posedge_Value_j0croo5cnv [ 1 ] ; break ; case 2 : rtB .
ap3kp501sl [ 0 ] = rtP . negedge_Value_lnmee3h1ob [ 0 ] ; rtB . ap3kp501sl [
1 ] = rtP . negedge_Value_lnmee3h1ob [ 1 ] ; break ; default : rtB .
ap3kp501sl [ 0 ] = rtP . eitheredge_Value_gsipsgs54b [ 0 ] ; rtB . ap3kp501sl
[ 1 ] = rtP . eitheredge_Value_gsipsgs54b [ 1 ] ; break ; } UNUSED_PARAMETER
( tid ) ; } extern "C" void MdlUpdate ( int_T tid ) { { real_T * * uBuffer =
( real_T * * ) & rtDW . ozcsecc153 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . dazeyaom3l . Head = ( ( rtDW . dazeyaom3l . Head < (
rtDW . dazeyaom3l . CircularBufSize - 1 ) ) ? ( rtDW . dazeyaom3l . Head + 1
) : 0 ) ; if ( rtDW . dazeyaom3l . Head == rtDW . dazeyaom3l . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . dazeyaom3l . CircularBufSize , &
rtDW . dazeyaom3l . Tail , & rtDW . dazeyaom3l . Head , & rtDW . dazeyaom3l .
Last , simTime - rtP . Retraso_Canal , uBuffer , ( boolean_T ) 0 , false , &
rtDW . dazeyaom3l . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Canal/Transport\nDelay_TUbuffer0" , ( void * * ) ( & uBuffer [ 0 ] )
, 2 * rtDW . dazeyaom3l . CircularBufSize * sizeof ( real_T ) , ( NULL ) , (
NULL ) ) ; } ( * uBuffer + rtDW . dazeyaom3l . CircularBufSize ) [ rtDW .
dazeyaom3l . Head ] = simTime ; ( * uBuffer ) [ rtDW . dazeyaom3l . Head ] =
rtB . o5tdwwqd3u ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . bssa0c1myd
= rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . afqavbs5ty ) * muDoubleScalarSqrt (
rtP . Pot_Ruido ) + rtP . RuidoAGWN_Mean ; } { real_T * * uBuffer = ( real_T
* * ) & rtDW . psh3vd4qdr . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . hpsposfxjp . Head = ( ( rtDW . hpsposfxjp . Head < ( rtDW .
hpsposfxjp . CircularBufSize - 1 ) ) ? ( rtDW . hpsposfxjp . Head + 1 ) : 0 )
; if ( rtDW . hpsposfxjp . Head == rtDW . hpsposfxjp . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hpsposfxjp . CircularBufSize , & rtDW
. hpsposfxjp . Tail , & rtDW . hpsposfxjp . Head , & rtDW . hpsposfxjp . Last
, simTime - rtP . TransportDelay_Delay , uBuffer , ( boolean_T ) 0 , false ,
& rtDW . hpsposfxjp . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Correlación/Transport\nDelay_TUbuffer0" , ( void * * ) ( &
uBuffer [ 0 ] ) , 2 * rtDW . hpsposfxjp . CircularBufSize * sizeof ( real_T )
, ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . hpsposfxjp . CircularBufSize
) [ rtDW . hpsposfxjp . Head ] = simTime ; ( * uBuffer ) [ rtDW . hpsposfxjp
. Head ] = rtB . exkkdo4tfp ; } { real_T * * uBuffer = ( real_T * * ) & rtDW
. lhdff4g1zf . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
achc50k0kr . Head = ( ( rtDW . achc50k0kr . Head < ( rtDW . achc50k0kr .
CircularBufSize - 1 ) ) ? ( rtDW . achc50k0kr . Head + 1 ) : 0 ) ; if ( rtDW
. achc50k0kr . Head == rtDW . achc50k0kr . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . achc50k0kr . CircularBufSize , & rtDW
. achc50k0kr . Tail , & rtDW . achc50k0kr . Head , & rtDW . achc50k0kr . Last
, simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
achc50k0kr . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay12_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . achc50k0kr . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . achc50k0kr .
CircularBufSize ) [ rtDW . achc50k0kr . Head ] = simTime ; ( * uBuffer ) [
rtDW . achc50k0kr . Head ] = rtB . jkw11eafiz ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . kt2rdibexx . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . h2kosmawcp . Head = ( ( rtDW . h2kosmawcp . Head < (
rtDW . h2kosmawcp . CircularBufSize - 1 ) ) ? ( rtDW . h2kosmawcp . Head + 1
) : 0 ) ; if ( rtDW . h2kosmawcp . Head == rtDW . h2kosmawcp . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . h2kosmawcp . CircularBufSize , &
rtDW . h2kosmawcp . Tail , & rtDW . h2kosmawcp . Head , & rtDW . h2kosmawcp .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
h2kosmawcp . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay2_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . h2kosmawcp . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . h2kosmawcp .
CircularBufSize ) [ rtDW . h2kosmawcp . Head ] = simTime ; ( * uBuffer ) [
rtDW . h2kosmawcp . Head ] = rtB . fpr0eiute3 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . h1me53arog . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . jklfnyaqcu . Head = ( ( rtDW . jklfnyaqcu . Head < (
rtDW . jklfnyaqcu . CircularBufSize - 1 ) ) ? ( rtDW . jklfnyaqcu . Head + 1
) : 0 ) ; if ( rtDW . jklfnyaqcu . Head == rtDW . jklfnyaqcu . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . jklfnyaqcu . CircularBufSize , &
rtDW . jklfnyaqcu . Tail , & rtDW . jklfnyaqcu . Head , & rtDW . jklfnyaqcu .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
jklfnyaqcu . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay1_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . jklfnyaqcu . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . jklfnyaqcu .
CircularBufSize ) [ rtDW . jklfnyaqcu . Head ] = simTime ; ( * uBuffer ) [
rtDW . jklfnyaqcu . Head ] = rtB . ijuklwld0a ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . pu2m2nsrgd . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . bl1p0blo4b . Head = ( ( rtDW . bl1p0blo4b . Head < (
rtDW . bl1p0blo4b . CircularBufSize - 1 ) ) ? ( rtDW . bl1p0blo4b . Head + 1
) : 0 ) ; if ( rtDW . bl1p0blo4b . Head == rtDW . bl1p0blo4b . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . bl1p0blo4b . CircularBufSize , &
rtDW . bl1p0blo4b . Tail , & rtDW . bl1p0blo4b . Head , & rtDW . bl1p0blo4b .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
bl1p0blo4b . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay4_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . bl1p0blo4b . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . bl1p0blo4b .
CircularBufSize ) [ rtDW . bl1p0blo4b . Head ] = simTime ; ( * uBuffer ) [
rtDW . bl1p0blo4b . Head ] = rtB . nryqbxo330 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . lfbf1a2jus . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . ahczbduber . Head = ( ( rtDW . ahczbduber . Head < (
rtDW . ahczbduber . CircularBufSize - 1 ) ) ? ( rtDW . ahczbduber . Head + 1
) : 0 ) ; if ( rtDW . ahczbduber . Head == rtDW . ahczbduber . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ahczbduber . CircularBufSize , &
rtDW . ahczbduber . Tail , & rtDW . ahczbduber . Head , & rtDW . ahczbduber .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
ahczbduber . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay3_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . ahczbduber . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . ahczbduber .
CircularBufSize ) [ rtDW . ahczbduber . Head ] = simTime ; ( * uBuffer ) [
rtDW . ahczbduber . Head ] = rtB . hihmi4odjo ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . othjjrceoi . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . mehfzxnojj . Head = ( ( rtDW . mehfzxnojj . Head < (
rtDW . mehfzxnojj . CircularBufSize - 1 ) ) ? ( rtDW . mehfzxnojj . Head + 1
) : 0 ) ; if ( rtDW . mehfzxnojj . Head == rtDW . mehfzxnojj . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . mehfzxnojj . CircularBufSize , &
rtDW . mehfzxnojj . Tail , & rtDW . mehfzxnojj . Head , & rtDW . mehfzxnojj .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
mehfzxnojj . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay6_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . mehfzxnojj . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . mehfzxnojj .
CircularBufSize ) [ rtDW . mehfzxnojj . Head ] = simTime ; ( * uBuffer ) [
rtDW . mehfzxnojj . Head ] = rtB . hcmaylj25a ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . m4vidzf1kq . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . bxfujbkphp . Head = ( ( rtDW . bxfujbkphp . Head < (
rtDW . bxfujbkphp . CircularBufSize - 1 ) ) ? ( rtDW . bxfujbkphp . Head + 1
) : 0 ) ; if ( rtDW . bxfujbkphp . Head == rtDW . bxfujbkphp . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . bxfujbkphp . CircularBufSize , &
rtDW . bxfujbkphp . Tail , & rtDW . bxfujbkphp . Head , & rtDW . bxfujbkphp .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
bxfujbkphp . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay5_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . bxfujbkphp . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . bxfujbkphp .
CircularBufSize ) [ rtDW . bxfujbkphp . Head ] = simTime ; ( * uBuffer ) [
rtDW . bxfujbkphp . Head ] = rtB . cyqeay1yht ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . ogkqvonou1 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . jcgpwdcw13 . Head = ( ( rtDW . jcgpwdcw13 . Head < (
rtDW . jcgpwdcw13 . CircularBufSize - 1 ) ) ? ( rtDW . jcgpwdcw13 . Head + 1
) : 0 ) ; if ( rtDW . jcgpwdcw13 . Head == rtDW . jcgpwdcw13 . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . jcgpwdcw13 . CircularBufSize , &
rtDW . jcgpwdcw13 . Tail , & rtDW . jcgpwdcw13 . Head , & rtDW . jcgpwdcw13 .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
jcgpwdcw13 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay8_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . jcgpwdcw13 . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . jcgpwdcw13 .
CircularBufSize ) [ rtDW . jcgpwdcw13 . Head ] = simTime ; ( * uBuffer ) [
rtDW . jcgpwdcw13 . Head ] = rtB . gmgguax0lb ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . iyhbqhzckm . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . adt2xe2pd0 . Head = ( ( rtDW . adt2xe2pd0 . Head < (
rtDW . adt2xe2pd0 . CircularBufSize - 1 ) ) ? ( rtDW . adt2xe2pd0 . Head + 1
) : 0 ) ; if ( rtDW . adt2xe2pd0 . Head == rtDW . adt2xe2pd0 . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . adt2xe2pd0 . CircularBufSize , &
rtDW . adt2xe2pd0 . Tail , & rtDW . adt2xe2pd0 . Head , & rtDW . adt2xe2pd0 .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
adt2xe2pd0 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay7_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . adt2xe2pd0 . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . adt2xe2pd0 .
CircularBufSize ) [ rtDW . adt2xe2pd0 . Head ] = simTime ; ( * uBuffer ) [
rtDW . adt2xe2pd0 . Head ] = rtB . e0stmf0wje ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . fdlikytedu . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . mijwxy1gfd . Head = ( ( rtDW . mijwxy1gfd . Head < (
rtDW . mijwxy1gfd . CircularBufSize - 1 ) ) ? ( rtDW . mijwxy1gfd . Head + 1
) : 0 ) ; if ( rtDW . mijwxy1gfd . Head == rtDW . mijwxy1gfd . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . mijwxy1gfd . CircularBufSize , &
rtDW . mijwxy1gfd . Tail , & rtDW . mijwxy1gfd . Head , & rtDW . mijwxy1gfd .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
mijwxy1gfd . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay9_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , 2 * rtDW . mijwxy1gfd . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . mijwxy1gfd .
CircularBufSize ) [ rtDW . mijwxy1gfd . Head ] = simTime ; ( * uBuffer ) [
rtDW . mijwxy1gfd . Head ] = rtB . ggvs3qvpfu ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . g0jka410r5 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . ewfcczil0j . Head = ( ( rtDW . ewfcczil0j . Head < (
rtDW . ewfcczil0j . CircularBufSize - 1 ) ) ? ( rtDW . ewfcczil0j . Head + 1
) : 0 ) ; if ( rtDW . ewfcczil0j . Head == rtDW . ewfcczil0j . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ewfcczil0j . CircularBufSize , &
rtDW . ewfcczil0j . Tail , & rtDW . ewfcczil0j . Head , & rtDW . ewfcczil0j .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
ewfcczil0j . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK/Receptor/Sincronismo de Trama/Transport\nDelay11_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . ewfcczil0j . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . ewfcczil0j .
CircularBufSize ) [ rtDW . ewfcczil0j . Head ] = simTime ; ( * uBuffer ) [
rtDW . ewfcczil0j . Head ] = rtB . mdt0d44sb1 ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . jddr3btzwa = rtB . pzi0oq2mxf ; rtDW . m0i1af3trd = rtB .
djf3ji5ytw ; rtDW . phadp4f3b4 = rtB . a34p2x24w2 ; rtDW . kwrhw5www5 = rtB .
lb3j4jh0k1 ; rtDW . hz35lsskp2 = rtB . lgqv4rlpjm ; rtDW . mse1diqmww = rtB .
exkkdo4tfp ; rtDW . bhmfx0qy3i = rtB . m0n2ncikto ; rtDW . bf33xtbrhg = rtB .
hehncpsx5o ; rtDW . cmv1b20lsy = rtB . exkkdo4tfp ; rtDW . lvp0eixlb4 = rtB .
dxkeuerubi ; } UNUSED_PARAMETER ( tid ) ; } extern "C" void MdlUpdateTID4 (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } extern "C" void MdlDerivatives (
void ) { XDot * _rtXdot ; int_T is ; uint32_T ri ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> emjc3fqnss [ 0 ] = 0.0 ; _rtXdot -> emjc3fqnss
[ 1 ] = 0.0 ; _rtXdot -> emjc3fqnss [ 2 ] = 0.0 ; _rtXdot -> emjc3fqnss [ 3 ]
= 0.0 ; for ( ri = rtP . AnalogFilterDesign_A_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign_A_jc [ 1U ] ; ri ++ ) { _rtXdot -> emjc3fqnss [ rtP .
AnalogFilterDesign_A_ir [ ri ] ] += rtP . AnalogFilterDesign_A_pr [ ri ] *
rtX . emjc3fqnss [ 0U ] ; } for ( ri = rtP . AnalogFilterDesign_A_jc [ 1U ] ;
ri < rtP . AnalogFilterDesign_A_jc [ 2U ] ; ri ++ ) { _rtXdot -> emjc3fqnss [
rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP . AnalogFilterDesign_A_pr [ ri
] * rtX . emjc3fqnss [ 1U ] ; } for ( ri = rtP . AnalogFilterDesign_A_jc [ 2U
] ; ri < rtP . AnalogFilterDesign_A_jc [ 3U ] ; ri ++ ) { _rtXdot ->
emjc3fqnss [ rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP .
AnalogFilterDesign_A_pr [ ri ] * rtX . emjc3fqnss [ 2U ] ; } for ( ri = rtP .
AnalogFilterDesign_A_jc [ 3U ] ; ri < rtP . AnalogFilterDesign_A_jc [ 4U ] ;
ri ++ ) { _rtXdot -> emjc3fqnss [ rtP . AnalogFilterDesign_A_ir [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . emjc3fqnss [ 3U ] ; } for ( ri =
rtP . AnalogFilterDesign_B_jc [ 0U ] ; ri < rtP . AnalogFilterDesign_B_jc [
1U ] ; ri ++ ) { _rtXdot -> emjc3fqnss [ rtP . AnalogFilterDesign_B_ir ] +=
rtP . AnalogFilterDesign_B_pr * rtB . nag5slvt33 ; } _rtXdot -> cyh0kmfhle [
0 ] = 0.0 ; _rtXdot -> cyh0kmfhle [ 1 ] = 0.0 ; _rtXdot -> cyh0kmfhle [ 2 ] =
0.0 ; _rtXdot -> cyh0kmfhle [ 3 ] = 0.0 ; for ( ri = rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 0U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 1U ] ; ri ++ ) { _rtXdot -> cyh0kmfhle [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . cyh0kmfhle [ 0U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 1U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 2U ] ; ri ++ ) { _rtXdot -> cyh0kmfhle [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . cyh0kmfhle [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 2U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 3U ] ; ri ++ ) { _rtXdot -> cyh0kmfhle [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . cyh0kmfhle [ 2U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 3U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 4U ] ; ri ++ ) { _rtXdot -> cyh0kmfhle [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . cyh0kmfhle [ 3U ] ; } for (
ri = rtP . AnalogFilterDesign_B_jc_nk0ranamkl [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc_nk0ranamkl [ 1U ] ; ri ++ ) { _rtXdot -> cyh0kmfhle [
rtP . AnalogFilterDesign_B_ir_gklrfvy2xp ] += rtP .
AnalogFilterDesign_B_pr_om0jg41jmb * rtB . bqly4iysyb ; } _rtXdot ->
owcac5vhsm = rtB . atcqfparc4 ; _rtXdot -> pokwk5dsee = rtB . gpdt1s5m43 ;
for ( is = 0 ; is < 8 ; is ++ ) { _rtXdot -> bqamom4kaa [ is ] = 0.0 ; } for
( is = 0 ; is < 8 ; is ++ ) { for ( ri = rtP .
AnalogFilterDesign_A_jc_h5xar20tzm [ static_cast < uint32_T > ( is ) ] ; ri <
rtP . AnalogFilterDesign_A_jc_h5xar20tzm [ is + 1U ] ; ri ++ ) { _rtXdot ->
bqamom4kaa [ rtP . AnalogFilterDesign_A_ir_cx1zj2mhzp [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_f4zixacbw1 [ ri ] * rtX . bqamom4kaa [ static_cast <
uint32_T > ( is ) ] ; } } for ( ri = rtP . AnalogFilterDesign_B_jc_acwf2d2gj0
[ 0U ] ; ri < rtP . AnalogFilterDesign_B_jc_acwf2d2gj0 [ 1U ] ; ri ++ ) {
_rtXdot -> bqamom4kaa [ rtP . AnalogFilterDesign_B_ir_nneewrak4c ] += rtP .
AnalogFilterDesign_B_pr_by1sufu2fg * rtB . c2cnah1c34 ; } _rtXdot ->
e1epvwdkhs = rtB . c1quq2kkeo ; _rtXdot -> dhvzxe4g3s = rtB . apaian0okb ;
_rtXdot -> gc00zq2jpx = rtB . ktfxpbuyoi ; _rtXdot -> e1jmtpc2vb = rtB .
ktfxpbuyoi ; } extern "C" void MdlProjection ( void ) { } extern "C" void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> iazpe4yfr5 = rtB .
d4ytgmijes ; _rtZCSV -> a1t4ed4wgs = rtB . krai04vzyy ; _rtZCSV -> jzsmdmady2
= rtB . da4cqxiizn ; _rtZCSV -> ip4oxd3020 = rtB . kxicx45q5w - rtP .
Switch_Threshold ; _rtZCSV -> mwjydau40g = rtB . jers21a5nu - rtB .
owsmsehx52 ; _rtZCSV -> ksohzj1diq = rtB . gnebrkauvk - rtB . fpmqgmj2cy ;
_rtZCSV -> kghj5pk2h3 = rtB . acvegdxqsb ; _rtZCSV -> i252fdz5sq = rtB .
c1co2zjsgy ; _rtZCSV -> ddj2qfk2oh = rtB . blc3ahlqoa - rtB . ewn2wlainw ;
_rtZCSV -> mvauzegt1r = rtB . e2pyl4rib3 - rtB . f14htfpour ; _rtZCSV ->
fjujlpnk1z = rtB . n2wkjomta0 ; } extern "C" void MdlTerminate ( void ) {
rt_FREE ( rtDW . f5j5cwamx4 . RSimInfoPtr ) ; rt_TDelayFreeBuf ( rtDW .
ozcsecc153 . TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . psh3vd4qdr .
TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . lhdff4g1zf . TUbufferPtrs [
0 ] ) ; rt_TDelayFreeBuf ( rtDW . kt2rdibexx . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . h1me53arog . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . pu2m2nsrgd . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . lfbf1a2jus . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . othjjrceoi . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . m4vidzf1kq . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . ogkqvonou1 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . iyhbqhzckm . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . fdlikytedu . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . g0jka410r5 . TUbufferPtrs [ 0 ] ) ; { if ( rtDW .
dmnu1nlz2m . AQHandles ) { sdiTerminateStreaming ( & rtDW . dmnu1nlz2m .
AQHandles ) ; } } } static void mr_modPSK_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_modPSK_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_modPSK_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_modPSK_restoreDataFromMxArray ( void * destData , const mxArray * srcArray
, mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_modPSK_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_modPSK_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_modPSK_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_modPSK_extractBitFieldFromMxArray
( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_modPSK_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i ,
int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_modPSK_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T
* varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j
) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const
uint8_T * ) srcData , numBytes ) ; } static void
mr_modPSK_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_modPSK_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_modPSK_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_modPSK_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_modPSK_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_modPSK_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal
= ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j
) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray *
mr_modPSK_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ] = { "rtB" ,
"rtDW" , "rtPrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3
, ssDWFieldNames ) ; mr_modPSK_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const
void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char *
rtdwDataFieldNames [ 61 ] = { "rtDW.bssa0c1myd" , "rtDW.phadp4f3b4" ,
"rtDW.mse1diqmww" , "rtDW.bhmfx0qy3i" , "rtDW.cmv1b20lsy" , "rtDW.lvp0eixlb4"
, "rtDW.kv1pa1ywzi" , "rtDW.ij5krlemte" , "rtDW.h0tlb2kuwe" ,
"rtDW.mj5evfwhzb" , "rtDW.ngqgrvp4ei" , "rtDW.ajgpkfca1o" , "rtDW.ma103w0rl5"
, "rtDW.ocb1qur2h1" , "rtDW.d0nohml22r" , "rtDW.mzuvrrfieu" ,
"rtDW.d4whpythev" , "rtDW.d4oxqhfhid" , "rtDW.jrveltrtha" , "rtDW.afqavbs5ty"
, "rtDW.eidamkhewj" , "rtDW.dazeyaom3l" , "rtDW.hpsposfxjp" ,
"rtDW.achc50k0kr" , "rtDW.h2kosmawcp" , "rtDW.jklfnyaqcu" , "rtDW.bl1p0blo4b"
, "rtDW.ahczbduber" , "rtDW.mehfzxnojj" , "rtDW.bxfujbkphp" ,
"rtDW.jcgpwdcw13" , "rtDW.adt2xe2pd0" , "rtDW.mijwxy1gfd" , "rtDW.ewfcczil0j"
, "rtDW.es3p4dnuna" , "rtDW.hr4s0kwfwa" , "rtDW.lfe1ibkwop" ,
"rtDW.m2jub0kxpz" , "rtDW.izid4kf2wl" , "rtDW.f5bd1tnerd" , "rtDW.aece3kamvy"
, "rtDW.fbu1o32502" , "rtDW.j3dn4gfhs1" , "rtDW.hfhvsoe1hu" ,
"rtDW.ezpzvynldc" , "rtDW.jddr3btzwa" , "rtDW.m0i1af3trd" , "rtDW.nssittgb5o"
, "rtDW.iwr1b2avuw" , "rtDW.kwrhw5www5" , "rtDW.hz35lsskp2" ,
"rtDW.jf03aj3gmd" , "rtDW.bf33xtbrhg" , "rtDW.itvjzmhcag" , "rtDW.ehwgl0hfyk"
, "rtDW.cmjzvpvpsf.j13iuzvksk" , "rtDW.jdw3pbikft.o3j2yaswp3" ,
"rtDW.hdzoplw4kn.o0iconal0v" , "rtDW.msxjrffonnn.o3j2yaswp3" ,
"rtDW.ggca33mvdun.o0iconal0v" , "rtDW.nrqkqpzimhq.j13iuzvksk" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 61 , rtdwDataFieldNames ) ;
volatile void * dwork_0 = reinterpret_cast < volatile void * > ( & ( rtDW .
bssa0c1myd ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 0 , (
const_cast < void * > ( dwork_0 ) ) , sizeof ( rtDW . bssa0c1myd ) ) ;
volatile void * dwork_1 = reinterpret_cast < volatile void * > ( & ( rtDW .
phadp4f3b4 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 1 , (
const_cast < void * > ( dwork_1 ) ) , sizeof ( rtDW . phadp4f3b4 ) ) ;
volatile void * dwork_2 = reinterpret_cast < volatile void * > ( & ( rtDW .
mse1diqmww ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 2 , (
const_cast < void * > ( dwork_2 ) ) , sizeof ( rtDW . mse1diqmww ) ) ;
volatile void * dwork_3 = reinterpret_cast < volatile void * > ( & ( rtDW .
bhmfx0qy3i ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 3 , (
const_cast < void * > ( dwork_3 ) ) , sizeof ( rtDW . bhmfx0qy3i ) ) ;
volatile void * dwork_4 = reinterpret_cast < volatile void * > ( & ( rtDW .
cmv1b20lsy ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 4 , (
const_cast < void * > ( dwork_4 ) ) , sizeof ( rtDW . cmv1b20lsy ) ) ;
volatile void * dwork_5 = reinterpret_cast < volatile void * > ( & ( rtDW .
lvp0eixlb4 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 5 , (
const_cast < void * > ( dwork_5 ) ) , sizeof ( rtDW . lvp0eixlb4 ) ) ;
volatile void * dwork_6 = reinterpret_cast < volatile void * > ( & ( rtDW .
kv1pa1ywzi ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 6 , (
const_cast < void * > ( dwork_6 ) ) , sizeof ( rtDW . kv1pa1ywzi ) ) ;
volatile void * dwork_7 = reinterpret_cast < volatile void * > ( & ( rtDW .
ij5krlemte ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 7 , (
const_cast < void * > ( dwork_7 ) ) , sizeof ( rtDW . ij5krlemte ) ) ;
volatile void * dwork_8 = reinterpret_cast < volatile void * > ( & ( rtDW .
h0tlb2kuwe ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 8 , (
const_cast < void * > ( dwork_8 ) ) , sizeof ( rtDW . h0tlb2kuwe ) ) ;
volatile void * dwork_9 = reinterpret_cast < volatile void * > ( & ( rtDW .
mj5evfwhzb ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 9 , (
const_cast < void * > ( dwork_9 ) ) , sizeof ( rtDW . mj5evfwhzb ) ) ;
volatile void * dwork_10 = reinterpret_cast < volatile void * > ( & ( rtDW .
ngqgrvp4ei ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 10 , (
const_cast < void * > ( dwork_10 ) ) , sizeof ( rtDW . ngqgrvp4ei ) ) ;
volatile void * dwork_11 = reinterpret_cast < volatile void * > ( & ( rtDW .
ajgpkfca1o ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 11 , (
const_cast < void * > ( dwork_11 ) ) , sizeof ( rtDW . ajgpkfca1o ) ) ;
volatile void * dwork_12 = reinterpret_cast < volatile void * > ( & ( rtDW .
ma103w0rl5 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 12 , (
const_cast < void * > ( dwork_12 ) ) , sizeof ( rtDW . ma103w0rl5 ) ) ;
volatile void * dwork_13 = reinterpret_cast < volatile void * > ( & ( rtDW .
ocb1qur2h1 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 13 , (
const_cast < void * > ( dwork_13 ) ) , sizeof ( rtDW . ocb1qur2h1 ) ) ;
volatile void * dwork_14 = reinterpret_cast < volatile void * > ( & ( rtDW .
d0nohml22r ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 14 , (
const_cast < void * > ( dwork_14 ) ) , sizeof ( rtDW . d0nohml22r ) ) ;
volatile void * dwork_15 = reinterpret_cast < volatile void * > ( & ( rtDW .
mzuvrrfieu ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 15 , (
const_cast < void * > ( dwork_15 ) ) , sizeof ( rtDW . mzuvrrfieu ) ) ;
volatile void * dwork_16 = reinterpret_cast < volatile void * > ( & ( rtDW .
d4whpythev ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 16 , (
const_cast < void * > ( dwork_16 ) ) , sizeof ( rtDW . d4whpythev ) ) ;
volatile void * dwork_17 = reinterpret_cast < volatile void * > ( & ( rtDW .
d4oxqhfhid ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 17 , (
const_cast < void * > ( dwork_17 ) ) , sizeof ( rtDW . d4oxqhfhid ) ) ;
volatile void * dwork_18 = reinterpret_cast < volatile void * > ( & ( rtDW .
jrveltrtha ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 18 , (
const_cast < void * > ( dwork_18 ) ) , sizeof ( rtDW . jrveltrtha ) ) ;
volatile void * dwork_19 = reinterpret_cast < volatile void * > ( & ( rtDW .
afqavbs5ty ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 19 , (
const_cast < void * > ( dwork_19 ) ) , sizeof ( rtDW . afqavbs5ty ) ) ;
volatile void * dwork_20 = reinterpret_cast < volatile void * > ( & ( rtDW .
eidamkhewj ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 20 , (
const_cast < void * > ( dwork_20 ) ) , sizeof ( rtDW . eidamkhewj ) ) ;
volatile void * dwork_21 = reinterpret_cast < volatile void * > ( & ( rtDW .
dazeyaom3l ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 21 , (
const_cast < void * > ( dwork_21 ) ) , sizeof ( rtDW . dazeyaom3l ) ) ;
volatile void * dwork_22 = reinterpret_cast < volatile void * > ( & ( rtDW .
hpsposfxjp ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 22 , (
const_cast < void * > ( dwork_22 ) ) , sizeof ( rtDW . hpsposfxjp ) ) ;
volatile void * dwork_23 = reinterpret_cast < volatile void * > ( & ( rtDW .
achc50k0kr ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 23 , (
const_cast < void * > ( dwork_23 ) ) , sizeof ( rtDW . achc50k0kr ) ) ;
volatile void * dwork_24 = reinterpret_cast < volatile void * > ( & ( rtDW .
h2kosmawcp ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 24 , (
const_cast < void * > ( dwork_24 ) ) , sizeof ( rtDW . h2kosmawcp ) ) ;
volatile void * dwork_25 = reinterpret_cast < volatile void * > ( & ( rtDW .
jklfnyaqcu ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 25 , (
const_cast < void * > ( dwork_25 ) ) , sizeof ( rtDW . jklfnyaqcu ) ) ;
volatile void * dwork_26 = reinterpret_cast < volatile void * > ( & ( rtDW .
bl1p0blo4b ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 26 , (
const_cast < void * > ( dwork_26 ) ) , sizeof ( rtDW . bl1p0blo4b ) ) ;
volatile void * dwork_27 = reinterpret_cast < volatile void * > ( & ( rtDW .
ahczbduber ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 27 , (
const_cast < void * > ( dwork_27 ) ) , sizeof ( rtDW . ahczbduber ) ) ;
volatile void * dwork_28 = reinterpret_cast < volatile void * > ( & ( rtDW .
mehfzxnojj ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 28 , (
const_cast < void * > ( dwork_28 ) ) , sizeof ( rtDW . mehfzxnojj ) ) ;
volatile void * dwork_29 = reinterpret_cast < volatile void * > ( & ( rtDW .
bxfujbkphp ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 29 , (
const_cast < void * > ( dwork_29 ) ) , sizeof ( rtDW . bxfujbkphp ) ) ;
volatile void * dwork_30 = reinterpret_cast < volatile void * > ( & ( rtDW .
jcgpwdcw13 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 30 , (
const_cast < void * > ( dwork_30 ) ) , sizeof ( rtDW . jcgpwdcw13 ) ) ;
volatile void * dwork_31 = reinterpret_cast < volatile void * > ( & ( rtDW .
adt2xe2pd0 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 31 , (
const_cast < void * > ( dwork_31 ) ) , sizeof ( rtDW . adt2xe2pd0 ) ) ;
volatile void * dwork_32 = reinterpret_cast < volatile void * > ( & ( rtDW .
mijwxy1gfd ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 32 , (
const_cast < void * > ( dwork_32 ) ) , sizeof ( rtDW . mijwxy1gfd ) ) ;
volatile void * dwork_33 = reinterpret_cast < volatile void * > ( & ( rtDW .
ewfcczil0j ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 33 , (
const_cast < void * > ( dwork_33 ) ) , sizeof ( rtDW . ewfcczil0j ) ) ;
volatile void * dwork_34 = reinterpret_cast < volatile void * > ( & ( rtDW .
es3p4dnuna ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 34 , (
const_cast < void * > ( dwork_34 ) ) , sizeof ( rtDW . es3p4dnuna ) ) ;
volatile void * dwork_35 = reinterpret_cast < volatile void * > ( & ( rtDW .
hr4s0kwfwa ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 35 , (
const_cast < void * > ( dwork_35 ) ) , sizeof ( rtDW . hr4s0kwfwa ) ) ;
volatile void * dwork_36 = reinterpret_cast < volatile void * > ( & ( rtDW .
lfe1ibkwop ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 36 , (
const_cast < void * > ( dwork_36 ) ) , sizeof ( rtDW . lfe1ibkwop ) ) ;
volatile void * dwork_37 = reinterpret_cast < volatile void * > ( & ( rtDW .
m2jub0kxpz ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 37 , (
const_cast < void * > ( dwork_37 ) ) , sizeof ( rtDW . m2jub0kxpz ) ) ;
volatile void * dwork_38 = reinterpret_cast < volatile void * > ( & ( rtDW .
izid4kf2wl ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 38 , (
const_cast < void * > ( dwork_38 ) ) , sizeof ( rtDW . izid4kf2wl ) ) ;
volatile void * dwork_39 = reinterpret_cast < volatile void * > ( & ( rtDW .
f5bd1tnerd ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 39 , (
const_cast < void * > ( dwork_39 ) ) , sizeof ( rtDW . f5bd1tnerd ) ) ;
volatile void * dwork_40 = reinterpret_cast < volatile void * > ( & ( rtDW .
aece3kamvy ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 40 , (
const_cast < void * > ( dwork_40 ) ) , sizeof ( rtDW . aece3kamvy ) ) ;
volatile void * dwork_41 = reinterpret_cast < volatile void * > ( & ( rtDW .
fbu1o32502 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 41 , (
const_cast < void * > ( dwork_41 ) ) , sizeof ( rtDW . fbu1o32502 ) ) ;
volatile void * dwork_42 = reinterpret_cast < volatile void * > ( & ( rtDW .
j3dn4gfhs1 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 42 , (
const_cast < void * > ( dwork_42 ) ) , sizeof ( rtDW . j3dn4gfhs1 ) ) ;
volatile void * dwork_43 = reinterpret_cast < volatile void * > ( & ( rtDW .
hfhvsoe1hu ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 43 , (
const_cast < void * > ( dwork_43 ) ) , sizeof ( rtDW . hfhvsoe1hu ) ) ;
volatile void * dwork_44 = reinterpret_cast < volatile void * > ( & ( rtDW .
ezpzvynldc ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 44 , (
const_cast < void * > ( dwork_44 ) ) , sizeof ( rtDW . ezpzvynldc ) ) ;
volatile void * dwork_45 = reinterpret_cast < volatile void * > ( & ( rtDW .
jddr3btzwa ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 45 , (
const_cast < void * > ( dwork_45 ) ) , sizeof ( rtDW . jddr3btzwa ) ) ;
volatile void * dwork_46 = reinterpret_cast < volatile void * > ( & ( rtDW .
m0i1af3trd ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 46 , (
const_cast < void * > ( dwork_46 ) ) , sizeof ( rtDW . m0i1af3trd ) ) ;
volatile void * dwork_47 = reinterpret_cast < volatile void * > ( & ( rtDW .
nssittgb5o ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 47 , (
const_cast < void * > ( dwork_47 ) ) , sizeof ( rtDW . nssittgb5o ) ) ;
volatile void * dwork_48 = reinterpret_cast < volatile void * > ( & ( rtDW .
iwr1b2avuw ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 48 , (
const_cast < void * > ( dwork_48 ) ) , sizeof ( rtDW . iwr1b2avuw ) ) ;
volatile void * dwork_49 = reinterpret_cast < volatile void * > ( & ( rtDW .
kwrhw5www5 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 49 , (
const_cast < void * > ( dwork_49 ) ) , sizeof ( rtDW . kwrhw5www5 ) ) ;
volatile void * dwork_50 = reinterpret_cast < volatile void * > ( & ( rtDW .
hz35lsskp2 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 50 , (
const_cast < void * > ( dwork_50 ) ) , sizeof ( rtDW . hz35lsskp2 ) ) ;
volatile void * dwork_51 = reinterpret_cast < volatile void * > ( & ( rtDW .
jf03aj3gmd ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 51 , (
const_cast < void * > ( dwork_51 ) ) , sizeof ( rtDW . jf03aj3gmd ) ) ;
volatile void * dwork_52 = reinterpret_cast < volatile void * > ( & ( rtDW .
bf33xtbrhg ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 52 , (
const_cast < void * > ( dwork_52 ) ) , sizeof ( rtDW . bf33xtbrhg ) ) ;
volatile void * dwork_53 = reinterpret_cast < volatile void * > ( & ( rtDW .
itvjzmhcag ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 53 , (
const_cast < void * > ( dwork_53 ) ) , sizeof ( rtDW . itvjzmhcag ) ) ;
volatile void * dwork_54 = reinterpret_cast < volatile void * > ( & ( rtDW .
ehwgl0hfyk ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 54 , (
const_cast < void * > ( dwork_54 ) ) , sizeof ( rtDW . ehwgl0hfyk ) ) ;
volatile void * dwork_55 = reinterpret_cast < volatile void * > ( & ( rtDW .
cmjzvpvpsf . j13iuzvksk ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 ,
55 , ( const_cast < void * > ( dwork_55 ) ) , sizeof ( rtDW . cmjzvpvpsf .
j13iuzvksk ) ) ; volatile void * dwork_56 = reinterpret_cast < volatile void
* > ( & ( rtDW . jdw3pbikft . o3j2yaswp3 ) ) ; mr_modPSK_cacheDataAsMxArray (
rtdwData , 0 , 56 , ( const_cast < void * > ( dwork_56 ) ) , sizeof ( rtDW .
jdw3pbikft . o3j2yaswp3 ) ) ; volatile void * dwork_57 = reinterpret_cast <
volatile void * > ( & ( rtDW . hdzoplw4kn . o0iconal0v ) ) ;
mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const_cast < void * > (
dwork_57 ) ) , sizeof ( rtDW . hdzoplw4kn . o0iconal0v ) ) ; volatile void *
dwork_58 = reinterpret_cast < volatile void * > ( & ( rtDW . msxjrffonnn .
o3j2yaswp3 ) ) ; mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 58 , (
const_cast < void * > ( dwork_58 ) ) , sizeof ( rtDW . msxjrffonnn .
o3j2yaswp3 ) ) ; volatile void * dwork_59 = reinterpret_cast < volatile void
* > ( & ( rtDW . ggca33mvdun . o0iconal0v ) ) ; mr_modPSK_cacheDataAsMxArray
( rtdwData , 0 , 59 , ( const_cast < void * > ( dwork_59 ) ) , sizeof ( rtDW
. ggca33mvdun . o0iconal0v ) ) ; volatile void * dwork_60 = reinterpret_cast
< volatile void * > ( & ( rtDW . nrqkqpzimhq . j13iuzvksk ) ) ;
mr_modPSK_cacheDataAsMxArray ( rtdwData , 0 , 60 , ( const_cast < void * > (
dwork_60 ) ) , sizeof ( rtDW . nrqkqpzimhq . j13iuzvksk ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; }
mr_modPSK_cacheDataAsMxArray ( ssDW , 0 , 2 , ( const void * ) & ( rtPrevZCX
) , sizeof ( rtPrevZCX ) ) ; return ssDW ; } void mr_modPSK_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_modPSK_restoreDataFromMxArray ( ( void
* ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ; volatile void * dwork_0 =
reinterpret_cast < volatile void * > ( & ( rtDW . bssa0c1myd ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_0 ) ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . bssa0c1myd ) ) ; volatile void * dwork_1 =
reinterpret_cast < volatile void * > ( & ( rtDW . phadp4f3b4 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_1 ) ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . phadp4f3b4 ) ) ; volatile void * dwork_2 =
reinterpret_cast < volatile void * > ( & ( rtDW . mse1diqmww ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_2 ) ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . mse1diqmww ) ) ; volatile void * dwork_3 =
reinterpret_cast < volatile void * > ( & ( rtDW . bhmfx0qy3i ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_3 ) ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . bhmfx0qy3i ) ) ; volatile void * dwork_4 =
reinterpret_cast < volatile void * > ( & ( rtDW . cmv1b20lsy ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_4 ) ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . cmv1b20lsy ) ) ; volatile void * dwork_5 =
reinterpret_cast < volatile void * > ( & ( rtDW . lvp0eixlb4 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_5 ) ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . lvp0eixlb4 ) ) ; volatile void * dwork_6 =
reinterpret_cast < volatile void * > ( & ( rtDW . kv1pa1ywzi ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_6 ) ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . kv1pa1ywzi ) ) ; volatile void * dwork_7 =
reinterpret_cast < volatile void * > ( & ( rtDW . ij5krlemte ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_7 ) ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . ij5krlemte ) ) ; volatile void * dwork_8 =
reinterpret_cast < volatile void * > ( & ( rtDW . h0tlb2kuwe ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_8 ) ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . h0tlb2kuwe ) ) ; volatile void * dwork_9 =
reinterpret_cast < volatile void * > ( & ( rtDW . mj5evfwhzb ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_9 ) ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . mj5evfwhzb ) ) ; volatile void * dwork_10
= reinterpret_cast < volatile void * > ( & ( rtDW . ngqgrvp4ei ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_10 ) ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . ngqgrvp4ei ) ) ; volatile void * dwork_11
= reinterpret_cast < volatile void * > ( & ( rtDW . ajgpkfca1o ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_11 ) ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . ajgpkfca1o ) ) ; volatile void * dwork_12
= reinterpret_cast < volatile void * > ( & ( rtDW . ma103w0rl5 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_12 ) ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . ma103w0rl5 ) ) ; volatile void * dwork_13
= reinterpret_cast < volatile void * > ( & ( rtDW . ocb1qur2h1 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_13 ) ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . ocb1qur2h1 ) ) ; volatile void * dwork_14
= reinterpret_cast < volatile void * > ( & ( rtDW . d0nohml22r ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_14 ) ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . d0nohml22r ) ) ; volatile void * dwork_15
= reinterpret_cast < volatile void * > ( & ( rtDW . mzuvrrfieu ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_15 ) ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . mzuvrrfieu ) ) ; volatile void * dwork_16
= reinterpret_cast < volatile void * > ( & ( rtDW . d4whpythev ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_16 ) ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . d4whpythev ) ) ; volatile void * dwork_17
= reinterpret_cast < volatile void * > ( & ( rtDW . d4oxqhfhid ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_17 ) ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . d4oxqhfhid ) ) ; volatile void * dwork_18
= reinterpret_cast < volatile void * > ( & ( rtDW . jrveltrtha ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_18 ) ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . jrveltrtha ) ) ; volatile void * dwork_19
= reinterpret_cast < volatile void * > ( & ( rtDW . afqavbs5ty ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_19 ) ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . afqavbs5ty ) ) ; volatile void * dwork_20
= reinterpret_cast < volatile void * > ( & ( rtDW . eidamkhewj ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_20 ) ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . eidamkhewj ) ) ; volatile void * dwork_21
= reinterpret_cast < volatile void * > ( & ( rtDW . dazeyaom3l ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_21 ) ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . dazeyaom3l ) ) ; volatile void * dwork_22
= reinterpret_cast < volatile void * > ( & ( rtDW . hpsposfxjp ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_22 ) ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . hpsposfxjp ) ) ; volatile void * dwork_23
= reinterpret_cast < volatile void * > ( & ( rtDW . achc50k0kr ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_23 ) ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . achc50k0kr ) ) ; volatile void * dwork_24
= reinterpret_cast < volatile void * > ( & ( rtDW . h2kosmawcp ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_24 ) ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . h2kosmawcp ) ) ; volatile void * dwork_25
= reinterpret_cast < volatile void * > ( & ( rtDW . jklfnyaqcu ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_25 ) ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . jklfnyaqcu ) ) ; volatile void * dwork_26
= reinterpret_cast < volatile void * > ( & ( rtDW . bl1p0blo4b ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_26 ) ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . bl1p0blo4b ) ) ; volatile void * dwork_27
= reinterpret_cast < volatile void * > ( & ( rtDW . ahczbduber ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_27 ) ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . ahczbduber ) ) ; volatile void * dwork_28
= reinterpret_cast < volatile void * > ( & ( rtDW . mehfzxnojj ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_28 ) ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . mehfzxnojj ) ) ; volatile void * dwork_29
= reinterpret_cast < volatile void * > ( & ( rtDW . bxfujbkphp ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_29 ) ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . bxfujbkphp ) ) ; volatile void * dwork_30
= reinterpret_cast < volatile void * > ( & ( rtDW . jcgpwdcw13 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_30 ) ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . jcgpwdcw13 ) ) ; volatile void * dwork_31
= reinterpret_cast < volatile void * > ( & ( rtDW . adt2xe2pd0 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_31 ) ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . adt2xe2pd0 ) ) ; volatile void * dwork_32
= reinterpret_cast < volatile void * > ( & ( rtDW . mijwxy1gfd ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_32 ) ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . mijwxy1gfd ) ) ; volatile void * dwork_33
= reinterpret_cast < volatile void * > ( & ( rtDW . ewfcczil0j ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_33 ) ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . ewfcczil0j ) ) ; volatile void * dwork_34
= reinterpret_cast < volatile void * > ( & ( rtDW . es3p4dnuna ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_34 ) ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . es3p4dnuna ) ) ; volatile void * dwork_35
= reinterpret_cast < volatile void * > ( & ( rtDW . hr4s0kwfwa ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_35 ) ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . hr4s0kwfwa ) ) ; volatile void * dwork_36
= reinterpret_cast < volatile void * > ( & ( rtDW . lfe1ibkwop ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_36 ) ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . lfe1ibkwop ) ) ; volatile void * dwork_37
= reinterpret_cast < volatile void * > ( & ( rtDW . m2jub0kxpz ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_37 ) ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . m2jub0kxpz ) ) ; volatile void * dwork_38
= reinterpret_cast < volatile void * > ( & ( rtDW . izid4kf2wl ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_38 ) ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . izid4kf2wl ) ) ; volatile void * dwork_39
= reinterpret_cast < volatile void * > ( & ( rtDW . f5bd1tnerd ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_39 ) ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . f5bd1tnerd ) ) ; volatile void * dwork_40
= reinterpret_cast < volatile void * > ( & ( rtDW . aece3kamvy ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_40 ) ) ,
rtdwData , 0 , 40 , sizeof ( rtDW . aece3kamvy ) ) ; volatile void * dwork_41
= reinterpret_cast < volatile void * > ( & ( rtDW . fbu1o32502 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_41 ) ) ,
rtdwData , 0 , 41 , sizeof ( rtDW . fbu1o32502 ) ) ; volatile void * dwork_42
= reinterpret_cast < volatile void * > ( & ( rtDW . j3dn4gfhs1 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_42 ) ) ,
rtdwData , 0 , 42 , sizeof ( rtDW . j3dn4gfhs1 ) ) ; volatile void * dwork_43
= reinterpret_cast < volatile void * > ( & ( rtDW . hfhvsoe1hu ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_43 ) ) ,
rtdwData , 0 , 43 , sizeof ( rtDW . hfhvsoe1hu ) ) ; volatile void * dwork_44
= reinterpret_cast < volatile void * > ( & ( rtDW . ezpzvynldc ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_44 ) ) ,
rtdwData , 0 , 44 , sizeof ( rtDW . ezpzvynldc ) ) ; volatile void * dwork_45
= reinterpret_cast < volatile void * > ( & ( rtDW . jddr3btzwa ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_45 ) ) ,
rtdwData , 0 , 45 , sizeof ( rtDW . jddr3btzwa ) ) ; volatile void * dwork_46
= reinterpret_cast < volatile void * > ( & ( rtDW . m0i1af3trd ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_46 ) ) ,
rtdwData , 0 , 46 , sizeof ( rtDW . m0i1af3trd ) ) ; volatile void * dwork_47
= reinterpret_cast < volatile void * > ( & ( rtDW . nssittgb5o ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_47 ) ) ,
rtdwData , 0 , 47 , sizeof ( rtDW . nssittgb5o ) ) ; volatile void * dwork_48
= reinterpret_cast < volatile void * > ( & ( rtDW . iwr1b2avuw ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_48 ) ) ,
rtdwData , 0 , 48 , sizeof ( rtDW . iwr1b2avuw ) ) ; volatile void * dwork_49
= reinterpret_cast < volatile void * > ( & ( rtDW . kwrhw5www5 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_49 ) ) ,
rtdwData , 0 , 49 , sizeof ( rtDW . kwrhw5www5 ) ) ; volatile void * dwork_50
= reinterpret_cast < volatile void * > ( & ( rtDW . hz35lsskp2 ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_50 ) ) ,
rtdwData , 0 , 50 , sizeof ( rtDW . hz35lsskp2 ) ) ; volatile void * dwork_51
= reinterpret_cast < volatile void * > ( & ( rtDW . jf03aj3gmd ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_51 ) ) ,
rtdwData , 0 , 51 , sizeof ( rtDW . jf03aj3gmd ) ) ; volatile void * dwork_52
= reinterpret_cast < volatile void * > ( & ( rtDW . bf33xtbrhg ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_52 ) ) ,
rtdwData , 0 , 52 , sizeof ( rtDW . bf33xtbrhg ) ) ; volatile void * dwork_53
= reinterpret_cast < volatile void * > ( & ( rtDW . itvjzmhcag ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_53 ) ) ,
rtdwData , 0 , 53 , sizeof ( rtDW . itvjzmhcag ) ) ; volatile void * dwork_54
= reinterpret_cast < volatile void * > ( & ( rtDW . ehwgl0hfyk ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_54 ) ) ,
rtdwData , 0 , 54 , sizeof ( rtDW . ehwgl0hfyk ) ) ; volatile void * dwork_55
= reinterpret_cast < volatile void * > ( & ( rtDW . cmjzvpvpsf . j13iuzvksk )
) ; mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_55 ) )
, rtdwData , 0 , 55 , sizeof ( rtDW . cmjzvpvpsf . j13iuzvksk ) ) ; volatile
void * dwork_56 = reinterpret_cast < volatile void * > ( & ( rtDW .
jdw3pbikft . o3j2yaswp3 ) ) ; mr_modPSK_restoreDataFromMxArray ( ( const_cast
< void * > ( dwork_56 ) ) , rtdwData , 0 , 56 , sizeof ( rtDW . jdw3pbikft .
o3j2yaswp3 ) ) ; volatile void * dwork_57 = reinterpret_cast < volatile void
* > ( & ( rtDW . hdzoplw4kn . o0iconal0v ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_57 ) ) ,
rtdwData , 0 , 57 , sizeof ( rtDW . hdzoplw4kn . o0iconal0v ) ) ; volatile
void * dwork_58 = reinterpret_cast < volatile void * > ( & ( rtDW .
msxjrffonnn . o3j2yaswp3 ) ) ; mr_modPSK_restoreDataFromMxArray ( (
const_cast < void * > ( dwork_58 ) ) , rtdwData , 0 , 58 , sizeof ( rtDW .
msxjrffonnn . o3j2yaswp3 ) ) ; volatile void * dwork_59 = reinterpret_cast <
volatile void * > ( & ( rtDW . ggca33mvdun . o0iconal0v ) ) ;
mr_modPSK_restoreDataFromMxArray ( ( const_cast < void * > ( dwork_59 ) ) ,
rtdwData , 0 , 59 , sizeof ( rtDW . ggca33mvdun . o0iconal0v ) ) ; volatile
void * dwork_60 = reinterpret_cast < volatile void * > ( & ( rtDW .
nrqkqpzimhq . j13iuzvksk ) ) ; mr_modPSK_restoreDataFromMxArray ( (
const_cast < void * > ( dwork_60 ) ) , rtdwData , 0 , 60 , sizeof ( rtDW .
nrqkqpzimhq . j13iuzvksk ) ) ; } mr_modPSK_restoreDataFromMxArray ( ( void *
) & ( rtPrevZCX ) , ssDW , 0 , 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_modPSK_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 5 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 5 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope" ,
} ; static const char * blockPath [ 5 ] = { "modPSK/Scope" ,
"modPSK/Receptor/Detector/Scope" ,
"modPSK/Receptor/Sincronismo de Trama/Scope1" ,
"modPSK/Receptor/Sincronismo de s&#xED;mbolo/Scope1" ,
"modPSK/Transmisor/Scope" , } ; static const int reason [ 5 ] = { 0 , 0 , 0 ,
0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 5 ; ++ ( subs [ 0 ] ) ) {
subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } extern "C" void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 22 ) ; ssSetNumPeriodicContStates ( rtS , 2 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 4 ) ; ssSetNumBlocks ( rtS , 180 ) ;
ssSetNumBlockIO ( rtS , 77 ) ; ssSetNumBlockParams ( rtS , 1336 ) ; } extern
"C" void MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0
) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.0001 )
; ssSetSampleTime ( rtS , 3 , 1.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; } extern "C" void raccel_set_checksum ( )
{ ssSetChecksumVal ( rtS , 0 , 3134493899U ) ; ssSetChecksumVal ( rtS , 1 ,
3043254526U ) ; ssSetChecksumVal ( rtS , 2 , 4272357070U ) ; ssSetChecksumVal
( rtS , 3 , 1867159465U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
extern "C" SimStruct * raccel_register_model ( ssExecutionInfo *
executionInfo ) { static struct _ssMdlInfo mdlInfo ; ssSetMdlInfoPtr ( rtS ,
& mdlInfo ) ; ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( static_cast < void * > ( & rtB ) ) , 0 , sizeof ( B ) ) ;
{ rtB . ee42tgof2b = 0.0 ; rtB . o5tdwwqd3u = 0.0 ; rtB . p5kktr1wyk = 0.0 ;
rtB . mvhgymrwqe = 0.0 ; rtB . gqtvp2z5yf = 0.0 ; rtB . d4ytgmijes = 0.0 ;
rtB . ijwiii2est = 0.0 ; rtB . krai04vzyy = 0.0 ; rtB . exkkdo4tfp = 0.0 ;
rtB . fpr0eiute3 = 0.0 ; rtB . kqemtml2w3 = 0.0 ; rtB . da4cqxiizn = 0.0 ;
rtB . atcqfparc4 = 0.0 ; rtB . c2cnah1c34 = 0.0 ; rtB . ooymnwvq5a = 0.0 ;
rtB . ijuklwld0a = 0.0 ; rtB . nryqbxo330 = 0.0 ; rtB . hihmi4odjo = 0.0 ;
rtB . hcmaylj25a = 0.0 ; rtB . cyqeay1yht = 0.0 ; rtB . gmgguax0lb = 0.0 ;
rtB . e0stmf0wje = 0.0 ; rtB . ggvs3qvpfu = 0.0 ; rtB . mdt0d44sb1 = 0.0 ;
rtB . kxicx45q5w = 0.0 ; rtB . i0rkndmb13 = 0.0 ; rtB . owsmsehx52 = 0.0 ;
rtB . nsdd2hdqf1 = 0.0 ; rtB . a34p2x24w2 = 0.0 ; rtB . jyhhxwku5j = 0.0 ;
rtB . jers21a5nu = 0.0 ; rtB . fpmqgmj2cy = 0.0 ; rtB . gnebrkauvk = 0.0 ;
rtB . jkw11eafiz = 0.0 ; rtB . acvegdxqsb = 0.0 ; rtB . c1quq2kkeo = 0.0 ;
rtB . bqly4iysyb = 0.0 ; rtB . apaian0okb = 0.0 ; rtB . c1co2zjsgy = 0.0 ;
rtB . ktfxpbuyoi = 0.0 ; rtB . max2gpqnqf = 0.0 ; rtB . ewn2wlainw = 0.0 ;
rtB . jxbxouhvpz = 0.0 ; rtB . m0n2ncikto = 0.0 ; rtB . blc3ahlqoa = 0.0 ;
rtB . n2wkjomta0 = 0.0 ; rtB . f14htfpour = 0.0 ; rtB . k3ehqfnhji = 0.0 ;
rtB . dxkeuerubi = 0.0 ; rtB . e2pyl4rib3 = 0.0 ; rtB . nnbbyhuwe5 = 0.0 ;
rtB . pjddsfuka3 = 0.0 ; rtB . gpdt1s5m43 = 0.0 ; rtB . df1ir0te5a = 0.0 ;
rtB . nag5slvt33 = 0.0 ; rtB . fxorr2mhne [ 0 ] = 0.0 ; rtB . fxorr2mhne [ 1
] = 0.0 ; rtB . nhjc2m3cbx [ 0 ] = 0.0 ; rtB . nhjc2m3cbx [ 1 ] = 0.0 ; rtB .
ap3kp501sl [ 0 ] = 0.0 ; rtB . ap3kp501sl [ 1 ] = 0.0 ; rtB . nylejvpk25 =
0.0 ; rtB . g5n3z2eyy3 = 0.0 ; rtB . cmjzvpvpsf . olytfz4wp1 = 0.0 ; rtB .
nrqkqpzimhq . olytfz4wp1 = 0.0 ; } } { real_T * x = ( real_T * ) & rtX ;
ssSetContStates ( rtS , x ) ; ( void ) memset ( static_cast < void * > ( x )
, 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork
( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; rtDW .
bssa0c1myd = 0.0 ; rtDW . phadp4f3b4 = 0.0 ; rtDW . mse1diqmww = 0.0 ; rtDW .
bhmfx0qy3i = 0.0 ; rtDW . cmv1b20lsy = 0.0 ; rtDW . lvp0eixlb4 = 0.0 ; rtDW .
kv1pa1ywzi . modelTStart = 0.0 ; rtDW . ij5krlemte . modelTStart = 0.0 ; rtDW
. h0tlb2kuwe . modelTStart = 0.0 ; rtDW . mj5evfwhzb . modelTStart = 0.0 ;
rtDW . ngqgrvp4ei . modelTStart = 0.0 ; rtDW . ajgpkfca1o . modelTStart = 0.0
; rtDW . ma103w0rl5 . modelTStart = 0.0 ; rtDW . ocb1qur2h1 . modelTStart =
0.0 ; rtDW . d0nohml22r . modelTStart = 0.0 ; rtDW . mzuvrrfieu . modelTStart
= 0.0 ; rtDW . d4whpythev . modelTStart = 0.0 ; rtDW . d4oxqhfhid .
modelTStart = 0.0 ; rtDW . jrveltrtha . modelTStart = 0.0 ; } { static
DataTypeTransInfo dtInfo ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo
. numDataTypes = 20 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ;
dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } modPSK_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"modPSK" ) ; ssSetPath ( rtS , "modPSK" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 0.12000000000000001 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 4 , 4 , 1 , 1 , 8 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 4 , 4 , 1 , 1 , 8 , 1 , 1 , 1
, 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = {
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "modPSK/Transmisor/Analog\nFilter Design" ,
"modPSK/Receptor/Sincronismo de portadora/Analog\nFilter Design" ,
"modPSK/Receptor/Correlación/Integrator" ,
 "modPSK/Receptor/Sincronismo de símbolo/Continuous-Time\nVCO/Modulo \nIntegrator/Modulo\nIntegrator"
, "modPSK/Receptor/Correlación/Analog\nFilter Design" ,
 "modPSK/Receptor/Sincronismo de portadora/\nVCO/Modulo \nIntegrator/Modulo\nIntegrator"
, "modPSK/Receptor/Sincronismo de portadora/Integrator" ,
"modPSK/Receptor/Sincronismo de símbolo/Integrator1" ,
"modPSK/Receptor/Sincronismo de símbolo/Integrator" } ; static const char_T
* rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0
, SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 ,
6 , 7 , 8 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 9 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 9 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . emjc3fqnss [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . cyh0kmfhle [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . owcac5vhsm ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . pokwk5dsee ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . bqamom4kaa [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . e1epvwdkhs ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . dhvzxe4g3s ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . gc00zq2jpx ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . e1jmtpc2vb ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ;
ssSetPeriodicContStateIndices ( rtS , rtPeriodicIndX ) ; ( void ) memset (
static_cast < void * > ( rtPeriodicIndX ) , 0 , 2 * sizeof ( int_T ) ) ;
ssSetPeriodicContStateRanges ( rtS , rtPeriodicRngX ) ; ( void ) memset (
static_cast < void * > ( rtPeriodicRngX ) , 0 , 4 * sizeof ( real_T ) ) ; } {
static ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 22 ] ;
static real_T absTol [ 22 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 22 ] = { 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U } ; static real_T contStateJacPerturbBoundMinVec [ 22 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 22 ] ; static uint8_T zcAttributes [ 18 ] =
{ ( 0x80 | ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
0xc0 | ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( 0xc0 | ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( 0x80 | ZC_EVENT_ALL_DN ) , ( 0xc0 |
ZC_EVENT_ALL_UP ) , ( 0xc0 | ZC_EVENT_ALL_DN ) , ( 0xc0 | ZC_EVENT_ALL_UP ) ,
( 0xc0 | ZC_EVENT_ALL_UP ) , ( 0xc0 | ZC_EVENT_ALL_UP ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 5 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . df1ir0te5a ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . gpdt1s5m43 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . ktfxpbuyoi ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . bqly4iysyb ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . p5kktr1wyk ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i <
22 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 3.3333333333333335E-7 ) ; ssSetSolverMaxOrder ( rtS
, - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , (
NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 )
; ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
5 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 18 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 11 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . hvekerdey5 = UNINITIALIZED_ZCSIG ; rtPrevZCX .
gzsjhe3j3h = UNINITIALIZED_ZCSIG ; rtPrevZCX . cqolqyndhe =
UNINITIALIZED_ZCSIG ; rtPrevZCX . f2owmsmztm = POS_ZCSIG ; rtPrevZCX .
cmf42mhbgp = UNINITIALIZED_ZCSIG ; rtPrevZCX . lzwwl1jhb5 = ZERO_ZCSIG ;
rtPrevZCX . mexgwhndus = UNINITIALIZED_ZCSIG ; rtPrevZCX . cmjzvpvpsf .
pbvwazbpud = UNINITIALIZED_ZCSIG ; rtPrevZCX . nrqkqpzimhq . pbvwazbpud =
UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS , 0 , 3134493899U ) ;
ssSetChecksumVal ( rtS , 1 , 3043254526U ) ; ssSetChecksumVal ( rtS , 2 ,
4272357070U ) ; ssSetChecksumVal ( rtS , 3 , 1867159465U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 13 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . nrqkqpzimhq . j13iuzvksk ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . hfhvsoe1hu ; systemRan [ 3 ] = ( sysRanDType * ) &
rtDW . j3dn4gfhs1 ; systemRan [ 4 ] = ( sysRanDType * ) & rtDW . fbu1o32502 ;
systemRan [ 5 ] = ( sysRanDType * ) & rtDW . aece3kamvy ; systemRan [ 6 ] = (
sysRanDType * ) & rtDW . ggca33mvdun . o0iconal0v ; systemRan [ 7 ] = (
sysRanDType * ) & rtDW . msxjrffonnn . o3j2yaswp3 ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . hdzoplw4kn . o0iconal0v ; systemRan [ 9 ] = (
sysRanDType * ) & rtDW . jdw3pbikft . o3j2yaswp3 ; systemRan [ 10 ] = (
sysRanDType * ) & rtDW . f5bd1tnerd ; systemRan [ 11 ] = ( sysRanDType * ) &
rtDW . cmjzvpvpsf . j13iuzvksk ; systemRan [ 12 ] = ( sysRanDType * ) & rtDW
. izid4kf2wl ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_modPSK_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_modPSK_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_modPSK_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
extern "C" { const int_T gblParameterTuningTid = 4 ; } void
MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID4 ( tid ) ; }
