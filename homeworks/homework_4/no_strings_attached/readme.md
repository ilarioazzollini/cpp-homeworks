# Prerequisites (tested with)

- Docker version 20.10.0, build 7287ab3 (on MacBook Pro)
- Ubuntu 20.04 container
- CMake version: 3.16.3
- clang version 10.0.0-4ubuntu1 
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin

# Add googletest as a submodule

https://github.com/google/googletest

```
cpp-homeworks ilarioazzollini$ cd homeworks/homework_4/no_strings_attached/

no_strings_attached ilarioazzollini$ ls
CMakeLists.txt		examples		no_strings_attached
build			external		readme.md

no_strings_attached ilarioazzollini$ git submodule add https://github.com/google/googletest.git external/googletest

no_strings_attached ilarioazzollini$ git submodule update --init --recursive
```

# Build and Test

```
cpp-homeworks $ docker run -it --rm -v $PWD/homeworks:/root/homeworks ubuntu20_cpp bash
root@4efc5d6cd8d2:~# cd homeworks/homework_4/no_strings_attached/
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# ls
CMakeLists.txt  examples  no_strings_attached  readme.md
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# cmake -S . -B build
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# cmake --build build -j 12
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j 12
```

Notice that `--test-dir build` works only with CMake 3.20+. If you have a previous version, you could simply `cd` to the build folder manually

```
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# cd build
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached/build# GTEST_COLOR=1 ctest --output-on-failure -j 12
```

# Run example applications (after successful build)

Run `split_strings`:
```
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# ./build/examples/split_strings
```

Run `trim_strings`:
```
root@4efc5d6cd8d2:~/homeworks/homework_4/no_strings_attached# ./build/examples/trim_strings
```