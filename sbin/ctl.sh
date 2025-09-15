function f_devprep(){
    sudo apt update
    sudo apt install g++ make cppcheck cpplint
    chmod +x sbin/ctl.sh
}

function f_build(){
    make
}

function f_check(){
    cppcheck src/cpp.cpp
}

function f_lint(){
    cpplint src/cpp.cpp
}

function f_doc(){
    grep @doc src/cpp.cpp
}

function f_test(){
    ./HelloWorld > /tmp/out
    grep 0.707 /tmp/out
    echo $?
    grep 0.717 /tmp/out
    echo $?
}

case $1 in
    "devprep")  f_devprep;;
    "build")    f_build;;
    "check")    f_check;;
    "lint")     f_lint;;
    "test")     f_test;;
    "doc")      f_doc;;
    "all")      time `grep run .github/workflows/build.yml |grep ctl.sh |cut -b 13-`;;
    *)          echo "Error. Option $1 is not available."
esac