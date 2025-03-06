cmake_minimum_required(VERSION 3.15)

project(NintendoSDK-NEX CXX)

file(GLOB_RECURSE NEX_SOURCES
  "*.cpp"
)

add_library(NintendoSDK-NEX OBJECT ${NEX_SOURCES})

target_include_directories(NintendoSDK-NEX PUBLIC
  ../../include
  OnlineCore/include
  RendezVous/include
)

target_compile_options(NintendoSDK-NEX PRIVATE -fno-strict-aliasing)
target_compile_options(NintendoSDK-NEX PRIVATE -fno-exceptions)
target_compile_options(NintendoSDK-NEX PRIVATE -Wall -Wextra)
target_compile_options(NintendoSDK-NEX PRIVATE -Wno-invalid-offsetof)
target_compile_options(NintendoSDK-NEX PRIVATE -fvisibility=default -g1 -flto)
