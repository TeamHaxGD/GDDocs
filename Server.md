# The Geometry Dash Server
## Introduction

The online part of Geometry Dash is the most used of the entire game. Everyday, dozens of levels get uploaded/download to/from the server.
Using the server, you can also view the global ranks, such as top star grinders, top creators; you can even have friends and send messages to them!
But how does that work? First we must know something about HTTP.

### HTTP

The client exchange with the server HTTP packets; those packets contains:
* the request line (requests only), which specifies the request method, the file where to send the request and the protocol version;
* the status line (response only), which consists of the protocol version, the status code and its reason phrase;
* the HTTP header, which has some informations used by the HTTP protocol;
* the body, which is the data the client and the server uses to comunicate. 

There are 2 type of HTTP packets: the request one, sent by the client, and the response one, sent by the server.

#### Request

There are many ways to send a HTTP request, geometry dash uses POST requests.

A POST request usually looks like this:

REQUEST LINE|POST /database/getGJGauntlets21.php HTTP/1.1

            |Host: www.boomlings.com
 HTTP HEADER|Content-Length: 56
            |Content-Type: application/x-www-form-urlencoded

        BODY|gameVersion=21&binaryVersion=35&gdw=0&secret=Wmfd2893gb7
		
**NOTES:**
* **The body is delimited from the rest of the packet by 4 C chars(\r\n\r\n).**
* **The type of body is specified in the Content-Type field.**
* **As you can see, a POST request can send some variables and their values in the body.**

#### Response
 
A response packet is very similar to a request packet; however, the request line gets replaced by the status line.

A GD response packet usually looks like this:

STATUS LINE|HTTP/1.1 200 OK

           |Date: Mon, 21 May 2018 14:13:54 GMT
           |Server: Apache/2.2.22 (Ubuntu)
HTTP HEADER|X-Powered-By: PHP/5.3.10-1ubuntu3.26
           |Content-Length: 808
           |Content-Type: text/html

       BODY|1:1:3:27732941,28200611,27483789,28225110,27448202|1:2:3:20635816,28151870,25969464,24302376,27399722

So, what the server does is:
* Read the request, and eventually get the parameters values to do its stuff;
* Do above-mentioned stuff;
* Return a response.

We understood that to make a request, we need the HTTP protocol; but who manage this protocol?
The Geometry Dash server uses PHP: PHP is a scripting language that... *continue me pls*

### Structure of the request body

The request body is structured in this way:

param1=value1&param2=value2&param3...

The values are always casted to the string type.

### Structure of the response body

Let's take a look at the response body above:

`1:1:3:27732941,28200611,27483789,28225110,27448202|1:2:3:20635816,28151870,25969464,24302376,27399722`

Pretty confusing, isn't it? Well, let's see how it would have been with json:

```json
{
	"1":1,
	"3":[27732941,28200611,27483789,28225110,27448202]
}
{
	"1":2,
	"3":[20635816,28151870,25969464,24302376,27399722]
}
```

As you can see:
* *|* delimits 2 or more objects;
* *:* delimits the variables ID and their values;
* *,* delimits the values in a array.

**Note: sometimes ':' may appear in a value: to avoid undefined behaviours, some pages uses '~' as a delimiter instead of ':'.**

## Development tools

If you want to start interacting with the Geometry Dash Server, you can use some tools to make the development easier.

Python is a powerful, multi-use and cross platform programming language. With python and the urllib library you can
easily simulate requests just as it were done by the game. Here's a simple script that get the account ID of a player
from its name:

```python
from urllib.request import urlopen,Request

playername = "robtop"

url = "http://www.boomlings.com/database/getGJUsers20.php" #page where to send the packet
p = "gameVersion=21&binaryVersion=35&gdw=0&str="+playername+"&total=0&page=0&secret=Wmfd2893gb7" #our body
p = p.encode() #prepare our packet for the request
data = urlopen(url,p).read().decode()# send the request and save the response
if data == "-1": #check if the request got accepted
    print("Request failed.") #player doesnt exist, some required variables may be missing from the body,
    #wrong url, invalid body format, invalid values, etc.
else:
    data = data.split('|') #split the response in objects
    data = data[0].split(':') #split the first object to access variables
    print("Player name: "+playername) #print player name
    print("Account ID: "+data[21]) #print account ID
```
//Wireshark




	







