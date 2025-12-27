#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "utf8proc" ]; then return; fi
URL="https://github.com/JuliaStrings/utf8proc/archive/refs/heads/master.zip"
ZIP="${URL##*/}"
DIR="utf8proc-master"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to utf8proc/ ..."
rm -rf utf8proc
mkdir -p utf8proc
cp -f  ".build/$DIR"/*.c utf8proc/
cp -f  ".build/$DIR"/*.h utf8proc/
echo ""
}


# Test the project
test() {
echo "Running 01-codepoint_to_utf8.c ..."
clang -I. -o 01.exe examples/01-codepoint_to_utf8.c   && ./01.exe && echo -e "\n"
echo "Running 02-utf8_to_codepoints.c ..."
clang -I. -o 02.exe examples/02-utf8_to_codepoints.c  && ./02.exe && echo -e "\n"
echo "Running 03-casefold.c ..."
clang -I. -o 03.exe examples/03-casefold.c            && ./03.exe && echo -e "\n"
echo "Running 04-normalization.c ..."
clang -I. -o 04.exe examples/04-normalization.c       && ./04.exe && echo -e "\n"
echo "Running 05-custom_filter.c ..."
clang -I. -o 05.exe examples/05-custom_filter.c       && ./05.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
