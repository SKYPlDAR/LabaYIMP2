#include <iostream>

using namespace std;

namespace nm{
class jets{
public:
    string model;
    string pilot;
    string range;
    int speed;
    bool status;
    int time;
    int x;
    int y;
    int timeEnd;
    friend ostream& operator<<(ostream& os, const jets& Jets);
    friend istream& operator>>(istream& is, const jets& Jets);
};
//классы
class routes{
public:
    string name;
    int startX;
    int startY;
    int endX;
    int endY;
    friend ostream& operator<<(ostream& os, const routes& Routes);
    friend istream& operator>>(istream& is, const routes& Routes);
};
//войды я пропишу
}
