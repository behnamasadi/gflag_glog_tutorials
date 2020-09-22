- [Google Falgs and Google Log Tutorials](#google-falgs-and-google-log-tutorials)
  * [Google Falgs](#google-falgs)
    + [Commandline Flag and Commandline Argument](#commandline-flag-and-commandline-argument)
    + [Defining Flags In Program](#defining-flags-in-program)
    + [Accessing the Flag](#accessing-the-flag)
    + [Sanity Checking Flag Values](#sanity-checking-flag-values)
    + [Putting It Together](#putting-it-together)
    + [Special Flags](#special-flags)
  * [Google Log](#google-log)

# Google Falgs and Google Log Tutorials
This repository contains my tutorials code for using Google Falgs and Google Log in my c++ projects.  


## Google Falgs
### Commandline Flag and Commandline Argument

**Commandline flags**: start with `-` for example `-l` or `-f`.
`-l` takes no argument, and `-f` takes a string (/path/to/file) as an argument.


**Commandline arguments**: `mumbo` and `jumbo`, which don't start with a dash commandline arguments.

```
grep -l -f /path/to/file mumbo jumbo
```
 
Within a single source-code file that defines and use flags that are meaningful to that file, any application that links in that file will get the flags, and the gflags library will automatically handle that flag appropriately.


### Defining Flags In Program
Just use the appropriate macro for the type you want the flag:

```
DEFINE_<variable_type>(name, default_value, "help text");
```
`variable_type` could be:

- DEFINE_bool: boolean
- DEFINE_int32: 32-bit integer
- DEFINE_int64: 64-bit integer
- DEFINE_uint64: unsigned 64-bit integer
- DEFINE_double: double
- DEFINE_string: C++ string

Example:

```cpp
DEFINE_string(languages, "english,french,german", "comma-separated list of languages to offer in the 'lang' menu");
```

### Accessing the Flag

Defined flags are available to the program as just a normal variable, with the prefix `FLAGS_`. For example:

```cpp
  if (FLAGS_languages.find("finnish") != string::npos)
     HandleFinnish();
```


### Sanity Checking Flag Values
After DEFINE-ing a flag, you may optionally register a validator function with the flag

```cpp
static bool ValidatePort(const char* flagname, int32 value) {
   if (value > 0 && value < 32768)   // value is ok
     return true;
   printf("Invalid value for --%s: %d\n", flagname, (int)value);
   return false;
}
DEFINE_int32(port, 0, "What port to listen on");
DEFINE_validator(port, &ValidatePort);
```
### Putting It Together
First you need to call
```cpp
gflags::ParseCommandLineFlags(&argc, &argv, true);
```
you can add your custome help message:
```cpp
gflags::SetUsageMessage("my custom help msg with --help");
```

You can pass the flags for `DEFINE_string(languages, "english,french,german", "comma-separated list of languages to offer in the 'lang' menu");`
in one of the following forms:
```
./main --languages="chinese,japanese,korean"
./main -languages="chinese,japanese,korean"
./main --languages "chinese,japanese,korean"
./main -languages "chinese,japanese,korean"
```
For the boolean flag `DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");`, the possibilities are slightly different:
```
./main --big_menu
./main --nobig_menu
./maino --big_menu=true
./main --big_menu=false
```
### Special Flags

There are a few flags defined by the commandlineflags module itself. to see the complete list just use `--help`
1) Reporting flags:
- --help
- --helpxml

2) Flags that affect how other flags are parsed:
- --undefok=flagname,flagname

for those names listed as the argument to --undefok, suppress the normal error-exit that occurs when --name is seen on the commandline, but name has not been DEFINED anywhere in the application

3) Recursive Flags:
cause other flag values to be set: `--fromenv`, `--tryfromenv`, `--flagfile`.



## Google Log

<small><i>TOC generated with <a href='http://ecotrust-canada.github.io/markdown-toc/'>markdown-toc</a></i></small>

Refs:  [1](https://gflags.github.io/gflags/)
[![Build Status](https://travis-ci.com/behnamasadi/gflag_glog_tutorials.svg?branch=master)](https://travis-ci.com/behnamasadi/gflag_glog_tutorials)
![alt text](https://img.shields.io/badge/license-BSD-blue.svg)

