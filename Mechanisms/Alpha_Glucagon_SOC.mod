NEURON{
SUFFIX A_Glucagon_SOC
USEION CaPQ READ iCaPQ
USEION CaT READ iCaT
USEION CaL READ iCaL
RANGE alphaa, Ba, fcyta, fVpqa, tmsb, vcella, vmdpq, kpmcaa, ksercaa, pleaka, fera, sigmava, fmda, k1a, km1a, r1a, rm1a, r20a, r30a, rm3a, u1a, u2a, u3a, kpa, kp2a, GlucFacta, knockoutda, ra, sombara, rako, ssom, fa, vc, caerbara, ssoca, vsoca, gsocbara, G_init 
RANGE iCaPQ, iCaT, iCaL, JPQ, JTa, JLa, Jera, rm2a, r2a, r3a, Jsercaa, Jleaka, Jmema, JGS, cinfa, isoca
:POINTER Sst
}

PARAMETER{
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
alphaa = 5.18e-15
Ba = 1
fcyta = 0.01
fVpqa = 0.00226
tmsb = 0.001
vcella = 0.624e-12
vmdpq = 1.41e-15
cmdpqa = 11.51299890826233
ca = 0.3449148387259899
kpmcaa = 0.3
ksercaa = 0.05
pleaka = 0.0003
cera = 58.71698724650182
N1a = 1.057203539612775e-05
N2a = 2.113947666062938e-05
N3a = 2.388848788981755e-05
N4a = 2.391806975716259e-06
N5a = 0.008850176609826538
N6a = 12.69715161782077
NFa = 0.001724142875712899
NRa = 0.1927364884362762
fera = 0.01
sigmava = 31
fmda = 0.01
k1a = 20
km1a = 100
r1a = 0.6
rm1a = 1
r20a = 0.006
r30a = 1.205
rm3a = 0.0001
u1a = 2000
u2a = 3
u3a = 0.025
kpa = 2.3
kp2a = 2.3
GlucFacta = 0.05
knockoutda = 0
ra = 4.5
sombara = 50
rako = 0.001
ssom = 15
fa = 150
vc = 1e-13
caerbara = 70
ssoca = -20
vsoca = 0
gsocbara = 0.025
v = -49.03736299581227
}

BREAKPOINT{
JPQ = -alphaa*iCaPQ / vmdpq
JTa = -alphaa*iCaT/vcella
JLa = -alphaa*iCaL/vcella
Jera = Jleaka - Jsercaa
rm2a=(1-knockoutda)*ra/(1+exp(-(Sst-sombara)/ssom))+knockoutda*rako :Delta inhibiting alphaa by Sst increasing the rate of depriming of G granules.
SOLVE states METHOD cnexp
r2a = r20a*ca/(ca+kp2a)
r3a = GlucFacta*r30a*ca/(ca+kpa)
Jsercaa = ksercaa*ca
Jleaka = pleaka*(cera - ca)
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