#include <Password.h>
#include <Keypad.h>
#include <Servo.h> //使用舵機

int buzzer=11;
 
Servo myservo; //聲明 servo
Password password = Password( "841122" ); //密碼
 
const byte ROWS = 4;  //4行
const byte COLS = 4;  //4列
char keys[ROWS][COLS] = { //4*4薄膜按鍵
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3,4,5}; //連接腳位
byte colPins[COLS] = {6,7,8,9}; //連接腳位
 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup(){
  Serial.begin(9600);
  delay(200);
  myservo.attach(10); 
  myservo.write(10);
//舵机
  keypad.addEventListener(keypadEvent); //增加對鍵盤的偵聽
  pinMode(buzzer,OUTPUT);  
  }
 
void loop(){
  keypad.getKey();
  }
  //注意一些特殊的事件
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
  case PRESSED:
 
  Serial.print("Enter: ");
  Serial.println(eKey);
  delay(10);
 
  
 
  switch (eKey){
    case 'A': checkPassword(); delay(1); break;
    case 'B': password.reset(); delay(1); break;
    default: password.append(eKey); delay(1);
}
}
}
 
 
void checkPassword(){
 
if (password.evaluate()){  
 
    Serial.println("Accepted");//如果密碼正確開鎖
    delay(10);
    //如果開始工作，運行以下代碼
    myservo.write(180); 
    password.reset();

    for(int i=0;i<160;i++)//發出聲音
    {
      digitalWrite(buzzer,HIGH);
      delay(1);
      digitalWrite(buzzer,LOW);
      delay(1);
    }
    delay(5000);
    myservo.write(10);
 
}else{
    Serial.println("Denied"); //如果密碼錯誤保持鎖定
    delay(10);
    //如果沒有開始工作，運行以下代碼
    myservo.write(10);
    password.reset();
  int k = 5;
  while(k != 0){  
    k--;
    for(int i = 0; i < 80; i++){  //發出聲音
      digitalWrite(buzzer,HIGH);
      delay(1);
      digitalWrite(buzzer,LOW);
      delay(1);
    }
    for(int i = 0; i < 100; i++){
      digitalWrite(buzzer,HIGH);
      delay(2);
      digitalWrite(buzzer,LOW);
      delay(2);
    }
  }
}
}
