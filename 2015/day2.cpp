/*
 https://adventofcode.com/2015/day/2
 --- Day 2: I Was Told There Would Be No Math ---
The elves are running low on wrapping paper, and so they need to submit an order
for more. They have a list of the dimensions (length l, width w, and height h)
of each present, and only want to order exactly as much as they need.

Fortunately, every present is a box (a perfect right rectangular prism), which
makes calculating the required wrapping paper for each gift a little easier:
find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. The elves also
need a little extra paper for each present: the area of the smallest side.

For example:

A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of
wrapping paper plus 6 square feet of slack, for a total of 58 square feet. A
present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of
wrapping paper plus 1 square foot of slack, for a total of 43 square feet. All
numbers in the elves' list are in feet. How many total square feet of wrapping
paper should they order?
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::vector<std::vector<int>> data;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::vector<int> row;
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, 'x')) {
      row.push_back(std::stoi(token));
    }

    data.push_back(row);
  }

  for (auto &row : data) {
    std::sort(row.begin(), row.end());
  }

  // part 1
  long totalArea = 0;
  for (auto &row : data) {
    int area = 0;
    area += 2 * row[0] * row[1];
    area += 2 * row[0] * row[2];
    area += 2 * row[1] * row[2];
    area += row[0] * row[1];

    totalArea += long(area);
  }

  std::cout << totalArea;

  return 0;
}
