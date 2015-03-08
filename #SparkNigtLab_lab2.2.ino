int led1 = D0; // We name pin D0 as led
void setup() { 
   Spark.function("led", ledControl);
   pinMode(led1, OUTPUT);
   digitalWrite(led1, LOW);
} 
void loop() { }

int ledControl(String command){
   int state = 0;
   int pinNumber = (command.charAt(1) - '0') - 1;
   if(pinNumber < 0 || pinNumber > 1)
      return pinNumber;
   if (command.substring(3,7) == "HIGH") 
      state = 1;
   else if(command.substring(3,6) == "LOW") 
      state = 0;
   else    
      return  -1;
   digitalWrite(pinNumber, state);
   return 1;
}
