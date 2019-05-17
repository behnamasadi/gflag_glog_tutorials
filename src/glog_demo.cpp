#include <glog/logging.h>
/*
http://rpg.ifi.uzh.ch/docs/glog.html

You can log a message by simply streaming things to LOG(<a particular severity level>)

severity level:
    INFO 
    WARNING 
    ERROR
    FATAL

Logging a FATAL message terminates the program (after the message is logged). 
Messages of a given seriousness are logged in the logfile for that seriousness, yet additionally in all logfiles of lower seriousness. E.g., a message of seriousness FATAL will be logged to the logfiles of seriousness FATAL, ERROR, WARNING, and INFO.


Except if generally determined, glog keeps writes output in a filename "/tmp/<program name>.<hostname>.<user name>.log.<severity level>.<date>.<time>.<pid>

By default, glog copies the log messages of severity level ERROR or FATAL to standard error (stderr) in addition to log files.

############################################Setting Flags############################################3

You can start your application with the following command line:

if gflag installed:
    ./your_app --<flag>

if gflag is not installed
    GLOG_flag ./glog_demo
or in the code:

    FLAGS_log_dir=std::string(".");
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel=0;
    
    
    
1)logtostderr (bool, default=false)
    Log messages to stderr instead of logfiles, for example: 
    ./your_app --logtostderr=1
    GLOG_logtostderr=1  ./your_app

    
2)stderrthreshold (int, default=2, which is ERROR)
    Copy log messages at or above this level to stderr in addition to logfiles. The numbers of severity levels INFO, WARNING, ERROR, and FATAL are 0, 1, 2, and 3, respectively, for example:  
    ./your_app --stderrthreshold=1
    GLOG_stderrthreshold=1  ./your_app

    
3)minloglevel (int, default=0, which is INFO) for example:  
    ./your_app --minloglevel=1
    GLOG_minloglevel=1  ./your_app
    
    
4)log_dir (string, default="")
    If specified, logfiles are written into this directory instead of the default logging directory. for example:
    ./your_app --log_dir="."
    GLOG_log_dir="."  ./your_app

    
    
    
#####################################Conditional / Occasional Logging#####################################

LOG_EVERY_N(INFO, 10) << "i is: " << google::COUNTER;
LOG_FIRST_N(INFO, 20) << "Got the " << google::COUNTER << "th ";
LOG_IF_EVERY_N(INFO, (size > 1024), 10) << "Got the " << google::COUNTER;

##################################### Debug Mode #####################################

    DLOG(INFO) << "something";
    DLOG_IF(INFO, i > 10) << "something happened";
    DLOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER;

    
CHECK Macros
Verbose Logging
Failure Signal Handler
Syslog
Strip Logging Messages

##################################### Google Style perror() #####################################


    
*/


int main(int argc, char* argv[]) 
{
    
    FLAGS_log_dir=std::string(".");
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel=0;
    
    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);

/*
 

*/
    int i=0;
    LOG(INFO) << "INFO " << ++i<< " i";
    LOG(WARNING) << "WARNING " << ++i << " i";
    LOG(ERROR) << "ERROR " << ++i << " i";
    //LOG(FATAL) << "Found " << ++i << " i"; // this will terminate the program
     int size=2000;
    for(std::size_t i=0;i<35;i++)
    {
        LOG_EVERY_N(INFO, 10) << "i is: " << google::COUNTER;
        LOG_FIRST_N(INFO, 3) << "Got the " << google::COUNTER << "th ";
        LOG_IF_EVERY_N(INFO, (size > 1024), 10) << "Got the " << google::COUNTER;
    }
    
    DLOG(INFO) << "only in debug mode";
    DLOG_IF(INFO, i > 10) << "only in debug mode i>10";
    DLOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER<< " in debug mode";

    PCHECK(write(1, NULL, 2) >= 0) << "Write NULL failed";
    
    //exit(5) ; //$?
}
