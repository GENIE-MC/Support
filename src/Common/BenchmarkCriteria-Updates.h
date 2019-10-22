#ifndef BENCHMARK_CRITERIA_H
#define BENCHMARK_CRITERIA_H
 
static const double tolerance_in_percent = 0.001;
 
namespace cc_xsec {
 
namespace lwlyn {
static const double xsec_default = 9.11464e-12;
} // end namespace lwlyn
 
namespace nieves {
static const double xsec_default = 1.7381e-11;
} // end namespace nieves
 
} // end namespace cc_xsec
 
namespace coh_xsec {
 
namespace reinsehgal {
static const double xsec_default = 1.74145e-11;
static const double xsec_use_modi_pcac_false = 2.00335e-11;
} // end namespace reinsehgal
 
} // end namespace coh_xsec
 
#endif
 
