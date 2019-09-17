## Multiple code examples to emulate a request to the server

#### PHP
```php
<?php
//sets the target url
$url = "http://boomlings.com/database/[insert target file]";

//makes the post string
$str = "seperateAndDefine=0&indexes=example&like=true&this=everything_behind_the_equal_sign_is_a_value_and_everything_behind_a_and_sign_is_an_index";

//turns the post string into an array
parse_str($str, $post);

//makes a curl request on your url using the post values
$ch = curl_init($url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_POSTFIELDS, $post);
$result = curl_exec($ch);
curl_close($ch);

//outputs the site responce
echo $result
?>
```

#### Python
```python
# imports needed library
from urllib.request import urlopen

# sets the target url
url = "http://www.boomlings.com/database/[insert target file]"

# makes the post string
post = "seperateAndDefine=0&indexes=example&like=true&this=everything_behind_the_equal_sign_is_a_value_and_everything_behind_a_and_sign_is_an_index"
post = post.encode()

# makes a request on your url using the post values
result = urlopen(url, post).read().decode()

# outputs the site responce
print(result)
```
