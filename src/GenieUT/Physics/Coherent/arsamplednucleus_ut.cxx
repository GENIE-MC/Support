#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif
#include "Physics/Coherent/XSection/ARSampledNucleus.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;
using namespace alvarezruso;

void arsamplednucleus_ut()
{
  unsigned int sampling=20;
  ARSampledNucleus* ar=new ARSampledNucleus(6,12,sampling);
  std::ostringstream os;
  std::string s;
#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace arsamplednucleus {" );
#endif

  unsigned int valint=ar->A();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int A = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint, coh_xsec::arsamplednucleus::A );
#endif

  valint=ar->Z();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int Z = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint, coh_xsec::arsamplednucleus::Z );
#endif

  valint=ar->N();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int N = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint, coh_xsec::arsamplednucleus::N );
#endif

  unsigned int i=12,j=22; // i,j has to be less than value of 'sampling' else it causes a crash
  double valdbl=ar->Density(i,j);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double density = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::density, tolerance_in_percent );
#endif

  valdbl=ar->DensityOfCentres(i,j);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double densityofcentres = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::densityofcentres, tolerance_in_percent );
#endif

  valdbl=ar->Radius(i,j);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double radius = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::radius, tolerance_in_percent );
#endif

  valdbl=ar->RadiusMax();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double radiusmax = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::radiusmax, tolerance_in_percent );
#endif

  valdbl=ar->SamplePoint1(i);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double samplepoint1 = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::samplepoint1, tolerance_in_percent );
#endif

  valdbl=ar->SamplePoint2(j);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double samplepoint2 = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::samplepoint2, tolerance_in_percent );
#endif

  valint=ar->GetSampling();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int sample = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint, coh_xsec::arsamplednucleus::sample );
#endif

  valint=ar->GetNDensities();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int ndensities = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint, coh_xsec::arsamplednucleus::ndensities );
#endif

  valdbl=ar->CalcMatterDensity(0.86);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double matterdensity = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::matterdensity, tolerance_in_percent );
#endif

  valdbl=ar->CalcNumberDensity(0.86);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valdbl;
  s = "static const double numberdensity = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_CLOSE( valdbl, coh_xsec::arsamplednucleus::numberdensity, tolerance_in_percent );
#endif

#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace arsamplednucleus" );
#endif
  return;
}
