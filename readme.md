Spinning Card
=============

by Hapax
2014 Golden Eagle Software

**The follow-up (successor) to this class is Sprite3d.  
Both SpinningCard and Sprite3d are available in [Selba Ward](https://github.com/Hapaxia/SelbaWard/wiki)**

SpinningCard is a class that takes an SFML sprite, mimics it using an SFML vertex array, then manipulates it using faux-3D so that it is at an angle.

It can spin either horizontally (around the y axis - default) or vertically (around the x axis) but not both at the same time.

The depth of the fake perspective can be specified, which alters the strength of the effect. At a depth of zero, the effect "spins" in a similar way to just changing the width (or height if spinning vertically)

Simple example video: http://www.youtube.com/watch?v=u428K0xyorI
Short animation example video: http://www.youtube.com/watch?v=yNSEmSMfbgQ

Requires C++11 and SFML (http://sfml-dev.org)
