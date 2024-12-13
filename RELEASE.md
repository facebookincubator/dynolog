# Steps to make a release
1. Pull the most recent tags: `git fetch --all --tags`.
2. Create a new branch from main, say `release-vX.Y.Z` where X.Y.Z is the new release number.
3. Bump the version in `version.txt`. Versions must adhere to [Semantic Versioning](https://semver.org/).
4. Make a tag, `git tag vX.Y.Z`.
5. Add and commit the change of `version.txt` to the local repo with `git add` and `git commit`.
6. Merge the release branch along **with the tag** into main through a PR `git push --tags -u origin
   [branch_name]`
7. Create a new release on [this
  page](https://github.com/facebookincubator/dynolog/releases) on Github.
8. Build rpm and debian packages. You can use Docker for this, details provided below.
9. Upload the rpm and debian packages to the [release page](https://github.com/facebookincubator/dynolog/releases) or by running [gh cli](https://cli.github.com/manual/gh_release_upload)

# Building Release Packages using Docker

## About
Docker is a container technology that can emulate any OS and and HW platform. It provides a simpler flow to control and version the release environment. It also eliminates the need to have machines with the specific Linux OS versions; instead you can build packages on a Mac/Windows/Linux laptop, all the same.

## 1) Install Docker Desktop
Follow the instructions [here](https://docs.docker.com/get-docker/).

## 2) Build Docker images
We include a `Dockerfile` in the repo to make release generation easy.
Run the following commands for building debian (Ubuntu based) and rpm (Rocky/CentOS based)packages
```
# For debian package
docker build . -f /path/to/dynolog_repo/dynolog.dockerfile -t dyno_build:ubuntu20.04 --target ubuntu_x86
# For rpm package
docker build . -f /path/to/dynolog_repo/dynolog.dockerfile -t dyno_build:rocky9_build_x86 --target rocky9_x86
```

Note, this step may take a while if you are using an ARM based laptop/machine and building the x86 packages.

## 3) Generate Packages

The docker images should have already run majority of the build process. We only need to run the final packaging step by spinning up the container.

Below are commands for Ubuntu/debian package build
```
docker run -it dyno_build:ubuntu20.04 /bin/bash

root@05d28f436d2b:/workspace/dynolog# ./scripts/debian/make_deb.sh
```

Similarly, run `./scripts/rpm/make_rpm.sh` in the rocky9 image for rpm package build.
```
docker run -it dyno_build:rocky9_build_x86 /bin/bash

root@05d28f436d2b:/workspace/dynolog# ./scripts/rpm/make_rpm.sh
```

## 4) Copy packages
You can copy files from your docker container. Make sure the container is still running while you do this.

Each docker container should have a unique ID; you can run `docker ps` to get a list of all running containers. Please replace '05d28f436d2b' below to the docker container ID.
```
mkdir -p build_packages
docker cp 05d28f436d2b:/workspace/dynolog/dynolog_0.2.2-0-amd64.deb build_packages

# similarly for rpm in container 01382d91b91b
docker cp 01382d91b91b:/root/rpmbuild/RPMS/x86_64/dynolog-0.2.2-1.el9.x86_64.rpm build_packages
```

## Notes
Currently, the docker file fixes the platform for deployment to 'linux/amd64'. We can also build packages for ARM or other architectures, the build scripts do hard-code the package file names as amd64 and that needs to be fixed.

Also, anupamb has shared a great [cheatsheet](https://gist.github.com/anupambhatnagar/07ebff374bc45e4b63eb42893cca7e87) for docker commands.
