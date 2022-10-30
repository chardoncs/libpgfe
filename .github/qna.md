# Q&A

## Q1: Meaning of the name?

The name "*libpgfe*" used to be an abbreviation of "**Lib**rary of **P**assword **G**eneration **F**ront-**e**nd". Because it is initially designed to be just an HOTP/TOTP library ported to [Nettle](https://www.lysator.liu.se/~nisse/nettle/). But during the development period, more and more algorithms have been directly implemented in this library, so its full name has been deprecated since it may mislead viewers.

Since v0.2.0, *libpgfe* has been "self-sufficient" and does not depend on any third-party library.

## Q2: Interested in supporting Big Endian?

I will think about it eventually, but not now! Because byte order compatibility will dramatically increase complexity of the code,
and I currently don't have enough time or effort to tackle it. Also, I do not have Big Endian machines or virtual machines, so the additional code would be left untested, which is what I don't expect.

## Q3: Why not [Assembly Language](https://en.wikipedia.org/wiki/Assembly_language)?

1. I'm not familiar with Assembly.

2. Assembly is machine-dependent.

3. C is fast enough for *libpgfe*. It's no need to use Assembly to do those optimizations.

## Q4: Why not MSVC?

> ***PS:** MSVC = Microsoft Visual C++*

1. This library prioritizes POSIX compatibility, instead of Windows compatibility.

2. *libpgfe* needs some necessary features that are not included in *MSVC*. For instance, like the C code below. *MSVC* will refuse to compile that code, because a variable is used as the array's size, while *Clang* and *GCC* are OK with it.

```c
int main() {
    int n = 12;
    int arr[n];

    return 0;
}
```
