# LoopUnrollPass

This project implements a custom LLVM compiler pass that performs loop unrolling optimizations at the Intermediate Representation (IR) level. The pass is built using LLVM's new PassManager infrastructure.

## 🛠 Features

- Identifies and unrolls simple loops in LLVM IR.
- Designed for experimentation and learning about compiler optimizations.
- Cleanly integrates with LLVM as a dynamically loadable pass.

## 📁 Project Structure

```
LoopUnrollPassProject/
├── CMakeLists.txt          # Build configuration using CMake
└── LoopUnrollPass.cpp      # Custom LLVM pass implementation
```

## 🔧 Build Instructions

### Prerequisites

- LLVM and Clang installed (LLVM 12 or later recommended)
- CMake 3.10 or newer
- A C++ compiler (e.g., `clang++` or `g++`)

### Steps

```bash
git clone https://github.com/your-username/LoopUnrollPass.git
cd LoopUnrollPass
mkdir build
cd build
cmake ..
make
```

This will build the `LoopUnrollPass` as a shared object (`.so` or `.dylib`).

## 🧪 Running the Pass

You can apply the pass to an LLVM IR file:

```bash
opt -load-pass-plugin ./LoopUnrollPass.so -passes=loop-unroll -disable-output < input.ll
```

> Note: Make sure the LLVM tools like `opt` and `clang` are in your `PATH`.

## 📚 References

- [LLVM Writing an LLVM Pass](https://llvm.org/docs/WritingAnLLVMPass.html)
- [LLVM Pass Infrastructure](https://llvm.org/docs/NewPassManager.html)

## 🧑‍💻 Author

Damin Risho J V
