#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <string>


using namespace ariel;

int is_posted( Board ba ,u_int row,u_int col, Direction d, string s){
    string str=ba.read(row,col,d,s.length());
    if(str==s)return 1;
    return 0;
}


TEST_CASE("good"){
   
    Board b;
    string message="hello";
    for(int i=0;i<10;i++){
      b.post(i,i,Direction::Horizontal,message);  
    }
    
    for(int i=0;i<10;i++){
        int n=is_posted(b,i,i,Direction::Horizontal,message);
        CHECK(n==1);
    }
    
    //chek sub message

    



    //chek where empty





}

TEST_CASE("bad"){




}