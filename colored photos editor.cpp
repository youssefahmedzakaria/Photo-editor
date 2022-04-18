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
void black_and_white() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int x = 0; x < RGB; x++){
        if(x ==0){
            if (image[i][j][x] < 127 )
        {
            image[i][j][x] =255;
            image[i][j][x+1] =255;
            image[i][j][x+2] =255;
        }
            else{
            image[i][j][x] =0;
            image[i][j][x+1] =0;
            image[i][j][x+2] =0;
            }
            }
        if(x ==1){
            if (image[i][j][x] < 127 )
        {
            image[i][j][x-1] =255;
            image[i][j][x] =255;
            image[i][j][x+1] =255;
        }
            else{
            image[i][j][x-1] =0;
            image[i][j][x] =0;
            image[i][j][x+1] =0;
            }
            }
        if(x ==2){
            if (image[i][j][x] < 127 )
        {
            image[i][j][x-2] =255;
            image[i][j][x-1] =255;
            image[i][j][x] =255;
            }
            else{
            image[i][j][x-2] =0;
            image[i][j][x-1] =0;
            image[i][j][x] =0;
            }
            }
        }
    }
    }
}
void flip(){
    cout<<"1-horizontal"<<endl;
    cout<<"2-vertical"<<endl;
    int x;
    while (!(cin>>x)) // check if input!= int then he will ask user to input an int
    {
        cout<<"enter a valid num"<<endl;
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(x==1)
    {for (int i = 0; i < SIZE/2; i++) {
        if (i!=0)
        {
            change-=1;
            }
    for (int j = 0; j< SIZE; j++) 
    {
        for (int x = 0; x < RGB; x++){
            swap(image[i][j][x] ,image[change][j][x]);
            }
            }
    }  
    }
    else if(x==2){
        for (int i = 0; i < SIZE; i++) {
            change = 254;
        for (int j = 0; j<= 127; j++) 
        {
            if(j!=0){
                change-=1;
            }
            for (int x = 0; x < RGB; x++){
                swap(image[i][j][x] ,image[i][change][x]);
                }
                }
    }  
    }
    if(x!=1 && x!=2){
        cout<<"please write a valid number"<<endl;
        flip();
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
            for(int x = 0; x <= RGB ; x++)
            {image[change][j][x]=image[i][j][x];}// replacing last rows by first rows
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
            for(int x = 0; x <= RGB ; x++)
            {image[i][j][x]=image[change][j][x];}// replacing first last rows by last rows
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
            for(int x = 0; x <= RGB ; x++)
            {image[i][j][x]=image[i][change][x];} //replacing first coulmns by last coulmns
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
            for(int x = 0; x <= RGB ; x++)
            {image[i][change][x]=image[i][j][x];}//replacing last coulmns by first coulmns
            change-=1;
            }      
    }
    }
    else{
        cout<<"enter a valid number"<<endl;
        mirror();
    }
}
void Detect_Image_Edges(){
for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int x = 0; x < RGB; x++){
        if(x ==0){
            if (image[i][j][x] < 127 )
        {
            image[i][j][x] =255;
            image[i][j][x+1] =255;
            image[i][j][x+2] =255;
        }
            else{
            image[i][j][x] =0;
            image[i][j][x+1] =0;
            image[i][j][x+2] =0;
            }
            }
        if(x ==1){
            if (image[i][j][x] < 127 )
        {
            image[i][j][x-1] =255;
            image[i][j][x] =255;
            image[i][j][x+1] =255;
        }
            else{
            image[i][j][x-1] =0;
            image[i][j][x] =0;
            image[i][j][x+1] =0;
            }
            }
        if(x ==2){
            if (image[i][j][x] < 127 )
        {
            image[i][j][x-2] =255;
            image[i][j][x-1] =255;
            image[i][j][x] =255;
            }
            else{
            image[i][j][x-2] =0;
            image[i][j][x-1] =0;
            image[i][j][x] =0;
            }
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
        black_and_white();
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
        flip();
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
        Detect_Image_Edges();
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
        mirror();
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
