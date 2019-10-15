## uploadGJLevel21.php
Uploads a level to the server.
### Parameters
(For all empty parameters refer to [the common parameters](https://github.com/SMJSGaming/GDDocs/blob/master/endpoints/common_parameters.md))
#### gameVersion
#### binaryVersion
#### gdw
#### accountID
#### gjp
#### userName
#### levelID
If the level already is uploaded and needs to be updated it will put the level it should update here. Leave it at 0 to upload it as a new level.
#### levelName
The name of the level in plain text.
#### levelDesc
The decription of the level in Base64.
#### levelVersion
The ammount of times you updated the level. It starts with 1.
#### LevelLenght
A number telling the server how long a level is. 0 is tiny, 1 is short, 2 is medium, 3 is long and 4 is extra long.
#### audioTrack
Which of the defaults songs you want to use if songID is unused.
#### songID
The newGrounds song ID you want to use for your level. Unused is 0.
#### auto, original, twoPlayer, unlisted, ldm
A boolean which toggles if one of these elements is enabled (1) or disabled (0).
#### password
Your password sends as a plain text int.
#### objects
The ammount of objects the level has.
#### coins
The ammount of coins your level has.
#### requestedStars
The star ammount requested as plain text.
#### wt
Unknown.
#### wt2
Unknown.
#### extraString
A string containing all kinds of properties of a level.
#### seed
Unknown.
#### seed2
Unknown.
#### levelString
Your level encrypted in `Plain Text -> Gzip -> Base64`.
#### secret
Wmfd2893gb7
