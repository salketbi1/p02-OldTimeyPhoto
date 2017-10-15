#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"

using namespace std;

int main ()
{
    Bitmap image;
    vector <vector <Pixel> > bmp;
    int average;
    //Pixel rgb;

    string fileName;
    
    bool goodImage = false;

    // ask for image filename until it is a valid windows bitmap file
    while (!goodImage)
    {
        cout <<"What is the name of the file?"<<endl;
        getline(cin,fileName);
        image.open(fileName);

        if (!image.isImage())
        {

            goodImage = false;
            cout <<"Please enter valid Windows BMP image file!"<<endl;
        }
        else
            goodImage = true;
    }

    // create the pixel matrix from the image
    bmp = image.toPixelMatrix();

    cout <<"Converting " << fileName << " to an old timey photo!"<<endl; 


    for (int x=0;x<bmp.size();x++)
    {


        for (int y=0;y<bmp[x].size();y++)
        {
            // rgb average
            average = bmp[x][y].red + bmp[x][y].green + bmp[x][y].blue;
            average /= 3;
            Pixel rgbTemp(average,average,average);
            bmp[x][y] = rgbTemp; // assign the pixel the new grayscale pixel
        }

    } 

    // save the grayscale image and exit
    image.fromPixelMatrix(bmp);
    image.save("oldtimey.bmp");
    
    return 0;
}
