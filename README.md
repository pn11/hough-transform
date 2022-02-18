# Hough Transform

## Usage

```sh
g++ generate_data.cpp -o generate_data
./generate_data
```

で円のデータ (`circle.dat`) を作成。

```sh
g++ hough_vote.cpp -o hough_vote
./hough_vote
```

で Hough Voting を実行。

```sh
python count_vote.py
```

で簡単に vote 結果を数える。デフォルトで (x, y, r = 20, 30, 10) なのでその結果が多かったら成功。
