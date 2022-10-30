#!/usr/bin/env python3

import json


FILES = {
    "scripts/metadata.mak.in": "metadata.mak",
    "scripts/version.h.template": "include/version.h",
}


def main():
    p = {}
    with open("project.json") as fp:
        p = json.load(fp)

    name = p['name']
    version = p['version']
    version_list = [int(i) for i in version.split('-')[0].split('.')]

    info = {
        "name": name,
        "version": version,
        "major_version": version_list[0],
        "minor_version": version_list[1],
        "revision": version_list[2],
        "variant": '-'.join(version.split('-')[1:]),
    }

    for src, dest in FILES.items():
        with open(src, 'r') as s_fp:
            with open(dest, 'w') as d_fp:
                d_fp.write(s_fp.read().format(**info))


if __name__ == '__main__':
    main()
