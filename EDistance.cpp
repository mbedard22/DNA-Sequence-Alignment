// Copyright
#include "EDistance.h"

EDistance::EDistance(string xString, string yString) {
     x = xString;
     y = yString;
     int xLength = x.size();
     opt.resize(xLength + 1);
}
int EDistance::penalty(char a, char b) {
     if (a == b) {
          return 0;
     } else {
          return 1;
     }
}

int EDistance::min(int a, int b, int c) {
     int num = (a < b) ? a : b;
     num = (num < c) ? num : c;
     return num;
}

int EDistance::OptDistance(void) {
     int xLength = x.size();
     int yLength = y.size();
     for (int j = 0; j <= yLength; j++) {
          opt[xLength].push_back(2 * (yLength - j));
     }
     for (int i = xLength - 1; i > -1; i--) {
          for (int k = yLength; k > -1; k--) {
               opt[i].push_back(2 * (xLength - i));
          }
          for (int j = yLength - 1; j > -1; j--) {
               opt[i][j] = min((opt[i+1][j+1]) + penalty(x[i], y[j]), (opt[i+1][j]) + 2, (opt[i][j+1]) + 2);//NOLINT
          }
     }
     return opt[0][0];
}

std::string EDistance::Alignment(void) {
     int ED = OptDistance();
     string ret;
     int i = 0;
     int j = 0;
     int xSize = x.size();
     int ySize = y.size();
     ret += "Edit distance = ";
     ret += to_string(ED);
     ret += '\n';
     while (i != (xSize) || j != (ySize)) {
          if (((x[i] == y[j]) && (opt[i][j] == opt[i + 1][j + 1])) || ((x[i] != y[j]) && (opt[i][j] == opt[i + 1][j + 1] + 1))) {//NOLINT
               ret += x[i];
               ret += ' ';
               ret += y[j];
               ret += ' ';
               ret += to_string(penalty(x[i], y[j]));
               i += 1;
               j += 1;
          } else if (opt[i][j] == opt[i+1][j] + 2) {
               ret += x[i];
               ret += ' ';
               ret += '-';
               ret += ' ';
               ret += '2';
               i += 1;
          } else {
               ret += '-';
               ret += ' ';
               ret += y[j];
               ret += ' ';
               ret += '2';
               j+= 1;
          }
          ret += '\n';
     }
     return ret;
}

