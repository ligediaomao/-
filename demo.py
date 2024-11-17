def xor_encrypt(data, key):
    return bytes([a ^ b for a, b in zip(data, key * (len(data) // len(key) + 1))])
 
def xor_decrypt(data, key):
    return xor_encrypt(data, key)
 
def main():
    # 读取文件内容
    with open('input.txt', 'rb') as file:
        data = file.read()
    
    # 定义密钥
    key = b'secret_key'
    
    # 加密文件内容
    encrypted_data = xor_encrypt(data, key)
    
    # 将加密后的内容写入新文件
    with open('encrypted.txt', 'wb') as file:
        file.write(encrypted_data)
 
if __name__ == "__main__":
    main()