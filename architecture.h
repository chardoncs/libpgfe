#ifndef LIBPGFE_ARCHITECTURE_H
#define LIBPGFE_ARCHITECTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#if __x86_64__ || _M_AMD64 || __aarch64__ || __ppc64__ || __mips64__ || __mips64 || __MIPS64__
#define __PGFE_64Bit
#else
#define __PGFE_32Bit
#define __PGFE_ARCH_COMPAT
#endif

#ifdef __cplusplus
}
#endif

#endif