# libpgfe

![Version 0.2.0](https://img.shields.io/badge/Version-0.2.0-brightgreen)

## Introduction

**libpgfe** (IPA: /ˌlɪbˈpɪɡfiː/, like "lib-pig-fee") is a simple and easy-to-use C/C++ library for hash encoding, HOTP/TOTP generation and base encoding/decoding.

The name "*libpgfe*" used to be an abbreviation of "**Lib**rary of **P**assword **G**eneration **F**ront-**e**nd". Because it is initially designed to be just a boring functional port to [Nettle](https://www.lysator.liu.se/~nisse/nettle/). But during the development period, more and more algorithms have been directly implemented in this library, so its full name may mislead viewers and has been deprecated.

Since the version 0.2.0, **libpgfe** has been "self-sufficient" and does not depend on any library.

| Item         | Content             |
| :----------- | :------------------ |
| C Standard   | [C11 (ISO/IEC 9899:2011)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))  |
| C++ Standard | [C++11 (ISO/IEC 14882:2011)](https://en.wikipedia.org/wiki/C%2B%2B11) |
| Compiler     | LLVM Clang          |
| License      | BSD 3-Clause        |

## Endianness (Byte order)

The implementation philosophy of *libpgfe* assumes that systems running this library are **Little Endian**, since most architectures and OS are Little Endian. Therefore, this library should not run properly on Big Endian systems.

## Tips for compilation

### Compilers

It is suggested to use latest [LLVM](https://llvm.org/) or [GCC](https://gcc.gnu.org/) to compile this project. **Using [MSVC](https://en.wikipedia.org/wiki/Microsoft_Visual_C++) is not tested and will probably cause compilation failure.**

| Compiler   | Suggested version |
| :--------- | :---------------- |
| LLVM Clang | 11.0+             |
| GCC        | 9.0+              |

### Build tools

It is suggested to use CMake GUI or [VSCode](https://code.visualstudio.com/)'s CMake extension. The local Makefile is poorly written and does not function properly on compilation, but it is still available for clean, installation and uninstallation.

## Implementation reference

### Standards

The standards that are followed in this library are shown below.

| Algorithm                     | Standard                                            |
| :---------------------------- | :-------------------------------------------------- |
| Base 16/32/64                 | [RFC 4648](https://doi.org/10.17487/RFC4648) |
| HMAC                          | [RFC 2104](https://doi.org/10.17487/RFC2104)<br>[RFC 6151](https://doi.org/10.17487/RFC6151) |
| HOTP                          | [RFC 4226](https://doi.org/10.17487/RFC4226) |
| MD5                           | [RFC 1321](https://doi.org/10.17487/RFC1321)<br>RFC 6151 |
| SHA-1                         | [RFC 3174](https://doi.org/10.17487/RFC3174)<br>[RFC 6234](https://doi.org/10.17487/RFC6234) |
| SHA-2 Family                  | RFC 6234<br>[NIST FIPS 180-4 (Aug. 2015 ver.)](https://doi.org/10.6028/NIST.FIPS.180-4) |
| SHA-3 Family (Revised [Keccak](https://keccak.team/keccak.html)) | [NIST FIPS 202](https://doi.org/10.6028/NIST.FIPS.202) |
| TOTP                          | [RFC 6238](https://doi.org/10.17487/RFC6238) |

### Implementation instances

Meanwhile, some existing implementation repositories are referenced for the development.

| Algorithm                     | Reference                                           |
| :---------------------------- | :-------------------------------------------------- |
| SHA-3 Family (Revised Keccak) | [Keccak-NIST Reference Implementation](https://csrc.nist.gov/projects/hash-functions/sha-3-project)<br>[Fackelmann/SHA3](https://github.com/Fackelmann/SHA3)<br>[brainhub/SHU3IUF](https://github.com/brainhub/SHA3IUF)<br>[mjosaarinen/tiny_sha3](https://github.com/mjosaarinen/tiny_sha3) |