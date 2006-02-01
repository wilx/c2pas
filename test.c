int main ()
{
int x, y, z;
float f, g;
x = 1;
y = 2;
z = x + y;

f = 1.1;
g = f + 2.2;

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

