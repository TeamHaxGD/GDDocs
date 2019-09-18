## backupGJAccountNew.php
Sends your data to the server to backup
### Parameters
(For all empty parameters refer to [the common parameters](https://github.com/SMJSGaming/GDDocs/blob/master/endpoints/common_parameters.md))
#### userName
#### password
#### gameVersion
#### binaryVersion
#### gdw
#### saveData
You save data encrypted using `Plain Text -> Gzip -> Base64`. The first part is your CCGameManager data and the second part is the CCLocalLevels data. These 2 are being seperated with a `;`, split these 2 first before decrypting one of them.
#### secret
Wmfv3899gc9
