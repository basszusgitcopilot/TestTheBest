./prepare.sh

cmake -S . -B _build
cmake --build _build --target codeGen -j

if [ $? -ne 0 ]; then
    exit 1
fi

_build/TestTheBestApp/codeGen .

cmake -S . -B _build
cmake --build _build --target testTheBestApp -j
if [ $? -ne 0 ]; then
    exit 1
fi

cp TestTheBest.properties _build/TestTheBestApp
echo 10987654321

