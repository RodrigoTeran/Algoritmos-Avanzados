g++ main.cpp -o app.out &&
./app.out < ./tests/test1.txt > ./solutions/solution1.txt &&
./app.out < ./tests/test2.txt > ./solutions/solution2.txt &&
./app.out < ./tests/test3.txt > ./solutions/solution3.txt &&
./app.out < ./tests/test4.txt > ./solutions/solution4.txt &&
rm -rf app.out

