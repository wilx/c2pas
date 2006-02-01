int main ()
{
  int X;
int x, y, z;
float f, g;
 X = 2;
x = 1;
y = 2;
z = x + y;

f = 1.1;
g = f + 2.2 + X;

while (g < 10) {
    g += 1;
}

switch (y) {
case 1 : {
    z = x + y;
}
case 2 : {
    z = x - y;
}
default: {
    z += 1;
}
}

}

