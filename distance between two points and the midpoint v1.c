/*
	Distance between two points and the midpoint v1.c

The distance formula is an algebraic expression used to determine
the distance between two points with the coordinates
A(x1, y1) and B(x2, y2).

distance = sqrt( (x2-x1)^2 +(y2-y1)^2 )

If the end points of a line segment are A(x1, y1) and B(x2, y2)
then the midpoint M(xm,ym) of the line segment AB has the coordinates:

xm = (x1+x2)/2

ym = (y1+y2)/2

M(xm,ym) = M( (x1+x2)/2 , (y1+y2)/2 )


	o-----------------o-----------------o
	A                 M                 B


*/

#include<stdio.h>
#include <math.h>	// because of sqrt()

int main(void)
{
/*
	A(x1,y1)	point A is at the beginning of line segment AB
	B(x2,y2)	point B is at the end of line segment AB
	M(xm,ym)	point M is in the middle between A and B
	distance	is the distance between points A and B
*/
	double x1, y1, x2, y2, xm, ym, distance;

	printf("\n A and B are two points with the coordinates A(x1, y1) and B(x2, y2) \n");

	printf("\n Enter coordinate x1 = ");
	scanf("%lf",&x1);

	printf("\n Enter coordinate y1 = ");
	scanf("%lf",&y1);

	printf("\n Enter coordinate x2 = ");
	scanf("%lf",&x2);

	printf("\n Enter coordinate y2 = ");
	scanf("%lf",&y2);

	distance = sqrt( pow( (x2-x1),2 ) + pow( (y2-y1),2) );

	xm = (x1+x2) / 2;

	ym = (y1+y2) / 2;


	printf("\n A( %.2lf , %.2lf ) \t B( %.2lf , %.2lf ) \n", x1, y1, x2, y2 );

	printf("\n Distance between points A and B = sqrt( (x2-x1)^2 +(y2-y1)^2 ) = %.2lf \n", distance);

	printf("\n In the middle between A and B is point M( (x1+x2)/2 , (y1+y2)/2 ) \n");

	printf("\n M( %.2lf , %.2lf ) \n", xm, ym);


	printf("\n");

	return 0;
}
