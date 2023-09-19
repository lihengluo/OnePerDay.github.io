# Google BenchMark

来自google开发的CXX语言的基准测试库，提供一系列自动化的测试，通过迭代得到稳定解

### 使用方式

```bash
# for more details please dive to https://github.com/google/benchmark.git

# preinstall the requisites
sudo apt update && apt install git cmake vim 
# Check out the library.
git clone https://github.com/google/benchmark.git
# Go to the library root directory
cd benchmark
# Make a build directory to place the build output.
cmake -E make_directory "build"
# Generate build system files with cmake, and download any dependencies.
cmake -E chdir "build" cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release ../
# or, starting with CMake 3.13, use a simpler form:
# cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
# Build the library.
cmake --build "build" --config Release
# Test the built library.
cmake -E chdir "build" ctest --build-config Release
# install it globally
sudo cmake --build "build" --config Release --target install

```
**make sure  your dir like this**

```

/src
  /benchmark
    /build
      /src
        /libbenchmark.a
        /libbenchmark_main.a
      /test
    /include
  main.cc
  CMakeList.txts
        ...
```

```bash
# complie with c++11
g++ file -std=c++11 -isystem benchmark/include \
  -Lbenchmark/build/src -lbenchmark -lpthread -o file_exe
# exe
./file_exe
```

**write a CMake file to use benchmark library**

```cmake
# file is named as CMakeLists.txt
cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard, c++17,c++20 also supported
find_package(benchmark REQUIRED)      # Find the package benchmark
# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example ${SOURCE_FILES})
# Link the library to target
target_link_libraries(simple_example benchmark::benchmark)
```

### 运行示例

#### Basic Usage

```c++
#include <benchmark/benchmark.h>

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

//里面封装了main()函数
BENCHMARK_MAIN();
```

#### One Level Up

```cmake
static void BM_SetInsert(benchmark::State& state) {
  std::set<int> data;
  for (auto _ : state) {
  	# 可以暂停计时，精确要测量的部分
    state.PauseTiming();
    data = ConstructRandomSet(state.range(0));
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j)
      data.insert(RandomNumber());
  }
}
# 可以从外部为函数传递阐述，使用stage.range(*)调用对应参数
BENCHMARK(BM_SetInsert)
    ->Args({1<<10, 128})
    ->Args({2<<10, 128})
    ->Args({4<<10, 128})
    ->Args({8<<10, 128})
    ->Args({1<<10, 512})
    ->Args({2<<10, 512})
    ->Args({4<<10, 512})
    ->Args({8<<10, 512});
```

