#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif
#include "Physics/Coherent/XSection/ARConstants.h"

#include "Framework/Interaction/Interaction.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;
using namespace alvarezruso;

void arconstants_ut()
{
  double val;
  val=Hbar();
  std::ostringstream os;

  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Hbar, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Hbar = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif
  /*
  val=Ma_Nucleon();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Ma_Nucleon, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Ma_Nucleon = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=Mv_Nucleon();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Mv_Nucleon, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Mv_Nucleon = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=Ma_Delta();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Ma_Delta, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Ma_Delta = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=Mv_Delta();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Mv_Delta, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Mv_Delta = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=GAxial();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::GAxial, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double GAxial = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=Rho0();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Rho0, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Rho0 = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=CA4_A();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::CA4_A, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double CA4_A = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=CA5_A();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::CA5_A, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double CA5_A = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=CA4_B();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::CA4_B, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double CA4_B = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=CA5_B();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::CA5_B, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double CA5_B = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=PiDecayConst();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::PiDecayConst, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double PiDecayConst = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=DeltaNCoupling();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::DeltaNCoupling, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double DeltaNCoupling = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=CosCabibboAngle();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::CosCabibboAngle, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double CosCabibboAngle = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=SinWeinbergAngle();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::SinWeinbergAngle, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double SinWeinbergAngle = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=GFermi();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::GFermi, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double GFermi = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=ElectronMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::ElectronMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double ElectronMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=MuonMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::MuonMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double MuonMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=TauMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::TauMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double TauMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=ProtonMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::ProtonMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double ProtonMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=NucleonMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::NucleonMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double NucleonMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=NucleonMassSq();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::NucleonMassSq, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double NucleonMassSq = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=DeltaPMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::DeltaPMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double DeltaPMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=Delta0Mass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Delta0Mass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Delta0Mass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=PiPMass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::PiPMass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double PiPMass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=Pi0Mass();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::Pi0Mass, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double Pi0Mass = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=cm38Conversion();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::cm38Conversion, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double cm38Conversion = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif

  val=NCFactor();
  BOOST_CHECK_CLOSE( val, coh_xsec::arconstant::NCFactor, tolerance_in_percent );
#ifdef PRINTOUT  
  os.clear();
  os.str("");
  os << val;
  std::string s = "static const double NCFactor = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( "namespace arconstant {" );
  UpdateBenchmark::Instance()->Write( s );
#endif
  */
  return;
}
