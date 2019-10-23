#ifndef BENCHMARK_CRITERIA_H
#define BENCHMARK_CRITERIA_H
 
static const double tolerance_in_percent = 0.001;
 
namespace cc_xsec {
 
namespace lwlyn {
static const double xsec_default = 9.11464e-12;
} // end namespace lwlyn
 
namespace nieves {
static const double xsec_default = 1.7381e-11;
} // end namespace nieves
 
} // end namespace cc_xsec
 
namespace coh_xsec {
 
namespace reinsehgal {
static const double xsec_default = 1.74145e-11;
static const double xsec_use_modi_pcac_false = 2.00335e-11;
} // end namespace reinsehgal
namespace arconstant {
static const double HBar = 0.19733;
static const double Ma_Nucleon = 1;
static const double Mv_Nucleon = 0.84;
static const double Ma_Delta = 1.28;
static const double Mv_Delta = 0.73;
static const double GAxial = 1.267;
static const double Rho0 = 0.17;
static const double CA4_A = -1.21;
static const double CA5_A = -1.21;
static const double CA4_B = 2;
static const double CA5_B = 2;
static const double PiDecayConst = 0.471292;
static const double DeltaNCoupling = 2.13;
static const double CosCabibboAngle = 0.974;
static const double SinWeinbergAngle = 0.477179;
static const double GFermi = 4.54182e-07;
static const double ElectronMass = 0.00258957;
static const double MuonMass = 0.53544;
static const double TauMass = 9.00451;
static const double ProtonMass = 4.75484;
static const double NucleonMass = 4.75811;
static const double NucleonMassSq = 22.6397;
static const double DeltaPMass = 6.24335;
static const double Delta0Mass = 6.24842;
static const double PiPMass = 0.707293;
static const double Pi0Mass = 0.684015;
static const double cm38Conversion = 1e+12;
static const double NCFactor = 0.5446;
} // end namespace arconstants
 
} // end namespace coh_xsec
 
#endif
 
