#include "Framework/Utils/RunOpt.h"
#include "Framework/Conventions/Units.h"

#include "Framework/Registry/Registry.h"

#include "Physics/Coherent/XSection/ReinSehgalCOHPiPXSec.h"

#include "SynthEvent.h"

using namespace std;
using namespace genie;

int main( void )
{

   // Select the tune
   // NOTE: We selecting G00_00a_00_000 because we want to handle
   //       ReinSehgalCOHPiPXSec model, and it's not clear if it's
   //       included in more modern tunes (perhaps it's replaced
   //       by BergerSehgal)
   //
   RunOpt::Instance()->SetTuneName("G00_00a_00_000");

   // Instanciate ReinSehgalCOHPiPXSec object
   //
   ReinSehgalCOHPiPXSec* rs_xsec = new ReinSehgalCOHPiPXSec();
   //
   // Configure it with "Default"
   //
   rs_xsec->Configure( "Default" );
   
   // Instaciate COH event (this one is generic enough)
   //
   EventRecord* synth_event = new SynthEventCOH();
   
   // Calculate the XSec for the interaction 
   //
   double xsec = rs_xsec->XSec( synth_event->Summary(), kPSxyfE );
   cout << " Unmodified RS XSec = " << xsec << endl;   
   
   // Now let's see what we can extract from the configuration 
   //
   // First, let's print the whole configuration
   //
   (rs_xsec->GetConfig()).Print( cout );
   
   // Now let's extract various config parameters one by one
   //
   string MaPath = "COH-Ma";  
   double Ma = (rs_xsec->GetConfig()).GetDouble(MaPath);
   cout << " Ma = " << Ma << endl;
   
   string RoPath = "COH-Ro";
   double Ro = (rs_xsec->GetConfig()).GetDouble(RoPath);
   cout << " Ro = " << Ro << endl;
   
   string ReImPath = "COH-ReImAmpl";
   double ReIm = (rs_xsec->GetConfig()).GetDouble(ReImPath);
   cout << " ReIm = " << ReIm << endl;
   
   string ModPCACPath = "COH-UseModifiedPCAC";
   bool ModPCAC = (rs_xsec->GetConfig()).GetBool(ModPCACPath);
   cout << " ModPCAC = " << ModPCAC << endl;
   
   // NOTE-1: What sits on the IntegratorPath is NOT a string;
   //         it's the name of an ** Algorithm ** !!!
   //
   // NOTE-2: Mechanically speaking, it's an RgAlg object 
   //         which is defined by a name (string) and a config (string)
   string IntegratorPath = "XSec-Integrator";
   RgAlg XSecIntegrator = (rs_xsec->GetConfig()).GetAlg(IntegratorPath);
   cout << " XSecIntegrator = " << XSecIntegrator.name << "/" << XSecIntegrator.config << endl;
   
   // Now let's create a custom registry, with some changes of the parameters
   // Let's make it a copy of the "default" one because it'll simplify our life it bit.
   // Keep in mind that the GetConfig() method returns a const Registry&, so you're
   // unlikely to be able to modify it (unless you do an ugly trick of casting away cosnt).
   //
   Registry config_modi( rs_xsec->GetConfig() );
   //
   // Now our new objet config_modi is NOT cosnt, and we can make modifications to it. 
   //
   config_modi.Set( ModPCACPath, false );
   config_modi.Set( ReImPath, 0.35 );
   //
   // Print out the modified config
   //
   config_modi.Print( cout );
      
   // Reconfigure the RS XSec object with the new config
   //
   rs_xsec->Configure( config_modi );
   
   // Check what XSec it generates now
   //
   double xsec_modi = rs_xsec->XSec( synth_event->Summary(), kPSxyfE );
   cout << " Modified RS XSec(modi) = " << xsec_modi << endl; 
   
   // now let's try to tweak sub-alogirithm
   //
   // when getting the sub-algorithm, we have to cast away cosnt which is an ugly trick
   // but unfortunately there's no direct way to set (a separate) sub-algorithm, e.g.
   // xsec integrator, but only through global config...
   //
   Algorithm* xsec_int = (Algorithm*)(rs_xsec->SubAlg("XSec-Integrator"));
   
   (xsec_int->GetConfig()).Print(cout);
   cout <<endl;
   
   Registry rg_xsec_int_modi( xsec_int->GetConfig() );
   string gsl_min_eval = "gsl-min-eval";
   string gsl_max_eval = "gsl-max-eval";
   rg_xsec_int_modi.Set( gsl_min_eval, 10 );
   rg_xsec_int_modi.Set( gsl_max_eval, 100 );
   xsec_int->Configure( rg_xsec_int_modi );
   
   // re-print, to check if config of sub-algorithm is modified
   //
   ( (rs_xsec->SubAlg("XSec-Integrator"))->GetConfig() ).Print(cout);
   cout << endl;
   
   double rs_integral = rs_xsec->Integral( synth_event->Summary() );
   cout << " rs_integral = " << rs_integral << endl;
        
   cout << " ENJOY THE REST OF YOUR DAY !!!" << endl;
      
   return 0;
   
}
