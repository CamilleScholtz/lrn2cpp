#ifndef BALL_HPP
#define BALL_HPP

#include "window.hpp"
#include "vector.hpp"
#include "circle.hpp"
// @file

/// \brief
/// ball
/// \details
/// A circle, this circle has a speed so it can move and it will bounce
/// off (interact) with walls.
class ball : public circle {
private:
   vector speed;
public:
   ball( window & w, const vector & midpoint, int radius, const vector & speed );
   void update() override;
   void interact( drawable & other ) override;
};

#endif // BALL_HPP
