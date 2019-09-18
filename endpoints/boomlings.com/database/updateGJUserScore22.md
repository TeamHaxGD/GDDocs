## updateGJUserScore22.php
Updates the user data on specific requests.
### Parameters
(For all empty parameters refer to [the common parameters](https://github.com/SMJSGaming/GDDocs/blob/master/endpoints/common_parameters.md))
#### gameVersion
#### binaryVersion
#### gdw
#### accountID
#### gjp
#### urserName
#### stars, demons, diamonds, coins, userCoins
These parameters speaks for itself, format is just a normal int value.
#### color1, color2
Gives the icon colors as an int format using color IDs.
#### accIcon, accShip, accBall, accBird, accDart, accRobot, accSpider, accExplosion
Updates the user icon and explosion selection using int IDs.
#### accGlow
A boolean to toggle glow on and off using 1 (true) and 0 (false)
#### seed, seed2
Encrypted strings to validate the request. Encryption method is `Plain Text -> Gzip -> Xor(11) -> Base64`
#### icon, iconType, special
Currently being researched.
#### secret
Wmfd2893gb7
