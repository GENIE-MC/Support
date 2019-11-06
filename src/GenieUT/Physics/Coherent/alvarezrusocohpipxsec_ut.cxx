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
  //Interaction* cohint=synth_event->Summary();


  AlvarezRusoCOHPiPXSec* ar = new AlvarezRusoCOHPiPXSec();

  BOOST_CHECK( ar != 0 );

  ar->Configure("Default" );
   
  BOOST_CHECK( ar->ValidProcess( synth_event->Summary() ));

  double xsec = ar->XSec( synth_event->Summary() , kPSElOlOpifE );
  BOOST_REQUIRE_NE( xsec, 0. );

#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace alvarezrusocohpipxsec {" );
#endif
   
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << xsec;
  s = "static const double xsec = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(xsec,coh_xsec::alvarezrusocohpipxsec::xsec,tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace alvarezrusocohpipxsec" );
#endif

  delete ar;
  delete synth_event;
   
  return;

}
