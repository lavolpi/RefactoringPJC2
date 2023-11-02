#include <iostream>
#include <vector>
#include <algorithm>
auto example(std::vector<std::string> left, std::vector<std::string> right) -> void {

    auto removeDuplicatesAndSort = [](std::vector<std::string>& vec){
        std::ranges::sort(vec);
        auto dupicates = std::ranges::unique(vec);
        vec.erase(dupicates.begin(), dupicates.end());
    };

    removeDuplicatesAndSort(left);
    removeDuplicatesAndSort(right);


    auto compareSizes = [] (std::vector<std::string>& vec){

        auto startDigitOrLetter = [](char a){
            return a >= '0' and a <= '9';
        };

        auto startDigitOrLetter2 = [] (char a, char b){
            return (a < '0' or a > '9') and (b < '0' or b > '9');
        };

        for (auto i = 0; i < vec.size(); i++) {
            for (auto j = 0; j < vec.size() - 1 - i; j++) {
                // both start with a digit or both start with a letter
                if ((startDigitOrLetter(vec[j].front()) and startDigitOrLetter(vec[j+1].front()))
                    or
                    startDigitOrLetter2(vec[j].front(), vec[j+1].front())) {
                    if (vec[j] > vec[j + 1]) {
                        std::ranges::swap(vec[j], vec[j + 1]);
                    }
                } else { // leading digits last
                    if (startDigitOrLetter(vec[j].front())) {
                        std::ranges::swap(vec[j], vec[j + 1]);
                    }
                }
            }
        }
    };

     if (left.size() < right.size()){
         compareSizes(right);
     } else {
         compareSizes(left);
     }
}
int main() {

    return 0;
}
