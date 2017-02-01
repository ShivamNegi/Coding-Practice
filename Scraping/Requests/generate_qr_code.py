import pyqrcode

qr = pyqrcode.create("http://www.museumsofindia.gov.in/repository/record/im_kol-At-73-159-4860")
qr.png("site.png", scale=6)
