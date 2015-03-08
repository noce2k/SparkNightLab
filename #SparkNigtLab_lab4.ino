//
// Lab presented during the 1st edition of SparkNightLab in Turin 6-Mar-2015
// this is an example provided by Spark and presented by @marcobodoira and @noce2k 
// ----------------------------------------------------------------------------------

#include "HttpClient/HttpClient.h"
#include "application.h"

unsigned int nextTime = 0;    // Next time to contact the server
HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
      { "Content-Type", "application/json" },
      { "Accept" , "application/json" },
      {"x-temboo-domain", "/sparknightlab/master"},
      {"Authorization", "Basic bXlGaXJzdEFwcDo5ZmQyZDFiMTMzNzU0YTYyYjliZDY0OWExOii3ZWNlMw"},
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

void setup() {
Serial.begin(9600);
Delay(10000);
}

void loop() {
    if (nextTime > millis()) {
          Serial.println("waiting");
        return;
    }
    Serial.println();
    Serial.println("Application>\tStart of Loop.");
    // Request path and body can be set at runtime or at setup.
    request.hostname = "sparknightlab.temboolive.com";
    request.port = 80;
    request.path = "/temboo-api/1.0/choreos/Library/Twilio/SMSMessages/SendSMS";
    // The library also supports sending a body with your request:
    request.body = "{\"inputs\": [	{\"name\":\"AuthToken\", \"value\":\"30696956308f7b37b2867125c8551ce1\"}, 	{\"name\":\"Body\", \"value\":\"ciao da temboo. #sparknightlab Hack the World!!\"}, 	{\"name\":\"To\", \"value\":\"+393481036744\"}, 	{\"name\":\"AccountSID\", \"value\":\"AC9d4ca5ef598febbb90ade7709277b09d\"}, 	{\"name\":\"From\", \"value\":\"+15105926788\"}]}";
    // Get request
    http.post(request, response, headers);
    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    nextTime = millis() + 2000000;
    delay(10000);
}
