# TDD_GTest
Test Driven Development with Google Test

# C++ Project using CMake and GTest

> Requirements: `g++` and `CMake` installed

### Lets start with a simple C++ hello_world with CMake

Steps:
1. Create the [source](https://github.com/JoanaMota/TDD_GTest/blob/main/Cpp/src/hello_world.cpp) file.
2. Create the [`CMakeLists.txt`](https://github.com/JoanaMota/TDD_GTest/blob/main/Cpp/CMakeLists.txt) file. [A basic starting point for creating `CMakeLists.txt` files](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html)
3. Create a `build` folder.
4. Inside the created build folder run `cmake ..` for generating the build files;
5. Again inside the created build folder run `make` for building and linking;
6. Execute the program.

Afterwards you should have the following folder structure:
```
.
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── hello_world
│   └── Makefile
├── CMakeLists.txt
└── src
    └── hello_world.cpp
```

### Add GTest to your project's `CMakeLists.txt`

You have several ways of doing this which are explained in the [GTest Documentation](https://github.com/google/googletest/tree/master/googletest#generic-build-instructions).

I went for the [*Standalone CMake Project*](https://github.com/google/googletest/tree/master/googletest#standalone-cmake-project):
- Followed the steps on the documentation.
- Created a folder for the tests.
- Added a `CMakeLists.txt` for the tests folder
- Updated the main [`CMakeLists.txt`](https://github.com/JoanaMota/TDD_GTest/blob/main/Cpp/CMakeLists.txt) to include the tests:
```
add_subdirectory(googletest)
add_subdirectory(tests)
```
- Filled the [`CMakeLists.txt`](https://github.com/JoanaMota/TDD_GTest/blob/main/Cpp/tests/CMakeLists.txt) of the tests.
- Compiled again (with `make` inside the build folder).
- The tests will be inside `build/tests`.

Every time you want to had a new test you just need to add the following lines:
```
add_executable(ut_hello_world ut_hello_world.cpp)
target_link_libraries(ut_hello_world gtest_main)
add_test(NAME ut_hello_world_test COMMAND ut_hello_world)
```

Now your folding structure should look like this:
```
.
├── build
│   ├── bin
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── CTestTestfile.cmake
│   ├── googletest
│   ├── hello_world
│   ├── lib
│   ├── Makefile
│   ├── Testing
│   └── tests
├── CMakeLists.txt
├── googletest
│   ├── ...
├── src
│   └── hello_world.cpp
└── tests
    ├── CMakeLists.txt
    └── ut_hello_world.cpp
```

### Develop your functions using TDD

Imagine we need to create a function that divides 2 values:

1. Create simple test case
```cpp
TEST(Functions, Division)
{
    EXPECT_EQ(division(4, 2), 2);
}
```
2. See the compilation fail
```
error: ‘division’ was not declared in this scope
     EXPECT_EQ(division(4, 2), 2);
```
3. Make it compile the fastest way possible
```cpp
int division(int a, int b)
{
    return 0;
}
```
4. Run the test and see it fail (RED Phase)
```
Expected equality of these values:
  division(4, 2)
    Which is: 0
  2
[  FAILED  ] Functions.Division (0 ms)
```
5. Create logic only to make the existent test cases pass (REFACTOR Phase)
```cpp
int division(int a, int b)
{
    return a / b;
}
```
6. Run test cases and see them pass (GREEN Phase)
```
[----------] 1 test from Functions
[ RUN      ] Functions.Division
[       OK ] Functions.Division (0 ms)
[----------] 1 test from Functions (0 ms total)
```
7. Go back to add more tests to make sure that your functions accomplishes everything that is expected
```cpp
EXPECT_EQ(division(4, 0), 0);
```
8. Run test cases (RED Phase)
9. Refactor production code to make the new existent test cases pass
```cpp
int division(int a, int b)
{
    if (0 == b)
    {
        std::cout << "Math error: Attempted to divide by Zero" << std::endl;
        return 0;
    }
    return a / b;
}
```
10. Run tests and see them pass (GREEN Phase)





