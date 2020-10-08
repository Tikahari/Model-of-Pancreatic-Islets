NEURON{
    POINT_PROCESS D_Sst
    USEION CaPQ READ iCaPQ
    USEION CaL READ iCaL
    USEION insulin READ insulini
    USEION glucagon READ glucagoni
    USEION sst READ ssti, ssto VALENCE 1
    RANGE capq_curr
    RANGE capq_curr,vmdpqd,vmdld,vcapqhd,vcapqmd,tausom,tcapqh1d,tcapqh2d,fd,fmdd,fcytd,fVld,fVpqd,ferd,ksercad,kpmcad,vc,tmsb,bas,con,alphad,pleakd,sigmavd,Bd,scapqhd,scapqmd
    RANGE taucapqmd,taucapqhd,hcapqinfd,Jsercad,Jleakd,JLd,Jerd,Jmemd,JPQd,y,som,JSS
    RANGE myvar_m, myvar_h
    RANGE Ins, G, ist, sstin, sstout, iin
    POINTER Sstpnt
}

PARAMETER{
    Sstpnt
    iin
    Ins
    G
    insulini
    glucagoni
    sstin
    sstout
    ssti
    ssto
    iCaPQ
    iCaL
    vmdpqd
    vmdld
    vcapqhd
    vcapqmd
    tausom
    tcapqh1d
    tcapqh2d
    fd
    fmdd
    fcytd
    fVld
    fVpqd
    ferd
    ksercad
    kpmcad
    vc
    tmsb
    bas
    con
    alphad
    pleakd
    sigmavd
    Bd
    scapqhd
    scapqmd
}

ASSIGNED{
    iinsulin
    ist
    isst
    v
    taucapqmd
    mcapqinfd
    taucapqhd
    hcapqinfd
    Jsercad
    Jleakd
    JLd
    Jerd
    Jmemd
    capq_curr
    JPQd
    y
    som
    JSS
}

STATE{
    myvar_m
    myvar_h
    Sst
    cmdpqd
    cd  
    mcapqd
    hcapqd
    cmdld
    cerd
}

INITIAL{
    vc = 1e-13
    tmsb=0.001
    bas=0.0009
    con=0.00000000594
    alphad=5.18e-15
    pleakd=0.0003
    sigmavd=31
    Bd=1

    scapqhd=-5
    scapqmd=10

    Sst=18.71318922819339
    cmdpqd=27.93917378868966
    cd=0.3051356309084454  
    mcapqd=0.5089033026581684
    hcapqd=0.6672499701175263
    cmdld=19.82903375122306
    cerd=413.8135591677398

    myvar_m = 0.5089033026581684
    myvar_h = 0.6672499701175263  

    
    vmdpqd=1.41e-15 
    vmdld=2.12e-15
    vcapqhd=-33
    vcapqmd=-15

    tausom=2000
    tcapqh1d=60
    tcapqh2d=51
    taucapqhd=71
    taucapqmd=0.17


    fd= 0.003
    fmdd=0.01
    fcytd=0.01
    fVld=0.00340
    fVpqd=0.00226
    ferd=0.01

    ksercad=0.4
    kpmcad=0.3
}

BREAKPOINT{
    :iinsulin = 999
    Sstpnt = Sst
    iin = iinsulin
    sstin = ssti
    sstout = ssto
    Ins = insulini * 99999999
    G = glucagoni *100000000000
    :isst = JSS
    ist = isst
    taucapqmd=(1/(exp(-(v+23)/20)+exp((v+23)/20)))+0.05
    mcapqinfd=1/(1+exp(-(v-vcapqmd)/scapqmd))
    taucapqhd=(tcapqh1d/(exp(-(v+0)/20)+exp((v+0)/20)))+tcapqh2d
    hcapqinfd=1/(1+exp(-(v-vcapqhd)/scapqhd))
    Jsercad = ksercad*cd
    Jleakd = pleakd*(cerd - cd)
    JLd=-alphad*iCaL/vmdld
    Jerd = (Jleakd - Jsercad)
    Jmemd = fVld*Bd*(cmdld-cd)+fVpqd*Bd*(cmdpqd-cd)-kpmcad*cd
    capq_curr = iCaPQ
    JPQd=-alphad*iCaPQ/vmdpqd
    y=(cmdpqd/200)^4/(0.2^4+(cmdpqd/200)^4)
    som=(200*mcapqd*hcapqd*(y)/tausom)+bas
    :som = 4
    JSS=tmsb*som*con
    :JSS = 4
    SOLVE state METHOD cnexp
}

DERIVATIVE state{
    myvar_m' = (mcapqinfd-mcapqd)
    myvar_h' = (hcapqinfd-hcapqd)
    cerd' = -ferd*sigmavd*Jerd
    cmdld'=fmdd*JLd-fmdd*Bd*(cmdld-cd)
    hcapqd'=(hcapqinfd-hcapqd)/taucapqhd
    mcapqd'=(mcapqinfd-mcapqd)/taucapqmd
    cd' = fcytd*(Jmemd+Jerd) 
    cmdpqd'=fmdd*JPQd-fmdd*Bd*(cmdpqd-cd)
    Sst'=JSS/vc-fd*Sst
}