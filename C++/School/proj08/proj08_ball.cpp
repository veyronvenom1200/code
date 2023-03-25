/*
 * Author: Nathan Dohm
 * Date: 11/05/17
 * proj08_ball.cpp is a C++ script that defines the declarations of proj08_ball.h
 */

#include <iostream>
using std::cout; using std::endl;
#include <sstream>
#include <iomanip>
#include <cmath>
#include "proj08_ball.h"
#include "proj08_twod.h"

// Member functions definitions and constructor
Ball::Ball(double m, TwoD pos, TwoD speed, double r) {
    mass = m;
    coords = pos;
    velocity = speed;
    radius = r;
}

string Ball::to_string() {

/*
 * converts the Ball TwoD struct into a string
 */

    std::ostringstream oss;
    oss.precision(2);
    oss << std::fixed;
    oss << mass << ", "
    << "(" << coords.x << ", " << coords.y << ")" << ", " << "("
    << velocity.x << ", " << velocity.y << ")" << ", " << radius;
    string str = oss.str();
    return str;
}

bool Ball::contact_ball(Ball b) {

/*
 * determines if the ball comes into contact with another another ball by calculating
 * the distance between the centers
 */

    double m = std::pow((std::pow(b.coords.x - coords.x, 2))
                        + std::abs(std::pow(b.coords.y - coords.y, 2)), .5)/2;

    if (m <= b.radius) {
        return true;
    } else {
    return false;
    }

}

bool Ball::contact_wall(long xdim, long ydim) {

/*
 * determines if the ball comes into contact with a wall by calculating the
 * distance between their centers
 */

    if (((coords.x + radius) > xdim) or ((coords.x - radius) < 0)){
        return true;
    } else if (((coords.y + radius) > xdim) or ((coords.y - radius) < 0)) {
        return true;
    } else {
        return false;
    }
}

TwoD Ball::update_velocity_wall(long xdim, long ydim) {

/*
 * updates the velocity of the ball after if makes contact with a wall by negating
 * the sign of the associated x-velocity or y-velocity, depending on which dimension
 * made contact
 */

    if (contact_wall(xdim, ydim) == true) {
        if (((coords.x + radius) > xdim) or ((coords.x - radius) < 0)) {
            velocity.x = -velocity.x;
        } else if (((coords.y + radius) > xdim) or ((coords.y - radius))) {
            velocity.y = -velocity.y;
        }
    }
    return TwoD(velocity.x, velocity.y);
}

TwoD Ball::update_velocity_ball(Ball b) {

/*
 * updates the velocity of the ball using the TwoD struct and vector arithmetic
 */

    //double v1 = std::pow((std::pow(velocity.x, 2) + std::pow(velocity.y, 2)), .5);
    TwoD v1D(velocity.x, velocity.y);
    TwoD v2D(b.velocity.x, b.velocity.y);
    TwoD velocity_diff = v1D.diff(v2D);

    TwoD x1(coords.x, coords.y);
    TwoD x2(b.coords.x, b.coords.y);
    TwoD position_diff = x1.diff(x2);

    double dot = velocity_diff.dot_product(position_diff);
    double new_mass = ((2 * b.mass)/(mass + b.mass));

    return TwoD(v1D.diff(position_diff.mult(new_mass * (dot/position_diff.magnitude_squared()))));
}


