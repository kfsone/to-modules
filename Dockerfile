FROM kfsone/to-modules

# Mount the current directory here, e.g. (sh/bash/zsh and powershell mac/win/lin):
#   docker run --rm -it ${PWD}:/workspace/to-modules kfsone/to-modules

VOLUME /workspace/to-modules
WORKDIR /workspace/to-modules

CMD [ "/bin/bash" ]
