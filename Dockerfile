FROM ubuntu:latest as development
COPY dpkg-requirements.txt .

RUN apt-get update \
    && apt-get install -y --force-yes software-properties-common \
    && add-apt-repository ppa:deadsnakes/ppa \
    && apt-get install -y --force-yes \
        $(cat dpkg-requirements.txt | tr '\n' ' ') \
    && apt-get clean \
    && mkdir /workarea \
    && rm -rf dpkg-requirements.txt

WORKDIR /workarea
VOLUME ["/workarea"]

# docker pull ubuntu:latest
# docker build --target development -t tsk-scheduler-development .
# docker run --rm -v $(pwd):/workarea -it tsk-scheduler-development