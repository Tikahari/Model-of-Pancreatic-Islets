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
    RANGE VdKCaB
    RANGE ICaL, ICaP, ICaT, IKATP, IKCa, IBK, iKDR, IHERG, INa, INaB, IPCa
    RANGE IS, MgADP, OKATP, tdCaL, VdKCaB
    RANGE V_real
    USEION CaL READ iCaL
    USEION CaT READ iCaT
    USEION CaP READ iCaP
    USEION BK READ iBK
    USEION Na READ iNa
    USEION NaB READ iNaB
    USEION HERG READ iHERG
    USEION PCa READ iPCa
    USEION KCa READ iKCa
    USEION KATP READ iKATP
    USEION KDR READ iKDR
:    USEION CaLL WRITE iCaLL VALENCE 2   
:   USEION CaTT WRITE iCaTT VALENCE 2
:   USEION CaPP WRITE iCaPP VALENCE 2
:    USEION BKK WRITE iBKK VALENCE 1
:    USEION Naa WRITE iNaa VALENCE 1
:    USEION NaBB WRITE iNaBB VALENCE 1
:    USEION HERGG WRITE iHERGG VALENCE 1
:    USEION PCaa WRITE iPCaa VALENCE 2
:    USEION KCaa WRITE iKCaa VALENCE 1
:    USEION KATPP WRITE iKATPP VALENCE 1
:    USEION KDRR WRITE iKDRR VALENCE 1
    RANGE fi_, dCaLi_, dCaPi_, dCaTi_, dKCa_, dKCaBi_, dKhei_, dKri_, dNai_, fCaLi_, fCaPi_, fCaTi_, fiCa_, fKCaBi_, fKhei_, fNai_, fsi_, MgADP_, OKATP_, tdCaL_, VdKCaB_
    RANGE iCaLL, iCaTT, iCaPP, iBKK, iNaa, iNaBB, iHERGG, iPCaa, iKCaa, iKATPP, iKDRR
}

PARAMETER{
    iCaL
    iCaT
    iCaP
    iBK
    iNa
    iNaB
    iHERG
    iPCa
    iKCa
    iKATP
    iKDR
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
    IBK
    IKDR
    IHERG
    INa
    INaB
    IPCa
    IS : insulin secretion
    MgADP
    OKATP
    tdCaL
    VdKCaB
    V_real

    : 'v' for 'Vp'
    fi_
    dCaLi_
    dCaPi_
    dCaTi_
    dKCa_
    dKCaBi_
    dKhei_
    dKri_
    dNai_
    fCaLi_
    fCaPi_
    fCaTi_
    fiCa_
    fKCaBi_
    fKhei_
    fNai_
    fsi_
    MgADP_
    OKATP_
    tdCaL_
    VdKCaB_
}

ASSIGNED{
    Vmio
    iCaLL
    iCaTT
    iCaPP
    iBKK
    iNaa
    iNaBB
    iHERGG
    iPCaa
    iKCaa
    iKATPP
    iKDRR
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
    Vmi

    Cac_
    IntCa_
    dKr_
    dCaL_
    dCaP_
    fCaP_
    f1CaL_
    f2CaL_
    dNa_
    fNa_
    dCaT_
    fCaT_
    dKCaB_
    fKCaB_
    dKhe_
    fKhe_
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

    : 'v' for 'Vp'
    Cac_ = 0.25
    dCaL_ = 0.001
    dCaP_ = 0.1
    dCaT_ = 0.1
    dKCa_ = 0.1
    dKCaB_ = 0.1
    dKhe_ = 0.1
    dKr_ = 0.0029
    dNa_ = 0.1

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

    :'v' for 'Vp'
    f1CaL_ = 0.1
    f2CaL_ = 0.7
    fCaP_ = 0.1
    fCaT_ = 0.1
    fi_ = 0.005
    fKCaB_ = 0.1
    fKhe_ = 0.1
    fNa_ = 0.1    

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
    :Vmi = -62
    Vpi = 45000
    tdCaL = 0.41
    tdCaL_ = 0.41
}

BREAKPOINT{
    V_real = v
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

    : use 'v' instead of 'Vp' for gating variables
    dCaLi_ = (1.0 / (1.0 + exp(((VdCaL - v) / kdCaL))))
    dCaPi_ = (1.0 / (1.0 + exp(((VdCaP - v) / kdCaP))))
    dCaTi_ = (1.0 / (1.0 + exp(((VdCaT - v) / kdCaT))))
    dKCa_ = (pow(Cac_,4.0) / (pow(KKCa,4.0) + pow(Cac_,4.0)))
    dKCaBi_ = (1.0 / (1.0 + exp(((VdKCaB - v) / kdKCaB))))
    dKhei_ =  (1.0 / (1.0 + exp(((Vdhe - v) / kdhe))))
    dKri_ = (1.0 / (1.0 + exp(((Vdkr - v) / kdkr))))
    dNai_ = (1.0 / (1.0 + exp(((VdNa - v) / kdNa))))
    fCaLi_ = (1.0 / (1.0 + exp(((v - VfCaL) / kfCaL))))
    fCaPi_ =  (1.0 / (1.0 + exp(((v - VfCaP) / kfCaP))))
    fCaTi_ = (1.0 / (1.0 + exp(((v - VfCaT) / kfCaT))))
    fiCa_ =  (Cac_ * Cac_ / ((KiCa * KiCa) + (Cac_ * Cac_)))
    fKCaBi_ = (1.0 / (1.0 + exp( - ((VfKCaB - v) / kfKCaB))))
    fKhei_ = (1.0 / (1.0 + exp(((v - Vfhe) / kfhe))))
    fNai_ = (1.0 / (1.0 + exp( - ((VfNa - v) / kfNa))))
    fsi_ = ( - (kci * fiCa * iCaPP / F) + kre)

    MgADP_ =  (0.55 * ADPf)
    OKATP_ =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))
    tdCaL_ =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + v) * ( - 9.7 + v)))))
    VdKCaB_ =   (VBKo - (kshift * log((Cac_ / kCaBK))))


    ICaL = (gmCaL * dCaL * f1CaL * f2CaL * (Vp - ECa))
    ICaP = (gmCaP * dCaP * fCaP * (Vp - ECa))
    ICaT = (gmCaT * dCaT * fCaT * (Vp - ECa))
    IKATP =  (gmKATP * OKATP * (Vp - EK))
    IKCa =  (gmKCa * dKCa * (Vp - EK))
    IBK =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (Vp - EK))
    IKDR =  (gmKDr * dKr * dKr * (Vp - EK))
    IHERG =  (gmKhe * dKhe * fKhe * (Vp - EK))
    INa = (gmNa * ((pow(dNa,3.0) * fNa) + kNar) * (Vp - ENa))
    INaB =  (gBNa * (Vp - ENa))
    IPCa =  (PmCaP * Cac * Cac / ((Cac * Cac) + (kCap * kCap)))
    IS =  (kpi * ksi * In)

    MgADP =  (0.55 * ADPf)
    OKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))
    tdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + Vp) * ( - 9.7 + Vp)))))
    VdKCaB =   (VBKo - (kshift * log((Cac / kCaBK))))

    : use 'v' instead of 'Vp' for currents
    iCaLL = (gmCaL * dCaL_ * f1CaL_ * f2CaL_ * (v - ECa))
    iCaTT = (gmCaT * dCaT_ * fCaT_ * (v - ECa))
    iCaPP = (gmCaP * dCaP_ * fCaP_ * (v - ECa))
    iBKK =  (gmKCaB * pow(dKCaB_,hdk) * fKCaB_ * (v - EK))
    iNaa = (gmNa * ((pow(dNa_,3.0) * fNa_) + kNar) * (v - ENa))
    iNaBB =  (gBNa * (v - ENa))
    iHERGG =  (gmKhe * dKhe_ * fKhe_ * (v - EK))
    iPCaa =  (PmCaP * Cac_ * Cac_ / ((Cac_ * Cac_) + (kCap * kCap)))
    iKCaa =  (gmKCa * dKCa_ * (v - EK))
    iKATPP =  (gmKATP * OKATP_ * (v - EK))
    iKDRR =  (gmKDr * dKr_ * dKr_ * (v - EK))
    SOLVE states METHOD cnexp  
}

DERIVATIVE states{
    Cac' = ((fi * ( - ICaL - ICaP - ICaT - (2.0 * IPCa)) / (2.0 * F * Vi)) - (ksg * Cac))
    IntCa' = (0.001 * Cac)
    dKr' = ((dKri - dKr) / tdKr)
    Vp' =  - ((ICaL + ICaP + ICaT + IKDR + IPCa + IKCa + IBK + IKATP + IHERG + INaB + INa) / Cm)
    Vmi' = - ((iCaL + iCaP + iCaT + iKDR + iPCa + iKCa + iBK + iKATP + iHERG + iNaB + iNa) / Cm)
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

    : use 'v' instead of 'Vp' for state variables
    Cac_' = ((fi * ( - iCaLL - iCaPP - iCaTT - (2.0 * iPCaa)) / (2.0 * F * Vi)) - (ksg * Cac_))
    dKr_' = ((dKri_ - dKr_) / tdKr)
    dCaL_' = ((dCaLi_ - dCaL_) / tdCaL_)
    dCaP_' = ((dCaPi_ - dCaP_) / tdCaP)
    fCaP_' = ((fCaPi_ - fCaP_) / tfCaP)
    f1CaL_' = ((fCaLi_ - f1CaL_) / tf1CaL)
    f2CaL_' = ((fCaLi_ - f2CaL_) / tf2CaL)
    dNa_' = ((dNai_ - dNa_) / tdNa)
    fNa_' = ((fNai_ - fNa_) / tfNa)
    dCaT_' = ((dCaTi_ - dCaT_) / tdCaT)
    fCaT_' = ((fCaTi_ - fCaT_) / tfCaT)
    dKCaB_' = ((dKCaBi_ - dKCaB_) / tdKCaB)
    fKCaB_' = ((fKCaBi_ - fKCaB_) / tfKCaB)
    dKhe_' = ((dKhei_ - dKhe_) / tdKhe)
    fKhe_' = ((fKhei_ - fKhe_) / tfKhe)
}
