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
            section.nData     = 23;
            section.data(23)  = dumData; %prealloc

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

                    ;% rtP.varRuido
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

                    ;% rtP.CheckStaticUpperBound_max
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.CheckStaticLowerBound_min
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.Monostable_ic
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 89;
            section.data(89)  = dumData; %prealloc

                    ;% rtP.Out1_Y0
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP._Y0
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.clock_out_Y0
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Constant2_Value
                    section.data(5).logicalSrcIdx = 28;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Constant_Value
                    section.data(6).logicalSrcIdx = 29;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.FromWorkspace_Data0
                    section.data(7).logicalSrcIdx = 31;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Unbuffer_ic
                    section.data(8).logicalSrcIdx = 32;
                    section.data(8).dtTransOffset = 30;

                    ;% rtP.AnalogFilterDesign_A_pr
                    section.data(9).logicalSrcIdx = 33;
                    section.data(9).dtTransOffset = 31;

                    ;% rtP.AnalogFilterDesign_B_pr
                    section.data(10).logicalSrcIdx = 34;
                    section.data(10).dtTransOffset = 38;

                    ;% rtP.AnalogFilterDesign_C_pr
                    section.data(11).logicalSrcIdx = 35;
                    section.data(11).dtTransOffset = 39;

                    ;% rtP.AnalogFilterDesign_InitialCondition
                    section.data(12).logicalSrcIdx = 36;
                    section.data(12).dtTransOffset = 40;

                    ;% rtP.TransportDelay_InitOutput
                    section.data(13).logicalSrcIdx = 37;
                    section.data(13).dtTransOffset = 41;

                    ;% rtP.RuidoAGWN_Mean
                    section.data(14).logicalSrcIdx = 38;
                    section.data(14).dtTransOffset = 42;

                    ;% rtP.RuidoAGWN_Seed
                    section.data(15).logicalSrcIdx = 39;
                    section.data(15).dtTransOffset = 43;

                    ;% rtP.AnalogFilterDesign_A_pr_jsdcqwampi
                    section.data(16).logicalSrcIdx = 40;
                    section.data(16).dtTransOffset = 44;

                    ;% rtP.AnalogFilterDesign_B_pr_om0jg41jmb
                    section.data(17).logicalSrcIdx = 41;
                    section.data(17).dtTransOffset = 51;

                    ;% rtP.AnalogFilterDesign_C_pr_d0qgd0zcfa
                    section.data(18).logicalSrcIdx = 42;
                    section.data(18).dtTransOffset = 52;

                    ;% rtP.AnalogFilterDesign_InitialCondition_bizf0yluzm
                    section.data(19).logicalSrcIdx = 43;
                    section.data(19).dtTransOffset = 53;

                    ;% rtP.TransportDelay_Delay
                    section.data(20).logicalSrcIdx = 44;
                    section.data(20).dtTransOffset = 54;

                    ;% rtP.TransportDelay_InitOutput_m3b1lj5lye
                    section.data(21).logicalSrcIdx = 45;
                    section.data(21).dtTransOffset = 55;

                    ;% rtP.Integrator_IC
                    section.data(22).logicalSrcIdx = 46;
                    section.data(22).dtTransOffset = 56;

                    ;% rtP.AddConstant_Bias
                    section.data(23).logicalSrcIdx = 47;
                    section.data(23).dtTransOffset = 57;

                    ;% rtP.Multiply_Gain
                    section.data(24).logicalSrcIdx = 48;
                    section.data(24).dtTransOffset = 58;

                    ;% rtP.LogicDecision1_PropDelay
                    section.data(25).logicalSrcIdx = 49;
                    section.data(25).dtTransOffset = 59;

                    ;% rtP.Switch_Threshold
                    section.data(26).logicalSrcIdx = 50;
                    section.data(26).dtTransOffset = 60;

                    ;% rtP.TransportDelay2_InitOutput
                    section.data(27).logicalSrcIdx = 51;
                    section.data(27).dtTransOffset = 61;

                    ;% rtP.TransportDelay1_InitOutput
                    section.data(28).logicalSrcIdx = 52;
                    section.data(28).dtTransOffset = 62;

                    ;% rtP.TransportDelay4_InitOutput
                    section.data(29).logicalSrcIdx = 53;
                    section.data(29).dtTransOffset = 63;

                    ;% rtP.TransportDelay3_InitOutput
                    section.data(30).logicalSrcIdx = 54;
                    section.data(30).dtTransOffset = 64;

                    ;% rtP.TransportDelay6_InitOutput
                    section.data(31).logicalSrcIdx = 55;
                    section.data(31).dtTransOffset = 65;

                    ;% rtP.TransportDelay5_InitOutput
                    section.data(32).logicalSrcIdx = 56;
                    section.data(32).dtTransOffset = 66;

                    ;% rtP.TransportDelay8_InitOutput
                    section.data(33).logicalSrcIdx = 57;
                    section.data(33).dtTransOffset = 67;

                    ;% rtP.TransportDelay7_InitOutput
                    section.data(34).logicalSrcIdx = 58;
                    section.data(34).dtTransOffset = 68;

                    ;% rtP.TransportDelay9_InitOutput
                    section.data(35).logicalSrcIdx = 59;
                    section.data(35).dtTransOffset = 69;

                    ;% rtP.TransportDelay11_InitOutput
                    section.data(36).logicalSrcIdx = 60;
                    section.data(36).dtTransOffset = 70;

                    ;% rtP.Switch_Threshold_bmfda2wh42
                    section.data(37).logicalSrcIdx = 61;
                    section.data(37).dtTransOffset = 71;

                    ;% rtP.AnalogFilterDesign_A_pr_gc0kz31g5a
                    section.data(38).logicalSrcIdx = 62;
                    section.data(38).dtTransOffset = 72;

                    ;% rtP.AnalogFilterDesign_B_pr_kq1k3m2fjm
                    section.data(39).logicalSrcIdx = 63;
                    section.data(39).dtTransOffset = 79;

                    ;% rtP.AnalogFilterDesign_C_pr_aqq5iiwnf2
                    section.data(40).logicalSrcIdx = 64;
                    section.data(40).dtTransOffset = 80;

                    ;% rtP.AnalogFilterDesign_InitialCondition_l2mskoueic
                    section.data(41).logicalSrcIdx = 65;
                    section.data(41).dtTransOffset = 81;

                    ;% rtP.ModuloIntegrator_IC
                    section.data(42).logicalSrcIdx = 66;
                    section.data(42).dtTransOffset = 82;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue
                    section.data(43).logicalSrcIdx = 67;
                    section.data(43).dtTransOffset = 83;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue
                    section.data(44).logicalSrcIdx = 68;
                    section.data(44).dtTransOffset = 84;

                    ;% rtP.AnalogFilterDesign_A_pr_f4zixacbw1
                    section.data(45).logicalSrcIdx = 69;
                    section.data(45).dtTransOffset = 85;

                    ;% rtP.AnalogFilterDesign_B_pr_by1sufu2fg
                    section.data(46).logicalSrcIdx = 70;
                    section.data(46).dtTransOffset = 100;

                    ;% rtP.AnalogFilterDesign_C_pr_e3t31otpuq
                    section.data(47).logicalSrcIdx = 71;
                    section.data(47).dtTransOffset = 101;

                    ;% rtP.AnalogFilterDesign_InitialCondition_gxj5snzs0v
                    section.data(48).logicalSrcIdx = 72;
                    section.data(48).dtTransOffset = 102;

                    ;% rtP.ModuloIntegrator_IC_g1vo2kap3u
                    section.data(49).logicalSrcIdx = 73;
                    section.data(49).dtTransOffset = 103;

                    ;% rtP.ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5
                    section.data(50).logicalSrcIdx = 74;
                    section.data(50).dtTransOffset = 104;

                    ;% rtP.ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk
                    section.data(51).logicalSrcIdx = 75;
                    section.data(51).dtTransOffset = 105;

                    ;% rtP.Integrator_IC_oxpanuusbm
                    section.data(52).logicalSrcIdx = 76;
                    section.data(52).dtTransOffset = 106;

                    ;% rtP.Integrator1_IC
                    section.data(53).logicalSrcIdx = 77;
                    section.data(53).dtTransOffset = 107;

                    ;% rtP.Integrator_IC_a5b0eygpkp
                    section.data(54).logicalSrcIdx = 78;
                    section.data(54).dtTransOffset = 108;

                    ;% rtP.Multiply_Gain_ptvyavefxe
                    section.data(55).logicalSrcIdx = 79;
                    section.data(55).dtTransOffset = 109;

                    ;% rtP.AddConstant_Bias_ljcfbacsm3
                    section.data(56).logicalSrcIdx = 80;
                    section.data(56).dtTransOffset = 110;

                    ;% rtP.SineWave_Bias
                    section.data(57).logicalSrcIdx = 81;
                    section.data(57).dtTransOffset = 111;

                    ;% rtP.SineWave_Phase
                    section.data(58).logicalSrcIdx = 82;
                    section.data(58).dtTransOffset = 112;

                    ;% rtP.matrizGeneradora_Value
                    section.data(59).logicalSrcIdx = 83;
                    section.data(59).dtTransOffset = 113;

                    ;% rtP.Constant_Value_bfe1ms15wt
                    section.data(60).logicalSrcIdx = 84;
                    section.data(60).dtTransOffset = 120;

                    ;% rtP.Constant1_Value
                    section.data(61).logicalSrcIdx = 85;
                    section.data(61).dtTransOffset = 121;

                    ;% rtP.Constant10_Value
                    section.data(62).logicalSrcIdx = 86;
                    section.data(62).dtTransOffset = 122;

                    ;% rtP.Constant13_Value
                    section.data(63).logicalSrcIdx = 87;
                    section.data(63).dtTransOffset = 123;

                    ;% rtP.Constant14_Value
                    section.data(64).logicalSrcIdx = 88;
                    section.data(64).dtTransOffset = 124;

                    ;% rtP.Constant15_Value
                    section.data(65).logicalSrcIdx = 89;
                    section.data(65).dtTransOffset = 125;

                    ;% rtP.Constant16_Value
                    section.data(66).logicalSrcIdx = 90;
                    section.data(66).dtTransOffset = 126;

                    ;% rtP.Constant2_Value_ldvsshgj3v
                    section.data(67).logicalSrcIdx = 91;
                    section.data(67).dtTransOffset = 127;

                    ;% rtP.Constant3_Value
                    section.data(68).logicalSrcIdx = 92;
                    section.data(68).dtTransOffset = 128;

                    ;% rtP.Constant4_Value
                    section.data(69).logicalSrcIdx = 93;
                    section.data(69).dtTransOffset = 129;

                    ;% rtP.Constant5_Value
                    section.data(70).logicalSrcIdx = 94;
                    section.data(70).dtTransOffset = 130;

                    ;% rtP.Constant6_Value
                    section.data(71).logicalSrcIdx = 95;
                    section.data(71).dtTransOffset = 131;

                    ;% rtP.Constant7_Value
                    section.data(72).logicalSrcIdx = 96;
                    section.data(72).dtTransOffset = 132;

                    ;% rtP.Constant8_Value
                    section.data(73).logicalSrcIdx = 97;
                    section.data(73).dtTransOffset = 133;

                    ;% rtP.Constant9_Value
                    section.data(74).logicalSrcIdx = 98;
                    section.data(74).dtTransOffset = 134;

                    ;% rtP.Constant1_Value_afssjxve00
                    section.data(75).logicalSrcIdx = 99;
                    section.data(75).dtTransOffset = 135;

                    ;% rtP.posedge_Value
                    section.data(76).logicalSrcIdx = 100;
                    section.data(76).dtTransOffset = 136;

                    ;% rtP.negedge_Value
                    section.data(77).logicalSrcIdx = 101;
                    section.data(77).dtTransOffset = 138;

                    ;% rtP.eitheredge_Value
                    section.data(78).logicalSrcIdx = 102;
                    section.data(78).dtTransOffset = 140;

                    ;% rtP.Constant2_Value_mwviqzbxqh
                    section.data(79).logicalSrcIdx = 103;
                    section.data(79).dtTransOffset = 142;

                    ;% rtP.Constant5_Value_hu2bresth1
                    section.data(80).logicalSrcIdx = 104;
                    section.data(80).dtTransOffset = 143;

                    ;% rtP.Constant6_Value_dkmziwbikw
                    section.data(81).logicalSrcIdx = 105;
                    section.data(81).dtTransOffset = 144;

                    ;% rtP.Constant1_Value_hcjo4f4r5j
                    section.data(82).logicalSrcIdx = 106;
                    section.data(82).dtTransOffset = 145;

                    ;% rtP.posedge_Value_av2r5ustik
                    section.data(83).logicalSrcIdx = 107;
                    section.data(83).dtTransOffset = 146;

                    ;% rtP.negedge_Value_fef1hh2jz4
                    section.data(84).logicalSrcIdx = 108;
                    section.data(84).dtTransOffset = 148;

                    ;% rtP.eitheredge_Value_nntils3rkv
                    section.data(85).logicalSrcIdx = 109;
                    section.data(85).dtTransOffset = 150;

                    ;% rtP.posedge_Value_j0croo5cnv
                    section.data(86).logicalSrcIdx = 110;
                    section.data(86).dtTransOffset = 152;

                    ;% rtP.negedge_Value_lnmee3h1ob
                    section.data(87).logicalSrcIdx = 111;
                    section.data(87).dtTransOffset = 154;

                    ;% rtP.eitheredge_Value_gsipsgs54b
                    section.data(88).logicalSrcIdx = 112;
                    section.data(88).dtTransOffset = 156;

                    ;% rtP.Constant_Value_i2hydlpkci
                    section.data(89).logicalSrcIdx = 113;
                    section.data(89).dtTransOffset = 158;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 114;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 115;
                    section.data(2).dtTransOffset = 7;

                    ;% rtP.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 116;
                    section.data(3).dtTransOffset = 12;

                    ;% rtP.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 117;
                    section.data(4).dtTransOffset = 13;

                    ;% rtP.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 118;
                    section.data(5).dtTransOffset = 15;

                    ;% rtP.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 119;
                    section.data(6).dtTransOffset = 16;

                    ;% rtP.AnalogFilterDesign_A_ir_gqpywhsxtr
                    section.data(7).logicalSrcIdx = 120;
                    section.data(7).dtTransOffset = 21;

                    ;% rtP.AnalogFilterDesign_A_jc_fyftqxybap
                    section.data(8).logicalSrcIdx = 121;
                    section.data(8).dtTransOffset = 28;

                    ;% rtP.AnalogFilterDesign_B_ir_gklrfvy2xp
                    section.data(9).logicalSrcIdx = 122;
                    section.data(9).dtTransOffset = 33;

                    ;% rtP.AnalogFilterDesign_B_jc_nk0ranamkl
                    section.data(10).logicalSrcIdx = 123;
                    section.data(10).dtTransOffset = 34;

                    ;% rtP.AnalogFilterDesign_C_ir_jr05e5amzn
                    section.data(11).logicalSrcIdx = 124;
                    section.data(11).dtTransOffset = 36;

                    ;% rtP.AnalogFilterDesign_C_jc_jc5wcv0wk2
                    section.data(12).logicalSrcIdx = 125;
                    section.data(12).dtTransOffset = 37;

                    ;% rtP.AnalogFilterDesign_A_ir_o3wehlil1t
                    section.data(13).logicalSrcIdx = 126;
                    section.data(13).dtTransOffset = 42;

                    ;% rtP.AnalogFilterDesign_A_jc_hepc5hv3fw
                    section.data(14).logicalSrcIdx = 127;
                    section.data(14).dtTransOffset = 49;

                    ;% rtP.AnalogFilterDesign_B_ir_bqybfmsaae
                    section.data(15).logicalSrcIdx = 128;
                    section.data(15).dtTransOffset = 54;

                    ;% rtP.AnalogFilterDesign_B_jc_cfquo51aq1
                    section.data(16).logicalSrcIdx = 129;
                    section.data(16).dtTransOffset = 55;

                    ;% rtP.AnalogFilterDesign_C_ir_ivqqscx0vn
                    section.data(17).logicalSrcIdx = 130;
                    section.data(17).dtTransOffset = 57;

                    ;% rtP.AnalogFilterDesign_C_jc_llcs1qdtjn
                    section.data(18).logicalSrcIdx = 131;
                    section.data(18).dtTransOffset = 58;

                    ;% rtP.AnalogFilterDesign_A_ir_cx1zj2mhzp
                    section.data(19).logicalSrcIdx = 132;
                    section.data(19).dtTransOffset = 63;

                    ;% rtP.AnalogFilterDesign_A_jc_h5xar20tzm
                    section.data(20).logicalSrcIdx = 133;
                    section.data(20).dtTransOffset = 78;

                    ;% rtP.AnalogFilterDesign_B_ir_nneewrak4c
                    section.data(21).logicalSrcIdx = 134;
                    section.data(21).dtTransOffset = 87;

                    ;% rtP.AnalogFilterDesign_B_jc_acwf2d2gj0
                    section.data(22).logicalSrcIdx = 135;
                    section.data(22).dtTransOffset = 88;

                    ;% rtP.AnalogFilterDesign_C_ir_cqrtf32rbd
                    section.data(23).logicalSrcIdx = 136;
                    section.data(23).dtTransOffset = 90;

                    ;% rtP.AnalogFilterDesign_C_jc_d2bgogmalx
                    section.data(24).logicalSrcIdx = 137;
                    section.data(24).dtTransOffset = 91;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.OUT_Y0
                    section.data(1).logicalSrcIdx = 138;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.OUT_Y0_gbikirmbla
                    section.data(2).logicalSrcIdx = 139;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Q_Y0
                    section.data(3).logicalSrcIdx = 140;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Q_Y0_ngs1cr5pq5
                    section.data(4).logicalSrcIdx = 141;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Memory_InitialCondition
                    section.data(5).logicalSrcIdx = 142;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.TmpLatchAtDFlipFlopInport1_InitialCondition
                    section.data(6).logicalSrcIdx = 143;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Memory_InitialCondition_oggd2r4odw
                    section.data(7).logicalSrcIdx = 144;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Memory_InitialCondition_ljulw4woig
                    section.data(8).logicalSrcIdx = 145;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.pokud50mlj._Y0
                    section.data(1).logicalSrcIdx = 146;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.l2pxsorbc0.OUT_Y0
                    section.data(1).logicalSrcIdx = 147;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ntt0n0z3qa.OUT_Y0
                    section.data(1).logicalSrcIdx = 148;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.guziuj3nzou.OUT_Y0
                    section.data(1).logicalSrcIdx = 149;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.obgcvvf2c2c.OUT_Y0
                    section.data(1).logicalSrcIdx = 150;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.f5g5ssvz0ob._Y0
                    section.data(1).logicalSrcIdx = 151;
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

                    ;% rtB.dxp2tc3fwu
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.lyj5czwr1t
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 7;

                    ;% rtB.d4txlaulvr
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 8;

                    ;% rtB.f2es2rkn4r
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 9;

                    ;% rtB.ailrsbpb25
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtB.bfrc2rc5zl
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtB.ncdgrorzsx
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% rtB.pl5zjiseby
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% rtB.nihlui3tdy
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% rtB.lno2d3wb5h
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtB.nutzsr0h3j
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 22;

                    ;% rtB.nk4rw4u2ad
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 23;

                    ;% rtB.c5lvecx0ln
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 24;

                    ;% rtB.pznu3l5z1a
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 25;

                    ;% rtB.bhvr0udrsy
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 26;

                    ;% rtB.kmqtx532fz
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 27;

                    ;% rtB.hnp1kuefxm
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 28;

                    ;% rtB.lsnuriwz44
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 29;

                    ;% rtB.lisuhkiql3
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 30;

                    ;% rtB.ewq0jsmjdj
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 31;

                    ;% rtB.dv3oqsxz41
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 32;

                    ;% rtB.nz2mzf3abt
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 33;

                    ;% rtB.geeegghaq4
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 34;

                    ;% rtB.eancnret3z
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 35;

                    ;% rtB.m2vnyqktog
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 36;

                    ;% rtB.k3la20515u
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 37;

                    ;% rtB.jfofwf5qdn
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 38;

                    ;% rtB.k0hg52okk1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 39;

                    ;% rtB.dxje1nzfb1
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 40;

                    ;% rtB.lrg23dznf5
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 41;

                    ;% rtB.gopo0ay43o
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 42;

                    ;% rtB.ncgerps2w1
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 43;

                    ;% rtB.dzwzyjfb3d
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 44;

                    ;% rtB.hs04wl1crq
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 45;

                    ;% rtB.c1tvvwnguu
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 46;

                    ;% rtB.pxicmncoih
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 47;

                    ;% rtB.ao3hvbk03u
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 48;

                    ;% rtB.cjvhltyh5i
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 49;

                    ;% rtB.awbajcw3bs
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 50;

                    ;% rtB.k0xpbzxvuq
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 51;

                    ;% rtB.pgstwodvgn
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 52;

                    ;% rtB.ji14ejc3mp
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 53;

                    ;% rtB.agrizcdfza
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 54;

                    ;% rtB.mxxtwp3ieb
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 55;

                    ;% rtB.o0mruwezip
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 56;

                    ;% rtB.dwgm1iwulr
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 57;

                    ;% rtB.h3lftethav
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 58;

                    ;% rtB.kiqo1dkx4d
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 59;

                    ;% rtB.ki1f5bwrru
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 60;

                    ;% rtB.o51erkdynh
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 61;

                    ;% rtB.asbkydpcdt
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 62;

                    ;% rtB.mxwhtwoxqb
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 63;

                    ;% rtB.hzfal5kgng
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 64;

                    ;% rtB.kppvt5er43
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 65;

                    ;% rtB.ck3j1srrxl
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 67;

                    ;% rtB.pnagitghhg
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 69;

                    ;% rtB.gnsbtz3idv
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 71;

                    ;% rtB.amouf3rzmf
                    section.data(58).logicalSrcIdx = 58;
                    section.data(58).dtTransOffset = 72;

                    ;% rtB.l1u4z2oxl4
                    section.data(59).logicalSrcIdx = 59;
                    section.data(59).dtTransOffset = 73;

                    ;% rtB.ktacawrolb
                    section.data(60).logicalSrcIdx = 60;
                    section.data(60).dtTransOffset = 74;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% rtB.p4bwi2pbc0
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.efvczhdjet
                    section.data(2).logicalSrcIdx = 62;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ftifgsd50u
                    section.data(3).logicalSrcIdx = 63;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.hrmk3oqzup
                    section.data(4).logicalSrcIdx = 64;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.fv3qrvs3nd
                    section.data(5).logicalSrcIdx = 65;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.bq2qwyyni3
                    section.data(6).logicalSrcIdx = 66;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.bxjduwjkqo
                    section.data(7).logicalSrcIdx = 67;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.ohloxwa40r
                    section.data(8).logicalSrcIdx = 68;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.lfy2bgoxg0
                    section.data(9).logicalSrcIdx = 69;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.kowifb0jnq
                    section.data(10).logicalSrcIdx = 70;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.fv5bybewyw
                    section.data(11).logicalSrcIdx = 71;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.d0uzclm1vr
                    section.data(12).logicalSrcIdx = 72;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.pet04kmorq
                    section.data(13).logicalSrcIdx = 73;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.i3hvpke3ms
                    section.data(14).logicalSrcIdx = 74;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.octfr53rd1
                    section.data(15).logicalSrcIdx = 75;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.pokud50mlj.n0jiemzt0m
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.l2pxsorbc0.fncspxqpzn
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ntt0n0z3qa.gcuafzmxgi
                    section.data(1).logicalSrcIdx = 78;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.guziuj3nzou.fncspxqpzn
                    section.data(1).logicalSrcIdx = 79;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.obgcvvf2c2c.gcuafzmxgi
                    section.data(1).logicalSrcIdx = 80;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.f5g5ssvz0ob.n0jiemzt0m
                    section.data(1).logicalSrcIdx = 81;
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
        nTotSects     = 17;
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
            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% rtDW.adesp1hwj2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cac2du1fvg
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 7;

                    ;% rtDW.mbiyzrn1pd
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 14;

                    ;% rtDW.idhuf1euoi
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 15;

                    ;% rtDW.cgnw3nvnug
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 16;

                    ;% rtDW.guhnoflhss
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 22;

                    ;% rtDW.gwrvf21tek
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 23;

                    ;% rtDW.cuilob0auh
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 24;

                    ;% rtDW.g4c0zz45r4
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 25;

                    ;% rtDW.gamney3fyk
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 26;

                    ;% rtDW.hobor2c3tl
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 27;

                    ;% rtDW.jkafh5jkcy
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 28;

                    ;% rtDW.lddp3kj4wc.modelTStart
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 29;

                    ;% rtDW.bj4mi1vzil.modelTStart
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 30;

                    ;% rtDW.p5cigbuwvn.modelTStart
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 31;

                    ;% rtDW.gf4lfoijb0.modelTStart
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 32;

                    ;% rtDW.okq3xbd2ii.modelTStart
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 33;

                    ;% rtDW.iobbwey3sn.modelTStart
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 34;

                    ;% rtDW.e334mwrkee.modelTStart
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 35;

                    ;% rtDW.pryezgtgn4.modelTStart
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 36;

                    ;% rtDW.hzbip0oysg.modelTStart
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 37;

                    ;% rtDW.huh20tu5q1.modelTStart
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 38;

                    ;% rtDW.agxdp5talt.modelTStart
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 39;

                    ;% rtDW.nb2ebbj1qe.modelTStart
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 40;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% rtDW.c550b3xklm.TimePtr
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.jc1itafzwd.TUbufferPtrs
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lj1tdbxggs.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 3;

                    ;% rtDW.ml2avl24pf.TUbufferPtrs
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 5;

                    ;% rtDW.fbk251u41l.TUbufferPtrs
                    section.data(5).logicalSrcIdx = 28;
                    section.data(5).dtTransOffset = 7;

                    ;% rtDW.kpvx4uvt01.TUbufferPtrs
                    section.data(6).logicalSrcIdx = 29;
                    section.data(6).dtTransOffset = 9;

                    ;% rtDW.oeere24mz0.TUbufferPtrs
                    section.data(7).logicalSrcIdx = 30;
                    section.data(7).dtTransOffset = 11;

                    ;% rtDW.h1egexnfwb.TUbufferPtrs
                    section.data(8).logicalSrcIdx = 31;
                    section.data(8).dtTransOffset = 13;

                    ;% rtDW.lycpuo0tla.TUbufferPtrs
                    section.data(9).logicalSrcIdx = 32;
                    section.data(9).dtTransOffset = 15;

                    ;% rtDW.etoiwhh4sj.TUbufferPtrs
                    section.data(10).logicalSrcIdx = 33;
                    section.data(10).dtTransOffset = 17;

                    ;% rtDW.l4z1r030na.TUbufferPtrs
                    section.data(11).logicalSrcIdx = 34;
                    section.data(11).dtTransOffset = 19;

                    ;% rtDW.e3lmwmye5o.TUbufferPtrs
                    section.data(12).logicalSrcIdx = 35;
                    section.data(12).dtTransOffset = 21;

                    ;% rtDW.mxtwjhbmuw.TUbufferPtrs
                    section.data(13).logicalSrcIdx = 36;
                    section.data(13).dtTransOffset = 23;

                    ;% rtDW.j30qutghas.LoggedData
                    section.data(14).logicalSrcIdx = 37;
                    section.data(14).dtTransOffset = 25;

                    ;% rtDW.o1r21qardz.LoggedData
                    section.data(15).logicalSrcIdx = 38;
                    section.data(15).dtTransOffset = 33;

                    ;% rtDW.apsrc53ins.LoggedData
                    section.data(16).logicalSrcIdx = 39;
                    section.data(16).dtTransOffset = 37;

                    ;% rtDW.bexxg3fswd.LoggedData
                    section.data(17).logicalSrcIdx = 40;
                    section.data(17).dtTransOffset = 42;

                    ;% rtDW.kmyqkb4ou1.LoggedData
                    section.data(18).logicalSrcIdx = 41;
                    section.data(18).dtTransOffset = 46;

                    ;% rtDW.diduvlcjw5.LoggedData
                    section.data(19).logicalSrcIdx = 42;
                    section.data(19).dtTransOffset = 50;

                    ;% rtDW.otc0z4rhtr.LoggedData
                    section.data(20).logicalSrcIdx = 43;
                    section.data(20).dtTransOffset = 54;

                    ;% rtDW.dke2w5vglk.AQHandles
                    section.data(21).logicalSrcIdx = 44;
                    section.data(21).dtTransOffset = 58;

                    ;% rtDW.jqho42deiu.LoggedData
                    section.data(22).logicalSrcIdx = 45;
                    section.data(22).dtTransOffset = 59;

                    ;% rtDW.dla5jwburz.AQHandles
                    section.data(23).logicalSrcIdx = 46;
                    section.data(23).dtTransOffset = 60;

                    ;% rtDW.ivu5m05flg.AQHandles
                    section.data(24).logicalSrcIdx = 47;
                    section.data(24).dtTransOffset = 61;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.gv0a02tm0t
                    section.data(1).logicalSrcIdx = 48;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.avwaalc2cs
                    section.data(2).logicalSrcIdx = 49;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.bzmxqssdoq
                    section.data(1).logicalSrcIdx = 50;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ibd5rjzks4
                    section.data(2).logicalSrcIdx = 51;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% rtDW.kb5rvgdujd.PrevIndex
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.kcxfvmkrf2.Tail
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.n2bt3cyc55.Tail
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.lcuflefjuj.Tail
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ovi0zqdzif.Tail
                    section.data(5).logicalSrcIdx = 56;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.advdik1iky.Tail
                    section.data(6).logicalSrcIdx = 57;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.kb3fhgjdld.Tail
                    section.data(7).logicalSrcIdx = 58;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.ho5e0de00z.Tail
                    section.data(8).logicalSrcIdx = 59;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.dlpoyqagu4.Tail
                    section.data(9).logicalSrcIdx = 60;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.k1nwxppvuo.Tail
                    section.data(10).logicalSrcIdx = 61;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.azfuopxupm.Tail
                    section.data(11).logicalSrcIdx = 62;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.bnqksyhx4b.Tail
                    section.data(12).logicalSrcIdx = 63;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.jsj5ows1gx.Tail
                    section.data(13).logicalSrcIdx = 64;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.olipbciiyt
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ajzqjdehhp
                    section.data(2).logicalSrcIdx = 66;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ecetpirpni
                    section.data(3).logicalSrcIdx = 67;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.kjy05jsjy1
                    section.data(4).logicalSrcIdx = 68;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.mt4cgs1ctq
                    section.data(5).logicalSrcIdx = 69;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.jggqbqxmox
                    section.data(6).logicalSrcIdx = 70;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.bluxjvuquj
                    section.data(7).logicalSrcIdx = 71;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.pu1wrg42xz
                    section.data(8).logicalSrcIdx = 72;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.kia112cgkq
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.igyctbswok
                    section.data(2).logicalSrcIdx = 74;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.llqwbguanw
                    section.data(3).logicalSrcIdx = 75;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.i3eziu3f1n
                    section.data(4).logicalSrcIdx = 76;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.fbp5lgspzk
                    section.data(5).logicalSrcIdx = 77;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.nrn32puwjn
                    section.data(6).logicalSrcIdx = 78;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ckhj2mjol3
                    section.data(7).logicalSrcIdx = 79;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.haenchykp4
                    section.data(8).logicalSrcIdx = 80;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pokud50mlj.kw45gvclvl
                    section.data(1).logicalSrcIdx = 81;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.l2pxsorbc0.mzbzupg3uq
                    section.data(1).logicalSrcIdx = 82;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.l2pxsorbc0.miqumv2j33
                    section.data(1).logicalSrcIdx = 83;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ntt0n0z3qa.igzqysubwr
                    section.data(1).logicalSrcIdx = 84;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ntt0n0z3qa.jfiw2hmwe4
                    section.data(1).logicalSrcIdx = 85;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.guziuj3nzou.mzbzupg3uq
                    section.data(1).logicalSrcIdx = 86;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.guziuj3nzou.miqumv2j33
                    section.data(1).logicalSrcIdx = 87;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.obgcvvf2c2c.igzqysubwr
                    section.data(1).logicalSrcIdx = 88;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.obgcvvf2c2c.jfiw2hmwe4
                    section.data(1).logicalSrcIdx = 89;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.f5g5ssvz0ob.kw45gvclvl
                    section.data(1).logicalSrcIdx = 90;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
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


    targMap.checksum0 = 815223402;
    targMap.checksum1 = 1087110751;
    targMap.checksum2 = 1550997493;
    targMap.checksum3 = 3421349989;

