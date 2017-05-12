#include "ball.hpp"
#include <iostream>

void ball::update(){
   location += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         speed.x *= other.getBounce().x;
         speed.y *= other.getBounce().y;
      }
   }
}