
int analogPin = 0;  //水位感測器
int buzzer = 13;  //蜂鳴器
int val = 0; 

void setup()
{
  pinMode(buzzer, OUTPUT); //定義蜂鳴器為輸出裝置
  Serial.begin(9600); //設定波特律為9600
  
}

void loop()
{
  val = analogRead(analogPin); //讀取模擬值送給變量val
  Serial.println(val);  //在監控視窗印出val
  delay(1000);
  if(val > 300){  //當水位到達一定高度→蜂鳴器開始發出聲音
    for(int i=0;i<160;i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(1);
      digitalWrite(buzzer,LOW);
      delay(1);
    }
  }
}
