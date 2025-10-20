#include <deque>
#include <iostream>
#include <vector>

std::vector<long long> GetMinOnVector(std::vector<long long>& summ,
                                      long long length, long long size) {
  std::vector<long long> res(0);
  std::deque<long long> help_deque;
  for (long long tmp = 0; tmp < size; ++tmp) {
    if (tmp >= length && help_deque.front() == tmp - length) {
      help_deque.pop_front();
    }
    while (!help_deque.empty() && summ[help_deque.back()] >= summ[tmp]) {
      help_deque.pop_back();
    }
    help_deque.push_back(tmp);
    if (tmp >= length - 1) {
      res.push_back(-1 * summ[help_deque.front()]);
    }
  }
  return res;
}

std::vector<long long> GetTheMinOnVector(std::vector<long long>& summ,
                                         long long length, long long size) {
  std::vector<long long> res(0);
  std::deque<long long> help_deque;
  for (long long tmp = 0; tmp < size; ++tmp) {
    if (tmp >= length && help_deque.front() == tmp - length) {
      help_deque.pop_front();
    }
    while (!help_deque.empty() && summ[help_deque.back()] >= summ[tmp]) {
      help_deque.pop_back();
    }
    help_deque.push_back(tmp);
    if (tmp >= length - 1) {
      res.push_back(summ[help_deque.front()]);
    }
  }
  return res;
}

int main() {
  const long long kTheInfinity = 2e16;
  long long size = 0;
  std::cin >> size;
  std::vector<long long> vec(2 * size + 1, 0);
  std::vector<long long> prefix(size + 1, 0);
  long long half_size = size / 2;
  for (long long tmp = 0; tmp < size; ++tmp) {
    std::cin >> vec[tmp];
    vec[tmp + size] = vec[tmp];
    prefix[tmp + 1] += vec[tmp] + prefix[tmp];
  }
  std::vector<long long> summ(2 * size, 0);
  summ[0] = prefix[half_size];
  for (long long tmp = size; tmp < 2 * size; ++tmp) {
    summ[tmp - size + 1] = summ[tmp - size];
    summ[tmp - size + 1] += vec[tmp - half_size - size % 2];
    summ[tmp - size + 1] -= vec[tmp - size];
  }
  for (long long tmp = 0; tmp < size; ++tmp) {
    summ[tmp] *= -1;
    summ[size + tmp] = summ[tmp];
  }
  std::vector<long long> ans = GetMinOnVector(summ, half_size, 2 * size);
  for (long long tmp = 0; tmp < (long long)ans.size(); ++tmp) {
    ans[tmp] *= -1;
  }
  long long minn = kTheInfinity;
  std::vector<long long> ans2 =
      GetTheMinOnVector(ans, size - 2 * half_size + 1, (long long)ans.size());
  for (auto elem : ans2) {
    elem *= -1;
    minn = std::min(minn, elem);
  }
  std::cout << prefix[size] - minn << " " << minn;
}