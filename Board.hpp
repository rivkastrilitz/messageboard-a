#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel{
    class Board;
}   

class ariel:: Board{
    private:
    
        vector<vector<string>>vec_board;
    //constactor
    public:
        Board();
      


    void post(u_int row ,u_int col, Direction d,string s);
    string read(u_int row ,u_int col, Direction d,u_int n);
    void show()const;

};