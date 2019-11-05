#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif
#include "Physics/Coherent/XSection/AlvarezRusoCOHPiPXSec.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;
using namespace alvarezruso;

void alvarezrusocohpipdxsec_ut()
{
  AlvarezRusoCOHPiPDXSec* ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kNu,kNieves);
  std::ostringstream os;
  std::string s;
  unsigned int valint;
  double valdbl;


#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace alvarezrusocohpipdxsec {" );
#endif

  valint=ar->GetSampling();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int sampling = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint,coh_xsec::alvarezrusocohpipdxsec::sampling );
#endif

  valdbl=ar->GetPiMass();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double pimass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::pimass,tolerance_in_percent );
#endif

  valdbl=ar->GetLeptonMass();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double leptonmass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::leptonmass,tolerance_in_percent );
#endif

  valdbl=ar->DXSec(4.0,1.5,0.32,1.2,-0.05,0.59);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_E_Nu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_E_Nu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_E_Nu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_E_Nu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kAntiNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_E_AntiNu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_E_AntiNu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kE,kAntiNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_E_AntiNu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_E_AntiNu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_E_Nu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_E_Nu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_E_Nu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_E_Nu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kAntiNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_E_AntiNu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_E_AntiNu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kE,kAntiNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_E_AntiNu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_E_AntiNu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Mu_Nu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Mu_Nu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Mu_Nu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Mu_Nu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kAntiNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Mu_AntiNu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Mu_AntiNu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kMu,kAntiNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Mu_AntiNu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Mu_AntiNu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Mu_Nu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Mu_Nu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Mu_Nu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Mu_Nu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kAntiNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Mu_AntiNu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Mu_AntiNu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kMu,kAntiNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Mu_AntiNu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Mu_AntiNu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Tau_Nu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Tau_Nu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Tau_Nu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Tau_Nu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kAntiNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Tau_AntiNu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Tau_AntiNu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kCC,kTau,kAntiNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_CC_Tau_AntiNu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_CC_Tau_AntiNu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Tau_Nu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Tau_Nu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Tau_Nu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Tau_Nu_Garcia,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kAntiNu,kNieves);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Tau_AntiNu_Nieves = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Tau_AntiNu_Nieves,tolerance_in_percent );
#endif

  ar=new AlvarezRusoCOHPiPDXSec(6,12,kNC,kTau,kAntiNu,kGarcia);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double DXSec_NC_Tau_AntiNu_Garcia = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(valdbl,coh_xsec::alvarezrusocohpipdxsec::DXSec_NC_Tau_AntiNu_Garcia,tolerance_in_percent );
#endif


#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace alvarezrusocohpipdxsec" );
#endif

}
