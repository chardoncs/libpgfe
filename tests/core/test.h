/*
  libpgfe
  test.h

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_TEST_TEST_H
#define LIBPGFE_TEST_TEST_H

#define ARGS int argc, char **argv

#define TEST_INIT                                                                                                      \
    char *option = argv[1];                                                                                            \
    char output_str[400];

#define TEST_CASE(cmd, name)                                                                                           \
    if (!strcmp(option, cmd)) {                                                                                        \
        name(argc, argv);                                                                                              \
    }                                                                                                                  \
    else

#define TEST_END                                                                                                       \
    ;                                                                                                                  \
    printf("\n")

#endif