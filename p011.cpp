/**
 *  \file p011.cpp
 *  \authors Jiexi Cao
 *  \brief Solves Problem 11 on Project Euler
 *
 *  \details
 *      Given an NxN grid of numbers, this program will output the
 *      largest product of K numbers in one direction.
 */

/**
 * Note: The grid is stored as a vector of vectors where the inner
 * vector represents the rows of the grid.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Functions:
int maxHori(const vector< vector<int> >& grid, const size_t K);
int maxVert(const vector< vector<int> >& grid, const size_t K);
int maxDiag(const vector< vector<int> >& grid, const size_t K);
vector<int> split(string row);

int main(const int argc, const char* argv[])
{
    if (argc == 1) {
        cerr << "Please give a plain text file of a grid." << endl;
        exit(EXIT_FAILURE);
    }

    vector< vector<int> > grid;
    string filename = argv[argc - 1];

    ifstream inputStream(filename.c_str());

    if (!inputStream) {
        cerr << "No such file exists." << endl;
        exit(EXIT_FAILURE);
    }

    string line;

    while (getline(inputStream, line))
        grid.push_back(split(line));

    // Make sure to assert it is a NxN grid!

/*   for (size_t i = 0; i < grid.size(); ++i) {
       for (vector<int>::iterator j = grid[i].begin(); j != grid[i].end(); ++j) {
            cout << *j << "\t ";
       }
       cout << endl;
   } */

    int horiMax = maxHori(grid, 4);
    int vertMax = maxVert(grid, 4);
    int diagMax = maxDiag(grid, 4);


    cout << "max in horizontal: " << horiMax << endl
         << "max in vertical:   " << vertMax << endl
         << "max in diagonal:   " << diagMax << endl;

    return 0;
}

int maxHori(const vector< vector<int> >& grid, const size_t K)
{
    int maxProduct = 0;

    cout << "grid size = " << grid.size() << endl;

    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size() - K + 1; ++j) {
            int prod = 1;

            for (int m = 0; m < K; ++m)
                prod *= grid[i][j + m];

            if (prod > maxProduct)
                maxProduct = prod;
        }
    }

    return maxProduct;
}

int maxVert(const vector< vector<int> >& grid, const size_t K)
{
    int maxProduct = 0;

    for (size_t i = 0; i < grid.size() - K + 1; ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            int prod = 1;

            for (int m = 0; m < K; ++m)
                prod *= grid[i + m][j];

            if (prod > maxProduct)
                maxProduct = prod;
        }
    }

    return maxProduct;
}

int maxDiag(const vector< vector<int> >& grid, const size_t K)
{
    int maxProduct = 0;

    for (size_t i = 0; i < grid.size() - K + 1; ++i) {
        for (size_t j = 0; j < grid[i].size() - K + 1; ++j) {
            int prod = 1;

            for (int m = 0; m < K; ++m)
                prod *= grid[i + m][j + m];

            if (prod > maxProduct)
                maxProduct = prod;
        }
    }

    for (size_t i = 0; i < grid.size() - K + 1; ++i) {
        for (size_t j = grid[i].size() - 1; j > K - 1; --j) {
            int prod = 1;

            for (int m = 0; m < K; ++m)
                prod *= grid[i + m][j - m];

            if (prod > maxProduct)
                maxProduct = prod;
        }
    }

    return maxProduct;
}

vector<int> split(string row)
{
    vector<int> r;

    size_t pos = 0;
    size_t len = 0;

    for (size_t i = 0; i < row.length(); ++i) {
        if (!isspace(row[i])) {
            pos = i;
            ++i;
            ++len;
        }

        while (!isspace(row[i])) {
            ++len;
            ++i;
        }

        r.push_back(atoi(row.substr(pos, len).c_str()));
    }

    return r;
}
