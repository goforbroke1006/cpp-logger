# cpp-logger

Logger for C++ >=11 std project

Single header - **logger.h**

### Compilers compatibility

* g++ 9.3.0 (Ubuntu 20) - *OK*
* cygwin 3.1.7 (Windows 10) - *OK*
* MinGW 5.4 (Windows 10) - *OK*
* VS 16.0 (Visual Studio 2019) (Windows 10) - *OK*


### Functions

* **Logger_Info** - green text
* **Logger_Warn** - yellow text
* **Logger_Error** - magenta text
* **Logger_Critical** - red text + exception (you can catch it)
* **Logger_Fatal** - red text + EXIT_FAILURE (immediate exit program)