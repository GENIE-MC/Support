#ifndef BENCHMARK_CRITERIA_H
#define BENCHMARK_CRITERIA_H
 
static const double tolerance_in_percent = 0.001;
 
namespace qel_xsec {
 
namespace lwlyn {
static const double xsec_default = 4.09333e-11;
} // end namespace lwlyn
 
namespace nieves {
static const double xsec_default = 1.7381e-11;
} // end namespace nieves
 
namespace dipoleaxialff {
static const double fa_default = -1.03748;
} // end namespace dipoleaxialff
 
namespace dipoleelff {
static const double gep_default = 0.761465;
static const double gmp_default = 2.12677;
static const double gmn_default = -1.45671;
} // end namespace dipoleelff
 
namespace zexpaxialff {
static const double fa_default = -1.03345;
} // end namespace zexpaxialff
 
} // end namespace qel_xsec
 
namespace coh_xsec {
 
namespace reinsehgal {
static const double xsec_default = 1.74145e-11;
static const double xsec_use_modi_pcac_false = 2.00335e-11;
} // end namespace reinsehgal
 
} // end namespace coh_xsec
 
#endif
 
