#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"

    using namespace std;

      int main ()
    {
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;

image.open("White Clouds.bmp");
bmp = image.toPixelMatrix();

cout<<"White Clouds.bmp is loaded. it is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;

    return 0;
    }

