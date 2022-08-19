from pathlib import Path


HEADER_STR = '''\
/*
  libpgfe
  {0}

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
'''

ROOT_DIR = '.'
INCLUDE_SUBDIR = ['test']
EXTS = ['c', 'h', 'cpp', 'hpp']


def add_comment_header(file: Path):
    file_content = file.read_text()
    if file_content[:2] == '/*':
        return

    file.write_text('\n'.join([HEADER_STR.format(file.name), file_content]))
    print(f"Updated {file}")


def iter_dir(path_item: Path):
    for item in path_item.iterdir():
        if item.is_dir() and item.name in INCLUDE_SUBDIR:
            iter_dir(item)
            continue
        
        if item.name.split('.')[-1] in EXTS:
            add_comment_header(item)


def main():
    iter_dir(Path(ROOT_DIR))

if __name__ == "__main__":
    main()