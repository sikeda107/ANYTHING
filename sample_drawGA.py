# References:
# http://d.hatena.ne.jp/white_wheels/20100311/p2
# http://seesaawiki.jp/samplepython/d/%C0%FE%2C%B1%DF%2C%BB%CD%B3%D1%2C%2C%2C%A4%F2%C9%C1%A4%AF

from PIL import Image, ImageDraw, ImageFont
import csv # ファイル読み込み用
import pandas as pd

# new(mode:string,size:turple,color:turple):Image
im = Image.new("RGB", (3800, 2100), (0, 0, 0)) # 新しい画像を作る
# im = Image.new("RGB", (800, 800), (0, 0, 0)) # 新しい画像を作る
draw = ImageDraw.Draw(im) # 画像に絵を描く準備

csv_file = "drawGA.csv"
# csv_file = "drawgui.csv"

with open(csv_file, 'r') as f:
    reader = csv.reader(f, delimiter='\t')  # tab区切りでcsv読み込み
    # reader = csv.reader(f, delimiter=' ')  # スペース区切りでcsv読み込み
    row = list()  # rowをリストとして初期化
    for row_tmp in reader:
        # row_tmp.pop()  # 最後の改行を削除
        row_tmp = list(map(lambda x:int(x),row_tmp))  # mapで全ての要素へint()を適用し、mapをlistへ変換
        row.append(row_tmp)  # 1行ずつ読み込んでrowリストの末尾へrow_tmpリストを追加

    R = 255
    G = 255
    B = 255
    i = 0
    y1 = 0
    for row_elem in row:
        if i%2 == 0:
            tmp = row_elem
            pass
        elif i%2 == 1:
            for x1, x2 in zip(tmp,row_elem):
                y2 = y1+1
                if x1 == 15 :
                    R = 0
                    G = 0
                    B = 255
                    pass
                else :
                    R = 255
                    G = 0
                    B = 0
                    pass
                draw.rectangle((x1*100-5, y1*100-5,x1*100+5, y1*100+5), fill=(0, 255, 0))
                draw.rectangle((x2*100-5, y2*100-5,x2*100+5, y2*100+5), fill=(0, 255, 0))
                draw.line((x1*100,y1*100,x2*100,y2*100), fill=(R, G, B), width=1)
                pass
            y1 += 1
            pass
        else :
            pass
        i += 1
        pass

im.show() # 画像の表示
im.save("drawgui.png") # 画像の保存
