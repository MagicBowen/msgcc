# msgcc

***

## Introduction

`msgcc` is a DSL written by C++ for describing the static valid range of fields in msg structure. It can auto generate the construct function which will fill the every described fields a valid value, and also generate a check function which will verify the incoming msg fields value according the given range described in DSL.

To learn more, view the source code of tests of msgcc in the test folder, I think it's quite simple for learn and use!

## Test and Install

To test msgcc, you need install [gtest](https://github.com/google/googletest). Gtest do not support auto installation now, so you need compile gtest, and manually put the include folder and lib like below:

> 1. Download gtest source code, and compile to generate the gtest library.
> 2. Select a path for manually installation of gtest. For example choose to manually install gtest to folder "/home/shared", enter "/home/shared" and create a folder named "gtest";
> 3. Copy the "gtest/incude" to "/home/shared/gtest", the folder will like "/home/shared/gtest/include/gtest";
> 4. Copy the "libgtest.a" which you compiled out before to "/home/shared/gtest/lib"
> 5. Now the path "/home/shared/gtest" will be your gtest root path.

- Get msgcc

~~~ bash
git clone git@github.com:MagicBowen/msgcc.git
~~~

- Build msgcc

~~~ bash
cd msgcc
mkdir build
cd build
cmake ..
make
~~~

- Install msgcc

~~~ bash
sudo make install
~~~

You can also install msgcc manually, just copy "msgcc/include" and "msgcc/build/src/libmsgcc.a" to your special installation path.

- Test msgcc

~~~ bash
cd build
cmake -DGTEST_ROOT="/home/shared/gtest" ..
make
./test/msgcc-test
~~~

The "~/project/gtest" should be replaced to your gtest installed path.

## Finally

The msgcc now only be supported on Linux platform, all the tests run passed on Unbuntu14.04. Other OS such as Windows or Mac has not been tested!