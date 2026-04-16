./prepare.sh

cmake -S TestTheBestCodeGen -B _buildCodeGen
cmake --build _buildCodeGen --target codeGen -j

if [ $? -ne 0 ]; then
    exit 1
fi

_buildCodeGen/codeGen .

cmake -S . -B _build
cmake --build _build --target testTheBestLib -j
if [ $? -ne 0 ]; then
    exit 1
fi

cmake --build _build --target testTheBestApp -j
if [ $? -ne 0 ]; then
    exit 1
fi

cp TestTheBest.properties _build/TestTheBestApp
echo 10987654321

