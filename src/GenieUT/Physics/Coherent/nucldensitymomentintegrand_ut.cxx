#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif

#include <iostream>
#include <TMath.h>

#include "Framework/Messenger/Messenger.h"
#include "Physics/Coherent/XSection/NuclDensityMomentIntegrand.h"

using namespace genie;
using namespace boost::unit_test;
using namespace genie::utils::gsl::wrap;


void nucldensitymomentintegrand_ut()
{
  std::ostringstream os;
  string s;

  NuclDensityMomentIntegrand* nd = new NuclDensityMomentIntegrand(32,3);

#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace nucldensitymomentintegrand {" );
#endif

  int NDim=nd->NDim();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << NDim;
  s = "static const int NDim = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL( NDim,coh_xsec::nucldensitymomentintegrand::NDim );
#endif

  const double xin=0.25;
  double DoEval = nd->DoEval(xin);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << DoEval;
  s = "static const double DoEval = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE(DoEval,coh_xsec::nucldensitymomentintegrand::DoEval,tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace nucldensitymomentintegrand" );
#endif

  delete nd;
   
  return;

}
