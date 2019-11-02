#include "CommonXSec.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include "Physics/QuasiElastic/XSection/TransverseEnhancementFFModel.h"
#include "Physics/QuasiElastic/XSection/BBA07ELFormFactorsModel.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;

void trans_enh_ff_ut()
{

   EventRecord* evt = new SynthEvent();

   TransverseEnhancementFFModel* trs = new TransverseEnhancementFFModel();

   BOOST_CHECK( trs != 0 );

   trs->Configure("Dufault");
   
   BBA07ELFormFactorsModel* bba07 = new BBA07ELFormFactorsModel();

   BOOST_CHECK( bba07 != 0 );

   bba07->Configure("Default");   
   trs->SetElFFBaseModel( bba07 );
   
   double gep = trs->Gep( evt->Summary() );
   
   BOOST_CHECK_CLOSE( gep, qel_xsec::transenh::gep_default,  tolerance_in_percent );
      
   double gmp = trs->Gmp( evt->Summary() );

   BOOST_CHECK_CLOSE( gmp, qel_xsec::transenh::gmp_default,  tolerance_in_percent );

   double gen = trs->Gen( evt->Summary() );

   BOOST_CHECK_CLOSE( gen, qel_xsec::transenh::gen_default,  tolerance_in_percent );

   double gmn = trs->Gmn( evt->Summary() );

   BOOST_CHECK_CLOSE( gmn, qel_xsec::transenh::gmn_default,  tolerance_in_percent );

#ifdef PRINTOUT
   std::ostringstream os;
   UpdateBenchmark::Instance()->Write( "namespace transenh {" );
   os << gep;
   std::string s = "static const double gep_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   os.clear();
   os.str("");
   os << gmp;
   s = "static const double gmp_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   os.clear();
   os.str("");
   os << gen;
   s = "static const double gen_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   os.clear();
   os.str("");
   os << gmn;
   s = "static const double gmn_default = " + os.str() + ";" ;
   UpdateBenchmark::Instance()->Write( s );
   UpdateBenchmark::Instance()->Write( "} // end namespace transenh" );
#endif

   delete evt;
   delete bba07;
   delete trs;

   return;

}
