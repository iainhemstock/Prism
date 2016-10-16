/*
 * Circle.h
 * v0.1
 *
 *  Created on: Jul 3, 2016
 *      Author: iainhemstock
 */

#ifndef PRISM_CIRCLE_H_
#define PRISM_CIRCLE_H_

#include <ostream>
#include <prism/h/Vector.h>
#include <prism/h/Flags.h>

namespace prism {

class Pointf;

/// @class 	Circle prism/h/Circle.h prism/Circle
///
/// @brief 	A class that represents a circle
///
/*!The Circle class defines a circle using floating point precision.

<h3>Construction</h3>

A circle can be created through various constructors:

\code
Circle c; // radius of 1 and centred at (0,0)
Circle c(12); // radius of 12 and centred at (0,0)
Circle c(23, 100, 150); // radius of 23 and centred at (100,150)

Pointf p(100,150);
Circle c(23, p) ;
\endcode

<h3> Getting circle data</h3>
Basic information about the circle can be accessed with isValid(), radius(), diameter(), area(), circumference(), sectorArea(), segmentArea() and arcLength(). The circle’s centre point can be found with centre() which returns a Pointf or with the separate x() and y() methods.

As a convenience top() returns the y-coordinate of the top edge, right() returns the x-coordinate of the right edge, bottom() returns the y-coordinate of the bottom edge and left() returns the x-coordinate of the left edge of the circle.

\code
float radius = 10;
Pointf p(100,100);
Circle c(radius, p);

cout << c.top(); // outputs 90
cout << c.right(); // outputs 110
cout << c.bottom(); // outputs 110
cout << c.left(); // outputs 90

\endcode

It is also possible to extract the raw data from the circle with getCircle():

\code
float radius;
float x;
float y;

Circle c(23, 100, 150);
c.getCircle(&radius, &x, &y);

// now radius = 23, x = 100 and y = 150
\endcode

<h3>Modifying the circle</h3>

The circle can be modified after construction with setDiameter(), setRadius(), setX() and setY() as well as the two setCircle() methods.

The circle can be moved with various methods. It can be moved to a new centre point with moveCentre() or independently in the x and y axis with setX() and setY(). There are four convenience methods, moveTop(), moveRight(), moveBottom() and moveLeft(), that aligns that edge of the circle to the coordinate supplied in the corresponding axis.

\code
Circle c(10, Pointf(100, 100));

c.moveCentre(100, 100);	// x() and y() = 100
c.moveTop(50); 			// top() = 50, y() = 60
c.moveRight(80); 		// right() = 80, x() = 70
c.moveBottom(120); 		// bottom() = 120, y() = 110
c.moveLeft(20); 		// left() = 20, x() = 30
\endcode

The circle can be translated relative to its current position with translate() and a copy of this circle translated relative to its current position is returned with translated().

\code
Circle c(10, 50, 50);
c.translate(5, 10); // x() = 55, y() = 60
c.translate(-10, -25); // x() = 45, y() = 35

Circle translatedCircle = c.translated(5, 10);
\endcode

If a circle ends up with a negative radius it can fixed by flipping the negative value to a positive one with normalised().

<h3>Angles and points</h3>

There are a variety of ways of calculating angles and points on the circumference.

<h4>Angles</h4>

This class can work with both degrees and radians. By default, a circle is set to work in degrees. The angle mode can be changed with setAngleMode() and can be queried with angleMode().

\code
Circle c; // by default the angle mode is degrees
c.setAngleMode(Circle::RADIANS);
// and to switch back to degrees
c.setAngleMode(Circle::DEGREES);
\endcode

If you have a point on the circumference you can find the angle of it with angle(). If you have two points on the circumference you can find the angle between them with centralAngle().

\code
Circle c; // radius=1, x=0, y=0
Pointf p1(0,1);

float theta = c.angle(p1); // 90 (in degrees mode)

Pointf p2(0,-1);
theta = c.centralAngle(p1,p2); // 180 (in degrees mode)
\endcode

<h4>Points</h4>

If you want the point on the circumference at a certain angle use point() or to acquire a vector containing evenly spaced points around the circumference use points().

\code
Circle c(20);
float theta;

// in degree mode
theta = 90;
Pointf p1 = c.point(theta); // p1 = (0,20)

// in radian mode
c.setAngleMode(Circle::RADIANS);
theta = 3.14159/2; // 90 degrees
Pointf p2 = c.point(theta); // p2 = (0,20)

// calculates 12 evenly spaced points around the circumference
Vector<Pointf> v = c.points(12);
\endcode

<h3>Intersections, boundaries and containments</h3>

To find if two circles are intersecting each other use intersects() and to return a new circle that bounds this circle and another circle use united(). Finally use contains() (and its overloads) to find out whether the circle contains a point or another circle.

<h3>Some useful formulas:-</h3>

Arc length (radians formula)
\code
θ r
\endcode

Arc length (degrees formula)
\code
    π
 θ --- r
   180
\endcode

Area
\code
π r^2
\endcode

Circumference
\code
2 π r
\endcode

Law of cosines
\code
c^2 = a^2 + b^2 - 2ab cos θ
\endcode

Sector area (radians formula)
\code
 θ
--- r^2
 2
\endcode

Sector area (degrees formula)
\code
 θ
--- π r^2
360
\endcode

Segment area (radians formula)
\code
θ - sin θ
--------- r^2
    2
\endcode

Segment area (degrees formula)
\code
 r^2       |   π              |
 --- times |θ ---  minus sin θ|
  2        |  180             |
\endcode
*/
///
/// @since	1.0.0
class Circle {
public:
	enum AngleMode { DEGREES = 0x1, RADIANS = 0x2 };
	PRISM_DECLARE_FLAGS(AngleModeFlags, AngleMode)

private:
	float m_radius;
	float m_x;
	float m_y;
	AngleMode m_angleMode;
	const float PI = 3.14159;

public:
	/// @brief		Constructor that creates a default circle
	///
	///				Creates a unit circle i.e. a circle with a radius of 1
	///
	/// @since 1.0.0
	Circle();

	/// @brief 		Constructor that creates a circle
	///
	///				Creates a circle with a radius of \em radius and its centre (x,y) set to 0.
	///
	/// @since		1.0.0
	Circle(const float radius);

	/// @brief		Constructor that creates a circle
	///
	///				Creates a unit circle with a radius of 1 and its centre point
	///				set to \em (x,y)
	///
	/// @since		1.0.0
	Circle(const float x, const float y);

	/// @brief		Constructor that creates a circle
	///
	///				Creates a circle with a radius of \em radius and its centre point
	///				set to \em (x,y).
	///
	/// @since		1.0.0
	Circle(const float radius, const float x, const float y);

	Circle(const float radius, const Pointf &position);

	Circle(const Circle &copy);

	virtual ~Circle();

	const float			angle(const float x, const float y) const;

	const float			angle(const Pointf &position) const;

	Circle::AngleMode	angleMode() const;

	const float 		arcLength(const Pointf &p1, const Pointf &p2) const;

	const float			area() const;

	const float			bottom() const;

	const float 		centralAngle(const Pointf &p1, const Pointf &p2) const;

	Pointf 				centre() const;

	const bool			contains(const float x, const float y) const;

	const bool			contains(const Pointf &position) const;

	const bool			contains(const Circle &otherCircle) const;

	const float			circumference() const;

	const float			diameter() const;

	void				getCircle(float *radius, float *x, float *y);

	const bool			intersects(const Circle &otherCircle) const;

	const bool 			isValid() const;

	const float			left() const;

	void				moveBottom(const float y);

	void				moveCentre(const float x, const float y);

	void				moveCentre(const Pointf &position);

	void				moveLeft(const float x);

	void				moveRight(const float x);

	void				moveTop(const float y);

	Circle 				normalised() const;

	Pointf				point(const float angle) const;

	Vector<Pointf>		points(const int divisions) const;

	const float 		radius() const;

	const float			right() const;

	const float			sectorArea(const Pointf &p1, const Pointf &p2) const;

	const float			segmentArea(const Pointf &p1, const Pointf &p2) const;

	void				setAngleMode(Circle::AngleMode mode);

	void				setCircle(const float radius, const float x, const float y);

	void				setCircle(const float radius, const Pointf &position);

	void				setDiameter(const float diamter);

	void 				setRadius(const float radius);

	void				setX(const float x);

	void				setY(const float y);

	const float			top() const;

	void				translate(const float dx, const float dy);

	void				translate(const Pointf &offset);

	Circle				translated(const float dx, const float dy) const;

	Circle				translated(const Pointf &offset) const;

	Circle				unit() const;

	Circle				united(const Circle &otherCircle) const;

	const float			x() const;

	const float 		y() const;


	Circle & operator=(const Circle &other);

	// related non-members
	friend const bool operator==(const Circle &c1, const Circle &c2);

	friend const bool operator!=(const Circle &c1, const Circle &c2);

	friend const bool operator<(const Circle &c1, const Circle &c2);

	friend const bool operator>(const Circle &c1, const Circle &c2);

	friend std::ostream& operator<<(std::ostream &out, const Circle &c);
};

PRISM_DECLARE_OPERATORS_FOR_FLAGS(Circle::AngleModeFlags)

} /* namespace prism */

#endif /* PRISM_CIRCLE_H_ */
