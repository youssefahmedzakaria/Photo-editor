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
void loadImage(unsigned char image[SIZE][SIZE][RGB]);
void saveImage(unsigned char image[SIZE][SIZE][RGB]);

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
void loadImage(unsigned char image[SIZE][SIZE][RGB]) {
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
void saveImage(unsigned char image[SIZE][SIZE][RGB]) {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
    writeRGBBMP(imageFileName, output_image);
}
void merge(){
    unsigned char image[SIZE][SIZE][RGB];
    unsigned char image2[SIZE][SIZE][RGB];
    unsigned char res_image[SIZE][SIZE][RGB];
    loadImage(image);
    loadImage(image2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                res_image[i][j][k] = (((image[i][j][k])+(image2[i][j][k])) / 2 );
            }

        }
    }
    saveImage(res_image);
}

void rotate(){
    //90
    cout << "by how many degrees do u want to rotate? type 90 or 180 or 270: ";
    int userinput;
    cin>>userinput;
    if(userinput==90) {


        for (int i = 0; i < SIZE; i++) {

            for (int j = i; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    int temp = image[i][j][k];
                    image[i][j][k] = image[j][i][k];
                    image[j][i][k] = temp;
                }

            }
        }

        for (int i = 0; i < SIZE; i++) {

            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; ++k) {
                    int temp = image[i][j][k];
                    image[i][j][k] = image[i][SIZE - 1 - j][k];
                    image[i][SIZE - 1 - j][k] = temp;
                }

            }
        }
    }

        //180
    else if (userinput==180){

        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j <SIZE ; ++j) {
                for (int k = 0; k <RGB ; ++k) {


                    swap(image[i][j][k],image[SIZE-i-1][SIZE-j-1][k]);
                }
            }

        }
    }

 else if (userinput==270){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = i; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {


                    swap(image[i][j][k], image[j][i][k]);
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {

            for (int j = 0; j < SIZE/2; j++) {
                for (int k = 0; k < RGB; ++k) {


                    swap(image[i][j][k], image[j][SIZE - 1 - j][k]);
                }
            }
        }
 }
 else {
        cout << "invalid input";
    }
}


void invertimage() {
    for (int i = 0; i < SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                if (image[i][j][k] == 0) {
                    output_image[i][j][k] = 255;
                }
                else {
                    output_image[i][j][k] = (255 - image[i][j][k]);
                }
            }
        }
    }
}
void black_and_white() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int x = 0; x < RGB; x++) {
                if (x == 0) {
                    if (image[i][j][x] < 127)
                    {
                        image[i][j][x] = 255;
                        image[i][j][x + 1] = 255;
                        image[i][j][x + 2] = 255;
                    }
                    else {
                        image[i][j][x] = 0;
                        image[i][j][x + 1] = 0;
                        image[i][j][x + 2] = 0;
                    }
                }
                if (x == 1) {
                    if (image[i][j][x] < 127)
                    {
                        image[i][j][x - 1] = 255;
                        image[i][j][x] = 255;
                        image[i][j][x + 1] = 255;
                    }
                    else {
                        image[i][j][x - 1] = 0;
                        image[i][j][x] = 0;
                        image[i][j][x + 1] = 0;
                    }
                }
                if (x == 2) {
                    if (image[i][j][x] < 127)
                    {
                        image[i][j][x - 2] = 255;
                        image[i][j][x - 1] = 255;
                        image[i][j][x] = 255;
                    }
                    else {
                        image[i][j][x - 2] = 0;
                        image[i][j][x - 1] = 0;
                        image[i][j][x] = 0;
                    }
                }
            }
        }
    }
}
void flip() {
    cout << "1-horizontal" << endl;
    cout << "2-vertical" << endl;
    int x;
    while (!(cin >> x)) // check if input!= int then he will ask user to input an int
    {
        cout << "enter a valid num" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (x == 1)
    {
        for (int i = 0; i < SIZE / 2; i++) {
            if (i != 0)
            {
                change -= 1;
            }
            for (int j = 0; j < SIZE; j++)
            {
                for (int x = 0; x < RGB; x++) {
                    swap(image[i][j][x], image[change][j][x]);
                }
            }
        }
    }
    else if (x == 2) {
        for (int i = 0; i < SIZE; i++) {
            change = 254;
            for (int j = 0; j <= 127; j++)
            {
                if (j != 0) {
                    change -= 1;
                }
                for (int x = 0; x < RGB; x++) {
                    swap(image[i][j][x], image[i][change][x]);
                }
            }
        }
    }
    if (x != 1 && x != 2) {
        cout << "please write a valid number" << endl;
        flip();
    }
}
void mirror() {
    int reverse;
    cout << "1- up to down" << endl;
    cout << "2- down to up" << endl;
    cout << "3- right to left" << endl;
    cout << "4- left to right" << endl;
    while (!(cin >> reverse))
    {
        cout << "enter a valid num" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (reverse == 1)
    {
        for (int i = 0; i <= 127; i++) {
            if (i != 0)
            {
                change -= 1;
            }
            for (int j = 0; j <= 254; j++) {
                for (int x = 0; x <= RGB; x++)
                {
                    image[change][j][x] = image[i][j][x];
                }// replacing last rows by first rows
            }
        }
    }
    else if (reverse == 2)
    {
        for (int i = 0; i <= 127; i++) {
            if (i != 0)
            {
                change -= 1;
            }
            for (int j = 0; j <= 254; j++) {
                for (int x = 0; x <= RGB; x++)
                {
                    image[i][j][x] = image[change][j][x];
                }// replacing first last rows by last rows
            }
        }
    }
    else if (reverse == 3)
    {
        for (int i = 0; i <= 254; i++) {
            if (i != 0)
            {
                change = 254;
            }
            for (int j = 0; j <= 127; j++) {
                for (int x = 0; x <= RGB; x++)
                {
                    image[i][j][x] = image[i][change][x];
                } //replacing first coulmns by last coulmns
                change -= 1;
            }
        }
    }
    else if (reverse == 4)
    {
        for (int i = 0; i <= 254; i++) {
            if (i != 0)
            {
                change = 254;
            }
            for (int j = 0; j <= 127; j++) {
                for (int x = 0; x <= RGB; x++)
                {
                    image[i][change][x] = image[i][j][x];
                }//replacing last coulmns by first coulmns
                change -= 1;
            }
        }
    }
    else {
        cout << "enter a valid number" << endl;
        mirror();
    }
}
void Detect_Image_Edges(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int x = 0 ; x<RGB ; x++)
            {if (image[i][j][x]<127)
            {
                while ((image[i][j][x]<=image[i][j+1][x]+10 &&image[i][j][x]>=image[i][j+1][x]) || (image[i][j][x]+10>=image[i][j+1][x]&&image[i][j][x]<=image[i][j+1][x])) // if there is a black cell and black cells after it , makes theses cells white
                {
                    if((image[i][j][x]<=image[i+1][j][x]+10&&image[i][j][x]>=image[i+1][j][x])||(image[i][j][x]+10>=image[i+1][j][x]&&image[i][j][x]<=image[i+1][j][x]))
                    {
                    if(x ==0){
                        image[i][j][x] =255;
                        image[i][j][x+1] =255;
                        image[i][j][x+2] =255;}
                    if(x ==1){
                        image[i][j][x-1] =255;
                        image[i][j][x] =255;
                        image[i][j][x+1] =255;
                        }
                    if(x ==2){
                        image[i][j][x-2] =255;
                        image[i][j][x-1] =255;
                        image[i][j][x] =255;
                        }
                    j+=1;}
                else{
                    j+=1;
                }
            }          
            }
            }
            }      
    }
}
void blur(){

    double average;

    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            for (int k =0 ; k <3; k++){
                int sum = 0;
                sum = image[i ][j ][k] + image[i ][j+1][k] + image[i][j + 2][k] + image[i+1][j][k] + image[i+1][j+1][k] +image[i+1][j +2][k] + image[i +2][j ][k] + image[i + 2][j+1][k] + image[i + 2][j + 2][k];
                average = (sum / 9);
                image[i][j][k] = average;
            }

        }
    }
}
void Darken_and_Lighten_Image()
{
    char choose;
    cout << "Do you want to (d)arken or (l)ighten?";
    cin >> choose;
    if (choose == 'd' || choose == 'D') {
        for (int i = 0; i < SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    image[i][j][k] -= (image[i][j][k]) / 2;
                    output_image[i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else if (choose == 'l' || choose == 'L') {
        for (int i = 0; i < SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    image[i][j][k] = (image[i][j][k] + 256) / 2;
                    output_image[i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else {
        cout << "invalid choice\n";
    }
}

void enlarge() {
    cout << "which quarter do want to enlarge : \n";
    int choose;
    cout << "1- first quarter \n";
    cout << "2- second quarter \n";
    cout << "3- third quarter \n";
    cout << "4- fourth quarter \n";
    cin >> choose;
    if (choose == 1) {
        for (int i = 0, x = 0; i <= SIZE / 2; i++, x += 2) {
            for (int j = 0, y = 0; j < SIZE / 2; j++, y += 2) {
                for (int k = 0; k < RGB; k++) {
                    output_image[x][y][k] = image[i][j][k];
                    output_image[x][y - 1][k] = image[i][j][k];
                    output_image[x - 1][y][k] = image[i][j][k];
                    output_image[x - 1][y - 1][k] = image[i][j][k];
                }
            }
        }
    }

    else if (choose == 2) {
        for (int i = 0, x = 0; i <= SIZE / 2; i++, x += 2) {
            for (int j = SIZE / 2, y = 0; j < SIZE; j++, y += 2) {
                for (int k = 0; k < RGB; k++) {
                    output_image[x][y][k] = image[i][j][k];
                    output_image[x][y - 1][k] = image[i][j][k];
                    output_image[x - 1][y][k] = image[i][j][k];
                    output_image[x - 1][y - 1][k] = image[i][j][k];
                }
            }
        }
    }
    else if (choose == 3) {
        for (int i = SIZE / 2, x = 0; i <= SIZE; i++, x += 2) {
            for (int j = 0, y = 0; j < SIZE / 2; j++, y += 2) {
                for (int k = 0; k < RGB; k++) {
                    output_image[x][y][k] = image[i][j][k];
                    output_image[x][y - 1][k] = image[i][j][k];
                    output_image[x - 1][y][k] = image[i][j][k];
                    output_image[x - 1][y - 1][k] = image[i][j][k];
                }
            }
        }
    }
    else if (choose == 4) {
        for (int i = SIZE / 2, x = 0; i <= SIZE; i++, x += 2) {
            for (int j = SIZE / 2, y = 0; j < SIZE; j++, y += 2) {
                for (int k = 0; k < RGB; k++) {
                    output_image[x][y][k] = image[i][j][k];
                    output_image[x][y - 1][k] = image[i][j][k];
                    output_image[x - 1][y][k] = image[i][j][k];
                    output_image[x - 1][y - 1][k] = image[i][j][k];
                }
            }
        }
    }
    else
        cout << "wrong input, salam; \n";
}

void shuffle() {

    for (int i = 0, l = SIZE / 2; i <= SIZE / 2, l < SIZE; i++, l++) {
        for (int j = 0, k = 0; j < SIZE / 2, k < SIZE / 2; j++, k++) {
            for (int r = 0; r < RGB; r++) {
                output_image[l][k][r] = image[i][j][r];
            }
        }
    }
    for (int i = 0, l = 0; i <= SIZE / 2, l < SIZE / 2; i++, l++) {
        for (int j = SIZE / 2, k = 0; j < SIZE, k < SIZE / 2; j++, k++) {
            for (int r = 0; r < RGB; r++) {
                output_image[l][k][r] = image[i][j][r];
            }
        }
    }
    for (int i = SIZE / 2, l = SIZE / 2; i <= SIZE, l < SIZE; i++, l++) {
        for (int j = 0, k = SIZE / 2; j < SIZE / 2, k < SIZE; j++, k++) {
            for (int r = 0; r < RGB; r++) {
                output_image[l][k][r] = image[i][j][r];
            }
        }
    }
    for (int i = SIZE / 2, l = 0; i <= SIZE, l < SIZE / 2; i++, l++) {
        for (int j = SIZE / 2, k = SIZE / 2; j < SIZE, k < SIZE; j++, k++) {
            for (int r = 0; r < RGB; r++) {
                output_image[l][k][r] = image[i][j][r];
            }
        }
    }
}
string shrink_response(){
    string ratio;
    cout << "Do you wish to Shrink to (1/2), (1/3) or (1/4) ? write only the number without brackets, to exit from filter enter 0" << endl;
    while(true) {
        cout << "what ratio you want to shrink photo to it : " << endl;
        cin >> ratio;
        if ((ratio == "1/2") or (ratio == "1/3") or (ratio == "1/4")) {
            return ratio;
        }
        else if(ratio == "0"){
            cout << "end filter " << endl;
            return 0;
        }
        else {
            cout << "please enter valid degree" << endl;
            cin.ignore();
        }
    }
}
void Shrink(){
    string ratio = shrink_response();
    unsigned char image[SIZE][SIZE][RGB];
    unsigned char shrink_image[SIZE][SIZE][RGB];
    if(ratio != "0"){
        // to make the shrink image array all have value 255 (white picture)
        loadImage(image);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; ++k) {
                    shrink_image[i][j][k] = 255;
                }

            }
        }
        // to make shrink to half 1/2
        if(ratio == "1/2") {
            for (int i = 0; i < (SIZE/2); i++) {
                for (int j = 0; j < (SIZE/2); j++) {
                    for (int k = 0; k < 3; ++k){
                        shrink_image[i][j][k] = image[2 * i][2 * j][k];
                    }

                }
            }
            saveImage(shrink_image);
        }
        else if(ratio == "1/3"){
            for (int i = 0; i < (SIZE/3); i++) {
                for (int j = 0; j < (SIZE/3); j++) {
                    for (int k = 0; k < 3; ++k){
                        shrink_image[i][j][k] = image[3 * i][3 * j][k];
                    }

                }
            }
            saveImage(shrink_image);
        }
        else if(ratio == "1/4"){
            for (int i = 0; i < (SIZE /4); i++) {
                for (int j = 0; j < (SIZE /4); j++) {
                    for (int k = 0; k < 3; ++k) {


                        shrink_image[i][j][k] = image[4 * i][4 * j][k];
                    }
                }

            }
            saveImage(shrink_image);
            cout << "end filter " << endl;
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
        merge();
    }
    else if (x == 3)
    {
        flip();
    }
    else if (x == 4)
    {
          rotate();
    }
    else if (x == 5)
    {
        Darken_and_Lighten_Image();
    }
    else if (x == 6)
    {
        Detect_Image_Edges();
    }
    else if (x == 7)
    {
        enlarge();
    }
    else if (x == 8)
    {
       Shrink();
    }
    else if (x == 9)
    {
        mirror();
    }
    else if (x == 10)
    {
        shuffle();
    }
    else if (x == 11)
    {
        blur();
    }
    else {
        choose();
    }
}
