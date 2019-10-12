## getGJLevels21.php
Gets the pages containing multiple levels.
### Parameters
(For all empty parameters refer to [the common parameters](https://github.com/SMJSGaming/GDDocs/blob/master/endpoints/common_parameters.md))
#### gameVersion
#### binaryVersion
#### gdw
#### type
Tells the server what the fetch priority should be. Type: 0 are the most liked levels, 1 are the most downloaded levels, 2 are the most liked levels (this is also the default for the search button), 3 are the trending levels, 5 are your own levels, 6 are the featured levels, 7 are the magic levels, 10 are the map packs, 11 are the recently awarded levels, 12 are levels from people you follow, 13 are levels from friends, 15 are the most liked levels in GD world and 16 are the hall of fame levels
#### str
The search string. This is empty if you didn't search any specific string.
#### diff
The difficulty you are filtering on. This is a `-` if you didn't filter any difficulty.
#### len
The lenght you are filtering on. this is a `-` if you didn't filter any length.
#### total
The ammount of levels there are in total on the specific page. It's currently unknown how the game gets this data and what the use for it is.
#### uncompleted
A boolean which filters on levels you didn't complete if true. The values are 1 (true) and 0 (false).
#### onlyCompleted
A boolean which filters on levels you did complete if true. The values are 1 (true) and 0 (false).
#### featured
A boolean which filters on featured levels if true. The values are 1 (true) and 0 (false). It orders on most downloaded.
#### original
A boolean which filters on original levels if true. The values are 1 (true) and 0 (false).
#### twoPlayer
A boolean which filters on two player levels if true. The values are 1 (true) and 0 (false).
#### coins
A boolean which filters on levels with coins if true. The values are 1 (true) and 0 (false).
#### epic
A boolean which filters on epic levels if true. The values are 1 (true) and 0 (false).
#### secret
Wmfd2893gb7
