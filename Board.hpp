#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel{
    

    
class Board{
    private:
        vector<vector<string>>vec_board;

    //constactor
    public:
        Board();
      
    void post(u_int row ,u_int col, ariel::Direction d, string  s);
    string read(u_int row ,u_int col, ariel::Direction d,u_int n);
    void show();

};
}
