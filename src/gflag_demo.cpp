//https://github.com/gflags/gflags/issues/43
#define STRIP_FLAG_HELP 1
#include <gflags/gflags.h>
#include <string>
#include <iostream>
#include <cstdint>
/*
you can pass the flags like any of these:
./main --languages="chinese,japanese,korean"
./main -languages="chinese,japanese,korean"
./main --languages "chinese,japanese,korean"
./main -languages "chinese,japanese,korean"

For boolean flags, the possibilities are slightly different:
./main --big_menu
./main --nobig_menu
./maino --big_menu=true
./main --big_menu=false

*/


DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german", "comma-separated list of languages to offer in the 'lang' menu");


//Sanity-checking Flag Values
static bool ValidatePort(const char* flagname, int value) {
   if (value > 0 && value < 32768)   // value is ok
     return true;
   printf("Invalid value for --%s: %d\n", flagname, (int)value);
   return false;
}
DEFINE_int32(port, 0, "What port to listen on");
DEFINE_validator(port, &ValidatePort);

void HandleFinnish(std::string languages)
{
    std::cout<<languages <<std::endl;
}





int main(int argc, char ** argv)
{
    gflags::SetUsageMessage("my custom help msg with --help");
    gflags::ParseCommandLineFlags(&argc, &argv, true);


    std::cout<< "FLAGS_big_menu : " << FLAGS_big_menu << "\n";
    

    if (FLAGS_big_menu)
        FLAGS_languages += ",klingon";   // implied by --consider_made_up_languages
    if (FLAGS_languages.find("finnish") != std::string::npos)
        HandleFinnish(FLAGS_languages);
    

    gflags::ShutDownCommandLineFlags();
    
}
