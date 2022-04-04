#ifndef RTW_HEADER_modPSK_mod3_h_
#define RTW_HEADER_modPSK_mod3_h_
#ifndef modPSK_mod3_COMMON_INCLUDES_
#define modPSK_mod3_COMMON_INCLUDES_
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
#include "modPSK_mod3_types.h"
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
#define MODEL_NAME modPSK_mod3
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (71) 
#define NUM_ZC_EVENTS (9) 
#ifndef NCSTATES
#define NCSTATES (26)   
#elif NCSTATES != 26
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
typedef struct { real_T n0jiemzt0m ; } igetpbslua ; typedef struct { int8_T
kw45gvclvl ; } kkwkju2b34 ; typedef struct { ZCSigState pfohtyb5z1 ; }
mcilpbj4n3 ; typedef struct { boolean_T gcuafzmxgi ; } b25ph2maso ; typedef
struct { int8_T igzqysubwr ; boolean_T jfiw2hmwe4 ; } d2girhkqx4 ; typedef
struct { boolean_T fncspxqpzn ; } iqmdugheux ; typedef struct { int8_T
mzbzupg3uq ; boolean_T miqumv2j33 ; } aiayfqjngh ; typedef struct { real_T
cjskazwmh1 ; real_T d4txlaulvr ; real_T f2es2rkn4r ; real_T ailrsbpb25 ;
real_T bfrc2rc5zl ; real_T ncdgrorzsx ; real_T pl5zjiseby ; real_T nihlui3tdy
; real_T gopo0ay43o ; real_T hs04wl1crq ; real_T pznu3l5z1a ; real_T
bhvr0udrsy ; real_T kmqtx532fz ; real_T hnp1kuefxm ; real_T lsnuriwz44 ;
real_T lisuhkiql3 ; real_T ewq0jsmjdj ; real_T dv3oqsxz41 ; real_T nz2mzf3abt
; real_T geeegghaq4 ; real_T eancnret3z ; real_T m2vnyqktog ; real_T
k3la20515u ; real_T jfofwf5qdn ; real_T k0hg52okk1 ; real_T dxje1nzfb1 ;
real_T lrg23dznf5 ; real_T ncgerps2w1 ; real_T dzwzyjfb3d ; real_T c1tvvwnguu
; real_T pxicmncoih ; real_T ao3hvbk03u ; real_T cjvhltyh5i ; real_T
awbajcw3bs ; real_T k0xpbzxvuq ; real_T pgstwodvgn ; real_T ji14ejc3mp ;
real_T agrizcdfza ; real_T mxxtwp3ieb ; real_T o0mruwezip ; real_T dwgm1iwulr
; real_T h3lftethav ; real_T kiqo1dkx4d ; real_T ki1f5bwrru ; real_T
o51erkdynh ; real_T asbkydpcdt ; real_T mxwhtwoxqb ; real_T hzfal5kgng ;
real_T kppvt5er43 [ 2 ] ; real_T ck3j1srrxl [ 2 ] ; real_T pnagitghhg [ 2 ] ;
real_T amouf3rzmf ; boolean_T p4bwi2pbc0 ; boolean_T efvczhdjet ; boolean_T
ftifgsd50u ; boolean_T hrmk3oqzup ; boolean_T fv3qrvs3nd ; boolean_T
bq2qwyyni3 ; boolean_T bxjduwjkqo ; boolean_T ohloxwa40r ; boolean_T
lfy2bgoxg0 ; boolean_T d0uzclm1vr ; boolean_T pet04kmorq ; boolean_T
i3hvpke3ms ; boolean_T octfr53rd1 ; igetpbslua pokud50mlj ; iqmdugheux
l2pxsorbc0 ; b25ph2maso ntt0n0z3qa ; iqmdugheux guziuj3nzou ; b25ph2maso
obgcvvf2c2c ; igetpbslua f5g5ssvz0ob ; } B ; typedef struct { real_T
idhuf1euoi ; real_T cuilob0auh ; real_T g4c0zz45r4 ; real_T gamney3fyk ;
real_T hobor2c3tl ; real_T jkafh5jkcy ; struct { real_T modelTStart ; }
lddp3kj4wc ; struct { real_T modelTStart ; } bj4mi1vzil ; struct { real_T
modelTStart ; } p5cigbuwvn ; struct { real_T modelTStart ; } gf4lfoijb0 ;
struct { real_T modelTStart ; } okq3xbd2ii ; struct { real_T modelTStart ; }
iobbwey3sn ; struct { real_T modelTStart ; } e334mwrkee ; struct { real_T
modelTStart ; } pryezgtgn4 ; struct { real_T modelTStart ; } hzbip0oysg ;
struct { real_T modelTStart ; } huh20tu5q1 ; struct { real_T modelTStart ; }
agxdp5talt ; struct { real_T modelTStart ; } nb2ebbj1qe ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } c550b3xklm ; struct { void
* TUbufferPtrs [ 2 ] ; } jc1itafzwd ; struct { void * TUbufferPtrs [ 2 ] ; }
lj1tdbxggs ; struct { void * TUbufferPtrs [ 2 ] ; } ml2avl24pf ; struct {
void * TUbufferPtrs [ 2 ] ; } fbk251u41l ; struct { void * TUbufferPtrs [ 2 ]
; } kpvx4uvt01 ; struct { void * TUbufferPtrs [ 2 ] ; } oeere24mz0 ; struct {
void * TUbufferPtrs [ 2 ] ; } h1egexnfwb ; struct { void * TUbufferPtrs [ 2 ]
; } lycpuo0tla ; struct { void * TUbufferPtrs [ 2 ] ; } etoiwhh4sj ; struct {
void * TUbufferPtrs [ 2 ] ; } l4z1r030na ; struct { void * TUbufferPtrs [ 2 ]
; } e3lmwmye5o ; struct { void * TUbufferPtrs [ 2 ] ; } mxtwjhbmuw ; struct {
void * LoggedData [ 7 ] ; } j30qutghas ; struct { void * LoggedData [ 3 ] ; }
o1r21qardz ; struct { void * LoggedData [ 4 ] ; } apsrc53ins ; struct { void
* LoggedData [ 4 ] ; } kmyqkb4ou1 ; struct { void * LoggedData [ 4 ] ; }
diduvlcjw5 ; struct { void * LoggedData [ 4 ] ; } otc0z4rhtr ; struct { void
* AQHandles ; } dke2w5vglk ; struct { void * LoggedData ; } jqho42deiu ;
struct { void * AQHandles ; } ivu5m05flg ; uint32_T bzmxqssdoq ; struct {
int_T PrevIndex ; } kb5rvgdujd ; struct { int_T Tail ; int_T Head ; int_T
Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } kcxfvmkrf2 ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } n2bt3cyc55 ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } lcuflefjuj ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } ovi0zqdzif ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } advdik1iky ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
kb3fhgjdld ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } ho5e0de00z ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
dlpoyqagu4 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } k1nwxppvuo ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
azfuopxupm ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } bnqksyhx4b ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
jsj5ows1gx ; int8_T ajzqjdehhp ; int8_T kjy05jsjy1 ; int8_T mt4cgs1ctq ;
int8_T jggqbqxmox ; int8_T bluxjvuquj ; int8_T pu1wrg42xz ; boolean_T
kia112cgkq ; boolean_T igyctbswok ; boolean_T llqwbguanw ; boolean_T
i3eziu3f1n ; boolean_T fbp5lgspzk ; boolean_T nrn32puwjn ; boolean_T
ckhj2mjol3 ; boolean_T haenchykp4 ; kkwkju2b34 pokud50mlj ; aiayfqjngh
l2pxsorbc0 ; d2girhkqx4 ntt0n0z3qa ; aiayfqjngh guziuj3nzou ; d2girhkqx4
obgcvvf2c2c ; kkwkju2b34 f5g5ssvz0ob ; } DW ; typedef struct { real_T
amtjz55qss [ 4 ] ; real_T jpbcgznxiw [ 4 ] ; real_T gax2n2uyhb ; real_T
lzv0rcie1i ; real_T adtcefug1k [ 4 ] ; real_T e5d2w4theu [ 8 ] ; real_T
lpelu0o3uv ; real_T ef1jjuhfsz ; real_T bwxjromtln ; real_T fkxwshodm4 ; } X
; typedef int_T PeriodicIndX [ 2 ] ; typedef real_T PeriodicRngX [ 4 ] ;
typedef struct { real_T amtjz55qss [ 4 ] ; real_T jpbcgznxiw [ 4 ] ; real_T
gax2n2uyhb ; real_T lzv0rcie1i ; real_T adtcefug1k [ 4 ] ; real_T e5d2w4theu
[ 8 ] ; real_T lpelu0o3uv ; real_T ef1jjuhfsz ; real_T bwxjromtln ; real_T
fkxwshodm4 ; } XDot ; typedef struct { boolean_T amtjz55qss [ 4 ] ; boolean_T
jpbcgznxiw [ 4 ] ; boolean_T gax2n2uyhb ; boolean_T lzv0rcie1i ; boolean_T
adtcefug1k [ 4 ] ; boolean_T e5d2w4theu [ 8 ] ; boolean_T lpelu0o3uv ;
boolean_T ef1jjuhfsz ; boolean_T bwxjromtln ; boolean_T fkxwshodm4 ; } XDis ;
typedef struct { real_T amtjz55qss [ 4 ] ; real_T jpbcgznxiw [ 4 ] ; real_T
gax2n2uyhb ; real_T lzv0rcie1i ; real_T adtcefug1k [ 4 ] ; real_T e5d2w4theu
[ 8 ] ; real_T lpelu0o3uv ; real_T ef1jjuhfsz ; real_T bwxjromtln ; real_T
fkxwshodm4 ; } CStateAbsTol ; typedef struct { real_T amtjz55qss [ 4 ] ;
real_T jpbcgznxiw [ 4 ] ; real_T gax2n2uyhb ; real_T lzv0rcie1i ; real_T
adtcefug1k [ 4 ] ; real_T e5d2w4theu [ 8 ] ; real_T lpelu0o3uv ; real_T
ef1jjuhfsz ; real_T bwxjromtln ; real_T fkxwshodm4 ; } CXPtMin ; typedef
struct { real_T amtjz55qss [ 4 ] ; real_T jpbcgznxiw [ 4 ] ; real_T
gax2n2uyhb ; real_T lzv0rcie1i ; real_T adtcefug1k [ 4 ] ; real_T e5d2w4theu
[ 8 ] ; real_T lpelu0o3uv ; real_T ef1jjuhfsz ; real_T bwxjromtln ; real_T
fkxwshodm4 ; } CXPtMax ; typedef struct { ZCSigState h30gjmuzs5 ; ZCSigState
ct04cv1aou ; ZCSigState i514uivwi3 ; ZCSigState gma50kdl5l ; mcilpbj4n3
pokud50mlj ; ZCSigState aws53lhtcb ; ZCSigState ph4ircn3eg ; ZCSigState
neekdr5ik0 ; mcilpbj4n3 f5g5ssvz0ob ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct izzmnm4or4_ { real_T
_Y0 ; } ; struct akft0npbrm_ { boolean_T OUT_Y0 ; } ; struct ft4pkmho30_ {
boolean_T OUT_Y0 ; } ; struct P_ { real_T Amplitud ; real_T AmplitudPortadora
; real_T Att_Volt_Canal ; real_T C ; real_T Frec_port ; real_T Kv ; real_T
Pot_Ruido ; real_T R1 ; real_T R2 ; real_T Rb ; real_T Retraso_Canal ; real_T
Tb ; real_T b ; real_T kv2 ; real_T Monostable1_EdgeDetect ; real_T
Monostable3_EdgeDetect ; real_T SampleandHold_ic ; real_T Monostable1_ic ;
real_T SampleHold_ic ; real_T Monostable3_ic ; real_T
SampleHold_ic_cvpetr2ktj ; boolean_T Monostable_ic ; real_T Out1_Y0 ; real_T
_Y0 ; real_T FromWorkspace_Data0 [ 1124 ] ; real_T AnalogFilterDesign_A_pr [
7 ] ; real_T AnalogFilterDesign_B_pr ; real_T AnalogFilterDesign_C_pr ;
real_T AnalogFilterDesign_InitialCondition ; real_T TransportDelay_InitOutput
; real_T RuidoAGWN_Mean ; real_T RuidoAGWN_Seed ; real_T
AnalogFilterDesign_A_pr_jsdcqwampi [ 7 ] ; real_T
AnalogFilterDesign_B_pr_om0jg41jmb ; real_T
AnalogFilterDesign_C_pr_d0qgd0zcfa ; real_T
AnalogFilterDesign_InitialCondition_bizf0yluzm ; real_T TransportDelay_Delay
; real_T TransportDelay_InitOutput_m3b1lj5lye ; real_T Integrator_IC ; real_T
ModuloIntegrator_IC ; real_T ModuloIntegrator_WrappedStateUpperValue ; real_T
ModuloIntegrator_WrappedStateLowerValue ; real_T TransportDelay2_InitOutput ;
real_T TransportDelay1_InitOutput ; real_T TransportDelay4_InitOutput ;
real_T TransportDelay3_InitOutput ; real_T TransportDelay6_InitOutput ;
real_T TransportDelay5_InitOutput ; real_T TransportDelay8_InitOutput ;
real_T TransportDelay7_InitOutput ; real_T TransportDelay9_InitOutput ;
real_T TransportDelay11_InitOutput ; real_T Switch_Threshold ; real_T
AnalogFilterDesign_A_pr_gc0kz31g5a [ 7 ] ; real_T
AnalogFilterDesign_B_pr_kq1k3m2fjm ; real_T
AnalogFilterDesign_C_pr_aqq5iiwnf2 ; real_T
AnalogFilterDesign_InitialCondition_l2mskoueic ; real_T
AnalogFilterDesign_A_pr_f4zixacbw1 [ 15 ] ; real_T
AnalogFilterDesign_B_pr_by1sufu2fg ; real_T
AnalogFilterDesign_C_pr_e3t31otpuq ; real_T
AnalogFilterDesign_InitialCondition_gxj5snzs0v ; real_T
ModuloIntegrator_IC_g1vo2kap3u ; real_T
ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5 ; real_T
ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk ; real_T
Integrator_IC_oxpanuusbm ; real_T Integrator1_IC ; real_T
Integrator_IC_a5b0eygpkp ; real_T Multiply_Gain ; real_T AddConstant_Bias ;
real_T SineWave_Bias ; real_T SineWave_Phase ; real_T Constant1_Value ;
real_T Constant10_Value ; real_T Constant13_Value ; real_T Constant14_Value ;
real_T Constant15_Value ; real_T Constant16_Value ; real_T Constant2_Value ;
real_T Constant3_Value ; real_T Constant4_Value ; real_T Constant5_Value ;
real_T Constant6_Value ; real_T Constant7_Value ; real_T Constant8_Value ;
real_T Constant9_Value ; real_T Constant1_Value_afssjxve00 ; real_T
posedge_Value [ 2 ] ; real_T negedge_Value [ 2 ] ; real_T eitheredge_Value [
2 ] ; real_T Constant2_Value_mwviqzbxqh ; real_T Constant5_Value_hu2bresth1 ;
real_T Constant6_Value_dkmziwbikw ; real_T Constant1_Value_hcjo4f4r5j ;
real_T posedge_Value_av2r5ustik [ 2 ] ; real_T negedge_Value_fef1hh2jz4 [ 2 ]
; real_T eitheredge_Value_nntils3rkv [ 2 ] ; real_T posedge_Value_j0croo5cnv
[ 2 ] ; real_T negedge_Value_lnmee3h1ob [ 2 ] ; real_T
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
AnalogFilterDesign_A_ir_o3wehlil1t [ 7 ] ; uint32_T
AnalogFilterDesign_A_jc_hepc5hv3fw [ 5 ] ; uint32_T
AnalogFilterDesign_B_ir_bqybfmsaae ; uint32_T
AnalogFilterDesign_B_jc_cfquo51aq1 [ 2 ] ; uint32_T
AnalogFilterDesign_C_ir_ivqqscx0vn ; uint32_T
AnalogFilterDesign_C_jc_llcs1qdtjn [ 5 ] ; uint32_T
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
Memory_InitialCondition_ljulw4woig ; izzmnm4or4 pokud50mlj ; ft4pkmho30
l2pxsorbc0 ; akft0npbrm ntt0n0z3qa ; ft4pkmho30 guziuj3nzou ; akft0npbrm
obgcvvf2c2c ; izzmnm4or4 f5g5ssvz0ob ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_modPSK_mod3_GetDWork ( ) ; extern void mr_modPSK_mod3_SetDWork ( const
mxArray * ssDW ) ; extern mxArray *
mr_modPSK_mod3_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * modPSK_mod3_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
