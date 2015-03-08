//
// Lab presented during the 1st edition of SparkNightLab in Turin 6-Mar-2015
// this is an example provided by Spark and presented by @marcobodoira and @noce2k 
// ----------------------------------------------------------------------------------

// This #include statement was automatically added by the Spark IDE.
#include "HttpClient/HttpClient.h"


#include "application.h"

/**
* Declaring the variables.
*/
unsigned int nextTime = 0;    // Next time to contact the server
HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
      { "Content-Type", "application/json" },
      { "Accept" , "application/json" },
      {"x-temboo-domain", "/noce2k/master"},
      {"Authorization", "Basic bXlGaXJzdEFwcDo1NmIzMTk4ZmQ0MGY0OGE2YjhhNTI2YjZkNWQwMzllNw=="},
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

void setup() {
    Delay(2000);
    Serial.begin(9600);
      Serial.println("setup");
    Delay(10000);
}

/*
curl --basic -u "myFirstApp":"56b3198fd40f48a6b8a526b6d5d03997" --header "x-temboo-domain: /noce2k/master" --header "Content-Type: application/json" --header "Accept: application/json" -X POST --data '{
"inputs": [	{"name":"AccessToken", "value":"2996878047-ltPLnxsMsQ46lpJ95omyBBXb3FZjzLdGr69BwKW"}, 	{"name":"AccessTokenSecret", "value":"3WmC3IKPphHxyTzV5GuwTpEl4P24iNpMxRbZClgg0hDTV"}, 	{"name":"ConsumerSecret", "value":"xK2CQ6tOhRro4yOZe3iHfqKsoAjEFRCDIOIivDeP6scNkk282S"}, 	{"name":"StatusUpdate", "value":"this is a test! 333"}, 	{"name":"ConsumerKey", "value":"9Y1EaA37iL9DCPpI9rjyO5rsM"}]
}' "https://noce2k.temboolive.com/temboo-api/1.0/choreos/Library/Twitter/Tweets/StatusesUpdate"
*/


void loop() {
   Serial.println("start the loop");
  
  /*  if (nextTime > millis()) {
          Serial.println("waiting");
        return;
    }*/

    Serial.println();
    Serial.println("Application>\tStart of Loop.");
    // Request path and body can be set at runtime or at setup.
    //request.hostname = "noce2k.temboolive.com";
    request.hostname = "sparknightlab.temboolive.com";
    request.port = 80;
    request.path = "/temboo-api/1.0/choreos/Library/Twitter/Tweets/StatusesUpdate";

    // The library also supports sending a body with your request:
    request.body = "{\"inputs\": [	{\"name\":\"AccessToken\", \"value\":\"2996878047-ltPLnxsMsQ46lpJ95omyBBXb3FZjzLdGr69BwKW\"}, 	{\"name\":\"AccessTokenSecret\", \"value\":\"3WmC3IKPphHxyTzV5GuwTpEl4P24iNpMxRbZClgg0hDTV\"}, 	{\"name\":\"ConsumerSecret\", \"value\":\"xK2CQ6tOhRro4yOZe3iHfqKsoAjEFRCDIOIivDeP6scNkk282S\"}, 	{\"name\":\"StatusUpdate\", \"value\":\"tessssTT!!!4444\"}, 	{\"name\":\"ConsumerKey\", \"value\":\"9Y1EaA37iL9DCPpI9rjyO5rsM\"}]}";

    // Get request
    http.post(request, response, headers);
  //  Serial.print("Application>\tResponse status: ");
  //  Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    nextTime = millis() + 200000;
    delay(10000);
}
