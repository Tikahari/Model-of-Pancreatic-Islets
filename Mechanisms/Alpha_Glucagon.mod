NEURON{
    POINT_PROCESS A_Glucagon
    USEION soca WRITE isoca VALENCE 1
    USEION cala READ icala
    USEION cata READ icata
    USEION capqa READ icapqa
    USEION sst READ ssti,ssto VALENCE 1
    USEION insulin READ insulini,insulino VALENCE 1
    RANGE vc, caerbara, ssoca, vsoca, k1a, km1a, r1a, rm1a, r20a, r30a, rm3a, u1a, u2a, u3a, kpa, kp2a, GlucFacta, vcella, vmdpqa, fVpqa, fmda, Ba, alphaa, kpmcaa, fcyta, fera, pleaka, sigmava, fa, gsocbara, ksercaa, tmsb, knockoutda, ra, sombara, rako, ssom
    RANGE rm2a, cinfa, JLa, JPQa, JTa, Jmema, Jsercaa, Jleaka, Jera, r2a, r3a, JGS, isoca
    RANGE Sst, I, Io, Ssto
    POINTER Gpnt
}

PARAMETER{
    ssti
    ssto
    insulini
    insulino
    Gpnt
    Sst
    Ssto
    I
    Io
    icala
    icata
    icapqa
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
}

ASSIGNED{
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
    v
    isoca
}

STATE{
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

    Sst=0

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
}
 
BREAKPOINT{
    SOLVE states METHOD cnexp
    Sst = ssti
    Ssto = ssto
    I = insulini
    Io = insulino
    Gpnt = G
    rm2a=(1-knockoutda)*ra/(1+exp(-(Sst-sombara)/ssom))+knockoutda*rako
    cinfa = 1/(1+exp(-(cera-caerbara)/ssoca))
    isoca = gsocbara*cinfa*(v-vsoca)
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
}

DERIVATIVE states{
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