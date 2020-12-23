NEURON{
    SUFFIX watts_delta
    RANGE knockoutbd,vGABA,fd,gkatpbard,vnad,vkd,vcad,vld,gcald,gcapqd,gnad,gkad,gkdrd,gld,vcelld,vmdpqd,vmdld,fVld,fVpqd,fmdd,Bd,alphad,kpmcad,fcytd,ferd,pleakd,sigmavd,ksercad,vcalmd,scalmd,vcalhd
    RANGE scalhd,tcalh1d,tcalh2d,vcapqmd,scapqmd,vcapqhd,scapqhd,tcapqh1d,tcapqh2d,vnamd,vnahd,snamd,snahd,tnah1d,tnah2d,vkamd,skamd,vkahd,skahd,taukamd,tkah1d,tkah2d,vkdrmd,skdrmd,con,bas,cma,vc,tmsb,tausom
    RANGE gGABAbar,EffId,IGABA,mcalinfd,hcalinfd,taucalmd,taucalhd,Icald,mcapqinfd,hcapqinfd,taucapqmd,taucapqhd,Icapqd,mnainfd,hnainfd,taunamd,taunahd,Inad,mkainfd,hkainfd,taukahd,Ikad,mkdrinfd,taukdrmd,Ikdrd,Ikatpd,Ild,JLd,JPQd,Jmemd,Jsercad,Jleakd,Jerd,y,Som,JSS
    RANGE I,G
}

PARAMETER{
I
G    
knockoutbd
vGABA

fd
gkatpbard

vnad
vkd
vcad
vld
gcald
gcapqd
gnad
gkad
gkdrd
gld
vcelld
vmdpqd
vmdld
fVld
fVpqd
fmdd
Bd
alphad
kpmcad
fcytd
ferd
pleakd
sigmavd
ksercad
vcalmd
scalmd
vcalhd
scalhd
tcalh1d
tcalh2d
vcapqmd
scapqmd
vcapqhd
scapqhd
tcapqh1d
tcapqh2d
vnamd
vnahd
snamd
snahd
tnah1d
tnah2d
vkamd
skamd
vkahd
skahd
taukamd
tkah1d
tkah2d
vkdrmd
skdrmd
con
bas
cma
vc
tmsb
tausom
}

ASSIGNED{
gGABAbar
EffId
IGABA

mcalinfd
hcalinfd
taucalmd
taucalhd
Icald
mcapqinfd
hcapqinfd
taucapqmd
taucapqhd
Icapqd
mnainfd
hnainfd
taunamd
taunahd
Inad
mkainfd
hkainfd
taukahd
Ikad
mkdrinfd
taukdrmd
Ikdrd
Ikatpd
Ild
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
S=18.71318922819339

knockoutbd=0
vGABA=0

fd= 0.003
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
vcelld=0.624e-12
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
cma=5
vc = 1e-13
tmsb=0.001
tausom=2000
taucalmd = 0.5
taucalhd = 0.5
taucapqmd = 0.5
taucapqhd = 0.5
taunamd = 0.5
taunahd = 0.5
taukahd = 0.5
taukdrmd = 0.5
}

BREAKPOINT{
SOLVE states METHOD cnexp

gGABAbar=(1-knockoutbd)*0.1+knockoutbd*0
EffId = 0.8/(1+exp(-(I-1500)/500))
IGABA = gGABAbar*EffId*(vd-vGABA)

mcalinfd=1/(1+exp(-(vd-vcalmd)/scalmd))
hcalinfd=1/(1+exp(-(vd-vcalhd)/scalhd))
taucalmd=(1/(exp(-(vd+23)/20)+exp((vd+23)/20)))+0.05
taucalhd=(tcalh1d/(exp(-(vd+0)/20)+exp((vd+0)/20)))+tcalh2d
Icald=gcald*mcald^2*hcald*(vd-vcad)
mcapqinfd=1/(1+exp(-(vd-vcapqmd)/scapqmd))
hcapqinfd=1/(1+exp(-(vd-vcapqhd)/scapqhd))
taucapqmd=(1/(exp(-(vd+23)/20)+exp((vd+23)/20)))+0.05
taucapqhd=(tcapqh1d/(exp(-(vd+0)/20)+exp((vd+0)/20)))+tcapqh2d
Icapqd=gcapqd*mcapqd*hcapqd*(vd-vcad)
mnainfd=1/(1+exp(-(vd-vnamd)/snamd))
hnainfd=1/(1+exp(-(vd-vnahd)/snahd))
taunamd=(6/(exp(-(vd+50)/10)+exp((vd+50)/10)))+0.05
taunahd=(tnah1d/(exp(-(vd+50)/8)+exp((vd+50)/8)))+tnah2d
Inad=gnad*mnad^3*hnad*(vd-vnad)
mkainfd=1/(1+exp(-(vd-vkamd)/skamd))
hkainfd=1/(1+exp(-(vd-vkahd)/skahd))
taukahd=(tkah1d/(exp(-(vd-5)/20)+exp((vd-5)/20)))+tkah2d
Ikad=gkad*mkad*hkad*(vd-vkd)
mkdrinfd=1/(1+exp(-(vd-vkdrmd)/skdrmd))
taukdrmd=(1.5/(exp(-(vd+10)/25)+exp((vd+10)/25)))+15
Ikdrd=gkdrd*mkdrd^4*(vd-vkd)
Ikatpd=gkatpbard*(vd-vkd)
Ild=gld*(vd-vld)
JLd=-alphad*Icald/vmdld
JPQd=-alphad*Icapqd/vmdpqd
Jmemd = fVld*Bd*(cmdld-cd)+fVpqd*Bd*(cmdpqd-cd)-kpmcad*cd
Jsercad = ksercad*cd
Jleakd = pleakd*(cerd - cd)
Jerd = (Jleakd - Jsercad)
y=(cmdpqd/200)^4/(0.2^4+(cmdpqd/200)^4)
Som=(200*mcapqd*hcapqd*(y)/tausom)+bas
JSS=tmsb*Som*con

}

DERIVATIVE states{
vd'=-(Icald+Icapqd+Inad+Ikdrd+Ikatpd+Ikad+Ild+IGABA)/cma
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