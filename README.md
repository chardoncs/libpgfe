# libpgfe

libpgfe (**Lib**rary of **P**assword **G**eneration **F**ront-**e**nd) is a front-end library for generating hash codes and OTP passwords, using [Nettle](https://www.lysator.liu.se/~nisse/nettle/) as its backend.

"libpgfe" is pronounced like "lib-pig-fee" (IPA: /ˌlɪbˈpɪɡfiː/).

## Information

| Item       | Content             |
| :--------- | :------------------ |
| C Standard | C11                 |
| License    | LGPL 3.0 (or later) |


## Implementation

MD5 and SHA series' implementation is ported to Nettle. Besides that, the standards followed in this library are shown below.

| Algorithm     | Standard                                           |
| :------------ | :------------------------------------------------- |
| Base 16/32/64 | [RFC 4648](https://www.rfc-editor.org/rfc/rfc4648) |
| HMAC          | [RFC 2104](https://www.rfc-editor.org/rfc/rfc2104) |
| HOTP          | [RFC 4226](https://www.rfc-editor.org/rfc/rfc4226) |
| TOTP          | [RFC 6238](https://www.rfc-editor.org/rfc/rfc6238) |