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
            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% rtP.Amplitud
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AmplitudPortadora
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Att_Volt_Canal
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.C
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Frec_port
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Kv
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Pot_Ruido
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.R1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.R2
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Rb
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Retraso_Canal
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Tb
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.b
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.kv2
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.Monostable1_EdgeDetect
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Monostable3_EdgeDetect
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.SampleandHold_ic
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.Monostable1_ic
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.SampleHold_ic
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.Monostable3_ic
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.SampleHold_ic_cvpetr2ktj
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.Monostable_ic
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 77;
            section.data(77)  = dumData; %prealloc

                    ;% rtP.Out1_Y0
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP._Y0
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.FromWorkspace_Data0
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.AnalogFilterDesign_A_pr
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 1126;

                    ;% rtP.AnalogFilterDesign_B_pr
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 1133;

                    ;% rtP.AnalogFilterDesign_C_pr
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 1134;

                    ;% rtP.AnalogFilterDesign_InitialCondition
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 1135;

                    ;% rtP.TransportDelay_InitOutput
                    section.data(8).logicalSrcIdx = 30;
                    section.data(8).dtTransOffset = 1136;

                    ;% rtP.RuidoAGWN_Mean
                    section.data(9).logicalSrcIdx = 31;
                    section.data(9).dtTransOffset = 1137;

                    ;% rtP.RuidoAGWN_Seed
                    section.data(10).logicalSrcIdx = 32;
                    section.data(10).dtTransOffset = 1138;

                    ;% rtP.AnalogFilterDesign_A_pr_jsdcqwampi
                    section.data(11).logicalSrcIdx = 33;
                    section.data(11).dtTransOffset = 1139;

                    ;% rtP.AnalogFilterDesign_B_pr_om0jg41jmb
                    section.data(12).logicalSrcIdx = 34;
                    section.data(12).dtTransOffset = 1146;

                    ;% rtP.AnalogFilterDesign_C_pr_d0qgd0zcfa
                    section.data(13).logicalSrcIdx = 35;
                    section.data(13).dtTransOffset = 1147;

                    ;% rtP.AnalogFilterDesign_InitialCondition_bizf0yluzm
                    section.data(14).logicalSrcIdx = 36;
                    section.data(14).dtTransOffset = 1148;

                    ;% rtP.TransportDelay_Delay
                    section.data(15).logicalSrcIdx = 37;
                    section.data(15).dtTransOffset = 1149;

                    ;% rtP.TransportDelay_InitOutput_m3b1lj5lye
                    section.data(16).logicalSrcIdx = 38;
                    section.data(16).dtTransOffset = 1150;

                    ;% rtP.Integrator_IC
                    section.data(17).logicalSrcIdx = 39;
                    section.data(17).dtTransOffset = 1151;

                    ;% rtP.ModuloIntegrator_IC
                    section.data(18).logicalSrcIdx = 40;
                    section.data(18).dtTransOffset = 1152;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue
                    section.data(19).logicalSrcIdx = 41;
                    section.data(19).dtTransOffset = 1153;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue
                    section.data(20).logicalSrcIdx = 42;
                    section.data(20).dtTransOffset = 1154;

                    ;% rtP.TransportDelay2_InitOutput
                    section.data(21).logicalSrcIdx = 43;
                    section.data(21).dtTransOffset = 1155;

                    ;% rtP.TransportDelay1_InitOutput
                    section.data(22).logicalSrcIdx = 44;
                    section.data(22).dtTransOffset = 1156;

                    ;% rtP.TransportDelay4_InitOutput
                    section.data(23).logicalSrcIdx = 45;
                    section.data(23).dtTransOffset = 1157;

                    ;% rtP.TransportDelay3_InitOutput
                    section.data(24).logicalSrcIdx = 46;
                    section.data(24).dtTransOffset = 1158;

                    ;% rtP.TransportDelay6_InitOutput
                    section.data(25).logicalSrcIdx = 47;
                    section.data(25).dtTransOffset = 1159;

                    ;% rtP.TransportDelay5_InitOutput
                    section.data(26).logicalSrcIdx = 48;
                    section.data(26).dtTransOffset = 1160;

                    ;% rtP.TransportDelay8_InitOutput
                    section.data(27).logicalSrcIdx = 49;
                    section.data(27).dtTransOffset = 1161;

                    ;% rtP.TransportDelay7_InitOutput
                    section.data(28).logicalSrcIdx = 50;
                    section.data(28).dtTransOffset = 1162;

                    ;% rtP.TransportDelay9_InitOutput
                    section.data(29).logicalSrcIdx = 51;
                    section.data(29).dtTransOffset = 1163;

                    ;% rtP.TransportDelay11_InitOutput
                    section.data(30).logicalSrcIdx = 52;
                    section.data(30).dtTransOffset = 1164;

                    ;% rtP.Switch_Threshold
                    section.data(31).logicalSrcIdx = 53;
                    section.data(31).dtTransOffset = 1165;

                    ;% rtP.AnalogFilterDesign_A_pr_gc0kz31g5a
                    section.data(32).logicalSrcIdx = 54;
                    section.data(32).dtTransOffset = 1166;

                    ;% rtP.AnalogFilterDesign_B_pr_kq1k3m2fjm
                    section.data(33).logicalSrcIdx = 55;
                    section.data(33).dtTransOffset = 1173;

                    ;% rtP.AnalogFilterDesign_C_pr_aqq5iiwnf2
                    section.data(34).logicalSrcIdx = 56;
                    section.data(34).dtTransOffset = 1174;

                    ;% rtP.AnalogFilterDesign_InitialCondition_l2mskoueic
                    section.data(35).logicalSrcIdx = 57;
                    section.data(35).dtTransOffset = 1175;

                    ;% rtP.AnalogFilterDesign_A_pr_f4zixacbw1
                    section.data(36).logicalSrcIdx = 58;
                    section.data(36).dtTransOffset = 1176;

                    ;% rtP.AnalogFilterDesign_B_pr_by1sufu2fg
                    section.data(37).logicalSrcIdx = 59;
                    section.data(37).dtTransOffset = 1191;

                    ;% rtP.AnalogFilterDesign_C_pr_e3t31otpuq
                    section.data(38).logicalSrcIdx = 60;
                    section.data(38).dtTransOffset = 1192;

                    ;% rtP.AnalogFilterDesign_InitialCondition_gxj5snzs0v
                    section.data(39).logicalSrcIdx = 61;
                    section.data(39).dtTransOffset = 1193;

                    ;% rtP.ModuloIntegrator_IC_g1vo2kap3u
                    section.data(40).logicalSrcIdx = 62;
                    section.data(40).dtTransOffset = 1194;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5
                    section.data(41).logicalSrcIdx = 63;
                    section.data(41).dtTransOffset = 1195;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk
                    section.data(42).logicalSrcIdx = 64;
                    section.data(42).dtTransOffset = 1196;

                    ;% rtP.Integrator_IC_oxpanuusbm
                    section.data(43).logicalSrcIdx = 65;
                    section.data(43).dtTransOffset = 1197;

                    ;% rtP.Integrator1_IC
                    section.data(44).logicalSrcIdx = 66;
                    section.data(44).dtTransOffset = 1198;

                    ;% rtP.Integrator_IC_a5b0eygpkp
                    section.data(45).logicalSrcIdx = 67;
                    section.data(45).dtTransOffset = 1199;

                    ;% rtP.Multiply_Gain
                    section.data(46).logicalSrcIdx = 68;
                    section.data(46).dtTransOffset = 1200;

                    ;% rtP.AddConstant_Bias
                    section.data(47).logicalSrcIdx = 69;
                    section.data(47).dtTransOffset = 1201;

                    ;% rtP.SineWave_Bias
                    section.data(48).logicalSrcIdx = 70;
                    section.data(48).dtTransOffset = 1202;

                    ;% rtP.SineWave_Phase
                    section.data(49).logicalSrcIdx = 71;
                    section.data(49).dtTransOffset = 1203;

                    ;% rtP.Constant1_Value
                    section.data(50).logicalSrcIdx = 72;
                    section.data(50).dtTransOffset = 1204;

                    ;% rtP.Constant10_Value
                    section.data(51).logicalSrcIdx = 73;
                    section.data(51).dtTransOffset = 1205;

                    ;% rtP.Constant13_Value
                    section.data(52).logicalSrcIdx = 74;
                    section.data(52).dtTransOffset = 1206;

                    ;% rtP.Constant14_Value
                    section.data(53).logicalSrcIdx = 75;
                    section.data(53).dtTransOffset = 1207;

                    ;% rtP.Constant15_Value
                    section.data(54).logicalSrcIdx = 76;
                    section.data(54).dtTransOffset = 1208;

                    ;% rtP.Constant16_Value
                    section.data(55).logicalSrcIdx = 77;
                    section.data(55).dtTransOffset = 1209;

                    ;% rtP.Constant2_Value
                    section.data(56).logicalSrcIdx = 78;
                    section.data(56).dtTransOffset = 1210;

                    ;% rtP.Constant3_Value
                    section.data(57).logicalSrcIdx = 79;
                    section.data(57).dtTransOffset = 1211;

                    ;% rtP.Constant4_Value
                    section.data(58).logicalSrcIdx = 80;
                    section.data(58).dtTransOffset = 1212;

                    ;% rtP.Constant5_Value
                    section.data(59).logicalSrcIdx = 81;
                    section.data(59).dtTransOffset = 1213;

                    ;% rtP.Constant6_Value
                    section.data(60).logicalSrcIdx = 82;
                    section.data(60).dtTransOffset = 1214;

                    ;% rtP.Constant7_Value
                    section.data(61).logicalSrcIdx = 83;
                    section.data(61).dtTransOffset = 1215;

                    ;% rtP.Constant8_Value
                    section.data(62).logicalSrcIdx = 84;
                    section.data(62).dtTransOffset = 1216;

                    ;% rtP.Constant9_Value
                    section.data(63).logicalSrcIdx = 85;
                    section.data(63).dtTransOffset = 1217;

                    ;% rtP.Constant1_Value_afssjxve00
                    section.data(64).logicalSrcIdx = 86;
                    section.data(64).dtTransOffset = 1218;

                    ;% rtP.posedge_Value
                    section.data(65).logicalSrcIdx = 87;
                    section.data(65).dtTransOffset = 1219;

                    ;% rtP.negedge_Value
                    section.data(66).logicalSrcIdx = 88;
                    section.data(66).dtTransOffset = 1221;

                    ;% rtP.eitheredge_Value
                    section.data(67).logicalSrcIdx = 89;
                    section.data(67).dtTransOffset = 1223;

                    ;% rtP.Constant2_Value_mwviqzbxqh
                    section.data(68).logicalSrcIdx = 90;
                    section.data(68).dtTransOffset = 1225;

                    ;% rtP.Constant5_Value_hu2bresth1
                    section.data(69).logicalSrcIdx = 91;
                    section.data(69).dtTransOffset = 1226;

                    ;% rtP.Constant6_Value_dkmziwbikw
                    section.data(70).logicalSrcIdx = 92;
                    section.data(70).dtTransOffset = 1227;

                    ;% rtP.Constant1_Value_hcjo4f4r5j
                    section.data(71).logicalSrcIdx = 93;
                    section.data(71).dtTransOffset = 1228;

                    ;% rtP.posedge_Value_av2r5ustik
                    section.data(72).logicalSrcIdx = 94;
                    section.data(72).dtTransOffset = 1229;

                    ;% rtP.negedge_Value_fef1hh2jz4
                    section.data(73).logicalSrcIdx = 95;
                    section.data(73).dtTransOffset = 1231;

                    ;% rtP.eitheredge_Value_nntils3rkv
                    section.data(74).logicalSrcIdx = 96;
                    section.data(74).dtTransOffset = 1233;

                    ;% rtP.posedge_Value_j0croo5cnv
                    section.data(75).logicalSrcIdx = 97;
                    section.data(75).dtTransOffset = 1235;

                    ;% rtP.negedge_Value_lnmee3h1ob
                    section.data(76).logicalSrcIdx = 98;
                    section.data(76).dtTransOffset = 1237;

                    ;% rtP.eitheredge_Value_gsipsgs54b
                    section.data(77).logicalSrcIdx = 99;
                    section.data(77).dtTransOffset = 1239;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 100;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 101;
                    section.data(2).dtTransOffset = 7;

                    ;% rtP.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 102;
                    section.data(3).dtTransOffset = 12;

                    ;% rtP.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 103;
                    section.data(4).dtTransOffset = 13;

                    ;% rtP.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 104;
                    section.data(5).dtTransOffset = 15;

                    ;% rtP.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 105;
                    section.data(6).dtTransOffset = 16;

                    ;% rtP.AnalogFilterDesign_A_ir_gqpywhsxtr
                    section.data(7).logicalSrcIdx = 106;
                    section.data(7).dtTransOffset = 21;

                    ;% rtP.AnalogFilterDesign_A_jc_fyftqxybap
                    section.data(8).logicalSrcIdx = 107;
                    section.data(8).dtTransOffset = 28;

                    ;% rtP.AnalogFilterDesign_B_ir_gklrfvy2xp
                    section.data(9).logicalSrcIdx = 108;
                    section.data(9).dtTransOffset = 33;

                    ;% rtP.AnalogFilterDesign_B_jc_nk0ranamkl
                    section.data(10).logicalSrcIdx = 109;
                    section.data(10).dtTransOffset = 34;

                    ;% rtP.AnalogFilterDesign_C_ir_jr05e5amzn
                    section.data(11).logicalSrcIdx = 110;
                    section.data(11).dtTransOffset = 36;

                    ;% rtP.AnalogFilterDesign_C_jc_jc5wcv0wk2
                    section.data(12).logicalSrcIdx = 111;
                    section.data(12).dtTransOffset = 37;

                    ;% rtP.AnalogFilterDesign_A_ir_o3wehlil1t
                    section.data(13).logicalSrcIdx = 112;
                    section.data(13).dtTransOffset = 42;

                    ;% rtP.AnalogFilterDesign_A_jc_hepc5hv3fw
                    section.data(14).logicalSrcIdx = 113;
                    section.data(14).dtTransOffset = 49;

                    ;% rtP.AnalogFilterDesign_B_ir_bqybfmsaae
                    section.data(15).logicalSrcIdx = 114;
                    section.data(15).dtTransOffset = 54;

                    ;% rtP.AnalogFilterDesign_B_jc_cfquo51aq1
                    section.data(16).logicalSrcIdx = 115;
                    section.data(16).dtTransOffset = 55;

                    ;% rtP.AnalogFilterDesign_C_ir_ivqqscx0vn
                    section.data(17).logicalSrcIdx = 116;
                    section.data(17).dtTransOffset = 57;

                    ;% rtP.AnalogFilterDesign_C_jc_llcs1qdtjn
                    section.data(18).logicalSrcIdx = 117;
                    section.data(18).dtTransOffset = 58;

                    ;% rtP.AnalogFilterDesign_A_ir_cx1zj2mhzp
                    section.data(19).logicalSrcIdx = 118;
                    section.data(19).dtTransOffset = 63;

                    ;% rtP.AnalogFilterDesign_A_jc_h5xar20tzm
                    section.data(20).logicalSrcIdx = 119;
                    section.data(20).dtTransOffset = 78;

                    ;% rtP.AnalogFilterDesign_B_ir_nneewrak4c
                    section.data(21).logicalSrcIdx = 120;
                    section.data(21).dtTransOffset = 87;

                    ;% rtP.AnalogFilterDesign_B_jc_acwf2d2gj0
                    section.data(22).logicalSrcIdx = 121;
                    section.data(22).dtTransOffset = 88;

                    ;% rtP.AnalogFilterDesign_C_ir_cqrtf32rbd
                    section.data(23).logicalSrcIdx = 122;
                    section.data(23).dtTransOffset = 90;

                    ;% rtP.AnalogFilterDesign_C_jc_d2bgogmalx
                    section.data(24).logicalSrcIdx = 123;
                    section.data(24).dtTransOffset = 91;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.OUT_Y0
                    section.data(1).logicalSrcIdx = 124;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.OUT_Y0_gbikirmbla
                    section.data(2).logicalSrcIdx = 125;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Q_Y0
                    section.data(3).logicalSrcIdx = 126;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Q_Y0_ngs1cr5pq5
                    section.data(4).logicalSrcIdx = 127;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Memory_InitialCondition
                    section.data(5).logicalSrcIdx = 128;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.TmpLatchAtDFlipFlopInport1_InitialCondition
                    section.data(6).logicalSrcIdx = 129;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Memory_InitialCondition_oggd2r4odw
                    section.data(7).logicalSrcIdx = 130;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Memory_InitialCondition_ljulw4woig
                    section.data(8).logicalSrcIdx = 131;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.pokud50mlj._Y0
                    section.data(1).logicalSrcIdx = 132;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.l2pxsorbc0.OUT_Y0
                    section.data(1).logicalSrcIdx = 133;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ntt0n0z3qa.OUT_Y0
                    section.data(1).logicalSrcIdx = 134;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.guziuj3nzou.OUT_Y0
                    section.data(1).logicalSrcIdx = 135;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.obgcvvf2c2c.OUT_Y0
                    section.data(1).logicalSrcIdx = 136;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.f5g5ssvz0ob._Y0
                    section.data(1).logicalSrcIdx = 137;
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
            section.nData     = 52;
            section.data(52)  = dumData; %prealloc

                    ;% rtB.cjskazwmh1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.d4txlaulvr
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.f2es2rkn4r
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.ailrsbpb25
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.bfrc2rc5zl
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.ncdgrorzsx
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.pl5zjiseby
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.nihlui3tdy
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.gopo0ay43o
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.hs04wl1crq
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.pznu3l5z1a
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.bhvr0udrsy
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.kmqtx532fz
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.hnp1kuefxm
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.lsnuriwz44
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.lisuhkiql3
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.ewq0jsmjdj
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.dv3oqsxz41
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.nz2mzf3abt
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.geeegghaq4
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.eancnret3z
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.m2vnyqktog
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.k3la20515u
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.jfofwf5qdn
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.k0hg52okk1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.dxje1nzfb1
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.lrg23dznf5
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.ncgerps2w1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.dzwzyjfb3d
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.c1tvvwnguu
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.pxicmncoih
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.ao3hvbk03u
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.cjvhltyh5i
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtB.awbajcw3bs
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtB.k0xpbzxvuq
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtB.pgstwodvgn
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtB.ji14ejc3mp
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtB.agrizcdfza
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtB.mxxtwp3ieb
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtB.o0mruwezip
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtB.dwgm1iwulr
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtB.h3lftethav
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtB.kiqo1dkx4d
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

                    ;% rtB.ki1f5bwrru
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 43;

                    ;% rtB.o51erkdynh
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 44;

                    ;% rtB.asbkydpcdt
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 45;

                    ;% rtB.mxwhtwoxqb
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 46;

                    ;% rtB.hzfal5kgng
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 47;

                    ;% rtB.kppvt5er43
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 48;

                    ;% rtB.ck3j1srrxl
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 50;

                    ;% rtB.pnagitghhg
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 52;

                    ;% rtB.amouf3rzmf
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 54;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% rtB.p4bwi2pbc0
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.efvczhdjet
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ftifgsd50u
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.hrmk3oqzup
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.fv3qrvs3nd
                    section.data(5).logicalSrcIdx = 56;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.bq2qwyyni3
                    section.data(6).logicalSrcIdx = 57;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.bxjduwjkqo
                    section.data(7).logicalSrcIdx = 58;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.ohloxwa40r
                    section.data(8).logicalSrcIdx = 59;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.lfy2bgoxg0
                    section.data(9).logicalSrcIdx = 60;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.d0uzclm1vr
                    section.data(10).logicalSrcIdx = 61;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.pet04kmorq
                    section.data(11).logicalSrcIdx = 62;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.i3hvpke3ms
                    section.data(12).logicalSrcIdx = 63;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.octfr53rd1
                    section.data(13).logicalSrcIdx = 64;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.pokud50mlj.n0jiemzt0m
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.l2pxsorbc0.fncspxqpzn
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ntt0n0z3qa.gcuafzmxgi
                    section.data(1).logicalSrcIdx = 67;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.guziuj3nzou.fncspxqpzn
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.obgcvvf2c2c.gcuafzmxgi
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.f5g5ssvz0ob.n0jiemzt0m
                    section.data(1).logicalSrcIdx = 70;
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
        nTotSects     = 16;
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

                    ;% rtDW.idhuf1euoi
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cuilob0auh
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.g4c0zz45r4
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.gamney3fyk
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.hobor2c3tl
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.jkafh5jkcy
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.lddp3kj4wc.modelTStart
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.bj4mi1vzil.modelTStart
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.p5cigbuwvn.modelTStart
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.gf4lfoijb0.modelTStart
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.okq3xbd2ii.modelTStart
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.iobbwey3sn.modelTStart
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.e334mwrkee.modelTStart
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.pryezgtgn4.modelTStart
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.hzbip0oysg.modelTStart
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.huh20tu5q1.modelTStart
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.agxdp5talt.modelTStart
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.nb2ebbj1qe.modelTStart
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 22;
            section.data(22)  = dumData; %prealloc

                    ;% rtDW.c550b3xklm.TimePtr
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.jc1itafzwd.TUbufferPtrs
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lj1tdbxggs.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 3;

                    ;% rtDW.ml2avl24pf.TUbufferPtrs
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 5;

                    ;% rtDW.fbk251u41l.TUbufferPtrs
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 7;

                    ;% rtDW.kpvx4uvt01.TUbufferPtrs
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 9;

                    ;% rtDW.oeere24mz0.TUbufferPtrs
                    section.data(7).logicalSrcIdx = 24;
                    section.data(7).dtTransOffset = 11;

                    ;% rtDW.h1egexnfwb.TUbufferPtrs
                    section.data(8).logicalSrcIdx = 25;
                    section.data(8).dtTransOffset = 13;

                    ;% rtDW.lycpuo0tla.TUbufferPtrs
                    section.data(9).logicalSrcIdx = 26;
                    section.data(9).dtTransOffset = 15;

                    ;% rtDW.etoiwhh4sj.TUbufferPtrs
                    section.data(10).logicalSrcIdx = 27;
                    section.data(10).dtTransOffset = 17;

                    ;% rtDW.l4z1r030na.TUbufferPtrs
                    section.data(11).logicalSrcIdx = 28;
                    section.data(11).dtTransOffset = 19;

                    ;% rtDW.e3lmwmye5o.TUbufferPtrs
                    section.data(12).logicalSrcIdx = 29;
                    section.data(12).dtTransOffset = 21;

                    ;% rtDW.mxtwjhbmuw.TUbufferPtrs
                    section.data(13).logicalSrcIdx = 30;
                    section.data(13).dtTransOffset = 23;

                    ;% rtDW.j30qutghas.LoggedData
                    section.data(14).logicalSrcIdx = 31;
                    section.data(14).dtTransOffset = 25;

                    ;% rtDW.o1r21qardz.LoggedData
                    section.data(15).logicalSrcIdx = 32;
                    section.data(15).dtTransOffset = 32;

                    ;% rtDW.apsrc53ins.LoggedData
                    section.data(16).logicalSrcIdx = 33;
                    section.data(16).dtTransOffset = 35;

                    ;% rtDW.kmyqkb4ou1.LoggedData
                    section.data(17).logicalSrcIdx = 34;
                    section.data(17).dtTransOffset = 39;

                    ;% rtDW.diduvlcjw5.LoggedData
                    section.data(18).logicalSrcIdx = 35;
                    section.data(18).dtTransOffset = 43;

                    ;% rtDW.otc0z4rhtr.LoggedData
                    section.data(19).logicalSrcIdx = 36;
                    section.data(19).dtTransOffset = 47;

                    ;% rtDW.dke2w5vglk.AQHandles
                    section.data(20).logicalSrcIdx = 37;
                    section.data(20).dtTransOffset = 51;

                    ;% rtDW.jqho42deiu.LoggedData
                    section.data(21).logicalSrcIdx = 38;
                    section.data(21).dtTransOffset = 52;

                    ;% rtDW.ivu5m05flg.AQHandles
                    section.data(22).logicalSrcIdx = 39;
                    section.data(22).dtTransOffset = 53;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bzmxqssdoq
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% rtDW.kb5rvgdujd.PrevIndex
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.kcxfvmkrf2.Tail
                    section.data(2).logicalSrcIdx = 42;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.n2bt3cyc55.Tail
                    section.data(3).logicalSrcIdx = 43;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.lcuflefjuj.Tail
                    section.data(4).logicalSrcIdx = 44;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ovi0zqdzif.Tail
                    section.data(5).logicalSrcIdx = 45;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.advdik1iky.Tail
                    section.data(6).logicalSrcIdx = 46;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.kb3fhgjdld.Tail
                    section.data(7).logicalSrcIdx = 47;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.ho5e0de00z.Tail
                    section.data(8).logicalSrcIdx = 48;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.dlpoyqagu4.Tail
                    section.data(9).logicalSrcIdx = 49;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.k1nwxppvuo.Tail
                    section.data(10).logicalSrcIdx = 50;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.azfuopxupm.Tail
                    section.data(11).logicalSrcIdx = 51;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.bnqksyhx4b.Tail
                    section.data(12).logicalSrcIdx = 52;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.jsj5ows1gx.Tail
                    section.data(13).logicalSrcIdx = 53;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.ajzqjdehhp
                    section.data(1).logicalSrcIdx = 54;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.kjy05jsjy1
                    section.data(2).logicalSrcIdx = 55;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.mt4cgs1ctq
                    section.data(3).logicalSrcIdx = 56;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jggqbqxmox
                    section.data(4).logicalSrcIdx = 57;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.bluxjvuquj
                    section.data(5).logicalSrcIdx = 58;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.pu1wrg42xz
                    section.data(6).logicalSrcIdx = 59;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.kia112cgkq
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.igyctbswok
                    section.data(2).logicalSrcIdx = 61;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.llqwbguanw
                    section.data(3).logicalSrcIdx = 62;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.i3eziu3f1n
                    section.data(4).logicalSrcIdx = 63;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.fbp5lgspzk
                    section.data(5).logicalSrcIdx = 64;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.nrn32puwjn
                    section.data(6).logicalSrcIdx = 65;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ckhj2mjol3
                    section.data(7).logicalSrcIdx = 66;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.haenchykp4
                    section.data(8).logicalSrcIdx = 67;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pokud50mlj.kw45gvclvl
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.l2pxsorbc0.mzbzupg3uq
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.l2pxsorbc0.miqumv2j33
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ntt0n0z3qa.igzqysubwr
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ntt0n0z3qa.jfiw2hmwe4
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.guziuj3nzou.mzbzupg3uq
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.guziuj3nzou.miqumv2j33
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.obgcvvf2c2c.igzqysubwr
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.obgcvvf2c2c.jfiw2hmwe4
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.f5g5ssvz0ob.kw45gvclvl
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
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


    targMap.checksum0 = 1850872603;
    targMap.checksum1 = 165999143;
    targMap.checksum2 = 1301383288;
    targMap.checksum3 = 1439320884;

