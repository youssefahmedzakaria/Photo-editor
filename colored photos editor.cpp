// FCAI�CU - Programming 1 - Assignment 3
// Program Name: photo Editor.cpp
// Last Modification Date: 4/4/2022
// Author1 : assem emad      
// Author2 : youssef ahmed zakaria 
// Author3 : tareq mahfouz 
// Teaching Assistant: Eng nesma & yousra

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char output_image[SIZE][SIZE][RGB];
static int change = SIZE - 1;
void loadImage();
void choose();
void saveImage();

int main()
{
    loadImage();
    choose();
    saveImage();
    return 0;
}

void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
    writeRGBBMP(imageFileName, output_image);
}

void invertimage() {
    for (int i = 0; i < SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++){
                if (image[i][j][k] == 0) {
                    output_image[i][j][k] = 255;
            }
                else{
                output_image[i][j][k] = (255 - image[i][j][k]);
                }
            }
        }
    }
}


void choose() {
    cout << "press 0 to black and white filter " << endl;
    cout << "press 1 to invert image filter " << endl;
    cout << "press 2 to merge images filter " << endl;
    cout << "press 3 to flip filter " << endl;
    cout << "press 4 to rotate filter " << endl;
    cout << "press 5 to darken and lighten filter " << endl;
    cout << "press 6 to detect images edges filter " << endl;
    cout << "press 7 to enlarge image filter " << endl;
    cout << "press 8 to shrink image filter " << endl;
    cout << "press 9 to mirror filter " << endl;
    cout << "press 10 to shuffle filter " << endl;
    cout << "press 11 to blur filter " << endl;

    int x;
    cin.ignore();
    while (!(cin >> x))
    {
        cout << "enter a valid num" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (x == 0)
    {
       // black_and_white();
    }
    else if (x == 1)
    {
        invertimage();
    }
    else if (x == 2)
    {
        return;
    }
    else if (x == 3)
    {
     //   flip();
    }
    else if (x == 4)
    {
      //  rotate();
    }
    else if (x == 5)
    {
    //    Darken_and_Lighten_Image();
    }
    else if (x == 6)
    {
        //Detect_Image_Edges();
    }
    else if (x == 7)
    {
       // enlarge();
    }
    else if (x == 8)
    {
        return;
    }
    else if (x == 9)
    {
     //   mirror();
    }
    else if (x == 10)
    {
        //shuffle();
    }
    else if (x == 11)
    {
        return;
    }
    else {
        choose();
    }
}
