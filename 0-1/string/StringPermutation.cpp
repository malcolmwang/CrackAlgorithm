#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        m_vector.clear();
        doPermute(0, num);
        return m_vector;
    }

    vector<vector<int>> m_vector;

    bool noswap(int start, int step, vector<int>& num) {
        for (int i = start; i < step; i++) {
            if (num[i] == num[step])
                return true;
        }
        return false;
    }

    void doPermute(int start, vector<int> num) {
        if (start == num.size())
            m_vector.push_back(num);

        for (int i = start; i < num.size(); ++i) {
            if (noswap(start, i, num))
                continue;

            swap(num[start], num[i]);
            doPermute(start + 1, num);
            swap(num[start], num[i]);
        }
    }
};

void PrintVector(vector<int>& vec) {
  for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    std::cout << *iter << " ";
}

int main() {
  std::vector<int> testVector = {1, 1, 2};
  Solution s;
  vector<vector<int>> result = s.permuteUnique(testVector);
  for(vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); iter++) {
    PrintVector(*iter);
    std::cout << std::endl;
  }
  return 0;
}
