#include "CommonXSec.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include "Physics/QuasiElastic/XSection/LwlynSmithFFCC.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;

void lwlyn_cc_ff_ut()
{

   EventRecord* evt = new SynthEvent();

   LwlynSmithFFCC* lwffcc = new LwlynSmithFFCC();
   
   BOOST_CHECK( lwffcc != 0 );

   lwffcc->Configure( "Dipole" );
   
   double f1v = lwffcc->F1V( evt->Summary() );

   BOOST_CHECK_CLOSE( f1v, qel_xsec::lwlynffcc::f1v_default,  tolerance_in_percent );

   double xif2v = lwffcc->xiF2V( evt->Summary() );

   BOOST_CHECK_CLOSE( xif2v, qel_xsec::lwlynffcc::xif2v_default,  tolerance_in_percent );

   double fa = lwffcc->FA( evt->Summary() );

   BOOST_CHECK_CLOSE( fa, qel_xsec::lwlynffcc::fa_default,  tolerance_in_percent );

   double fp = lwffcc->Fp( evt->Summary() );

   BOOST_CHECK_CLOSE( fp, qel_xsec::lwlynffcc::fp_default,  tolerance_in_percent );

#ifdef PRINTOUT
   std::ostringstream os;
   UpdateBenchmark::Instance()->Write( "namespace lwlynffcc {" );
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
   UpdateBenchmark::Instance()->Write( "} // end namespace lwlynffcc" );
#endif

   delete evt;
   delete lwffcc;

   return;

}
