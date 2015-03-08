//
// Lab presented during the 1st edition of SparkNightLab in Turin 6-Mar-2015
// this is an example provided by Spark and presented by @marcobodoira and @noce2k 
// ----------------------------------------------------------------------------------

//Create a variable that will store the temperature value
double temperature = 0.0;
void setup(){
 // Register a Spark variable here
  Spark.variable("temperature", &temperature, DOUBLE);
  // Connect the temperature sensor to A7 and configure it
  // to be an input
  pinMode(A7, INPUT);
}

void loop(){
  int reading = 0;
  double voltage = 0.0;
  // Keep reading the sensor value so when we make an API
  // call to read its value, we have the latest one
  reading = analogRead(A7);
  // The returned value from the Core is in the range 0 - 4095
  // Calculate the voltage from the sensor reading
  voltage = (reading * 3.3) / 4095;
  // Calculate the temperature and update our static variable
  temperature = (voltage - 0.5) * 100;
}
