# libpgfe

![Version](https://img.shields.io/github/v/tag/chardon55/libpgfe?color=brightgreen&label=version)
![License](https://img.shields.io/github/license/chardon55/libpgfe)

> NOTE
>
> This library is archived since I have discovered that Rust has more systematic ecosystem for cryptography,
> which may reduce tons of repetitive work.

## Introduction

**libpgfe** (IPA: /[ˌlɪbˈpɪɡfiː](http://ipa-reader.xyz/?text=%CB%8Cl%C9%AAb%CB%88p%C9%AA%C9%A1fi%CB%90)/, respelling: "lib-PIG-fee") is a free and open-source cryptographic library focusing on flexibility and easy-to-access interfaces, which is written in [C](https://en.wikipedia.org/wiki/C_(programming_language)) and [C++](https://en.wikipedia.org/wiki/C%2B%2B).

*libpgfe* currently supports hash encoding (e.g. SHA256, MD5), HMAC encoding, HOTP/TOTP, Base 16/32/64 and Blowfish.

*libpgfe* is currently under heavy development, more features and optimization will be added in the future.

| Entry        | Info                |
| :----------- | :------------------ |
| C Standard   | [C11 (ISO/IEC 9899:2011)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))  |
| C++ Standard | [C++14 (ISO/IEC 14882:2014)](https://en.wikipedia.org/wiki/C++14) |
| Compiler     | LLVM Clang          |
| License      | Dual (MIT / Apache 2.0)    |

[*Any questions?*](.github/qna.md)

## [Endianness (Byte order)](https://en.wikipedia.org/wiki/Endianness)

The implementation philosophy of *libpgfe* assumes that the systems running this library are **Little Endian**, since it is widely used by architectures and OS. Therefore, this library should not run properly on Big Endian systems.

## Tips for compilation

### Compilers

It is suggested to use latest [LLVM](https://llvm.org/) or [GCC](https://gcc.gnu.org/) to compile this project. **Using [MSVC](https://en.wikipedia.org/wiki/Microsoft_Visual_C++) is not tested and will probably cause compilation failure.**

| Compiler   | Suggested version |
| :--------- | :---------------- |
| LLVM Clang | 11.0+             |
| GCC        | 9.0+              |

### Build tools

CMake is needed to compile the project.

## Implementation Reference

### Standards

The standards that are followed in this library are shown below.

| Algorithm                     | Standard                                            |
| :---------------------------- | :-------------------------------------------------- |
| Base 16/32/64                 | [RFC 4648](https://doi.org/10.17487/RFC4648) |
| Blowfish                      | [DOI: 10.1007/3-540-58108-1_24](https://doi.org/10.1007/3-540-58108-1_24) |
| HMAC                          | [RFC 2104](https://doi.org/10.17487/RFC2104)<br>[RFC 6151](https://doi.org/10.17487/RFC6151) |
| HOTP                          | [RFC 4226](https://doi.org/10.17487/RFC4226) |
| MD5                           | [RFC 1321](https://doi.org/10.17487/RFC1321)<br>RFC 6151 |
| SHA-1                         | [RFC 3174](https://doi.org/10.17487/RFC3174)<br>[RFC 6234](https://doi.org/10.17487/RFC6234) |
| SHA-2 Family                  | RFC 6234<br>[NIST FIPS 180-4 (Aug. 2015 ver.)](https://doi.org/10.6028/NIST.FIPS.180-4) |
| SHA-3/SHAKE Family (Revised [Keccak](https://keccak.team/keccak.html)) | [NIST FIPS 202](https://doi.org/10.6028/NIST.FIPS.202) |
| TOTP                          | [RFC 6238](https://doi.org/10.17487/RFC6238) |

### Implementation instances

Meanwhile, some existing implementation repositories are referenced for the development.

| Algorithm                     | Reference                                           |
| :---------------------------- | :-------------------------------------------------- |
| Blowfish                      | [Reference source code](https://www.schneier.com/academic/blowfish/download/) |
| SHA-3/SHAKE Family            | [Keccak-NIST Reference Implementation](https://csrc.nist.gov/projects/hash-functions/sha-3-project)<br>[Fackelmann/SHA3](https://github.com/Fackelmann/SHA3)<br>[brainhub/SHU3IUF](https://github.com/brainhub/SHA3IUF)<br>[mjosaarinen/tiny_sha3](https://github.com/mjosaarinen/tiny_sha3) |
