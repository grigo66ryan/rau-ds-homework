#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(const std::vector<int>& mainVec, const std::vector<int>& subVec) {
    if (subVec.empty()) return 0;
    if (subVec.size() > mainVec.size()) return -1;
    for (int i = 0; i <= mainVec.size() - subVec.size(); i++) {
        bool found = true;
        for (int j = 0; j < subVec.size(); j++) {
            if (mainVec[i + j] != subVec[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}

void testFindSubsequence() {
    std::vector<int> mainVec = { 1,2,3,4,5,6 };
    std::vector<int> sub1 = { 3,4,5 };
    assert(findSubsequence(mainVec, sub1) == 2);

    std::vector<int> sub2 = { 1,2 };
    assert(findSubsequence(mainVec, sub2) == 0);

    std::vector<int> sub3 = { 5,7 };
    assert(findSubsequence(mainVec, sub3) == -1);

    std::vector<int> sub4;
    assert(findSubsequence(mainVec, sub4) == 0);

    std::vector<int> sub5 = { 1,2,3,4,5,6,7 };
    assert(findSubsequence(mainVec, sub5) == -1);

    std::vector<int> repeated = { 1,1,1,2 };
    std::vector<int> sub6 = { 1,1,2 };
    assert(findSubsequence(repeated, sub6) == 1);
}

int main() {
    testFindSubsequence();
    std::cout << "All tests passed!" << std::endl;
}
