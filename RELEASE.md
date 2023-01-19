# Steps to make a release
1. Pull the most recent tags: `git fetch --all --tags`.
2. Create a new branch from main, say `release-vX.Y.Z` where X.Y.Z is the new release number.
3. Bump the version in `dynolog/src/version.txt`. Versions must adhere to [Semantic Versioning](https://semver.org/).
4. Make a tag, `git tag vX.Y.Z`.
5. Merge the release branch along **with the tag** into main through a PR `git push --tags -u origin
   [branch_name]`
6. Build the rpm by running `dynolog/scripts/rpm/make_rpm.sh`.
7. Create a new release on [this
  page](https://github.com/facebookincubator/dynolog/releases) on Github.
