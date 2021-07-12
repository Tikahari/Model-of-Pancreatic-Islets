NEURON{
    SUFFIX one
    : Beta stimulating delta
    RANGE gGABAbar, EffId, iGABA 

    : Beta inhibiting alpha
    RANGE EffIa, gkatpa, ikatpa

    : Delta inhibiting alpha
    RANGE gGIRKbara, EffSa, iGIRKa, rm2a

    : Alpha stimulating beta
    RANGE r20

    : Delta inhibiting beta
    RANGE gGIRKbarb, EffSb, iGIRKb, rm2b

    : Equations beta cell
    RANGE ikca, minf, ica, ical, icar, ninf, ik, topo, bottomo, katpo, ikatp, vmdcyt, JL, JR, Jmem, Jserca, Jleak, Jer, f6p, Jgpdh, Jgk_ms, mod_cmd
    RANGE weight2, topa2, bottom2, weight3, topa3, bottom3, weight4, topa4, bottom4, weight5, topa5, bottom5, weight6, topa6, bottom6, weight7, topa7, bottom7, weight8, topa8, bottom8, weight9, topa9, bottom9, weight10, topa10, bottom10, weight11, topa11, bottom11, weight12, topa12, bottom12, weight13, topa13, bottom13, weight14, topa14, bottom14, weight15, topa15, topb, bottom15, weight16, topa16, bottom16
    RANGE pfk, pfk_ms, delta, Juni, JNaCa, Jmito, NADm, ATPm, RATm, Jpdh, JHleak, MM1, JO, MM2, JHres, b2, JF1F0, JHatp, FRT, Jant, atp, Jhyd, mgadp, adp3m, atp4m, ampfactor, r3, r2, JIS

    : Equations alpha cell
    RANGE mcalinfa, hcalinfa, taucalma, taucalha, icala, mcatinfa, hcatinfa, taucatma, taucatha, icata, mcapqinfa, hcapqinfa, taucapqma, taucapqha, icapqa, mnainfa, hnainfa, taunama, taunaha, inaa, mkainfa, hkainfa, taukaha, ikaa, mkdrinfa, taukdrma, ikdra, ila, cinfa, isoca, JLa, JPQa, JTa, Jmema, Jsercaa, Jleaka, Jera, r2a, r3a, JGS

    : Equations delta cell
    RANGE mcalinfd, hcalinfd, taucalmd, taucalhd, icald, mcapqinfd, hcapqinfd, taucapqmd, taucapqhd, icapqd, mnainfd, hnainfd, taunamd, taunahd, inad, mkainfd, hkainfd, taukahd, ikad, mkdrinfd, taukdrmd, ikdrd, ikatpd, ild, JLd, JPQd, Jmemd, Jsercad, Jleakd, Jerd, y, Som, JSS
}

PARAMETER{
    : Islet interactions
    knockoutbd=0
    knockoutba=0
    knockoutdb=0
    knockoutda=0

    : Beta stimulating delta
    vGABA=0

    : Beta inhibiting alpha
    tausom=2000
    vc = 1e-13
    : 1, 7, 11 mM glucose value respectively
    :gkatpbara=3
    :gkatpbara=0.6
    gkatpbara=0.15
    ka1=0.1

    : Delta inhibiting alpha
    gGIRKko=0
    vGIRK=-80
    sombara2=35
    ssom2=10
    ra=4.5
    sombara=50
    rako=0.001
    ssom=15

    : Alpha Stimulating beta
    gthresh=40

    : Delta inhibiting beta
    sombarb2=35
    sombarb=50
    ssomb=15
    rb=0.002

    : Parameters beta cell
    fb = 2000
    Jgk=0.4
    factor=14
    : 1, 7, 11 mM glucose value respectively
    :gkatpb=150
    :gkatpb=85
    gkatpb=25
    bas_r3=0.032
    amplify=1
    cm=5300
    gkca=280
    k4=150
    kd=0.5
    nca=590
    raL=0.5
    vca=25
    vm=-6
    sm=10
    gca=7
    vk=-75
    gk=1800
    vn=-16
    sn=6
    taun=5
    kdd=17
    ktd=26
    ktt=1
    fcyt=0.01
    fer=0.01
    fmd=0.01
    kpmca=0.2
    cbas=0.05
    B=1
    per=0.0002
    kserca3=0.1
    kserca2b=0.01
    sigmav=30
    vmd=4.2e-3
    vcell=1.15
    alpha=5.18e-6
    phigk=0.3
    KGPDH=0.0005
    k1=30
    k2=1
    k3=50000
    f13=0.02
    f43=20
    f23=0.2
    f42=20
    f41=20
    lambda=0.06
    taua=5
    VmaxPFK=5
    kappa=0.001
    Jgpdh_bas=0.0005
    fmito=0.01
    gamma=0.001
    p21=0.04
    p22=1.1
    exo_k1=20
    bas_cmd=0.06935
    p23=0.01 
    p24=0.016 
    Amtot=15 
    NADmtot=10 
    p1=400
    p2=1
    p3=0.01
    Cmito=1.8
    p17=0.002
    p18=-0.03
    p4=0.6
    p5=0.1
    p6=177
    p7=5
    p8=7
    p9=0.1
    p10=177
    p11=5
    p13=10
    p14=190
    p15=8.5
    p16=35
    p19=0.35
    p20=2
    khyd=0.00005 
    JhydSS=0.00005
    amp=500
    atot=2500
    km1=100 
    r1=0.6
    rm1=1
    r30=1.205
    rm3=0.0001
    u1=2000 
    u2=3 
    u3=0.02
    Kp=2.3 
    Kp2=2.3
    tmsb=0.001
    max_cmd=32 
    cmdp=4
    kcmd=3
    weight1=1
    topa1=0
    bottom1=1

    : Parameters alpha cell
    fa= 150
    gsocbara=0.025
    : 1, 7, 11 mM glucose value respectively
    :ksercaa=0.05
    :ksercaa=0.5
    ksercaa=0.5
    vnaa=70
    vka=-75
    vcaa=65
    vla=-20
    cma=5
    gcala=0.7 
    gcapqa=0.6
    gcata=0.5
    gnaa=11
    gkaa=1
    gkdra=4.5 
    gla=0.2
    vcella=0.624e-12 
    vmdpqa=1.41e-15
    fVpqa=0.00226
    fmda=0.01
    Ba=1
    alphaa=5.18e-15 
    kpmcaa=0.3 
    fcyta=0.01 
    fera=0.01
    pleaka=0.0003 
    sigmava=31
    vcalma=-30
    scalma=10
    vcalha=-33
    scalha=-5
    tcalh1a=60
    tcalh2a=51
    vcatma=-49
    scatma=4
    vcatha=-52
    scatha=-5
    tcatm1a=15
    tcatm2a=0
    tcath1a=20
    tcath2a=5
    vcapqma=-5
    scapqma=10
    vcapqha=-33
    scapqha=-5
    tcapqh1a=60
    tcapqh2a=51
    vnama=-30
    vnaha=-52
    snama=4
    snaha=-8
    tnah1a=120
    tnah2a=0.5
    vkama=-45
    skama=10
    vkaha=-68
    skaha=-10
    taukama=0.1
    tkah1a=60
    tkah2a=5
    vkdrma=-25
    skdrma=23
    caerbara=70 
    ssoca=-20
    vsoca=0
    k1a=20
    km1a=100 
    r1a=0.6
    rm1a=1 
    r20a=0.006
    r30a=1.205 
    rm3a=0.0001
    u1a=2000 
    u2a=3
    u3a=0.025
    kpa=2.3 
    kp2a=2.3 
    GlucFacta=0.05

    :Parameters delta cell
    fd= 0.003
    : 1, 7, 11 mM glucose value respectively
    :gkatpbard=0.29
    :gkatpbard=0.27
    gkatpbard=0.18
    vnad=70 
    vkd=-75 
    vcad=65
    vld=-20 
    gcald=0.7 
    gcapqd=0.7
    gnad=5 
    gkad=0.5 
    gkdrd=7.5
    gld=0.2
    vmdpqd=1.41e-15
    vmdld=2.12e-15
    fVld=0.00340
    fVpqd=0.00226 
    fmdd=0.01 
    Bd=1 
    alphad=5.18e-15
    kpmcad=0.3 
    fcytd=0.01 
    ferd=0.01
    pleakd=0.0003 
    sigmavd=31 
    ksercad=0.4
    vcalmd=-30 
    scalmd=10
    vcalhd=-33
    scalhd=-5
    tcalh1d=60
    tcalh2d=51
    vcapqmd=-15
    scapqmd=10
    vcapqhd=-33
    scapqhd=-5
    tcapqh1d=60
    tcapqh2d=51
    vnamd=-30
    vnahd=-52
    snamd=4
    snahd=-8
    tnah1d=120
    tnah2d=0.5
    vkamd=-45
    skamd=10
    vkahd=-68
    skahd=-10
    taukamd=0.1
    tkah1d=60
    tkah2d=5
    vkdrmd=-25
    skdrmd=23
    con=0.00000000594
    bas=0.0009
}

ASSIGNED{	
    : Beta stimulating delta
    gGABAbar
    EffId 
    iGABA 

    : Beta inhibiting alpha
    EffIa
    gkatpa
    ikatpa

    : Delta inhibiting alpha
    gGIRKbara
    EffSa
    iGIRKa
    rm2a

    : Alpha stimulating beta
    r20

    : Delta inhibiting beta
    gGIRKbarb
    EffSb
    iGIRKb
    rm2b

    : Equations beta cell
    ikca 
    minf 
    ica 
    ical 
    icar 
    ninf 
    ik 
    topo 
    bottomo 
    katpo 
    ikatp 
    vmdcyt
    JL 
    JR 
    Jmem 
    Jserca 
    Jleak 
    Jer 
    f6p 
    Jgpdh 
    Jgk_ms
    mod_cmd

    weight2
    topa2
    bottom2
    weight3
    topa3
    bottom3
    weight4
    topa4
    bottom4
    weight5
    topa5
    bottom5
    weight6
    topa6
    bottom6
    weight7
    topa7
    bottom7
    weight8
    topa8
    bottom8
    weight9
    topa9
    bottom9
    weight10
    topa10
    bottom10
    weight11
    topa11
    bottom11
    weight12
    topa12
    bottom12
    weight13
    topa13
    bottom13
    weight14
    topa14
    bottom14
    weight15
    topa15
    topb
    bottom15
    weight16
    topa16
    bottom16

    pfk
    pfk_ms
    delta
    Juni
    JNaCa
    Jmito
    NADm
    ATPm
    RATm
    Jpdh
    JHleak
    MM1
    JO
    MM2
    JHres
    b2
    JF1F0
    JHatp
    FRT
    Jant
    atp 
    Jhyd
    mgadp 
    adp3m 
    atp4m 
    ampfactor
    r3 
    r2 
    JIS

    : Equations alpha cell
    mcalinfa
    hcalinfa
    taucalma
    taucalha
    icala
    mcatinfa
    hcatinfa
    taucatma
    taucatha
    icata
    mcapqinfa
    hcapqinfa
    taucapqma
    taucapqha
    icapqa
    mnainfa
    hnainfa
    taunama
    taunaha
    inaa
    mkainfa
    hkainfa
    taukaha
    ikaa
    mkdrinfa
    taukdrma
    ikdra
    ila
    cinfa 
    isoca 
    JLa
    JPQa
    JTa
    Jmema 
    Jsercaa 
    Jleaka 
    Jera 
    r2a
    r3a
    JGS

    : Equations delta cell
    mcalinfd
    hcalinfd
    taucalmd
    taucalhd
    icald
    mcapqinfd
    hcapqinfd
    taucapqmd
    taucapqhd
    icapqd
    mnainfd
    hnainfd
    taunamd
    taunahd
    inad
    mkainfd
    hkainfd
    taukahd
    ikad
    mkdrinfd
    taukdrmd
    ikdrd
    ikatpd
    ild
    JLd
    JPQd
    Jmemd 
    Jsercad 
    Jleakd 
    Jerd 
    y
    Som
    JSS
}

STATE{
    : Beta
    vb 
    n <1e-10>
    c 
    cer 
    cmd 
    g6p 
    fbp 
    adpm
    cam 
    NADHm 
    Psim
    adp 
    n1 
    n2 
    n3 
    n4 <1e-10>
    n5 
    n6 
    nf 
    nr 
    I

    : Alpha
    va
    mcala 
    hcala 
    mcata 
    hcata 
    mcapqa 
    hcapqa 
    mnaa 
    hnaa 
    mkaa 
    hkaa 
    mkdra 
    ca
    cmdpqa
    cera
    n1a <1e-10>
    n2a <1e-10>
    n3a <1e-10>
    n4a <1e-10>
    n5a 
    n6a 
    nfa 
    nra 
    G

    : Delta
    vd
    mcald 
    hcald 
    mcapqd 
    hcapqd 
    mnad 
    hnad 
    mkad 
    hkad 
    mkdrd 
    cd 
    cmdld
    cmdpqd
    cerd 
    S
}

INITIAL{
    : Initial conditions beta cell
    vb=-71.33779976819424  
    n=9.875188779513991e-05  
    c=0.0630015242008439  
    cer=81.57023672312617  
    cmd=0.4188629403487558  
    g6p=244.936858732948  
    fbp=0.08283840527865462 
    adpm=13.53015038508978  
    cam=0.01102007399722167 
    NADHm=0.02908310367935971 
    Psim=151.1015153147079  
    adp=1913.096601466651  
    n1=4.627586868810905  
    n2=0.2262327588817945  
    n3=0.003661670524646639  
    n4=2.595179480355916e-06  
    n5=7.762125378310579  
    n6=274.1666227230976  
    nf=0.00172689211245988  
    nr=0.3002686554719045 

    : Inital conditions alpha cell
    va=-49.03736299581227  
    mcala=0.1293341713632475  
    hcala=0.8127842536675057  
    mcata=0.4633857551023612  
    hcata=0.3735421388722815  
    mcapqa=0.0120465460803863  
    hcapqa=0.8127842536675057  
    mnaa=0.007938786735335676  
    hnaa=0.2498175179717122 
    mkaa=0.4001652246173745
    hkaa=0.1373195977592295  
    mkdra=0.2674634279865117 
    ca=0.3449148387259899  
    cmdpqa=11.51299890826233 
    cera=58.71698724650182
    n1a=1.057203539612775e-05
    n2a=2.113947666062938e-05  
    n3a=2.388848788981755e-05  
    n4a=2.391806975716259e-06  
    n5a=0.008850176609826538  
    n6a=12.69715161782077  
    nfa=0.001724142875712899  
    nra=0.1927364884362762  

    : Inital condition delta cell  
    vd=-16.26895428994972  
    mcald=0.8218051702003508  
    hcald=0.6672499701175263  
    mcapqd=0.5089033026581684  
    hcapqd=0.6672499701175263  
    mnad=0.9737137320580179  
    hnad=0.006777955247303555  
    mkad=0.9480884005315277 
    hkad=0.02771925786328598  
    mkdrd=0.5717652452166768 
    cd=0.3051356309084454  
    cmdld=19.82903375122306  
    cmdpqd=27.93917378868966  
    cerd=413.8135591677398  

    : Initial hormone concentrations

    I=48.04298494148047  
    G=31.73727470720019 
    S=18.71318922819339

    : Initialization variables not included in BAD model XPP file
    : Generated from calculate.py
    taucalma=0.3032811940166806
    taucalha=56.12989393816361
    mcalinfa=0.1296861831162709
    hcalinfa=0.9611145179788654
    icala=-1.08529313843157
    mcapqinfa=0.012083750627573104
    hcapqinfa=0.9611145179788654
    taucapqma=0.3032811940166806
    taucapqha=56.12989393816361
    icapqa=-0.6699405169228547
    mcatinfa=0.4976648297402624
    hcatinfa=0.3560551615487483
    taucatma=7.475932505911923
    taucatha=14.979442612364645
    icata=-2.1192627702105704
    gGIRKbara=0.025
    EffSa=0.16401112054523317
    iGIRKa=0.1269554197523033
    rm2a=0.49718657776876884
    cinfa =0.6374123727563218
    isoca =-0.7814255475218438
    JLa=0.009009324450441558
    JPQa=2.461199913234317
    JTa=0.017592597996299284
    Jmema =-0.051632659173903986
    Jsercaa =0.17245741936299494
    Jleaka =0.017511621722332747
    Jera =-0.1549457976406622
    r2a=0.0007824407054832726
    r3a=0.00785700875089453
    JGS=4.760591264376022e-10
    mkainfa=0.40041498568618583
    hkainfa=0.13053193445833075
    taukaha=9.00677536264756
    ikaa=1.4266606033882763
    EffIa=0.10001054147411872
    gkatpa=0.06000632488447123
    ikatpa=1.5579224309308837
    mkdrinfa=0.26016661765554117
    taukdrma=15.30146142661036
    ikdra=0.5978867667431156
    ila=-5.807472599162455
    mnainfa=0.008498416028612855
    hnainfa=0.40846137482156436
    taunama=3.036153418307839
    taunaha=60.06822869326301
    inaa=-0.00016366705880007713
    minf =0.0014513916520931425
    ica =-577.4726176457064
    gGIRKbarb=10
    EffSb=0.16401112054523317
    iGIRKb=14.206971664056404
    r20=0.006001031554023141
    rm2b=0.00022097181234167506
    ikca =16.025854402092854
    ical =-288.7363088228532
    icar =-288.7363088228532
    topo =309.906384691809
    bottomo =15423.383945456666
    katpo =0.020093280812288894
    ikatp =311.2870197034892
    vmdcyt=0.0036521739130434784
    JL =0.3561081142148523
    JR =0.001300568764958591
    Jmem =-6.829449607573257e-08
    Jserca =0.01630015242008439
    Jleak =0.016301447039785068
    Jer =1.2946197006785676e-06
    f6p =73.4810576198844
    Jgpdh =0.00014390830872351902
    Jgk_ms=0.0004
    mod_cmd=0.08150591626797878
    weight2=2296.370661399967
    topa2=0
    bottom2=2297.370661399967
    weight3=0.10798931657873541
    topa3=0.10798931657873541
    bottom3=2297.478650716546
    weight4=12.399174916802055
    topa4=12.50716423338079
    bottom4=2309.877825633348
    weight5=0.08283840527865462
    topa5=12.50716423338079
    bottom5=2309.960664038627
    weight6=9.51138417595313
    topa6=12.50716423338079
    bottom6=2319.47204821458
    weight7=0.044728313862571104
    topa7=12.55189254724336
    bottom7=2319.5167765284423
    weight8=0.2567819692197443
    topa8=12.808674516463105
    bottom8=2319.773558497662
    weight9=16.666666666666668
    topa9=12.808674516463105
    bottom9=2336.4402251643287
    weight10=1913.642217833306
    topa10=12.808674516463105
    bottom10=4250.082442997635
    weight11=89.99109714894618
    topa11=102.79977166540928
    bottom11=4340.073540146581
    weight12=516.6322882000856
    topa12=619.4320598654948
    bottom12=4856.705828346667
    weight13=1.380640087977577
    topa13=619.4320598654948
    bottom13=4858.086468434644
    weight14=7.926153479960942
    topa14=619.4320598654948
    bottom14=4866.012621914605
    weight15=37.273594885475916
    topa15=619.4320598654948
    topb=37.273594885475916
    bottom15=4903.286216800081
    weight16=10.699248717489347
    topa16=630.1313085829842
    bottom16=4913.98546551757

    pfk=0.07639570154136274
    pfk_ms=7.639570154136274e-05
    Juni=0.01962392608626012
    JNaCa=0.019624306722058324
    Jmito=3.806357982034936e-07
    NADm=9.97091689632064
    ATPm=1.4698496149102205
    RATm=0.10863512770190598
    Jpdh=0.13463853801663372
    JHleak=0.27220303062941587
    MM1=0.13518316270858338
    JO=0.13442638085707123
    MM2=1.5771368982668066
    JHres=1.5683077766658313
    b2=30.514785437554284
    JF1F0=0.31088837377098194
    JHatp=0.9326651213129458
    FRT=0.037410133089805564
    Jant=0.304446602316938
    atp =586.903398533349
    Jhyd=0.031193960359980264
    mgadp =315.6609392419974
    adp3m =258.2680411979979
    atp4m =29.345169926667452
    ampfactor=0.25298632618462513
    r3 =0.040127765219777956
    r2 =0.0001599974146477454

    JIS=9.608596975100945e-09
    ninf =9.873556239473554e-05
    ik =0.6509685354743112
    mcalinfd=0.797881280658739
    hcalinfd=0.03401952024443635
    taucalmd=0.5229606925470396
    taucalhd=73.2304683206763
    icald=-25.635926220427873
    mcapqinfd=0.468318643634233
    hcapqinfd=0.03401952024443635
    taucapqmd=0.5229606925470396
    taucapqhd=73.2304683206763
    icapqd=-19.317305313715206
    gGABAbar=0.1
    EffId =41.56833392753747
    iGABA =-67.62733245764733
    mkainfd=0.9465007724360222
    hkainfd=0.005635014702807043
    taukahd=23.509361336319593
    ikad=0.7717349514854953
    ikatpd=15.857382341713578
    mkdrinfd=0.5937792009880476
    taukdrmd=15.72702251180529
    ikdrd=47.07604938593722
    ild=0.7462091420100564
    mnainfd=0.9687128701879236
    hnainfd=0.011358328217907197
    taunamd=0.255456748187674
    taunahd=2.2698475854851585
    inad=-2.699088467105948
    JLd=62.63872538764923
    JPQd=70.96712164896792
    Jmemd =0.037293490573121604
    Jsercad =0.12205425236337818
    Jleakd =0.1240525270610494
    Jerd =0.0019982746976712207
    y=0.19225889978869892
    Som=0.0074284530481816
    JSS=4.412501110619871e-14
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    : Beta stimulating delta
    gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0
    EffId = 0.8/(1+exp(-(I-1500)/500))
    iGABA = gGABAbar*EffId*(vd-vGABA)

    : Beta inhibiting alpha
    EffIa=(1-knockoutba)*((0.015/(1+exp((-I+1500)/200)))+ka1)+knockoutba*ka1
    gkatpa=gkatpbara*EffIa
    ikatpa=gkatpa*(va-vka)

    : Delta inhibiting alpha
    gGIRKbara=(1-knockoutda)*0.025+knockoutda*gGIRKko
    EffSa=1/(1+exp(-(S-sombara2)/ssom2))
    iGIRKa=gGIRKbara*EffSa*(va-vGIRK)
    rm2a=(1-knockoutda)*ra/(1+exp(-(S-sombara)/ssom))+knockoutda*rako

    : Alpha stimulating beta
    r20=0.004/(1+exp(-G+gthresh))+0.006

    : Delta inhibiting beta
    gGIRKbarb=(1-knockoutdb)*10+knockoutdb*0
    EffSb=1/(1+exp(-(S-sombarb2)/10))
    iGIRKb=gGIRKbarb*EffSb*(vb-vGIRK)
    rm2b=(1-knockoutdb)*rb/(1+exp(-(S-sombarb)/ssomb))+knockoutdb*0.001

    : Equations beta cell
    ikca = gkca/(1+(kd/c)^2)*(vb-vk)
    minf = 1/(1+exp((vm-vb)/sm))
    ica = gca*nca*minf*(vb-vca)
    ical = raL*ica
    icar = (1-raL)*ica
    ninf = 1/(1+exp((vn-vb)/sn))
    ik = gk*n*(vb-vk)
    topo = 0.08*(1+2*mgadp/kdd) + 0.89*(mgadp/kdd)^2
    bottomo = (1+mgadp/kdd)^2 * (1+adp3m/ktd+atp4m/ktt)
    katpo = (topo/bottomo)
    ikatp = gkatpb*(vb-vk)
    vmdcyt=vmd/vcell
    JL = -alpha*ical/vmd
    JR = -alpha*icar/vcell
    Jmem = JR+vmdcyt*B*(cmd-c)-kpmca*(c-cbas)
    Jserca = kserca2b+kserca3*c
    Jleak = per*(cer - c)
    Jer = (Jleak - Jserca)
    f6p = phigk*g6p
    Jgpdh = KGPDH*sqrt(fbp) 
    Jgk_ms=kappa*Jgk
    mod_cmd=bas_cmd + max_cmd*cmd^cmdp/(cmd^cmdp+kcmd^cmdp)


    weight2=atp^2/k4
    topa2=topa1
    bottom2=bottom1+weight2
    weight3=f6p^2/k3
    topa3=topa2+weight3
    bottom3=bottom2+weight3
    weight4=(f6p*atp)^2/(f43*k3*k4)
    topa4=topa3+weight4
    bottom4=bottom3+weight4
    weight5=fbp/k2
    topa5=topa4
    bottom5=bottom4+weight5
    weight6=(fbp*atp^2)/(k2*k4*f42)
    topa6=topa5
    bottom6=bottom5+weight6
    weight7=(fbp*f6p^2)/(k2*k3*f23)
    topa7=topa6+weight7
    bottom7=bottom6+weight7
    weight8=(fbp*f6p^2*atp^2)/(k2*k3*k4*f23*f42*f43)
    topa8=topa7+weight8
    bottom8=bottom7+weight8
    weight9=amp/k1
    topa9=topa8
    bottom9=bottom8+weight9
    weight10=(amp*atp^2)/(k1*k4*f41)
    topa10=topa9
    bottom10=bottom9+weight10
    weight11=(amp*f6p^2)/(k1*k3*f13)
    topa11=topa10+weight11
    bottom11=bottom10+weight11
    weight12=(amp*f6p^2*atp^2)/(k1*k3*k4*f13*f41*f43)
    topa12=topa11+weight12
    bottom12=bottom11+weight12
    weight13=(amp*fbp)/(k1*k2)
    topa13=topa12
    bottom13=bottom12+weight13
    weight14=(amp*fbp*atp^2)/(k1*k2*k4*f42*f41)
    topa14=topa13
    bottom14=bottom13+weight14
    weight15=(amp*fbp*f6p^2)/(k1*k2*k3*f23*f13)
    topa15=topa14
    topb=weight15
    bottom15=bottom14+weight15
    weight16=(amp*fbp*f6p^2*atp^2)/(k1*k2*k3*k4*f23*f13*f42*f41*f43)
    topa16=topa15+weight16
    bottom16=bottom15+weight16

    pfk=(lambda*VmaxPFK*topa16 + VmaxPFK*topb)/bottom16
    pfk_ms=kappa*pfk 
    delta=3.9/53.2
    Juni=(p21*Psim-p22)*c^2
    JNaCa=(p23/c)*cam*exp(p24*Psim)
    Jmito=JNaCa-Juni
    NADm=NADmtot-NADHm
    ATPm=Amtot-adpm
    RATm=ATPm/adpm
    Jpdh=(p1/(p2+NADHm/NADm))*(cam/(p3+cam))*(Jgpdh+Jgpdh_bas)
    JHleak=p17*Psim+p18
    MM1=p4*NADHm/(p5+NADHm)
    JO=MM1/(1+exp((Psim-p6)/p7))
    MM2=p8*NADHm/(p9+NADHm)
    JHres=MM2/(1+exp((Psim-p10)/p11))
    b2=(p16*p13)/(p13+ATPm)
    JF1F0=b2/(1.0+exp((p14-Psim)/p15))
    JHatp=3*JF1F0
    FRT=96480/(310.16*8315)
    Jant=p19*(RATm/(RATm+p20))/exp(-0.5*FRT*Psim)
    atp = atot-adp
    Jhyd=(khyd*c+JhydSS)*atp
    mgadp = 0.165*adp
    adp3m = 0.135*adp
    atp4m = 0.05*atp
    ampfactor=factor*JO^2
    r3 = bas_r3 + amplify*ampfactor*r30*c/(c + Kp)
    r2 = r20*c/(c + Kp2)
    JIS=tmsb*u3*nr*0.0016

    : Equations alpha cell
    mcalinfa=1/(1+exp(-(va-vcalma)/scalma))
    hcalinfa=1/(1+exp(-(va-vcalha)/scalha))
    taucalma=(1/(exp(-(va+23)/20)+exp((va+23)/20)))+0.05
    taucalha=(tcalh1a/(exp(-(va+0)/20)+exp((va+0)/20)))+tcalh2a
    icala=gcala*mcala^2*hcala*(va-vcaa)
    mcatinfa=1/(1+exp(-(va-vcatma)/scatma))
    hcatinfa=1/(1+exp(-(va-vcatha)/scatha))
    taucatma=(tcatm1a/(exp(-(va+50)/12)+exp((va+50)/12)))+tcatm2a
    taucatha=(tcath1a/(exp(-(va+50)/15)+exp((va+50)/15)))+tcath2a
    icata=gcata*mcata^3*hcata*(va-vcaa)
    mcapqinfa=1/(1+exp(-(va-vcapqma)/scapqma))
    hcapqinfa=1/(1+exp(-(va-vcapqha)/scapqha))
    taucapqma=(1/(exp(-(va+23)/20)+exp((va+23)/20)))+0.05
    taucapqha=(tcapqh1a/(exp(-(va+0)/20)+exp((va+0)/20)))+tcapqh2a
    icapqa=gcapqa*mcapqa*hcapqa*(va-vcaa)
    mnainfa=1/(1+exp(-(va-vnama)/snama))
    hnainfa=1/(1+exp(-(va-vnaha)/snaha))
    taunama=(6/(exp(-(va+50)/10)+exp((va+50)/10)))+0.05
    taunaha=(tnah1a/(exp(-(va+50)/8)+exp((va+50)/8)))+tnah2a
    inaa=gnaa*mnaa^3*hnaa*(va-vnaa)
    mkainfa=1/(1+exp(-(va-vkama)/skama))
    hkainfa=1/(1+exp(-(va-vkaha)/skaha))
    taukaha=(tkah1a/(exp(-(va-5)/20)+exp((va-5)/20)))+tkah2a
    ikaa=gkaa*mkaa*hkaa*(va-vka)
    mkdrinfa=1/(1+exp(-(va-vkdrma)/skdrma))
    taukdrma=(1.5/(exp(-(va+10)/25)+exp((va+10)/25)))+15
    ikdra=gkdra*mkdra^4*(va-vka)
    ila=gla*(va-vla)
    cinfa = 1/(1+exp(-(cera-caerbara)/ssoca))
    isoca = gsocbara*cinfa*(va-vsoca)
    JLa=-alphaa*icala/vcella
    JPQa=-alphaa*icapqa/vmdpqa
    JTa=-alphaa*icata/vcella
    Jmema = JTa+JLa+fVpqa*Ba*(cmdpqa-ca)-kpmcaa*ca
    Jsercaa = ksercaa*ca
    Jleaka = pleaka*(cera - ca)
    Jera = Jleaka - Jsercaa
    r2a=r20a*ca/(ca+kp2a)
    r3a=GlucFacta*r30a*ca/(ca+kpa)
    JGS=tmsb*u3a*nra*0.0000988

    : Equations delta cell
    mcalinfd=1/(1+exp(-(vd-vcalmd)/scalmd))
    hcalinfd=1/(1+exp(-(vd-vcalhd)/scalhd))
    taucalmd=(1/(exp(-(vd+23)/20)+exp((vd+23)/20)))+0.05
    taucalhd=(tcalh1d/(exp(-(vd+0)/20)+exp((vd+0)/20)))+tcalh2d
    icald=gcald*mcald^2*hcald*(vd-vcad)
    mcapqinfd=1/(1+exp(-(vd-vcapqmd)/scapqmd))
    hcapqinfd=1/(1+exp(-(vd-vcapqhd)/scapqhd))
    taucapqmd=(1/(exp(-(vd+23)/20)+exp((vd+23)/20)))+0.05
    taucapqhd=(tcapqh1d/(exp(-(vd+0)/20)+exp((vd+0)/20)))+tcapqh2d
    icapqd=gcapqd*mcapqd*hcapqd*(vd-vcad)
    mnainfd=1/(1+exp(-(vd-vnamd)/snamd))
    hnainfd=1/(1+exp(-(vd-vnahd)/snahd))
    taunamd=(6/(exp(-(vd+50)/10)+exp((vd+50)/10)))+0.05
    taunahd=(tnah1d/(exp(-(vd+50)/8)+exp((vd+50)/8)))+tnah2d
    inad=gnad*mnad^3*hnad*(vd-vnad)
    mkainfd=1/(1+exp(-(vd-vkamd)/skamd))
    hkainfd=1/(1+exp(-(vd-vkahd)/skahd))
    taukahd=(tkah1d/(exp(-(vd-5)/20)+exp((vd-5)/20)))+tkah2d
    ikad=gkad*mkad*hkad*(vd-vkd)
    mkdrinfd=1/(1+exp(-(vd-vkdrmd)/skdrmd))
    taukdrmd=(1.5/(exp(-(vd+10)/25)+exp((vd+10)/25)))+15
    ikdrd=gkdrd*mkdrd^4*(vd-vkd)
    ikatpd=gkatpbard*(vd-vkd)
    ild=gld*(vd-vld)
    JLd=-alphad*icald/vmdld
    JPQd=-alphad*icapqd/vmdpqd
    Jmemd = fVld*Bd*(cmdld-cd)+fVpqd*Bd*(cmdpqd-cd)-kpmcad*cd
    Jsercad = ksercad*cd
    Jleakd = pleakd*(cerd - cd)
    Jerd = (Jleakd - Jsercad)
    y=(cmdpqd/200)^4/(0.2^4+(cmdpqd/200)^4)
    Som=(200*mcapqd*hcapqd*(y)/tausom)+bas
    JSS=tmsb*Som*con
}

DERIVATIVE states{
    : ODE's
    : Beta
    vb' = -(ik + ica + ikca + ikatp+iGIRKb)/cm 
    n' = (ninf-n)/taun
    c' = fcyt*(Jmem + Jer + delta*Jmito)
    cer' = -fer*sigmav*Jer
    cmd' = fmd*(JL-B*(cmd-c)) 
    g6p' = Jgk_ms - pfk_ms
    fbp' = pfk_ms - 0.5*Jgpdh 
    adpm'= gamma*(Jant-JF1F0)
    cam' = -fmito*Jmito
    NADHm' = gamma*(Jpdh-JO)
    Psim'=(JHres-JHatp-Jant-JHleak-JNaCa-2*Juni)/Cmito
    adp' = (-delta*Jant + Jhyd)/taua
    n1' = tmsb*(-(3*exo_k1*mod_cmd + rm1)*n1 + km1*n2 + r1*n5)
    n2' = tmsb*(3*exo_k1*mod_cmd*n1 -(2*exo_k1*mod_cmd + km1)*n2 + 2*km1*n3)
    n3' = tmsb*(2*exo_k1*mod_cmd*n2 -(2*km1 + exo_k1*mod_cmd)*n3 + 3*km1*n4)
    n4' = tmsb*(exo_k1*mod_cmd*n3 - (3*km1 + u1)*n4)
    n5' = tmsb*(rm1*n1 - (r1 + rm2b)*n5 + r2*n6)
    n6' = tmsb*(r3 + rm2b*n5 - (rm3 + r2)*n6)
    nf' = tmsb*(u1*n4 - u2*nf)
    nr' = tmsb*(u2*nf - u3*nr)
    I'=JIS/vc-fb*I

    : Alpha
    va'=-(icala+icata+icapqa+inaa+ikdra+ikatpa+ikaa+ila+isoca+iGIRKa)/cma
    mcala'=(mcalinfa-mcala)/taucalma
    hcala'=(hcalinfa-hcala)/taucalha
    mcata'=(mcatinfa-mcata)/taucatma
    hcata'=(hcatinfa-hcata)/taucatha
    mcapqa'=(mcapqinfa-mcapqa)/taucapqma
    hcapqa'=(hcapqinfa-hcapqa)/taucapqha
    mnaa'=(mnainfa-mnaa)/taunama
    hnaa'=(hnainfa-hnaa)/taunaha
    mkaa'=(mkainfa-mkaa)/taukama
    hkaa'=(hkainfa-hkaa)/taukaha
    mkdra'=(mkdrinfa-mkdra)/taukdrma
    ca'= fcyta*(Jmema+Jera)
    cmdpqa'=fmda*JPQa-fmda*Ba*(cmdpqa-ca)
    cera'= -fera*sigmava*Jera
    n1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*n1a + km1a*n2a + r1a*n5a)
    n2a' = tmsb*(3*k1a*cmdpqa*n1a -(2*k1a*cmdpqa + km1a)*n2a + 2*km1a*n3a)
    n3a' = tmsb*(2*k1a*cmdpqa*n2a -(2*km1a + k1a*cmdpqa)*n3a + 3*km1a*n4a)
    n4a' = tmsb*(k1a*cmdpqa*n3a - (3*km1a + u1a)*n4a)
    n5a' = tmsb*(rm1a*n1a - (r1a + rm2a)*n5a + r2a*n6a)
    n6a' = tmsb*(r3a + rm2a*n5a - (rm3a + r2a)*n6a)
    nfa' = tmsb*(u1a*n4a - u2a*nfa)
    nra' = tmsb*(u2a*nfa - u3a*nra)
    G'=JGS/vc-fa*G

    : Delta
    vd'=-(icald+icapqd+inad+ikdrd+ikatpd+ikad+ild+iGABA)/cma
    mcald'=(mcalinfd-mcald)/taucalmd
    hcald'=(hcalinfd-hcald)/taucalhd
    mcapqd'=(mcapqinfd-mcapqd)/taucapqmd
    hcapqd'=(hcapqinfd-hcapqd)/taucapqhd
    mnad'=(mnainfd-mnad)/taunamd
    hnad'=(hnainfd-hnad)/taunahd
    mkad'=(mkainfd-mkad)/taukamd
    hkad'=(hkainfd-hkad)/taukahd
    mkdrd'=(mkdrinfd-mkdrd)/taukdrmd
    cd' = fcytd*(Jmemd+Jerd) 
    cmdld'=fmdd*JLd-fmdd*Bd*(cmdld-cd)
    cmdpqd'=fmdd*JPQd-fmdd*Bd*(cmdpqd-cd)
    cerd' = -ferd*sigmavd*Jerd
    S'=JSS/vc-fd*S
}