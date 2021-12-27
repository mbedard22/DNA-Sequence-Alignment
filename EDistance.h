// Copyright
#ifndef EDISTANCE_H//NOLINT
#define EDISTANCE_H//NOLINT
#include <iostream>
#include <string>
#include <vector>
using namespace std;//NOLINT

class EDistance {
 public:
     EDistance(string xString, string yString);
     int penalty(char a, char b);
     int min(int a, int b, int c);//NOLINT
     int OptDistance();
     string Alignment();
 private:
     string x;
     string y;
     vector<vector<int>> opt;
};

#endif//NOLINT
