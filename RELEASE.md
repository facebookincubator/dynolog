# Steps to make a release
1. Pull the most recent tags: `git fetch --all --tags`.
2. Create a new branch from main, say `release-vX.Y.Z` where X.Y.Z is the new release number.
3. Bump the version in `version.txt`. Versions must adhere to [Semantic Versioning](https://semver.org/).
4. Make a tag, `git tag vX.Y.Z`.
5. Merge the release branch along **with the tag** into main through a PR `git push --tags -u origin
   [branch_name]`
6. Create a new release on [this
  page](https://github.com/facebookincubator/dynolog/releases) on Github.
7. Add the rpm/debian package by running `./scripts/rpm/make_rpm.sh`/`./scripts/debian/make_deb.sh`  and adding it to the release by dropping from the [release page](https://github.com/facebookincubator/dynolog/releases) or by running the [gh cli](https://cli.github.com/manual/gh_release_upload)
