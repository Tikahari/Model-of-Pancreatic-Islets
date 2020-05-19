NEURON{
SUFFIX A_Glucagon
USEION CaPQ READ iCaPQ
USEION CaT READ iCaT
USEION CaL READ iCaL
}

PARAMETER{
iCaPQ
v
}

STATE{
G
}

INITIAL{
alpha = 5
Ba = 1
fcyta = 0.01
fVpqa = 0.00226
tmsb = 0.001
fmda = 0.01
k1a = 20
km1a=100
u1a = 2000
u2a = 3
u3a = 0.025
vcella = 0.624e-12
vmdpq = 1.41e-15
}

BREAKPOINT{
JGS = tmsb*u3a*NRa*0.0000988
JPQ = -alpha*iCaPQ / vmdpq
JTa = -alpha*iCaT/vcella
JLa = -alpha*iCaL/vcella
Jmema = JTa+JLa+fVpqa*Ba*(cmdpqa-ca)-kpmcaa*ca
Jsercaa = ksercaa*ca
Jleaka = pleaka*(cera - ca)
Jera = Jleaka - Jsercaa
SOLVE states METHOD cnexp
}

DERIVATIVE states{
ca'= fcyta*(Jmema+Jera)
cera'= -fera*sigmava*Jera
cmdpqa' = fmda*JPQ-fmda*Ba*(cmdpqa-ca)
N1a' = tmsb*(-(3*k1a*cmdpqa + rm1a)*N1a + km1a*N2a + r1a*N5a)
N2a' = tmsb*(3*k1a*cmdpqa*N1a -(2*k1a*cmdpqa + km1a)*N2a + 2*km1a*N3a)
N3a' = tmsb*(2*k1a*cmdpqa*N2a -(2*km1a + k1a*cmdpqa)*N3a + 3*km1a*N4a)
N4a' = tmsb*(k1a*cmdpqa*N3a - (3*km1a + u1a)*N4a)
NFa' = tmsb*(u1a*N4a - u2a*NFa)
NRa' = tmsb*(u2a*NFa - u3a*NRa)
G' = JGS/vc-fa*G
}
