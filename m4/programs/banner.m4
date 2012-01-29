echo \
"-------------------------------------------------
${PACKAGE_NAME} Version ${PACKAGE_VERSION}

Host:     '${host}'.
Prefix:   '${prefix}'.
Compiler: '${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}'

Linker:             ${LDFLAGS}
CFlags:             ${CFLAGS}
CPPFlags:           ${CPPFLAGS}

Package features:
-------------------------------------------------
Debug:              ${debug}
Tests:              ${tests}

Unix:               '${unix}'.
Windows:            '${windows}'.
-------------------------------------------------
-------------------------------------------------
Now type 'make @<:@<target>@:>@'
where the optional <target> is:
check              - run test suite
all                - build all binaries
install            - install everything
-------------------------------------------------"
