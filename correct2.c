
#include "lambdalib.h"




int next_random;

int next() {
next_random = (next_random * 1103515245 + 12345) % 2147483648;
if (next_random < 0) {
next_random = -next_random;

}
return next_random;


}


void printArray(int *a, int size) {
for (int i = 0; i < size; i++) {
writeInteger(a[i]);
if (i == size - 1) {
continue;

}
writeStr(", ");

}
writeStr("\n");

}

int main () {
const int size = 100;
writeStr("Current start:");
writeInteger(100);
writeStr("\n");
writeStr("Current stop:");
writeInteger(1000);
writeStr("\n");
writeStr("Current start:");
writeInteger(200);
writeStr("\nCurrent stop:");
writeInteger(1500);
writeStr("\n");
int* a = (int*)malloc(size*sizeof(int));
for(int i = 0; i < size; ++i) {
 a[i] = next() + next() * 2 / 2;
}
writeStr("Random array generated: ");
printArray(a, size);
int* f = (int*)malloc(size*sizeof(int));
for(int a_i = 0; a_i < size; ++a_i) {
	f[a_i] = a[a_i] % 1500;
}
int j;
j = 0;
while (j < size){
if (f[j] < 200 && f[j] >= 0) {
f[j] += 200;

}
if (f[j] < 0) {
f[j] = 200 + next() % (1500 - 200);

}
j = j + 1;

}

writeStr("Random bounded array generated: ");
printArray(f, size);

}
