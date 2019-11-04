#include <string>
#include <complex>

#include "BoostUtils.h"
#include "BenchmarkCriteria.h"

#ifdef PRINTOUT
#include "UpdateBenchmark.h"
#endif
#include "Physics/Coherent/XSection/ARWavefunction.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;
using namespace alvarezruso;

void arwavefunction_ut()
{
  unsigned int sampling=8;
  ARWavefunction ar(sampling);
  std::ostringstream os;
  std::string s;
  unsigned int valint;
  complex<double> valcmplx,valcmplx1;
  vector<complex<double>> v;
  ar.set(6,0,complex(0.1,-0.1));
  ar.set(6,1,complex(0.2,-0.2));
  ar.set(6,2,complex(0.3,-0.3));
  ar.set(6,3,complex(0.4,-0.4));


#ifdef PRINTOUT
  UpdateBenchmark::Instance()->Write( "namespace arwavefunction {" );
#endif

  valint=ar.sampling();
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valint;
  s = "static const unsigned int sampling = " + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valint, coh_xsec::arwavefunction::sampling );
#endif

  v=ar[6];

  valcmplx=ar.get(6,0);
  valcmplx1=ar(6,0);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> get60" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valcmplx.real(), coh_xsec::arwavefunction::get60.real() );
  BOOST_CHECK_EQUAL(valcmplx.imag(), coh_xsec::arwavefunction::get60.imag() );
  BOOST_CHECK_EQUAL(valcmplx1.real(), coh_xsec::arwavefunction::get60.real() );
  BOOST_CHECK_EQUAL(valcmplx1.imag(), coh_xsec::arwavefunction::get60.imag() );
  BOOST_CHECK_EQUAL(v[0].real(), coh_xsec::arwavefunction::get60.real() );
  BOOST_CHECK_EQUAL(v[0].imag(), coh_xsec::arwavefunction::get60.imag() );
#endif

  valcmplx=ar.get(6,1);
  valcmplx1=ar(6,1);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> get61" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valcmplx.real(), coh_xsec::arwavefunction::get61.real() );
  BOOST_CHECK_EQUAL(valcmplx.imag(), coh_xsec::arwavefunction::get61.imag() );
  BOOST_CHECK_EQUAL(valcmplx1.real(), coh_xsec::arwavefunction::get61.real() );
  BOOST_CHECK_EQUAL(valcmplx1.imag(), coh_xsec::arwavefunction::get61.imag() );
  BOOST_CHECK_EQUAL(v[1].real(), coh_xsec::arwavefunction::get61.real() );
  BOOST_CHECK_EQUAL(v[1].imag(), coh_xsec::arwavefunction::get61.imag() );
#endif

  valcmplx=ar.get(6,2);
  valcmplx1=ar(6,2);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> get62" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valcmplx.real(), coh_xsec::arwavefunction::get62.real() );
  BOOST_CHECK_EQUAL(valcmplx.imag(), coh_xsec::arwavefunction::get62.imag() );
  BOOST_CHECK_EQUAL(valcmplx1.real(), coh_xsec::arwavefunction::get62.real() );
  BOOST_CHECK_EQUAL(valcmplx1.imag(), coh_xsec::arwavefunction::get62.imag() );
  BOOST_CHECK_EQUAL(v[2].real(), coh_xsec::arwavefunction::get62.real() );
  BOOST_CHECK_EQUAL(v[2].imag(), coh_xsec::arwavefunction::get62.imag() );
#endif

  valcmplx=ar.get(6,3);
  valcmplx1=ar(6,3);
#ifdef PRINTOUT
  os.clear();
  os.str("");
  os << valcmplx;
  s = "static const std::complex<double> get63" + os.str() + ";" ;
  UpdateBenchmark::Instance()->Write( s );
#else
  BOOST_CHECK_EQUAL(valcmplx.real(), coh_xsec::arwavefunction::get63.real() );
  BOOST_CHECK_EQUAL(valcmplx.imag(), coh_xsec::arwavefunction::get63.imag() );
  BOOST_CHECK_EQUAL(valcmplx1.real(), coh_xsec::arwavefunction::get63.real() );
  BOOST_CHECK_EQUAL(valcmplx1.imag(), coh_xsec::arwavefunction::get63.imag() );
  BOOST_CHECK_EQUAL(v[3].real(), coh_xsec::arwavefunction::get63.real() );
  BOOST_CHECK_EQUAL(v[3].imag(), coh_xsec::arwavefunction::get63.imag() );
#endif





#ifdef PRINTOUT
   UpdateBenchmark::Instance()->Write( "} // end namespace wavefunction" );
#endif
  return;
}
