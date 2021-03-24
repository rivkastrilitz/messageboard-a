#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <string>



using namespace ariel;

int is_posted( Board ba ,u_int row,u_int col, Direction d, string s){
    string str=ba.read(row,col,d,s.length());
    return str.compare(s);  
}

    Board b;
    string message="hello";
    


TEST_CASE("good"){

    for(u_int i=0;i<10;i++){
      b.post(i,i,Direction::Horizontal,message);  
    }
    //check if posted
    for(u_int i=0;i<10;i++){
       
        int n=is_posted(b,i,i,Direction::Horizontal,message);
        CHECK(n==0);
    }
    
    //check sub message
    CHECK(b.read(0,1,Direction::Horizontal,5)=="ello");
    CHECK(b.read(0,0,Direction::Horizontal,4)=="hell");
    CHECK(b.read(0,0,Direction::Horizontal,1)=="h");
    CHECK(b.read(0,1,Direction::Horizontal,3)=="ell");
    CHECK(b.read(0,1,Direction::Horizontal,2)=="el");
   
    //check where board ia empty
    CHECK(b.read(0,5,Direction::Horizontal,5)=="");
    CHECK(b.read(20,30,Direction::Vertical,5)=="");

    //check if vertical override horizontal
    b.post(0,4,Direction::Vertical,"world");
    CHECK(b.read(0,0,Direction::Horizontal,5)=="hellw");
    CHECK(b.read(0,4,Direction::Vertical,5)=="world");

    //check if override
    b.post(1,1,Direction::Horizontal,"rivka");
    CHECK(b.read(1,1,Direction::Horizontal,5)=="rivka");
    
    // CHECK farther in the board 
    b.post(100,200,Direction::Horizontal,"rivka");
    CHECK(b.read(100,200,Direction::Horizontal,5)=="rivka");
    b.post(1000,4587,Direction::Horizontal,"rivka");
    CHECK(b.read(1000,4587,Direction::Horizontal,5)=="rivka");

    // read verticl word that build from horizontal
    b.post(51,50,Direction::Horizontal,"war");
    b.post(52,50,Direction::Horizontal,"la la lend");

    CHECK(b.read(51,50,Direction::Vertical,3)=="wl");

}


TEST_CASE("bad"){
    b.post(0,4,Direction::Vertical,"world");
    b.post(50,50,Direction::Horizontal,"star");
  
    // reding the wrong word
    CHECK_FALSE(b.read(0,4,Direction::Vertical,5)=="abcd");
    CHECK_FALSE(b.read(0,4,Direction::Vertical,5)=="");

    // read with the underline
    CHECK_FALSE(b.read(0,4,Direction::Vertical,5)=="_____");
   
    CHECK_FALSE(b.read(50,50,Direction::Horizontal,6)=="star_");
    
    // read backwordes
    CHECK_FALSE(b.read(50,50,Direction::Horizontal,4)=="rats");

    





}