NEURON{
	SUFFIX frid
    RANGE Cm, ADPf, ATP, Cac, dCaL, dCaP, dCaT, dKCa, dKCaB, dKhe
    RANGE dKr, dNa, ECa, EK, ENa, F, f1CaL, f2CaL, fCaP, fCaT
    RANGE fi, fKCaB, fKhe, fNa, gBNa, gmCaL, gmCaP, gmCaT, gmKATP, gmKCa
    RANGE gmKCaB, gmKDr, gmKhe, gmNa, hdk, In, IntCa, kCaBK, kCap, kci
    RANGE kdCaL, kdCaP, kdCaT, kdd, kdhe, kdKCaB, kdkr, kdNa, kfCaL
    RANGE kfCaP, kfCaT, kfhe, kfKCaB, kfNa, KiCa, KKCa, kNar, kpi, kre
    RANGE ksg, kshift, ksi, ktd, ktt, newk, Ni, PmCaP, RTdF, tdCaP
    RANGE tdCaT, tfKCaB, tfKhe, tfNa, VBKo, VdCaL, VdCaP, VdCaT, Vdhe, Vdkr
    RANGE VdNa, VfCaL, VfCaP, VfCaT, Vfhe, VfKCaB, VfNa, Vi, Vp, Vpi
    RANGE tdKr, tdNa, tf1CaL, tfCaP, tfCaT, tf2CaL
    RANGE tdCaL, test, Vp
}

PARAMETER{
    Cm
	ADPf
    ATP
    ECa
    EK
    ENa
    F
    fi
    gBNa
    gmCaL
    gmCaP
    gmCaT
    gmKATP
    gmKCa
    gmKCaB
    gmKDr
    gmKhe
    gmNa
    hdk
    kCaBK
    kCap
    kci
    kdCaL
    kdCaP
    kdCaT
    kdd
    kdhe
    kdKCaB
    kdkr
    kdNa
    kfCaL
    kfCaP
    kfCaT
    kfhe
    kfKCaB
    kfNa
    KiCa
    KKCa
    kNar
    kpi
    kre
    ksg
    kshift
    ksi
    ktd
    ktt
    newk
    Ni
    PmCaP
    RTdF
    tdCaP
    tdCaT
    tfKCaB
    tfKhe
    tfNa
    VBKo
    VdCaL
    VdCaP
    VdCaT
    Vdhe
    Vdkr
    VdNa
    VfCaL
    VfCaP
    VfCaT
    Vfhe
    VfKCaB
    VfNa
    Vi
    Vpi

    tdKr
    tdNa
    tf1CaL
    tfCaP
    tfCaT
    tf2CaL
    tdKCaB
    tdKhe	

    test	
}

ASSIGNED{
	dCaLi
    dCaPi
    dCaTi
    dKCa
    dKCaBi
    dKhei
    dKri
    dNai
    fCaLi
    fCaPi
    fCaTi
    fiCa
    fKCaBi
    fKhei
    fNai
    fsi
    ICaL
    ICaP
    ICaT
    IKATP
    IKCa
    IKCaB
    IKDr
    IKher
    INa
    INab
    IPCa
    IS : insulin secretion
    MgADP
    OKATP
    tdCaL
    VdKCaB
}

STATE{
    Cac
    IntCa
    dKr
    Vp
    dCaL
    dCaP
    fCaP
    f1CaL
    f2CaL
    dNa
    fNa
    dCaT
    fCaT
    dKCaB
    fKCaB
    dKhe
    fKhe
    In
}

INITIAL{
    test = -1 
    Cm = 9990
    ADPf = 15.0
    ATP = 3600
    Cac = 0.25
    dCaL = 0.001
    dCaP = 0.1
    dCaT = 0.1
    dKCa = 0.1
    dKCaB = 0.1
    dKhe = 0.1
    dKr = 0.0029
    dNa = 0.1
    ECa = 100
    EK = -75
    ENa = 70
    F = 96480
    f1CaL = 0.1
    f2CaL = 0.7
    fCaP = 0.1
    fCaT = 0.1
    fi = 0.005
    fKCaB = 0.1
    fKhe = 0.1
    fNa = 0.1
    gBNa = 10.0
    gmCaL = 2700
    gmCaP = 1200
    gmCaT = 250
    gmKATP = 65000
    gmKCa = 150
    gmKCaB = 25000
    gmKDr = 18000
    gmKhe = 200
    gmNa = 10000
    hdk = 2
    In = 1.0
    IntCa = 0
    kCaBK = 1.5
    kCap = 0.3
    kci = 2
    kdCaL = 8
    kdCaP = 6
    kdCaT = 6
    kdd = 17
    kdhe = 10
    kdKCaB = 30
    kdkr = 8
    kdNa = 10
    kfCaL = 8
    kfCaP = 8
    kfCaT = 8
    kfhe = 17.5
    kfKCaB = 9.2
    kfNa = 6
    KiCa = 0.2
    KKCa = 0.2
    kNar = 0
    kpi = 0.0001
    kre = 0.00073
    ksg = 0.00001
    kshift = 18
    ksi = 10000
    ktd = 26
    ktt = 50
    newk = 0.001
    Ni = 600
    PmCaP = 5600
    RTdF = 26.73
    tdCaP = 0.41
    tdCaT = 0.41
    tdKCaB = 1.9
    tdKhe = 100
    tdKr = 20
    tdNa = 0.1
    tf1CaL = 6.8
    tf2CaL = 65
    tfCaP = 65
    tfCaT = 6.8
    tfKCaB = 22.6
    tfKhe = 50
    tfNa = 0.5
    VBKo = 0.1
    VdCaL = -15
    VdCaP = -5
    VdCaT = -50
    Vdhe = -30
    Vdkr = -9
    VdNa = -30
    VfCaL = -25
    VfCaP = -25
    VfCaT = -64
    Vfhe = -42
    VfKCaB = 30
    VfNa = -42
    Vi = 0.764
    Vp = -62
    Vpi = 45000
    tdCaL = 0.41
}

BREAKPOINT{
    test = test + 3
    dCaLi = (1.0 / (1.0 + exp(((VdCaL - Vp) / kdCaL))))
    dCaPi = (1.0 / (1.0 + exp(((VdCaP - Vp) / kdCaP))))
    dCaTi = (1.0 / (1.0 + exp(((VdCaT - Vp) / kdCaT))))
    dKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))
    dKCaBi = (1.0 / (1.0 + exp(((VdKCaB - Vp) / kdKCaB))))
    dKhei =  (1.0 / (1.0 + exp(((Vdhe - Vp) / kdhe))))
    dKri = (1.0 / (1.0 + exp(((Vdkr - Vp) / kdkr))))
    dNai = (1.0 / (1.0 + exp(((VdNa - Vp) / kdNa))))
    fCaLi = (1.0 / (1.0 + exp(((Vp - VfCaL) / kfCaL))))
    fCaPi =  (1.0 / (1.0 + exp(((Vp - VfCaP) / kfCaP))))
    fCaTi = (1.0 / (1.0 + exp(((Vp - VfCaT) / kfCaT))))
    fiCa =  (Cac * Cac / ((KiCa * KiCa) + (Cac * Cac)))
    fKCaBi = (1.0 / (1.0 + exp( - ((VfKCaB - Vp) / kfKCaB))))
    fKhei = (1.0 / (1.0 + exp(((Vp - Vfhe) / kfhe))))
    fNai = (1.0 / (1.0 + exp( - ((VfNa - Vp) / kfNa))))
    fsi = ( - (kci * fiCa * ICaP / F) + kre)
    ICaL = (gmCaL * dCaL * f1CaL * f2CaL * (Vp - ECa))
    ICaP = (gmCaP * dCaP * fCaP * (Vp - ECa))
    ICaT = (gmCaT * dCaT * fCaT * (Vp - ECa))
    IKATP =  (gmKATP * OKATP * (Vp - EK))
    IKCa =  (gmKCa * dKCa * (Vp - EK))
    IKCaB =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (Vp - EK))
    IKDr =  (gmKDr * dKr * dKr * (Vp - EK))
    IKher =  (gmKhe * dKhe * fKhe * (Vp - EK))
    INa = (gmNa * ((pow(dNa,3.0) * fNa) + kNar) * (Vp - ENa))
    INab =  (gBNa * (Vp - ENa))
    IPCa =  (PmCaP * Cac * Cac / ((Cac * Cac) + (kCap * kCap)))
    IS =  (kpi * ksi * In)
    MgADP =  (0.55 * ADPf)
    OKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))
    tdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + Vp) * ( - 9.7 + Vp)))))
    VdKCaB =   (VBKo - (kshift * log((Cac / kCaBK))))
    SOLVE states METHOD cnexp  
}

DERIVATIVE states{
    Cac' = ((fi * ( - ICaL - ICaP - ICaT - (2.0 * IPCa)) / (2.0 * F * Vi)) - (ksg * Cac))
    IntCa' = (0.001 * Cac)
    dKr' = ((dKri - dKr) / tdKr)
    Vp' =  - ((ICaL + ICaP + ICaT + IKDr + IPCa + IKCa + IKCaB + IKATP + IKher + INab + INa) / Cm)
    dCaL' = ((dCaLi - dCaL) / tdCaL)
    dCaP' = ((dCaPi - dCaP) / tdCaP)
    fCaP' = ((fCaPi - fCaP) / tfCaP)
    f1CaL' = ((fCaLi - f1CaL) / tf1CaL)
    f2CaL' = ((fCaLi - f2CaL) / tf2CaL)
    dNa' = ((dNai - dNa) / tdNa)
    fNa' = ((fNai - fNa) / tfNa)
    dCaT' = ((dCaTi - dCaT) / tdCaT)
    fCaT' = ((fCaTi - fCaT) / tfCaT)
    dKCaB' = ((dKCaBi - dKCaB) / tdKCaB)
    fKCaB' = ((fKCaBi - fKCaB) / tfKCaB)
    dKhe' = ((dKhei - dKhe) / tdKhe)
    fKhe' = ((fKhei - fKhe) / tfKhe)
    In' = ((fsi * Ni / Vpi) - (kpi * In))
}