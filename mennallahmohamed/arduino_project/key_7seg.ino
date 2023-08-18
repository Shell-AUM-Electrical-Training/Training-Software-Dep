#include <Keyboard.h>

#include <Keypad.h>
int i=0;
int arr[4]={6,5,4,3};
int dis[10][4]{
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1},
  };
const byte rows=4;
const byte col=3;
char keys[rows][col]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'},
  };
  byte rowpins[rows]={13,12,11,10};
  byte colpins[col]={9,8,7};
  Keypad keypad=Keypad(makeKeymap(keys),rowpins,colpins,rows,col);
void setup() {
  for(i=0;i<4;i++){
    pinMode(arr[i],OUTPUT);
    }

}

void loop() {
  
  char key = keypad.getKey();
  
switch(key){
  case'0':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[0][i]);
  }
  break;
   case'1':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[1][i]);
  }
  break;
   case'2':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[2][i]);
  }
  break;
   case'3':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[3][i]);
  }
  break;
   case'4':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[4][i]);
  }
  break;
   case'5':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[5][i]);
  }
  break;
  case'6':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[6][i]);
  }
  break;
  case'7':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[7][i]);
  }
  break;
  case'8':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[8][i]);
  }
  break;
  case'9':
  for(i=0;i<4;i++){
  digitalWrite(arr[i],dis[9][i]);
  }
  break;
  default:
  break;
}
    
    }

