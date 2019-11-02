#include "CommonXSec.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include "Physics/QuasiElastic/XSection/LwlynSmithFFNC.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;

void lwlyn_ff_nc_ut()
{

   EventRecord* evt = new SynthEvent();
   evt->Summary()->SetProcInfo( ProcessInfo( kScQuasiElastic, kIntWeakNC ) );

   LwlynSmithFFNC* lwffnc = new LwlynSmithFFNC();
   
   BOOST_CHECK( lwffnc != 0 );

   lwffnc->Configure( "Dipole" );
   
   double f1v = lwffnc->F1V( evt->Summary() );

   BOOST_CHECK_CLOSE( f1v, qel_xsec::lwlynffnc::f1v_default,  tolerance_in_percent );

   double xif2v = lwffnc->xiF2V( evt->Summary() );

   BOOST_CHECK_CLOSE( xif2v, qel_xsec::lwlynffnc::xif2v_default,  tolerance_in_percent );

   double fa = lwffnc->FA( evt->Summary() );

   BOOST_CHECK_CLOSE( fa, qel_xsec::lwlynffnc::fa_default,  tolerance_in_percent );

   double fp = lwffnc->Fp( evt->Summary() );

   BOOST_CHECK_CLOSE( fp, qel_xsec::lwlynffnc::fp_default,  tolerance_in_percent );

#ifdef PRINTOUT
   std::ostringstream os;
   UpdateBenchmark::Instance()->Write( "namespace lwlynffnc {" );
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
   UpdateBenchmark::Instance()->Write( "} // end namespace lwlynffnc" );
#endif

   delete evt;
   delete lwffnc;

   return;

}
