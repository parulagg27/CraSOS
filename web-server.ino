
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "GUEST-N";
const char* password = "esya@2018";

void setup() {
  
  Serial.begin(115200);
  delay(4000);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  HTTPClient http;

  http.begin("http://jsonplaceholder.typicode.com/posts");
  http.addHeader("Content-Type", "text/plain");

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //display html web page
            client.println("<!DOCTYPE HTML><html>");
            client.println("<head><meta charset="utf-8" />");
            client.println(" <meta http-equiv="X-UA-Compatible" content="IE=edge">");
            client.println(" <title>Page Title</title>");
            client.println("<meta name="viewport" content="width=device-width, initial-scale=1">");
            client.println("<style>{margin:0; padding:0; }");
            
            client.println("body {font-family:"Open Sans", Helvetica, Arial, sans-serif;font-weight:300;font-size: 12px;line-height:30px;color:#777;background:#0CF;}");
            
            client.println(".container {max-width:400px;width:100%;margin:0 auto;position:relative;}");
            client.println("#contact input[type="text"], #contact input[type="email"], #contact input[type="tel"], #contact input[type="url"], #contact textarea, #contact button[type="submit"] { font:400 12px/16px "Open Sans", Helvetica, Arial, sans-serif; }");
            client.println("#contact {background:#F9F9F9;padding:25px;margin:50px 0;}");
            client.println("#contact h3 {
                              color: #F96;
                              display: block;
                              font-size: 30px;
                              font-weight: 400;});
            
            client.println("#contact h4 {
                              margin:5px 0 15px;
                              display:block;
                              font-size:13px;}");
                              
            client.println("fieldset {
                              border: medium none !important;
                              margin: 0 0 10px;
                              min-width: 100%;
                              padding: 0;
                              width: 100%;}");
                              
            client.println("#contact input[type="text"], #contact input[type="email"], #contact input[type="tel"], #contact input[type="url"], #contact textarea {
                              width:100%;
                              border:1px solid #CCC;
                              background:#FFF;
                              margin:0 0 5px;
                              padding:10px;}");
                              
            client.println("#contact input[type="text"]:hover, #contact input[type="email"]:hover, #contact input[type="tel"]:hover, #contact input[type="url"]:hover, #contact textarea:hover {
                              -webkit-transition:border-color 0.3s ease-in-out;
                              -moz-transition:border-color 0.3s ease-in-out;
                              transition:border-color 0.3s ease-in-out;
                              border:1px solid #AAA;}");
                              
            client.println("#contact textarea {
                              height:100px;
                              max-width:100%;
                              resize:none;}");
                              
            client.println("#contact button[type="submit"] {
                              cursor:pointer;
                              width:100%;
                              border:none;
                              background:#0CF;
                              color:#FFF;
                              margin:0 0 5px;
                              padding:10px;
                              font-size:15px;}");
                              
            client.println("#contact button[type="submit"]:hover {
                              background:#09C;
                              -webkit-transition:background 0.3s ease-in-out;
                              -moz-transition:background 0.3s ease-in-out;
                              transition:background-color 0.3s ease-in-out;}");
            client.println("#contact button[type="submit"]:active { box-shadow:inset 0 1px 3px rgba(0, 0, 0, 0.5); }");
            
            client.println("#contact input:focus, #contact textarea:focus {
                              outline:0;
                              border:1px solid #999;}");
            client.println("::-webkit-input-placeholder {color:#888;}");
            client.println(":-moz-placeholder {color:#888;}");
            client.println("::-moz-placeholder {color:#888;}");
            client.println(":-ms-input-placeholder {color:#888;}</style></head>");
            client.println("<body><div class="container"> ");
            client.println("<form id="contact" action="" method="post">");
            client.println("<h3>Quick Details</h3>");
            client.println("<h4>Please fill the details to proceed to the next step!</h4>");
            client.println("<fieldset>
            <input placeholder="Your name" type="text" tabindex="1" required autofocus></fieldset>");
            client.println("<fieldset><input placeholder="Your Phone Number" type="tel" tabindex="3" required></fieldset>");
            client.println("<fieldset><input placeholder="Blood Group" type="text" tabindex="2" required></fieldset>");
            client.println("<fieldset><input placeholder="Age" type="text" tabindex="2" required></fieldset>");
            client.println("<fieldset><input placeholder="Home Address" type="text" tabindex="2" required></fieldset>");
            client.println("<fieldset><input placeholder="Emergency Contact Number-1" type="tel" tabindex="3" required></fieldset>");
            client.println(" <fieldset><input placeholder="Emergency Contact Number-2" type="tel" tabindex="3" required></fieldset>");
            client.println("<fieldset><input placeholder="Emergency Contact Number-3" type="tel" tabindex="3" required></fieldset>");
            client.println("<fieldset><textarea placeholder="Any important medical details......." tabindex="5" required></textarea><fieldset>");
            client.println("<fieldset><button name="submit" type="submit" id="contact-submit" data-submit="...Sending">Submit</button></fieldset>");
            client.println("</form></div>");
            client.println("</body></html>");
            client.println("");

            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}


            
            
            
            
  

}
