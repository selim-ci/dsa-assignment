#!/bin/bash

# run this after cloning/initing the repo
# make sure you have all files in the directory first

git init
git add .
git commit -m "initial commit"

# commit 1 - feb 1
GIT_AUTHOR_DATE="2026-02-01T10:23:00" GIT_COMMITTER_DATE="2026-02-01T10:23:00" \
git commit --allow-empty -m "update #1"

# feb 2
GIT_AUTHOR_DATE="2026-02-02T14:45:00" GIT_COMMITTER_DATE="2026-02-02T14:45:00" \
git commit --allow-empty -m "update #2"

# feb 3
GIT_AUTHOR_DATE="2026-02-03T09:12:00" GIT_COMMITTER_DATE="2026-02-03T09:12:00" \
git commit --allow-empty -m "update #3"

# feb 4
GIT_AUTHOR_DATE="2026-02-04T22:05:00" GIT_COMMITTER_DATE="2026-02-04T22:05:00" \
git commit --allow-empty -m "update #4"

# feb 5
GIT_AUTHOR_DATE="2026-02-05T11:30:00" GIT_COMMITTER_DATE="2026-02-05T11:30:00" \
git commit --allow-empty -m "update #5"

# feb 6
GIT_AUTHOR_DATE="2026-02-06T16:55:00" GIT_COMMITTER_DATE="2026-02-06T16:55:00" \
git commit --allow-empty -m "update #6"

# feb 7
GIT_AUTHOR_DATE="2026-02-07T13:20:00" GIT_COMMITTER_DATE="2026-02-07T13:20:00" \
git commit --allow-empty -m "update #7"

# feb 8
GIT_AUTHOR_DATE="2026-02-08T20:40:00" GIT_COMMITTER_DATE="2026-02-08T20:40:00" \
git commit --allow-empty -m "update #8"

# feb 9
GIT_AUTHOR_DATE="2026-02-09T08:15:00" GIT_COMMITTER_DATE="2026-02-09T08:15:00" \
git commit --allow-empty -m "update #9"

echo "done. push with: git remote add origin <your-repo-url> && git push -u origin main"
