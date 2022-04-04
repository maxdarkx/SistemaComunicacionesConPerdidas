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
            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

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

                    ;% rtP.Pot_Ruido
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.R1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.R2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Rb
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Retraso_Canal
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Tb
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.b
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.kv2
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Monostable1_EdgeDetect
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.Monostable3_EdgeDetect
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.SampleandHold_ic
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.Monostable1_ic
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.SampleHold_ic
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.Monostable3_ic
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.SampleHold_ic_cvpetr2ktj
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.Monostable_ic
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 77;
            section.data(77)  = dumData; %prealloc

                    ;% rtP.Out1_Y0
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP._Y0
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.FromWorkspace_Data0
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.AnalogFilterDesign_A_pr
                    section.data(4).logicalSrcIdx = 25;
                    section.data(4).dtTransOffset = 1113;

                    ;% rtP.AnalogFilterDesign_B_pr
                    section.data(5).logicalSrcIdx = 26;
                    section.data(5).dtTransOffset = 1120;

                    ;% rtP.AnalogFilterDesign_C_pr
                    section.data(6).logicalSrcIdx = 27;
                    section.data(6).dtTransOffset = 1121;

                    ;% rtP.AnalogFilterDesign_InitialCondition
                    section.data(7).logicalSrcIdx = 28;
                    section.data(7).dtTransOffset = 1122;

                    ;% rtP.TransportDelay_InitOutput
                    section.data(8).logicalSrcIdx = 29;
                    section.data(8).dtTransOffset = 1123;

                    ;% rtP.RuidoAGWN_Mean
                    section.data(9).logicalSrcIdx = 30;
                    section.data(9).dtTransOffset = 1124;

                    ;% rtP.RuidoAGWN_Seed
                    section.data(10).logicalSrcIdx = 31;
                    section.data(10).dtTransOffset = 1125;

                    ;% rtP.AnalogFilterDesign_A_pr_jsdcqwampi
                    section.data(11).logicalSrcIdx = 32;
                    section.data(11).dtTransOffset = 1126;

                    ;% rtP.AnalogFilterDesign_B_pr_om0jg41jmb
                    section.data(12).logicalSrcIdx = 33;
                    section.data(12).dtTransOffset = 1133;

                    ;% rtP.AnalogFilterDesign_C_pr_d0qgd0zcfa
                    section.data(13).logicalSrcIdx = 34;
                    section.data(13).dtTransOffset = 1134;

                    ;% rtP.AnalogFilterDesign_InitialCondition_bizf0yluzm
                    section.data(14).logicalSrcIdx = 35;
                    section.data(14).dtTransOffset = 1135;

                    ;% rtP.TransportDelay_Delay
                    section.data(15).logicalSrcIdx = 36;
                    section.data(15).dtTransOffset = 1136;

                    ;% rtP.TransportDelay_InitOutput_m3b1lj5lye
                    section.data(16).logicalSrcIdx = 37;
                    section.data(16).dtTransOffset = 1137;

                    ;% rtP.Integrator_IC
                    section.data(17).logicalSrcIdx = 38;
                    section.data(17).dtTransOffset = 1138;

                    ;% rtP.ModuloIntegrator_IC
                    section.data(18).logicalSrcIdx = 39;
                    section.data(18).dtTransOffset = 1139;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue
                    section.data(19).logicalSrcIdx = 40;
                    section.data(19).dtTransOffset = 1140;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue
                    section.data(20).logicalSrcIdx = 41;
                    section.data(20).dtTransOffset = 1141;

                    ;% rtP.AddConstant_Bias
                    section.data(21).logicalSrcIdx = 42;
                    section.data(21).dtTransOffset = 1142;

                    ;% rtP.Multiply_Gain
                    section.data(22).logicalSrcIdx = 43;
                    section.data(22).dtTransOffset = 1143;

                    ;% rtP.TransportDelay12_InitOutput
                    section.data(23).logicalSrcIdx = 44;
                    section.data(23).dtTransOffset = 1144;

                    ;% rtP.AnalogFilterDesign_A_pr_f4zixacbw1
                    section.data(24).logicalSrcIdx = 45;
                    section.data(24).dtTransOffset = 1145;

                    ;% rtP.AnalogFilterDesign_B_pr_by1sufu2fg
                    section.data(25).logicalSrcIdx = 46;
                    section.data(25).dtTransOffset = 1160;

                    ;% rtP.AnalogFilterDesign_C_pr_e3t31otpuq
                    section.data(26).logicalSrcIdx = 47;
                    section.data(26).dtTransOffset = 1161;

                    ;% rtP.AnalogFilterDesign_InitialCondition_gxj5snzs0v
                    section.data(27).logicalSrcIdx = 48;
                    section.data(27).dtTransOffset = 1162;

                    ;% rtP.TransportDelay2_InitOutput
                    section.data(28).logicalSrcIdx = 49;
                    section.data(28).dtTransOffset = 1163;

                    ;% rtP.TransportDelay1_InitOutput
                    section.data(29).logicalSrcIdx = 50;
                    section.data(29).dtTransOffset = 1164;

                    ;% rtP.TransportDelay4_InitOutput
                    section.data(30).logicalSrcIdx = 51;
                    section.data(30).dtTransOffset = 1165;

                    ;% rtP.TransportDelay3_InitOutput
                    section.data(31).logicalSrcIdx = 52;
                    section.data(31).dtTransOffset = 1166;

                    ;% rtP.TransportDelay6_InitOutput
                    section.data(32).logicalSrcIdx = 53;
                    section.data(32).dtTransOffset = 1167;

                    ;% rtP.TransportDelay5_InitOutput
                    section.data(33).logicalSrcIdx = 54;
                    section.data(33).dtTransOffset = 1168;

                    ;% rtP.TransportDelay8_InitOutput
                    section.data(34).logicalSrcIdx = 55;
                    section.data(34).dtTransOffset = 1169;

                    ;% rtP.TransportDelay7_InitOutput
                    section.data(35).logicalSrcIdx = 56;
                    section.data(35).dtTransOffset = 1170;

                    ;% rtP.TransportDelay9_InitOutput
                    section.data(36).logicalSrcIdx = 57;
                    section.data(36).dtTransOffset = 1171;

                    ;% rtP.TransportDelay11_InitOutput
                    section.data(37).logicalSrcIdx = 58;
                    section.data(37).dtTransOffset = 1172;

                    ;% rtP.Switch_Threshold
                    section.data(38).logicalSrcIdx = 59;
                    section.data(38).dtTransOffset = 1173;

                    ;% rtP.ModuloIntegrator_IC_g1vo2kap3u
                    section.data(39).logicalSrcIdx = 60;
                    section.data(39).dtTransOffset = 1174;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5
                    section.data(40).logicalSrcIdx = 61;
                    section.data(40).dtTransOffset = 1175;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk
                    section.data(41).logicalSrcIdx = 62;
                    section.data(41).dtTransOffset = 1176;

                    ;% rtP.Integrator_IC_oxpanuusbm
                    section.data(42).logicalSrcIdx = 63;
                    section.data(42).dtTransOffset = 1177;

                    ;% rtP.Integrator1_IC
                    section.data(43).logicalSrcIdx = 64;
                    section.data(43).dtTransOffset = 1178;

                    ;% rtP.Integrator_IC_a5b0eygpkp
                    section.data(44).logicalSrcIdx = 65;
                    section.data(44).dtTransOffset = 1179;

                    ;% rtP.Multiply_Gain_ptvyavefxe
                    section.data(45).logicalSrcIdx = 66;
                    section.data(45).dtTransOffset = 1180;

                    ;% rtP.AddConstant_Bias_ljcfbacsm3
                    section.data(46).logicalSrcIdx = 67;
                    section.data(46).dtTransOffset = 1181;

                    ;% rtP.SineWave_Bias
                    section.data(47).logicalSrcIdx = 68;
                    section.data(47).dtTransOffset = 1182;

                    ;% rtP.SineWave_Phase
                    section.data(48).logicalSrcIdx = 69;
                    section.data(48).dtTransOffset = 1183;

                    ;% rtP.Constant1_Value
                    section.data(49).logicalSrcIdx = 70;
                    section.data(49).dtTransOffset = 1184;

                    ;% rtP.Constant10_Value
                    section.data(50).logicalSrcIdx = 71;
                    section.data(50).dtTransOffset = 1185;

                    ;% rtP.Constant13_Value
                    section.data(51).logicalSrcIdx = 72;
                    section.data(51).dtTransOffset = 1186;

                    ;% rtP.Constant14_Value
                    section.data(52).logicalSrcIdx = 73;
                    section.data(52).dtTransOffset = 1187;

                    ;% rtP.Constant15_Value
                    section.data(53).logicalSrcIdx = 74;
                    section.data(53).dtTransOffset = 1188;

                    ;% rtP.Constant16_Value
                    section.data(54).logicalSrcIdx = 75;
                    section.data(54).dtTransOffset = 1189;

                    ;% rtP.Constant2_Value
                    section.data(55).logicalSrcIdx = 76;
                    section.data(55).dtTransOffset = 1190;

                    ;% rtP.Constant3_Value
                    section.data(56).logicalSrcIdx = 77;
                    section.data(56).dtTransOffset = 1191;

                    ;% rtP.Constant4_Value
                    section.data(57).logicalSrcIdx = 78;
                    section.data(57).dtTransOffset = 1192;

                    ;% rtP.Constant5_Value
                    section.data(58).logicalSrcIdx = 79;
                    section.data(58).dtTransOffset = 1193;

                    ;% rtP.Constant6_Value
                    section.data(59).logicalSrcIdx = 80;
                    section.data(59).dtTransOffset = 1194;

                    ;% rtP.Constant7_Value
                    section.data(60).logicalSrcIdx = 81;
                    section.data(60).dtTransOffset = 1195;

                    ;% rtP.Constant8_Value
                    section.data(61).logicalSrcIdx = 82;
                    section.data(61).dtTransOffset = 1196;

                    ;% rtP.Constant9_Value
                    section.data(62).logicalSrcIdx = 83;
                    section.data(62).dtTransOffset = 1197;

                    ;% rtP.Constant_Value
                    section.data(63).logicalSrcIdx = 84;
                    section.data(63).dtTransOffset = 1198;

                    ;% rtP.Constant1_Value_afssjxve00
                    section.data(64).logicalSrcIdx = 85;
                    section.data(64).dtTransOffset = 1199;

                    ;% rtP.posedge_Value
                    section.data(65).logicalSrcIdx = 86;
                    section.data(65).dtTransOffset = 1200;

                    ;% rtP.negedge_Value
                    section.data(66).logicalSrcIdx = 87;
                    section.data(66).dtTransOffset = 1202;

                    ;% rtP.eitheredge_Value
                    section.data(67).logicalSrcIdx = 88;
                    section.data(67).dtTransOffset = 1204;

                    ;% rtP.Constant2_Value_mwviqzbxqh
                    section.data(68).logicalSrcIdx = 89;
                    section.data(68).dtTransOffset = 1206;

                    ;% rtP.Constant5_Value_hu2bresth1
                    section.data(69).logicalSrcIdx = 90;
                    section.data(69).dtTransOffset = 1207;

                    ;% rtP.Constant6_Value_dkmziwbikw
                    section.data(70).logicalSrcIdx = 91;
                    section.data(70).dtTransOffset = 1208;

                    ;% rtP.Constant1_Value_hcjo4f4r5j
                    section.data(71).logicalSrcIdx = 92;
                    section.data(71).dtTransOffset = 1209;

                    ;% rtP.posedge_Value_av2r5ustik
                    section.data(72).logicalSrcIdx = 93;
                    section.data(72).dtTransOffset = 1210;

                    ;% rtP.negedge_Value_fef1hh2jz4
                    section.data(73).logicalSrcIdx = 94;
                    section.data(73).dtTransOffset = 1212;

                    ;% rtP.eitheredge_Value_nntils3rkv
                    section.data(74).logicalSrcIdx = 95;
                    section.data(74).dtTransOffset = 1214;

                    ;% rtP.posedge_Value_j0croo5cnv
                    section.data(75).logicalSrcIdx = 96;
                    section.data(75).dtTransOffset = 1216;

                    ;% rtP.negedge_Value_lnmee3h1ob
                    section.data(76).logicalSrcIdx = 97;
                    section.data(76).dtTransOffset = 1218;

                    ;% rtP.eitheredge_Value_gsipsgs54b
                    section.data(77).logicalSrcIdx = 98;
                    section.data(77).dtTransOffset = 1220;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 99;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 100;
                    section.data(2).dtTransOffset = 7;

                    ;% rtP.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 101;
                    section.data(3).dtTransOffset = 12;

                    ;% rtP.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 102;
                    section.data(4).dtTransOffset = 13;

                    ;% rtP.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 103;
                    section.data(5).dtTransOffset = 15;

                    ;% rtP.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 104;
                    section.data(6).dtTransOffset = 16;

                    ;% rtP.AnalogFilterDesign_A_ir_gqpywhsxtr
                    section.data(7).logicalSrcIdx = 105;
                    section.data(7).dtTransOffset = 21;

                    ;% rtP.AnalogFilterDesign_A_jc_fyftqxybap
                    section.data(8).logicalSrcIdx = 106;
                    section.data(8).dtTransOffset = 28;

                    ;% rtP.AnalogFilterDesign_B_ir_gklrfvy2xp
                    section.data(9).logicalSrcIdx = 107;
                    section.data(9).dtTransOffset = 33;

                    ;% rtP.AnalogFilterDesign_B_jc_nk0ranamkl
                    section.data(10).logicalSrcIdx = 108;
                    section.data(10).dtTransOffset = 34;

                    ;% rtP.AnalogFilterDesign_C_ir_jr05e5amzn
                    section.data(11).logicalSrcIdx = 109;
                    section.data(11).dtTransOffset = 36;

                    ;% rtP.AnalogFilterDesign_C_jc_jc5wcv0wk2
                    section.data(12).logicalSrcIdx = 110;
                    section.data(12).dtTransOffset = 37;

                    ;% rtP.AnalogFilterDesign_A_ir_cx1zj2mhzp
                    section.data(13).logicalSrcIdx = 111;
                    section.data(13).dtTransOffset = 42;

                    ;% rtP.AnalogFilterDesign_A_jc_h5xar20tzm
                    section.data(14).logicalSrcIdx = 112;
                    section.data(14).dtTransOffset = 57;

                    ;% rtP.AnalogFilterDesign_B_ir_nneewrak4c
                    section.data(15).logicalSrcIdx = 113;
                    section.data(15).dtTransOffset = 66;

                    ;% rtP.AnalogFilterDesign_B_jc_acwf2d2gj0
                    section.data(16).logicalSrcIdx = 114;
                    section.data(16).dtTransOffset = 67;

                    ;% rtP.AnalogFilterDesign_C_ir_cqrtf32rbd
                    section.data(17).logicalSrcIdx = 115;
                    section.data(17).dtTransOffset = 69;

                    ;% rtP.AnalogFilterDesign_C_jc_d2bgogmalx
                    section.data(18).logicalSrcIdx = 116;
                    section.data(18).dtTransOffset = 70;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.OUT_Y0
                    section.data(1).logicalSrcIdx = 117;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.OUT_Y0_gbikirmbla
                    section.data(2).logicalSrcIdx = 118;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Q_Y0
                    section.data(3).logicalSrcIdx = 119;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Q_Y0_ngs1cr5pq5
                    section.data(4).logicalSrcIdx = 120;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Memory_InitialCondition
                    section.data(5).logicalSrcIdx = 121;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.TmpLatchAtDFlipFlopInport1_InitialCondition
                    section.data(6).logicalSrcIdx = 122;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Memory_InitialCondition_oggd2r4odw
                    section.data(7).logicalSrcIdx = 123;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Memory_InitialCondition_ljulw4woig
                    section.data(8).logicalSrcIdx = 124;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.cmjzvpvpsf._Y0
                    section.data(1).logicalSrcIdx = 125;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.jdw3pbikft.OUT_Y0
                    section.data(1).logicalSrcIdx = 126;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.hdzoplw4kn.OUT_Y0
                    section.data(1).logicalSrcIdx = 127;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.msxjrffonnn.OUT_Y0
                    section.data(1).logicalSrcIdx = 128;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ggca33mvdun.OUT_Y0
                    section.data(1).logicalSrcIdx = 129;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.nrqkqpzimhq._Y0
                    section.data(1).logicalSrcIdx = 130;
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
            section.nData     = 60;
            section.data(60)  = dumData; %prealloc

                    ;% rtB.ee42tgof2b
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.o5tdwwqd3u
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.p5kktr1wyk
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.mvhgymrwqe
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.gqtvp2z5yf
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.d4ytgmijes
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.ijwiii2est
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.krai04vzyy
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.exkkdo4tfp
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.fpr0eiute3
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.kqemtml2w3
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.da4cqxiizn
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.atcqfparc4
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.c2cnah1c34
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.ooymnwvq5a
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.ijuklwld0a
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.nryqbxo330
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.hihmi4odjo
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.hcmaylj25a
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.cyqeay1yht
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.gmgguax0lb
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.e0stmf0wje
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.ggvs3qvpfu
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.mdt0d44sb1
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.kxicx45q5w
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.i0rkndmb13
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.owsmsehx52
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.nsdd2hdqf1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.a34p2x24w2
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.jyhhxwku5j
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.jers21a5nu
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.fpmqgmj2cy
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.gnebrkauvk
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtB.jkw11eafiz
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtB.acvegdxqsb
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtB.c1quq2kkeo
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtB.bqly4iysyb
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtB.apaian0okb
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtB.c1co2zjsgy
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtB.ktfxpbuyoi
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtB.max2gpqnqf
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtB.ewn2wlainw
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtB.jxbxouhvpz
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

                    ;% rtB.m0n2ncikto
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 43;

                    ;% rtB.blc3ahlqoa
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 44;

                    ;% rtB.n2wkjomta0
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 45;

                    ;% rtB.f14htfpour
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 46;

                    ;% rtB.k3ehqfnhji
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 47;

                    ;% rtB.dxkeuerubi
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 48;

                    ;% rtB.e2pyl4rib3
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 49;

                    ;% rtB.nnbbyhuwe5
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 50;

                    ;% rtB.pjddsfuka3
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 51;

                    ;% rtB.gpdt1s5m43
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 52;

                    ;% rtB.df1ir0te5a
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 53;

                    ;% rtB.nag5slvt33
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 54;

                    ;% rtB.fxorr2mhne
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 55;

                    ;% rtB.nhjc2m3cbx
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 57;

                    ;% rtB.ap3kp501sl
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 59;

                    ;% rtB.nylejvpk25
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 61;

                    ;% rtB.g5n3z2eyy3
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 62;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtB.djf3ji5ytw
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.bkyaf0nkhx
                    section.data(2).logicalSrcIdx = 61;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.pzi0oq2mxf
                    section.data(3).logicalSrcIdx = 62;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.owu2nywhc4
                    section.data(4).logicalSrcIdx = 63;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.lgqv4rlpjm
                    section.data(5).logicalSrcIdx = 64;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.pehstkjnkd
                    section.data(6).logicalSrcIdx = 65;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.hehncpsx5o
                    section.data(7).logicalSrcIdx = 66;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.bhwit4pfgp
                    section.data(8).logicalSrcIdx = 67;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.lb3j4jh0k1
                    section.data(9).logicalSrcIdx = 68;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.po2rfexerf
                    section.data(10).logicalSrcIdx = 69;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.p0reyhkgec
                    section.data(11).logicalSrcIdx = 70;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.cmjzvpvpsf.olytfz4wp1
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jdw3pbikft.k0x4is02ar
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.hdzoplw4kn.e5aa54psh5
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.msxjrffonnn.k0x4is02ar
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ggca33mvdun.e5aa54psh5
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.nrqkqpzimhq.olytfz4wp1
                    section.data(1).logicalSrcIdx = 76;
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
        nTotSects     = 12;
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
            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% rtDW.bssa0c1myd
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.phadp4f3b4
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.mse1diqmww
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.bhmfx0qy3i
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.cmv1b20lsy
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.lvp0eixlb4
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.kv1pa1ywzi.modelTStart
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.ij5krlemte.modelTStart
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.h0tlb2kuwe.modelTStart
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.mj5evfwhzb.modelTStart
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.ngqgrvp4ei.modelTStart
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.ajgpkfca1o.modelTStart
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.ma103w0rl5.modelTStart
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.ocb1qur2h1.modelTStart
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.d0nohml22r.modelTStart
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.mzuvrrfieu.modelTStart
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.d4whpythev.modelTStart
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.d4oxqhfhid.modelTStart
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.jrveltrtha.modelTStart
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% rtDW.f5j5cwamx4.TimePtr
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ozcsecc153.TUbufferPtrs
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.psh3vd4qdr.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 3;

                    ;% rtDW.lhdff4g1zf.TUbufferPtrs
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 5;

                    ;% rtDW.hg5xr2o52a.LoggedData
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 7;

                    ;% rtDW.lcytbmuuny.LoggedData
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 14;

                    ;% rtDW.kt2rdibexx.TUbufferPtrs
                    section.data(7).logicalSrcIdx = 25;
                    section.data(7).dtTransOffset = 18;

                    ;% rtDW.h1me53arog.TUbufferPtrs
                    section.data(8).logicalSrcIdx = 26;
                    section.data(8).dtTransOffset = 20;

                    ;% rtDW.pu2m2nsrgd.TUbufferPtrs
                    section.data(9).logicalSrcIdx = 27;
                    section.data(9).dtTransOffset = 22;

                    ;% rtDW.lfbf1a2jus.TUbufferPtrs
                    section.data(10).logicalSrcIdx = 28;
                    section.data(10).dtTransOffset = 24;

                    ;% rtDW.othjjrceoi.TUbufferPtrs
                    section.data(11).logicalSrcIdx = 29;
                    section.data(11).dtTransOffset = 26;

                    ;% rtDW.m4vidzf1kq.TUbufferPtrs
                    section.data(12).logicalSrcIdx = 30;
                    section.data(12).dtTransOffset = 28;

                    ;% rtDW.ogkqvonou1.TUbufferPtrs
                    section.data(13).logicalSrcIdx = 31;
                    section.data(13).dtTransOffset = 30;

                    ;% rtDW.iyhbqhzckm.TUbufferPtrs
                    section.data(14).logicalSrcIdx = 32;
                    section.data(14).dtTransOffset = 32;

                    ;% rtDW.fdlikytedu.TUbufferPtrs
                    section.data(15).logicalSrcIdx = 33;
                    section.data(15).dtTransOffset = 34;

                    ;% rtDW.g0jka410r5.TUbufferPtrs
                    section.data(16).logicalSrcIdx = 34;
                    section.data(16).dtTransOffset = 36;

                    ;% rtDW.dkeugicdjj.LoggedData
                    section.data(17).logicalSrcIdx = 35;
                    section.data(17).dtTransOffset = 38;

                    ;% rtDW.j3kmw0bx15.LoggedData
                    section.data(18).logicalSrcIdx = 36;
                    section.data(18).dtTransOffset = 42;

                    ;% rtDW.dmnu1nlz2m.AQHandles
                    section.data(19).logicalSrcIdx = 37;
                    section.data(19).dtTransOffset = 46;

                    ;% rtDW.glgftsaydo.LoggedData
                    section.data(20).logicalSrcIdx = 38;
                    section.data(20).dtTransOffset = 47;

                    ;% rtDW.ewzvvg2wnk.LoggedData
                    section.data(21).logicalSrcIdx = 39;
                    section.data(21).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.afqavbs5ty
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtDW.eidamkhewj.PrevIndex
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dazeyaom3l.Tail
                    section.data(2).logicalSrcIdx = 42;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.hpsposfxjp.Tail
                    section.data(3).logicalSrcIdx = 43;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.achc50k0kr.Tail
                    section.data(4).logicalSrcIdx = 44;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.h2kosmawcp.Tail
                    section.data(5).logicalSrcIdx = 45;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.jklfnyaqcu.Tail
                    section.data(6).logicalSrcIdx = 46;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.bl1p0blo4b.Tail
                    section.data(7).logicalSrcIdx = 47;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.ahczbduber.Tail
                    section.data(8).logicalSrcIdx = 48;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.mehfzxnojj.Tail
                    section.data(9).logicalSrcIdx = 49;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.bxfujbkphp.Tail
                    section.data(10).logicalSrcIdx = 50;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.jcgpwdcw13.Tail
                    section.data(11).logicalSrcIdx = 51;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.adt2xe2pd0.Tail
                    section.data(12).logicalSrcIdx = 52;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.mijwxy1gfd.Tail
                    section.data(13).logicalSrcIdx = 53;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.ewfcczil0j.Tail
                    section.data(14).logicalSrcIdx = 54;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.es3p4dnuna
                    section.data(15).logicalSrcIdx = 55;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.hr4s0kwfwa
                    section.data(16).logicalSrcIdx = 56;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.lfe1ibkwop
                    section.data(17).logicalSrcIdx = 57;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.m2jub0kxpz
                    section.data(18).logicalSrcIdx = 58;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.izid4kf2wl
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.f5bd1tnerd
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.aece3kamvy
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.fbu1o32502
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.j3dn4gfhs1
                    section.data(5).logicalSrcIdx = 63;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.hfhvsoe1hu
                    section.data(6).logicalSrcIdx = 64;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtDW.ezpzvynldc
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.jddr3btzwa
                    section.data(2).logicalSrcIdx = 66;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.m0i1af3trd
                    section.data(3).logicalSrcIdx = 67;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.nssittgb5o
                    section.data(4).logicalSrcIdx = 68;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.iwr1b2avuw
                    section.data(5).logicalSrcIdx = 69;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kwrhw5www5
                    section.data(6).logicalSrcIdx = 70;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.hz35lsskp2
                    section.data(7).logicalSrcIdx = 71;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.jf03aj3gmd
                    section.data(8).logicalSrcIdx = 72;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.bf33xtbrhg
                    section.data(9).logicalSrcIdx = 73;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.itvjzmhcag
                    section.data(10).logicalSrcIdx = 74;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.ehwgl0hfyk
                    section.data(11).logicalSrcIdx = 75;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.cmjzvpvpsf.j13iuzvksk
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jdw3pbikft.o3j2yaswp3
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hdzoplw4kn.o0iconal0v
                    section.data(1).logicalSrcIdx = 78;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.msxjrffonnn.o3j2yaswp3
                    section.data(1).logicalSrcIdx = 79;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ggca33mvdun.o0iconal0v
                    section.data(1).logicalSrcIdx = 80;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nrqkqpzimhq.j13iuzvksk
                    section.data(1).logicalSrcIdx = 81;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
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


    targMap.checksum0 = 3134493899;
    targMap.checksum1 = 3043254526;
    targMap.checksum2 = 4272357070;
    targMap.checksum3 = 1867159465;

