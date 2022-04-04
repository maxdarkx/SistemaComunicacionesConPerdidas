#include "original.h"
#include "rtwtypes.h"
#include "original_private.h"
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "original_capi.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "original_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.7 (R2022a) 13-Nov-2021" ; void
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
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; PeriodicIndX rtPeriodicIndX ;
PeriodicRngX rtPeriodicRngX ; static SimStruct model_S ; SimStruct * const
rtS = & model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
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
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void jmit3vr51d (
lp5ztxd20y * localB , ehm3sgzrjf * localP ) { localB -> lzgwbwuubl = localP
-> _Y0 ; } void mnr2afncj2 ( SimStruct * rtS_e , real_T pdfdnwdcb4 , real_T
cagtww4tts , lp5ztxd20y * localB , mem4sagm4y * localDW , fgwwoolgrw *
localZCE ) { ZCEventType zcEvent ; if ( ssIsModeUpdateTimeStep ( rtS_e ) ) {
zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & localZCE -> ohewvvpbtd , (
pdfdnwdcb4 ) ) ; if ( zcEvent != NO_ZCEVENT ) { localB -> lzgwbwuubl =
cagtww4tts ; localDW -> bmw2hixe1f = 4 ; } } } void hpvik1zrta ( hh5f121zsr *
localB , bgrpsvzorg * localP ) { localB -> o3dp55eklq = localP -> OUT_Y0 ; }
void mjqilvpgl5 ( SimStruct * rtS_m , real_T c0gmvzy4fh , real_T l22fp4ju4c ,
real_T kmw1tns1nf , hh5f121zsr * localB , pzawjmwk3y * localDW ) { if (
c0gmvzy4fh > 0.0 ) { localB -> o3dp55eklq = ( kmw1tns1nf > l22fp4ju4c ) ; if
( ssIsModeUpdateTimeStep ( rtS_m ) ) { srUpdateBC ( localDW -> fulyjjxmue ) ;
} } } void h3xdm3koso ( dufzjkshrc * localB , o0jdhwlf44 * localP ) { localB
-> elss3awww2 = localP -> OUT_Y0 ; } void ligjpsfhvt ( SimStruct * rtS_e ,
real_T czgu4rdmf0 , real_T o01sow1ps0 , real_T hah1ogqu2h , dufzjkshrc *
localB , d51rut2e0g * localDW ) { if ( czgu4rdmf0 > 0.0 ) { localB ->
elss3awww2 = ( o01sow1ps0 > hah1ogqu2h ) ; if ( ssIsModeUpdateTimeStep (
rtS_e ) ) { srUpdateBC ( localDW -> idqwe24upn ) ; } } } void MdlInitialize (
void ) { int_T is ; rtX . egzjqzicdq [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . benb2xcfzc [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . egzjqzicdq [ 1 ] = rtP
. AnalogFilterDesign_InitialCondition ; rtX . benb2xcfzc [ 1 ] = rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . egzjqzicdq [ 2 ] = rtP
. AnalogFilterDesign_InitialCondition ; rtX . benb2xcfzc [ 2 ] = rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . egzjqzicdq [ 3 ] = rtP
. AnalogFilterDesign_InitialCondition ; rtX . benb2xcfzc [ 3 ] = rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . ng4tabqmtd = rtP .
Integrator_IC ; rtX . moligukihq = rtP . ModuloIntegrator_IC ; for ( is = 0 ;
is < 8 ; is ++ ) { rtX . dbfnj3ttmr [ is ] = rtP .
AnalogFilterDesign_InitialCondition_gxj5snzs0v ; } rtDW . cqe343kytb = rtP .
Memory_InitialCondition ; rtDW . mvcna0flrg = rtP . Monostable_ic ; rtDW .
eflcwal1mu = rtP . SampleandHold_ic ; rtX . gjwqeukkq3 = rtP .
ModuloIntegrator_IC_g1vo2kap3u ; rtX . lhjxqs0ce0 = rtP .
Integrator_IC_oxpanuusbm ; rtDW . isfqm5nn3q = rtP .
TmpLatchAtDFlipFlopInport1_InitialCondition ; rtX . nppgwv3zah = rtP .
Integrator1_IC ; rtDW . nbeww3raq3 = rtP . Memory_InitialCondition_oggd2r4odw
; rtDW . oquiajmyfp = rtP . Monostable1_ic ; rtDW . ltasifvkde = rtP .
SampleHold_ic ; rtX . my5bz0mxqu = rtP . Integrator_IC_a5b0eygpkp ; rtDW .
g22bx3mwrj = rtP . Memory_InitialCondition_ljulw4woig ; rtDW . iksurbbs2u =
rtP . Monostable3_ic ; rtDW . nkspyzjmj0 = rtP . SampleHold_ic_cvpetr2ktj ;
jmit3vr51d ( & rtB . mnr2afncj2u , & rtP . mnr2afncj2u ) ; rtB . grenet1so1 =
rtP . OUT_Y0_gbikirmbla ; rtB . gzklf0ilir = rtP . OUT_Y0 ; rtB . gpjz2pf2n0
= rtP . Out1_Y0 ; rtB . nlky1z3g2k = rtP . Q_Y0 ; rtB . ov3s20wyhx = rtP .
Q_Y0_ngs1cr5pq5 ; h3xdm3koso ( & rtB . ligjpsfhvtg , & rtP . ligjpsfhvtg ) ;
hpvik1zrta ( & rtB . mjqilvpgl54 , & rtP . mjqilvpgl54 ) ; h3xdm3koso ( & rtB
. llvx0kbake , & rtP . llvx0kbake ) ; hpvik1zrta ( & rtB . iewfgzwb31 , & rtP
. iewfgzwb31 ) ; rtB . bnrnxdd0vt = rtP . _Y0 ; jmit3vr51d ( & rtB .
o0byjwoyow , & rtP . o0byjwoyow ) ; { int_T rootPeriodicContStateIndices [ 2
] = { 9 , 18 } ; real_T rootPeriodicContStateRanges [ 4 ] = { 0.0 , 1.0 , 0.0
, 1.0 } ; ( void ) memcpy ( ( void * ) rtPeriodicIndX ,
rootPeriodicContStateIndices , 2 * sizeof ( int_T ) ) ; ( void ) memcpy ( (
void * ) rtPeriodicRngX , rootPeriodicContStateRanges , 4 * sizeof ( real_T )
) ; } } void MdlStart ( void ) { { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "In1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "In1" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"original/Triggered To Workspace/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "In1" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dmu42kigql . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "5fb55a34-e7b5-4e9f-b1fa-6c185d7ac3e3" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . dmu42kigql . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . dmu42kigql . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . dmu42kigql . AQHandles , "Triggered" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . dmu42kigql .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dmu42kigql . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
dmu42kigql . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
dmu42kigql . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . dmu42kigql . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Rx" ) ; sdiRegisterWksVariable ( rtDW . dmu42kigql . AQHandles , varName ,
"array2D" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"original/Receptor/Sincronismo de s&#xED;mbolo/Sign" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . h3b22feudi . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "f453babb-7d79-4740-976d-2b86b4c66b8d" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . h3b22feudi . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . h3b22feudi . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . h3b22feudi . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . h3b22feudi .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . h3b22feudi . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
h3b22feudi . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
h3b22feudi . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "s" ; fromwksInfo -> origDataTypeId = 0
; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints = 1124 ;
fromwksInfo -> time = ( NULL ) ; rtDW . g24kh0yl0d . TimePtr = fromwksInfo ->
time ; rtDW . g24kh0yl0d . DataPtr = fromwksInfo -> data ; rtDW . g24kh0yl0d
. RSimInfoPtr = fromwksInfo ; } rtDW . kqimps20tr . PrevIndex = - 1 ; } {
char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf (
2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } rtDW
. bijp5lznr0 . Tail = 0 ; rtDW . bijp5lznr0 . Head = 0 ; rtDW . bijp5lznr0 .
Last = 0 ; rtDW . bijp5lznr0 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
iufdazrcci . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf (
ptrKey , "original/Canal/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
iufdazrcci . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . gozlgoace0 . Tail = 0 ; rtDW . gozlgoace0 . Head = 0 ; rtDW .
gozlgoace0 . Last = 0 ; rtDW . gozlgoace0 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput_m3b1lj5lye ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; rtDW . d3b3zasoji . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; sprintf ( ptrKey ,
"original/Receptor/Correlación/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
d3b3zasoji . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . jukyp4co3s . Tail = 0 ; rtDW . jukyp4co3s . Head = 0 ; rtDW .
jukyp4co3s . Last = 0 ; rtDW . jukyp4co3s . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay12_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . fqpjvnu3on . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay12_TUbuffer%d" , 0 )
; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
fqpjvnu3on . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . dwcos053mm . Tail = 0 ; rtDW . dwcos053mm . Head = 0 ; rtDW .
dwcos053mm . Last = 0 ; rtDW . dwcos053mm . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . ii1qwqcizu . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay2_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
ii1qwqcizu . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . ar3vwuqqcr . Tail = 0 ; rtDW . ar3vwuqqcr . Head = 0 ; rtDW .
ar3vwuqqcr . Last = 0 ; rtDW . ar3vwuqqcr . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . gbr1avzpo5 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay1_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
gbr1avzpo5 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . pbrpegxnve . Tail = 0 ; rtDW . pbrpegxnve . Head = 0 ; rtDW .
pbrpegxnve . Last = 0 ; rtDW . pbrpegxnve . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay4_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . e02rtjhnng . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay4_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
e02rtjhnng . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . otun30mznk . Tail = 0 ; rtDW . otun30mznk . Head = 0 ; rtDW .
otun30mznk . Last = 0 ; rtDW . otun30mznk . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay3_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . hmhofpz1ew . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay3_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
hmhofpz1ew . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . etsjn5fqxr . Tail = 0 ; rtDW . etsjn5fqxr . Head = 0 ; rtDW .
etsjn5fqxr . Last = 0 ; rtDW . etsjn5fqxr . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay6_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . audlhahb3y . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay6_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
audlhahb3y . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . dm031mdhzh . Tail = 0 ; rtDW . dm031mdhzh . Head = 0 ; rtDW .
dm031mdhzh . Last = 0 ; rtDW . dm031mdhzh . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay5_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . c0b2si44of . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay5_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
c0b2si44of . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . dwt1logpyt . Tail = 0 ; rtDW . dwt1logpyt . Head = 0 ; rtDW .
dwt1logpyt . Last = 0 ; rtDW . dwt1logpyt . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay8_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . px5wrgqdsn . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay8_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
px5wrgqdsn . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . olvi0wrke2 . Tail = 0 ; rtDW . olvi0wrke2 . Head = 0 ; rtDW .
olvi0wrke2 . Last = 0 ; rtDW . olvi0wrke2 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay7_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . dqimiih00v . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay7_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
dqimiih00v . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . h0xflbr2r2 . Tail = 0 ; rtDW . h0xflbr2r2 . Head = 0 ; rtDW .
h0xflbr2r2 . Last = 0 ; rtDW . h0xflbr2r2 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay9_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . hyxywufgvp . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay9_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
hyxywufgvp . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . o5k3wqz1te . Tail = 0 ; rtDW . o5k3wqz1te . Head = 0 ; rtDW .
o5k3wqz1te . Last = 0 ; rtDW . o5k3wqz1te . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay11_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . ibeq1uqak3 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay11_TUbuffer%d" , 0 )
; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
ibeq1uqak3 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T
iqs0v33w40 ; real_T bdyc1bm3bz ; real_T bmpdsnlvwo ; real_T jve4swfk5m ;
real_T o4jhd51y0k ; real_T chxvpheep2 ; int32_T ci ; uint32_T ri ; boolean_T
eihbrr5yaz ; ZCEventType zcEvent ; srClearBC ( rtDW . mnr2afncj2u .
bmw2hixe1f ) ; srClearBC ( rtDW . ork2mu3aqa ) ; srClearBC ( rtDW .
iuuqkwmjrb ) ; srClearBC ( rtDW . kg30gk0yon ) ; srClearBC ( rtDW .
kudt5h2w0b ) ; srClearBC ( rtDW . mjqilvpgl54 . fulyjjxmue ) ; srClearBC (
rtDW . ligjpsfhvtg . idqwe24upn ) ; srClearBC ( rtDW . mtstnsjsji ) ;
srClearBC ( rtDW . n1tmln402w ) ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { {
int_T currIndex = rtDW . kqimps20tr . PrevIndex + 1 ; real_T * pDataValues =
( real_T * ) rtDW . g24kh0yl0d . DataPtr ; int numPoints ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . g24kh0yl0d . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; if ( currIndex < numPoints ) { pDataValues +=
currIndex ; rtB . pczptaloqn = * pDataValues ; } else { rtB . pczptaloqn =
0.0 ; } rtDW . kqimps20tr . PrevIndex = currIndex ; } } rtB . lyy2rgzssu =
0.0 ; for ( ri = rtP . AnalogFilterDesign_C_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign_C_jc [ 1U ] ; ri ++ ) { rtB . lyy2rgzssu += rtP .
AnalogFilterDesign_C_pr * rtX . egzjqzicdq [ 0U ] ; } for ( ri = rtP .
AnalogFilterDesign_C_jc [ 1U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 2U ] ;
ri ++ ) { rtB . lyy2rgzssu += rtP . AnalogFilterDesign_C_pr * rtX .
egzjqzicdq [ 1U ] ; } for ( ri = rtP . AnalogFilterDesign_C_jc [ 2U ] ; ri <
rtP . AnalogFilterDesign_C_jc [ 3U ] ; ri ++ ) { rtB . lyy2rgzssu += rtP .
AnalogFilterDesign_C_pr * rtX . egzjqzicdq [ 2U ] ; } for ( ri = rtP .
AnalogFilterDesign_C_jc [ 3U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 4U ] ;
ri ++ ) { rtB . lyy2rgzssu += rtP . AnalogFilterDesign_C_pr * rtX .
egzjqzicdq [ 3U ] ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
iufdazrcci . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
tMinusDelay = simTime - rtP . Retraso_Canal ; iqs0v33w40 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . bijp5lznr0 .
CircularBufSize , & rtDW . bijp5lznr0 . Last , rtDW . bijp5lznr0 . Tail ,
rtDW . bijp5lznr0 . Head , rtP . TransportDelay_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . bijp5lznr0 .
CircularBufSize ) [ rtDW . bijp5lznr0 . Head ] == ssGetT ( rtS ) ) ) ) ; }
rtB . b4klkr2hpb = 1.0 / rtP . Att_Volt_Canal * iqs0v33w40 ; chxvpheep2 = 0.0
; for ( ri = rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 0U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 1U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . benb2xcfzc [ 0U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 1U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 2U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . benb2xcfzc [ 1U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 2U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 3U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . benb2xcfzc [ 2U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 3U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 4U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . benb2xcfzc [ 3U ] ; } rtB .
mttr3remqe = rtP . Amplitud / rtP . Att_Volt_Canal * chxvpheep2 ; { real_T *
* uBuffer = ( real_T * * ) & rtDW . d3b3zasoji . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay_Delay ; rtB . azmfpdpfhr = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , rtDW . gozlgoace0 . CircularBufSize , & rtDW . gozlgoace0
. Last , rtDW . gozlgoace0 . Tail , rtDW . gozlgoace0 . Head , rtP .
TransportDelay_InitOutput_m3b1lj5lye , 1 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ( * uBuffer + rtDW . gozlgoace0 . CircularBufSize ) [ rtDW .
gozlgoace0 . Head ] == ssGetT ( rtS ) ) ) ) ; } if ( ssIsModeUpdateTimeStep (
rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX .
i2q0ncrpsr , ( rtB . azmfpdpfhr ) ) ; if ( zcEvent != NO_ZCEVENT ) { rtX .
ng4tabqmtd = rtP . Integrator_IC ; ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtB . b4dgdwqfvr = rtX . ng4tabqmtd ; } else { rtB . b4dgdwqfvr =
rtX . ng4tabqmtd ; } rtB . apurb3sda3 = muDoubleScalarCos ( rtX . moligukihq
* 6.2831853071795862 + 5.497787143782138 ) ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { if ( rtB . apurb3sda3 > 0.0 ) { rtDW . nl35cfre3r = 1 ; } else if ( rtB
. apurb3sda3 < 0.0 ) { rtDW . nl35cfre3r = - 1 ; } else { rtDW . nl35cfre3r =
0 ; } rtB . c5jqurmpza = rtDW . nl35cfre3r ; mnr2afncj2 ( rtS , rtB .
c5jqurmpza , rtB . b4dgdwqfvr , & rtB . mnr2afncj2u , & rtDW . mnr2afncj2u ,
& rtPrevZCX . mnr2afncj2u ) ; rtB . hssaqyb021 = muDoubleScalarSign ( rtB .
mnr2afncj2u . lzgwbwuubl ) ; rtB . nqw3knpw3y = ( rtB . hssaqyb021 + rtP .
AddConstant_Bias ) * rtP . Multiply_Gain ; } { real_T * * uBuffer = ( real_T
* * ) & rtDW . fqpjvnu3on . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ; rtB . nqqxqhj4uh =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . jukyp4co3s .
CircularBufSize , & rtDW . jukyp4co3s . Last , rtDW . jukyp4co3s . Tail ,
rtDW . jukyp4co3s . Head , rtP . TransportDelay12_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . jukyp4co3s
. CircularBufSize ) [ rtDW . jukyp4co3s . Head ] == ssGetT ( rtS ) ) ) ) ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) {
zcEvent = rt_ZCFcn ( FALLING_ZERO_CROSSING , & rtPrevZCX . gta1yuk1am , ( rtB
. nqqxqhj4uh ) ) ; if ( zcEvent != NO_ZCEVENT ) { { if ( rtDW . dmu42kigql .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . dmu42kigql .
AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . nqw3knpw3y + 0 ) ;
} } rtDW . n1tmln402w = 4 ; } } rtB . aibuxow2f4 = 0.0 ; for ( ci = 0 ; ci <
8 ; ci ++ ) { for ( ri = rtP . AnalogFilterDesign_C_jc_d2bgogmalx [ (
uint32_T ) ci ] ; ri < rtP . AnalogFilterDesign_C_jc_d2bgogmalx [ ci + 1U ] ;
ri ++ ) { rtB . aibuxow2f4 += rtP . AnalogFilterDesign_C_pr_e3t31otpuq * rtX
. dbfnj3ttmr [ ( uint32_T ) ci ] ; } } rtB . i0c1bgukye = rtB . b4klkr2hpb *
rtB . mttr3remqe ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fewalbo2ov =
rtB . hssaqyb021 * rtP . Constant1_Value ; } { real_T * * uBuffer = ( real_T
* * ) & rtDW . ii1qwqcizu . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ; rtB . azchjpegsm =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . dwcos053mm .
CircularBufSize , & rtDW . dwcos053mm . Last , rtDW . dwcos053mm . Tail ,
rtDW . dwcos053mm . Head , rtP . TransportDelay2_InitOutput , 1 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . dwcos053mm .
CircularBufSize ) [ rtDW . dwcos053mm . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . gbr1avzpo5 . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . ihiwfhuo0a = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . ar3vwuqqcr . CircularBufSize , & rtDW . ar3vwuqqcr . Last , rtDW .
ar3vwuqqcr . Tail , rtDW . ar3vwuqqcr . Head , rtP .
TransportDelay1_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . ar3vwuqqcr . CircularBufSize ) [ rtDW . ar3vwuqqcr .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . e02rtjhnng . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . hkn2g3gvsz =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . pbrpegxnve .
CircularBufSize , & rtDW . pbrpegxnve . Last , rtDW . pbrpegxnve . Tail ,
rtDW . pbrpegxnve . Head , rtP . TransportDelay4_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . pbrpegxnve .
CircularBufSize ) [ rtDW . pbrpegxnve . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . hmhofpz1ew . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . ntkisuxn2g = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . otun30mznk . CircularBufSize , & rtDW . otun30mznk . Last , rtDW .
otun30mznk . Tail , rtDW . otun30mznk . Head , rtP .
TransportDelay3_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . otun30mznk . CircularBufSize ) [ rtDW . otun30mznk .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . audlhahb3y . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . m4m214ovbs =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . etsjn5fqxr .
CircularBufSize , & rtDW . etsjn5fqxr . Last , rtDW . etsjn5fqxr . Tail ,
rtDW . etsjn5fqxr . Head , rtP . TransportDelay6_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . etsjn5fqxr .
CircularBufSize ) [ rtDW . etsjn5fqxr . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . c0b2si44of . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . pndfq3ndef = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . dm031mdhzh . CircularBufSize , & rtDW . dm031mdhzh . Last , rtDW .
dm031mdhzh . Tail , rtDW . dm031mdhzh . Head , rtP .
TransportDelay5_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . dm031mdhzh . CircularBufSize ) [ rtDW . dm031mdhzh .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . px5wrgqdsn . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . oxkodghnh1 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . dwt1logpyt .
CircularBufSize , & rtDW . dwt1logpyt . Last , rtDW . dwt1logpyt . Tail ,
rtDW . dwt1logpyt . Head , rtP . TransportDelay8_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . dwt1logpyt .
CircularBufSize ) [ rtDW . dwt1logpyt . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . dqimiih00v . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . g53czseiki = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . olvi0wrke2 . CircularBufSize , & rtDW . olvi0wrke2 . Last , rtDW .
olvi0wrke2 . Tail , rtDW . olvi0wrke2 . Head , rtP .
TransportDelay7_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . olvi0wrke2 . CircularBufSize ) [ rtDW . olvi0wrke2 .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . hyxywufgvp . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . icz5jiqa5l =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . h0xflbr2r2 .
CircularBufSize , & rtDW . h0xflbr2r2 . Last , rtDW . h0xflbr2r2 . Tail ,
rtDW . h0xflbr2r2 . Head , rtP . TransportDelay9_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . h0xflbr2r2 .
CircularBufSize ) [ rtDW . h0xflbr2r2 . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . ibeq1uqak3 . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
bdyc1bm3bz = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW .
o5k3wqz1te . CircularBufSize , & rtDW . o5k3wqz1te . Last , rtDW . o5k3wqz1te
. Tail , rtDW . o5k3wqz1te . Head , rtP . TransportDelay11_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . o5k3wqz1te
. CircularBufSize ) [ rtDW . o5k3wqz1te . Head ] == ssGetT ( rtS ) ) ) ) ; }
rtB . l0uo4a4mr4 = ( ( ( ( ( ( ( ( ( rtB . azchjpegsm * rtP . Constant2_Value
+ rtB . fewalbo2ov ) + rtB . ihiwfhuo0a * rtP . Constant3_Value ) + rtB .
hkn2g3gvsz * rtP . Constant4_Value ) + rtB . ntkisuxn2g * rtP .
Constant5_Value ) + rtB . m4m214ovbs * rtP . Constant6_Value ) + rtB .
pndfq3ndef * rtP . Constant7_Value ) + rtB . oxkodghnh1 * rtP .
Constant8_Value ) + rtB . g53czseiki * rtP . Constant9_Value ) + rtB .
icz5jiqa5l * rtP . Constant10_Value ) + bdyc1bm3bz * rtP . Constant13_Value ;
if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . fgt0gfkzzs = ( rtB .
l0uo4a4mr4 >= rtP . Switch_Threshold ) ; } if ( rtDW . fgt0gfkzzs ) { rtB .
ntk0mkheco = rtP . Constant15_Value ; } else { rtB . ntk0mkheco = rtP .
Constant14_Value ; } rtB . fqfddfhgnv = ssGetT ( rtS ) ; rtB . orn3venhnk = (
rtB . ntk0mkheco != 0.0 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB .
f4wxz52mc5 [ 0 ] > 0.0 ) { rtB . grenet1so1 = ( ( int32_T ) rtDW . mvcna0flrg
< ( int32_T ) rtB . orn3venhnk ) ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . kg30gk0yon ) ; } } if ( rtB . f4wxz52mc5 [ 1 ] > 0.0 ) {
rtB . gzklf0ilir = ( ( int32_T ) rtDW . mvcna0flrg > ( int32_T ) rtB .
orn3venhnk ) ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
iuuqkwmjrb ) ; } } eihbrr5yaz = ( rtB . grenet1so1 || rtB . gzklf0ilir ) ;
rtB . azngqgys3a = ( ( ! rtDW . cqe343kytb ) && eihbrr5yaz ) ; rtB .
k4j5el1r4t = rtDW . eflcwal1mu ; rtB . bz0pvs5lfr = 1000.0 * rtP . Tb -
2.2204460492503131E-16 ; } if ( rtB . azngqgys3a ) { rtB . ac5onrei0k = rtB .
fqfddfhgnv ; } else { rtB . ac5onrei0k = rtB . k4j5el1r4t ; } rtB .
dmtaqaxly0 = rtB . ac5onrei0k + rtB . bz0pvs5lfr ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . al2bessz01 = ( rtB
. dmtaqaxly0 > rtB . fqfddfhgnv ) ; } rtB . mmbwdvbds0 = rtDW . al2bessz01 ;
} rtB . abjvxeqou3 = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
if ( ssIsModeUpdateTimeStep ( rtS ) ) { if ( eihbrr5yaz && ( rtPrevZCX .
lopkxabcwq != POS_ZCSIG ) ) { rtB . gpjz2pf2n0 = rtB . abjvxeqou3 ; rtDW .
ork2mu3aqa = 4 ; } rtPrevZCX . lopkxabcwq = eihbrr5yaz ; } rtB . ie0mnn5bjz =
rtB . gpjz2pf2n0 + rtP . Constant_Value ; if ( ssIsModeUpdateTimeStep ( rtS )
) { rtDW . luewrj1rxn = ( rtB . ie0mnn5bjz > rtB . abjvxeqou3 ) ; } } if (
rtB . mmbwdvbds0 ) { rtB . ngmqsygkuj = rtB . c5jqurmpza ; } else { rtB .
ngmqsygkuj = rtP . Constant16_Value ; } rtB . kpyjbyqhnn = muDoubleScalarCos
( rtX . gjwqeukkq3 * 6.2831853071795862 ) ; chxvpheep2 = rtP . Att_Volt_Canal
/ rtP . Amplitud * rtB . b4klkr2hpb ; chxvpheep2 = chxvpheep2 * chxvpheep2 *
rtB . kpyjbyqhnn ; bmpdsnlvwo = rtP . R2 / rtP . R1 * chxvpheep2 + rtX .
lhjxqs0ce0 ; rtB . nqzijf3v2s = rtP . Kv / 6.2831853071795862 * bmpdsnlvwo +
2.0 * rtP . Frec_port ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { eihbrr5yaz =
rtDW . isfqm5nn3q ; if ( rtB . kpyjbyqhnn > 0.0 ) { rtDW . kp4ub4djpq = 1 ; }
else if ( rtB . kpyjbyqhnn < 0.0 ) { rtDW . kp4ub4djpq = - 1 ; } else { rtDW
. kp4ub4djpq = 0 ; } zcEvent = NO_ZCEVENT ; if ( ssIsModeUpdateTimeStep ( rtS
) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX . fueymmbsgp ,
( ( real_T ) rtDW . kp4ub4djpq ) ) ; } if ( rtP . Constant2_Value_mwviqzbxqh
> 0.0 ) { if ( ! rtDW . c01gnuxhwv ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} rtDW . c01gnuxhwv = true ; } if ( ssIsModeUpdateTimeStep ( rtS ) && (
zcEvent != NO_ZCEVENT ) ) { rtB . nlky1z3g2k = eihbrr5yaz ; rtB . ov3s20wyhx
= ! rtB . nlky1z3g2k ; rtDW . kudt5h2w0b = 4 ; } } else if ( rtDW .
c01gnuxhwv ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB .
nlky1z3g2k = rtP . Q_Y0 ; rtB . ov3s20wyhx = rtP . Q_Y0_ngs1cr5pq5 ; rtDW .
c01gnuxhwv = false ; } rtB . bzfqsaqdca = rtP . Constant6_Value_dkmziwbikw *
( real_T ) rtB . nlky1z3g2k + rtP . Constant5_Value_hu2bresth1 ; } rtB .
cdlxrrgn43 = 1.0 / ( rtP . R1 * rtP . C ) * chxvpheep2 ; rtB . majhbieqf2 =
rtP . Constant1_Value_hcjo4f4r5j * rtB . aibuxow2f4 ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( rtB . majhbieqf2 > 0.0 ) { rtDW . miaubkp1tz = 1 ; }
else if ( rtB . majhbieqf2 < 0.0 ) { rtDW . miaubkp1tz = - 1 ; } else { rtDW
. miaubkp1tz = 0 ; } rtB . mojdhi2f5w = rtDW . miaubkp1tz ; } if (
ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING
, & rtPrevZCX . mc53zk2efp , ( rtB . c5jqurmpza ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { rtX . nppgwv3zah = rtP . Integrator1_IC ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . myomqf4clw = rtX
. nppgwv3zah ; } else { rtB . myomqf4clw = rtX . nppgwv3zah ; } rtB .
cqgvyb1usr = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
jve4swfk5m = rtDW . oquiajmyfp ; ligjpsfhvt ( rtS , rtB . pyvoagmwyq [ 0 ] ,
rtB . c5jqurmpza , jve4swfk5m , & rtB . ligjpsfhvtg , & rtDW . ligjpsfhvtg )
; mjqilvpgl5 ( rtS , rtB . pyvoagmwyq [ 1 ] , rtB . c5jqurmpza , jve4swfk5m ,
& rtB . mjqilvpgl54 , & rtDW . mjqilvpgl54 ) ; rtB . ndzz4ltczv = ( ( ! rtDW
. nbeww3raq3 ) && ( rtB . ligjpsfhvtg . elss3awww2 || rtB . mjqilvpgl54 .
o3dp55eklq ) ) ; rtB . otmkurmb40 = rtDW . ltasifvkde ; } if ( rtB .
ndzz4ltczv ) { rtB . g1iqixqqbk = rtB . cqgvyb1usr ; } else { rtB .
g1iqixqqbk = rtB . otmkurmb40 ; } rtB . le03i4u1w1 = ( ( 1.0 - rtP . b ) /
rtP . Rb - 2.2204460492503131E-16 ) + rtB . g1iqixqqbk ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . gqsz4zovj0 =
( rtB . le03i4u1w1 > rtB . cqgvyb1usr ) ; } rtB . bik1lk5raz = rtDW .
gqsz4zovj0 ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) { eihbrr5yaz = ( ( ! rtB
. bik1lk5raz ) && ( rtPrevZCX . a40vve3elm != ZERO_ZCSIG ) ) ; rtPrevZCX .
a40vve3elm = rtB . bik1lk5raz ; if ( eihbrr5yaz ) { rtX . my5bz0mxqu = rtP .
Integrator_IC_a5b0eygpkp ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } rtB . dxkzb2shae = rtX . my5bz0mxqu ; } else { rtB . dxkzb2shae = rtX .
my5bz0mxqu ; } rtB . bcqstcbcss = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { o4jhd51y0k = rtDW . iksurbbs2u ; ligjpsfhvt ( rtS , rtB .
ppuci252pa [ 0 ] , rtB . c5jqurmpza , o4jhd51y0k , & rtB . llvx0kbake , &
rtDW . llvx0kbake ) ; mjqilvpgl5 ( rtS , rtB . ppuci252pa [ 1 ] , rtB .
c5jqurmpza , o4jhd51y0k , & rtB . iewfgzwb31 , & rtDW . iewfgzwb31 ) ; rtB .
elhj11vpue = ( ( ! rtDW . g22bx3mwrj ) && ( rtB . llvx0kbake . elss3awww2 ||
rtB . iewfgzwb31 . o3dp55eklq ) ) ; rtB . klpoi14tq3 = rtDW . nkspyzjmj0 ; }
if ( rtB . elhj11vpue ) { rtB . btco2hfhqs = rtB . bcqstcbcss ; } else { rtB
. btco2hfhqs = rtB . klpoi14tq3 ; } rtB . j5xzo5caz4 = ( rtP . b / rtP . Rb -
2.2204460492503131E-16 ) + rtB . btco2hfhqs ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . gywfygl1db = ( rtB .
j5xzo5caz4 > rtB . bcqstcbcss ) ; } rtB . pnc2oxbc5h = rtDW . gywfygl1db ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { if ( ( ! rtB . pnc2oxbc5h ) && (
rtPrevZCX . j44yq314nr != ZERO_ZCSIG ) ) { rtB . bnrnxdd0vt = rtB .
myomqf4clw ; rtDW . mtstnsjsji = 4 ; } rtPrevZCX . j44yq314nr = rtB .
pnc2oxbc5h ; } rtB . m2lqawkue3 = muDoubleScalarAbs ( rtB . bnrnxdd0vt ) ; }
if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . frfvjoiupy = ( rtB .
dxkzb2shae >= 0.0 ) ; } rtB . njbn3w11wn = rtB . m2lqawkue3 - ( rtDW .
frfvjoiupy > 0 ? rtB . dxkzb2shae : - rtB . dxkzb2shae ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { mnr2afncj2 ( rtS , rtB . c5jqurmpza , rtB . njbn3w11wn ,
& rtB . o0byjwoyow , & rtDW . o0byjwoyow , & rtPrevZCX . o0byjwoyow ) ; } if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . h3b22feudi . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . h3b22feudi . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . mojdhi2f5w + 0 ) ; } } rtB .
k3v5lqeyfa = rtP . kv2 * rtB . o0byjwoyow . lzgwbwuubl + rtP . Rb ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . ommuhpqjnr = rtP .
Multiply_Gain_ptvyavefxe * rtB . pczptaloqn + rtP .
AddConstant_Bias_ljcfbacsm3 ; } rtB . g2d1qhfmtb = ( muDoubleScalarSin (
6.2831853071795862 * rtP . Frec_port * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWave_Phase ) * rtP . Amplitud + rtP . SineWave_Bias ) * rtB . ommuhpqjnr
; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid ) { switch ( (
int32_T ) rtP . Constant1_Value_afssjxve00 ) { case 1 : rtB . f4wxz52mc5 [ 0
] = rtP . posedge_Value [ 0 ] ; rtB . f4wxz52mc5 [ 1 ] = rtP . posedge_Value
[ 1 ] ; break ; case 2 : rtB . f4wxz52mc5 [ 0 ] = rtP . negedge_Value [ 0 ] ;
rtB . f4wxz52mc5 [ 1 ] = rtP . negedge_Value [ 1 ] ; break ; default : rtB .
f4wxz52mc5 [ 0 ] = rtP . eitheredge_Value [ 0 ] ; rtB . f4wxz52mc5 [ 1 ] =
rtP . eitheredge_Value [ 1 ] ; break ; } switch ( ( int32_T ) rtP .
Monostable1_EdgeDetect ) { case 1 : rtB . pyvoagmwyq [ 0 ] = rtP .
posedge_Value_av2r5ustik [ 0 ] ; rtB . pyvoagmwyq [ 1 ] = rtP .
posedge_Value_av2r5ustik [ 1 ] ; break ; case 2 : rtB . pyvoagmwyq [ 0 ] =
rtP . negedge_Value_fef1hh2jz4 [ 0 ] ; rtB . pyvoagmwyq [ 1 ] = rtP .
negedge_Value_fef1hh2jz4 [ 1 ] ; break ; default : rtB . pyvoagmwyq [ 0 ] =
rtP . eitheredge_Value_nntils3rkv [ 0 ] ; rtB . pyvoagmwyq [ 1 ] = rtP .
eitheredge_Value_nntils3rkv [ 1 ] ; break ; } switch ( ( int32_T ) rtP .
Monostable3_EdgeDetect ) { case 1 : rtB . ppuci252pa [ 0 ] = rtP .
posedge_Value_j0croo5cnv [ 0 ] ; rtB . ppuci252pa [ 1 ] = rtP .
posedge_Value_j0croo5cnv [ 1 ] ; break ; case 2 : rtB . ppuci252pa [ 0 ] =
rtP . negedge_Value_lnmee3h1ob [ 0 ] ; rtB . ppuci252pa [ 1 ] = rtP .
negedge_Value_lnmee3h1ob [ 1 ] ; break ; default : rtB . ppuci252pa [ 0 ] =
rtP . eitheredge_Value_gsipsgs54b [ 0 ] ; rtB . ppuci252pa [ 1 ] = rtP .
eitheredge_Value_gsipsgs54b [ 1 ] ; break ; } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { { real_T * * uBuffer = ( real_T * * ) & rtDW .
iufdazrcci . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
bijp5lznr0 . Head = ( ( rtDW . bijp5lznr0 . Head < ( rtDW . bijp5lznr0 .
CircularBufSize - 1 ) ) ? ( rtDW . bijp5lznr0 . Head + 1 ) : 0 ) ; if ( rtDW
. bijp5lznr0 . Head == rtDW . bijp5lznr0 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . bijp5lznr0 . CircularBufSize , & rtDW
. bijp5lznr0 . Tail , & rtDW . bijp5lznr0 . Head , & rtDW . bijp5lznr0 . Last
, simTime - rtP . Retraso_Canal , uBuffer , ( boolean_T ) 0 , false , & rtDW
. bijp5lznr0 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Canal/Transport\nDelay_TUbuffer0" , ( void * * ) ( & uBuffer [ 0 ]
) , 2 * rtDW . bijp5lznr0 . CircularBufSize * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } ( * uBuffer + rtDW . bijp5lznr0 . CircularBufSize ) [ rtDW .
bijp5lznr0 . Head ] = simTime ; ( * uBuffer ) [ rtDW . bijp5lznr0 . Head ] =
rtB . lyy2rgzssu ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
d3b3zasoji . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
gozlgoace0 . Head = ( ( rtDW . gozlgoace0 . Head < ( rtDW . gozlgoace0 .
CircularBufSize - 1 ) ) ? ( rtDW . gozlgoace0 . Head + 1 ) : 0 ) ; if ( rtDW
. gozlgoace0 . Head == rtDW . gozlgoace0 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . gozlgoace0 . CircularBufSize , & rtDW
. gozlgoace0 . Tail , & rtDW . gozlgoace0 . Head , & rtDW . gozlgoace0 . Last
, simTime - rtP . TransportDelay_Delay , uBuffer , ( boolean_T ) 0 , false ,
& rtDW . gozlgoace0 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Correlación/Transport\nDelay_TUbuffer0" , ( void * * ) ( &
uBuffer [ 0 ] ) , 2 * rtDW . gozlgoace0 . CircularBufSize * sizeof ( real_T )
, ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . gozlgoace0 . CircularBufSize
) [ rtDW . gozlgoace0 . Head ] = simTime ; ( * uBuffer ) [ rtDW . gozlgoace0
. Head ] = rtB . c5jqurmpza ; } { real_T * * uBuffer = ( real_T * * ) & rtDW
. fqpjvnu3on . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
jukyp4co3s . Head = ( ( rtDW . jukyp4co3s . Head < ( rtDW . jukyp4co3s .
CircularBufSize - 1 ) ) ? ( rtDW . jukyp4co3s . Head + 1 ) : 0 ) ; if ( rtDW
. jukyp4co3s . Head == rtDW . jukyp4co3s . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . jukyp4co3s . CircularBufSize , & rtDW
. jukyp4co3s . Tail , & rtDW . jukyp4co3s . Head , & rtDW . jukyp4co3s . Last
, simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
jukyp4co3s . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay12_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . jukyp4co3s . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . jukyp4co3s
. CircularBufSize ) [ rtDW . jukyp4co3s . Head ] = simTime ; ( * uBuffer ) [
rtDW . jukyp4co3s . Head ] = rtB . ngmqsygkuj ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . ii1qwqcizu . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . dwcos053mm . Head = ( ( rtDW . dwcos053mm . Head < (
rtDW . dwcos053mm . CircularBufSize - 1 ) ) ? ( rtDW . dwcos053mm . Head + 1
) : 0 ) ; if ( rtDW . dwcos053mm . Head == rtDW . dwcos053mm . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . dwcos053mm . CircularBufSize , &
rtDW . dwcos053mm . Tail , & rtDW . dwcos053mm . Head , & rtDW . dwcos053mm .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
dwcos053mm . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay2_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . dwcos053mm . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . dwcos053mm .
CircularBufSize ) [ rtDW . dwcos053mm . Head ] = simTime ; ( * uBuffer ) [
rtDW . dwcos053mm . Head ] = rtB . hssaqyb021 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . gbr1avzpo5 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . ar3vwuqqcr . Head = ( ( rtDW . ar3vwuqqcr . Head < (
rtDW . ar3vwuqqcr . CircularBufSize - 1 ) ) ? ( rtDW . ar3vwuqqcr . Head + 1
) : 0 ) ; if ( rtDW . ar3vwuqqcr . Head == rtDW . ar3vwuqqcr . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ar3vwuqqcr . CircularBufSize , &
rtDW . ar3vwuqqcr . Tail , & rtDW . ar3vwuqqcr . Head , & rtDW . ar3vwuqqcr .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
ar3vwuqqcr . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay1_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . ar3vwuqqcr . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . ar3vwuqqcr .
CircularBufSize ) [ rtDW . ar3vwuqqcr . Head ] = simTime ; ( * uBuffer ) [
rtDW . ar3vwuqqcr . Head ] = rtB . azchjpegsm ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . e02rtjhnng . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . pbrpegxnve . Head = ( ( rtDW . pbrpegxnve . Head < (
rtDW . pbrpegxnve . CircularBufSize - 1 ) ) ? ( rtDW . pbrpegxnve . Head + 1
) : 0 ) ; if ( rtDW . pbrpegxnve . Head == rtDW . pbrpegxnve . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . pbrpegxnve . CircularBufSize , &
rtDW . pbrpegxnve . Tail , & rtDW . pbrpegxnve . Head , & rtDW . pbrpegxnve .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
pbrpegxnve . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay4_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . pbrpegxnve . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . pbrpegxnve .
CircularBufSize ) [ rtDW . pbrpegxnve . Head ] = simTime ; ( * uBuffer ) [
rtDW . pbrpegxnve . Head ] = rtB . ihiwfhuo0a ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . hmhofpz1ew . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . otun30mznk . Head = ( ( rtDW . otun30mznk . Head < (
rtDW . otun30mznk . CircularBufSize - 1 ) ) ? ( rtDW . otun30mznk . Head + 1
) : 0 ) ; if ( rtDW . otun30mznk . Head == rtDW . otun30mznk . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . otun30mznk . CircularBufSize , &
rtDW . otun30mznk . Tail , & rtDW . otun30mznk . Head , & rtDW . otun30mznk .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
otun30mznk . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay3_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . otun30mznk . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . otun30mznk .
CircularBufSize ) [ rtDW . otun30mznk . Head ] = simTime ; ( * uBuffer ) [
rtDW . otun30mznk . Head ] = rtB . hkn2g3gvsz ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . audlhahb3y . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . etsjn5fqxr . Head = ( ( rtDW . etsjn5fqxr . Head < (
rtDW . etsjn5fqxr . CircularBufSize - 1 ) ) ? ( rtDW . etsjn5fqxr . Head + 1
) : 0 ) ; if ( rtDW . etsjn5fqxr . Head == rtDW . etsjn5fqxr . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . etsjn5fqxr . CircularBufSize , &
rtDW . etsjn5fqxr . Tail , & rtDW . etsjn5fqxr . Head , & rtDW . etsjn5fqxr .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
etsjn5fqxr . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay6_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . etsjn5fqxr . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . etsjn5fqxr .
CircularBufSize ) [ rtDW . etsjn5fqxr . Head ] = simTime ; ( * uBuffer ) [
rtDW . etsjn5fqxr . Head ] = rtB . ntkisuxn2g ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . c0b2si44of . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . dm031mdhzh . Head = ( ( rtDW . dm031mdhzh . Head < (
rtDW . dm031mdhzh . CircularBufSize - 1 ) ) ? ( rtDW . dm031mdhzh . Head + 1
) : 0 ) ; if ( rtDW . dm031mdhzh . Head == rtDW . dm031mdhzh . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . dm031mdhzh . CircularBufSize , &
rtDW . dm031mdhzh . Tail , & rtDW . dm031mdhzh . Head , & rtDW . dm031mdhzh .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
dm031mdhzh . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay5_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . dm031mdhzh . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . dm031mdhzh .
CircularBufSize ) [ rtDW . dm031mdhzh . Head ] = simTime ; ( * uBuffer ) [
rtDW . dm031mdhzh . Head ] = rtB . m4m214ovbs ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . px5wrgqdsn . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . dwt1logpyt . Head = ( ( rtDW . dwt1logpyt . Head < (
rtDW . dwt1logpyt . CircularBufSize - 1 ) ) ? ( rtDW . dwt1logpyt . Head + 1
) : 0 ) ; if ( rtDW . dwt1logpyt . Head == rtDW . dwt1logpyt . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . dwt1logpyt . CircularBufSize , &
rtDW . dwt1logpyt . Tail , & rtDW . dwt1logpyt . Head , & rtDW . dwt1logpyt .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
dwt1logpyt . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay8_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . dwt1logpyt . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . dwt1logpyt .
CircularBufSize ) [ rtDW . dwt1logpyt . Head ] = simTime ; ( * uBuffer ) [
rtDW . dwt1logpyt . Head ] = rtB . pndfq3ndef ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . dqimiih00v . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . olvi0wrke2 . Head = ( ( rtDW . olvi0wrke2 . Head < (
rtDW . olvi0wrke2 . CircularBufSize - 1 ) ) ? ( rtDW . olvi0wrke2 . Head + 1
) : 0 ) ; if ( rtDW . olvi0wrke2 . Head == rtDW . olvi0wrke2 . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . olvi0wrke2 . CircularBufSize , &
rtDW . olvi0wrke2 . Tail , & rtDW . olvi0wrke2 . Head , & rtDW . olvi0wrke2 .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
olvi0wrke2 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay7_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . olvi0wrke2 . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . olvi0wrke2 .
CircularBufSize ) [ rtDW . olvi0wrke2 . Head ] = simTime ; ( * uBuffer ) [
rtDW . olvi0wrke2 . Head ] = rtB . oxkodghnh1 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . hyxywufgvp . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . h0xflbr2r2 . Head = ( ( rtDW . h0xflbr2r2 . Head < (
rtDW . h0xflbr2r2 . CircularBufSize - 1 ) ) ? ( rtDW . h0xflbr2r2 . Head + 1
) : 0 ) ; if ( rtDW . h0xflbr2r2 . Head == rtDW . h0xflbr2r2 . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . h0xflbr2r2 . CircularBufSize , &
rtDW . h0xflbr2r2 . Tail , & rtDW . h0xflbr2r2 . Head , & rtDW . h0xflbr2r2 .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
h0xflbr2r2 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay9_TUbuffer0" , ( void
* * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . h0xflbr2r2 . CircularBufSize * sizeof
( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . h0xflbr2r2 .
CircularBufSize ) [ rtDW . h0xflbr2r2 . Head ] = simTime ; ( * uBuffer ) [
rtDW . h0xflbr2r2 . Head ] = rtB . g53czseiki ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . ibeq1uqak3 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . o5k3wqz1te . Head = ( ( rtDW . o5k3wqz1te . Head < (
rtDW . o5k3wqz1te . CircularBufSize - 1 ) ) ? ( rtDW . o5k3wqz1te . Head + 1
) : 0 ) ; if ( rtDW . o5k3wqz1te . Head == rtDW . o5k3wqz1te . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . o5k3wqz1te . CircularBufSize , &
rtDW . o5k3wqz1te . Tail , & rtDW . o5k3wqz1te . Head , & rtDW . o5k3wqz1te .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
o5k3wqz1te . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"original/Receptor/Sincronismo de Trama/Transport\nDelay11_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . o5k3wqz1te . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . o5k3wqz1te
. CircularBufSize ) [ rtDW . o5k3wqz1te . Head ] = simTime ; ( * uBuffer ) [
rtDW . o5k3wqz1te . Head ] = rtB . icz5jiqa5l ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . cqe343kytb = rtB . mmbwdvbds0 ; rtDW . mvcna0flrg = rtB .
orn3venhnk ; rtDW . eflcwal1mu = rtB . ac5onrei0k ; rtDW . isfqm5nn3q = rtB .
ov3s20wyhx ; rtDW . nbeww3raq3 = rtB . bik1lk5raz ; rtDW . oquiajmyfp = rtB .
c5jqurmpza ; rtDW . ltasifvkde = rtB . g1iqixqqbk ; rtDW . g22bx3mwrj = rtB .
pnc2oxbc5h ; rtDW . iksurbbs2u = rtB . c5jqurmpza ; rtDW . nkspyzjmj0 = rtB .
btco2hfhqs ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID3 ( int_T tid )
{ UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot
; int_T is ; uint32_T ri ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot
-> egzjqzicdq [ 0 ] = 0.0 ; _rtXdot -> egzjqzicdq [ 1 ] = 0.0 ; _rtXdot ->
egzjqzicdq [ 2 ] = 0.0 ; _rtXdot -> egzjqzicdq [ 3 ] = 0.0 ; for ( ri = rtP .
AnalogFilterDesign_A_jc [ 0U ] ; ri < rtP . AnalogFilterDesign_A_jc [ 1U ] ;
ri ++ ) { _rtXdot -> egzjqzicdq [ rtP . AnalogFilterDesign_A_ir [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . egzjqzicdq [ 0U ] ; } for ( ri =
rtP . AnalogFilterDesign_A_jc [ 1U ] ; ri < rtP . AnalogFilterDesign_A_jc [
2U ] ; ri ++ ) { _rtXdot -> egzjqzicdq [ rtP . AnalogFilterDesign_A_ir [ ri ]
] += rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . egzjqzicdq [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc [ 2U ] ; ri < rtP .
AnalogFilterDesign_A_jc [ 3U ] ; ri ++ ) { _rtXdot -> egzjqzicdq [ rtP .
AnalogFilterDesign_A_ir [ ri ] ] += rtP . AnalogFilterDesign_A_pr [ ri ] *
rtX . egzjqzicdq [ 2U ] ; } for ( ri = rtP . AnalogFilterDesign_A_jc [ 3U ] ;
ri < rtP . AnalogFilterDesign_A_jc [ 4U ] ; ri ++ ) { _rtXdot -> egzjqzicdq [
rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP . AnalogFilterDesign_A_pr [ ri
] * rtX . egzjqzicdq [ 3U ] ; } for ( ri = rtP . AnalogFilterDesign_B_jc [ 0U
] ; ri < rtP . AnalogFilterDesign_B_jc [ 1U ] ; ri ++ ) { _rtXdot ->
egzjqzicdq [ rtP . AnalogFilterDesign_B_ir ] += rtP . AnalogFilterDesign_B_pr
* rtB . g2d1qhfmtb ; } _rtXdot -> benb2xcfzc [ 0 ] = 0.0 ; _rtXdot ->
benb2xcfzc [ 1 ] = 0.0 ; _rtXdot -> benb2xcfzc [ 2 ] = 0.0 ; _rtXdot ->
benb2xcfzc [ 3 ] = 0.0 ; for ( ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap
[ 0U ] ; ri < rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 1U ] ; ri ++ ) {
_rtXdot -> benb2xcfzc [ rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . benb2xcfzc [ 0U ] ; }
for ( ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 1U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 2U ] ; ri ++ ) { _rtXdot -> benb2xcfzc [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . benb2xcfzc [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 2U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 3U ] ; ri ++ ) { _rtXdot -> benb2xcfzc [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . benb2xcfzc [ 2U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 3U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 4U ] ; ri ++ ) { _rtXdot -> benb2xcfzc [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . benb2xcfzc [ 3U ] ; } for (
ri = rtP . AnalogFilterDesign_B_jc_nk0ranamkl [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc_nk0ranamkl [ 1U ] ; ri ++ ) { _rtXdot -> benb2xcfzc [
rtP . AnalogFilterDesign_B_ir_gklrfvy2xp ] += rtP .
AnalogFilterDesign_B_pr_om0jg41jmb * rtB . bzfqsaqdca ; } _rtXdot ->
ng4tabqmtd = rtB . aibuxow2f4 ; _rtXdot -> moligukihq = rtB . k3v5lqeyfa ;
for ( is = 0 ; is < 8 ; is ++ ) { _rtXdot -> dbfnj3ttmr [ is ] = 0.0 ; } for
( is = 0 ; is < 8 ; is ++ ) { for ( ri = rtP .
AnalogFilterDesign_A_jc_h5xar20tzm [ ( uint32_T ) is ] ; ri < rtP .
AnalogFilterDesign_A_jc_h5xar20tzm [ is + 1U ] ; ri ++ ) { _rtXdot ->
dbfnj3ttmr [ rtP . AnalogFilterDesign_A_ir_cx1zj2mhzp [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_f4zixacbw1 [ ri ] * rtX . dbfnj3ttmr [ ( uint32_T )
is ] ; } } for ( ri = rtP . AnalogFilterDesign_B_jc_acwf2d2gj0 [ 0U ] ; ri <
rtP . AnalogFilterDesign_B_jc_acwf2d2gj0 [ 1U ] ; ri ++ ) { _rtXdot ->
dbfnj3ttmr [ rtP . AnalogFilterDesign_B_ir_nneewrak4c ] += rtP .
AnalogFilterDesign_B_pr_by1sufu2fg * rtB . i0c1bgukye ; } _rtXdot ->
gjwqeukkq3 = rtB . nqzijf3v2s ; _rtXdot -> lhjxqs0ce0 = rtB . cdlxrrgn43 ;
_rtXdot -> nppgwv3zah = rtB . mojdhi2f5w ; _rtXdot -> my5bz0mxqu = rtB .
mojdhi2f5w ; } void MdlProjection ( void ) { } void MdlZeroCrossings ( void )
{ ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ;
_rtZCSV -> b31pbtdn2k = rtB . azmfpdpfhr ; _rtZCSV -> o3znflkpdp = rtB .
apurb3sda3 ; _rtZCSV -> b25cfon423 = rtB . nqqxqhj4uh ; _rtZCSV -> babbwy4ulx
= rtB . l0uo4a4mr4 - rtP . Switch_Threshold ; _rtZCSV -> b0wj3p5hwu = rtB .
dmtaqaxly0 - rtB . fqfddfhgnv ; _rtZCSV -> ocukxygk3c = rtB . ie0mnn5bjz -
rtB . abjvxeqou3 ; _rtZCSV -> ohbka3d3xa = rtB . kpyjbyqhnn ; _rtZCSV ->
cmos0jmlkz = rtB . majhbieqf2 ; _rtZCSV -> hp4mce0gfx = rtB . le03i4u1w1 -
rtB . cqgvyb1usr ; _rtZCSV -> gnqui0x0du = rtB . j5xzo5caz4 - rtB .
bcqstcbcss ; _rtZCSV -> bmo44x2usr = rtB . dxkzb2shae ; } void MdlTerminate (
void ) { rt_FREE ( rtDW . g24kh0yl0d . RSimInfoPtr ) ; rt_TDelayFreeBuf (
rtDW . iufdazrcci . TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW .
d3b3zasoji . TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . fqpjvnu3on .
TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . ii1qwqcizu . TUbufferPtrs [
0 ] ) ; rt_TDelayFreeBuf ( rtDW . gbr1avzpo5 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . e02rtjhnng . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . hmhofpz1ew . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . audlhahb3y . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . c0b2si44of . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . px5wrgqdsn . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . dqimiih00v . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . hyxywufgvp . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . ibeq1uqak3 . TUbufferPtrs [ 0 ] ) ; { if ( rtDW .
dmu42kigql . AQHandles ) { sdiTerminateStreaming ( & rtDW . dmu42kigql .
AQHandles ) ; } } { if ( rtDW . h3b22feudi . AQHandles ) {
sdiTerminateStreaming ( & rtDW . h3b22feudi . AQHandles ) ; } } } static void
mr_original_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_original_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_original_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_original_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_original_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_original_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_original_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_original_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_original_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_original_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_original_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_original_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_original_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_original_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_original_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_original_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_original_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix
( 1 , 1 , 3 , ssDWFieldNames ) ; mr_original_cacheDataAsMxArray ( ssDW , 0 ,
0 , ( const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char *
rtdwDataFieldNames [ 59 ] = { "rtDW.eflcwal1mu" , "rtDW.oquiajmyfp" ,
"rtDW.ltasifvkde" , "rtDW.iksurbbs2u" , "rtDW.nkspyzjmj0" , "rtDW.owd5cjyj4l"
, "rtDW.i4xfbt1z25" , "rtDW.ky1a3dnkiw" , "rtDW.fwikzb00to" ,
"rtDW.azfsgwj0il" , "rtDW.i30swi3eeg" , "rtDW.bjvck4ijez" , "rtDW.idakjgagwj"
, "rtDW.j0o0q4ccss" , "rtDW.jx0fvxr0vd" , "rtDW.moy4nejcr1" ,
"rtDW.pf1rurynfs" , "rtDW.brbjfuklas" , "rtDW.kqimps20tr" , "rtDW.bijp5lznr0"
, "rtDW.gozlgoace0" , "rtDW.jukyp4co3s" , "rtDW.dwcos053mm" ,
"rtDW.ar3vwuqqcr" , "rtDW.pbrpegxnve" , "rtDW.otun30mznk" , "rtDW.etsjn5fqxr"
, "rtDW.dm031mdhzh" , "rtDW.dwt1logpyt" , "rtDW.olvi0wrke2" ,
"rtDW.h0xflbr2r2" , "rtDW.o5k3wqz1te" , "rtDW.nl35cfre3r" , "rtDW.kp4ub4djpq"
, "rtDW.miaubkp1tz" , "rtDW.frfvjoiupy" , "rtDW.n1tmln402w" ,
"rtDW.mtstnsjsji" , "rtDW.kudt5h2w0b" , "rtDW.kg30gk0yon" , "rtDW.iuuqkwmjrb"
, "rtDW.ork2mu3aqa" , "rtDW.fgt0gfkzzs" , "rtDW.cqe343kytb" ,
"rtDW.mvcna0flrg" , "rtDW.al2bessz01" , "rtDW.luewrj1rxn" , "rtDW.isfqm5nn3q"
, "rtDW.nbeww3raq3" , "rtDW.gqsz4zovj0" , "rtDW.g22bx3mwrj" ,
"rtDW.gywfygl1db" , "rtDW.c01gnuxhwv" , "rtDW.o0byjwoyow.bmw2hixe1f" ,
"rtDW.llvx0kbake.idqwe24upn" , "rtDW.iewfgzwb31.fulyjjxmue" ,
"rtDW.ligjpsfhvtg.idqwe24upn" , "rtDW.mjqilvpgl54.fulyjjxmue" ,
"rtDW.mnr2afncj2u.bmw2hixe1f" , } ; mxArray * rtdwData = mxCreateStructMatrix
( 1 , 1 , 59 , rtdwDataFieldNames ) ; mr_original_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( rtDW . eflcwal1mu ) , sizeof ( rtDW .
eflcwal1mu ) ) ; mr_original_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const
void * ) & ( rtDW . oquiajmyfp ) , sizeof ( rtDW . oquiajmyfp ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. ltasifvkde ) , sizeof ( rtDW . ltasifvkde ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. iksurbbs2u ) , sizeof ( rtDW . iksurbbs2u ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW
. nkspyzjmj0 ) , sizeof ( rtDW . nkspyzjmj0 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW
. owd5cjyj4l ) , sizeof ( rtDW . owd5cjyj4l ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW
. i4xfbt1z25 ) , sizeof ( rtDW . i4xfbt1z25 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW
. ky1a3dnkiw ) , sizeof ( rtDW . ky1a3dnkiw ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & ( rtDW
. fwikzb00to ) , sizeof ( rtDW . fwikzb00to ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & ( rtDW
. azfsgwj0il ) , sizeof ( rtDW . azfsgwj0il ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . i30swi3eeg ) , sizeof ( rtDW . i30swi3eeg ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . bjvck4ijez ) , sizeof ( rtDW . bjvck4ijez ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . idakjgagwj ) , sizeof ( rtDW . idakjgagwj ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . j0o0q4ccss ) , sizeof ( rtDW . j0o0q4ccss ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & (
rtDW . jx0fvxr0vd ) , sizeof ( rtDW . jx0fvxr0vd ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & (
rtDW . moy4nejcr1 ) , sizeof ( rtDW . moy4nejcr1 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & (
rtDW . pf1rurynfs ) , sizeof ( rtDW . pf1rurynfs ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & (
rtDW . brbjfuklas ) , sizeof ( rtDW . brbjfuklas ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & (
rtDW . kqimps20tr ) , sizeof ( rtDW . kqimps20tr ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & (
rtDW . bijp5lznr0 ) , sizeof ( rtDW . bijp5lznr0 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & (
rtDW . gozlgoace0 ) , sizeof ( rtDW . gozlgoace0 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & (
rtDW . jukyp4co3s ) , sizeof ( rtDW . jukyp4co3s ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & (
rtDW . dwcos053mm ) , sizeof ( rtDW . dwcos053mm ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & (
rtDW . ar3vwuqqcr ) , sizeof ( rtDW . ar3vwuqqcr ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & (
rtDW . pbrpegxnve ) , sizeof ( rtDW . pbrpegxnve ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & (
rtDW . otun30mznk ) , sizeof ( rtDW . otun30mznk ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & (
rtDW . etsjn5fqxr ) , sizeof ( rtDW . etsjn5fqxr ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & (
rtDW . dm031mdhzh ) , sizeof ( rtDW . dm031mdhzh ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & (
rtDW . dwt1logpyt ) , sizeof ( rtDW . dwt1logpyt ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & (
rtDW . olvi0wrke2 ) , sizeof ( rtDW . olvi0wrke2 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & (
rtDW . h0xflbr2r2 ) , sizeof ( rtDW . h0xflbr2r2 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & (
rtDW . o5k3wqz1te ) , sizeof ( rtDW . o5k3wqz1te ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & (
rtDW . nl35cfre3r ) , sizeof ( rtDW . nl35cfre3r ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & (
rtDW . kp4ub4djpq ) , sizeof ( rtDW . kp4ub4djpq ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & (
rtDW . miaubkp1tz ) , sizeof ( rtDW . miaubkp1tz ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) & (
rtDW . frfvjoiupy ) , sizeof ( rtDW . frfvjoiupy ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) & (
rtDW . n1tmln402w ) , sizeof ( rtDW . n1tmln402w ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) & (
rtDW . mtstnsjsji ) , sizeof ( rtDW . mtstnsjsji ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) & (
rtDW . kudt5h2w0b ) , sizeof ( rtDW . kudt5h2w0b ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) & (
rtDW . kg30gk0yon ) , sizeof ( rtDW . kg30gk0yon ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void * ) & (
rtDW . iuuqkwmjrb ) , sizeof ( rtDW . iuuqkwmjrb ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) & (
rtDW . ork2mu3aqa ) , sizeof ( rtDW . ork2mu3aqa ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void * ) & (
rtDW . fgt0gfkzzs ) , sizeof ( rtDW . fgt0gfkzzs ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void * ) & (
rtDW . cqe343kytb ) , sizeof ( rtDW . cqe343kytb ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) & (
rtDW . mvcna0flrg ) , sizeof ( rtDW . mvcna0flrg ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void * ) & (
rtDW . al2bessz01 ) , sizeof ( rtDW . al2bessz01 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void * ) & (
rtDW . luewrj1rxn ) , sizeof ( rtDW . luewrj1rxn ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * ) & (
rtDW . isfqm5nn3q ) , sizeof ( rtDW . isfqm5nn3q ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void * ) & (
rtDW . nbeww3raq3 ) , sizeof ( rtDW . nbeww3raq3 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void * ) & (
rtDW . gqsz4zovj0 ) , sizeof ( rtDW . gqsz4zovj0 ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void * ) & (
rtDW . g22bx3mwrj ) , sizeof ( rtDW . g22bx3mwrj ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void * ) & (
rtDW . gywfygl1db ) , sizeof ( rtDW . gywfygl1db ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void * ) & (
rtDW . c01gnuxhwv ) , sizeof ( rtDW . c01gnuxhwv ) ) ;
mr_original_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void * ) & (
rtDW . o0byjwoyow . bmw2hixe1f ) , sizeof ( rtDW . o0byjwoyow . bmw2hixe1f )
) ; mr_original_cacheDataAsMxArray ( rtdwData , 0 , 54 , ( const void * ) & (
rtDW . llvx0kbake . idqwe24upn ) , sizeof ( rtDW . llvx0kbake . idqwe24upn )
) ; mr_original_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const void * ) & (
rtDW . iewfgzwb31 . fulyjjxmue ) , sizeof ( rtDW . iewfgzwb31 . fulyjjxmue )
) ; mr_original_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void * ) & (
rtDW . ligjpsfhvtg . idqwe24upn ) , sizeof ( rtDW . ligjpsfhvtg . idqwe24upn
) ) ; mr_original_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const void * ) &
( rtDW . mjqilvpgl54 . fulyjjxmue ) , sizeof ( rtDW . mjqilvpgl54 .
fulyjjxmue ) ) ; mr_original_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const
void * ) & ( rtDW . mnr2afncj2u . bmw2hixe1f ) , sizeof ( rtDW . mnr2afncj2u
. bmw2hixe1f ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; }
mr_original_cacheDataAsMxArray ( ssDW , 0 , 2 , ( const void * ) & (
rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ; } void
mr_original_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . eflcwal1mu
) , rtdwData , 0 , 0 , sizeof ( rtDW . eflcwal1mu ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . oquiajmyfp ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . oquiajmyfp ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . ltasifvkde ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . ltasifvkde ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . iksurbbs2u ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . iksurbbs2u ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . nkspyzjmj0 ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . nkspyzjmj0 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . owd5cjyj4l ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . owd5cjyj4l ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . i4xfbt1z25 ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . i4xfbt1z25 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . ky1a3dnkiw ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . ky1a3dnkiw ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . fwikzb00to ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . fwikzb00to ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . azfsgwj0il ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . azfsgwj0il ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . i30swi3eeg ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . i30swi3eeg ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . bjvck4ijez ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . bjvck4ijez ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . idakjgagwj ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . idakjgagwj ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . j0o0q4ccss ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . j0o0q4ccss ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . jx0fvxr0vd ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . jx0fvxr0vd ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . moy4nejcr1 ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . moy4nejcr1 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . pf1rurynfs ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . pf1rurynfs ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . brbjfuklas ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . brbjfuklas ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . kqimps20tr ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . kqimps20tr ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . bijp5lznr0 ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . bijp5lznr0 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . gozlgoace0 ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . gozlgoace0 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . jukyp4co3s ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . jukyp4co3s ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . dwcos053mm ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . dwcos053mm ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . ar3vwuqqcr ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . ar3vwuqqcr ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . pbrpegxnve ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . pbrpegxnve ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . otun30mznk ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . otun30mznk ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . etsjn5fqxr ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . etsjn5fqxr ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . dm031mdhzh ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . dm031mdhzh ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . dwt1logpyt ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . dwt1logpyt ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . olvi0wrke2 ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . olvi0wrke2 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . h0xflbr2r2 ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . h0xflbr2r2 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . o5k3wqz1te ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . o5k3wqz1te ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . nl35cfre3r ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . nl35cfre3r ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . kp4ub4djpq ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . kp4ub4djpq ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . miaubkp1tz ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . miaubkp1tz ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . frfvjoiupy ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . frfvjoiupy ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . n1tmln402w ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . n1tmln402w ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . mtstnsjsji ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . mtstnsjsji ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . kudt5h2w0b ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . kudt5h2w0b ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . kg30gk0yon ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . kg30gk0yon ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . iuuqkwmjrb ) ,
rtdwData , 0 , 40 , sizeof ( rtDW . iuuqkwmjrb ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . ork2mu3aqa ) ,
rtdwData , 0 , 41 , sizeof ( rtDW . ork2mu3aqa ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . fgt0gfkzzs ) ,
rtdwData , 0 , 42 , sizeof ( rtDW . fgt0gfkzzs ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . cqe343kytb ) ,
rtdwData , 0 , 43 , sizeof ( rtDW . cqe343kytb ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . mvcna0flrg ) ,
rtdwData , 0 , 44 , sizeof ( rtDW . mvcna0flrg ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . al2bessz01 ) ,
rtdwData , 0 , 45 , sizeof ( rtDW . al2bessz01 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . luewrj1rxn ) ,
rtdwData , 0 , 46 , sizeof ( rtDW . luewrj1rxn ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . isfqm5nn3q ) ,
rtdwData , 0 , 47 , sizeof ( rtDW . isfqm5nn3q ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . nbeww3raq3 ) ,
rtdwData , 0 , 48 , sizeof ( rtDW . nbeww3raq3 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . gqsz4zovj0 ) ,
rtdwData , 0 , 49 , sizeof ( rtDW . gqsz4zovj0 ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . g22bx3mwrj ) ,
rtdwData , 0 , 50 , sizeof ( rtDW . g22bx3mwrj ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . gywfygl1db ) ,
rtdwData , 0 , 51 , sizeof ( rtDW . gywfygl1db ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . c01gnuxhwv ) ,
rtdwData , 0 , 52 , sizeof ( rtDW . c01gnuxhwv ) ) ;
mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . o0byjwoyow .
bmw2hixe1f ) , rtdwData , 0 , 53 , sizeof ( rtDW . o0byjwoyow . bmw2hixe1f )
) ; mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . llvx0kbake .
idqwe24upn ) , rtdwData , 0 , 54 , sizeof ( rtDW . llvx0kbake . idqwe24upn )
) ; mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . iewfgzwb31 .
fulyjjxmue ) , rtdwData , 0 , 55 , sizeof ( rtDW . iewfgzwb31 . fulyjjxmue )
) ; mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . ligjpsfhvtg .
idqwe24upn ) , rtdwData , 0 , 56 , sizeof ( rtDW . ligjpsfhvtg . idqwe24upn )
) ; mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . mjqilvpgl54 .
fulyjjxmue ) , rtdwData , 0 , 57 , sizeof ( rtDW . mjqilvpgl54 . fulyjjxmue )
) ; mr_original_restoreDataFromMxArray ( ( void * ) & ( rtDW . mnr2afncj2u .
bmw2hixe1f ) , rtdwData , 0 , 58 , sizeof ( rtDW . mnr2afncj2u . bmw2hixe1f )
) ; } mr_original_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW
, 0 , 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_original_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 5 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 5 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope" ,
} ; static const char * blockPath [ 5 ] = { "original/Scope" ,
"original/Receptor/Detector/Scope" ,
"original/Receptor/Sincronismo de Trama/Scope1" ,
"original/Receptor/Sincronismo de s&#xED;mbolo/Scope1" ,
"original/Transmisor/Scope" , } ; static const int reason [ 5 ] = { 0 , 0 , 0
, 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 5 ; ++ ( subs [ 0 ] ) ) {
subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 22 ) ; ssSetNumPeriodicContStates ( rtS , 2 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 179 ) ;
ssSetNumBlockIO ( rtS , 76 ) ; ssSetNumBlockParams ( rtS , 1346 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.0001 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 3022713193U ) ; ssSetChecksumVal ( rtS , 1 ,
4233992415U ) ; ssSetChecksumVal ( rtS , 2 , 1504175238U ) ; ssSetChecksumVal
( rtS , 3 , 3029251898U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; { rtB . pczptaloqn = 0.0 ; rtB . lyy2rgzssu = 0.0 ; rtB .
b4klkr2hpb = 0.0 ; rtB . mttr3remqe = 0.0 ; rtB . azmfpdpfhr = 0.0 ; rtB .
b4dgdwqfvr = 0.0 ; rtB . apurb3sda3 = 0.0 ; rtB . c5jqurmpza = 0.0 ; rtB .
hssaqyb021 = 0.0 ; rtB . nqw3knpw3y = 0.0 ; rtB . nqqxqhj4uh = 0.0 ; rtB .
aibuxow2f4 = 0.0 ; rtB . i0c1bgukye = 0.0 ; rtB . fewalbo2ov = 0.0 ; rtB .
azchjpegsm = 0.0 ; rtB . ihiwfhuo0a = 0.0 ; rtB . hkn2g3gvsz = 0.0 ; rtB .
ntkisuxn2g = 0.0 ; rtB . m4m214ovbs = 0.0 ; rtB . pndfq3ndef = 0.0 ; rtB .
oxkodghnh1 = 0.0 ; rtB . g53czseiki = 0.0 ; rtB . icz5jiqa5l = 0.0 ; rtB .
l0uo4a4mr4 = 0.0 ; rtB . ntk0mkheco = 0.0 ; rtB . fqfddfhgnv = 0.0 ; rtB .
k4j5el1r4t = 0.0 ; rtB . ac5onrei0k = 0.0 ; rtB . bz0pvs5lfr = 0.0 ; rtB .
dmtaqaxly0 = 0.0 ; rtB . abjvxeqou3 = 0.0 ; rtB . ie0mnn5bjz = 0.0 ; rtB .
ngmqsygkuj = 0.0 ; rtB . kpyjbyqhnn = 0.0 ; rtB . nqzijf3v2s = 0.0 ; rtB .
bzfqsaqdca = 0.0 ; rtB . cdlxrrgn43 = 0.0 ; rtB . majhbieqf2 = 0.0 ; rtB .
mojdhi2f5w = 0.0 ; rtB . myomqf4clw = 0.0 ; rtB . cqgvyb1usr = 0.0 ; rtB .
otmkurmb40 = 0.0 ; rtB . g1iqixqqbk = 0.0 ; rtB . le03i4u1w1 = 0.0 ; rtB .
dxkzb2shae = 0.0 ; rtB . bcqstcbcss = 0.0 ; rtB . klpoi14tq3 = 0.0 ; rtB .
btco2hfhqs = 0.0 ; rtB . j5xzo5caz4 = 0.0 ; rtB . m2lqawkue3 = 0.0 ; rtB .
njbn3w11wn = 0.0 ; rtB . k3v5lqeyfa = 0.0 ; rtB . ommuhpqjnr = 0.0 ; rtB .
g2d1qhfmtb = 0.0 ; rtB . f4wxz52mc5 [ 0 ] = 0.0 ; rtB . f4wxz52mc5 [ 1 ] =
0.0 ; rtB . pyvoagmwyq [ 0 ] = 0.0 ; rtB . pyvoagmwyq [ 1 ] = 0.0 ; rtB .
ppuci252pa [ 0 ] = 0.0 ; rtB . ppuci252pa [ 1 ] = 0.0 ; rtB . bnrnxdd0vt =
0.0 ; rtB . gpjz2pf2n0 = 0.0 ; rtB . o0byjwoyow . lzgwbwuubl = 0.0 ; rtB .
mnr2afncj2u . lzgwbwuubl = 0.0 ; } } { real_T * x = ( real_T * ) & rtX ;
ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X
) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ;
( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; rtDW . eflcwal1mu = 0.0 ;
rtDW . oquiajmyfp = 0.0 ; rtDW . ltasifvkde = 0.0 ; rtDW . iksurbbs2u = 0.0 ;
rtDW . nkspyzjmj0 = 0.0 ; rtDW . owd5cjyj4l . modelTStart = 0.0 ; rtDW .
i4xfbt1z25 . modelTStart = 0.0 ; rtDW . ky1a3dnkiw . modelTStart = 0.0 ; rtDW
. fwikzb00to . modelTStart = 0.0 ; rtDW . azfsgwj0il . modelTStart = 0.0 ;
rtDW . i30swi3eeg . modelTStart = 0.0 ; rtDW . bjvck4ijez . modelTStart = 0.0
; rtDW . idakjgagwj . modelTStart = 0.0 ; rtDW . j0o0q4ccss . modelTStart =
0.0 ; rtDW . jx0fvxr0vd . modelTStart = 0.0 ; rtDW . moy4nejcr1 . modelTStart
= 0.0 ; rtDW . pf1rurynfs . modelTStart = 0.0 ; rtDW . brbjfuklas .
modelTStart = 0.0 ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( (
char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS ,
& dtInfo ) ; dtInfo . numDataTypes = 22 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
original_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "original" ) ; ssSetPath
( rtS , "original" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS ,
0.12000000000000001 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 4 , 4
, 1 , 1 , 8 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ]
= { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 4 , 4 , 1 , 1 , 8 , 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"original/Transmisor/Analog\nFilter Design" ,
"original/Receptor/Sincronismo de portadora/Analog\nFilter Design" ,
"original/Receptor/Correlaci&#xF3;n/Integrator" ,
 "original/Receptor/Sincronismo de s&#xED;mbolo/Continuous-Time\nVCO/Modulo \nIntegrator/Modulo\nIntegrator"
, "original/Receptor/Correlaci&#xF3;n/Analog\nFilter Design" ,
 "original/Receptor/Sincronismo de portadora/\nVCO/Modulo \nIntegrator/Modulo\nIntegrator"
, "original/Receptor/Sincronismo de portadora/Integrator" ,
"original/Receptor/Sincronismo de s&#xED;mbolo/Integrator1" ,
"original/Receptor/Sincronismo de s&#xED;mbolo/Integrator" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" ,
"" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] =
{ { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
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
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . egzjqzicdq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . benb2xcfzc [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ng4tabqmtd ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . moligukihq ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . dbfnj3ttmr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . gjwqeukkq3 ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . lhjxqs0ce0 ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . nppgwv3zah ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . my5bz0mxqu ; }
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
ssSetPeriodicContStateIndices ( rtS , rtPeriodicIndX ) ; ( void ) memset ( (
void * ) rtPeriodicIndX , 0 , 2 * sizeof ( int_T ) ) ;
ssSetPeriodicContStateRanges ( rtS , rtPeriodicRngX ) ; ( void ) memset ( (
void * ) rtPeriodicRngX , 0 , 4 * sizeof ( real_T ) ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
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
ssNonContDerivSigInfo nonContDerivSigInfo [ 4 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . ommuhpqjnr ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . k3v5lqeyfa ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . mojdhi2f5w ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . bzfqsaqdca ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i <
22 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 3.3333333333333335E-7 ) ; ssSetSolverMaxOrder ( rtS
, - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , (
NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 )
; ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
4 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
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
zc ) ; } { rtPrevZCX . i2q0ncrpsr = UNINITIALIZED_ZCSIG ; rtPrevZCX .
mc53zk2efp = UNINITIALIZED_ZCSIG ; rtPrevZCX . a40vve3elm =
UNINITIALIZED_ZCSIG ; rtPrevZCX . lopkxabcwq = POS_ZCSIG ; rtPrevZCX .
fueymmbsgp = UNINITIALIZED_ZCSIG ; rtPrevZCX . j44yq314nr = ZERO_ZCSIG ;
rtPrevZCX . gta1yuk1am = UNINITIALIZED_ZCSIG ; rtPrevZCX . o0byjwoyow .
ohewvvpbtd = UNINITIALIZED_ZCSIG ; rtPrevZCX . mnr2afncj2u . ohewvvpbtd =
UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS , 0 , 3022713193U ) ;
ssSetChecksumVal ( rtS , 1 , 4233992415U ) ; ssSetChecksumVal ( rtS , 2 ,
1504175238U ) ; ssSetChecksumVal ( rtS , 3 , 3029251898U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 13 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . mnr2afncj2u . bmw2hixe1f ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . ork2mu3aqa ; systemRan [ 3 ] = ( sysRanDType * ) &
rtDW . iuuqkwmjrb ; systemRan [ 4 ] = ( sysRanDType * ) & rtDW . kg30gk0yon ;
systemRan [ 5 ] = ( sysRanDType * ) & rtDW . kudt5h2w0b ; systemRan [ 6 ] = (
sysRanDType * ) & rtDW . mjqilvpgl54 . fulyjjxmue ; systemRan [ 7 ] = (
sysRanDType * ) & rtDW . ligjpsfhvtg . idqwe24upn ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . iewfgzwb31 . fulyjjxmue ; systemRan [ 9 ] = (
sysRanDType * ) & rtDW . llvx0kbake . idqwe24upn ; systemRan [ 10 ] = (
sysRanDType * ) & rtDW . mtstnsjsji ; systemRan [ 11 ] = ( sysRanDType * ) &
rtDW . o0byjwoyow . bmw2hixe1f ; systemRan [ 12 ] = ( sysRanDType * ) & rtDW
. n1tmln402w ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_original_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_original_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_original_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
