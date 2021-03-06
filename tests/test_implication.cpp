#include "test_implication.h"

#include <cstdio>

#include <vector>

TestFunctionGroup TestImplicationAll("TestImplication", &TestImplication);

TestFunctionVector GetAllImplicationTestFunctions() {
    TestFunctionVector res;
    res.push_back(TestFunction("TestImplicationDefaultConstructor", &TestImplicationDefaultConstructor));
    res.push_back(TestFunction("TestImplicationSizeConstructor", &TestImplicationSizeConstructor));
    res.push_back(TestFunction("TestImplicationTwoBitSetConstructor", &TestImplicationTwoBitSetConstructor));
    res.push_back(TestFunction("TestImplicationCopyConstructor", &TestImplicationCopyConstructor));
    res.push_back(TestFunction("TestImplicationPremiseGetter", &TestImplicationPremiseGetter));
    res.push_back(TestFunction("TestImplicationConclusionGetter", &TestImplicationConclusionGetter));
    res.push_back(TestFunction("TestImplicationPremiseSize", &TestImplicationPremiseSize));
    res.push_back(TestFunction("TestImplicationConclusionSize", &TestImplicationConclusionSize));
    res.push_back(TestFunction("TestImplicationComplete", &TestImplicationComplete));
    return res;
}

TEST_RESULT TestImplication(const std::string& indent, size_t& ok, size_t& fail) {
    fprintf(stdout, "%s%s:\n", indent.c_str(), TestImplicationAll.name.c_str());
    ok = 0;
    fail = 0;
    TestFunctionVector allTests = GetAllImplicationTestFunctions();
    RunTestsFromGroup(allTests, indent + "\t", ok, fail);

    fprintf(stdout, "%sTotal subtest OK: %lu\n", indent.c_str(), ok);
    fprintf(stdout, "%sTotal subtest FAIL: %lu\n", indent.c_str(), fail);
    const double p = (0 == ok + fail ? 100 : static_cast<double>(ok * 100) / static_cast<double>(ok + fail));
    fprintf(stdout, "%sSuccessfull subtests: %.2lf %%\n", indent.c_str(), p);
    fprintf(stdout, "%s%s:", indent.c_str(), TestImplicationAll.name.c_str());
    TEST_RESULT res = (0 == fail ? TEST_RESULT_OK : TEST_RESULT_FAIL);
    PrintOkFailAndLineFeed(res, stdout);
    return res;
}

TEST_RESULT TestImplicationDefaultConstructor() {
    FCA::Implication impl;
    if (impl.Premise().size() != 0 || impl.Conclusion().size() != 0) {
        return TEST_RESULT_FAIL;
    }
    if (impl.Premise().any() || impl.Conclusion().any()) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationSizeConstructor() {
    const size_t baseSize = 100;
    FCA::Implication impl(baseSize);
    if (impl.Premise().size() != baseSize || impl.Conclusion().size() != baseSize) {
        return TEST_RESULT_FAIL;
    }
    if (impl.Premise().any() || impl.Conclusion().any()) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationTwoBitSetConstructor() {
    const size_t baseSize = 100;
    FCA::BitSet premise(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            premise.set(i);
        }
    }
    FCA::BitSet conclusion(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 5 == 0) {
            conclusion.set(i);
        }
    }
    const FCA::Implication impl(premise, conclusion);
    if (impl.Premise() != premise || impl.Conclusion() != conclusion) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationCopyConstructor() {
    const size_t baseSize = 100;
    FCA::Implication impl1(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            impl1.Premise().set(i);
        }
    }
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 5 == 0) {
            impl1.Conclusion().set(i);
        }
    }
    const FCA::Implication impl2(impl1);
    if (impl2.Premise() != impl1.Premise() || impl2.Conclusion() != impl1.Conclusion()) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationPremiseGetter() {
    const size_t baseSize = 100;
    FCA::BitSet premise(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            premise.set(i);
        }
    }
    FCA::BitSet conclusion(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 5 == 0) {
            conclusion.set(i);
        }
    }
    FCA::Implication impl1(premise, conclusion);
    if (impl1.Premise() != premise) {
        return TEST_RESULT_FAIL;
    }
    const FCA::Implication impl2(premise, conclusion);
    if (impl2.Premise() != premise) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}
TEST_RESULT TestImplicationConclusionGetter() {
    const size_t baseSize = 100;
    FCA::BitSet premise(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            premise.set(i);
        }
    }
    FCA::BitSet conclusion(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 5 == 0) {
            conclusion.set(i);
        }
    }
    FCA::Implication impl1(premise, conclusion);
    if (impl1.Conclusion() != conclusion) {
        return TEST_RESULT_FAIL;
    }
    const FCA::Implication impl2(premise, conclusion);
    if (impl2.Conclusion() != conclusion) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationPremiseSize() {
    const size_t baseSize = 100;
    FCA::Implication impl(baseSize);
    size_t premiseSize = 0;
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            impl.Premise().set(i);
            ++premiseSize;
        }
    }
    if (impl.PremiseSize() != premiseSize) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationConclusionSize() {
    const size_t baseSize = 100;
    FCA::Implication impl(baseSize);
    size_t conclusionSize = 0;
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            impl.Conclusion().set(i);
            ++conclusionSize;
        }
    }
    if (impl.ConclusionSize() != conclusionSize) {
        return TEST_RESULT_FAIL;
    }
    return TEST_RESULT_OK;
}

TEST_RESULT TestImplicationComplete() {
    const size_t baseSize = 100;
    FCA::Implication impl(baseSize);
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0) {
            impl.Premise().set(i);
        }
    }
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 5 == 0) {
            impl.Conclusion().set(i);
        }
    }
    impl.Complete();
    for (size_t i = 0; i < baseSize; ++i) {
        if (i % 3 == 0 && !impl.Conclusion().test(i)) {
            return TEST_RESULT_FAIL;
        }
        if (i % 5 == 0 && !impl.Conclusion().test(i)) {
            return TEST_RESULT_FAIL;
        }
        if (i % 3 != 0 && i % 5 != 0 && impl.Conclusion().test(i)) {
            return TEST_RESULT_FAIL;
        }
    }
    return TEST_RESULT_OK;
}
