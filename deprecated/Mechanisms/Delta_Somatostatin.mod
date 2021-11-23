NEURON{
    POINT_PROCESS D_Somatostatin
    USEION cald READ icald
    USEION capqd READ icapqd
    USEION insulin READ insulini,insulino VALENCE 0
    POINTER mcapqd
    POINTER hcapqd
    RANGE con, bas, vc, tmsb, tausom, pleakd, fVld, fVpqd, fmdd, Bd, alphad, kpmcad, fcytd, ferd, sigmavd, ksercad, fd, vmdpqd, vmdld
    RANGE JLd, JPQd, Jmemd, Jsercad, Jleakd, Jerd, y, Som, JSS
    RANGE I, Io, Sstpnt
    :POINTER 
}

PARAMETER{
    icald
    icapqd
    mcapqd
    hcapqd
    Sstpnt
    insulini
    insulino
    I
    Io
    con
    bas
    vc
    tmsb
    tausom
    pleakd
    fVld
    fVpqd
    fmdd
    Bd
    alphad
    kpmcad
    fcytd
    ferd
    sigmavd
    ksercad
    fd
    vmdpqd
    vmdld
}

ASSIGNED{
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
    cd
    cmdld
    cmdpqd
    cerd
    Sst
}

INITIAL{
    cd=0.3051356309084454  
    cmdld=19.82903375122306  
    cmdpqd=27.93917378868966  
    cerd=413.8135591677398  
    Sst=18.71318922819339
    con=0.00000000594
    bas=0.0009
    vc = 1e-13
    tmsb=0.001
    tausom=2000
    pleakd=0.0003
    fVld=0.00340
    fVpqd=0.00226
    fmdd=0.01
    Bd=1 
    alphad=5.18e-15
    kpmcad=0.3
    fcytd=0.01
    ferd=0.01
    sigmavd=31
    ksercad=0.4
    fd= 0.003
    vmdpqd=1.41e-15
    vmdld=2.12e-15
}

BREAKPOINT{
    SOLVE states METHOD cnexp
    Sstpnt = Sst
    I = insulini
    Io = insulino
    JLd=-alphad*icald/vmdld
    JPQd=-alphad*icapqd/vmdpqd
    Jmemd = fVld*Bd*(cmdld-cd)+fVpqd*Bd*(cmdpqd-cd)-kpmcad*cd
    Jsercad = ksercad*cd
    Jleakd = pleakd*(cerd - cd)
    Jerd = (Jleakd - Jsercad)
    y=(cmdpqd/200)^4/(0.2^4+(cmdpqd/200)^4)
    Som=(200*mcapqd*hcapqd*(y)/tausom)+bas
    JSS=tmsb*Som*con
}

DERIVATIVE states{
    cd' = fcytd*(Jmemd+Jerd) 
    cmdld'=fmdd*JLd-fmdd*Bd*(cmdld-cd)
    cmdpqd'=fmdd*JPQd-fmdd*Bd*(cmdpqd-cd)
    cerd' = -ferd*sigmavd*Jerd
    Sst'=JSS/vc-fd*Sst
}