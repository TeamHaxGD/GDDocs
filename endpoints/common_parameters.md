#### gameVersion
Version of the game.
#### binaryVersion
Version of the client.
#### gdw
If the request was made by the Geometry Dash World app, this is set to 1; else it's 0.
#### userName
The username of the user in plain text
#### password
The password of the user in plain text
#### accountID
A unique ID used to identify accounts. If the player is not logged in, this is set to 0.
#### gjp
The encoded password of the player. If the player is not logged in, this is empty or not even included.
#### udid
An alphanumeric ID used to identify unregistered players. This is either based on the device, or generated casually.
#### uuid
Yet another ID used to identify unregistered players. These are generated through the database using an unique value.
#### secret
A value used to validate requests. This may vary from endpoint to endpoint, but it doesnt change.
#### seedX
These are values used by very few endpoints, they are probably some first implementations of the chk, since they follow a pratically identical structure. The X in the name is a number.
#### rs
"Random seed": as the name says, this is a totally random string, generally used by the chk.
#### chk
Like the secret, this is also used to validate the requests. However this is generated using an algorithm which is similar for every endpoint but uses different values. Every chk is encoded in this way:
`Plain Text + Salt -> sha1 -> Xor -> Base64`
The only exception is the chk of the level leaderboard, which hasn't the salt at the end of the string.
