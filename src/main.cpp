
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using Row = std::pair<int, int>;
using Relation = std::vector<Row>;
using ResultTuple = std::tuple<int, int, int>;
using Result = std::vector<ResultTuple>;
using Cover = Result;

using Cache = std::unordered_set<int>;

//R1(A, B)
Relation R1 = {
    {2, 1},
    {1, 1},
    {1, 2},
    {1, 3},
    {2, 3}
};

//R2(A, C)
Relation R2 = {
    {1, 5},
    {2, 10},
    {1, 6},
    {2, 7}
};

// computes cover via the good lil old and very inefficient nested loop join
Cover compute_cover(Relation r1, Relation r2) {
    Cache mapOfKeys;
    Cover cover;

    for(auto r1_tuple : r1) {
        bool is_present = mapOfKeys.find(r1_tuple.first) != mapOfKeys.end();

        for(auto r2_tuple : r2) {
            if(r1_tuple.first != r2_tuple.first)
                continue;

            cover.emplace_back(r1_tuple.first, r1_tuple.second, r2_tuple.second);
            if(is_present) break;
        }

        mapOfKeys.insert(r1_tuple.first);
    }

    return cover;
}

int main(void) {
    std::cout <<
        "Computes the cover of the result of the acyclic join R1(A, B), R2(A, C)\n"
        "\n"
        "";
    Result cover = compute_cover(R1, R2);

    for(auto tuple : cover) {
        std::cout << std::get<0>(tuple) << "\t";
        std::cout << std::get<1>(tuple) << "\t";
        std::cout << std::get<2>(tuple) << std::endl;
    }

}
