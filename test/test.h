/*
  libpgfe
  test.h

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#ifndef LIGPGFE_TEST_TEST_H
#define LIGPGFE_TEST_TEST_H

#define ARGS int argc, char **argv

#define TEST_INIT                                                                                                      \
    char *option = argv[1];                                                                                            \
    char output_str[400];

#define TEST_CASE(cmd, name)                                                                                           \
    if (!strcmp(option, cmd)) {                                                                                        \
        name(argc, argv);                                                                                              \
    }                                                                                                                  \
    else

#endif