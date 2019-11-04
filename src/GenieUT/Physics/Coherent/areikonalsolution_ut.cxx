#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif
#include "Physics/Coherent/XSection/AREikonalSolution.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;
using namespace alvarezruso;

void areikonalsolution_ut()
{
  AlvarezRusoCOHPiPDXSec* al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kNu,kNieves);
  AREikonalSolution* eik=new AREikonalSolution(false,al);
  std::ostringstream os;
  std::string s;
#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace areikonalsolution {" );
#endif

  std::complex<double> valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_E_Nu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_E_Nu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_E_Nu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_E_Nu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_E_Nu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_E_Nu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kAntiNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_E_AntiNu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_E_AntiNu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_E_AntiNu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kAntiNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_E_AntiNu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_E_AntiNu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_E_AntiNu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_E_Nu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_E_Nu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_E_Nu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_E_Nu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_E_Nu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_E_Nu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kAntiNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_E_AntiNu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_E_AntiNu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_E_AntiNu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kAntiNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_E_AntiNu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_E_AntiNu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_E_AntiNu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Mu_Nu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Mu_Nu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Mu_Nu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Mu_Nu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Mu_Nu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Mu_Nu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kAntiNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Mu_AntiNu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Mu_AntiNu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Mu_AntiNu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kAntiNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Mu_AntiNu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Mu_AntiNu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Mu_AntiNu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Mu_Nu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Mu_Nu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Mu_Nu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Mu_Nu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Mu_Nu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Mu_Nu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kAntiNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Mu_AntiNu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Mu_AntiNu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Mu_AntiNu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kAntiNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Mu_AntiNu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Mu_AntiNu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Mu_AntiNu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Tau_Nu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Tau_Nu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Tau_Nu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Tau_Nu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Tau_Nu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Tau_Nu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kAntiNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Tau_AntiNu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Tau_AntiNu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Tau_AntiNu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kAntiNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_CC_Tau_AntiNu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_CC_Tau_AntiNu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_CC_Tau_AntiNu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Tau_Nu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Tau_Nu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Tau_Nu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Tau_Nu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Tau_Nu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Tau_Nu_Garcia.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kAntiNu,kNieves);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Tau_AntiNu_Nieves" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Tau_AntiNu_Nieves.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Tau_AntiNu_Nieves.imag(),tolerance_in_percent );
#endif

  al=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kAntiNu,kGarcia);
  eik=new AREikonalSolution(false,al);
  valcmplx=eik->Element(0.81,0.22,1.1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> element_NC_Tau_AntiNu_Garcia" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valcmplx.real(), coh_xsec::areikonalsolution::element_NC_Tau_AntiNu_Garcia.real(),tolerance_in_percent );
  BOOST_CHECK_CLOSE(valcmplx.imag(), coh_xsec::areikonalsolution::element_NC_Tau_AntiNu_Garcia.imag(),tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace areikonalsolution" );
#endif

}
