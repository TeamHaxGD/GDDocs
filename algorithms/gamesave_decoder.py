#Made by absolute: https://pastebin.com/JakxXUVG
import base64,zlib,os
 
saves = ['CCGameManager.dat','CCLocalLevels.dat']
 
def Xor(path,key):
    fr = open(path,'rb')
    data = fr.read()
    fr.close()
   
    res = []
    for i in data:
        res.append(i^key)
    return bytearray(res).decode()
 
def Decrypt(data):
    return zlib.decompress(base64.b64decode(data.replace('-','+').replace('_','/').encode())[10:],-zlib.MAX_WBITS)
 
for x in range(2):
    fPath = os.getenv('localappdata')+'\\GeometryDash\\'
    res = Xor(fPath+saves[x],11)
    fin = Decrypt(res)
 
    fw = open(saves[x]+'.txt','wb')
    fw.write(fin)
    fw.close()
