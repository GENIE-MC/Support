
// #include "CommonCOHXSec.h"

#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include "Framework/Interaction/Interaction.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;

#include "SynthEvent.h"

#include "Framework/Utils/RunOpt.h"
#include "Physics/Coherent/XSection/ReinSehgalCOHPiPXSec.h"

void reinsehgal_ut()
{
   string tune_name = RunOpt::Instance()->Tune()->Name();   
   if ( tune_name.find("G00_00a") == string::npos )
   {
      RunOpt::Instance()->SetTuneName("G00_00a_00_000" );
   }
   
   EventRecord* synth_event = new SynthEventCOH();
   ReinSehgalCOHPiPXSec* rs = new ReinSehgalCOHPiPXSec();

   rs->Configure("Default" );
   double xsec = rs->XSec( synth_event->Summary(), kPSxyfE );
#ifdef PRINTOUT
   std::ostringstream os;
   os << xsec;
   std::string s = "static const double xsec_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( "namespace reinsehgal {" );
   UpdateBenchmark::Instance()->Write( s );
#else
   BOOST_CHECK_CLOSE( xsec, coh_xsec::reinsehgal::xsec_default, tolerance_in_percent );
#endif

   Registry config_modi( rs->GetConfig() );
   string ModPCACPath = "COH-UseModifiedPCAC";
   config_modi.Set( ModPCACPath, false );
   rs->Configure( config_modi );
   xsec = rs->XSec( synth_event->Summary(), kPSxyfE ); 
#ifdef PRINTOUT
   os.clear();
   os.str("");
   os << xsec;
   s = "static const double xsec_use_modi_pcac_false = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
#else
   BOOST_CHECK_CLOSE( xsec,  coh_xsec::reinsehgal::xsec_use_modi_pcac_false, tolerance_in_percent );
#endif

   Algorithm* xsec_int = (Algorithm*)(rs->SubAlg("XSec-Integrator"));
   Registry rg_xsec_int_modi( xsec_int->GetConfig() );
   string gsl_min_eval = "gsl-min-eval";
   string gsl_max_eval = "gsl-max-eval";
   rg_xsec_int_modi.Set( gsl_min_eval, 10 );
   rg_xsec_int_modi.Set( gsl_max_eval, 100 );
   xsec_int->Configure( rg_xsec_int_modi );
   double rsintegral = rs->Integral( synth_event->Summary() );
#ifdef PRINTOUT
   os.clear();
   os.str("");
   os << rsintegral;
   s = "static const double rsintegral = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
#else
   BOOST_CHECK_CLOSE( rsintegral,  coh_xsec::reinsehgal::rsintegral, tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace reinsehgal" );
#endif
   
   RunOpt::Instance()->SetTuneName();// set tune name back to "Default"
   delete rs;
   delete synth_event;
   
   return;

}
