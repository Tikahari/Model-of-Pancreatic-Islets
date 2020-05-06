# write outline of mod file from configuration file from configuration.py
import configparser
import sys

# make writer a class so we can keep a set which will keep track of which variables have been added to the mod file so far
class Mod():
    def __init__(self, modname, ininame):
        self.mod = modname
        self.ini = ininame
        self.f = ''
        self.initialize_block = ""
        # outline
        self.f += "NEURON{\
                \nSUFFIX frid\
                \nRANGE Cm, ADPf, ATP, Cac, dCaL, dCaP, dCaT, dKCa, dKCaB, dKhe\
                \nRANGE dKr, dNa, ECa, EK, ENa, F, f1CaL, f2CaL, fCaP, fCaT\
                \nRANGE fi, fKCaB, fKhe, fNa, gBNa, gmCaL, gmCaP, gmCaT, gmKATP, gmKCa\
                \nRANGE gmKCaB, gmKDr, gmKhe, gmNa, hdk, In, IntCa, kCaBK, kCap, kci\
                \nRANGE kdCaL, kdCaP, kdCaT, kdd, kdhe, kdKCaB, kdkr, kdNa, kfCaL\
                \nRANGE kfCaP, kfCaT, kfhe, kfKCaB, kfNa, KiCa, KKCa, kNar, kpi, kre\
                \nRANGE ksg, kshift, ksi, ktd, ktt, newk, Ni, PmCaP, RTdF, tdCaP\
                \nRANGE tdCaT, tfKCaB, tfKhe, tfNa, VBKo, VdCaL, VdCaP, VdCaT, Vdhe, Vdkr\
                \nRANGE VdNa, VfCaL, VfCaP, VfCaT, Vfhe, VfKCaB, VfNa, Vi, Vp, Vpi\
                \nRANGE tdKr, tdNa, tf1CaL, tfCaP, tfCaT, tf2CaL\
                \nRANGE tdCaL, test, Vp\
                \n}\
                \n\nPARAMETER{\
                \nCm\
	            \nADPf\
                \nATP\
                \nECa\
                \nEK\
                \nENa\
                \nF\
                \nfi\
                \ngBNa\
                \ngmCaL\
                \ngmCaP\
                \ngmCaT\
                \ngmKATP\
                \ngmKCa\
                \ngmKCaB\
                \ngmKDr\
                \ngmKhe\
                \ngmNa\
                \nhdk\
                \nkCaBK\
                \nkCap\
                \nkci\
                \nkdCaL\
                \nkdCaP\
                \nkdCaT\
                \nkdd\
                \nkdhe\
                \nkdKCaB\
                \nkdkr\
                \nkdNa\
                \nkfCaL\
                \nkfCaP\
                \nkfCaT\
                \nkfhe\
                \nkfKCaB\
                \nkfNa\
                \nKiCa\
                \nKKCa\
                \nkNar\
                \nkpi\
                \nkre\
                \nksg\
                \nkshift\
                \nksi\
                \nktd\
                \nktt\
                \nnewk\
                \nNi\
                \nPmCaP\
                \nRTdF\
                \ntdCaP\
                \ntdCaT\
                \ntfKCaB\
                \ntfKhe\
                \ntfNa\
                \nVBKo\
                \nVdCaL\
                \nVdCaP\
                \nVdCaT\
                \nVdhe\
                \nVdkr\
                \nVdNa\
                \nVfCaL\
                \nVfCaP\
                \nVfCaT\
                \nVfhe\
                \nVfKCaB\
                \nVfNa\
                \nVi\
                \nVpi\
                \ntdKr\
                \ntdNa\
                \ntf1CaL\
                \ntfCaP\
                \ntfCaT\
                \ntf2CaL\
                \ntdKCaB\
                \ntdKhe\
                \ntest\
                \n}\
                \nSTATE{\
                \nCac\
                \nIntCa\
                \ndKr\
                \nVp\
                \ndCaL\
                \ndCaP\
                \nfCaP\
                \nf1CaL\
                \nf2CaL\
                \ndNa\
                \nfNa\
                \ndCaT\
                \nfCaT\
                \ndKCaB\
                \nfKCaB\
                \ndKhe\
                \nfKhe\
                \nIn\
                \n}\
                \n\nASSIGNED{\
                \ndCaLi\
                \ndCaPi\
                \ndCaTi\
                \ndKCa\
                \ndKCaBi\
                \ndKhei\
                \ndKri\
                \ndNai\
                \nfCaLi\
                \nfCaPi\
                \nfCaTi\
                \nfiCa\
                \nfKCaBi\
                \nfKhei\
                \nfNai\
                \nfsi\
                \nICaL\
                \nICaP\
                \nICaT\
                \nIKATP\
                \nIKCa\
                \nIKCaB\
                \nIKDr\
                \nIKher\
                \nINa\
                \nINab\
                \nIPCa\
                \nIS : insulin secretion\
                \nMgADP\
                \nOKATP\
                \ntdCaL\
                \nVdKCaB\
                \n}\
                \n\nINITIAL{\n}\
                \n\nBREAKPOINT{\
                \ntest = test + 3\
                \ndCaLi = (1.0 / (1.0 + exp(((VdCaL - Vp) / kdCaL))))\
                \ndCaPi = (1.0 / (1.0 + exp(((VdCaP - Vp) / kdCaP))))\
                \ndCaTi = (1.0 / (1.0 + exp(((VdCaT - Vp) / kdCaT))))\
                \ndKCa = (pow(Cac,4.0) / (pow(KKCa,4.0) + pow(Cac,4.0)))\
                \ndKCaBi = (1.0 / (1.0 + exp(((VdKCaB - Vp) / kdKCaB))))\
                \ndKhei =  (1.0 / (1.0 + exp(((Vdhe - Vp) / kdhe))))\
                \ndKri = (1.0 / (1.0 + exp(((Vdkr - Vp) / kdkr))))\
                \ndNai = (1.0 / (1.0 + exp(((VdNa - Vp) / kdNa))))\
                \nfCaLi = (1.0 / (1.0 + exp(((Vp - VfCaL) / kfCaL))))\
                \nfCaPi =  (1.0 / (1.0 + exp(((Vp - VfCaP) / kfCaP))))\
                \nfCaTi = (1.0 / (1.0 + exp(((Vp - VfCaT) / kfCaT))))\
                \nfiCa =  (Cac * Cac / ((KiCa * KiCa) + (Cac * Cac)))\
                \nfKCaBi = (1.0 / (1.0 + exp( - ((VfKCaB - Vp) / kfKCaB))))\
                \nfKhei = (1.0 / (1.0 + exp(((Vp - Vfhe) / kfhe))))\
                \nfNai = (1.0 / (1.0 + exp( - ((VfNa - Vp) / kfNa))))\
                \nfsi = ( - (kci * fiCa * ICaP / F) + kre)\
                \nICaL = (gmCaL * dCaL * f1CaL * f2CaL * (Vp - ECa))\
                \nICaP = (gmCaP * dCaP * fCaP * (Vp - ECa))\
                \nICaT = (gmCaT * dCaT * fCaT * (Vp - ECa))\
                \nIKATP =  (gmKATP * OKATP * (Vp - EK))\
                \nIKCa =  (gmKCa * dKCa * (Vp - EK))\
                \nIKCaB =  (gmKCaB * pow(dKCaB,hdk) * fKCaB * (Vp - EK))\
                \nIKDr =  (gmKDr * dKr * dKr * (Vp - EK))\
                \nIKher =  (gmKhe * dKhe * fKhe * (Vp - EK))\
                \nINa = (gmNa * ((pow(dNa,3.0) * fNa) + kNar) * (Vp - ENa))\
                \nINab =  (gBNa * (Vp - ENa))\
                \nIPCa =  (PmCaP * Cac * Cac / ((Cac * Cac) + (kCap * kCap)))\
                \nIS =  (kpi * ksi * In)\
                \nMgADP =  (0.55 * ADPf)\
                \nOKATP =  (((0.08 * (1.0 + (2.0 * MgADP / kdd))) + (0.89 * MgADP * MgADP / kdd / kdd)) / ((1.0 + (MgADP / kdd)) * (1.0 + (MgADP / kdd)) * (1.0 + (0.45 * MgADP / ktd) + (ATP / ktt))))\
                \ntdCaL =  (2.2 - (1.79 * exp( - (.00020292043084065876 * ( - 9.7 + Vp) * ( - 9.7 + Vp)))))\
                \nVdKCaB =   (VBKo - (kshift * log((Cac / kCaBK))))\
                \nSOLVE states METHOD cnexp\
                \n}\
                \n\nDERIVATIVE states{\
                \nCac' = ((fi * ( - ICaL - ICaP - ICaT - (2.0 * IPCa)) / (2.0 * F * Vi)) - (ksg * Cac))\
                \nIntCa' = (0.001 * Cac)\
                \ndKr' = ((dKri - dKr) / tdKr)\
                \nVp' =  - ((ICaL + ICaP + ICaT + IKDr + IPCa + IKCa + IKCaB + IKATP + IKher + INab + INa) / Cm)\
                \ndCaL' = ((dCaLi - dCaL) / tdCaL)\
                \ndCaP' = ((dCaPi - dCaP) / tdCaP)\
                \nfCaP' = ((fCaPi - fCaP) / tfCaP)\
                \nf1CaL' = ((fCaLi - f1CaL) / tf1CaL)\
                \nf2CaL' = ((fCaLi - f2CaL) / tf2CaL)\
                \ndNa' = ((dNai - dNa) / tdNa)\
                \nfNa' = ((fNai - fNa) / tfNa)\
                \ndCaT' = ((dCaTi - dCaT) / tdCaT)\
                \nfCaT' = ((fCaTi - fCaT) / tfCaT)\
                \ndKCaB' = ((dKCaBi - dKCaB) / tdKCaB)\
                \nfKCaB' = ((fKCaBi - fKCaB) / tfKCaB)\
                \ndKhe' = ((dKhei - dKhe) / tdKhe)\
                \nfKhe' = ((fKhei - fKhe) / tfKhe)\
                \nIn' = ((fsi * Ni / Vpi) - (kpi * In))\
                \n}"
        # write outline / format
    def format(self):
        file = open(self.mod, 'w')
        # print(self.f)
        file.write(self.f)
        file.close()
    def initialize(self):
        filer = open(self.mod, 'r')
        lines = filer.readlines()
        st = ''
        new = ''
        for line in lines:
            if 'INITIAL' in line:
                line += self.initialize_block
            new += line
        filer.close()
        filew = open(self.mod, 'w')
        filew.write(new)
        filew.close()
    def writeMod(self):
        # format mod file
        self.format()
        config = configparser.ConfigParser()
        config.optionxform = str
        config.read(self.ini)
        # get initialization info from .ini file
        for i in config['Beta']:
            self.initialize_block += i + " = " + config['Beta'][i] + '\n'
        # printFile(self.mod)
        self.initialize()
def printFile(file):
    f = open(file, 'r')
    for line in f:
        print(line)
    f.close()
if __name__ == '__main__':
    if len(sys.argv) != 3:
        print('Incorrect number of argumets\nUsage: python writemod.py <modfile> <name>')
        sys.exit()
    mod = Mod(sys.argv[1], sys.argv[2])
    mod.writeMod()
