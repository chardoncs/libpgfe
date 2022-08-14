import sys

import json


def main(args):
    p = {}
    with open(args[0]) as fp:
        p = json.load(fp)

    name = p['name']
    version = p['version']
    version_list = [int(i) for i in version.split('.')]

    with open('meta.mak', 'w') as f:
        f.write(f'''\
PROJECT := {name}
VERSION := {version}

BUILD_DIR := build
TARGET_DIR := $(BUILD_DIR)/bin

OBJS_DIR := $(BUILD_DIR)/obj
OBJS := $(OBJS_DIR)/*.o

TARGET := $(TARGET_DIR)/$(PROJECT).so
TEST_TARGET := $(TARGET_DIR)/$(TEST_BIN)
LIBS := {" ".join(p['libs'])}

CC := {p['compiler_binary']}
STD := {p['standard']['c']}

STD_OPTION := -std=$(STD)
''')

    nameuc = name.upper()

    with open('meta.h', 'w') as f:
        f.write(f'''\
#ifndef {nameuc}_META_H
#define {nameuc}_META_H

#define {nameuc}_NAME "{name}"

#define {nameuc}_MAJOR_VERSION {version_list[0]}
#define {nameuc}_MINOR_VERSION {version_list[1]}
#define {nameuc}_REVISION {version_list[2]}

#define {nameuc}_VERSION "{version}"
#endif
        ''')


if __name__ == '__main__':
    main(sys.argv[1:])
