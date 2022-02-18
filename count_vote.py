
count = {}

with open('hough.dat') as f:
    for line in f.readlines():
        x, y, r = [float(a) for a in line.strip().split()]
        x = int(x)
        y = int(y)
        r = int(r)
        # 整数で丸めてスペースでつないだ文字列をキーとする
        key = " ".join([str(x), str(y), str(r)])
        # キーが一致すれば足し合わせる
        count[key] = count.get(key, 0) + 1

# 件数でソート
count = sorted(count.items(), key=lambda x:x[1])

# 上位10件を表示
print(count[-10:])
