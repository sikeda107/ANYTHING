# References:
# http://d.hatena.ne.jp/white_wheels/20100311/p2
# http://seesaawiki.jp/samplepython/d/%C0%FE%2C%B1%DF%2C%BB%CD%B3%D1%2C%2C%2C%A4%F2%C9%C1%A4%AF

from PIL import Image, ImageDraw, ImageFont
import csv # ファイル読み込み用

# # new(mode:string,size:turple,color:turple):Image
# im = Image.new("RGB", (512, 512), (128, 128, 128)) # 新しい画像を作る
# draw = ImageDraw.Draw(im) # 画像に絵を描く準備
#
# # 画像に絵を描く
# draw.rectangle((100, 100, 200, 200), fill=(0, 255, 0)) # 四角.rectangle((左上点,右下点),塗つぶし色,線色)
# draw.ellipse((250, 300, 450, 400), fill=(0, 0, 255)) # 円.ellipse((左上点,右下点),塗つぶし色,線色)
# draw.line((150,150,350,350), fill=(255, 0, 0), width=8)
# im.show() # 画像の表示
# im.save("sample_imagedraw.png") # 画像の保存

csv_file = "drawGA.csv"

with open(csv_file, 'r') as f:
    reader = csv.reader(f, delimiter='\t')
    print(reader)
    print(next(reader))
    print(next(reader))
