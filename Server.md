# The Geometry Dash Server
## Introduction

The online part of Geometry Dash is the most used of the entire game. Everyday, dozens of levels get uploaded/download to/from the server.
Using the server, you can also view the global ranks, such as top star grinders, top creators; you can even have friends and send messages to them!
But how does that work?

#### Request

Geometry Dash exchange data with the server through PHP, which is based on the HTTP protocol.
There are many ways to send HTTP requests; Geometry Dash uses POST requests.
The data is in the body field of the request.
The body of a request is always structured in this way:

param1=value1&param2=value2&param3...

### Response

The server also sends its data through the body of the request.
Let's take a look at a sample response:

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

playername = "RobTop"

url = "http://www.boomlings.com/database/getGJUsers20.php" #page where to send the packet
p = "gameVersion=21&binaryVersion=35&gdw=0&str="+playername+"&total=0&page=0&secret=Wmfd2893gb7" #our body
p = p.encode() #prepare our packet for the request
headers = {
    "User-Agent": ""
}

req = Request(url, headers=headers)
data = urlopen(req,p).read().decode()# send the request and save the response
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




	







