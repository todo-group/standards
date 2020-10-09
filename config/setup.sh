#!/bin/sh

GOOGLETEST_VERSION=1.10.0

BASE_DIR=$(cd "$(dirname $0)"; cd ..; pwd)

# googletest

rm -rf $BASE_DIR/googletest*
curl -L https://github.com/google/googletest/archive/release-${GOOGLETEST_VERSION}.tar.gz | tar xf - -C ${BASE_DIR}
mv -f ${BASE_DIR}/googletest-release-${GOOGLETEST_VERSION}/googletest ${BASE_DIR}
rm -rf ${BASE_DIR}/googletest-release-${GOOGLETEST_VERSION}
