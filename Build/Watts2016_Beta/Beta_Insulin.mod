NEURON{
    POINT_PROCESS B_Insulin
    USEION Ca READ iCa
    USEION kca WRITE ikca VALENCE 1
    USEION glucagon READ glucagoni VALENCE 1
    USEION sst READ ssti VALENCE 1
    RANGE gthresh,sombarb,ssomb,rb,fb,Jgk,factor,gkatpb,bas_r3,amplify,cm,gkca,k4,gkatpbar,kd,nca,raL,vca,vm,sm,gca,vk,kdd,ktd,ktt,fcyt,fer,fmd,kpmca,cbas,B,per,kserca3,kserca2b,sigmav,vmd,vcell,alpha,phigk,KGPDH,k1,k2,k3,f13,f43,f23,f42,f41,lambda,taua,VmaxPFK,kappa,Jgpdh_bas,fmito,gamma,p21,p22,exo_k1,bas_cmd,p23,p24,Amtot,NADmtot
    RANGE p1,p2,p3,Cmito,p17,p18,p4,p5,p6,p7,p8,p9,p10,p11,p13,p14,p15,p16,p19,p20,khyd,JhydSS,amp,atot,km1,r1,rm1,r30,rm3,u1,u2,u3,Kp,Kp2,tmsb,max_cmd,cmdp,kcmd,delta,vc,knockoutdb,vGIRK
    RANGE gGIRKbarb,EffSb,r20,minf,IcaL,IcaR,ninf,topo,bottomo,katpo,vmdcyt,JL,JR,Jmem,Jserca,Jleak,Jer,f6p,Jgpdh,Jgk_ms,mod_cmd,weight1,topa1,bottom1,weight2,topa2,bottom2,weight3,topa3,bottom3,weight4,topa4,bottom4,weight5,topa5,bottom5,weight6,topa6,bottom6,weight7,topa7,bottom7,weight8,topa8,bottom8,weight9,topa9,bottom9,weight10,topa10,bottom10,weight11,topa11,bottom11,weight12,topa12,bottom12,weight13,topa13,bottom13,weight14,topa14
    RANGE bottom14,weight15,topa15,topb,bottom15,weight16,topa16,bottom16,pfk,pfk_ms,Juni,JNaCa,Jmito,NADm,ATPm,RATm,Jpdh,JHleak,MM1,JO,MM2,JHres,b2,JF1F0,JHatp,FRT,Jant,atp,Jhyd,mgadp,adp3m,atp4m,ampfactor,r3,r2,JIS,rm2b
    RANGE iCa, ikca, ikatp
    RANGE Sst, G
    POINTER Inspnt
}

UNITS{
    (mV) = (millivolt)
    (ms) = (milliseconds)
    (molar) = (1/liter)
    (uM) = (micromolar)
    (pM) = (picomolar)
    (s) = (seconds)
 }

PARAMETER{
Inspnt
glucagoni
ssti
Sst (pM)
G   (pM)
gthresh
sombarb
ssomb
rb  (/s)
vk
fb      :dimensionless
Jgk (uM/ms)
factor
gkatpb
bas_r3
amplify
cm
gkca
k4
gkatpbar
kd
nca
raL
vca
vm
sm
gca
kdd
ktd
ktt
fcyt
fer
fmd
kpmca   (/ms)
cbas
B   (/ms)
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
:r20
r30
rm3
u1
u2
u3
Kp
Kp2
tmsb
max_cmd
cmdp
kcmd
delta
vc
knockoutdb
}

ASSIGNED{
    gGIRKbarb
    EffSb
    r20
    iCa
    ikca
    ikatp
    IcaL
    IcaR
    minf
    ninf
    Ik
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
    v   (mV)
}

STATE{
    n
    c   (uM)
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
    I   (pM)
}

INITIAL{
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
I=1500

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
cm=5300
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
:r20=0.006
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
delta=3.9/53.2
vc = 1e-13
knockoutdb=0
vk=-75
}

BREAKPOINT{
SOLVE states METHOD cnexp
Inspnt = I
Sst = ssti
G = glucagoni

r20=0.004/(1+exp(-G+gthresh))+0.006
rm2b=(1-knockoutdb)*rb/(1+exp(-(Sst-sombarb)/ssomb))+knockoutdb*0.001
ikca = gkca/(1+(kd/c)^2)*(v-vk)
IcaL = raL*iCa
IcaR = (1-raL)*iCa
topo = 0.08*(1+2*mgadp/kdd) + 0.89*(mgadp/kdd)^2
bottomo = (1+mgadp/kdd)^2 * (1+adp3m/ktd+atp4m/ktt)
katpo = (topo/bottomo)
ikatp = gkatpb*(v-vk)
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
}

DERIVATIVE states{
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
}