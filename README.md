# Aspam
Spam protection with challenge - jQuery widget

Aspam is a challenge-response test for web forms to determine whether the user is human. Aspam offer the new idea of challenge-response test to block form submissions by spambots and automated scripts.

![alt text](http://sztorc.com/aspam/aspam-captcha.gif "Aspam")

# Requirements
- jQuery
- Raphaël 2.x JavaScript Vector Library by Dmitry Baranovskiy & Sencha Labs
- CryptoJS (MD5) by Jeff Mott
- jsEncrypt by AllPlayers.com - optional

# Installation & usage

## Drupal 7 module available
Required [CAPTCHA](https://www.drupal.org/project/captcha) module.

Clone this repository to /DRUPAL_PATH/sites/all/modules/aspam or /DRUPAL_PATH/sites/SITENAME/modules/aspam and go to http://your.site/admin/modules to install Aspam module.

Visit http://your.site/admin/config/people/captcha/aspam to configure Aspam module.

You have to configure also CAPTCHA module on http://your.site/admin/config/people/captcha. 
You should change CHALLENGE TYPE to "aspam" for any form you want. 


## Normal installation

### Client side

```html
<script src="https://code.jquery.com/jquery-1.11.3.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/raphael/2.1.4/raphael-min.js"</script>
<script type="text/javascript" src="/aspam/lib/crypto-js/md5.js"></script>
<script type="text/javascript" src="/aspam/lib/jsencrypt/jsencrypt-all.js"></script>
<script type="text/javascript" src="/aspam/fonts/helvetica.js"></script>
<script type="text/javascript" src="/aspam/js/aspam.js"></script>
```

HTML
```html
<div id="aspam_container" style="overflow: hidden; position: relative;">
	<div id="aspam">
	  <div id="aspam-padlock"></div>
	  <div id="aspam-holder"></div>
	  <span style="font-size:9px;"><b>Aspam</b></span>
	</div>
</div>
```
JS simple widget constructor (without encryption)
```javascript
jQuery.spam.aspam( { }, "#aspam" );

```

JS widget constructor with params

```javascript
jQuery.spam.aspam( {
	"width": 50,
	"height": 50,
	"numChars": 6,
	"transformTime": 1000,
	"showTime": 1500,
	"backgroundColor":"#5BAE09",
	"borderColor":"#4F9607",
	"borderWidth": 1,
	"charColor":"#5BAE09",
	"fillOpacity": 0.8,
	"charStrokeColor":"#448107",
	"charStrokeWidth": 2,
	"charWidthScale": 0.2,
	"charHeightScale": 0.2,
	"padlockOpacity": 0.3,
	"padlockFillColor":"#000000",
	"paddingLeft":"auto",
	"paddingTop":"auto",
	"symbols":"lowercase|uppercase|digits",
	"encryption":1,
	"publicKey":"-----BEGIN PUBLIC KEY-----\r\nMIGfMA0...\r\n-----END PUBLIC KEY-----"
	}, "#aspam" );
```
### Server side

PHP (validation)
```php

$encryption = true; // on or off encryption
$aspam_private_key = ''; //your private key


$ip_address = ip_address();

if ($ip_address && !empty($_POST['captcha_response']) && !empty($_POST['aspam_chash'])) {

	$vhash = ''; //verify hash

	$cres = $_POST['captcha_response'];

	for ($i = 0; $i < strlen($cres); ++$i) {
	    $vhash = (ord($cres[$i]) % 2 == 0) ? md5($vhash.$cres[$i].ord($cres[$i])) : md5($vhash.ord($cres[$i]));
	}

	if ($encryption) {

	    $pk = openssl_get_privatekey($aspam_private_key);
		openssl_private_decrypt(base64_decode($_POST['aspam_chash']), $chash, $pk);

	} else {

	    $chash = $_POST['aspam_chash'];

	}

	$valid = false;

	if ($vhash == $chash) $valid = true;

	if (!$valid) {

		// error message - validation error

	} else {

		// validation success
	}

} else echo 'Invalid POST params';

```

### Generate certificates for encryption support

##### Generate private key

Within your terminal (Unix based OS) type the following:
```bash
openssl genrsa -out rsa_1024_priv.pem 1024
```
Copy your private key from file: rsa_1024_priv.pem

##### Generate public key

Within your terminal (Unix based OS) type the following:
```bash
openssl rsa -pubout -in rsa_1024_priv.pem -out rsa_1024_pub.pem
```
Copy your private key from file: rsa_1024_pub.pem



# Copyright and license
&copy; Copyright Mirosław Sztorc

[MIT License](LICENSE)