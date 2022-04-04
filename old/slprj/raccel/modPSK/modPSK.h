#ifndef RTW_HEADER_modPSK_h_
#define RTW_HEADER_modPSK_h_
#include <string.h>
#include <stddef.h>
#include <float.h>
#include "rtw_modelmap_simtarget.h"
#include <stdio.h>
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "modPSK_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME modPSK
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (77) 
#define NUM_ZC_EVENTS (9) 
#ifndef NCSTATES
#define NCSTATES (22)   
#elif NCSTATES != 22
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T olytfz4wp1 ; } hzskem2oxy ; typedef struct { int8_T
j13iuzvksk ; } jayuearsj1 ; typedef struct { real_T fxkvl3okqx ; } peywaezwuq
; typedef struct { ZCSigState pbvwazbpud ; } l32trj3bao ; typedef struct {
boolean_T e5aa54psh5 ; } m0godxqmay ; typedef struct { int8_T o0iconal0v ; }
dturppu2h0 ; typedef struct { boolean_T k0x4is02ar ; } jjavt2chnr ; typedef
struct { int8_T o3j2yaswp3 ; } fucri11br2 ; typedef struct { real_T
ee42tgof2b ; real_T o5tdwwqd3u ; real_T p5kktr1wyk ; real_T mvhgymrwqe ;
real_T gqtvp2z5yf ; real_T d4ytgmijes ; real_T ijwiii2est ; real_T krai04vzyy
; real_T exkkdo4tfp ; real_T fpr0eiute3 ; real_T kqemtml2w3 ; real_T
da4cqxiizn ; real_T atcqfparc4 ; real_T c2cnah1c34 ; real_T ooymnwvq5a ;
real_T ijuklwld0a ; real_T nryqbxo330 ; real_T hihmi4odjo ; real_T hcmaylj25a
; real_T cyqeay1yht ; real_T gmgguax0lb ; real_T e0stmf0wje ; real_T
ggvs3qvpfu ; real_T mdt0d44sb1 ; real_T kxicx45q5w ; real_T i0rkndmb13 ;
real_T owsmsehx52 ; real_T nsdd2hdqf1 ; real_T a34p2x24w2 ; real_T jyhhxwku5j
; real_T jers21a5nu ; real_T fpmqgmj2cy ; real_T gnebrkauvk ; real_T
jkw11eafiz ; real_T acvegdxqsb ; real_T c1quq2kkeo ; real_T bqly4iysyb ;
real_T apaian0okb ; real_T c1co2zjsgy ; real_T ktfxpbuyoi ; real_T max2gpqnqf
; real_T ewn2wlainw ; real_T jxbxouhvpz ; real_T m0n2ncikto ; real_T
blc3ahlqoa ; real_T n2wkjomta0 ; real_T f14htfpour ; real_T k3ehqfnhji ;
real_T dxkeuerubi ; real_T e2pyl4rib3 ; real_T nnbbyhuwe5 ; real_T pjddsfuka3
; real_T gpdt1s5m43 ; real_T df1ir0te5a ; real_T nag5slvt33 ; real_T
fxorr2mhne [ 2 ] ; real_T nhjc2m3cbx [ 2 ] ; real_T ap3kp501sl [ 2 ] ; real_T
nylejvpk25 ; real_T g5n3z2eyy3 ; boolean_T djf3ji5ytw ; boolean_T bkyaf0nkhx
; boolean_T pzi0oq2mxf ; boolean_T owu2nywhc4 ; boolean_T lgqv4rlpjm ;
boolean_T pehstkjnkd ; boolean_T hehncpsx5o ; boolean_T bhwit4pfgp ;
boolean_T lb3j4jh0k1 ; boolean_T po2rfexerf ; boolean_T p0reyhkgec ;
hzskem2oxy cmjzvpvpsf ; jjavt2chnr jdw3pbikft ; m0godxqmay hdzoplw4kn ;
jjavt2chnr msxjrffonnn ; m0godxqmay ggca33mvdun ; hzskem2oxy nrqkqpzimhq ; }
B ; typedef struct { real_T bssa0c1myd ; real_T phadp4f3b4 ; real_T
mse1diqmww ; real_T bhmfx0qy3i ; real_T cmv1b20lsy ; real_T lvp0eixlb4 ;
struct { real_T modelTStart ; } kv1pa1ywzi ; struct { real_T modelTStart ; }
ij5krlemte ; struct { real_T modelTStart ; } h0tlb2kuwe ; struct { real_T
modelTStart ; } mj5evfwhzb ; struct { real_T modelTStart ; } ngqgrvp4ei ;
struct { real_T modelTStart ; } ajgpkfca1o ; struct { real_T modelTStart ; }
ma103w0rl5 ; struct { real_T modelTStart ; } ocb1qur2h1 ; struct { real_T
modelTStart ; } d0nohml22r ; struct { real_T modelTStart ; } mzuvrrfieu ;
struct { real_T modelTStart ; } d4whpythev ; struct { real_T modelTStart ; }
d4oxqhfhid ; struct { real_T modelTStart ; } jrveltrtha ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } f5j5cwamx4 ; struct { void
* TUbufferPtrs [ 2 ] ; } ozcsecc153 ; struct { void * TUbufferPtrs [ 2 ] ; }
psh3vd4qdr ; struct { void * TUbufferPtrs [ 2 ] ; } lhdff4g1zf ; struct {
void * LoggedData [ 7 ] ; } hg5xr2o52a ; struct { void * LoggedData [ 4 ] ; }
lcytbmuuny ; struct { void * TUbufferPtrs [ 2 ] ; } kt2rdibexx ; struct {
void * TUbufferPtrs [ 2 ] ; } h1me53arog ; struct { void * TUbufferPtrs [ 2 ]
; } pu2m2nsrgd ; struct { void * TUbufferPtrs [ 2 ] ; } lfbf1a2jus ; struct {
void * TUbufferPtrs [ 2 ] ; } othjjrceoi ; struct { void * TUbufferPtrs [ 2 ]
; } m4vidzf1kq ; struct { void * TUbufferPtrs [ 2 ] ; } ogkqvonou1 ; struct {
void * TUbufferPtrs [ 2 ] ; } iyhbqhzckm ; struct { void * TUbufferPtrs [ 2 ]
; } fdlikytedu ; struct { void * TUbufferPtrs [ 2 ] ; } g0jka410r5 ; struct {
void * LoggedData [ 4 ] ; } dkeugicdjj ; struct { void * LoggedData [ 4 ] ; }
j3kmw0bx15 ; struct { void * AQHandles ; } dmnu1nlz2m ; struct { void *
LoggedData ; } glgftsaydo ; struct { void * LoggedData ; } ewzvvg2wnk ;
uint32_T afqavbs5ty ; struct { int_T PrevIndex ; } eidamkhewj ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } dazeyaom3l ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } hpsposfxjp ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } achc50k0kr ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } h2kosmawcp ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
jklfnyaqcu ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } bl1p0blo4b ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
ahczbduber ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } mehfzxnojj ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
bxfujbkphp ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } jcgpwdcw13 ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
adt2xe2pd0 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } mijwxy1gfd ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
ewfcczil0j ; int_T es3p4dnuna ; int_T hr4s0kwfwa ; int_T lfe1ibkwop ; int_T
m2jub0kxpz ; int8_T izid4kf2wl ; int8_T f5bd1tnerd ; int8_T aece3kamvy ;
int8_T fbu1o32502 ; int8_T j3dn4gfhs1 ; int8_T hfhvsoe1hu ; boolean_T
ezpzvynldc ; boolean_T jddr3btzwa ; boolean_T m0i1af3trd ; boolean_T
nssittgb5o ; boolean_T iwr1b2avuw ; boolean_T kwrhw5www5 ; boolean_T
hz35lsskp2 ; boolean_T jf03aj3gmd ; boolean_T bf33xtbrhg ; boolean_T
itvjzmhcag ; boolean_T ehwgl0hfyk ; jayuearsj1 cmjzvpvpsf ; fucri11br2
jdw3pbikft ; dturppu2h0 hdzoplw4kn ; fucri11br2 msxjrffonnn ; dturppu2h0
ggca33mvdun ; jayuearsj1 nrqkqpzimhq ; } DW ; typedef struct { real_T
emjc3fqnss [ 4 ] ; real_T cyh0kmfhle [ 4 ] ; real_T owcac5vhsm ; real_T
pokwk5dsee ; real_T bqamom4kaa [ 8 ] ; real_T e1epvwdkhs ; real_T dhvzxe4g3s
; real_T gc00zq2jpx ; real_T e1jmtpc2vb ; } X ; typedef int_T PeriodicIndX [
2 ] ; typedef real_T PeriodicRngX [ 4 ] ; typedef struct { real_T emjc3fqnss
[ 4 ] ; real_T cyh0kmfhle [ 4 ] ; real_T owcac5vhsm ; real_T pokwk5dsee ;
real_T bqamom4kaa [ 8 ] ; real_T e1epvwdkhs ; real_T dhvzxe4g3s ; real_T
gc00zq2jpx ; real_T e1jmtpc2vb ; } XDot ; typedef struct { boolean_T
emjc3fqnss [ 4 ] ; boolean_T cyh0kmfhle [ 4 ] ; boolean_T owcac5vhsm ;
boolean_T pokwk5dsee ; boolean_T bqamom4kaa [ 8 ] ; boolean_T e1epvwdkhs ;
boolean_T dhvzxe4g3s ; boolean_T gc00zq2jpx ; boolean_T e1jmtpc2vb ; } XDis ;
typedef struct { real_T emjc3fqnss [ 4 ] ; real_T cyh0kmfhle [ 4 ] ; real_T
owcac5vhsm ; real_T pokwk5dsee ; real_T bqamom4kaa [ 8 ] ; real_T e1epvwdkhs
; real_T dhvzxe4g3s ; real_T gc00zq2jpx ; real_T e1jmtpc2vb ; } CStateAbsTol
; typedef struct { real_T emjc3fqnss [ 4 ] ; real_T cyh0kmfhle [ 4 ] ; real_T
owcac5vhsm ; real_T pokwk5dsee ; real_T bqamom4kaa [ 8 ] ; real_T e1epvwdkhs
; real_T dhvzxe4g3s ; real_T gc00zq2jpx ; real_T e1jmtpc2vb ; } CXPtMin ;
typedef struct { real_T emjc3fqnss [ 4 ] ; real_T cyh0kmfhle [ 4 ] ; real_T
owcac5vhsm ; real_T pokwk5dsee ; real_T bqamom4kaa [ 8 ] ; real_T e1epvwdkhs
; real_T dhvzxe4g3s ; real_T gc00zq2jpx ; real_T e1jmtpc2vb ; } CXPtMax ;
typedef struct { real_T iazpe4yfr5 ; real_T a1t4ed4wgs ; real_T ip4oxd3020 ;
real_T mwjydau40g ; real_T ksohzj1diq ; real_T kghj5pk2h3 ; real_T i252fdz5sq
; real_T lsjkbd3twb ; real_T ddj2qfk2oh ; real_T kvc5bba54l ; real_T
mvauzegt1r ; real_T fjujlpnk1z ; real_T jzsmdmady2 ; peywaezwuq cmjzvpvpsf ;
real_T fmlhkacdka ; real_T fnfeea2pgq ; real_T h3oxau4oen ; peywaezwuq
nrqkqpzimhq ; } ZCV ; typedef struct { ZCSigState hvekerdey5 ; ZCSigState
gzsjhe3j3h ; ZCSigState cqolqyndhe ; ZCSigState mexgwhndus ; l32trj3bao
cmjzvpvpsf ; ZCSigState lzwwl1jhb5 ; ZCSigState cmf42mhbgp ; ZCSigState
f2owmsmztm ; l32trj3bao nrqkqpzimhq ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct pvhrmw3hdx_ { real_T
_Y0 ; } ; struct n3okybeeky_ { boolean_T OUT_Y0 ; } ; struct ivhfwjkeio_ {
boolean_T OUT_Y0 ; } ; struct P_ { real_T Amplitud ; real_T Att_Volt_Canal ;
real_T C ; real_T Frec_port ; real_T Kv ; real_T Pot_Ruido ; real_T R1 ;
real_T R2 ; real_T Rb ; real_T Retraso_Canal ; real_T Tb ; real_T b ; real_T
kv2 ; real_T Monostable1_EdgeDetect ; real_T Monostable3_EdgeDetect ; real_T
SampleandHold_ic ; real_T Monostable1_ic ; real_T SampleHold_ic ; real_T
Monostable3_ic ; real_T SampleHold_ic_cvpetr2ktj ; boolean_T Monostable_ic ;
real_T Out1_Y0 ; real_T _Y0 ; real_T FromWorkspace_Data0 [ 1111 ] ; real_T
AnalogFilterDesign_A_pr [ 7 ] ; real_T AnalogFilterDesign_B_pr ; real_T
AnalogFilterDesign_C_pr ; real_T AnalogFilterDesign_InitialCondition ; real_T
TransportDelay_InitOutput ; real_T RuidoAGWN_Mean ; real_T RuidoAGWN_Seed ;
real_T AnalogFilterDesign_A_pr_jsdcqwampi [ 7 ] ; real_T
AnalogFilterDesign_B_pr_om0jg41jmb ; real_T
AnalogFilterDesign_C_pr_d0qgd0zcfa ; real_T
AnalogFilterDesign_InitialCondition_bizf0yluzm ; real_T TransportDelay_Delay
; real_T TransportDelay_InitOutput_m3b1lj5lye ; real_T Integrator_IC ; real_T
ModuloIntegrator_IC ; real_T ModuloIntegrator_WrappedStateUpperValue ; real_T
ModuloIntegrator_WrappedStateLowerValue ; real_T AddConstant_Bias ; real_T
Multiply_Gain ; real_T TransportDelay12_InitOutput ; real_T
AnalogFilterDesign_A_pr_f4zixacbw1 [ 15 ] ; real_T
AnalogFilterDesign_B_pr_by1sufu2fg ; real_T
AnalogFilterDesign_C_pr_e3t31otpuq ; real_T
AnalogFilterDesign_InitialCondition_gxj5snzs0v ; real_T
TransportDelay2_InitOutput ; real_T TransportDelay1_InitOutput ; real_T
TransportDelay4_InitOutput ; real_T TransportDelay3_InitOutput ; real_T
TransportDelay6_InitOutput ; real_T TransportDelay5_InitOutput ; real_T
TransportDelay8_InitOutput ; real_T TransportDelay7_InitOutput ; real_T
TransportDelay9_InitOutput ; real_T TransportDelay11_InitOutput ; real_T
Switch_Threshold ; real_T ModuloIntegrator_IC_g1vo2kap3u ; real_T
ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5 ; real_T
ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk ; real_T
Integrator_IC_oxpanuusbm ; real_T Integrator1_IC ; real_T
Integrator_IC_a5b0eygpkp ; real_T Multiply_Gain_ptvyavefxe ; real_T
AddConstant_Bias_ljcfbacsm3 ; real_T SineWave_Bias ; real_T SineWave_Phase ;
real_T Constant1_Value ; real_T Constant10_Value ; real_T Constant13_Value ;
real_T Constant14_Value ; real_T Constant15_Value ; real_T Constant16_Value ;
real_T Constant2_Value ; real_T Constant3_Value ; real_T Constant4_Value ;
real_T Constant5_Value ; real_T Constant6_Value ; real_T Constant7_Value ;
real_T Constant8_Value ; real_T Constant9_Value ; real_T Constant_Value ;
real_T Constant1_Value_afssjxve00 ; real_T posedge_Value [ 2 ] ; real_T
negedge_Value [ 2 ] ; real_T eitheredge_Value [ 2 ] ; real_T
Constant2_Value_mwviqzbxqh ; real_T Constant5_Value_hu2bresth1 ; real_T
Constant6_Value_dkmziwbikw ; real_T Constant1_Value_hcjo4f4r5j ; real_T
posedge_Value_av2r5ustik [ 2 ] ; real_T negedge_Value_fef1hh2jz4 [ 2 ] ;
real_T eitheredge_Value_nntils3rkv [ 2 ] ; real_T posedge_Value_j0croo5cnv [
2 ] ; real_T negedge_Value_lnmee3h1ob [ 2 ] ; real_T
eitheredge_Value_gsipsgs54b [ 2 ] ; uint32_T AnalogFilterDesign_A_ir [ 7 ] ;
uint32_T AnalogFilterDesign_A_jc [ 5 ] ; uint32_T AnalogFilterDesign_B_ir ;
uint32_T AnalogFilterDesign_B_jc [ 2 ] ; uint32_T AnalogFilterDesign_C_ir ;
uint32_T AnalogFilterDesign_C_jc [ 5 ] ; uint32_T
AnalogFilterDesign_A_ir_gqpywhsxtr [ 7 ] ; uint32_T
AnalogFilterDesign_A_jc_fyftqxybap [ 5 ] ; uint32_T
AnalogFilterDesign_B_ir_gklrfvy2xp ; uint32_T
AnalogFilterDesign_B_jc_nk0ranamkl [ 2 ] ; uint32_T
AnalogFilterDesign_C_ir_jr05e5amzn ; uint32_T
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 5 ] ; uint32_T
AnalogFilterDesign_A_ir_cx1zj2mhzp [ 15 ] ; uint32_T
AnalogFilterDesign_A_jc_h5xar20tzm [ 9 ] ; uint32_T
AnalogFilterDesign_B_ir_nneewrak4c ; uint32_T
AnalogFilterDesign_B_jc_acwf2d2gj0 [ 2 ] ; uint32_T
AnalogFilterDesign_C_ir_cqrtf32rbd ; uint32_T
AnalogFilterDesign_C_jc_d2bgogmalx [ 9 ] ; boolean_T OUT_Y0 ; boolean_T
OUT_Y0_gbikirmbla ; boolean_T Q_Y0 ; boolean_T Q_Y0_ngs1cr5pq5 ; boolean_T
Memory_InitialCondition ; boolean_T
TmpLatchAtDFlipFlopInport1_InitialCondition ; boolean_T
Memory_InitialCondition_oggd2r4odw ; boolean_T
Memory_InitialCondition_ljulw4woig ; pvhrmw3hdx cmjzvpvpsf ; ivhfwjkeio
jdw3pbikft ; n3okybeeky hdzoplw4kn ; ivhfwjkeio msxjrffonnn ; n3okybeeky
ggca33mvdun ; pvhrmw3hdx nrqkqpzimhq ; } ;
#ifdef __cplusplus
extern "C" {
#endif
extern const char * RT_MEMORY_ALLOCATION_ERROR ;
#ifdef __cplusplus
}
#endif
extern B rtB ; extern X rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ;
extern P rtP ; extern mxArray * mr_modPSK_GetDWork ( ) ; extern void
mr_modPSK_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_modPSK_GetSimStateDisallowedBlocks ( ) ;
#ifdef __cplusplus 
extern "C" {
#endif
#ifdef __cplusplus 
}
#endif
#ifdef __cplusplus 
extern "C" {
#endif
#ifdef __cplusplus 
}
#endif
extern const rtwCAPI_ModelMappingStaticInfo * modPSK_GetCAPIStaticMap ( void
) ;
#ifdef __cplusplus
extern "C" {
#endif
extern SimStruct * const rtS ;
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#ifdef __cplusplus
}
#endif
#endif
