NEURON{
SUFFIX watts_alpha_v
:NONSPECIFIC_CURRENT i
USEION cala WRITE icala VALENCE 2
USEION cata WRITE icata VALENCE 2
USEION capqa WRITE icapqa VALENCE 2
USEION naa WRITE inaa VALENCE 1
USEION kdra WRITE ikdra VALENCE 1
USEION katpa WRITE ikatpa VALENCE 1
USEION kaa WRITE ikaa VALENCE 1
USEION la WRITE ila VALENCE 1
USEION soca WRITE isoca VALENCE 2
USEION GIRKa WRITE iGIRKa VALENCE 1
RANGE  fa,gsocbara,ksercaa,vnaa,vka,vcaa,vla,cma,gcala,gcapqa,gcata,gnaa,gkaa,gkdra,gla,vcella,vmdpqa,fVpqa,fmda,Ba,alphaa,kpmcaa,fcyta,fera,pleaka,sigmava,vcalma,scalma,vcalha,scalha,tcalh1a,tcalh2a,vcatma,scatma,vcatha,scatha,tcatm1a,tcatm2a,tcath1a,tcath2a,vcapqma,scapqma,vcapqha
RANGE  scapqha,tcapqh1a,tcapqh2a,vnama,vnaha,snama,snaha,tnah1a,tnah2a,vkama,skama,vkaha,skaha,taukama,tkah1a,tkah2a,vkdrma,skdrma,caerbara,ssoca,vsoca,k1a,km1a,r1a,rm1a,r20a,r30a,rm3a,u1a,u2a,u3a,kpa,kp2a,GlucFacta,gGIRKko,vGIRK,sombara2,ssom2,tausom,vc,gkatpbara,ka1,gkatpak,knockoutba,knockoutda
RANGE  Icala,gkatpa,Ikatpa,gGIRKbara,EffSa,IGIRKa,rm2a,mcalinfa,hcalinfa,taucalma,taucalha,mcatinfa,hcatinfa,taucatma,taucatha,Icata,mcapqinfa,hcapqinfa,taucapqma,taucapqha,Icapqa,mnainfa,hnainfa,taunama,taunaha,Inaa,mkainfa,hkainfa,taukaha,Ikaa,mkdrinfa,taukdrma,Ikdra,Ila,cinfa,Isoca,JLa,JPQa,JTa,Jmema,Jsercaa,Jleaka,Jera,r2a,r3a,JGS
RANGE  I,S
}

PARAMETER{
 I
 S
 fa
 gsocbara
 ksercaa
 vnaa
 vka
 vcaa
 vla
 cma
 gcala
 gcapqa
 gcata
 gnaa
 gkaa
 gkdra
 gla
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
 vcalma
 scalma
 vcalha
 scalha
 tcalh1a
 tcalh2a
 vcatma
 scatma
 vcatha
 scatha
 tcatm1a
 tcatm2a
 tcath1a
 tcath2a
 vcapqma
 scapqma
 vcapqha
 scapqha
 tcapqh1a
 tcapqh2a
 vnama
 vnaha
 snama
 snaha
 tnah1a
 tnah2a
 vkama
 skama
 vkaha
 skaha
 taukama
 tkah1a
 tkah2a
 vkdrma
 skdrma
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
 gGIRKko
 vGIRK
 sombara2
 ssom2
 tausom
 vc
 gkatpbara
 ka1
 gkatpak
 knockoutba
 knockoutda
 ra
 sombara
 rako
 ssom
 tmsb
}

ASSIGNED{
EffIa
gkatpa
Ikatpa

gGIRKbara
EffSa
IGIRKa

rm2a
Icala
mcalinfa
hcalinfa
taucalma
taucalha
mcatinfa
hcatinfa
taucatma
taucatha
Icata
mcapqinfa
hcapqinfa
taucapqma
taucapqha
Icapqa
mnainfa
hnainfa
taunama
taunaha
Inaa
mkainfa
hkainfa
taukaha
Ikaa
mkdrinfa
taukdrma
Ikdra
Ila
cinfa
Isoca
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
icala
icata
icapqa
inaa
ikdra
ikatpa
ikaa
ila
isoca
iGIRKa
}

STATE{
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
N1a
N2a
N3a
N4a
N5a
N6a
NFa
NRa
G
}

INITIAL{
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
N1a=1.057203539612775e-05
N2a=2.113947666062938e-05  
N3a=2.388848788981755e-05  
N4a=2.391806975716259e-06  
N5a=0.008850176609826538  
N6a=12.69715161782077  
NFa=0.001724142875712899  
NRa=0.1927364884362762  

I=48.04298494148047  
G=31.73727470720019 
S=18.71318922819339  



fa= 150
gsocbara=25
ksercaa=0.5
vnaa=70
vka=-75
vcaa=65
vla=-20
cma=5
gcala=700
gcapqa=600
gcata=500
gnaa=11000
gkaa=1000
gkdra=4500
gla=200
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
gGIRKko=0
vGIRK=-80
sombara2=35
ssom2=10
tausom=2000
vc = 1e-13
gkatpbara=600
ka1=0.1
gkatpak=0.05
knockoutba=0
knockoutda=0
ra=4.5
sombara=50
rako=0.001
ssom=15
tmsb=0.001
taucalma = 0.5
taucalha = 0.5
taucatma = 0.5
taucatha = 0.5
taucapqma = 0.5
taucapqha = 0.5
taunama = 0.5
taunaha = 0.5
taukaha = 0.5
taukdrma = 0.5
 
}

BREAKPOINT{
SOLVE states METHOD cnexp

icala = Icala
icata = Icata
icapqa = Icapqa
inaa = Inaa
ikdra = Ikdra
ikatpa = Ikatpa
ikaa = Ikaa
ila = Ila
isoca = Isoca
iGIRKa = IGIRKa


EffIa=(1-knockoutba)*((0.015/(1+exp((-I+1500)/200)))+ka1)+knockoutba*ka1
gkatpa=gkatpbara*EffIa
Ikatpa=gkatpa*(v-vka)

gGIRKbara=(1-knockoutda)*0.025+knockoutda*gGIRKko
EffSa=1000/(1+exp(-(S-sombara2)/ssom2))
IGIRKa=gGIRKbara*EffSa*(v-vGIRK)

rm2a=(1-knockoutda)*ra/(1+exp(-(S-sombara)/ssom))+knockoutda*rako
mcalinfa=1/(1+exp(-(v-vcalma)/scalma))
hcalinfa=1/(1+exp(-(v-vcalha)/scalha))
taucalma=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
taucalha=(tcalh1a/(exp(-(v+0)/20)+exp((v+0)/20)))+tcalh2a
Icala=gcala*(mcala^2)*hcala*(v-vcaa)
mcatinfa=1/(1+exp(-(v-vcatma)/scatma))
hcatinfa=1/(1+exp(-(v-vcatha)/scatha))
taucatma=(tcatm1a/(exp(-(v+50)/12)+exp((v+50)/12)))+tcatm2a
taucatha=(tcath1a/(exp(-(v+50)/15)+exp((v+50)/15)))+tcath2a
Icata=gcata*(mcata^3)*hcata*(v-vcaa)
mcapqinfa=1/(1+exp(-(v-vcapqma)/scapqma))
hcapqinfa=1/(1+exp(-(v-vcapqha)/scapqha))
taucapqma=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
taucapqha=(tcapqh1a/(exp(-(v+0)/20)+exp((v+0)/20)))+tcapqh2a
Icapqa=gcapqa*mcapqa*hcapqa*(v-vcaa)
mnainfa=1/(1+exp(-(v-vnama)/snama))
hnainfa=1/(1+exp(-(v-vnaha)/snaha))
taunama=(6/(exp(-(v+50)/10)+exp((v+50)/10)))+0.05
taunaha=(tnah1a/(exp(-(v+50)/8)+exp((v+50)/8)))+tnah2a
Inaa=gnaa*(mnaa^3)*hnaa*(v-vnaa)
mkainfa=1/(1+exp(-(v-vkama)/skama))
hkainfa=1/(1+exp(-(v-vkaha)/skaha))
taukaha=(tkah1a/(exp(-(v-5)/20)+exp((v-5)/20)))+tkah2a
Ikaa=gkaa*mkaa*hkaa*(v-vka)
mkdrinfa=1/(1+exp(-(v-vkdrma)/skdrma))
taukdrma=(1.5/(exp(-(v+10)/25)+exp((v+10)/25)))+15
Ikdra=gkdra*(mkdra^4)*(v-vka)
Ila=gla*(v-vla)
cinfa = 1/(1+exp(-(cera-caerbara)/ssoca))
Isoca = gsocbara*cinfa*(v-vsoca)
JLa=-alphaa*Icala/vcella
JPQa=-alphaa*Icapqa/vmdpqa
JTa=-alphaa*Icata/vcella
Jmema = JTa+JLa+fVpqa*Ba*(cmdpqa-ca)-kpmcaa*ca
Jsercaa = ksercaa*ca
Jleaka = pleaka*(cera - ca)
Jera = Jleaka - Jsercaa
r2a=r20a*ca/(ca+kp2a)
r3a=GlucFacta*r30a*ca/(ca+kpa)
JGS=tmsb*u3a*NRa*0.0000988
}

DERIVATIVE states{
va'=-(Icala+Icata+Icapqa+Inaa+Ikdra+Ikatpa+Ikaa+Ila+Isoca+IGIRKa)/cma
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
N1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*N1a + km1a*N2a + r1a*N5a)
N2a' = tmsb*(3*k1a*cmdpqa*N1a -(2*k1a*cmdpqa + km1a)*N2a + 2*km1a*N3a)
N3a' = tmsb*(2*k1a*cmdpqa*N2a -(2*km1a + k1a*cmdpqa)*N3a + 3*km1a*N4a)
N4a' = tmsb*(k1a*cmdpqa*N3a - (3*km1a + u1a)*N4a)
N5a' = tmsb*(rm1a*N1a - (r1a + rm2a)*N5a + r2a*N6a)
N6a' = tmsb*(r3a + rm2a*N5a - (rm3a + r2a)*N6a)
NFa' = tmsb*(u1a*N4a - u2a*NFa)
NRa' = tmsb*(u2a*NFa - u3a*NRa)
G'=JGS/vc-fa*G
}