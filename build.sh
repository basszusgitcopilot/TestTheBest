./prepare.sh

if [ "$TEST_THE_BEST_BUILD_USE_CODEGEN" == "true" ]; then
    cmake -G Ninja -S TestTheBestCodeGen -B _buildCodeGen
    cmake --build _buildCodeGen --target codeGen -j

    if [ $? -ne 0 ]; then
        exit 1
    fi

    _buildCodeGen/codeGen .
fi

cmake -G Ninja -S . -B _build
cmake --build _build --target testTheBestLib -j
if [ $? -ne 0 ]; then
    exit 1
fi

cmake --build _build --target testTestTheBestLib -j
if [ $? -ne 0 ]; then
    exit 1
fi

export CALL_CTEST_PARAMS="-T Test -j --output-on-failure --stop-on-failure --progress"
cd _build
ctest $CALL_CTEST_PARAMS
if [ $? -ne 0 ]; then
    cd ..
    exit 1
fi
cd ..

cmake --build _build --target testTheBestApp -j
if [ $? -ne 0 ]; then
    exit 1
fi

#cp TestTheBest.properties _build/TestTheBestApp
echo 10987654321

