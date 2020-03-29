  int inputPin=4; //超音波輸入
int outputPin=5; //超音波輸出
int LED = 13; //LED燈                
int val = 0; 
int button = 12;  //蜂鳴器                      
int num = 0;

void light(){
  val = analogRead(0);   
      
  //Serial.println(val);       
  delay(50);
  if(val>800 && distance() > 30){    // 晚上且開門->開燈
    digitalWrite(LED,HIGH);
  }
  else{                        // 白天或沒開門->關燈
    digitalWrite(LED,LOW);
  }
  delay(10);             
}

int distance(){ //探測距離
  digitalWrite(outputPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(outputPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(outputPin, LOW);   
  int distance = pulseIn(inputPin, HIGH);  
  distance= distance/58; 
  Serial.println(distance); 
  return distance;
  delay(50); 
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(inputPin, INPUT); 
  pinMode(outputPin, OUTPUT); 
  Serial.begin(9600);
  pinMode(button, INPUT);  
}

void loop() {

  light();
}
