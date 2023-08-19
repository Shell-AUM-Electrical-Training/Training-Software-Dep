/*libraries*/
#include <Keypad.h>

//=======================================================================

/*KeyPad Declaration using the keypad.h library */

const byte ROWS = 4; // four rows
const byte COLS = 3; // three columns

// define the cymbols on the buttons of the keypads

char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {3, 2, 1, 0}; // connect to the row pinouts of the keypad

byte colPins[COLS] = {4, 5, 6}; // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//=======================================================================

/*7segment declaration*/
const int segment[7] = {7, 8, 9, 10, 11, 12, 13}; // pins for each segment

const int nums[10][7] = // declaring array
    {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 0, 0, 1, 1}  // 9
};

//=======================================================================

void setup()
{
    for (int i = 7; i <= 13; i++) // shorcut for declaring  pin modes of 7segment
    {
        pinMode(i, OUTPUT);
    }
}
//======================================================================
void loop()
{

    char key = customKeypad.getKey();
    if (key)
    {
        int x = key - '0'; /* TO make if the key='7' also x=7 so i can use it in array   as character
                             '0' has a decimal value of 48, subtracting it from the character '7'
                             (with a decimal value of 55) gives you the integer value 7  ( ASCII encoding,)*/

        for (int j = 0; j < 7; ++j) // instead od diong this digitalwriter(7,HIGH), digitalwriter(8,HIGH),....and so on
        {
            digitalWrite(segment[j], nums[x][j]);
        }
    }
}
