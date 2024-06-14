
#include "lambdalib.h"





#define SELF struct Circle *self

typedef struct Circle {
double x, y;
double radius;
double (*area)(SELF );

double (*perimeter)(SELF );

void (*move)(SELF , double dx, double dy);

} Circle;
double area(SELF ) {
return 3.14 * (pow(self->radius, 2));

}

double perimeter(SELF ) {
return 2 * 3.14 * self->radius;

}

void move(SELF , double dx, double dy) {
self->x = self->x + dx;
self->y = self->y + dx;

}

const Circle ctor_Circle = { .area=area,.perimeter=perimeter,.move=move   };
#undef SELF

int main () {

Circle a = ctor_Circle;


Circle z = ctor_Circle;

Circle h = ctor_Circle;


Circle arr[5];
for (int i = 0; i < 5; i++) 
{ arr[i] = ctor_Circle; }

Circle arr2[10];
for (int i = 0; i < 10; i++) 
{ arr2[i] = ctor_Circle; }

Circle arr3[3];
for (int i = 0; i < 3; i++) 
{ arr3[i] = ctor_Circle; }
Circle z2 = ctor_Circle;

Circle z3 = ctor_Circle;


Circle z1 = ctor_Circle;

Circle arr4[3];
for (int i = 0; i < 3; i++) 
{ arr4[i] = ctor_Circle; }
Circle z4 = ctor_Circle;

z.radius = 5;
double area;
area = z.area(&z);
writeScalar(area);
arr[2].radius = 5;
double area2;
area2 = arr[2].area(&arr[2]);
writeScalar(area);

}
