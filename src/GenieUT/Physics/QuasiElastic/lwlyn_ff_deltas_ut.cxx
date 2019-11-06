#include "CommonXSec.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include "Physics/QuasiElastic/XSection/LwlynSmithFFDeltaS.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;

void lwlyn_ff_deltas_ut()
{

   EventRecord* evt = new SynthEvent();

   LwlynSmithFFDeltaS* lwffds = new LwlynSmithFFDeltaS();
   
   BOOST_CHECK( lwffds != 0 );

   lwffds->Configure( "Dipole" );
   
   double f1v = lwffds->F1V( evt->Summary() );

   BOOST_CHECK_CLOSE( f1v, qel_xsec::lwlynffds::f1v_default,  tolerance_in_percent );

   double xif2v = lwffds->xiF2V( evt->Summary() );

   BOOST_CHECK_CLOSE( xif2v, qel_xsec::lwlynffds::xif2v_default,  tolerance_in_percent );

   double fa = lwffds->FA( evt->Summary() );

   BOOST_CHECK_CLOSE( fa, qel_xsec::lwlynffds::fa_default,  tolerance_in_percent );

   double fp = lwffds->Fp( evt->Summary() );

   BOOST_CHECK_CLOSE( fp, qel_xsec::lwlynffds::fp_default,  tolerance_in_percent );

#ifdef PRINTOUT
   std::ostringstream os;
   UpdateBenchmark::Instance()->Write( "namespace lwlynffds {" );
   os << f1v;
   std::string s = "static const double f1v_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   os.clear();
   os.str("");
   os << xif2v;
   s = "static const double xif2v_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   os.clear();
   os.str("");
   os << fa;
   s = "static const double fa_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   os.clear();
   os.str("");
   os << fp;
   s = "static const double fp_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   UpdateBenchmark::Instance()->Write( "} // end namespace lwlynffds" );
#endif

   delete evt;
   delete lwffds;

   return;

}
