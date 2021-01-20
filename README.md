# LearningCleanCpp

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Project full of exercises for getting into clean C++.

## References

 * [The C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) ([Source](https://github.com/isocpp/CppCoreGuidelines))
 * [The Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
 * [cppreference.com](https://en.cppreference.com/w/)
 * [Compiler Explorer](https://godbo.lt/)

## Dependencies

 * [GoogleTest](https://github.com/google/googletest) for testing, included as a git-submodule.
 * [GSL](https://github.com/microsoft/GSL) - The Guideline Support Library, included via FetchContent.
 * [Range-v3](https://github.com/ericniebler/range-v3) making ranges available to C++14, included via Conan.

## Usage

```bash
git clone --recursive https://github.com/Drako/LearningCleanCpp
cd LearningCleanCpp
mkdir build
cd build
conan install ../conanfile.txt
cmake -DCMAKE_BUILD_TYPE=Debug ..
```
