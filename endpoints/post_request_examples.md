## Multiple code examples to emulate a request to the server

#### PHP
```php
<?php
//sets the target url
$url = "http://boomlings.com/database/[insert target file]";

//makes the post string
$str = "seperateAndDefine=0&indexes=example&like=true&this=everything_behind_the_equal_sign_is_a_value_and_everything_behind_the_and_sign_is_an_index";

//turns the post string into an array
parse_str($str, $post);

//makes a curl request on your url using the post values
$ch = curl_init($url);
curl_setopt($ch, CURLOPT_POSTFIELDS, $post);

//requests the output
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
$result = curl_exec($ch);

//closes the request
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
post = "seperateAndDefine=0&indexes=example&like=true&this=everything_behind_the_equal_sign_is_a_value_and_everything_behind_the_and_sign_is_an_index"
post = post.encode()

# makes a request on your url using the post values
result = urlopen(url, post).read().decode()

# outputs the site responce
print(result)
```

#### Java
```java
import java.io.*;
import java.net.*;

//calls the main class and method
class Main {
  public static void main(String[] args) throws Exception {
    
    //sets the target url
    URL url = new URL("http://www.boomlings.com/database/[insert target file]");
    
    //makes the post string
    String postData = "seperateAndDefine=0&indexes=example&like=true&this=everything_behind_the_equal_sign_is_a_value_and_everything_behind_the_and_sign_is_an_index";

    //turns the post data into a byte array
    byte[] postDataBytes = postData.getBytes("UTF-8");

    //makes the request header
    HttpURLConnection conn = (HttpURLConnection)url.openConnection();
    conn.setRequestMethod("POST");
    conn.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
    conn.setRequestProperty("Content-Length", String.valueOf(postDataBytes.length));
    
    //requests the output
    conn.setDoOutput(true);
    conn.getOutputStream().write(postDataBytes);

    //reads the output
    Reader in = new BufferedReader(new InputStreamReader(conn.getInputStream(), "UTF-8"));

    //constructs and prints the output
    for (int c; (c = in.read()) >= 0;)
        System.out.print((char)c);
    }
}
```

#### Javascript/Jquery
```javascript
<!-- includes jquery -->
<script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
<script>

  //executes when the document is loaded
  $(document).ready(function() {
    
    //prepares the ajax request
    $.ajax({
      
      //sets the target url
      url: "http://www.boomlings.com/database/[insert target file]",
      
      //tells ajax the request type needs to be post
      type: "post",
      
      //makes the post data array using json
      data: {
        seperateAndDefine: 0,
        indexes: "example",
        like: true,
        this: "everything behind the double dots is a value and everything behind the and sign is an index"
      },
      
      //reads the output
      success: function(data) {
      
        //prints the output
        console.log(data);
      }
    });
  });
</script>
```
