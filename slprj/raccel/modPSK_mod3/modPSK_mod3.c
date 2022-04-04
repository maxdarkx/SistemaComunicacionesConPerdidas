#include "modPSK_mod3.h"
#include "rtwtypes.h"
#include "modPSK_mod3_private.h"
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "modPSK_mod3_capi.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "modPSK_mod3_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
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
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
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
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void ej24c2k4ef (
igetpbslua * localB , izzmnm4or4 * localP ) { localB -> n0jiemzt0m = localP
-> _Y0 ; } void f5g5ssvz0o ( SimStruct * rtS_e , real_T a5pv3ym0hk , real_T
gugk31myqr , igetpbslua * localB , kkwkju2b34 * localDW , mcilpbj4n3 *
localZCE ) { ZCEventType zcEvent ; if ( ssIsModeUpdateTimeStep ( rtS_e ) ) {
zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & localZCE -> pfohtyb5z1 , (
a5pv3ym0hk ) ) ; if ( zcEvent != NO_ZCEVENT ) { localB -> n0jiemzt0m =
gugk31myqr ; localDW -> kw45gvclvl = 4 ; } } } void dodpev2jqu ( b25ph2maso *
localB , akft0npbrm * localP ) { localB -> gcuafzmxgi = localP -> OUT_Y0 ; }
void cum1qupdzn ( d2girhkqx4 * localDW ) { localDW -> jfiw2hmwe4 = false ; }
void akqqybeix5 ( SimStruct * rtS_i , d2girhkqx4 * localDW ) { localDW ->
jfiw2hmwe4 = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; }
void obgcvvf2c2 ( SimStruct * rtS_i , real_T p5pgg55qc0 , real_T icsayk3iqt ,
real_T ish1rcvhs2 , b25ph2maso * localB , d2girhkqx4 * localDW ) { if (
ssIsSampleHit ( rtS_i , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS_i ) ) { if (
p5pgg55qc0 > 0.0 ) { if ( ! localDW -> jfiw2hmwe4 ) { if ( ssGetTaskTime (
rtS_i , 1 ) != ssGetTStart ( rtS_i ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } localDW ->
jfiw2hmwe4 = true ; } } else if ( localDW -> jfiw2hmwe4 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; cum1qupdzn ( localDW )
; } } if ( localDW -> jfiw2hmwe4 ) { localB -> gcuafzmxgi = ( ish1rcvhs2 >
icsayk3iqt ) ; if ( ssIsModeUpdateTimeStep ( rtS_i ) ) { srUpdateBC ( localDW
-> igzqysubwr ) ; } } } void llehjofb4m ( iqmdugheux * localB , ft4pkmho30 *
localP ) { localB -> fncspxqpzn = localP -> OUT_Y0 ; } void ai5wun410l (
aiayfqjngh * localDW ) { localDW -> miqumv2j33 = false ; } void k3cvpvfqnb (
SimStruct * rtS_g , aiayfqjngh * localDW ) { localDW -> miqumv2j33 = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_g ) ; } void guziuj3nzo (
SimStruct * rtS_j , real_T ifvgwahfd5 , real_T h4w2g3uqjk , real_T lwukqo0wc0
, iqmdugheux * localB , aiayfqjngh * localDW ) { if ( ssIsSampleHit ( rtS_j ,
1 , 0 ) && ssIsModeUpdateTimeStep ( rtS_j ) ) { if ( ifvgwahfd5 > 0.0 ) { if
( ! localDW -> miqumv2j33 ) { if ( ssGetTaskTime ( rtS_j , 1 ) != ssGetTStart
( rtS_j ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_j ) ; }
localDW -> miqumv2j33 = true ; } } else if ( localDW -> miqumv2j33 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_j ) ; ai5wun410l ( localDW )
; } } if ( localDW -> miqumv2j33 ) { localB -> fncspxqpzn = ( h4w2g3uqjk >
lwukqo0wc0 ) ; if ( ssIsModeUpdateTimeStep ( rtS_j ) ) { srUpdateBC ( localDW
-> mzbzupg3uq ) ; } } } real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) {
uint32_T hi ; uint32_T lo ; lo = * u % 127773U * 16807U ; hi = * u / 127773U
* 2836U ; if ( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u =
lo - hi ; } return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T si ; real_T sr ; real_T
y ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MdlInitialize ( void ) { real_T tmp ; int32_T r ;
int32_T t ; uint32_T tseed ; rtX . amtjz55qss [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . amtjz55qss [ 1 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . amtjz55qss [ 2 ] = rtP .
AnalogFilterDesign_InitialCondition ; rtX . amtjz55qss [ 3 ] = rtP .
AnalogFilterDesign_InitialCondition ; tmp = muDoubleScalarFloor ( rtP .
RuidoAGWN_Seed ) ; if ( muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf (
tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9
) ; } tseed = tmp < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp : (
uint32_T ) tmp ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed &
32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U )
+ t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else if ( tseed >
2147483646U ) { tseed = 2147483646U ; } rtDW . bzmxqssdoq = tseed ; rtDW .
idhuf1euoi = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . bzmxqssdoq ) *
muDoubleScalarSqrt ( rtP . Pot_Ruido ) + rtP . RuidoAGWN_Mean ; rtX .
gax2n2uyhb = rtP . Integrator_IC ; rtX . lzv0rcie1i = rtP .
ModuloIntegrator_IC ; rtDW . kia112cgkq = rtP . Memory_InitialCondition ;
rtDW . igyctbswok = rtP . Monostable_ic ; rtDW . cuilob0auh = rtP .
SampleandHold_ic ; rtX . jpbcgznxiw [ 0 ] = rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . adtcefug1k [ 0 ] = rtP
. AnalogFilterDesign_InitialCondition_l2mskoueic ; rtX . jpbcgznxiw [ 1 ] =
rtP . AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . adtcefug1k [ 1 ]
= rtP . AnalogFilterDesign_InitialCondition_l2mskoueic ; rtX . jpbcgznxiw [ 2
] = rtP . AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX . adtcefug1k [
2 ] = rtP . AnalogFilterDesign_InitialCondition_l2mskoueic ; rtX . jpbcgznxiw
[ 3 ] = rtP . AnalogFilterDesign_InitialCondition_bizf0yluzm ; rtX .
adtcefug1k [ 3 ] = rtP . AnalogFilterDesign_InitialCondition_l2mskoueic ; for
( r = 0 ; r < 8 ; r ++ ) { rtX . e5d2w4theu [ r ] = rtP .
AnalogFilterDesign_InitialCondition_gxj5snzs0v ; } rtX . lpelu0o3uv = rtP .
ModuloIntegrator_IC_g1vo2kap3u ; rtX . ef1jjuhfsz = rtP .
Integrator_IC_oxpanuusbm ; rtDW . llqwbguanw = rtP .
TmpLatchAtDFlipFlopInport1_InitialCondition ; rtX . bwxjromtln = rtP .
Integrator1_IC ; rtDW . i3eziu3f1n = rtP . Memory_InitialCondition_oggd2r4odw
; rtDW . g4c0zz45r4 = rtP . Monostable1_ic ; rtDW . gamney3fyk = rtP .
SampleHold_ic ; rtX . fkxwshodm4 = rtP . Integrator_IC_a5b0eygpkp ; rtDW .
fbp5lgspzk = rtP . Memory_InitialCondition_ljulw4woig ; rtDW . hobor2c3tl =
rtP . Monostable3_ic ; rtDW . jkafh5jkcy = rtP . SampleHold_ic_cvpetr2ktj ;
ej24c2k4ef ( & rtB . f5g5ssvz0ob , & rtP . f5g5ssvz0ob ) ; rtB . i3hvpke3ms =
rtP . OUT_Y0_gbikirmbla ; rtB . octfr53rd1 = rtP . OUT_Y0 ; rtB . d0uzclm1vr
= rtP . Q_Y0 ; rtB . pet04kmorq = rtP . Q_Y0_ngs1cr5pq5 ; llehjofb4m ( & rtB
. guziuj3nzou , & rtP . guziuj3nzou ) ; dodpev2jqu ( & rtB . obgcvvf2c2c , &
rtP . obgcvvf2c2c ) ; llehjofb4m ( & rtB . l2pxsorbc0 , & rtP . l2pxsorbc0 )
; dodpev2jqu ( & rtB . ntt0n0z3qa , & rtP . ntt0n0z3qa ) ; rtB . amouf3rzmf =
rtP . _Y0 ; ej24c2k4ef ( & rtB . pokud50mlj , & rtP . pokud50mlj ) ; { int_T
rootPeriodicContStateIndices [ 2 ] = { 9 , 22 } ; real_T
rootPeriodicContStateRanges [ 4 ] = { 0.0 , 1.0 , 0.0 , 1.0 } ; ( void )
memcpy ( ( void * ) rtPeriodicIndX , rootPeriodicContStateIndices , 2 *
sizeof ( int_T ) ) ; ( void ) memcpy ( ( void * ) rtPeriodicRngX ,
rootPeriodicContStateRanges , 4 * sizeof ( real_T ) ) ; } } void MdlStart (
void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "In1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "In1" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"modPSK_mod3/Triggered To Workspace/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "In1" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
2 ] = { 1 , 1 } ; sigDims . nDims = 2 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ivu5m05flg . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "eb9e814e-69c0-4644-8794-b513e2d065c7" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. ivu5m05flg . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ivu5m05flg
. AQHandles , "Triggered" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate
( rtDW . ivu5m05flg . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW .
ivu5m05flg . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . ivu5m05flg . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . ivu5m05flg . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain ( rtDW
. ivu5m05flg . AQHandles ) ; sdiSetSignalIsFrameBased ( rtDW . ivu5m05flg .
AQHandles , true ) ; sdiCompleteAsyncioQueueCreation ( rtDW . ivu5m05flg .
AQHandles , hDT , & srcInfo ) ; } sdiFreeLabel ( sigName ) ; sdiFreeLabel (
loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ;
sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; sdiFreeLabel (
subPath ) ; } } if ( ! isStreamoutAlreadyRegistered ) { { sdiLabelU varName =
sdiGetLabelFromChars ( "Rx" ) ; sdiRegisterWksVariable ( rtDW . ivu5m05flg .
AQHandles , varName , "array2D" ) ; sdiFreeLabel ( varName ) ; } } } } } { {
{ bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo
; sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"modPSK_mod3/Receptor/Sincronismo de s&#xED;mbolo/Sign" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 2 ] = { 1 , 1 } ; sigDims . nDims = 2 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. dke2w5vglk . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"f453babb-7d79-4740-976d-2b86b4c66b8d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . dke2w5vglk . AQHandles , hDT , & srcInfo ) ; if ( rtDW . dke2w5vglk .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . dke2w5vglk . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
dke2w5vglk . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dke2w5vglk .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . dke2w5vglk . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . dke2w5vglk . AQHandles , loggedName , origSigName , propName ) ; }
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
fromwksInfo -> time = ( NULL ) ; rtDW . c550b3xklm . TimePtr = fromwksInfo ->
time ; rtDW . c550b3xklm . DataPtr = fromwksInfo -> data ; rtDW . c550b3xklm
. RSimInfoPtr = fromwksInfo ; } rtDW . kb5rvgdujd . PrevIndex = - 1 ; } {
char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf (
2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } rtDW
. kcxfvmkrf2 . Tail = 0 ; rtDW . kcxfvmkrf2 . Head = 0 ; rtDW . kcxfvmkrf2 .
Last = 0 ; rtDW . kcxfvmkrf2 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
jc1itafzwd . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf (
ptrKey , "modPSK_mod3/Canal/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
jc1itafzwd . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . n2bt3cyc55 . Tail = 0 ; rtDW . n2bt3cyc55 . Head = 0 ; rtDW .
n2bt3cyc55 . Last = 0 ; rtDW . n2bt3cyc55 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput_m3b1lj5lye ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; rtDW . lj1tdbxggs . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Correlación/Transport\nDelay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
lj1tdbxggs . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . lcuflefjuj . Tail = 0 ; rtDW . lcuflefjuj . Head = 0 ; rtDW .
lcuflefjuj . Last = 0 ; rtDW . lcuflefjuj . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay2_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . ml2avl24pf . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay2_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
ml2avl24pf . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . ovi0zqdzif . Tail = 0 ; rtDW . ovi0zqdzif . Head = 0 ; rtDW .
ovi0zqdzif . Last = 0 ; rtDW . ovi0zqdzif . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . fbk251u41l . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay1_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
fbk251u41l . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . advdik1iky . Tail = 0 ; rtDW . advdik1iky . Head = 0 ; rtDW .
advdik1iky . Last = 0 ; rtDW . advdik1iky . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay4_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . kpvx4uvt01 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay4_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
kpvx4uvt01 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . kb3fhgjdld . Tail = 0 ; rtDW . kb3fhgjdld . Head = 0 ; rtDW .
kb3fhgjdld . Last = 0 ; rtDW . kb3fhgjdld . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay3_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . oeere24mz0 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay3_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
oeere24mz0 . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . ho5e0de00z . Tail = 0 ; rtDW . ho5e0de00z . Head = 0 ; rtDW .
ho5e0de00z . Last = 0 ; rtDW . ho5e0de00z . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay6_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . h1egexnfwb . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay6_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
h1egexnfwb . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . dlpoyqagu4 . Tail = 0 ; rtDW . dlpoyqagu4 . Head = 0 ; rtDW .
dlpoyqagu4 . Last = 0 ; rtDW . dlpoyqagu4 . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay5_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . lycpuo0tla . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay5_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
lycpuo0tla . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . k1nwxppvuo . Tail = 0 ; rtDW . k1nwxppvuo . Head = 0 ; rtDW .
k1nwxppvuo . Last = 0 ; rtDW . k1nwxppvuo . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay8_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . etoiwhh4sj . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay8_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
etoiwhh4sj . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . azfuopxupm . Tail = 0 ; rtDW . azfuopxupm . Head = 0 ; rtDW .
azfuopxupm . Last = 0 ; rtDW . azfuopxupm . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay7_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . l4z1r030na . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay7_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
l4z1r030na . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . bnqksyhx4b . Tail = 0 ; rtDW . bnqksyhx4b . Head = 0 ; rtDW .
bnqksyhx4b . Last = 0 ; rtDW . bnqksyhx4b . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay9_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . e3lmwmye5o . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay9_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
e3lmwmye5o . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . jsj5ows1gx . Tail = 0 ; rtDW . jsj5ows1gx . Head = 0 ; rtDW .
jsj5ows1gx . Last = 0 ; rtDW . jsj5ows1gx . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay11_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS )
; rtDW . mxtwjhbmuw . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay11_TUbuffer%d" , 0
) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
mxtwjhbmuw . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } rtDW . ckhj2mjol3 = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . haenchykp4 =
false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; k3cvpvfqnb ( rtS
, & rtDW . guziuj3nzou ) ; akqqybeix5 ( rtS , & rtDW . obgcvvf2c2c ) ;
k3cvpvfqnb ( rtS , & rtDW . l2pxsorbc0 ) ; akqqybeix5 ( rtS , & rtDW .
ntt0n0z3qa ) ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T
anocvnzoxf ; real_T hqbvl5bohq ; real_T mezednkrc5 ; real_T chxvpheep2 ;
real_T ol0hstuhh3 ; int32_T ci ; uint32_T ri ; boolean_T jfpszsfffo ;
ZCEventType zcEvent ; srClearBC ( rtDW . f5g5ssvz0ob . kw45gvclvl ) ;
srClearBC ( rtDW . pu1wrg42xz ) ; srClearBC ( rtDW . bluxjvuquj ) ; srClearBC
( rtDW . jggqbqxmox ) ; srClearBC ( rtDW . mt4cgs1ctq ) ; srClearBC ( rtDW .
obgcvvf2c2c . igzqysubwr ) ; srClearBC ( rtDW . guziuj3nzou . mzbzupg3uq ) ;
srClearBC ( rtDW . kjy05jsjy1 ) ; srClearBC ( rtDW . ajzqjdehhp ) ; if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { { int_T currIndex = rtDW . kb5rvgdujd .
PrevIndex + 1 ; real_T * pDataValues = ( real_T * ) rtDW . c550b3xklm .
DataPtr ; int numPoints ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
c550b3xklm . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; if (
currIndex < numPoints ) { pDataValues += currIndex ; rtB . cjskazwmh1 = *
pDataValues ; } else { rtB . cjskazwmh1 = 0.0 ; } rtDW . kb5rvgdujd .
PrevIndex = currIndex ; } } rtB . d4txlaulvr = 0.0 ; for ( ri = rtP .
AnalogFilterDesign_C_jc [ 0U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 1U ] ;
ri ++ ) { rtB . d4txlaulvr += rtP . AnalogFilterDesign_C_pr * rtX .
amtjz55qss [ 0U ] ; } for ( ri = rtP . AnalogFilterDesign_C_jc [ 1U ] ; ri <
rtP . AnalogFilterDesign_C_jc [ 2U ] ; ri ++ ) { rtB . d4txlaulvr += rtP .
AnalogFilterDesign_C_pr * rtX . amtjz55qss [ 1U ] ; } for ( ri = rtP .
AnalogFilterDesign_C_jc [ 2U ] ; ri < rtP . AnalogFilterDesign_C_jc [ 3U ] ;
ri ++ ) { rtB . d4txlaulvr += rtP . AnalogFilterDesign_C_pr * rtX .
amtjz55qss [ 2U ] ; } for ( ri = rtP . AnalogFilterDesign_C_jc [ 3U ] ; ri <
rtP . AnalogFilterDesign_C_jc [ 4U ] ; ri ++ ) { rtB . d4txlaulvr += rtP .
AnalogFilterDesign_C_pr * rtX . amtjz55qss [ 3U ] ; } { real_T * * uBuffer =
( real_T * * ) & rtDW . jc1itafzwd . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Retraso_Canal ;
anocvnzoxf = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW .
kcxfvmkrf2 . CircularBufSize , & rtDW . kcxfvmkrf2 . Last , rtDW . kcxfvmkrf2
. Tail , rtDW . kcxfvmkrf2 . Head , rtP . TransportDelay_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . kcxfvmkrf2
. CircularBufSize ) [ rtDW . kcxfvmkrf2 . Head ] == ssGetT ( rtS ) ) ) ) ; }
rtB . f2es2rkn4r = 1.0 / rtP . Att_Volt_Canal * anocvnzoxf ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . ailrsbpb25 = rtDW . idhuf1euoi ; }
rtB . bfrc2rc5zl = rtB . f2es2rkn4r + rtB . ailrsbpb25 ; chxvpheep2 = 0.0 ;
for ( ri = rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 0U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 1U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . jpbcgznxiw [ 0U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 1U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 2U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . jpbcgznxiw [ 1U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 2U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 3U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . jpbcgznxiw [ 2U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 3U ] ; ri < rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 4U ] ; ri ++ ) { chxvpheep2 += rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa * rtX . jpbcgznxiw [ 3U ] ; } rtB .
ncdgrorzsx = rtP . Amplitud / rtP . Att_Volt_Canal * chxvpheep2 ; { real_T *
* uBuffer = ( real_T * * ) & rtDW . lj1tdbxggs . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay_Delay ; rtB . pl5zjiseby = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , rtDW . n2bt3cyc55 . CircularBufSize , & rtDW . n2bt3cyc55
. Last , rtDW . n2bt3cyc55 . Tail , rtDW . n2bt3cyc55 . Head , rtP .
TransportDelay_InitOutput_m3b1lj5lye , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ( * uBuffer + rtDW . n2bt3cyc55 . CircularBufSize ) [ rtDW .
n2bt3cyc55 . Head ] == ssGetT ( rtS ) ) ) ) ; } if ( ssIsModeUpdateTimeStep (
rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX .
h30gjmuzs5 , ( rtB . pl5zjiseby ) ) ; if ( zcEvent != NO_ZCEVENT ) { rtX .
gax2n2uyhb = rtP . Integrator_IC ; ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtB . nihlui3tdy = rtX . gax2n2uyhb ; } else { rtB . nihlui3tdy =
rtX . gax2n2uyhb ; } rtB . gopo0ay43o = muDoubleScalarSign (
muDoubleScalarCos ( rtX . lzv0rcie1i * 6.2831853071795862 + 5.497787143782138
) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { f5g5ssvz0o ( rtS , rtB .
gopo0ay43o , rtB . nihlui3tdy , & rtB . f5g5ssvz0ob , & rtDW . f5g5ssvz0ob ,
& rtPrevZCX . f5g5ssvz0ob ) ; rtB . hs04wl1crq = muDoubleScalarSign ( rtB .
f5g5ssvz0ob . n0jiemzt0m ) ; rtB . p4bwi2pbc0 = ! rtDW . kia112cgkq ; rtB .
pznu3l5z1a = rtB . hs04wl1crq * rtP . Constant1_Value ; } chxvpheep2 = ssGetT
( rtS ) ; { real_T * * uBuffer = ( real_T * * ) & rtDW . ml2avl24pf .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . Tb ; rtB . bhvr0udrsy = rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , rtDW . lcuflefjuj . CircularBufSize , & rtDW . lcuflefjuj .
Last , rtDW . lcuflefjuj . Tail , rtDW . lcuflefjuj . Head , rtP .
TransportDelay2_InitOutput , 1 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . lcuflefjuj . CircularBufSize ) [ rtDW . lcuflefjuj .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . fbk251u41l . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . kmqtx532fz =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . ovi0zqdzif .
CircularBufSize , & rtDW . ovi0zqdzif . Last , rtDW . ovi0zqdzif . Tail ,
rtDW . ovi0zqdzif . Head , rtP . TransportDelay1_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . ovi0zqdzif .
CircularBufSize ) [ rtDW . ovi0zqdzif . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . kpvx4uvt01 . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . hnp1kuefxm = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . advdik1iky . CircularBufSize , & rtDW . advdik1iky . Last , rtDW .
advdik1iky . Tail , rtDW . advdik1iky . Head , rtP .
TransportDelay4_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . advdik1iky . CircularBufSize ) [ rtDW . advdik1iky .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . oeere24mz0 . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . lsnuriwz44 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . kb3fhgjdld .
CircularBufSize , & rtDW . kb3fhgjdld . Last , rtDW . kb3fhgjdld . Tail ,
rtDW . kb3fhgjdld . Head , rtP . TransportDelay3_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . kb3fhgjdld .
CircularBufSize ) [ rtDW . kb3fhgjdld . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . h1egexnfwb . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . lisuhkiql3 = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . ho5e0de00z . CircularBufSize , & rtDW . ho5e0de00z . Last , rtDW .
ho5e0de00z . Tail , rtDW . ho5e0de00z . Head , rtP .
TransportDelay6_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . ho5e0de00z . CircularBufSize ) [ rtDW . ho5e0de00z .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . lycpuo0tla . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . ewq0jsmjdj =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . dlpoyqagu4 .
CircularBufSize , & rtDW . dlpoyqagu4 . Last , rtDW . dlpoyqagu4 . Tail ,
rtDW . dlpoyqagu4 . Head , rtP . TransportDelay5_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . dlpoyqagu4 .
CircularBufSize ) [ rtDW . dlpoyqagu4 . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . etoiwhh4sj . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . dv3oqsxz41 = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . k1nwxppvuo . CircularBufSize , & rtDW . k1nwxppvuo . Last , rtDW .
k1nwxppvuo . Tail , rtDW . k1nwxppvuo . Head , rtP .
TransportDelay8_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . k1nwxppvuo . CircularBufSize ) [ rtDW . k1nwxppvuo .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . l4z1r030na . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; rtB . nz2mzf3abt =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , rtDW . azfuopxupm .
CircularBufSize , & rtDW . azfuopxupm . Last , rtDW . azfuopxupm . Tail ,
rtDW . azfuopxupm . Head , rtP . TransportDelay7_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . azfuopxupm .
CircularBufSize ) [ rtDW . azfuopxupm . Head ] == ssGetT ( rtS ) ) ) ) ; } {
real_T * * uBuffer = ( real_T * * ) & rtDW . e3lmwmye5o . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . Tb ;
rtB . geeegghaq4 = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer ,
rtDW . bnqksyhx4b . CircularBufSize , & rtDW . bnqksyhx4b . Last , rtDW .
bnqksyhx4b . Tail , rtDW . bnqksyhx4b . Head , rtP .
TransportDelay9_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ( * uBuffer + rtDW . bnqksyhx4b . CircularBufSize ) [ rtDW . bnqksyhx4b .
Head ] == ssGetT ( rtS ) ) ) ) ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . mxtwjhbmuw . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . Tb ; hqbvl5bohq = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , rtDW . jsj5ows1gx . CircularBufSize , & rtDW
. jsj5ows1gx . Last , rtDW . jsj5ows1gx . Tail , rtDW . jsj5ows1gx . Head ,
rtP . TransportDelay11_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ( * uBuffer + rtDW . jsj5ows1gx . CircularBufSize ) [ rtDW .
jsj5ows1gx . Head ] == ssGetT ( rtS ) ) ) ) ; } rtB . eancnret3z = ( ( ( ( (
( ( ( ( rtB . bhvr0udrsy * rtP . Constant2_Value + rtB . pznu3l5z1a ) + rtB .
kmqtx532fz * rtP . Constant3_Value ) + rtB . hnp1kuefxm * rtP .
Constant4_Value ) + rtB . lsnuriwz44 * rtP . Constant5_Value ) + rtB .
lisuhkiql3 * rtP . Constant6_Value ) + rtB . ewq0jsmjdj * rtP .
Constant7_Value ) + rtB . dv3oqsxz41 * rtP . Constant8_Value ) + rtB .
nz2mzf3abt * rtP . Constant9_Value ) + rtB . geeegghaq4 * rtP .
Constant10_Value ) + hqbvl5bohq * rtP . Constant13_Value ; if ( rtB .
eancnret3z >= rtP . Switch_Threshold ) { rtB . m2vnyqktog = rtP .
Constant15_Value ; } else { rtB . m2vnyqktog = rtP . Constant14_Value ; } rtB
. efvczhdjet = ( rtB . m2vnyqktog != 0.0 ) ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . ftifgsd50u = rtDW . igyctbswok ; if ( ssIsModeUpdateTimeStep (
rtS ) ) { if ( rtB . kppvt5er43 [ 0 ] > 0.0 ) { if ( ! rtDW . ckhj2mjol3 ) {
if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . ckhj2mjol3 =
true ; } } else if ( rtDW . ckhj2mjol3 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . ckhj2mjol3 =
false ; } } } if ( rtDW . ckhj2mjol3 ) { rtB . i3hvpke3ms = ( ( int32_T ) rtB
. ftifgsd50u < ( int32_T ) rtB . efvczhdjet ) ; if ( ssIsModeUpdateTimeStep (
rtS ) ) { srUpdateBC ( rtDW . jggqbqxmox ) ; } } if ( ssIsSampleHit ( rtS , 1
, 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtB . kppvt5er43 [ 1 ] > 0.0
) { if ( ! rtDW . haenchykp4 ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} rtDW . haenchykp4 = true ; } } else if ( rtDW . haenchykp4 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . haenchykp4 =
false ; } } if ( rtDW . haenchykp4 ) { rtB . octfr53rd1 = ( ( int32_T ) rtB .
ftifgsd50u > ( int32_T ) rtB . efvczhdjet ) ; if ( ssIsModeUpdateTimeStep (
rtS ) ) { srUpdateBC ( rtDW . bluxjvuquj ) ; } } rtB . hrmk3oqzup = ( rtB .
i3hvpke3ms || rtB . octfr53rd1 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB
. k3la20515u = rtDW . cuilob0auh ; rtB . k0hg52okk1 = 1000.0 * rtP . Tb -
2.2204460492503131E-16 ; } if ( rtB . p4bwi2pbc0 && rtB . hrmk3oqzup ) { rtB
. jfofwf5qdn = chxvpheep2 ; } else { rtB . jfofwf5qdn = rtB . k3la20515u ; }
rtB . fv3qrvs3nd = ( rtB . jfofwf5qdn + rtB . k0hg52okk1 > chxvpheep2 ) ; if
( rtB . fv3qrvs3nd ) { rtB . dxje1nzfb1 = rtB . gopo0ay43o ; } else { rtB .
dxje1nzfb1 = rtP . Constant16_Value ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) &&
ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( FALLING_ZERO_CROSSING
, & rtPrevZCX . gma50kdl5l , ( rtB . dxje1nzfb1 ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { { if ( rtDW . ivu5m05flg . AQHandles && ssGetLogOutput ( rtS )
) { sdiWriteSignal ( rtDW . ivu5m05flg . AQHandles , ssGetTaskTime ( rtS , 1
) , ( char * ) & rtB . hs04wl1crq + 0 ) ; } } rtDW . ajzqjdehhp = 4 ; } } rtB
. lrg23dznf5 = 0.0 ; for ( ri = rtP . AnalogFilterDesign_C_jc_llcs1qdtjn [ 0U
] ; ri < rtP . AnalogFilterDesign_C_jc_llcs1qdtjn [ 1U ] ; ri ++ ) { rtB .
lrg23dznf5 += rtP . AnalogFilterDesign_C_pr_aqq5iiwnf2 * rtX . adtcefug1k [
0U ] ; } for ( ri = rtP . AnalogFilterDesign_C_jc_llcs1qdtjn [ 1U ] ; ri <
rtP . AnalogFilterDesign_C_jc_llcs1qdtjn [ 2U ] ; ri ++ ) { rtB . lrg23dznf5
+= rtP . AnalogFilterDesign_C_pr_aqq5iiwnf2 * rtX . adtcefug1k [ 1U ] ; } for
( ri = rtP . AnalogFilterDesign_C_jc_llcs1qdtjn [ 2U ] ; ri < rtP .
AnalogFilterDesign_C_jc_llcs1qdtjn [ 3U ] ; ri ++ ) { rtB . lrg23dznf5 += rtP
. AnalogFilterDesign_C_pr_aqq5iiwnf2 * rtX . adtcefug1k [ 2U ] ; } for ( ri =
rtP . AnalogFilterDesign_C_jc_llcs1qdtjn [ 3U ] ; ri < rtP .
AnalogFilterDesign_C_jc_llcs1qdtjn [ 4U ] ; ri ++ ) { rtB . lrg23dznf5 += rtP
. AnalogFilterDesign_C_pr_aqq5iiwnf2 * rtX . adtcefug1k [ 3U ] ; } rtB .
ncgerps2w1 = 0.0 ; for ( ci = 0 ; ci < 8 ; ci ++ ) { for ( ri = rtP .
AnalogFilterDesign_C_jc_d2bgogmalx [ ( uint32_T ) ci ] ; ri < rtP .
AnalogFilterDesign_C_jc_d2bgogmalx [ ci + 1U ] ; ri ++ ) { rtB . ncgerps2w1
+= rtP . AnalogFilterDesign_C_pr_e3t31otpuq * rtX . e5d2w4theu [ ( uint32_T )
ci ] ; } } rtB . dzwzyjfb3d = rtB . lrg23dznf5 * rtB . ncdgrorzsx ; rtB .
c1tvvwnguu = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtB . hrmk3oqzup && ( rtPrevZCX .
neekdr5ik0 != POS_ZCSIG ) ) { rtDW . pu1wrg42xz = 4 ; } rtPrevZCX .
neekdr5ik0 = rtB . hrmk3oqzup ; } jfpszsfffo = rtDW . llqwbguanw ; }
chxvpheep2 = muDoubleScalarCos ( rtX . lpelu0o3uv * 6.2831853071795862 ) ;
ol0hstuhh3 = rtP . Att_Volt_Canal / rtP . Amplitud * rtB . lrg23dznf5 ;
ol0hstuhh3 = ol0hstuhh3 * ol0hstuhh3 * chxvpheep2 ; mezednkrc5 = rtP . R2 /
rtP . R1 * ol0hstuhh3 + rtX . ef1jjuhfsz ; rtB . pxicmncoih = rtP . Kv /
6.2831853071795862 * mezednkrc5 + 2.0 * rtP . Frec_port ; rtB . ao3hvbk03u =
muDoubleScalarSign ( chxvpheep2 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
zcEvent = NO_ZCEVENT ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent =
rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX . ph4ircn3eg , ( rtB .
ao3hvbk03u ) ) ; } if ( rtP . Constant2_Value_mwviqzbxqh > 0.0 ) { if ( !
rtDW . nrn32puwjn ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . nrn32puwjn =
true ; } if ( ssIsModeUpdateTimeStep ( rtS ) && ( zcEvent != NO_ZCEVENT ) ) {
rtB . d0uzclm1vr = jfpszsfffo ; rtB . pet04kmorq = ! rtB . d0uzclm1vr ; rtDW
. mt4cgs1ctq = 4 ; } } else if ( rtDW . nrn32puwjn ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . d0uzclm1vr = rtP .
Q_Y0 ; rtB . pet04kmorq = rtP . Q_Y0_ngs1cr5pq5 ; rtDW . nrn32puwjn = false ;
} rtB . cjvhltyh5i = rtP . Constant6_Value_dkmziwbikw * ( real_T ) rtB .
d0uzclm1vr - rtP . Constant5_Value_hu2bresth1 ; } rtB . awbajcw3bs = 1.0 / (
rtP . R1 * rtP . C ) * ol0hstuhh3 ; rtB . k0xpbzxvuq = muDoubleScalarSign (
rtP . Constant1_Value_hcjo4f4r5j * rtB . ncgerps2w1 ) ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING
, & rtPrevZCX . ct04cv1aou , ( rtB . gopo0ay43o ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { rtX . bwxjromtln = rtP . Integrator1_IC ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . pgstwodvgn = rtX
. bwxjromtln ; } else { rtB . pgstwodvgn = rtX . bwxjromtln ; } chxvpheep2 =
ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . bq2qwyyni3 = !
rtDW . i3eziu3f1n ; rtB . ji14ejc3mp = rtDW . g4c0zz45r4 ; } guziuj3nzo ( rtS
, rtB . ck3j1srrxl [ 0 ] , rtB . gopo0ay43o , rtB . ji14ejc3mp , & rtB .
guziuj3nzou , & rtDW . guziuj3nzou ) ; obgcvvf2c2 ( rtS , rtB . ck3j1srrxl [
1 ] , rtB . gopo0ay43o , rtB . ji14ejc3mp , & rtB . obgcvvf2c2c , & rtDW .
obgcvvf2c2c ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . agrizcdfza =
rtDW . gamney3fyk ; } if ( rtB . bq2qwyyni3 && ( rtB . guziuj3nzou .
fncspxqpzn || rtB . obgcvvf2c2c . gcuafzmxgi ) ) { rtB . mxxtwp3ieb =
chxvpheep2 ; } else { rtB . mxxtwp3ieb = rtB . agrizcdfza ; } rtB .
bxjduwjkqo = ( ( ( 1.0 - rtP . b ) / rtP . Rb - 2.2204460492503131E-16 ) +
rtB . mxxtwp3ieb > chxvpheep2 ) ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
jfpszsfffo = ( ( ! rtB . bxjduwjkqo ) && ( rtPrevZCX . i514uivwi3 !=
ZERO_ZCSIG ) ) ; rtPrevZCX . i514uivwi3 = rtB . bxjduwjkqo ; if ( jfpszsfffo
) { rtX . fkxwshodm4 = rtP . Integrator_IC_a5b0eygpkp ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . o0mruwezip = rtX
. fkxwshodm4 ; } else { rtB . o0mruwezip = rtX . fkxwshodm4 ; } chxvpheep2 =
ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ohloxwa40r = !
rtDW . fbp5lgspzk ; rtB . dwgm1iwulr = rtDW . hobor2c3tl ; } guziuj3nzo ( rtS
, rtB . pnagitghhg [ 0 ] , rtB . gopo0ay43o , rtB . dwgm1iwulr , & rtB .
l2pxsorbc0 , & rtDW . l2pxsorbc0 ) ; obgcvvf2c2 ( rtS , rtB . pnagitghhg [ 1
] , rtB . gopo0ay43o , rtB . dwgm1iwulr , & rtB . ntt0n0z3qa , & rtDW .
ntt0n0z3qa ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . h3lftethav = rtDW
. jkafh5jkcy ; } if ( rtB . ohloxwa40r && ( rtB . l2pxsorbc0 . fncspxqpzn ||
rtB . ntt0n0z3qa . gcuafzmxgi ) ) { rtB . kiqo1dkx4d = chxvpheep2 ; } else {
rtB . kiqo1dkx4d = rtB . h3lftethav ; } rtB . lfy2bgoxg0 = ( ( rtP . b / rtP
. Rb - 2.2204460492503131E-16 ) + rtB . kiqo1dkx4d > chxvpheep2 ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsModeUpdateTimeStep ( rtS ) ) { if
( ( ! rtB . lfy2bgoxg0 ) && ( rtPrevZCX . aws53lhtcb != ZERO_ZCSIG ) ) { rtB
. amouf3rzmf = rtB . pgstwodvgn ; rtDW . kjy05jsjy1 = 4 ; } rtPrevZCX .
aws53lhtcb = rtB . lfy2bgoxg0 ; } rtB . ki1f5bwrru = muDoubleScalarAbs ( rtB
. amouf3rzmf ) ; } rtB . o51erkdynh = rtB . ki1f5bwrru - muDoubleScalarAbs (
rtB . o0mruwezip ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { f5g5ssvz0o ( rtS
, rtB . gopo0ay43o , rtB . o51erkdynh , & rtB . pokud50mlj , & rtDW .
pokud50mlj , & rtPrevZCX . pokud50mlj ) ; } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { { if ( rtDW . dke2w5vglk . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . dke2w5vglk . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . k0xpbzxvuq + 0 ) ; } } rtB . asbkydpcdt = rtP . kv2 * rtB
. pokud50mlj . n0jiemzt0m + rtP . Rb ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) )
{ rtB . mxwhtwoxqb = rtP . Multiply_Gain * rtB . cjskazwmh1 + rtP .
AddConstant_Bias ; } rtB . hzfal5kgng = ( muDoubleScalarSin (
6.2831853071795862 * rtP . Frec_port * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWave_Phase ) * rtP . AmplitudPortadora + rtP . SineWave_Bias ) * rtB .
mxwhtwoxqb ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) {
switch ( ( int32_T ) rtP . Constant1_Value_afssjxve00 ) { case 1 : rtB .
kppvt5er43 [ 0 ] = rtP . posedge_Value [ 0 ] ; rtB . kppvt5er43 [ 1 ] = rtP .
posedge_Value [ 1 ] ; break ; case 2 : rtB . kppvt5er43 [ 0 ] = rtP .
negedge_Value [ 0 ] ; rtB . kppvt5er43 [ 1 ] = rtP . negedge_Value [ 1 ] ;
break ; default : rtB . kppvt5er43 [ 0 ] = rtP . eitheredge_Value [ 0 ] ; rtB
. kppvt5er43 [ 1 ] = rtP . eitheredge_Value [ 1 ] ; break ; } switch ( (
int32_T ) rtP . Monostable1_EdgeDetect ) { case 1 : rtB . ck3j1srrxl [ 0 ] =
rtP . posedge_Value_av2r5ustik [ 0 ] ; rtB . ck3j1srrxl [ 1 ] = rtP .
posedge_Value_av2r5ustik [ 1 ] ; break ; case 2 : rtB . ck3j1srrxl [ 0 ] =
rtP . negedge_Value_fef1hh2jz4 [ 0 ] ; rtB . ck3j1srrxl [ 1 ] = rtP .
negedge_Value_fef1hh2jz4 [ 1 ] ; break ; default : rtB . ck3j1srrxl [ 0 ] =
rtP . eitheredge_Value_nntils3rkv [ 0 ] ; rtB . ck3j1srrxl [ 1 ] = rtP .
eitheredge_Value_nntils3rkv [ 1 ] ; break ; } switch ( ( int32_T ) rtP .
Monostable3_EdgeDetect ) { case 1 : rtB . pnagitghhg [ 0 ] = rtP .
posedge_Value_j0croo5cnv [ 0 ] ; rtB . pnagitghhg [ 1 ] = rtP .
posedge_Value_j0croo5cnv [ 1 ] ; break ; case 2 : rtB . pnagitghhg [ 0 ] =
rtP . negedge_Value_lnmee3h1ob [ 0 ] ; rtB . pnagitghhg [ 1 ] = rtP .
negedge_Value_lnmee3h1ob [ 1 ] ; break ; default : rtB . pnagitghhg [ 0 ] =
rtP . eitheredge_Value_gsipsgs54b [ 0 ] ; rtB . pnagitghhg [ 1 ] = rtP .
eitheredge_Value_gsipsgs54b [ 1 ] ; break ; } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { { real_T * * uBuffer = ( real_T * * ) & rtDW .
jc1itafzwd . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
kcxfvmkrf2 . Head = ( ( rtDW . kcxfvmkrf2 . Head < ( rtDW . kcxfvmkrf2 .
CircularBufSize - 1 ) ) ? ( rtDW . kcxfvmkrf2 . Head + 1 ) : 0 ) ; if ( rtDW
. kcxfvmkrf2 . Head == rtDW . kcxfvmkrf2 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . kcxfvmkrf2 . CircularBufSize , & rtDW
. kcxfvmkrf2 . Tail , & rtDW . kcxfvmkrf2 . Head , & rtDW . kcxfvmkrf2 . Last
, simTime - rtP . Retraso_Canal , uBuffer , ( boolean_T ) 0 , false , & rtDW
. kcxfvmkrf2 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Canal/Transport\nDelay_TUbuffer0" , ( void * * ) ( & uBuffer [ 0
] ) , 2 * rtDW . kcxfvmkrf2 . CircularBufSize * sizeof ( real_T ) , ( NULL )
, ( NULL ) ) ; } ( * uBuffer + rtDW . kcxfvmkrf2 . CircularBufSize ) [ rtDW .
kcxfvmkrf2 . Head ] = simTime ; ( * uBuffer ) [ rtDW . kcxfvmkrf2 . Head ] =
rtB . d4txlaulvr ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . idhuf1euoi
= rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . bzmxqssdoq ) * muDoubleScalarSqrt (
rtP . Pot_Ruido ) + rtP . RuidoAGWN_Mean ; } { real_T * * uBuffer = ( real_T
* * ) & rtDW . lj1tdbxggs . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . n2bt3cyc55 . Head = ( ( rtDW . n2bt3cyc55 . Head < ( rtDW .
n2bt3cyc55 . CircularBufSize - 1 ) ) ? ( rtDW . n2bt3cyc55 . Head + 1 ) : 0 )
; if ( rtDW . n2bt3cyc55 . Head == rtDW . n2bt3cyc55 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . n2bt3cyc55 . CircularBufSize , & rtDW
. n2bt3cyc55 . Tail , & rtDW . n2bt3cyc55 . Head , & rtDW . n2bt3cyc55 . Last
, simTime - rtP . TransportDelay_Delay , uBuffer , ( boolean_T ) 0 , false ,
& rtDW . n2bt3cyc55 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Correlación/Transport\nDelay_TUbuffer0" , ( void * * )
( & uBuffer [ 0 ] ) , 2 * rtDW . n2bt3cyc55 . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . n2bt3cyc55 .
CircularBufSize ) [ rtDW . n2bt3cyc55 . Head ] = simTime ; ( * uBuffer ) [
rtDW . n2bt3cyc55 . Head ] = rtB . gopo0ay43o ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . kia112cgkq = rtB . fv3qrvs3nd ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . ml2avl24pf . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . lcuflefjuj . Head = ( ( rtDW . lcuflefjuj . Head < (
rtDW . lcuflefjuj . CircularBufSize - 1 ) ) ? ( rtDW . lcuflefjuj . Head + 1
) : 0 ) ; if ( rtDW . lcuflefjuj . Head == rtDW . lcuflefjuj . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . lcuflefjuj . CircularBufSize , &
rtDW . lcuflefjuj . Tail , & rtDW . lcuflefjuj . Head , & rtDW . lcuflefjuj .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
lcuflefjuj . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay2_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . lcuflefjuj . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . lcuflefjuj
. CircularBufSize ) [ rtDW . lcuflefjuj . Head ] = simTime ; ( * uBuffer ) [
rtDW . lcuflefjuj . Head ] = rtB . hs04wl1crq ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . fbk251u41l . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . ovi0zqdzif . Head = ( ( rtDW . ovi0zqdzif . Head < (
rtDW . ovi0zqdzif . CircularBufSize - 1 ) ) ? ( rtDW . ovi0zqdzif . Head + 1
) : 0 ) ; if ( rtDW . ovi0zqdzif . Head == rtDW . ovi0zqdzif . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ovi0zqdzif . CircularBufSize , &
rtDW . ovi0zqdzif . Tail , & rtDW . ovi0zqdzif . Head , & rtDW . ovi0zqdzif .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
ovi0zqdzif . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay1_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . ovi0zqdzif . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . ovi0zqdzif
. CircularBufSize ) [ rtDW . ovi0zqdzif . Head ] = simTime ; ( * uBuffer ) [
rtDW . ovi0zqdzif . Head ] = rtB . bhvr0udrsy ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . kpvx4uvt01 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . advdik1iky . Head = ( ( rtDW . advdik1iky . Head < (
rtDW . advdik1iky . CircularBufSize - 1 ) ) ? ( rtDW . advdik1iky . Head + 1
) : 0 ) ; if ( rtDW . advdik1iky . Head == rtDW . advdik1iky . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . advdik1iky . CircularBufSize , &
rtDW . advdik1iky . Tail , & rtDW . advdik1iky . Head , & rtDW . advdik1iky .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
advdik1iky . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay4_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . advdik1iky . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . advdik1iky
. CircularBufSize ) [ rtDW . advdik1iky . Head ] = simTime ; ( * uBuffer ) [
rtDW . advdik1iky . Head ] = rtB . kmqtx532fz ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . oeere24mz0 . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . kb3fhgjdld . Head = ( ( rtDW . kb3fhgjdld . Head < (
rtDW . kb3fhgjdld . CircularBufSize - 1 ) ) ? ( rtDW . kb3fhgjdld . Head + 1
) : 0 ) ; if ( rtDW . kb3fhgjdld . Head == rtDW . kb3fhgjdld . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . kb3fhgjdld . CircularBufSize , &
rtDW . kb3fhgjdld . Tail , & rtDW . kb3fhgjdld . Head , & rtDW . kb3fhgjdld .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
kb3fhgjdld . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay3_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . kb3fhgjdld . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . kb3fhgjdld
. CircularBufSize ) [ rtDW . kb3fhgjdld . Head ] = simTime ; ( * uBuffer ) [
rtDW . kb3fhgjdld . Head ] = rtB . hnp1kuefxm ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . h1egexnfwb . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . ho5e0de00z . Head = ( ( rtDW . ho5e0de00z . Head < (
rtDW . ho5e0de00z . CircularBufSize - 1 ) ) ? ( rtDW . ho5e0de00z . Head + 1
) : 0 ) ; if ( rtDW . ho5e0de00z . Head == rtDW . ho5e0de00z . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ho5e0de00z . CircularBufSize , &
rtDW . ho5e0de00z . Tail , & rtDW . ho5e0de00z . Head , & rtDW . ho5e0de00z .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
ho5e0de00z . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay6_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . ho5e0de00z . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . ho5e0de00z
. CircularBufSize ) [ rtDW . ho5e0de00z . Head ] = simTime ; ( * uBuffer ) [
rtDW . ho5e0de00z . Head ] = rtB . lsnuriwz44 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . lycpuo0tla . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . dlpoyqagu4 . Head = ( ( rtDW . dlpoyqagu4 . Head < (
rtDW . dlpoyqagu4 . CircularBufSize - 1 ) ) ? ( rtDW . dlpoyqagu4 . Head + 1
) : 0 ) ; if ( rtDW . dlpoyqagu4 . Head == rtDW . dlpoyqagu4 . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . dlpoyqagu4 . CircularBufSize , &
rtDW . dlpoyqagu4 . Tail , & rtDW . dlpoyqagu4 . Head , & rtDW . dlpoyqagu4 .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
dlpoyqagu4 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay5_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . dlpoyqagu4 . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . dlpoyqagu4
. CircularBufSize ) [ rtDW . dlpoyqagu4 . Head ] = simTime ; ( * uBuffer ) [
rtDW . dlpoyqagu4 . Head ] = rtB . lisuhkiql3 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . etoiwhh4sj . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . k1nwxppvuo . Head = ( ( rtDW . k1nwxppvuo . Head < (
rtDW . k1nwxppvuo . CircularBufSize - 1 ) ) ? ( rtDW . k1nwxppvuo . Head + 1
) : 0 ) ; if ( rtDW . k1nwxppvuo . Head == rtDW . k1nwxppvuo . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . k1nwxppvuo . CircularBufSize , &
rtDW . k1nwxppvuo . Tail , & rtDW . k1nwxppvuo . Head , & rtDW . k1nwxppvuo .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
k1nwxppvuo . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay8_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . k1nwxppvuo . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . k1nwxppvuo
. CircularBufSize ) [ rtDW . k1nwxppvuo . Head ] = simTime ; ( * uBuffer ) [
rtDW . k1nwxppvuo . Head ] = rtB . ewq0jsmjdj ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . l4z1r030na . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . azfuopxupm . Head = ( ( rtDW . azfuopxupm . Head < (
rtDW . azfuopxupm . CircularBufSize - 1 ) ) ? ( rtDW . azfuopxupm . Head + 1
) : 0 ) ; if ( rtDW . azfuopxupm . Head == rtDW . azfuopxupm . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . azfuopxupm . CircularBufSize , &
rtDW . azfuopxupm . Tail , & rtDW . azfuopxupm . Head , & rtDW . azfuopxupm .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
azfuopxupm . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay7_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . azfuopxupm . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . azfuopxupm
. CircularBufSize ) [ rtDW . azfuopxupm . Head ] = simTime ; ( * uBuffer ) [
rtDW . azfuopxupm . Head ] = rtB . dv3oqsxz41 ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . e3lmwmye5o . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . bnqksyhx4b . Head = ( ( rtDW . bnqksyhx4b . Head < (
rtDW . bnqksyhx4b . CircularBufSize - 1 ) ) ? ( rtDW . bnqksyhx4b . Head + 1
) : 0 ) ; if ( rtDW . bnqksyhx4b . Head == rtDW . bnqksyhx4b . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . bnqksyhx4b . CircularBufSize , &
rtDW . bnqksyhx4b . Tail , & rtDW . bnqksyhx4b . Head , & rtDW . bnqksyhx4b .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
bnqksyhx4b . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay9_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . bnqksyhx4b . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . bnqksyhx4b
. CircularBufSize ) [ rtDW . bnqksyhx4b . Head ] = simTime ; ( * uBuffer ) [
rtDW . bnqksyhx4b . Head ] = rtB . nz2mzf3abt ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . mxtwjhbmuw . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . jsj5ows1gx . Head = ( ( rtDW . jsj5ows1gx . Head < (
rtDW . jsj5ows1gx . CircularBufSize - 1 ) ) ? ( rtDW . jsj5ows1gx . Head + 1
) : 0 ) ; if ( rtDW . jsj5ows1gx . Head == rtDW . jsj5ows1gx . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . jsj5ows1gx . CircularBufSize , &
rtDW . jsj5ows1gx . Tail , & rtDW . jsj5ows1gx . Head , & rtDW . jsj5ows1gx .
Last , simTime - rtP . Tb , uBuffer , ( boolean_T ) 0 , false , & rtDW .
jsj5ows1gx . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport\nDelay11_TUbuffer0" , (
void * * ) ( & uBuffer [ 0 ] ) , 2 * rtDW . jsj5ows1gx . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . jsj5ows1gx
. CircularBufSize ) [ rtDW . jsj5ows1gx . Head ] = simTime ; ( * uBuffer ) [
rtDW . jsj5ows1gx . Head ] = rtB . geeegghaq4 ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . igyctbswok = rtB . efvczhdjet ; rtDW . cuilob0auh = rtB .
jfofwf5qdn ; rtDW . llqwbguanw = rtB . pet04kmorq ; rtDW . i3eziu3f1n = rtB .
bxjduwjkqo ; rtDW . g4c0zz45r4 = rtB . gopo0ay43o ; rtDW . gamney3fyk = rtB .
mxxtwp3ieb ; rtDW . fbp5lgspzk = rtB . lfy2bgoxg0 ; rtDW . hobor2c3tl = rtB .
gopo0ay43o ; rtDW . jkafh5jkcy = rtB . kiqo1dkx4d ; } UNUSED_PARAMETER ( tid
) ; } void MdlUpdateTID4 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; int_T is ; uint32_T ri ; _rtXdot =
( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> amtjz55qss [ 0 ] = 0.0 ; _rtXdot
-> amtjz55qss [ 1 ] = 0.0 ; _rtXdot -> amtjz55qss [ 2 ] = 0.0 ; _rtXdot ->
amtjz55qss [ 3 ] = 0.0 ; for ( ri = rtP . AnalogFilterDesign_A_jc [ 0U ] ; ri
< rtP . AnalogFilterDesign_A_jc [ 1U ] ; ri ++ ) { _rtXdot -> amtjz55qss [
rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP . AnalogFilterDesign_A_pr [ ri
] * rtX . amtjz55qss [ 0U ] ; } for ( ri = rtP . AnalogFilterDesign_A_jc [ 1U
] ; ri < rtP . AnalogFilterDesign_A_jc [ 2U ] ; ri ++ ) { _rtXdot ->
amtjz55qss [ rtP . AnalogFilterDesign_A_ir [ ri ] ] += rtP .
AnalogFilterDesign_A_pr [ ri ] * rtX . amtjz55qss [ 1U ] ; } for ( ri = rtP .
AnalogFilterDesign_A_jc [ 2U ] ; ri < rtP . AnalogFilterDesign_A_jc [ 3U ] ;
ri ++ ) { _rtXdot -> amtjz55qss [ rtP . AnalogFilterDesign_A_ir [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . amtjz55qss [ 2U ] ; } for ( ri =
rtP . AnalogFilterDesign_A_jc [ 3U ] ; ri < rtP . AnalogFilterDesign_A_jc [
4U ] ; ri ++ ) { _rtXdot -> amtjz55qss [ rtP . AnalogFilterDesign_A_ir [ ri ]
] += rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . amtjz55qss [ 3U ] ; } for (
ri = rtP . AnalogFilterDesign_B_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc [ 1U ] ; ri ++ ) { _rtXdot -> amtjz55qss [ rtP .
AnalogFilterDesign_B_ir ] += rtP . AnalogFilterDesign_B_pr * rtB . hzfal5kgng
; } _rtXdot -> jpbcgznxiw [ 0 ] = 0.0 ; _rtXdot -> jpbcgznxiw [ 1 ] = 0.0 ;
_rtXdot -> jpbcgznxiw [ 2 ] = 0.0 ; _rtXdot -> jpbcgznxiw [ 3 ] = 0.0 ; for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 0U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 1U ] ; ri ++ ) { _rtXdot -> jpbcgznxiw [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . jpbcgznxiw [ 0U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 1U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 2U ] ; ri ++ ) { _rtXdot -> jpbcgznxiw [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . jpbcgznxiw [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 2U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 3U ] ; ri ++ ) { _rtXdot -> jpbcgznxiw [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . jpbcgznxiw [ 2U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_fyftqxybap [ 3U ] ; ri < rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 4U ] ; ri ++ ) { _rtXdot -> jpbcgznxiw [
rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_jsdcqwampi [ ri ] * rtX . jpbcgznxiw [ 3U ] ; } for (
ri = rtP . AnalogFilterDesign_B_jc_nk0ranamkl [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc_nk0ranamkl [ 1U ] ; ri ++ ) { _rtXdot -> jpbcgznxiw [
rtP . AnalogFilterDesign_B_ir_gklrfvy2xp ] += rtP .
AnalogFilterDesign_B_pr_om0jg41jmb * rtB . cjvhltyh5i ; } _rtXdot ->
gax2n2uyhb = rtB . ncgerps2w1 ; _rtXdot -> lzv0rcie1i = rtB . asbkydpcdt ;
_rtXdot -> adtcefug1k [ 0 ] = 0.0 ; _rtXdot -> adtcefug1k [ 1 ] = 0.0 ;
_rtXdot -> adtcefug1k [ 2 ] = 0.0 ; _rtXdot -> adtcefug1k [ 3 ] = 0.0 ; for (
ri = rtP . AnalogFilterDesign_A_jc_hepc5hv3fw [ 0U ] ; ri < rtP .
AnalogFilterDesign_A_jc_hepc5hv3fw [ 1U ] ; ri ++ ) { _rtXdot -> adtcefug1k [
rtP . AnalogFilterDesign_A_ir_o3wehlil1t [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_gc0kz31g5a [ ri ] * rtX . adtcefug1k [ 0U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_hepc5hv3fw [ 1U ] ; ri < rtP .
AnalogFilterDesign_A_jc_hepc5hv3fw [ 2U ] ; ri ++ ) { _rtXdot -> adtcefug1k [
rtP . AnalogFilterDesign_A_ir_o3wehlil1t [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_gc0kz31g5a [ ri ] * rtX . adtcefug1k [ 1U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_hepc5hv3fw [ 2U ] ; ri < rtP .
AnalogFilterDesign_A_jc_hepc5hv3fw [ 3U ] ; ri ++ ) { _rtXdot -> adtcefug1k [
rtP . AnalogFilterDesign_A_ir_o3wehlil1t [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_gc0kz31g5a [ ri ] * rtX . adtcefug1k [ 2U ] ; } for (
ri = rtP . AnalogFilterDesign_A_jc_hepc5hv3fw [ 3U ] ; ri < rtP .
AnalogFilterDesign_A_jc_hepc5hv3fw [ 4U ] ; ri ++ ) { _rtXdot -> adtcefug1k [
rtP . AnalogFilterDesign_A_ir_o3wehlil1t [ ri ] ] += rtP .
AnalogFilterDesign_A_pr_gc0kz31g5a [ ri ] * rtX . adtcefug1k [ 3U ] ; } for (
ri = rtP . AnalogFilterDesign_B_jc_cfquo51aq1 [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc_cfquo51aq1 [ 1U ] ; ri ++ ) { _rtXdot -> adtcefug1k [
rtP . AnalogFilterDesign_B_ir_bqybfmsaae ] += rtP .
AnalogFilterDesign_B_pr_kq1k3m2fjm * rtB . bfrc2rc5zl ; } for ( is = 0 ; is <
8 ; is ++ ) { _rtXdot -> e5d2w4theu [ is ] = 0.0 ; } for ( is = 0 ; is < 8 ;
is ++ ) { for ( ri = rtP . AnalogFilterDesign_A_jc_h5xar20tzm [ ( uint32_T )
is ] ; ri < rtP . AnalogFilterDesign_A_jc_h5xar20tzm [ is + 1U ] ; ri ++ ) {
_rtXdot -> e5d2w4theu [ rtP . AnalogFilterDesign_A_ir_cx1zj2mhzp [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr_f4zixacbw1 [ ri ] * rtX . e5d2w4theu [ (
uint32_T ) is ] ; } } for ( ri = rtP . AnalogFilterDesign_B_jc_acwf2d2gj0 [
0U ] ; ri < rtP . AnalogFilterDesign_B_jc_acwf2d2gj0 [ 1U ] ; ri ++ ) {
_rtXdot -> e5d2w4theu [ rtP . AnalogFilterDesign_B_ir_nneewrak4c ] += rtP .
AnalogFilterDesign_B_pr_by1sufu2fg * rtB . dzwzyjfb3d ; } _rtXdot ->
lpelu0o3uv = rtB . pxicmncoih ; _rtXdot -> ef1jjuhfsz = rtB . awbajcw3bs ;
_rtXdot -> bwxjromtln = rtB . k0xpbzxvuq ; _rtXdot -> fkxwshodm4 = rtB .
k0xpbzxvuq ; } void MdlProjection ( void ) { } void MdlTerminate ( void ) {
rt_FREE ( rtDW . c550b3xklm . RSimInfoPtr ) ; rt_TDelayFreeBuf ( rtDW .
jc1itafzwd . TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . lj1tdbxggs .
TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . ml2avl24pf . TUbufferPtrs [
0 ] ) ; rt_TDelayFreeBuf ( rtDW . fbk251u41l . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . kpvx4uvt01 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . oeere24mz0 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . h1egexnfwb . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . lycpuo0tla . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . etoiwhh4sj . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . l4z1r030na . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . e3lmwmye5o . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . mxtwjhbmuw . TUbufferPtrs [ 0 ] ) ; { if ( rtDW .
ivu5m05flg . AQHandles ) { sdiTerminateStreaming ( & rtDW . ivu5m05flg .
AQHandles ) ; } } { if ( rtDW . dke2w5vglk . AQHandles ) {
sdiTerminateStreaming ( & rtDW . dke2w5vglk . AQHandles ) ; } } } static void
mr_modPSK_mod3_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_modPSK_mod3_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_modPSK_mod3_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_modPSK_mod3_restoreDataFromMxArray ( void * destData , const mxArray
* srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_modPSK_mod3_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_modPSK_mod3_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_modPSK_mod3_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_modPSK_mod3_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_modPSK_mod3_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_modPSK_mod3_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
{ uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber (
destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes
] , ( const uint8_T * ) srcData , numBytes ) ; } static void
mr_modPSK_mod3_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_modPSK_mod3_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_modPSK_mod3_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray
, mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_modPSK_mod3_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_modPSK_mod3_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_modPSK_mod3_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_modPSK_mod3_GetDWork ( ) { static const char *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB )
, sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 56 ] = {
"rtDW.idhuf1euoi" , "rtDW.cuilob0auh" , "rtDW.g4c0zz45r4" , "rtDW.gamney3fyk"
, "rtDW.hobor2c3tl" , "rtDW.jkafh5jkcy" , "rtDW.lddp3kj4wc" ,
"rtDW.bj4mi1vzil" , "rtDW.p5cigbuwvn" , "rtDW.gf4lfoijb0" , "rtDW.okq3xbd2ii"
, "rtDW.iobbwey3sn" , "rtDW.e334mwrkee" , "rtDW.pryezgtgn4" ,
"rtDW.hzbip0oysg" , "rtDW.huh20tu5q1" , "rtDW.agxdp5talt" , "rtDW.nb2ebbj1qe"
, "rtDW.bzmxqssdoq" , "rtDW.kb5rvgdujd" , "rtDW.kcxfvmkrf2" ,
"rtDW.n2bt3cyc55" , "rtDW.lcuflefjuj" , "rtDW.ovi0zqdzif" , "rtDW.advdik1iky"
, "rtDW.kb3fhgjdld" , "rtDW.ho5e0de00z" , "rtDW.dlpoyqagu4" ,
"rtDW.k1nwxppvuo" , "rtDW.azfuopxupm" , "rtDW.bnqksyhx4b" , "rtDW.jsj5ows1gx"
, "rtDW.ajzqjdehhp" , "rtDW.kjy05jsjy1" , "rtDW.mt4cgs1ctq" ,
"rtDW.jggqbqxmox" , "rtDW.bluxjvuquj" , "rtDW.pu1wrg42xz" , "rtDW.kia112cgkq"
, "rtDW.igyctbswok" , "rtDW.llqwbguanw" , "rtDW.i3eziu3f1n" ,
"rtDW.fbp5lgspzk" , "rtDW.nrn32puwjn" , "rtDW.ckhj2mjol3" , "rtDW.haenchykp4"
, "rtDW.pokud50mlj.kw45gvclvl" , "rtDW.l2pxsorbc0.mzbzupg3uq" ,
"rtDW.l2pxsorbc0.miqumv2j33" , "rtDW.ntt0n0z3qa.igzqysubwr" ,
"rtDW.ntt0n0z3qa.jfiw2hmwe4" , "rtDW.guziuj3nzou.mzbzupg3uq" ,
"rtDW.guziuj3nzou.miqumv2j33" , "rtDW.obgcvvf2c2c.igzqysubwr" ,
"rtDW.obgcvvf2c2c.jfiw2hmwe4" , "rtDW.f5g5ssvz0ob.kw45gvclvl" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 56 , rtdwDataFieldNames ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & (
rtDW . idhuf1euoi ) , sizeof ( rtDW . idhuf1euoi ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . cuilob0auh ) , sizeof ( rtDW . cuilob0auh ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . g4c0zz45r4 ) , sizeof ( rtDW . g4c0zz45r4 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . gamney3fyk ) , sizeof ( rtDW . gamney3fyk ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . hobor2c3tl ) , sizeof ( rtDW . hobor2c3tl ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . jkafh5jkcy ) , sizeof ( rtDW . jkafh5jkcy ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . lddp3kj4wc ) , sizeof ( rtDW . lddp3kj4wc ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . bj4mi1vzil ) , sizeof ( rtDW . bj4mi1vzil ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . p5cigbuwvn ) , sizeof ( rtDW . p5cigbuwvn ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . gf4lfoijb0 ) , sizeof ( rtDW . gf4lfoijb0 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . okq3xbd2ii ) , sizeof ( rtDW . okq3xbd2ii ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . iobbwey3sn ) , sizeof ( rtDW . iobbwey3sn ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . e334mwrkee ) , sizeof ( rtDW . e334mwrkee ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . pryezgtgn4 ) , sizeof ( rtDW . pryezgtgn4 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & (
rtDW . hzbip0oysg ) , sizeof ( rtDW . hzbip0oysg ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & (
rtDW . huh20tu5q1 ) , sizeof ( rtDW . huh20tu5q1 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & (
rtDW . agxdp5talt ) , sizeof ( rtDW . agxdp5talt ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & (
rtDW . nb2ebbj1qe ) , sizeof ( rtDW . nb2ebbj1qe ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & (
rtDW . bzmxqssdoq ) , sizeof ( rtDW . bzmxqssdoq ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & (
rtDW . kb5rvgdujd ) , sizeof ( rtDW . kb5rvgdujd ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & (
rtDW . kcxfvmkrf2 ) , sizeof ( rtDW . kcxfvmkrf2 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & (
rtDW . n2bt3cyc55 ) , sizeof ( rtDW . n2bt3cyc55 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & (
rtDW . lcuflefjuj ) , sizeof ( rtDW . lcuflefjuj ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & (
rtDW . ovi0zqdzif ) , sizeof ( rtDW . ovi0zqdzif ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & (
rtDW . advdik1iky ) , sizeof ( rtDW . advdik1iky ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & (
rtDW . kb3fhgjdld ) , sizeof ( rtDW . kb3fhgjdld ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & (
rtDW . ho5e0de00z ) , sizeof ( rtDW . ho5e0de00z ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & (
rtDW . dlpoyqagu4 ) , sizeof ( rtDW . dlpoyqagu4 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & (
rtDW . k1nwxppvuo ) , sizeof ( rtDW . k1nwxppvuo ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & (
rtDW . azfuopxupm ) , sizeof ( rtDW . azfuopxupm ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & (
rtDW . bnqksyhx4b ) , sizeof ( rtDW . bnqksyhx4b ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & (
rtDW . jsj5ows1gx ) , sizeof ( rtDW . jsj5ows1gx ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & (
rtDW . ajzqjdehhp ) , sizeof ( rtDW . ajzqjdehhp ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & (
rtDW . kjy05jsjy1 ) , sizeof ( rtDW . kjy05jsjy1 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & (
rtDW . mt4cgs1ctq ) , sizeof ( rtDW . mt4cgs1ctq ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) & (
rtDW . jggqbqxmox ) , sizeof ( rtDW . jggqbqxmox ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) & (
rtDW . bluxjvuquj ) , sizeof ( rtDW . bluxjvuquj ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) & (
rtDW . pu1wrg42xz ) , sizeof ( rtDW . pu1wrg42xz ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) & (
rtDW . kia112cgkq ) , sizeof ( rtDW . kia112cgkq ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) & (
rtDW . igyctbswok ) , sizeof ( rtDW . igyctbswok ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void * ) & (
rtDW . llqwbguanw ) , sizeof ( rtDW . llqwbguanw ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) & (
rtDW . i3eziu3f1n ) , sizeof ( rtDW . i3eziu3f1n ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void * ) & (
rtDW . fbp5lgspzk ) , sizeof ( rtDW . fbp5lgspzk ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void * ) & (
rtDW . nrn32puwjn ) , sizeof ( rtDW . nrn32puwjn ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) & (
rtDW . ckhj2mjol3 ) , sizeof ( rtDW . ckhj2mjol3 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void * ) & (
rtDW . haenchykp4 ) , sizeof ( rtDW . haenchykp4 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void * ) & (
rtDW . pokud50mlj . kw45gvclvl ) , sizeof ( rtDW . pokud50mlj . kw45gvclvl )
) ; mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * )
& ( rtDW . l2pxsorbc0 . mzbzupg3uq ) , sizeof ( rtDW . l2pxsorbc0 .
mzbzupg3uq ) ) ; mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 48 , (
const void * ) & ( rtDW . l2pxsorbc0 . miqumv2j33 ) , sizeof ( rtDW .
l2pxsorbc0 . miqumv2j33 ) ) ; mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData ,
0 , 49 , ( const void * ) & ( rtDW . ntt0n0z3qa . igzqysubwr ) , sizeof (
rtDW . ntt0n0z3qa . igzqysubwr ) ) ; mr_modPSK_mod3_cacheDataAsMxArray (
rtdwData , 0 , 50 , ( const void * ) & ( rtDW . ntt0n0z3qa . jfiw2hmwe4 ) ,
sizeof ( rtDW . ntt0n0z3qa . jfiw2hmwe4 ) ) ;
mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void * ) & (
rtDW . guziuj3nzou . mzbzupg3uq ) , sizeof ( rtDW . guziuj3nzou . mzbzupg3uq
) ) ; mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void *
) & ( rtDW . guziuj3nzou . miqumv2j33 ) , sizeof ( rtDW . guziuj3nzou .
miqumv2j33 ) ) ; mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData , 0 , 53 , (
const void * ) & ( rtDW . obgcvvf2c2c . igzqysubwr ) , sizeof ( rtDW .
obgcvvf2c2c . igzqysubwr ) ) ; mr_modPSK_mod3_cacheDataAsMxArray ( rtdwData ,
0 , 54 , ( const void * ) & ( rtDW . obgcvvf2c2c . jfiw2hmwe4 ) , sizeof (
rtDW . obgcvvf2c2c . jfiw2hmwe4 ) ) ; mr_modPSK_mod3_cacheDataAsMxArray (
rtdwData , 0 , 55 , ( const void * ) & ( rtDW . f5g5ssvz0ob . kw45gvclvl ) ,
sizeof ( rtDW . f5g5ssvz0ob . kw45gvclvl ) ) ; mxSetFieldByNumber ( ssDW , 0
, 1 , rtdwData ) ; } mr_modPSK_mod3_cacheDataAsMxArray ( ssDW , 0 , 2 , (
const void * ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ; }
void mr_modPSK_mod3_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW .
idhuf1euoi ) , rtdwData , 0 , 0 , sizeof ( rtDW . idhuf1euoi ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . cuilob0auh ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . cuilob0auh ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . g4c0zz45r4 ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . g4c0zz45r4 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . gamney3fyk ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . gamney3fyk ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . hobor2c3tl ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . hobor2c3tl ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . jkafh5jkcy ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . jkafh5jkcy ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . lddp3kj4wc ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . lddp3kj4wc ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . bj4mi1vzil ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . bj4mi1vzil ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . p5cigbuwvn ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . p5cigbuwvn ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . gf4lfoijb0 ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . gf4lfoijb0 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . okq3xbd2ii ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . okq3xbd2ii ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . iobbwey3sn ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . iobbwey3sn ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . e334mwrkee ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . e334mwrkee ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . pryezgtgn4 ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . pryezgtgn4 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . hzbip0oysg ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . hzbip0oysg ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . huh20tu5q1 ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . huh20tu5q1 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . agxdp5talt ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . agxdp5talt ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . nb2ebbj1qe ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . nb2ebbj1qe ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . bzmxqssdoq ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . bzmxqssdoq ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . kb5rvgdujd ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . kb5rvgdujd ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . kcxfvmkrf2 ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . kcxfvmkrf2 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . n2bt3cyc55 ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . n2bt3cyc55 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . lcuflefjuj ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . lcuflefjuj ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . ovi0zqdzif ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . ovi0zqdzif ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . advdik1iky ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . advdik1iky ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . kb3fhgjdld ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . kb3fhgjdld ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . ho5e0de00z ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . ho5e0de00z ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . dlpoyqagu4 ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . dlpoyqagu4 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . k1nwxppvuo ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . k1nwxppvuo ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . azfuopxupm ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . azfuopxupm ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . bnqksyhx4b ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . bnqksyhx4b ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . jsj5ows1gx ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . jsj5ows1gx ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . ajzqjdehhp ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . ajzqjdehhp ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . kjy05jsjy1 ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . kjy05jsjy1 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . mt4cgs1ctq ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . mt4cgs1ctq ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . jggqbqxmox ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . jggqbqxmox ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . bluxjvuquj ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . bluxjvuquj ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . pu1wrg42xz ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . pu1wrg42xz ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . kia112cgkq ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . kia112cgkq ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . igyctbswok ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . igyctbswok ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . llqwbguanw ) ,
rtdwData , 0 , 40 , sizeof ( rtDW . llqwbguanw ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . i3eziu3f1n ) ,
rtdwData , 0 , 41 , sizeof ( rtDW . i3eziu3f1n ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . fbp5lgspzk ) ,
rtdwData , 0 , 42 , sizeof ( rtDW . fbp5lgspzk ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . nrn32puwjn ) ,
rtdwData , 0 , 43 , sizeof ( rtDW . nrn32puwjn ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . ckhj2mjol3 ) ,
rtdwData , 0 , 44 , sizeof ( rtDW . ckhj2mjol3 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . haenchykp4 ) ,
rtdwData , 0 , 45 , sizeof ( rtDW . haenchykp4 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . pokud50mlj .
kw45gvclvl ) , rtdwData , 0 , 46 , sizeof ( rtDW . pokud50mlj . kw45gvclvl )
) ; mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . l2pxsorbc0
. mzbzupg3uq ) , rtdwData , 0 , 47 , sizeof ( rtDW . l2pxsorbc0 . mzbzupg3uq
) ) ; mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l2pxsorbc0 . miqumv2j33 ) , rtdwData , 0 , 48 , sizeof ( rtDW . l2pxsorbc0 .
miqumv2j33 ) ) ; mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW
. ntt0n0z3qa . igzqysubwr ) , rtdwData , 0 , 49 , sizeof ( rtDW . ntt0n0z3qa
. igzqysubwr ) ) ; mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & (
rtDW . ntt0n0z3qa . jfiw2hmwe4 ) , rtdwData , 0 , 50 , sizeof ( rtDW .
ntt0n0z3qa . jfiw2hmwe4 ) ) ; mr_modPSK_mod3_restoreDataFromMxArray ( ( void
* ) & ( rtDW . guziuj3nzou . mzbzupg3uq ) , rtdwData , 0 , 51 , sizeof ( rtDW
. guziuj3nzou . mzbzupg3uq ) ) ; mr_modPSK_mod3_restoreDataFromMxArray ( (
void * ) & ( rtDW . guziuj3nzou . miqumv2j33 ) , rtdwData , 0 , 52 , sizeof (
rtDW . guziuj3nzou . miqumv2j33 ) ) ; mr_modPSK_mod3_restoreDataFromMxArray (
( void * ) & ( rtDW . obgcvvf2c2c . igzqysubwr ) , rtdwData , 0 , 53 , sizeof
( rtDW . obgcvvf2c2c . igzqysubwr ) ) ; mr_modPSK_mod3_restoreDataFromMxArray
( ( void * ) & ( rtDW . obgcvvf2c2c . jfiw2hmwe4 ) , rtdwData , 0 , 54 ,
sizeof ( rtDW . obgcvvf2c2c . jfiw2hmwe4 ) ) ;
mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtDW . f5g5ssvz0ob .
kw45gvclvl ) , rtdwData , 0 , 55 , sizeof ( rtDW . f5g5ssvz0ob . kw45gvclvl )
) ; } mr_modPSK_mod3_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) ,
ssDW , 0 , 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_modPSK_mod3_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 7 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 7 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , } ; static const char * blockPath [ 7 ] = {
"modPSK_mod3/Scope" , "modPSK_mod3/Canal/Scope" ,
"modPSK_mod3/Receptor/Scope" , "modPSK_mod3/Receptor/Detector/Scope" ,
"modPSK_mod3/Receptor/Sincronismo de Trama/Scope1" ,
"modPSK_mod3/Receptor/Sincronismo de s&#xED;mbolo/Scope1" ,
"modPSK_mod3/Transmisor/Scope" , } ; static const int reason [ 7 ] = { 0 , 0
, 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 7 ; ++ ( subs [
0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 26 ) ; ssSetNumPeriodicContStates ( rtS , 2 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 4 ) ; ssSetNumBlocks ( rtS , 176 ) ;
ssSetNumBlockIO ( rtS , 71 ) ; ssSetNumBlockParams ( rtS , 1377 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 2.5E-7 ) ;
ssSetSampleTime ( rtS , 3 , 0.0001 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1850872603U ) ; ssSetChecksumVal ( rtS , 1 ,
165999143U ) ; ssSetChecksumVal ( rtS , 2 , 1301383288U ) ; ssSetChecksumVal
( rtS , 3 , 1439320884U ) ; }
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
( B ) ) ; { rtB . cjskazwmh1 = 0.0 ; rtB . d4txlaulvr = 0.0 ; rtB .
f2es2rkn4r = 0.0 ; rtB . ailrsbpb25 = 0.0 ; rtB . bfrc2rc5zl = 0.0 ; rtB .
ncdgrorzsx = 0.0 ; rtB . pl5zjiseby = 0.0 ; rtB . nihlui3tdy = 0.0 ; rtB .
gopo0ay43o = 0.0 ; rtB . hs04wl1crq = 0.0 ; rtB . pznu3l5z1a = 0.0 ; rtB .
bhvr0udrsy = 0.0 ; rtB . kmqtx532fz = 0.0 ; rtB . hnp1kuefxm = 0.0 ; rtB .
lsnuriwz44 = 0.0 ; rtB . lisuhkiql3 = 0.0 ; rtB . ewq0jsmjdj = 0.0 ; rtB .
dv3oqsxz41 = 0.0 ; rtB . nz2mzf3abt = 0.0 ; rtB . geeegghaq4 = 0.0 ; rtB .
eancnret3z = 0.0 ; rtB . m2vnyqktog = 0.0 ; rtB . k3la20515u = 0.0 ; rtB .
jfofwf5qdn = 0.0 ; rtB . k0hg52okk1 = 0.0 ; rtB . dxje1nzfb1 = 0.0 ; rtB .
lrg23dznf5 = 0.0 ; rtB . ncgerps2w1 = 0.0 ; rtB . dzwzyjfb3d = 0.0 ; rtB .
c1tvvwnguu = 0.0 ; rtB . pxicmncoih = 0.0 ; rtB . ao3hvbk03u = 0.0 ; rtB .
cjvhltyh5i = 0.0 ; rtB . awbajcw3bs = 0.0 ; rtB . k0xpbzxvuq = 0.0 ; rtB .
pgstwodvgn = 0.0 ; rtB . ji14ejc3mp = 0.0 ; rtB . agrizcdfza = 0.0 ; rtB .
mxxtwp3ieb = 0.0 ; rtB . o0mruwezip = 0.0 ; rtB . dwgm1iwulr = 0.0 ; rtB .
h3lftethav = 0.0 ; rtB . kiqo1dkx4d = 0.0 ; rtB . ki1f5bwrru = 0.0 ; rtB .
o51erkdynh = 0.0 ; rtB . asbkydpcdt = 0.0 ; rtB . mxwhtwoxqb = 0.0 ; rtB .
hzfal5kgng = 0.0 ; rtB . kppvt5er43 [ 0 ] = 0.0 ; rtB . kppvt5er43 [ 1 ] =
0.0 ; rtB . ck3j1srrxl [ 0 ] = 0.0 ; rtB . ck3j1srrxl [ 1 ] = 0.0 ; rtB .
pnagitghhg [ 0 ] = 0.0 ; rtB . pnagitghhg [ 1 ] = 0.0 ; rtB . amouf3rzmf =
0.0 ; rtB . pokud50mlj . n0jiemzt0m = 0.0 ; rtB . f5g5ssvz0ob . n0jiemzt0m =
0.0 ; } } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; (
void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void
* ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 ,
sizeof ( DW ) ) ; rtDW . idhuf1euoi = 0.0 ; rtDW . cuilob0auh = 0.0 ; rtDW .
g4c0zz45r4 = 0.0 ; rtDW . gamney3fyk = 0.0 ; rtDW . hobor2c3tl = 0.0 ; rtDW .
jkafh5jkcy = 0.0 ; rtDW . lddp3kj4wc . modelTStart = 0.0 ; rtDW . bj4mi1vzil
. modelTStart = 0.0 ; rtDW . p5cigbuwvn . modelTStart = 0.0 ; rtDW .
gf4lfoijb0 . modelTStart = 0.0 ; rtDW . okq3xbd2ii . modelTStart = 0.0 ; rtDW
. iobbwey3sn . modelTStart = 0.0 ; rtDW . e334mwrkee . modelTStart = 0.0 ;
rtDW . pryezgtgn4 . modelTStart = 0.0 ; rtDW . hzbip0oysg . modelTStart = 0.0
; rtDW . huh20tu5q1 . modelTStart = 0.0 ; rtDW . agxdp5talt . modelTStart =
0.0 ; rtDW . nb2ebbj1qe . modelTStart = 0.0 ; } { static DataTypeTransInfo
dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 22 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } modPSK_mod3_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"modPSK_mod3" ) ; ssSetPath ( rtS , "modPSK_mod3" ) ; ssSetTStart ( rtS , 0.0
) ; ssSetTFinal ( rtS , 0.12000000000000001 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 4 , 4 , 1 , 1 , 4 , 8 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 } ; static int_T rt_LoggedStateDimensions [ ] = { 4 , 4 , 1 , 1 , 4 , 8 , 1
, 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds
[ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE
, SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [
] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"modPSK_mod3/Transmisor/Analog\nFilter Design" ,
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog\nFilter Design" ,
"modPSK_mod3/Receptor/Correlaci&#xF3;n/Integrator" ,
 "modPSK_mod3/Receptor/Sincronismo de s&#xED;mbolo/Continuous-Time\nVCO/Modulo \nIntegrator/Modulo\nIntegrator"
, "modPSK_mod3/Receptor/Analog\nFilter Design" ,
"modPSK_mod3/Receptor/Correlaci&#xF3;n/Analog\nFilter Design" ,
 "modPSK_mod3/Receptor/Sincronismo de portadora/\nVCO/Modulo \nIntegrator/Modulo\nIntegrator"
, "modPSK_mod3/Receptor/Sincronismo de portadora/Integrator" ,
"modPSK_mod3/Receptor/Sincronismo de s&#xED;mbolo/Integrator1" ,
"modPSK_mod3/Receptor/Sincronismo de s&#xED;mbolo/Integrator" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 ,
2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 10 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 10 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . amtjz55qss [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . jpbcgznxiw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . gax2n2uyhb ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . lzv0rcie1i ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . adtcefug1k [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . e5d2w4theu [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . lpelu0o3uv ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . ef1jjuhfsz ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . bwxjromtln ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . fkxwshodm4 ; }
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
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 26 ] ;
static real_T absTol [ 26 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [
26 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 26 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 26 ] ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 4 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
mxwhtwoxqb ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
asbkydpcdt ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cjvhltyh5i ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ailrsbpb25 ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 26 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 2.5E-7
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 4 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
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
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . h30gjmuzs5 = UNINITIALIZED_ZCSIG ; rtPrevZCX .
ct04cv1aou = UNINITIALIZED_ZCSIG ; rtPrevZCX . i514uivwi3 =
UNINITIALIZED_ZCSIG ; rtPrevZCX . neekdr5ik0 = POS_ZCSIG ; rtPrevZCX .
ph4ircn3eg = UNINITIALIZED_ZCSIG ; rtPrevZCX . aws53lhtcb = ZERO_ZCSIG ;
rtPrevZCX . gma50kdl5l = UNINITIALIZED_ZCSIG ; rtPrevZCX . pokud50mlj .
pfohtyb5z1 = UNINITIALIZED_ZCSIG ; rtPrevZCX . f5g5ssvz0ob . pfohtyb5z1 =
UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS , 0 , 1850872603U ) ;
ssSetChecksumVal ( rtS , 1 , 165999143U ) ; ssSetChecksumVal ( rtS , 2 ,
1301383288U ) ; ssSetChecksumVal ( rtS , 3 , 1439320884U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 13 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . f5g5ssvz0ob . kw45gvclvl ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . pu1wrg42xz ; systemRan [ 3 ] = ( sysRanDType * ) &
rtDW . bluxjvuquj ; systemRan [ 4 ] = ( sysRanDType * ) & rtDW . jggqbqxmox ;
systemRan [ 5 ] = ( sysRanDType * ) & rtDW . mt4cgs1ctq ; systemRan [ 6 ] = (
sysRanDType * ) & rtDW . obgcvvf2c2c . igzqysubwr ; systemRan [ 7 ] = (
sysRanDType * ) & rtDW . guziuj3nzou . mzbzupg3uq ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . ntt0n0z3qa . igzqysubwr ; systemRan [ 9 ] = (
sysRanDType * ) & rtDW . l2pxsorbc0 . mzbzupg3uq ; systemRan [ 10 ] = (
sysRanDType * ) & rtDW . kjy05jsjy1 ; systemRan [ 11 ] = ( sysRanDType * ) &
rtDW . pokud50mlj . kw45gvclvl ; systemRan [ 12 ] = ( sysRanDType * ) & rtDW
. ajzqjdehhp ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_modPSK_mod3_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_modPSK_mod3_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_modPSK_mod3_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
