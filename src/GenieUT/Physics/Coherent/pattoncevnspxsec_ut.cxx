#include "BoostUtils.h"
#include "BenchmarkCriteria.h"
#include "SynthEvent.h"
#include "Framework/Utils/RunOpt.h"

#include <Math/Integrator.h>

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include "Framework/Algorithm/AlgConfigPool.h"
#include "Framework/Conventions/Constants.h"
#include "Framework/Conventions/RefFrame.h"
#include "Framework/Conventions/KineVar.h"
#include "Framework/Messenger/Messenger.h"
#include "Framework/ParticleData/PDGUtils.h"
#include "Framework/ParticleData/PDGLibrary.h"
#include "Framework/Utils/KineUtils.h"
#include "Framework/Numerical/MathUtils.h"
#include "Framework/Numerical/GSLUtils.h"
#include "Physics/NuclearState/NuclearUtils.h"
#include "Physics/XSectionIntegration/XSecIntegratorI.h"
#include "Physics/Coherent/XSection/PattonCEvNSPXSec.h"
#include "Physics/Coherent/XSection/NuclDensityMomentIntegrand.h"



using namespace boost::unit_test;

using namespace genie;
using namespace genie::utils;
using namespace genie::constants;


void pattoncevnspxsec_ut()
{
  std::ostringstream os;
  string s;

  string tune_name = RunOpt::Instance()->Tune()->Name();
   
  if ( tune_name.find("G00_00a") == string::npos )
    {
      RunOpt::Instance()->SetTuneName("G00_00a_00_000" );
    }
   
  EventRecord* synth_event = new SynthEventElastic();
  PattonCEvNSPXSec* pa = new PattonCEvNSPXSec();

  pa->Configure("Default" );
#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace pattoncevnspxsec {" );
#endif

  bool valid = pa -> ValidProcess( synth_event->Summary() );
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valid;
  s = "static const bool valid = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL( valid,coh_xsec::pattoncevnspxsec::valid );
#endif

  double xsec = pa->XSec( synth_event->Summary() , kPSQ2fE );
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << xsec;
  s = "static const double xsec = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(xsec,coh_xsec::pattoncevnspxsec::xsec,tolerance_in_percent );
#endif

   Algorithm* xsec_int = (Algorithm*)(pa->SubAlg("XSec-Integrator"));
   Registry rg_xsec_int_modi( xsec_int->GetConfig() );
   string gsl_min_eval = "gsl-min-eval";
   string gsl_max_eval = "gsl-max-eval";
   rg_xsec_int_modi.Set( gsl_min_eval, 1 );
   rg_xsec_int_modi.Set( gsl_max_eval, 2 );
   xsec_int->Configure( rg_xsec_int_modi );
   double paintegral = pa->Integral( synth_event->Summary() );
#ifdef PRINTOUT
   os.clear();
   os.str("");
   os << paintegral;
   s = "static const double paintegral = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
#else
   BOOST_CHECK_CLOSE( paintegral,  coh_xsec::pattoncevnspxsec::paintegral, tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace pattoncevnspxsec" );
#endif

  delete pa;
  delete synth_event;
   
  return;

}
