# cpp-logger

Logger for C++ >=11 std project

### How to use

Copy **logger.cpp** and **logger.h** to your project.


### Compilers compatibility

* g++ 9.3.0 (Ubuntu 20) - *?*
* cygwin 3.1.7 (Windows 10) - *OK*
* MinGW 5.4 (Windows 10) - *?*
* VS 16.0 (Visual Studio 2019) (Windows 10) - *OK*


### Functions

#### sprintf formatting style functions

* **Logger_Info_F(fmt, args...)** - green text
* **Logger_Warn_F(fmt, args...)** - yellow text
* **Logger_Error_F(fmt, args...)** - magenta text
* **Logger_Critical_F(fmt, args...)** - red text + exception (you can catch it)
* **Logger_Fatal_F(fmt, args...)** - red text + EXIT_FAILURE (immediate exit program)

#### Legacy functions

* **Logger_Info(msg)** - green text
* **Logger_Warn(msg)** - yellow text
* **Logger_Error(msg)** - magenta text
* **Logger_Critical(msg)** - red text + exception (you can catch it)
* **Logger_Fatal(msg)** - red text + EXIT_FAILURE (immediate exit program)
