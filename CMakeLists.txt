cmake_minimum_required(VERSION 3.10)


project(LoopUnrollPass)


# set(LLVM_DIR "/path/to/llvm/lib/cmake/llvm") if not in the default dir


find_package(LLVM REQUIRED CONFIG)


include_directories(${LLVM_INCLUDE_DIRS})


add_library(LoopUnrollPass MODULE
  LoopUnrollPass.cpp
)


target_link_libraries(LoopUnrollPass PRIVATE ${LLVM_LIBRARIES})


target_compile_options(LoopUnrollPass PRIVATE -Wall -O2)

