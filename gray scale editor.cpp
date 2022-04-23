// FCAI–CU - Programming 1 - Assignment 3
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
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char output_image[SIZE][SIZE];
static int change = SIZE - 1;
void loadImage();
void choose();
void saveImage();
void loadImage(unsigned char image[SIZE][SIZE]);
void saveImage(unsigned char image[SIZE][SIZE]);

int main()
{

    choose();

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
void loadImage (unsigned char image[SIZE][SIZE]) {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void saveImage (unsigned char image[SIZE][SIZE]) {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
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

void flip() {
    for (int i = 0; i <= 127; i++) {
        if (i != 0)
        {
            change -= 1;
        }
        for (int j = 0; j <= 254; j++) {
            swap(image[i][j], image[change][j]);
        }
    }
}
void black_and_white() {
    static long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg) {
                image[i][j] = 255;
            }
            else {
                image[i][j] = 0;
            }
        }
    }
}
void Detect_Image_Edges(){
    static long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            avg+=image[i][j];}  // taking the sum of every elemnt in the array
    }
    avg/=(SIZE*SIZE);//caculate the average color
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j]<avg&&image[i][j+1]<avg)
            {
                while (image[i][j+4]<avg) // if there is a black cell and black cells after it , makes theses cells white
                {
                    if (image[i+1][j]<avg)
                    {
                        image[i][j+2]=255;
                        j+=1;
                    }
                    else{
                        j+=1;
                    }

                }
            }
            if (image[i][j]>avg) // if cell is white , make it white
            {
                image[i][j]=255;
            }

        }
    }
}

void merge(){
    unsigned char image[SIZE][SIZE];
    unsigned char image2[SIZE][SIZE];
    unsigned char res_image[SIZE][SIZE];
    loadImage(image);
    loadImage(image2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            res_image[i][j] = (((image[i][j])+(image2[i][j])) / 2 );
        }
    }
    saveImage(res_image);
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
                image[change][j] = image[i][j];
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
                image[i][j] = image[change][j];
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
                image[i][j] = image[i][change];
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
                image[i][change] = image[i][j];
                change -= 1;
            }
        }
    }
    else {
        cout << "enter a valid number" << endl;
        mirror();
    }
}

void invertimage() {
    for (int i = 0; i < SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] == 0) {
                image[i][j] = 255;
            }
            else
                image[i][j] = (255 - image[i][j]);
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
                image[i][j] = image[i][j] + (image[i][j] + 256) / 2;
            }
        }
    }
    else if (choose == 'l' || choose == 'L') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][j] - (image[i][j] + 256) / 2;
            }
        }
    }
    else {
        cout << "invalid choice\n";
    }
}

void rotate() {
    string userinput = "";
    cout << "please choose if u want to rotate by 90 degrees or 180 or 270: ";
    cin >> userinput;
    if (userinput == "90") {


        //90 to rotate by 90 degrees

        for (int i = 0; i < SIZE; i++) {

            for (int j = i; j < SIZE; j++) {
                int temp = image[i][j];
                image[i][j] = image[j][i]; //flipping the pixel rows with the pixel columns (keeping the diagonal pixels as it is)
                image[j][i] = temp;
            }
        }


        for (int i = 0; i < SIZE; i++) {

            for (int j = 0; j < SIZE / 2; j++) {
                int temp = image[i][j];
                image[i][j] = image[i][SIZE - 1 - j]; //rotating by 90 degrees by changing the postion of the pixel columns (original rows)
                image[i][SIZE - 1 - j] = temp;
            }
        }
    }

    else if (userinput == "180") {


        //180 //rotating by 180 degrees

        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                swap(image[i][j], image[SIZE - i - 1][SIZE - j - 1]); // swapping the first pixel row with the before last row and same goes for other pixel rows and columns
            }

        }
    }
    else if (userinput == "270") {


        //270 //rotatong by 270 degrees

        for (int i = 0; i < SIZE; ++i) {
            for (int j = i; j < SIZE; ++j) {
                swap(image[i][j], image[j][i]); //swapping the pixel row with pixel column

            }
        }
        for (int i = 0; i < SIZE; i++) {

            for (int j = 0; j < SIZE / 2; j++) {
                swap(image[i][j], image[j][SIZE - 1 - j]); //changing only the pixel columns (original rows) to keep the diagonal pixels as it is
            }
        }
    }
    else {
        cout << "invalid input";
    }
}

void enlarge() {
    loadImage(image);
    cout << "which quarter do want to enlarge : \n";
    int choose;
    cout << "1- first quarter \n";
    cout << "2- second quarter \n";
    cout << "3- third quarter \n";
    cout << "4- fourth quarter \n";
    cin >> choose;
    if (choose == 1) {
        for (int i = 0, x=0; i <= SIZE/2; i++, x+=2) {
            for (int j = 0, y=0; j< SIZE/2; j++, y+=2) {
                output_image[x][y] = image[i][j];
                output_image[x][y-1] = image[i][j];
                output_image[x-1][y] = image[i][j];
                output_image[x-1][y-1] = image[i][j];
            }
        }
        saveImage(output_image);
    }

    else if (choose == 2){
        for (int i = 0, x = 0; i <= SIZE/2; i++, x+=2) {
            for (int j = SIZE/2, y=0; j< SIZE; j++, y+=2){
                output_image[x][y] = image[i][j];
                output_image[x][y-1] = image[i][j];
                output_image[x-1][y] = image[i][j];
                output_image[x-1][y-1] = image[i][j];
            }
        }
        saveImage(output_image);
    }
    else if (choose == 3){
        for (int i = SIZE/2, x=0; i <= SIZE; i++, x+=2) {
            for (int j = 0, y=0; j< SIZE/2; j++, y+=2) {
                output_image[x][y] = image[i][j];
                output_image[x][y-1] = image[i][j];
                output_image[x-1][y] = image[i][j];
                output_image[x-1][y-1] = image[i][j];
            }
        }
        saveImage(output_image);
    }
    else if (choose == 4){
        for (int i = SIZE/2, x=0; i <= SIZE; i++, x+=2) {
            for (int j = SIZE/2, y=0; j< SIZE; j++, y+=2) {
                output_image[x][y] = image[i][j];
                output_image[x][y-1] = image[i][j];
                output_image[x-1][y] = image[i][j];
                output_image[x-1][y-1] = image[i][j];
            }
        }
        saveImage(output_image);
    }

    else
        cout<<"wrong input, salam; \n";

}

void shuffle(){
    loadImage(image);
        for (int i = 0, l = SIZE / 2; i <= SIZE / 2, l < SIZE; i++, l++) {
            for (int j = 0, k = 0; j < SIZE / 2, k < SIZE / 2; j++, k++) {
                output_image[l][k] = image[i][j];
            }
        }
        for (int i = 0, l = 0; i <= SIZE / 2, l < SIZE / 2; i++, l++) {
            for (int j = SIZE / 2, k = 0; j < SIZE, k < SIZE / 2; j++, k++) {
                output_image[l][k] = image[i][j];
            }
        }
        for (int i = SIZE / 2, l = SIZE / 2; i <= SIZE, l < SIZE; i++, l++) {
            for (int j = 0, k = SIZE / 2; j < SIZE / 2, k < SIZE; j++, k++) {
                output_image[l][k] = image[i][j];
            }
        }
        for (int i = SIZE / 2, l = 0; i <= SIZE, l < SIZE / 2; i++, l++) {
            for (int j = SIZE / 2, k = SIZE / 2; j < SIZE, k < SIZE; j++, k++) {
                output_image[l][k] = image[i][j];
            }
        }
    saveImage(output_image);
    }


void blur(){

    double average;

    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            int sum = 0;
            sum = image[i ][j ] + image[i ][j+1] + image[i][j + 2] + image[i+1][j] + image[i+1][j+1] +image[i+1][j +2] + image[i +2][j ] + image[i + 2][j+1] + image[i + 2][j + 2];
            average = (sum / 9);
            image[i][j] = average;
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
    unsigned char image[SIZE][SIZE];
    unsigned char shrink_image[SIZE][SIZE];
    if(ratio != "0"){
        // to make the shrink image array all have value 255 (white picture)
        loadImage(image);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                shrink_image[i][j] = 255;
            }
        }
        // to make shrink to half 1/2
        if(ratio == "1/2") {
            for (int i = 0; i < (SIZE/2); i++) {
                for (int j = 0; j < (SIZE/2); j++) {
                    shrink_image[i][j] = image[2 * i][2 * j];
                }
            }
            saveImage(shrink_image);
        }
        else if(ratio == "1/3"){
            for (int i = 0; i < (SIZE/3); i++) {
                for (int j = 0; j < (SIZE/3); j++) {
                    shrink_image[i][j] = image[3 * i][3 * j];
                }
            }
            saveImage(shrink_image);
        }
        else if(ratio == "1/4"){
            for (int i = 0; i < (SIZE /4); i++) {
                for (int j = 0; j < (SIZE /4); j++) {
                    shrink_image[i][j] = image[4 * i][4 * j];
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

    while (!(cin >> x))
    {
        cout << "enter a valid num" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (x == 0)
    {
       loadImage();
        black_and_white();
       saveImage();
    }
    else if (x == 1)
    {
        loadImage();
        invertimage();
        saveImage();
    }
    else if (x == 2)
    {
        merge();
    }
    else if (x == 3)
    {
        loadImage();
        flip();
        saveImage();
    }
    else if (x == 4)
    {
        loadImage();
        rotate();
        saveImage();
    }
    else if (x == 5)
    {
        loadImage();
        Darken_and_Lighten_Image();
        saveImage();
    }
    else if (x == 6)
    {
        loadImage();
        Detect_Image_Edges();
        saveImage();
    }
    else if (x == 7)
    {
      //  loadimage();
        enlarge();
       // saveimage();
    }
    else if (x == 8)
    {
        Shrink();
    }
    else if (x == 9)
    {
        loadImage();
        mirror();
        saveImage();
    }
    else if (x == 10)
    {
       // loadimage();
        shuffle();
        //saveimage();
    }
    else if (x == 11)
    {
        loadImage();
        blur();
        saveImage();
    }
    else {
        choose();
    }
}
