#!/usr/bin/env python3

from argparse import ArgumentParser
import os
from glob import glob
import shutil
from pathlib import Path

HEADER_ROOT = "libpgfe"
SHARED_LIB = "libpgfe.so"
LIB_DIR = "./build"


def main(args):
    if args.uninstall:
        for ds in args.header_dir:
            _dir = Path(ds) / HEADER_ROOT
            if not _dir.exists():
                continue

            shutil.rmtree(_dir)

        for ss in args.lib_dir:
            _dir = Path(ss)
            if not _dir.exists():
                continue

            os.remove(_dir / SHARED_LIB)

    else:
        for ds in args.header_dir:
            _dir = Path(ds) / HEADER_ROOT
            if not _dir.exists():
                _dir.mkdir(parents=True)

            for f in glob(r'./*.h'):
                shutil.copy(f, _dir)

            for f in glob(r'./*.hpp'):
                shutil.copy(f, _dir)

        for ss in args.lib_dir:
            _dir = Path(ss)
            if not _dir.exists():
                _dir.mkdir(parents=True)

            shutil.copy(str(Path(LIB_DIR, SHARED_LIB)), _dir)


if __name__ == '__main__':
    ap = ArgumentParser()
    ap.add_argument("-h", "--header-dir", required=True,
                    nargs='*', action='extend', default=[])
    ap.add_argument("-l", "--lib-dir", required=True,
                    nargs='*', action='extend', default=[])
    ap.add_argument("-u", "--uninstall", action='store_true')
    main(ap.parse_args())
