#PIC 16
#Assignment 3F
#Li, Chak Yin (Anders)
#704950093

def load_img(filename):
    
    with open(filename, "r") as f:
        content = f.read()
        
    with open("PIC_hex.txt", "w") as f:
        f.write(repr(content))

def read_hex(bmp, offset, size):
    
    with open(bmp, "r") as f:
        hex = f.read()
    
    

load_img("PIC.bmp")