#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include <iostream>

#include "Framework/Algorithm/AlgConfigPool.h"
#include "Physics/XSectionIntegration/XSecIntegratorI.h"
#include "Framework/Conventions/GBuild.h"
#include "Framework/Conventions/Constants.h"
#include "Framework/Conventions/Units.h"
#include "Framework/Conventions/RefFrame.h"
#include "Framework/Messenger/Messenger.h"
#include "Framework/ParticleData/PDGCodes.h"
#include "Framework/ParticleData/PDGUtils.h"
#include "Physics/Coherent/XSection/AlvarezRusoCOHPiPXSec.h"
#include "Framework/Utils/HadXSUtils.h"
#include "Framework/Utils/KineUtils.h"
#include "Framework/Utils/RunOpt.h"

#include "Physics/Coherent/XSection/ARConstants.h"
#include "Physics/Coherent/XSection/ARSampledNucleus.h"
#include "Physics/Coherent/XSection/AlvarezRusoCOHPiPDXSec.h"
#include "Physics/Coherent/XSection/AREikonalSolution.h"


#include "SynthEvent.h"

using namespace genie;
using namespace boost::unit_test;
using namespace genie::constants;
using namespace genie::utils;

using namespace alvarezruso;

void alvarezrusocohpipxsec_ut()
{
  std::ostringstream os;
  string s;

  string tune_name = RunOpt::Instance()->Tune()->Name();
   
  if ( tune_name.find("G00_00a") == string::npos )
    {
      RunOpt::Instance()->SetTuneName("G00_00a_00_000" );
    }
   
  EventRecord* synth_event = new SynthEventCOH();
  AlvarezRusoCOHPiPXSec* ar = new AlvarezRusoCOHPiPXSec();
  ar->Configure("Default" );
#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace alvarezrusocohpipxsec {" );
#endif

  double xsec = ar->XSec( synth_event->Summary() , kPSElOlOpifE );
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << xsec;
  s = "static const double xsec = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(xsec,coh_xsec::alvarezrusocohpipxsec::xsec,tolerance_in_percent );
#endif

   Algorithm* xsec_int = (Algorithm*)(ar->SubAlg("XSec-Integrator"));
   Registry rg_xsec_int_modi( xsec_int->GetConfig() );
   string gsl_min_eval = "gsl-min-eval";
   string gsl_max_eval = "gsl-max-eval";
   rg_xsec_int_modi.Set( gsl_min_eval, 1 );
   rg_xsec_int_modi.Set( gsl_max_eval, 10 );
   xsec_int->Configure( rg_xsec_int_modi );
   double arintegral = ar->Integral( synth_event->Summary() );
#ifdef PRINTOUT
   os.clear();
   os.str("");
   os << arintegral;
   s = "static const double arintegral = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
#else
   BOOST_CHECK_CLOSE( arintegral,  coh_xsec::alvarezrusocohpipxsec::arintegral, tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace alvarezrusocohpipxsec" );
#endif

  delete ar;
  delete synth_event;
   
  return;

}
