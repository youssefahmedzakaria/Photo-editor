#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
static int change = SIZE-1;
void loadImage ();
void choose ();
void saveImage ();
int main()
{
    loadImage();
    choose();
    saveImage();
    return 0;
}
void loadImage () {
    char imageFileName[100];

   // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

   // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void saveImage () {
    char imageFileName[100];

   // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

   // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
void flip(){
    for (int i = 0; i <= 127; i++) {
        if (i!=0)
        {
            change-=1;
        }
        for (int j = 0; j<= 254; j++) {
            swap(image[i][j],image[change][j]);
            }      
    }
}
void black_and_white(){
    static long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            avg+=image[i][j];}      
    }
    avg/=(SIZE*SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j]>avg){
                image[i][j]=255;
            }
            else{
            image[i][j]=0;
            }
    }      
    }
}
void Detect_Image_Edges(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j]<127&&image[i][j+1]<127)
            {
                while (image[i][j+1]<127)
                {
                    image[i][j+1]=255;
                    j+=1;
                }          
            }
            }      
    }
}
void mirror(){
    int reverse;
    cout<<"1- up to down"<<endl;
    cout<<"2- down to up"<<endl;
    cout<<"3- right to left"<<endl;
    cout<<"4- left to right"<<endl;
    while (!(cin>>reverse))
    {
        cout<<"enter a valid num"<<endl;
        cin.clear();
        cin.ignore(123,'\n');
    }
    if (reverse==1)
    {
    for (int i = 0; i <= 127; i++) {
        if (i!=0)
        {
            change-=1;
        }
        for (int j = 0; j<= 254; j++) {
            image[change][j]=image[i][j];
            }      
    }
    }
    else if (reverse==2)
    {
    for (int i = 0; i <= 127; i++) {
        if (i!=0)
        {
            change-=1;
        }
        for (int j = 0; j<= 254; j++) {
            image[i][j]=image[change][j];
            }      
    }
    }
    else if (reverse==3)
    {
    for (int i = 0; i <= 254; i++) {
        if (i!=0)
        {
            change=254;
        }
        for (int j = 0; j<= 127; j++) {
            image[i][j]=image[i][change];
            change-=1;
            }      
    }
    }
    else if (reverse==4)
    {
    for (int i = 0; i <= 254; i++) {
        if (i!=0)
        {
            change=254;
        }
        for (int j = 0; j<= 127; j++) {
            image[i][change]=image[i][j];
            change-=1;
            }      
    }
    }
    else{
        cout<<"enter a valid number"<<endl;
        mirror();
    }
}
void choose(){
    cout<<"press 0 to black and white filter "<<endl;
    cout<<"press 1 to invert image filter "<<endl;
    cout<<"press 2 to merge images filter "<<endl;
    cout<<"press 3 to flip filter "<<endl;
    cout<<"press 4 to rotate filter "<<endl;
    cout<<"press 5 to darken and lighten filter "<<endl;
    cout<<"press 6 to detect images edges filter "<<endl;
    cout<<"press 7 to enlarge image filter "<<endl;
    cout<<"press 8 to shrink image filter "<<endl;
    cout<<"press 9 to mirror filter "<<endl;
    cout<<"press 10 to shuffle filter "<<endl;
    cout<<"press 11 to blur filter "<<endl;

    int x;
    cin.ignore();
    while (!(cin>>x))
    {
        cout<<"enter a valid num"<<endl;
        cin.clear();
        cin.ignore(123,'\n');
    }
    if (x==0)
    {
        black_and_white();
    }
    else if (x==1)
    {
        return;
    }
    else if (x==2)
    {
        return;
    }
    else if (x==3)
    {
        flip();
    }
    else if (x==4)
    {
        return;
    }
    else if (x==5)
    {
        return;
    }
    else if (x==6)
    {
        Detect_Image_Edges();
    }
    else if (x==7)
    {
        return;
    }
    else if (x==8)
    {
        return;
    }
    else if (x==9)
    {
        mirror();
    }
    else if (x==10)
    {
        return;
    }
    else if (x==11)
    {
        return;
    }
    else{
        choose();
    }
}

