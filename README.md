# MarathonOnlineJudge problems

Marathon Online Judge (https://judge.ats5515.net) の問題ソースコード

## 実行方法
提出コードの実行コマンドが'./main'であるとします。
ジャッジ形式によってジャッジの実行方法が異なります。

いずれの場合も、出力の形式が不適切である場合に./judgeが異常終了します。
ACであれば、score.txtにスコアが出力されます。

### 通常ジャッジ
~~~
# ジャッジプログラムコンパイル
g++ generator.cpp -o generator -std=c++11
g++ judge.cpp -o judge -std=c++11

# テストケース実行
./generator [seed] > input.txt
./main < input.txt > output.txt
./judge input.txt < output.txt > score.txt
~~~

### インタラクティブ
Windowsを使う場合はWSL等でUnix環境を用意してください。
~~~
# ジャッジプログラムコンパイル
g++ judge.cpp -o judge -std=c++11

# 名前付きパイプを用意
mkfifo input output

# テストケース実行
./judge [seed] score.txt < output | cat > input &
./main < input | cat > output
~~~

### 2回実行
~~~
# ジャッジプログラムコンパイル
g++ generator.cpp -o generator -std=c++11
g++ mediator.cpp -o mediator -std=c++11
g++ judge.cpp -o judge -std=c++11

# テストケース実行
./generator [seed] > input1.txt
./main < input1.txt > output1.txt
./mediator input1.txt < output1.txt > input2.txt
./main < input2.txt > output2.txt
./judge input1.txt output1.txt output2.txt > score.txt
~~~