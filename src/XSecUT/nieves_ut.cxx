
#include "CommonXSec.h"

using namespace std;
using namespace genie;
using namespace boost::unit_test;

#include "Physics/QuasiElastic/XSection/QELUtils.h"
// nieves-specific
#include "Physics/QuasiElastic/XSection/NievesQELCCPXSec.h"

void nieves_ut()
{

   // this part below is identical between lwlyn and niev !!!
   //
   InitialState istate( 6, 12, 14 ); // tgt=Carbon, projectile=nu_mu
   istate.TgtPtr()->SetHitNucPdg( 2112 ); // "hit nucleon" is neutron

   // kinematics
   //
   double Ev = 3; // in GeV
   TLorentzVector nup4(0., 0., Ev, Ev); //px, py, pz, E
   istate.SetProbeP4( nup4 );
   //
   ProcessInfo  procinfo( kScQuasiElastic, kIntWeakCC );
   //
   Interaction inter( istate, procinfo );

   NievesQELCCPXSec niev;
   // niev.Configure("Default");
   // niev.Configure("Dipole");
   niev.Configure( "ZExp" ); // as of trunk/v3, most recent valid configuration

   RgKey nuclkey = "IntegralNuclearModel";
   const NuclearModelI* nucl_model = dynamic_cast< const NuclearModelI* >(
     niev.SubAlg(nuclkey) );
   BOOST_CHECK( nucl_model );

   // CM frame scattering angles of the outgoing lepton, measured with respect
   // to the boost direction for going from the CM frame to the lab frame
   double cos_theta_0 = 0.5;
   double phi_0 = 0.;

   double dummy_binding_energy = 0.;
   double dummy_min_angle_EM = 0.;

   QELEvGen_BindingMode_t hitNucleonBindingMode = kUseNuclearModel;

   double xsec = utils::ComputeFullQELPXSec(&inter, nucl_model, &niev,
     cos_theta_0, phi_0, dummy_binding_energy, hitNucleonBindingMode,
     dummy_min_angle_EM, true);

   BOOST_CHECK( niev.ValidProcess( &inter ) );

   BOOST_REQUIRE_NE( xsec, 0. );

   // this is for "ZExp", towards v3-series
//   BOOST_CHECK_CLOSE( xsec, 1.738095e-11, tolerance_in_percent );
   BOOST_CHECK_CLOSE( xsec, cc_xsec::nieves::xsec_default, tolerance_in_percent );

   return;
}
