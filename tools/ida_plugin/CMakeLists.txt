cmake_minimum_required(VERSION 3.20)
project(ee_mac_lifter CXX)
# Build:
#   IDASDK=$HOME/ida-sdk cmake -B build -G Ninja -DIDA_INSTALL=$HOME/ida-pro-9.4
#   cmake --build build
find_package(idasdk REQUIRED)
ida_add_plugin(ee_mac_lifter SOURCES ee_mac_lifter.cpp)
