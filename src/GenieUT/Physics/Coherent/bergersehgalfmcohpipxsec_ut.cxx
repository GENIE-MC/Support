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
#include "Physics/Coherent/XSection/BergerSehgalFMCOHPiPXSec2015.h"
#include "Framework/Utils/HadXSUtils.h"
#include "Framework/Utils/KineUtils.h"
#include "Framework/Utils/RunOpt.h"

#include "SynthEvent.h"

using namespace genie;
using namespace boost::unit_test;
using namespace genie::constants;
using namespace genie::utils;


void bergersehgalfmcohpipxsec_ut()
{
  std::ostringstream os;
  string s;

  string tune_name = RunOpt::Instance()->Tune()->Name();
   
  if ( tune_name.find("G00_00a") == string::npos )
    {
      RunOpt::Instance()->SetTuneName("G00_00a_00_000" );
    }
   
  EventRecord* synth_event = new SynthEventCOH();
  BergerSehgalFMCOHPiPXSec2015* bs = new BergerSehgalFMCOHPiPXSec2015();
  bs->Configure("Default" );

#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace bergersehgalfmcohpipxsec {" );
#endif

  bool valid = bs -> ValidProcess( synth_event->Summary() );
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valid;
  s = "static const bool valid = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL( valid,coh_xsec::bergersehgalfmcohpipxsec::valid );
#endif


  double xsec = bs->XSec( synth_event->Summary() , kPSQ2yfE );
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << xsec;
  s = "static const double xsec = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(xsec,coh_xsec::bergersehgalfmcohpipxsec::xsec,tolerance_in_percent );
#endif

   Algorithm* xsec_int = (Algorithm*)(bs->SubAlg("XSec-Integrator"));
   Registry rg_xsec_int_modi( xsec_int->GetConfig() );
   string gsl_min_eval = "gsl-min-eval";
   string gsl_max_eval = "gsl-max-eval";
   rg_xsec_int_modi.Set( gsl_min_eval, 1 );
   rg_xsec_int_modi.Set( gsl_max_eval, 10 );
   xsec_int->Configure( rg_xsec_int_modi );
   double bsintegral = bs->Integral( synth_event->Summary() );
#ifdef PRINTOUT
   os.clear();
   os.str("");
   os << bsintegral;
   s = "static const double bsintegral = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
#else
   BOOST_CHECK_CLOSE( bsintegral,  coh_xsec::bergersehgalfmcohpipxsec::bsintegral, tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace bergersehgalfmcohpipxsec" );
#endif

  delete bs;
  delete synth_event;
   
  return;

}
