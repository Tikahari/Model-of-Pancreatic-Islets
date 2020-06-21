NEURON{
SUFFIX A_Glucagon
USEION CaPQ READ iCaPQ
USEION CaT READ iCaT
USEION CaL READ iCaL
RANGE alphaa, Ba, fcyta, fVpqa, tmsb, vcella, vmdpq, kpmcaa, ksercaa, pleaka, fera, sigmava, fmda, k1a, km1a, r1a, rm1a, r20a, r30a, rm3a, u1a, u2a, u3a, kpa, kp2a, GlucFacta, knockoutda, ra, sombara, rako, ssom, fa, vc, caerbara, ssoca, vsoca, gsocbara, G_init 
RANGE iCaPQ, iCaT, iCaL, JPQ, JTa, JLa, Jera, rm2a, r2a, r3a, Jsercaa, Jleaka, Jmema, JGS, cinfa, isoca
RANGE Sst, Ins
RANGE t_, dir
}

PARAMETER{
: hormone secretion variables
t_
dir
Ins
alphaa 
Ba 
fcyta 
fVpqa 
tmsb 
vcella
vmdpq 
kpmcaa 
ksercaa 
pleaka 
fera 
sigmava 
fmda 
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
knockoutda 
ra 
sombara 
rako 
ssom 
fa 
vc 
caerbara 
ssoca 
gsocbara
vsoca 
G_init
}

ASSIGNED{
iCaPQ
iCaT
iCaL
JPQ
JTa
JLa
Jera
rm2a
r2a 
r3a 
Jsercaa
Jleaka 
Jmema 
JGS 
cinfa
isoca
Sst
v
}

STATE{
ca
cera
cmdpqa
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
t_ = 0
dir = 0
}

BREAKPOINT{
if (t_ > 2){
dir = 1
}
else if (t_ == 0){
dir = 0
}
if (dir == 0){
t_ = t_ + 1
}
else{
t_ = t_ - 1
}
JPQ = -alphaa*iCaPQ / vmdpq
JTa = -alphaa*iCaT/vcella
JLa = -alphaa*iCaL/vcella
rm2a=(1-knockoutda)*ra/(1+exp(-(Sst-sombara)/ssom))+knockoutda*rako :Delta inhibiting alphaa by Sst increasing the rate of depriming of G granules.
SOLVE states METHOD cnexp
r2a = r20a*ca/(ca+kp2a)
r3a = GlucFacta*r30a*ca/(ca+kpa)
Jsercaa = ksercaa*ca
Jleaka = pleaka*(cera - ca)
Jera = Jleaka - Jsercaa
Jmema = JTa+JLa+fVpqa*Ba*(cmdpqa-ca)-kpmcaa*ca
JGS = tmsb*u3a*NRa*0.0000988
cinfa = 1/(1 + exp(-(cera - caerbara)/ssoca))
isoca = gsocbara * cinfa * (v - vsoca)
}

DERIVATIVE states{
ca'= fcyta*(Jmema+Jera)
cera'= -fera*sigmava*Jera
cmdpqa' = fmda*JPQ-fmda*Ba*(cmdpqa-ca)
N1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*N1a + km1a*N2a + r1a*N5a)
N2a' = tmsb*(3*k1a*cmdpqa*N1a -(2*k1a*cmdpqa + km1a)*N2a + 2*km1a*N3a)
N3a' = tmsb*(2*k1a*cmdpqa*N2a -(2*km1a + k1a*cmdpqa)*N3a + 3*km1a*N4a)
N4a' = tmsb*(k1a*cmdpqa*N3a - (3*km1a + u1a)*N4a)
N5a' = tmsb*(rm1a*N1a - (r1a + rm2a)*N5a + r2a*N6a)
N6a' = tmsb*(r3a + rm2a*N5a - (rm3a + r2a)*N6a)
NFa' = tmsb*(u1a*N4a - u2a*NFa)
NRa' = tmsb*(u2a*NFa - u3a*NRa)
G' = JGS/vc-fa*G_init
}
