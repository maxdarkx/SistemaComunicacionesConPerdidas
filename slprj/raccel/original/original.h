#ifndef RTW_HEADER_original_h_
#define RTW_HEADER_original_h_
#ifndef original_COMMON_INCLUDES_
#define original_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "original_types.h"
#include "mwmathutil.h"
#include "rt_zcfcn.h"
#include <string.h>
#include <stddef.h>
#include <float.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME original
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (76) 
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
typedef struct { real_T lzgwbwuubl ; } lp5ztxd20y ; typedef struct { int8_T
bmw2hixe1f ; } mem4sagm4y ; typedef struct { real_T l534ubw1vx ; } isjbvgrnv1
; typedef struct { ZCSigState ohewvvpbtd ; } fgwwoolgrw ; typedef struct {
boolean_T o3dp55eklq ; } hh5f121zsr ; typedef struct { int8_T fulyjjxmue ; }
pzawjmwk3y ; typedef struct { boolean_T elss3awww2 ; } dufzjkshrc ; typedef
struct { int8_T idqwe24upn ; } d51rut2e0g ; typedef struct { real_T
pczptaloqn ; real_T lyy2rgzssu ; real_T b4klkr2hpb ; real_T mttr3remqe ;
real_T azmfpdpfhr ; real_T b4dgdwqfvr ; real_T apurb3sda3 ; real_T c5jqurmpza
; real_T hssaqyb021 ; real_T nqw3knpw3y ; real_T nqqxqhj4uh ; real_T
aibuxow2f4 ; real_T i0c1bgukye ; real_T fewalbo2ov ; real_T azchjpegsm ;
real_T ihiwfhuo0a ; real_T hkn2g3gvsz ; real_T ntkisuxn2g ; real_T m4m214ovbs
; real_T pndfq3ndef ; real_T oxkodghnh1 ; real_T g53czseiki ; real_T
icz5jiqa5l ; real_T l0uo4a4mr4 ; real_T ntk0mkheco ; real_T fqfddfhgnv ;
real_T k4j5el1r4t ; real_T ac5onrei0k ; real_T bz0pvs5lfr ; real_T dmtaqaxly0
; real_T abjvxeqou3 ; real_T ie0mnn5bjz ; real_T ngmqsygkuj ; real_T
kpyjbyqhnn ; real_T nqzijf3v2s ; real_T bzfqsaqdca ; real_T cdlxrrgn43 ;
real_T majhbieqf2 ; real_T mojdhi2f5w ; real_T myomqf4clw ; real_T cqgvyb1usr
; real_T otmkurmb40 ; real_T g1iqixqqbk ; real_T le03i4u1w1 ; real_T
dxkzb2shae ; real_T bcqstcbcss ; real_T klpoi14tq3 ; real_T btco2hfhqs ;
real_T j5xzo5caz4 ; real_T m2lqawkue3 ; real_T njbn3w11wn ; real_T k3v5lqeyfa
; real_T ommuhpqjnr ; real_T g2d1qhfmtb ; real_T f4wxz52mc5 [ 2 ] ; real_T
pyvoagmwyq [ 2 ] ; real_T ppuci252pa [ 2 ] ; real_T bnrnxdd0vt ; real_T
gpjz2pf2n0 ; boolean_T orn3venhnk ; boolean_T azngqgys3a ; boolean_T
mmbwdvbds0 ; boolean_T ndzz4ltczv ; boolean_T bik1lk5raz ; boolean_T
elhj11vpue ; boolean_T pnc2oxbc5h ; boolean_T nlky1z3g2k ; boolean_T
ov3s20wyhx ; boolean_T grenet1so1 ; boolean_T gzklf0ilir ; lp5ztxd20y
o0byjwoyow ; dufzjkshrc llvx0kbake ; hh5f121zsr iewfgzwb31 ; dufzjkshrc
ligjpsfhvtg ; hh5f121zsr mjqilvpgl54 ; lp5ztxd20y mnr2afncj2u ; } B ; typedef
struct { real_T eflcwal1mu ; real_T oquiajmyfp ; real_T ltasifvkde ; real_T
iksurbbs2u ; real_T nkspyzjmj0 ; struct { real_T modelTStart ; } owd5cjyj4l ;
struct { real_T modelTStart ; } i4xfbt1z25 ; struct { real_T modelTStart ; }
ky1a3dnkiw ; struct { real_T modelTStart ; } fwikzb00to ; struct { real_T
modelTStart ; } azfsgwj0il ; struct { real_T modelTStart ; } i30swi3eeg ;
struct { real_T modelTStart ; } bjvck4ijez ; struct { real_T modelTStart ; }
idakjgagwj ; struct { real_T modelTStart ; } j0o0q4ccss ; struct { real_T
modelTStart ; } jx0fvxr0vd ; struct { real_T modelTStart ; } moy4nejcr1 ;
struct { real_T modelTStart ; } pf1rurynfs ; struct { real_T modelTStart ; }
brbjfuklas ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} g24kh0yl0d ; struct { void * TUbufferPtrs [ 2 ] ; } iufdazrcci ; struct {
void * TUbufferPtrs [ 2 ] ; } d3b3zasoji ; struct { void * TUbufferPtrs [ 2 ]
; } fqpjvnu3on ; struct { void * LoggedData [ 7 ] ; } k1ubjjkoqs ; struct {
void * LoggedData [ 4 ] ; } am5rag2bw4 ; struct { void * TUbufferPtrs [ 2 ] ;
} ii1qwqcizu ; struct { void * TUbufferPtrs [ 2 ] ; } gbr1avzpo5 ; struct {
void * TUbufferPtrs [ 2 ] ; } e02rtjhnng ; struct { void * TUbufferPtrs [ 2 ]
; } hmhofpz1ew ; struct { void * TUbufferPtrs [ 2 ] ; } audlhahb3y ; struct {
void * TUbufferPtrs [ 2 ] ; } c0b2si44of ; struct { void * TUbufferPtrs [ 2 ]
; } px5wrgqdsn ; struct { void * TUbufferPtrs [ 2 ] ; } dqimiih00v ; struct {
void * TUbufferPtrs [ 2 ] ; } hyxywufgvp ; struct { void * TUbufferPtrs [ 2 ]
; } ibeq1uqak3 ; struct { void * LoggedData [ 4 ] ; } ez41hqhdtp ; struct {
void * LoggedData [ 4 ] ; } lu3ggubgbi ; struct { void * AQHandles ; }
h3b22feudi ; struct { void * LoggedData ; } muv5ta45dz ; struct { void *
AQHandles ; } dmu42kigql ; struct { int_T PrevIndex ; } kqimps20tr ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } bijp5lznr0 ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } gozlgoace0 ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } jukyp4co3s ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } dwcos053mm ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
ar3vwuqqcr ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } pbrpegxnve ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
otun30mznk ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } etsjn5fqxr ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
dm031mdhzh ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } dwt1logpyt ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
olvi0wrke2 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } h0xflbr2r2 ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
o5k3wqz1te ; int_T nl35cfre3r ; int_T kp4ub4djpq ; int_T miaubkp1tz ; int_T
frfvjoiupy ; int8_T n1tmln402w ; int8_T mtstnsjsji ; int8_T kudt5h2w0b ;
int8_T kg30gk0yon ; int8_T iuuqkwmjrb ; int8_T ork2mu3aqa ; boolean_T
fgt0gfkzzs ; boolean_T cqe343kytb ; boolean_T mvcna0flrg ; boolean_T
al2bessz01 ; boolean_T luewrj1rxn ; boolean_T isfqm5nn3q ; boolean_T
nbeww3raq3 ; boolean_T gqsz4zovj0 ; boolean_T g22bx3mwrj ; boolean_T
gywfygl1db ; boolean_T c01gnuxhwv ; mem4sagm4y o0byjwoyow ; d51rut2e0g
llvx0kbake ; pzawjmwk3y iewfgzwb31 ; d51rut2e0g ligjpsfhvtg ; pzawjmwk3y
mjqilvpgl54 ; mem4sagm4y mnr2afncj2u ; } DW ; typedef struct { real_T
egzjqzicdq [ 4 ] ; real_T benb2xcfzc [ 4 ] ; real_T ng4tabqmtd ; real_T
moligukihq ; real_T dbfnj3ttmr [ 8 ] ; real_T gjwqeukkq3 ; real_T lhjxqs0ce0
; real_T nppgwv3zah ; real_T my5bz0mxqu ; } X ; typedef int_T PeriodicIndX [
2 ] ; typedef real_T PeriodicRngX [ 4 ] ; typedef struct { real_T egzjqzicdq
[ 4 ] ; real_T benb2xcfzc [ 4 ] ; real_T ng4tabqmtd ; real_T moligukihq ;
real_T dbfnj3ttmr [ 8 ] ; real_T gjwqeukkq3 ; real_T lhjxqs0ce0 ; real_T
nppgwv3zah ; real_T my5bz0mxqu ; } XDot ; typedef struct { boolean_T
egzjqzicdq [ 4 ] ; boolean_T benb2xcfzc [ 4 ] ; boolean_T ng4tabqmtd ;
boolean_T moligukihq ; boolean_T dbfnj3ttmr [ 8 ] ; boolean_T gjwqeukkq3 ;
boolean_T lhjxqs0ce0 ; boolean_T nppgwv3zah ; boolean_T my5bz0mxqu ; } XDis ;
typedef struct { real_T egzjqzicdq [ 4 ] ; real_T benb2xcfzc [ 4 ] ; real_T
ng4tabqmtd ; real_T moligukihq ; real_T dbfnj3ttmr [ 8 ] ; real_T gjwqeukkq3
; real_T lhjxqs0ce0 ; real_T nppgwv3zah ; real_T my5bz0mxqu ; } CStateAbsTol
; typedef struct { real_T egzjqzicdq [ 4 ] ; real_T benb2xcfzc [ 4 ] ; real_T
ng4tabqmtd ; real_T moligukihq ; real_T dbfnj3ttmr [ 8 ] ; real_T gjwqeukkq3
; real_T lhjxqs0ce0 ; real_T nppgwv3zah ; real_T my5bz0mxqu ; } CXPtMin ;
typedef struct { real_T egzjqzicdq [ 4 ] ; real_T benb2xcfzc [ 4 ] ; real_T
ng4tabqmtd ; real_T moligukihq ; real_T dbfnj3ttmr [ 8 ] ; real_T gjwqeukkq3
; real_T lhjxqs0ce0 ; real_T nppgwv3zah ; real_T my5bz0mxqu ; } CXPtMax ;
typedef struct { real_T b31pbtdn2k ; real_T o3znflkpdp ; real_T babbwy4ulx ;
real_T b0wj3p5hwu ; real_T ocukxygk3c ; real_T ohbka3d3xa ; real_T cmos0jmlkz
; real_T lwabre4v5x ; real_T hp4mce0gfx ; real_T pv1uie1eqt ; real_T
gnqui0x0du ; real_T bmo44x2usr ; real_T b25cfon423 ; isjbvgrnv1 o0byjwoyow ;
real_T b2lxdgf2qh ; real_T lznowpyux5 ; real_T lwycayvfkf ; isjbvgrnv1
mnr2afncj2u ; } ZCV ; typedef struct { ZCSigState i2q0ncrpsr ; ZCSigState
mc53zk2efp ; ZCSigState a40vve3elm ; ZCSigState gta1yuk1am ; fgwwoolgrw
o0byjwoyow ; ZCSigState j44yq314nr ; ZCSigState fueymmbsgp ; ZCSigState
lopkxabcwq ; fgwwoolgrw mnr2afncj2u ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct ehm3sgzrjf_ { real_T
_Y0 ; } ; struct bgrpsvzorg_ { boolean_T OUT_Y0 ; } ; struct o0jdhwlf44_ {
boolean_T OUT_Y0 ; } ; struct P_ { real_T Amplitud ; real_T Att_Volt_Canal ;
real_T C ; real_T Frec_port ; real_T Kv ; real_T R1 ; real_T R2 ; real_T Rb ;
real_T Retraso_Canal ; real_T Tb ; real_T b ; real_T kv2 ; real_T
Monostable1_EdgeDetect ; real_T Monostable3_EdgeDetect ; real_T
SampleandHold_ic ; real_T Monostable1_ic ; real_T SampleHold_ic ; real_T
Monostable3_ic ; real_T SampleHold_ic_cvpetr2ktj ; boolean_T Monostable_ic ;
real_T Out1_Y0 ; real_T _Y0 ; real_T FromWorkspace_Data0 [ 1124 ] ; real_T
AnalogFilterDesign_A_pr [ 7 ] ; real_T AnalogFilterDesign_B_pr ; real_T
AnalogFilterDesign_C_pr ; real_T AnalogFilterDesign_InitialCondition ; real_T
TransportDelay_InitOutput ; real_T AnalogFilterDesign_A_pr_jsdcqwampi [ 7 ] ;
real_T AnalogFilterDesign_B_pr_om0jg41jmb ; real_T
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
Memory_InitialCondition_ljulw4woig ; ehm3sgzrjf o0byjwoyow ; o0jdhwlf44
llvx0kbake ; bgrpsvzorg iewfgzwb31 ; o0jdhwlf44 ligjpsfhvtg ; bgrpsvzorg
mjqilvpgl54 ; ehm3sgzrjf mnr2afncj2u ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_original_GetDWork ( ) ; extern void mr_original_SetDWork ( const mxArray *
ssDW ) ; extern mxArray * mr_original_GetSimStateDisallowedBlocks ( ) ;
extern const rtwCAPI_ModelMappingStaticInfo * original_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
