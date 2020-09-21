# Google Falgs and Google Log Tutorials
This repository contains my tutorials code for using Google Falgs and Google Log in my c++ projects.  


# Commandline Flag and Commandline Argument

**Commandline flags**: start with `-` for example `-l` or `-f`. 
`-l` takes no argument, and `-f` takes a string (/path/to/file) as an argument.
**Commandline arguments**: `mumbo` and `jumbo`, which don't start with a dash commandline arguments.

```
grep -l -f /path/to/file mumbo jumbo
```
 
Within a single source-code file that defines and use flags that are meaningful to that file, any application that links in that file will get the flags, and the gflags library will automatically handle that flag appropriately.


# Defining Flags In Program
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

# Accessing the Flag

Defined flags are available to the program as just a normal variable, with the prefix `FLAGS_`. For example:

```cpp
  if (FLAGS_languages.find("finnish") != string::npos)
     HandleFinnish();
```


# RegisterFlagValidator: Sanity-checking Flag Values
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
# Putting It Together
First you need to call
```cpp
gflags::ParseCommandLineFlags(&argc, &argv, true);
```
The last argument is called "remove_flags". If true, then ParseCommandLineFlags removes the flags and their arguments from argv, and modifies argc appropriately. In this case, after the function call, argv will hold only commandline arguments, and not commandline flags.




# Special Flags


Refs: [1](https://gflags.github.io/gflags/)



[![Build Status](https://travis-ci.com/behnamasadi/gflag_glog_tutorials.svg?branch=master)](https://travis-ci.com/behnamasadi/gflag_glog_tutorials)
![alt text](https://img.shields.io/badge/license-BSD-blue.svg)

