
#include "UpdateBenchmark.h"

#include "Framework/Messenger/Messenger.h"
#include "Framework/Utils/RunOpt.h"

using namespace std;
using namespace genie;
//using namespace boost::unit_test;

extern void lwlyn_ut();
extern void nieves_ut();
//extern void singlekaon_ut();
extern void reinsehgal_ut();

int main( /* int argc, char* argv[] */ )
{

   Messenger::Instance()->SetPrioritiesFromXmlFile("Messenger_whisper.xml");
   RunOpt::Instance()->SetTuneName(); // It'll be "Default" which in v3.x.y is G18_02a

   UpdateBenchmark* inst = UpdateBenchmark::Instance();
   
   inst->Write( "#ifndef BENCHMARK_CRITERIA_H" );
   inst->Write( "#define BENCHMARK_CRITERIA_H" );
   inst->Write( " " );
   inst->Write( "static const double tolerance_in_percent = 0.001;" );
   inst->Write( " " );
   
   // CC
   
   inst->Write( "namespace cc_xsec {" );
   inst->Write( " " );
   
   lwlyn_ut();
   
   inst->Write( " " );
   
   nieves_ut();
   
   inst->Write( " " );
   inst->Write( "} // end namespace cc_xsec" );
   inst->Write( " " );
   
   // COH
   
   inst->Write( "namespace coh_xsec {" );
   inst->Write( " " );
   
   reinsehgal_ut();
   
   inst->Write( " " );
   inst->Write( "} // end namespace coh_xsec" );
   
   // end of the story
   
   inst->Write( " " );
   inst->Write( "#endif" );
   inst->Write(" " );
   
   return 0;

}
