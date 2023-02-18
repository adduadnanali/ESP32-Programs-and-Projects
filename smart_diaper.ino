
int soil=A0;
int moisture;

void setup(){
   pinMode(soil,INPUT);
   Serial.begin(9600);
  }

void loop(){
   moisture=analogRead(soil);
   moisture=moisture-268;
   if (isnan(moisture)){
     return;
    }

   Serial.print("#");
   Serial.print(",");
   Serial.print(moisture);
   Serial.print(",");
   Serial.println("~");
   delay(1000);
  }
