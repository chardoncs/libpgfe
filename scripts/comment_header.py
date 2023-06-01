#!/usr/bin/env python3

from pathlib import Path
import sys


HEADER_STR = '''\
/*
  libpgfe
  {0}

  Copyright (c) 2022-2023 Charles Dong
*/
'''

INCLUDE_SUBDIR = ['include', 'src', 'test']
EXTS = ['c', 'h', 'cpp', 'hpp']


def add_comment_header(file: Path):
    file_content = file.read_text()
    if file_content[:2] == '/*':
        return

    file.write_text('\n'.join([HEADER_STR.format(file.name), file_content]))
    print(f"Updated {file}")


def iter_dir(path_item: Path, inside_subdir=False):
    if not path_item.exists():
        return

    if not path_item.is_dir():
        add_comment_header(path_item)
    else:
        for item in path_item.iterdir():
            if item.is_dir() and (item.name in INCLUDE_SUBDIR or inside_subdir):
                iter_dir(item, inside_subdir=True)
                continue

            if item.name.split('.')[-1] in EXTS:
                add_comment_header(item)


def main(args):
    if len(args) > 0:
        iter_dir(Path(args[0]))


if __name__ == "__main__":
    main(sys.argv[1:])
