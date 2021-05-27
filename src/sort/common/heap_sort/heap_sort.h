#pragma once

#include <vector>

namespace heap {
void make(std::vector<int>& vec);
void adjust(std::vector<int>& vec, int n, int i);
void sort(std::vector<int>& vec);
}  // namespace heap
