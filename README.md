# libpgfe

## Introduction

**libpgfe** (IPA: /ˌlɪbˈpɪɡfiː/, like "lib-pig-fee") is a simple and easy-to-use C/C++ library for hash encoding, HOTP/TOTP generation and base encoding/decoding.

*libpgfe* used to be an abbreviation of "**Lib**rary of **P**assword **G**eneration **F**ront-**e**nd". Because it is initially designed to be a functional and user-friendly port to [Nettle](https://www.lysator.liu.se/~nisse/nettle/). But during the development period, more algorithms have been directly implemented in this library, so its full name may mislead viewers and has been deprecated.

| Item         | Content             |
| :----------- | :------------------ |
| C Standard   | C11                 |
| C++ Standard | C++11               |
| Compiler     | LLVM Clang          |
| License      | LGPL 3.0 (or later) |

## Tips for compilation

### Selection of compilers

It is suggested to use latest [LLVM](https://llvm.org/) or [GCC](https://gcc.gnu.org/) to compile this project. **Using [MSVC](https://en.wikipedia.org/wiki/Microsoft_Visual_C++) is not tested and will probably cause compilation failure.**

| Compiler   | Suggested version |
| :--------- | :---------------- |
| LLVM Clang | 11.0+             |
| GCC        | 9.0+              |

### Build tools

It is suggested to use CMake GUI or [VSCode](https://code.visualstudio.com/)'s CMake extension. The local Makefile is poorly written and does not function properly on compilation, but it is still available for clean, installation and uninstallation.

## Implementation method

The standards that are followed in this library are shown below.

| Algorithm           | Standard                                            |
| :------------------ | :-------------------------------------------------- |
| Base 16/32/64       | [RFC 4648](https://www.rfc-editor.org/info/rfc4648) |
| HMAC                | [RFC 2104](https://www.rfc-editor.org/info/rfc2104)<br>[RFC 6151](https://www.rfc-editor.org/info/rfc6151) |
| HOTP                | [RFC 4226](https://www.rfc-editor.org/info/rfc4226) |
| MD5                 | [RFC 6561](https://www.rfc-editor.org/info/rfc6151) |
| SHA-1               | [RFC 3174](https://www.rfc-editor.org/info/rfc3174)<br>[RFC 6234](https://www.rfc-editor.org/info/rfc6234) |
| SHA-2 Family        | [RFC 6234](https://www.rfc-editor.org/info/rfc6234) |
| SHA-3 Family        | [NIST FIPS 202](https://doi.org/10.6028/NIST.FIPS.202) |
| TOTP                | [RFC 6238](https://www.rfc-editor.org/info/rfc6238) |