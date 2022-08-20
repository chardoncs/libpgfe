from argparse import ArgumentParser

def main(args):
    pass

if __name__ =='__main__':
    ap = ArgumentParser()
    ap.add_argument("-h", "--header-dir", required=True, type=str)
    ap.add_argument("-l", "--lib-dir", required=True, type=str)
    main(ap.parse_args())