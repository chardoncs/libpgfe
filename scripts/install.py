from argparse import ArgumentParser
import os
from pathlib import Path

def main(args):
    if args.uninstall:
        for ds in args.header_dir:
            _dir = Path(ds)
            if not _dir.exists():
                continue
            
            # os.remove(_dir,)
    else:
        pass

if __name__ =='__main__':
    ap = ArgumentParser()
    ap.add_argument("-h", "--header-dir", required=True, nargs='*', action='extend', default=[])
    ap.add_argument("-l", "--lib-dir", required=True, nargs='*', action='extend', default=[])
    ap.add_argument("-u", "--uninstall", action='store_true')
    main(ap.parse_args())