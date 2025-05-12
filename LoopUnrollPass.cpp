#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Scalar/LoopUnrollPass.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils/UnrollLoop.h"
#include "llvm/Analysis/LoopAnalysisManager.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/InitializePasses.h"
#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

struct CustomLoopUnrollPass : PassInfoMixin<CustomLoopUnrollPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        auto &LI = FAM.getResult<LoopAnalysis>(F);
        auto &SE = FAM.getResult<ScalarEvolutionAnalysis>(F);
        auto &TTI = FAM.getResult<TargetIRAnalysis>(F);
        auto &DT = FAM.getResult<DominatorTreeAnalysis>(F);

        for (auto *L : LI) {
            if (!L->isLoopSimplifyForm()) continue;
            if (!SE.hasLoopInvariantBackedgeTakenCount(L)) continue;

            LoopUnrollOptions UnrollOpts;
            UnrollOpts.Count = 4;
            UnrollOpts.Force = true;

            if (UnrollLoop(L, UnrollOpts, &LI, &SE, &DT, &TTI, false)) {
                errs() << "Unrolled a loop in function: " << F.getName() << "\n";
            }
        }

        return PreservedAnalyses::none();
    }
};

