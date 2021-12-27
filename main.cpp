// Copyright
#include "EDistance.h"
#include <SFML/System.hpp>
int main(int argc, const char * argv[]) {
     string stringA;
     string stringB;
     cin >> stringA;
     cin >> stringB;
     sf::Clock clock;
     sf::Time t;
     EDistance myStrings(stringA, stringB);
     cout << myStrings.Alignment();
     t = clock.getElapsedTime();
     cout << "Execution time is " << t.asSeconds() << " seconds \n";
     return 0;
}
