const char col = 3;  // columns of keypad matrix.
const char row = 4 ; // rows of keypad matrix.


char Columns[3] = {5,4,3}; // keypad column pins .
char Rows[4] = {9,8,7,6}; // keypad row pins.
char OUT[4] = {13,12,11,10}; // output pins to 7-segment decoder.
char key[4][3] = {{1,2,3},{4,5,6},{7,8,9},{0,0,0}}; // keypad values matrix (since # and * are not represented in the 7-segment , I set them to 0).
char key_fetch = 0 ;  //global variable used in the function to read the pressed key.


char check_key(); //a function that scans the pressed key.


void setup() {
  for (char i = 0 ; i < row ; i++)
  {
    pinMode(OUT[i],OUTPUT);  // output to 7-segment decoder pins
    pinMode(Rows[i],INPUT);  // Rows of the matrix are set as input (set intially to LOW by external pull down resistors).
    if (i<3) pinMode(Columns[i],OUTPUT);  //column pins set as output to continuosly scan the rows.
  }
}


void loop() {
  
  char key_pressed = check_key();

  switch (key_pressed)
  {
    case 0 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],0);digitalWrite(OUT[1],0);digitalWrite(OUT[0],0); // 0000 = 0
      break ;
    case 1 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],0);digitalWrite(OUT[1],0);digitalWrite(OUT[0],1); // 0001 = 1
      break ;
    case 2 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],0);digitalWrite(OUT[1],1);digitalWrite(OUT[0],0); // 0010 = 2
      break ;
    case 3 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],0);digitalWrite(OUT[1],1);digitalWrite(OUT[0],1); // 0011 = 3
      break ;
    case 4 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],1);digitalWrite(OUT[1],0);digitalWrite(OUT[0],0); // 0100 = 4
       break ;
    case 5 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],1);digitalWrite(OUT[1],0);digitalWrite(OUT[0],1); // 0101 = 5
      break ;
    case 6 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],1);digitalWrite(OUT[1],1);digitalWrite(OUT[0],0); // 0110 = 6
      break ;
    case 7 :
      digitalWrite(OUT[3],0);digitalWrite(OUT[2],1);digitalWrite(OUT[1],1);digitalWrite(OUT[0],1); // 0111 = 7
      break ;
    case 8 :
      digitalWrite(OUT[3],1);digitalWrite(OUT[2],0);digitalWrite(OUT[1],0);digitalWrite(OUT[0],0); // 1000 = 8
      break;
    case 9 :
      digitalWrite(OUT[3],1);digitalWrite(OUT[2],0);digitalWrite(OUT[1],0);digitalWrite(OUT[0],1); // 1001 = 9
      break;
  }
}




char check_key()
{
  for(char k = 0 ; k < col ; k++)
  {
    digitalWrite(Columns[k],HIGH);
    for (char j = 0 ; j < row ; j++)
    {
        if (digitalRead(Rows[j]) == HIGH)
        {
          key_fetch = key[j][k];
        }
    }
    digitalWrite(Columns[k],LOW);
  }
  delay(10); 
  return key_fetch;
}
/*This function continously changes the state of the column pins between high and low each pin at a time 
  when a button is pressed the column pin is now connected to the row pin , so when the column pin is HIGH
  the row pin will also read HIGH (it's intially set to Low with pull down resistors) , so now we know which button exactly is pressed
  and the function returns a variable that contains the value of the pressed key (stored in the double array "key").*/