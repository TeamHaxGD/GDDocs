## Chk parameter
An alternative for the secret parameter or to send secret data to the server to validate things.
### Decryption
`Raw -> Base64 decode -> XOR -> SHA1 -> Salt`

#### XOR Keys:
For level downloading and uploading: 41274  
For level comments: 29481  
For quests: 19847  
For chest rewards: 59182  
For liking and rating: 58281  
For updating user scores: 85271  
For update the level user highscore: 39673
#### Salt Keys
For level downloading and uploading: xI25fpAapCQg  
For level comments: xPT6iUrtws0J  
For quests: none  
For chest rewards: none  
For liking and rating: ysg6pUrtjn0J  
For updating user scores: xI35fsAapCRg  
For update the level user highscore: yPg6pUrtWn0J
#### Data for the chk
For level downloading: levelID, inc, RS value, accountID, UDID, UUID  
  
For level uploading: seed  
  
For level comments: username, comment, levelID, percentage, comment Type (0 = Level, 1 = User)  
  
For quests and chest rewards: 2 random numbers  
  
For liking: special, itemID, like, type, RS, accountID, UDID, UUID  
  
For rating: levelID, stars, RS, accountID, UDID, UUID  
  
For updating user scores: accountID, userCoins, demons, stars, coins, icon type, icon, diamonds, account icon, account ship, account ball, account UFO, account wave, account robot, account glow, account spider, account explosion  
  
For update the level user highscore: accountID, levelID, percentage, seconds, jumps, attempts, seed, bests differences, UNKNOWN (always 1), user coins, dailyID, seed7 ("s7" from packet) `Seconds = seconds taken to reach the best, Jumps = jumps taken to reach the best, Bests Differences = differences between bests, ex: 0% - 65% - 100% -> (65 - 0), (100 - 65) -> 65,35`  
<br><br><br>
Most values are explained in the [endpoints documentation](https://github.com/SMJSGaming/GDDocs/blob/master/endpoints)  
  
Reference from cos8o's [gdcrypto info](https://github.com/Cos8o/GDCrypto/blob/master/include/gdcrypto.hpp)
