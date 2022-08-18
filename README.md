# libpgfe

**libpgfe** (IPA: /ˌlɪbˈpɪɡfiː/, like "lib-pig-fee") is a simple and easy-to-use library for hash encoding, HOTP/TOTP generation and base encoding.

*libpgfe* was an abbreviation of "**Lib**rary of **P**assword **G**eneration **F**ront-**e**nd". It is initially designed to be a functional and user-friendly port to [Nettle](https://www.lysator.liu.se/~nisse/nettle/), but since more algorithms (e.g. HMAC, HOTP, Base etc.) are directly implemented in this library, its full name has been deprecated.

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