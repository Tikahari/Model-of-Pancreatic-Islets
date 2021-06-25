NEURON{
    SUFFIX one
    RANGE cala 
	RANGE capqa
    RANGE cata 
    RANGE GIRKa
    RANGE soca
    RANGE kaa
    RANGE katpa
    RANGE kdra
    RANGE la
    RANGE naa
    RANGE Ca
    RANGE GIRKb
    RANGE kca
    RANGE kb 
    RANGE cald
    RANGE capqd
    RANGE GABA
    RANGE kad
    RANGE katpd
    RANGE kdrd
    RANGE ld
    RANGE nad
    RANGE vcaa, gcala, tcalh1a, tcalh2a, vcalma, scalma, vcalha, scalha
    RANGE taucalma, taucalha, mcalinfa, hcalinfa, icala
    RANGE tcapqh1a, tcapqh2a, vcapqma, scapqma, vcapqha, scapqha, gcapqa
    RANGE mcapqinfa, hcapqinfa, taucapqma, taucapqha, icapqa
    RANGE gcata, vcatma, scatma, vcatha, scatha, tcatm1a, tcatm2a, tcath1a, tcath2a
    RANGE mcatinfa, hcatinfa, taucatma, taucatha, icata
    RANGE knockoutda, gGIRKko, vGIRK, sombara2, ssom2
    RANGE gGIRKbara, EffSa, iGIRKa, Sst
    RANGE vc, caerbara, ssoca, vsoca, k1a, km1a, r1a, rm1a, r20a, r30a, rm3a, u1a, u2a, u3a, kpa, kp2a, GlucFacta, vcella, vmdpqa, fVpqa, fmda, Ba, alphaa, kpmcaa, fcyta, fera, pleaka, sigmava, fa, gsocbara, ksercaa, tmsb, knockoutda, ra, sombara, rako, ssom
    RANGE rm2a, cinfa, JLa, JPQa, JTa, Jmema, Jsercaa, Jleaka, Jera, r2a, r3a, JGS, isoca
    RANGE gkaa, vkama, skama, vkaha, skaha, taukama, tkah1a, tkah2a
    RANGE mkainfa, hkainfa, taukaha, ikaa
    RANGE gkatpbara, vka, ka1, knockoutba
    RANGE EffIa, gkatpa, ikatpa
    RANGE vkdrma, skdrma, gkdra
    RANGE mkdrinfa, taukdrma, ikdra
    RANGE gla, vla, ila
    RANGE vnaa, vnama, vnaha, snama, snaha, tnah1a, tnah2a, gnaa
    RANGE mnainfa, hnainfa, taunama, taunaha, inaa
    RANGE vm, sm, gca, vca, nca
    RANGE iCa
    RANGE knockoutdb, vGIRK, sombarb2
    RANGE gGIRKbarb, EffSb, iGIRKb
    RANGE gthresh,sombarb,ssomb,rb,fb,Jgk,factor,gkatpb,bas_r3,amplify,gkca,k4,gkatpbar,kd,nca,raL,vca,vm,sm,gca,vk,kdd,ktd,ktt,fcyt,fer,fmd,kpmca,cbas,B,per,kserca3,kserca2b,sigmav,vmd,vcell,alpha,phigk,KGPDH,k1,k2,k3,f13,f43,f23,f42,f41,lambda,taua,VmaxPFK,kappa,Jgpdh_bas,fmito,gamma,p21,p22,exo_k1,bas_cmd,p23,p24,Amtot,NADmtot
    RANGE p1,p2,p3,Cmito,p17,p18,p4,p5,p6,p7,p8,p9,p10,p11,p13,p14,p15,p16,p19,p20,khyd,JhydSS,amp,atot,km1,r1,rm1,r30,rm3,u1,u2,u3,Kp,Kp2,tmsb,max_cmd,cmdp,kcmd,delta,vc,knockoutdb
    RANGE EffSb,r20,minf,IcaL,IcaR,ninf,topo,bottomo,katpo,vmdcyt,JL,JR,Jmem,Jserca,Jleak,Jer,f6p,Jgpdh,Jgk_ms,mod_cmd,weight1,topa1,bottom1,weight2,topa2,bottom2,weight3,topa3,bottom3,weight4,topa4,bottom4,weight5,topa5,bottom5,weight6,topa6,bottom6,weight7,topa7,bottom7,weight8,topa8,bottom8,weight9,topa9,bottom9,weight10,topa10,bottom10,weight11,topa11,bottom11,weight12,topa12,bottom12,weight13,topa13,bottom13,weight14,topa14
    RANGE bottom14,weight15,topa15,topb,bottom15,weight16,topa16,bottom16,pfk,pfk_ms,Juni,JNaCa,Jmito,NADm,ATPm,RATm,Jpdh,JHleak,MM1,JO,MM2,JHres,b2,JF1F0,JHatp,FRT,Jant,atp,Jhyd,mgadp,adp3m,atp4m,ampfactor,r3,r2,JIS,rm2b
    RANGE ikca, ikatp
    RANGE taun, vk, gk, vn, sn
    RANGE ikb
    RANGE gcald, vcad, vcalmd, scalmd, vcalhd, scalhd, tcalh1d, tcalh2d
    RANGE mcalinfd, hcalinfd, taucalmd, taucalhd, icald
    RANGE gcapqd, vcad, scapqmd, vcapqmd, scapqhd, vcapqhd, tcapqh1d, tcapqh2d
    RANGE mcapqinfd, hcapqinfd, taucapqmd, taucapqhd, icapqd
    RANGE knockoutbd, vGABA 
    RANGE gGABAbar, EffId, iGABA
    RANGE gkad, vkd, vkamd, skamd, vkahd, skahd, taukamd, tkah1d, tkah2d
    RANGE mkainfd, hkainfd, taukahd, ikad
    RANGE gkatpbard, vkd
    RANGE ikatpd
    RANGE gkdrd, vkd, vkdrmd, skdrmd
    RANGE mkdrinfd, taukdrmd, ikdrd
    RANGE gld, vld
    RANGE ild
    RANGE gnad, vnad, vnamd, vnahd, snamd, snahd, tnah1d, tnah2d
    RANGE mnainfd, hnainfd, taunamd, taunahd, inad
    RANGE con, bas, vc, tmsb, tausom, pleakd, fVld, fVpqd, fmdd, Bd, alphad, kpmcad, fcytd, ferd, sigmavd, ksercad, fd, vmdpqd, vmdld
    RANGE JLd, JPQd, Jmemd, Jsercad, Jleakd, Jerd, y, Som, JSS
}

PARAMETER{
    vcaa
    gcala
    tcalh1a (ms)
    tcalh2a (ms)
    vcalma (mV)
    scalma (mV)
    vcalha
    scalha
	tcapqh1a
    tcapqh2a
    vcapqma
    scapqma
    vcapqha
    scapqha
    gcapqa
    gcata
    vcatma
    scatma
    vcatha
    scatha
    tcatm1a
    tcatm2a
    tcath1a
    tcath2a
    gGIRKko
    vGIRK
    sombara2
    ssom2
    vc
    caerbara
    ssoca
    vsoca
    k1a
    km1a
    r1a
    rm1a
    r20a
    r30a
    rm3a
    u1a
    u2a
    u3a
    kpa
    kp2a
    GlucFacta
    vcella
    vmdpqa
    fVpqa
    fmda
    Ba
    alphaa
    kpmcaa
    fcyta
    fera
    pleaka
    sigmava
    fa
    gsocbara
    ksercaa
    tmsb
    knockoutda
    ra
    sombara
    rako
    ssom
    vka
    gkaa
    vkama
    skama
    vkaha
    skaha
    taukama
    tkah1a
    tkah2a
    ka1
    knockoutba
    gkatpbara
    vkdrma
    skdrma
    gkdra
    gla
    vla
    vnaa (mV)
    vnama
    vnaha
    snama
    snaha
    tnah1a
    tnah2a
    gnaa
    vm
    sm
    gca
    vca
    nca :dimensionless
    knockoutdb
    sombarb2
	gthresh
	sombarb
	ssomb
	rb
	vk
	fb
	Jgk
	factor
	gkatpb
	bas_r3
	amplify
	gkca (pS)
	k4
	gkatpbar
	kd
	raL
	kdd
	ktd
	ktt
	fcyt
	fer
	fmd
	kpmca
	cbas
	B
	per
	kserca3
	kserca2b
	sigmav
	vmd
	vcell
	alpha
	phigk
	KGPDH
	k1
	k2
	k3
	f13
	f43
	f23
	f42
	f41
	lambda
	taua
	VmaxPFK
	kappa
	Jgpdh_bas
	fmito
	gamma
	p21
	p22
	exo_k1
	bas_cmd
	p23
	p24
	Amtot
	NADmtot
	p1
	p2
	p3
	Cmito
	p17
	p18
	p4
	p5
	p6
	p7
	p8
	p9
	p10
	p11
	p13
	p14
	p15
	p16
	p19
	p20
	khyd
	JhydSS
	amp
	atot
	km1
	r1
	rm1
	r20
	r30
	rm3
	u1
	u2
	u3
	Kp
	Kp2
	max_cmd
	cmdp
	kcmd
	delta
    taun
    gk
    vn
    sn
    gcald
    vcalmd
    scalmd
    vcalhd
    scalhd
    tcalh1d
    tcalh2d
    gcapqd
    vcad
    scapqmd
    vcapqmd
    scapqhd
    vcapqhd
    tcapqh1d
    tcapqh2d
    knockoutbd
    vGABA
    gkad
    vkd
    vkamd
    skamd
    vkahd
    skahd
    taukamd
    tkah1d
    tkah2d
    gkatpbard 
    gkdrd
    vkdrmd
    skdrmd
    gld
    vld
    gnad
    vnad
    vnamd
    vnahd
    snamd
    snahd
    tnah1d
    tnah2d
    con
    bas
    tausom
    pleakd
    fVld
    fVpqd
    fmdd
    Bd
    alphad
    kpmcad
    fcytd
    ferd
    sigmavd
    ksercad
    fd
    vmdpqd
    vmdld
	cm
	cma
}

ASSIGNED{	
    taucalma
    taucalha
    mcalinfa
    hcalinfa
    icala
    mcapqinfa
    hcapqinfa
    taucapqma
    taucapqha
    icapqa
    mcatinfa
    hcatinfa
    taucatma
    taucatha
    icata
    gGIRKbara
    EffSa
    iGIRKa
    rm2a
    cinfa
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
    isoca
    mkainfa
    hkainfa
    taukaha
    ikaa
    EffIa
    gkatpa  
    ikatpa
    mkdrinfa
    taukdrma
    ikdra
    ila
    mnainfa
    hnainfa
    taunama
    taunaha
    inaa
    iCa
    gGIRKbarb
    EffSb
    iGIRKb
    ikca
    ikatp
    IcaL
    IcaR
    minf
    topo
    bottomo
    katpo
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

    weight1
    topa1
    bottom1
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
    rm2b
    ninf
    ikb
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
    gGABAbar
    EffId
    iGABA
    mkainfd
    hkainfd
    taukahd
    ikad
    ikatpd
    mkdrinfd
    taukdrmd
    ikdrd
    ild
    mnainfd
    hnainfd
    taunamd
    taunahd
    inad
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
    mcala
    hcala
    mcapqa
    hcapqa
    mcata
    hcata
    ca
    cmdpqa
    cera
    N1a
    N2a
    N3a
    N4a
    N5a
    N6a
    NFa
    NRa
    G
    mkaa
    hkaa
    mkdra
    mnaa
    hnaa
    n
    c
    cer
    cmd 
    g6p
    fbp
    ADPm
    cam
    NADHm
    Psim  
    adp
    N1
    N2
    N3
    N4
    N5
    N6 
    NF 
    NR
    I
    nb
    mcald
    hcald
    mcapqd
    hcapqd
    mkad
    hkad
    mkdrd
    mnad
    hnad
    cd
    cmdld
    cmdpqd
    cerd
    Sst
	vb
	va
	vd
}

INITIAL{
    mcala=0.1293341713632475  
    hcala=0.8127842536675057  
    vcaa=65
    gcala=0.7
    vcalma=-30
    scalma=10
    vcalha=-33
    scalha=-5
    tcalh1a=60 
    tcalh2a=51 
    mcapqa=0.0120465460803863  
    hcapqa=0.8127842536675057  
    vcaa=65
    vcapqma=-5
    scapqma=10
    vcapqha=-33
    scapqha=-5
    gcapqa=0.6
    tcapqh1a=60
    tcapqh2a=51
    mcata=0.4633857551023612  
    hcata=0.3735421388722815    
    vcaa=65
    gcata=0.5
    vcatma=-49
    scatma=4
    vcatha=-52
    scatha=-5
    tcatm1a=15
    tcatm2a=0
    tcath1a=20
    tcath2a=5
    knockoutda=0
    gGIRKko=0
    vGIRK=-80
    sombara2=35
    ssom2=10
    ca=0.3449148387259899  
    cmdpqa=11.51299890826233 
    cera=58.71698724650182
    N1a=1.057203539612775e-05
    N2a=2.113947666062938e-05  
    N3a=2.388848788981755e-05  
    N4a=2.391806975716259e-06  
    N5a=0.008850176609826538  
    N6a=12.69715161782077  
    NFa=0.001724142875712899  
    NRa=0.1927364884362762  
    G=31.73727470720019 
    vc = 1e-13
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
    fa= 150
    gsocbara=0.025
    ksercaa=0.5
    tmsb=0.001
    knockoutda=0
    ra=4.5
    sombara=50
    rako=0.001
    ssom=15
    mkaa=0.4001652246173745
    hkaa=0.1373195977592295  
    vka=-75
    gkaa=1
    vkama=-45
    skama=10
    vkaha=-68
    skaha=-10
    taukama=0.1
    tkah1a=60
    tkah2a=5
    gkatpbara=0.015 
    vka=-75 
    ka1=0.1
    knockoutba=0
    mkdra=0.2674634279865117 
    vkdrma=-25
    skdrma=23
    gkdra=4.5
    gla=0.2
    vla=-20
    mnaa=0.007938786735335676  
    hnaa=0.2498175179717122 
    vnaa=70
    vnama=-30
    vnaha=-52
    snama=4
    snaha=-8
    tnah1a=120
    tnah2a=0.5
    gnaa=11
    vm=-6
    sm=10
    gca=7
    vca=25
    nca=590
    knockoutdb=0
    vGIRK=-80
    sombarb2=35
	c=0.0630015242008439  
	cer=81.57023672312617  
	cmd=0.4188629403487558  
	g6p=244.936858732948  
	fbp=0.08283840527865462 
	ADPm=13.53015038508978  
	cam=0.01102007399722167 
	NADHm=0.02908310367935971 
	Psim=151.1015153147079  
	adp=1913.096601466651  
	N1=4.627586868810905  
	N2=0.2262327588817945  
	N3=0.003661670524646639  
	N4=2.595179480355916e-06  
	N5=7.762125378310579  
	N6=274.1666227230976  
	NF=0.00172689211245988  
	NR=0.3002686554719045  
	I=48.04298494148047

	gthresh=40
	sombarb=50
	ssomb=15
	rb=0.002 

	fb = 2000
	Jgk=0.4
	factor=14
	gkatpb=85

	bas_r3=0.032
	amplify=1
	gkca=280
	k4=150
	gkatpbar=7000
	kd=0.5
	raL=0.5
	vca=25
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
	r20=0.006
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
	delta=0.0733082707      :3.9/53.2
	vc = 1e-13
	knockoutdb=0
	vk=-75
    nb=9.875188779513991e-05
    taun=5
    gk=1800
    vn=-16
    sn=6
    mcald=0.8218051702003508  
    hcald=0.6672499701175263  
    gcald=700
    vcad=65
    vcalmd=-30
    scalmd=10
    vcalhd=-33
    scalhd=-5
    tcalh1d=60
    tcalh2d=51
    mcapqd=0.5089033026581684  
    hcapqd=0.6672499701175263  
    gcapqd=700
    vcad=65
    vcapqmd=-15
    scapqmd=10
    vcapqhd=-33
    scapqhd=-5
    tcapqh1d=60
    tcapqh2d=51
    knockoutbd=0
    vGABA=0
    mkad=0.9480884005315277 
    hkad=0.02771925786328598  
    gkad=500
    vkd=-75
    vkamd=-45
    skamd=10
    vkahd=-68
    skahd=-10
    taukamd=0.1
    tkah1d=60
    tkah2d=5
    gkatpbard=180
    mkdrd=0.5717652452166768 
    gkdrd=7500
    vkdrmd=-25
    skdrmd=23
    gld=200
    vld=-20
    mnad=0.9737137320580179  
    hnad=0.006777955247303555  
    gnad=5000
    vnad=70
    vnamd=-30
    vnahd=-52
    snamd=4
    snahd=-8
    tnah1d=120
    tnah2d=0.5
    cd=0.3051356309084454  
    cmdld=19.82903375122306  
    cmdpqd=27.93917378868966  
    cerd=413.8135591677398  
    Sst=18.71318922819339
    con=0.00000000594
    bas=0.0009
    vc = 1e-13
    tmsb=0.001
    tausom=2000
    pleakd=0.0003
    fVld=0.00340
    fVpqd=0.00226
    fmdd=0.01
    Bd=1 
    alphad=5.18e-15
    kpmcad=0.3
    fcytd=0.01
    ferd=0.01
    sigmavd=31
    ksercad=0.4
    fd= 0.003
    vmdpqd=1.41e-15
    vmdld=2.12e-15
	vb=-71.33779976819424
	va=-49.03736299581227
	vd=-16.26895428994972 
	cm=5300
	cma=5
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    taucalma=(1/(exp(-(va+23)/20)+exp((va+23)/20)))+0.05
    taucalha=(tcalh1a/(exp(-(va+0)/20)+exp((va+0)/20)))+tcalh2a
    mcalinfa=1/(1+exp(-(va-vcalma)/scalma))
    hcalinfa=1/(1+exp(-(va-vcalha)/scalha))
    icala=gcala*(mcala^2)*hcala*(va-vcaa)
    mcapqinfa=1/(1+exp(-(va-vcapqma)/scapqma))
    hcapqinfa=1/(1+exp(-(va-vcapqha)/scapqha))
    taucapqma=(1/(exp(-(va+23)/20)+exp((va+23)/20)))+0.05
    taucapqha=(tcapqh1a/(exp(-(va+0)/20)+exp((va+0)/20)))+tcapqh2a
    icapqa=gcapqa*mcapqa*hcapqa*(va-vcaa)
    mcatinfa=1/(1+exp(-(va-vcatma)/scatma))
    hcatinfa=1/(1+exp(-(va-vcatha)/scatha))
    taucatma=(tcatm1a/(exp(-(va+50)/12)+exp((va+50)/12)))+tcatm2a
    taucatha=(tcath1a/(exp(-(va+50)/15)+exp((va+50)/15)))+tcath2a
    icata=gcata*(mcata^3)*hcata*(va-vcaa)
    gGIRKbara=(1-knockoutda)*0.025+knockoutda*gGIRKko
    EffSa=1/(1+exp(-(Sst-sombara2)/ssom2))
    iGIRKa=gGIRKbara*EffSa*(va-vGIRK)
    rm2a=(1-knockoutda)*ra/(1+exp(-(Sst-sombara)/ssom))+knockoutda*rako
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
    JGS=tmsb*u3a*NRa*0.0000988
    mkainfa=1/(1+exp(-(va-vkama)/skama))
    hkainfa=1/(1+exp(-(va-vkaha)/skaha))
    taukaha=(tkah1a/(exp(-(va-5)/20)+exp((va-5)/20)))+tkah2a
    ikaa=gkaa*mkaa*hkaa*(va-vka)
    EffIa=(1-knockoutba)*((0.015/(1+exp((-I+1500)/200)))+ka1)+knockoutba*ka1
    gkatpa=gkatpbara*EffIa
    ikatpa=gkatpa*(va-vka)
    mkdrinfa=1/(1+exp(-(va-vkdrma)/skdrma))
    taukdrma=(1.5/(exp(-(va+10)/25)+exp((va+10)/25)))+15
    ikdra=gkdra*(mkdra^4)*(va-vka)
    ila=gla*(va-vla)
    mnainfa=1/(1+exp(-(va-vnama)/snama))
    hnainfa=1/(1+exp(-(va-vnaha)/snaha))
    taunama=(6/(exp(-(va+50)/10)+exp((va+50)/10)))+0.05
    taunaha=(tnah1a/(exp(-(va+50)/8)+exp((va+50)/8)))+tnah2a
    inaa=gnaa*(mnaa^3)*hnaa*(va-vnaa)
    minf = 1/(1+exp((vm-vb)/sm))
    iCa = gca*nca*minf*(vb-vca)
    gGIRKbarb=(1-knockoutdb)*10+knockoutdb*0
    EffSb=1/(1+exp(-(Sst-sombarb2)/10))
    iGIRKb=gGIRKbarb*EffSb*(vb-vGIRK)
    r20=0.004/(1+exp(-G+gthresh))+0.006
    rm2b=(1-knockoutdb)*rb/(1+exp(-(Sst-sombarb)/ssomb))+knockoutdb*0.001
    ikca = gkca/(1+(kd/c)^2)*(vb-vk)
    IcaL = raL*iCa
    IcaR = (1-raL)*iCa
    topo = 0.08*(1+2*mgadp/kdd) + 0.89*(mgadp/kdd)^2
    bottomo = (1+mgadp/kdd)^2 * (1+adp3m/ktd+atp4m/ktt)
    katpo = (topo/bottomo)
    ikatp = gkatpb*(vb-vk)
    vmdcyt=vmd/vcell
    JL = -alpha*IcaL/vmd
    JR = -alpha*IcaR/vcell
    Jmem = JR+vmdcyt*B*(cmd-c)-kpmca*(c-cbas)
    Jserca = kserca2b+kserca3*c
    Jleak = per*(cer - c)
    Jer = (Jleak - Jserca)
    f6p = phigk*g6p
    Jgpdh = KGPDH*sqrt(fbp) 
    Jgk_ms=kappa*Jgk
    mod_cmd=bas_cmd + max_cmd*cmd^cmdp/(cmd^cmdp+kcmd^cmdp)
    weight1=1
    topa1=0
    bottom1=1
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
    Juni=(p21*Psim-p22)*c^2
    JNaCa=(p23/c)*cam*exp(p24*Psim)
    Jmito=JNaCa-Juni
    NADm=NADmtot-NADHm
    ATPm=Amtot-ADPm
    RATm=ATPm/ADPm
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

    JIS=tmsb*u3*NR*0.0016
    ninf = 1/(1+exp((vn-vb)/sn))
    ikb = gk*nb*(vb-vk)
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
    gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0
    EffId = 800/(1+exp(-(I-1500)/500))
    iGABA = gGABAbar*EffId*(vd-vGABA)
    mkainfd=1/(1+exp(-(vd-vkamd)/skamd))
    hkainfd=1/(1+exp(-(vd-vkahd)/skahd))
    taukahd=(tkah1d/(exp(-(vd-5)/20)+exp((vd-5)/20)))+tkah2d
    ikad=gkad*mkad*hkad*(vd-vkd)
    ikatpd=gkatpbard*(vd-vkd)
    mkdrinfd=1/(1+exp(-(vd-vkdrmd)/skdrmd))
    taukdrmd=(1.5/(exp(-(vd+10)/25)+exp((vd+10)/25)))+15
    ikdrd=gkdrd*mkdrd^4*(vd-vkd)
    ild=gld*(vd-vld)
    mnainfd=1/(1+exp(-(vd-vnamd)/snamd))
    hnainfd=1/(1+exp(-(vd-vnahd)/snahd))
    taunamd=(6/(exp(-(vd+50)/10)+exp((vd+50)/10)))+0.05
    taunahd=(tnah1d/(exp(-(vd+50)/8)+exp((vd+50)/8)))+tnah2d
    inad=gnad*mnad^3*hnad*(vd-vnad)
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
    mcala'=(mcalinfa-mcala)/taucalma
    hcala'=(hcalinfa-hcala)/taucalha
    mcapqa'=(mcapqinfa-mcapqa)/taucapqma
    hcapqa'=(hcapqinfa-hcapqa)/taucapqha
    mcata'=(mcatinfa-mcata)/taucatma
    hcata'=(hcatinfa-hcata)/taucatha
    ca'= fcyta*(Jmema+Jera)
    cmdpqa'=fmda*JPQa-fmda*Ba*(cmdpqa-ca)
    cera'= -fera*sigmava*Jera
    N1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*N1a + km1a*N2a + r1a*N5a)
    N2a' = tmsb*(3*k1a*cmdpqa*N1a -(2*k1a*cmdpqa + km1a)*N2a + 2*km1a*N3a)
    N3a' = tmsb*(2*k1a*cmdpqa*N2a -(2*km1a + k1a*cmdpqa)*N3a + 3*km1a*N4a)
    N4a' = tmsb*(k1a*cmdpqa*N3a - (3*km1a + u1a)*N4a)
    N5a' = tmsb*(rm1a*N1a - (r1a + rm2a)*N5a + r2a*N6a)
    N6a' = tmsb*(r3a + rm2a*N5a - (rm3a + r2a)*N6a)
    NFa' = tmsb*(u1a*N4a - u2a*NFa)
    NRa' = tmsb*(u2a*NFa - u3a*NRa)
    G'=JGS/vc-fa*G
    mkaa'=(mkainfa-mkaa)/taukama
    hkaa'=(hkainfa-hkaa)/taukaha
    mkdra'=(mkdrinfa-mkdra)/taukdrma
    mnaa'=(mnainfa-mnaa)/taunama
    hnaa'=(hnainfa-hnaa)/taunaha
    c' = fcyt*(Jmem + Jer + delta*Jmito)
    cer' = -fer*sigmav*Jer
    cmd' = fmd*(JL-B*(cmd-c)) 
    g6p' = Jgk_ms - pfk_ms
    fbp' = pfk_ms - 0.5*Jgpdh 
    ADPm'= gamma*(Jant-JF1F0)
    cam' = -fmito*Jmito
    NADHm' = gamma*(Jpdh-JO)
    Psim'=(JHres-JHatp-Jant-JHleak-JNaCa-2*Juni)/Cmito
    adp' = (-delta*Jant + Jhyd)/taua
    N1' = tmsb*(-(3*exo_k1*mod_cmd + rm1)*N1 + km1*N2 + r1*N5)
    N2' = tmsb*(3*exo_k1*mod_cmd*N1 -(2*exo_k1*mod_cmd + km1)*N2 + 2*km1*N3)
    N3' = tmsb*(2*exo_k1*mod_cmd*N2 -(2*km1 + exo_k1*mod_cmd)*N3 + 3*km1*N4)
    N4' = tmsb*(exo_k1*mod_cmd*N3 - (3*km1 + u1)*N4)
    N5' = tmsb*(rm1*N1 - (r1 + rm2b)*N5 + r2*N6)
    N6' = tmsb*(r3 + rm2b*N5 - (rm3 + r2)*N6)
    NF' = tmsb*(u1*N4 - u2*NF)
    NR' = tmsb*(u2*NF - u3*NR)
    I'=JIS/vc-fb*I
    nb' = (ninf-nb)/taun
    mcald'=(mcalinfd-mcald)/taucalmd
    hcald'=(hcalinfd-hcald)/taucalhd
    mcapqd'=(mcapqinfd-mcapqd)/taucapqmd
    hcapqd'=(hcapqinfd-hcapqd)/taucapqhd
    mkad'=(mkainfd-mkad)/taukamd
    hkad'=(hkainfd-hkad)/taukahd
    mkdrd'=(mkdrinfd-mkdrd)/taukdrmd
    mnad'=(mnainfd-mnad)/taunamd
    hnad'=(hnainfd-hnad)/taunahd
    cd' = fcytd*(Jmemd+Jerd) 
    cmdld'=fmdd*JLd-fmdd*Bd*(cmdld-cd)
    cmdpqd'=fmdd*JPQd-fmdd*Bd*(cmdpqd-cd)
    cerd' = -ferd*sigmavd*Jerd
    Sst'=JSS/vc-fd*Sst
	vb' = -(ikb + iCa + ikca + ikatp+iGIRKb)/cm 
	va'=-(icala+icata+icapqa+inaa+ikdra+ikatpa+ikaa+ila+isoca+iGIRKa)/cma
	vd'=-(icald+icapqd+inad+ikdrd+ikatpd+ikad+ild+iGABA)/cma
}