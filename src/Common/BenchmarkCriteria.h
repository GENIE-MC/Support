#ifndef BENCHMARK_CRITERIA_H
#define BENCHMARK_CRITERIA_H
 
#include <complex>
 
static const double tolerance_in_percent = 0.001;
 
namespace qel_xsec {
 
namespace lwlyn {
static const double xsec_default = 4.09333e-11;
} // end namespace lwlyn
 
namespace nieves {
static const double xsec_default = 1.7381e-11;
} // end namespace nieves
 
namespace dipoleaxialff {
static const double fa_default = -1.03748;
} // end namespace dipoleaxialff
 
namespace dipoleelff {
static const double gep_default = 0.761465;
static const double gmp_default = 2.12677;
static const double gmn_default = -1.45671;
} // end namespace dipoleelff
 
namespace zexpaxialff {
static const double fa_default = -1.03345;
} // end namespace zexpaxialff
 
namespace ahrens {
static const double xsec_default = 8.58382e-12;
} // end namespace ahrens
 
namespace bba03el {
static const double gep_default = 0.74059;
static const double gmp_default = 2.09216;
static const double gen_default = 0.0352822;
static const double gmn_default = -1.44574;
} // end namespace bba03el
 
namespace bba05el {
static const double gep_default = 0.747147;
static const double gmp_default = 2.09245;
static const double gen_default = 0.0393927;
static const double gmn_default = -1.40783;
} // end namespace bba05el
 
namespace bba07el {
static const double gep_default = 0.736716;
static const double gmp_default = 2.08578;
static const double gen_default = 0.0383839;
static const double gmn_default = -1.40956;
} // end namespace bba07el
 
namespace transenh {
static const double gep_default = 0.736716;
static const double gmp_default = 2.47362;
static const double gen_default = 0.0383839;
static const double gmn_default = -1.67167;
} // end namespace transenh
 
namespace lwlynffcc {
static const double f1v_default = 0.777606;
static const double xif2v_default = 2.71773;
static const double fa_default = -1.03748;
static const double fp_default = -14.9555;
} // end namespace lwlynffcc
 
namespace lwlynffnc {
static const double f1v_default = 0.0198615;
static const double xif2v_default = 0.958243;
static const double fa_default = -0.518741;
static const double fp_default = -7.47773;
} // end namespace lwlynffnc
 
} // end namespace qel_xsec
 
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
 
namespace arsamplednucleus {
static const unsigned int A = 12;
static const unsigned int Z = 6;
static const unsigned int N = 6;
static const double density = 0.0738277;
static const double densityofcentres = 0.0780715;
static const double radius = 2.37793;
static const double radiusmax = 6.86829;
static const double samplepoint1 = 2.35875;
static const double samplepoint2 = 0.3014;
static const unsigned int sample = 20;
static const unsigned int ndensities = 40;
static const double matterdensity = 0.167552;
static const double numberdensity = 0.17601;
} // end namespace arsamplednucleus
 
namespace areikonalsolution {
static const std::complex<double> element_CC_E_Nu_Nieves(0.904281,0.242239);
static const std::complex<double> element_CC_E_Nu_Garcia(0.904281,0.242239);
static const std::complex<double> element_CC_E_AntiNu_Nieves(0.904281,0.242239);
static const std::complex<double> element_CC_E_AntiNu_Garcia(0.904281,0.242239);
static const std::complex<double> element_NC_E_Nu_Nieves(0.892656,0.251322);
static const std::complex<double> element_NC_E_Nu_Garcia(0.892656,0.251322);
static const std::complex<double> element_NC_E_AntiNu_Nieves(0.892656,0.251322);
static const std::complex<double> element_NC_E_AntiNu_Garcia(0.892656,0.251322);
static const std::complex<double> element_CC_Mu_Nu_Nieves(0.904281,0.242239);
static const std::complex<double> element_CC_Mu_Nu_Garcia(0.904281,0.242239);
static const std::complex<double> element_CC_Mu_AntiNu_Nieves(0.904281,0.242239);
static const std::complex<double> element_CC_Mu_AntiNu_Garcia(0.904281,0.242239);
static const std::complex<double> element_NC_Mu_Nu_Nieves(0.892656,0.251322);
static const std::complex<double> element_NC_Mu_Nu_Garcia(0.892656,0.251322);
static const std::complex<double> element_NC_Mu_AntiNu_Nieves(0.892656,0.251322);
static const std::complex<double> element_NC_Mu_AntiNu_Garcia(0.892656,0.251322);
static const std::complex<double> element_CC_Tau_Nu_Nieves(0.904281,0.242239);
static const std::complex<double> element_CC_Tau_Nu_Garcia(0.904281,0.242239);
static const std::complex<double> element_CC_Tau_AntiNu_Nieves(0.904281,0.242239);
static const std::complex<double> element_CC_Tau_AntiNu_Garcia(0.904281,0.242239);
static const std::complex<double> element_NC_Tau_Nu_Nieves(0.892656,0.251322);
static const std::complex<double> element_NC_Tau_Nu_Garcia(0.892656,0.251322);
static const std::complex<double> element_NC_Tau_AntiNu_Nieves(0.892656,0.251322);
static const std::complex<double> element_NC_Tau_AntiNu_Garcia(0.892656,0.251322);
} // end namespace areikonalsolution
 
namespace arwavefunction {
static const unsigned int sampling = 16;
static const std::complex<double> get60(0.1,-0.1);
static const std::complex<double> get61(0.2,-0.2);
static const std::complex<double> get62(0.3,-0.3);
static const std::complex<double> get63(0.4,-0.4);
} // end namespace wavefunction
 
namespace alvarezrusocohpipdxsec {
static const unsigned int sampling = 20;
static const double pimass = 0.707293;
static const double leptonmass = 0.00258957;
static const double DXSec_CC_E_Nu_Nieves = 0.000104381;
static const double DXSec_CC_E_Nu_Garcia = 0.000104381;
static const double DXSec_CC_E_AntiNu_Nieves = 0.000104381;
static const double DXSec_CC_E_AntiNu_Garcia = 0.000104381;
static const double DXSec_NC_E_Nu_Nieves = 0.000104381;
static const double DXSec_NC_E_Nu_Garcia = 0.000104381;
static const double DXSec_NC_E_AntiNu_Nieves = 0.000104381;
static const double DXSec_NC_E_AntiNu_Garcia = 0.000104381;
static const double DXSec_CC_Mu_Nu_Nieves = 0.000104381;
static const double DXSec_CC_Mu_Nu_Garcia = 0.000104381;
static const double DXSec_CC_Mu_AntiNu_Nieves = 0.000104381;
static const double DXSec_CC_Mu_AntiNu_Garcia = 0.000104381;
static const double DXSec_NC_Mu_Nu_Nieves = 0.000104381;
static const double DXSec_NC_Mu_Nu_Garcia = 0.000104381;
static const double DXSec_NC_Mu_AntiNu_Nieves = 0.000104381;
static const double DXSec_NC_Mu_AntiNu_Garcia = 0.000104381;
static const double DXSec_CC_Tau_Nu_Nieves = 0.000104381;
static const double DXSec_CC_Tau_Nu_Garcia = 0.000104381;
static const double DXSec_CC_Tau_AntiNu_Nieves = 0.000104381;
static const double DXSec_CC_Tau_AntiNu_Garcia = 0.000104381;
static const double DXSec_NC_Tau_Nu_Nieves = 0.000104381;
static const double DXSec_NC_Tau_Nu_Garcia = 0.000104381;
static const double DXSec_NC_Tau_AntiNu_Nieves = 0.000104381;
static const double DXSec_NC_Tau_AntiNu_Garcia = 0.000104381;
} // end namespace alvarezrusocohpipdxsec
 
} // end namespace coh_xsec
 
#endif
 
