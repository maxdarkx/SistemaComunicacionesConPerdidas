    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 11;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% rtP.Amplitud
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Att_Volt_Canal
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.C
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Frec_port
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Kv
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.R1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.R2
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Rb
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Retraso_Canal
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Tb
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.b
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.kv2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Monostable1_EdgeDetect
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Monostable3_EdgeDetect
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.SampleandHold_ic
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Monostable1_ic
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.SampleHold_ic
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.Monostable3_ic
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.SampleHold_ic_cvpetr2ktj
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.Monostable_ic
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 75;
            section.data(75)  = dumData; %prealloc

                    ;% rtP.Out1_Y0
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP._Y0
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.FromWorkspace_Data0
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.AnalogFilterDesign_A_pr
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 1126;

                    ;% rtP.AnalogFilterDesign_B_pr
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 1133;

                    ;% rtP.AnalogFilterDesign_C_pr
                    section.data(6).logicalSrcIdx = 26;
                    section.data(6).dtTransOffset = 1134;

                    ;% rtP.AnalogFilterDesign_InitialCondition
                    section.data(7).logicalSrcIdx = 27;
                    section.data(7).dtTransOffset = 1135;

                    ;% rtP.TransportDelay_InitOutput
                    section.data(8).logicalSrcIdx = 28;
                    section.data(8).dtTransOffset = 1136;

                    ;% rtP.AnalogFilterDesign_A_pr_jsdcqwampi
                    section.data(9).logicalSrcIdx = 29;
                    section.data(9).dtTransOffset = 1137;

                    ;% rtP.AnalogFilterDesign_B_pr_om0jg41jmb
                    section.data(10).logicalSrcIdx = 30;
                    section.data(10).dtTransOffset = 1144;

                    ;% rtP.AnalogFilterDesign_C_pr_d0qgd0zcfa
                    section.data(11).logicalSrcIdx = 31;
                    section.data(11).dtTransOffset = 1145;

                    ;% rtP.AnalogFilterDesign_InitialCondition_bizf0yluzm
                    section.data(12).logicalSrcIdx = 32;
                    section.data(12).dtTransOffset = 1146;

                    ;% rtP.TransportDelay_Delay
                    section.data(13).logicalSrcIdx = 33;
                    section.data(13).dtTransOffset = 1147;

                    ;% rtP.TransportDelay_InitOutput_m3b1lj5lye
                    section.data(14).logicalSrcIdx = 34;
                    section.data(14).dtTransOffset = 1148;

                    ;% rtP.Integrator_IC
                    section.data(15).logicalSrcIdx = 35;
                    section.data(15).dtTransOffset = 1149;

                    ;% rtP.ModuloIntegrator_IC
                    section.data(16).logicalSrcIdx = 36;
                    section.data(16).dtTransOffset = 1150;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue
                    section.data(17).logicalSrcIdx = 37;
                    section.data(17).dtTransOffset = 1151;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue
                    section.data(18).logicalSrcIdx = 38;
                    section.data(18).dtTransOffset = 1152;

                    ;% rtP.AddConstant_Bias
                    section.data(19).logicalSrcIdx = 39;
                    section.data(19).dtTransOffset = 1153;

                    ;% rtP.Multiply_Gain
                    section.data(20).logicalSrcIdx = 40;
                    section.data(20).dtTransOffset = 1154;

                    ;% rtP.TransportDelay12_InitOutput
                    section.data(21).logicalSrcIdx = 41;
                    section.data(21).dtTransOffset = 1155;

                    ;% rtP.AnalogFilterDesign_A_pr_f4zixacbw1
                    section.data(22).logicalSrcIdx = 42;
                    section.data(22).dtTransOffset = 1156;

                    ;% rtP.AnalogFilterDesign_B_pr_by1sufu2fg
                    section.data(23).logicalSrcIdx = 43;
                    section.data(23).dtTransOffset = 1171;

                    ;% rtP.AnalogFilterDesign_C_pr_e3t31otpuq
                    section.data(24).logicalSrcIdx = 44;
                    section.data(24).dtTransOffset = 1172;

                    ;% rtP.AnalogFilterDesign_InitialCondition_gxj5snzs0v
                    section.data(25).logicalSrcIdx = 45;
                    section.data(25).dtTransOffset = 1173;

                    ;% rtP.TransportDelay2_InitOutput
                    section.data(26).logicalSrcIdx = 46;
                    section.data(26).dtTransOffset = 1174;

                    ;% rtP.TransportDelay1_InitOutput
                    section.data(27).logicalSrcIdx = 47;
                    section.data(27).dtTransOffset = 1175;

                    ;% rtP.TransportDelay4_InitOutput
                    section.data(28).logicalSrcIdx = 48;
                    section.data(28).dtTransOffset = 1176;

                    ;% rtP.TransportDelay3_InitOutput
                    section.data(29).logicalSrcIdx = 49;
                    section.data(29).dtTransOffset = 1177;

                    ;% rtP.TransportDelay6_InitOutput
                    section.data(30).logicalSrcIdx = 50;
                    section.data(30).dtTransOffset = 1178;

                    ;% rtP.TransportDelay5_InitOutput
                    section.data(31).logicalSrcIdx = 51;
                    section.data(31).dtTransOffset = 1179;

                    ;% rtP.TransportDelay8_InitOutput
                    section.data(32).logicalSrcIdx = 52;
                    section.data(32).dtTransOffset = 1180;

                    ;% rtP.TransportDelay7_InitOutput
                    section.data(33).logicalSrcIdx = 53;
                    section.data(33).dtTransOffset = 1181;

                    ;% rtP.TransportDelay9_InitOutput
                    section.data(34).logicalSrcIdx = 54;
                    section.data(34).dtTransOffset = 1182;

                    ;% rtP.TransportDelay11_InitOutput
                    section.data(35).logicalSrcIdx = 55;
                    section.data(35).dtTransOffset = 1183;

                    ;% rtP.Switch_Threshold
                    section.data(36).logicalSrcIdx = 56;
                    section.data(36).dtTransOffset = 1184;

                    ;% rtP.ModuloIntegrator_IC_g1vo2kap3u
                    section.data(37).logicalSrcIdx = 57;
                    section.data(37).dtTransOffset = 1185;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5
                    section.data(38).logicalSrcIdx = 58;
                    section.data(38).dtTransOffset = 1186;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk
                    section.data(39).logicalSrcIdx = 59;
                    section.data(39).dtTransOffset = 1187;

                    ;% rtP.Integrator_IC_oxpanuusbm
                    section.data(40).logicalSrcIdx = 60;
                    section.data(40).dtTransOffset = 1188;

                    ;% rtP.Integrator1_IC
                    section.data(41).logicalSrcIdx = 61;
                    section.data(41).dtTransOffset = 1189;

                    ;% rtP.Integrator_IC_a5b0eygpkp
                    section.data(42).logicalSrcIdx = 62;
                    section.data(42).dtTransOffset = 1190;

                    ;% rtP.Multiply_Gain_ptvyavefxe
                    section.data(43).logicalSrcIdx = 63;
                    section.data(43).dtTransOffset = 1191;

                    ;% rtP.AddConstant_Bias_ljcfbacsm3
                    section.data(44).logicalSrcIdx = 64;
                    section.data(44).dtTransOffset = 1192;

                    ;% rtP.SineWave_Bias
                    section.data(45).logicalSrcIdx = 65;
                    section.data(45).dtTransOffset = 1193;

                    ;% rtP.SineWave_Phase
                    section.data(46).logicalSrcIdx = 66;
                    section.data(46).dtTransOffset = 1194;

                    ;% rtP.Constant1_Value
                    section.data(47).logicalSrcIdx = 67;
                    section.data(47).dtTransOffset = 1195;

                    ;% rtP.Constant10_Value
                    section.data(48).logicalSrcIdx = 68;
                    section.data(48).dtTransOffset = 1196;

                    ;% rtP.Constant13_Value
                    section.data(49).logicalSrcIdx = 69;
                    section.data(49).dtTransOffset = 1197;

                    ;% rtP.Constant14_Value
                    section.data(50).logicalSrcIdx = 70;
                    section.data(50).dtTransOffset = 1198;

                    ;% rtP.Constant15_Value
                    section.data(51).logicalSrcIdx = 71;
                    section.data(51).dtTransOffset = 1199;

                    ;% rtP.Constant16_Value
                    section.data(52).logicalSrcIdx = 72;
                    section.data(52).dtTransOffset = 1200;

                    ;% rtP.Constant2_Value
                    section.data(53).logicalSrcIdx = 73;
                    section.data(53).dtTransOffset = 1201;

                    ;% rtP.Constant3_Value
                    section.data(54).logicalSrcIdx = 74;
                    section.data(54).dtTransOffset = 1202;

                    ;% rtP.Constant4_Value
                    section.data(55).logicalSrcIdx = 75;
                    section.data(55).dtTransOffset = 1203;

                    ;% rtP.Constant5_Value
                    section.data(56).logicalSrcIdx = 76;
                    section.data(56).dtTransOffset = 1204;

                    ;% rtP.Constant6_Value
                    section.data(57).logicalSrcIdx = 77;
                    section.data(57).dtTransOffset = 1205;

                    ;% rtP.Constant7_Value
                    section.data(58).logicalSrcIdx = 78;
                    section.data(58).dtTransOffset = 1206;

                    ;% rtP.Constant8_Value
                    section.data(59).logicalSrcIdx = 79;
                    section.data(59).dtTransOffset = 1207;

                    ;% rtP.Constant9_Value
                    section.data(60).logicalSrcIdx = 80;
                    section.data(60).dtTransOffset = 1208;

                    ;% rtP.Constant_Value
                    section.data(61).logicalSrcIdx = 81;
                    section.data(61).dtTransOffset = 1209;

                    ;% rtP.Constant1_Value_afssjxve00
                    section.data(62).logicalSrcIdx = 82;
                    section.data(62).dtTransOffset = 1210;

                    ;% rtP.posedge_Value
                    section.data(63).logicalSrcIdx = 83;
                    section.data(63).dtTransOffset = 1211;

                    ;% rtP.negedge_Value
                    section.data(64).logicalSrcIdx = 84;
                    section.data(64).dtTransOffset = 1213;

                    ;% rtP.eitheredge_Value
                    section.data(65).logicalSrcIdx = 85;
                    section.data(65).dtTransOffset = 1215;

                    ;% rtP.Constant2_Value_mwviqzbxqh
                    section.data(66).logicalSrcIdx = 86;
                    section.data(66).dtTransOffset = 1217;

                    ;% rtP.Constant5_Value_hu2bresth1
                    section.data(67).logicalSrcIdx = 87;
                    section.data(67).dtTransOffset = 1218;

                    ;% rtP.Constant6_Value_dkmziwbikw
                    section.data(68).logicalSrcIdx = 88;
                    section.data(68).dtTransOffset = 1219;

                    ;% rtP.Constant1_Value_hcjo4f4r5j
                    section.data(69).logicalSrcIdx = 89;
                    section.data(69).dtTransOffset = 1220;

                    ;% rtP.posedge_Value_av2r5ustik
                    section.data(70).logicalSrcIdx = 90;
                    section.data(70).dtTransOffset = 1221;

                    ;% rtP.negedge_Value_fef1hh2jz4
                    section.data(71).logicalSrcIdx = 91;
                    section.data(71).dtTransOffset = 1223;

                    ;% rtP.eitheredge_Value_nntils3rkv
                    section.data(72).logicalSrcIdx = 92;
                    section.data(72).dtTransOffset = 1225;

                    ;% rtP.posedge_Value_j0croo5cnv
                    section.data(73).logicalSrcIdx = 93;
                    section.data(73).dtTransOffset = 1227;

                    ;% rtP.negedge_Value_lnmee3h1ob
                    section.data(74).logicalSrcIdx = 94;
                    section.data(74).dtTransOffset = 1229;

                    ;% rtP.eitheredge_Value_gsipsgs54b
                    section.data(75).logicalSrcIdx = 95;
                    section.data(75).dtTransOffset = 1231;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 96;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 97;
                    section.data(2).dtTransOffset = 7;

                    ;% rtP.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 98;
                    section.data(3).dtTransOffset = 12;

                    ;% rtP.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 99;
                    section.data(4).dtTransOffset = 13;

                    ;% rtP.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 100;
                    section.data(5).dtTransOffset = 15;

                    ;% rtP.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 101;
                    section.data(6).dtTransOffset = 16;

                    ;% rtP.AnalogFilterDesign_A_ir_gqpywhsxtr
                    section.data(7).logicalSrcIdx = 102;
                    section.data(7).dtTransOffset = 21;

                    ;% rtP.AnalogFilterDesign_A_jc_fyftqxybap
                    section.data(8).logicalSrcIdx = 103;
                    section.data(8).dtTransOffset = 28;

                    ;% rtP.AnalogFilterDesign_B_ir_gklrfvy2xp
                    section.data(9).logicalSrcIdx = 104;
                    section.data(9).dtTransOffset = 33;

                    ;% rtP.AnalogFilterDesign_B_jc_nk0ranamkl
                    section.data(10).logicalSrcIdx = 105;
                    section.data(10).dtTransOffset = 34;

                    ;% rtP.AnalogFilterDesign_C_ir_jr05e5amzn
                    section.data(11).logicalSrcIdx = 106;
                    section.data(11).dtTransOffset = 36;

                    ;% rtP.AnalogFilterDesign_C_jc_jc5wcv0wk2
                    section.data(12).logicalSrcIdx = 107;
                    section.data(12).dtTransOffset = 37;

                    ;% rtP.AnalogFilterDesign_A_ir_cx1zj2mhzp
                    section.data(13).logicalSrcIdx = 108;
                    section.data(13).dtTransOffset = 42;

                    ;% rtP.AnalogFilterDesign_A_jc_h5xar20tzm
                    section.data(14).logicalSrcIdx = 109;
                    section.data(14).dtTransOffset = 57;

                    ;% rtP.AnalogFilterDesign_B_ir_nneewrak4c
                    section.data(15).logicalSrcIdx = 110;
                    section.data(15).dtTransOffset = 66;

                    ;% rtP.AnalogFilterDesign_B_jc_acwf2d2gj0
                    section.data(16).logicalSrcIdx = 111;
                    section.data(16).dtTransOffset = 67;

                    ;% rtP.AnalogFilterDesign_C_ir_cqrtf32rbd
                    section.data(17).logicalSrcIdx = 112;
                    section.data(17).dtTransOffset = 69;

                    ;% rtP.AnalogFilterDesign_C_jc_d2bgogmalx
                    section.data(18).logicalSrcIdx = 113;
                    section.data(18).dtTransOffset = 70;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.OUT_Y0
                    section.data(1).logicalSrcIdx = 114;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.OUT_Y0_gbikirmbla
                    section.data(2).logicalSrcIdx = 115;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Q_Y0
                    section.data(3).logicalSrcIdx = 116;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Q_Y0_ngs1cr5pq5
                    section.data(4).logicalSrcIdx = 117;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Memory_InitialCondition
                    section.data(5).logicalSrcIdx = 118;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.TmpLatchAtDFlipFlopInport1_InitialCondition
                    section.data(6).logicalSrcIdx = 119;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Memory_InitialCondition_oggd2r4odw
                    section.data(7).logicalSrcIdx = 120;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Memory_InitialCondition_ljulw4woig
                    section.data(8).logicalSrcIdx = 121;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.o0byjwoyow._Y0
                    section.data(1).logicalSrcIdx = 122;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.llvx0kbake.OUT_Y0
                    section.data(1).logicalSrcIdx = 123;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.iewfgzwb31.OUT_Y0
                    section.data(1).logicalSrcIdx = 124;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ligjpsfhvtg.OUT_Y0
                    section.data(1).logicalSrcIdx = 125;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.mjqilvpgl54.OUT_Y0
                    section.data(1).logicalSrcIdx = 126;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.mnr2afncj2u._Y0
                    section.data(1).logicalSrcIdx = 127;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 59;
            section.data(59)  = dumData; %prealloc

                    ;% rtB.pczptaloqn
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.lyy2rgzssu
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.b4klkr2hpb
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.mttr3remqe
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.azmfpdpfhr
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.b4dgdwqfvr
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.apurb3sda3
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.c5jqurmpza
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.hssaqyb021
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.nqw3knpw3y
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.nqqxqhj4uh
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.aibuxow2f4
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.i0c1bgukye
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.fewalbo2ov
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.azchjpegsm
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.ihiwfhuo0a
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.hkn2g3gvsz
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.ntkisuxn2g
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.m4m214ovbs
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.pndfq3ndef
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.oxkodghnh1
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.g53czseiki
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.icz5jiqa5l
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.l0uo4a4mr4
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.ntk0mkheco
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.fqfddfhgnv
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.k4j5el1r4t
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.ac5onrei0k
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.bz0pvs5lfr
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.dmtaqaxly0
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.abjvxeqou3
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.ie0mnn5bjz
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.ngmqsygkuj
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtB.kpyjbyqhnn
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtB.nqzijf3v2s
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtB.bzfqsaqdca
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtB.cdlxrrgn43
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtB.majhbieqf2
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtB.mojdhi2f5w
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtB.myomqf4clw
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtB.cqgvyb1usr
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtB.otmkurmb40
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtB.g1iqixqqbk
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

                    ;% rtB.le03i4u1w1
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 43;

                    ;% rtB.dxkzb2shae
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 44;

                    ;% rtB.bcqstcbcss
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 45;

                    ;% rtB.klpoi14tq3
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 46;

                    ;% rtB.btco2hfhqs
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 47;

                    ;% rtB.j5xzo5caz4
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 48;

                    ;% rtB.m2lqawkue3
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 49;

                    ;% rtB.njbn3w11wn
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 50;

                    ;% rtB.k3v5lqeyfa
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 51;

                    ;% rtB.ommuhpqjnr
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 52;

                    ;% rtB.g2d1qhfmtb
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 53;

                    ;% rtB.f4wxz52mc5
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 54;

                    ;% rtB.pyvoagmwyq
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 56;

                    ;% rtB.ppuci252pa
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 58;

                    ;% rtB.bnrnxdd0vt
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 60;

                    ;% rtB.gpjz2pf2n0
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 61;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtB.orn3venhnk
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.azngqgys3a
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.mmbwdvbds0
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.ndzz4ltczv
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.bik1lk5raz
                    section.data(5).logicalSrcIdx = 63;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.elhj11vpue
                    section.data(6).logicalSrcIdx = 64;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.pnc2oxbc5h
                    section.data(7).logicalSrcIdx = 65;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.nlky1z3g2k
                    section.data(8).logicalSrcIdx = 66;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.ov3s20wyhx
                    section.data(9).logicalSrcIdx = 67;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.grenet1so1
                    section.data(10).logicalSrcIdx = 68;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.gzklf0ilir
                    section.data(11).logicalSrcIdx = 69;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.o0byjwoyow.lzgwbwuubl
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.llvx0kbake.elss3awww2
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.iewfgzwb31.o3dp55eklq
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ligjpsfhvtg.elss3awww2
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.mjqilvpgl54.o3dp55eklq
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.mnr2afncj2u.lzgwbwuubl
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 11;
        sectIdxOffset = 8;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtDW.eflcwal1mu
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.oquiajmyfp
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ltasifvkde
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.iksurbbs2u
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.nkspyzjmj0
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.owd5cjyj4l.modelTStart
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.i4xfbt1z25.modelTStart
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.ky1a3dnkiw.modelTStart
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.fwikzb00to.modelTStart
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.azfsgwj0il.modelTStart
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.i30swi3eeg.modelTStart
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.bjvck4ijez.modelTStart
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.idakjgagwj.modelTStart
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.j0o0q4ccss.modelTStart
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.jx0fvxr0vd.modelTStart
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.moy4nejcr1.modelTStart
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.pf1rurynfs.modelTStart
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.brbjfuklas.modelTStart
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% rtDW.g24kh0yl0d.TimePtr
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.iufdazrcci.TUbufferPtrs
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.d3b3zasoji.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 3;

                    ;% rtDW.fqpjvnu3on.TUbufferPtrs
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 5;

                    ;% rtDW.k1ubjjkoqs.LoggedData
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 7;

                    ;% rtDW.am5rag2bw4.LoggedData
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 14;

                    ;% rtDW.ii1qwqcizu.TUbufferPtrs
                    section.data(7).logicalSrcIdx = 24;
                    section.data(7).dtTransOffset = 18;

                    ;% rtDW.gbr1avzpo5.TUbufferPtrs
                    section.data(8).logicalSrcIdx = 25;
                    section.data(8).dtTransOffset = 20;

                    ;% rtDW.e02rtjhnng.TUbufferPtrs
                    section.data(9).logicalSrcIdx = 26;
                    section.data(9).dtTransOffset = 22;

                    ;% rtDW.hmhofpz1ew.TUbufferPtrs
                    section.data(10).logicalSrcIdx = 27;
                    section.data(10).dtTransOffset = 24;

                    ;% rtDW.audlhahb3y.TUbufferPtrs
                    section.data(11).logicalSrcIdx = 28;
                    section.data(11).dtTransOffset = 26;

                    ;% rtDW.c0b2si44of.TUbufferPtrs
                    section.data(12).logicalSrcIdx = 29;
                    section.data(12).dtTransOffset = 28;

                    ;% rtDW.px5wrgqdsn.TUbufferPtrs
                    section.data(13).logicalSrcIdx = 30;
                    section.data(13).dtTransOffset = 30;

                    ;% rtDW.dqimiih00v.TUbufferPtrs
                    section.data(14).logicalSrcIdx = 31;
                    section.data(14).dtTransOffset = 32;

                    ;% rtDW.hyxywufgvp.TUbufferPtrs
                    section.data(15).logicalSrcIdx = 32;
                    section.data(15).dtTransOffset = 34;

                    ;% rtDW.ibeq1uqak3.TUbufferPtrs
                    section.data(16).logicalSrcIdx = 33;
                    section.data(16).dtTransOffset = 36;

                    ;% rtDW.ez41hqhdtp.LoggedData
                    section.data(17).logicalSrcIdx = 34;
                    section.data(17).dtTransOffset = 38;

                    ;% rtDW.lu3ggubgbi.LoggedData
                    section.data(18).logicalSrcIdx = 35;
                    section.data(18).dtTransOffset = 42;

                    ;% rtDW.h3b22feudi.AQHandles
                    section.data(19).logicalSrcIdx = 36;
                    section.data(19).dtTransOffset = 46;

                    ;% rtDW.muv5ta45dz.LoggedData
                    section.data(20).logicalSrcIdx = 37;
                    section.data(20).dtTransOffset = 47;

                    ;% rtDW.dmu42kigql.AQHandles
                    section.data(21).logicalSrcIdx = 38;
                    section.data(21).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtDW.kqimps20tr.PrevIndex
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bijp5lznr0.Tail
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.gozlgoace0.Tail
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jukyp4co3s.Tail
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.dwcos053mm.Tail
                    section.data(5).logicalSrcIdx = 43;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ar3vwuqqcr.Tail
                    section.data(6).logicalSrcIdx = 44;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.pbrpegxnve.Tail
                    section.data(7).logicalSrcIdx = 45;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.otun30mznk.Tail
                    section.data(8).logicalSrcIdx = 46;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.etsjn5fqxr.Tail
                    section.data(9).logicalSrcIdx = 47;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.dm031mdhzh.Tail
                    section.data(10).logicalSrcIdx = 48;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.dwt1logpyt.Tail
                    section.data(11).logicalSrcIdx = 49;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.olvi0wrke2.Tail
                    section.data(12).logicalSrcIdx = 50;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.h0xflbr2r2.Tail
                    section.data(13).logicalSrcIdx = 51;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.o5k3wqz1te.Tail
                    section.data(14).logicalSrcIdx = 52;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.nl35cfre3r
                    section.data(15).logicalSrcIdx = 53;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.kp4ub4djpq
                    section.data(16).logicalSrcIdx = 54;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.miaubkp1tz
                    section.data(17).logicalSrcIdx = 55;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.frfvjoiupy
                    section.data(18).logicalSrcIdx = 56;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.n1tmln402w
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mtstnsjsji
                    section.data(2).logicalSrcIdx = 58;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.kudt5h2w0b
                    section.data(3).logicalSrcIdx = 59;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.kg30gk0yon
                    section.data(4).logicalSrcIdx = 60;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.iuuqkwmjrb
                    section.data(5).logicalSrcIdx = 61;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ork2mu3aqa
                    section.data(6).logicalSrcIdx = 62;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtDW.fgt0gfkzzs
                    section.data(1).logicalSrcIdx = 63;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cqe343kytb
                    section.data(2).logicalSrcIdx = 64;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.mvcna0flrg
                    section.data(3).logicalSrcIdx = 65;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.al2bessz01
                    section.data(4).logicalSrcIdx = 66;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.luewrj1rxn
                    section.data(5).logicalSrcIdx = 67;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.isfqm5nn3q
                    section.data(6).logicalSrcIdx = 68;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.nbeww3raq3
                    section.data(7).logicalSrcIdx = 69;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.gqsz4zovj0
                    section.data(8).logicalSrcIdx = 70;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.g22bx3mwrj
                    section.data(9).logicalSrcIdx = 71;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.gywfygl1db
                    section.data(10).logicalSrcIdx = 72;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.c01gnuxhwv
                    section.data(11).logicalSrcIdx = 73;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.o0byjwoyow.bmw2hixe1f
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.llvx0kbake.idqwe24upn
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.iewfgzwb31.fulyjjxmue
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ligjpsfhvtg.idqwe24upn
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mjqilvpgl54.fulyjjxmue
                    section.data(1).logicalSrcIdx = 78;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mnr2afncj2u.bmw2hixe1f
                    section.data(1).logicalSrcIdx = 79;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3022713193;
    targMap.checksum1 = 4233992415;
    targMap.checksum2 = 1504175238;
    targMap.checksum3 = 3029251898;

